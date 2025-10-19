/***************************************************************
 *  Problem: Count Subsequences with Sum = K
 *
 *  Intuition:
 *  ----------------
 *  - A subsequence is formed by including or excluding each element.
 *  - At each index, we make 2 choices:
 *       1. Include the element → add it to current sum
 *       2. Exclude the element → keep sum unchanged
 *  - Recursively explore both choices until the end of the array.
 *  - Base case:
 *       * If we reach the end of array:
 *            return 1 if sum == K (valid subsequence)
 *            return 0 otherwise
 *  - The final answer is the total count of all valid subsequences.
 *
 *  Why recursion works:
 *  ----------------
 *  - It systematically explores all `2^N` possible subsequences.
 *  - By returning counts from each branch, we add up the valid ones.
 *
 *  Time Complexity:
 *  ----------------
 *  - O(2^N), where N = size of array
 *    → Because at each index we branch into two recursive calls.
 *  - Each subsequence is checked once.
 *
 *  Space Complexity:
 *  ----------------
 *  - Recursion stack depth = O(N) (due to backtracking)
 *  - No extra space apart from function call stack
 *  - Total = O(N)
 ***************************************************************/

#include <bits/stdc++.h>
using namespace std;

/**
 * Function: countSubsequences
 * ------------------------------
 * @param idx  : current index in the array
 * @param arr  : input array
 * @param sum  : current accumulated sum
 * @param k    : target sum
 *
 * @return number of subsequences from idx..end whose sum == k
 */
int countSubsequences(int idx, vector<int> &arr, int sum, int k)
{
    // Base case: if we have considered all elements
    if (idx == arr.size())
    {
        return (sum == k) ? 1 : 0; // valid subsequence found
    }

    // Choice 1: Take current element
    int take = countSubsequences(idx + 1, arr, sum + arr[idx], k);

    // Choice 2: Do not take current element
    int notTake = countSubsequences(idx + 1, arr, sum, k);

    // Total valid subsequences = take + notTake
    return take + notTake;
}

int main()
{
    // Example input array
    vector<int> arr = {1, 2, 1};

    // Target sum
    int k = 2;

    // Call recursive function
    int count = countSubsequences(0, arr, 0, k);

    cout << "Number of subsequences with sum = " << k << " is: " << count << endl;

    return 0;
}
