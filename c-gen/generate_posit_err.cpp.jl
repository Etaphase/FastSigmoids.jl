function generate_posit_err_cpp(io::IOStream, _)
  write(io,"""

#include <setjmp.h>
#include "include/posit.h"

static jmp_buf nan_jmp_buf;

extern "C" int set_nan_jmp(){
  return setjmp(nan_jmp_buf);
}

extern "C" void throw_nan_jmp(){
  longjmp(nan_jmp_buf,1);
}

  """)
end
