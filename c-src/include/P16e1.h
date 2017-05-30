#ifndef POSIT_16_1_H
#define POSIT_16_1_H

#include "posit.h"

class P16e1{
  public:
    uint16_t data;

    //various public constructors
    P16e1();             //defaults to zero
    P16e1(const float);        //conversion constructor from IEEE32
    P16e1(const double);       //conversion constructor from IEEE64
    P16e1(const P16e1 &); //copy constructor
    P16e1(const p16e1_t);   //bridge constructor from c functionality.

    //public operators
    P16e1 operator -() const;
    P16e1 operator +(const P16e1 rhs) const;
    P16e1 operator -(const P16e1 rhs) const;
    P16e1 operator *(const P16e1 rhs) const;
    P16e1 &operator +=(const P16e1 rhs);
    P16e1 &operator -=(const P16e1 rhs);
    P16e1 &operator *=(const P16e1 rhs);
    bool operator <(const P16e1 rhs) const;
    bool operator <=(const P16e1 rhs) const;
    bool operator >(const P16e1 rhs) const;
    bool operator >=(const P16e1 rhs) const;
    P16e1 operator /(const P16e1 rhs) const;
    P16e1 &operator /=(const P16e1 rhs);

    operator float() const;
    operator double() const;
    operator p16e1_t() const;
};

P16e1 mulinv(const P16e1 arg);
P16e1 log2(const P16e1 arg);
P16e1 exp2(const P16e1 arg);
P16e1 fma(const P16e1 a, const P16e1 b, const P16e1 c);
P16e1 fms(const P16e1 a, const P16e1 b, const P16e1 c);
P16e1 nfma(const P16e1 a, const P16e1 b, const P16e1 c);
P16e1 nfms(const P16e1 a, const P16e1 b, const P16e1 c);
P16e1 sqrt(const P16e1 arg);
P16e1 log1p(const P16e1 arg);
P16e1 log(const P16e1 arg);
P16e1 log10(const P16e1 arg);
P16e1 exp(const P16e1 arg);
P16e1 pow(const P16e1 lhs, const P16e1 rhs);
P16e1 sin(const P16e1 arg);
P16e1 cos(const P16e1 arg);
P16e1 atan(const P16e1 arg);
P16e1 atan2(const P16e1 y, const P16e1 x);

#endif

