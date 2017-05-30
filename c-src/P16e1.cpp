
#include "include/posit_conv.h"
#include "include/posit_ops.h"
#include "include/posit_ops_jumps.h"
#include "include/P16e1.h"
#include <stdexcept>


P16e1::P16e1(){ this->data = P16ZER; }

P16e1::P16e1(const float a){ this->data = f_to_p16e1(a).udata; }

P16e1::P16e1(const double a){ this->data = f_to_p16e1((float) a).udata; }

P16e1::P16e1(const P16e1 &a){ this->data = a.data; }

P16e1::P16e1(const p16e1_t a){ this->data = a.udata; }



P16e1 &P16e1::operator *=(const P16e1 rhs){
  p16e1_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e1_mul_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator *=");
  }

  this->data = res.udata;
  return (*this);
}

P16e1 P16e1::operator *(const P16e1 rhs){
  P16e1 res;          //create a return value on the stack.
  p16e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e1_t(p16e1_mul_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator *");
  }

  return P16e1(res);
}

P16e1 &P16e1::operator -=(const P16e1 rhs){
  p16e1_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e1_sub_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator -=");
  }

  this->data = res.udata;
  return (*this);
}

P16e1 P16e1::operator -(const P16e1 rhs){
  P16e1 res;          //create a return value on the stack.
  p16e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e1_t(p16e1_sub_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator -");
  }

  return P16e1(res);
}

P16e1 &P16e1::operator +=(const P16e1 rhs){
  p16e1_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e1_add_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator +=");
  }

  this->data = res.udata;
  return (*this);
}

P16e1 P16e1::operator +(const P16e1 rhs){
  P16e1 res;          //create a return value on the stack.
  p16e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e1_t(p16e1_add_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator +");
  }

  return P16e1(res);
}

P16e1 &P16e1::operator /=(const P16e1 rhs){
  p16e1_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e1_div_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator /=");
  }

  this->data = res.udata;
  return (*this);
}

P16e1 P16e1::operator /(const P16e1 rhs){
  P16e1 res;          //create a return value on the stack.
  p16e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e1_t(p16e1_div_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator /");
  }

  return P16e1(res);
}


bool P16e1::operator >(const P16e1 rhs){
  p16e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e1_gt(lhs_p, rhs_p);
}


bool P16e1::operator >=(const P16e1 rhs){
  p16e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e1_gte(lhs_p, rhs_p);
}


bool P16e1::operator <=(const P16e1 rhs){
  p16e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e1_lte(lhs_p, rhs_p);
}


bool P16e1::operator <(const P16e1 rhs){
  p16e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e1_lt(lhs_p, rhs_p);
}



