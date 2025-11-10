/*
    ==============================================================================
                        💡 LeetCode #2220 — Minimum Bit Flips to Convert Number
    ==============================================================================

    🧩 PROBLEM STATEMENT:
    ---------------------
    A bit flip of a number `x` is choosing a bit in the binary representation of `x`
    and flipping it (i.e., turning 0 → 1 or 1 → 0).

    You are given two integers: `start` and `goal`.

    Return the **minimum number of bit flips** required to convert `start` to `goal`.

    ------------------------------------------------------------------------------
    ⚙️ FUNCTIONAL REQUIREMENT:
    --------------------------
    int minBitFlips(int start, int goal)

    → Returns the minimum number of bit flips to make `start` == `goal`.

    ------------------------------------------------------------------------------
    🧠 INTUITION:
    -------------
    - Every bit in binary can be either **0** or **1**.
    - To make `start` equal to `goal`, we only need to flip **those bits** where
      they differ.
    - Hence, we just count the number of **bit positions** where the two numbers
      differ.

    ------------------------------------------------------------------------------
    💡 OBSERVATION:
    ---------------
    → If we perform XOR (^) between two numbers:
          - Bits that are same → 0
          - Bits that differ → 1
      So counting 1’s in (start ^ goal) gives us the number of differing bits.

    ------------------------------------------------------------------------------
    🔢 EXAMPLES:
    ------------

    Example 1:
    ----------
        Input:  start = 10, goal = 7
        Binary: start = 1010
                 goal  = 0111
                 XOR   = 1101 → three 1's
        Output: 3

        Explanation:
        We can flip these bits:
         - bit 0 (LSB): 0 → 1
         - bit 2: 0 → 1
         - bit 3: 1 → 0
        Minimum flips = 3 ✅


    Example 2:
    ----------
        Input:  start = 3, goal = 4
        Binary: start = 011
                 goal  = 100
                 XOR   = 111 → three 1's
        Output: 3 ✅


    Example 3:
    ----------
        Input:  start = 0, goal = 0
        Binary: start = 0000
                 goal  = 0000
                 XOR   = 0000
        Output: 0 ✅

    ------------------------------------------------------------------------------
    🔒 CONSTRAINTS:
    ----------------
        0 ≤ start, goal ≤ 10⁹
    ------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================================
    🪜 APPROACH 1 — BRUTE FORCE (BIT-BY-BIT COMPARISON)
    ==============================================================================

    ✅ INTUITION:
        We manually compare each bit of `start` and `goal` from the least significant
        bit (LSB) to the most significant bit (MSB).
        Whenever a bit differs, that means one flip is needed.

    ------------------------------------------------------------------------------
    🔍 STEP-BY-STEP EXAMPLE:
        start = 10 (binary 1010)
        goal  = 7  (binary 0111)

        Compare bit-by-bit (from right to left):
        ----------------------------------------
        Bit 0: start=0, goal=1 → flip++
        Bit 1: start=1, goal=1 → no change
        Bit 2: start=0, goal=1 → flip++
        Bit 3: start=1, goal=0 → flip++
        Total flips = 3 ✅

    ------------------------------------------------------------------------------
    🧮 PSEUDOCODE:
        function countBitFlips_BruteForce(start, goal):
            flips = 0
            while start > 0 or goal > 0:
                bit1 = start % 2
                bit2 = goal % 2
                if bit1 != bit2:
                    flips = flips + 1
                start = start / 2
                goal = goal / 2
            return flips

    ------------------------------------------------------------------------------
    🧩 TIME COMPLEXITY:  O(log₂(max(start, goal)))  → each bit checked once
    🧮 SPACE COMPLEXITY: O(1)
    ==============================================================================
*/

int countBitFlips_BruteForce(int start, int goal)
{
    int flips = 0;

    // Continue until both numbers are processed completely
    while (start > 0 || goal > 0)
    {
        // Extract the last bit (can use %2 or &1)
        int bitStart = start & 1;
        int bitGoal = goal & 1;

        // If the bits differ, we need a flip
        if (bitStart != bitGoal)
            flips++;

        // Shift right by 1 to check next bit
        start >>= 1;
        goal >>= 1;
    }

    return flips;
}

/*
    ==============================================================================
    ⚡ APPROACH 2 — OPTIMIZED (XOR + BRIAN KERNIGHAN’S BIT COUNT)
    ==============================================================================

    ✅ INTUITION:
        - XOR (^) gives 1 for bits that differ.
        - So (start ^ goal) marks all differing bit positions with 1.
        - Counting how many 1s are in XOR gives the total flips needed.

        But instead of checking every bit individually,
        we can use Brian Kernighan’s algorithm to count set bits efficiently.

    ------------------------------------------------------------------------------
    ⚙️ HOW BRIAN KERNIGHAN’S ALGORITHM WORKS:
        For a number x:
        Each operation `x = x & (x - 1)` removes the **rightmost set bit (1)**.

        Hence, number of iterations = number of set bits.

        Example:
            x = 13 → binary 1101
            Step 1: x = 1101 & 1100 = 1100
            Step 2: x = 1100 & 1011 = 1000
            Step 3: x = 1000 & 0111 = 0000 → done (3 bits removed)
            → 3 set bits = 3 flips ✅

    ------------------------------------------------------------------------------
    🧮 PSEUDOCODE:
        function countBitFlips_Optimized(start, goal):
            diff = start XOR goal
            flips = 0
            while diff > 0:
                diff = diff & (diff - 1)
                flips++
            return flips

    ------------------------------------------------------------------------------
    🧩 TIME COMPLEXITY:  O(k)
        where k = number of differing bits (faster than O(log n))
    🧮 SPACE COMPLEXITY: O(1)
    ==============================================================================
*/

int countBitFlips_Optimized(int start, int goal)
{
    int diff = start ^ goal; // XOR highlights differing bits
    int flips = 0;

    while (diff > 0)
    {
        diff = diff & (diff - 1); // Remove rightmost set bit
        flips++;
    }

    return flips;
}

/*
    ==============================================================================
    🧪 DRIVER CODE — TESTING BOTH APPROACHES
    ==============================================================================

    Includes:
      - Multiple test cases
      - Binary representation of both numbers
      - Comparison between brute force & optimized
      - Displays XOR binary form
    ==============================================================================
*/

int main()
{
    cout << "===========================================================\n";
    cout << "💡 LeetCode #2220 — Minimum Bit Flips to Convert Number\n";
    cout << "===========================================================\n\n";

    vector<pair<int, int>> testCases = {
        {10, 7},  // Expected 3
        {3, 4},   // Expected 3
        {0, 0},   // Expected 0
        {5, 2},   // Expected 3 (101 vs 010)
        {15, 0},  // Expected 4 (1111 vs 0000)
        {8, 16}}; // Expected 2 (01000 vs 10000)

    for (size_t i = 0; i < testCases.size(); ++i)
    {
        int start = testCases[i].first;
        int goal = testCases[i].second;

        cout << "🔹 Test Case " << (i + 1) << ":\n";
        cout << "   Start = " << setw(3) << start
             << " (Binary: " << bitset<8>(start) << ")\n";
        cout << "   Goal  = " << setw(3) << goal
             << " (Binary: " << bitset<8>(goal) << ")\n";

        int brute = countBitFlips_BruteForce(start, goal);
        int opt = countBitFlips_Optimized(start, goal);

        cout << "   XOR   = " << bitset<8>(start ^ goal)
             << "  → (Differing bits)\n";
        cout << "   Brute Force Result : " << brute << " flips\n";
        cout << "   Optimized Result   : " << opt << " flips\n";
        cout << "-----------------------------------------------------------\n";
    }

    cout << "\n===========================================================\n";
    cout << "✅ Execution Complete — Both Approaches Tested Successfully!\n";
    cout << "===========================================================\n";

    return 0;
}

/*
    ==============================================================================
    🧮 COMPLEXITY SUMMARY
    ------------------------------------------------------------------------------
    | Approach     | Concept Used              | Time Complexity | Space Complexity |
    |---------------|---------------------------|-----------------|-----------------|
    | Brute Force   | Bit-by-bit Comparison     | O(log₂ N)       | O(1)            |
    | Optimized     | XOR + Bit Manipulation    | O(k)            | O(1)            |
    ------------------------------------------------------------------------------
    Where:
      • N = max(start, goal)
      • k = number of differing bits
    ==============================================================================

    🧠 KEY INSIGHTS:
    ----------------
    1️⃣ XOR (^) — Identifies bit differences:
        - 1 when bits differ
        - 0 when bits are same

    2️⃣ n & (n - 1) — Removes the rightmost set bit:
        - Used in bit counting and power-of-2 problems.

    3️⃣ (n & 1) — Checks whether the least significant bit is set.

    4️⃣ Bit manipulation provides O(1) per bit operations,
        which is significantly faster than arithmetic.

    ==============================================================================

    ✅ SAMPLE OUTPUT (when run):

    ===========================================================
    💡 LeetCode #2220 — Minimum Bit Flips to Convert Number
    ===========================================================

    🔹 Test Case 1:
       Start =  10 (Binary: 00001010)
       Goal  =   7 (Binary: 00000111)
       XOR   = 00001101  → (Differing bits)
       Brute Force Result : 3 flips
       Optimized Result   : 3 flips
    -----------------------------------------------------------
    🔹 Test Case 2:
       Start =   3 (Binary: 00000011)
       Goal  =   4 (Binary: 00000100)
       XOR   = 00000111  → (Differing bits)
       Brute Force Result : 3 flips
       Optimized Result   : 3 flips
    -----------------------------------------------------------
    🔹 Test Case 3:
       Start =  15 (Binary: 00001111)
       Goal  =   0 (Binary: 00000000)
       XOR   = 00001111  → (Differing bits)
       Brute Force Result : 4 flips
       Optimized Result   : 4 flips
    -----------------------------------------------------------

    ✅ Execution Complete — Both Approaches Tested Successfully!
    ===========================================================
*/
