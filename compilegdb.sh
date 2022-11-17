mpicxx -ggdb3 main.cpp linear_search.cpp -o linsrch
mpirun -np 2 xterm -e gdb --tui ./linsrch
