#include "grid.h"
#include "cage.h"
#include "cage_rules.h"

int checkCage(int grid[SIZE][SIZE], struct Cage *c){
    //the function is for checking one particular cage only
    int req_sum = c -> sum;
    int sum = 0;
    //used_nums will have 1 marked if number is in the cage and 0 if not...keeps track of used numbers
    int used_nums[10] = {0};
    //total_cells means the number of cells in the cage
    int total_cells = c->cell_count;
    for (int i=0; i<total_cells;i++){
        int r = c -> cells[i].row;
        int col = c -> cells[i].col;
        int val = grid[r][col];
        if (val == 0) continue;
        if (used_nums[val]) return 0;
        used_nums[val] = 1;
        sum += val;
    }
    if (sum>req_sum) return 0;
    return 1;

}
int checkAllCages(int grid[SIZE][SIZE], struct Cage cages[], int cage_count){
    for (int i=0; i<cage_count;i++){
        if(!checkCage(grid, &cages[i])) return 0;
    }
    return 1;
}