#include <stdio.h>
#include "sums.h"

void setup(int64_t N, double A[])
{
    printf("Inside sum_vector problem_setup, N=%lld \n", N);
    // Initialize the array with sequential values: 0, 1, 2, ..., N-1.
    for (int64_t i = 0; i < N; i++)
    {
         A[i] = static_cast<double>(i);
    }
}

double sum(int64_t N, double A[])
{
    printf("Inside sum_vector perform_sum, N=%lld \n", N);
    double total = 0.0;
    for (int64_t i = 0; i < N; i++)
    {
         total += A[i];
    }
    return total;
}
