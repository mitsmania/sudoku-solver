#include<stdio.h>
int SIZE = 9;

int grid[9][9];

void initalizeGrid(int grid[SIZE][SIZE])
{
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            grid[9][9]=0;
}

void setvalue(int grid[SIZE][SIZE], int row,int col,int value)
{
    grid[row][col]=value;
}

int getvalue(int grid[SIZE][SIZE], int row,int col)
{
    return grid[row][col];
}

int isCellEmpty(int grid[SIZE][SIZE], int row,int col) 
{
    return grid[row][col]==0;
}

void printGrid(int grid[SIZE][SIZE])
{
    printf("\n");
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}