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

int main() {
    InitWindow(700, 700, "Killer Sudoku - Cage Builder");
    SetTargetFPS(60);

    bool selected[GRID_SIZE][GRID_SIZE] = {false};
    int cage_id[GRID_SIZE][GRID_SIZE] = {0};

    GUICage guiCages[MAX_CAGES];
    int cage_count = 0;

    int solution[GRID_SIZE][GRID_SIZE] = {0};

   
