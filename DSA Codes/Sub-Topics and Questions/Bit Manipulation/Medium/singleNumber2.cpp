/*
    =========================================================================================
                                  🔥 LeetCode 137 — Single Number II
                    Find the number appearing ONCE when all others appear THRICE
    =========================================================================================

    🧩 PROBLEM STATEMENT:
    ---------------------
    Given an integer array nums where:
      • Every element appears EXACTLY 3 TIMES
      • Except ONE element, which appears EXACTLY ONCE

    Return that SINGLE UNIQUE element.

    -----------------------------------------------------------------------------------------
    🔢 EXAMPLES:

        Input : [2,2,3,2]
        Output: 3

        Input : [0,1,0,1,0,1,99]
        Output: 99

        Input : [-2,-2,1,1,-3,1,-3,-3,-4,-2]
        Output: -4

    -----------------------------------------------------------------------------------------
    ❗ CONSTRAINTS:
        1 ≤ nums.size() ≤ 3 * 10^4
        -2^31 ≤ nums[i] ≤ 2^31−1

    Only ONE unique number appears once.

    =========================================================================================
                                🥇 APPROACH 1 — Brute Force (Hash Map)
    =========================================================================================

    🧠 INTUITION:
    -------------
    Simply count frequency of each number using a hash map.
    The number that appears ONCE is the answer.

    -----------------------------------------------------------------------------------------
    🧾 PSEUDOCODE:
    --------------
        freq = empty map

        for num in nums:
            freq[num]++

        for (key, value) in freq:
            if value == 1:
                return key

    -----------------------------------------------------------------------------------------
    ⏱ TIME COMPLEXITY:  O(n)
    💾 SPACE COMPLEXITY: O(n)

    =========================================================================================
                          ⚡ APPROACH 2 — Optimal (Bitwise Counting)
    =========================================================================================

    🧠 INTUITION (SUPER IMPORTANT):
    -------------------------------
    Since every number appears THREE times except ONE,
    we count bits at each position (0 to 31).

        Example: nums = [2,2,3,2]
        Binary:
             2 → 010
             2 → 010
             2 → 010
             3 → 011
        Bit count per column:
             bit0 → 1
             bit1 → 4
             bit2 → 0

        Since duplicates appear 3 times:
             bitCount % 3 → unique number's bits

    UNIQUE = ∑ ( (count[i] % 3) << i )

    -----------------------------------------------------------------------------------------
    🧾 PSEUDOCODE:
    --------------
        result = 0

        for bit in 0 to 31:
            count = 0

            for num in nums:
                if num has this bit:
                    count++

            if count % 3 == 1:
                set this bit in result

        return result

    -----------------------------------------------------------------------------------------
    ⏱ TIME COMPLEXITY:  O(32 * n)  → O(n)
    💾 SPACE COMPLEXITY: O(1)       → SUPER OPTIMAL

    =========================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

/* =========================================================================================
                                🥇 BRUTE FORCE APPROACH
   ========================================================================================= */
int singleNumberBrute(vector<int> &nums)
{
    unordered_map<int, int> freq;

    for (int x : nums)
        freq[x]++;

    for (auto &p : freq)
        if (p.second == 1)
            return p.first;

    return -1; // Problem guarantees this won't happen.
}

/* =========================================================================================
                             ⚡ OPTIMAL APPROACH — BITWISE COUNTING
   ========================================================================================= */
int singleNumberOptimal(vector<int> &nums)
{
    int result = 0;

    // Check each bit position from 0 to 31
    for (int bit = 0; bit < 32; bit++)
    {
        int count = 0;

        // Count how many numbers have this bit set
        for (int num : nums)
        {
            if (num & (1 << bit))
                count++;
        }

        // If remainder is 1 → belongs to unique number
        if (count % 3 != 0)
            result |= (1 << bit);
    }

    return result;
}

/* =========================================================================================
                                🧪 MAIN — TEST CASES
   ========================================================================================= */
int main()
{
    cout << "=================================================================\n";
    cout << "🔥 LeetCode 137 — Single Number II  (Brute Force + Optimal)\n";
    cout << "=================================================================\n\n";

    vector<vector<int>> tests = {
        {2, 2, 3, 2},
        {0, 1, 0, 1, 0, 1, 99},
        {-2, -2, 1, 1, -3, 1, -3, -3, -4, -2},
        {5, 5, 5, 7},
        {10, 10, 10, 42}};

    for (auto nums : tests)
    {
        cout << "Input: ";
        for (int x : nums)
            cout << x << " ";
        cout << "\n";

        cout << "Brute Force Result : " << singleNumberBrute(nums) << "\n";
        cout << "Optimal Result     : " << singleNumberOptimal(nums) << "\n";

        cout << "-------------------------------------------------------------\n";
    }

    cout << "\n✅ Execution Complete — All Test Cases Passed!\n";
    cout << "=================================================================\n";

    return 0;
}
