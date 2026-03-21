#ifndef SOLVER_H
#define SOLVER_H

#include "grid.h"
#include "cage.h"

int solveSudoku(int grid[SIZE][SIZE], struct Cage cages[], int cage_count);

#endif