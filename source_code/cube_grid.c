#include<stdio.h>
int SIZE = 9;

int grid[9][9];

void initalizeGrid()
{
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            grid[9][9]=0;
}
void setvalue(int row,int col,int value){
    grid[row][col]=value;
}
int getvalue(int row,int col){
    return grid[row][col];
}