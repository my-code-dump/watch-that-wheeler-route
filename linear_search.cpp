#include "linear_search.hpp"

float run_loop(std::uniform_real_distribution<float>& x,
         std::mt19937& rng,
         long& local_size) {
    float output = x(rng);
    float temp = 0.0;
 
    // "Linear search" to find the MIN value
    for (long i = 0; i < local_size; i++) {
        temp = x(rng);
        if (temp < output) {
            output = temp;
        }
    }
 
    return output;
}

float find_min_time(long& local_size) {
    int rank, num_procs;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    
    // Random number generator
    int lower_bound = 0;
    int upper_bound = 10000;

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<float> dist(lower_bound,upper_bound);
    
    // Start timer
    float start = MPI_Wtime();

    // Run the llinear search
    float output = run_loop(dist, rng, local_size);
    // Apply all reduce on the minimum
    MPI_Allreduce(MPI_IN_PLACE, &output, 1, 
            MPI_FLOAT, MPI_MIN, MPI_COMM_WORLD);
    
    // End timer
    float end = MPI_Wtime();
    float time = end - start;

    MPI_Allreduce(MPI_IN_PLACE, &time, 1, 
            MPI_FLOAT, MPI_SUM, MPI_COMM_WORLD);

    time /= num_procs;
    return time;
}


