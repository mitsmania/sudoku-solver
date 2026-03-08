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
