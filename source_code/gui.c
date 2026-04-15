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

//first person ends
    while (!WindowShouldClose()) {

        Vector2 mouse = GetMousePosition();
        int col = (mouse.x - OFFSET_X) / CELL_SIZE;
        int row = (mouse.y - OFFSET_Y) / CELL_SIZE;
        bool insideGrid = (row >= 0 && row < GRID_SIZE && col >= 0 && col < GRID_SIZE);

        // Cage drawing
        if ((!enteringSum && !solved) || editingCage) {

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && insideGrid) {
                isDrawing = true;
                strokeModeAdd = !selected[row][col];
            }

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
                isDrawing = false;
                lastRow = -1;
                lastCol = -1;
            }

            if (isDrawing && insideGrid) {
                if ((row != lastRow || col != lastCol) &&
                    (cage_id[row][col] == 0 || (editingCage && cage_id[row][col] == editingIndex + 1))) {
                    selected[row][col] = strokeModeAdd;
                    lastRow = row;
                    lastCol = col;
                }
            }

            
            if (IsKeyPressed(KEY_TAB)) {
                enteringSum = true;
                if (!editingCage) {
                    inputLen = 0;
                    sumInput[0] = '\0';
                }
            }
        }
// 2nd person ends
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
//3rd person ends
        // Solve trigger
        if (IsKeyPressed(KEY_S) && !enteringSum && !editingCage) {
            struct Cage backendCages[MAX_CAGES];
            for(int i=0;i<cage_count;i++){
                backendCages[i] = guiCages[i].cage;
            }

            for(int i=0;i<GRID_SIZE;i++)
                for(int j=0;j<GRID_SIZE;j++)
                    solution[i][j] = 0;

            solved = solveSudokuWrapper(solution, backendCages, cage_count);
            unsolvable = !solved;
        }
//4th person ends
        // DRAWING
        BeginDrawing();
        ClearBackground(RAYWHITE);

        int gridPixelSize = CELL_SIZE * GRID_SIZE;

        // Cells
        for (int i=0;i<GRID_SIZE;i++) {
            for(int j=0;j<GRID_SIZE;j++) {
                int x = OFFSET_X + j*CELL_SIZE;
                int y = OFFSET_Y + i*CELL_SIZE;

                if (cage_id[i][j] != 0) {
                    DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, guiCages[cage_id[i][j]-1].color);
                }

                if (selected[i][j]) {
                    DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, SKYBLUE);
                }

                DrawRectangleLines(x, y, CELL_SIZE, CELL_SIZE, BLACK);
            }
        }
//5th person ends
        // Bold 3x3 box borders
        int lineWidth = 4;
        for(int i=0;i<=GRID_SIZE;i+=3){
            int x = OFFSET_X + i*CELL_SIZE;
            DrawRectangle(x - lineWidth/2, OFFSET_Y, lineWidth, gridPixelSize, BLACK);

            int y = OFFSET_Y + i*CELL_SIZE;
            DrawRectangle(OFFSET_X, y - lineWidth/2, gridPixelSize, lineWidth, BLACK);
        }

        // Cage sums (top-left)
        for(int k=0;k<cage_count;k++){
            int topRow=100, leftCol=100;
            for(int i=0;i<guiCages[k].cage.cell_count;i++){
                int r=guiCages[k].cage.cells[i].row;
                int c=guiCages[k].cage.cells[i].col;
                if(r<topRow || (r==topRow && c<leftCol)){
                    topRow=r;
                    leftCol=c;
                }
            }
            int x = OFFSET_X + leftCol*CELL_SIZE;
            int y = OFFSET_Y + topRow*CELL_SIZE;
            DrawText(TextFormat("%d", guiCages[k].cage.sum), x+2, y+2, 14, BLACK);
        }

        // Solution numbers
        if(solved){
            for(int i=0;i<GRID_SIZE;i++){
                for(int j=0;j<GRID_SIZE;j++){
                    if(solution[i][j]!=0){
                        int x = OFFSET_X + j * CELL_SIZE;
                        int y = OFFSET_Y + i * CELL_SIZE;
                        DrawText(TextFormat("%d", solution[i][j]), x + CELL_SIZE/4, y + CELL_SIZE/4, 30, BLACK);
                    }
                }
            }
        }

        // Show message if unsolvable
        if(unsolvable){
            DrawText("No solution found!", 200, 40, 35, RED);
        }

        // Sum input popup
        if (enteringSum){
            DrawRectangle(200, 250, 300, 150, LIGHTGRAY);
            DrawRectangleLines(200, 250, 300, 150, BLACK);
            DrawText("Enter Cage Sum:", 230, 270, 20, BLACK);
            DrawRectangle(230, 310, 240, 30, WHITE);
            DrawRectangleLines(230, 310, 240, 30, BLACK);
            DrawText(sumInput, 240, 315, 20, BLACK);
            DrawText("Press E to add more cells before confirming", 210, 360, 14, DARKGRAY);
        }

        DrawText("TAB: finalize | ENTER: confirm | ESC: cancel | S: solve", 50, 10, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

