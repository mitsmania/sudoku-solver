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