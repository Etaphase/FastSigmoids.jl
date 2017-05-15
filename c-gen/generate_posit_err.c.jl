function generate_posit_err_c(io::IOStream)
  write(io,"""

#include "posit.h"

static jmp_buf nan_jmp_buf;

extern "C" int set_nan_jmp(){
  return set_jmp(nan_jmp_buf);
}

extern "C" void throw_nan_jmp(){
  longjmp(nan_jmp_buf,1);
}

  """)
end
