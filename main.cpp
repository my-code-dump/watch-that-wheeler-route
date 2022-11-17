#include <iostream>
#include <random> 
#include "linear_search.hpp"

int main (int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    float time;
    int rank, num_procs;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    long limit = 1 << 25;
    long local_size = limit / num_procs;

    time = find_min_time(local_size);

    std::cout << "Rank " << rank << " | Time: " << time << "s" << std::endl;

    MPI_Finalize();
    return 0;
}
