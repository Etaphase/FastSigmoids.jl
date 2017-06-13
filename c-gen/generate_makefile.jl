doc"""
  generate_makefile(io, defs)

  generates a makefile which builds the make file corresponding to the posit definitions.
"""
function generate_makefile(io, posit_defs)

  #a list of general posit file names.
  pfilenames = [:posit_conv, :posit_extended, :posit_basics, :posit_err, :posit_full]

  #a list of posit classnames
  pclassnames = []
  for posit_size in sort(collect(keys(posit_defs)))
    for exp in posit_defs[posit_size]
      push!(pclassnames, Symbol("P$(posit_size)e$(exp)"))
    end
  end

  obj_file = (s::Union{Symbol}) -> ("obj/$s.o")
  cpp_file = (s::Union{Symbol}) -> ("$s.cpp")

  obj_def = (s::Symbol) -> """
  $(obj_file(s)): $(cpp_file(s))
  \tgcc -c -Wall -Werror -fpic $(cpp_file(s)) -o $(obj_file(s))
  """


  all_objects = join(map(obj_file, pfilenames), " ") * " " * join(map(obj_file, pclassnames), " ")

  c_objects = join(map(obj_def, pfilenames),"\n")

  cpp_objects = join(map(obj_def, pclassnames), "\n")

  link_library = """
  build: $(all_objects)
  \tgcc -shared -o libfastposit.so $all_objects
  """

  write(io, """
  $(c_objects)

  $(cpp_objects)

  $(link_library)

  test: test.cpp
  \tgcc -Wall -o test test.cpp -lstdc++ -lfastposit
  \tchmod +x test
  \t./test

  .PHONY: install
  install:
  \tcp ./libfastposit.so /usr/lib
  \tchmod +r /usr/lib/libfastposit.so

  .PHONY: clean
  clean:
  \t-rm *.so
  \t-rm obj/*.o
  """)
end
