#include <chrono>

#include "bench.hpp"

using namespace std::chrono;

namespace Bench
{
    Result Bench(int (*a)(), int (*b)())
    {
        Result r = {};
        auto first_start = high_resolution_clock::now();
        r.first = a();
        auto first_end = high_resolution_clock::now();

        auto second_start = high_resolution_clock::now();
        r.second = b();
        auto second_end = high_resolution_clock::now();

        r.time.first  = duration_cast<microseconds>(first_end - first_start).count();
        r.time.second = duration_cast<microseconds>(second_end - second_start).count();

        return r;
    }
}