#include<stdio.h>
#include<string.h>
#include "parser.h"

int parseFile(const char *filename,
              int grid[SIZE][SIZE],
              struct Cage cages[],
              int *cage_count)
{
    FILE *fp = fopen(filename, "r");

    if(!fp){
        printf("Error opening file\n");
        return 0;
    }

    // READ GRID
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            fscanf(fp,"%d",&grid[i][j]);

    // READ CAGE COUNT
    fscanf(fp,"%d", cage_count);

    // READ CAGES
    for(int i=0;i<*cage_count;i++)
    {
        fscanf(fp,"%d %d",
               &cages[i].sum,
               &cages[i].cell_count);

        for(int j=0;j<cages[i].cell_count;j++)
        {
            fscanf(fp,"%d %d",
                   &cages[i].cells[j].row,
                   &cages[i].cells[j].col);
        }
    }

    fclose(fp);
    return 1;
}