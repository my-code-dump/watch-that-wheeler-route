mpicxx -ggdb3 main.cpp -o main
mpirun -np 2 xterm -e gdb --tui ./main
