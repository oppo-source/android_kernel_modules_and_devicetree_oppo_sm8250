/************************************************************************************
 ** File: - SZCustomizedProductTest.cpp
 ** OPLUS_FEATURE_FINGERPRINT
 ** Copyright (C), 2008-2018, OPLUS Mobile Comm Corp., Ltd
 **
 ** Description:
 **      Engineer mode API for goodix optical fingerprint (android O)
 **
 ** Version: 1.0
 ** Date : 18:03:11,6/11/2018
 ** Author: oujinrong@BSP.Fingerprint.Basic
 ** TAG: BSP.Fingerprint.Basic
 ** --------------------------- Revision History: --------------------------------
 **  <author>       <data>            <desc>
 **  oujinrong   2018/11/06           create file, and add return value of spi test
 **  Dongnan.Wu  2019/05/06           add some delay after hbm on for p90 platform
 ************************************************************************************/

#define LOG_TAG "[GF_HAL][SZCustomizedProductTest]"

#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#include "SZCustomizedProductTest.h"
#include "HalContext.h"
#include "SZProductTestDefine.h"
#include "gf_sensor_types.h"
#include "gf_sz_config.h"
#include "SZSensor.h"
#include "TestUtils.hpp"
#include "Device.h"

#include "SZHalDump.h"

// Note: the control path should be changed as different customers.
#define HBM_PATH "/sys/kernel/oplus_display/hbm"
#define BRIGHTNESS_PATH "/sys/class/backlight/panel0-backlight/brightness"
#define OPEN_HBM_VALUE "1"
#define CLOSE_HBM_VALUE "0"
#define HIGH_BRIGHTNESS_VALUE "1023"
#define LOW_BRIGHTNESS_VALUE "500"
#define SCREEN_HEIGHT 1.55f  // mm
#define FILM_HEIGHT 0.12f  // mm


namespace goodix
{
    SZCustomizedProductTest::SZCustomizedProductTest(HalContext* context)
            :SZProductTest(context)
    {
    }
    SZCustomizedProductTest::~SZCustomizedProductTest()
    {
    }

    void SZCustomizedProductTest::notifyCaptureImageFinish(gf_error_t err, uint32_t capture_cmd)
    {
        uint32_t len = 0;
        int8_t *test_result = NULL;

        VOID_FUNC_ENTER();

        do
        {
            len += HAL_TEST_SIZEOF_INT32;  // err code

            test_result = new int8_t[len] { 0 };
            if (test_result != NULL)
            {
                int8_t *current = test_result;
                memset(test_result, 0, len);

                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_ERROR_CODE,
                                    GF_ERROR_WITHOUT_OFFSET(err, GF_ERROR_SZ_FT_BASE));
            }
            else
            {
                len = 0;
            }

			mContext->mFingerprintCore->notifyFingerprintCmd(0, (int32_t)capture_cmd, test_result, len);
        }
        while (0);

        if (test_result != NULL)
        {
            delete []test_result;
        }

        VOID_FUNC_EXIT();
    }

    void SZCustomizedProductTest::notifyFactoryPerformance(gf_error_t err, gf_sz_factory_performance_t *result)
    {
        uint32_t len = 0;
        int8_t *test_result = NULL;

        VOID_FUNC_ENTER();

        do
        {
            len += HAL_TEST_SIZEOF_INT32;  // err code
            len += HAL_TEST_SIZEOF_INT32;  // nP2P
            len += HAL_TEST_SIZEOF_INT32;  // nNoise
            len += HAL_TEST_SIZEOF_INT32;  // nSSNR
            len += HAL_TEST_SIZEOF_INT32;  // nMeanRidge
            len += HAL_TEST_SIZEOF_INT32;  // nMeanValley
            len += HAL_TEST_SIZEOF_INT32;  // nSharpness
            len += HAL_TEST_SIZEOF_INT32;  // nSharpnessAll
            len += HAL_TEST_SIZEOF_INT32;  // nChartTouchDiff
            len += HAL_TEST_SIZEOF_INT32;  // nChartContrast

            test_result = new int8_t[len] { 0 };
            if (test_result != NULL)
            {
                int8_t *current = test_result;
                memset(test_result, 0, len);

                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_ERROR_CODE,
                                    GF_ERROR_WITHOUT_OFFSET(err, GF_ERROR_SZ_FT_BASE));
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_PERFORMANCE_P2P,
                                    result->nP2P);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_PERFORMANCE_NOISE,
                                    result->nNoise);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_PERFORMANCE_SSNR,
                                    result->nSSNR);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_PERFORMANCE_MEAN_RIDGE,
                                    result->nMeanRidge);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_PERFORMANCE_MEAN_VALLEY,
                                    result->nMeanValley);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_PERFORMANCE_SHARPNESS,
                                    result->nSharpness);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_PERFORMANCE_SHARPNESS_ALL,
                                    result->nSharpnessAll);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_PERFORMANCE_CHART_TOUCH_DIFF,
                                    result->nChartTouchDiff);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_PERFORMANCE_CHART_CONTRAST,
                                    result->nChartContrast);
            }
            else
            {
                len = 0;
            }

			mContext->mFingerprintCore->notifyFingerprintCmd(0, CMD_TEST_SZ_FT_CAPTURE_CHART, test_result, len);
        }
        while (0);

        if (test_result != NULL)
        {
            delete []test_result;
        }

        VOID_FUNC_EXIT();
    }

    void SZCustomizedProductTest::notifyFactoryCalibrate(gf_error_t err, gf_sz_factory_calibrate_t *result, uint32_t capture_cmd)
    {
        uint32_t len = 0;
        int8_t *test_result = NULL;

        VOID_FUNC_ENTER();

        do
        {
            len += HAL_TEST_SIZEOF_INT32;  // err code
            len += HAL_TEST_SIZEOF_INT32;  // nSNoise
            len += HAL_TEST_SIZEOF_INT32;  // nTNoise
            len += HAL_TEST_SIZEOF_INT32;  // nFleshTouchDiff
            len += HAL_TEST_SIZEOF_INT32;  // nLightLeakRatio
            len += HAL_TEST_SIZEOF_INT32;  // nFovLeft
            len += HAL_TEST_SIZEOF_INT32;  // nFovRight
            len += HAL_TEST_SIZEOF_INT32;  // nFovUp
            len += HAL_TEST_SIZEOF_INT32;  // nFovDown
            len += HAL_TEST_SIZEOF_ARRAY(sizeof(result->nRelativeIlluminance));  // nRelativeIlluminance
            len += HAL_TEST_SIZEOF_INT32;  // nIllumMaxX
            len += HAL_TEST_SIZEOF_INT32;  // nIllumMaxY
            len += HAL_TEST_SIZEOF_INT32;  // nScale
            len += HAL_TEST_SIZEOF_DOUBLE;  // rms
            len += HAL_TEST_SIZEOF_INT32;  // nCropWidth
            len += HAL_TEST_SIZEOF_INT32;  // nCropHeight
            len += HAL_TEST_SIZEOF_INT32;  // nBadPointNum
            len += HAL_TEST_SIZEOF_INT32;  // nClusterNum
            len += HAL_TEST_SIZEOF_INT32;  // nPixelOfLargestBadCluster
            len += HAL_TEST_SIZEOF_INT32;  // nStructRatio
            len += HAL_TEST_SIZEOF_INT32;  // centerOffsetLevel
            len += HAL_TEST_SIZEOF_INT32;  // nDarkSNoise
            len += HAL_TEST_SIZEOF_INT32;  // nDarkTNoise
            len += HAL_TEST_SIZEOF_INT32;  // lens_tilt_level;
            len += HAL_TEST_SIZEOF_INT32;  // lens_tilt_angle;
            len += HAL_TEST_SIZEOF_INT32;  // nPixelOfLargestOrientBadCluster;

            test_result = new int8_t[len] { 0 };
            if (test_result != NULL)
            {
                int8_t *current = test_result;
                memset(test_result, 0, len);

                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_ERROR_CODE,
                                    GF_ERROR_WITHOUT_OFFSET(err, GF_ERROR_SZ_FT_BASE));
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTORY_SNOISE,
                                    result->nSNoise);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTORY_TNOISE,
                                    result->nTNoise);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTORY_FLESH_TOUCH_DIFF,
                                    result->nFleshTouchDiff);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTORY_LIGHT_LEAK_RATIO,
                                    result->nLightLeakRatio);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTORY_FOV_LEFT,
                                    result->nFovLeft);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTORY_FOV_RIGHT,
                                    result->nFovRight);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTORY_FOV_UP,
                                    result->nFovUp);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTORY_FOV_DOWN,
                                    result->nFovDown);
                current = TestUtils::testEncodeArray(current, TEST_TOKEN_FACTORY_RELATIVE_ILLUMINANCE,
                            (int8_t *) result->nRelativeIlluminance, sizeof(result->nRelativeIlluminance));
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTORY_ILLUM_MAX_X,
                                    result->nIllumMaxX);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTORY_ILLUM_MAX_Y,
                                    result->nIllumMaxY);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTORY_SCALE,
                                    result->nScale);
                current = TestUtils::testEncodeDouble(current, TEST_TOKEN_FACTORY_RMS,
                                    result->rms);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTORY_CROP_WIDTH,
                                    result->nCropWidth);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTORY_CROP_HEIGHT,
                                    result->nCropHeight);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTORY_BAD_POINT_NUM,
                                    result->nBadPointNum);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTORY_CLUSTER_NUM,
                                    result->nClusterNum);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTORY_PIXEL_OF_LARGEST_BAD_CLUSTER,
                                    result->nPixelOfLargestBadCluster);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTROY_SCREEN_STRUCT_RATIO,
                                    result->nStructRatio);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTORY_CENTER_OFFSET,
                                    result->centerOffsetLevel);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTORY_DARK_SNOISE,
                                    result->nDarkSNoise);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTORY_DARK_TNOISE,
                                    result->nDarkTNoise);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTORY_LENS_TILT_LEVEL,
                                    result->lens_tilt_level);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTORY_LENS_TILT_ANGLE,
                                    result->lens_tilt_angle);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FACTORY_PIXEL_OF_LARGEST_ORIENT_BAD_CLUSTER,
                                    result->nPixelOfLargestOrientBadCluster);
            }
            else
            {
                len = 0;
            }

			mContext->mFingerprintCore->notifyFingerprintCmd(0, capture_cmd, test_result, len);
        }
        while (0);

        if (test_result != NULL)
        {
            delete []test_result;
        }

        VOID_FUNC_EXIT();
    }

    gf_error_t SZCustomizedProductTest::factoryCalibrate(uint32_t frame_type, uint8_t reliability_flag, uint32_t capture_cmd)
    {
        gf_error_t err = GF_SUCCESS;
        gf_sz_get_factory_calibrate_t *cmd = NULL;

        VOID_FUNC_ENTER();

        do
        {
            cmd = (gf_sz_get_factory_calibrate_t*)malloc(sizeof(gf_sz_get_factory_calibrate_t));
            if (NULL == cmd)
            {
                LOG_E(LOG_TAG, "[%s] out of memory", __func__);
                err = GF_ERROR_OUT_OF_MEMORY;
                break;
            }

            memset(cmd, 0, sizeof(gf_sz_get_factory_calibrate_t));
            cmd->cmd_header.cmd_id = GF_SZ_CMD_FACTORY_TEST_CALIBRATE;
            cmd->cmd_header.target = GF_TARGET_PRODUCT_TEST;
            cmd->factory_calibrate.reliability_test_flag = reliability_flag;

            err = getSensorInfo(&(cmd->factory_calibrate.sensor));
            if (err != GF_SUCCESS)
            {
                LOG_E(LOG_TAG, "[%s] get sensor info fail", __func__);
                err = GF_ERROR_GENERIC;
                break;
            }

            err = invokeCommand(cmd, sizeof(gf_sz_get_factory_calibrate_t));
            notifyFactoryCalibrate(err, &(cmd->factory_calibrate), capture_cmd);
#ifdef SUPPORT_DUMP
            if (frame_type < SZHalDump::DUMP_MAX)
            {
                SZHalDump* szdump = static_cast<SZHalDump*>(mContext->mHalDump);
                err = szdump->szDumpFactory((uint8_t *) &(cmd->factory_calibrate), sizeof(gf_sz_factory_calibrate_t),
                                            frame_type, init_timestamp, sizeof(init_timestamp), ft_time, err);
            }
#else  // SUPPORT_DUMP
            UNUSED_VAR(frame_type);
#endif  // SUPPORT_DUMP
        } while (0);

        if (NULL != cmd)
        {
            free(cmd);
            cmd = NULL;
        }

        VOID_FUNC_EXIT();
        return err;
    }

#ifdef SUPPORT_DUMP
    static uint32_t token2type(uint32_t token)
    {
        uint32_t frame_type = SZHalDump::DUMP_MAX;

        switch (token)
        {
            case CMD_TEST_SZ_FT_CAPTURE_DARK_BASE:
            {
                frame_type = SZHalDump::DUMP_DARK_BASE;
                break;
            }
            case CMD_TEST_SZ_FT_CAPTURE_H_DARK:
            {
                frame_type = SZHalDump::DUMP_H_DARK;
                break;
            }
            case CMD_TEST_SZ_FT_CAPTURE_L_DARK:
            {
                frame_type = SZHalDump::DUMP_L_DARK;
                break;
            }
            case CMD_TEST_SZ_FT_CAPTURE_H_FLESH:
            {
                frame_type = SZHalDump::DUMP_H_FLESH;
                break;
            }
            case CMD_TEST_SZ_FT_CAPTURE_L_FLESH:
            {
                frame_type = SZHalDump::DUMP_L_FLESH;
                break;
            }
            case CMD_TEST_SZ_FT_CAPTURE_CHART:
            {
                frame_type = SZHalDump::DUMP_CHART;
                break;
            }
            case CMD_TEST_SZ_FT_CAPTURE_CHECKBOX:
            case CMD_TEST_SZ_FT_SAMPLE_CALI_SCREEN_CHART:
            {
                frame_type = SZHalDump::DUMP_CALIBRATE_CHART;
                break;
            }
            case CMD_TEST_SZ_FT_SAMPLE_CALI_BASE:
            {
                frame_type = SZHalDump::DUMP_FINGER_SAMPLE;
                break;
            }
            case CMD_TEST_SZ_FT_SAMPLE_CALI_PERFORMANCE:
            {
                frame_type = SZHalDump::DUMP_SAMPLE_DATA;
                break;
            }
            case CMD_TEST_SZ_FT_CAPTURE_LOCATION_IMAGE:
            {
                break;
            }
            default:
            {
                break;
            }
        }

        return frame_type;
    }
#endif  // SUPPORT_DUMP

    void* SZCustomizedProductTest::factoryCaptureImageThread(uint32_t cmd)
    {
        uint32_t cmd_id = 0;
        gf_error_t err = GF_SUCCESS;
        gf_factory_capture_image_t *cmd_capture_buf = NULL;
        uint32_t time_sleep = 1;
        uint32_t frame_type = 0;
		LOG_D(LOG_TAG, "cmd = %u", cmd);

        switch (cmd)
        {
            case CMD_TEST_SZ_FT_CAPTURE_DARK_BASE:
            {
                cmd_id = GF_CMD_FACTORY_TEST_CAPTURE_DARK_BASE;
                time_sleep = 50 * 1000;
                break;
            }
            case CMD_TEST_SZ_FT_CAPTURE_H_DARK:
            {
                cmd_id = GF_SZ_CMD_FACTORY_TEST_CAPTURE_H_DARK;
                time_sleep = 100 * 1000;
                break;
            }
            case CMD_TEST_SZ_FT_CAPTURE_L_DARK:
            {
                cmd_id = GF_SZ_CMD_FACTORY_TEST_CAPTURE_L_DARK;
                time_sleep = 150 * 1000;
                break;
            }
            case CMD_TEST_SZ_FT_CAPTURE_H_FLESH:
            {
                cmd_id = GF_SZ_CMD_FACTORY_TEST_CAPTURE_H_FLESH;
                break;
            }
            case CMD_TEST_SZ_FT_CAPTURE_L_FLESH:
            {
                cmd_id = GF_SZ_CMD_FACTORY_TEST_CAPTURE_L_FLESH;
                time_sleep = 50 * 1000;
                break;
            }
            case CMD_TEST_SZ_FT_CAPTURE_CHART:
            {
                cmd_id = GF_SZ_CMD_FACTORY_TEST_CAPTURE_CHART;
                time_sleep = 100 * 1000;
                break;
            }
            case CMD_TEST_SZ_FT_SAMPLE_CALI_SCREEN_CHART:
            {
                cmd_id = GF_SZ_CMD_FACTORY_TEST_CAPTURE_CHECKBOX;
                time_sleep = 100 * 1000;
                break;
            }
            case CMD_TEST_SZ_FT_CAPTURE_CHECKBOX:
            case CMD_TEST_SZ_FT_CAPTURE_CHECKBOX_PERFORMANCE:
            {
                cmd_id = GF_SZ_CMD_FACTORY_TEST_CAPTURE_CHECKBOX;
                time_sleep = 50 * 1000;
                break;
            }
            case CMD_TEST_SZ_FT_CAPTURE_LOCATION_IMAGE:
            {
                cmd_id = GF_SZ_CMD_FACTORY_TEST_CAPTURE_LOCATION_IMAGE;
                break;
            }
            case CMD_TEST_SZ_FT_FACTORY_PERFORMANCE:
            {
                cmd_id = GF_SZ_CMD_FACTORY_TEST_CAPTURE_LOCATION_IMAGE;
                break;
            }
            default:
                break;
        }

        switch (cmd)
        {
            case CMD_TEST_SZ_FT_CAPTURE_DARK_BASE:
            case CMD_TEST_SZ_FT_CAPTURE_H_DARK:
            case CMD_TEST_SZ_FT_CAPTURE_L_DARK:
            case CMD_TEST_SZ_FT_CAPTURE_H_FLESH:
            case CMD_TEST_SZ_FT_CAPTURE_L_FLESH:
            case CMD_TEST_SZ_FT_CAPTURE_CHART:
            case CMD_TEST_SZ_FT_CAPTURE_CHECKBOX:
            case CMD_TEST_SZ_FT_CAPTURE_CHECKBOX_PERFORMANCE:
            case CMD_TEST_SZ_FT_CAPTURE_LOCATION_IMAGE:
            case CMD_TEST_SZ_FT_SAMPLE_CALI_SCREEN_CHART:
            {
                usleep(time_sleep);
                cmd_capture_buf = (gf_factory_capture_image_t *) malloc(sizeof(gf_factory_capture_image_t));    // NOLINT(542)
                if (NULL == cmd_capture_buf)
                {
                    LOG_E(LOG_TAG, "[%s] out of memory, cmd", __func__);
                    err = GF_ERROR_OUT_OF_MEMORY;
                    break;
                }
                memset(cmd_capture_buf, 0, sizeof(gf_factory_capture_image_t));

                cmd_capture_buf->cmd_header.cmd_id = cmd_id;
                cmd_capture_buf->cmd_header.target = GF_TARGET_PRODUCT_TEST;
                err = invokeCommand(cmd_capture_buf, sizeof(gf_factory_capture_image_t));

                if (err == GF_SUCCESS)
                {
#ifdef SUPPORT_DUMP
                    frame_type = token2type(cmd);
                    if (frame_type < SZHalDump::DUMP_KBCali)
                    {
                        SZHalDump* szdump = static_cast<SZHalDump*>(mContext->mHalDump);
                        err = szdump->szDumpFactory((uint8_t *) cmd_capture_buf, sizeof(gf_factory_capture_image_t),
                                            frame_type, init_timestamp, sizeof(init_timestamp), ft_time, err);
                    }
#endif  // SUPPORT_DUMP
                    if (CMD_TEST_SZ_FT_CAPTURE_CHECKBOX == cmd)
                    {
                        memcpy(&g_frame_data[CHECKBOX_INDEX * cmd_capture_buf->width * cmd_capture_buf->height],
                            cmd_capture_buf->img_data, cmd_capture_buf->img_data_size);
                        // gf_hal_dump(OPERATION_FACTORY_GET_CALIBRATE_RAWDATA, module, err);
#ifdef SUPPORT_DUMP
                        frame_type = SZHalDump::DUMP_KBCali;
#endif  // SUPPORT_DUMP
                        err = factoryCalibrate(frame_type, 0, cmd);
                        if (err != GF_SUCCESS)
                        {
                            LOG_E(LOG_TAG, "[%s] factory calibrate failed", __func__);
                            notifyCaptureImageFinish(err, cmd);
                            break;
                        }
                    }
                    else if (CMD_TEST_SZ_FT_CAPTURE_CHECKBOX_PERFORMANCE == cmd)
                    {
                        memcpy(&g_frame_data[CHECKBOX_INDEX * cmd_capture_buf->width * cmd_capture_buf->height],
                            cmd_capture_buf->img_data, cmd_capture_buf->img_data_size);
                        // gf_hal_dump(OPERATION_FACTORY_GET_CALIBRATE_RAWDATA, module, err);
#ifdef SUPPORT_DUMP
                        frame_type = SZHalDump::DUMP_KBCali;
#endif  // SUPPORT_DUMP
                        err = factoryCalibrate(frame_type, 1, cmd);
                        if (err != GF_SUCCESS)
                        {
                            LOG_E(LOG_TAG, "[%s] factory performance cali test failed", __func__);
                            notifyCaptureImageFinish(err, cmd);
                            break;
                        }
                    }
                    else if (CMD_TEST_SZ_FT_CAPTURE_CHART == cmd)
                    {
                        // gf_hal_dump(OPERATION_FACTORY_GET_PERFORMANCE_RAWDATA, cmd, err);
                        gf_sz_get_factory_performance_t *cmd_buf = NULL;
                        cmd_buf = (gf_sz_get_factory_performance_t*)malloc(sizeof(gf_sz_get_factory_performance_t));
                        if (NULL == cmd_buf)
                        {
                            LOG_E(LOG_TAG, "[%s] out of memory, cmd", __func__);
                            err = GF_ERROR_OUT_OF_MEMORY;
                            break;
                        }
                        memset(cmd_buf, 0, sizeof(gf_sz_get_factory_performance_t));

                        cmd_buf->cmd_header.cmd_id = GF_SZ_CMD_FACTORY_TEST_PERFORMANCE;
                        cmd_buf->cmd_header.target = GF_TARGET_PRODUCT_TEST;
                        cmd_buf->factory_performance.lpf_enabled = 1;

                        err = getSensorInfo(&(cmd_buf->factory_performance.sensor));
                        if (err != GF_SUCCESS)
                        {
                            LOG_E(LOG_TAG, "[%s] get sensor info fail", __func__);
                            err = GF_ERROR_GENERIC;
                            break;
                        }

                        err = invokeCommand(cmd_buf, sizeof(gf_sz_get_factory_performance_t));
                        notifyFactoryPerformance(err, &(cmd_buf->factory_performance));
#ifdef SUPPORT_DUMP
                        SZHalDump* szdump = static_cast<SZHalDump*>(mContext->mHalDump);
                        frame_type = SZHalDump::DUMP_PERFORMANCECali;
                        err = szdump->szDumpFactory((uint8_t *)&(cmd_buf->factory_performance), sizeof(gf_sz_factory_performance_t),
                                          frame_type, init_timestamp, sizeof(init_timestamp), ft_time, err);
#endif  // SUPPORT_DUMP
                        if (NULL != cmd_buf)
                        {
                            free(cmd_buf);
                            cmd_buf = NULL;
                        }

                        if (err != GF_SUCCESS)
                        {
                            LOG_E(LOG_TAG, "[%s] factory performance failed", __func__);
                            break;
                        }
                    }
                    else
                    {
                        notifyCaptureImageFinish(err, cmd);
                    }
                }
                else
                {
                    LOG_E(LOG_TAG, "[%s] capture rawData failed %d", __func__, cmd_id);
                    notifyCaptureImageFinish(err, cmd);
                }
                // gf_hal_notify_factory_test(module, err, module->cmd);
            }
            default:
                break;
        }

        if (NULL != cmd_capture_buf)
        {
            free(cmd_capture_buf);
            cmd_capture_buf = NULL;
        }
        return NULL;
    }

    gf_error_t SZCustomizedProductTest::factoryCaptureImage(gf_sz_test_rawdata_t *rawdata, uint16_t exposure_time,
                                         uint8_t frame_avg_num, uint16_t pga_gain)
    {
        gf_error_t err =  GF_SUCCESS;
        gf_sz_test_capture_image_t *cmd = NULL;
        uint32_t size = sizeof(gf_sz_test_capture_image_t);
        FUNC_ENTER();

        do
        {
            if (NULL == rawdata)
            {
                LOG_E(LOG_TAG, "[%s] param is erro", __func__);
                err = GF_ERROR_BAD_PARAMS;
                break;
            }
            cmd = (gf_sz_test_capture_image_t *) malloc(size);
            if (NULL == cmd)
            {
                LOG_E(LOG_TAG, "[%s] out of memory, cmd", __func__);
                err = GF_ERROR_OUT_OF_MEMORY;
                break;
            }

            memset(cmd, 0, size);
            cmd->exposure_time = exposure_time;
            cmd->frame_avg_num = frame_avg_num;
            cmd->pga_gain = pga_gain;

            cmd->cmd_header.cmd_id = GF_SZ_CMD_FACTORY_TEST_CAPTURE_IMAGE;
            cmd->cmd_header.target = GF_TARGET_PRODUCT_TEST;
            err = invokeCommand(cmd, size);
            if (GF_SUCCESS == err)
            {
                // LOG_D(LOG_TAG, "[%s] line:%d", __func__, __LINE__);
                memcpy(rawdata, &cmd->rawdata, sizeof(gf_sz_test_rawdata_t));
            }
        }
        while (0);

        if (cmd != NULL)
        {
            free(cmd);
        }

        FUNC_EXIT(err);
        return err;
    }

    gf_error_t SZCustomizedProductTest::getSensorInfo(gf_sz_chip_info_t *sensor)
    {
        gf_error_t err =  GF_SUCCESS;
        gf_sz_get_chip_info_t *cmd = NULL;
        uint32_t size = sizeof(gf_sz_get_chip_info_t);
        FUNC_ENTER();

        do
        {
            if (NULL == sensor)
            {
                LOG_E(LOG_TAG, "[%s] param is erro", __func__);
                err = GF_ERROR_BAD_PARAMS;
                break;
            }

            cmd = (gf_sz_get_chip_info_t *) malloc(size);
            if (NULL == cmd)
            {
                LOG_E(LOG_TAG, "[%s] out of memory, cmd", __func__);
                err = GF_ERROR_OUT_OF_MEMORY;
                break;
            }

            memset(cmd, 0, size);

            cmd->cmd_header.cmd_id = GF_SZ_CMD_FACTORY_TEST_GET_SENSOR_INFO;
            cmd->cmd_header.target = GF_TARGET_PRODUCT_TEST;
            err = invokeCommand(cmd, size);
            if (GF_SUCCESS == err)
            {
                memcpy(sensor->uid, cmd->chip_info.uid, GF_SENSOR_ID_LEN);
                sensor->col = cmd->chip_info.col;
                sensor->row = cmd->chip_info.row;
                sensor->dark_start_col = cmd->chip_info.dark_start_col;
                sensor->dark_len = cmd->chip_info.dark_len;
                sensor->expo_value = cmd->chip_info.expo_value;
                sensor->lens_type = cmd->chip_info.lens_type;
                sensor->factory_type = cmd->chip_info.factory_type;
                sensor->expo_time = cmd->chip_info.expo_time;
                sensor->ae_min_time = cmd->chip_info.ae_min_time;
                sensor->ae_max_time = cmd->chip_info.ae_max_time;
                sensor->ae_expo_start_time = cmd->chip_info.ae_expo_start_time;
            }

            if (simple_cali_ae_flag)
            {
                sensor->expo_value = sensor->expo_value * 4 / 5;
                LOG_D(LOG_TAG, "[%s] >>>>>> simple cali ae <<<<<<", __func__);
            }

            LOG_D(LOG_TAG, "[%s] row:%d, col:%d", __func__, sensor->row, sensor->col);
            LOG_D(LOG_TAG, "[%s] dark_start_col:%d, dark_len:%d", __func__, sensor->dark_start_col, sensor->dark_len);
            LOG_D(LOG_TAG, "[%s] expo_value:%d, lens_type:%d", __func__, sensor->expo_value, sensor->lens_type);
            LOG_D(LOG_TAG, "[%s] factory_type:%d, expo_time:%d, ae_min_time:%d, ae_expo_start_time:%d", __func__, sensor->factory_type,
                sensor->expo_time, sensor->ae_min_time, sensor->ae_expo_start_time);
        }
        while (0);

        if (cmd != NULL)
        {
            free(cmd);
        }

        FUNC_EXIT(err);
        return err;
    }

    gf_error_t SZCustomizedProductTest::rawDataDedark(gf_sz_test_rawdata_t *raw_data, gf_sz_chip_info_t *sensor,
        uint32_t *row_dark_average)
    {
        gf_error_t err = GF_SUCCESS;
        uint32_t dark_sum = 0;
        uint16_t i = 0;
        uint16_t j = 0;
        uint16_t index = 0;

        if (NULL == raw_data || NULL == sensor || NULL == row_dark_average)
        {
            LOG_E(LOG_TAG, "[%s] out of memory", __func__);
            err = GF_ERROR_BAD_PARAMS;
            return err;
        }

        for (i = 0; i < sensor->row; i++)
        {
            dark_sum = 0;
            for (j = 0; j < sensor->dark_len; j++)
            {
                index = i * sensor->col + sensor->dark_start_col + j;
                dark_sum += raw_data->data[index];
            }
            row_dark_average[i] = dark_sum / sensor->dark_len;
        }

        for (i = 0; i < sensor->row; i++)
        {
            for (j = 0; j < sensor->col; j++)
            {
                index = i * sensor->col + j;
                if (raw_data->data[index] >= row_dark_average[i])
                {
                    raw_data->data[index] = raw_data->data[index] - row_dark_average[i];
                }
                else
                {
                    raw_data->data[index] = 0;
                }
            }
        }

        return err;
    }

    gf_error_t SZCustomizedProductTest::findBrightestPoint(gf_sz_expo_auto_calibration_t *expo_auto_calibration)
    {
        gf_error_t err =  GF_SUCCESS;
        gf_sz_test_rawdata_t raw_data;
        gf_sz_test_find_brightest_point_t cmd;
        int i=0;
        FUNC_ENTER();

        do {
            if (NULL == expo_auto_calibration) {
                LOG_E(LOG_TAG, "[%s] param is error", __func__);
                err = GF_ERROR_BAD_PARAMS;
                break;
            }
            memset(&raw_data, 0, sizeof(gf_sz_test_rawdata_t));

            memset(&cmd, 0, sizeof(gf_sz_test_find_brightest_point_t));
            cmd.cmd_header.cmd_id = GF_SZ_CMD_FACTORY_TEST_FIND_BRIGHTEST_POINT;
            cmd.cmd_header.target = GF_TARGET_PRODUCT_TEST;
            cmd.i_frame_avg_num = GF_SZ_PRODUCT_TEST_NORMAL_FRAME_AVG_NUM;
            cmd.i_pga_gain = GF_SZ_PRODUCT_TEST_NORMAL_PGA_GAIN;
            memcpy(&cmd.i_expo_auto_calibration,expo_auto_calibration,sizeof(gf_sz_expo_auto_calibration_t));
            err = invokeCommand(&cmd, sizeof(gf_sz_test_find_brightest_point_t));

            if (GF_SUCCESS == err) {
                memcpy(&expo_auto_calibration->select_pixel, &cmd.i_expo_auto_calibration.select_pixel,
                            sizeof(expo_auto_calibration->select_pixel));
                for(i=0;i<GF_SZ_PRODUCT_TEST_SELECT_MAX_VALUE_NUM;i++){
                     LOG_D(LOG_TAG, "[%s] select_pixel[%d].x = %d", __func__,i,expo_auto_calibration->select_pixel[i].x);
                     LOG_D(LOG_TAG, "[%s] select_pixel[%d].y = %d", __func__,i,expo_auto_calibration->select_pixel[i].y);
                     LOG_D(LOG_TAG, "[%s] select_pixel[%d].value = %d", __func__,i,expo_auto_calibration->select_pixel[i].value);
                }
            } else {
                LOG_E(LOG_TAG, "[%s] find brightest point fail", __func__);
                err = GF_ERROR_GENERIC;
                break;
            }

            if (ae_stop_flag) {
                LOG_D(LOG_TAG, "[%s] stop calibration, exit", __func__);
                err = GF_ERROR_GENERIC;
                break;
            }
        } while (0);

        FUNC_EXIT(err);
        return err;
    }

    gf_error_t SZCustomizedProductTest::findBrightestPoint_3p(gf_sz_expo_auto_calibration_t *expo_auto_calibration)
    {
        gf_error_t err =  GF_SUCCESS;
        gf_sz_test_find_brightest_point3p_t cmd;
        int i=0;

        FUNC_ENTER();

        do {
            if (NULL == expo_auto_calibration) {
                LOG_E(LOG_TAG, "[%s] param is error", __func__);
                err = GF_ERROR_BAD_PARAMS;
                break;
            }

            memset(&cmd, 0, sizeof(gf_sz_test_find_brightest_point3p_t));
            cmd.cmd_header.cmd_id = GF_SZ_CMD_FACTORY_TEST_FIND_BRIGHTEST_POINT3P;
            cmd.cmd_header.target = GF_TARGET_PRODUCT_TEST;
            cmd.i_frame_avg_num = GF_SZ_PRODUCT_TEST_NORMAL_FRAME_AVG_NUM;
            cmd.i_pga_gain = GF_SZ_PRODUCT_TEST_NORMAL_PGA_GAIN;
            memcpy(&cmd.i_expo_auto_calibration,expo_auto_calibration,sizeof(gf_sz_expo_auto_calibration_t));
            err = invokeCommand(&cmd, sizeof(gf_sz_test_find_brightest_point3p_t));

            if (GF_SUCCESS == err) {
                memcpy(&expo_auto_calibration->select_pixel, &cmd.i_expo_auto_calibration.select_pixel,
                            sizeof(expo_auto_calibration->select_pixel));
                for(i=0;i<GF_SZ_PRODUCT_TEST_SELECT_MAX_VALUE_NUM;i++){
                     LOG_D(LOG_TAG, "[%s] select_pixel[%d].x = %d", __func__,i,expo_auto_calibration->select_pixel[i].x);
                     LOG_D(LOG_TAG, "[%s] select_pixel[%d].y = %d", __func__,i,expo_auto_calibration->select_pixel[i].y);
                     LOG_D(LOG_TAG, "[%s] select_pixel[%d].value = %d", __func__,i,expo_auto_calibration->select_pixel[i].value);
                }
            } else {
                LOG_E(LOG_TAG, "[%s] find brightest point3p fail", __func__);
                err = GF_ERROR_GENERIC;
                break;
            }

            if (ae_stop_flag) {
                LOG_D(LOG_TAG, "[%s] stop calibration, exit", __func__);
                err = GF_ERROR_GENERIC;
                break;
            }
        }
        while (0);

        FUNC_EXIT(err);
        return err;
    }


    gf_error_t SZCustomizedProductTest::findTargetExposureTime(gf_sz_expo_auto_calibration_t *expo_auto_calibration,
        gf_sz_exposure_data_t *exposure_dump_data)
    {
        gf_error_t err =  GF_SUCCESS;
        gf_sz_test_rawdata_t raw_data;
        gf_sz_test_find_target_expo_time_t cmd;
        uint16_t average_value = 0;
        uint16_t exposure_time = 0;
        gf_sz_chip_info_t *sensor = &expo_auto_calibration->sensor;
        FUNC_ENTER();

        do {
            if (NULL == expo_auto_calibration || NULL == exposure_dump_data) {
                LOG_E(LOG_TAG, "[%s] param is error", __func__);
                err = GF_ERROR_BAD_PARAMS;
                break;
            }

            exposure_time = expo_auto_calibration->sensor.ae_expo_start_time;
            memset(&raw_data, 0, sizeof(gf_sz_test_rawdata_t));

            memset(&cmd, 0, sizeof(gf_sz_test_find_target_expo_time_t));
            cmd.cmd_header.cmd_id = GF_SZ_CMD_FACTORY_TEST_FIND_TARGET_EXPO_TIME;
            cmd.cmd_header.target = GF_TARGET_PRODUCT_TEST;
            cmd.i_frame_avg_num = GF_SZ_PRODUCT_TEST_NORMAL_FRAME_AVG_NUM;
            cmd.i_pga_gain = GF_SZ_PRODUCT_TEST_NORMAL_PGA_GAIN;
            memcpy(&cmd.i_expo_auto_calibration,expo_auto_calibration,sizeof(gf_sz_expo_auto_calibration_t));
            err = invokeCommand(&cmd, sizeof(gf_sz_test_find_target_expo_time_t));

            if (GF_SUCCESS == err) {
                average_value = cmd.o_average_value;
                if (0 == average_value) {
                    LOG_E(LOG_TAG, "[%s]:average_value :%d, is invalid ", __func__, average_value);
                    err = GF_ERROR_BAD_PARAMS;
                    break;
                }
                expo_auto_calibration->target_exposure_time = exposure_time *
                                                              sensor->expo_value / average_value;
                LOG_D(LOG_TAG,
                      "[%s] exposure_time=%u, average_value=%u, expo_value=%d, target_exposure_time=%u",
                      __func__, \
                      exposure_time, average_value, sensor->expo_value,
                      expo_auto_calibration->target_exposure_time);

                if (expo_auto_calibration->target_exposure_time < exposure_time) {
                    expo_auto_calibration->target_exposure_time = exposure_time;
                    LOG_D(LOG_TAG, "[%s] target_exposure_time is small and use ae_min_time=%u",
                          __func__, exposure_time);
                } else if (expo_auto_calibration->target_exposure_time > expo_auto_calibration->sensor.ae_max_time) {
                    LOG_E(LOG_TAG, "[%s] target_exposure_time is bigger and use ae_max_time=%u",
                          __func__, \
                          expo_auto_calibration->sensor.ae_max_time);
                    err = GF_ERROR_GENERIC;
                    break;
                }

                expo_auto_calibration->target_rawdata_value = sensor->expo_value;
                LOG_D(LOG_TAG, "[%s] target_exposure_time=%u, target_rawdata_value=%u",
                      __func__, \
                      expo_auto_calibration->target_exposure_time,
                      expo_auto_calibration->target_rawdata_value);

                exposure_dump_data->ae_result.start_exposure_time = sensor->ae_expo_start_time;
                exposure_dump_data->ae_result.start_average_value = average_value;

            } else {
                LOG_E(LOG_TAG, "[%s] find target exposure time fail", __func__);
                err = GF_ERROR_GENERIC;
                break;
            }

            if (ae_stop_flag) {
                LOG_D(LOG_TAG, "[%s] stop calibration, exit", __func__);
                err = GF_ERROR_GENERIC;
                break;
            }
        } while (0);

        FUNC_EXIT(err);
        return err;
    }

    gf_error_t SZCustomizedProductTest::checkAeParam(gf_sz_expo_auto_calibration_t *expo_auto_calibration,
        gf_sz_exposure_data_t *exposure_dump_data)
    {
        gf_error_t err = GF_SUCCESS;
        uint16_t average_value = 0;
        uint16_t value = 0;
        gf_sz_test_check_ae_param_t cmd;
        VOID_FUNC_ENTER();

        do {
            if (NULL == expo_auto_calibration || NULL == exposure_dump_data) {
                LOG_E(LOG_TAG, "[%s] param is error", __func__);
                err = GF_ERROR_BAD_PARAMS;
                break;
            }

            memset(&cmd, 0, sizeof(gf_sz_test_check_ae_param_t));
            cmd.cmd_header.cmd_id = GF_SZ_CMD_FACTORY_TEST_CHECK_AE_PARAM;
            cmd.cmd_header.target = GF_TARGET_PRODUCT_TEST;
            cmd.i_frame_avg_num = GF_SZ_PRODUCT_TEST_NORMAL_FRAME_AVG_NUM;
            cmd.i_pga_gain = GF_SZ_PRODUCT_TEST_NORMAL_PGA_GAIN;
            memcpy(&cmd.i_expo_auto_calibration,expo_auto_calibration,sizeof(gf_sz_expo_auto_calibration_t));
            err = invokeCommand(&cmd, sizeof(gf_sz_test_check_ae_param_t));

            if (GF_SUCCESS == err) {
                average_value = cmd.o_average_value;
                LOG_D(LOG_TAG, "[%s] average_value=%u, exposure_time=%u", __func__,
                      average_value, expo_auto_calibration->target_exposure_time);
                value = abs(average_value - expo_auto_calibration->target_rawdata_value);

                if (value <= (expo_auto_calibration->target_rawdata_value * 10 / 100)) {
                    LOG_D(LOG_TAG,
                          "[%s] check ae param success, target_exposure_time:%u, average_value:%u, target_value:%u, threshold:%u",
                          \
                          __func__, expo_auto_calibration->target_exposure_time, average_value,
                          expo_auto_calibration->target_rawdata_value, \
                          expo_auto_calibration->target_rawdata_value * 10 / 100);
                } else {
                    err = GF_ERROR_BASE;
                    LOG_D(LOG_TAG,
                          "[%s] check ae param fail, target_exposure_time:%u, average_value:%u, target_value:%u, threshold:%u",
                          \
                          __func__, expo_auto_calibration->target_exposure_time, average_value,
                          expo_auto_calibration->target_rawdata_value, \
                          expo_auto_calibration->target_rawdata_value * 10 / 100);
                }

                exposure_dump_data->ae_result.target_exposure_time =
                    expo_auto_calibration->target_exposure_time;
                exposure_dump_data->ae_result.target_average_value = average_value;
                exposure_dump_data->ae_result.target_rawdata_value =
                    expo_auto_calibration->target_rawdata_value;
                exposure_dump_data->ae_result.rawdata_threshold =
                    expo_auto_calibration->target_rawdata_value * 10 / 100;

            } else {
                LOG_E(LOG_TAG, "[%s] check ae param fail", __func__);
                break;
            }

            if (ae_stop_flag) {
                LOG_D(LOG_TAG, "[%s] stop calibration, exit", __func__);
                err = GF_ERROR_GENERIC;
                break;
            }
        } while (0);

        VOID_FUNC_EXIT();
        return err;
    }

    gf_error_t SZCustomizedProductTest::setExposureParam(gf_sz_expo_auto_calibration_t *expo_auto_calibration, int32_t flag)
    {
        gf_error_t err =  GF_SUCCESS;
        gf_sz_test_exposure_param_t *cmd = NULL;
        uint32_t size = sizeof(gf_sz_test_exposure_param_t);
        FUNC_ENTER();

        do
        {
            cmd = (gf_sz_test_exposure_param_t *) malloc(size);
            if (NULL == cmd)
            {
                LOG_E(LOG_TAG, "[%s] out of memory, cmd", __func__);
                err = GF_ERROR_OUT_OF_MEMORY;
                break;
            }

            memset(cmd, 0, size);
            cmd->flag = flag;
            cmd->exposure_time = expo_auto_calibration->target_exposure_time;
            cmd->cmd_header.cmd_id = GF_SZ_CMD_FACTORY_TEST_FINSH_EXPO_AUTO_CALIBRATION;
            cmd->cmd_header.target = GF_TARGET_PRODUCT_TEST;
            err = invokeCommand(cmd, size);
        }
        while (0);

        if (cmd != NULL)
        {
            free(cmd);
        }

        FUNC_EXIT(err);
        return err;
    }

    void SZCustomizedProductTest::notifyExpoAutoCalibrationFinish(gf_sz_expo_auto_calibration_t *expo_auto_calibration, uint32_t flag)
    {
        uint32_t len = 0;
        int8_t *test_result = NULL;

        VOID_FUNC_ENTER();

        do
        {
            // auto calibration result
            len += HAL_TEST_SIZEOF_INT32;
            // short exposure time
            len += HAL_TEST_SIZEOF_INT32;
            len += HAL_TEST_SIZEOF_INT32;

            test_result = new int8_t[len] { 0 };
            if (test_result != NULL)
            {
                int8_t *current = test_result;
                memset(test_result, 0, len);
                LOG_D(LOG_TAG, "[%s] flag %d, exposure time %d", __func__, flag, expo_auto_calibration->target_exposure_time);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_EXPO_AUTO_CALIBRATION_FLAG, flag);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_SHORT_EXPOSURE_TIME, expo_auto_calibration->target_exposure_time);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_ERROR_CODE, GF_ERROR_WITHOUT_OFFSET(flag, GF_ERROR_SZ_FT_BASE));
            }
            else
            {
                len = 0;
            }
		
			mContext->mFingerprintCore->notifyFingerprintCmd(0, CMD_TEST_SZ_FT_EXPO_AUTO_CALIBRATION, test_result, len);
        }
        while (0);

        if (test_result != NULL)
        {
            delete []test_result;
        }

        VOID_FUNC_EXIT();
        return;
    }

    void* SZCustomizedProductTest::expoAutoCalibrationThread(void* obj)
    {
        gf_error_t err = GF_SUCCESS;
        gf_sz_chip_info_t sensor;
        memset(&sensor, 0, sizeof(gf_sz_chip_info_t));
        gf_sz_expo_auto_calibration_t *expo_auto_calibration = NULL;
        SZCustomizedProductTest* sz_product_test_obj = (SZCustomizedProductTest*)obj;
        gf_sz_exposure_data_t *exposure_dump_data = NULL;
        gf_sz_config_t* config = (gf_sz_config_t*)(mContext->mConfig);

        VOID_FUNC_ENTER();

        do
        {
            expo_auto_calibration = (gf_sz_expo_auto_calibration_t *)malloc(sizeof(gf_sz_expo_auto_calibration_t));
            if (NULL == expo_auto_calibration)
            {
                LOG_E(LOG_TAG, "[%s] out of memory, cmd", __func__);
                err = GF_ERROR_OUT_OF_MEMORY;
                break;
            }
            memset(expo_auto_calibration, 0, sizeof(gf_sz_expo_auto_calibration_t));

            exposure_dump_data = (gf_sz_exposure_data_t *)malloc(sizeof(gf_sz_exposure_data_t));
            if (NULL == exposure_dump_data)
            {
                LOG_E(LOG_TAG, "[%s] out of memory, cmd", __func__);
                err = GF_ERROR_OUT_OF_MEMORY;
                break;
            }
            memset(exposure_dump_data, 0, sizeof(gf_sz_exposure_data_t));

            err = sz_product_test_obj->getSensorInfo(&sensor);
            if (err != GF_SUCCESS)
            {
                LOG_E(LOG_TAG, "[%s] get sensor info fail", __func__);
                err = GF_ERROR_GENERIC;
                break;
            }

            memcpy(&expo_auto_calibration->sensor, &sensor, sizeof(gf_sz_chip_info_t));
            memcpy(&exposure_dump_data->sensor, &sensor, sizeof(gf_sz_chip_info_t));

            if (0x2 == config->illumination_mode)
            {
                err = sz_product_test_obj->findBrightestPoint_3p(expo_auto_calibration);
            }
            else
            {
                err = sz_product_test_obj->findBrightestPoint(expo_auto_calibration);
            }
            if (err != GF_SUCCESS)
            {
                LOG_E(LOG_TAG, "[%s] find brightest point fail", __func__);
                err = GF_ERROR_GENERIC;
                break;
            }

            err = sz_product_test_obj->findTargetExposureTime(expo_auto_calibration, exposure_dump_data);
            if (err != GF_SUCCESS)
            {
                LOG_E(LOG_TAG, "[%s] find short exposure time fail", __func__);
                err = GF_ERROR_GENERIC;
                break;
            }

            err = sz_product_test_obj->checkAeParam(expo_auto_calibration, exposure_dump_data);
            if (err != GF_SUCCESS)
            {
                LOG_E(LOG_TAG, "[%s] ae param fail", __func__);
                err = GF_ERROR_GENERIC;
                break;
            }
        }
        while (0);

        if (expo_auto_calibration != NULL)
        {
            if (GF_SUCCESS == err)
            {
                sz_product_test_obj->setExposureParam(expo_auto_calibration, EXPO_AUTO_CALIBRATION_SUCCESS);
                sz_product_test_obj->notifyExpoAutoCalibrationFinish(expo_auto_calibration, EXPO_AUTO_CALIBRATION_SUCCESS);
            }
            else
            {
                sz_product_test_obj->setExposureParam(expo_auto_calibration, EXPO_AUTO_CALIBRATION_FAIL);

                if (sz_product_test_obj->ae_stop_flag)
                {
                    sz_product_test_obj->notifyExpoAutoCalibrationFinish(expo_auto_calibration, EXPO_AUTO_CALIBRATION_STOP);
                }
                else
                {
                    sz_product_test_obj->notifyExpoAutoCalibrationFinish(expo_auto_calibration, GF_SZ_FT_ERROR_SELF_EXPOSURE_ABNORMAL);
                }
            }

            if (exposure_dump_data != NULL)
            {
#ifdef SUPPORT_DUMP
                SZHalDump* szdump = static_cast<SZHalDump*>(mContext->mHalDump);
                err = szdump->szDumpAutoExposure((uint8_t *)exposure_dump_data, sizeof(gf_sz_exposure_data_t),
                            init_timestamp, sizeof(init_timestamp), err);
#endif  // SUPPORT_DUMP

                free(exposure_dump_data);
            }

            free(expo_auto_calibration);
        }

        VOID_FUNC_EXIT();
        return NULL;
    }

    gf_error_t SZCustomizedProductTest::expoAutoCalibration(void)
    {
        gf_error_t err = GF_SUCCESS;

        FUNC_ENTER();

        do
        {
            ae_stop_flag = 0;
            expoAutoCalibrationThread(this);
            simple_cali_ae_flag = 0;
        }
        while (0);

        FUNC_EXIT(err);
        return GF_SUCCESS;
    }

    gf_error_t SZCustomizedProductTest::stopExpoAutoCalibration(void)
    {
        gf_error_t err = GF_SUCCESS;
        FUNC_ENTER();

        do
        {
            ae_stop_flag = 1;
        }
        while (0);

        FUNC_EXIT(err);

        return GF_SUCCESS;
    }

    void SZCustomizedProductTest::notifySpiTest(gf_error_t err, gf_sz_spi_test_t *result)
    {
        uint32_t len = 0;
        int8_t *test_result = NULL;

        VOID_FUNC_ENTER();

        do
        {
            len += HAL_TEST_SIZEOF_INT32;  // err code
            len += HAL_TEST_SIZEOF_INT32;  // sensor id
            len += HAL_TEST_SIZEOF_INT32;  // MCU id
            len += HAL_TEST_SIZEOF_INT32;  // flash id
            len += HAL_TEST_SIZEOF_INT32;  // pmic id
            len += HAL_TEST_SIZEOF_ARRAY(13);  // SENSOR ID

            test_result = new int8_t[len] { 0 };
            if (test_result != NULL)
            {
                int8_t *current = test_result;
                memset(test_result, 0, len);

                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_ERROR_CODE,
                                    GF_ERROR_WITHOUT_OFFSET(err, GF_ERROR_SZ_FT_BASE));
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_FLASH_ID,
                                    result->flash_id);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_SENSOR_ID,
                                    result->sensor_id);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_MCU_ID,
                                    result->mcu_id);
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_PMIC_ID,
                                    result->pmic_id);
                current = TestUtils::testEncodeArray(current, TEST_TOKEN_CHIP_ID,
                                    result->otp_info, 13);

                LOG_D(LOG_TAG, "[%s] flash_id = 0x%x", __func__, result->flash_id);
                LOG_D(LOG_TAG, "[%s] sensor_id = 0x%x", __func__, result->sensor_id);
                LOG_D(LOG_TAG, "[%s] mcu_id = 0x%x", __func__, result->mcu_id);
                LOG_D(LOG_TAG, "[%s] pmic_id = 0x%x", __func__, result->pmic_id);
            }
            else
            {
                len = 0;
            }

			mContext->mFingerprintCore->notifyFingerprintCmd(0, CMD_TEST_SZ_FT_SPI, test_result, len);

        }
        while (0);

        if (test_result != NULL)
        {
            delete []test_result;
        }

        VOID_FUNC_EXIT();
    }

    gf_error_t SZCustomizedProductTest::spiTest(void)
    {
        gf_error_t err = GF_SUCCESS;
        gf_sz_spi_test_t *cmd = NULL;
        uint32_t size = sizeof(gf_sz_spi_test_t);

        VOID_FUNC_ENTER();

        do
        {
            cmd = (gf_sz_spi_test_t *) malloc(size);
            if (NULL == cmd)
            {
                err = GF_ERROR_OUT_OF_MEMORY;
                LOG_E(LOG_TAG, "[%s] out of memory", __func__);
                break;
            }
            memset(cmd, 0, sizeof(gf_sz_spi_test_t));

            cmd->cmd_header.cmd_id = GF_SZ_CMD_FACTORY_TEST_SPI;
            cmd->cmd_header.target = GF_TARGET_PRODUCT_TEST;
            err = invokeCommand(cmd, size);

            notifySpiTest(err, cmd);
#ifdef SUPPORT_DUMP
            // store sensor otp and start time to haldump
            SZHalDump* szdump = static_cast<SZHalDump*>(mContext->mHalDump);
            szdump->szDumpSettingPath((uint8_t*)cmd->otp_info);
#endif  // SUPPORT_DUMP
        } while (0);

        if (NULL != cmd)
        {
            free(cmd);
            cmd = NULL;
        }

        VOID_FUNC_EXIT();

        return err;
    }

    void SZCustomizedProductTest::notifyfactoryReset(gf_error_t err)
    {
        int8_t *test_result = NULL;
        uint32_t len = 0;

        VOID_FUNC_ENTER();

        do
        {
            // error_code
            len += HAL_TEST_SIZEOF_INT32;

            test_result = new int8_t[len] { 0 };
            if (test_result != NULL)
            {
                int8_t *current = test_result;
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_ERROR_CODE,
                                                    GF_ERROR_WITHOUT_OFFSET(err, GF_ERROR_SZ_FT_BASE));
            }
            else
            {
                len = 0;
            }

			mContext->mFingerprintCore->notifyFingerprintCmd(0, CMD_TEST_SZ_FT_SPI_RST_INT, test_result, len);

        } while (0);

        if (test_result != NULL)
        {
            delete []test_result;
        }

        VOID_FUNC_EXIT();
    }

    void SZCustomizedProductTest::notifyfactoryMtCheck(gf_error_t err)
    {
        int8_t *test_result = NULL;
        uint32_t len = 0;

        VOID_FUNC_ENTER();

        do
        {
            // error_code
            len += HAL_TEST_SIZEOF_INT32;

            test_result = new int8_t[len] { 0 };
            if (test_result != NULL)
            {
                int8_t *current = test_result;
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_ERROR_CODE,
                                                    GF_ERROR_WITHOUT_OFFSET(err, GF_ERROR_SZ_FT_BASE));
            }
            else
            {
                len = 0;
            }

			mContext->mFingerprintCore->notifyFingerprintCmd(0, CMD_TEST_SZ_FT_MT_CHECK, test_result, len);
			
        } while (0);

        if (test_result != NULL)
        {
            delete []test_result;
        }

        VOID_FUNC_EXIT();
    }
    gf_error_t SZCustomizedProductTest::factoryResetHard(void)
    {
        gf_error_t err = GF_SUCCESS;
        gf_cmd_header_t *cmd = NULL;
        uint32_t size = sizeof(gf_cmd_header_t);

        VOID_FUNC_ENTER();

        do
        {
            cmd = (gf_cmd_header_t *) malloc(size);
            if (NULL == cmd)
            {
                err = GF_ERROR_OUT_OF_MEMORY;
                LOG_E(LOG_TAG, "[%s] out of memory", __func__);
                break;
            }
            memset(cmd, 0, sizeof(gf_cmd_header_t));

            cmd->cmd_id = GF_SZ_CMD_FACTORY_RESET;
            cmd->target = GF_TARGET_PRODUCT_TEST;
            err = invokeCommand(cmd, size);

            notifyfactoryReset(err);
        } while (0);

        if (NULL != cmd)
        {
            free(cmd);
            cmd = NULL;
        }

        VOID_FUNC_EXIT();

        return GF_SUCCESS;
    }

    gf_error_t SZCustomizedProductTest::factoryMtCheck(void)
    {
        gf_error_t err = GF_SUCCESS;
        gf_cmd_header_t *cmd = NULL;
        uint32_t size = sizeof(gf_cmd_header_t);

        VOID_FUNC_ENTER();

        do
        {
            cmd = (gf_cmd_header_t *) malloc(size);
            if (NULL == cmd)
            {
                err = GF_ERROR_OUT_OF_MEMORY;
                LOG_E(LOG_TAG, "[%s] out of memory", __func__);
                break;
            }
            memset(cmd, 0, sizeof(gf_cmd_header_t));

            cmd->cmd_id = GF_SZ_CMD_FACTORY_MT_CHECK;
            cmd->target = GF_TARGET_PRODUCT_TEST;
            err = invokeCommand(cmd, size);
            notifyfactoryMtCheck(err);
        } while (0);

        if (NULL != cmd)
        {
            free(cmd);
            cmd = NULL;
        }

        VOID_FUNC_EXIT();

        return GF_SUCCESS;
    }

#if 0
    static int32_t writeIntByChar(char const* path, int32_t value)
    {
        int32_t fd = 0;

        LOG_D(LOG_TAG, "[%s] write %d to %s", __func__, value, path);

        fd = open(path, O_RDWR);
        if (fd >= 0)
        {
            char buffer[20] = {0};
            int32_t bytes = snprintf(buffer, sizeof(buffer), "%d\n", value);
            int32_t amt = write(fd, buffer, bytes);

            close(fd);

            return amt == -1 ? -errno : 0;
        }
        else
        {
            return -errno;
        }
    }

    static int32_t writeInt(char const* path, int32_t value)
    {
        int32_t fd = 0;

        LOG_D(LOG_TAG, "[%s] write %d to %s", __func__, value, path);

        fd = open(path, O_RDWR);
        if (fd >= 0)
        {
            int32_t amt = write(fd, &value, sizeof(int32_t));

            close(fd);

            return amt == -1 ? -errno : 0;
        }
        else
        {
            return -errno;
        }
    }
#endif  // write

    static int32_t writeStr(char const* path, char const* str)
    {
        int32_t fd = 0;

        LOG_D(LOG_TAG, "[%s] write %s to %s", __func__, str, path);

        fd = open(path, O_RDWR);
        if (fd >= 0)
        {
            char buffer[20] = {0};
            int32_t bytes = snprintf(buffer, sizeof(buffer), "%s", str);
            int32_t amt = write(fd, buffer, bytes);

            close(fd);

            return amt == -1 ? -errno : 0;
        }
        else
        {
            return -errno;
        }
    }

    void SZCustomizedProductTest::notifySetScreenBrightness(gf_error_t err, int32_t cmd_id)
    {
        int8_t *test_result = NULL;
        uint32_t len = 0;

        VOID_FUNC_ENTER();

        do
        {
            // error_code
            len += HAL_TEST_SIZEOF_INT32;

            test_result = new int8_t[len] { 0 };
            if (test_result != NULL)
            {
                int8_t *current = test_result;
                current = TestUtils::testEncodeInt32(current, TEST_TOKEN_ERROR_CODE,
                                                    GF_ERROR_WITHOUT_OFFSET(err, GF_ERROR_SZ_FT_BASE));
            }
            else
            {
                len = 0;
            }

            mContext->mFingerprintCore->notifyFingerprintCmd(0, cmd_id, test_result, len);
        } while (0);

        if (test_result != NULL)
        {
            delete []test_result;
        }

        VOID_FUNC_EXIT();
    }

    gf_error_t SZCustomizedProductTest::setHbmMode(void)
    {
        gf_error_t err = GF_SUCCESS;

        VOID_FUNC_ENTER();

        do
        {
            if (writeStr(HBM_PATH, OPEN_HBM_VALUE))
            {
                LOG_E(LOG_TAG, "[%s] set hbm mode fail", __func__);
                err = GF_SZ_FT_ERROR_SET_HBM_MODE_FAIL;
            }
        } while (0);

        notifySetScreenBrightness(err, CMD_TEST_SZ_SET_HBM_MODE);

        VOID_FUNC_EXIT();

        return GF_SUCCESS;
    }

    gf_error_t SZCustomizedProductTest::closeHbmMode(void)
    {
        gf_error_t err = GF_SUCCESS;

        VOID_FUNC_ENTER();

        do
        {
            if (writeStr(HBM_PATH, CLOSE_HBM_VALUE))
            {
                LOG_E(LOG_TAG, "[%s] close hbm mode fail", __func__);
                err = GF_SZ_FT_ERROR_CLOSE_HBM_MODE_FAIL;
            }
        } while (0);

        notifySetScreenBrightness(err, CMD_TEST_SZ_CLOSE_HBM_MODE);

        VOID_FUNC_EXIT();

        return GF_SUCCESS;
    }

    gf_error_t SZCustomizedProductTest::setHighBrightness(void)
    {
        gf_error_t err = GF_SUCCESS;

        VOID_FUNC_ENTER();

        do
        {
            if (writeStr(BRIGHTNESS_PATH, HIGH_BRIGHTNESS_VALUE))
            {
                LOG_E(LOG_TAG, "[%s] set high brightness fail", __func__);
                err = GF_SZ_FT_ERROR_SET_HIGH_BRIGHTNESS_FAIL;
            }
        } while (0);

        notifySetScreenBrightness(err, CMD_TEST_SZ_SET_HIGH_BRIGHTNESS);

        VOID_FUNC_EXIT();

        return GF_SUCCESS;
    }

    gf_error_t SZCustomizedProductTest::setLowBrightness(uint32_t value)
    {
        gf_error_t err = GF_SUCCESS;
        char buffer[20];
        VOID_FUNC_ENTER();

        do
        {
            snprintf(buffer, sizeof(buffer), "%d\n", value);
            LOG_D(LOG_TAG, "[%s] set  brightness %s", __func__, buffer);
            if (writeStr(BRIGHTNESS_PATH, buffer))
            {
                LOG_E(LOG_TAG, "[%s] set low brightness fail", __func__);
                err = GF_SZ_FT_ERROR_SET_LOW_BRIGHTNESS_FAIL;
            }
        } while (0);

        notifySetScreenBrightness(err, CMD_TEST_SZ_SET_LOW_BRIGHTNESS);

        VOID_FUNC_EXIT();

        return GF_SUCCESS;
    }

    gf_error_t SZCustomizedProductTest::onEvent(gf_event_type_t e)
    {
        gf_error_t err = GF_SUCCESS;
        FUNC_ENTER();
		//add by chenran
        int8_t *test_result = NULL;
        uint32_t len = 0;

        LOG_D(LOG_TAG, "[%s] sz factory test get event: %d", __func__, e);
        do
        {
            switch (e)
            {
                case EVENT_IRQ_RESET:
                {
                    if (FACTORY_RESET_INT == mWorkState)
                    {
                        err = factoryResetHard();
                    }

                    break;
                }
                case EVENT_FINGER_DOWN:
                {
                    if (STATE_KPI == mWorkState)
                    {
                        mContext->mFingerprintCore->setHbmMode(1);
                        #ifdef MTK_HBM_NODE
                        usleep(50*1000);
                        #endif
                        gf_sz_image_kpi_t cmd;
                        memset(&cmd, 0, sizeof(gf_sz_image_kpi_t));

                        cmd.cmd_header.cmd_id = GF_SZ_CMD_FACTORY_KPI;
                        cmd.cmd_header.target = GF_TARGET_PRODUCT_TEST;
                        err = invokeCommand(&cmd, sizeof(gf_sz_image_kpi_t));
                        len += HAL_TEST_SIZEOF_INT32;  // err code
                        test_result = new int8_t[len] { 0 };
                        if (test_result != NULL)
                        {
                            int8_t *current = test_result;
                            memset(test_result, 0, len);
                            current = TestUtils::testEncodeInt32(current, cmd.o_image_quality,cmd.o_valid_area);
                        }
                        else
                        {
                            len = 0;
                        }

                        LOG_D(LOG_TAG, "[%s] image_quality: %d", __func__, cmd.o_image_quality);
                        LOG_D(LOG_TAG, "[%s] valid_area: %d", __func__, cmd.o_valid_area);

                        mContext->mFingerprintCore->setHbmMode(0);
                        mContext->mFingerprintCore->notifyFingerprintCmd(0, CMD_TEST_OPLUS_GET_IMAGE_QUALITY, test_result, len);
                    }
                   else if (STATE_CALI_BASE == mWorkState)
                    {
                        LOG_D(LOG_TAG, "[%s] sample cali base", __func__);
                        gfHalSampleCaliBase();
                    }
                    else if(STATE_CALI_AUTO_CALIBRATION == mWorkState)
                    {
                        expoAutoCalibration();
                    }
                    else {
                        SZProductTest::onEvent(e);
                    }

                    break;
                }
                default:
                {
                    SZProductTest::onEvent(e);
                    break;
                }
            }
        }while (0);
        FUNC_EXIT(err);
        return err;
    }

    gf_error_t SZCustomizedProductTest::getMTInfo(void **mt, uint32_t *mt_len)
    {
        gf_error_t err = GF_SUCCESS;
        gf_sensor_mt_info_t *mt_info = NULL;
        FUNC_ENTER();

        do
        {
            gf_sz_test_get_mt_t cmd;
            memset(&cmd, 0, sizeof(gf_sz_test_get_mt_t));
            if (mt_len == NULL)
            {
                LOG_E(LOG_TAG, "[%s] mt_len is NULL", __func__);
                err = GF_ERROR_BAD_PARAMS;
                break;
            }

            cmd.cmd_header.cmd_id = GF_SZ_CMD_FACTORY_TEST_GET_MT_INFO;
            cmd.cmd_header.target = GF_TARGET_PRODUCT_TEST;
            err = invokeCommand(&cmd, sizeof(gf_sz_test_get_mt_t));

            if (err == GF_SUCCESS)
            {
                mt_info =(gf_sensor_mt_info_t *) malloc(sizeof(gf_sensor_mt_info_t));
                if (NULL != mt_info)
                {
                    memcpy(mt_info, &cmd.mt_info, sizeof(gf_sensor_mt_info_t));
                }
                *mt = mt_info;
                *mt_len = sizeof(gf_sensor_mt_info_t);
            }
        }while (0);

        FUNC_EXIT(err);
        return err;
    }

    gf_error_t SZCustomizedProductTest::getBigDataSensorInfo(void **buf)
    {
        gf_error_t err = GF_SUCCESS;
        gf_sensor_mt_info_t *mt_info = NULL;
        uint32_t mt_info_len = 0;
        FUNC_ENTER();

        do
        {
            err = executeCommand(CMD_TEST_SZ_FACTORY_TEST_GET_MT_INFO, NULL, 0, (int8_t **)&mt_info, &mt_info_len);
            if (err != GF_SUCCESS)
            {
                break;
            }

            *buf = (void *)mt_info;
        } while (0);

        FUNC_EXIT(err);
        return err;
    }

    gf_error_t SZCustomizedProductTest::gfHalSampleCaliInit()
    {
        gf_error_t err = GF_SUCCESS;
        gf_cmd_header_t cmd = {0};

        VOID_FUNC_ENTER();
        HalUtils::genTimestamp(init_timestamp, sizeof(init_timestamp));

        simple_cali_ae_flag = 1;

        cmd.cmd_id = GF_SZ_CMD_FACTORY_TEST_SAMPLE_INIT;
        cmd.target = GF_TARGET_PRODUCT_TEST;
        err = invokeCommand(&cmd, sizeof(gf_cmd_header_t));
        spiTest();

        VOID_FUNC_EXIT();

        return err;
    }

    gf_error_t SZCustomizedProductTest::gfHalSampleSaveData()
    {
        gf_error_t err = GF_SUCCESS;
        gf_cmd_header_t cmd = {0};

        VOID_FUNC_ENTER();

        cmd.cmd_id = GF_SZ_CMD_FACTORY_TEST_SAMPLE_CALI_SAVE_DATA;
        cmd.target = GF_TARGET_PRODUCT_TEST;
        err = invokeCommand(&cmd, sizeof(gf_cmd_header_t));

        VOID_FUNC_EXIT();

        return err;
    }

    gf_error_t SZCustomizedProductTest::gfHalSampleCaliExit()
    {
        gf_error_t err = GF_SUCCESS;
        gf_cmd_header_t cmd = {0};

        VOID_FUNC_ENTER();

        simple_cali_ae_flag = 0;

        cmd.cmd_id = GF_SZ_CMD_FACTORY_TEST_SAMPLE_EXIT;
        cmd.target = GF_TARGET_PRODUCT_TEST;
        err = invokeCommand(&cmd, sizeof(gf_cmd_header_t));

        VOID_FUNC_EXIT();

        return err;
    }


    void SZCustomizedProductTest::gfHalFactoryNotifySampleCaliBase(SAMPLE_CALI_STATE state)
    {
        uint32_t len = 0;
        int8_t *test_result = NULL;

        len += HAL_TEST_SIZEOF_INT32; //err code
        test_result = (int8_t *) malloc(len);

        if (test_result != NULL)
        {
            memset(test_result, 0, len);
            int8_t *current = test_result;
            current = TestUtils::testEncodeInt32(current, TEST_TOKEN_ERROR_CODE, state);
            mContext->mFingerprintCore->notifyFingerprintCmd(0, CMD_TEST_SZ_FT_SAMPLE_CALI_BASE, test_result, len);
        }

        if (test_result != NULL)
        {
            free(test_result);
            test_result = NULL;
        }
    }

    void SZCustomizedProductTest::gfHalFactoryNotifySampleCaliPerformance(SAMPLE_CALI_STATE state)
    {
        uint32_t len = 0;
        int8_t *test_result = NULL;

        len += HAL_TEST_SIZEOF_INT32; //err code
        test_result = (int8_t *) malloc(len);

        if (test_result != NULL)
        {
            memset(test_result, 0, len);
            int8_t *current = test_result;
            current = TestUtils::testEncodeInt32(current, TEST_TOKEN_ERROR_CODE, state);
            mContext->mFingerprintCore->notifyFingerprintCmd(0, CMD_TEST_SZ_FT_SAMPLE_CALI_PERFORMANCE, test_result, len);
        }

        if (test_result != NULL)
        {
            free(test_result);
            test_result = NULL;
        }
    }


    gf_error_t SZCustomizedProductTest::gfHalSampleCaliBase()
    {
        gf_error_t err =  GF_SUCCESS;
        gf_sample_cali_base_t *cmd = NULL;
        uint32_t size = sizeof(gf_sample_cali_base_t);
        UNUSED_VAR(size);
        FUNC_ENTER();

       do
        {
            cmd = (gf_sample_cali_base_t *)malloc(size);    // NOLINT(542)
            if (NULL == cmd)
            {
                LOG_E(LOG_TAG, "[%s] out of memory, cmd", __func__);
                err = GF_ERROR_OUT_OF_MEMORY;
                break;
            }

            memset(cmd, 0, size);
            cmd->cmd_header.cmd_id = GF_SZ_CMD_FACTORY_TEST_SAMPLE_CALI_BASE;
            cmd->cmd_header.target = GF_TARGET_PRODUCT_TEST;
            err = invokeCommand(cmd, size);
#ifdef SUPPORT_DUMP
            uint32_t frame_type = 0;
            frame_type = token2type(CMD_TEST_SZ_FT_SAMPLE_CALI_BASE);
            if (frame_type < SZHalDump::DUMP_MAX)
            {
                SZHalDump* szdump = static_cast<SZHalDump*>(mContext->mHalDump);
                err = szdump->szDumpFactory((uint8_t *)cmd, sizeof(gf_sample_cali_base_t),
                                            frame_type, init_timestamp, sizeof(init_timestamp), ft_time, err);
            }
#endif  // SUPPORT_DUMP

            gfHalFactoryNotifySampleCaliBase(cmd->state);
            //TODO dump rawdata here
            // gf_hal_factory_dump(OPERATION_SAMPLE_CALI_BASE, &(cmd->finger_rawdata), err);
        }
        while (0);

        if (cmd != NULL)
        {
            free(cmd);
        }

        FUNC_EXIT(err);
        return err;
    }

    gf_error_t SZCustomizedProductTest::gfHalSampleCaliPerformance(const int8_t *in, uint32_t inLen)
    {
        gf_error_t err =  GF_SUCCESS;
        gf_error_t dump_err =  GF_SUCCESS;
        gf_sample_cali_data_t *cmd = NULL;
        uint32_t size = sizeof(gf_sample_cali_data_t);
        const int8_t *in_buf = in;
        uint32_t token = 0;
        uint32_t chart_width  = 0;

        FUNC_ENTER();
        UNUSED_VAR(inLen);

        do
        {
            cmd = (gf_sample_cali_data_t *)malloc(size);    // NOLINT(542)
            if (NULL == cmd)
            {
                LOG_E(LOG_TAG, "[%s] out of memory, cmd", __func__);
                err = GF_ERROR_OUT_OF_MEMORY;
                break;
            }

            if (NULL != in) {
                do {
                    in_buf = TestUtils::testDecodeUint32(&token, in_buf);

                    switch (token) {
                        case TEST_TOKEN_METADATA: {
                            in_buf = TestUtils::testDecodeUint32(&chart_width, in_buf);
                            LOG_D(LOG_TAG, "[%s] chart_distance %d ", __func__, chart_width);
                            break;
                        }

                        default: {
                            break;
                        }
                    }
                } while (0);
            }

            memset(cmd, 0, size);
            cmd->cmd_header.cmd_id = GF_SZ_CMD_FACTORY_TEST_SAMPLE_CALI_PERFORMANCE;
            cmd->cmd_header.target = GF_TARGET_PRODUCT_TEST;
            cmd->i_chartWidth = chart_width;
            cmd->i_screen_height = SCREEN_HEIGHT;
            cmd->i_film_height = FILM_HEIGHT;
            err = invokeCommand(cmd, size);
            gfHalFactoryNotifySampleCaliPerformance(cmd->state);
#ifdef SUPPORT_DUMP
            uint32_t frame_type = 0;
            frame_type = token2type(CMD_TEST_SZ_FT_SAMPLE_CALI_PERFORMANCE);
            if (frame_type < SZHalDump::DUMP_MAX)
            {
                SZHalDump* szdump = static_cast<SZHalDump*>(mContext->mHalDump);
                dump_err = szdump->szDumpFactory((uint8_t *) cmd, sizeof(gf_sample_cali_data_t),
                                            frame_type, init_timestamp, sizeof(init_timestamp), ft_time, err);
            }
#endif  // SUPPORT_DUMP
        }
        while (0);

        if (cmd != NULL)
        {
            free(cmd);
        }

        FUNC_EXIT(err);
        return err;
    }

    gf_error_t SZCustomizedProductTest::executeCommand(int32_t cmdId, const int8_t *in, uint32_t inLen, int8_t **out, uint32_t *outLen)
    {
        gf_error_t err = GF_SUCCESS;
        FUNC_ENTER();
        // ProductTest::executeCommand(cmdId, in, inLen, out, outLen);
        switch (cmdId)
        {
            case CMD_TEST_SZ_SET_GROUP_ID:
            case CMD_TEST_SZ_UNTRUSTED_ENROLL:
            case CMD_TEST_SZ_UNTRUSTED_AUTHENTICATE:
            {
                break;
            }
            case CMD_TEST_SZ_FINGER_DOWN:
            case CMD_TEST_SZ_FINGER_UP:
            {
                if (mWorkState == STATE_FARR_ENROLL || mWorkState == STATE_FARR_AUTHENTICATE)
                {
                    mContext->mSensor->wakeupSensor();
                }
                break;
            }
            default:
            {
                mContext->mSensor->wakeupSensor();
                break;
            }
        }

        do
        {
            switch (cmdId)
            {
                case CMD_TEST_SZ_FT_CAPTURE_DARK_BASE:
                case CMD_TEST_SZ_FT_CAPTURE_H_DARK:
                case CMD_TEST_SZ_FT_CAPTURE_L_DARK:
                case CMD_TEST_SZ_FT_CAPTURE_H_FLESH:
                case CMD_TEST_SZ_FT_CAPTURE_L_FLESH:
                case CMD_TEST_SZ_FT_CAPTURE_CHART:
                case CMD_TEST_SZ_FT_CAPTURE_CHECKBOX:
                case CMD_TEST_SZ_FT_CAPTURE_LOCATION_IMAGE:
                case CMD_TEST_SZ_FT_SAMPLE_CALI_SCREEN_CHART:
                case CMD_TEST_SZ_FT_CAPTURE_CHECKBOX_PERFORMANCE:
                {
                    factoryCaptureImageThread(cmdId);
                    break;
                }
                case CMD_TEST_SZ_FT_EXPO_AUTO_CALIBRATION:
                {
                    expoAutoCalibration();
                    break;
                }
                case CMD_TEST_SZ_FT_STOP_EXPO_AUTO_CALIBRATION:
                {
                    stopExpoAutoCalibration();
                    break;
                }
                case CMD_TEST_SZ_FT_RESET:
                case CMD_TEST_SZ_FT_SPI_RST_INT:
                {
                    mContext->mDevice->enableIrq();
                    mWorkState = FACTORY_RESET_INT;
                    mContext->mCenter->registerHandler(this);
                    err = mContext->mDevice->reset();
                    usleep(100*1000);  // 100ms, ensure that rst int has already reproted
                    mContext->mDevice->disableIrq();

                    if (GF_SUCCESS != err)
                    {
                        notifyfactoryReset(err);
                    }
                    break;
                }
                case CMD_TEST_SZ_FT_SPI:
                {
                    err = spiTest();
                    break;
                }
                case CMD_TEST_SZ_FT_MT_CHECK:
                {
                    factoryMtCheck();
                    break;
                }
                case CMD_TEST_SZ_FT_KPI:
                {
                    LOG_D(LOG_TAG, "[%s] test image kpi", __func__);
                    mWorkState = STATE_KPI;
                    mContext->mCenter->registerHandler(this);
                    break;
                }
                case CMD_TEST_SZ_SET_HBM_MODE:
                {
                    LOG_D(LOG_TAG, "[%s] set hbm mode", __func__);
                    setHbmMode();
                    usleep(50*1000);
                    break;
                }
                case CMD_TEST_SZ_CLOSE_HBM_MODE:
                {
                    LOG_D(LOG_TAG, "[%s] close hbm mode", __func__);
                    closeHbmMode();
                    usleep(50*1000);
                    break;
                }
                case CMD_TEST_SZ_SET_HIGH_BRIGHTNESS:
                {
                    LOG_D(LOG_TAG, "[%s] set high brightness", __func__);
                    setHighBrightness();
                    usleep(50*1000);
                    break;
                }
                case CMD_TEST_SZ_SET_LOW_BRIGHTNESS:
                {
                    uint32_t brihtness = 0;
                    const int8_t *in_buf = in;
                    uint32_t token = 0;

                    do
                    {
                        in_buf = TestUtils::testDecodeUint32(&token, in_buf);

                        switch (token)
                        {
                            case TEST_TOKEN_METADATA:
                            {
                                in_buf = TestUtils::testDecodeUint32(&brihtness, in_buf);
                                break;
                            }

                            default:
                                break;
                        }
                    }
                    while (in_buf < in + inLen);

                    LOG_D(LOG_TAG, "[%s] setbrightness %d", __func__, brihtness);
                    setLowBrightness(brihtness);
                    usleep(50*1000);
                    break;
                }
                case CMD_TEST_SZ_FACTORY_TEST_GET_MT_INFO:
                {
                    gf_error_t err = GF_SUCCESS;
                    int8_t *test_result = NULL;
                    uint32_t len = 0;
                    gf_sensor_mt_info_t *mt_info = NULL;
                    uint32_t mt_info_len = 0;
                    uint32_t module = 0;
                    uint32_t lens = 0;

                    err = getMTInfo((void **)&mt_info, &mt_info_len);

                    if (mt_info != NULL)
                    {
                        module = mt_info->flash_vendor_id >> 4;
                        lens = mt_info->flash_vendor_id & 0x0f;
                    }

                    LOG_D(LOG_TAG, "[%s] module %d, lens %d", __func__, module, lens);

                    // err code
                    len += HAL_TEST_SIZEOF_INT32;
                    // module
                    len += HAL_TEST_SIZEOF_INT32;
                    // lens
                    len += HAL_TEST_SIZEOF_INT32;
                    // S
                    len += HAL_TEST_SIZEOF_ARRAY(30);  // SENSOR ID

                    test_result = new int8_t[len] { 0 };
                    if (test_result != NULL)
                    {
                        int8_t *current = test_result;
                        current = TestUtils::testEncodeInt32(current, TEST_TOKEN_ERROR_CODE,
                                                    GF_ERROR_WITHOUT_OFFSET(err, GF_ERROR_SZ_FT_BASE));
                        current = TestUtils::testEncodeInt32(current, TEST_TOKEN_MODULE_VENDOR,
                                                            module);
                        current = TestUtils::testEncodeInt32(current, TEST_TOKEN_LENS_VENSOR,
                                                            lens);
                        current = TestUtils::testEncodeArray(current, TEST_TOKEN_SERIAL_NUM,
                                                            (int8_t *)mt_info->module_QR_code, 30);

                    }
                    else
                    {
                        len = 0;
                    }

                    mContext->mFingerprintCore->notifyFingerprintCmd(0, CMD_TEST_SZ_FACTORY_TEST_GET_MT_INFO, test_result, len);

                    if (test_result != NULL)
                    {
                        delete []test_result;
                    }
                    break;
                }
                case CMD_TEST_SZ_SLEEP_SENSOR:
                {
                    mContext->mSensor->sleepSensor();
                    break;
                }
                case CMD_TEST_SZ_FT_SAMPLE_CALI_BASE:
                {
                    mContext->mCenter->registerHandler(this);
                    mWorkState = STATE_CALI_BASE;
                    break;
                }
                case CMD_TEST_SZ_FT_SAMPLE_CALI_AUTO_CALIBRATION:
                {
                    mContext->mCenter->registerHandler(this);
                    mWorkState = STATE_CALI_AUTO_CALIBRATION;
                    break;
                }
                case CMD_TEST_SZ_FT_SAMPLE_STOP_CALI_AUTO_CALIBRATION:
                {
                    stopExpoAutoCalibration();
                    mWorkState = STATE_CALI_STOP_AUTO_CALIBRATION;
                    break;
                }
                case CMD_TEST_SZ_FT_SAMPLE_CALI_INIT:
                {
                    err = gfHalSampleCaliInit();
                    break;
                }
                case CMD_TEST_SZ_FT_SAMPLE_CALI_EXIT:
                {
                    err = gfHalSampleCaliExit();
                    break;
                }
                case CMD_TEST_SZ_FT_SAMPLE_CALI_PERFORMANCE:
                {
                    err = gfHalSampleCaliPerformance(in, inLen);
                    if (GF_SUCCESS == err)
                    {
                        gfHalSampleSaveData();
                    }
                    break;
                }
                default:
                {
                    err = SZProductTest::executeCommand(cmdId, in, inLen, out, outLen);
                    break;
                }
            }
        }
        while (0);
        FUNC_EXIT(err);
        return err;
    }

}  // namespace goodix
