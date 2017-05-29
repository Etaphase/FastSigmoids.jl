
#include "P8e2.h"


P8e2::P8e2(){ this.data = P8ZER; }

P8e2::P8e2(float a){ this.data = f_to_p8e2(a).udata; }

P8e2::P8e2(double a){ this.data = f_to_p8e2((float) a).udata; }

P8e2::P8e2(P8e2 a){ this.data = a.udata; }

P8e2::P8e2(p8e2_t a){ this.data = a.udata; }



P8e2 &P8e2::operator *=(const P8e2 rhs){
  p8e2_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p8e2_mul_j((p8e2_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator *=");
  }
  return (*this);
}

P8e2 P8e2::operator *(const P8e2 rhs){
  p8e2_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p8e2_mul(&res, (p8e2_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator *");
  }
  return res;
}

P8e2 &P8e2::operator -=(const P8e2 rhs){
  p8e2_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p8e2_sub_j((p8e2_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator -=");
  }
  return (*this);
}

P8e2 P8e2::operator -(const P8e2 rhs){
  p8e2_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p8e2_sub(&res, (p8e2_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator -");
  }
  return res;
}

P8e2 &P8e2::operator +=(const P8e2 rhs){
  p8e2_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p8e2_add_j((p8e2_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator +=");
  }
  return (*this);
}

P8e2 P8e2::operator +(const P8e2 rhs){
  p8e2_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p8e2_add(&res, (p8e2_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator +");
  }
  return res;
}

P8e2 &P8e2::operator /=(const P8e2 rhs){
  p8e2_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p8e2_div_j((p8e2_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator /=");
  }
  return (*this);
}

P8e2 P8e2::operator /(const P8e2 rhs){
  p8e2_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p8e2_div(&res, (p8e2_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator /");
  }
  return res;
}


