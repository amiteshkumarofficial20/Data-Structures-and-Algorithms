#include <bits/stdc++.h>
using namespace std;

/* ============================================================
    🧩 PROBLEM: Rat in a Maze (Backtracking)
    ------------------------------------------------------------
    📄 Description:
    A rat is placed at the top-left corner (0,0) of a NxN maze.
    The maze contains:
       1 -> Open path
       0 -> Blocked path
    The rat must reach the bottom-right corner (n-1,n-1).

    The rat can move in 4 directions:
        D = Down  (x + 1, y)
        L = Left  (x, y - 1)
        R = Right (x, y + 1)
        U = Up    (x - 1, y)

    Goal: Find ALL possible paths the rat can take to reach the end.

    💼 Asked In:
    Amazon | Microsoft | Flipkart | Google | Adobe | Samsung | TCS | Infosys

    ⚙️ Techniques Used:
    - Backtracking
    - Recursion (DFS style)
    - Visited Matrix to prevent revisiting same cell

    📈 Time Complexity:  O(4^(N*N))
    📉 Space Complexity: O(N*N)  (visited matrix + recursion stack)

    ============================================================
    We will demonstrate 2 approaches:

        1️⃣ Using Individual `if` Statements  (Simple & Explicit)
        2️⃣ Using Direction Arrays + Single For Loop  (Compact & Elegant)
    ============================================================ */

/* ============================================================
   🧠 CLASS 1: SolutionIfStatements
   - Uses individual if-statements for D, L, R, U directions.
   ============================================================ */
class SolutionIfStatements
{
public:
    // ✅ Checks whether the next move is valid
    bool isSafe(int x, int y, int n, vector<vector<int>> &maze, vector<vector<int>> &visited)
    {
        return (x >= 0 && x < n && y >= 0 && y < n &&
                maze[x][y] == 1 && visited[x][y] == 0);
    }

    // 🧩 Recursive helper function
    void solve(int x, int y, int n, vector<vector<int>> &maze,
               vector<vector<int>> &visited, string path, vector<string> &res)
    {

        // 🎯 Base Case: destination reached
        if (x == n - 1 && y == n - 1)
        {
            res.push_back(path);
            return;
        }

        // Mark cell visited
        visited[x][y] = 1;

        // ↓ Move Down
        if (isSafe(x + 1, y, n, maze, visited))
            solve(x + 1, y, n, maze, visited, path + "D", res);

        // ← Move Left
        if (isSafe(x, y - 1, n, maze, visited))
            solve(x, y - 1, n, maze, visited, path + "L", res);

        // → Move Right
        if (isSafe(x, y + 1, n, maze, visited))
            solve(x, y + 1, n, maze, visited, path + "R", res);

        // ↑ Move Up
        if (isSafe(x - 1, y, n, maze, visited))
            solve(x - 1, y, n, maze, visited, path + "U", res);

        // 🔙 Backtrack to explore new paths
        visited[x][y] = 0;
    }

    vector<string> findPath(vector<vector<int>> &maze, int n)
    {
        vector<string> res;
        vector<vector<int>> visited(n, vector<int>(n, 0));

        if (maze[0][0] == 1)
            solve(0, 0, n, maze, visited, "", res);

        return res;
    }
};

/* ============================================================
   🧠 CLASS 2: SolutionForLoop
   - Uses direction arrays and one for-loop to handle all moves.
   ============================================================ */
class SolutionForLoop
{
public:
    bool isSafe(int x, int y, int n, vector<vector<int>> &maze, vector<vector<int>> &visited)
    {
        return (x >= 0 && x < n && y >= 0 && y < n &&
                maze[x][y] == 1 && visited[x][y] == 0);
    }

    void solve(int x, int y, int n, vector<vector<int>> &maze,
               vector<vector<int>> &visited, string path, vector<string> &res)
    {

        // 🎯 Base Case
        if (x == n - 1 && y == n - 1)
        {
            res.push_back(path);
            return;
        }

        visited[x][y] = 1;

        // Directions → Down, Left, Right, Up
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};
        char dir[] = {'D', 'L', 'R', 'U'};

        // Loop through all 4 possible moves
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            char move = dir[i];

            if (isSafe(newX, newY, n, maze, visited))
                solve(newX, newY, n, maze, visited, path + move, res);
        }

        // 🔙 Backtrack
        visited[x][y] = 0;
    }

    vector<string> findPath(vector<vector<int>> &maze, int n)
    {
        vector<string> res;
        vector<vector<int>> visited(n, vector<int>(n, 0));

        if (maze[0][0] == 1)
            solve(0, 0, n, maze, visited, "", res);

        return res;
    }
};

/* ============================================================
   🧪 DRIVER CODE
   Includes Example Input and Prints Both Approaches' Output
   ============================================================ */
int main()
{
    // 🧮 Example Input Maze
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    int n = maze.size();

    cout << "\n=============================\n";
    cout << "🎯 R A T   I N   A   M A Z E\n";
    cout << "=============================\n";
    cout << "Maze Size: " << n << "x" << n << "\n";
    cout << "Start: (0,0) → Destination: (" << n - 1 << "," << n - 1 << ")\n\n";

    // Show Maze Layout
    cout << "Maze Layout (1 = open, 0 = blocked):\n";
    for (auto &row : maze)
    {
        for (auto &cell : row)
            cout << cell << " ";
        cout << "\n";
    }
    cout << "\n";

    /* ---------------- Approach 1 ---------------- */
    cout << "🧩 Approach 1: Using Individual If Statements\n";
    cout << "---------------------------------------------\n";
    SolutionIfStatements obj1;
    vector<string> paths1 = obj1.findPath(maze, n);

    if (paths1.empty())
        cout << "No path found!\n";
    else
    {
        cout << "✅ Paths Found (" << paths1.size() << "):\n";
        for (auto &p : paths1)
            cout << p << " ";
        cout << "\n";
    }
    cout << "\n";

    /* ---------------- Approach 2 ---------------- */
    cout << "🧭 Approach 2: Using For Loop with Direction Arrays\n";
    cout << "---------------------------------------------------\n";
    SolutionForLoop obj2;
    vector<string> paths2 = obj2.findPath(maze, n);

    if (paths2.empty())
        cout << "No path found!\n";
    else
    {
        cout << "✅ Paths Found (" << paths2.size() << "):\n";
        for (auto &p : paths2)
            cout << p << " ";
        cout << "\n";
    }

    /* ---------------- Example Dry Run ---------------- */
    cout << "\n📘 Example Dry Run (for path = DDRDRR)\n";
    cout << "--------------------------------------\n";
    cout << "Start at (0,0)\n";
    cout << "↓ D → (1,0)\n";
    cout << "↓ D → (2,0)\n";
    cout << "→ R → (2,1)\n";
    cout << "↓ D → (3,1)\n";
    cout << "→ R → (3,2)\n";
    cout << "→ R → (3,3) ✅ Destination Reached!\n";

    cout << "\n=============================\n";
    cout << "✅ Program Finished Successfully\n";
    cout << "=============================\n\n";

    return 0;
}

/* ============================================================
   🧾 EXPECTED OUTPUT
   ------------------------------------------------------------
   🎯 R A T   I N   A   M A Z E
   =============================
   Maze Size: 4x4
   Start: (0,0) → Destination: (3,3)

   Maze Layout (1 = open, 0 = blocked):
   1 0 0 0
   1 1 0 1
   1 1 0 0
   0 1 1 1

   🧩 Approach 1: Using Individual If Statements
   ✅ Paths Found (2):
   DDRDRR DRDDRR

   🧭 Approach 2: Using For Loop with Direction Arrays
   ✅ Paths Found (2):
   DDRDRR DRDDRR

   📘 Example Dry Run (for path = DDRDRR)
   Start at (0,0)
   ↓ D → (1,0)
   ↓ D → (2,0)
   → R → (2,1)
   ↓ D → (3,1)
   → R → (3,2)
   → R → (3,3) ✅ Destination Reached!
   ============================================================ */
