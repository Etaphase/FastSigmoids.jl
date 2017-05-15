#include "include/posit.h"
#include "include/posit_conv.h"

extern "C" p8e0_t p8e0_sqrt(p8e0_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p8e0(sqrt(p8e0_to_f(x)));
}
extern "C" p8e1_t p8e1_sqrt(p8e1_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p8e1(sqrt(p8e1_to_f(x)));
}
extern "C" p8e2_t p8e2_sqrt(p8e2_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p8e2(sqrt(p8e2_to_f(x)));
}
extern "C" p16e0_t p16e0_sqrt(p16e0_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p16e0(sqrt(p16e0_to_f(x)));
}
extern "C" p16e1_t p16e1_sqrt(p16e1_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p16e1(sqrt(p16e1_to_f(x)));
}
extern "C" p16e2_t p16e2_sqrt(p16e2_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p16e2(sqrt(p16e2_to_f(x)));
}
extern "C" p32e0_t p32e0_sqrt(p32e0_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e0(sqrt(p32e0_to_f(x)));
}
extern "C" p32e1_t p32e1_sqrt(p32e1_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e1(sqrt(p32e1_to_f(x)));
}
extern "C" p32e2_t p32e2_sqrt(p32e2_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e2(sqrt(p32e2_to_f(x)));
}
extern "C" p32e3_t p32e3_sqrt(p32e3_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e3(sqrt(p32e3_to_f(x)));
}

extern "C" p8e0_t p8e0_log1p(p8e0_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p8e0(log1p(p8e0_to_f(x)));
}
extern "C" p8e1_t p8e1_log1p(p8e1_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p8e1(log1p(p8e1_to_f(x)));
}
extern "C" p8e2_t p8e2_log1p(p8e2_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p8e2(log1p(p8e2_to_f(x)));
}
extern "C" p16e0_t p16e0_log1p(p16e0_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p16e0(log1p(p16e0_to_f(x)));
}
extern "C" p16e1_t p16e1_log1p(p16e1_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p16e1(log1p(p16e1_to_f(x)));
}
extern "C" p16e2_t p16e2_log1p(p16e2_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p16e2(log1p(p16e2_to_f(x)));
}
extern "C" p32e0_t p32e0_log1p(p32e0_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e0(log1p(p32e0_to_f(x)));
}
extern "C" p32e1_t p32e1_log1p(p32e1_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e1(log1p(p32e1_to_f(x)));
}
extern "C" p32e2_t p32e2_log1p(p32e2_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e2(log1p(p32e2_to_f(x)));
}
extern "C" p32e3_t p32e3_log1p(p32e3_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e3(log1p(p32e3_to_f(x)));
}

extern "C" p8e0_t p8e0_log(p8e0_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p8e0(log(p8e0_to_f(x)));
}
extern "C" p8e1_t p8e1_log(p8e1_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p8e1(log(p8e1_to_f(x)));
}
extern "C" p8e2_t p8e2_log(p8e2_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p8e2(log(p8e2_to_f(x)));
}
extern "C" p16e0_t p16e0_log(p16e0_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p16e0(log(p16e0_to_f(x)));
}
extern "C" p16e1_t p16e1_log(p16e1_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p16e1(log(p16e1_to_f(x)));
}
extern "C" p16e2_t p16e2_log(p16e2_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p16e2(log(p16e2_to_f(x)));
}
extern "C" p32e0_t p32e0_log(p32e0_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e0(log(p32e0_to_f(x)));
}
extern "C" p32e1_t p32e1_log(p32e1_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e1(log(p32e1_to_f(x)));
}
extern "C" p32e2_t p32e2_log(p32e2_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e2(log(p32e2_to_f(x)));
}
extern "C" p32e3_t p32e3_log(p32e3_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e3(log(p32e3_to_f(x)));
}

extern "C" p8e0_t p8e0_log10(p8e0_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p8e0(log10(p8e0_to_f(x)));
}
extern "C" p8e1_t p8e1_log10(p8e1_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p8e1(log10(p8e1_to_f(x)));
}
extern "C" p8e2_t p8e2_log10(p8e2_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p8e2(log10(p8e2_to_f(x)));
}
extern "C" p16e0_t p16e0_log10(p16e0_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p16e0(log10(p16e0_to_f(x)));
}
extern "C" p16e1_t p16e1_log10(p16e1_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p16e1(log10(p16e1_to_f(x)));
}
extern "C" p16e2_t p16e2_log10(p16e2_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p16e2(log10(p16e2_to_f(x)));
}
extern "C" p32e0_t p32e0_log10(p32e0_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e0(log10(p32e0_to_f(x)));
}
extern "C" p32e1_t p32e1_log10(p32e1_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e1(log10(p32e1_to_f(x)));
}
extern "C" p32e2_t p32e2_log10(p32e2_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e2(log10(p32e2_to_f(x)));
}
extern "C" p32e3_t p32e3_log10(p32e3_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e3(log10(p32e3_to_f(x)));
}

extern "C" p8e0_t p8e0_exp(p8e0_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p8e0(exp(p8e0_to_f(x)));
}
extern "C" p8e1_t p8e1_exp(p8e1_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p8e1(exp(p8e1_to_f(x)));
}
extern "C" p8e2_t p8e2_exp(p8e2_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p8e2(exp(p8e2_to_f(x)));
}
extern "C" p16e0_t p16e0_exp(p16e0_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p16e0(exp(p16e0_to_f(x)));
}
extern "C" p16e1_t p16e1_exp(p16e1_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p16e1(exp(p16e1_to_f(x)));
}
extern "C" p16e2_t p16e2_exp(p16e2_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p16e2(exp(p16e2_to_f(x)));
}
extern "C" p32e0_t p32e0_exp(p32e0_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e0(exp(p32e0_to_f(x)));
}
extern "C" p32e1_t p32e1_exp(p32e1_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e1(exp(p32e1_to_f(x)));
}
extern "C" p32e2_t p32e2_exp(p32e2_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e2(exp(p32e2_to_f(x)));
}
extern "C" p32e3_t p32e3_exp(p32e3_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e3(exp(p32e3_to_f(x)));
}

extern "C" p8e0_t p8e0_pow(p8e0_t a, p8e0_t b){
  if ( a.udata == 0 && b.udata == 0 ){ throw_nan_jmp(); }

  return f_to_p8e0(pow(p8e0_to_f(a),p8e0_to_f(b)));
}
extern "C" p8e1_t p8e1_pow(p8e1_t a, p8e1_t b){
  if ( a.udata == 0 && b.udata == 0 ){ throw_nan_jmp(); }

  return f_to_p8e1(pow(p8e1_to_f(a),p8e1_to_f(b)));
}
extern "C" p8e2_t p8e2_pow(p8e2_t a, p8e2_t b){
  if ( a.udata == 0 && b.udata == 0 ){ throw_nan_jmp(); }

  return f_to_p8e2(pow(p8e2_to_f(a),p8e2_to_f(b)));
}
extern "C" p16e0_t p16e0_pow(p16e0_t a, p16e0_t b){
  if ( a.udata == 0 && b.udata == 0 ){ throw_nan_jmp(); }

  return f_to_p16e0(pow(p16e0_to_f(a),p16e0_to_f(b)));
}
extern "C" p16e1_t p16e1_pow(p16e1_t a, p16e1_t b){
  if ( a.udata == 0 && b.udata == 0 ){ throw_nan_jmp(); }

  return f_to_p16e1(pow(p16e1_to_f(a),p16e1_to_f(b)));
}
extern "C" p16e2_t p16e2_pow(p16e2_t a, p16e2_t b){
  if ( a.udata == 0 && b.udata == 0 ){ throw_nan_jmp(); }

  return f_to_p16e2(pow(p16e2_to_f(a),p16e2_to_f(b)));
}
extern "C" p32e0_t p32e0_pow(p32e0_t a, p32e0_t b){
  if ( a.udata == 0 && b.udata == 0 ){ throw_nan_jmp(); }

  return f_to_p32e0(pow(p32e0_to_f(a),p32e0_to_f(b)));
}
extern "C" p32e1_t p32e1_pow(p32e1_t a, p32e1_t b){
  if ( a.udata == 0 && b.udata == 0 ){ throw_nan_jmp(); }

  return f_to_p32e1(pow(p32e1_to_f(a),p32e1_to_f(b)));
}
extern "C" p32e2_t p32e2_pow(p32e2_t a, p32e2_t b){
  if ( a.udata == 0 && b.udata == 0 ){ throw_nan_jmp(); }

  return f_to_p32e2(pow(p32e2_to_f(a),p32e2_to_f(b)));
}
extern "C" p32e3_t p32e3_pow(p32e3_t a, p32e3_t b){
  if ( a.udata == 0 && b.udata == 0 ){ throw_nan_jmp(); }

  return f_to_p32e3(pow(p32e3_to_f(a),p32e3_to_f(b)));
}












extern "C" p8e0_t p8e0_sin(p8e0_t x){
  return f_to_p8e0(sin(p8e0_to_f(x)));
}
extern "C" p8e1_t p8e1_sin(p8e1_t x){
  return f_to_p8e1(sin(p8e1_to_f(x)));
}
extern "C" p8e2_t p8e2_sin(p8e2_t x){
  return f_to_p8e2(sin(p8e2_to_f(x)));
}
extern "C" p16e0_t p16e0_sin(p16e0_t x){
  return f_to_p16e0(sin(p16e0_to_f(x)));
}
extern "C" p16e1_t p16e1_sin(p16e1_t x){
  return f_to_p16e1(sin(p16e1_to_f(x)));
}
extern "C" p16e2_t p16e2_sin(p16e2_t x){
  return f_to_p16e2(sin(p16e2_to_f(x)));
}
extern "C" p32e0_t p32e0_sin(p32e0_t x){
  return f_to_p32e0(sin(p32e0_to_f(x)));
}
extern "C" p32e1_t p32e1_sin(p32e1_t x){
  return f_to_p32e1(sin(p32e1_to_f(x)));
}
extern "C" p32e2_t p32e2_sin(p32e2_t x){
  return f_to_p32e2(sin(p32e2_to_f(x)));
}
extern "C" p32e3_t p32e3_sin(p32e3_t x){
  return f_to_p32e3(sin(p32e3_to_f(x)));
}

extern "C" p8e0_t p8e0_cos(p8e0_t x){
  return f_to_p8e0(cos(p8e0_to_f(x)));
}
extern "C" p8e1_t p8e1_cos(p8e1_t x){
  return f_to_p8e1(cos(p8e1_to_f(x)));
}
extern "C" p8e2_t p8e2_cos(p8e2_t x){
  return f_to_p8e2(cos(p8e2_to_f(x)));
}
extern "C" p16e0_t p16e0_cos(p16e0_t x){
  return f_to_p16e0(cos(p16e0_to_f(x)));
}
extern "C" p16e1_t p16e1_cos(p16e1_t x){
  return f_to_p16e1(cos(p16e1_to_f(x)));
}
extern "C" p16e2_t p16e2_cos(p16e2_t x){
  return f_to_p16e2(cos(p16e2_to_f(x)));
}
extern "C" p32e0_t p32e0_cos(p32e0_t x){
  return f_to_p32e0(cos(p32e0_to_f(x)));
}
extern "C" p32e1_t p32e1_cos(p32e1_t x){
  return f_to_p32e1(cos(p32e1_to_f(x)));
}
extern "C" p32e2_t p32e2_cos(p32e2_t x){
  return f_to_p32e2(cos(p32e2_to_f(x)));
}
extern "C" p32e3_t p32e3_cos(p32e3_t x){
  return f_to_p32e3(cos(p32e3_to_f(x)));
}

extern "C" p8e0_t p8e0_atan(p8e0_t x){
  return f_to_p8e0(atan(p8e0_to_f(x)));
}
extern "C" p8e1_t p8e1_atan(p8e1_t x){
  return f_to_p8e1(atan(p8e1_to_f(x)));
}
extern "C" p8e2_t p8e2_atan(p8e2_t x){
  return f_to_p8e2(atan(p8e2_to_f(x)));
}
extern "C" p16e0_t p16e0_atan(p16e0_t x){
  return f_to_p16e0(atan(p16e0_to_f(x)));
}
extern "C" p16e1_t p16e1_atan(p16e1_t x){
  return f_to_p16e1(atan(p16e1_to_f(x)));
}
extern "C" p16e2_t p16e2_atan(p16e2_t x){
  return f_to_p16e2(atan(p16e2_to_f(x)));
}
extern "C" p32e0_t p32e0_atan(p32e0_t x){
  return f_to_p32e0(atan(p32e0_to_f(x)));
}
extern "C" p32e1_t p32e1_atan(p32e1_t x){
  return f_to_p32e1(atan(p32e1_to_f(x)));
}
extern "C" p32e2_t p32e2_atan(p32e2_t x){
  return f_to_p32e2(atan(p32e2_to_f(x)));
}
extern "C" p32e3_t p32e3_atan(p32e3_t x){
  return f_to_p32e3(atan(p32e3_to_f(x)));
}

extern "C" p8e0_t p8e0_atan2(p8e0_t a, p8e0_t b){
  return f_to_p8e0(atan2(p8e0_to_f(a),p8e0_to_f(b)));
}
extern "C" p8e1_t p8e1_atan2(p8e1_t a, p8e1_t b){
  return f_to_p8e1(atan2(p8e1_to_f(a),p8e1_to_f(b)));
}
extern "C" p8e2_t p8e2_atan2(p8e2_t a, p8e2_t b){
  return f_to_p8e2(atan2(p8e2_to_f(a),p8e2_to_f(b)));
}
extern "C" p16e0_t p16e0_atan2(p16e0_t a, p16e0_t b){
  return f_to_p16e0(atan2(p16e0_to_f(a),p16e0_to_f(b)));
}
extern "C" p16e1_t p16e1_atan2(p16e1_t a, p16e1_t b){
  return f_to_p16e1(atan2(p16e1_to_f(a),p16e1_to_f(b)));
}
extern "C" p16e2_t p16e2_atan2(p16e2_t a, p16e2_t b){
  return f_to_p16e2(atan2(p16e2_to_f(a),p16e2_to_f(b)));
}
extern "C" p32e0_t p32e0_atan2(p32e0_t a, p32e0_t b){
  return f_to_p32e0(atan2(p32e0_to_f(a),p32e0_to_f(b)));
}
extern "C" p32e1_t p32e1_atan2(p32e1_t a, p32e1_t b){
  return f_to_p32e1(atan2(p32e1_to_f(a),p32e1_to_f(b)));
}
extern "C" p32e2_t p32e2_atan2(p32e2_t a, p32e2_t b){
  return f_to_p32e2(atan2(p32e2_to_f(a),p32e2_to_f(b)));
}
extern "C" p32e3_t p32e3_atan2(p32e3_t a, p32e3_t b){
  return f_to_p32e3(atan2(p32e3_to_f(a),p32e3_to_f(b)));
}

