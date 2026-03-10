#include <stdio.h>

int matrix[9][9][3]; 

int checkRow(int layer, int row, int num){
    for (int col=0; col<9; col++){
        if (matrix[row][col][layer] == num){
            return 0;
        }
    }
    return 1;
}


int checkCol(int layer, int col, int num){
    for (int row=0; row<9; row++){
        if (matrix[row][col][layer] == num){
            return 0;
        }
    }
    return 1;
}


int checkBox (int layer, int row, int col, int num){
    
    int startRow = (row/3)*3;
    int startCol = (col/3)*3;
    
    for (int r=startRow; r<startRow + 3; r++){
        for (int c =startCol; c<startCol + 3; c++){
            if (matrix[r][c][layer]== num){
                return 0;
            }
        }
    }
    return 1;
}



int checkEmptyMatrix (){
    for (int l=0; l<3; l++){
        for (int r=0; r<9; r++){
            for (int c=0; c<9; c++){
                if (matrix[r][c][l]==0){
                    return 1;
                }
            }
        }
    }
    return 0;
}


int checkEmptyCell(int *row, int *col, int *layer){
    for (int l=0; l<3; l++){
    for (int r=0; r<9; r++){
        for (int c=0; c<9; c++){
            if(matrix[r][c][l]==0){
                *layer = l;
                *row = r;
                *col = c;
                return 1;
            }
        }
    }
}
return 0;
}





