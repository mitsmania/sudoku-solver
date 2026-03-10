#include<stdio.h>


int matrix[9][9][3];


void initMatrix(){
    for(int row=0; row<9; row++){
       for(int col=0; col<9; col++){
          for(int layer=0; layer<3; layer++){
            matrix[row][col][layer] = 0;
          }
       }
    }
}



void printMatrix(){
    for(int layer=0; layer<3; layer++){
        printf("layer: %d\n", layer);

        for(int row=0; row<9; row++){
            for(int col=0; col<9; col++){
                printf("%d", matrix[row][col][layer]);
            }
            printf("\n");
        }
        printf("\n");
    }
}





void setValue(int matrix[9][9][3], int row, int col, int layer, int value){
    if(row>=0 && row<=8 && col>=0 && col<=8 && layer>=0 && layer<=2){
        matrix[row][col][layer] = value;
    }else{
        printf("Invalid coordinates\n");
    }
}




void getValue(int a[9][9][3], int i, int j, int k, int value) {
    if(i >= 1 && i <=9 && j >= 1 && j <=9 && k >= 1 && k <=3) {
        return a[i][j][k];
    } else {
        printf("Invalid coordinates\n");
        return -1;
    }
}

void IscellEmpty( int a[9][9][3],int i, int j, int k ){
    if (a[9][9][3] = 0){
        return 1;
    }else{
        return 0;
    } 
}