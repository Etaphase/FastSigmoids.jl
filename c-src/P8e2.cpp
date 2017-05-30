
#include "include/posit_conv.h"
#include "include/posit_ops.h"
#include "include/posit_ops_jumps.h"
#include "include/P8e2.h"
#include <stdexcept>


P8e2::P8e2(){ this->data = P8ZER; }

P8e2::P8e2(const float a){ this->data = f_to_p8e2(a).udata; }

P8e2::P8e2(const double a){ this->data = f_to_p8e2((float) a).udata; }

P8e2::P8e2(const P8e2 &a){ this->data = a.data; }

P8e2::P8e2(const p8e2_t a){ this->data = a.udata; }



P8e2 &P8e2::operator *=(const P8e2 rhs){
  p8e2_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p8e2_mul_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator *=");
  }

  this->data = res.udata;
  return (*this);
}

P8e2 P8e2::operator *(const P8e2 rhs){
  P8e2 res;          //create a return value on the stack.
  p8e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p8e2_t(p8e2_mul_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator *");
  }

  return P8e2(res);
}

P8e2 &P8e2::operator -=(const P8e2 rhs){
  p8e2_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p8e2_sub_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator -=");
  }

  this->data = res.udata;
  return (*this);
}

P8e2 P8e2::operator -(const P8e2 rhs){
  P8e2 res;          //create a return value on the stack.
  p8e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p8e2_t(p8e2_sub_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator -");
  }

  return P8e2(res);
}

P8e2 &P8e2::operator +=(const P8e2 rhs){
  p8e2_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p8e2_add_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator +=");
  }

  this->data = res.udata;
  return (*this);
}

P8e2 P8e2::operator +(const P8e2 rhs){
  P8e2 res;          //create a return value on the stack.
  p8e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p8e2_t(p8e2_add_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator +");
  }

  return P8e2(res);
}

P8e2 &P8e2::operator /=(const P8e2 rhs){
  p8e2_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p8e2_div_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator /=");
  }

  this->data = res.udata;
  return (*this);
}

P8e2 P8e2::operator /(const P8e2 rhs){
  P8e2 res;          //create a return value on the stack.
  p8e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p8e2_t(p8e2_div_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator /");
  }

  return P8e2(res);
}


bool P8e2::operator >(const P8e2 rhs){
  p8e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p8e2_gt(lhs_p, rhs_p);
}


bool P8e2::operator >=(const P8e2 rhs){
  p8e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p8e2_gte(lhs_p, rhs_p);
}


bool P8e2::operator <=(const P8e2 rhs){
  p8e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p8e2_lte(lhs_p, rhs_p);
}


bool P8e2::operator <(const P8e2 rhs){
  p8e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p8e2_lt(lhs_p, rhs_p);
}



