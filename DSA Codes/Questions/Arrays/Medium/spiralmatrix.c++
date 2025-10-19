/*
====================================================
   LeetCode 54: Spiral Matrix
   Problem Statement:
   Given an m x n matrix, return all elements of the
   matrix in spiral order.

   Example:
   Input:  [[1,2,3],
            [4,5,6],
            [7,8,9]]
   Output: [1,2,3,6,9,8,7,4,5]

   -------------------------------------------------
   ✅ Approach:
   - Maintain 4 boundaries: top, bottom, left, right.
   - Traverse in 4 directions:
        1. Left → Right   (top row)
        2. Top  → Bottom  (right column)
        3. Right → Left   (bottom row, if still valid)
        4. Bottom → Top   (left column, if still valid)
   - After each direction, shrink the boundary inward.
   - Continue until all elements are visited.

   -------------------------------------------------
   ⏱ Time Complexity:
   - Each element is visited exactly once → O(m * n),
     where m = number of rows, n = number of columns.

   🗂 Space Complexity:
   - Output vector stores all m*n elements → O(m * n).
   - No extra space except boundaries → O(1) auxiliary.

====================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans; // final answer to store spiral order

        // Handle empty matrix case
        if (matrix.empty())
            return ans;

        // Initialize boundaries
        int top = 0;
        int bottom = matrix.size() - 1; // last row index
        int left = 0;
        int right = matrix[0].size() - 1; // last col index

        // Loop until boundaries overlap
        while (top <= bottom && left <= right)
        {

            // 1. Traverse Left → Right across the top row
            for (int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++; // move top boundary down

            // 2. Traverse Top → Bottom along the right column
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--; // move right boundary left

            // 3. Traverse Right → Left across the bottom row
            if (top <= bottom)
            { // check validity
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--; // move bottom boundary up
            }

            // 4. Traverse Bottom → Top along the left column
            if (left <= right)
            { // check validity
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++; // move left boundary right
            }
        }

        return ans;
    }
};

// ==================== MAIN FUNCTION ====================
int main()
{
    Solution sol;

    // Example input matrix
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    // Call the function
    vector<int> ans = sol.spiralOrder(matrix);

    // Print result
    cout << "Spiral Order: ";
    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
