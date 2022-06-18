/************************************************************************************
 ** File: - ingerprint\silead\SileadFingerprint.cpp
 ** OPLUS_FEATURE_FINGERPRINT
 ** Copyright (C), 2008-2017, OPLUS Mobile Comm Corp., Ltd
 **
 ** Description:
 **      HIDL Service implementation for silead_optical(android O)
 **
 ** Version: 1.0
 ** Date created: 15:09:11,18/11/2017
 ** Author: Ran.chen@Bsp.Fingerprint.basic
 ** TAG: BSP.Fingerprint.Basic
 ** --------------------------- Revision History: --------------------------------
 **  <author>           <data>            <desc>
 **  Ran.Chen         2018/06/24      add oplus feature
 **  Ran.Chen         2018/06/26      add for msg info(ALREADY_ENROLLED)
 **  Ran.Chen         2018/07/17      modify for enroll_total_times to 16
 **  Ran.Chen         2018/08/07      modify for enroll_total_times to 17
 **  oujinrong        2018/09/07      add dynamical log
 **  oujinrong        2018/09/13      add to dump calibration image
 **  Ziqing.Guo       2018/09/13      add for distingue fingerprint unlock and pay
 **  Bangxiong.Wu     2019/03/18      add for call hypnusd service
 **  Bangxiong.Wu     2019/04/14      add for algo and power monitor
 **  Qing.Guan        2019/05/15      add for silead P 18081 8bit
 **  oujinrong        2019/06/18      add macro for DCS
 **  Zemin.Li         2019/12/10      remove HypnsdSetAction.h temporarily
 **  Zemin.Li         2019/12/11      remove setHynsAction temporarily
 **  Zemin.Li         2020/01/14      add for hypnus setAction
 ************************************************************************************/
#define LOG_VERBOSE "vendor.oplus.hardware.biometrics.fingerprint@2.1-service_silead"

#include <hardware/hw_auth_token.h>
#include <hardware/hardware.h>
#include "fingerprint.h"
#include "SileadFingerprint.h"
#include <inttypes.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <string.h>

#include "fingerprint_type.h"

#ifdef FP_DCS_ENABLE
#include "vendor/oplus/hardware/commondcs/1.0/ICommonDcsHalService.h"
#include "vendor/oplus/hardware/commondcs/1.0/types.h"
#endif /* FP_DCS_ENABLE */

#include "silead_impl.h"
#include <cutils/properties.h>
//#include "registerService.h"
#ifdef FP_HYPNUSD_ENABLE
//#include "HypnusdSetAction.h" //remove temporarily because of no exist
#endif

using android::Hypnus;

namespace vendor {
namespace oplus {
namespace hardware {
namespace biometrics {
namespace fingerprint {
namespace V2_1 {
namespace implementation {

#ifndef UNUSED
#define UNUSED(x) (void)(x)
#endif
#define FINGERPRINT_RESTART    (2001)

// Supported fingerprint HAL version
static const uint16_t kVersion = HARDWARE_MODULE_API_VERSION(2, 1);

#define OPTICAL_SEPARATE_SOFTFEATURE  "ro.separate.soft"
#define SILEAD_16BIT_FEATURE "persist.vendor.silead_newalgo.support"
static char silead_16bit_support[PROPERTY_VALUE_MAX] = {0};

using RequestStatus =
        android::hardware::biometrics::fingerprint::V2_1::RequestStatus;

SileadFingerprint *SileadFingerprint::sInstance = nullptr;
SileadFingerprint::SileadFingerprint() : mClientCallback(nullptr), mClientCallbackEx(nullptr), mDevice(nullptr) {
    sInstance = this; // keep track of the most recent instance
    mDevice = openHal();
    if (!mDevice) {
        ALOGE("Can't open HAL module");
    }
}

SileadFingerprint::~SileadFingerprint() {
    ALOGV("~SileadFingerprint()");
    if (mDevice == nullptr) {
        ALOGE("No valid device");
        return;
    }
    int err;
    if (0 != (err = mDevice->common.close(
            reinterpret_cast<hw_device_t*>(mDevice)))) {
        ALOGE("Can't close fingerprint module, error: %d", err);
        return;
    }
    mDevice = nullptr;
}

Return<RequestStatus> SileadFingerprint::ErrorFilter(int32_t error) {
    switch (error) {
        case 0: return RequestStatus::SYS_OK;
        case -2: return RequestStatus::SYS_ENOENT;
        case -4: return RequestStatus::SYS_EINTR;
        case -5: return RequestStatus::SYS_EIO;
        case -11: return RequestStatus::SYS_EAGAIN;
        case -12: return RequestStatus::SYS_ENOMEM;
        case -13: return RequestStatus::SYS_EACCES;
        case -14: return RequestStatus::SYS_EFAULT;
        case -16: return RequestStatus::SYS_EBUSY;
        case -22: return RequestStatus::SYS_EINVAL;
        case -28: return RequestStatus::SYS_ENOSPC;
        case -110: return RequestStatus::SYS_ETIMEDOUT;
        default:
            ALOGE("An unknown error returned from fingerprint vendor library: %d", error);
            return RequestStatus::SYS_UNKNOWN;
    }
}

// Translate from errors returned by traditional HAL (see fingerprint.h) to
// HIDL-compliant FingerprintError.
FingerprintError SileadFingerprint::vendorErrorFilter(int32_t error,
            int32_t* vendorCode) {
    *vendorCode = 0;
    switch (error) {
        case FINGERPRINT_ERROR_HW_UNAVAILABLE:
            return FingerprintError::ERROR_HW_UNAVAILABLE;
        case FINGERPRINT_ERROR_UNABLE_TO_PROCESS:
            return FingerprintError::ERROR_UNABLE_TO_PROCESS;
        case FINGERPRINT_ERROR_TIMEOUT:
            return FingerprintError::ERROR_TIMEOUT;
        case FINGERPRINT_ERROR_NO_SPACE:
            return FingerprintError::ERROR_NO_SPACE;
        case FINGERPRINT_ERROR_CANCELED:
            return FingerprintError::ERROR_CANCELED;
        case FINGERPRINT_ERROR_UNABLE_TO_REMOVE:
            return FingerprintError::ERROR_UNABLE_TO_REMOVE;
        case FINGERPRINT_ERROR_LOCKOUT:
            return FingerprintError::ERROR_LOCKOUT;
        default:
            if (error >= FINGERPRINT_ERROR_VENDOR_BASE) {
                // vendor specific code.
                *vendorCode = error - FINGERPRINT_ERROR_VENDOR_BASE;
                return FingerprintError::ERROR_VENDOR;
            }
    }
    ALOGE("Unknown error from fingerprint vendor library: %d", error);
    return FingerprintError::ERROR_UNABLE_TO_PROCESS;
}

// Translate acquired messages returned by traditional HAL (see fingerprint.h)
// to HIDL-compliant FingerprintAcquiredInfo.
FingerprintAcquiredInfo SileadFingerprint::vendorAcquiredFilter(
        int32_t info, int32_t* vendorCode) {
    *vendorCode = 0;
    switch (info) {
        case FINGERPRINT_ACQUIRED_GOOD:
            return FingerprintAcquiredInfo::ACQUIRED_GOOD;
        case FINGERPRINT_ACQUIRED_PARTIAL:
            return FingerprintAcquiredInfo::ACQUIRED_PARTIAL;
        case FINGERPRINT_ACQUIRED_INSUFFICIENT:
            return FingerprintAcquiredInfo::ACQUIRED_INSUFFICIENT;
        case FINGERPRINT_ACQUIRED_IMAGER_DIRTY:
            return FingerprintAcquiredInfo::ACQUIRED_IMAGER_DIRTY;
        case FINGERPRINT_ACQUIRED_TOO_SLOW:
            return FingerprintAcquiredInfo::ACQUIRED_TOO_SLOW;
        case FINGERPRINT_ACQUIRED_TOO_FAST:
            return FingerprintAcquiredInfo::ACQUIRED_TOO_FAST;
        case FINGERPRINT_ACQUIRED_ALREADY_ENROLLED:
            return (FingerprintAcquiredInfo)FINGERPRINT_ACQUIRED_ALREADY_ENROLLED;
        case FINGERPRINT_ACQUIRED_TOO_SIMILAR:
            return (FingerprintAcquiredInfo)FINGERPRINT_ACQUIRED_TOO_SIMILAR;
        default:
            if (info >= FINGERPRINT_ACQUIRED_VENDOR_BASE) {
                // vendor specific code.
                *vendorCode = info - FINGERPRINT_ACQUIRED_VENDOR_BASE;
                return FingerprintAcquiredInfo::ACQUIRED_VENDOR;
            }
    }
    ALOGE("Unknown acquiredmsg from fingerprint vendor library: %d", info);
    return FingerprintAcquiredInfo::ACQUIRED_INSUFFICIENT;
}

hidl_string SileadFingerprint::getHidlstring(uint32_t param) {
        char data[64];
        snprintf(data, 63, "%u", param);
        ALOGD("getString16(param=%u)", param);
        return hidl_string(data, strlen(data));
}

Return<uint64_t> SileadFingerprint::setNotify(
        const sp<IBiometricsFingerprintClientCallback>& clientCallback) {
    std::lock_guard<std::mutex> lock(mClientCallbackMutex);
    mClientCallback = clientCallback;
    // This is here because HAL 2.1 doesn't have a way to propagate a
    // unique token for its driver. Subsequent versions should send a unique
    // token for each call to setNotify(). This is fine as long as there's only
    // one fingerprint device on the platform.
    return reinterpret_cast<uint64_t>(mDevice);
}

Return<uint64_t> SileadFingerprint::setHalCallback(
        const sp<IBiometricsFingerprintClientCallbackEx>& clientCallbackEx) {
    std::lock_guard<std::mutex> lock(mClientCallbackMutex);
    mClientCallbackEx = clientCallbackEx;
    return reinterpret_cast<uint64_t>(mDevice);
}

Return<uint64_t> SileadFingerprint::preEnroll()  {
    return mDevice->pre_enroll(mDevice);
}

Return<RequestStatus> SileadFingerprint::enroll(const hidl_array<uint8_t, 69>& hat,
        uint32_t gid, uint32_t timeoutSec) {
    (void) timeoutSec;
    uint32_t fingerprint_enroll_time = 0;
    const hw_auth_token_t* authToken =
        reinterpret_cast<const hw_auth_token_t*>(hat.data());
    return ErrorFilter(mDevice->enroll(mDevice, authToken, gid, fingerprint_enroll_time));
}

Return<RequestStatus> SileadFingerprint::postEnroll() {
    return ErrorFilter(mDevice->post_enroll(mDevice));
}

Return<uint64_t> SileadFingerprint::getAuthenticatorId() {
    return mDevice->get_authenticator_id(mDevice);
}

Return<RequestStatus> SileadFingerprint::cancel() {
    return ErrorFilter(mDevice->cancel(mDevice));
}

Return<RequestStatus> SileadFingerprint::enumerate()  {
    ALOGD("SileadFingerprint enumerate");
    return ErrorFilter(mDevice->enumerate(mDevice));//we need it
    //return RequestStatus::SYS_OK;
}

Return<RequestStatus> SileadFingerprint::remove(uint32_t gid, uint32_t fid) {
    return ErrorFilter(mDevice->remove(mDevice, gid, fid));
}

Return<RequestStatus> SileadFingerprint::setActiveGroup(uint32_t gid,
        const hidl_string& storePath) {
    if (storePath.size() >= PATH_MAX || storePath.size() <= 0) {
        ALOGE("Bad path length: %zd", storePath.size());
        return RequestStatus::SYS_EINVAL;
    }
    if (access(storePath.c_str(), W_OK)) {
        return RequestStatus::SYS_EINVAL;
    }

    return ErrorFilter(mDevice->set_active_group(mDevice, gid,
                                                    storePath.c_str()));
}

Return<RequestStatus> SileadFingerprint::authenticate(uint64_t operationId,
        uint32_t gid) {
    return ErrorFilter(mDevice->authenticate(mDevice, operationId, gid));
}

Return<RequestStatus> SileadFingerprint::authenticateAsType(uint64_t operationId,
        uint32_t gid, int32_t authtype) {
    ALOGI("authenticate type: %d", authtype);
    return ErrorFilter(mDevice->authenticateAsType(mDevice, operationId, gid, static_cast<uint32_t>(authtype)));
}

Return<bool> SileadFingerprint::isUdfps(uint32_t sensorId) {
    ALOGD("isUdfps sensor_id = %d", sensorId);
    if (sensorId >= E_SENSOR_ID_MAX) {
        ALOGE("unknown sensor");
        return false;
    }
    return (fp_config_info[sensorId].fp_type) == 4? true:false;
}

Return<void> SileadFingerprint::onFingerDown(uint32_t x, uint32_t y, float minor, float major) {
    ALOGD("onFingerDown");
    mDevice->touchDown(mDevice);
    return Void();
}

Return<void> SileadFingerprint::onFingerUp() {
    ALOGD("onFingerUp");
    mDevice->touchUp(mDevice);
    return Void();
}

Return<int32_t> SileadFingerprint::getEnrollmentTotalTimes() {
    ALOGD("getEnrollmentTotalTimes = %d", fp_config_info_init.total_enroll_times);
    return fp_config_info_init.total_enroll_times;
}

Return<RequestStatus> SileadFingerprint::pauseEnroll() {
    ALOGI("enter pauseEnroll");
	return ErrorFilter(mDevice->pause_enroll(mDevice));
}

Return<RequestStatus> SileadFingerprint::continueEnroll() {
    ALOGI("enter continueEnroll");
	return ErrorFilter(mDevice->continue_enroll(mDevice));
}

Return<RequestStatus> SileadFingerprint::setTouchEventListener() {
	ALOGI("enter wait_touch_down");	
    mDevice->wait_touch_down(mDevice);
	return RequestStatus::SYS_OK;
}

Return<RequestStatus> SileadFingerprint::dynamicallyConfigLog(uint32_t on) {
    int ret = 0;
    ALOGI("%s log type: %d", __func__, on);
    switch (on) {
        case DYNAMICAL_LOG_CLOSE:
            {
                //ret = sl_fp_set_image_dump_flag(FP_STOP_IMAGE_DUMP_CMD, 0);
                if (ret) {
                    ALOGE("%s stop log failed", __func__);
                }
                break;
            }
        case DYNAMICAL_LOG_CAPTURE_IMAGE:
            {
                //ret = sl_fp_set_image_dump_flag(FP_START_IMAGE_DUMP_CMD, 0);
                if (ret) {
                    ALOGE("%s stop log failed", __func__);
                }
                //ret = sl_dump_calibration_image();
                if (ret) {
                    ALOGE("%s dump calibration image failed", __func__);
                }
                break;
            }
    }
	return RequestStatus::SYS_OK;
}

Return<int32_t> SileadFingerprint::getEngineeringInfo(uint32_t type) {
    int32_t ret = -1;
    int32_t cmdid = -1;
    fingerprint_msg_t msg;
    switch (type) {
        case FINGERPRINT_GET_IMAGE_SNR:
            ALOGD("getImageSnr   BEGIN_CALL_API");
            //mDevice->getImageSnr(mDevice);
            ALOGD("getImageSnr   END_CALL_API");
            return 0;
        case FINGERPRINT_GET_IMAGET_QUALITY:
            ALOGD("getImageQuality   BEGIN_CALL_API");
            mDevice->getImageQuality(mDevice);
            ALOGD("getImageQuality   END_CALL_API");
            return 0;
        case FINGERPRINT_GET_BAD_PIXELS:
            ALOGD("getBadPixels   BEGIN_CALL_API");
            //ret = mDevice->getBadPixels(mDevice);
            ALOGD("getBadPixels   END_CALL_API");
            break;
        case FINGERPRINT_SELF_TEST:
            ALOGD("selftest   BEGIN_CALL_API");
            ret = mDevice->selftest(mDevice);
            msg.type = ENGINEERING_INFO;
            msg.data.engineering.type = FINGERPRINT_INAGE_SELF_TEST;
            msg.data.engineering.self_test_result = ret;
            notify(&msg);
            ALOGE("selftest spi ret=%d", ret);
            ALOGD("selftest   END_CALL_API");
            break;
        default:
            ALOGD("invalid msg type: %d", type);
            return -1;
    }
    return ret;

}



Return<int32_t> SileadFingerprint::init() {
#if 0  //remove by chenran
    int32_t err;
    err = gf_hal_open(&mDevice);
    if (err) {
        return err;
    }

    mDevice.notify = notify;


#ifdef SUPPORT_CMD_TEST
    registerExtVndService(&mDevice);
#endif
    return 0;
#endif

    return 0;
}

IBiometricsFingerprint* SileadFingerprint::getInstance() {
    if (!sInstance) {
        sInstance = new SileadFingerprint();
    }
    return sInstance;
}

fingerprint_device_t* SileadFingerprint::openHal() {
    int err;
    const hw_module_t *hw_mdl = nullptr;
    char regionmark[PROPERTY_VALUE_MAX] = {0};
    ALOGD("Opening fingerprint hal library...");
    property_get(SILEAD_16BIT_FEATURE, silead_16bit_support, "0");

    if (!strncmp(silead_16bit_support, "0", sizeof("0"))) {
        ALOGD("sileadfp enter 8 Opening fingerprint hal library...");
        err = hw_get_module("fingerprint.silead", &hw_mdl);
        property_set(SILEAD_16BIT_FEATURE, "0");
    }  else {
        ALOGD("sileadfp enter 16 Opening fingerprint hal library...");
        err = hw_get_module("fingerprint.silead_16bit", &hw_mdl);
    }
    if (0 != err) {
        ALOGE("Can't open fingerprint HW Module, error: %d", err);
        return nullptr;
    }

    if (hw_mdl == nullptr) {
        ALOGE("No valid fingerprint module");
        return nullptr;
    }

    fingerprint_module_t const *module =
        reinterpret_cast<const fingerprint_module_t*>(hw_mdl);
    if (module->common.methods->open == nullptr) {
        ALOGE("No valid open method");
        return nullptr;
    }

    hw_device_t *device = nullptr;

    if (0 != (err = module->common.methods->open(hw_mdl, nullptr, &device))) {
        ALOGE("Can't open fingerprint methods, error: %d", err);
        return nullptr;
    }

    if (kVersion != device->version) {
        // enforce version on new devices because of HIDL@2.1 translation layer
        ALOGE("Wrong fp version. Expected %d, got %d", kVersion, device->version);
        return nullptr;
    }

    fingerprint_device_t* fp_device =
        reinterpret_cast<fingerprint_device_t*>(device);

    if (0 != (err =
            fp_device->set_notify(fp_device, SileadFingerprint::notify))) {
        ALOGE("Can't register fingerprint module callback, error: %d", err);
        return nullptr;
    }

    return fp_device;
}




void SileadFingerprint::notify(const fingerprint_msg_t *msg) {
    SileadFingerprint* thisPtr = static_cast<SileadFingerprint*>(
            SileadFingerprint::getInstance());
    std::lock_guard<std::mutex> lock(thisPtr->mClientCallbackMutex);
    if (thisPtr == nullptr || thisPtr->mClientCallback == nullptr) {
        ALOGE("Receiving callbacks before the client callback is registered.");
        return;
    }
    const uint64_t devId = reinterpret_cast<uint64_t>(thisPtr->mDevice);
    const std::vector<int8_t> deviceId(&devId, &devId + sizeof(uint64_t));
    switch (msg->type) {
        case FINGERPRINT_ERROR: {
                int32_t vendorCode = 0;
                FingerprintError result = vendorErrorFilter(msg->data.error, &vendorCode);
                ALOGD("onError(result:%d, error:%d)", result, msg->data.error);
                if(FingerprintError::ERROR_VENDOR == result){
                    ALOGE("do nothing with ERROR_VENDOR");
                    break;
                }
                if (!thisPtr->mClientCallback->onError(devId, result, vendorCode).isOk()) {
                    ALOGE("failed to invoke fingerprint onError callback");
                }
            }
            break;
        case FINGERPRINT_ACQUIRED: {
                int32_t vendorCode = 0;
                FingerprintAcquiredInfo result =
                    vendorAcquiredFilter(msg->data.acquired.acquired_info, &vendorCode);
                ALOGD("onAcquired(%d)", result);
                if (!thisPtr->mClientCallback->onAcquired(devId, result, vendorCode).isOk()) {
                    ALOGE("failed to invoke fingerprint onAcquired callback");
                }
            }
            break;
        case FINGERPRINT_TEMPLATE_ENROLLING:
            ALOGD("onEnrollResult(fid=%d, gid=%d, rem=%d)",
                msg->data.enroll.finger.fid,
                msg->data.enroll.finger.gid,
                msg->data.enroll.samples_remaining);
            if (!thisPtr->mClientCallback->onEnrollResult(devId,
                    msg->data.enroll.finger.fid,
                    msg->data.enroll.finger.gid,
                    msg->data.enroll.samples_remaining).isOk()) {
                ALOGE("failed to invoke fingerprint onEnrollResult callback");
            }
            break;
        case FINGERPRINT_TEMPLATE_REMOVED:
            ALOGE("onRemove(fid=%d, gid=%d, rem=%d)",
                msg->data.removed.finger.fid,
                msg->data.removed.finger.gid,
                msg->data.removed.fingers_count);
            if (!thisPtr->mClientCallback->onRemoved(devId,
                    msg->data.removed.finger.fid,
                    msg->data.removed.finger.gid,
                    msg->data.removed.fingers_count).isOk()) {
                ALOGE("failed to invoke fingerprint onRemoved callback");
            }
            break;
        case FINGERPRINT_AUTHENTICATED:
            ALOGD("onAuthenticated(fid=%d, gid=%d)",
                    msg->data.authenticated.finger.fid,
                    msg->data.authenticated.finger.gid);
            if (msg->data.authenticated.finger.fid != 0) {
                const uint8_t* hat =
                    reinterpret_cast<const uint8_t *>(&msg->data.authenticated.hat);
                const hidl_vec<uint8_t> token(
                    std::vector<uint8_t>(hat, hat + sizeof(msg->data.authenticated.hat)));
                if (!thisPtr->mClientCallback->onAuthenticated(devId,
                        msg->data.authenticated.finger.fid,
                        msg->data.authenticated.finger.gid,
                        token).isOk()) {
                    ALOGE("failed to invoke fingerprint onAuthenticated callback");
                }
            } else {
                // Not a recognized fingerprint
                if (!thisPtr->mClientCallback->onAuthenticated(devId,
                        msg->data.authenticated.finger.fid,
                        msg->data.authenticated.finger.gid,
                        hidl_vec<uint8_t>()).isOk()) {
                    ALOGE("failed to invoke fingerprint onAuthenticated callback");
                }
            }
            break;
        case FINGERPRINT_TOUCH_DOWN:
            ALOGD("onTouchDown()");
            if (!thisPtr->mClientCallbackEx->onFingerprintCmd(FINGERPRINT_CALLBACK_CMD_ID_ON_TOUCH_DOWN,
                    hidl_vec<int8_t>(deviceId), sizeof(uint64_t)).isOk()) {
                ALOGE("failed to invoke FINGERPRINT_TOUCH_DOWN callback");
            }
            break;
        case FINGERPRINT_TOUCH_UP:
            ALOGD("onTouchUp()");
            if (!thisPtr->mClientCallbackEx->onFingerprintCmd(FINGERPRINT_CALLBACK_CMD_ID_ON_TOUCH_UP,
                    hidl_vec<int8_t>(deviceId), sizeof(uint64_t)).isOk()) {
                ALOGE("failed to invoke FINGERPRINT_TOUCH_UP callback");
            }
            break;
        case ENGINEERING_INFO:
            {
            uint32_t len = 0;
            uint32_t *key = NULL;
            hidl_string *value = NULL;
            ALOGE("ENGINEERING_INFO ");
            switch (msg->data.engineering.type) {
                case FINGERPRINT_IMAGE_QUALITY:
                    ALOGE(" callback ENGINEERING_INFO FINGERPRINT_IMAGE_QUALITY ");
                    len = 3;
                    key = (uint32_t*)malloc(len * sizeof(uint32_t));
                    value = new hidl_string[len];

                    key[0]   = SUCCESSED;
                    value[0] = getHidlstring(msg->data.engineering.quality.successed);
                    key[1]   = IMAGE_QUALITY;
                    value[1] = getHidlstring(msg->data.engineering.quality.image_quality);
                    key[2]   = QUALITY_PASS;
                    value[2] = getHidlstring(msg->data.engineering.quality.quality_pass);
                    break;
                case FINGERPRINT_INAGE_SELF_TEST:
                    ALOGE(" callback ENGINEERING_INFO FINGERPRINT_INAGE_SELF_TEST result=%d", msg->data.engineering.self_test_result);
                    len = 1;
                    key = (uint32_t*)malloc(len * sizeof(uint32_t));
                    value = new hidl_string[len];
                    if (key == NULL || value == NULL) {
                        ALOGE("malloc fail");
                        break;
                    }
                    key[0]   = SUCCESSED;
                    value[0] = getHidlstring(msg->data.engineering.self_test_result);
                    break;
                default:
                    break;
            }

            const std::vector<uint32_t> hidl_key(key, key + len);
            const std::vector<hidl_string> hidl_value(value, value+len);
            int count = hidl_value.size();
            for (int i=0; i < count; i++) {
                ALOGD("onEngineeringInfoUpdated, key[%d] = %d, value[%d] = %s", i, hidl_key[i], i, (android::String8(hidl_value[i].c_str())).string());
            }
            if (!thisPtr->mClientCallbackEx->onEngineeringInfoUpdated(len, hidl_vec<uint32_t>(hidl_key), hidl_vec<hidl_string>(hidl_value)).isOk()) {
                ALOGE("failed to invoke onEngineeringInfoUpdated callback");
            }
            free(key);
            }
            break;
        case FINGERPRINT_TEMPLATE_ENUMERATING:
            {
            int32_t rem;
            int32_t *fids;
	    char separate_soft[PROPERTY_VALUE_MAX] = {0};
            rem = msg->data.enumerated.remaining_templates;
            fids = (int32_t*)malloc(rem * sizeof(int32_t));
            ALOGD("onEnumerate()");
            property_get(OPTICAL_SEPARATE_SOFTFEATURE, separate_soft, "0");
            if ((!strncmp(separate_soft, "18081", sizeof("18081"))) || (!strncmp(separate_soft, "18085", sizeof("18085"))) || (!strncmp(separate_soft, "18086", sizeof("18086")))  || (!strncmp(separate_soft, "18181", sizeof("18181"))) ||(!strncmp(separate_soft, "18381", sizeof("18381"))) || (!strncmp(separate_soft, "18385", sizeof("18385"))) ) {
            /*add for 16bit*/

                if(0 == rem){
                    property_get(SILEAD_16BIT_FEATURE, silead_16bit_support, "0");
                    if (!strncmp(silead_16bit_support, "0", sizeof("0"))) {
                        ALOGE("sileadfp enter 16 ,set SILEAD_16_FEATURE to 1");
                        property_set(SILEAD_16BIT_FEATURE, "1");
                        (thisPtr->mDevice)->common.close(reinterpret_cast<hw_device_t*>(thisPtr->mDevice));
                        ALOGE("restart fingerprint");
                        if (!thisPtr->mClientCallback->onError(devId, (FingerprintError)FINGERPRINT_RESTART, 0).isOk()) {
                            ALOGE("failed to invoke fingerprint restart callback");
                        }
                        //exit(0);
                    } else {
                        ALOGD("SILEAD_16BIT_FEATURE:16bit do nothing");
                    }
                }
            }
            /*end for 16bit*/
            if (rem == 0) {
                ALOGD("fingerprint template is null");
                if (!thisPtr->mClientCallback->onEnumerate(devId,
                        0,
                        msg->data.enumerated.gid,
                        0).isOk()) {
                    ALOGE("failed to invoke fingerprint onEnumerate callback");
                }
            }

            for (int32_t index = 0; index < rem; index++) {
                fids[index] = msg->data.enumerated.fingers[index].fid;
                ALOGE("fids[%d] = %d, gids[%d] = %d",
                index, fids[index], index, msg->data.enumerated.fingers[index].gid);
                if (!thisPtr->mClientCallback->onEnumerate(devId,
                        fids[index],
                        msg->data.enumerated.fingers[index].gid,
                        rem - index - 1).isOk()) {
                    ALOGE("failed to invoke fingerprint onEnumerate callback");
                }
            }
            if (fids) {
                free(fids);
                fids = NULL;
            }
            }
            break;
        case FINGERPRINT_IMAGE_INFO:
            {
            ALOGD("onImageInfoAcquired(type=%d, quality=%d, match_score=%d)",
                    msg->data.image_info.type,
                    msg->data.image_info.quality,
                    msg->data.image_info.match_score);
            }
            break;
        case FINGERPRINT_MONITOR: {
                char data[64];
                size_t size = 0;
                switch (msg->data.monitor.type) {
                    case fingerprint_monitor_type_t::FINGER_POWER_MONITOR:
                        ALOGD("onMonitorEventTriggered(type=%d, battery=%f)",
                                msg->data.monitor.type,
                                msg->data.monitor.data.power.battery);

                        size = snprintf(data, 63, "%f", msg->data.monitor.data.power.battery);
                        break;
                    case fingerprint_monitor_type_t::FINGER_ERROR_STATE:
                        //ignore, no available yet.
                        break;
                    case fingerprint_monitor_type_t::FINGER_TP_PROTECT_MONITOR:
                        ALOGD("onMonitorEventTriggered(type=%d, mode=%d)",
                                msg->data.monitor.type,
                                msg->data.monitor.data.tp_protect.mode);

                        size = snprintf(data, 63, "%d", msg->data.monitor.data.tp_protect.mode);
                        break;
                    default:
                        ;//ignore
                    }
                if (size > 0) {
#ifdef FP_DCS_ENABLE
                    ALOGD("enter into onMonitorEventTriggered CommonDcsmsg ");
                    sp<::vendor::oplus::hardware::commondcs::V1_0::ICommonDcsHalService> service =
                        vendor::oplus::hardware::commondcs::V1_0::ICommonDcsHalService::getService("commondcsservice");
                    if (service != NULL) {
                        ALOGD(" send silead fingerprint onMonitorEventTriggered dcsmsg");
                        hidl_vec<vendor::oplus::hardware::commondcs::V1_0::StringPair> dcsmsg;
                        vendor::oplus::hardware::commondcs::V1_0::StringPair dataArray[1] = {{0, 0}};
                        dataArray[0].key = "MonitorEvent";
                        dataArray[0].value = getHidlstring((uint32_t)(msg->data.monitor.data.power.battery));

                        dcsmsg.setToExternal(dataArray, 1);
                        service->notifyMsgToCommonDcs(dcsmsg, "20120", "fingerprint_MonitorEvent");
                    } else {
                        ALOGE("service NULL");
                    }
#endif /* FP_DCS_ENABLE */

                }
            }
            break;
        case FINGERPRINT_OPTICAL_SENDCMD: {
            ALOGD("onFingerprintCmd type==");
            const std::vector<int8_t> test_result(msg->data.test.result, msg->data.test.result + msg->data.test.result_len);

            if (!thisPtr->mClientCallbackEx->onFingerprintCmd(msg->data.test.cmd_id,
                hidl_vec<int8_t>(test_result),
                msg->data.test.result_len).isOk()) {
                ALOGE(" FINGERPRINT_OPTICAL_SENDCMD ");
            }

        }
        break;
        /*Just for getting hypnusd setting from HAL by notify,not notify FingerprintService any message*/
#ifdef FP_HYPNUSD_ENABLE
        case FINGERPRINT_HYPNUSDSETACION: {
/*
            ALOGD("onHypnusdSetAction(type=%d, type=%d)", msg->data.hypnusd_setting.action_type, msg->data.hypnusd_setting.action_timeout);
            if (hypnusdSetAction(msg->data.hypnusd_setting.action_type, msg->data.hypnusd_setting.action_timeout)) {
                ALOGE("hypnusd set action failed");
            } else {
                ALOGD("hypnusd set action successed");
            }
*/
            int32_t action_type = msg->data.hypnusd_setting.action_type;
            int32_t action_timeout = msg->data.hypnusd_setting.action_timeout;
 
            ALOGD("hypnusdSetAction(type=%d, timeout=%d)", action_type, action_timeout);
            Hypnus::getInstance()->setAction(action_type, action_timeout);
        }
            break;
#endif
        case FINGERPRINT_AUTHENTICATED_DCSSTATUS: {
#ifdef FP_DCS_ENABLE
            ALOGD("enter into FINGERPRINT_AUTHENTICATED CommonDcsmsg ");
            sp<::vendor::oplus::hardware::commondcs::V1_0::ICommonDcsHalService> service =
                vendor::oplus::hardware::commondcs::V1_0::ICommonDcsHalService::getService("commondcsservice");
            if (service != NULL) {
                ALOGD(" send fingerprint auth dcsmsg");
                hidl_vec<vendor::oplus::hardware::commondcs::V1_0::StringPair> dcsmsg;
                vendor::oplus::hardware::commondcs::V1_0::StringPair dataArray[12] = {{0, 0}};
                dataArray[0].key = "auth_result";
                dataArray[0].value = getHidlstring(msg->data.auth_dcsmsg.auth_result);
                dataArray[1].key = "fail_reason";
                dataArray[1].value = getHidlstring(msg->data.auth_dcsmsg.fail_reason);
                dataArray[2].key = "quality_score";
                dataArray[2].value = getHidlstring(msg->data.auth_dcsmsg.quality_score);
                dataArray[3].key = "match_score";
                dataArray[3].value = getHidlstring(msg->data.auth_dcsmsg.match_score);
                dataArray[4].key = "signal_value";
                dataArray[4].value = getHidlstring(msg->data.auth_dcsmsg.signal_value);
                dataArray[5].key = "img_area";
                dataArray[5].value = getHidlstring(msg->data.auth_dcsmsg.img_area);
                dataArray[6].key = "retry_times";
                dataArray[6].value = getHidlstring(msg->data.auth_dcsmsg.retry_times);
                dataArray[7].key = "algo_version";
                dataArray[7].value = hidl_string(msg->data.auth_dcsmsg.algo_version, strlen(msg->data.auth_dcsmsg.algo_version));
                dataArray[8].key = "chip_ic";
                dataArray[8].value = getHidlstring(msg->data.auth_dcsmsg.chip_ic);
                dataArray[9].key = "module_type";
                dataArray[9].value = getHidlstring(msg->data.auth_dcsmsg.module_type);
                dataArray[10].key = "lense_type";
                dataArray[10].value = getHidlstring(msg->data.auth_dcsmsg.lense_type);
                dataArray[11].key = "dsp_available";
                dataArray[11].value = getHidlstring(msg->data.auth_dcsmsg.dsp_availalbe);

                dcsmsg.setToExternal(dataArray, 12);
                service->notifyMsgToCommonDcs(dcsmsg, "20120", "fingerprint_auth_dcsmsg");
            } else {
                ALOGE("service NULL");
            }
#endif /* FP_DCS_ENABLE */
        }
        break;

        default:
            ALOGE("unkonown msg->type= %d", msg->type);
            break;
        }
    }//notify end


    Return<RequestStatus> SileadFingerprint::setScreenState(int32_t screen_state) {
        ALOGD("setScreenState ");
        return ErrorFilter(mDevice->setScreenState(mDevice, (uint32_t)screen_state));
    }

    Return<int32_t> SileadFingerprint::sendFingerprintCmd(int32_t cmdId,  const hidl_vec<int8_t>& in_buf ) {
        ALOGD("silead sendFingerprintCmd ");
        ALOGE("sendFingerprintCmd in_buf= %s ", (int8_t*)in_buf.data());
        int ret = FINGERPRINT_RIGHTNESS_ERROR;

        switch (cmdId) {
        case fingerprint_cmd_Id_t::FINGERPRINT_CMD_ID_AUTHENTICATE_TYPE:
        {
            uint64_t operationId = 0;
            uint32_t gid = 0;
            int32_t authtype;

            int8_t *value = (int8_t*)in_buf.data();
            memcpy(&authtype, value, sizeof(uint32_t));
            ALOGE("FINGERPRINT_CMD_ID_AUTHENTICATE_TYPE  authtype = %d", authtype);

            authenticateAsType(operationId, gid, authtype);
            return 0;
        }
        case fingerprint_cmd_Id_t::FINGERPRINT_CMD_ID_PAUSE_ENROLL:
        {
            pauseEnroll();
            return 0;
        }
        case fingerprint_cmd_Id_t::FINGERPRINT_CMD_ID_CONTINUE_ENROLL:
        {
            continueEnroll();
            return 0;
        }
        case fingerprint_cmd_Id_t::FINGERPRINT_CMD_ID_SET_TOUCHEVENT_LISTENER:
        {
            setTouchEventListener();
            return 0;
        }
        case fingerprint_cmd_Id_t::FINGERPRINT_CMD_ID_DYNAMICALLY_LOG:
        {
            uint32_t on = 0;
            int8_t *value = (int8_t*)in_buf.data();
            memcpy(&on, value, sizeof(uint32_t));
            ALOGE("FINGERPRINT_CMD_ID_DYNAMICALLY_LOG on = %d", on);
            dynamicallyConfigLog(on);
            return 0;
        }
        case fingerprint_cmd_Id_t::FINGERPRINT_CMD_ID_GET_ENROLL_TIMES:
        {
            int32_t enroll_times = 0;
            enroll_times = getEnrollmentTotalTimes();
            return enroll_times;
        }
        case fingerprint_cmd_Id_t::FINGERPRINT_CMD_ID_SET_SCREEN_STATE:
        {
            int32_t screen_state;
            int8_t *value = (int8_t*)in_buf.data();
            memcpy(&screen_state, value, sizeof(int32_t));
            ALOGE("FINGERPRINT_CMD_ID_SET_SCREEN_STATE screen_state = %d", screen_state);
            setScreenState(screen_state);
            return 0;
        }
        case fingerprint_cmd_Id_t::FINGERPRINT_CMD_ID_GET_ENGINEERING_INFO:
        {
            uint32_t type = 0;
            int8_t *value = (int8_t*)in_buf.data();
            memcpy(&type, value, sizeof(uint32_t));
            ALOGE("FINGERPRINT_CMD_ID_GET_ENGINEERING_INFO type = %d", type);
            return getEngineeringInfo(type);
        }
        case fingerprint_cmd_Id_t::FINGERPRINT_CMD_ID_GET_SENSOR_ID:
        {
            ALOGE("FINGERPRINT_CMD_ID_GET_SENSOR_ID = %d", fp_config_info_init.sensor_id);
            return fp_config_info_init.sensor_id;
        }
        case fingerprint_cmd_Id_t::FINGERPRINT_CMD_ID_SIDE_PRESS_ENABLE:
        {
            return 0;
        }
        case fingerprint_cmd_Id_t::FINGERPRINT_CMD_ID_SIDE_SCREEN_STATE:
        {
            return 0;
        }
        case fingerprint_cmd_Id_t::FINGERPRINT_CMD_ID_SIDE_POWER_KEY_PRESSED:
        {
            return 0;
        }
        default:
            break;
        }
        return mDevice->sendFingerprintCmd(mDevice, cmdId, (int8_t*)in_buf.data(), (uint32_t)in_buf.size());
    }

} // namespace implementation
}  // namespace V2_1
}  // namespace fingerprint
}  // namespace biometrics
}  // namespace hardware
}  // namespace oplus
}  // namespace vendor

