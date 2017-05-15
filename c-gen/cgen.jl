#generally helpful things
include("posit_cgen_helpers.jl")

#conversion headers
include("generate_posit.h.jl")
include("generate_posit_conv.h.jl")
include("generate_posit_ops.h.jl")

#c library source files
include("generate_posit_err.c.jl")
include("generate_posit_conv.c.jl")
include("generate_posit_basics.c.jl")
include("generate_posit_full.c.jl")
include("generate_posit_extended.c.jl")

doc"""
  generate_fastsigmoid_c_libary(directory)

  generates the fastsigmoid library in a particular directory.
"""
function generate_fastsigmoid_c_library(posit_defs, d::AbstractString = normpath(Pkg.dir("FastSigmoid"),"c-src"))

  ##############################################################################
  # headers

  #create the include directory
  include_dir = normpath(d, "include")
  isdir(include_dir) || mkdir(include_dir)

  #posit definitions
  posits_h = normpath(include_dir, "posit.h")
  open(posits_h, "w") do io
    generate_posit_h(io, posit_defs)
  end

  #posit conversions
  posit_conv_h = normpath(include_dir, "posit_conv.h")
  open(posit_conv_h, "w") do io
    generate_posit_conv_h(io, posit_defs)
  end

  #posit operations
  posit_ops_h = normpath(include_dir, "posit_ops.h")
  open(posit_ops_h, "w") do io
    generate_posit_ops_h(io, posit_defs)
  end

  ##############################################################################
  # c code files.

  #error handling
  posit_err_c = normpath(d, "posit_err.c")
  open(posit_err_c, "w") do io
    generate_posit_err_c(io)
  end

  #conversions
  posit_conv_c = normpath(d, "posit_conv.c")
  open(posit_conv_c, "w") do io
    generate_posit_conv_c(io, posit_defs)
  end

  #basics
  posit_basics_c = normpath(d, "posit_basics.c")
  open(posit_basics_c, "w") do io
    generate_posit_basics_c(io, posit_defs)
  end

  #full
  posit_full_c = normpath(d, "posit_full.c")
  open(posit_full_c, "w") do io
    generate_posit_full_c(io, posit_defs)
  end

  #extended
  posit_extended_c = normpath(d, "posit_extended.c")
  open(posit_extended_c, "w") do io
    generate_posit_extended_c(io, posit_defs)
  end

  ##############################################################################
  # c++ code files.

end
