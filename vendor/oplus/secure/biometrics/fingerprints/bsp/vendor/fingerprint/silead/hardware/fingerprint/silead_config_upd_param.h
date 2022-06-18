PARAM_UPD_ITEM(param, device, dev_ver, dev, TYPE_DEV_LIST) /* dev ver list, must index 0 */
PARAM_UPD_ITEM_2(param, SysParam, SLMaskChipID, SLMaskID, mask, TYPE_MASK) /* mask, must index 1 */

/* register */
PARAM_UPD_ID_FROM(param, registers, cfg, 0x01) /* reg cfg */
PARAM_UPD_ITEM(param, registers, normal_mode,               cfg[CFG_NORMAL],        TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, data_interrupt_mode,       cfg[CFG_DOWN_INT],      TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, leave_interrupt_mode,      cfg[CFG_UP_INT],        TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, vkey_interrupt_mode,       cfg[CFG_VKEY_INT],      TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, nav_read_mode,             cfg[CFG_NAV],           TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, hg_nav_read_mode,          cfg[CFG_NAV_HG],        TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, ds_nav_read_mode,          cfg[CFG_NAV_DS],        TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, hg_ds_nav_read_mode,       cfg[CFG_NAV_HG_DS],     TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, hg_coverage_mode,          cfg[CFG_HG_COVERAGE],   TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, hwagc_read_mode,           cfg[CFG_HWAGC_READ],    TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, partial_read_mode,         cfg[CFG_PARTIAL],       TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, full_read_mode,            cfg[CFG_FULL],          TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, base_ori_mode,             cfg[CFG_BASE_ORI],      TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, finger_detect_mode,        cfg[CFG_FG_DETECT],     TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, auto_adjust_mode,          cfg[CFG_AUTO_ADJUST],   TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, start_frm_mode,            cfg[CFG_FRM_START],     TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, start_hwcov_mode,          cfg[CFG_HWCOV_START],   TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, start_hwagc_mode,          cfg[CFG_HWAGC_START],   TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, start_ds_mode,             cfg[CFG_DS_START],      TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, stop_mode,                 cfg[CFG_STOP],          TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, test_deadpix_mode1,        cfg[CFG_DEADPX1],       TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, test_deadpix_mode2,        cfg[CFG_DEADPX2],       TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, test_deadpix_mode3,        cfg[CFG_DEADPX3],       TYPE_UU_ARRAY)
PARAM_UPD_ITEM(param, registers, test_snr_mode,             cfg[CFG_SNR],           TYPE_UU_ARRAY)

/* SysParam/SLFpApi */
PARAM_UPD_ID_FROM(param, SysParam, SLFpApi, 0x05)
PARAM_UPD_ITEM_2(param, SysParam, SLFpApi, frame_h, common.h,   TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLFpApi, frame_w, common.w,   TYPE_UINT16)

/* SysParam/SLAlg */
PARAM_UPD_ID_FROM_2(param, SysParam, SLAlg, param, 0x0A) /* param cfg */
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, C_AlgParmA,    pb.param[CFG_PB_PARAM_FINETUNE],        TYPE_INT32_ARRAY)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, C_AlgParmN,    pb.param[CFG_PB_PARAM_NAVI],            TYPE_INT32_ARRAY)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, C_AlgParmB,    pb.param[CFG_PB_PARAM_BASE],            TYPE_INT32_ARRAY)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, C_AlgParmC,    pb.param[CFG_PB_PARAM_COVER],           TYPE_INT32_ARRAY)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, C_AlgParmAp,   pb.param[CFG_PB_PARAM_REDUCE_NOISE],    TYPE_INT32_ARRAY)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, C_AlgParmOpt,  pb.param[CFB_PB_PARAM_OPT_PARMC],       TYPE_INT32_ARRAY)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, C_AlgParmFd,   pb.param[CFB_PB_PARAM_OPT_FD],          TYPE_INT32_ARRAY)

PARAM_UPD_ID_FROM_2(param, SysParam, SLAlg, common, 0x0F) /* common */
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, partial_read_w,    common.wp,      TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, partial_read_h,    common.hp,      TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, hwagc_w,           common.w_hwagc, TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, hwagc_h,           common.h_hwagc, TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, cut_w,             common.wc,      TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, cut_h,             common.hc,      TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, wdpi,              common.wdpi,    TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, hdpi,              common.hdpi,    TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, fg_loop,           common.fg_loop, TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, alg_w,             common.wa,      TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, alg_h,             common.ha,      TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, alg_cut,           common.alg_cut, TYPE_UINT32)

PARAM_UPD_ID_FROM_2(param, SysParam, SLAlg, nav, 0x14) /* nav */
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, nav_enable,        nav.enable,             TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, nav_mode,          nav.mode,               TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, nav_read_w,        nav.w,                  TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, nav_read_h,        nav.h,                  TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, hg_nav_read_w,     nav.wh,                 TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, hg_nav_read_h,     nav.hh,                 TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, ds_nav_read_w,     nav.w_ds,               TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, ds_nav_read_h,     nav.h_ds,               TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, hg_ds_nav_read_w,  nav.w_hg_ds,            TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, hg_ds_nav_read_h,  nav.h_hg_ds,            TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, con_frame_get_num, nav.con_frame_get_num,  TYPE_UINT8)

PARAM_UPD_ID_FROM_2(param, SysParam, SLAlg, hwagc, 0x19) /* pb agc */
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, MaxLoopTime,           pb.agc.max_small,       TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, HWAGCFlag,             pb.agc.hwagc_enable,    TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, HWCoverageWake,        pb.agc.hwcov_wake,      TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, HWCoverageTune,        pb.agc.hwcov_tune,      TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, ExpSize,               pb.agc.exp_size,        TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, SkipSmall,             pb.agc.skip_small,      TYPE_UINT8)

PARAM_UPD_ID_FROM_2(param, SysParam, SLAlg, mmi, 0x1E) /* mmi */
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, mmi_dac_min,           mmi.dac_min,                TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, mmi_dac_max,           mmi.dac_max,                TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, mmi_grey_range_left,   mmi.grey_range_left,        TYPE_INT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, mmi_grey_range_right,  mmi.grey_range_right,       TYPE_INT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, nav_base_frame_num,    mmi.nav_base_frame_num,     TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, mmi_max_tune_time,     mmi.max_tune_time,          TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, auto_adjust_w,         mmi.auto_adjust_w,          TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, auto_adjust_h,         mmi.auto_adjust_h,          TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, frm_loop_max,          mmi.frm_loop_max,           TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, postprocess_ctl,       mmi.postprocess_ctl,        TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, whiteBaseWhiteThr,     mmi.white_base_white_thr,   TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, cen_w_start,           mmi.white_base_white_thr,   TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, whiteBaseBlackThr,     mmi.white_base_black_thr,   TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, cen_h_start,           mmi.white_base_black_thr,   TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, blackBaseWhiteThr,     mmi.black_base_white_thr,   TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, cen_w_ace,             mmi.black_base_white_thr,   TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, blackBaseBlackThr,     mmi.black_base_black_thr,   TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, cen_h_ace,             mmi.black_base_black_thr,   TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, middleBaseWhiteThr,    mmi.middle_base_white_thr,  TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, middleBaseBlackThr,    mmi.middle_base_black_thr,  TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, diffBaseMinThr,        mmi.diff_base_min_thr,      TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, diffBaseMaxThr,        mmi.diff_base_max_thr,      TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, snr_cut,               mmi.snr_cut,                TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, base_size,             mmi.base_size,              TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, snr_img_num,           mmi.snr_img_num,            TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, snrThr,                mmi.snr_thr,                TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, distortion,            mmi.distortion,             TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, finger_num,            mmi.finger_num,             TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, storage_interval,      mmi.storage_interval,       TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, sum_type,              mmi.sum_type,               TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, dpx_radius,            mmi.deadpx_radius,          TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, cut_radius,            mmi.cut_radius,             TYPE_UINT8)

PARAM_UPD_ITEM_2(param, SysParam, SLAlg, normalize_blk,         mmi.normalize_blk,          TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, normalize_ratio,       mmi.normalize_ratio,        TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, fft_ratio,             mmi.fft_ratio,              TYPE_UINT32)

PARAM_UPD_ID_FROM_2(param, SysParam, SLAlg, ci, 0x23) /* ci */
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, auth_reverse_skip,             ci.auth_reverse_skip,       TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, auth_reverse_grey,             ci.auth_reverse_grey,       TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, enroll_loop,                   ci.enroll_loop,             TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, enroll_skip,                   ci.enroll_skip,             TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, auth_buf_num,                  ci.auth_buf_num,            TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, artificial_verify_bias,        ci.artificial_verify_bias,  TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, artificial_update_bias,        ci.artificial_update_bias,  TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, fingerprint_spd_score_thr,     ci.fingerprint_spd_score,   TYPE_INT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, algorithm_ctl,                 ci.alg_ctl,                 TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, fake_score_Threshold,          ci.fake_score,              TYPE_INT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, artifical_score_thr,           ci.artifical_score,         TYPE_INT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, miscellaneous_ctl,             ci.misc_ctl,                TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, maximum_mean_gap,              ci.max_mean_gap,            TYPE_UINT8)

PARAM_UPD_ID_FROM_2(param, SysParam, SLAlg, pp, 0x28) /* pp */
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, shutterleft,                   pp.aec_left,                TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, shutterright,                  pp.aec_right,               TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, aec_sram_time,                 pp.aec_time,                TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, cal_maxlooptime,               pp.cal_max_loop,            TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, dead_a,                        pp.dead_a,                  TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, dead_b,                        pp.dead_b,                  TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, quality_cut,                   pp.quality_cut,             TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, quality_thr,                   pp.quality_thr,             TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, enroll_quality_chk_num,        pp.enroll_quality_chk_num,  TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, enroll_post_num,               pp.enroll_post_num,         TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, enroll_post_mask,              pp.enroll_post_mask,        TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, icon_ratio_z,                  pp.icon_ratio_z,            TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, icon_ratio_m,                  pp.icon_ratio_m,            TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, big_blot_threshold,            pp.big_blot_thr,            TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, duo_tpl_quality_threshold,     pp.duo_tpl_thr,             TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, tpl_update_leakage_threshold,  pp.tpl_upd_leakage_thr,     TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, tp_coverage_default,           pp.tp_coverage_default,     TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, slope_len,                     pp.slope_len,               TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, slope_cnt,                     pp.slope_cnt,               TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, iCharge_Noise_Threshold_Goal,  pp.slope_h,                 TYPE_INT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, slope_h,                       pp.slope_h,                 TYPE_INT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, iCharge_Noise_Threshold_Start, pp.slope_w,                 TYPE_INT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, slope_w,                       pp.slope_w,                 TYPE_INT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, cut_angle,                     pp.cut_angle,               TYPE_INT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, cut_up_down,                   pp.cut_ud,                  TYPE_INT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, cut_left_right,                pp.cut_lr,                  TYPE_INT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, dry_sub_cnt,                   pp.dry_sub_cnt,             TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, after_verify_cnt,              pp.after_verify_cnt,        TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, wts_threshold,                 pp.wts_threshold,           TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, wts_up_cnt,                    pp.wts_up_cnt,              TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, attack_fail_cnt,               pp.attack_fail_cnt,         TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, w2d_verify,                    pp.w2d_verify,              TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, w2d_update,                    pp.w2d_update,              TYPE_UINT8)

PARAM_UPD_ID_FROM_2(param, SysParam, SLAlg, ft, 0x2D) /* ft */
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, ft_line_step_min,                  ft.line_step_min,       TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, ft_ignore,                         ft.ignore,              TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, ft_min_theta,                      ft.min_theta,           TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, ft_max_theta,                      ft.max_theta,           TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, ft_quality_thr,                    ft.quality_thr,         TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, ft_line_distance_min,              ft.line_distance_min,   TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, ft_line_distance_max,              ft.line_distance_max,   TYPE_UINT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, ft_cut,                            ft.cut,                 TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, mask_min1,                         ft.mask_min1,           TYPE_INT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, mask_min2,                         ft.mask_min2,           TYPE_INT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, mask_min3,                         ft.mask_min3,           TYPE_INT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, mask_max1,                         ft.mask_max1,           TYPE_INT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, mask_max2,                         ft.mask_max2,           TYPE_INT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, mask_max3,                         ft.mask_max3,           TYPE_INT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, mask_threshold,                    ft.mask_thr,            TYPE_INT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, mask_error_threshold,              ft.mask_err_thr,        TYPE_INT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, mask_ex_threshold,                 ft.mask_ex,             TYPE_INT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, bias_threshold,                    ft.bias_thr,            TYPE_INT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, bias_error_threshold,              ft.bias_err_thr,        TYPE_INT16)

PARAM_UPD_ITEM_2(param, SysParam, SLAlg, shading_threshold,                 ft.shading_thr,         TYPE_INT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, shading_unit_threshold,            ft.shading_unit_thr,    TYPE_INT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, pvalue_gray_threshold,             ft.p_gray_thr,          TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, pvalue_white_black_threshold,      ft.p_w_b_thr,           TYPE_UINT8)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, pvalue_gray_area_threshold,        ft.p_gray_area_thr,     TYPE_INT16)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, pvalue_white_black_area_threshold, ft.p_w_b_area_thr,      TYPE_INT16)

PARAM_UPD_ITEM_2(param, SysParam, SLAlg, dark_percent_thr,  ft.dark_percent_thr,    TYPE_INT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, max_diameter_thr,  ft.max_diameter_thr,    TYPE_INT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, min_diameter_thr,  ft.min_diameter_thr,    TYPE_INT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, circle_thr,        ft.circle_thr,          TYPE_INT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, black_signal_thr,  ft.black_signal_thr,    TYPE_INT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, mean_diff,         ft.mean_diff,           TYPE_INT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, r_square_thr,      ft.r_square_thr,        TYPE_INT32)

PARAM_UPD_ITEM_2(param, SysParam, SLAlg, edge_threshold,    ft.check_snr.edge_threshold,    TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, line_len,          ft.check_snr.line_len,          TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, line_num,          ft.check_snr.line_num,          TYPE_UINT32)

PARAM_UPD_ID_FROM_2(param, SysParam, SLAlg, touch, 0x32) /* touch info */
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, touch_center_x,                    mmi.touch_info.center_x,                    TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, touch_center_y,                    mmi.touch_info.center_y,                    TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, touch_b1_distance_threshold,       mmi.touch_info.b1_distance_threshold,       TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, touch_b2_distance_threshold,       mmi.touch_info.b2_distance_threshold,       TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, touch_b2_b1_distance_threshold,    mmi.touch_info.b2_b1_distance_threshold,    TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, touch_c1_coverage_threshold,       mmi.touch_info.c1_coverage_threshold,       TYPE_UINT32)
PARAM_UPD_ITEM_2(param, SysParam, SLAlg, touch_c2_coverage_threshold,       mmi.touch_info.c2_coverage_threshold,       TYPE_UINT32)

/* HardWare/spi */
PARAM_UPD_ID_FROM_2(param, SysParam, HardWare, spi, 0x37)
PARAM_UPD_ITEM_3(param, SysParam, HardWare, spi, ms_frm,  spi.ms_frm, TYPE_UINT16)
PARAM_UPD_ITEM_3(param, SysParam, HardWare, spi, retry,   spi.retry,  TYPE_UINT8)
PARAM_UPD_ITEM_3(param, SysParam, HardWare, spi, reinit,  spi.reinit, TYPE_UINT8)
PARAM_UPD_ITEM_3(param, SysParam, HardWare, spi, start,   spi.start,  TYPE_UINT16)
PARAM_UPD_ITEM_3(param, SysParam, HardWare, spi, msb,     spi.msb,    TYPE_UINT8)

/* op_registers */
PARAM_UPD_ID_FROM(param, op_registers, fine_tune, 0x3C) /* fine_tune */
PARAM_UPD_ITEM(param, op_registers, fine_tune_val_dac,  common.gain.v0c,    TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, fine_tune_val_ag20, common.gain.v20,    TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, fine_tune_val_ag2c, common.gain.v2c,    TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, fine_tune_val_ag24, common.gain.v24,    TYPE_UINT32)

PARAM_UPD_ID_FROM(param, op_registers, fine_tune_reg, 0x3D) /* fine_tune_reg */
PARAM_UPD_ITEM(param, op_registers, fine_tune_reg_dac,  common.gain_reg.reg0c,  TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, fine_tune_reg_ag20, common.gain_reg.reg20,  TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, fine_tune_reg_ag2c, common.gain_reg.reg2c,  TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, fine_tune_reg_ag24, common.gain_reg.reg24,  TYPE_UINT32)

PARAM_UPD_ID_FROM(param, op_registers, navi_tune, 0x3E) /* navi_tune */
PARAM_UPD_ITEM(param, op_registers, navi_tune_val_dac,  nav.gain[CFG_NAV_AGC_MODE_TUNE].v0c,    TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, navi_tune_val_ag20, nav.gain[CFG_NAV_AGC_MODE_TUNE].v20,    TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, navi_tune_val_ag2c, nav.gain[CFG_NAV_AGC_MODE_TUNE].v2c,    TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, navi_tune_val_ag24, nav.gain[CFG_NAV_AGC_MODE_TUNE].v24,    TYPE_UINT32)

PARAM_UPD_ID_FROM(param, op_registers, navi_hg, 0x3F) /* navi_hg */
PARAM_UPD_ITEM(param, op_registers, navi_hg_val_dac,    nav.gain[CFG_NAV_AGC_MODE_HG].v0c,      TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, navi_hg_val_ag20,   nav.gain[CFG_NAV_AGC_MODE_HG].v20,      TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, navi_hg_val_ag2c,   nav.gain[CFG_NAV_AGC_MODE_HG].v2c,      TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, navi_hg_val_ag24,   nav.gain[CFG_NAV_AGC_MODE_HG].v24,      TYPE_UINT32)

PARAM_UPD_ID_FROM(param, op_registers, navi_ds, 0x40) /* navi_ds */
PARAM_UPD_ITEM(param, op_registers, navi_ds_tune_val_dac,   nav.gain[CFG_NAV_AGC_MODE_DS].v0c,  TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, navi_ds_tune_val_ag24,  nav.gain[CFG_NAV_AGC_MODE_DS].v24,  TYPE_UINT32)

PARAM_UPD_ID_FROM(param, op_registers, navi_hg_ds, 0x41) /* navi_hg_ds */
PARAM_UPD_ITEM(param, op_registers, navi_hg_ds_val_dac, nav.gain[CFG_NAV_AGC_MODE_HG_DS].v0c,   TYPE_UINT32)

PARAM_UPD_ID_FROM(param, op_registers, esd, 0x42) /* esd */
PARAM_UPD_ITEM(param, op_registers, esd_irq_check,      esd.irq_check,  TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, esd_irq_reg,        esd.irq_reg,    TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, esd_irq_val,        esd.irq_val,    TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, data_int_reg,       esd.int_reg,    TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, data_int_val,       esd.int_val,    TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, data_int_beacon,    esd.int_beacon, TYPE_UINT32)

PARAM_UPD_ID_FROM(param, op_registers, otp, 0x46) /* otp */
PARAM_UPD_ITEM(param, op_registers, otp_reg_otp0,   common.otp.otp0,    TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, otp_reg_otp1,   common.otp.otp1,    TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, otp_reg_otp2,   common.otp.otp2,    TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, otp_reg_otp3,   common.otp.otp3,    TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, otp_reg_otp4,   common.otp.otp4,    TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, otp_reg_otp5,   common.otp.otp5,    TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, otp_a0_val,     common.otp.otp_a0,  TYPE_UINT32)

PARAM_UPD_ID_FROM(param, op_registers, snr, 0x48) /* snr */
PARAM_UPD_ITEM(param, op_registers, snr_gain_val_dac,   mmi.gain_snr_signal.v0c,    TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, snr_gain_val_ag20,  mmi.gain_snr_signal.v20,    TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, snr_gain_val_ag2c,  mmi.gain_snr_signal.v2c,    TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, snr_gain_val_ag24,  mmi.gain_snr_signal.v24,    TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, snr_white_val_dac,  mmi.gain_snr_white.v0c,     TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, snr_white_val_ag20, mmi.gain_snr_white.v20,     TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, snr_white_val_ag2c, mmi.gain_snr_white.v2c,     TYPE_UINT32)
PARAM_UPD_ITEM(param, op_registers, snr_white_val_ag24, mmi.gain_snr_white.v24,     TYPE_UINT32)