#include <stdio.h>
#define SIZE 9
int grid[SIZE][SIZE];

void initGrid()
{
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            grid[i][j]=0;
}

void setValue(int row,int col,int value)
{
    grid[row][col]=value;
}

int getValue(int row,int col)
{
    return grid[row][col];
}

int isCellEmpty(int row,int col)
{
    return grid[row][col]==0;
}
int main(){

    return 0;
}