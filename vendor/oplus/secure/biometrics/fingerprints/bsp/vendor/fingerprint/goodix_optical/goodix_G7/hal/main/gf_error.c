/*
 * Copyright (C) 2013-2017, Shenzhen Huiding Technology Co., Ltd.
 * All Rights Reserved.
 * Version:
 * Description:
 * History:
 */

#include<string.h>
#include"gf_error.h"

// string error definition
gf_strerror_t err_table[ ] = {
    { GF_SUCCESS, "GF_SUCCESS" },
    { GF_ERROR_BASE, "GF_ERROR_BASE" },
    { GF_ERROR_OUT_OF_MEMORY, "GF_ERROR_OUT_OF_MEMORY" },
    { GF_ERROR_OPEN_TA_FAILED, "GF_ERROR_OPEN_TA_FAILED" },
    { GF_ERROR_MODULE_NOT_INITED, "GF_ERROR_MODULE_NOT_INITED"},
    { GF_ERROR_BAD_PARAMS, "GF_ERROR_BAD_PARAMS" },
    { GF_ERROR_NO_SPACE, "GF_ERROR_NO_SPACE" },
    { GF_ERROR_MEMORY_COPY_FAILED, "GF_ERROR_MEMORY_COPY_FAILED" },
    { GF_ERROR_REACH_FINGERS_UPLIMIT, "GF_ERROR_REACH_FINGERS_UPLIMIT" },
    { GF_ERROR_NOT_MATCH, "GF_ERROR_NOT_MATCH" },
    { GF_ERROR_CANCELED, "GF_ERROR_CANCELED" },
    { GF_ERROR_TIMEOUT, "GF_ERROR_TIMEOUT" },
    { GF_ERROR_PREPROCESS_FAILED, "GF_ERROR_PREPROCESS_FAILED" },
    { GF_ERROR_GENERIC, "GF_ERROR_GENERIC" },
    { GF_ERROR_ACQUIRED_PARTIAL, "GF_ERROR_ACQUIRED_PARTIAL" },
    { GF_ERROR_ACQUIRED_IMAGER_DIRTY, "GF_ERROR_ACQUIRED_IMAGER_DIRTY" },
    { GF_ERROR_DUPLICATE_FINGER, "GF_ERROR_DUPLICATE_FINGER" },
    { GF_ERROR_OPEN_DEVICE_FAILED, "GF_ERROR_OPEN_DEVICE_FAILED" },
    { GF_ERROR_HAL_GENERAL_ERROR, "GF_ERROR_HAL_GENERAL_ERROR" },
    { GF_ERROR_HAL_FILE_DESCRIPTION_NULL, "GF_ERROR_HAL_FILE_DESCRIPTION_NULL" },
    { GF_ERROR_HAL_IOCTL_FAILED, "GF_ERROR_HAL_IOCTL_FAILED" },
    { GF_ERROR_HAL_TIMER_FUNC, "GF_ERROR_HAL_TIMER_FUNC" },
    { GF_ERROR_CORRUPT_CONTENT, "GF_ERROR_CORRUPT_CONTENT" },
    { GF_ERROR_INCORRECT_VERSION, "GF_ERROR_INCORRECT_VERSION" },
    { GF_ERROR_CORRUPT_OBJECT, "GF_ERROR_CORRUPT_OBJECT" },
    { GF_ERROR_INVALID_DATA, "GF_ERROR_INVALID_DATA" },
    { GF_ERROR_SPI_TRANSFER_ERROR, "GF_ERROR_SPI_TRANSFER_ERROR" },
    { GF_ERROR_SPI_GENERAL_ERROR, "GF_ERROR_SPI_GENERAL_ERROR" },
    { GF_ERROR_SPI_IRQ_HANDLE, "GF_ERROR_SPI_IRQ_HANDLE" },
    { GF_ERROR_SPI_RAW_DATA_CRC_FAILED, "GF_ERROR_SPI_RAW_DATA_CRC_FAILED" },
    { GF_ERROR_SPI_RAW_DATA_BUF_BUSY, "GF_ERROR_SPI_RAW_DATA_BUF_BUSY" },
    { GF_ERROR_SPI_FW_CFG_DATA_ERROR, "GF_ERROR_SPI_FW_CFG_DATA_ERROR" },
    { GF_ERROR_SPI_FW_DOWNLOAD_FAILED, "GF_ERROR_SPI_FW_DOWNLOAD_FAILED" },
    { GF_ERROR_SPI_CFG_DOWNLOAD_FAILED, "GF_ERROR_SPI_CFG_DOWNLOAD_FAILED" },
    { GF_ERROR_SAVE_FP_TEMPLATE, "GF_ERROR_SAVE_FP_TEMPLATE" },
    { GF_ERROR_FP_BUSY, "GF_ERROR_FP_BUSY" },
    { GF_ERROR_OPEN_SECURE_OBJECT_FAILED, "GF_ERROR_OPEN_SECURE_OBJECT_FAILED" },
    { GF_ERROR_READ_SECURE_OBJECT_FAILED, "GF_ERROR_READ_SECURE_OBJECT_FAILED" },
    { GF_ERROR_WRITE_SECURE_OBJECT_FAILED, "GF_ERROR_WRITE_SECURE_OBJECT_FAILED" },
    { GF_ERROR_DELETE_SECURE_OBJECT_FAILED, "GF_ERROR_DELETE_SECURE_OBJECT_FAILED" },
    { GF_ERROR_SECURE_OBJECT_NOT_EXIST, "GF_ERROR_SECURE_OBJECT_NOT_EXIST" },
    { GF_ERROR_WRITE_CONFIG_FAILED, "GF_ERROR_WRITE_CONFIG_FAILED" },
    { GF_ERROR_TEST_SENSOR_FAILED, "GF_ERROR_TEST_SENSOR_FAILED" },
    { GF_ERROR_SET_MODE_FAILED, "GF_ERROR_SET_MODE_FAILED" },
    { GF_ERROR_CHIP_ID_NOT_CORRECT, "GF_ERROR_CHIP_ID_NOT_CORRECT" },
    { GF_ERROR_MAX_NUM, "GF_ERROR_MAX_NUM" },
    { GF_ERROR_TEST_BAD_POINT_FAILED, "GF_ERROR_TEST_BAD_POINT_FAILED" },
    { GF_ERROR_TEST_FRR_FAR_ENROLL_DIFFERENT_FINGER, "GF_ERROR_TEST_FRR_FAR_ENROLL_DIFFERENT_FINGER" },
    { GF_ERROR_DUPLICATE_AREA, "GF_ERROR_DUPLICATE_AREA" },
    { GF_ERROR_SPI_COMMUNICATION, "GF_ERROR_SPI_COMMUNICATION" },
    { GF_ERROR_FINGER_NOT_EXIST, "GF_ERROR_FINGER_NOT_EXIST" },
    { GF_ERROR_INVALID_PREPROCESS_VERSION, "GF_ERROR_INVALID_PREPROCESS_VERSION" },
    { GF_ERROR_TA_DEAD, "GF_ERROR_TA_DEAD" },
    { GF_ERROR_NAV_TOO_FAST, "GF_ERROR_NAV_TOO_FAST" },
    { GF_ERROR_UNSUPPORT_CHIP, "GF_ERROR_UNSUPPORT_CHIP" },
    { GF_ERROR_INVALID_FINGER_PRESS, "GF_ERROR_INVALID_FINGER_PRESS" },
    { GF_ERROR_TA_GENERATE_RANDOM, "GF_ERROR_TA_GENERATE_RANDOM" },
    { GF_ERROR_BIO_ASSAY_FAIL, "GF_ERROR_BIO_ASSAY_FAIL" },
    { GF_ERROR_INVALID_HAT_VERSION, "GF_ERROR_INVALID_HAT_VERSION" },
    { GF_ERROR_INVALID_CHALLENGE, "GF_ERROR_INVALID_CHALLENGE" },
    { GF_ERROR_UNTRUSTED_ENROLL, "GF_ERROR_UNTRUSTED_ENROLL" },
    { GF_ERROR_INVALID_BASE, "GF_ERROR_INVALID_BASE" },
    { GF_ERROR_SENSOR_BROKEN_CHECK_NEXT_FRAME, "GF_ERROR_SENSOR_BROKEN_CHECK_NEXT_FRAME" },
    { GF_ERROR_SENSOR_BROKEN_CHECK_ALGO_ERROR, "GF_ERROR_SENSOR_BROKEN_CHECK_ALGO_ERROR" },
    { GF_ERROR_SENSOR_IS_BROKEN, "GF_ERROR_SENSOR_IS_BROKEN" },
    { GF_ERROR_SENSOR_NOT_AVAILABLE, "GF_ERROR_SENSOR_NOT_AVAILABLE" },
    { GF_ERROR_SENSOR_TEST_FAILED, "GF_ERROR_SENSOR_TEST_FAILED" },
    { GF_ERROR_MATCH_FAIL_AND_RETRY, "GF_ERROR_MATCH_FAIL_AND_RETRY" },
    { GF_ERROR_FINGER_NOT_LEAVE, "GF_ERROR_FINGER_NOT_LEAVE" },
    { GF_ERROR_GET_TEMPERATURE_FAILED, "GF_ERROR_GET_TEMPERATURE_FAILED" },
    { GF_ERROR_GET_OTP_INFO_FAILED, "GF_ERROR_GET_OTP_INFO_FAILED" },
    { GF_ERROR_TEST_RESET_PIN, "GF_ERROR_TEST_RESET_PIN" },
    { GF_ERROR_TEST_INTERRUPT_PIN, "GF_ERROR_TEST_INTERRUPT_PIN" },
    { GF_ERROR_UNKNOWN_CMD, "GF_ERROR_UNKNOWN_CMD" },
    { GF_ERROR_TEST_SPI_TRANSFER_TIMEOUT, "GF_ERROR_TEST_SPI_TRANSFER_TIMEOUT" },
    { GF_ERROR_ENCODE_TLV, "GF_ERROR_ENCODE_TLV" },
    { GF_ERROR_INVALID_FP_ID, "GF_ERROR_INVALID_FP_ID" },
    { GF_ERROR_NATIVE_SERVICE_BASE, "GF_ERROR_NATIVE_SERVICE_BASE" },
    { GF_ERROR_NATIVE_SERVICE_GETSERVICE, "GF_ERROR_NATIVE_SERVICE_GETSERVICE" },
    { GF_ERROR_NATIVE_SERVICE_INIT_HAL, "GF_ERROR_NATIVE_SERVICE_INIT_HAL" },
    { GF_ERROR_MKDIR_FAILED, "GF_ERROR_MKDIR_FAILED" },
    { GF_ERROR_FILE_OPEN_FAILED, "GF_ERROR_FILE_OPEN_FAILED" },
    { GF_ERROR_FILE_NOT_EXIST, "GF_ERROR_FILE_NOT_EXIST" },
    { GF_ERROR_FILE_READ_FAILED, "GF_ERROR_FILE_READ_FAILED" },
    { GF_ERROR_FILE_WRITE_FAILED, "GF_ERROR_FILE_WRITE_FAILED" },
    { GF_ERROR_FILE_DELETE_FAILED, "GF_ERROR_FILE_DELETE_FAILED" },
    { GF_ERROR_TOO_MUCH_UNDER_SATURATED_PIXELS, "GF_ERROR_TOO_MUCH_UNDER_SATURATED_PIXELS" },
    { GF_ERROR_TOO_MUCH_OVER_SATURATED_PIXELS, "GF_ERROR_TOO_MUCH_OVER_SATURATED_PIXELS" },
    { GF_ERROR_SENSOR_HAS_CHANGED, "GF_ERROR_SENSOR_HAS_CHANGED" },
    { GF_ERROR_OPEN_SESSION_FAILED, "GF_ERROR_OPEN_SESSION_FAILED" },
    { GF_ERROR_FACTORY_TEST_FAILED, "GF_ERROR_FACTORY_TEST_FAILED" },
    { GF_ERROR_NO_GROUP_ID, "GF_ERROR_NO_GROUP_ID" },
    { GF_ERROR_UNKNOWN_TEST_TOKEN, "GF_ERROR_UNKNOWN_TEST_TOKEN" },
    { GF_FINGER_FEATURE_STUDY_FAILED, "GF_FINGER_FEATURE_STUDY_FAILED" },
    { GF_ERROR_INVALID_OTP_VERSION, "GF_ERROR_INVALID_OTP_VERSION" },
    { GF_ERROR_CALIBRATION_NOT_READY, "GF_ERROR_CALIBRATION_NOT_READY"},
    { GF_ERROR_ALGO_INVALID_DATA, "GF_ERROR_ALGO_INVALID_DATA" },
    { GF_ERROR_TOO_FAST, "GF_ERROR_TOO_FAST" },
    { GF_ERROR_TEST_NOT_SUPPORTED, "GF_ERROR_TEST_NOT_SUPPORTED" },
    { GF_ERROR_NO_NEED_UPDATE_BASE, "GF_ERROR_NO_NEED_UPDATE_BASE" },
    { GF_ERROR_OTP_CHECK_FAIL, "GF_ERROR_OTP_CHECK_FAIL" },
    { GF_ERROR_INIT_ALGO_REGISTER_INFO, "GF_ERROR_INIT_ALGO_REGISTER_INFO" },
    { GF_ERROR_DYNAMIC_ENROLL_INVALID_PRESS_TOO_MUCH, "GF_ERROR_DYNAMIC_ENROLL_INVALID_PRESS_TOO_MUCH" },
    { GF_ERROR_DYNAMIC_ERNOLL_INCOMPLETE_TEMPLATE, "GF_ERROR_DYNAMIC_ERNOLL_INCOMPLETE_TEMPLATE" },
    { GF_ERROR_ALGO_DIRTY_FINGER, "GF_ERROR_ALGO_DIRTY_FINGER" },
    { GF_ERROR_PREPROCESS_FAIL_AND_RETRY, "GF_ERROR_PREPROCESS_FAIL_AND_RETRY" },
    { GF_ERROR_CRC_CHECK_FAILED_AND_RETRY, "GF_ERROR_CRC_CHECK_FAILED_AND_RETRY" },
    { GF_ERROR_ALGO_COVER_BROKEN, "GF_ERROR_ALGO_COVER_BROKEN" },
    { GF_ERROR_FARGO_CHIP_ID_NOT_CORRECT, "GF_ERROR_FARGO_CHIP_ID_NOT_CORRECT" },
    { GF_ERROR_CREATE_FINGER_TEMPLATE, "GF_ERROR_CREATE_FINGER_TEMPLATE" },  // = GF_ERROR_BASE + 107,
    { GF_ERROR_DUMP_CONFIG_NOT_CORRECT, "GF_ERROR_DUMP_CONFIG_NOT_CORRECT" },
    { GF_ERROR_INVALID_STATE, "GF_ERROR_INVALID_STATE" },
    { GF_ERROR_FAILED_AND_RETRY, "GF_ERROR_FAILED_AND_RETRY" },
    { GF_ERROR_MT_INFO_CHECK_FAIL, "GF_ERROR_MT_INFO_CHECK_FAIL" },
    { GF_ERROR_TEST_RESET_INT_PIN_MCU, "GF_ERROR_TEST_RESET_INT_PIN_MCU" },
    { GF_ERROR_TEST_RESET_INT_PIN_SENSOR, "GF_ERROR_TEST_RESET_INT_PIN_SENSOR" },
    { GF_ERROR_TEST_RESET_INT_PIN_PMIC, "GF_ERROR_TEST_RESET_INT_PIN_PMIC" },
    { GF_ERROR_TEST_MT, "GF_ERROR_TEST_MT" },
    { GF_ERROR_TEST_SPMT, "GF_ERROR_TEST_SPMT" },
    { GF_ERROR_TEST_OTP, "GF_ERROR_TEST_OTP" },
    { GF_ERROR_CHIP_IS_NOT_READY, "GF_ERROR_CHIP_IS_NOT_READY" },
    { GF_ERROR_FACTORY_FOV_INVALID, "GF_ERROR_FACTORY_FOV_INVALID" },
    { GF_ERROR_FACTORY_BADPOINT_INVALID, "GF_ERROR_FACTORY_BADPOINT_INVALID" },
    { GF_ERROR_FACTORY_SCALE_INVALID, "GF_ERROR_FACTORY_SCALE_INVALID" },
    { GF_ERROR_FACTORY_TNOISE_INVALID, "GF_ERROR_FACTORY_TNOISE_INVALID" },
    { GF_ERROR_FACTORY_SNOISE_INVALID, "GF_ERROR_FACTORY_SNOISE_INVALID" },
    { GF_ERROR_FACTORY_FLESH_TOUCHDIFF_INVALID, "GF_ERROR_FACTORY_FLESH_TOUCHDIFF_INVALID" },
    { GF_ERROR_FACTORY_LIGHT_LEAK_RATIO_INVALID, "GF_ERROR_FACTORY_LIGHT_LEAK_RATIO_INVALID" },
    { GF_ERROR_FACTORY_RELATIVEILLUMINANCE_INVALID, "GF_ERROR_FACTORY_RELATIVEILLUMINANCE_INVALID" },
    { GF_ERROR_FACTORY_CROP_INVALID, "GF_ERROR_FACTORY_CROP_INVALID" },
    { GF_ERROR_FACTORY_SSNR_INVALID, "GF_ERROR_FACTORY_SSNR_INVALID" },
    { GF_ERROR_FACTORY_SHAPENESS_INVALID, "GF_ERROR_FACTORY_SHAPENESS_INVALID" },
    { GF_ERROR_FACTORY_CONSTRAST_INVALID, "GF_ERROR_FACTORY_CONSTRAST_INVALID" },
    { GF_ERROR_FACTORY_RAWDATA_INVALID, "GF_ERROR_FACTORY_RAWDATA_INVALID" },
    { GF_ERROR_HOLD_MCU_FAILED, "GF_ERROR_HOLD_MCU_FAILED" },
    { GF_ERROR_CAPTURE_IMAGE_FAILED, "GF_ERROR_CAPTURE_IMAGE_FAILED" },
    { GF_ERROR_NO_NEED_FORCE_STUDY, "GF_ERROR_NO_NEED_FORCE_STUDY" },
    { GF_ERROR_NOT_LIVE_FINGER, "GF_ERROR_NOT_LIVE_FINGER" },
    { GF_ERROR_RESIDUAL_FINGER, "GF_ERROR_RESIDUAL_FINGER" },
    { GF_ERROR_FACTORY_SCREEN_STRUCT_INVALID, "GF_ERROR_FACTORY_SCREEN_STRUCT_INVALID"},
    { GF_ERROR_ALGO_INIT_FAILED, "GF_ERROR_ALGO_INIT_FAILED"},
    { GF_ERROR_NOT_MATCH_NOT_LIVE_FINGER, "GF_ERROR_NOT_MATCH_NOT_LIVE_FINGER"},
    { GF_ERROR_ENROLL_AUTH_TOKEN_TIME_OUT, "GF_ERROR_ENROLL_AUTH_TOKEN_TIME_OUT"},
    { GF_ERROR_UI_READY_TIMEOUT, "GF_ERROR_UI_READY_TIMEOUT"},
    { GF_ERROR_FACTORY_TILT_LEVEL_INVALID, "GF_ERROR_FACTORY_TILT_LEVEL_INVALID"},
    { GF_ERROR_ALG_ANTIPEEPING_FINGER, "GF_ERROR_ALG_ANTIPEEPING_FINGER"},
    { GF_ERROR_ALG_SCREEN_STRUCT_IMG, "GF_ERROR_ALG_SCREEN_STRUCT_IMG"},
    { GF_ERROR_ACQUIRED_IMAGER_DRY, "GF_ERROR_ACQUIRED_IMAGER_DRY"},
    { GF_ERROR_ACQUIRED_IMAGER_WET, "GF_ERROR_ACQUIRED_IMAGER_WET"},
    { GF_ERROR_FACTORY_CAHRT_DIRECTION_INVALID, "GF_ERROR_FACTORY_CAHRT_DIRECTION_INVALID"},
    { GF_ERROR_GPIO_FAILED, "GF_ERROR_GPIO_FAILED"},
    { GF_ERROR_DSP_NOT_AVAILABLE, "GF_ERROR_DSP_NOT_AVAILABLE" },
    { GF_ERROR_DSP_WAIT_TIMEOUT, "GF_ERROR_DSP_WAIT_TIMEOUT" },
    { GF_ERROR_DSP_GET_FEATURE_FAIL, "GF_ERROR_DSP_GET_FEATURE_FAIL" },
    { GF_ERROR_UI_DISAPPEAR, "GF_ERROR_UI_DISAPPEAR" },
    { GF_ERROR_FARR_MOCK_DISABLE, "GF_ERROR_FARR_MOCK_DISABLE" },
    { GF_ERROR_ACQUIRED_NOT_LIVE_FINGER, "GF_ERROR_ACQUIRED_NOT_LIVE_FINGER" },
    { GF_ERROR_RPMB_GENERAL_ERROR, "GF_ERROR_RPMB_GENERAL_ERROR" },
    { GF_ERROR_RPMB_WRITE_ERROR, "GF_ERROR_RPMB_WRITE_ERROR" },
    { GF_ERROR_RPMB_READ_ERROR, "GF_ERROR_RPMB_READ_ERROR" },
    { GF_ERROR_CHECK_PERFORMANCE_TESTING_RESULT_NOT_PASS, "GF_ERROR_CHECK_PERFORMANCE_TESTING_RESULT_NOT_PASS"},
    { GF_ERROR_ALG_LOGO_DETECTION_FAILED, "GF_ERROR_ALG_LOGO_DETECTION_FAILED"},
    { GF_ERROR_BRIGHTNESS_CHANGE_FAIL, "GF_ERROR_BRIGHTNESS_CHANGE_FAIL"},
    { GF_ERROR_BRIGHTNESS_NOT_STABILITY, "GF_ERROR_BRIGHTNESS_NOT_STABILITY"},
    { GF_ERROR_CHART_DIRECTION_INCORRECT, "GF_ERROR_CHART_DIRECTION_INCORRECT"},
    { GF_ERROR_TEST_SMT, "GF_ERROR_TEST_SMT"},
    { GF_ERROR_ANOMALY_FINGER, "GF_ERROR_ANOMALY_FINGER"},
    { GF_ERROR_NEED_CANCLE_ENROLL, "GF_ERROR_NEED_CANCLE_ENROLL"},
    { GF_ERROR_TA_TRANSFER_SIZE, "GF_ERROR_TA_TRANSFER_SIZE"},
    { GF_ERROR_TEMPORARY_LOCKOUT, "GF_ERROR_TEMPORARY_LOCKOUT"},
    { GF_ERROR_PERMANENT_LOCKOUT, "GF_ERROR_PERMANENT_LOCKOUT"},

    { GF_ERROR_SPI_TEST, "GF_ERROR_SPI_TEST"},
    { GF_ERROR_RST_INT_TEST, "GF_ERROR_RST_INT_TEST"},
    { GF_ERROR_OTP_FLASH_TEST, "GF_ERROR_OTP_FLASH_TEST"},
    { GF_ERROR_GET_CALIBRATION, "GF_ERROR_GET_CALIBRATION"},
    { GF_ERROR_LOC_CIRCLE_TEST, "GF_ERROR_LOC_CIRCLE_TEST"},
    { GF_ERROR_BAD_POINT_CLUSTER, "GF_ERROR_BAD_POINT_CLUSTER"},
    { GF_ERROR_SNOISE, "GF_ERROR_SNOISE"},
    { GF_ERROR_TNOISE, "GF_ERROR_TNOISE"},
    { GF_ERROR_SIGNAL, "GF_ERROR_SIGNAL"},
    { GF_ERROR_FLATSNOISE, "GF_ERROR_FLATSNOISE"},
    { GF_ERROR_SSNR, "GF_ERROR_SSNR"},
    { GF_ERROR_TSNR, "GF_ERROR_TSNR"},
    { GF_ERROR_SHARPNESS, "GF_ERROR_SHARPNESS"},
    { GF_ERROR_HIGH_LIGHT, "GF_ERROR_HIGH_LIGHT"},
    { GF_ERROR_SWITCH_BRIGHTNESS, "GF_ERROR_SWITCH_BRIGHTNESS"},
    { GF_ERROR_BRIGHTNESS_INSTABILITY, "GF_ERROR_BRIGHTNESS_INSTABILITY"},
    { GF_ERROR_PRESS_INCOMPLETE, "GF_ERROR_PRESS_INCOMPLETE"},
    { GF_ERROR_CHART_DIRECTION, "GF_ERROR_CHART_DIRECTION"},
    { GF_ERROR_BLACK_RUBBER_LEAKAGE, "GF_ERROR_BLACK_RUBBER_LEAKAGE"},
    { GF_ERROR_CALI_TEST_STAGE, "GF_ERROR_CALI_TEST_STAGE"},
    { GF_ERROR_CALI_INFO_HEADER_CRC, "GF_ERROR_CALI_INFO_HEADER_CRC"},
    { GF_ERROR_CALI_INFO_CRC, "GF_ERROR_CALI_INFO_CRC"},
    { GF_ERROR_HAF_BAD_POINT_CLUSTER, "GF_ERROR_HAF_BAD_POINT_CLUSTER"},
    { GF_ERROR_DARK_PIXEL_PARAM, "GF_ERROR_DARK_PIXEL_PARAM"},
    { GF_ERROR_SCREEN_PARAM, "GF_ERROR_SCREEN_PARAM"},
    { GF_ERROR_CALCULATE_PGA_GAIN, "GF_ERROR_CALCULATE_PGA_GAIN"},
    { GF_ERROR_MORPHOTYPE_TEST, "GF_ERROR_MORPHOTYPE_TEST"},
    { GF_ERROR_PRODUCT_ALGO_INTERFACE, "GF_ERROR_PRODUCT_ALGO_INTERFACE"},
    { GF_ERROR_CHIP_TYPE_INCORRECT, "GF_ERROR_CHIP_TYPE_INCORRECT"},
    { GF_ERROR_TEMPERATURE_ADC_BASE, "GF_ERROR_TEMPERATURE_ADC_BASE"},
    { GF_ERROR_DIAMOND_K, "GF_ERROR_DIAMOND_K"},
    { GF_ERROR_POLAR_DEGREE, "GF_ERROR_POLAR_DEGREE"},
    { GF_ERROR_CHART_GHOST_SHADOW, "GF_ERROR_CHART_GHOST_SHADOW"},
    { GF_ERROR_CHART_DIRTY, "GF_ERROR_CHART_DIRTY"},
    { GF_ERROR_ANTIFAKE_OFFSET, "GF_ERROR_ANTIFAKE_OFFSET"},
    { GF_ERROR_SENSOR_ID_DISMATCH, "GF_ERROR_SENSOR_ID_DISMATCH"},
    { GF_ERROR_HRD_NOISE, "GF_ERROR_HRD_NOISE"},
    { GF_ERROR_FLESH_3D_EXCHANGE, "GF_ERROR_FLESH_3D_EXCHANGE"},
    { GF_ERROR_HBLACK_RANGE, "GF_ERROR_HBLACK_RANGE"},
    { GF_ERROR_TEST_HEAD_DEPTH, "GF_ERROR_TEST_HEAD_DEPTH"},

    { GF_SZ_FT_PASS, "GF_SZ_FT_PASS" },
    { GF_SZ_FT_ERROR_INIT_PARAM, "GF_SZ_FT_ERROR_INIT_PARAM" },
    { GF_SZ_FT_ERROR_BAD_PIXEL_OVERPROOF, "GF_SZ_FT_ERROR_BAD_PIXEL_OVERPROOF" },
    { GF_SZ_FT_ERROR_ANC_PREPROCESS, "GF_SZ_FT_ERROR_ANC_PREPROCESS" },
    { GF_SZ_FT_ERROR_RAWDATA_INVALID, "GF_SZ_FT_ERROR_RAWDATA_INVALID" },
    { GF_SZ_FT_ERROR_GET_IMAGE_MASK_FAIL, "GF_SZ_FT_ERROR_GET_IMAGE_MASK_FAIL" },
    { GF_SZ_FT_ERROR_COMM_FAIL, "GF_SZ_FT_ERROR_COMM_FAIL" },
    { GF_SZ_FT_ERROR_READ_RAWDATA_TIMEOUT, "GF_SZ_FT_ERROR_READ_RAWDATA_TIMEOUT" },
    { GF_SZ_FT_ERROR_NOISE_TEST_FAIL, "GF_SZ_FT_ERROR_NOISE_TEST_FAIL" },
    { GF_SZ_FT_ERROR_Q_VALUR_ABNORMAL, "GF_SZ_FT_ERROR_Q_VALUR_ABNORMAL" },
    { GF_SZ_FT_ERROR_CROP_PEREMETER_INVALID, "GF_SZ_FT_ERROR_CROP_PEREMETER_INVALID" },
    { GF_SZ_FT_ERROR_SCREEN_STRUCT_INVALID, "GF_SZ_FT_ERROR_SCREEN_STRUCT_INVALID" },
    { GF_SZ_FT_ERROR_CHART_DIRECTION_INVALID, "GF_SZ_FT_ERROR_CHART_DIRECTION_INVALID" },
    { GF_SZ_FT_ERROR_CALCULATE_KB_FAIL, "GF_SZ_FT_ERROR_CALCULATE_KB_FAIL" },
    { GF_SZ_FT_ERROR_GET_TNOISE_FAIL, "GF_SZ_FT_ERROR_GET_TNOISE_FAIL" },
    { GF_SZ_FT_ERROR_GET_SNOISE_FAIL, "GF_SZ_FT_ERROR_GET_SNOISE_FAIL" },
    { GF_SZ_FT_ERROR_GET_PREPRESS_PARAM_FAIL, "GF_SZ_FT_ERROR_GET_PREPRESS_PARAM_FAIL" },
    { GF_SZ_FT_ERROR_GET_RAWDATA_FAIL, "GF_SZ_FT_ERROR_GET_RAWDATA_FAIL" },
    { GF_SZ_FT_ERROR_SHARPNESS_ABNORMAL, "GF_SZ_FT_ERROR_SHARPNESS_ABNORMAL" },
    { GF_SZ_FT_ERROR_SINGNAL_TEST_FAIL, "GF_SZ_FT_ERROR_SINGNAL_TEST_FAIL" },
    { GF_SZ_FT_ERROR_SSNR_TEST_FAIL, "GF_SZ_FT_ERROR_SSNR_TEST_FAIL" },
    { GF_SZ_FT_ERROR_KB_CALIBRATION_FAIL, "GF_SZ_FT_ERROR_KB_CALIBRATION_FAIL" },
    { GF_SZ_FT_ERROR_READ_FLASH_FAIL, "GF_SZ_FT_ERROR_READ_FLASH_FAIL" },
    { GF_SZ_FT_ERROR_WRITE_FLASH_FAIL, "GF_SZ_FT_ERROR_WRITE_FLASH_FAIL" },
    { GF_SZ_FT_ERROR_CHECK_MT_FAIL, "GF_SZ_FT_ERROR_CHECK_MT_FAIL" },
    { GF_SZ_FT_ERROR_WRITE_RESUTL_TO_FLASH_FAIL, "GF_SZ_FT_ERROR_WRITE_RESUTL_TO_FLASH_FAIL" },
    { GF_SZ_FT_ERROR_CHIP_ID_CHECK_FAIL, "GF_SZ_FT_ERROR_CHIP_ID_CHECK_FAIL" },
    { GF_SZ_FT_ERROR_FOV_TEST_FAIL, "GF_SZ_FT_ERROR_FOV_TEST_FAIL" },
    { GF_SZ_FT_ERROR_SCALE_ABNORMAL, "GF_SZ_FT_ERROR_SCALE_ABNORMAL" },
    { GF_SZ_FT_ERROR_ILLUMINANCE_ABNORMAL, "GF_SZ_FT_ERROR_ILLUMINANCE_ABNORMAL" },
    { GF_SZ_FT_ERROR_TOUCH_DIFF_ABNORMAL, "GF_SZ_FT_ERROR_TOUCH_DIFF_ABNORMAL" },
    { GF_SZ_FT_ERROR_CONTRAST_ABNORMAL, "GF_SZ_FT_ERROR_CONTRAST_ABNORMAL" },
    { GF_SZ_FT_ERROR_LDC_TEST_ABNORMAL, "GF_SZ_FT_ERROR_LDC_TEST_ABNORMAL" },
    { GF_SZ_FT_ERROR_SELF_EXPOSURE_ABNORMAL, "GF_SZ_FT_ERROR_SELF_EXPOSURE_ABNORMAL" },
    { GF_SZ_FT_ERROR_VENDOR_ID_ERROR, "GF_SZ_FT_ERROR_VENDOR_ID_ERROR" },
    { GF_SZ_FT_ERROR_LEAK_LIGHT_ABNOEMAL, "GF_SZ_FT_ERROR_LEAK_LIGHT_ABNOEMAL" },
    { GF_SZ_FT_ERROR_LOG_IS_OPENED, "GF_SZ_FT_ERROR_LOG_IS_OPENED" },
    { GF_SZ_FT_ERROR_NOT_SUPPORT_TEST, "GF_SZ_FT_ERROR_NOT_SUPPORT_TEST" },
    { GF_SZ_FT_ERROR_BAD_PIXEL_PARAM_INIT_FAIL, "GF_SZ_FT_ERROR_BAD_PIXEL_PARAM_INIT_FAIL" },
    { GF_SZ_FT_ERROR_CHECK_BAD_PIXEL_FAIL, "GF_SZ_FT_ERROR_CHECK_BAD_PIXEL_FAIL" },
    { GF_SZ_FT_ERROR_ANC_PARAM_INIT_FAIL, "GF_SZ_FT_ERROR_ANC_PARAM_INIT_FAIL" },
    { GF_SZ_FT_ERROR_GET_FOV_FAIL, "GF_SZ_FT_ERROR_GET_FOV_FAIL" },
    { GF_SZ_FT_ERROR_SCREEN_STRUCT_PARAM_INIT_FAIL, "GF_SZ_FT_ERROR_SCREEN_STRUCT_PARAM_INIT_FAIL" },
    { GF_SZ_FT_ERROR_GET_SCREEN_STRUCT_RATIO_FAIL, "GF_SZ_FT_ERROR_GET_SCREEN_STRUCT_RATIO_FAIL" },
    { GF_SZ_FT_ERROR_CALCULATE_KB_PARAM_INIT_FAIL, "GF_SZ_FT_ERROR_CALCULATE_KB_PARAM_INIT_FAIL" },
    { GF_SZ_FT_ERROR_GET_SCALE_RATIO_FAIL, "GF_SZ_FT_ERROR_GET_SCALE_RATIO_FAIL" },
    { GF_SZ_FT_ERROR_QUALITY_CONTROL_PARAM_INIT_FAIL, "GF_SZ_FT_ERROR_QUALITY_CONTROL_PARAM_INIT_FAIL" },
    { GF_SZ_FT_ERROR_SCALE_RATIO_PARAM_INIT_FAIL, "GF_SZ_FT_ERROR_SCALE_RATIO_PARAM_INIT_FAIL" },
    { GF_SZ_FT_ERROR_TNOISE_PARAM_INIT_FAIL, "GF_SZ_FT_ERROR_TNOISE_PARAM_INIT_FAIL" },
    { GF_SZ_FT_ERROR_TNOISE_OVERPROOF, "GF_SZ_FT_ERROR_TNOISE_OVERPROOF" },
    { GF_SZ_FT_ERROR_SNOISE_PARAM_INIT_FAIL, "GF_SZ_FT_ERROR_SNOISE_PARAM_INIT_FAIL" },
    { GF_SZ_FT_ERROR_SNOISE_OVERPROOF, "GF_SZ_FT_ERROR_SNOISE_OVERPROOF" },
    { GF_SZ_FT_ERROR_TOUCH_DIFF_PARAM_INIT_FAIL, "GF_SZ_FT_ERROR_TOUCH_DIFF_PARAM_INIT_FAIL" },
    { GF_SZ_FT_ERROR_GET_TOUCH_DIFF_FAIL, "GF_SZ_FT_ERROR_GET_TOUCH_DIFF_FAIL" },
    { GF_SZ_FT_ERROR_LEAK_LIGHT_PARAM_INIT_FAIL, "GF_SZ_FT_ERROR_LEAK_LIGHT_PARAM_INIT_FAIL" },
    { GF_SZ_FT_ERROR_GET_LEAK_LIGHT_FAIL, "GF_SZ_FT_ERROR_GET_LEAK_LIGHT_FAIL" },
    { GF_SZ_FT_ERROR_ILLUMINANCE_PARAM_INIT_FAIL, "GF_SZ_FT_ERROR_ILLUMINANCE_PARAM_INIT_FAIL" },
    { GF_SZ_FT_ERROR_GET_ILLUMINANCE_FAIL, "GF_SZ_FT_ERROR_GET_ILLUMINANCE_FAIL" },
    { GF_SZ_FT_ERROR_SSNR_PARAM_INIT_FAIL, "GF_SZ_FT_ERROR_SSNR_PARAM_INIT_FAIL" },
    { GF_SZ_FT_ERROR_GET_SSNR_PTOP_FAIL, "GF_SZ_FT_ERROR_GET_SSNR_PTOP_FAIL" },
    { GF_SZ_FT_ERROR_CHART_DIRECTION_PARAM_INIT_FAIL, "GF_SZ_FT_ERROR_CHART_DIRECTION_PARAM_INIT_FAIL" },
    { GF_SZ_FT_ERROR_SHARPNESS_PARAM_INIT_FAIL, "GF_SZ_FT_ERROR_SHARPNESS_PARAM_INIT_FAIL" },
    { GF_SZ_FT_ERROR_GET_SHARPNESS_FAIL, "GF_SZ_FT_ERROR_GET_SHARPNESS_FAIL" },
    { GF_SZ_FT_ERROR_TC_PARAM_INIT_FAIL, "GF_SZ_FT_ERROR_TC_PARAM_INIT_FAIL" },
    { GF_SZ_FT_ERROR_GET_TC_FAIL, "GF_SZ_FT_ERROR_GET_TC_FAIL" },
    { GF_SZ_FT_ERROR_SET_HBM_MODE_FAIL, "GF_SZ_FT_ERROR_SET_HBM_MODE_FAIL" },
    { GF_SZ_FT_ERROR_CLOSE_HBM_MODE_FAIL, "GF_SZ_FT_ERROR_CLOSE_HBM_MODE_FAIL" },
    { GF_SZ_FT_ERROR_SET_HIGH_BRIGHTNESS_FAIL, "GF_SZ_FT_ERROR_SET_HIGH_BRIGHTNESS_FAIL" },
    { GF_SZ_FT_ERROR_SET_LOW_BRIGHTNESS_FAIL, "GF_SZ_FT_ERROR_SET_LOW_BRIGHTNESS_FAIL" },
    { GF_SZ_FT_ERROR_LOCAL_AREA_SAMPLE_FAIL, "GF_SZ_FT_ERROR_LOCAL_AREA_SAMPLE_FAIL"},
    { GF_SZ_FT_ERROR_CENTER_OFFSET_INIT_FAIL, "GF_SZ_FT_ERROR_CENTER_OFFSET_INIT_FAIL" },
    { GF_SZ_FT_ERROR_CHECK_CENTER_OFFSET_FAIL, "GF_SZ_FT_ERROR_CHECK_CENTER_OFFSET_FAIL" },
    { GF_SZ_FT_ERROR_CHECK_LENS_MODULE_TILT, "GF_SZ_FT_ERROR_CHECK_LENS_MODULE_TILT" },
    { GF_SZ_FT_ERROR_LENS_MODULE_TILT_OVERPROOF, "GF_SZ_FT_ERROR_LENS_MODULE_TILT_OVERPROOF" },
    { GF_SZ_FT_ERROR_CF_MASK_CHECK_FAIL, "GF_SZ_FT_ERROR_CF_MASK_CHECK_FAIL"},
    { GF_SZ_FT_ERROR_RAW_DATA, "GF_SZ_FT_ERROR_RAW_DATA" },
    { GF_SZ_FT_ERROR_APPLICATION_EXCEPTION, "GF_SZ_FT_ERROR_APPLICATION_EXCEPTION" },
    { GF_SZ_FT_ERROR_MOIRE_PARAM_INIT_FAIL, "GF_SZ_FT_ERROR_MOIRE_PARAM_INIT_FAIL" },
    { GF_SZ_FT_ERROR_CHECK_MOIRE_FAIL, "GF_SZ_FT_ERROR_CHECK_MOIRE_FAIL" },
    { GF_SZ_FT_ERROR_AUTO_EXPOSURE, "GF_SZ_FT_ERROR_AUTO_EXPOSURE" },
    { GF_SZ_FT_ERROR_CHECK_FLESH_INIT_FAIL, "GF_SZ_FT_ERROR_CHECK_FLESH_INIT_FAIL" },
    { GF_SZ_FT_ERROR_CHECK_FLESH_CHECK_FAIL, "GF_SZ_FT_ERROR_CHECK_FLESH_CHECK_FAIL" },
    { GF_SZ_FT_ERROR_CHECK_FLESH_FAIL, "GF_SZ_FT_ERROR_CHECK_FLESH_FAIL" },
    { GF_SZ_FT_ERROR_GET_PATTERN_INIT_FAIL, "GF_SZ_FT_ERROR_GET_PATTERN_INIT_FAIL" },
    { GF_SZ_FT_ERROR_GET_PATTERN_CHECK_FAIL, "GF_SZ_FT_ERROR_GET_PATTERN_CHECK_FAIL" },
    { GF_SZ_FT_ERROR_IRREGULAR_SPOT_INIT_FAIL, "GF_SZ_FT_ERROR_IRREGULAR_SPOT_INIT_FAIL" },
    { GF_SZ_FT_ERROR_IRREGULAR_SPOT_CHECK_FAIL, "GF_SZ_FT_ERROR_IRREGULAR_SPOT_CHECK_FAIL" },
    { GF_SZ_FT_ERROR_CALC_SHELTER_FAIL, "GF_SZ_FT_ERROR_CALC_SHELTER_FAIL" },
    { GF_SZ_FT_ERROR_CHECK_SHELTER_FAIL, "GF_SZ_FT_ERROR_CHECK_SHELTER_FAIL" },
    { GF_SZ_FT_ERROR_SCALE_RATIO_DIVIDE_BY_0, "GF_SZ_FT_ERROR_SCALE_RATIO_DIVIDE_BY_0" },
    { GF_SZ_FT_ERROR_SCALE_RATIO_ERR_LINE_NUM, "GF_SZ_FT_ERROR_SCALE_RATIO_ERR_LINE_NUM" },
    { GF_SZ_FT_ERROR_SCALE_RATIO_ERR_PARALLEL_LINE, "GF_SZ_FT_ERROR_SCALE_RATIO_ERR_PARALLEL_LINE" },
    { GF_SZ_FT_ERROR_SCALE_RATIO_ERR_CROSS_LINE, "GF_SZ_FT_ERROR_SCALE_RATIO_ERR_CROSS_LINE" },
    { GF_SZ_FT_ERROR_LB_BASE_INIT_FAIL, "GF_SZ_FT_ERROR_LB_BASE_INIT_FAIL" },
    { GF_SZ_FT_ERROR_LB_BASE, "GF_SZ_FT_ERROR_LB_BASE" },
    { GF_SZ_FT_ERROR_LB_BASE_CHECK_FAILED, "GF_SZ_FT_ERROR_LB_BASE_CHECK_FAILED" },
    { GF_ERROR_MAX, "INVALID_ERROR" }
};

/**
 * Function: gf_strerror
 * Description: get error string
 * Input: error code
 * Output: none
 * Return: error string
 */
const char *gf_strerror(const gf_error_t err) {
    // need error is consequent 0 , 1000, 1001, 1002, ..., max
    uint32_t idx = 0;
    uint32_t len = sizeof(err_table) / sizeof(gf_strerror_t);

    do {
        if (GF_SUCCESS == err) {
            break;
        }

        if ((err < GF_ERROR_BASE) || (err > GF_ERROR_MAX)) {
            idx = len - 1;
            break;
        }

        while (idx < len) {
            if (err == err_table[idx].err) {
                break;
            }

            idx++;
        }

        if (idx == len) {
            idx = len - 1;
        }
    }  // do...

    while (0);

    return err_table[idx].strerror;
}

/**
 * Function: gf_get_err_table_len
 * Description: get error table length
 * Input: none
 * Output: none
 * Return: error table length
 */
uint32_t gf_get_err_table_len(void) {
    uint32_t len = sizeof(err_table) / sizeof(gf_strerror_t);
    return len;
}
