#include "include/posit.h"
#include "include/posit_conv.h"
#include <stdio.h>

extern "C" void p8e0_add(p8e0_t *res, p8e0_t *lhs, p8e0_t *rhs){
    bool lhs_inf = (lhs->udata == P8INF);
    bool rhs_inf = (rhs->udata == P8INF);

    if (lhs_inf || rhs_inf) {
      if (lhs_inf && rhs_inf) { throw_nan_jmp(); }
      res->udata = P8INF;
      return;
    }

    //throw or long jump with the global NaNJump on addition of two infinities.

    float fres = p8e0_to_f(*lhs) + p8e0_to_f(*rhs);

    //check to see if we became infinity.
    if (!isfinite(fres)){
      //turn it into infinity.
      if (lhs_inf || rhs_inf) { res->udata = P8INF; }
      //check the sign and assign maxreal/minreal
      res->udata = (fres > 0) ? P8MAXREAL : P8MINREAL;
    };

    //in the basic case, just output the result.
    *res = f_to_p8e0(fres);
}
extern "C" void p8e1_add(p8e1_t *res, p8e1_t *lhs, p8e1_t *rhs){
    bool lhs_inf = (lhs->udata == P8INF);
    bool rhs_inf = (rhs->udata == P8INF);

    if (lhs_inf || rhs_inf) {
      if (lhs_inf && rhs_inf) { throw_nan_jmp(); }
      res->udata = P8INF;
      return;
    }

    //throw or long jump with the global NaNJump on addition of two infinities.

    float fres = p8e1_to_f(*lhs) + p8e1_to_f(*rhs);

    //check to see if we became infinity.
    if (!isfinite(fres)){
      //turn it into infinity.
      if (lhs_inf || rhs_inf) { res->udata = P8INF; }
      //check the sign and assign maxreal/minreal
      res->udata = (fres > 0) ? P8MAXREAL : P8MINREAL;
    };

    //in the basic case, just output the result.
    *res = f_to_p8e1(fres);
}
extern "C" void p8e2_add(p8e2_t *res, p8e2_t *lhs, p8e2_t *rhs){
    bool lhs_inf = (lhs->udata == P8INF);
    bool rhs_inf = (rhs->udata == P8INF);

    if (lhs_inf || rhs_inf) {
      if (lhs_inf && rhs_inf) { throw_nan_jmp(); }
      res->udata = P8INF;
      return;
    }

    //throw or long jump with the global NaNJump on addition of two infinities.

    float fres = p8e2_to_f(*lhs) + p8e2_to_f(*rhs);

    //check to see if we became infinity.
    if (!isfinite(fres)){
      //turn it into infinity.
      if (lhs_inf || rhs_inf) { res->udata = P8INF; }
      //check the sign and assign maxreal/minreal
      res->udata = (fres > 0) ? P8MAXREAL : P8MINREAL;
    };

    //in the basic case, just output the result.
    *res = f_to_p8e2(fres);
}
extern "C" void p16e0_add(p16e0_t *res, p16e0_t *lhs, p16e0_t *rhs){
    bool lhs_inf = (lhs->udata == P16INF);
    bool rhs_inf = (rhs->udata == P16INF);

    if (lhs_inf || rhs_inf) {
      if (lhs_inf && rhs_inf) { throw_nan_jmp(); }
      res->udata = P16INF;
      return;
    }

    //throw or long jump with the global NaNJump on addition of two infinities.

    float fres = p16e0_to_f(*lhs) + p16e0_to_f(*rhs);

    //check to see if we became infinity.
    if (!isfinite(fres)){
      //turn it into infinity.
      if (lhs_inf || rhs_inf) { res->udata = P16INF; }
      //check the sign and assign maxreal/minreal
      res->udata = (fres > 0) ? P16MAXREAL : P16MINREAL;
    };

    //in the basic case, just output the result.
    *res = f_to_p16e0(fres);
}
extern "C" void p16e1_add(p16e1_t *res, p16e1_t *lhs, p16e1_t *rhs){
    bool lhs_inf = (lhs->udata == P16INF);
    bool rhs_inf = (rhs->udata == P16INF);

    if (lhs_inf || rhs_inf) {
      if (lhs_inf && rhs_inf) { throw_nan_jmp(); }
      res->udata = P16INF;
      return;
    }

    //throw or long jump with the global NaNJump on addition of two infinities.

    float fres = p16e1_to_f(*lhs) + p16e1_to_f(*rhs);

    //check to see if we became infinity.
    if (!isfinite(fres)){
      //turn it into infinity.
      if (lhs_inf || rhs_inf) { res->udata = P16INF; }
      //check the sign and assign maxreal/minreal
      res->udata = (fres > 0) ? P16MAXREAL : P16MINREAL;
    };

    //in the basic case, just output the result.
    *res = f_to_p16e1(fres);
}
extern "C" void p16e2_add(p16e2_t *res, p16e2_t *lhs, p16e2_t *rhs){
    bool lhs_inf = (lhs->udata == P16INF);
    bool rhs_inf = (rhs->udata == P16INF);

    if (lhs_inf || rhs_inf) {
      if (lhs_inf && rhs_inf) { throw_nan_jmp(); }
      res->udata = P16INF;
      return;
    }

    //throw or long jump with the global NaNJump on addition of two infinities.

    float fres = p16e2_to_f(*lhs) + p16e2_to_f(*rhs);

    //check to see if we became infinity.
    if (!isfinite(fres)){
      //turn it into infinity.
      if (lhs_inf || rhs_inf) { res->udata = P16INF; }
      //check the sign and assign maxreal/minreal
      res->udata = (fres > 0) ? P16MAXREAL : P16MINREAL;
    };

    //in the basic case, just output the result.
    *res = f_to_p16e2(fres);
}
extern "C" void p32e0_add(p32e0_t *res, p32e0_t *lhs, p32e0_t *rhs){
    bool lhs_inf = (lhs->udata == P32INF);
    bool rhs_inf = (rhs->udata == P32INF);

    if (lhs_inf || rhs_inf) {
      if (lhs_inf && rhs_inf) { throw_nan_jmp(); }
      res->udata = P32INF;
      return;
    }

    //throw or long jump with the global NaNJump on addition of two infinities.

    double fres = p32e0_to_f(*lhs) + p32e0_to_f(*rhs);

    //check to see if we became infinity.
    if (!isfinite(fres)){
      //turn it into infinity.
      if (lhs_inf || rhs_inf) { res->udata = P32INF; }
      //check the sign and assign maxreal/minreal
      res->udata = (fres > 0) ? P32MAXREAL : P32MINREAL;
    };

    //in the basic case, just output the result.
    *res = f_to_p32e0(fres);
}
extern "C" void p32e1_add(p32e1_t *res, p32e1_t *lhs, p32e1_t *rhs){
    bool lhs_inf = (lhs->udata == P32INF);
    bool rhs_inf = (rhs->udata == P32INF);

    if (lhs_inf || rhs_inf) {
      if (lhs_inf && rhs_inf) { throw_nan_jmp(); }
      res->udata = P32INF;
      return;
    }

    //throw or long jump with the global NaNJump on addition of two infinities.

    double fres = p32e1_to_f(*lhs) + p32e1_to_f(*rhs);

    //check to see if we became infinity.
    if (!isfinite(fres)){
      //turn it into infinity.
      if (lhs_inf || rhs_inf) { res->udata = P32INF; }
      //check the sign and assign maxreal/minreal
      res->udata = (fres > 0) ? P32MAXREAL : P32MINREAL;
    };

    //in the basic case, just output the result.
    *res = f_to_p32e1(fres);
}
extern "C" void p32e2_add(p32e2_t *res, p32e2_t *lhs, p32e2_t *rhs){
    bool lhs_inf = (lhs->udata == P32INF);
    bool rhs_inf = (rhs->udata == P32INF);

    if (lhs_inf || rhs_inf) {
      if (lhs_inf && rhs_inf) { throw_nan_jmp(); }
      res->udata = P32INF;
      return;
    }

    //throw or long jump with the global NaNJump on addition of two infinities.

    double fres = p32e2_to_f(*lhs) + p32e2_to_f(*rhs);

    //check to see if we became infinity.
    if (!isfinite(fres)){
      //turn it into infinity.
      if (lhs_inf || rhs_inf) { res->udata = P32INF; }
      //check the sign and assign maxreal/minreal
      res->udata = (fres > 0) ? P32MAXREAL : P32MINREAL;
    };

    //in the basic case, just output the result.
    *res = f_to_p32e2(fres);
}
extern "C" void p32e3_add(p32e3_t *res, p32e3_t *lhs, p32e3_t *rhs){
    bool lhs_inf = (lhs->udata == P32INF);
    bool rhs_inf = (rhs->udata == P32INF);

    if (lhs_inf || rhs_inf) {
      if (lhs_inf && rhs_inf) { throw_nan_jmp(); }
      res->udata = P32INF;
      return;
    }

    //throw or long jump with the global NaNJump on addition of two infinities.

    double fres = p32e3_to_f(*lhs) + p32e3_to_f(*rhs);

    //check to see if we became infinity.
    if (!isfinite(fres)){
      //turn it into infinity.
      if (lhs_inf || rhs_inf) { res->udata = P32INF; }
      //check the sign and assign maxreal/minreal
      res->udata = (fres > 0) ? P32MAXREAL : P32MINREAL;
    };

    //in the basic case, just output the result.
    *res = f_to_p32e3(fres);
}

extern "C" void p8e0_mul(p8e0_t *res, p8e0_t *lhs, p8e0_t *rhs){
    bool lhs_inf = (lhs->udata == P8INF);
    bool rhs_inf = (rhs->udata == P8INF);
    bool lhs_zer = (lhs->udata == P8ZER);
    bool rhs_zer = (rhs->udata == P8ZER);

    //long jump on multiplication of infinity times zero.
    if ( (lhs_inf && rhs_zer) || (rhs_inf && lhs_zer)) { throw_nan_jmp(); }

    float fres = p8e0_to_f(*lhs) * p8e0_to_f(*rhs);

    //check to see if we became infinity correctly.
    if (!isfinite(fres)){
      if (lhs_inf || rhs_inf) { res->udata = P8INF; }
      else {res->udata = (fres > 0) ? P8MAXREAL : P8MINREAL;}
      return;
    };

    //IEEE numbers underflow to zero.  sad!
    if (fres == 0){
      if (lhs_zer || rhs_zer) { res->udata = 0; }
      else {res->udata = (((lhs->udata & P8INF) ^ (rhs->udata & P8INF)) != 0) ? P8NEGSMALL : P8POSSMALL;}
      return;
    };

    //in the basic case, just output the result.
    *res = f_to_p8e0(fres);
}
extern "C" void p8e1_mul(p8e1_t *res, p8e1_t *lhs, p8e1_t *rhs){
    bool lhs_inf = (lhs->udata == P8INF);
    bool rhs_inf = (rhs->udata == P8INF);
    bool lhs_zer = (lhs->udata == P8ZER);
    bool rhs_zer = (rhs->udata == P8ZER);

    //long jump on multiplication of infinity times zero.
    if ( (lhs_inf && rhs_zer) || (rhs_inf && lhs_zer)) { throw_nan_jmp(); }

    float fres = p8e1_to_f(*lhs) * p8e1_to_f(*rhs);

    //check to see if we became infinity correctly.
    if (!isfinite(fres)){
      if (lhs_inf || rhs_inf) { res->udata = P8INF; }
      else {res->udata = (fres > 0) ? P8MAXREAL : P8MINREAL;}
      return;
    };

    //IEEE numbers underflow to zero.  sad!
    if (fres == 0){
      if (lhs_zer || rhs_zer) { res->udata = 0; }
      else {res->udata = (((lhs->udata & P8INF) ^ (rhs->udata & P8INF)) != 0) ? P8NEGSMALL : P8POSSMALL;}
      return;
    };

    //in the basic case, just output the result.
    *res = f_to_p8e1(fres);
}
extern "C" void p8e2_mul(p8e2_t *res, p8e2_t *lhs, p8e2_t *rhs){
    bool lhs_inf = (lhs->udata == P8INF);
    bool rhs_inf = (rhs->udata == P8INF);
    bool lhs_zer = (lhs->udata == P8ZER);
    bool rhs_zer = (rhs->udata == P8ZER);

    //long jump on multiplication of infinity times zero.
    if ( (lhs_inf && rhs_zer) || (rhs_inf && lhs_zer)) { throw_nan_jmp(); }

    float fres = p8e2_to_f(*lhs) * p8e2_to_f(*rhs);

    //check to see if we became infinity correctly.
    if (!isfinite(fres)){
      if (lhs_inf || rhs_inf) { res->udata = P8INF; }
      else {res->udata = (fres > 0) ? P8MAXREAL : P8MINREAL;}
      return;
    };

    //IEEE numbers underflow to zero.  sad!
    if (fres == 0){
      if (lhs_zer || rhs_zer) { res->udata = 0; }
      else {res->udata = (((lhs->udata & P8INF) ^ (rhs->udata & P8INF)) != 0) ? P8NEGSMALL : P8POSSMALL;}
      return;
    };

    //in the basic case, just output the result.
    *res = f_to_p8e2(fres);
}
extern "C" void p16e0_mul(p16e0_t *res, p16e0_t *lhs, p16e0_t *rhs){
    bool lhs_inf = (lhs->udata == P16INF);
    bool rhs_inf = (rhs->udata == P16INF);
    bool lhs_zer = (lhs->udata == P16ZER);
    bool rhs_zer = (rhs->udata == P16ZER);

    //long jump on multiplication of infinity times zero.
    if ( (lhs_inf && rhs_zer) || (rhs_inf && lhs_zer)) { throw_nan_jmp(); }

    float fres = p16e0_to_f(*lhs) * p16e0_to_f(*rhs);

    //check to see if we became infinity correctly.
    if (!isfinite(fres)){
      if (lhs_inf || rhs_inf) { res->udata = P16INF; }
      else {res->udata = (fres > 0) ? P16MAXREAL : P16MINREAL;}
      return;
    };

    //IEEE numbers underflow to zero.  sad!
    if (fres == 0){
      if (lhs_zer || rhs_zer) { res->udata = 0; }
      else {res->udata = (((lhs->udata & P16INF) ^ (rhs->udata & P16INF)) != 0) ? P16NEGSMALL : P16POSSMALL;}
      return;
    };

    //in the basic case, just output the result.
    *res = f_to_p16e0(fres);
}
extern "C" void p16e1_mul(p16e1_t *res, p16e1_t *lhs, p16e1_t *rhs){
    bool lhs_inf = (lhs->udata == P16INF);
    bool rhs_inf = (rhs->udata == P16INF);
    bool lhs_zer = (lhs->udata == P16ZER);
    bool rhs_zer = (rhs->udata == P16ZER);

    //long jump on multiplication of infinity times zero.
    if ( (lhs_inf && rhs_zer) || (rhs_inf && lhs_zer)) { throw_nan_jmp(); }

    float fres = p16e1_to_f(*lhs) * p16e1_to_f(*rhs);

    //check to see if we became infinity correctly.
    if (!isfinite(fres)){
      if (lhs_inf || rhs_inf) { res->udata = P16INF; }
      else {res->udata = (fres > 0) ? P16MAXREAL : P16MINREAL;}
      return;
    };

    //IEEE numbers underflow to zero.  sad!
    if (fres == 0){
      if (lhs_zer || rhs_zer) { res->udata = 0; }
      else {res->udata = (((lhs->udata & P16INF) ^ (rhs->udata & P16INF)) != 0) ? P16NEGSMALL : P16POSSMALL;}
      return;
    };

    //in the basic case, just output the result.
    *res = f_to_p16e1(fres);
}
extern "C" void p16e2_mul(p16e2_t *res, p16e2_t *lhs, p16e2_t *rhs){
    bool lhs_inf = (lhs->udata == P16INF);
    bool rhs_inf = (rhs->udata == P16INF);
    bool lhs_zer = (lhs->udata == P16ZER);
    bool rhs_zer = (rhs->udata == P16ZER);

    //long jump on multiplication of infinity times zero.
    if ( (lhs_inf && rhs_zer) || (rhs_inf && lhs_zer)) { throw_nan_jmp(); }

    float fres = p16e2_to_f(*lhs) * p16e2_to_f(*rhs);

    //check to see if we became infinity correctly.
    if (!isfinite(fres)){
      if (lhs_inf || rhs_inf) { res->udata = P16INF; }
      else {res->udata = (fres > 0) ? P16MAXREAL : P16MINREAL;}
      return;
    };

    //IEEE numbers underflow to zero.  sad!
    if (fres == 0){
      if (lhs_zer || rhs_zer) { res->udata = 0; }
      else {res->udata = (((lhs->udata & P16INF) ^ (rhs->udata & P16INF)) != 0) ? P16NEGSMALL : P16POSSMALL;}
      return;
    };

    //in the basic case, just output the result.
    *res = f_to_p16e2(fres);
}
extern "C" void p32e0_mul(p32e0_t *res, p32e0_t *lhs, p32e0_t *rhs){
    bool lhs_inf = (lhs->udata == P32INF);
    bool rhs_inf = (rhs->udata == P32INF);
    bool lhs_zer = (lhs->udata == P32ZER);
    bool rhs_zer = (rhs->udata == P32ZER);

    //long jump on multiplication of infinity times zero.
    if ( (lhs_inf && rhs_zer) || (rhs_inf && lhs_zer)) { throw_nan_jmp(); }

    double fres = p32e0_to_f(*lhs) * p32e0_to_f(*rhs);

    //check to see if we became infinity correctly.
    if (!isfinite(fres)){
      if (lhs_inf || rhs_inf) { res->udata = P32INF; }
      else {res->udata = (fres > 0) ? P32MAXREAL : P32MINREAL;}
      return;
    };

    //IEEE numbers underflow to zero.  sad!
    if (fres == 0){
      if (lhs_zer || rhs_zer) { res->udata = 0; }
      else {res->udata = (((lhs->udata & P32INF) ^ (rhs->udata & P32INF)) != 0) ? P32NEGSMALL : P32POSSMALL;}
      return;
    };

    //in the basic case, just output the result.
    *res = f_to_p32e0(fres);
}
extern "C" void p32e1_mul(p32e1_t *res, p32e1_t *lhs, p32e1_t *rhs){
    bool lhs_inf = (lhs->udata == P32INF);
    bool rhs_inf = (rhs->udata == P32INF);
    bool lhs_zer = (lhs->udata == P32ZER);
    bool rhs_zer = (rhs->udata == P32ZER);

    //long jump on multiplication of infinity times zero.
    if ( (lhs_inf && rhs_zer) || (rhs_inf && lhs_zer)) { throw_nan_jmp(); }

    double fres = p32e1_to_f(*lhs) * p32e1_to_f(*rhs);

    //check to see if we became infinity correctly.
    if (!isfinite(fres)){
      if (lhs_inf || rhs_inf) { res->udata = P32INF; }
      else {res->udata = (fres > 0) ? P32MAXREAL : P32MINREAL;}
      return;
    };

    //IEEE numbers underflow to zero.  sad!
    if (fres == 0){
      if (lhs_zer || rhs_zer) { res->udata = 0; }
      else {res->udata = (((lhs->udata & P32INF) ^ (rhs->udata & P32INF)) != 0) ? P32NEGSMALL : P32POSSMALL;}
      return;
    };

    //in the basic case, just output the result.
    *res = f_to_p32e1(fres);
}
extern "C" void p32e2_mul(p32e2_t *res, p32e2_t *lhs, p32e2_t *rhs){
    bool lhs_inf = (lhs->udata == P32INF);
    bool rhs_inf = (rhs->udata == P32INF);
    bool lhs_zer = (lhs->udata == P32ZER);
    bool rhs_zer = (rhs->udata == P32ZER);

    //long jump on multiplication of infinity times zero.
    if ( (lhs_inf && rhs_zer) || (rhs_inf && lhs_zer)) { throw_nan_jmp(); }

    double fres = p32e2_to_f(*lhs) * p32e2_to_f(*rhs);

    //check to see if we became infinity correctly.
    if (!isfinite(fres)){
      if (lhs_inf || rhs_inf) { res->udata = P32INF; }
      else {res->udata = (fres > 0) ? P32MAXREAL : P32MINREAL;}
      return;
    };

    //IEEE numbers underflow to zero.  sad!
    if (fres == 0){
      if (lhs_zer || rhs_zer) { res->udata = 0; }
      else {res->udata = (((lhs->udata & P32INF) ^ (rhs->udata & P32INF)) != 0) ? P32NEGSMALL : P32POSSMALL;}
      return;
    };

    //in the basic case, just output the result.
    *res = f_to_p32e2(fres);
}
extern "C" void p32e3_mul(p32e3_t *res, p32e3_t *lhs, p32e3_t *rhs){
    bool lhs_inf = (lhs->udata == P32INF);
    bool rhs_inf = (rhs->udata == P32INF);
    bool lhs_zer = (lhs->udata == P32ZER);
    bool rhs_zer = (rhs->udata == P32ZER);

    //long jump on multiplication of infinity times zero.
    if ( (lhs_inf && rhs_zer) || (rhs_inf && lhs_zer)) { throw_nan_jmp(); }

    double fres = p32e3_to_f(*lhs) * p32e3_to_f(*rhs);

    //check to see if we became infinity correctly.
    if (!isfinite(fres)){
      if (lhs_inf || rhs_inf) { res->udata = P32INF; }
      else {res->udata = (fres > 0) ? P32MAXREAL : P32MINREAL;}
      return;
    };

    //IEEE numbers underflow to zero.  sad!
    if (fres == 0){
      if (lhs_zer || rhs_zer) { res->udata = 0; }
      else {res->udata = (((lhs->udata & P32INF) ^ (rhs->udata & P32INF)) != 0) ? P32NEGSMALL : P32POSSMALL;}
      return;
    };

    //in the basic case, just output the result.
    *res = f_to_p32e3(fres);
}

extern "C" void p8e0_sub(p8e0_t *res, p8e0_t *lhs, p8e0_t *rhs){
    bool lhs_inf = (lhs->udata == P8INF);
    bool rhs_inf = (rhs->udata == P8INF);

    if (lhs_inf || rhs_inf) {
      if (lhs_inf && rhs_inf) { throw_nan_jmp(); }
      res->udata = P8INF;
      return;
    }

    //throw or long jump with the global NaNJump on addition of two infinities.

    float fres = p8e0_to_f(*lhs) - p8e0_to_f(*rhs);

    //check to see if we became infinity.
    if (!isfinite(fres)){
      //turn it into infinity.
      if (lhs_inf || rhs_inf) { res->udata = P8INF; }
      //check the sign and assign maxreal/minreal
      res->udata = (fres > 0) ? P8MAXREAL : P8MINREAL;
    };

    //in the basic case, just output the result.
    *res = f_to_p8e0(fres);
}
extern "C" void p8e1_sub(p8e1_t *res, p8e1_t *lhs, p8e1_t *rhs){
    bool lhs_inf = (lhs->udata == P8INF);
    bool rhs_inf = (rhs->udata == P8INF);

    if (lhs_inf || rhs_inf) {
      if (lhs_inf && rhs_inf) { throw_nan_jmp(); }
      res->udata = P8INF;
      return;
    }

    //throw or long jump with the global NaNJump on addition of two infinities.

    float fres = p8e1_to_f(*lhs) - p8e1_to_f(*rhs);

    //check to see if we became infinity.
    if (!isfinite(fres)){
      //turn it into infinity.
      if (lhs_inf || rhs_inf) { res->udata = P8INF; }
      //check the sign and assign maxreal/minreal
      res->udata = (fres > 0) ? P8MAXREAL : P8MINREAL;
    };

    //in the basic case, just output the result.
    *res = f_to_p8e1(fres);
}
extern "C" void p8e2_sub(p8e2_t *res, p8e2_t *lhs, p8e2_t *rhs){
    bool lhs_inf = (lhs->udata == P8INF);
    bool rhs_inf = (rhs->udata == P8INF);

    if (lhs_inf || rhs_inf) {
      if (lhs_inf && rhs_inf) { throw_nan_jmp(); }
      res->udata = P8INF;
      return;
    }

    //throw or long jump with the global NaNJump on addition of two infinities.

    float fres = p8e2_to_f(*lhs) - p8e2_to_f(*rhs);

    //check to see if we became infinity.
    if (!isfinite(fres)){
      //turn it into infinity.
      if (lhs_inf || rhs_inf) { res->udata = P8INF; }
      //check the sign and assign maxreal/minreal
      res->udata = (fres > 0) ? P8MAXREAL : P8MINREAL;
    };

    //in the basic case, just output the result.
    *res = f_to_p8e2(fres);
}
extern "C" void p16e0_sub(p16e0_t *res, p16e0_t *lhs, p16e0_t *rhs){
    bool lhs_inf = (lhs->udata == P16INF);
    bool rhs_inf = (rhs->udata == P16INF);

    if (lhs_inf || rhs_inf) {
      if (lhs_inf && rhs_inf) { throw_nan_jmp(); }
      res->udata = P16INF;
      return;
    }

    //throw or long jump with the global NaNJump on addition of two infinities.

    float fres = p16e0_to_f(*lhs) - p16e0_to_f(*rhs);

    //check to see if we became infinity.
    if (!isfinite(fres)){
      //turn it into infinity.
      if (lhs_inf || rhs_inf) { res->udata = P16INF; }
      //check the sign and assign maxreal/minreal
      res->udata = (fres > 0) ? P16MAXREAL : P16MINREAL;
    };

    //in the basic case, just output the result.
    *res = f_to_p16e0(fres);
}
extern "C" void p16e1_sub(p16e1_t *res, p16e1_t *lhs, p16e1_t *rhs){
    bool lhs_inf = (lhs->udata == P16INF);
    bool rhs_inf = (rhs->udata == P16INF);

    if (lhs_inf || rhs_inf) {
      if (lhs_inf && rhs_inf) { throw_nan_jmp(); }
      res->udata = P16INF;
      return;
    }

    //throw or long jump with the global NaNJump on addition of two infinities.

    float fres = p16e1_to_f(*lhs) - p16e1_to_f(*rhs);

    //check to see if we became infinity.
    if (!isfinite(fres)){
      //turn it into infinity.
      if (lhs_inf || rhs_inf) { res->udata = P16INF; }
      //check the sign and assign maxreal/minreal
      res->udata = (fres > 0) ? P16MAXREAL : P16MINREAL;
    };

    //in the basic case, just output the result.
    *res = f_to_p16e1(fres);
}
extern "C" void p16e2_sub(p16e2_t *res, p16e2_t *lhs, p16e2_t *rhs){
    bool lhs_inf = (lhs->udata == P16INF);
    bool rhs_inf = (rhs->udata == P16INF);

    if (lhs_inf || rhs_inf) {
      if (lhs_inf && rhs_inf) { throw_nan_jmp(); }
      res->udata = P16INF;
      return;
    }

    //throw or long jump with the global NaNJump on addition of two infinities.

    float fres = p16e2_to_f(*lhs) - p16e2_to_f(*rhs);

    //check to see if we became infinity.
    if (!isfinite(fres)){
      //turn it into infinity.
      if (lhs_inf || rhs_inf) { res->udata = P16INF; }
      //check the sign and assign maxreal/minreal
      res->udata = (fres > 0) ? P16MAXREAL : P16MINREAL;
    };

    //in the basic case, just output the result.
    *res = f_to_p16e2(fres);
}
extern "C" void p32e0_sub(p32e0_t *res, p32e0_t *lhs, p32e0_t *rhs){
    bool lhs_inf = (lhs->udata == P32INF);
    bool rhs_inf = (rhs->udata == P32INF);

    if (lhs_inf || rhs_inf) {
      if (lhs_inf && rhs_inf) { throw_nan_jmp(); }
      res->udata = P32INF;
      return;
    }

    //throw or long jump with the global NaNJump on addition of two infinities.

    double fres = p32e0_to_f(*lhs) - p32e0_to_f(*rhs);

    //check to see if we became infinity.
    if (!isfinite(fres)){
      //turn it into infinity.
      if (lhs_inf || rhs_inf) { res->udata = P32INF; }
      //check the sign and assign maxreal/minreal
      res->udata = (fres > 0) ? P32MAXREAL : P32MINREAL;
    };

    //in the basic case, just output the result.
    *res = f_to_p32e0(fres);
}
extern "C" void p32e1_sub(p32e1_t *res, p32e1_t *lhs, p32e1_t *rhs){
    bool lhs_inf = (lhs->udata == P32INF);
    bool rhs_inf = (rhs->udata == P32INF);

    if (lhs_inf || rhs_inf) {
      if (lhs_inf && rhs_inf) { throw_nan_jmp(); }
      res->udata = P32INF;
      return;
    }

    //throw or long jump with the global NaNJump on addition of two infinities.

    double fres = p32e1_to_f(*lhs) - p32e1_to_f(*rhs);

    //check to see if we became infinity.
    if (!isfinite(fres)){
      //turn it into infinity.
      if (lhs_inf || rhs_inf) { res->udata = P32INF; }
      //check the sign and assign maxreal/minreal
      res->udata = (fres > 0) ? P32MAXREAL : P32MINREAL;
    };

    //in the basic case, just output the result.
    *res = f_to_p32e1(fres);
}
extern "C" void p32e2_sub(p32e2_t *res, p32e2_t *lhs, p32e2_t *rhs){
    bool lhs_inf = (lhs->udata == P32INF);
    bool rhs_inf = (rhs->udata == P32INF);

    if (lhs_inf || rhs_inf) {
      if (lhs_inf && rhs_inf) { throw_nan_jmp(); }
      res->udata = P32INF;
      return;
    }

    //throw or long jump with the global NaNJump on addition of two infinities.

    double fres = p32e2_to_f(*lhs) - p32e2_to_f(*rhs);

    //check to see if we became infinity.
    if (!isfinite(fres)){
      //turn it into infinity.
      if (lhs_inf || rhs_inf) { res->udata = P32INF; }
      //check the sign and assign maxreal/minreal
      res->udata = (fres > 0) ? P32MAXREAL : P32MINREAL;
    };

    //in the basic case, just output the result.
    *res = f_to_p32e2(fres);
}
extern "C" void p32e3_sub(p32e3_t *res, p32e3_t *lhs, p32e3_t *rhs){
    bool lhs_inf = (lhs->udata == P32INF);
    bool rhs_inf = (rhs->udata == P32INF);

    if (lhs_inf || rhs_inf) {
      if (lhs_inf && rhs_inf) { throw_nan_jmp(); }
      res->udata = P32INF;
      return;
    }

    //throw or long jump with the global NaNJump on addition of two infinities.

    double fres = p32e3_to_f(*lhs) - p32e3_to_f(*rhs);

    //check to see if we became infinity.
    if (!isfinite(fres)){
      //turn it into infinity.
      if (lhs_inf || rhs_inf) { res->udata = P32INF; }
      //check the sign and assign maxreal/minreal
      res->udata = (fres > 0) ? P32MAXREAL : P32MINREAL;
    };

    //in the basic case, just output the result.
    *res = f_to_p32e3(fres);
}

extern "C" p8e0_t p8e0_addinv(p8e0_t x){
  p8e0_t res;
  res.udata = -x.udata;
  return res;
}
extern "C" p8e1_t p8e1_addinv(p8e1_t x){
  p8e1_t res;
  res.udata = -x.udata;
  return res;
}
extern "C" p8e2_t p8e2_addinv(p8e2_t x){
  p8e2_t res;
  res.udata = -x.udata;
  return res;
}
extern "C" p16e0_t p16e0_addinv(p16e0_t x){
  p16e0_t res;
  res.udata = -x.udata;
  return res;
}
extern "C" p16e1_t p16e1_addinv(p16e1_t x){
  p16e1_t res;
  res.udata = -x.udata;
  return res;
}
extern "C" p16e2_t p16e2_addinv(p16e2_t x){
  p16e2_t res;
  res.udata = -x.udata;
  return res;
}
extern "C" p32e0_t p32e0_addinv(p32e0_t x){
  p32e0_t res;
  res.udata = -x.udata;
  return res;
}
extern "C" p32e1_t p32e1_addinv(p32e1_t x){
  p32e1_t res;
  res.udata = -x.udata;
  return res;
}
extern "C" p32e2_t p32e2_addinv(p32e2_t x){
  p32e2_t res;
  res.udata = -x.udata;
  return res;
}
extern "C" p32e3_t p32e3_addinv(p32e3_t x){
  p32e3_t res;
  res.udata = -x.udata;
  return res;
}

extern "C" bool p8e0_lt(p8e0_t lhs, p8e0_t rhs){
  if ((lhs.udata == P8INF) || (rhs.udata == P8INF)) { return true; }
  return (lhs.sdata < rhs.sdata);
}
extern "C" bool p8e1_lt(p8e1_t lhs, p8e1_t rhs){
  if ((lhs.udata == P8INF) || (rhs.udata == P8INF)) { return true; }
  return (lhs.sdata < rhs.sdata);
}
extern "C" bool p8e2_lt(p8e2_t lhs, p8e2_t rhs){
  if ((lhs.udata == P8INF) || (rhs.udata == P8INF)) { return true; }
  return (lhs.sdata < rhs.sdata);
}
extern "C" bool p16e0_lt(p16e0_t lhs, p16e0_t rhs){
  if ((lhs.udata == P16INF) || (rhs.udata == P16INF)) { return true; }
  return (lhs.sdata < rhs.sdata);
}
extern "C" bool p16e1_lt(p16e1_t lhs, p16e1_t rhs){
  if ((lhs.udata == P16INF) || (rhs.udata == P16INF)) { return true; }
  return (lhs.sdata < rhs.sdata);
}
extern "C" bool p16e2_lt(p16e2_t lhs, p16e2_t rhs){
  if ((lhs.udata == P16INF) || (rhs.udata == P16INF)) { return true; }
  return (lhs.sdata < rhs.sdata);
}
extern "C" bool p32e0_lt(p32e0_t lhs, p32e0_t rhs){
  if ((lhs.udata == P32INF) || (rhs.udata == P32INF)) { return true; }
  return (lhs.sdata < rhs.sdata);
}
extern "C" bool p32e1_lt(p32e1_t lhs, p32e1_t rhs){
  if ((lhs.udata == P32INF) || (rhs.udata == P32INF)) { return true; }
  return (lhs.sdata < rhs.sdata);
}
extern "C" bool p32e2_lt(p32e2_t lhs, p32e2_t rhs){
  if ((lhs.udata == P32INF) || (rhs.udata == P32INF)) { return true; }
  return (lhs.sdata < rhs.sdata);
}
extern "C" bool p32e3_lt(p32e3_t lhs, p32e3_t rhs){
  if ((lhs.udata == P32INF) || (rhs.udata == P32INF)) { return true; }
  return (lhs.sdata < rhs.sdata);
}

extern "C" bool p8e0_lte(p8e0_t lhs, p8e0_t rhs){
  if ((lhs.udata == P8INF) || (rhs.udata == P8INF)) { return true; }
  return (lhs.sdata <= rhs.sdata);
}
extern "C" bool p8e1_lte(p8e1_t lhs, p8e1_t rhs){
  if ((lhs.udata == P8INF) || (rhs.udata == P8INF)) { return true; }
  return (lhs.sdata <= rhs.sdata);
}
extern "C" bool p8e2_lte(p8e2_t lhs, p8e2_t rhs){
  if ((lhs.udata == P8INF) || (rhs.udata == P8INF)) { return true; }
  return (lhs.sdata <= rhs.sdata);
}
extern "C" bool p16e0_lte(p16e0_t lhs, p16e0_t rhs){
  if ((lhs.udata == P16INF) || (rhs.udata == P16INF)) { return true; }
  return (lhs.sdata <= rhs.sdata);
}
extern "C" bool p16e1_lte(p16e1_t lhs, p16e1_t rhs){
  if ((lhs.udata == P16INF) || (rhs.udata == P16INF)) { return true; }
  return (lhs.sdata <= rhs.sdata);
}
extern "C" bool p16e2_lte(p16e2_t lhs, p16e2_t rhs){
  if ((lhs.udata == P16INF) || (rhs.udata == P16INF)) { return true; }
  return (lhs.sdata <= rhs.sdata);
}
extern "C" bool p32e0_lte(p32e0_t lhs, p32e0_t rhs){
  if ((lhs.udata == P32INF) || (rhs.udata == P32INF)) { return true; }
  return (lhs.sdata <= rhs.sdata);
}
extern "C" bool p32e1_lte(p32e1_t lhs, p32e1_t rhs){
  if ((lhs.udata == P32INF) || (rhs.udata == P32INF)) { return true; }
  return (lhs.sdata <= rhs.sdata);
}
extern "C" bool p32e2_lte(p32e2_t lhs, p32e2_t rhs){
  if ((lhs.udata == P32INF) || (rhs.udata == P32INF)) { return true; }
  return (lhs.sdata <= rhs.sdata);
}
extern "C" bool p32e3_lte(p32e3_t lhs, p32e3_t rhs){
  if ((lhs.udata == P32INF) || (rhs.udata == P32INF)) { return true; }
  return (lhs.sdata <= rhs.sdata);
}

