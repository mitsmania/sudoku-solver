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

    bool isDrawing = false;
    bool strokeModeAdd = true;
    int lastRow = -1, lastCol = -1;

    bool enteringSum = false;
    char sumInput[10] = "";
    int inputLen = 0;

    bool solved = false;
    bool unsolvable = false;

    // Edit mode for cage
    bool editingCage = false;
    int editingIndex = -1;
// Text input for sum
        if (enteringSum) {
            int key = GetCharPressed();
            while (key > 0) {
                if ((key >= '0' && key <= '9') && inputLen < 9) {
                    sumInput[inputLen++] = (char)key;
                    sumInput[inputLen] = '\0';
                }
                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE) && inputLen > 0) {
                inputLen--;
                sumInput[inputLen] = '\0';
            }

            // Press E to add more cells before confirming
            if (IsKeyPressed(KEY_E) && !editingCage && cage_count < MAX_CAGES) {
                editingCage = true;
                editingIndex = cage_count; // new cage index
                // sumInput is kept as is
                enteringSum = true; // reopen prompt
            }

            // Press ENTER to finalize cage
            if (IsKeyPressed(KEY_ENTER) && inputLen > 0) {

                struct Cage newCage;
                newCage.cell_count = 0;
                newCage.sum = atoi(sumInput);

                for (int i = 0; i < GRID_SIZE; i++) {
                    for (int j = 0; j < GRID_SIZE; j++) {
                        if (selected[i][j]) {
                            newCage.cells[newCage.cell_count].row = i;
                            newCage.cells[newCage.cell_count].col = j;
                            newCage.cell_count++;
                        }
                    }
                }

                if (newCage.cell_count > 0) {
                    if (editingCage) {
                        guiCages[editingIndex].cage = newCage;
                        for (int i = 0; i < newCage.cell_count; i++) {
                            int r = newCage.cells[i].row;
                            int c = newCage.cells[i].col;
                            cage_id[r][c] = editingIndex + 1;
                            selected[r][c] = false;
                        }
                    } else {
                        guiCages[cage_count].cage = newCage;
                        guiCages[cage_count].color = (Color){
                            GetRandomValue(100,255),
                            GetRandomValue(100,255),
                            GetRandomValue(100,255),
                            255
                        };
                        for (int i = 0; i < newCage.cell_count; i++) {
                            int r = newCage.cells[i].row;
                            int c = newCage.cells[i].col;
                            cage_id[r][c] = cage_count + 1;
                            selected[r][c] = false;
                        }
                        cage_count++;
                    }
                }

                enteringSum = false;
                editingCage = false;
                editingIndex = -1;
            }

            if (IsKeyPressed(KEY_ESCAPE)) {
                enteringSum = false;
                editingCage = false;
                editingIndex = -1;
            }
        }