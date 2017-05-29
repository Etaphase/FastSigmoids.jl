#ifndef POSIT_32_2_H
#define POSIT_32_2_H

class P32e2{
  private:
    uint32_t data;
  public:

    //various public constructors
    P32e2();             //defaults to zero
    P32e2(float);        //conversion constructor from IEEE32
    P32e2(double);       //conversion constructor from IEEE64
    P32e2(P32e2);   //copy constructor
    P32e2(p32e2_t);   //bridge constructor from c functionality.

    //public operators
    P32e2 operator +(const P32e2 rhs);
    P32e2 operator -(const P32e2 rhs);
    P32e2 operator *(const P32e2 rhs);
    P32e2 &operator +=(const P32e2 rhs);
    P32e2 &operator -=(const P32e2 rhs);
    P32e2 &operator *=(const P32e2 rhs);
    bool operator <(const P32e2 rhs);
    bool operator <=(const P32e2 rhs);
    bool operator >(const P32e2 rhs);
    bool operator >=(const P32e2 rhs);
    P32e2 operator /(const P32e2 rhs);
    P32e2 &operator /=(const P32e2 rhs);

    //external friended operators
    friend P32e2 operator -(const P32e2 rhs);
    friend P32e2 operator float(const P32e2 rhs);
    friend P32e2 operator double(const P32e2 rhs);

    //friended functions
    friend P32e2 mulinv(const P32e2 arg);
    friend P32e2 log2(const P32e2 arg);
    friend P32e2 exp2(const P32e2 arg);
    friend P32e2 fma(const P32e2 a, const P32e2 b, const P32e2 c);
    friend P32e2 fms(const P32e2 a, const P32e2 b, const P32e2 c);
    friend P32e2 nfma(const P32e2 a, const P32e2 b, const P32e2 c);
    friend P32e2 nfms(const P32e2 a, const P32e2 b, const P32e2 c);
    friend P32e2 sqrt(const P32e2 arg);
    friend P32e2 log1p(const P32e2 arg);
    friend P32e2 log(const P32e2 arg);
    friend P32e2 log10(const P32e2 arg);
    friend P32e2 exp(const P32e2 arg);
    friend P32e2 pow(const P32e2 lhs, const P32e2 rhs);
    friend P32e2 sin(const P32e2 arg);
    friend P32e2 cos(const P32e2 arg);
    friend P32e2 atan(const P32e2 arg);
    friend P32e2 atan2(const P32e2 y, const P32e2 x);
}

//redeclaration of the functions that were just friended
P32e2 operator -(const P32e2 rhs);
P32e2 operator float(const P32e2 rhs);
P32e2 operator double(const P32e2 rhs);



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

