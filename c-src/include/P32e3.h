#ifndef POSIT_32_3_H
#define POSIT_32_3_H

class P32e3{
  public:
    uint32_t data;

    //various public constructors
    P32e3();             //defaults to zero
    P32e3(float);        //conversion constructor from IEEE32
    P32e3(double);       //conversion constructor from IEEE64
    P32e3(P32e3);   //copy constructor
    P32e3(p32e3_t);   //bridge constructor from c functionality.

    //public operators
    P32e3 operator +(const P32e3 rhs);
    P32e3 operator -(const P32e3 rhs);
    P32e3 operator *(const P32e3 rhs);
    P32e3 &operator +=(const P32e3 rhs);
    P32e3 &operator -=(const P32e3 rhs);
    P32e3 &operator *=(const P32e3 rhs);
    bool operator <(const P32e3 rhs);
    bool operator <=(const P32e3 rhs);
    bool operator >(const P32e3 rhs);
    bool operator >=(const P32e3 rhs);
    P32e3 operator /(const P32e3 rhs);
    P32e3 &operator /=(const P32e3 rhs);
}

//redeclaration of the functions that were just friended
P32e3 operator -(const P32e3 rhs);
P32e3 operator float(const P32e3 rhs);
P32e3 operator double(const P32e3 rhs);

P32e3 mulinv(const P32e3 arg);
P32e3 log2(const P32e3 arg);
P32e3 exp2(const P32e3 arg);
P32e3 fma(const P32e3 a, const P32e3 b, const P32e3 c);
P32e3 fms(const P32e3 a, const P32e3 b, const P32e3 c);
P32e3 nfma(const P32e3 a, const P32e3 b, const P32e3 c);
P32e3 nfms(const P32e3 a, const P32e3 b, const P32e3 c);
P32e3 sqrt(const P32e3 arg);
P32e3 log1p(const P32e3 arg);
P32e3 log(const P32e3 arg);
P32e3 log10(const P32e3 arg);
P32e3 exp(const P32e3 arg);
P32e3 pow(const P32e3 lhs, const P32e3 rhs);
P32e3 sin(const P32e3 arg);
P32e3 cos(const P32e3 arg);
P32e3 atan(const P32e3 arg);
P32e3 atan2(const P32e3 y, const P32e3 x);

#endif

