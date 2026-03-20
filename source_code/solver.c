#include <stdio.h>

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
