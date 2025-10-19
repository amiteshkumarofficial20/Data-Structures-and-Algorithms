/*
    🧩 Problem Name: Combination Sum III
    📘 LeetCode Problem Number: 216
    💡 Difficulty: Medium
    🏢 Asked In: Google, Amazon, Microsoft, Adobe, Facebook

    ----------------------------------------------------------
    🧠 Problem Statement:
    Find all valid combinations of k numbers that sum up to n,
    such that only numbers from 1 to 9 are used, and each number
    is used at most once.

    ----------------------------------------------------------
    🔹 Example 1:
        Input: k = 3, n = 7
        Output: [[1,2,4]]
        Explanation: 1 + 2 + 4 = 7 and uses 3 numbers.

    🔹 Example 2:
        Input: k = 3, n = 9
        Output: [[1,2,6], [1,3,5], [2,3,4]]
        Explanation: All valid combinations of 3 distinct numbers that sum to 9.

    🔹 Example 3:
        Input: k = 4, n = 1
        Output: []
        Explanation: Minimum sum using 4 distinct numbers = 10 → No valid combo.

    ----------------------------------------------------------
    🎯 Intuition:
    We need to pick exactly k distinct numbers between 1–9
    that add up to n. This can be thought of as exploring all
    possible combinations (subset generation).

    Since order doesn’t matter and each number can be used once,
    we can use a backtracking approach to:
    - Pick a number
    - Explore further with reduced target sum
    - Backtrack (undo the choice) to try other possibilities

    ----------------------------------------------------------
    🧩 Approach (Backtracking):
    1️⃣ Start from number 1 and go up to 9.
    2️⃣ Maintain:
        - current sum (n)
        - count of numbers left to pick (k)
        - current combination (path)
    3️⃣ If both k == 0 and n == 0 → valid combination found.
    4️⃣ If either k < 0 or n < 0 → invalid branch (backtrack).
    5️⃣ Otherwise, try each number i (from start to 9):
        - Choose i, explore with remaining (k-1, n-i)
        - Then backtrack (remove i from current combination)
    6️⃣ Continue until all combinations are explored.

    ----------------------------------------------------------
    ⏱ Time Complexity:
        - O(2^9) ≈ O(512)
        - Because each number (1–9) can be either chosen or skipped.
        - Since range is fixed (1–9), this is efficient.

    💾 Space Complexity:
        - O(k) for recursion depth + O(k) for temporary combination storage.
        - Result list takes space for valid answers.

    ----------------------------------------------------------
    ✅ Output for Example (k=3, n=9):
        [ [1,2,6], [1,3,5], [2,3,4] ]
*/

#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------------------
// 🔧 Solution Class
// --------------------------------------------------------------
class Solution
{
public:
    // 🔁 Helper function for backtracking
    void backtrack(int start, int k, int n, vector<int> &path, vector<vector<int>> &res)
    {

        // 🎯 Base Case 1: Valid combination found
        if (k == 0 && n == 0)
        {
            res.push_back(path); // Store the current valid combination
            return;
        }

        // 🚫 Base Case 2: Invalid branch (either too many numbers or sum exceeded)
        if (k < 0 || n < 0)
            return;

        // 🔍 Explore all possible numbers from 'start' to 9
        for (int i = start; i <= 9; i++)
        {

            // 🔸 Choose the current number 'i'
            path.push_back(i);

            // 🔁 Recursively explore further with:
            //    - next start = i + 1 (since each number can be used once)
            //    - one less number to pick (k - 1)
            //    - reduced target sum (n - i)
            backtrack(i + 1, k - 1, n - i, path, res);

            // 🔙 Backtrack (undo the last choice)
            path.pop_back();
        }
    }

    // 🧮 Main function to find all combinations
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;       // To store all valid combinations
        vector<int> path;              // Temporary list to hold current combination
        backtrack(1, k, n, path, res); // Start from 1
        return res;
    }
};

// --------------------------------------------------------------
// 🧾 Example Usage in VS Code (Driver Code)
// --------------------------------------------------------------
int main()
{
    Solution sol;

    // Example: Find all combinations of 3 numbers summing to 9
    int k = 3;
    int n = 9;

    vector<vector<int>> ans = sol.combinationSum3(k, n);

    cout << "🔹 All Combinations of " << k << " numbers summing to " << n << ":\n";
    for (auto &v : ans)
    {
        cout << "[ ";
        for (int num : v)
            cout << num << " ";
        cout << "]\n";
    }

    /*
        ✅ Expected Output:
        [ 1 2 6 ]
        [ 1 3 5 ]
        [ 2 3 4 ]
    */

    return 0;
}
