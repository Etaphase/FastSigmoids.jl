function generate_posit_h(io, posit_defs)
  #generates "posit.h" based on the posit_definitions
  write(io, "#ifndef __POSIT_H\n")
  write(io, "#define __POSIT_H\n")
  write(io, "\n")

  write(io, "#include <stdint.h>\n")
  write(io, "#include <math.h>\n")
  write(io, "#include <stdbool.h>\n\n")
  #create a section for error handling

  for n in sort(collect(keys(posit_defs)))
    T = top_bits(n)
    write(io,"""
    #define P$(n)INF      $(c_literal(T))
    #define P$(n)MAXREAL  $(c_literal(T - one(T)))
    #define P$(n)MINREAL  $(c_literal(T | one(T)))
    #define P$(n)POSSMALL $(c_literal(one(T)))
    #define P$(n)NEGSMALL $(c_literal(-one(T)))
    #define P$(n)ZER      $(c_literal(zero(T)))
    """)
  end
  write(io, "\n")

  for n in sort(collect(keys(posit_defs)))
    for es in posit_defs[n]
      write(io, "typedef union {uint$(n)_t udata; int$(n)_t sdata;} p$(n)e$(es)_t ;\n")
    end
    write(io, "\n")
  end

  for n in sort(collect(keys(posit_defs)))
    for es in posit_defs[n]
      write(io, "typedef struct {uint64_t *cache; uint64_t exponent; uint64_t leading_ones;} fdp_cache$(n)e$(es)_t;\n")
    end
    write(io, "\n")
  end

  #next create a link to the error handler
  write(io,"""

  //c error handling routines
  extern "C" int set_nan_jmp();
  extern "C" void throw_nan_jmp();

  """)

  write(io, "#endif\n")
end
