#include <iostream>
#include <stdlib.h>
#include <random> 
#include "mpi/mpi.h"

double randomizer(double min, double max) {
    double x = (double)rand() / RAND_MAX;
    return (min + x * (max - min));
}

void find_min(long local_size, long limit) {
    int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    double lower_bound = 0;
    double upper_bound = 10000;
    double temp = 0.0;
    double output = randomizer(lower_bound,upper_bound);

    // Linear search to find the MIN value
    for (long i = 0; i < local_size; i++) {
        temp = randomizer(lower_bound,upper_bound);
        if (temp < output) {
            output = temp;
        } 
    }

    std::cout << "Rank " << rank << " | Out:" << output << std::endl;
}

int main (int argc, char* argv[]) {
    MPI_Init(&argc, &argv);
    srand(time(NULL));

    int rank, num_procs;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    long limit = 1 << 10;
    long local_size = limit / num_procs;

    find_min(local_size, limit);

    MPI_Finalize();
    return 0;
}
