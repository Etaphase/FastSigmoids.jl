const FULL_FNS = [:div, :mulinv, :log2, :exp2, :fma, :fms, :nfma, :nfms, :fas, :fcp, :fdp, :dpi]

const fmasig = Dict(:fma  => (n, es) -> " $(to_f(n,es,"*a")),  $(to_f(n,es,"*b")),  $(to_f(n,es, "*c"))",
                    :fms  => (n, es) -> " $(to_f(n,es,"*a")),  $(to_f(n,es,"*b")), -$(to_f(n,es, "*c"))",
                    :nfma => (n, es) -> "-$(to_f(n,es,"*a")), -$(to_f(n,es,"*b")), -$(to_f(n,es, "*c"))",
                    :nfms => (n, es) -> "-$(to_f(n,es,"*a")), -$(to_f(n,es,"*b")),  $(to_f(n,es, "*c"))")

function zcounts()
  """
    static bool z_count_valid_float(float a, float b, float c){
      //convert a, b, and c to their respective integers
      uint32_t a_int = *((uint32_t *) &a);
      uint32_t b_int = *((uint32_t *) &b);
      uint32_t c_int = *((uint32_t *) &c);

      int64_t trailing_a = __builtin_ctz(a_int);
      int64_t trailing_b = __builtin_ctz(b_int);
      int64_t trailing_c = __builtin_ctz(c_int);

      return trailing_c == trailing_a + trailing_b - 23;
    }

    static bool z_count_valid_double(double a, double b, double c){
      //convert a, b, and c to their respective integers
      uint64_t a_int = *((uint64_t *) &a);
      uint64_t b_int = *((uint64_t *) &b);
      uint64_t c_int = *((uint64_t *) &c);

      int64_t trailing_a = __builtin_ctzl(a_int);
      int64_t trailing_b = __builtin_ctzl(b_int);
      int64_t trailing_c = __builtin_ctzl(c_int);

      return trailing_c == trailing_a + trailing_b - 52;
    }
  """
end

function sanitizers(op::Symbol, n::Integer)
  fsize = float_for_posit_size(n)
  ftype = c_ftype(fsize)
  if op == :div
    """
    static uint$(n)_t sanitize_$(op)$(n)(uint$(n)_t lhs, uint$(n)_t rhs, $(ftype) fres, uint$(n)_t pres){
      bool lhs_inf = (lhs == P$(n)INF);
      bool rhs_inf = (rhs == P$(n)INF);
      bool lhs_zer = (lhs == P$(n)ZER);
      bool rhs_zer = (rhs == P$(n)ZER);

      //throw or long jump with the global NaNJump on division of two infinities.
      if ( lhs_inf && rhs_inf ){ throw_nan_jmp(); }
      //throw or long jump with the global NaNJump on division of zero by zero.
      if ( lhs_zer && rhs_zer ){ throw_nan_jmp(); }

      //check for legitimate infinities vs. overflow.
      if (!isfinite(fres)){
        if (lhs_inf || rhs_zer) { return P$(n)INF; }

        pres = (fres > 0) ? P$(n)MAXREAL : P$(n)MINREAL;
      };

      //check to see if we became zero correctly or through underflow.
      if (fres == 0.0){
        if (lhs_zer || rhs_inf) { return P$(n)ZER; }
        pres = (((lhs & P$(n)INF) ^ (rhs & P$(n)INF)) != 0) ? P$(n)NEGSMALL : P$(n)POSSMALL;
      };

      return pres;
    }
    """
  elseif op == :fma
    """
    static uint$(n)_t sanitize_$(op)$(n)(uint$(n)_t a, uint$(n)_t b, uint$(n)_t c, $(ftype) fres, uint$(n)_t pres, bool z_valid){

      //check the muliplicands for infinities and zero values.
      bool a_inf = (a == P$(n)INF);
      bool a_zer = (a == P$(n)ZER);
      bool b_inf = (b == P$(n)INF);
      bool b_zer = (b == P$(n)ZER);
      bool c_inf = (c == P$(n)INF);

      bool nan_from_mult = (a_inf && b_zer) || (a_zer && b_inf);
      bool mulinf = a_inf || b_inf;  //to check for sum of two infs.

      if (nan_from_mult || (mulinf && c_inf)) { throw_nan_jmp(); }

      //check to see if we throw a legitimate infinity.
      if (mulinf || c_inf) { return P$(n)INF; }

      //luckily for us, IEEE floating point infinities keep their sign.
      if (isinf(fres)) {return (fres > 0) ? P$(n)MAXREAL : P$(n)MINREAL;}

      //true zeroes take a bit of work.
      if (fres == 0.0) {
        if (c == P$(n)ZER){ //if the addend is zero, make sure at least one of the multipliers is zero.
          if (a_inf || b_inf) { return P$(n)ZER; }
        } else {
          //to decide if we reached exactly zero, convert a, b & c to floats and
          //count trailing zeros, which we did earlier in the "z_count_valid" function
          if (z_valid) { return P$(n)ZER; }
        }
        uint$(fsize)_t zero_check = *((uint$(fsize)_t *) &fres);
        return (zero_check == 0) ? P$(n)POSSMALL : P$(n)NEGSMALL;
      }

      return pres;
    }
    """
  else
    ""
  end
end

function full_output(op::Symbol, n::Integer, es::Integer)
  headerfn = ops[op]
  ftype = c_ftype(float_for_posit_size(n))

  if (op == :div)
    binf = TPTR_TO_BINF[op]
    string(headerfn(op, n, es), """{

      $(ftype) fres = $(to_f(n,es,"*lhs")) $(binf) $(to_f(n,es,"*rhs"));

      //sanitize the resulting data and store as an update to res.

      $(p(n,es)) pres = $(to_p(n, es, :fres));
      res->udata = sanitize_div$(n)(lhs->udata, rhs->udata, fres, pres.udata);

    }""")
  elseif (op == :mulinv)
    string(headerfn(op, n, es), """{
      p$(n)e$(es)_t res;

      if (x.udata == P$(n)INF) { res.udata = P$(n)ZER; return res; }
      if (x.udata == P$(n)ZER) { res.udata = P$(n)INF; return res; }

      //by nature of encapsulation we don't have to worry about overflow or underflow.

      return $(to_p(n,es,string("1 / ",to_f(n,es,:x))));
    }""")
  elseif (op == :log2)
    string(headerfn(op, n, es), """{
      if ( x.sdata < 0 ){ throw_nan_jmp(); }

      return $(to_p(n,es,string("log2(", to_f(n,es,:x),")")));
    }""")
  elseif (op == :exp2)
    string(headerfn(op, n, es), """{
      $(p(n,es)) res;
      //check to see if the result will be infinite, which causes NaN (not sure if zero or infinity).
      if ( x.udata == P$(n)INF ) { throw_nan_jmp(); }

      $(ftype) fres = exp2($(to_f(n,es,"x")));

      //clear on infinite and zero values.

      if (isinf(fres)){res.udata = P$(n)MAXREAL; return res;}
      if (fres == 0)  {res.udata = P$(n)POSSMALL; return res;}

      return $(to_p(n,es,:fres));
    }""")
  elseif (op in [:fma, :fms, :nfma, :nfms])
    fsig = fmasig[op](n, es)
    string(headerfn(op, n, es), """{

      $(ftype) fres = fma($fsig);

      bool z_count_valid = z_count_valid_$(ftype)($fsig);
      $(p(n,es)) pres = $(to_p(n,es,:fres));

      res->udata = sanitize_fma$(n)(a->udata, b->udata, c->udata, fres, pres.udata, z_count_valid);
    }""")
  elseif op == :fas
    #:fas, :fcp, :fdp, :dpi
    string(headerfn(op, n, es), """{
      throw_nan_jmp();
      $(p(n,es)) res;
      return res;
    }""")
  elseif op == :fcp
    #:fas, :fcp, :fdp, :dpi
    string(headerfn(op, n, es), """{
      throw_nan_jmp();
      $(p(n,es)) res;
      return res;
    }""")
  elseif op == :fdp
    #:fas, :fcp, :fdp, :dpi
    string(headerfn(op, n, es), """{
      throw_nan_jmp();
      $(p(n,es)) res;
      return res;
    }""")
  elseif op == :dpi
    #:fas, :fcp, :fdp, :dpi
    string(headerfn(op, n, es), """{
      throw_nan_jmp();
    }""")
  end
end

function generate_posit_full_c(io, posit_defs)
  #generates "posit.h" based on the posit_definitions
  write(io, "#include \"include/posit.h\"\n")
  write(io, "#include \"include/posit_conv.h\"\n\n")
  write(io, zcounts())
  write(io, "\n\n")

  for fn in FULL_FNS
    for n in sort(collect(keys(posit_defs)))
      write(io, sanitizers(fn, n))
      write(io, "\n\n")
      for es in posit_defs[n]
        write(io, full_output(fn, n, es))
        write(io, "\n\n")
      end
    end
    write(io,"\n")
  end
end
