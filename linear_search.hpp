#include <random> 
#include <cstdlib>
#include "mpi/mpi.h"

float run_loop(std::uniform_real_distribution<float>& x,
    std::mt19937& rng,
    long& local_size);

float find_min_time(long& local_size);

