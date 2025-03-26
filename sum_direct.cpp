#include <stdio.h>
#include "sums.h"

void setup(int64_t N, double A[])
{
    printf("Inside direct_sum problem_setup, N=%lld \n", N);
    // For direct sum, initialize array elements to 1.0.
    for (int64_t i = 0; i < N; i++)
    {
         A[i] = 1.0;
    }
}

double sum(int64_t N, double A[])
{
    printf("Inside direct_sum perform_sum, N=%lld \n", N);
    double total = 0.0;
    for (int64_t i = 0; i < N; i++)
    {
         total += A[i];
    }
    return total;
}

