#ifndef POSIT_32_2_H
#define POSIT_32_2_H

#include "posit.h"

class P32e2{
  public:
    uint32_t data;

    //various public constructors
    P32e2();             //defaults to zero
    P32e2(const float);        //conversion constructor from IEEE32
    P32e2(const double);       //conversion constructor from IEEE64
    P32e2(const P32e2 &); //copy constructor
    P32e2(const p32e2_t);   //bridge constructor from c functionality.

    //public operators
    P32e2 operator -() const;
    P32e2 operator +(const P32e2 rhs) const;
    P32e2 operator -(const P32e2 rhs) const;
    P32e2 operator *(const P32e2 rhs) const;
    P32e2 &operator +=(const P32e2 rhs);
    P32e2 &operator -=(const P32e2 rhs);
    P32e2 &operator *=(const P32e2 rhs);
    bool operator <(const P32e2 rhs) const;
    bool operator <=(const P32e2 rhs) const;
    bool operator >(const P32e2 rhs) const;
    bool operator >=(const P32e2 rhs) const;
    P32e2 operator /(const P32e2 rhs) const;
    P32e2 &operator /=(const P32e2 rhs);

    operator float() const;
    operator double() const;
    operator p32e2_t() const;
};

P32e2 mulinv(const P32e2 arg);
P32e2 log2(const P32e2 arg);
P32e2 exp2(const P32e2 arg);
P32e2 fma(const P32e2 a, const P32e2 b, const P32e2 c);
P32e2 fms(const P32e2 a, const P32e2 b, const P32e2 c);
P32e2 nfma(const P32e2 a, const P32e2 b, const P32e2 c);
P32e2 nfms(const P32e2 a, const P32e2 b, const P32e2 c);
P32e2 sqrt(const P32e2 arg);
P32e2 log1p(const P32e2 arg);
P32e2 log(const P32e2 arg);
P32e2 log10(const P32e2 arg);
P32e2 exp(const P32e2 arg);
P32e2 pow(const P32e2 lhs, const P32e2 rhs);
P32e2 sin(const P32e2 arg);
P32e2 cos(const P32e2 arg);
P32e2 atan(const P32e2 arg);
P32e2 atan2(const P32e2 y, const P32e2 x);

#endif

