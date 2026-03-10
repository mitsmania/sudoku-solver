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





void setValue( int row, int col, int layer, int value){
    if(row>=0 && row<=8 && col>=0 && col<=8 && layer>=0 && layer<=2){
        matrix[row][col][layer] = value;
    }else{
        printf("Invalid coordinates\n");
    }
}




int getValue( int row, int col, int layer) {
    if(row>= 0 && row <=8 && col >=0 && col <=8 && layer>= 0 && layer <=2) {
        return matrix[row][col][layer];
    } else {
        printf("Invalid coordinates\n");
        return -1;
    }
}


int isCellEmpty(int row, int col, int layer ){
    if (matrix[row][col][layer] == 0){
        return 1;
    }else{
        return 0;
    } 
}
