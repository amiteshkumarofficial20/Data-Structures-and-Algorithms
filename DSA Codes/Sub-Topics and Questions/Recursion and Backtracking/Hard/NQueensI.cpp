/*
------------------------------------------------------------
💡 Problem Name: N-Queens
📘 Problem Number: LeetCode #51

🧩 Problem Statement:
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that
no two queens attack each other. A queen can attack other queens in the same row,
column, or diagonal.

Return all distinct solutions to the n-queens puzzle.

Example:
Input: n = 4
Output:
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

------------------------------------------------------------
🧠 Intuition:
We use **Backtracking**:
- Place one queen in each column.
- For each column, try every row.
- Check if it's safe to place the queen (no other queen attacks it).
- If safe, place the queen and move to the next column.
- If all queens are placed → record the board configuration.
- If not, backtrack (remove the queen) and try the next row.

We have two implementations:
1️⃣ Simple version (checks safety by scanning board)
2️⃣ Optimized version (uses arrays to track attacks efficiently)

------------------------------------------------------------
⚙️ Algorithm (Common Logic):
1. Start from column 0.
2. For each row in that column:
   - Check if placing queen is safe.
   - If yes, place queen and recurse to next column.
   - If not safe, try next row.
3. If all columns are filled → store current configuration.
4. Backtrack and try next possibilities.

------------------------------------------------------------
⏱️ Time Complexity:
O(N!) – We try to place N queens with recursive exploration (worst case factorial).

💾 Space Complexity:
O(N²) – For the board + recursion stack.

------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/* ===========================================================
   🔹 APPROACH 1 — Basic Backtracking using `isSafe()` check
   =========================================================== */

class SolutionBasic
{
public:
    // Function to check if it’s safe to place a queen at (row, col)
    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        int dupRow = row, dupCol = col;

        // Check upper-left diagonal
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        // Check left side (same row)
        row = dupRow;
        col = dupCol;
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        // Check lower-left diagonal
        row = dupRow;
        col = dupCol;
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }

        return true;
    }

    // Backtracking function
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        // Base Case: all queens placed successfully
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        // Try placing queen in each row of this column
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';         // Place queen
                solve(col + 1, board, ans, n); // Recurse for next column
                board[row][col] = '.';         // Backtrack
            }
        }
    }

    // Main driver function
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.')); // Initialize n×n empty board
        solve(0, board, ans, n);                 // Start backtracking
        return ans;
    }
};

/* ===========================================================
   🔹 APPROACH 2 — Optimized Backtracking using Hash Arrays
   =========================================================== */

class SolutionOptimized
{
public:
    // Optimized backtracking with auxiliary arrays for O(1) safety checks
    void solve(int col, vector<string> &board, vector<vector<string>> &ans,
               vector<int> &leftRow, vector<int> &upperDiagonal,
               vector<int> &lowerDiagonal, int n)
    {
        // Base Case: All queens are placed
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        // Try placing queen in each row of current column
        for (int row = 0; row < n; row++)
        {
            // Check safety using precomputed arrays (O(1))
            if (leftRow[row] == 0 &&
                lowerDiagonal[row + col] == 0 &&
                upperDiagonal[n - 1 + col - row] == 0)
            {

                board[row][col] = 'Q'; // Place queen
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                // Recurse for next column
                solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

                // Backtrack: Remove queen and unmark arrays
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    // Main function
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.')); // Initialize empty board

        // Initialize helper arrays
        vector<int> leftRow(n, 0);               // Tracks occupied rows
        vector<int> upperDiagonal(2 * n - 1, 0); // Tracks upper diagonals (/)
        vector<int> lowerDiagonal(2 * n - 1, 0); // Tracks lower diagonals (\)

        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};

/* ===========================================================
   🔹 Example Usage (Main Function)
   =========================================================== */

int main()
{
    int n = 4;

    cout << "🔸 Using Basic Backtracking Approach:\n";
    SolutionBasic basic;
    vector<vector<string>> result1 = basic.solveNQueens(n);
    for (auto &config : result1)
    {
        for (auto &row : config)
            cout << row << endl;
        cout << "-----------------\n";
    }

    cout << "\n🔸 Using Optimized Backtracking Approach:\n";
    SolutionOptimized opt;
    vector<vector<string>> result2 = opt.solveNQueens(n);
    for (auto &config : result2)
    {
        for (auto &row : config)
            cout << row << endl;
        cout << "-----------------\n";
    }

    return 0;
}

/*
------------------------------------------------------------
✅ OUTPUT (for n = 4):
🔸 Using Basic Backtracking Approach:
.Q..
...Q
Q...
..Q.
-----------------
..Q.
Q...
...Q
.Q..
-----------------

🔸 Using Optimized Backtracking Approach:
.Q..
...Q
Q...
..Q.
-----------------
..Q.
Q...
...Q
.Q..
-----------------
------------------------------------------------------------
*/
