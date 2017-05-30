
#include "include/posit_conv.h"
#include "include/posit_ops.h"
#include "include/posit_ops_jumps.h"
#include "include/P32e3.h"
#include <stdexcept>


P32e3::P32e3(){ this->data = P32ZER; }

P32e3::P32e3(const float a){ this->data = f_to_p32e3((double) a).udata; }

P32e3::P32e3(const double a){ this->data = f_to_p32e3(a).udata; }

P32e3::P32e3(const P32e3 &a){ this->data = a.data; }

P32e3::P32e3(const p32e3_t a){ this->data = a.udata; }



P32e3 &P32e3::operator *=(const P32e3 rhs){
  p32e3_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e3_mul_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator *=");
  }

  this->data = res.udata;
  return (*this);
}

P32e3 P32e3::operator *(const P32e3 rhs){
  P32e3 res;          //create a return value on the stack.
  p32e3_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e3_t(p32e3_mul_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator *");
  }

  return P32e3(res);
}

P32e3 &P32e3::operator -=(const P32e3 rhs){
  p32e3_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e3_sub_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator -=");
  }

  this->data = res.udata;
  return (*this);
}

P32e3 P32e3::operator -(const P32e3 rhs){
  P32e3 res;          //create a return value on the stack.
  p32e3_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e3_t(p32e3_sub_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator -");
  }

  return P32e3(res);
}

P32e3 &P32e3::operator +=(const P32e3 rhs){
  p32e3_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e3_add_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator +=");
  }

  this->data = res.udata;
  return (*this);
}

P32e3 P32e3::operator +(const P32e3 rhs){
  P32e3 res;          //create a return value on the stack.
  p32e3_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e3_t(p32e3_add_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator +");
  }

  return P32e3(res);
}

P32e3 &P32e3::operator /=(const P32e3 rhs){
  p32e3_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e3_div_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator /=");
  }

  this->data = res.udata;
  return (*this);
}

P32e3 P32e3::operator /(const P32e3 rhs){
  P32e3 res;          //create a return value on the stack.
  p32e3_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e3_t(p32e3_div_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator /");
  }

  return P32e3(res);
}


bool P32e3::operator >(const P32e3 rhs){
  p32e3_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e3_gt(lhs_p, rhs_p);
}


bool P32e3::operator >=(const P32e3 rhs){
  p32e3_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e3_gte(lhs_p, rhs_p);
}


bool P32e3::operator <=(const P32e3 rhs){
  p32e3_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e3_lte(lhs_p, rhs_p);
}


bool P32e3::operator <(const P32e3 rhs){
  p32e3_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e3_lt(lhs_p, rhs_p);
}



