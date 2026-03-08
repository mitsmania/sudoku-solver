#include<stdio.h>
int a[9][9][3];
void initialize(){
    int i, j ,k;
    for(i=1; i<=9; i++){
       for(j=1; j<=9; j++){
          for(k=1; k<=3; k++){
            a[i][j][k] = 0;
          }
       }
    }
}

void printmatrix(){
    int i, j, k;
    for(k=1; k<=3; k++){
        printf("layer: %d", k);

        for(i=1; i<=9; i++){
            for(j=1; j<=9; j++){
                printf("%d", a[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void setvalue(int a[9][9][3], int i, int j, int k, int value){
    if(i>=1 && i<=9 && j>=1 && j<=9 && k>=1 && k<=3){
        a[i][j][k] = value;
    }else{
        printf("invalid coordinates\n");
    }
}