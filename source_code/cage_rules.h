#ifndef CAGE_RULES_H
#define CAGE_RULES_H

#include "grid.h"
#include "cage.h"

int checkCage(int grid[SIZE][SIZE], struct Cage *c);
int checkAllCages(int grid[SIZE][SIZE], struct Cage cages[], int cage_count);

#endif