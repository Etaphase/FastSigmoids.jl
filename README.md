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
* add     - binary addition
* sub     - binary subtraction
* mul     - binary multiplicaton
* addinv  - additive inverse
* lt      - less than
* lte     - less than or equal to
* div     - division
* mulinv  - multiplactive inverse
* log2    - logarithm base 2
* exp2    - exponential base 2
* fma     - fused multiply add
* fms     - fused multiply subtract
* nfma    - negative fused multiply add
* nfms    - negative fused multiply subtract
* fas     - _fused add/scale_
* fcp     - _fused cross product_
* fdp     - _fused dot product_
* dpi     - _initialize dot product accumulator_
* sqrt    - square root
* log1p   - logarithm base e of (argument + 1)
* log     - logarithm base e
* log10   - logarithm base 10
* exp     - exponential base e
* pow     - arbitrary base exponential
* logx    - arbitrary base logarithm
* sin     - trigonometric sine
* cos     - trigonometric cosine
* atan    - trigonometric arctangent
* atan2   - trigonometric arctangent with coordinate arguments

_italic_ functions are not currently implemented.

Specific functions
------------------

all functions in this section use Posit{16,0} as the example posit type


    void p16e0_add(p16e0_t \*res, p16e0_t \*lhs, p16e0_t \*rhs)

computes lhs + rhs and overwrites the value in res.


    void p16e0_sub(p16e0_t \*res, p16e0_t \*lhs, p16e0_t \*rhs)
    
computes rhs + lhs and overwrites the value in res.






* sub     - binary subtraction
* mul     - binary multiplicaton
