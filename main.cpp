#include <iostream>
#include <random> 
#include "mpi/mpi.h"

void printMe(long x) {
    int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    double lower_bound = 0;
    double upper_bound = 100000;
    double output = 0.0;
    std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
    std::default_random_engine re;

    for (int i = 0; i < 10; i++) {
        output = unif(re);
    }

    long currentIndex;
    long endIndex;

    currentIndex = x * rank;
    endIndex = x * (rank + 1) + 1;


}

int main (int argc, char* argv[]) {
    MPI_Init(&argc, &argv);
    
    int rank, num_procs;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    long limit = 1 << 30;
    long local_size = limit / num_procs;

    printMe(local_size);

    MPI_Finalize();
    return 0;
}
