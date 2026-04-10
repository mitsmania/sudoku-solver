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
int isValid(int grid[9][9], int row, int col, int num)
{
    return checkRow(grid, row, num) &&
           checkCol(grid, col, num) &&
           checkBox(grid, row, col, num);
}

// Online C compiler to run C program online
#include <stdio.h>

int isCageComplete (int grid[SIZE][SIZE], struct Cage cages[], int cage_count){
    for (int i=0; i< cage_count; i++){
        int filled =1;
        int sum = 0;
    for (int j=0; j<cages[i].cell_count; j++){
        int r = cages[i].cells[j].row;
        int c = cages[i].cells[j].col;
        if (grid[r][c]== 0){
            filled = 0;
            break;
        }
        sum += grid[r][c];
    }  
    if (filled && sum == cages[i].target){
        return 1;
    }

}
return 0;
}
