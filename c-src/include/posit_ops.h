#ifndef __POSIT_OPS_H
#define __POSIT_OPS_H

#include "posit.h"
extern "C" void p8e0_add(p8e0_t *res, p8e0_t *lhs, p8e0_t *rhs);
extern "C" void p8e1_add(p8e1_t *res, p8e1_t *lhs, p8e1_t *rhs);
extern "C" void p8e2_add(p8e2_t *res, p8e2_t *lhs, p8e2_t *rhs);
extern "C" void p16e0_add(p16e0_t *res, p16e0_t *lhs, p16e0_t *rhs);
extern "C" void p16e1_add(p16e1_t *res, p16e1_t *lhs, p16e1_t *rhs);
extern "C" void p16e2_add(p16e2_t *res, p16e2_t *lhs, p16e2_t *rhs);
extern "C" void p32e0_add(p32e0_t *res, p32e0_t *lhs, p32e0_t *rhs);
extern "C" void p32e1_add(p32e1_t *res, p32e1_t *lhs, p32e1_t *rhs);
extern "C" void p32e2_add(p32e2_t *res, p32e2_t *lhs, p32e2_t *rhs);
extern "C" void p32e3_add(p32e3_t *res, p32e3_t *lhs, p32e3_t *rhs);

extern "C" void p8e0_mul(p8e0_t *res, p8e0_t *lhs, p8e0_t *rhs);
extern "C" void p8e1_mul(p8e1_t *res, p8e1_t *lhs, p8e1_t *rhs);
extern "C" void p8e2_mul(p8e2_t *res, p8e2_t *lhs, p8e2_t *rhs);
extern "C" void p16e0_mul(p16e0_t *res, p16e0_t *lhs, p16e0_t *rhs);
extern "C" void p16e1_mul(p16e1_t *res, p16e1_t *lhs, p16e1_t *rhs);
extern "C" void p16e2_mul(p16e2_t *res, p16e2_t *lhs, p16e2_t *rhs);
extern "C" void p32e0_mul(p32e0_t *res, p32e0_t *lhs, p32e0_t *rhs);
extern "C" void p32e1_mul(p32e1_t *res, p32e1_t *lhs, p32e1_t *rhs);
extern "C" void p32e2_mul(p32e2_t *res, p32e2_t *lhs, p32e2_t *rhs);
extern "C" void p32e3_mul(p32e3_t *res, p32e3_t *lhs, p32e3_t *rhs);

extern "C" void p8e0_sub(p8e0_t *res, p8e0_t *lhs, p8e0_t *rhs);
extern "C" void p8e1_sub(p8e1_t *res, p8e1_t *lhs, p8e1_t *rhs);
extern "C" void p8e2_sub(p8e2_t *res, p8e2_t *lhs, p8e2_t *rhs);
extern "C" void p16e0_sub(p16e0_t *res, p16e0_t *lhs, p16e0_t *rhs);
extern "C" void p16e1_sub(p16e1_t *res, p16e1_t *lhs, p16e1_t *rhs);
extern "C" void p16e2_sub(p16e2_t *res, p16e2_t *lhs, p16e2_t *rhs);
extern "C" void p32e0_sub(p32e0_t *res, p32e0_t *lhs, p32e0_t *rhs);
extern "C" void p32e1_sub(p32e1_t *res, p32e1_t *lhs, p32e1_t *rhs);
extern "C" void p32e2_sub(p32e2_t *res, p32e2_t *lhs, p32e2_t *rhs);
extern "C" void p32e3_sub(p32e3_t *res, p32e3_t *lhs, p32e3_t *rhs);

extern "C" p8e0_t p8e0_addinv(p8e0_t x);
extern "C" p8e1_t p8e1_addinv(p8e1_t x);
extern "C" p8e2_t p8e2_addinv(p8e2_t x);
extern "C" p16e0_t p16e0_addinv(p16e0_t x);
extern "C" p16e1_t p16e1_addinv(p16e1_t x);
extern "C" p16e2_t p16e2_addinv(p16e2_t x);
extern "C" p32e0_t p32e0_addinv(p32e0_t x);
extern "C" p32e1_t p32e1_addinv(p32e1_t x);
extern "C" p32e2_t p32e2_addinv(p32e2_t x);
extern "C" p32e3_t p32e3_addinv(p32e3_t x);

extern "C" bool p8e0_lt(p8e0_t lhs, p8e0_t rhs);
extern "C" bool p8e1_lt(p8e1_t lhs, p8e1_t rhs);
extern "C" bool p8e2_lt(p8e2_t lhs, p8e2_t rhs);
extern "C" bool p16e0_lt(p16e0_t lhs, p16e0_t rhs);
extern "C" bool p16e1_lt(p16e1_t lhs, p16e1_t rhs);
extern "C" bool p16e2_lt(p16e2_t lhs, p16e2_t rhs);
extern "C" bool p32e0_lt(p32e0_t lhs, p32e0_t rhs);
extern "C" bool p32e1_lt(p32e1_t lhs, p32e1_t rhs);
extern "C" bool p32e2_lt(p32e2_t lhs, p32e2_t rhs);
extern "C" bool p32e3_lt(p32e3_t lhs, p32e3_t rhs);

extern "C" bool p8e0_lte(p8e0_t lhs, p8e0_t rhs);
extern "C" bool p8e1_lte(p8e1_t lhs, p8e1_t rhs);
extern "C" bool p8e2_lte(p8e2_t lhs, p8e2_t rhs);
extern "C" bool p16e0_lte(p16e0_t lhs, p16e0_t rhs);
extern "C" bool p16e1_lte(p16e1_t lhs, p16e1_t rhs);
extern "C" bool p16e2_lte(p16e2_t lhs, p16e2_t rhs);
extern "C" bool p32e0_lte(p32e0_t lhs, p32e0_t rhs);
extern "C" bool p32e1_lte(p32e1_t lhs, p32e1_t rhs);
extern "C" bool p32e2_lte(p32e2_t lhs, p32e2_t rhs);
extern "C" bool p32e3_lte(p32e3_t lhs, p32e3_t rhs);

extern "C" void p8e0_div(p8e0_t *res, p8e0_t *lhs, p8e0_t *rhs);
extern "C" void p8e1_div(p8e1_t *res, p8e1_t *lhs, p8e1_t *rhs);
extern "C" void p8e2_div(p8e2_t *res, p8e2_t *lhs, p8e2_t *rhs);
extern "C" void p16e0_div(p16e0_t *res, p16e0_t *lhs, p16e0_t *rhs);
extern "C" void p16e1_div(p16e1_t *res, p16e1_t *lhs, p16e1_t *rhs);
extern "C" void p16e2_div(p16e2_t *res, p16e2_t *lhs, p16e2_t *rhs);
extern "C" void p32e0_div(p32e0_t *res, p32e0_t *lhs, p32e0_t *rhs);
extern "C" void p32e1_div(p32e1_t *res, p32e1_t *lhs, p32e1_t *rhs);
extern "C" void p32e2_div(p32e2_t *res, p32e2_t *lhs, p32e2_t *rhs);
extern "C" void p32e3_div(p32e3_t *res, p32e3_t *lhs, p32e3_t *rhs);

extern "C" p8e0_t p8e0_mulinv(p8e0_t x);
extern "C" p8e1_t p8e1_mulinv(p8e1_t x);
extern "C" p8e2_t p8e2_mulinv(p8e2_t x);
extern "C" p16e0_t p16e0_mulinv(p16e0_t x);
extern "C" p16e1_t p16e1_mulinv(p16e1_t x);
extern "C" p16e2_t p16e2_mulinv(p16e2_t x);
extern "C" p32e0_t p32e0_mulinv(p32e0_t x);
extern "C" p32e1_t p32e1_mulinv(p32e1_t x);
extern "C" p32e2_t p32e2_mulinv(p32e2_t x);
extern "C" p32e3_t p32e3_mulinv(p32e3_t x);

extern "C" p8e0_t p8e0_log2(p8e0_t x);
extern "C" p8e1_t p8e1_log2(p8e1_t x);
extern "C" p8e2_t p8e2_log2(p8e2_t x);
extern "C" p16e0_t p16e0_log2(p16e0_t x);
extern "C" p16e1_t p16e1_log2(p16e1_t x);
extern "C" p16e2_t p16e2_log2(p16e2_t x);
extern "C" p32e0_t p32e0_log2(p32e0_t x);
extern "C" p32e1_t p32e1_log2(p32e1_t x);
extern "C" p32e2_t p32e2_log2(p32e2_t x);
extern "C" p32e3_t p32e3_log2(p32e3_t x);

extern "C" p8e0_t p8e0_exp2(p8e0_t x);
extern "C" p8e1_t p8e1_exp2(p8e1_t x);
extern "C" p8e2_t p8e2_exp2(p8e2_t x);
extern "C" p16e0_t p16e0_exp2(p16e0_t x);
extern "C" p16e1_t p16e1_exp2(p16e1_t x);
extern "C" p16e2_t p16e2_exp2(p16e2_t x);
extern "C" p32e0_t p32e0_exp2(p32e0_t x);
extern "C" p32e1_t p32e1_exp2(p32e1_t x);
extern "C" p32e2_t p32e2_exp2(p32e2_t x);
extern "C" p32e3_t p32e3_exp2(p32e3_t x);

extern "C" void p8e0_fma(p8e0_t *res, p8e0_t *a,   p8e0_t *b,   p8e0_t *c);
extern "C" void p8e1_fma(p8e1_t *res, p8e1_t *a,   p8e1_t *b,   p8e1_t *c);
extern "C" void p8e2_fma(p8e2_t *res, p8e2_t *a,   p8e2_t *b,   p8e2_t *c);
extern "C" void p16e0_fma(p16e0_t *res, p16e0_t *a,   p16e0_t *b,   p16e0_t *c);
extern "C" void p16e1_fma(p16e1_t *res, p16e1_t *a,   p16e1_t *b,   p16e1_t *c);
extern "C" void p16e2_fma(p16e2_t *res, p16e2_t *a,   p16e2_t *b,   p16e2_t *c);
extern "C" void p32e0_fma(p32e0_t *res, p32e0_t *a,   p32e0_t *b,   p32e0_t *c);
extern "C" void p32e1_fma(p32e1_t *res, p32e1_t *a,   p32e1_t *b,   p32e1_t *c);
extern "C" void p32e2_fma(p32e2_t *res, p32e2_t *a,   p32e2_t *b,   p32e2_t *c);
extern "C" void p32e3_fma(p32e3_t *res, p32e3_t *a,   p32e3_t *b,   p32e3_t *c);

extern "C" void p8e0_fms(p8e0_t *res, p8e0_t *a,   p8e0_t *b,   p8e0_t *c);
extern "C" void p8e1_fms(p8e1_t *res, p8e1_t *a,   p8e1_t *b,   p8e1_t *c);
extern "C" void p8e2_fms(p8e2_t *res, p8e2_t *a,   p8e2_t *b,   p8e2_t *c);
extern "C" void p16e0_fms(p16e0_t *res, p16e0_t *a,   p16e0_t *b,   p16e0_t *c);
extern "C" void p16e1_fms(p16e1_t *res, p16e1_t *a,   p16e1_t *b,   p16e1_t *c);
extern "C" void p16e2_fms(p16e2_t *res, p16e2_t *a,   p16e2_t *b,   p16e2_t *c);
extern "C" void p32e0_fms(p32e0_t *res, p32e0_t *a,   p32e0_t *b,   p32e0_t *c);
extern "C" void p32e1_fms(p32e1_t *res, p32e1_t *a,   p32e1_t *b,   p32e1_t *c);
extern "C" void p32e2_fms(p32e2_t *res, p32e2_t *a,   p32e2_t *b,   p32e2_t *c);
extern "C" void p32e3_fms(p32e3_t *res, p32e3_t *a,   p32e3_t *b,   p32e3_t *c);

extern "C" void p8e0_nfma(p8e0_t *res, p8e0_t *a,   p8e0_t *b,   p8e0_t *c);
extern "C" void p8e1_nfma(p8e1_t *res, p8e1_t *a,   p8e1_t *b,   p8e1_t *c);
extern "C" void p8e2_nfma(p8e2_t *res, p8e2_t *a,   p8e2_t *b,   p8e2_t *c);
extern "C" void p16e0_nfma(p16e0_t *res, p16e0_t *a,   p16e0_t *b,   p16e0_t *c);
extern "C" void p16e1_nfma(p16e1_t *res, p16e1_t *a,   p16e1_t *b,   p16e1_t *c);
extern "C" void p16e2_nfma(p16e2_t *res, p16e2_t *a,   p16e2_t *b,   p16e2_t *c);
extern "C" void p32e0_nfma(p32e0_t *res, p32e0_t *a,   p32e0_t *b,   p32e0_t *c);
extern "C" void p32e1_nfma(p32e1_t *res, p32e1_t *a,   p32e1_t *b,   p32e1_t *c);
extern "C" void p32e2_nfma(p32e2_t *res, p32e2_t *a,   p32e2_t *b,   p32e2_t *c);
extern "C" void p32e3_nfma(p32e3_t *res, p32e3_t *a,   p32e3_t *b,   p32e3_t *c);

extern "C" void p8e0_nfms(p8e0_t *res, p8e0_t *a,   p8e0_t *b,   p8e0_t *c);
extern "C" void p8e1_nfms(p8e1_t *res, p8e1_t *a,   p8e1_t *b,   p8e1_t *c);
extern "C" void p8e2_nfms(p8e2_t *res, p8e2_t *a,   p8e2_t *b,   p8e2_t *c);
extern "C" void p16e0_nfms(p16e0_t *res, p16e0_t *a,   p16e0_t *b,   p16e0_t *c);
extern "C" void p16e1_nfms(p16e1_t *res, p16e1_t *a,   p16e1_t *b,   p16e1_t *c);
extern "C" void p16e2_nfms(p16e2_t *res, p16e2_t *a,   p16e2_t *b,   p16e2_t *c);
extern "C" void p32e0_nfms(p32e0_t *res, p32e0_t *a,   p32e0_t *b,   p32e0_t *c);
extern "C" void p32e1_nfms(p32e1_t *res, p32e1_t *a,   p32e1_t *b,   p32e1_t *c);
extern "C" void p32e2_nfms(p32e2_t *res, p32e2_t *a,   p32e2_t *b,   p32e2_t *c);
extern "C" void p32e3_nfms(p32e3_t *res, p32e3_t *a,   p32e3_t *b,   p32e3_t *c);

extern "C" p8e0_t p8e0_fas(p8e0_t a, p8e0_t b, p8e0_t c);
extern "C" p8e1_t p8e1_fas(p8e1_t a, p8e1_t b, p8e1_t c);
extern "C" p8e2_t p8e2_fas(p8e2_t a, p8e2_t b, p8e2_t c);
extern "C" p16e0_t p16e0_fas(p16e0_t a, p16e0_t b, p16e0_t c);
extern "C" p16e1_t p16e1_fas(p16e1_t a, p16e1_t b, p16e1_t c);
extern "C" p16e2_t p16e2_fas(p16e2_t a, p16e2_t b, p16e2_t c);
extern "C" p32e0_t p32e0_fas(p32e0_t a, p32e0_t b, p32e0_t c);
extern "C" p32e1_t p32e1_fas(p32e1_t a, p32e1_t b, p32e1_t c);
extern "C" p32e2_t p32e2_fas(p32e2_t a, p32e2_t b, p32e2_t c);
extern "C" p32e3_t p32e3_fas(p32e3_t a, p32e3_t b, p32e3_t c);

extern "C" p8e0_t p8e0_fcp(p8e0_t a, p8e0_t b, p8e0_t c, p8e0_t d);
extern "C" p8e1_t p8e1_fcp(p8e1_t a, p8e1_t b, p8e1_t c, p8e1_t d);
extern "C" p8e2_t p8e2_fcp(p8e2_t a, p8e2_t b, p8e2_t c, p8e2_t d);
extern "C" p16e0_t p16e0_fcp(p16e0_t a, p16e0_t b, p16e0_t c, p16e0_t d);
extern "C" p16e1_t p16e1_fcp(p16e1_t a, p16e1_t b, p16e1_t c, p16e1_t d);
extern "C" p16e2_t p16e2_fcp(p16e2_t a, p16e2_t b, p16e2_t c, p16e2_t d);
extern "C" p32e0_t p32e0_fcp(p32e0_t a, p32e0_t b, p32e0_t c, p32e0_t d);
extern "C" p32e1_t p32e1_fcp(p32e1_t a, p32e1_t b, p32e1_t c, p32e1_t d);
extern "C" p32e2_t p32e2_fcp(p32e2_t a, p32e2_t b, p32e2_t c, p32e2_t d);
extern "C" p32e3_t p32e3_fcp(p32e3_t a, p32e3_t b, p32e3_t c, p32e3_t d);

extern "C" p8e0_t p8e0_fdp(fdp_cache8e0_t *fc, p8e0_t a, p8e0_t b);
extern "C" p8e1_t p8e1_fdp(fdp_cache8e1_t *fc, p8e1_t a, p8e1_t b);
extern "C" p8e2_t p8e2_fdp(fdp_cache8e2_t *fc, p8e2_t a, p8e2_t b);
extern "C" p16e0_t p16e0_fdp(fdp_cache16e0_t *fc, p16e0_t a, p16e0_t b);
extern "C" p16e1_t p16e1_fdp(fdp_cache16e1_t *fc, p16e1_t a, p16e1_t b);
extern "C" p16e2_t p16e2_fdp(fdp_cache16e2_t *fc, p16e2_t a, p16e2_t b);
extern "C" p32e0_t p32e0_fdp(fdp_cache32e0_t *fc, p32e0_t a, p32e0_t b);
extern "C" p32e1_t p32e1_fdp(fdp_cache32e1_t *fc, p32e1_t a, p32e1_t b);
extern "C" p32e2_t p32e2_fdp(fdp_cache32e2_t *fc, p32e2_t a, p32e2_t b);
extern "C" p32e3_t p32e3_fdp(fdp_cache32e3_t *fc, p32e3_t a, p32e3_t b);

extern "C" void p8e0_dpi(fdp_cache8e0_t *fc);
extern "C" void p8e1_dpi(fdp_cache8e1_t *fc);
extern "C" void p8e2_dpi(fdp_cache8e2_t *fc);
extern "C" void p16e0_dpi(fdp_cache16e0_t *fc);
extern "C" void p16e1_dpi(fdp_cache16e1_t *fc);
extern "C" void p16e2_dpi(fdp_cache16e2_t *fc);
extern "C" void p32e0_dpi(fdp_cache32e0_t *fc);
extern "C" void p32e1_dpi(fdp_cache32e1_t *fc);
extern "C" void p32e2_dpi(fdp_cache32e2_t *fc);
extern "C" void p32e3_dpi(fdp_cache32e3_t *fc);

extern "C" fdp_cache8e0_t* newcache8e0();
extern "C" fdp_cache8e1_t* newcache8e1();
extern "C" fdp_cache8e2_t* newcache8e2();
extern "C" fdp_cache16e0_t* newcache16e0();
extern "C" fdp_cache16e1_t* newcache16e1();
extern "C" fdp_cache16e2_t* newcache16e2();
extern "C" fdp_cache32e0_t* newcache32e0();
extern "C" fdp_cache32e1_t* newcache32e1();
extern "C" fdp_cache32e2_t* newcache32e2();
extern "C" fdp_cache32e3_t* newcache32e3();

extern "C" p8e0_t p8e0_sqrt(p8e0_t x);
extern "C" p8e1_t p8e1_sqrt(p8e1_t x);
extern "C" p8e2_t p8e2_sqrt(p8e2_t x);
extern "C" p16e0_t p16e0_sqrt(p16e0_t x);
extern "C" p16e1_t p16e1_sqrt(p16e1_t x);
extern "C" p16e2_t p16e2_sqrt(p16e2_t x);
extern "C" p32e0_t p32e0_sqrt(p32e0_t x);
extern "C" p32e1_t p32e1_sqrt(p32e1_t x);
extern "C" p32e2_t p32e2_sqrt(p32e2_t x);
extern "C" p32e3_t p32e3_sqrt(p32e3_t x);

extern "C" p8e0_t p8e0_log10(p8e0_t x);
extern "C" p8e1_t p8e1_log10(p8e1_t x);
extern "C" p8e2_t p8e2_log10(p8e2_t x);
extern "C" p16e0_t p16e0_log10(p16e0_t x);
extern "C" p16e1_t p16e1_log10(p16e1_t x);
extern "C" p16e2_t p16e2_log10(p16e2_t x);
extern "C" p32e0_t p32e0_log10(p32e0_t x);
extern "C" p32e1_t p32e1_log10(p32e1_t x);
extern "C" p32e2_t p32e2_log10(p32e2_t x);
extern "C" p32e3_t p32e3_log10(p32e3_t x);

extern "C" p8e0_t p8e0_log(p8e0_t x);
extern "C" p8e1_t p8e1_log(p8e1_t x);
extern "C" p8e2_t p8e2_log(p8e2_t x);
extern "C" p16e0_t p16e0_log(p16e0_t x);
extern "C" p16e1_t p16e1_log(p16e1_t x);
extern "C" p16e2_t p16e2_log(p16e2_t x);
extern "C" p32e0_t p32e0_log(p32e0_t x);
extern "C" p32e1_t p32e1_log(p32e1_t x);
extern "C" p32e2_t p32e2_log(p32e2_t x);
extern "C" p32e3_t p32e3_log(p32e3_t x);

extern "C" p8e0_t p8e0_exp(p8e0_t x);
extern "C" p8e1_t p8e1_exp(p8e1_t x);
extern "C" p8e2_t p8e2_exp(p8e2_t x);
extern "C" p16e0_t p16e0_exp(p16e0_t x);
extern "C" p16e1_t p16e1_exp(p16e1_t x);
extern "C" p16e2_t p16e2_exp(p16e2_t x);
extern "C" p32e0_t p32e0_exp(p32e0_t x);
extern "C" p32e1_t p32e1_exp(p32e1_t x);
extern "C" p32e2_t p32e2_exp(p32e2_t x);
extern "C" p32e3_t p32e3_exp(p32e3_t x);

extern "C" p8e0_t p8e0_pow(p8e0_t a, p8e0_t b);
extern "C" p8e1_t p8e1_pow(p8e1_t a, p8e1_t b);
extern "C" p8e2_t p8e2_pow(p8e2_t a, p8e2_t b);
extern "C" p16e0_t p16e0_pow(p16e0_t a, p16e0_t b);
extern "C" p16e1_t p16e1_pow(p16e1_t a, p16e1_t b);
extern "C" p16e2_t p16e2_pow(p16e2_t a, p16e2_t b);
extern "C" p32e0_t p32e0_pow(p32e0_t a, p32e0_t b);
extern "C" p32e1_t p32e1_pow(p32e1_t a, p32e1_t b);
extern "C" p32e2_t p32e2_pow(p32e2_t a, p32e2_t b);
extern "C" p32e3_t p32e3_pow(p32e3_t a, p32e3_t b);

extern "C" p8e0_t p8e0_logx(p8e0_t a, p8e0_t b);
extern "C" p8e1_t p8e1_logx(p8e1_t a, p8e1_t b);
extern "C" p8e2_t p8e2_logx(p8e2_t a, p8e2_t b);
extern "C" p16e0_t p16e0_logx(p16e0_t a, p16e0_t b);
extern "C" p16e1_t p16e1_logx(p16e1_t a, p16e1_t b);
extern "C" p16e2_t p16e2_logx(p16e2_t a, p16e2_t b);
extern "C" p32e0_t p32e0_logx(p32e0_t a, p32e0_t b);
extern "C" p32e1_t p32e1_logx(p32e1_t a, p32e1_t b);
extern "C" p32e2_t p32e2_logx(p32e2_t a, p32e2_t b);
extern "C" p32e3_t p32e3_logx(p32e3_t a, p32e3_t b);

extern "C" p8e0_t p8e0_sin(p8e0_t x);
extern "C" p8e1_t p8e1_sin(p8e1_t x);
extern "C" p8e2_t p8e2_sin(p8e2_t x);
extern "C" p16e0_t p16e0_sin(p16e0_t x);
extern "C" p16e1_t p16e1_sin(p16e1_t x);
extern "C" p16e2_t p16e2_sin(p16e2_t x);
extern "C" p32e0_t p32e0_sin(p32e0_t x);
extern "C" p32e1_t p32e1_sin(p32e1_t x);
extern "C" p32e2_t p32e2_sin(p32e2_t x);
extern "C" p32e3_t p32e3_sin(p32e3_t x);

extern "C" p8e0_t p8e0_cos(p8e0_t x);
extern "C" p8e1_t p8e1_cos(p8e1_t x);
extern "C" p8e2_t p8e2_cos(p8e2_t x);
extern "C" p16e0_t p16e0_cos(p16e0_t x);
extern "C" p16e1_t p16e1_cos(p16e1_t x);
extern "C" p16e2_t p16e2_cos(p16e2_t x);
extern "C" p32e0_t p32e0_cos(p32e0_t x);
extern "C" p32e1_t p32e1_cos(p32e1_t x);
extern "C" p32e2_t p32e2_cos(p32e2_t x);
extern "C" p32e3_t p32e3_cos(p32e3_t x);

extern "C" p8e0_t p8e0_atan(p8e0_t x);
extern "C" p8e1_t p8e1_atan(p8e1_t x);
extern "C" p8e2_t p8e2_atan(p8e2_t x);
extern "C" p16e0_t p16e0_atan(p16e0_t x);
extern "C" p16e1_t p16e1_atan(p16e1_t x);
extern "C" p16e2_t p16e2_atan(p16e2_t x);
extern "C" p32e0_t p32e0_atan(p32e0_t x);
extern "C" p32e1_t p32e1_atan(p32e1_t x);
extern "C" p32e2_t p32e2_atan(p32e2_t x);
extern "C" p32e3_t p32e3_atan(p32e3_t x);

extern "C" p8e0_t p8e0_atan2(p8e0_t a, p8e0_t b);
extern "C" p8e1_t p8e1_atan2(p8e1_t a, p8e1_t b);
extern "C" p8e2_t p8e2_atan2(p8e2_t a, p8e2_t b);
extern "C" p16e0_t p16e0_atan2(p16e0_t a, p16e0_t b);
extern "C" p16e1_t p16e1_atan2(p16e1_t a, p16e1_t b);
extern "C" p16e2_t p16e2_atan2(p16e2_t a, p16e2_t b);
extern "C" p32e0_t p32e0_atan2(p32e0_t a, p32e0_t b);
extern "C" p32e1_t p32e1_atan2(p32e1_t a, p32e1_t b);
extern "C" p32e2_t p32e2_atan2(p32e2_t a, p32e2_t b);
extern "C" p32e3_t p32e3_atan2(p32e3_t a, p32e3_t b);

#endif