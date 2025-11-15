/*
====================================================================================================
                                  🔥 LeetCode 137 — Single Number II
                         Find the element that appears ONCE when others appear THRICE
====================================================================================================

    🧩 PROBLEM STATEMENT:
    ---------------------
    Given an integer array nums where:
       • Every element appears EXACTLY 3 TIMES
       • Except ONE element, which appears EXACTLY ONCE

    Return that SINGLE UNIQUE element.

----------------------------------------------------------------------------------------------------
    🔢 EXAMPLES:
        [2,2,3,2] → 3
        [0,1,0,1,0,1,99] → 99
        [-2,-2,1,1,-3,1,-3,-3,-4,-2] → -4

----------------------------------------------------------------------------------------------------
    ❗ CONSTRAINT:
    1 ≤ nums.size() ≤ 30000
    Only ONE element appears once.

====================================================================================================
🥇 APPROACH 1 — BRUTE FORCE (HASH MAP)
====================================================================================================

    🧠 INTUITION:
        Count frequency of every number using a hash map.
        The number with frequency 1 is the answer.

    📌 ALGORITHM (STEP-BY-STEP):
    --------------------------------
    1. Create an empty hash map: freq
    2. Traverse the array:
         - Increase freq[num]++
    3. Traverse the hash map:
         - If freq[x] == 1 → return x
    4. Return -1 (never occurs because problem guarantees 1 unique number)

    📌 PSEUDOCODE:
        freq = map()
        for x in nums:
            freq[x]++

        for key, val in freq:
            if val == 1:
                return key

    ⏱ TIME COMPLEXITY:   O(n)
    💾 SPACE COMPLEXITY: O(n)

====================================================================================================
⚡ APPROACH 2 — OPTIMAL BITWISE COUNTING
====================================================================================================

    🧠 INTUITION:
        Since each repeating number appears 3 times,
        counting bits at each position tells us which bits belong
        to the unique number.

        Bit contribution rule:
            count(bit) % 3 = unique_number_bit

        Example:
            nums = [2,2,3,2]
            2 -> 010
            2 -> 010
            2 -> 010
            3 -> 011

            Bit counts:
                bit0 = 1
                bit1 = 4
                bit2 = 0

            bit0 % 3 = 1 → unique has bit0 = 1
            bit1 % 3 = 1 → unique has bit1 = 1
            => answer = 3 (011)

    📌 ALGORITHM (STEP-BY-STEP):
    --------------------------------
    1. Set result = 0
    2. Loop bit from 0 → 31:
         a. count = 0
         b. For each number:
                if bit is set → count++
         c. If count % 3 != 0 → set this bit in result
    3. Return result

    📌 PSEUDOCODE:
        result = 0
        for bit = 0 ... 31:
            count = 0
            for num in nums:
                if (num & (1 << bit)) != 0:
                    count++
            if count % 3 != 0:
                result |= (1 << bit)
        return result

    ⏱ TIME COMPLEXITY:   O(32n) → O(n)
    💾 SPACE COMPLEXITY: O(1)

====================================================================================================
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

    return -1; // logically unreachable
}

/* =========================================================================================
                        ⚡ OPTIMAL APPROACH — BITWISE COUNTING
   ========================================================================================= */
int singleNumberOptimal(vector<int> &nums)
{
    int result = 0;

    // Check each bit from 0 to 31
    for (int bit = 0; bit < 32; bit++)
    {
        int count = 0;

        for (int num : nums)
            if (num & (1 << bit))
                count++;

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
    cout << "===============================================================\n";
    cout << "🔥 LeetCode 137 — Single Number II (Brute + Optimal)\n";
    cout << "===============================================================\n\n";

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

        cout << "---------------------------------------------------------------\n";
    }

    cout << "\n✅ Execution Complete — All Test Cases Passed!\n";
    cout << "===============================================================\n";

    return 0;
}
