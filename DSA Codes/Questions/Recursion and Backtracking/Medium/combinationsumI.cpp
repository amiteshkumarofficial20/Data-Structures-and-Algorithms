/************************************************************
 *  Problem: Combination Sum
 *  LeetCode: #39
 *  Difficulty: Medium
 *
 *  Description:
 *  ------------
 *  Given an array of distinct integers (candidates) and
 *  a target integer (target), return all unique combinations
 *  of candidates where the chosen numbers sum to target.
 *  The same number may be chosen from candidates an unlimited
 *  number of times. Two combinations are unique if the
 *  frequency of at least one of the chosen numbers is different.
 *
 *  Example:
 *  --------
 *  Input: candidates = [2,3,6,7], target = 7
 *  Output: [[2,2,3],[7]]
 *
 *  Constraints:
 *  ------------
 *  • 1 <= candidates.length <= 30
 *  • 2 <= candidates[i] <= 40 (all distinct)
 *  • 1 <= target <= 40
 *
 *  Companies:
 *  ----------
 *  Asked by: Amazon, Google, Microsoft, Facebook, Adobe
 *
 *  Approach:
 *  ---------
 *  • Use Backtracking (DFS recursion).
 *  • At each index, we have 2 choices:
 *      1. Pick the current element (if <= target).
 *         -> Stay at the same index since elements
 *            can be reused unlimited times.
 *      2. Skip the current element and move to next index.
 *  • When we reach end of array:
 *      -> If target == 0, we found a valid combination.
 *
 *  Time Complexity:
 *  ----------------
 *  • In the worst case, each element can be picked multiple times.
 *  • Exponential in nature: O(2^t * k), where
 *      - t = target value
 *      - k = average length of a combination
 *  • Since target <= 40, the recursion depth is manageable.
 *
 *  Space Complexity:
 *  -----------------
 *  • O(k) for recursion stack (where k = target / min(candidates[i])).
 *  • O(ans.size() * k) for storing all valid combinations.
 ************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * Helper function to recursively build combinations.
     *
     * @param ind   Current index in candidates array
     * @param target Remaining sum needed
     * @param arr   Reference to candidates array
     * @param ans   Reference to final answer (list of combinations)
     * @param ds    Current combination being built
     */
    void findCombination(int ind, int target, vector<int> &arr,
                         vector<vector<int>> &ans, vector<int> &ds)
    {

        // Base case: if we have considered all elements
        if (ind == arr.size())
        {
            if (target == 0)
            {
                ans.push_back(ds); // Found a valid combination
            }
            return;
        }

        // Choice 1: Pick the element (if it does not exceed target)
        if (arr[ind] <= target)
        {
            ds.push_back(arr[ind]); // include arr[ind]

            // Since we can use the same element unlimited times,
            // we do NOT move to next index
            findCombination(ind, target - arr[ind], arr, ans, ds);

            ds.pop_back(); // backtrack (undo choice)
        }

        // Choice 2: Skip the element and move to next index
        findCombination(ind + 1, target, arr, ans, ds);
    }

    /**
     * Main function to find all combinations.
     *
     * @param candidates List of distinct integers
     * @param target     Target sum
     * @return           List of all unique combinations
     */
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans; // Stores all valid combinations
        vector<int> ds;          // Temporary list for current combination
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};

// ---------------- Driver Code ----------------
int main()
{
    Solution obj;

    // Example input
    vector<int> v{2, 3, 6, 7};
    int target = 7;

    // Function call
    vector<vector<int>> ans = obj.combinationSum(v, target);

    // Print output
    cout << "Combinations that sum to " << target << " are:\n";
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
