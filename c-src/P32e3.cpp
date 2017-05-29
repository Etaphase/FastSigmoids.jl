
#include "P32e3.h"


P32e3::P32e3(){ this.data = P32ZER; }

P32e3::P32e3(float a){ this.data = f_to_p32e3((double) a).udata; }

P32e3::P32e3(double a){ this.data = f_to_p32e3(a).udata; }

P32e3::P32e3(P32e3 a){ this.data = a.udata; }

P32e3::P32e3(p32e3_t a){ this.data = a.udata; }



P32e3 &P32e3::operator *=(const P32e3 rhs){
  p32e3_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p32e3_mul_j((p32e3_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator *=");
  }
  return (*this);
}

P32e3 P32e3::operator *(const P32e3 rhs){
  p32e3_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p32e3_mul(&res, (p32e3_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator *");
  }
  return res;
}

P32e3 &P32e3::operator -=(const P32e3 rhs){
  p32e3_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p32e3_sub_j((p32e3_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator -=");
  }
  return (*this);
}

P32e3 P32e3::operator -(const P32e3 rhs){
  p32e3_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p32e3_sub(&res, (p32e3_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator -");
  }
  return res;
}

P32e3 &P32e3::operator +=(const P32e3 rhs){
  p32e3_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p32e3_add_j((p32e3_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator +=");
  }
  return (*this);
}

P32e3 P32e3::operator +(const P32e3 rhs){
  p32e3_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p32e3_add(&res, (p32e3_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator +");
  }
  return res;
}

P32e3 &P32e3::operator /=(const P32e3 rhs){
  p32e3_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p32e3_div_j((p32e3_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator /=");
  }
  return (*this);
}

P32e3 P32e3::operator /(const P32e3 rhs){
  p32e3_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p32e3_div(&res, (p32e3_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator /");
  }
  return res;
}


