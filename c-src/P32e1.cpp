
#include "P32e1.h"


P32e1::P32e1(){ this.data = P32ZER; }

P32e1::P32e1(float a){ this.data = f_to_p32e1((double) a).udata; }

P32e1::P32e1(double a){ this.data = f_to_p32e1(a).udata; }

P32e1::P32e1(P32e1 a){ this.data = a.udata; }

P32e1::P32e1(p32e1_t a){ this.data = a.udata; }



P32e1 &P32e1::operator *=(const P32e1 rhs){
  p32e1_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p32e1_mul_j((p32e1_t *) this, lhs, (p32e1_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator *=");
  }
  return (*this);
}

P32e1 P32e1::operator *(const P32e1 rhs){
  p32e1_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p32e1_mul(&res, (p32e1_t) (*this), (p32e1_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator *");
  }
  return res;
}

P32e1 &P32e1::operator -=(const P32e1 rhs){
  p32e1_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p32e1_sub_j((p32e1_t *) this, lhs, (p32e1_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator -=");
  }
  return (*this);
}

P32e1 P32e1::operator -(const P32e1 rhs){
  p32e1_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p32e1_sub(&res, (p32e1_t) (*this), (p32e1_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator -");
  }
  return res;
}

P32e1 &P32e1::operator +=(const P32e1 rhs){
  p32e1_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p32e1_add_j((p32e1_t *) this, lhs, (p32e1_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator +=");
  }
  return (*this);
}

P32e1 P32e1::operator +(const P32e1 rhs){
  p32e1_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p32e1_add(&res, (p32e1_t) (*this), (p32e1_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator +");
  }
  return res;
}

P32e1 &P32e1::operator /=(const P32e1 rhs){
  p32e1_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p32e1_div_j((p32e1_t *) this, lhs, (p32e1_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator /=");
  }
  return (*this);
}

P32e1 P32e1::operator /(const P32e1 rhs){
  p32e1_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p32e1_div(&res, (p32e1_t) (*this), (p32e1_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator /");
  }
  return res;
}


