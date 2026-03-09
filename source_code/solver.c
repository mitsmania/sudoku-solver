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





