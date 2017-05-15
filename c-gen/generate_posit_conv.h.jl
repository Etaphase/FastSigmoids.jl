function p2fheader(n, es)
  ftype = c_ftype(float_for_posit_size(n))
  "extern \"C\" $(ftype) $(to_f(n,es, string(p(n,es), " pval")))"
end

function f2pheader(n, es)
  ftype = c_ftype(float_for_posit_size(n))
  "extern \"C\" $(p(n,es)) $(to_p(n,es, string(ftype, " fval")))"
end

function generate_posit_conv_h(io, posit_defs)
  write(io, "#ifndef __POSIT_CONV_H\n")
  write(io, "#define __POSIT_CONV_H\n")
  write(io, "\n")
  write(io, "#include \"posit.h\"\n")
  write(io, "\n")
  for n in sort(collect(keys(posit_defs)))
    for es in posit_defs[n]
      write(io, p2fheader(n, es))
      write(io, ";\n")
      write(io, f2pheader(n, es))
      write(io, ";\n")
    end

    write(io, "\n")
  end
  write(io, "#endif")
end
