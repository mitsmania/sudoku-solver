#include<stdio.h>
#include "cage.h"

void readCages(struct Cage cages[], int cage_count)
{
    for(int i = 0; i < cage_count; i++)
    {
        printf("\nCage %d\n", i+1);

        printf("Enter sum: ");
        scanf("%d", &cages[i].sum);

        printf("Enter number of cells: ");
        scanf("%d", &cages[i].cell_count);

        for(int j = 0; j < cages[i].cell_count; j++)
        {
            printf("Enter row and column: ");
            scanf("%d %d",
                  &cages[i].cells[j].row,
                  &cages[i].cells[j].col);
        }
    }
}
int main()
{
    struct Cage cages[50];
    int cage_count;

    printf("Enter number of cages: ");
    scanf("%d", &cage_count);

    readCages(cages, cage_count);

    return 0;
}