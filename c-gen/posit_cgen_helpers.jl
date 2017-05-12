#posit_cgen_helpers.jl.  A bunch of helper functions that make the cgen
#process smoother.

const IEEE_sizes = Dict(32 => 32, 64 => 64)
const IEEE_fsize = Dict(32 => 23, 64 => 52)

doc"""
  `fptype_for_posit` tells you the IEEE floating point type (as identified by a
  single integer "size" that will accomodate any given posit (n, es) specification.
"""
function fptype_for_posit(n::Integer, es::Integer)
  #first determine the maximum fraction size.
  max_fsize = n - 3 - es
  max_exp = (n - 2) * (2 ^ es)
  min_exp = -((n - 1) * (2 ^ es))

  usable_size = 32
  #check to make sure fsize fits in the es
  #if max_fsize < IEEE_fsize[size]
end
