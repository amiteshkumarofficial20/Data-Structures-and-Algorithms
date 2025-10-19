/*
LeetCode Problem 90: Subsets II
Problem Name: Subsets II
Difficulty: Medium

Problem Statement:
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
Each subset must be unique and can be returned in any order.

Example:
Input: nums = [1,2,2]
Output: [[],[1],[2],[1,2],[2,2],[1,2,2]]
Explanation:
- All possible subsets of [1,2,2] are generated.
- Duplicates subsets are removed.
*/

#include <bits/stdc++.h>
using namespace std;

// -------------------- HELPER FUNCTION --------------------
/*
Function: printAns
Purpose: Prints all subsets in a readable format.
Parameters:
- ans : vector of subsets (each subset is a vector of integers)
*/
void printAns(vector<vector<int>> &ans)
{
    cout << "The unique subsets are:\n[ ";
    for (auto &subset : ans)
    {
        cout << "[ ";
        for (int num : subset)
            cout << num << " "; // Print each element of the subset
        cout << "] ";
    }
    cout << "]" << endl;
}

// -------------------- SOLUTION CLASS --------------------
class Solution
{
public:
    // ==================== BRUTE FORCE APPROACH ====================
    /*
    Function: bruteForceHelper
    Purpose: Generates all possible subsets including duplicates, then uses a set to remove duplicate subsets.
    Parameters:
    - nums  : Input array of integers
    - index : Current index in the array
    - ds    : Current subset being constructed
    - res   : Set to store unique subsets
    Logic:
    1. At each index, we have two choices:
       a) Include nums[index] in subset
       b) Exclude nums[index] from subset
    2. Recursively explore both choices.
    3. Base case: When index reaches the end of array, sort ds and insert into set.
    */
    void bruteForceHelper(vector<int> &nums, int index, vector<int> ds, set<vector<int>> &res)
    {
        if (index == nums.size())
        {                               // Base case: all elements considered
            sort(ds.begin(), ds.end()); // Sort to handle duplicates (e.g., [2,1] and [1,2] are same)
            res.insert(ds);             // Insert into set (automatically removes duplicates)
            return;
        }

        // 1. Include current element
        ds.push_back(nums[index]);                  // Pick nums[index]
        bruteForceHelper(nums, index + 1, ds, res); // Recurse to next index

        // Backtrack step
        ds.pop_back(); // Remove last element to explore path without it

        // 2. Exclude current element
        bruteForceHelper(nums, index + 1, ds, res); // Recurse to next index without current element
    }

    /*
    Function: subsetsWithDupBrute
    Purpose: Initializes helper structures and returns all unique subsets using brute-force.
    */
    vector<vector<int>> subsetsWithDupBrute(vector<int> &nums)
    {
        set<vector<int>> res;               // Set to store unique subsets
        vector<int> ds;                     // Temporary subset
        bruteForceHelper(nums, 0, ds, res); // Start recursion from index 0

        // Convert set to vector to match return type
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }

    // ==================== OPTIMAL APPROACH ====================
    /*
    Function: optimalHelper
    Purpose: Efficiently generates all unique subsets using backtracking without using a set.
    Parameters:
    - ind   : Current index in nums
    - nums  : Input array
    - ds    : Current subset
    - ans   : Stores all unique subsets
    Logic:
    1. Always add current subset ds to ans.
    2. Loop from current index to end of nums.
    3. Skip elements that are duplicates of previous (i != ind && nums[i] == nums[i-1])
    4. Pick current element, recurse, then backtrack.
    */
    void optimalHelper(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
    {
        ans.push_back(ds); // Add current subset to answer

        for (int i = ind; i < nums.size(); i++)
        {
            // Skip duplicates at the same recursion level
            if (i != ind && nums[i] == nums[i - 1])
                continue;

            ds.push_back(nums[i]);               // Include nums[i]
            optimalHelper(i + 1, nums, ds, ans); // Recurse for next index
            ds.pop_back();                       // Backtrack to explore path without nums[i]
        }
    }

    /*
    Function: subsetsWithDupOptimal
    Purpose: Initializes structures and returns all unique subsets using optimal approach.
    */
    vector<vector<int>> subsetsWithDupOptimal(vector<int> &nums)
    {
        vector<vector<int>> ans;         // Final answer
        vector<int> ds;                  // Temporary subset
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        optimalHelper(0, nums, ds, ans); // Start recursion from index 0
        return ans;
    }
};

// -------------------- MAIN FUNCTION --------------------
int main()
{
    Solution obj;
    vector<int> nums = {1, 2, 2}; // Example input

    // -------------------- BRUTE FORCE OUTPUT --------------------
    cout << "---- BRUTE FORCE APPROACH ----" << endl;
    vector<vector<int>> ansBrute = obj.subsetsWithDupBrute(nums);
    printAns(ansBrute);

    // -------------------- OPTIMAL OUTPUT --------------------
    cout << "\n---- OPTIMAL APPROACH ----" << endl;
    vector<vector<int>> ansOptimal = obj.subsetsWithDupOptimal(nums);
    printAns(ansOptimal);

    return 0;
}

/*
==================== TIME AND SPACE COMPLEXITY ====================

Brute Force:
- Time Complexity:
    1. Generating all subsets: O(2^n)
    2. Sorting each subset before insertion: O(k log k), where k = size of subset
    3. Insertion into set: O(log x), x = number of subsets in set
    Overall: O(2^n * (k log k + log x))

- Space Complexity:
    1. Recursive stack: O(n)
    2. Set storage: O(2^n * k)
    3. Final answer vector: O(2^n * k)

Optimal:
- Time Complexity:
    1. Generating all subsets: O(2^n)
    2. Copying each subset into answer: O(k)
    Overall: O(k * 2^n)

- Space Complexity:
    1. Recursive stack: O(n)
    2. Answer storage: O(2^n * k)
*/
