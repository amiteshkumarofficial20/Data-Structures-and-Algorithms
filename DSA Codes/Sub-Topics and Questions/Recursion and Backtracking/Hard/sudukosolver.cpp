/************************************************************************************
 * 🧩 LeetCode Problem: 37. Sudoku Solver
 *
 * 📘 Problem Statement:
 * ---------------------
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * A sudoku solution must satisfy all of the following rules:
 *   1. Each of the digits 1–9 must occur exactly once in each row.
 *   2. Each of the digits 1–9 must occur exactly once in each column.
 *   3. Each of the digits 1–9 must occur exactly once in each of the 9 sub-boxes
 *      of the grid (3×3 regions).
 *
 * The '.' character indicates empty cells.
 *
 * You must solve the Sudoku by modifying the input board in-place.
 * The input board is always a valid 9×9 Sudoku puzzle.
 *
 * ----------------------------------------------------------------------------------
 * 🧠 Intuition:
 * -------------
 * Sudoku is a constraint satisfaction problem. Each cell must hold a number that
 * satisfies three rules — unique in row, column, and its 3×3 subgrid.
 *
 * We use **backtracking**:
 *   - Try placing digits '1' to '9' in an empty cell.
 *   - Check validity using a helper function (isValid()).
 *   - If valid, recurse to solve the rest.
 *   - If the board becomes invalid, backtrack (remove the number and try next).
 *
 * The recursion continues until the board is filled correctly.
 *
 * ----------------------------------------------------------------------------------
 * ⚙️ Approach:
 * ------------
 * 1️⃣ Traverse the Sudoku grid cell by cell.
 * 2️⃣ When an empty cell ('.') is found:
 *     - Try placing numbers from '1' to '9'.
 *     - For each number, check if it’s valid using isValid():
 *          • It’s not already in the same row.
 *          • It’s not already in the same column.
 *          • It’s not already in the same 3×3 subgrid.
 * 3️⃣ If a number is valid:
 *       - Place it temporarily and recursively call solve().
 *       - If the recursion returns true → the board is solved.
 *       - Else, undo the placement (backtrack) and try another number.
 * 4️⃣ If no number can fit in a cell, return false to trigger backtracking.
 * 5️⃣ Once all cells are filled, return true.
 *
 * ----------------------------------------------------------------------------------
 * 🧩 Example:
 * Input:
 * --------
 * 5 3 . . 7 . . . .
 * 6 . . 1 9 5 . . .
 * . 9 8 . . . . 6 .
 * 8 . . . 6 . . . 3
 * 4 . . 8 . 3 . . 1
 * 7 . . . 2 . . . 6
 * . 6 . . . . 2 8 .
 * . . . 4 1 9 . . 5
 * . . . . 8 . . 7 9
 *
 * Output:
 * --------
 * 5 3 4 6 7 8 9 1 2
 * 6 7 2 1 9 5 3 4 8
 * 1 9 8 3 4 2 5 6 7
 * 8 5 9 7 6 1 4 2 3
 * 4 2 6 8 5 3 7 9 1
 * 7 1 3 9 2 4 8 5 6
 * 9 6 1 5 3 7 2 8 4
 * 2 8 7 4 1 9 6 3 5
 * 3 4 5 2 8 6 1 7 9
 *
 * ----------------------------------------------------------------------------------
 * 🏢 Asked In:
 * ------------
 * Amazon, Google, Facebook, Microsoft, Apple, Adobe, Bloomberg
 *
 * ----------------------------------------------------------------------------------
 * ⏱️ Time Complexity:
 * -------------------
 * Worst case: O(9^n) — where n = number of empty cells
 * Each cell can have up to 9 possibilities.
 *
 * 💾 Space Complexity:
 * --------------------
 * O(1) — We modify the board in-place (only recursion stack used)
 *
 ************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /******************************************************
     * ✅ Helper Function: Check if placing 'ch' is valid
     ******************************************************/
    bool isValid(vector<vector<char>> &board, int row, int col, char ch)
    {
        for (int i = 0; i < 9; i++)
        {
            // 1️⃣ Check current row
            if (board[row][i] == ch)
                return false;

            // 2️⃣ Check current column
            if (board[i][col] == ch)
                return false;

            // 3️⃣ Check current 3x3 subgrid
            int subRow = 3 * (row / 3) + i / 3;
            int subCol = 3 * (col / 3) + i % 3;
            if (board[subRow][subCol] == ch)
                return false;
        }
        return true; // If all checks pass, placement is valid
    }

    /******************************************************
     * 🔁 Recursive Function: Solve the Sudoku board
     ******************************************************/
    bool solve(vector<vector<char>> &board)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                // 🕳️ If current cell is empty
                if (board[row][col] == '.')
                {
                    // Try placing digits '1' to '9'
                    for (char ch = '1'; ch <= '9'; ch++)
                    {
                        // Check if placement is valid
                        if (isValid(board, row, col, ch))
                        {
                            board[row][col] = ch; // Place number

                            // Recurse to fill next cell
                            if (solve(board))
                                return true;

                            // ❌ If not solvable → backtrack
                            board[row][col] = '.';
                        }
                    }
                    // If no number fits in this cell → backtrack
                    return false;
                }
            }
        }
        // ✅ If no empty cell found → solved
        return true;
    }

    /******************************************************
     * 🚀 Main API: Called from driver
     ******************************************************/
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};

/******************************************************
 * 🧪 Example Usage (VS Code Testing)
 ******************************************************/
int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution solver;
    solver.solveSudoku(board);

    cout << "✅ Solved Sudoku:\n";
    for (auto &row : board)
    {
        for (auto &ch : row)
            cout << ch << " ";
        cout << endl;
    }

    return 0;
}
