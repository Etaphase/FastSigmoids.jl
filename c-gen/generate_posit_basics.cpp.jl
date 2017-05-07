function generate_posit_basics_cpp(io, posit_defs)
  #generates "posit.h" based on the posit_definitions
  write(io, "#include \"posit.h\"\n")
end

const BASICS_FNS = [:add, :mul, :sub, :addinv, :lt, :lte]
const TPTR_TO_BINF = Dict(:add => "+", :mul => "*", :sub => "-")
const UNV_TO_UNF = Dict(:addinv => "-")
const BOOLF = Dict(:lt => "<", :lte => "<=")

function basics_output(op::Symbol, n::Integer, es::Integer)
  headerfn = ops[op]
  ftype = ((n == 8) || (n == 16)) ? "float" : "double"
  if (op == :add || op == :sub)
    binf = TPTR_TO_BINF[op]
    string(headerfn(op, n, es), """{
    bool lhs_inf = (lhs.udata == P$(n)INF);
    bool rhs_inf = (rhs.udata == P$(n)INF);

    //throw or long jump with the global NaNJump on addition of two infinities.
    if ( lhs_inf && rhs_inf ){
      #ifdef __cplusplus
        throw NaNError();
      #else
        longjmp(__nan_ex_buf__, 1);
      #endif
    }

    $(ftype) fres = p$(n)_$(es)_to_f(*lhs) $(binf) p$(n)_$(es)_to_f(*rhs);

    //check to see if we became infinity.
    if (!isfinite(fres)){
      //turn it into infinity.
      if (lhs_inf || rhs_inf) { res->udata = P$(n)INF; }
      //check the sign and assign maxreal/minreal
      res->udata = (fres > 0) ? P$(n)MAXREAL : P$(n)MINREAL;
    };

    //in the basic case, just output the result.
    *res = f_to_p$(n)_$(es)(fres);
}""")
  elseif (op == :mul)
    binf = TPTR_TO_BINF[op]
    string(headerfn(op, n, es), """{
    bool lhs_inf = (lhs.udata == P$(n)INF);
    bool rhs_inf = (rhs.udata == P$(n)INF);
    bool lhs_zer = (lhs.udata == P$(n)ZER);
    bool rhs_zer = (rhs.udata == P$(n)ZER);

    //throw or long jump with the global NaNJump on multiplication of infinity times zero.
    if ( (lhs_inf && rhs_zer) || (rhs_inf && lhs_zer)) {
      #ifdef __cplusplus
        throw NaNError();
      #else
        longjmp(__nan_ex_buf__, 1);
      #endif
    }

    $(ftype) fres = p$(n)_$(es)_to_f(*lhs) $(binf) p$(n)_$(es)_to_f(*rhs);

    //check to see if we became infinity correctly.
    if (!isfinite(fres)){
      if (lhs_inf || rhs_inf) { res->udata = P$(n)INF; }
      else {res->udata = (fres > 0) ? P$(n)MAXREAL : P$(n)MINREAL;}
      return;
    };

    //IEEE numbers underflow to zero.  sad!
    if (fres == 0){
      if (lhs_zer || rhs_zer) { res->udata = 0; }
      else {res->udata = negflag(fres) ? P$(n)NEGSMALL : P$(n)POSSMALL;}
      return;
    };

    //in the basic case, just output the result.
    *res = f_to_p$(n)_$(es)(fres);
}""")
  elseif (op == :addinv)
    #additive inverse should be coded directly.
    string(headerfn(op, n, es), """{
  p$(n)_$(es)_t res;
  res.udata = -x.udata;
  return res
}""")
  elseif (headerfn == boolean_header)
    boolf = BOOLF[op]
    string(headerfn(op, n, es), """{
  if (lhs.udata == P$(n)INF || rhs.udata == P$(n)INF) { return true; };
  return lhs.sdata $(boolf) rhs.sdata;
}""")
  end
end
