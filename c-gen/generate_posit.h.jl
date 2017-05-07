function generate_posit_h(io, posit_defs)
  #generates "posit.h" based on the posit_definitions
  write(io, "#ifndef __POSIT_H\n")
  write(io, "#define __POSIT_H\n")
  write(io, "\n")
  for n in sort(collect(keys(posit_defs)))
    for es in posit_defs[key]
      write(io, "typedef union {uint$(n)_t udata; int$(n)_t sdata} p$(n)e$(es)_t;\n")
    end
    write(io, "\n")
  end
  write(io, "#endif\n")
end

#val-headers
unary_val_header(op::Symbol, n::Integer, es::Integer) = "extern \"C\" p$(n)_$(es)_t p_$(op)_$(n)_$(es)(p$(n)_$(es)_t x)"
binary_val_header(op::Symbol, n::Integer, es::Integer) = "extern \"C\" p$(n)_$(es)_t p_$(op)_$(n)_$(es)(p$(n)_$(es)_t A, p$(n)_$(es)_t b)"
ternary_val_header(op::Symbol, n::Integer, es::Integer) = "extern \"C\" p$(n)_$(es)_t p_$(op)_$(n)_$(es)(p$(n)_$(es)_t a, p$(n)_$(es)_t b, p$(n)_$(es)_t c)"
quaternary_val_header(op::Symbol, n::Integer, es::Integer) = "extern \"C\" p$(n)_$(es)_t p_$(op)_$(n)_$(es)(p$(n)_$(es)_t a, p$(n)_$(es)_t b, p$(n)_$(es)_t c, p$(n)_$(es)_t b)"

#boolean headers
boolean_header(op::Symbol, n::Integer, es::Integer) = "extern \"C\" bool p_$(op)_$(n)_$(es)(p$(n)_$(es)_t lhs, p$(n)_$(es)_t rhs)"

#pointer headers
ternary_ptr_header(op::Symbol, n::Integer, es::Integer) = "extern \"C\" void p_$(op)_$(n)_$(es)(p$(n)_$(es)_t *res, p$(n)_$(es)_t *lhs, p$(n)_$(es)_t *rhs)"
quaternary_ptr_header(op::Symbol, n::Integer, es::Integer) = "extern \"C\" void p_$(op)_$(n)_$(es)(p$(n)_$(es)_t *res, p$(n)_$(es)_t *a, p$(n)_$(es)_t *b, p$(n)_$(es)_t *c)"

#headers for special functions
fdp_header(op::Symbol, n::Integer, es::Integer) = "extern \"C\" p$(n)_$(es)_t p_fdp_$(n)_$(es)(fdp_cache$(n)_$(es), *fc, p$(n)_$(es)_t a, p$(n)_$(es)_t b)"
dpi_header(op::Symbol, n::Integer, es::Integer) = "extern \"C\" p$(n)_$(es)_t fdp_cache$(n)_$(es)()"

const ops = Dict(#required for all posit implementations
                 :add    => ternary_ptr_header,
                 :mul    => ternary_ptr_header,
                 :sub    => ternary_ptr_header,
                 :addinv => unary_val_header,
                 :lt     => boolean_header,
                 :lte    => boolean_header,
                 #full posit required functions
                 :div    => ternary_ptr_header,
                 :mulinv => unary_val_header,
                 :log2   => unary_val_header,
                 :exp2   => unary_val_header,
                 :fma    => quaternary_ptr_header,
                 :fms    => quaternary_ptr_header,
                 :nfma   => quaternary_ptr_header,
                 :nfms   => quaternary_ptr_header,
                 :fas    => ternary_val_header,
                 :fcp    => quaternary_val_header,
                 :fdp    => fdp_header,
                 :dpi    => dpi_header,
                 #extended functions,
                 :sqrt   => unary_val_header,
                 :log10  => unary_val_header,
                 :log    => unary_val_header,
                 :exp    => unary_val_header,
                 :pow    => binary_val_header,
                 :logx   => binary_val_header,
                 :sin    => unary_val_header,
                 :cos    => unary_val_header,
                 :atan   => unary_val_header,
                 :atan2  => unary_val_header)

function writefndef(io, op, n, es)
  write(io, ops[op](op, n, es))
end

function generate_posit_ops(io, posit_defs)
  write(io, "#ifndef __POSIT_OPS_H\n")
  write(io, "#define __POSIT_OPS_H\n")
  write(io, "\n")
  for op in keys(ops)
    for n in sort(collect(keys(posit_defs)))
      for es in posit_defs[n]
        writefndef(io, op, n, es)
        write(io, ";\n")
      end
    end

    write(io, "\n")
  end
  write(io, "#endif")
end
