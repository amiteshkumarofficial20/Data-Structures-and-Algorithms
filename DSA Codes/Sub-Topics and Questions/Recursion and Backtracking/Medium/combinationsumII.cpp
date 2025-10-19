/*
====================================================================================
|                                   LEETCODE 40                                     |
|                             🔹 Combination Sum II 🔹                              |
====================================================================================

🧩 Problem Statement:
---------------------
Given a collection of candidate numbers (candidates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sum to target.

⚙️ Conditions:
-------------
1. Each number in candidates may only be used once in the combination.
2. The solution set must not contain duplicate combinations.
3. The order of elements inside a combination doesn’t matter (i.e., [1,2,5] == [2,1,5]).
4. Combinations themselves should appear in non-decreasing order.

🔒 Constraints:
--------------
1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

💡 Examples:
------------
Input:  candidates = [10,1,2,7,6,1,5], target = 8
Output: [ [1,1,6], [1,2,5], [1,7], [2,6] ]

Input:  candidates = [2,5,2,1,2], target = 5
Output: [ [1,2,2], [5] ]

------------------------------------------------------------------------------------
🎯 Goal:
Find all **unique** combinations where the sum equals the target.
Each number can be used at most once.
------------------------------------------------------------------------------------

🔍 Intuition & Approach:
========================
This is a **Backtracking problem** (similar to Combination Sum I) but with two key differences:
1️⃣ Each number can be used **only once** → recursive call with index `i + 1`
2️⃣ We must **avoid duplicate combinations** → handled by sorting + skipping equal elements.

Steps:

1️⃣ **Sort the input array**
   - Helps generate combinations in non-decreasing order.
   - Makes duplicate detection easy.
   - Enables pruning (if current number > target, break early).

2️⃣ **Use Recursion + Backtracking**
   - Define a recursive function `findCombination(ind, target, arr, ans, ds)`.
   - `ind` → starting index in array.
   - `target` → remaining target sum.
   - `ds` → current combination.
   - `ans` → list of all valid combinations.

3️⃣ **At each recursive call**:
   - If `target == 0` → valid combination found → add `ds` to `ans`.
   - Else, iterate through elements starting at `ind`.

4️⃣ **Duplicate Skipping**:
   - If `i > ind && arr[i] == arr[i-1]` → skip this element.
   - Why? Because picking the same number again at the same recursion level
     creates duplicate combinations.
   - But we allow the *first* occurrence (i == ind) to start a new unique path.

5️⃣ **Pruning / Early Stop**:
   - If `arr[i] > target`, break the loop.
   - Since the array is sorted, no further elements can fit into the combination.

6️⃣ **Backtracking Pattern**:
   - Choose → Recurse → Unchoose
   - Push `arr[i]` into `ds`, recurse with `i+1` and `target - arr[i]`,
     then pop back after recursion to restore the state.

------------------------------------------------------------------------------------
⏱️ Time Complexity:
-------------------
⚡ Worst Case: O(2^n * k)
   - n = number of candidates
   - k = average length of a combination (copy cost)
   Because we explore subsets of n elements.
   Pruning + duplicate skipping make it much faster in practice.

💾 Space Complexity:
--------------------
⚡ O(k) recursion stack depth + O(k) for temporary `ds`
⚡ Output storage = O(number_of_combinations * average_length)

------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------------------------------------------
🔹 Helper Function: findCombination
------------------------------------------------------------------------------------
Parameters:
-----------
- int ind: Current starting index in array
- int target: Remaining target sum we need to reach
- vector<int>& arr: Sorted array of candidate numbers
- vector<vector<int>>& ans: Stores all valid combinations (final result)
- vector<int>& ds: Stores current combination being built (temporary)

Base Case:
----------
If target == 0 → valid combination found → push `ds` into `ans`.

Recursive Logic:
----------------
For each index i from ind to arr.size() - 1:
  - Skip duplicates (if i > ind && arr[i] == arr[i-1])
  - Stop (prune) if arr[i] > target
  - Include arr[i] and recurse with:
        i + 1 → move to next index (since each number is used once)
        target - arr[i] → updated remaining sum
  - Backtrack → remove arr[i] after recursion (restore previous state)
------------------------------------------------------------------------------------
*/
void findCombination(int ind, int target,
                     vector<int> &arr,
                     vector<vector<int>> &ans,
                     vector<int> &ds)
{
    // ✅ Base condition: if remaining target is zero,
    // it means current combination `ds` is valid
    if (target == 0)
    {
        ans.push_back(ds); // add current combination to result
        return;
    }

    // Iterate from the current index to the end of array
    for (int i = ind; i < arr.size(); i++)
    {

        // ⚠️ Duplicate Skipping Condition:
        // If current element is same as previous (and not the first at this level)
        // → skip to avoid duplicate combinations.
        if (i > ind && arr[i] == arr[i - 1])
            continue; // skip same element at same recursion level

        // ⚡ Pruning Condition:
        // Since array is sorted, if current number > target,
        // no point in exploring further (later numbers will be even bigger)
        if (arr[i] > target)
            break; // stop exploring further numbers

        // 🧩 Choose current element (include it in current combination)
        ds.push_back(arr[i]);

        // 🔁 Recursive call:
        // i + 1 → move to next index (can't reuse same element)
        // target - arr[i] → remaining sum after including arr[i]
        findCombination(i + 1, target - arr[i], arr, ans, ds);

        // 🧹 Backtrack:
        // Remove last element before moving to next candidate
        // to restore state for other recursive branches
        ds.pop_back();
    }
}

/*
------------------------------------------------------------------------------------
🔹 Main Function: combinationSum2
------------------------------------------------------------------------------------
Purpose:
--------
- Sorts candidates
- Initializes result and temporary arrays
- Calls recursive backtracking function
- Returns all valid combinations
------------------------------------------------------------------------------------
*/
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    // Step 1: Sort to simplify duplicate handling and enable pruning
    sort(candidates.begin(), candidates.end());

    // Step 2: Define result container and temporary combination holder
    vector<vector<int>> ans;
    vector<int> ds;

    // Step 3: Start backtracking from index 0
    findCombination(0, target, candidates, ans, ds);

    // Step 4: Return final result
    return ans;
}

/*
------------------------------------------------------------------------------------
🔹 Driver Code (main function)
------------------------------------------------------------------------------------
- Creates test input
- Calls combinationSum2
- Prints all valid unique combinations
------------------------------------------------------------------------------------
*/
int main()
{
    // Example Input
    vector<int> v{10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    // Call our function
    vector<vector<int>> comb = combinationSum2(v, target);

    // Output printing in formatted way
    cout << "All unique combinations that sum to target = " << target << ":\n";
    cout << "[\n";
    for (auto &combination : comb)
    {
        cout << "  [ ";
        for (int num : combination)
            cout << num << " ";
        cout << "]\n";
    }
    cout << "]\n";

    return 0;
}

/*
====================================================================================
📘 Quick Summary of Key Concepts
====================================================================================

🧠 Why SORT?
-------------
- To ensure combinations are in ascending order.
- To skip consecutive duplicates easily.
- To apply pruning (break when arr[i] > target).

🔁 Why (i > ind && arr[i] == arr[i-1]) ?
----------------------------------------
- Because if we’ve already used arr[i-1] at this recursion level,
  using arr[i] (which is same value) would create duplicate combinations.
- But if i == ind (first element at this level), we explore it once.

🔢 Why move to (i + 1) ?
------------------------
- Each number can be used only once → must move forward.
- Prevents reusing same index in deeper recursion.

🚫 Why Pruning (arr[i] > target) break ?
----------------------------------------
- Sorted array means next elements will be ≥ arr[i].
- So once arr[i] > target, all further numbers are useless → stop loop early.

🎯 Base Case (target == 0)
--------------------------
- When target becomes 0, current combination `ds` forms a valid sum → store it.

↩️ Backtracking Pattern
------------------------
- Choose → Recurse → Un-choose
- Ensures we explore all possibilities without corrupting `ds`.

====================================================================================
🕒 Time Complexity:  O(2^n * k)
💾 Space Complexity: O(k) (recursion + temporary storage)
====================================================================================
*/
