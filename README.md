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

USING C FUNCTIONS
-----------------

FastSigmoid-c implements C types of the form p(N)e(ES)\_t.  These correspond to
Posit{N,ES}.  For example, p16e2_t represents Posit{16,2}.

_Functions_ are implemented as p(N)e(ES)\_(fun).  For example, p16e2_add is the
addition function over Posit{16,2}.  Under the hood, these functions wrap
conversion of the posit to the smallest IEEE floating point form, evaulation
using standard hardware, followed by conversion back to the posit form.

_NaN Exceptions_ are implemented using the setjmp/longjmp

Supported functions (described as p32e2_t but implemented for all types):

* `void p32e2_add(p32e2_t *res, p32e2_t *lhs, p32e2_t *rhs)`  *res <- lhs + rhs*
* `void p32e2_sub(p32e2_t *res, p32e2_t *lhs, p32e2_t *rhs)`  *res <- lhs - rhs*
* `void p32e2_mul(p32e2_t *res, p32e2_t *lhs, p32e2_t *rhs)`  *res <- lhs * rhs*
* `p32e2_t p32e2_addinv(p32e2_t arg)` *==> -arg*
* `bool p32e2_lt(p32e2_t lhs, p32e2_t rhs)` *==> lhs < rhs*
* `bool p32e2_lte(p32e2_t lhs, p32e2_t rhs)` *==> lhs <= rhs*
* `void p32e2_sub(p32e2_t *res, p32e2_t *lhs, p32e2_t *rhs)`  *res <- lhs / rhs*
* `p32e2_t p32e2_addinv(p32e2_t arg)`  *==> 1/arg*
* `p32e2_t p32e2_log2(p32e2_t arg)`  *==> log2(arg)*
* `p32e2_t p32e2_exp2(p32e2_t arg)`  *==> 2^(arg)*
* `void p32e2_fma(p32e2_t *res, p32e2_t *a, p32e2_t *b, p32e2_t *c,)`  *res <- a * b + c*
* `void p32e2_fms(p32e2_t *res, p32e2_t *a, p32e2_t *b, p32e2_t *c,)`  *res <- a * b - c*
* `void p32e2_nfma(p32e2_t *res, p32e2_t *a, p32e2_t *b, p32e2_t *c,)`  *res <- -(a * b) + c*
* `void p32e2_nfms(p32e2_t *res, p32e2_t *a, p32e2_t *b, p32e2_t *c,)`  *res <- -(a * b) - c*
* fas     - _fused add/scale_
* fcp     - _fused cross product_
* fdp     - _fused dot product_
* dpi     - _initialize dot product accumulator_
* `p32e2_t p32e2_sqrt(p32e2_t arg)`  *==> sqrt(arg)*
* `p32e2_t p32e2_log1p(p32e2_t arg)`  *==> ln(arg + 1)*
* `p32e2_t p32e2_log(p32e2_t arg)`  *==> ln(arg)*
* `p32e2_t p32e2_log10(p32e2_t arg)`  *==> log10(arg)*
* `p32e2_t p32e2_exp(p32e2_t arg)`  *==> e^(arg)*
* `p32e2_t p32e2_pow(p32e2_t lhs, p32e2_t rhs)`  *==> (lhs)^(rhs)*
* `p32e2_t p32e2_logx(p32e2_t lhs, p32e2_t rhs)`  *==> log_lhs(rhs)*
* `p32e2_t p32e2_sin(p32e2_t arg)`  *==> sin(arg)*
* `p32e2_t p32e2_cos(p32e2_t arg)`  *==> cos(arg)*
* `p32e2_t p32e2_atan(p32e2_t arg)`  *==> atan(arg)*
* `p32e2_t p32e2_atan2(p32e2_t y, p32e2_t x)`  *==> atan(y/x)*

_italic_ functions are not currently implemented.
