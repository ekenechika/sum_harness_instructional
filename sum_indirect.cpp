#include <stdio.h>
#include <stdlib.h>
#include "sums.h"

void setup(int64_t N, double A[])
{
    printf("Inside sum_indirect problem_setup, N=%lld \n", N);
    // Seed the random number generator for repeatability.
    srand48(42);
    // Initialize the array with random values in the range 0 to N-1.
    for (int64_t i = 0; i < N; i++)
    {
         A[i] = static_cast<double>(lrand48() % N);
    }
}

double sum(int64_t N, double A[])
{
    printf("Inside sum_indirect perform_sum, N=%lld \n", N);
    double total = 0.0;
    for (int64_t i = 0; i < N; i++)
    {
         total += A[i];
    }
    return total;
}

