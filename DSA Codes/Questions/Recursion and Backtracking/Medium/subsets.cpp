/*
LeetCode 78. Subsets
Asked in: Amazon, Google, Microsoft, Meta, Adobe, Apple, etc.

Problem:
Given an integer array nums of unique elements, return all possible subsets (the power set).
*/
#include <bits/stdc++.h> // includes vector, iostream, etc.
using namespace std;

class Solution
{
public:
    // Recursive helper function to generate subsets
    // i       : current index in nums
    // nums    : input array
    // current : temporary vector storing current subset
    // ans     : stores all subsets
    void solve(int i, vector<int> &nums, vector<int> &current, vector<vector<int>> &ans)
    {
        // -------------------------
        // Base Case:
        // If index reaches the end of nums, we have formed one subset.
        // Add it to ans and return.
        // -------------------------
        if (i == nums.size())
        {
            ans.push_back(current); // store the current subset
            return;
        }

        // -------------------------
        // Choice 1: Pick nums[i]
        // -------------------------
        current.push_back(nums[i]);       // include nums[i] in the current subset
        solve(i + 1, nums, current, ans); // recurse for the next index
        current.pop_back();               // backtrack: remove nums[i] to explore other options

        // -------------------------
        // Choice 2: Not pick nums[i]
        // -------------------------
        solve(i + 1, nums, current, ans); // recurse for the next index without including nums[i]
    }

    /*
    Main function called by LeetCode.
    Initializes helper variables and starts recursion.
    */
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;      // stores all subsets
        vector<int> current;          // temporary vector to build subsets
        solve(0, nums, current, ans); // start recursion from index 0
        return ans;                   // return all subsets
    }
};

// -------------------------
// Example usage with main()
// -------------------------
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};                   // input array
    vector<vector<int>> result = sol.subsets(nums); // generate all subsets

    // Print all subsets
    for (auto &subset : result)
    {
        cout << "[ ";
        for (int x : subset)
            cout << x << " "; // print elements of subset
        cout << "]\n";
    }
    return 0;
}

/*
Dry Run Example: nums = [1,2,3]

Recursion Tree:

f(0, [])
├─ pick 1 → f(1,[1])
│   ├─ pick 2 → f(2,[1,2])
│   │   ├─ pick 3 → f(3,[1,2,3]) → store [1,2,3]
│   │   └─ not pick 3 → f(3,[1,2]) → store [1,2]
│   └─ not pick 2 → f(2,[1])
│       ├─ pick 3 → f(3,[1,3]) → store [1,3]
│       └─ not pick 3 → f(3,[1]) → store [1]
└─ not pick 1 → f(1,[])
    ├─ pick 2 → f(2,[2])
    │   ├─ pick 3 → f(3,[2,3]) → store [2,3]
    │   └─ not pick 3 → f(3,[2]) → store [2]
    └─ not pick 2 → f(2,[])
        ├─ pick 3 → f(3,[3]) → store [3]
        └─ not pick 3 → f(3,[]) → store []

Output Order:
[1,2,3], [1,2], [1,3], [1], [2,3], [2], [3], []

Time Complexity:
- Each element has 2 choices → O(2^n)
- Copying subsets to answer → O(n * 2^n)
- Overall: O(n * 2^n)

Space Complexity:
- Recursion stack: O(n)
- Current subset + answer storage: O(n * 2^n)
- Overall: O(n * 2^n)

Summary:
- Classic recursion with backtracking.
- Pick/not-pick choice at each index generates all subsets.
- Backtracking ensures we undo choices for the next branch.
- Professional, clean code style suitable for interviews.
*/
