#include <iostream>
#include <random> 
#include <cstdlib>
#include <vector>
#include "mpi.h"

float run_loop(std::vector<float>& partition);

float find_min_time(long& local_size);

