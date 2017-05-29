#ifndef POSIT_32_1_H
#define POSIT_32_1_H

class P32e1{
  private:
    uint32_t data;
  public:

    //various public constructors
    P32e1();             //defaults to zero
    P32e1(float);        //conversion constructor from IEEE32
    P32e1(double);       //conversion constructor from IEEE64
    P32e1(P32e1);   //copy constructor
    P32e1(p32e1_t);   //bridge constructor from c functionality.

    //public operators
    P32e1 operator +(const P32e1 rhs);
    P32e1 operator -(const P32e1 rhs);
    P32e1 operator *(const P32e1 rhs);
    P32e1 &operator +=(const P32e1 rhs);
    P32e1 &operator -=(const P32e1 rhs);
    P32e1 &operator *=(const P32e1 rhs);
    bool operator <(const P32e1 rhs);
    bool operator <=(const P32e1 rhs);
    bool operator >(const P32e1 rhs);
    bool operator >=(const P32e1 rhs);
    P32e1 operator /(const P32e1 rhs);
    P32e1 &operator /=(const P32e1 rhs);

    //external friended operators
    friend P32e1 operator -(const P32e1 rhs);
    friend P32e1 operator float(const P32e1 rhs);
    friend P32e1 operator double(const P32e1 rhs);

    //friended functions
    friend P32e1 mulinv(const P32e1 arg);
    friend P32e1 log2(const P32e1 arg);
    friend P32e1 exp2(const P32e1 arg);
    friend P32e1 fma(const P32e1 a, const P32e1 b, const P32e1 c);
    friend P32e1 fms(const P32e1 a, const P32e1 b, const P32e1 c);
    friend P32e1 nfma(const P32e1 a, const P32e1 b, const P32e1 c);
    friend P32e1 nfms(const P32e1 a, const P32e1 b, const P32e1 c);
    friend P32e1 sqrt(const P32e1 arg);
    friend P32e1 log1p(const P32e1 arg);
    friend P32e1 log(const P32e1 arg);
    friend P32e1 log10(const P32e1 arg);
    friend P32e1 exp(const P32e1 arg);
    friend P32e1 pow(const P32e1 lhs, const P32e1 rhs);
    friend P32e1 sin(const P32e1 arg);
    friend P32e1 cos(const P32e1 arg);
    friend P32e1 atan(const P32e1 arg);
    friend P32e1 atan2(const P32e1 y, const P32e1 x);
}

//redeclaration of the functions that were just friended
P32e1 operator -(const P32e1 rhs);
P32e1 operator float(const P32e1 rhs);
P32e1 operator double(const P32e1 rhs);



P32e1 mulinv(const P32e1 arg);
P32e1 log2(const P32e1 arg);
P32e1 exp2(const P32e1 arg);
P32e1 fma(const P32e1 a, const P32e1 b, const P32e1 c);
P32e1 fms(const P32e1 a, const P32e1 b, const P32e1 c);
P32e1 nfma(const P32e1 a, const P32e1 b, const P32e1 c);
P32e1 nfms(const P32e1 a, const P32e1 b, const P32e1 c);
P32e1 sqrt(const P32e1 arg);
P32e1 log1p(const P32e1 arg);
P32e1 log(const P32e1 arg);
P32e1 log10(const P32e1 arg);
P32e1 exp(const P32e1 arg);
P32e1 pow(const P32e1 lhs, const P32e1 rhs);
P32e1 sin(const P32e1 arg);
P32e1 cos(const P32e1 arg);
P32e1 atan(const P32e1 arg);
P32e1 atan2(const P32e1 y, const P32e1 x);

#endif

