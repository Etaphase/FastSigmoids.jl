function generate_posit_full_cpp(io, posit_defs)
  #generates "posit.h" based on the posit_definitions
  write(io, "#include \"posit.h\"\n")
end

const FULL_FNS = [:div, :mulinv, :log2, :exp2, :fma, :fms, :nfma, :nfms, :fas, :fcp, :fdp, :dpi]

const fmasig = Dict(:fma  => (n, es) -> " p$(n)_$(es)_to_f(a),  p$(n)_$(es)_to_f(b),  p$(n)_$(es)_to_f(c)",
                    :fms  => (n, es) -> " p$(n)_$(es)_to_f(a),  p$(n)_$(es)_to_f(b), -p$(n)_$(es)_to_f(c)",
                    :nfma => (n, es) -> "-p$(n)_$(es)_to_f(a), -p$(n)_$(es)_to_f(b), -p$(n)_$(es)_to_f(c)",
                    :nfms => (n, es) -> "-p$(n)_$(es)_to_f(a), -p$(n)_$(es)_to_f(b),  p$(n)_$(es)_to_f(c)")

function basics_output(op::Symbol, n::Integer, es::Integer)
  headerfn = ops[op]
  ftype = ((n == 8) || (n == 16)) ? "float" : "double"

  if (op == :div)
    binf = TPTR_TO_BINF[op]
    string(headerfn(op, n, es), """{
    bool lhs_inf = (lhs.udata == P$(n)INF);
    bool rhs_inf = (rhs.udata == P$(n)INF);
    bool lhs_zer = (lhs.udata == P$(n)ZER);
    bool rhs_zer = (rhs.udata == P$(n)ZER);

    //throw or long jump with the global NaNJump on addition of two infinities.
    if ( lhs_inf && rhs_inf ){
      #ifdef __cplusplus
        throw NaNError();
      #else
        longjmp(__nan_ex_buf__, 1);
      #endif
    }

    //throw or long jump with the global NaNJump on division of zero by zero.
    if ( lhs_zer && rhs_zer ){
      #ifdef __cplusplus
        throw NaNError();
      #else
        longjmp(__nan_ex_buf__, 1);
      #endif
    }

    $(ftype) fres = p$(n)_$(es)_to_f(*lhs) $(binf) p$(n)_$(es)_to_f(*rhs);

    //check to see if we became infinity correctly.
    if (!isfinite(fres)){
      if (lhs_inf || rhs_zer) { res->udata = P$(n)INF; }
      else { res->udata = (fres > 0) ? P$(n)MAXREAL : P$(n)MINREAL; }
      return
    };

    //check to see if we became zero correctly.
    if (fres == 0){
      if (lhs_zer || rhs_inf) { res->sdata = 0; }
      else { res->udata = negflag(fres) ? P$(n)POSSMALL : P$(n)NEGSMALL; } //check signedness of zero
      return
    };

    //in the basic case, just output the result.
    *res = f_to_p$(n)_$(es)(fres);
}""")
  elseif (op == :mulinv)
    string(headerfn(op, n, es), """{
    if (x.udata == P$(n)INF) { res.udata = P$(n)ZER; return res; }
    if (x.udata == P$(n)ZER) { res.udata = P$(n)INF; return res; }

    p$(n)_$(es)_t res;

    //by nature of encapsulation we don't have to worry about overflow or underflow.

    return f_to_p$(n)_$(es)(1 / p$(n)_$(es)_to_f(*x));
}""")
  elseif (op == :log2)
    string(headerfn(op, n, es), """{
    if ( x.sdata < 0 ){
      #ifdef __cplusplus
        throw NaNError();
      #else
        longjmp(__nan_ex_buf__, 1);
      #endif
    }

    return f_to_p$(n)_$(es)(log2(p$(n)_$(es)_to_f(x)));
}""")
  elseif (op == :exp2)
    string(headerfn(op, n, es), """{
    p$(n)_$(es)_t res;
    //check to see if the result will be infinite, which causes NaN (not sure if zero or infinity).
    if ( x.udata == P$(n)INF ) {
      #ifdef __cplusplus
        throw NaNError();
      #else
        longjmp(__nan_ex_buf__, 1);
      #endif
    }

    $(ftype) fres = exp2(p$(n)_$(es)_to_f(x));

    //clear on infinite and zero values.

    if (isinf(fres)){res.udata = P$(n)MAXREAL; return;}
    if (fres == 0)  {res.udata = P$(n)POSSMALL; return;}

    return f_to_p$(n)_$(es)(res);

    }""")
  elseif (op in [:fma, :fms, :nfma, :nfms])
    fsig = fmasig[op](n, es)
    string(headerfn(op, n, es), """{
    //check the muliplicands for infinities.
    bool a_inf = (a.udata == P$(n)INF);
    bool a_zer = (a.udata == P$(n)ZER);
    bool b_inf = (b.udata == P$(n)INF);
    bool b_zer = (b.udata == P$(n)ZER);
    bool c_inf = (c.udata == P$(n)INF);

    bool nanerror = (a_inf && b_zer) || (a_zer && b_inf)
    bool mulinf = a_inf || b_inf
    nanerror = nanerror || (mulinf && c_inf)

    p$(n)_$(es)_t res;

    if (nanerror) {
      #ifdef __cplusplus
        throw NaNError();
      #else
        longjmp(__nan_ex_buf__, 1);
      #endif
    }

    if (mulinf || c_inf) {
      res.udata = P$(n)INF;
      return res;
    }

    fres = fma($fsig)

    if (isinf(fres)) {res.udata = (fres > 0) ? P$(n)MAXREAL : P$(n)MINREAL; return res;}
    if (iszero(fres)) {
      //we need to implement a technically correct routine for zero checking here..
    }

    return res;
}""")
  end
end
