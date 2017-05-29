
#include "P32e0.h"


P32e0::P32e0(){ this.data = P32ZER; }

P32e0::P32e0(float a){ this.data = f_to_p32e0((double) a).udata; }

P32e0::P32e0(double a){ this.data = f_to_p32e0(a).udata; }

P32e0::P32e0(P32e0 a){ this.data = a.udata; }

P32e0::P32e0(p32e0_t a){ this.data = a.udata; }



P32e0 &P32e0::operator *=(const P32e0 rhs){
  p32e0_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p32e0_mul_j((p32e0_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator *=");
  }
  return (*this);
}

P32e0 P32e0::operator *(const P32e0 rhs){
  p32e0_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p32e0_mul(&res, (p32e0_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator *");
  }
  return res;
}

P32e0 &P32e0::operator -=(const P32e0 rhs){
  p32e0_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p32e0_sub_j((p32e0_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator -=");
  }
  return (*this);
}

P32e0 P32e0::operator -(const P32e0 rhs){
  p32e0_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p32e0_sub(&res, (p32e0_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator -");
  }
  return res;
}

P32e0 &P32e0::operator +=(const P32e0 rhs){
  p32e0_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p32e0_add_j((p32e0_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator +=");
  }
  return (*this);
}

P32e0 P32e0::operator +(const P32e0 rhs){
  p32e0_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p32e0_add(&res, (p32e0_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator +");
  }
  return res;
}

P32e0 &P32e0::operator /=(const P32e0 rhs){
  p32e0_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p32e0_div_j((p32e0_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator /=");
  }
  return (*this);
}

P32e0 P32e0::operator /(const P32e0 rhs){
  p32e0_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p32e0_div(&res, (p32e0_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator /");
  }
  return res;
}


