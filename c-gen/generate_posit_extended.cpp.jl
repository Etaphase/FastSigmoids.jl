
const EXT_FNS = [:sqrt, :log1p, :log, :log10, :exp, :pow, :logx, :sin, :cos, :atan, :atan2]

function ext_output(op::Symbol, n::Integer, es::Integer)
  headerfn = ops[op]
  ftype = ((n == 8) || (n == 16)) ? "float" : "double"

  if (op == :sqrt)
    string(headerfn(op, n, es), """{
      if ( x.sdata < 0 ){ throw_nan_jmp(); }

      return $(to_p(n,es,string("sqrt(", to_f(n,es,:x), ")")));
    }""")
  elseif (op == :log1p)
    string(headerfn(op, n, es), """{
      if ( x.sdata < 0 ){ throw_nan_jmp(); }

      return $(to_p(n,es,string("log1p(", to_f(n,es,:x), ")")));
    }""")
  elseif (op == :log)
    string(headerfn(op, n, es), """{
      if ( x.sdata < 0 ){ throw_nan_jmp(); }

      return $(to_p(n,es,string("log(", to_f(n,es,:x), ")")));
    }""")
  elseif (op == :log10)
    string(headerfn(op, n, es), """{
      if ( x.sdata < 0 ){ throw_nan_jmp(); }

      return $(to_p(n,es,string("log10(", to_f(n,es,:x), ")")));
    }""")
  elseif (op == :exp)
    string(headerfn(op, n, es), """{
      if ( x.sdata < 0 ){ throw_nan_jmp(); }

      return $(to_p(n,es,string("exp(", to_f(n,es,:x), ")")));
    }""")
  elseif (op == :pow)
    string(headerfn(op, n, es), """{
      if ( a.udata == 0 && b.udata == 0 ){ throw_nan_jmp(); }

      return $(to_p(n,es,string("pow(", to_f(n,es,:a), ",", to_f(n,es,:b),")")));
    }""")
  elseif (op == :sin)
    string(headerfn(op, n, es), """{
      return $(to_p(n,es,string("sin(", to_f(n,es,:x), ")")));
    }""")
  elseif (op == :cos)
    string(headerfn(op, n, es), """{
      return $(to_p(n,es,string("cos(", to_f(n,es,:x), ")")));
    }""")
  elseif (op == :atan)
    string(headerfn(op, n, es), """{
      return $(to_p(n,es,string("atan(", to_f(n,es,:x), ")")));
    }""")
  elseif (op == :atan2)
    string(headerfn(op, n, es), """{
      return $(to_p(n,es,string("atan2(", to_f(n,es,:a), ",", to_f(n,es,:b),")")));
    }""")
  else
    ""
  end
end

function generate_posit_extended_c(io, posit_defs)
  #generates "posit.h" based on the posit_definitions
  write(io, "#include \"include/posit.h\"\n")
  write(io, "#include \"include/posit_conv.h\"\n\n")
  for fn in EXT_FNS
    for n in sort(collect(keys(posit_defs)))
      for es in posit_defs[n]
        write(io, ext_output(fn, n, es))
        write(io, "\n")
      end
    end
    write(io,"\n")
  end
end
