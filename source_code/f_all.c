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

    return 0;
}
