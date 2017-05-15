using FastSigmoid
using Base.Test

# comprehensively test that transcoding of fast sigmoids works.

include("c-lib-test.jl")

#integration tests.

@test FastSigmoid.__decomp(reinterpret(Posit{16,0}, 0x0001)) == (false, -14, 0x0000)
@test FastSigmoid.__p2f(reinterpret(Posit{16,0}, 0x0001)) == 6.1035156f-5

#conversion and deconversion of 8-bit posits
for fs_val = 0x00:0xFF
  pval = reinterpret(Posit{8,0}, fs_val)
  @test (Posit{8,0}(FastSigmoid.__p2f(pval)), fs_val) == (pval, fs_val)
end
for fs_val = 0x00:0xFF
  pval = reinterpret(Posit{8,1}, fs_val)
  @test (Posit{8,1}(FastSigmoid.__p2f(pval)), fs_val) == (pval, fs_val)
end
for fs_val = 0x00:0xFF
  pval = reinterpret(Posit{8,2}, fs_val)
  @test (Posit{8,2}(FastSigmoid.__p2f(pval)), fs_val) == (pval, fs_val)
end

#conversion and deconversion of 16-bit posits
for fs_val = 0x0000:0xFFFF
  pval = reinterpret(Posit{16,0}, fs_val)
  @test (Posit{16,0}(FastSigmoid.__p2f(pval)), fs_val) == (pval, fs_val)
end
