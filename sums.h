#ifndef __sum_h_
#define __sum_h_

// Use the C header for fixed-width integer types
#include <stdint.h>

// If int64_t isn’t defined, define it using the built-in type
#ifndef INT64_MAX
typedef __int64_t int64_t;
#endif

extern void setup(int64_t N, double A[]);
extern double sum(int64_t N, double A[]);

#endif  
