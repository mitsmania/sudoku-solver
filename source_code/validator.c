#include<stdio.h>

int checkRow(int grid[9][9], int row, int num)
{
    for(int i= 0; i < 9; i++)
    {
        if(grid[row][i] == num)
            return 0; // already exists
    }
    return 1;
}
int checkCol(int grid[9][9], int col, int num)
{
    for(int j = 0; j < 9; j++)
    {
        if(grid[j][col] == num)
            return 0;//already exists
    }
    return 1;
}

int checkBox(int grid[9][9], int row, int col, int num)
{
    int startRow = row - (row % 3);
    int startCol = col - (col % 3);

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(grid[startRow + i][startCol + j] == num)
            {
                return 0; // number already exists in box
            }
        }
    }

    return 1; 
}