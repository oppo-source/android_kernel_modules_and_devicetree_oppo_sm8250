#ifndef HIDL_GENERATED_VENDOR_GOODIX_HARDWARE_BIOMETRICS_FINGERPRINT_V2_1_BPHWGOODIXFINGERPRINTDAEMON_H
#define HIDL_GENERATED_VENDOR_GOODIX_HARDWARE_BIOMETRICS_FINGERPRINT_V2_1_BPHWGOODIXFINGERPRINTDAEMON_H

#include <hidl/HidlTransportSupport.h>

#include <vendor/goodix/hardware/biometrics/fingerprint/2.1/IHwGoodixFingerprintDaemon.h>

namespace vendor {
namespace goodix {
namespace hardware {
namespace biometrics {
namespace fingerprint {
namespace V2_1 {

struct BpHwGoodixFingerprintDaemon : public ::android::hardware::BpInterface<IGoodixFingerprintDaemon>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwGoodixFingerprintDaemon(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    virtual bool isRemote() const override { return true; }

    // Methods from IGoodixFingerprintDaemon follow.
    ::android::hardware::Return<void> setNotify(const ::android::sp<IGoodixFingerprintDaemonCallback>& callback) override;
    ::android::hardware::Return<void> sendCommand(int32_t cmdId, const ::android::hardware::hidl_vec<int8_t>& in_buf, sendCommand_cb _hidl_cb) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> interfaceChain(interfaceChain_cb _hidl_cb) override;
    ::android::hardware::Return<void> debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) override;
    ::android::hardware::Return<void> interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) override;
    ::android::hardware::Return<void> getHashChain(getHashChain_cb _hidl_cb) override;
    ::android::hardware::Return<void> setHALInstrumentation() override;
    ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override;
    ::android::hardware::Return<void> ping() override;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb) override;
    ::android::hardware::Return<void> notifySyspropsChanged() override;
    ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override;

private:
    std::mutex _hidl_mMutex;
    std::vector<::android::sp<::android::hardware::hidl_binder_death_recipient>> _hidl_mDeathRecipients;
};

}  // namespace V2_1
}  // namespace fingerprint
}  // namespace biometrics
}  // namespace hardware
}  // namespace goodix
}  // namespace vendor

#endif  // HIDL_GENERATED_VENDOR_GOODIX_HARDWARE_BIOMETRICS_FINGERPRINT_V2_1_BPHWGOODIXFINGERPRINTDAEMON_H
