//
// (C) 2022-2023, E. Wes Bethel
// benchmark-* harness for running different versions of the sum study
// usage: no command line arguments
// set problem sizes, block sizes in the code below
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>
#include "sums.h"

int main(int argc, char** argv) 
{
    std::cout << std::fixed << std::setprecision(2);
    // Maximum problem size (256M elements)
    #define MAX_PROBLEM_SIZE (1LL << 28)
    
    // Define a range of problem sizes: from MAX/32 to MAX
    std::vector<int64_t> problem_sizes{
        MAX_PROBLEM_SIZE >> 5, 
        MAX_PROBLEM_SIZE >> 4, 
        MAX_PROBLEM_SIZE >> 3, 
        MAX_PROBLEM_SIZE >> 2, 
        MAX_PROBLEM_SIZE >> 1, 
        MAX_PROBLEM_SIZE
    };
    
    double *A = (double *)malloc(sizeof(double) * MAX_PROBLEM_SIZE);

    // Theoretical peak memory bandwidth (in bytes/sec) – adjust this value based on Perlmutter specs.
    const double peak_bandwidth = 500e9; // example: 500 GB/s

    // Loop over each problem size
    for (int64_t N : problem_sizes) 
    {
         printf("Working on problem size N=%lld \n", N);

         // Set up the problem-specific data in A
         setup(N, A);

         // Start timer
         auto start = std::chrono::high_resolution_clock::now();
         // Call the user-implemented sum function
         double s = sum(N, A);
         // Stop timer
         auto end = std::chrono::high_resolution_clock::now();
         std::chrono::duration<double> elapsed = end - start;
         double time_sec = elapsed.count();

         // Print results
         printf("Sum result = %lf \n", s);
         printf("Elapsed time = %lf seconds\n", time_sec);

         // Compute MFLOP/s: assuming one addition per element
         double mflops = (static_cast<double>(N) / time_sec) / 1e6;
         printf("MFLOP/s = %lf\n", mflops);

         // Compute memory bandwidth utilized.
         // For each element, we read 8 bytes (sizeof(double)).
         double bytes_accessed = static_cast<double>(N) * sizeof(double);
         double bandwidth = bytes_accessed / time_sec;  // bytes per second
         double percent_bandwidth = (bandwidth / peak_bandwidth) * 100.0;
         printf("Memory Bandwidth Utilized = %lf%%\n", percent_bandwidth);

         // Compute average memory latency per access (in nanoseconds)
         double latency_ns = (time_sec / N) * 1e9;
         printf("Average Memory Latency = %lf ns\n", latency_ns);

         printf("-----------------------------------------\n");
    }
    free(A);
    return 0;
}
