
#include "include/posit_conv.h"
#include "include/posit_ops.h"
#include "include/posit_ops_errno.h"
#include "include/P16e0.h"
#include "errno.h"
#include <stdexcept>


P16e0::P16e0(){ this->data = P16ZER; }

P16e0::P16e0(const float a){
  this->data = f_to_p16e0(a).udata;
  if (errno) {
    throw std::domain_error("attempted to construct a posit from a NaN IEEE value");
  }
}

P16e0::P16e0(const double a){
  this->data = f_to_p16e0((float) a).udata;
  if (errno) {
    throw std::domain_error("attempted to construct a posit from a NaN IEEE value");
  }
}

P16e0::P16e0(const P16e0 &a){ this->data = a.data; }

P16e0::P16e0(const p16e0_t a){ this->data = a.udata; }



P16e0 P16e0::operator -() const{
  P16e0 res;
  res.data = -(this->data);
  return res;
}

P16e0 &P16e0::operator *=(const P16e0 rhs){
  p16e0_t res;

  res = p16e0_mul_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator *=");
  }

  this->data = res.udata;
  return (*this);
}

P16e0 P16e0::operator *(const P16e0 rhs) const{
  P16e0 res;          //create a return value from the stack.

  res = p16e0_t(p16e0_mul_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator *");
  }

  return P16e0(res);
}

P16e0 &P16e0::operator -=(const P16e0 rhs){
  p16e0_t res;

  res = p16e0_sub_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator -=");
  }

  this->data = res.udata;
  return (*this);
}

P16e0 P16e0::operator -(const P16e0 rhs) const{
  P16e0 res;          //create a return value from the stack.

  res = p16e0_t(p16e0_sub_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator -");
  }

  return P16e0(res);
}

P16e0 &P16e0::operator +=(const P16e0 rhs){
  p16e0_t res;

  res = p16e0_add_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator +=");
  }

  this->data = res.udata;
  return (*this);
}

P16e0 P16e0::operator +(const P16e0 rhs) const{
  P16e0 res;          //create a return value from the stack.

  res = p16e0_t(p16e0_add_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator +");
  }

  return P16e0(res);
}

P16e0 &P16e0::operator /=(const P16e0 rhs){
  p16e0_t res;

  res = p16e0_div_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator /=");
  }

  this->data = res.udata;
  return (*this);
}

P16e0 P16e0::operator /(const P16e0 rhs) const{
  P16e0 res;          //create a return value from the stack.

  res = p16e0_t(p16e0_div_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator /");
  }

  return P16e0(res);
}


bool P16e0::operator >(const P16e0 rhs) const{
  p16e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e0_gt(lhs_p, rhs_p);
}


bool P16e0::operator >=(const P16e0 rhs) const{
  p16e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e0_gte(lhs_p, rhs_p);
}


bool P16e0::operator <=(const P16e0 rhs) const{
  p16e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e0_lte(lhs_p, rhs_p);
}


bool P16e0::operator <(const P16e0 rhs) const{
  p16e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e0_lt(lhs_p, rhs_p);
}



P16e0::operator float() const{
  return (float) p16e0_to_f((p16e0_t)(*this));
}

P16e0::operator double() const{
  return (double) p16e0_to_f((p16e0_t)(*this));
}

P16e0::operator p16e0_t() const{
  p16e0_t res;
  res.udata = this->data;
  return res;
}



P16e0 mulinv (const P16e0 x){
  p16e0_t res;

  res = p16e0_mulinv_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function mulinv");
  }

  P16e0 res_c(res);
  return res_c;
}


P16e0 log2 (const P16e0 x){
  p16e0_t res;

  res = p16e0_log2_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log2");
  }

  P16e0 res_c(res);
  return res_c;
}


P16e0 exp2 (const P16e0 x){
  p16e0_t res;

  res = p16e0_exp2_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function exp2");
  }

  P16e0 res_c(res);
  return res_c;
}


P16e0 sqrt (const P16e0 x){
  p16e0_t res;

  res = p16e0_sqrt_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function sqrt");
  }

  P16e0 res_c(res);
  return res_c;
}


P16e0 log1p (const P16e0 x){
  p16e0_t res;

  res = p16e0_log1p_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log1p");
  }

  P16e0 res_c(res);
  return res_c;
}


P16e0 log (const P16e0 x){
  p16e0_t res;

  res = p16e0_log_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log");
  }

  P16e0 res_c(res);
  return res_c;
}


P16e0 log10 (const P16e0 x){
  p16e0_t res;

  res = p16e0_log10_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log10");
  }

  P16e0 res_c(res);
  return res_c;
}


P16e0 exp (const P16e0 x){
  p16e0_t res;

  res = p16e0_exp_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function exp");
  }

  P16e0 res_c(res);
  return res_c;
}


P16e0 sin (const P16e0 x){
  p16e0_t res;

  res = p16e0_sin_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function sin");
  }

  P16e0 res_c(res);
  return res_c;
}


P16e0 cos (const P16e0 x){
  p16e0_t res;

  res = p16e0_cos_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function cos");
  }

  P16e0 res_c(res);
  return res_c;
}


P16e0 atan (const P16e0 x){
  p16e0_t res;

  res = p16e0_atan_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function atan");
  }

  P16e0 res_c(res);
  return res_c;
}



P16e0 pow (const P16e0 a, const P16e0 b){
  p16e0_t res;

  res = p16e0_pow_e(a, b);
  if (errno) {
    throw std::domain_error("NaN value obtained in function pow");
  }

  P16e0 res_c(res);
  return res_c;
}


P16e0 atan2 (const P16e0 a, const P16e0 b){
  p16e0_t res;

  res = p16e0_atan2_e(a, b);
  if (errno) {
    throw std::domain_error("NaN value obtained in function atan2");
  }

  P16e0 res_c(res);
  return res_c;
}



P16e0 fma(const P16e0 a, const P16e0 b, const P16e0 c){
  p16e0_t res;

  res = p16e0_fma_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function fma");
  }

  P16e0 res_c(res);
  return res_c;
}


P16e0 fms(const P16e0 a, const P16e0 b, const P16e0 c){
  p16e0_t res;

  res = p16e0_fms_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function fms");
  }

  P16e0 res_c(res);
  return res_c;
}


P16e0 nfma(const P16e0 a, const P16e0 b, const P16e0 c){
  p16e0_t res;

  res = p16e0_nfma_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function nfma");
  }

  P16e0 res_c(res);
  return res_c;
}


P16e0 nfms(const P16e0 a, const P16e0 b, const P16e0 c){
  p16e0_t res;

  res = p16e0_nfms_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function nfms");
  }

  P16e0 res_c(res);
  return res_c;
}

