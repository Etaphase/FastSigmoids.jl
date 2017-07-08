
#include "include/posit_conv.h"
#include "include/posit_ops.h"
#include "include/posit_ops_errno.h"
#include "include/P8e0.h"
#include "errno.h"
#include <stdexcept>


P8e0::P8e0(){ this->data = P8ZER; }

P8e0::P8e0(const float a){
  this->data = f_to_p8e0(a).udata;
  if (errno) {
    throw std::domain_error("attempted to construct a posit from a NaN IEEE value");
  }
}

P8e0::P8e0(const double a){
  this->data = f_to_p8e0((float) a).udata;
  if (errno) {
    throw std::domain_error("attempted to construct a posit from a NaN IEEE value");
  }
}

P8e0::P8e0(const P8e0 &a){ this->data = a.data; }

P8e0::P8e0(const p8e0_t a){ this->data = a.udata; }



P8e0 P8e0::operator -() const{
  P8e0 res;
  res.data = -(this->data);
  return res;
}

P8e0 &P8e0::operator *=(const P8e0 rhs){
  p8e0_t res;

  res = p8e0_mul_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator *=");
  }

  this->data = res.udata;
  return (*this);
}

P8e0 P8e0::operator *(const P8e0 rhs) const{
  P8e0 res;          //create a return value from the stack.

  res = p8e0_t(p8e0_mul_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator *");
  }

  return P8e0(res);
}

P8e0 &P8e0::operator -=(const P8e0 rhs){
  p8e0_t res;

  res = p8e0_sub_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator -=");
  }

  this->data = res.udata;
  return (*this);
}

P8e0 P8e0::operator -(const P8e0 rhs) const{
  P8e0 res;          //create a return value from the stack.

  res = p8e0_t(p8e0_sub_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator -");
  }

  return P8e0(res);
}

P8e0 &P8e0::operator +=(const P8e0 rhs){
  p8e0_t res;

  res = p8e0_add_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator +=");
  }

  this->data = res.udata;
  return (*this);
}

P8e0 P8e0::operator +(const P8e0 rhs) const{
  P8e0 res;          //create a return value from the stack.

  res = p8e0_t(p8e0_add_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator +");
  }

  return P8e0(res);
}

P8e0 &P8e0::operator /=(const P8e0 rhs){
  p8e0_t res;

  res = p8e0_div_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator /=");
  }

  this->data = res.udata;
  return (*this);
}

P8e0 P8e0::operator /(const P8e0 rhs) const{
  P8e0 res;          //create a return value from the stack.

  res = p8e0_t(p8e0_div_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator /");
  }

  return P8e0(res);
}


bool P8e0::operator ==(const P8e0 rhs) const{
  p8e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p8e0_eq(lhs_p, rhs_p);
}


bool P8e0::operator >(const P8e0 rhs) const{
  p8e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p8e0_gt(lhs_p, rhs_p);
}


bool P8e0::operator >=(const P8e0 rhs) const{
  p8e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p8e0_gte(lhs_p, rhs_p);
}


bool P8e0::operator <=(const P8e0 rhs) const{
  p8e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p8e0_lte(lhs_p, rhs_p);
}


bool P8e0::operator <(const P8e0 rhs) const{
  p8e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p8e0_lt(lhs_p, rhs_p);
}



P8e0::operator float() const{
  return (float) p8e0_to_f((p8e0_t)(*this));
}

P8e0::operator double() const{
  return (double) p8e0_to_f((p8e0_t)(*this));
}

P8e0::operator p8e0_t() const{
  p8e0_t res;
  res.udata = this->data;
  return res;
}


bool isequal(const P8e0 a, const P8e0 b){
  return a.data == b.data;
}


P8e0 mulinv (const P8e0 x){
  p8e0_t res;

  res = p8e0_mulinv_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function mulinv");
  }

  P8e0 res_c(res);
  return res_c;
}


P8e0 log2 (const P8e0 x){
  p8e0_t res;

  res = p8e0_log2_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log2");
  }

  P8e0 res_c(res);
  return res_c;
}


P8e0 exp2 (const P8e0 x){
  p8e0_t res;

  res = p8e0_exp2_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function exp2");
  }

  P8e0 res_c(res);
  return res_c;
}


P8e0 sqrt (const P8e0 x){
  p8e0_t res;

  res = p8e0_sqrt_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function sqrt");
  }

  P8e0 res_c(res);
  return res_c;
}


P8e0 log1p (const P8e0 x){
  p8e0_t res;

  res = p8e0_log1p_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log1p");
  }

  P8e0 res_c(res);
  return res_c;
}


P8e0 log (const P8e0 x){
  p8e0_t res;

  res = p8e0_log_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log");
  }

  P8e0 res_c(res);
  return res_c;
}


P8e0 log10 (const P8e0 x){
  p8e0_t res;

  res = p8e0_log10_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log10");
  }

  P8e0 res_c(res);
  return res_c;
}


P8e0 exp (const P8e0 x){
  p8e0_t res;

  res = p8e0_exp_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function exp");
  }

  P8e0 res_c(res);
  return res_c;
}


P8e0 sin (const P8e0 x){
  p8e0_t res;

  res = p8e0_sin_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function sin");
  }

  P8e0 res_c(res);
  return res_c;
}


P8e0 cos (const P8e0 x){
  p8e0_t res;

  res = p8e0_cos_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function cos");
  }

  P8e0 res_c(res);
  return res_c;
}


P8e0 atan (const P8e0 x){
  p8e0_t res;

  res = p8e0_atan_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function atan");
  }

  P8e0 res_c(res);
  return res_c;
}



P8e0 pow (const P8e0 a, const P8e0 b){
  p8e0_t res;

  res = p8e0_pow_e(a, b);
  if (errno) {
    throw std::domain_error("NaN value obtained in function pow");
  }

  P8e0 res_c(res);
  return res_c;
}


P8e0 atan2 (const P8e0 a, const P8e0 b){
  p8e0_t res;

  res = p8e0_atan2_e(a, b);
  if (errno) {
    throw std::domain_error("NaN value obtained in function atan2");
  }

  P8e0 res_c(res);
  return res_c;
}



P8e0 fma(const P8e0 a, const P8e0 b, const P8e0 c){
  p8e0_t res;

  res = p8e0_fma_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function fma");
  }

  P8e0 res_c(res);
  return res_c;
}


P8e0 fms(const P8e0 a, const P8e0 b, const P8e0 c){
  p8e0_t res;

  res = p8e0_fms_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function fms");
  }

  P8e0 res_c(res);
  return res_c;
}


P8e0 nfma(const P8e0 a, const P8e0 b, const P8e0 c){
  p8e0_t res;

  res = p8e0_nfma_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function nfma");
  }

  P8e0 res_c(res);
  return res_c;
}


P8e0 nfms(const P8e0 a, const P8e0 b, const P8e0 c){
  p8e0_t res;

  res = p8e0_nfms_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function nfms");
  }

  P8e0 res_c(res);
  return res_c;
}

