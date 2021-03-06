workspace()

#generally helpful things
include("posit_cgen_helpers.jl")

#conversion headers
include("generate_posit.h.jl")
include("generate_posit_conv.h.jl")
include("generate_posit_ops.h.jl")

#c library source files
include("generate_posit_conv.cpp.jl")
include("generate_posit_basics.cpp.jl")
include("generate_posit_full.cpp.jl")
include("generate_posit_extended.cpp.jl")

#c++ code
include("generate_posit_class.h.jl")
include("generate_posit_class.cpp.jl")

#makefile stuff
include("generate_makefile.jl")

#sample file
include("generate_testfile.jl")

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

  posit_ops_errno_h = normpath(include_dir, "posit_ops_errno.h")
  open(posit_ops_errno_h, "w") do io
    generate_posit_ops_errno_h(io, posit_defs)
  end

  ##############################################################################
  # "c" code files.

  filelist = Dict("posit_conv"     => generate_posit_conv_cpp,
                  "posit_basics"   => generate_posit_basics_cpp,
                  "posit_full"     => generate_posit_full_cpp,
                  "posit_extended" => generate_posit_extended_cpp)

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

  for n in sort(collect(keys(posit_defs)))
    for es in posit_defs[n]
      posit_class_h = normpath(include_dir, "P$(n)e$(es).h")
      open(posit_class_h, "w") do io
        generate_posit_class_h(io, n, es)
      end

      posit_class_cpp = normpath(d, "P$(n)e$(es).cpp")
      open(posit_class_cpp, "w") do io
        generate_posit_class_cpp(io, n, es)
      end

      posit_class_o = normpath(object_dir, "P$(n)e$(es).o")

      #next, compile the files.
      cc = run(`gcc -c -Wall -Werror -fpic $posit_class_cpp -o $posit_class_o`)
    end
  end

  ##############################################################################
  # make makefile.

  posit_makefile = normpath(d, "Makefile")
  open(posit_makefile, "w") do io
    generate_makefile(io, posit_defs)
  end

  posit_testfile = normpath(d, "test.cpp")
  open(posit_testfile, "w") do io
    generate_testfile(io)
  end

  #link all the files and combine them into libfastposit.so
  object_files = ["$object_dir/$f" for f in readdir(object_dir) if f[end-1:end] == ".o"]
  library_path = normpath(d, "libfastposit.so")
  ln = run(`gcc -shared -o $library_path $object_files`)
end

generate_fastsigmoid_c_library(Dict(8=>[0,1,2],16=>[0,1,2],32=>[0,1,2,3]))
