FastSigmoid
===========

FastSigmoid-c
=============

FastSigmoid-c is a hybrid C/C++ library for the deployment of posit numerical
types.  By default, it implements the following posit environments:

* Posit{8,0}
* Posit{8,1}
* Posit{8,2}
* Posit{16,0}
* Posit{16,1}
* Posit{16,2}
* Posit{32,0}
* Posit{32,1}
* Posit{32,2}
* Posit{32,3}

Support for 64- bit environments is forthcoming.

USE
---

FastSigmoid-c implements C types of the form p(N)e(ES)\_t.  These correspond to
Posit{N,ES}.  For example, p16e2_t represents Posit{16,2}.

Functions are implemented as p(N)e(ES)\_(fun).  For example, p16e2_add is the
addition function over Posit{16,2}.  Under the hood, these functions wrap
conversion of the posit to the smallest IEEE floating point form, evaulation
using standard hardware, followed by conversion back to the posit form.

Supported functions:
* `void p16e0_add(p16e0_t *res, p16e0_t *lhs, p16e0_t *rhs)`  res <- lhs + rhs
* `void p16e0_sub(p16e0_t *res, p16e0_t *lhs, p16e0_t *rhs)`  res <- lhs - rhs
* `void p16e0_mul(p16e0_t *res, p16e0_t *lhs, p16e0_t *rhs)`  res <- lhs * rhs
* `p16e0_t p16e0_addinv(p16e0_t arg)`  ==> -arg
* `bool p16e0_lt(p16e0_t lhs, p16e0_t rhs)` ==> lhs < rhs
* `bool p16e0_lte(p16e0_t lhs, p16e0_t rhs)` ==> lhs <= rhs
* `void p16e0_sub(p16e0_t *res, p16e0_t *lhs, p16e0_t *rhs)`  res <- lhs / rhs
* `p16e0_t p16e0_addinv(p16e0_t arg)`  ==> 1/arg
* `p16e0_t p16e0_log2(p16e0_t arg)`  ==> log2(arg)
* `p16e0_t p16e0_exp2(p16e0_t arg)`  ==> 2^(arg)
* `void p16e0_fma(p16e0_t *res, p16e0_t *a, p16e0_t *b, p16e0_t *c,)`  res <- a * b + c
* `void p16e0_fms(p16e0_t *res, p16e0_t *a, p16e0_t *b, p16e0_t *c,)`  res <- a * b - c
* `void p16e0_nfma(p16e0_t *res, p16e0_t *a, p16e0_t *b, p16e0_t *c,)`  res <- -(a * b) + c
* `void p16e0_nfms(p16e0_t *res, p16e0_t *a, p16e0_t *b, p16e0_t *c,)`  res <- -(a * b) - c
* fas     - _fused add/scale_
* fcp     - _fused cross product_
* fdp     - _fused dot product_
* dpi     - _initialize dot product accumulator_
* `p16e0_t p16e0_sqrt(p16e0_t arg)`  ==> sqrt(arg)
* `p16e0_t p16e0_log1p(p16e0_t arg)`  ==> ln(arg + 1)
* `p16e0_t p16e0_log(p16e0_t arg)`  ==> ln(arg)
* `p16e0_t p16e0_log10(p16e0_t arg)`  ==> log10(arg)
* `p16e0_t p16e0_exp(p16e0_t arg)`  ==> e^(arg)
* `p16e0_t p16e0_pow(p16e0_t lhs, p16e0_t rhs)`  ==> (lhs)^(rhs)
* `p16e0_t p16e0_logx(p16e0_t lhs, p16e0_t rhs)`  ==> log_lhs(rhs)
* `p16e0_t p16e0_sin(p16e0_t arg)`  ==> sin(arg)
* `p16e0_t p16e0_cos(p16e0_t arg)`  ==> cos(arg)
* `p16e0_t p16e0_atan(p16e0_t arg)`  ==> atan(arg)
* `p16e0_t p16e0_atan2(p16e0_t y, p16e0_t x)`  ==> atan(y/x)

_italic_ functions are not currently implemented.
