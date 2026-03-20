#include <stdio.h>
#include "grid.h"
#include "validator.h"
#include "cage_rules.h"

int findEmptyCell (int grid[SIZE][SIZE], int *row, int *col){

for (int i=0; i<SIZE; i++){
for (int j=0; j<SIZE; j++){
   if (isCellEmpty(grid, i, j) == 1){
       *row = i;
       *col = j;
       return 1;
   }
}
}
return 0;
}





int solveSudoku (int grid[SIZE][SIZE], struct Cage cages[], int cage_count){
    int row, col;
    
    if (findEmptyCell(grid, &row, &col)==0){
        return 1;
    }
    
    for (int num =1; num<=9; num++){
        if (isValid(grid, row, col, num)){
            grid[row][col] = num;
            
            if (checkAllCages(grid, cages, cage_count)){
                if (solveSudoku(grid, cages, cage_count)){
                    return 1;
                }
            }
            grid[row][col] = 0;
        }
    }
    return 0;
} 











