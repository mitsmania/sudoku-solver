#include "raylib.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>   // for atoi()
#include "grid.h"
#include "solver.h"
#include "cage_rules.h"
#include "cage.h"

#define GRID_SIZE 9
#define CELL_SIZE 60
#define OFFSET_X 50
#define OFFSET_Y 50
#define MAX_CAGES 100

typedef struct {
    int row, col;
} Cell;

typedef struct {
    struct Cage cage; // backend cage
    Color color;      
} GUICage;

