
#ifndef __POSIT_OPS_JUMPS_H
#define __POSIT_OPS_JUMPS_H

#include "posit.h"

#ifdef __cplusplus
  extern "C"{
#endif

   p8e0_t p8e0_add_j(const p8e0_t a, const p8e0_t b);
   p8e1_t p8e1_add_j(const p8e1_t a, const p8e1_t b);
   p8e2_t p8e2_add_j(const p8e2_t a, const p8e2_t b);
   p16e0_t p16e0_add_j(const p16e0_t a, const p16e0_t b);
   p16e1_t p16e1_add_j(const p16e1_t a, const p16e1_t b);
   p16e2_t p16e2_add_j(const p16e2_t a, const p16e2_t b);
   p32e0_t p32e0_add_j(const p32e0_t a, const p32e0_t b);
   p32e1_t p32e1_add_j(const p32e1_t a, const p32e1_t b);
   p32e2_t p32e2_add_j(const p32e2_t a, const p32e2_t b);
   p32e3_t p32e3_add_j(const p32e3_t a, const p32e3_t b);

   p8e0_t p8e0_mul_j(const p8e0_t a, const p8e0_t b);
   p8e1_t p8e1_mul_j(const p8e1_t a, const p8e1_t b);
   p8e2_t p8e2_mul_j(const p8e2_t a, const p8e2_t b);
   p16e0_t p16e0_mul_j(const p16e0_t a, const p16e0_t b);
   p16e1_t p16e1_mul_j(const p16e1_t a, const p16e1_t b);
   p16e2_t p16e2_mul_j(const p16e2_t a, const p16e2_t b);
   p32e0_t p32e0_mul_j(const p32e0_t a, const p32e0_t b);
   p32e1_t p32e1_mul_j(const p32e1_t a, const p32e1_t b);
   p32e2_t p32e2_mul_j(const p32e2_t a, const p32e2_t b);
   p32e3_t p32e3_mul_j(const p32e3_t a, const p32e3_t b);

   p8e0_t p8e0_sub_j(const p8e0_t a, const p8e0_t b);
   p8e1_t p8e1_sub_j(const p8e1_t a, const p8e1_t b);
   p8e2_t p8e2_sub_j(const p8e2_t a, const p8e2_t b);
   p16e0_t p16e0_sub_j(const p16e0_t a, const p16e0_t b);
   p16e1_t p16e1_sub_j(const p16e1_t a, const p16e1_t b);
   p16e2_t p16e2_sub_j(const p16e2_t a, const p16e2_t b);
   p32e0_t p32e0_sub_j(const p32e0_t a, const p32e0_t b);
   p32e1_t p32e1_sub_j(const p32e1_t a, const p32e1_t b);
   p32e2_t p32e2_sub_j(const p32e2_t a, const p32e2_t b);
   p32e3_t p32e3_sub_j(const p32e3_t a, const p32e3_t b);

   p8e0_t p8e0_addinv_j(const p8e0_t a);
   p8e1_t p8e1_addinv_j(const p8e1_t a);
   p8e2_t p8e2_addinv_j(const p8e2_t a);
   p16e0_t p16e0_addinv_j(const p16e0_t a);
   p16e1_t p16e1_addinv_j(const p16e1_t a);
   p16e2_t p16e2_addinv_j(const p16e2_t a);
   p32e0_t p32e0_addinv_j(const p32e0_t a);
   p32e1_t p32e1_addinv_j(const p32e1_t a);
   p32e2_t p32e2_addinv_j(const p32e2_t a);
   p32e3_t p32e3_addinv_j(const p32e3_t a);





   p8e0_t p8e0_div_j(const p8e0_t a, const p8e0_t b);
   p8e1_t p8e1_div_j(const p8e1_t a, const p8e1_t b);
   p8e2_t p8e2_div_j(const p8e2_t a, const p8e2_t b);
   p16e0_t p16e0_div_j(const p16e0_t a, const p16e0_t b);
   p16e1_t p16e1_div_j(const p16e1_t a, const p16e1_t b);
   p16e2_t p16e2_div_j(const p16e2_t a, const p16e2_t b);
   p32e0_t p32e0_div_j(const p32e0_t a, const p32e0_t b);
   p32e1_t p32e1_div_j(const p32e1_t a, const p32e1_t b);
   p32e2_t p32e2_div_j(const p32e2_t a, const p32e2_t b);
   p32e3_t p32e3_div_j(const p32e3_t a, const p32e3_t b);

   p8e0_t p8e0_mulinv_j(const p8e0_t a);
   p8e1_t p8e1_mulinv_j(const p8e1_t a);
   p8e2_t p8e2_mulinv_j(const p8e2_t a);
   p16e0_t p16e0_mulinv_j(const p16e0_t a);
   p16e1_t p16e1_mulinv_j(const p16e1_t a);
   p16e2_t p16e2_mulinv_j(const p16e2_t a);
   p32e0_t p32e0_mulinv_j(const p32e0_t a);
   p32e1_t p32e1_mulinv_j(const p32e1_t a);
   p32e2_t p32e2_mulinv_j(const p32e2_t a);
   p32e3_t p32e3_mulinv_j(const p32e3_t a);

   p8e0_t p8e0_log2_j(const p8e0_t a);
   p8e1_t p8e1_log2_j(const p8e1_t a);
   p8e2_t p8e2_log2_j(const p8e2_t a);
   p16e0_t p16e0_log2_j(const p16e0_t a);
   p16e1_t p16e1_log2_j(const p16e1_t a);
   p16e2_t p16e2_log2_j(const p16e2_t a);
   p32e0_t p32e0_log2_j(const p32e0_t a);
   p32e1_t p32e1_log2_j(const p32e1_t a);
   p32e2_t p32e2_log2_j(const p32e2_t a);
   p32e3_t p32e3_log2_j(const p32e3_t a);

   p8e0_t p8e0_exp2_j(const p8e0_t a);
   p8e1_t p8e1_exp2_j(const p8e1_t a);
   p8e2_t p8e2_exp2_j(const p8e2_t a);
   p16e0_t p16e0_exp2_j(const p16e0_t a);
   p16e1_t p16e1_exp2_j(const p16e1_t a);
   p16e2_t p16e2_exp2_j(const p16e2_t a);
   p32e0_t p32e0_exp2_j(const p32e0_t a);
   p32e1_t p32e1_exp2_j(const p32e1_t a);
   p32e2_t p32e2_exp2_j(const p32e2_t a);
   p32e3_t p32e3_exp2_j(const p32e3_t a);

   p8e0_t p8e0_fma_j(const p8e0_t a, const p8e0_t b, const p8e0_t c);
   p8e1_t p8e1_fma_j(const p8e1_t a, const p8e1_t b, const p8e1_t c);
   p8e2_t p8e2_fma_j(const p8e2_t a, const p8e2_t b, const p8e2_t c);
   p16e0_t p16e0_fma_j(const p16e0_t a, const p16e0_t b, const p16e0_t c);
   p16e1_t p16e1_fma_j(const p16e1_t a, const p16e1_t b, const p16e1_t c);
   p16e2_t p16e2_fma_j(const p16e2_t a, const p16e2_t b, const p16e2_t c);
   p32e0_t p32e0_fma_j(const p32e0_t a, const p32e0_t b, const p32e0_t c);
   p32e1_t p32e1_fma_j(const p32e1_t a, const p32e1_t b, const p32e1_t c);
   p32e2_t p32e2_fma_j(const p32e2_t a, const p32e2_t b, const p32e2_t c);
   p32e3_t p32e3_fma_j(const p32e3_t a, const p32e3_t b, const p32e3_t c);

   p8e0_t p8e0_fms_j(const p8e0_t a, const p8e0_t b, const p8e0_t c);
   p8e1_t p8e1_fms_j(const p8e1_t a, const p8e1_t b, const p8e1_t c);
   p8e2_t p8e2_fms_j(const p8e2_t a, const p8e2_t b, const p8e2_t c);
   p16e0_t p16e0_fms_j(const p16e0_t a, const p16e0_t b, const p16e0_t c);
   p16e1_t p16e1_fms_j(const p16e1_t a, const p16e1_t b, const p16e1_t c);
   p16e2_t p16e2_fms_j(const p16e2_t a, const p16e2_t b, const p16e2_t c);
   p32e0_t p32e0_fms_j(const p32e0_t a, const p32e0_t b, const p32e0_t c);
   p32e1_t p32e1_fms_j(const p32e1_t a, const p32e1_t b, const p32e1_t c);
   p32e2_t p32e2_fms_j(const p32e2_t a, const p32e2_t b, const p32e2_t c);
   p32e3_t p32e3_fms_j(const p32e3_t a, const p32e3_t b, const p32e3_t c);

   p8e0_t p8e0_nfma_j(const p8e0_t a, const p8e0_t b, const p8e0_t c);
   p8e1_t p8e1_nfma_j(const p8e1_t a, const p8e1_t b, const p8e1_t c);
   p8e2_t p8e2_nfma_j(const p8e2_t a, const p8e2_t b, const p8e2_t c);
   p16e0_t p16e0_nfma_j(const p16e0_t a, const p16e0_t b, const p16e0_t c);
   p16e1_t p16e1_nfma_j(const p16e1_t a, const p16e1_t b, const p16e1_t c);
   p16e2_t p16e2_nfma_j(const p16e2_t a, const p16e2_t b, const p16e2_t c);
   p32e0_t p32e0_nfma_j(const p32e0_t a, const p32e0_t b, const p32e0_t c);
   p32e1_t p32e1_nfma_j(const p32e1_t a, const p32e1_t b, const p32e1_t c);
   p32e2_t p32e2_nfma_j(const p32e2_t a, const p32e2_t b, const p32e2_t c);
   p32e3_t p32e3_nfma_j(const p32e3_t a, const p32e3_t b, const p32e3_t c);

   p8e0_t p8e0_nfms_j(const p8e0_t a, const p8e0_t b, const p8e0_t c);
   p8e1_t p8e1_nfms_j(const p8e1_t a, const p8e1_t b, const p8e1_t c);
   p8e2_t p8e2_nfms_j(const p8e2_t a, const p8e2_t b, const p8e2_t c);
   p16e0_t p16e0_nfms_j(const p16e0_t a, const p16e0_t b, const p16e0_t c);
   p16e1_t p16e1_nfms_j(const p16e1_t a, const p16e1_t b, const p16e1_t c);
   p16e2_t p16e2_nfms_j(const p16e2_t a, const p16e2_t b, const p16e2_t c);
   p32e0_t p32e0_nfms_j(const p32e0_t a, const p32e0_t b, const p32e0_t c);
   p32e1_t p32e1_nfms_j(const p32e1_t a, const p32e1_t b, const p32e1_t c);
   p32e2_t p32e2_nfms_j(const p32e2_t a, const p32e2_t b, const p32e2_t c);
   p32e3_t p32e3_nfms_j(const p32e3_t a, const p32e3_t b, const p32e3_t c);

   p8e0_t p8e0_fas_j(const p8e0_t a, const p8e0_t b, const p8e0_t c);
   p8e1_t p8e1_fas_j(const p8e1_t a, const p8e1_t b, const p8e1_t c);
   p8e2_t p8e2_fas_j(const p8e2_t a, const p8e2_t b, const p8e2_t c);
   p16e0_t p16e0_fas_j(const p16e0_t a, const p16e0_t b, const p16e0_t c);
   p16e1_t p16e1_fas_j(const p16e1_t a, const p16e1_t b, const p16e1_t c);
   p16e2_t p16e2_fas_j(const p16e2_t a, const p16e2_t b, const p16e2_t c);
   p32e0_t p32e0_fas_j(const p32e0_t a, const p32e0_t b, const p32e0_t c);
   p32e1_t p32e1_fas_j(const p32e1_t a, const p32e1_t b, const p32e1_t c);
   p32e2_t p32e2_fas_j(const p32e2_t a, const p32e2_t b, const p32e2_t c);
   p32e3_t p32e3_fas_j(const p32e3_t a, const p32e3_t b, const p32e3_t c);

   p8e0_t p8e0_fcp_j(const p8e0_t a, const p8e0_t b, const p8e0_t c, const p8e0_t d);
   p8e1_t p8e1_fcp_j(const p8e1_t a, const p8e1_t b, const p8e1_t c, const p8e1_t d);
   p8e2_t p8e2_fcp_j(const p8e2_t a, const p8e2_t b, const p8e2_t c, const p8e2_t d);
   p16e0_t p16e0_fcp_j(const p16e0_t a, const p16e0_t b, const p16e0_t c, const p16e0_t d);
   p16e1_t p16e1_fcp_j(const p16e1_t a, const p16e1_t b, const p16e1_t c, const p16e1_t d);
   p16e2_t p16e2_fcp_j(const p16e2_t a, const p16e2_t b, const p16e2_t c, const p16e2_t d);
   p32e0_t p32e0_fcp_j(const p32e0_t a, const p32e0_t b, const p32e0_t c, const p32e0_t d);
   p32e1_t p32e1_fcp_j(const p32e1_t a, const p32e1_t b, const p32e1_t c, const p32e1_t d);
   p32e2_t p32e2_fcp_j(const p32e2_t a, const p32e2_t b, const p32e2_t c, const p32e2_t d);
   p32e3_t p32e3_fcp_j(const p32e3_t a, const p32e3_t b, const p32e3_t c, const p32e3_t d);




   p8e0_t p8e0_sqrt_j(const p8e0_t a);
   p8e1_t p8e1_sqrt_j(const p8e1_t a);
   p8e2_t p8e2_sqrt_j(const p8e2_t a);
   p16e0_t p16e0_sqrt_j(const p16e0_t a);
   p16e1_t p16e1_sqrt_j(const p16e1_t a);
   p16e2_t p16e2_sqrt_j(const p16e2_t a);
   p32e0_t p32e0_sqrt_j(const p32e0_t a);
   p32e1_t p32e1_sqrt_j(const p32e1_t a);
   p32e2_t p32e2_sqrt_j(const p32e2_t a);
   p32e3_t p32e3_sqrt_j(const p32e3_t a);

   p8e0_t p8e0_log10_j(const p8e0_t a);
   p8e1_t p8e1_log10_j(const p8e1_t a);
   p8e2_t p8e2_log10_j(const p8e2_t a);
   p16e0_t p16e0_log10_j(const p16e0_t a);
   p16e1_t p16e1_log10_j(const p16e1_t a);
   p16e2_t p16e2_log10_j(const p16e2_t a);
   p32e0_t p32e0_log10_j(const p32e0_t a);
   p32e1_t p32e1_log10_j(const p32e1_t a);
   p32e2_t p32e2_log10_j(const p32e2_t a);
   p32e3_t p32e3_log10_j(const p32e3_t a);

   p8e0_t p8e0_log_j(const p8e0_t a);
   p8e1_t p8e1_log_j(const p8e1_t a);
   p8e2_t p8e2_log_j(const p8e2_t a);
   p16e0_t p16e0_log_j(const p16e0_t a);
   p16e1_t p16e1_log_j(const p16e1_t a);
   p16e2_t p16e2_log_j(const p16e2_t a);
   p32e0_t p32e0_log_j(const p32e0_t a);
   p32e1_t p32e1_log_j(const p32e1_t a);
   p32e2_t p32e2_log_j(const p32e2_t a);
   p32e3_t p32e3_log_j(const p32e3_t a);

   p8e0_t p8e0_exp_j(const p8e0_t a);
   p8e1_t p8e1_exp_j(const p8e1_t a);
   p8e2_t p8e2_exp_j(const p8e2_t a);
   p16e0_t p16e0_exp_j(const p16e0_t a);
   p16e1_t p16e1_exp_j(const p16e1_t a);
   p16e2_t p16e2_exp_j(const p16e2_t a);
   p32e0_t p32e0_exp_j(const p32e0_t a);
   p32e1_t p32e1_exp_j(const p32e1_t a);
   p32e2_t p32e2_exp_j(const p32e2_t a);
   p32e3_t p32e3_exp_j(const p32e3_t a);

   p8e0_t p8e0_pow_j(const p8e0_t a, const p8e0_t b);
   p8e1_t p8e1_pow_j(const p8e1_t a, const p8e1_t b);
   p8e2_t p8e2_pow_j(const p8e2_t a, const p8e2_t b);
   p16e0_t p16e0_pow_j(const p16e0_t a, const p16e0_t b);
   p16e1_t p16e1_pow_j(const p16e1_t a, const p16e1_t b);
   p16e2_t p16e2_pow_j(const p16e2_t a, const p16e2_t b);
   p32e0_t p32e0_pow_j(const p32e0_t a, const p32e0_t b);
   p32e1_t p32e1_pow_j(const p32e1_t a, const p32e1_t b);
   p32e2_t p32e2_pow_j(const p32e2_t a, const p32e2_t b);
   p32e3_t p32e3_pow_j(const p32e3_t a, const p32e3_t b);

   p8e0_t p8e0_logx_j(const p8e0_t a, const p8e0_t b);
   p8e1_t p8e1_logx_j(const p8e1_t a, const p8e1_t b);
   p8e2_t p8e2_logx_j(const p8e2_t a, const p8e2_t b);
   p16e0_t p16e0_logx_j(const p16e0_t a, const p16e0_t b);
   p16e1_t p16e1_logx_j(const p16e1_t a, const p16e1_t b);
   p16e2_t p16e2_logx_j(const p16e2_t a, const p16e2_t b);
   p32e0_t p32e0_logx_j(const p32e0_t a, const p32e0_t b);
   p32e1_t p32e1_logx_j(const p32e1_t a, const p32e1_t b);
   p32e2_t p32e2_logx_j(const p32e2_t a, const p32e2_t b);
   p32e3_t p32e3_logx_j(const p32e3_t a, const p32e3_t b);

   p8e0_t p8e0_sin_j(const p8e0_t a);
   p8e1_t p8e1_sin_j(const p8e1_t a);
   p8e2_t p8e2_sin_j(const p8e2_t a);
   p16e0_t p16e0_sin_j(const p16e0_t a);
   p16e1_t p16e1_sin_j(const p16e1_t a);
   p16e2_t p16e2_sin_j(const p16e2_t a);
   p32e0_t p32e0_sin_j(const p32e0_t a);
   p32e1_t p32e1_sin_j(const p32e1_t a);
   p32e2_t p32e2_sin_j(const p32e2_t a);
   p32e3_t p32e3_sin_j(const p32e3_t a);

   p8e0_t p8e0_cos_j(const p8e0_t a);
   p8e1_t p8e1_cos_j(const p8e1_t a);
   p8e2_t p8e2_cos_j(const p8e2_t a);
   p16e0_t p16e0_cos_j(const p16e0_t a);
   p16e1_t p16e1_cos_j(const p16e1_t a);
   p16e2_t p16e2_cos_j(const p16e2_t a);
   p32e0_t p32e0_cos_j(const p32e0_t a);
   p32e1_t p32e1_cos_j(const p32e1_t a);
   p32e2_t p32e2_cos_j(const p32e2_t a);
   p32e3_t p32e3_cos_j(const p32e3_t a);

   p8e0_t p8e0_atan_j(const p8e0_t a);
   p8e1_t p8e1_atan_j(const p8e1_t a);
   p8e2_t p8e2_atan_j(const p8e2_t a);
   p16e0_t p16e0_atan_j(const p16e0_t a);
   p16e1_t p16e1_atan_j(const p16e1_t a);
   p16e2_t p16e2_atan_j(const p16e2_t a);
   p32e0_t p32e0_atan_j(const p32e0_t a);
   p32e1_t p32e1_atan_j(const p32e1_t a);
   p32e2_t p32e2_atan_j(const p32e2_t a);
   p32e3_t p32e3_atan_j(const p32e3_t a);

   p8e0_t p8e0_atan2_j(const p8e0_t a, const p8e0_t b);
   p8e1_t p8e1_atan2_j(const p8e1_t a, const p8e1_t b);
   p8e2_t p8e2_atan2_j(const p8e2_t a, const p8e2_t b);
   p16e0_t p16e0_atan2_j(const p16e0_t a, const p16e0_t b);
   p16e1_t p16e1_atan2_j(const p16e1_t a, const p16e1_t b);
   p16e2_t p16e2_atan2_j(const p16e2_t a, const p16e2_t b);
   p32e0_t p32e0_atan2_j(const p32e0_t a, const p32e0_t b);
   p32e1_t p32e1_atan2_j(const p32e1_t a, const p32e1_t b);
   p32e2_t p32e2_atan2_j(const p32e2_t a, const p32e2_t b);
   p32e3_t p32e3_atan2_j(const p32e3_t a, const p32e3_t b);

#ifdef __cplusplus
}
#endif
#endif
