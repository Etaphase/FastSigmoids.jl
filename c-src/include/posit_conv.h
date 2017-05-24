#ifndef __POSIT_CONV_H
#define __POSIT_CONV_H

#include "posit.h"

#ifdef __cplusplus
extern "C" {
#endif

  float p8e0_to_f(p8e0_t pval);
  p8e0_t f_to_p8e0(float fval);
  float p8e1_to_f(p8e1_t pval);
  p8e1_t f_to_p8e1(float fval);
  float p8e2_to_f(p8e2_t pval);
  p8e2_t f_to_p8e2(float fval);

  float p16e0_to_f(p16e0_t pval);
  p16e0_t f_to_p16e0(float fval);
  float p16e1_to_f(p16e1_t pval);
  p16e1_t f_to_p16e1(float fval);
  float p16e2_to_f(p16e2_t pval);
  p16e2_t f_to_p16e2(float fval);

  double p32e0_to_f(p32e0_t pval);
  p32e0_t f_to_p32e0(double fval);
  double p32e1_to_f(p32e1_t pval);
  p32e1_t f_to_p32e1(double fval);
  double p32e2_to_f(p32e2_t pval);
  p32e2_t f_to_p32e2(double fval);
  double p32e3_to_f(p32e3_t pval);
  p32e3_t f_to_p32e3(double fval);

#ifdef __cplusplus
}
#endif
#endif
