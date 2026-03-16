#ifndef GRID_H
#define GRID_H

#define SIZE 9

void initalizeGrid(int grid[SIZE][SIZE]);
void setvalue(int grid[SIZE][SIZE], int row,int col,int value);
int getvalue(int grid[SIZE][SIZE], int row,int col);
int isCellEmpty(int grid[SIZE][SIZE], int row,int col);
void printGrid(int grid[SIZE][SIZE]);

#endif