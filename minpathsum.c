/*
Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right, which minimizes the sum 
of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

#include <stdio.h>
#include <limits.h>

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0 || gridColSize == 0) return 0;

    int m = gridSize;       // Number of rows
    int n = gridColSize[0]; // Number of columns

    // Update the grid in-place to store the minimum path sums
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                // Top-left corner (starting point)
                continue;
            } else if (i == 0) {
                // First row, can only come from the left
                grid[i][j] += grid[i][j - 1];
            } else if (j == 0) {
                // First column, can only come from above
                grid[i][j] += grid[i - 1][j];
            } else {
                // General case
                grid[i][j] += grid[i - 1][j] < grid[i][j - 1] ? grid[i - 1][j] : grid[i][j - 1];
            }
        }
    }

    // The bottom-right corner contains the minimum path sum
    return grid[m - 1][n - 1];
}

int main() {
    int gridArray[3][3] = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    // Convert 2D array to array of pointers for function compatibility
    int* grid[3];
    for (int i = 0; i < 3; i++) {
        grid[i] = gridArray[i];
    }

    int gridColSize[3] = {3, 3, 3};
    int result = minPathSum(grid, 3, gridColSize);
    printf("Minimum Path Sum: %d\n", result);

    return 0;
}
