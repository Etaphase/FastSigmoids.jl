#ifndef POSIT_16_2_H
#define POSIT_16_2_H

#include "posit.h"

class P16e2{
  public:
    uint16_t data;

    //various public constructors
    P16e2();             //defaults to zero
    P16e2(const float);        //conversion constructor from IEEE32
    P16e2(const double);       //conversion constructor from IEEE64
    P16e2(const P16e2 &); //copy constructor
    P16e2(const p16e2_t);   //bridge constructor from c functionality.

    //public operators
    P16e2 operator -() const;
    P16e2 operator +(const P16e2 rhs) const;
    P16e2 operator -(const P16e2 rhs) const;
    P16e2 operator *(const P16e2 rhs) const;
    P16e2 &operator +=(const P16e2 rhs);
    P16e2 &operator -=(const P16e2 rhs);
    P16e2 &operator *=(const P16e2 rhs);
    bool operator <(const P16e2 rhs) const;
    bool operator <=(const P16e2 rhs) const;
    bool operator >(const P16e2 rhs) const;
    bool operator >=(const P16e2 rhs) const;
    bool operator ==(const P16e2 rhs) const;
    P16e2 operator /(const P16e2 rhs) const;
    P16e2 &operator /=(const P16e2 rhs);

    operator float() const;
    operator double() const;
    operator p16e2_t() const;
};

bool isequal(const P16e2 a, const P16e2 b);
P16e2 mulinv(const P16e2 arg);
P16e2 log2(const P16e2 arg);
P16e2 exp2(const P16e2 arg);
P16e2 fma(const P16e2 a, const P16e2 b, const P16e2 c);
P16e2 fms(const P16e2 a, const P16e2 b, const P16e2 c);
P16e2 nfma(const P16e2 a, const P16e2 b, const P16e2 c);
P16e2 nfms(const P16e2 a, const P16e2 b, const P16e2 c);
P16e2 sqrt(const P16e2 arg);
P16e2 log1p(const P16e2 arg);
P16e2 log(const P16e2 arg);
P16e2 log10(const P16e2 arg);
P16e2 exp(const P16e2 arg);
P16e2 pow(const P16e2 lhs, const P16e2 rhs);
P16e2 sin(const P16e2 arg);
P16e2 cos(const P16e2 arg);
P16e2 atan(const P16e2 arg);
P16e2 atan2(const P16e2 y, const P16e2 x);

#endif

