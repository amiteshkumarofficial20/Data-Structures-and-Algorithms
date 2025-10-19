/*
====================================================
   LeetCode 48: Rotate Image (Brute Force Solution)
   Problem:
   Given an n x n matrix, rotate the image by 90°
   (clockwise). Modify matrix in-place if possible.

   Approach (Brute Force):
   - Use an extra matrix of same size.
   - For each element at (i, j), place it at (j, n-1-i).
   - Copy rotated matrix back into original.

   Time Complexity:  O(n^2)  (visit each cell once)
   Space Complexity: O(n^2)  (extra matrix storage)

====================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> rotated(n, vector<int>(n));

        // Fill rotated matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                rotated[j][n - 1 - i] = matrix[i][j];
            }
        }

        // Copy back to original matrix
        matrix = rotated;
    }
};

// ==================== MAIN ====================
int main()
{
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    sol.rotate(matrix);

    cout << "Rotated Matrix (90° clockwise):" << endl;
    for (auto row : matrix)
    {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}

/*
====================================================
   LeetCode 48: Rotate Image (In-Place Solution)
   Problem:
   Given an n x n matrix, rotate the image by 90°
   (clockwise). Modify matrix in-place.

   Approach (Optimal):
   1. Transpose the matrix: swap(matrix[i][j], matrix[j][i]).
   2. Reverse each row.

   Example:
   Input:
   1 2 3
   4 5 6
   7 8 9
   Output:
   7 4 1
   8 5 2
   9 6 3

   Time Complexity:  O(n^2)
   Space Complexity: O(1) (in-place, no extra matrix)

====================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // Step 1: Transpose
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// ==================== MAIN ====================
int main()
{
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    sol.rotate(matrix);

    cout << "Rotated Matrix (90° clockwise):" << endl;
    for (auto row : matrix)
    {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
