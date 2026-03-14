#include <stdio.h>
#include <stdbool.h>

#define L 6
#define N 9

int grid[L][N][N];

bool isSafe(int layer, int row, int col, int num) {

    // row check
    for (int x = 0; x < N; x++)
        if (grid[layer][row][x] == num)
            return false;

    // column check
    for (int x = 0; x < N; x++)
        if (grid[layer][x][col] == num)
            return false;

    // 3x3 box check
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[layer][i + startRow][j + startCol] == num)
                return false;

    // check same position in other layers
    for (int l = 0; l < L; l++)
        if (grid[l][row][col] == num)
            return false;

    return true;
}

bool solve(int layer, int row, int col) {

    if (layer == L)
        return true;

    if (row == N)
        return solve(layer, 0, col + 1);

    if (col == N)
        return solve(layer + 1, row, 0);

    if (grid[layer][row][col] != 0)
        return solve(layer, row + 1, col);

    for (int num = 1; num <= 9; num++) {

        if (isSafe(layer, row, col, num)) {

            grid[layer][row][col] = num;

            if (solve(layer, row + 1, col))
                return true;

            grid[layer][row][col] = 0;
        }
    }

    return false;
}

void printGrid() {
    for (int l = 0; l < L; l++) {
        printf("\nLayer %d\n", l + 1);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                printf("%d ", grid[l][i][j]);
            printf("\n");
        }
    }
}

int main() {

    printf("Enter 6 layers of 9x9 Sudoku (0 for empty):\n");

    for (int l = 0; l < L; l++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &grid[l][i][j]);

    if (solve(0,0,0))
        printGrid();
    else
        printf("No solution exists\n");

    return 0;
}