
#include "include/posit_conv.h"
#include "include/posit_ops.h"
#include "include/posit_ops_errno.h"
#include "include/P16e2.h"
#include "errno.h"
#include <stdexcept>


P16e2::P16e2(){ this->data = P16ZER; }

P16e2::P16e2(const float a){
  this->data = f_to_p16e2(a).udata;
  if (errno) {
    throw std::domain_error("attempted to construct a posit from a NaN IEEE value");
  }
}

P16e2::P16e2(const double a){
  this->data = f_to_p16e2((float) a).udata;
  if (errno) {
    throw std::domain_error("attempted to construct a posit from a NaN IEEE value");
  }
}

P16e2::P16e2(const P16e2 &a){ this->data = a.data; }

P16e2::P16e2(const p16e2_t a){ this->data = a.udata; }



P16e2 P16e2::operator -() const{
  P16e2 res;
  res.data = -(this->data);
  return res;
}

P16e2 &P16e2::operator *=(const P16e2 rhs){
  p16e2_t res;

  res = p16e2_mul_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator *=");
  }

  this->data = res.udata;
  return (*this);
}

P16e2 P16e2::operator *(const P16e2 rhs) const{
  P16e2 res;          //create a return value from the stack.

  res = p16e2_t(p16e2_mul_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator *");
  }

  return P16e2(res);
}

P16e2 &P16e2::operator -=(const P16e2 rhs){
  p16e2_t res;

  res = p16e2_sub_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator -=");
  }

  this->data = res.udata;
  return (*this);
}

P16e2 P16e2::operator -(const P16e2 rhs) const{
  P16e2 res;          //create a return value from the stack.

  res = p16e2_t(p16e2_sub_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator -");
  }

  return P16e2(res);
}

P16e2 &P16e2::operator +=(const P16e2 rhs){
  p16e2_t res;

  res = p16e2_add_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator +=");
  }

  this->data = res.udata;
  return (*this);
}

P16e2 P16e2::operator +(const P16e2 rhs) const{
  P16e2 res;          //create a return value from the stack.

  res = p16e2_t(p16e2_add_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator +");
  }

  return P16e2(res);
}

P16e2 &P16e2::operator /=(const P16e2 rhs){
  p16e2_t res;

  res = p16e2_div_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator /=");
  }

  this->data = res.udata;
  return (*this);
}

P16e2 P16e2::operator /(const P16e2 rhs) const{
  P16e2 res;          //create a return value from the stack.

  res = p16e2_t(p16e2_div_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator /");
  }

  return P16e2(res);
}


bool P16e2::operator >(const P16e2 rhs) const{
  p16e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e2_gt(lhs_p, rhs_p);
}


bool P16e2::operator >=(const P16e2 rhs) const{
  p16e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e2_gte(lhs_p, rhs_p);
}


bool P16e2::operator <=(const P16e2 rhs) const{
  p16e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e2_lte(lhs_p, rhs_p);
}


bool P16e2::operator <(const P16e2 rhs) const{
  p16e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e2_lt(lhs_p, rhs_p);
}



P16e2::operator float() const{
  return (float) p16e2_to_f((p16e2_t)(*this));
}

P16e2::operator double() const{
  return (double) p16e2_to_f((p16e2_t)(*this));
}

P16e2::operator p16e2_t() const{
  p16e2_t res;
  res.udata = this->data;
  return res;
}



P16e2 mulinv (const P16e2 x){
  p16e2_t res;

  res = p16e2_mulinv_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function mulinv");
  }

  P16e2 res_c(res);
  return res_c;
}


P16e2 log2 (const P16e2 x){
  p16e2_t res;

  res = p16e2_log2_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log2");
  }

  P16e2 res_c(res);
  return res_c;
}


P16e2 exp2 (const P16e2 x){
  p16e2_t res;

  res = p16e2_exp2_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function exp2");
  }

  P16e2 res_c(res);
  return res_c;
}


P16e2 sqrt (const P16e2 x){
  p16e2_t res;

  res = p16e2_sqrt_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function sqrt");
  }

  P16e2 res_c(res);
  return res_c;
}


P16e2 log1p (const P16e2 x){
  p16e2_t res;

  res = p16e2_log1p_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log1p");
  }

  P16e2 res_c(res);
  return res_c;
}


P16e2 log (const P16e2 x){
  p16e2_t res;

  res = p16e2_log_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log");
  }

  P16e2 res_c(res);
  return res_c;
}


P16e2 log10 (const P16e2 x){
  p16e2_t res;

  res = p16e2_log10_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log10");
  }

  P16e2 res_c(res);
  return res_c;
}


P16e2 exp (const P16e2 x){
  p16e2_t res;

  res = p16e2_exp_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function exp");
  }

  P16e2 res_c(res);
  return res_c;
}


P16e2 sin (const P16e2 x){
  p16e2_t res;

  res = p16e2_sin_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function sin");
  }

  P16e2 res_c(res);
  return res_c;
}


P16e2 cos (const P16e2 x){
  p16e2_t res;

  res = p16e2_cos_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function cos");
  }

  P16e2 res_c(res);
  return res_c;
}


P16e2 atan (const P16e2 x){
  p16e2_t res;

  res = p16e2_atan_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function atan");
  }

  P16e2 res_c(res);
  return res_c;
}



P16e2 pow (const P16e2 a, const P16e2 b){
  p16e2_t res;

  res = p16e2_pow_e(a, b);
  if (errno) {
    throw std::domain_error("NaN value obtained in function pow");
  }

  P16e2 res_c(res);
  return res_c;
}


P16e2 atan2 (const P16e2 a, const P16e2 b){
  p16e2_t res;

  res = p16e2_atan2_e(a, b);
  if (errno) {
    throw std::domain_error("NaN value obtained in function atan2");
  }

  P16e2 res_c(res);
  return res_c;
}



P16e2 fma(const P16e2 a, const P16e2 b, const P16e2 c){
  p16e2_t res;

  res = p16e2_fma_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function fma");
  }

  P16e2 res_c(res);
  return res_c;
}


P16e2 fms(const P16e2 a, const P16e2 b, const P16e2 c){
  p16e2_t res;

  res = p16e2_fms_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function fms");
  }

  P16e2 res_c(res);
  return res_c;
}


P16e2 nfma(const P16e2 a, const P16e2 b, const P16e2 c){
  p16e2_t res;

  res = p16e2_nfma_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function nfma");
  }

  P16e2 res_c(res);
  return res_c;
}


P16e2 nfms(const P16e2 a, const P16e2 b, const P16e2 c){
  p16e2_t res;

  res = p16e2_nfms_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function nfms");
  }

  P16e2 res_c(res);
  return res_c;
}

