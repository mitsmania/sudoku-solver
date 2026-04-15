#ifndef PARSER_H
#define PARSER_H

#include "grid.h"
#include "cage.h"

int parseFile(const char *filename,
              int grid[SIZE][SIZE],
              struct Cage cages[],
              int *cage_count);

#endif
