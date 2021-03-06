/*
 * Copyright (C) 2013-2017, Shenzhen Huiding Technology Co., Ltd.
 * All Rights Reserved.
 * Version: V1.0
 * Description:
 * History:
 */

#ifndef _SZPRODUCTTESTDEFINE_H_
#define _SZPRODUCTTESTDEFINE_H_

#include "ProductTestDefine.h"

#define SZ_UNTRUST_ENROLL_TEST_GID 0xFFFFFFFF
#define CMD_TEST_SZ_TEST_BASE   0X600

typedef enum {
    CMD_TEST_SZ_FINGER_DOWN = CMD_TEST_SZ_TEST_BASE,
    CMD_TEST_SZ_FINGER_UP,
    CMD_TEST_SZ_ENROLL,
    CMD_TEST_SZ_FIND_SENSOR,
    CMD_TEST_SZ_FUSION_PREVIEW,
    CMD_TEST_SZ_UNTRUSTED_ENROLL,
    CMD_TEST_SZ_UNTRUSTED_AUTHENTICATE,
    CMD_TEST_SZ_DELETE_UNTRUSTED_ENROLLED_FINGER,
    CMD_TEST_SZ_RAWDATA_PREVIEW,
    CMD_TEST_SZ_LDC_CALIBRATE,
    CMD_TEST_SZ_ENROLL_TEMPLATE_COUNT,
    CMD_TEST_SZ_UPDATE_CAPTURE_PARM,
    CMD_TEST_SZ_CANCEL,
    CMD_TEST_SZ_GET_CONFIG,
    CMD_TEST_SZ_GET_VERSION,
    CMD_TEST_SZ_K_B_CALIBRATION,
    CMD_TEST_SZ_SET_GROUP_ID,
    CMD_TEST_SZ_UPDATE_CFG,
    CMD_TEST_SZ_UPDATE_FW,
    CMD_TEST_SZ_UNTRUSTED_ENUMERATE,
    CMD_TEST_SZ_FT_CAPTURE_DARK_BASE = CMD_TEST_SZ_TEST_BASE + 20,
    CMD_TEST_SZ_FT_CAPTURE_H_DARK,
    CMD_TEST_SZ_FT_CAPTURE_L_DARK,
    CMD_TEST_SZ_FT_CAPTURE_H_FLESH,
    CMD_TEST_SZ_FT_CAPTURE_L_FLESH,
    CMD_TEST_SZ_FT_CAPTURE_CHART,
    CMD_TEST_SZ_FT_CAPTURE_CHECKBOX,
    CMD_TEST_SZ_FT_CAPTURE_LOCATION_IMAGE,
    CMD_TEST_SZ_FT_FACTORY_PERFORMANCE,
    CMD_TEST_SZ_FT_EXPO_AUTO_CALIBRATION,
    CMD_TEST_SZ_FT_STOP_EXPO_AUTO_CALIBRATION,
    CMD_TEST_SZ_FT_RESET,
    CMD_TEST_SZ_FT_SPI_RST_INT,
    CMD_TEST_SZ_FT_SPI,
    CMD_TEST_SZ_FT_INIT,
    CMD_TEST_SZ_FT_EXIT,
    CMD_TEST_SZ_FT_CALIBRATE,
    CMD_TEST_SZ_FT_MT_CHECK,
    CMD_TEST_SZ_FT_KPI,
    CMD_TEST_SZ_FT_FACTORY_CAPTURE_IMAGE_MANUAL,
    CMD_TEST_SZ_DUMP_TEMPLATE = CMD_TEST_SZ_TEST_BASE + 60,
    CMD_TEST_SZ_SET_HBM_MODE,
    CMD_TEST_SZ_CLOSE_HBM_MODE,
    CMD_TEST_SZ_SET_HIGH_BRIGHTNESS,
    CMD_TEST_SZ_SET_LOW_BRIGHTNESS,
    CMD_TEST_SZ_SET_DUMP_ENABLE_FLAG,
    CMD_TEST_SZ_FACTORY_TEST_GET_MT_INFO,
    CMD_TEST_SZ_SET_MAX_BRIGHTNESS,
    CMD_TEST_SZ_LOCAL_AREA_SAMPLE,
    CMD_TEST_SZ_ENABLE_POWER,
    CMD_TEST_SZ_DISABLE_POWER,
    CMD_TEST_SZ_UI_READY,
    CMD_TEST_SZ_UI_DISAPPER,
    CMD_TEST_SZ_ENABLE_PAY_ENVIRONMENT_LEVEL,
    CMD_TEST_SZ_DISABLE_PAY_ENVIRONMENT_LEVEL,
    CMD_TEST_SZ_FT_CAPTURE_CHECKBOX_CAPTURE = CMD_TEST_SZ_TEST_BASE + 100,
    CMD_TEST_SZ_FT_CAPTURE_CHART_CAPTURE,
    CMD_TEST_SZ_FT_SAMPLE_CALIBRATE_CHART = CMD_TEST_SZ_TEST_BASE + 150,
    CMD_TEST_SZ_FT_SAMPLE_CALIBRATE,
    CMD_TEST_SZ_FT_SIMPLE_CALI_INIT,  // simple cali no test
    CMD_TEST_SZ_FT_SIMPLE_CALI_EXIT,
    CMD_TEST_SZ_FT_SIMPLE_CALI_BASE,
    CMD_TEST_SZ_FT_SIMPLE_CALI_AUTO_CALIBRATION,
    CMD_TEST_SZ_FT_SIMPLE_STOP_CALI_AUTO_CALIBRATION,
    CMD_TEST_SZ_FT_SIMPLE_CALI_PERFORMANCE,
    CMD_TEST_SZ_FT_SIMPLE_CALI_SCREEN_CHART,
    CMD_TEST_SZ_FT_SIMPLE_CANCLE,
    CMD_TEST_OPLUS_GET_IMAGE_QUALITY = CMD_TEST_SZ_TEST_BASE + 1000,
    CMD_TEST_PRODUCT_CMD_MAX,  // note: match with gf_manager_lib contants
} SZ_PRODUCT_TEST_CMD;

typedef enum {
    TEST_TOKEN_AD_VERSION = 215,
    TEST_TOKEN_LENS_TYPE,
    TEST_TOKEN_FAKE_VERSION,
    TEST_TOKEN_AVG_DIFF_VAL = 300,
    TEST_TOKEN_NOISE,
    TEST_TOKEN_BAD_PIXEL_NUM,
    TEST_TOKEN_FDT_BAD_AREA_NUM,
    TEST_TOKEN_LOCAL_BAD_PIXEL_NUM,
    TEST_TOKEN_FRAME_NUM,
    TEST_TOKEN_MAX_FRAME_NUM,
    TEST_TOKEN_DATA_DEVIATION_DIFF,
    TEST_TOKEN_ALL_TILT_ANGLE,
    TEST_TOKEN_BLOCK_TILT_ANGLE_MAX,
    TEST_TOKEN_LOCAL_WORST,
    TEST_TOKEN_SINGULAR,
    TEST_TOKEN_IN_CIRCLE,
    TEST_TOKEN_BIG_BUBBLE,
    TEST_TOKEN_LINE,
    TEST_TOKEN_LOCAL_SMALL_BAD_PIXEL_NUM,
    TEST_TOKEN_LOCAL_BIG_BAD_PIXEL_NUM,
    TEST_TOKEN_FLATNESS_BAD_PIXEL_NUM,
    TEST_TOKEN_IS_BAD_LINE,
    TEST_TOKEN_GET_DR_TIMESTAMP_TIME = 400,
    TEST_TOKEN_GET_MODE_TIME,
    TEST_TOKEN_GET_CHIP_ID_TIME,
    TEST_TOKEN_GET_VENDOR_ID_TIME,
    TEST_TOKEN_GET_SENSOR_ID_TIME,
    TEST_TOKEN_GET_FW_VERSION_TIME,
    TEST_TOKEN_GET_IMAGE_TIME,
    TEST_TOKEN_RAW_DATA_LEN,
    TEST_TOKEN_CFG_DATA,
    TEST_TOKEN_CFG_DATA_LEN,
    TEST_TOKEN_FW_DATA,
    TEST_TOKEN_FW_DATA_LEN,
    TEST_TOKEN_IMAGE_QUALITY = 500,
    TEST_TOKEN_VALID_AREA,
    TEST_TOKEN_KEY_POINT_NUM,
    TEST_TOKEN_INCREATE_RATE,
    TEST_TOKEN_OVERLAY,
    TEST_TOKEN_GET_RAW_DATA_TIME,
    TEST_TOKEN_PREPROCESS_TIME,
    TEST_TOKEN_ALGO_START_TIME,
    TEST_TOKEN_GET_FEATURE_TIME,
    TEST_TOKEN_ENROLL_TIME,
    TEST_TOKEN_AUTHENTICATE_TIME,
    TEST_TOKEN_AUTHENTICATE_ID,
    TEST_TOKEN_AUTHENTICATE_UPDATE_FLAG,
    TEST_TOKEN_AUTHENTICATE_FINGER_COUNT,
    TEST_TOKEN_AUTHENTICATE_FINGER_ITME,
    TEST_TOKEN_TOTAL_TIME,
    TEST_TOKEN_GET_GSC_DATA_TIME,
    TEST_TOKEN_BIO_ASSAY_TIME,
    TEST_TOKEN_RESET_FLAG = 600,
    TEST_TOKEN_BMP_DATA_WIDTH = 690,
    TEST_TOKEN_BMP_DATA_HEIGHT,
    TEST_TOKEN_RAW_DATA = 700,
    TEST_TOKEN_BMP_DATA = 701,
    TEST_TOKEN_ALGO_INDEX = 702,
    TEST_TOKEN_SAFE_CLASS = 703,
    TEST_TOKEN_TEMPLATE_COUNT = 704,
    TEST_TOKEN_GSC_DATA = 705,
    TEST_TOKEN_HBD_BASE = 706,
    TEST_TOKEN_HBD_AVG = 707,
    TEST_TOKEN_HBD_RAW_DATA = 708,
    TEST_TOKEN_ELECTRICITY_VALUE = 709,
    TEST_TOKEN_FINGER_EVENT = 710,
    TEST_TOKEN_GSC_FLAG = 711,
    TEST_TOKEN_BASE_DATA = 712,
    TEST_TOKEN_KR_DATA = 713,
    TEST_TOKEN_B_DATA = 714,
    TEST_TOKEN_FPC_KEY_DATA = 715,
    TEST_TOKEN_FPC_KEY_EVENT,
    TEST_TOKEN_FPC_KEY_STATUS,
    TEST_TOKEN_FPC_KEY_EN_FLAG,
    TEST_TOKEN_FPC_KEY_FAIL_STATUS,
    TEST_TOKEN_FPC_KEY_CAN_TEST,
    TEST_TOKEN_FPC_KEY_RAWDATA,
    TEST_TOKEN_FPC_KEY_CANCELDATA,
    TEST_TOKEN_FPC_DOWNLOAD_CFG,
    TEST_TOKEN_FW_EXPOSE_TIME = 736,
    TEST_TOKEN_MAX_FINGERS = 800,
    TEST_TOKEN_MAX_FINGERS_PER_USER,
    TEST_TOKEN_SUPPORT_KEY_MODE,
    TEST_TOKEN_SUPPORT_FF_MODE,
    TEST_TOKEN_SUPPORT_POWER_KEY_FEATURE,
    TEST_TOKEN_FORBIDDEN_UNTRUSTED_ENROLL,
    TEST_TOKEN_FORBIDDEN_ENROLL_DUPLICATE_FINGERS,
    TEST_TOKEN_SUPPORT_BIO_ASSAY,
    TEST_TOKEN_SUPPORT_PERFORMANCE_DUMP,
    TEST_TOKEN_SUPPORT_NAV_MODE,
    TEST_TOKEN_NAV_DOUBLE_CLICK_TIME,
    TEST_TOKEN_NAV_LONG_PRESS_TIME,
    TEST_TOKEN_ENROLLING_MIN_TEMPLATES,
    TEST_TOKEN_VALID_IMAGE_QUALITY_THRESHOLD,
    TEST_TOKEN_VALID_IMAGE_AREA_THRESHOLD,
    TEST_TOKEN_DUPLICATE_FINGER_OVERLAY_SCORE,
    TEST_TOKEN_INCREASE_RATE_BETWEEN_STITCH_INFO,
    TEST_TOKEN_SCREEN_ON_AUTHENTICATE_FAIL_RETRY_COUNT,
    TEST_TOKEN_SCREEN_OFF_AUTHENTICATE_FAIL_RETRY_COUNT,
    TEST_TOKEN_SCREEN_ON_VALID_TOUCH_FRAME_THRESHOLD,
    TEST_TOKEN_SCREEN_OFF_VALID_TOUCH_FRAME_THRESHOLD,
    TEST_TOKEN_IMAGE_QUALITY_THRESHOLD_FOR_MISTAKE_TOUCH,
    TEST_TOKEN_AUTHENTICATE_ORDER,
    TEST_TOKEN_REISSUE_KEY_DOWN_WHEN_ENTRY_FF_MODE,
    TEST_TOKEN_REISSUE_KEY_DOWN_WHEN_ENTRY_IMAGE_MODE,
    TEST_TOKEN_SUPPORT_SENSOR_BROKEN_CHECK,
    TEST_TOKEN_BROKEN_PIXEL_THRESHOLD_FOR_DISABLE_SENSOR,
    TEST_TOKEN_BROKEN_PIXEL_THRESHOLD_FOR_DISABLE_STUDY,
    TEST_TOKEN_BAD_POINT_TEST_MAX_FRAME_NUMBER,
    TEST_TOKEN_REPORT_KEY_EVENT_ONLY_ENROLL_AUTHENTICATE,
    TEST_TOKEN_REQUIRE_DOWN_AND_UP_IN_PAIRS_FOR_IMAGE_MODE,
    TEST_TOKEN_REQUIRE_DOWN_AND_UP_IN_PAIRS_FOR_FF_MODE,
    TEST_TOKEN_REQUIRE_DOWN_AND_UP_IN_PAIRS_FOR_KEY_MODE,
    TEST_TOKEN_REQUIRE_DOWN_AND_UP_IN_PAIRS_FOR_NAV_MODE,
    TEST_TOKEN_SUPPORT_SET_SPI_SPEED_IN_TEE,
    TEST_TOKEN_SUPPORT_FRR_ANALYSIS,
    TEST_TOKEN_SENSOR_VALIDITY = 900,
    TEST_TOKEN_SPI_TRANSFER_RESULT,
    TEST_TOKEN_SPI_TRANSFER_REMAININGS,
    TEST_TOKEN_AVERAGE_PIXEL_DIFF,
    TEST_TOKEN_SPI_RW_CMD = 1100,
    TEST_TOKEN_SPI_RW_START_ADDR,
    TEST_TOKEN_SPI_RW_LENGTH,
    TEST_TOKEN_SPI_RW_CONTENT,
    TEST_TOKEN_PACKAGE_VERSION = 1200,
    TEST_TOKEN_PROTOCOL_VERSION,
    TEST_TOKEN_CHIP_SUPPORT_BIO,
    TEST_TOKEN_IS_BIO_ENABLE,
    TEST_TOKEN_AUTHENTICATED_WITH_BIO_SUCCESS_COUNT,
    TEST_TOKEN_AUTHENTICATED_WITH_BIO_FAILED_COUNT,
    TEST_TOKEN_AUTHENTICATED_SUCCESS_COUNT,
    TEST_TOKEN_AUTHENTICATED_FAILED_COUNT,
    TEST_TOKEN_BUF_FULL,
    TEST_TOKEN_UPDATE_POS,
    TEST_TOKEN_METADATA,
    TEST_TOKEN_UNDER_SATURATED_PIXEL_COUNT = 1300,
    TEST_TOKEN_OVER_SATURATED_PIXEL_COUNT,
    TEST_TOKEN_SATURATED_PIXEL_THRESHOLD,
    TEST_TOKEN_REMAIN_TEMPLATEGS = 1350,
    TEST_TOKEN_MAX_BAD_POINT_NUM = 1400,
    TEST_TOKEN_MAX_CLUSTER_NUM,
    TEST_TOKEN_MAX_PIXEL_OF_LARGEST_BAD_CLUSTER,
    TEST_TOKEN_MAX_LIGHT_NOISET,
    TEST_TOKEN_MAX_LIGHT_NOISES,
    TEST_TOKEN_MIN_FLESH_TOUCH_DIFF,
    TEST_TOKEN_MIN_FOV_AREA,
    TEST_TOKEN_MAX_LIGHT_LEAK_RATIO,
    TEST_TOKEN_MIN_RELATIVE_ILLUMINANCE,
    TEST_TOKEN_MAX_SCALE_RATIO,
    TEST_TOKEN_MIN_SCALE_RATIO,
    TEST_TOKEN_MIN_MASK_CROP_AREA,
    TEST_TOKEN_MIN_SSNR,
    TEST_TOKEN_MIN_SHAPENESS,
    TEST_TOKEN_MIN_P2P,
    TEST_TOKEN_MIN_CHART_CONSTRAST,
    TEST_TOKEN_EFF_REG_RAD,
    TEST_TOKEN_EFF_REG_RAD2,
    TEST_TOKEN_SPMT_BAD_PIX_THD,
    TEST_TOKEN_SPMT_BAD_PIX_THD2,
    TEST_TOKEN_SATURAT_PIX_HIGH_THD,
    TEST_TOKEN_CHART_DIRECTION_THD,
    TEST_TOKEN_CHART_DIRECTION_TARGET,
    TEST_TOKEN_MAX_SCREEN_STRUCT_RATIO,
    TEST_TOKEN_MAX_EXPO_TIME,
    TEST_TOKEN_MIN_EXPO_TIME,
    TEST_TOKEN_MODULE_VENDOR,
    TEST_TOKEN_LENS_VENSOR,
    TEST_TOKEN_SERIAL_NUM,
    TEST_TOKEN_MAX_CENTER_OFFSET,
    TEST_TOKEN_MAX_DARK_SNOISE,
    TEST_TOKEN_MAX_DARK_TNOISE,
    TEST_TOKEN_MAX_LENS_TILT_LEVEL,
    TEST_TOKEN_MAX_LENS_TILT_ANGLE,
    TEST_TOKEN_MAX_PIXEL_OF_ORIENT_LARGEST_BAD_CLUSTER,

    TEST_PARAM_TOKEN_FW_DATA = 5000,
    TEST_PARAM_TOKEN_CFG_DATA,
    TEST_PARAM_TOKEN_DUMP_PATH = 5100,
    TEST_TOKEN_TEMPLATE_UPDATE_SAVE_THRESHOLD = 5200,
    // add for shenzhen
    TEST_TOKEN_CALIBRATION_BRIGHT_LEVEL = 5300,
    TEST_TOKEN_CALIBRATION_NUM_PER_LEVEL,
    TEST_TOKEN_CALIBRATION_CUR_SAMPLE_COUNT,
    TEST_TOKEN_CALIBRATION_ALGO_FINISHED_FLAG,
    TEST_TOKEN_CALIBRATION_AUTO_FLAG,
    TEST_TOKEN_CALIBRATION_AUTO_SEND_DOWN_UP,
    TEST_TOKEN_CALIBRATION_AUTO_TEST_TYPE,
    TEST_TOKEN_CALIBRATION_STEP,
    TEST_TOKEN_EXPO_AUTO_CALIBRATION_FLAG,
    TEST_TOKEN_MCU_ID,
    TEST_TOKEN_FLASH_ID,
    TEST_TOKEN_PMIC_ID,
    TEST_TOKEN_PERFORMANCE_P2P,
    TEST_TOKEN_PERFORMANCE_NOISE,
    TEST_TOKEN_PERFORMANCE_SSNR,
    TEST_TOKEN_PERFORMANCE_MEAN_RIDGE,
    TEST_TOKEN_PERFORMANCE_MEAN_VALLEY,
    TEST_TOKEN_PERFORMANCE_SHARPNESS,
    TEST_TOKEN_PERFORMANCE_SHARPNESS_ALL,
    TEST_TOKEN_PERFORMANCE_CHART_TOUCH_DIFF,
    TEST_TOKEN_PERFORMANCE_CHART_CONTRAST,
    TEST_TOKEN_FACTORY_SNOISE,
    TEST_TOKEN_FACTORY_TNOISE,
    TEST_TOKEN_FACTORY_FLESH_TOUCH_DIFF,
    TEST_TOKEN_FACTORY_LIGHT_LEAK_RATIO,
    TEST_TOKEN_FACTORY_FOV_LEFT,
    TEST_TOKEN_FACTORY_FOV_RIGHT,
    TEST_TOKEN_FACTORY_FOV_UP,
    TEST_TOKEN_FACTORY_FOV_DOWN,
    TEST_TOKEN_FACTORY_RELATIVE_ILLUMINANCE,
    TEST_TOKEN_FACTORY_ILLUM_MAX_X,
    TEST_TOKEN_FACTORY_ILLUM_MAX_Y,
    TEST_TOKEN_FACTORY_SCALE,
    TEST_TOKEN_FACTORY_RMS,
    TEST_TOKEN_FACTORY_CROP_WIDTH,
    TEST_TOKEN_FACTORY_CROP_HEIGHT,
    TEST_TOKEN_FACTORY_BAD_POINT_NUM,
    TEST_TOKEN_FACTORY_CLUSTER_NUM,
    TEST_TOKEN_FACTORY_PIXEL_OF_LARGEST_BAD_CLUSTER,
    TEST_TOKEN_FACTROY_SCREEN_STRUCT_RATIO,
    TEST_TOKEN_FACTROY_CENTER_OFFSET,
    TEST_TOKEN_FACTROY_IMG_QUALITY,
    TEST_TOKEN_FACTROY_IMG_VALID_AREA,
    TEST_TOKEN_FACTORY_PIXEL_OF_ORIENT_LARGEST_BAD_CLUSTER,

    TEST_TOKEN_GREAT_CIRCLE_X = 5400,
    TEST_TOKEN_GREAT_CIRCLE_Y,
    TEST_TOKEN_CENTRAL_CIRCLE_X,
    TEST_TOKEN_CENTRAL_CIRCLE_Y,
    TEST_TOKEN_SMALL_CIRCLE_X,
    TEST_TOKEN_SMALL_CIRCLE_Y,
    TEST_TOKEN_CENTER_POINT_X,
    TEST_TOKEN_CENTER_POINT_Y,
    TEST_TOKEN_CIRCLE_ANGLE,
    TEST_TOKEN_CIRCLE_IMAGE_TIME_STAMP,

    TEST_TOKEN_BASE_BAD_POINT_NUM,
    TEST_TOKEN_BASE_DARK_NOISE_T,
    TEST_TOKEN_BASE_LIGHT_NOISE_T,
    TEST_TOKEN_BASE_DARK_NOISE_S,
    TEST_TOKEN_BASE_LIGHT_NOISE_S,
    TEST_TOKEN_BASE_SSNR,
    TEST_TOKEN_BASE_P2P,
    TEST_TOKEN_BASE_SHARPNESS,

    TEST_TOKEN_POSITION_OFFSET_ANGLE = 5500,
    TEST_TOKEN_POSITION_OFFSET_X,
    TEST_TOKEN_POSITION_OFFSET_Y,
    TEST_TOKEN_BAD_POINT_NUM,
    TEST_TOKEN_DARK_NOISE_T,
    TEST_TOKEN_LIGHT_NOISE_T,
    TEST_TOKEN_DARK_NOISE_S,
    TEST_TOKEN_LIGHT_NOISE_S,
    TEST_TOKEN_SSNR,
    TEST_TOKEN_P2P,
    TEST_TOKEN_SHARPNESS,

    TEST_PARAM_TOKEN_AUTO_FIND_SENSOR_STEP = 5600,
    TEST_TOKEN_AUTO_FIND_SENSOR_SENSOR_X,
    TEST_TOKEN_AUTO_FIND_SENSOR_SENSOR_Y,
    TEST_TOKEN_AUTO_FIND_SENSOR_LEFT_TOP_X,
    TEST_TOKEN_AUTO_FIND_SENSOR_LEFT_TOP_Y,
    TEST_TOKEN_AUTO_FIND_SENSOR_SENSOR_IMAGE_WIDTH,
    TEST_TOKEN_AUTO_FIND_SENSOR_SENSOR_IMAGE_HEIGHT,
    TEST_TOKEN_AUTO_FIND_SENSOR_RECT_SCREEN_WIDTH,
    TEST_TOKEN_AUTO_FIND_SENSOR_SENSOR_SCREEN_WIDTH,
    TEST_TOKEN_AUTO_FIND_SENSOR_SENSOR_SCREEN_HEIGHT,
    TEST_TOKEN_AUTO_FIND_SENSOR_ROTATE_RANDIAN,
    TEST_PARAM_TOKEN_AUTO_FIND_SENSOR_SCREEN_WIDTH,
    TEST_PARAM_TOKEN_AUTO_FIND_SENSOR_SCREEN_HEIGHT,
    TEST_TOKEN_AUTO_FIND_SENSOR_SENSOR_GUIDE_LTX,
    TEST_TOKEN_AUTO_FIND_SENSOR_SENSOR_GUIDE_LTY,

    TEST_TOKEN_PRESSURE_THRESHOLD = 5700,

    TEST_TOKEN_SUPPORT_IMAGE_SEGMENT = 5800,

    TEST_TOKEN_SCALE_RATIO_VALUE = 6000,
    TEST_TOKEN_LONG_FRAME_AVG_NUM,
    TEST_TOKEN_LONG_PAG_GAIN,
    TEST_TOKEN_SHORT_EXPOSURE_TIME,
    TEST_TOKEN_SHORT_FRAME_AVG_NUM,
    TEST_TOKEN_SHORT_PAG_GAIN,

    TEST_TOKEN_UNLOWERTHRESH,
    TEST_TOKEN_UNHIGHTHRESH,

    TEST_TOKEN_FUSION_RATIO,

    TEST_TOKEN_PREPROCESS,

    TEST_TOKEN_RECT_X,
    TEST_TOKEN_RECT_Y,
    TEST_TOKEN_RECT_WIDTH,
    TEST_TOKEN_RECT_HEIGHT,

    TEST_TOKEN_BASE_CALIBRATE_SWITCH,
    TEST_TOKEN_LDC_SWITCH,

    TEST_TOKEN_TNR_RESET_THRESH,  // 6016
    TEST_TOKEN_TNR_RESET_FLAG,  // 6017
    TEST_TOKEN_LPF_SWITCH,  // 6018
    TEST_TOKEN_LSC_SWITCH,  // 6019
    TEST_TOKEN_ENHANCE_LEVEL,  // 6020

    TEST_TOKEN_LONG_EXPOSURE_TIME_DISTANCE,  // 6021
    TEST_TOKEN_RECT_BMP_COL,  // 6022
    TEST_TOKEN_RECT_BMP_ROW,  // 6023
    TEST_TOKEN_ENROLL_TEMPLATE_COUNT,  // 6024
    TEST_TOKEN_AUTHENTICATE_RETRYCOUNT,  // 6025
    TEST_TOKEN_SENSOR_PREVIEW_ENHANCED,  // 6026
    TEST_TOKEN_SENSOR_COL,  // 6027
    TEST_TOKEN_SENSOR_ROW,  // 6028

    TEST_TOKEN_FINGER_ID = 7000,
    TEST_TOKEN_SET_GROUP_ID = 7100,

    // for capture parm
    TEST_TOKEN_LONG_EXPOSURE_DATA = 8000,
    TEST_TOKEN_LONG_EXPOSURE_WIDTH = 8001,
    TEST_TOKEN_LONG_EXPOSURE_HEIGHT = 8002,

    TEST_TOKEN_SHORT_EXPOSURE_DATA = 8003,
    TEST_TOKEN_SHORT_EXPOSURE_WIDTH = 8004,
    TEST_TOKEN_SHORT_EXPOSURE_HEIGHT = 8005,

    TEST_TOKEN_FUSION_DATA = 8006,
    TEST_TOKEN_FUSION_WIDTH = 8007,
    TEST_TOKEN_FUSION_HEIGHT = 8008,

    TEST_TOKEN_WEAK_DATA_WIDTH = 8009,
    TEST_TOKEN_WEAK_DATA_HEIGHT = 8010,
    TEST_TOKEN_CFG_UPDATE_MODE = 8011,
    TEST_TOKEN_FINGERPRINT_ENUMERATING_FID = 8012,
    TEST_TOKEN_MAX = 10000,  // match with gf_manager_lib
} GF_TEST_TOKEN;

typedef enum {
    CMD_TEST_FRR_FAR_BASE = CMD_TEST_SZ_TEST_BASE + 1000,
    CMD_TEST_FRR_FAR_MOCK = CMD_TEST_FRR_FAR_BASE + 100,
    CMD_TEST_FRR_FAR_MOCK_INIT,
    CMD_TEST_FRR_FAR_MOCK_RAWDATA_ENROLL,
    CMD_TEST_FRR_FAR_MOCK_RAWDATA_AUTH,
    CMD_TEST_FRR_FAR_MOCK_ENROLL_BEGIN,
    CMD_TEST_FRR_FAR_MOCK_ENROLL_FINISH,
    CMD_TEST_FRR_FAR_MOCK_AUTH_BEGIN,
    CMD_TEST_FRR_FAR_MOCK_AUTH_FINISH,
    CMD_TEST_FRR_FAR_MOCK_NOTIFY
} SZ_FARR_MOCK_CMD;

#endif /* _SZPRODUCTTESTDEFINE_H_ */
