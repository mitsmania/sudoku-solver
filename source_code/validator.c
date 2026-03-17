#include<stdio.h>

int checkRow(int grid[9][9], int row, int num)
{
    for(int i= 0; i < 9; i++)//column varies
    {
        if(grid[row][i] == num)
            return 0; // already exists
    }
    return 1;
}