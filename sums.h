#ifndef __sum_h_
#define __sum_h_

#include <cstdint>
using std::int64_t;  // Bring int64_t into the global namespace

extern void setup(int64_t N, double A[]);
extern double sum(int64_t N, double A[]);

#endif
