
#include "P32e2.h"


P32e2::P32e2(){ this.data = P32ZER; }

P32e2::P32e2(float a){ this.data = f_to_p32e2((double) a).udata; }

P32e2::P32e2(double a){ this.data = f_to_p32e2(a).udata; }

P32e2::P32e2(P32e2 a){ this.data = a.udata; }

P32e2::P32e2(p32e2_t a){ this.data = a.udata; }



P32e2 &P32e2::operator *=(const P32e2 rhs){
  p32e2_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p32e2_mul_j((p32e2_t *) this, lhs, (p32e2_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator *=");
  }
  return (*this);
}

P32e2 P32e2::operator *(const P32e2 rhs){
  p32e2_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p32e2_mul(&res, (p32e2_t) (*this), (p32e2_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator *");
  }
  return res;
}

P32e2 &P32e2::operator -=(const P32e2 rhs){
  p32e2_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p32e2_sub_j((p32e2_t *) this, lhs, (p32e2_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator -=");
  }
  return (*this);
}

P32e2 P32e2::operator -(const P32e2 rhs){
  p32e2_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p32e2_sub(&res, (p32e2_t) (*this), (p32e2_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator -");
  }
  return res;
}

P32e2 &P32e2::operator +=(const P32e2 rhs){
  p32e2_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p32e2_add_j((p32e2_t *) this, lhs, (p32e2_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator +=");
  }
  return (*this);
}

P32e2 P32e2::operator +(const P32e2 rhs){
  p32e2_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p32e2_add(&res, (p32e2_t) (*this), (p32e2_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator +");
  }
  return res;
}

P32e2 &P32e2::operator /=(const P32e2 rhs){
  p32e2_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p32e2_div_j((p32e2_t *) this, lhs, (p32e2_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator /=");
  }
  return (*this);
}

P32e2 P32e2::operator /(const P32e2 rhs){
  p32e2_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p32e2_div(&res, (p32e2_t) (*this), (p32e2_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator /");
  }
  return res;
}


