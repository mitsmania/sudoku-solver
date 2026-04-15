#ifndef VALIDATOR_H
#define VALIDATOR_H
#include "grid.h"
#include "cage.h"

int checkRow(int grid[SIZE][SIZE], int row, int num);
int checkCol(int grid[SIZE][SIZE], int col, int num);
int checkBox(int grid[SIZE][SIZE], int row, int col, int num);
int isValid(int grid[SIZE][SIZE], int row, int col, int num);
int isCageCompleteByIndex(int grid[SIZE][SIZE], struct Cage cages[], int cage_index);

#endif