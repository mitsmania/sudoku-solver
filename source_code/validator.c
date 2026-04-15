#include<stdio.h>
#include "grid.h"
#include "cage.h"
<<<<<<< HEAD


=======
>>>>>>> gui

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

<<<<<<< HEAD


// Check if a specific cage by index is complete
int isCageCompleteByIndex(int grid[SIZE][SIZE], struct Cage cages[], int cage_index){
    int filled = 1;
    int sum = 0;
    for (int j=0; j<cages[cage_index].cell_count; j++){
        int r = cages[cage_index].cells[j].row;
        int c = cages[cage_index].cells[j].col;
        if (grid[r][c]== 0){
            filled = 0;
            break;
        }
        sum += grid[r][c];
    }  
    return (filled && sum == cages[cage_index].sum);
}


=======
int isCageCompleteByIndex(int grid[SIZE][SIZE], struct Cage cages[], int cage_index){
    int filled = 1;
    int sum = 0;

    for (int j=0; j<cages[cage_index].cell_count; j++){
        int r = cages[cage_index].cells[j].row;
        int c = cages[cage_index].cells[j].col;

        if (grid[r][c] == 0){
            filled = 0;
            break;
        }

        sum += grid[r][c];
    }

    return (filled && sum == cages[cage_index].sum);
}
>>>>>>> gui
