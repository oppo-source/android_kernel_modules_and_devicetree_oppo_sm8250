PARAM_UPD_ID_FROM_2(config, SysParam, SLAlg, normal, 0xC8) /* pb config */
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, ialgi,                              pb.threshold.alg_select,                    TYPE_INT8)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, iMaxEnrollNum,                      pb.threshold.enrolNum,                      TYPE_INT8)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, iMaxTemplateNum,                    pb.threshold.max_templates_num,             TYPE_INT16)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, imax_template_size,                 pb.threshold.templates_size,                TYPE_INT32)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, ienroll_quality_threshold,          pb.threshold.enroll_quality_threshold,      TYPE_INT16)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, ienroll_coverage_threshold,         pb.threshold.enroll_coverage_threshold,     TYPE_INT16)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, iverify_quality_threshold,          pb.threshold.quality_threshold,             TYPE_UINT8)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, iverify_coverage_threshold,         pb.threshold.coverage_threshold,            TYPE_UINT8)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, skin_threshold,                     pb.threshold.skin_threshold,                TYPE_UINT16)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, artificial_threshold,               pb.threshold.artificial_threshold,          TYPE_UINT16)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, enroll_same_area,                   pb.threshold.samearea_detect,               TYPE_UINT16)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, isamearea_dist,                     pb.threshold.samearea_dist,                 TYPE_UINT16)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, iverifyStart,                       pb.threshold.samearea_start,                TYPE_UINT16)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, idyupdatefast_set,                  pb.threshold.dy_fast,                       TYPE_UINT16)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, isegment_set,                       pb.threshold.segment,                       TYPE_UINT32)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, water_finger_detect,                pb.threshold.water_finger_detect,           TYPE_UINT32)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, shake_coe,                          pb.threshold.shake_coe,                     TYPE_UINT32)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, noise_coe,                          pb.threshold.noise_coe,                     TYPE_UINT32)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, gray_prec,                          pb.threshold.gray_prec,                     TYPE_UINT32)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, water_detect_threshold,             pb.threshold.water_detect_threshold,        TYPE_UINT32)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, fail_threshold,                     pb.threshold.fail_threshold,                TYPE_UINT16)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, spd_flag,                           pb.threshold.spd_flag,                      TYPE_UINT8)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, iverify_far_high_threshold,         pb.threshold.identify_far_threshold,        TYPE_FAR)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, iverify_uptem_threshold,            pb.threshold.update_far_threshold,          TYPE_FAR)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, isamearea_verify_threshold,         pb.threshold.samearea_threshold,            TYPE_FAR)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, isamefinger_verify_threshold,       pb.threshold.samefinger_threshold,          TYPE_FAR)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, verify_epay_threshold,              pb.threshold.identify_epay_threshold,       TYPE_FAR)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, force_up_threshold,                 pb.threshold.force_up_threshold,            TYPE_FAR)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, isamearea_chk_mask,                 pb.threshold.samearea_mask,                 TYPE_UINT32)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, isamearea_chk_times_pre_step,       pb.threshold.samearea_check_once_num,       TYPE_UINT16)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, isamearea_chk_max_times,            pb.threshold.samearea_check_num_total,      TYPE_UINT16)

PARAM_UPD_ID_FROM_2(config, SysParam, SLAlg, deadpix, 0xCD) /* deadpix */
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, fingerdetectThreshold,              test.fd_threshold,                          TYPE_UINT8)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, deadpointhardThershold,             test.deadpx_hard_threshold,                 TYPE_UINT8)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, deadpointnormalThreashold,          test.deadpx_norm_threshold,                 TYPE_UINT8)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, scut,                               test.scut,                                  TYPE_UINT8)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, detev_ww,                           test.detev_ww,                              TYPE_UINT16)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, detev_hh,                           test.detev_hh,                              TYPE_UINT16)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, deteline_h,                         test.deteline_h,                            TYPE_UINT16)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, deteline_w,                         test.deteline_w,                            TYPE_UINT16)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, deadpointmax,                       test.deadpx_max,                            TYPE_UINT8)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, badlinemax,                         test.badline_max,                           TYPE_UINT8)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, deadpoint_finger_detect_mode,       test.finger_detect_mode,                    TYPE_UINT16)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, deadpoint_cut,                      test.deadpx_cut,                            TYPE_UINT32)
PARAM_UPD_ITEM_2(config, SysParam, SLAlg, center_bias_threshold,              test.center_bias_thr,                       TYPE_INT32)