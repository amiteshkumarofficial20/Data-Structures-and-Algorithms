#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
PROGRAM NAME: Subset Sum (All Subset Sums)
DESCRIPTION:
  - Given an array of integers, this program finds the sum of all possible subsets.
  - Uses a recursive approach with the classic "Pick / Not-Pick" technique.
  - Outputs the sums in increasing order.

DETAILED APPROACH:
  1. Start at index 0 with initial sum 0.
  2. For each index, choose either to "pick" or "not pick" the current element.
     a. Pick: Add arr[ind] to current sum and move to next index.
     b. Not Pick: Keep sum unchanged and move to next index.
  3. Continue recursively until the end of the array is reached (base case).
  4. At base case, push the current sum into the result vector.
  5. After recursion, sort the result vector to print sums in increasing order.

TIME COMPLEXITY:
  - Recursion generates 2^N subsets: O(2^N)
  - Sorting 2^N elements: O(2^N log(2^N))
  => Total: O(2^N + 2^N log(2^N))

SPACE COMPLEXITY:
  - O(2^N) for storing subset sums
  - O(N) recursion stack
================================================================================
*/

class Solution
{
public:
    /*
    ------------------------------------------------------------------------
    FUNCTION: subsetSumsHelper
    DESCRIPTION:
      Recursive helper function to generate subset sums.
    PARAMETERS:
      - ind : Current index in the array
      - arr : Reference to input array
      - n   : Size of the array
      - ans : Reference to vector storing subset sums
      - sum : Current sum of the subset formed so far
    LOGIC:
      - At each index, we have two choices:
        1. Pick the element at current index: sum += arr[ind]
        2. Do not pick the element: sum unchanged
      - Recurse to the next index for both choices.
      - Base case: if ind == n, push sum into ans.
    ------------------------------------------------------------------------
    */
    void subsetSumsHelper(int ind, vector<int> &arr, int n, vector<int> &ans, int sum)
    {
        // Base Case: All elements are considered
        if (ind == n)
        {
            ans.push_back(sum); // Store the sum of current subset
            return;             // Return to previous recursive call
        }

        // ------------------ PICK CASE ------------------
        // Include current element in sum and move to next index
        subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);

        // ---------------- NOT PICK CASE ----------------
        // Do not include current element and move to next index
        subsetSumsHelper(ind + 1, arr, n, ans, sum);
    }

    /*
    ------------------------------------------------------------------------
    FUNCTION: subsetSums
    DESCRIPTION:
      Main function that initializes variables and calls recursive helper.
      Sorts the final sums before returning.
    PARAMETERS:
      - arr : Input array
      - n   : Size of the array
    RETURNS:
      - Vector of integers containing all subset sums in increasing order
    ------------------------------------------------------------------------
    */
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> ans;                     // Vector to store all subset sums
        subsetSumsHelper(0, arr, n, ans, 0); // Start recursion from index 0 with sum 0
        sort(ans.begin(), ans.end());        // Sort sums in increasing order
        return ans;                          // Return sorted sums
    }
};

int main()
{
    /*
    ========================================================================
    MAIN FUNCTION
    - Creates an input array
    - Creates an object of Solution class
    - Calls subsetSums function to get all subset sums
    - Prints the sums in sorted order
    ========================================================================
    */

    vector<int> arr{3, 1, 2}; // Input array for testing

    // Create an object of Solution class
    Solution ob;

    // Get all subset sums in a sorted vector
    vector<int> ans = ob.subsetSums(arr, arr.size());

    // Print the result
    cout << "The sum of each subset is:" << endl;
    for (auto sum : ans)
    {
        cout << sum << " ";
    }
    cout << endl;

    /*
    ========================================================================
    EXAMPLE TRACE:
    arr = [3,1,2]
    Subsets & Sums:
      [] -> 0
      [1] -> 1
      [2] -> 2
      [1,2] -> 3
      [3] -> 3
      [3,1] -> 4
      [3,2] -> 5
      [3,1,2] -> 6
    Output: 0 1 2 3 3 4 5 6
    ========================================================================
    */

    return 0;
}

/*
================================================================================
SUMMARY:
- This program uses a classic recursion and backtracking pattern.
- Every element has two choices (pick/not-pick) leading to 2^N subsets.
- Stores sums in a vector and sorts for ordered output.
- Time Complexity: O(2^N + 2^N log(2^N))
- Space Complexity: O(2^N) for storing sums + O(N) recursion stack
- Works efficiently for N up to ~20-25 elements
================================================================================
*/
