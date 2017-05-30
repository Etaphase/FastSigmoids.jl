
#include "include/posit_conv.h"
#include "include/posit_ops.h"
#include "include/posit_ops_jumps.h"
#include "include/P8e1.h"
#include <stdexcept>


P8e1::P8e1(){ this->data = P8ZER; }

P8e1::P8e1(const float a){
  if (set_nan_jmp()) {
    this->data = f_to_p8e1(a).udata;
  } else {
    throw std::domain_error("attempted to construct a posit from a NaN IEEE value");
  }
}

P8e1::P8e1(const double a){
  if (set_nan_jmp()) {
    this->data = f_to_p8e1((float) a).udata;
  } else {
    throw std::domain_error("attempted to construct a posit from a NaN IEEE value");
  }
}

P8e1::P8e1(const P8e1 &a){ this->data = a.data; }

P8e1::P8e1(const p8e1_t a){ this->data = a.udata; }



P8e1 P8e1::operator -() const{
  P8e1 res;
  res.data = -(this->data);
  return res;
}

P8e1 &P8e1::operator *=(const P8e1 rhs){
  p8e1_t res;

  if (set_nan_jmp()){
    res = p8e1_mul_j(*this, rhs);
  } else {
    throw std::domain_error("NaN value obtained in operator *=");
  }

  this->data = res.udata;
  return (*this);
}

P8e1 P8e1::operator *(const P8e1 rhs) const{
  P8e1 res;          //create a return value from the stack.

  if (set_nan_jmp()){
    res = p8e1_t(p8e1_mul_j(*this, rhs));
  } else {
    throw std::domain_error("NaN value obtained in operator *");
  }

  return P8e1(res);
}

P8e1 &P8e1::operator -=(const P8e1 rhs){
  p8e1_t res;

  if (set_nan_jmp()){
    res = p8e1_sub_j(*this, rhs);
  } else {
    throw std::domain_error("NaN value obtained in operator -=");
  }

  this->data = res.udata;
  return (*this);
}

P8e1 P8e1::operator -(const P8e1 rhs) const{
  P8e1 res;          //create a return value from the stack.

  if (set_nan_jmp()){
    res = p8e1_t(p8e1_sub_j(*this, rhs));
  } else {
    throw std::domain_error("NaN value obtained in operator -");
  }

  return P8e1(res);
}

P8e1 &P8e1::operator +=(const P8e1 rhs){
  p8e1_t res;

  if (set_nan_jmp()){
    res = p8e1_add_j(*this, rhs);
  } else {
    throw std::domain_error("NaN value obtained in operator +=");
  }

  this->data = res.udata;
  return (*this);
}

P8e1 P8e1::operator +(const P8e1 rhs) const{
  P8e1 res;          //create a return value from the stack.

  if (set_nan_jmp()){
    res = p8e1_t(p8e1_add_j(*this, rhs));
  } else {
    throw std::domain_error("NaN value obtained in operator +");
  }

  return P8e1(res);
}

P8e1 &P8e1::operator /=(const P8e1 rhs){
  p8e1_t res;

  if (set_nan_jmp()){
    res = p8e1_div_j(*this, rhs);
  } else {
    throw std::domain_error("NaN value obtained in operator /=");
  }

  this->data = res.udata;
  return (*this);
}

P8e1 P8e1::operator /(const P8e1 rhs) const{
  P8e1 res;          //create a return value from the stack.

  if (set_nan_jmp()){
    res = p8e1_t(p8e1_div_j(*this, rhs));
  } else {
    throw std::domain_error("NaN value obtained in operator /");
  }

  return P8e1(res);
}


bool P8e1::operator >(const P8e1 rhs) const{
  p8e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p8e1_gt(lhs_p, rhs_p);
}


bool P8e1::operator >=(const P8e1 rhs) const{
  p8e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p8e1_gte(lhs_p, rhs_p);
}


bool P8e1::operator <=(const P8e1 rhs) const{
  p8e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p8e1_lte(lhs_p, rhs_p);
}


bool P8e1::operator <(const P8e1 rhs) const{
  p8e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p8e1_lt(lhs_p, rhs_p);
}



P8e1::operator float() const{
  return (float) p8e1_to_f((p8e1_t)(*this));
}

P8e1::operator double() const{
  return (double) p8e1_to_f((p8e1_t)(*this));
}

P8e1::operator p8e1_t() const{
  p8e1_t res;
  res.udata = this->data;
  return res;
}



P8e1 mulinv (const P8e1 x){
  p8e1_t res;

  if (set_nan_jmp()){
    res = p8e1_mulinv_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function mulinv");
  }

  P8e1 res_c(res);
  return res_c;
}


P8e1 log2 (const P8e1 x){
  p8e1_t res;

  if (set_nan_jmp()){
    res = p8e1_log2_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function log2");
  }

  P8e1 res_c(res);
  return res_c;
}


P8e1 exp2 (const P8e1 x){
  p8e1_t res;

  if (set_nan_jmp()){
    res = p8e1_exp2_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function exp2");
  }

  P8e1 res_c(res);
  return res_c;
}


P8e1 sqrt (const P8e1 x){
  p8e1_t res;

  if (set_nan_jmp()){
    res = p8e1_sqrt_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function sqrt");
  }

  P8e1 res_c(res);
  return res_c;
}


P8e1 log1p (const P8e1 x){
  p8e1_t res;

  if (set_nan_jmp()){
    res = p8e1_log1p_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function log1p");
  }

  P8e1 res_c(res);
  return res_c;
}


P8e1 log (const P8e1 x){
  p8e1_t res;

  if (set_nan_jmp()){
    res = p8e1_log_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function log");
  }

  P8e1 res_c(res);
  return res_c;
}


P8e1 log10 (const P8e1 x){
  p8e1_t res;

  if (set_nan_jmp()){
    res = p8e1_log10_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function log10");
  }

  P8e1 res_c(res);
  return res_c;
}


P8e1 exp (const P8e1 x){
  p8e1_t res;

  if (set_nan_jmp()){
    res = p8e1_exp_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function exp");
  }

  P8e1 res_c(res);
  return res_c;
}


P8e1 sin (const P8e1 x){
  p8e1_t res;

  if (set_nan_jmp()){
    res = p8e1_sin_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function sin");
  }

  P8e1 res_c(res);
  return res_c;
}


P8e1 cos (const P8e1 x){
  p8e1_t res;

  if (set_nan_jmp()){
    res = p8e1_cos_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function cos");
  }

  P8e1 res_c(res);
  return res_c;
}


P8e1 atan (const P8e1 x){
  p8e1_t res;

  if (set_nan_jmp()){
    res = p8e1_atan_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function atan");
  }

  P8e1 res_c(res);
  return res_c;
}



P8e1 pow (const P8e1 a, const P8e1 b){
  p8e1_t res;

  if (set_nan_jmp()){
    res = p8e1_pow_j(a, b);
  } else {
    throw std::domain_error("NaN value obtained in function pow");
  }

  P8e1 res_c(res);
  return res_c;
}


P8e1 atan2 (const P8e1 a, const P8e1 b){
  p8e1_t res;

  if (set_nan_jmp()){
    res = p8e1_atan2_j(a, b);
  } else {
    throw std::domain_error("NaN value obtained in function atan2");
  }

  P8e1 res_c(res);
  return res_c;
}



P8e1 fma(const P8e1 a, const P8e1 b, const P8e1 c){
  p8e1_t res;

  if (set_nan_jmp()){
    res = p8e1_fma_j(a, b, c);
  } else {
    throw std::domain_error("NaN value obtained in function fma");
  }

  P8e1 res_c(res);
  return res_c;
}


P8e1 fms(const P8e1 a, const P8e1 b, const P8e1 c){
  p8e1_t res;

  if (set_nan_jmp()){
    res = p8e1_fms_j(a, b, c);
  } else {
    throw std::domain_error("NaN value obtained in function fms");
  }

  P8e1 res_c(res);
  return res_c;
}


P8e1 nfma(const P8e1 a, const P8e1 b, const P8e1 c){
  p8e1_t res;

  if (set_nan_jmp()){
    res = p8e1_nfma_j(a, b, c);
  } else {
    throw std::domain_error("NaN value obtained in function nfma");
  }

  P8e1 res_c(res);
  return res_c;
}


P8e1 nfms(const P8e1 a, const P8e1 b, const P8e1 c){
  p8e1_t res;

  if (set_nan_jmp()){
    res = p8e1_nfms_j(a, b, c);
  } else {
    throw std::domain_error("NaN value obtained in function nfms");
  }

  P8e1 res_c(res);
  return res_c;
}

