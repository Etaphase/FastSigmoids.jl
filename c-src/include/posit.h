#ifndef __POSIT_H
#define __POSIT_H

#include <stdint.h>
#include <math.h>
#include <stdbool.h>

#define P8INF      ((uint8_t) 0x80)
#define P8MAXREAL  ((uint8_t) 0x7f)
#define P8MINREAL  ((uint8_t) 0x81)
#define P8POSSMALL ((uint8_t) 0x01)
#define P8NEGSMALL ((uint8_t) 0xff)
#define P8ZER      ((uint8_t) 0x00)
#define P16INF      ((uint16_t) 0x8000)
#define P16MAXREAL  ((uint16_t) 0x7fff)
#define P16MINREAL  ((uint16_t) 0x8001)
#define P16POSSMALL ((uint16_t) 0x0001)
#define P16NEGSMALL ((uint16_t) 0xffff)
#define P16ZER      ((uint16_t) 0x0000)
#define P32INF      0x80000000L
#define P32MAXREAL  0x7fffffffL
#define P32MINREAL  0x80000001L
#define P32POSSMALL 0x00000001L
#define P32NEGSMALL 0xffffffffL
#define P32ZER      0x00000000L

typedef union {uint8_t udata; int8_t sdata;} p8e0_t ;
typedef union {uint8_t udata; int8_t sdata;} p8e1_t ;
typedef union {uint8_t udata; int8_t sdata;} p8e2_t ;

typedef union {uint16_t udata; int16_t sdata;} p16e0_t ;
typedef union {uint16_t udata; int16_t sdata;} p16e1_t ;
typedef union {uint16_t udata; int16_t sdata;} p16e2_t ;

typedef union {uint32_t udata; int32_t sdata;} p32e0_t ;
typedef union {uint32_t udata; int32_t sdata;} p32e1_t ;
typedef union {uint32_t udata; int32_t sdata;} p32e2_t ;
typedef union {uint32_t udata; int32_t sdata;} p32e3_t ;

typedef struct {uint64_t *cache; uint64_t exponent; uint64_t leading_ones;} fdp_cache8e0_t;
typedef struct {uint64_t *cache; uint64_t exponent; uint64_t leading_ones;} fdp_cache8e1_t;
typedef struct {uint64_t *cache; uint64_t exponent; uint64_t leading_ones;} fdp_cache8e2_t;

typedef struct {uint64_t *cache; uint64_t exponent; uint64_t leading_ones;} fdp_cache16e0_t;
typedef struct {uint64_t *cache; uint64_t exponent; uint64_t leading_ones;} fdp_cache16e1_t;
typedef struct {uint64_t *cache; uint64_t exponent; uint64_t leading_ones;} fdp_cache16e2_t;

typedef struct {uint64_t *cache; uint64_t exponent; uint64_t leading_ones;} fdp_cache32e0_t;
typedef struct {uint64_t *cache; uint64_t exponent; uint64_t leading_ones;} fdp_cache32e1_t;
typedef struct {uint64_t *cache; uint64_t exponent; uint64_t leading_ones;} fdp_cache32e2_t;
typedef struct {uint64_t *cache; uint64_t exponent; uint64_t leading_ones;} fdp_cache32e3_t;


//c error handling routines
extern "C" int set_nan_jmp();
extern "C" void throw_nan_jmp();

#endif
