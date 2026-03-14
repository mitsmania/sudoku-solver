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
