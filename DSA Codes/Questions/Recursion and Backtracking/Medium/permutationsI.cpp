/*
================================================================================
🧮 Problem: LeetCode 46. Permutations
📘 Difficulty: Medium
📚 Topic: Backtracking
🏷️ Tags: Recursion, Array, Backtracking

--------------------------------------------------------------------------------
🧠 Problem Statement:
Given an array nums of distinct integers, return all the possible permutations.
You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]

--------------------------------------------------------------------------------
🧩 What is a Permutation?
A permutation is a rearrangement of all elements of an array.
For an array of size N, there are N! (factorial) total permutations.

For example:
nums = [1, 2, 3]
Permutations = 3! = 6
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]
================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

/* =============================================================================
    🧠 APPROACH 1: Using Frequency Array (Extra Space)
    -------------------------------------------------
    ✅ Algorithm / Intuition:
       - We maintain a temporary array (ds) to store the current permutation.
       - We use a `freq[]` array (or unordered_map) to mark which elements
         are already used in the current permutation.
       - Recursively pick each unused element, mark it as used,
         add to ds, and continue.
       - When ds.size() == nums.size(), we’ve formed a full permutation.

    ✅ Steps:
       1️⃣ Initialize freq[] = {0, 0, 0, ...} (all unused)
       2️⃣ Start recursion:
             - If an element is unused, pick it.
             - Mark as used.
             - Add to current permutation.
             - Recurse.
             - Backtrack → remove element + unmark freq.
       3️⃣ Store all permutations in ans[][].

    ✅ Time Complexity:  O(N! × N)
       - There are N! permutations and copying each permutation costs O(N)
    ✅ Space Complexity: O(N)
       - freq[] + ds + recursion stack
============================================================================= */

class Solution_UsingFreq
{
public:
    // Helper function for recursive backtracking
    void helper(vector<int> &nums, vector<vector<int>> &ans,
                vector<int> &ds, vector<int> &freq)
    {

        // Base Case: when current permutation is complete
        if (ds.size() == nums.size())
        {
            ans.push_back(ds); // Store a copy of current permutation
            return;
        }

        // Try including each unused element
        for (int i = 0; i < nums.size(); i++)
        {
            if (!freq[i])
            {                          // If nums[i] not yet used
                freq[i] = 1;           // Mark as used
                ds.push_back(nums[i]); // Add to current permutation

                helper(nums, ans, ds, freq); // Recurse

                // Backtrack: remove last added element and unmark freq
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }

    // Main function
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;          // To store all permutations
        vector<int> ds;                   // Current permutation being built
        vector<int> freq(nums.size(), 0); // Frequency array (0 = unused)
        helper(nums, ans, ds, freq);
        return ans;
    }
};

/* =============================================================================
    🧠 APPROACH 2: In-place Swapping (No Extra Space)
    -------------------------------------------------
    ✅ Algorithm / Intuition:
       - Instead of using extra space, we fix elements in-place.
       - For index `idx`, we swap each element from `idx` to `n-1` with `idx`.
       - Recurse for `idx + 1` (next index).
       - Backtrack by swapping again to restore the array.

    ✅ Steps:
       1️⃣ Start recursion with idx = 0
       2️⃣ For each i from idx to n-1:
              - Swap(nums[idx], nums[i])
              - Recurse with idx + 1
              - Backtrack (undo the swap)
       3️⃣ Base Case: when idx == nums.size() → push current nums to ans

    ✅ Time Complexity:  O(N! × N)
    ✅ Space Complexity: O(N) (recursion stack only)
============================================================================= */

class Solution_Swap
{
public:
    void helper(int idx, vector<int> &nums, vector<vector<int>> &ans)
    {
        // Base case: all positions fixed
        if (idx == nums.size())
        {
            ans.push_back(nums); // Store current permutation
            return;
        }

        // Try each number for the current index
        for (int i = idx; i < nums.size(); i++)
        {
            swap(nums[idx], nums[i]);   // Place nums[i] at position idx
            helper(idx + 1, nums, ans); // Recurse for next index
            swap(nums[idx], nums[i]);   // Backtrack: undo the swap
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        helper(0, nums, ans);
        return ans;
    }
};

/* =============================================================================
   🧾 MAIN FUNCTION (For Local Testing in VS Code)
   ----------------------------------------------
   Note: LeetCode doesn’t require a main() function,
         but you can use this in VS Code to test both solutions.
============================================================================= */

int main()
{
    vector<int> nums = {1, 2, 3};

    cout << "===============================" << endl;
    cout << "LeetCode 46: Permutations" << endl;
    cout << "===============================" << endl;

    // ---------- Using Frequency Array ----------
    cout << "\n🔹 Approach 1: Using freq[] array" << endl;
    Solution_UsingFreq obj1;
    vector<vector<int>> ans1 = obj1.permute(nums);

    for (auto &vec : ans1)
    {
        cout << "[ ";
        for (auto x : vec)
            cout << x << " ";
        cout << "]" << endl;
    }

    // ---------- Using In-place Swapping ----------
    cout << "\n🔹 Approach 2: Using In-place Swapping" << endl;
    Solution_Swap obj2;
    vector<vector<int>> ans2 = obj2.permute(nums);

    for (auto &vec : ans2)
    {
        cout << "[ ";
        for (auto x : vec)
            cout << x << " ";
        cout << "]" << endl;
    }

    return 0;
}

/*
================================================================================
🧾 Summary Comparison
--------------------------------------------------------------------------------
| Feature              | Approach 1 (freq[]) | Approach 2 (Swapping) |
|-----------------------|--------------------|------------------------|
| Extra Space           | O(N)               | O(1)                   |
| Implementation        | Easier for beginners | Slightly advanced     |
| Efficiency            | Slightly slower (freq array) | Faster in practice |
| Handles Duplicates?   | Easy to modify      | Needs extra check      |
| Use Case              | Simpler logic, educational | Production efficient |

================================================================================
*/
