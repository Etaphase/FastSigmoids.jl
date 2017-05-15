#ifndef __POSIT_H
#define __POSIT_H

typedef union {uint8_t udata; int8_t sdata} p8e0_t;
typedef union {uint8_t udata; int8_t sdata} p8e1_t;
typedef union {uint8_t udata; int8_t sdata} p8e2_t;

typedef union {uint16_t udata; int16_t sdata} p16e0_t;
typedef union {uint16_t udata; int16_t sdata} p16e1_t;
typedef union {uint16_t udata; int16_t sdata} p16e2_t;

typedef union {uint32_t udata; int32_t sdata} p32e0_t;
typedef union {uint32_t udata; int32_t sdata} p32e1_t;
typedef union {uint32_t udata; int32_t sdata} p32e2_t;
typedef union {uint32_t udata; int32_t sdata} p32e3_t;

typedef struct {uint64_t *cache; uint64_t exponent; uint64_t leading_ones} fdp_cache8e0_t;
typedef struct {uint64_t *cache; uint64_t exponent; uint64_t leading_ones} fdp_cache8e1_t;
typedef struct {uint64_t *cache; uint64_t exponent; uint64_t leading_ones} fdp_cache8e2_t;

typedef struct {uint64_t *cache; uint64_t exponent; uint64_t leading_ones} fdp_cache16e0_t;
typedef struct {uint64_t *cache; uint64_t exponent; uint64_t leading_ones} fdp_cache16e1_t;
typedef struct {uint64_t *cache; uint64_t exponent; uint64_t leading_ones} fdp_cache16e2_t;

typedef struct {uint64_t *cache; uint64_t exponent; uint64_t leading_ones} fdp_cache32e0_t;
typedef struct {uint64_t *cache; uint64_t exponent; uint64_t leading_ones} fdp_cache32e1_t;
typedef struct {uint64_t *cache; uint64_t exponent; uint64_t leading_ones} fdp_cache32e2_t;
typedef struct {uint64_t *cache; uint64_t exponent; uint64_t leading_ones} fdp_cache32e3_t;


//c error handling routines
extern "C" int set_nan_jmp();
extern "C" void throw_nan_jmp();

#endif
