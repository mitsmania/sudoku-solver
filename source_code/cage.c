#include<stdio.h>
struct Cell{
    int row;
    int col;
};
struct Cage{
    int sum;
    int cell_count;
    struct Cell cells[9];
};
void readCages(struct Cage cages[], int cage_count)
{
    for(int i = 0; i < cage_count; i++)
    {
        printf("\nCage %d\n", i+1);

        printf("Enter sum: ");
        scanf("%d", &cages[i].sum);

        printf("Enter number of cells: ");
        scanf("%d", &cages[i].cell_count);

       
    }
}

