/// @example count_primes.cpp
/// This example shows how to count primes.

#include <primesieve.hpp>
#include <stdint.h>
#include <iostream>
#include <chrono>

using namespace std::chrono;

int main()
{
    uint64_t count = primesieve::count_primes(0, 1000);
    std::cout << "Primes below 1000 = " << count << std::endl;

    // use multi-threading for large intervals
    uint64_t stop = 10'000'000'000;
    const auto tim0 = high_resolution_clock::now();
    //
    //count = primesieve::parallel_count_primes(0, stop);
    primesieve::ParallelPrimeSieve pps;
    pps.setSieveSize(pps.getSieveSize());
    pps.setNumThreads(8);
    count = pps.countPrimes(0, stop);
    //
    const auto tim1 = high_resolution_clock::now();
    std::cout << "Primes below 10^9 = " << count << std::endl;
    std::cout << "time: " << duration_cast<milliseconds>(tim1 - tim0).count() << std::endl;

    return 0;
}
