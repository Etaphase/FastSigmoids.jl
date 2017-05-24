#generally helpful things
include("posit_cgen_helpers.jl")

#conversion headers
include("generate_posit.h.jl")
include("generate_posit.hpp.jl")
include("generate_posit_conv.h.jl")
include("generate_posit_ops.h.jl")

#c library source files
#include("generate_posit_err.cpp.jl")
include("generate_posit_conv.cpp.jl")
#include("generate_posit_basics.cpp.jl")
#include("generate_posit_full.cpp.jl")
#include("generate_posit_extended.cpp.jl")

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

  object_dir = normpath(d, "obj")
  isdir(object_dir) || mkdir(object_dir)

  #posit definitions
  posits_h = normpath(include_dir, "posit.h")
  open(posits_h, "w") do io
    generate_posit_h(io, posit_defs)
  end

  posits_hpp = normpath(include_dir, "posit.hpp")
  open(posits_hpp, "w") do io
    generate_posit_hpp(io, posit_defs)
  end

  #posit conversions
  posit_conv_h = normpath(include_dir, "posit_conv.h")
  open(posit_conv_h, "w") do io
    generate_posit_conv_h(io, posit_defs)
  end

  #posit operations
  posit_ops_status_h = normpath(include_dir, "posit_ops.h")
  open(posit_ops_status_h, "w") do io
    generate_posit_ops_status_h(io, posit_defs)
  end

  posit_ops_jumps_h = normpath(include_dir, "posit_ops_jumps.h")
  open(posit_ops_jumps_h, "w") do io
    generate_posit_ops_jumps_h(io, posit_defs)
  end


  ##############################################################################
  # "c" code files.

  filelist = Dict("posit_err"      => generate_posit_err_cpp,
                  "posit_conv"     => generate_posit_conv_cpp,
                  )#"posit_basics"   => generate_posit_basics_c,
                  #"posit_full"     => generate_posit_full_c,
                  #"posit_extended" => generate_posit_extended_c)

  for file in keys(filelist)
    posit_file_path = normpath(d, string(file,".cpp"))
    posit_object_path = normpath(object_dir, string(file,".o"))
    open(posit_file_path, "w") do io
      filelist[file](io, posit_defs)
    end

    #next, compile the files.
    cc = run(`gcc -c -Wall -Werror -fpic $posit_file_path -o $posit_object_path`)
  end

  ##############################################################################
  # c++ code files.

#=
  #link all the files and combine them into libfastposit.so
  object_files = ["$object_dir/$f" for f in readdir(object_dir) if f[end-1:end] == ".o"]
  library_path = normpath(d, "libfastposit.so")
  ln = run(`gcc -shared -o $library_path $object_files`)
  =#
end
