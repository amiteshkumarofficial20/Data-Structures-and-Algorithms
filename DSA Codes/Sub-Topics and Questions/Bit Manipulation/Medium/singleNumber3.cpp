/*
====================================================================================================
                            🔥 LeetCode 260 — Single Number III
                      Find the Two Numbers Appearing Odd Number of Times
====================================================================================================

    🧩 PROBLEM STATEMENT:
    ---------------------
    You are given an integer array nums where:
        - Every number appears EXACTLY TWICE
        - Except TWO numbers which appear EXACTLY ONCE

    Return the two unique numbers in ASCENDING ORDER.

----------------------------------------------------------------------------------------------------
    🔢 EXAMPLES:
        [1,2,1,3,5,2] → [3,5]
        [4,1,2,1,2,3] → [3,4]
        [10,20]       → [10,20]

----------------------------------------------------------------------------------------------------
    ❗ CONSTRAINTS:
        2 ≤ nums.length ≤ 30000
        All values fit in signed 32-bit integer.

====================================================================================================
🥇 APPROACH 1 — BRUTE FORCE (HASH MAP)
====================================================================================================

    🧠 INTUITION:
        Count frequency of each element.
        The elements whose frequency is exactly 1 are the answer.

    ----------------------------------------------------------------------------------------------
    📌 ALGORITHM (STEP-BY-STEP):
    --------------------------------
    1. Create an empty hash map freq.
    2. Loop through nums:
           freq[num]++
    3. Create an empty result list.
    4. Loop through freq:
           if value == 1 → push key into result.
    5. Sort result in ascending order.
    6. Return result.

    ----------------------------------------------------------------------------------------------
    📌 PSEUDOCODE:
        map freq
        for num in nums:
            freq[num]++

        ans = []
        for key,val in freq:
            if val == 1:
                ans.push(key)

        sort(ans)
        return ans

    ----------------------------------------------------------------------------------------------
    ⏱ TIME COMPLEXITY:  O(n)
    💾 SPACE COMPLEXITY: O(n)

====================================================================================================
⚡ APPROACH 2 — OPTIMAL BITWISE XOR
====================================================================================================

    🧠 INTUITION:
        XOR cancels duplicates:
            a ^ a = 0
            a ^ 0 = a

        If two numbers are unique (say X and Y):
            xorAll = X ^ Y

        Since X ≠ Y, xorAll has at least one bit set.
        We extract the RIGHTMOST SET BIT:

            mask = xorAll & -xorAll

        Use this bit to split the numbers into 2 groups:
            • Group 1: bit is 1
            • Group 2: bit is 0

        Each unique number will fall into a different group.
        XOR each group separately → retrieves both numbers.

    ----------------------------------------------------------------------------------------------
    📌 ALGORITHM (STEP-BY-STEP):
    --------------------------------
    1. Compute xorAll = XOR of all numbers.
           xorAll = X ^ Y
    2. Find rightmost set bit:
           mask = xorAll & -xorAll
    3. Initialize bucket1 = 0, bucket2 = 0.
    4. Loop through nums:
           if num & mask → bucket1 ^= num
           else           → bucket2 ^= num
    5. Sort bucket1 and bucket2.
    6. Return [bucket1, bucket2].

    ----------------------------------------------------------------------------------------------
    📌 PSEUDOCODE:
        xorAll = XOR(nums)
        mask = xorAll & -xorAll

        a = 0, b = 0
        for num in nums:
            if num & mask:
                a ^= num
            else:
                b ^= num

        return sorted(a, b)

    ----------------------------------------------------------------------------------------------
    ⏱ TIME COMPLEXITY:  O(n)
    💾 SPACE COMPLEXITY: O(1)

====================================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

/* =========================================================================================
                                🥇 BRUTE FORCE APPROACH
   ========================================================================================= */
vector<int> singleNumberBrute(vector<int> &nums)
{
    unordered_map<int, int> freq;

    for (int num : nums)
        freq[num]++;

    vector<int> ans;
    for (auto &p : freq)
        if (p.second == 1)
            ans.push_back(p.first);

    sort(ans.begin(), ans.end());
    return ans;
}

/* =========================================================================================
                                ⚡ OPTIMAL BITWISE APPROACH
   ========================================================================================= */
vector<int> singleNumberOptimal(vector<int> &nums)
{
    int xorAll = 0;

    for (int num : nums)
        xorAll ^= num;

    int rightmostBit = xorAll & -xorAll;

    int bucket1 = 0, bucket2 = 0;

    for (int num : nums)
    {
        if (num & rightmostBit)
            bucket1 ^= num;
        else
            bucket2 ^= num;
    }

    vector<int> ans = {bucket1, bucket2};
    sort(ans.begin(), ans.end());
    return ans;
}

/* =========================================================================================
                                🧪 MAIN — TEST CASES
   ========================================================================================= */
int main()
{
    cout << "==============================================================\n";
    cout << "🔥 LeetCode 260 — Single Number III (Two Unique Numbers)\n";
    cout << "==============================================================\n\n";

    vector<vector<int>> testCases = {
        {1, 2, 1, 3, 5, 2},
        {4, 1, 2, 1, 2, 3},
        {10, 20},
        {7, 7, 9, 11}};

    for (auto nums : testCases)
    {
        cout << "Input: ";
        for (int x : nums)
            cout << x << " ";
        cout << "\n";

        auto brute = singleNumberBrute(nums);
        auto opt = singleNumberOptimal(nums);

        cout << "Brute Force Result : [" << brute[0] << ", " << brute[1] << "]\n";
        cout << "Optimal XOR Result : [" << opt[0] << ", " << opt[1] << "]\n";

        cout << "--------------------------------------------------------------\n";
    }

    cout << "\n✅ Execution Complete — All Methods Verified!\n";
    cout << "==============================================================\n";

    return 0;
}
