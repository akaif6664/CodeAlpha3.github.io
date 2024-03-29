#include <iostream>

using namespace std;

int board[9][9] = {
    // Initial Sudoku board (can be modified)
    {0, 9, 3, 1, 0, 5, 6, 4, 0},
    {7, 0, 0, 0, 0, 0, 0, 0, 5},
    {5, 0, 1, 2, 0, 9, 3, 0, 7},
    {2, 0, 0, 0, 0, 0, 0, 0, 3},
    {0, 3, 6, 9, 0, 7, 5, 2, 0},
    {9, 0, 0, 0, 0, 0, 0, 0, 1},
    {3, 0, 2, 4, 0, 8, 1, 0, 9},
    {6, 0, 0, 0, 0, 0, 0, 0, 4},
    {0, 4, 7, 3, 0, 2, 8, 5, 0}
};

// Function to print the Sudoku board
void printBoard() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (j % 3 == 0) {
        cout << "| "; // Add separators for better readability
      }
      cout << board[i][j] << " ";
    }
    cout << "|\n";
    if ((i + 1) % 3 == 0) {
      cout << "--------+-------+--------\n"; // Add visual blocks
    }
  }
}

// Function to check if a number is valid at a given position
bool isValid(int row, int col, int num) {
  // Check row and column
  for (int i = 0; i < 9; i++) {
    if (board[row][i] == num || board[i][col] == num) {
      return false;
    }
  }

  // Check 3x3 sub-grid
  int subGridRow = row / 3 * 3;
  int subGridCol = col / 3 * 3;
  for (int i = subGridRow; i < subGridRow + 3; i++) {
    for (int j = subGridCol; j < subGridCol + 3; j++) {
      if (board[i][j] == num) {
        return false;
      }
    }
  }

  return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku() {
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      if (board[row][col] == 0) { // Find an empty cell
        for (int num = 1; num <= 9; num++) {
          if (isValid(row, col, num)) {
            board[row][col] = num; // Place the number
            if (solveSudoku()) { // Recursively solve
              return true;
            }
            board[row][col] = 0; // Backtrack if placement doesn't lead to a solution
          }
        }
        return false; // No valid number can be placed here
      }
    }
  }
  return true; // Sudoku is solved
}

int main() {
  printBoard();

  if (solveSudoku()) {
    cout << "\nSolved Sudoku:\n";
    printBoard();
  } else {
    cout << "\nNo solution exists for this Sudoku puzzle.\n";
  }

  return 0;
}
