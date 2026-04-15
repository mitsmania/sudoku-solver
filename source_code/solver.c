#include <stdio.h>
#include "grid.h"
#include "validator.h"
#include "cage_rules.h"
#include "cage.h"

int DEBUG_MODE = 0;

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


int solveSudokuInternal (int grid[SIZE][SIZE], struct Cage cages[], int cage_count, int completed_cages[]){
    int row, col;
    
    if (findEmptyCell(grid, &row, &col)==0){
        return 1;
    }
    
    for (int num =1; num<=9; num++){
      if (DEBUG_MODE)
            printf("Trying %d at cell (%d, %d)\n", num, row, col);

        if (isValid(grid, row, col, num)){
            grid[row][col] = num;

            if (DEBUG_MODE)
                printf("Placed %d at cell (%d, %d)\n", num, row, col);

            if (checkAllCages(grid, cages, cage_count)){

                // Check if any cage just completed
                for (int i = 0; i < cage_count; i++){
                    if (!completed_cages[i] && isCageCompleteByIndex(grid, cages, i)){
                        completed_cages[i] = 1;

                        if (DEBUG_MODE){
                            printf("\n>>> Cage %d completed!\n", i + 1);
                            printGrid(grid);
                            printf(">>> Press Enter to continue...\n");
                            while (getchar() != '\n');
                            getchar();
                        }
                    }
                }

                if (solveSudokuInternal(grid, cages, cage_count, completed_cages)){
                    return 1;
                }
            }

            if (DEBUG_MODE)
                printf("Backtracking at cell (%d, %d), removing %d\n", row, col, grid[row][col]);

            grid[row][col] = 0;
        }
    }

    return 0;
}

// Wrapper function to initialize completed_cages array
int solveSudokuWrapper(int grid[SIZE][SIZE], struct Cage cages[], int cage_count){
    int completed_cages[cage_count];
    for (int i = 0; i < cage_count; i++){
        completed_cages[i] = 0;
    }
    return solveSudokuInternal(grid, cages, cage_count, completed_cages);
} 
