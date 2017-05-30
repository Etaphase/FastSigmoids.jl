
#include "include/posit_conv.h"
#include "include/posit_ops.h"
#include "include/posit_ops_jumps.h"
#include "include/P32e1.h"
#include <stdexcept>


P32e1::P32e1(){ this->data = P32ZER; }

P32e1::P32e1(const float a){ this->data = f_to_p32e1((double) a).udata; }

P32e1::P32e1(const double a){ this->data = f_to_p32e1(a).udata; }

P32e1::P32e1(const P32e1 &a){ this->data = a.data; }

P32e1::P32e1(const p32e1_t a){ this->data = a.udata; }



P32e1 &P32e1::operator *=(const P32e1 rhs){
  p32e1_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e1_mul_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator *=");
  }

  this->data = res.udata;
  return (*this);
}

P32e1 P32e1::operator *(const P32e1 rhs){
  P32e1 res;          //create a return value on the stack.
  p32e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e1_t(p32e1_mul_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator *");
  }

  return P32e1(res);
}

P32e1 &P32e1::operator -=(const P32e1 rhs){
  p32e1_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e1_sub_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator -=");
  }

  this->data = res.udata;
  return (*this);
}

P32e1 P32e1::operator -(const P32e1 rhs){
  P32e1 res;          //create a return value on the stack.
  p32e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e1_t(p32e1_sub_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator -");
  }

  return P32e1(res);
}

P32e1 &P32e1::operator +=(const P32e1 rhs){
  p32e1_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e1_add_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator +=");
  }

  this->data = res.udata;
  return (*this);
}

P32e1 P32e1::operator +(const P32e1 rhs){
  P32e1 res;          //create a return value on the stack.
  p32e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e1_t(p32e1_add_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator +");
  }

  return P32e1(res);
}

P32e1 &P32e1::operator /=(const P32e1 rhs){
  p32e1_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e1_div_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator /=");
  }

  this->data = res.udata;
  return (*this);
}

P32e1 P32e1::operator /(const P32e1 rhs){
  P32e1 res;          //create a return value on the stack.
  p32e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e1_t(p32e1_div_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator /");
  }

  return P32e1(res);
}


bool P32e1::operator >(const P32e1 rhs){
  p32e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e1_gt(lhs_p, rhs_p);
}


bool P32e1::operator >=(const P32e1 rhs){
  p32e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e1_gte(lhs_p, rhs_p);
}


bool P32e1::operator <=(const P32e1 rhs){
  p32e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e1_lte(lhs_p, rhs_p);
}


bool P32e1::operator <(const P32e1 rhs){
  p32e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e1_lt(lhs_p, rhs_p);
}



