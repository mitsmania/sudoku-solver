#ifndef CAGE_H
#define CAGE_H

#define MAX_CAGES 50

struct Cell{
    int row;
    int col;
};

struct Cage
{
    int sum;
    int cell_count;
    struct Cell cells[9];
};

void readCages(struct Cage cages[], int cage_count);

#endif