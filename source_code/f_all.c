#include<stdio.h>
#include "grid.h"
#include "cage.h"
#include "solver.h"
#include "parser.h"

int main()
{
    int grid[SIZE][SIZE];
    struct Cage cages[100];
    int cage_count;

    initalizeGrid(grid);

    int choice;
    scanf("%d",&choice);

    if(choice == 1)
    {
        for(int i=0;i<SIZE;i++)
            for(int j=0;j<SIZE;j++)
                scanf("%d",&grid[i][j]);

        scanf("%d",&cage_count);
        readCages(cages,cage_count);
    }
    else if(choice == 2)
    {
        char filename[100];
        scanf("%s",filename);

        if(!parseFile(filename,grid,cages,&cage_count))
            return 1;

        if(cage_count > 100)
            return 1;
    }
    else
    {
        printf("Invalid choice\n");
        return 1;
    }
    int used[9][9] = {0};

    for(int i=0;i<cage_count;i++){
         for(int j=0;j<cages[i].cell_count;j++){
            int r = cages[i].cells[j].row;


  for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(!used[i][j]){
                printf("WARNING: Cell (%d,%d) not in any cage\n", i, j);
            }
        }
    }
    printf("\nSolving Sudoku...\n");
    if(solveSudoku(grid,cages,cage_count))
        printGrid(grid);
    
    return 0;
} 
