/***************************************************************
 *  Problem: Print Any One Subsequence with Sum = K
 *
 *  Intuition:
 *  ----------------
 *  - A subsequence is formed by either including or excluding
 *    each element of the array.
 *  - At every index, we have two choices:
 *      1. Take the current element (add to sum and sequence)
 *      2. Do not take the current element
 *  - We recurse until we reach the end of the array.
 *  - Base case:
 *      * If current sum == K → print the subsequence & return true.
 *      * Else return false.
 *  - To print **any one subsequence**, we stop recursion as soon
 *    as we find one valid subsequence.
 *
 *  Why it works:
 *  ----------------
 *  - The recursion explores all possible subsequences.
 *  - Short-circuiting (returning true early) ensures that
 *    we stop once we’ve printed a valid subsequence.
 *
 *  Time Complexity:
 *  ----------------
 *  - Worst case (when no subsequence exists or we must check all):
 *        O(2^N), where N = size of array
 *    Because at each element we branch into two calls
 *    (include or exclude).
 *  - Best case:
 *        Much faster if we find a subsequence early and return.
 *
 *  Space Complexity:
 *  ----------------
 *  - Recursion stack = O(N) (depth of recursion tree)
 *  - Extra space for storing current subsequence = O(N)
 *  - So total = O(N)
 ***************************************************************/

#include <bits/stdc++.h>
using namespace std;

/**
 * Function: printOneSubsequence
 * ------------------------------
 * @param idx  : current index in the array
 * @param arr  : input array
 * @param ds   : vector to hold the current subsequence
 * @param sum  : current sum of subsequence
 * @param k    : target sum
 *
 * @return true if subsequence with sum == k is found, else false
 */
bool printOneSubsequence(int idx, vector<int> &arr,
                         vector<int> &ds, int sum, int k)
{
    // Base case: if we’ve considered all elements
    if (idx == arr.size())
    {
        if (sum == k)
        {
            // Print the subsequence
            cout << "Subsequence found: ";
            for (int x : ds)
                cout << x << " ";
            cout << endl;
            return true; // Found one valid subsequence
        }
        return false; // Not valid
    }

    // Choice 1: Take current element
    ds.push_back(arr[idx]); // include element
    if (printOneSubsequence(idx + 1, arr, ds, sum + arr[idx], k))
        return true; // Stop recursion if found
    ds.pop_back();   // backtrack

    // Choice 2: Do not take current element
    if (printOneSubsequence(idx + 1, arr, ds, sum, k))
        return true;

    // If neither choice worked, return false
    return false;
}

int main()
{
    // Input array
    vector<int> arr = {1, 2, 1};

    // Target sum
    int k = 2;

    // Vector to store the current subsequence
    vector<int> ds;

    cout << "Trying to find any one subsequence with sum = " << k << endl;

    // Call recursive function
    bool exists = printOneSubsequence(0, arr, ds, 0, k);

    if (!exists)
        cout << "No subsequence with sum " << k << " exists." << endl;

    return 0;
}
