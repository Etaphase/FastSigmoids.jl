
#include "include/posit_conv.h"
#include "include/posit_ops.h"
#include "include/posit_ops_errno.h"
#include "include/P32e3.h"
#include "errno.h"
#include <stdexcept>


P32e3::P32e3(){ this->data = P32ZER; }

P32e3::P32e3(const float a){
  this->data = f_to_p32e3((double) a).udata;
  if (errno) {
    throw std::domain_error("attempted to construct a posit from a NaN IEEE value");
  }
}

P32e3::P32e3(const double a){
  this->data = f_to_p32e3(a).udata;
  if (errno) {
    throw std::domain_error("attempted to construct a posit from a NaN IEEE value");
  }
}

P32e3::P32e3(const P32e3 &a){ this->data = a.data; }

P32e3::P32e3(const p32e3_t a){ this->data = a.udata; }



P32e3 P32e3::operator -() const{
  P32e3 res;
  res.data = -(this->data);
  return res;
}

P32e3 &P32e3::operator *=(const P32e3 rhs){
  p32e3_t res;

  res = p32e3_mul_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator *=");
  }

  this->data = res.udata;
  return (*this);
}

P32e3 P32e3::operator *(const P32e3 rhs) const{
  P32e3 res;          //create a return value from the stack.

  res = p32e3_t(p32e3_mul_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator *");
  }

  return P32e3(res);
}

P32e3 &P32e3::operator -=(const P32e3 rhs){
  p32e3_t res;

  res = p32e3_sub_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator -=");
  }

  this->data = res.udata;
  return (*this);
}

P32e3 P32e3::operator -(const P32e3 rhs) const{
  P32e3 res;          //create a return value from the stack.

  res = p32e3_t(p32e3_sub_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator -");
  }

  return P32e3(res);
}

P32e3 &P32e3::operator +=(const P32e3 rhs){
  p32e3_t res;

  res = p32e3_add_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator +=");
  }

  this->data = res.udata;
  return (*this);
}

P32e3 P32e3::operator +(const P32e3 rhs) const{
  P32e3 res;          //create a return value from the stack.

  res = p32e3_t(p32e3_add_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator +");
  }

  return P32e3(res);
}

P32e3 &P32e3::operator /=(const P32e3 rhs){
  p32e3_t res;

  res = p32e3_div_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator /=");
  }

  this->data = res.udata;
  return (*this);
}

P32e3 P32e3::operator /(const P32e3 rhs) const{
  P32e3 res;          //create a return value from the stack.

  res = p32e3_t(p32e3_div_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator /");
  }

  return P32e3(res);
}


bool P32e3::operator >(const P32e3 rhs) const{
  p32e3_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e3_gt(lhs_p, rhs_p);
}


bool P32e3::operator >=(const P32e3 rhs) const{
  p32e3_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e3_gte(lhs_p, rhs_p);
}


bool P32e3::operator <=(const P32e3 rhs) const{
  p32e3_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e3_lte(lhs_p, rhs_p);
}


bool P32e3::operator <(const P32e3 rhs) const{
  p32e3_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e3_lt(lhs_p, rhs_p);
}



P32e3::operator float() const{
  return (float) p32e3_to_f((p32e3_t)(*this));
}

P32e3::operator double() const{
  return (double) p32e3_to_f((p32e3_t)(*this));
}

P32e3::operator p32e3_t() const{
  p32e3_t res;
  res.udata = this->data;
  return res;
}



P32e3 mulinv (const P32e3 x){
  p32e3_t res;

  res = p32e3_mulinv_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function mulinv");
  }

  P32e3 res_c(res);
  return res_c;
}


P32e3 log2 (const P32e3 x){
  p32e3_t res;

  res = p32e3_log2_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log2");
  }

  P32e3 res_c(res);
  return res_c;
}


P32e3 exp2 (const P32e3 x){
  p32e3_t res;

  res = p32e3_exp2_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function exp2");
  }

  P32e3 res_c(res);
  return res_c;
}


P32e3 sqrt (const P32e3 x){
  p32e3_t res;

  res = p32e3_sqrt_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function sqrt");
  }

  P32e3 res_c(res);
  return res_c;
}


P32e3 log1p (const P32e3 x){
  p32e3_t res;

  res = p32e3_log1p_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log1p");
  }

  P32e3 res_c(res);
  return res_c;
}


P32e3 log (const P32e3 x){
  p32e3_t res;

  res = p32e3_log_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log");
  }

  P32e3 res_c(res);
  return res_c;
}


P32e3 log10 (const P32e3 x){
  p32e3_t res;

  res = p32e3_log10_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log10");
  }

  P32e3 res_c(res);
  return res_c;
}


P32e3 exp (const P32e3 x){
  p32e3_t res;

  res = p32e3_exp_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function exp");
  }

  P32e3 res_c(res);
  return res_c;
}


P32e3 sin (const P32e3 x){
  p32e3_t res;

  res = p32e3_sin_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function sin");
  }

  P32e3 res_c(res);
  return res_c;
}


P32e3 cos (const P32e3 x){
  p32e3_t res;

  res = p32e3_cos_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function cos");
  }

  P32e3 res_c(res);
  return res_c;
}


P32e3 atan (const P32e3 x){
  p32e3_t res;

  res = p32e3_atan_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function atan");
  }

  P32e3 res_c(res);
  return res_c;
}



P32e3 pow (const P32e3 a, const P32e3 b){
  p32e3_t res;

  res = p32e3_pow_e(a, b);
  if (errno) {
    throw std::domain_error("NaN value obtained in function pow");
  }

  P32e3 res_c(res);
  return res_c;
}


P32e3 atan2 (const P32e3 a, const P32e3 b){
  p32e3_t res;

  res = p32e3_atan2_e(a, b);
  if (errno) {
    throw std::domain_error("NaN value obtained in function atan2");
  }

  P32e3 res_c(res);
  return res_c;
}



P32e3 fma(const P32e3 a, const P32e3 b, const P32e3 c){
  p32e3_t res;

  res = p32e3_fma_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function fma");
  }

  P32e3 res_c(res);
  return res_c;
}


P32e3 fms(const P32e3 a, const P32e3 b, const P32e3 c){
  p32e3_t res;

  res = p32e3_fms_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function fms");
  }

  P32e3 res_c(res);
  return res_c;
}


P32e3 nfma(const P32e3 a, const P32e3 b, const P32e3 c){
  p32e3_t res;

  res = p32e3_nfma_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function nfma");
  }

  P32e3 res_c(res);
  return res_c;
}


P32e3 nfms(const P32e3 a, const P32e3 b, const P32e3 c){
  p32e3_t res;

  res = p32e3_nfms_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function nfms");
  }

  P32e3 res_c(res);
  return res_c;
}

