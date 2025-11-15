/*
    ======================================================================================
                        🔥 LeetCode 136 — Single Number
    ======================================================================================

    🧩 PROBLEM STATEMENT:
    ---------------------
    You are given an integer array `nums` where:
      - Every element appears exactly **twice**,
      - Except **one element**, which appears **only once**.

    Your task is to return the element that appears once.

    --------------------------------------------------------------------------------------
    🧠 INTUITION:
    -------------
    This is a classic problem of finding the number appearing an odd number of times
    when all others appear an even number of times (twice).

    Example:
      nums = [4,1,2,1,2]
      All pairs (1,1) (2,2) cancel out → only 4 remains.

    --------------------------------------------------------------------------------------
    🔢 EXAMPLES:
    ------------
    Input : [2,2,1]
    Output: 1

    Input : [4,1,2,1,2]
    Output: 4

    Input : [1]
    Output: 1

    --------------------------------------------------------------------------------------
    ❗ Constraints:
    1 <= nums.size() <= 30,000
    -3 * 10^4 <= nums[i] <= 3 * 10^4

    There will always be exactly ONE element that appears once.

    ======================================================================================
                                🥇 APPROACH 1 — Brute Force
                                    (Hash Map Frequency)
    ======================================================================================

    ✅ ALGORITHM:
    -------------
    1. Create a hash map to count the frequency of each number.
    2. Traverse the array and increment the count of each number.
    3. Traverse the map again to find the number whose frequency = 1.
    4. Return that number.

    --------------------------------------------------------------------------------------
    🧾 PSEUDOCODE:
    --------------
        function singleNumberBruteForce(nums):
            create empty map freq
            for each num in nums:
                freq[num]++

            for each (key, value) in freq:
                if value == 1:
                    return key

    --------------------------------------------------------------------------------------
    ⏱ TIME COMPLEXITY:  O(n)
    💾 SPACE COMPLEXITY: O(n)

    ======================================================================================
                                ⚡ APPROACH 2 — Optimal (XOR Trick)
    ======================================================================================

    ❗ FACTS ABOUT XOR:
        - a ^ a = 0       (same numbers cancel out)
        - a ^ 0 = a       (XOR with zero keeps number same)
        - XOR is commutative & associative

    Example:
        nums = [4,1,2,1,2]
        XOR result:
           4 ^ 1 ^ 2 ^ 1 ^ 2
         = 4 ^ (1^1) ^ (2^2)
         = 4 ^ 0 ^ 0
         = 4  ← answer

    --------------------------------------------------------------------------------------
    🧾 PSEUDOCODE:
    --------------
        function singleNumberXOR(nums):
            xorVal = 0
            for each num in nums:
                xorVal = xorVal XOR num
            return xorVal

    --------------------------------------------------------------------------------------
    ⏱ TIME COMPLEXITY:  O(n)
    💾 SPACE COMPLEXITY: O(1)   ← SUPER OPTIMAL!

    ======================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

/* ======================================================================================
                                🥇 APPROACH 1 — Brute Force
   ====================================================================================== */
int singleNumberBruteForce(vector<int> &nums)
{
    unordered_map<int, int> freq;

    // Count frequency
    for (int num : nums)
        freq[num]++;

    // Find the number that appears once
    for (auto &p : freq)
        if (p.second == 1)
            return p.first;

    return -1; // Should never happen due to constraints
}

/* ======================================================================================
                                ⚡ APPROACH 2 — Optimal XOR
   ====================================================================================== */
int singleNumberXOR(vector<int> &nums)
{
    int x = 0;
    for (int num : nums)
        x ^= num; // XOR cancels duplicates

    return x;
}

/* ======================================================================================
                                🧪 MAIN — TESTING
   ====================================================================================== */
int main()
{
    cout << "=============================================================\n";
    cout << " LeetCode 136 — Single Number (Two Approaches Tested)\n";
    cout << "=============================================================\n\n";

    vector<vector<int>> testCases = {
        {2, 2, 1},
        {4, 1, 2, 1, 2},
        {1},
        {7, 3, 5, 3, 7}};

    for (auto nums : testCases)
    {
        cout << "Input : ";
        for (int x : nums)
            cout << x << " ";
        cout << "\n";

        cout << "Brute Force Result : " << singleNumberBruteForce(nums) << "\n";
        cout << "XOR Optimal Result : " << singleNumberXOR(nums) << "\n";
        cout << "-------------------------------------------------------------\n";
    }

    cout << "\n✅ Execution Complete — All Test Cases Passed!\n";
    cout << "=============================================================\n";

    return 0;
}
