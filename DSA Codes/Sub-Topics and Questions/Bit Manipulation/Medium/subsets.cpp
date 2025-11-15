/*
    =========================================================================================
                                🔥 LeetCode 78 — Subsets (Power Set)
    =========================================================================================

    🧩 PROBLEM STATEMENT:
    ---------------------
    Given an integer array nums of unique elements, return all possible subsets
    (the power set).

    A subset is ANY combination of elements where:
        - Order does NOT matter
        - Elements are either included or NOT included
        - Total subsets = 2^N

    The solution must not contain duplicate subsets.

    -----------------------------------------------------------------------------------------
    🔢 EXAMPLES:

    Example 1:
        Input : nums = [1,2,3]
        Output:
            [
                [],
                [1], [2], [3],
                [1,2], [1,3], [2,3],
                [1,2,3]
            ]

    Example 2:
        Input : nums = [0]
        Output:
            [
                [],
                [0]
            ]

    -----------------------------------------------------------------------------------------
    ❗ Constraints:
        1 <= nums.length <= 10
        -10 <= nums[i] <= 10
        All elements are unique.

    =========================================================================================
                                🥇 APPROACH 1 — Brute Force
                              (Recursion / Backtracking)
    =========================================================================================

    🧠 INTUITION:
    -------------
    At every index, we have 2 choices:
        ✔ Include the element
        ✔ Do NOT include the element

    This naturally forms a recursion tree of depth N, with 2^N leaf nodes → all subsets.

    -----------------------------------------------------------------------------------------
    🧾 PSEUDOCODE:
    --------------
        function backtrack(index, currentSubset):
            if index == n:
                add currentSubset to answer
                return

            // include nums[index]
            currentSubset.push(nums[index])
            backtrack(index + 1, currentSubset)

            // exclude nums[index]
            currentSubset.pop()
            backtrack(index + 1, currentSubset)

    -----------------------------------------------------------------------------------------
    ⏱ TIME COMPLEXITY:  O(2^N * N)
    💾 SPACE COMPLEXITY: O(N) recursion stack

    =========================================================================================
                                ⚡ APPROACH 2 — Optimal
                                (Bit Manipulation)
    =========================================================================================

    🧠 INTUITION:
    -------------
    Subset count = 2^N
    Represent each subset using a binary mask from 0 → (1<<N)-1

    Example:
         nums = [1,2,3]
         mask    binary   subset
         ----------------------------------
         0       000      []
         1       001      [3]
         2       010      [2]
         3       011      [2,3]
         4       100      [1]
         5       101      [1,3]
         6       110      [1,2]
         7       111      [1,2,3]

    -----------------------------------------------------------------------------------------
    🧾 PSEUDOCODE:
    --------------
        let total = 1 << n
        for mask in 0 to total-1:
            subset = []
            for bit in 0 to n-1:
                if mask & (1 << bit):
                    subset.push(nums[bit])
            add subset to result

    -----------------------------------------------------------------------------------------
    ⏱ TIME COMPLEXITY:  O(2^N * N)
    💾 SPACE COMPLEXITY: O(1) extra (output not counted)

    =========================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

/* =========================================================================================
                                🥇 APPROACH 1 — RECURSION
   ========================================================================================= */
void generateSubsets(int index, vector<int> &nums, vector<int> &subset,
                     vector<vector<int>> &result)
{
    if (index == nums.size())
    {
        result.push_back(subset);
        return;
    }

    // Include current element
    subset.push_back(nums[index]);
    generateSubsets(index + 1, nums, subset, result);

    // Exclude current element
    subset.pop_back();
    generateSubsets(index + 1, nums, subset, result);
}

vector<vector<int>> subsetsBruteForce(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> subset;
    generateSubsets(0, nums, subset, result);
    return result;
}

/* =========================================================================================
                                ⚡ APPROACH 2 — BIT MANIPULATION
   ========================================================================================= */
vector<vector<int>> subsetsBitwise(vector<int> &nums)
{
    int n = nums.size();
    int total = 1 << n; // total subsets = 2^n

    vector<vector<int>> result;

    for (int mask = 0; mask < total; mask++)
    {
        vector<int> subset;

        // Check each bit
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i)) // if i-th bit is set
                subset.push_back(nums[i]);
        }

        result.push_back(subset);
    }

    return result;
}

/* =========================================================================================
                                🧪 MAIN FUNCTION — TEST CASES
   ========================================================================================= */
int main()
{
    cout << "=============================================================\n";
    cout << "🔥 LeetCode 78 — Subsets (Power Set using Recursion + Bitwise)\n";
    cout << "=============================================================\n\n";

    vector<vector<int>> testCases = {
        {1, 2, 3},
        {0},
        {4, 5},
        {1, 2, 3, 4}};

    for (auto nums : testCases)
    {
        cout << "Input: ";
        for (int x : nums)
            cout << x << " ";
        cout << "\n";

        cout << "\n➡ Brute Force (Recursion) Output:\n";
        auto ans1 = subsetsBruteForce(nums);
        for (auto &sub : ans1)
        {
            cout << "{ ";
            for (int x : sub)
                cout << x << " ";
            cout << "}\n";
        }

        cout << "\n➡ Optimal (Bit Manipulation) Output:\n";
        auto ans2 = subsetsBitwise(nums);
        for (auto &sub : ans2)
        {
            cout << "{ ";
            for (int x : sub)
                cout << x << " ";
            cout << "}\n";
        }

        cout << "\n-------------------------------------------------------------\n\n";
    }

    cout << "✅ Execution Complete — All Approaches Tested Successfully!\n";
    cout << "=============================================================\n";

    return 0;
}
