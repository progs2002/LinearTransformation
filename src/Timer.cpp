#include "Timer.h"

int getTime()
{
    auto start = std::chrono::high_resolution_clock::now();
    auto stop = std::chrono::high_resolution_clock::now();
    auto dt = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    return dt.count();
}
