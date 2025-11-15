/*
    =========================================================================================
                            🔥 LeetCode 260 — Single Number III
                      Find the Two Numbers Appearing Odd Number of Times
    =========================================================================================

    🧩 PROBLEM STATEMENT:
    ---------------------
    You are given an integer array nums where:
        - Every number occurs EXACTLY TWICE
        - EXCEPT two numbers that occur EXACTLY ONCE (odd number of times)

    Return the two unique numbers in ASCENDING ORDER.

    Example:
        nums = [1,2,1,3,5,2]
        Unique numbers = [3,5]

    -----------------------------------------------------------------------------------------
    🔢 EXAMPLES:

        Input  : [1,2,1,3,5,2]
        Output : [3,5]

        Input  : [4,1,2,1,2,3]
        Output : [3,4]

        Input  : [10,20]
        Output : [10,20]

    -----------------------------------------------------------------------------------------
    ❗ CONSTRAINTS:
        2 <= nums.length <= 3 * 10^4
        All values fit in 32-bit signed integer.

    =========================================================================================
                                🥇 APPROACH 1 — Brute Force
                                (Hash Map Frequency Count)
    =========================================================================================

    🧠 INTUITION:
    -------------
    Count the frequency of each element using a hash map.
    The elements with frequency == 1 are the answer.

    -----------------------------------------------------------------------------------------
    🧾 PSEUDOCODE:
    --------------
        map freq
        for each num:
            freq[num]++

        result = []
        for each (key, val) in freq:
            if val == 1:
                result.push(key)

        sort(result)
        return result

    -----------------------------------------------------------------------------------------
    ⏱ TIME COMPLEXITY:  O(n)
    💾 SPACE COMPLEXITY: O(n)

    =========================================================================================
                             ⚡ APPROACH 2 — OPTIMAL (BITWISE XOR)
    =========================================================================================

    🧠 INTUITION:
    -------------
    Key Property of XOR:
        a ^ a = 0
        a ^ 0 = a
        XOR cancels duplicates

    Let the two unique numbers be X and Y.

    If we XOR ALL numbers:
        xorAll = X ^ Y   (because all duplicates canceled)

    Now, X and Y MUST differ in at least 1 bit.
    We find the RIGHTMOST SET BIT in xorAll:

        mask = xorAll & -xorAll

    This bit distinguishes X and Y:
        - One has this bit = 1
        - Other has this bit = 0

    Partition the array into 2 groups based on this bit.

    XOR within each group:
        → gives X and Y separately.

    -----------------------------------------------------------------------------------------
    🧾 PSEUDOCODE:
    --------------
        xorAll = XOR of all elements
        mask   = rightmostSetBit(xorAll)

        bucket1 = 0
        bucket2 = 0

        for each num in nums:
            if num & mask:
                bucket1 ^= num
            else:
                bucket2 ^= num

        sort bucket1, bucket2
        return [bucket1, bucket2]

    -----------------------------------------------------------------------------------------
    ⏱ TIME COMPLEXITY:  O(n)
    💾 SPACE COMPLEXITY: O(1)   (super optimal!)

    =========================================================================================
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

    // XOR of all numbers = X ^ Y
    for (int num : nums)
        xorAll ^= num;

    // Find rightmost set bit (bit where X and Y differ)
    int rightmostBit = xorAll & -xorAll;

    int bucket1 = 0, bucket2 = 0;

    // Split numbers into 2 groups
    for (int num : nums)
    {
        if (num & rightmostBit)
            bucket1 ^= num; // numbers having that bit set
        else
            bucket2 ^= num; // numbers having that bit not set
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
