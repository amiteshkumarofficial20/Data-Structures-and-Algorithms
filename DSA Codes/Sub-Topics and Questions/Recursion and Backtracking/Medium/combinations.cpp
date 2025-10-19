/*
    Problem: 77. Combinations
    Difficulty: Medium
    Topics: Backtracking, Recursion
    Companies: Amazon, Microsoft, Google, Facebook, Adobe, LinkedIn
    LeetCode: https://leetcode.com/problems/combinations/

    Problem Statement:
    ------------------
    Given two integers n and k, return all possible combinations of k numbers
    chosen from the range [1, n]. You may return the answer in any order.

    Example:
    --------
    Input: n = 4, k = 2
    Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
    Explanation: There are 4 choose 2 = 6 total combinations.

    Constraints:
    ------------
    1 <= n <= 20
    1 <= k <= n

    Intuition:
    ----------
    - For each number from start to n, we have 2 choices:
        1. Include the number in current combination
        2. Exclude the number and move to next
    - When we have chosen k numbers, we store the combination.
    - This is a classic backtracking / recursion problem.

    Algorithm:
    ----------
    1. Start recursion from 1 to n.
    2. For each number, choose to include it or skip it.
    3. Reduce k by 1 when including a number.
    4. When k == 0, push the current combination to result.
    5. Return the result after the recursion ends.

    Time Complexity:
    ----------------
    - Total combinations = C(n, k)
    - Each combination takes O(k) time to copy into result
    - Total: O(k * C(n, k))

    Space Complexity:
    -----------------
    - Recursion stack: O(k)
    - Temp vector storing combination: O(k)
    - Result vector storing all combinations: O(k * C(n, k))
*/

#include <bits/stdc++.h>
using namespace std;

// ---------------------- Approach 1: Include/Exclude ----------------------
class SolutionIncludeExclude
{
public:
    vector<vector<int>> result;

    void solve(int start, int k, int n, vector<int> &temp)
    {
        if (k == 0)
        {
            result.push_back(temp);
            return;
        }
        if (start > n)
            return;

        // Include current number
        temp.push_back(start);
        solve(start + 1, k - 1, n, temp);
        temp.pop_back();

        // Exclude current number
        solve(start + 1, k, n, temp);
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> temp;
        solve(1, k, n, temp);
        return result;
    }
};

// ---------------------- Approach 2: For-loop Backtracking ----------------------

// Intuition:
//     ----------
//     - This is a classic backtracking problem.
//     - Idea: For each number from 'start' to 'n', try including it in the combination.
//     - After choosing a number, recursively choose remaining numbers (k-1) from next numbers.
//     - Use backtracking to remove the number after recursion to explore other possibilities.

//     Algorithm:
//     ----------
//     1. Start recursion from number 1.
//     2. Loop from 'start' to 'n':
//         a. Include current number i in temp combination.
//         b. Recursively call solve(i+1, k-1, n, temp) to choose remaining numbers.
//         c. Backtrack by removing last element from temp.
//     3. Base case: if k == 0, push temp into result.
//     4. Return the result after recursion ends.

//     Time Complexity:
//     ----------------
//     - Total combinations = C(n, k)
//     - Copying each combination to result takes O(k)
//     - Total: O(k * C(n, k))

//     Space Complexity:
//     -----------------
//     - Recursion stack: O(k)
//     - Temp vector storing current combination: O(k)
//     - Result vector storing all combinations: O(k * C(n, k))
class SolutionForLoop
{
public:
    vector<vector<int>> result;

    void solve(int start, int k, int n, vector<int> &temp)
    {
        if (k == 0)
        {
            result.push_back(temp);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            temp.push_back(i);
            solve(i + 1, k - 1, n, temp);
            temp.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> temp;
        solve(1, k, n, temp);
        return result;
    }
};

// ---------------------- Common main() to test both approaches ----------------------
int main()
{
    int n = 4, k = 2;

    cout << "==== Approach 1: Include/Exclude ====" << endl;
    SolutionIncludeExclude sol1;
    vector<vector<int>> comb1 = sol1.combine(n, k);
    for (auto &v : comb1)
    {
        cout << "[ ";
        for (int num : v)
            cout << num << " ";
        cout << "]" << endl;
    }

    cout << "\n==== Approach 2: For-loop Backtracking ====" << endl;
    SolutionForLoop sol2;
    vector<vector<int>> comb2 = sol2.combine(n, k);
    for (auto &v : comb2)
    {
        cout << "[ ";
        for (int num : v)
            cout << num << " ";
        cout << "]" << endl;
    }

    return 0;
}
