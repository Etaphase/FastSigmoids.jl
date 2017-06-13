
#include "include/posit_conv.h"
#include "include/posit_ops.h"
#include "include/posit_ops_errno.h"
#include "include/P8e2.h"
#include "errno.h"
#include <stdexcept>


P8e2::P8e2(){ this->data = P8ZER; }

P8e2::P8e2(const float a){
  this->data = f_to_p8e2(a).udata;
  if (errno) {
    throw std::domain_error("attempted to construct a posit from a NaN IEEE value");
  }
}

P8e2::P8e2(const double a){
  this->data = f_to_p8e2((float) a).udata;
  if (errno) {
    throw std::domain_error("attempted to construct a posit from a NaN IEEE value");
  }
}

P8e2::P8e2(const P8e2 &a){ this->data = a.data; }

P8e2::P8e2(const p8e2_t a){ this->data = a.udata; }



P8e2 P8e2::operator -() const{
  P8e2 res;
  res.data = -(this->data);
  return res;
}

P8e2 &P8e2::operator *=(const P8e2 rhs){
  p8e2_t res;

  res = p8e2_mul_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator *=");
  }

  this->data = res.udata;
  return (*this);
}

P8e2 P8e2::operator *(const P8e2 rhs) const{
  P8e2 res;          //create a return value from the stack.

  res = p8e2_t(p8e2_mul_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator *");
  }

  return P8e2(res);
}

P8e2 &P8e2::operator -=(const P8e2 rhs){
  p8e2_t res;

  res = p8e2_sub_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator -=");
  }

  this->data = res.udata;
  return (*this);
}

P8e2 P8e2::operator -(const P8e2 rhs) const{
  P8e2 res;          //create a return value from the stack.

  res = p8e2_t(p8e2_sub_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator -");
  }

  return P8e2(res);
}

P8e2 &P8e2::operator +=(const P8e2 rhs){
  p8e2_t res;

  res = p8e2_add_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator +=");
  }

  this->data = res.udata;
  return (*this);
}

P8e2 P8e2::operator +(const P8e2 rhs) const{
  P8e2 res;          //create a return value from the stack.

  res = p8e2_t(p8e2_add_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator +");
  }

  return P8e2(res);
}

P8e2 &P8e2::operator /=(const P8e2 rhs){
  p8e2_t res;

  res = p8e2_div_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator /=");
  }

  this->data = res.udata;
  return (*this);
}

P8e2 P8e2::operator /(const P8e2 rhs) const{
  P8e2 res;          //create a return value from the stack.

  res = p8e2_t(p8e2_div_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator /");
  }

  return P8e2(res);
}


bool P8e2::operator >(const P8e2 rhs) const{
  p8e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p8e2_gt(lhs_p, rhs_p);
}


bool P8e2::operator >=(const P8e2 rhs) const{
  p8e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p8e2_gte(lhs_p, rhs_p);
}


bool P8e2::operator <=(const P8e2 rhs) const{
  p8e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p8e2_lte(lhs_p, rhs_p);
}


bool P8e2::operator <(const P8e2 rhs) const{
  p8e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p8e2_lt(lhs_p, rhs_p);
}



P8e2::operator float() const{
  return (float) p8e2_to_f((p8e2_t)(*this));
}

P8e2::operator double() const{
  return (double) p8e2_to_f((p8e2_t)(*this));
}

P8e2::operator p8e2_t() const{
  p8e2_t res;
  res.udata = this->data;
  return res;
}



P8e2 mulinv (const P8e2 x){
  p8e2_t res;

  res = p8e2_mulinv_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function mulinv");
  }

  P8e2 res_c(res);
  return res_c;
}


P8e2 log2 (const P8e2 x){
  p8e2_t res;

  res = p8e2_log2_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log2");
  }

  P8e2 res_c(res);
  return res_c;
}


P8e2 exp2 (const P8e2 x){
  p8e2_t res;

  res = p8e2_exp2_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function exp2");
  }

  P8e2 res_c(res);
  return res_c;
}


P8e2 sqrt (const P8e2 x){
  p8e2_t res;

  res = p8e2_sqrt_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function sqrt");
  }

  P8e2 res_c(res);
  return res_c;
}


P8e2 log1p (const P8e2 x){
  p8e2_t res;

  res = p8e2_log1p_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log1p");
  }

  P8e2 res_c(res);
  return res_c;
}


P8e2 log (const P8e2 x){
  p8e2_t res;

  res = p8e2_log_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log");
  }

  P8e2 res_c(res);
  return res_c;
}


P8e2 log10 (const P8e2 x){
  p8e2_t res;

  res = p8e2_log10_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log10");
  }

  P8e2 res_c(res);
  return res_c;
}


P8e2 exp (const P8e2 x){
  p8e2_t res;

  res = p8e2_exp_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function exp");
  }

  P8e2 res_c(res);
  return res_c;
}


P8e2 sin (const P8e2 x){
  p8e2_t res;

  res = p8e2_sin_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function sin");
  }

  P8e2 res_c(res);
  return res_c;
}


P8e2 cos (const P8e2 x){
  p8e2_t res;

  res = p8e2_cos_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function cos");
  }

  P8e2 res_c(res);
  return res_c;
}


P8e2 atan (const P8e2 x){
  p8e2_t res;

  res = p8e2_atan_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function atan");
  }

  P8e2 res_c(res);
  return res_c;
}



P8e2 pow (const P8e2 a, const P8e2 b){
  p8e2_t res;

  res = p8e2_pow_e(a, b);
  if (errno) {
    throw std::domain_error("NaN value obtained in function pow");
  }

  P8e2 res_c(res);
  return res_c;
}


P8e2 atan2 (const P8e2 a, const P8e2 b){
  p8e2_t res;

  res = p8e2_atan2_e(a, b);
  if (errno) {
    throw std::domain_error("NaN value obtained in function atan2");
  }

  P8e2 res_c(res);
  return res_c;
}



P8e2 fma(const P8e2 a, const P8e2 b, const P8e2 c){
  p8e2_t res;

  res = p8e2_fma_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function fma");
  }

  P8e2 res_c(res);
  return res_c;
}


P8e2 fms(const P8e2 a, const P8e2 b, const P8e2 c){
  p8e2_t res;

  res = p8e2_fms_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function fms");
  }

  P8e2 res_c(res);
  return res_c;
}


P8e2 nfma(const P8e2 a, const P8e2 b, const P8e2 c){
  p8e2_t res;

  res = p8e2_nfma_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function nfma");
  }

  P8e2 res_c(res);
  return res_c;
}


P8e2 nfms(const P8e2 a, const P8e2 b, const P8e2 c){
  p8e2_t res;

  res = p8e2_nfms_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function nfms");
  }

  P8e2 res_c(res);
  return res_c;
}

