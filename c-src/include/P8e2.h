#ifndef POSIT_8_2_H
#define POSIT_8_2_H

class P8e2{
  private:
    uint8_t data;
  public:

    //various public constructors
    P8e2();             //defaults to zero
    P8e2(float);        //conversion constructor from IEEE32
    P8e2(double);       //conversion constructor from IEEE64
    P8e2(P8e2);   //copy constructor
    P8e2(p8e2_t);   //bridge constructor from c functionality.

    //public operators
    P8e2 operator +(const P8e2 rhs);
    P8e2 operator -(const P8e2 rhs);
    P8e2 operator *(const P8e2 rhs);
    P8e2 &operator +=(const P8e2 rhs);
    P8e2 &operator -=(const P8e2 rhs);
    P8e2 &operator *=(const P8e2 rhs);
    bool operator <(const P8e2 rhs);
    bool operator <=(const P8e2 rhs);
    bool operator >(const P8e2 rhs);
    bool operator >=(const P8e2 rhs);
    P8e2 operator /(const P8e2 rhs);
    P8e2 &operator /=(const P8e2 rhs);

    //external friended operators
    friend P8e2 operator -(const P8e2 rhs);
    friend P8e2 operator float(const P8e2 rhs);
    friend P8e2 operator double(const P8e2 rhs);

    //friended functions
    friend P8e2 mulinv(const P8e2 arg);
    friend P8e2 log2(const P8e2 arg);
    friend P8e2 exp2(const P8e2 arg);
    friend P8e2 fma(const P8e2 a, const P8e2 b, const P8e2 c);
    friend P8e2 fms(const P8e2 a, const P8e2 b, const P8e2 c);
    friend P8e2 nfma(const P8e2 a, const P8e2 b, const P8e2 c);
    friend P8e2 nfms(const P8e2 a, const P8e2 b, const P8e2 c);
    friend P8e2 sqrt(const P8e2 arg);
    friend P8e2 log1p(const P8e2 arg);
    friend P8e2 log(const P8e2 arg);
    friend P8e2 log10(const P8e2 arg);
    friend P8e2 exp(const P8e2 arg);
    friend P8e2 pow(const P8e2 lhs, const P8e2 rhs);
    friend P8e2 sin(const P8e2 arg);
    friend P8e2 cos(const P8e2 arg);
    friend P8e2 atan(const P8e2 arg);
    friend P8e2 atan2(const P8e2 y, const P8e2 x);
}

//redeclaration of the functions that were just friended
P8e2 operator -(const P8e2 rhs);
P8e2 operator float(const P8e2 rhs);
P8e2 operator double(const P8e2 rhs);



P8e2 mulinv(const P8e2 arg);
P8e2 log2(const P8e2 arg);
P8e2 exp2(const P8e2 arg);
P8e2 fma(const P8e2 a, const P8e2 b, const P8e2 c);
P8e2 fms(const P8e2 a, const P8e2 b, const P8e2 c);
P8e2 nfma(const P8e2 a, const P8e2 b, const P8e2 c);
P8e2 nfms(const P8e2 a, const P8e2 b, const P8e2 c);
P8e2 sqrt(const P8e2 arg);
P8e2 log1p(const P8e2 arg);
P8e2 log(const P8e2 arg);
P8e2 log10(const P8e2 arg);
P8e2 exp(const P8e2 arg);
P8e2 pow(const P8e2 lhs, const P8e2 rhs);
P8e2 sin(const P8e2 arg);
P8e2 cos(const P8e2 arg);
P8e2 atan(const P8e2 arg);
P8e2 atan2(const P8e2 y, const P8e2 x);

#endif

