function p2fheader(n, es)
  ftype = c_ftype(float_for_posit_size(n))
  "  $(ftype) $(to_f(n,es, string(p(n,es), " pval")))"
end

function f2pheader(n, es)
  ftype = c_ftype(float_for_posit_size(n))
  "  $(p(n,es)) $(to_p(n,es, string(ftype, " fval")))"
end

function generate_posit_conv_h(io, posit_defs)
  write(io,"""
  #ifndef __POSIT_CONV_H
  #define __POSIT_CONV_H

  #include \"posit.h\"

  #ifdef __cplusplus
  extern "C" {
  #endif

  """)
  for n in sort(collect(keys(posit_defs)))
    for es in posit_defs[n]
      write(io, p2fheader(n, es))
      write(io, ";\n")
      write(io, f2pheader(n, es))
      write(io, ";\n")
    end

    write(io, "\n")
  end
  write(io,"""
  #ifdef __cplusplus
  }
  #endif
  #endif
  """)
end
