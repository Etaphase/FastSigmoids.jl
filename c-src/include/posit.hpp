#ifndef __POSIT_HPP
#define __POSIT_HPP

class P8e0{
  private:

  public:
    P8e0();                                     //blank constructor which initializes to zero
    P8e0(const double);                         //constructor which takes a double
    P8e0(const p8e0_t);                     //constructor which takes the c type

    //direct operators
    P8e0 operator +(const P8e0); 
    P8e0 operator -(const P8e0); 
    P8e0 operator *(const P8e0); 
    P8e0 operator /(const P8e0); 
    P8e0 &operator +=(const P8e0); 
    P8e0 &operator -=(const P8e0); 
    P8e0 &operator *=(const P8e0); 
    P8e0 &operator /=(const P8e0); 
    bool operator <(const P8e0); 
    bool operator >(const P8e0); 
    bool operator <=(const P8e0); 
    bool operator >=(const P8e0); 
    bool operator ==(const P8e0); 
    bool operator !=(const P8e0);

    //conversion operators

    friend double operator double(const P8e0);  //explicit conversion to double
    friend P8e0 operator P8e0(const double);
    friend P8e0 operator P8e0(const int64_t);

    //friended functions
    friend P8e0 mulinv(const P8e0 a); 
    friend P8e0 log2(const P8e0 a); 
    friend P8e0 exp2(const P8e0 a); 
    friend P8e0 fma(const P8e0 a, const P8e0 b, const P8e0 c); 
    friend P8e0 fms(const P8e0 a, const P8e0 b, const P8e0 c); 
    friend P8e0 nfma(const P8e0 a, const P8e0 b, const P8e0 c); 
    friend P8e0 nfms(const P8e0 a, const P8e0 b, const P8e0 c); 
    friend P8e0 fas(const P8e0 a, const P8e0 b, const P8e0 c); 
    friend P8e0 fcp(const P8e0 a, const P8e0 b, const P8e0 c, const P8e0 d); 
    friend P8e0 sqrt(const P8e0 a); 
    friend P8e0 log1p(const P8e0 a); 
    friend P8e0 log(const P8e0 a); 
    friend P8e0 log10(const P8e0 a); 
    friend P8e0 exp(const P8e0 a); 
    friend P8e0 pow(const P8e0 a, const P8e0 b); 
    friend P8e0 logx(const P8e0 a, const P8e0 b); 
    friend P8e0 sin(const P8e0 a); 
    friend P8e0 cos(const P8e0 a); 
    friend P8e0 atan(const P8e0 a); 
    friend P8e0 atan2(const P8e0 a, const P8e0 b);

}
class P8e1{
  private:

  public:
    P8e1();                                     //blank constructor which initializes to zero
    P8e1(const double);                         //constructor which takes a double
    P8e1(const p8e1_t);                     //constructor which takes the c type

    //direct operators
    P8e1 operator +(const P8e1); 
    P8e1 operator -(const P8e1); 
    P8e1 operator *(const P8e1); 
    P8e1 operator /(const P8e1); 
    P8e1 &operator +=(const P8e1); 
    P8e1 &operator -=(const P8e1); 
    P8e1 &operator *=(const P8e1); 
    P8e1 &operator /=(const P8e1); 
    bool operator <(const P8e1); 
    bool operator >(const P8e1); 
    bool operator <=(const P8e1); 
    bool operator >=(const P8e1); 
    bool operator ==(const P8e1); 
    bool operator !=(const P8e1);

    //conversion operators

    friend double operator double(const P8e1);  //explicit conversion to double
    friend P8e1 operator P8e1(const double);
    friend P8e1 operator P8e1(const int64_t);

    //friended functions
    friend P8e1 mulinv(const P8e1 a); 
    friend P8e1 log2(const P8e1 a); 
    friend P8e1 exp2(const P8e1 a); 
    friend P8e1 fma(const P8e1 a, const P8e1 b, const P8e1 c); 
    friend P8e1 fms(const P8e1 a, const P8e1 b, const P8e1 c); 
    friend P8e1 nfma(const P8e1 a, const P8e1 b, const P8e1 c); 
    friend P8e1 nfms(const P8e1 a, const P8e1 b, const P8e1 c); 
    friend P8e1 fas(const P8e1 a, const P8e1 b, const P8e1 c); 
    friend P8e1 fcp(const P8e1 a, const P8e1 b, const P8e1 c, const P8e1 d); 
    friend P8e1 sqrt(const P8e1 a); 
    friend P8e1 log1p(const P8e1 a); 
    friend P8e1 log(const P8e1 a); 
    friend P8e1 log10(const P8e1 a); 
    friend P8e1 exp(const P8e1 a); 
    friend P8e1 pow(const P8e1 a, const P8e1 b); 
    friend P8e1 logx(const P8e1 a, const P8e1 b); 
    friend P8e1 sin(const P8e1 a); 
    friend P8e1 cos(const P8e1 a); 
    friend P8e1 atan(const P8e1 a); 
    friend P8e1 atan2(const P8e1 a, const P8e1 b);

}
class P8e2{
  private:

  public:
    P8e2();                                     //blank constructor which initializes to zero
    P8e2(const double);                         //constructor which takes a double
    P8e2(const p8e2_t);                     //constructor which takes the c type

    //direct operators
    P8e2 operator +(const P8e2); 
    P8e2 operator -(const P8e2); 
    P8e2 operator *(const P8e2); 
    P8e2 operator /(const P8e2); 
    P8e2 &operator +=(const P8e2); 
    P8e2 &operator -=(const P8e2); 
    P8e2 &operator *=(const P8e2); 
    P8e2 &operator /=(const P8e2); 
    bool operator <(const P8e2); 
    bool operator >(const P8e2); 
    bool operator <=(const P8e2); 
    bool operator >=(const P8e2); 
    bool operator ==(const P8e2); 
    bool operator !=(const P8e2);

    //conversion operators

    friend double operator double(const P8e2);  //explicit conversion to double
    friend P8e2 operator P8e2(const double);
    friend P8e2 operator P8e2(const int64_t);

    //friended functions
    friend P8e2 mulinv(const P8e2 a); 
    friend P8e2 log2(const P8e2 a); 
    friend P8e2 exp2(const P8e2 a); 
    friend P8e2 fma(const P8e2 a, const P8e2 b, const P8e2 c); 
    friend P8e2 fms(const P8e2 a, const P8e2 b, const P8e2 c); 
    friend P8e2 nfma(const P8e2 a, const P8e2 b, const P8e2 c); 
    friend P8e2 nfms(const P8e2 a, const P8e2 b, const P8e2 c); 
    friend P8e2 fas(const P8e2 a, const P8e2 b, const P8e2 c); 
    friend P8e2 fcp(const P8e2 a, const P8e2 b, const P8e2 c, const P8e2 d); 
    friend P8e2 sqrt(const P8e2 a); 
    friend P8e2 log1p(const P8e2 a); 
    friend P8e2 log(const P8e2 a); 
    friend P8e2 log10(const P8e2 a); 
    friend P8e2 exp(const P8e2 a); 
    friend P8e2 pow(const P8e2 a, const P8e2 b); 
    friend P8e2 logx(const P8e2 a, const P8e2 b); 
    friend P8e2 sin(const P8e2 a); 
    friend P8e2 cos(const P8e2 a); 
    friend P8e2 atan(const P8e2 a); 
    friend P8e2 atan2(const P8e2 a, const P8e2 b);

}

class P16e0{
  private:

  public:
    P16e0();                                     //blank constructor which initializes to zero
    P16e0(const double);                         //constructor which takes a double
    P16e0(const p16e0_t);                     //constructor which takes the c type

    //direct operators
    P16e0 operator +(const P16e0); 
    P16e0 operator -(const P16e0); 
    P16e0 operator *(const P16e0); 
    P16e0 operator /(const P16e0); 
    P16e0 &operator +=(const P16e0); 
    P16e0 &operator -=(const P16e0); 
    P16e0 &operator *=(const P16e0); 
    P16e0 &operator /=(const P16e0); 
    bool operator <(const P16e0); 
    bool operator >(const P16e0); 
    bool operator <=(const P16e0); 
    bool operator >=(const P16e0); 
    bool operator ==(const P16e0); 
    bool operator !=(const P16e0);

    //conversion operators

    friend double operator double(const P16e0);  //explicit conversion to double
    friend P16e0 operator P16e0(const double);
    friend P16e0 operator P16e0(const int64_t);

    //friended functions
    friend P16e0 mulinv(const P16e0 a); 
    friend P16e0 log2(const P16e0 a); 
    friend P16e0 exp2(const P16e0 a); 
    friend P16e0 fma(const P16e0 a, const P16e0 b, const P16e0 c); 
    friend P16e0 fms(const P16e0 a, const P16e0 b, const P16e0 c); 
    friend P16e0 nfma(const P16e0 a, const P16e0 b, const P16e0 c); 
    friend P16e0 nfms(const P16e0 a, const P16e0 b, const P16e0 c); 
    friend P16e0 fas(const P16e0 a, const P16e0 b, const P16e0 c); 
    friend P16e0 fcp(const P16e0 a, const P16e0 b, const P16e0 c, const P16e0 d); 
    friend P16e0 sqrt(const P16e0 a); 
    friend P16e0 log1p(const P16e0 a); 
    friend P16e0 log(const P16e0 a); 
    friend P16e0 log10(const P16e0 a); 
    friend P16e0 exp(const P16e0 a); 
    friend P16e0 pow(const P16e0 a, const P16e0 b); 
    friend P16e0 logx(const P16e0 a, const P16e0 b); 
    friend P16e0 sin(const P16e0 a); 
    friend P16e0 cos(const P16e0 a); 
    friend P16e0 atan(const P16e0 a); 
    friend P16e0 atan2(const P16e0 a, const P16e0 b);

}
class P16e1{
  private:

  public:
    P16e1();                                     //blank constructor which initializes to zero
    P16e1(const double);                         //constructor which takes a double
    P16e1(const p16e1_t);                     //constructor which takes the c type

    //direct operators
    P16e1 operator +(const P16e1); 
    P16e1 operator -(const P16e1); 
    P16e1 operator *(const P16e1); 
    P16e1 operator /(const P16e1); 
    P16e1 &operator +=(const P16e1); 
    P16e1 &operator -=(const P16e1); 
    P16e1 &operator *=(const P16e1); 
    P16e1 &operator /=(const P16e1); 
    bool operator <(const P16e1); 
    bool operator >(const P16e1); 
    bool operator <=(const P16e1); 
    bool operator >=(const P16e1); 
    bool operator ==(const P16e1); 
    bool operator !=(const P16e1);

    //conversion operators

    friend double operator double(const P16e1);  //explicit conversion to double
    friend P16e1 operator P16e1(const double);
    friend P16e1 operator P16e1(const int64_t);

    //friended functions
    friend P16e1 mulinv(const P16e1 a); 
    friend P16e1 log2(const P16e1 a); 
    friend P16e1 exp2(const P16e1 a); 
    friend P16e1 fma(const P16e1 a, const P16e1 b, const P16e1 c); 
    friend P16e1 fms(const P16e1 a, const P16e1 b, const P16e1 c); 
    friend P16e1 nfma(const P16e1 a, const P16e1 b, const P16e1 c); 
    friend P16e1 nfms(const P16e1 a, const P16e1 b, const P16e1 c); 
    friend P16e1 fas(const P16e1 a, const P16e1 b, const P16e1 c); 
    friend P16e1 fcp(const P16e1 a, const P16e1 b, const P16e1 c, const P16e1 d); 
    friend P16e1 sqrt(const P16e1 a); 
    friend P16e1 log1p(const P16e1 a); 
    friend P16e1 log(const P16e1 a); 
    friend P16e1 log10(const P16e1 a); 
    friend P16e1 exp(const P16e1 a); 
    friend P16e1 pow(const P16e1 a, const P16e1 b); 
    friend P16e1 logx(const P16e1 a, const P16e1 b); 
    friend P16e1 sin(const P16e1 a); 
    friend P16e1 cos(const P16e1 a); 
    friend P16e1 atan(const P16e1 a); 
    friend P16e1 atan2(const P16e1 a, const P16e1 b);

}
class P16e2{
  private:

  public:
    P16e2();                                     //blank constructor which initializes to zero
    P16e2(const double);                         //constructor which takes a double
    P16e2(const p16e2_t);                     //constructor which takes the c type

    //direct operators
    P16e2 operator +(const P16e2); 
    P16e2 operator -(const P16e2); 
    P16e2 operator *(const P16e2); 
    P16e2 operator /(const P16e2); 
    P16e2 &operator +=(const P16e2); 
    P16e2 &operator -=(const P16e2); 
    P16e2 &operator *=(const P16e2); 
    P16e2 &operator /=(const P16e2); 
    bool operator <(const P16e2); 
    bool operator >(const P16e2); 
    bool operator <=(const P16e2); 
    bool operator >=(const P16e2); 
    bool operator ==(const P16e2); 
    bool operator !=(const P16e2);

    //conversion operators

    friend double operator double(const P16e2);  //explicit conversion to double
    friend P16e2 operator P16e2(const double);
    friend P16e2 operator P16e2(const int64_t);

    //friended functions
    friend P16e2 mulinv(const P16e2 a); 
    friend P16e2 log2(const P16e2 a); 
    friend P16e2 exp2(const P16e2 a); 
    friend P16e2 fma(const P16e2 a, const P16e2 b, const P16e2 c); 
    friend P16e2 fms(const P16e2 a, const P16e2 b, const P16e2 c); 
    friend P16e2 nfma(const P16e2 a, const P16e2 b, const P16e2 c); 
    friend P16e2 nfms(const P16e2 a, const P16e2 b, const P16e2 c); 
    friend P16e2 fas(const P16e2 a, const P16e2 b, const P16e2 c); 
    friend P16e2 fcp(const P16e2 a, const P16e2 b, const P16e2 c, const P16e2 d); 
    friend P16e2 sqrt(const P16e2 a); 
    friend P16e2 log1p(const P16e2 a); 
    friend P16e2 log(const P16e2 a); 
    friend P16e2 log10(const P16e2 a); 
    friend P16e2 exp(const P16e2 a); 
    friend P16e2 pow(const P16e2 a, const P16e2 b); 
    friend P16e2 logx(const P16e2 a, const P16e2 b); 
    friend P16e2 sin(const P16e2 a); 
    friend P16e2 cos(const P16e2 a); 
    friend P16e2 atan(const P16e2 a); 
    friend P16e2 atan2(const P16e2 a, const P16e2 b);

}

class P32e0{
  private:

  public:
    P32e0();                                     //blank constructor which initializes to zero
    P32e0(const double);                         //constructor which takes a double
    P32e0(const p32e0_t);                     //constructor which takes the c type

    //direct operators
    P32e0 operator +(const P32e0); 
    P32e0 operator -(const P32e0); 
    P32e0 operator *(const P32e0); 
    P32e0 operator /(const P32e0); 
    P32e0 &operator +=(const P32e0); 
    P32e0 &operator -=(const P32e0); 
    P32e0 &operator *=(const P32e0); 
    P32e0 &operator /=(const P32e0); 
    bool operator <(const P32e0); 
    bool operator >(const P32e0); 
    bool operator <=(const P32e0); 
    bool operator >=(const P32e0); 
    bool operator ==(const P32e0); 
    bool operator !=(const P32e0);

    //conversion operators

    friend double operator double(const P32e0);  //explicit conversion to double
    friend P32e0 operator P32e0(const double);
    friend P32e0 operator P32e0(const int64_t);

    //friended functions
    friend P32e0 mulinv(const P32e0 a); 
    friend P32e0 log2(const P32e0 a); 
    friend P32e0 exp2(const P32e0 a); 
    friend P32e0 fma(const P32e0 a, const P32e0 b, const P32e0 c); 
    friend P32e0 fms(const P32e0 a, const P32e0 b, const P32e0 c); 
    friend P32e0 nfma(const P32e0 a, const P32e0 b, const P32e0 c); 
    friend P32e0 nfms(const P32e0 a, const P32e0 b, const P32e0 c); 
    friend P32e0 fas(const P32e0 a, const P32e0 b, const P32e0 c); 
    friend P32e0 fcp(const P32e0 a, const P32e0 b, const P32e0 c, const P32e0 d); 
    friend P32e0 sqrt(const P32e0 a); 
    friend P32e0 log1p(const P32e0 a); 
    friend P32e0 log(const P32e0 a); 
    friend P32e0 log10(const P32e0 a); 
    friend P32e0 exp(const P32e0 a); 
    friend P32e0 pow(const P32e0 a, const P32e0 b); 
    friend P32e0 logx(const P32e0 a, const P32e0 b); 
    friend P32e0 sin(const P32e0 a); 
    friend P32e0 cos(const P32e0 a); 
    friend P32e0 atan(const P32e0 a); 
    friend P32e0 atan2(const P32e0 a, const P32e0 b);

}
class P32e1{
  private:

  public:
    P32e1();                                     //blank constructor which initializes to zero
    P32e1(const double);                         //constructor which takes a double
    P32e1(const p32e1_t);                     //constructor which takes the c type

    //direct operators
    P32e1 operator +(const P32e1); 
    P32e1 operator -(const P32e1); 
    P32e1 operator *(const P32e1); 
    P32e1 operator /(const P32e1); 
    P32e1 &operator +=(const P32e1); 
    P32e1 &operator -=(const P32e1); 
    P32e1 &operator *=(const P32e1); 
    P32e1 &operator /=(const P32e1); 
    bool operator <(const P32e1); 
    bool operator >(const P32e1); 
    bool operator <=(const P32e1); 
    bool operator >=(const P32e1); 
    bool operator ==(const P32e1); 
    bool operator !=(const P32e1);

    //conversion operators

    friend double operator double(const P32e1);  //explicit conversion to double
    friend P32e1 operator P32e1(const double);
    friend P32e1 operator P32e1(const int64_t);

    //friended functions
    friend P32e1 mulinv(const P32e1 a); 
    friend P32e1 log2(const P32e1 a); 
    friend P32e1 exp2(const P32e1 a); 
    friend P32e1 fma(const P32e1 a, const P32e1 b, const P32e1 c); 
    friend P32e1 fms(const P32e1 a, const P32e1 b, const P32e1 c); 
    friend P32e1 nfma(const P32e1 a, const P32e1 b, const P32e1 c); 
    friend P32e1 nfms(const P32e1 a, const P32e1 b, const P32e1 c); 
    friend P32e1 fas(const P32e1 a, const P32e1 b, const P32e1 c); 
    friend P32e1 fcp(const P32e1 a, const P32e1 b, const P32e1 c, const P32e1 d); 
    friend P32e1 sqrt(const P32e1 a); 
    friend P32e1 log1p(const P32e1 a); 
    friend P32e1 log(const P32e1 a); 
    friend P32e1 log10(const P32e1 a); 
    friend P32e1 exp(const P32e1 a); 
    friend P32e1 pow(const P32e1 a, const P32e1 b); 
    friend P32e1 logx(const P32e1 a, const P32e1 b); 
    friend P32e1 sin(const P32e1 a); 
    friend P32e1 cos(const P32e1 a); 
    friend P32e1 atan(const P32e1 a); 
    friend P32e1 atan2(const P32e1 a, const P32e1 b);

}
class P32e2{
  private:

  public:
    P32e2();                                     //blank constructor which initializes to zero
    P32e2(const double);                         //constructor which takes a double
    P32e2(const p32e2_t);                     //constructor which takes the c type

    //direct operators
    P32e2 operator +(const P32e2); 
    P32e2 operator -(const P32e2); 
    P32e2 operator *(const P32e2); 
    P32e2 operator /(const P32e2); 
    P32e2 &operator +=(const P32e2); 
    P32e2 &operator -=(const P32e2); 
    P32e2 &operator *=(const P32e2); 
    P32e2 &operator /=(const P32e2); 
    bool operator <(const P32e2); 
    bool operator >(const P32e2); 
    bool operator <=(const P32e2); 
    bool operator >=(const P32e2); 
    bool operator ==(const P32e2); 
    bool operator !=(const P32e2);

    //conversion operators

    friend double operator double(const P32e2);  //explicit conversion to double
    friend P32e2 operator P32e2(const double);
    friend P32e2 operator P32e2(const int64_t);

    //friended functions
    friend P32e2 mulinv(const P32e2 a); 
    friend P32e2 log2(const P32e2 a); 
    friend P32e2 exp2(const P32e2 a); 
    friend P32e2 fma(const P32e2 a, const P32e2 b, const P32e2 c); 
    friend P32e2 fms(const P32e2 a, const P32e2 b, const P32e2 c); 
    friend P32e2 nfma(const P32e2 a, const P32e2 b, const P32e2 c); 
    friend P32e2 nfms(const P32e2 a, const P32e2 b, const P32e2 c); 
    friend P32e2 fas(const P32e2 a, const P32e2 b, const P32e2 c); 
    friend P32e2 fcp(const P32e2 a, const P32e2 b, const P32e2 c, const P32e2 d); 
    friend P32e2 sqrt(const P32e2 a); 
    friend P32e2 log1p(const P32e2 a); 
    friend P32e2 log(const P32e2 a); 
    friend P32e2 log10(const P32e2 a); 
    friend P32e2 exp(const P32e2 a); 
    friend P32e2 pow(const P32e2 a, const P32e2 b); 
    friend P32e2 logx(const P32e2 a, const P32e2 b); 
    friend P32e2 sin(const P32e2 a); 
    friend P32e2 cos(const P32e2 a); 
    friend P32e2 atan(const P32e2 a); 
    friend P32e2 atan2(const P32e2 a, const P32e2 b);

}
class P32e3{
  private:

  public:
    P32e3();                                     //blank constructor which initializes to zero
    P32e3(const double);                         //constructor which takes a double
    P32e3(const p32e3_t);                     //constructor which takes the c type

    //direct operators
    P32e3 operator +(const P32e3); 
    P32e3 operator -(const P32e3); 
    P32e3 operator *(const P32e3); 
    P32e3 operator /(const P32e3); 
    P32e3 &operator +=(const P32e3); 
    P32e3 &operator -=(const P32e3); 
    P32e3 &operator *=(const P32e3); 
    P32e3 &operator /=(const P32e3); 
    bool operator <(const P32e3); 
    bool operator >(const P32e3); 
    bool operator <=(const P32e3); 
    bool operator >=(const P32e3); 
    bool operator ==(const P32e3); 
    bool operator !=(const P32e3);

    //conversion operators

    friend double operator double(const P32e3);  //explicit conversion to double
    friend P32e3 operator P32e3(const double);
    friend P32e3 operator P32e3(const int64_t);

    //friended functions
    friend P32e3 mulinv(const P32e3 a); 
    friend P32e3 log2(const P32e3 a); 
    friend P32e3 exp2(const P32e3 a); 
    friend P32e3 fma(const P32e3 a, const P32e3 b, const P32e3 c); 
    friend P32e3 fms(const P32e3 a, const P32e3 b, const P32e3 c); 
    friend P32e3 nfma(const P32e3 a, const P32e3 b, const P32e3 c); 
    friend P32e3 nfms(const P32e3 a, const P32e3 b, const P32e3 c); 
    friend P32e3 fas(const P32e3 a, const P32e3 b, const P32e3 c); 
    friend P32e3 fcp(const P32e3 a, const P32e3 b, const P32e3 c, const P32e3 d); 
    friend P32e3 sqrt(const P32e3 a); 
    friend P32e3 log1p(const P32e3 a); 
    friend P32e3 log(const P32e3 a); 
    friend P32e3 log10(const P32e3 a); 
    friend P32e3 exp(const P32e3 a); 
    friend P32e3 pow(const P32e3 a, const P32e3 b); 
    friend P32e3 logx(const P32e3 a, const P32e3 b); 
    friend P32e3 sin(const P32e3 a); 
    friend P32e3 cos(const P32e3 a); 
    friend P32e3 atan(const P32e3 a); 
    friend P32e3 atan2(const P32e3 a, const P32e3 b);

}

#endif
