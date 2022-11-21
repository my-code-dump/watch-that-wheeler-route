#include <iostream>
#include <random> 
#include "linear_search.hpp"

int main (int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    float time;
    int rank, num_procs;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
	
	if (rank == 0) {
		std::cout << num_procs << " Procs" << std::endl;
	}

    for (int sz = 10; sz < 25; sz++) {
		long limit = 1 << sz;
		long local_size = limit / num_procs;
		
		time = find_min_time(local_size);

		if (rank == 0) { 
			std::cout << "2^" << sz << " | Time: " << time << "s" << std::endl;
		}
	}
    MPI_Finalize();
    return 0;
}
