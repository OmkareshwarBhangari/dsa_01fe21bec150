#include <stdio.h>

#define I 5

void printsol(int arr[I][I]) {
    for (int i = 0; i < I; i++) {

        for (int j = 0; j < I; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed on arr[row][col]
int safecheck(int arr[I][I], int row, int col) {
    // Check the row on the left side
    for (int i = 0; i < col; i++) {
        if (arr[row][i]==1) {
            return 0;
        }
    }
    // Check the upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (arr[i][j]) {
            return 0;
        }
    }
    // Check the lower diagonal on the left side
    for (int i = row, j = col; j >= 0 && i < I; i++, j--) {
        if (arr[i][j]) {
            return 0;
        }
    }
    // If all checks pass, it's safe to place a queen
    return 1;
}

// Recursive function to solve the N-queens problem using backtracking
int solvequeens(int arr[I][I], int col) {
    // Base case: all queens are placed
    if (col >= I) {
        return 1;
    }
    // Try placing a queen in each row of the current column
    for (int i = 0; i < I; i++) {
        // Check if it's safe to place a queen in arr[i][col]
        if (safecheck(arr, i, col)) {
            // Place the queen
            arr[i][col] = 1;
            // Recur to place queens in the next column
            if (solvequeens(arr, col + 1)) {
                return 1;
            }
            // Backtrack: remove the queen and try the next row
            arr[i][col] = 0;
        }
    }
    // If no queen can be placed in this column, return failure
    return 0;
}

int main() {
    int arr[I][I] = {0}; // Initialize the arr to all 0s
    if (solvequeens(arr, 0)) {
        printf("Solution:\n");
        printsol(arr);
    } else {
        printf("No solution found.\n");
    }
    return 0;
}


