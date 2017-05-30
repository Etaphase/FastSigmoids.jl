
#include "include/posit_conv.h"
#include "include/posit_ops.h"
#include "include/posit_ops_jumps.h"
#include "include/P8e1.h"
#include <stdexcept>


P8e1::P8e1(){ this->data = P8ZER; }

P8e1::P8e1(const float a){ this->data = f_to_p8e1(a).udata; }

P8e1::P8e1(const double a){ this->data = f_to_p8e1((float) a).udata; }

P8e1::P8e1(const P8e1 &a){ this->data = a.data; }

P8e1::P8e1(const p8e1_t a){ this->data = a.udata; }



P8e1 &P8e1::operator *=(const P8e1 rhs){
  p8e1_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p8e1_mul_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator *=");
  }

  this->data = res.udata;
  return (*this);
}

P8e1 P8e1::operator *(const P8e1 rhs){
  P8e1 res;          //create a return value on the stack.
  p8e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p8e1_t(p8e1_mul_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator *");
  }

  return P8e1(res);
}

P8e1 &P8e1::operator -=(const P8e1 rhs){
  p8e1_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p8e1_sub_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator -=");
  }

  this->data = res.udata;
  return (*this);
}

P8e1 P8e1::operator -(const P8e1 rhs){
  P8e1 res;          //create a return value on the stack.
  p8e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p8e1_t(p8e1_sub_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator -");
  }

  return P8e1(res);
}

P8e1 &P8e1::operator +=(const P8e1 rhs){
  p8e1_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p8e1_add_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator +=");
  }

  this->data = res.udata;
  return (*this);
}

P8e1 P8e1::operator +(const P8e1 rhs){
  P8e1 res;          //create a return value on the stack.
  p8e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p8e1_t(p8e1_add_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator +");
  }

  return P8e1(res);
}

P8e1 &P8e1::operator /=(const P8e1 rhs){
  p8e1_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p8e1_div_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator /=");
  }

  this->data = res.udata;
  return (*this);
}

P8e1 P8e1::operator /(const P8e1 rhs){
  P8e1 res;          //create a return value on the stack.
  p8e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p8e1_t(p8e1_div_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator /");
  }

  return P8e1(res);
}


bool P8e1::operator >(const P8e1 rhs){
  p8e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p8e1_gt(lhs_p, rhs_p);
}


bool P8e1::operator >=(const P8e1 rhs){
  p8e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p8e1_gte(lhs_p, rhs_p);
}


bool P8e1::operator <=(const P8e1 rhs){
  p8e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p8e1_lte(lhs_p, rhs_p);
}


bool P8e1::operator <(const P8e1 rhs){
  p8e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p8e1_lt(lhs_p, rhs_p);
}



