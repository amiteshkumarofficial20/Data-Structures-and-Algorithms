/*
    ==============================================================================
                    💡 COUNT NUMBER OF SET BITS IN A GIVEN INTEGER
    ==============================================================================

    🧩 Problem Statement:
    ---------------------
    Given an integer `n`, count the number of set bits (1s) in its binary representation.

    Return the total number of bits that are set to 1.

    ------------------------------------------------------------------------------
    🧠 Intuition:
    -------------
    - Every integer can be represented in binary form.
    - We can check each bit (either using %2, &1, or other bitwise operations)
      and count how many of them are set (equal to 1).

    Example:
        n = 13
        Binary = 1101
        → There are 3 bits set to 1.
        Output = 3

    ------------------------------------------------------------------------------
    🔢 Examples:
    ------------

    Example 1:
        Input: n = 5
        Binary: 0101
        Output: 2

    Example 2:
        Input: n = 7
        Binary: 0111
        Output: 3

    Example 3:
        Input: n = 0
        Binary: 0000
        Output: 0

    ------------------------------------------------------------------------------
    🧾 Constraints:
    ----------------
    - 0 ≤ n ≤ 10^9
    - Works for all 32-bit integers
    ------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================================
    🪜 APPROACH 1: Brute Force (Divide by 2 OR Bitwise AND with 1)
    ------------------------------------------------------------------------------

    ✅ Intuition:
        We can check every bit one by one.

        There are **two equivalent ways** to check the last bit:
        -------------------------------------------------------
        1️⃣  Using MOD 2:
            - If n % 2 == 1 → last bit is 1
            - Example: 13 % 2 = 1 → LSB = 1

        2️⃣  Using BITWISE AND with 1:
            - If (n & 1) == 1 → last bit is 1
            - Example: 13 (1101)
                       1  (0001)
                       &  = 0001 → 1 → LSB is set

        Both ways work the same, but (n & 1) is faster (bitwise > arithmetic).

    ✅ Algorithm:
        1. Initialize count = 0
        2. While n > 0:
             - If (n & 1) == 1 → increment count
             - Right shift n by 1 (to move to next bit)
        3. Return count

    ✅ Example (n = 13):
        1101 → LSB = 1 → count = 1
        110  → LSB = 0 → count = 1
        11   → LSB = 1 → count = 2
        1    → LSB = 1 → count = 3
        ✅ Result = 3

    ✅ Time Complexity: O(log₂ n)
    ✅ Space Complexity: O(1)
    ==============================================================================
*/
int countSetBits_BruteForce(int n)
{
    int count = 0;

    while (n > 0)
    {
        // Check if the last bit is 1 using bitwise AND (&)
        if (n & 1)
            count++;

        // Shift right to check next bit
        n = n >> 1;
    }

    return count;
}

/*
    ==============================================================================
    ⚡ APPROACH 2: Optimized (Brian Kernighan’s Algorithm)
    ------------------------------------------------------------------------------

    ✅ Intuition:
        - This is a classic bit manipulation trick.
        - When we subtract 1 from n:
              All bits after the rightmost set bit (including it) are flipped.

        - Performing (n & (n - 1)) removes the **rightmost set bit** in one operation.

        - Therefore, the number of times we can perform this operation before n becomes 0
          is equal to the total number of set bits.

    ✅ Key Bitwise Idea:
        Example: n = 12 (binary 1100)
                 n - 1 = 11 (binary 1011)
                 n & (n - 1)
                 = 1100
                 & 1011
                 = 1000  (rightmost set bit removed)

        Again:
                 1000 & 0111 = 0000  → done.

        Total operations = 2 → There were 2 set bits.

    ✅ Algorithm:
        1. Initialize count = 0
        2. While n > 0:
            - Increment count
            - Perform n = n & (n - 1)
              (removes the rightmost set bit)
        3. Return count

    ✅ Time Complexity: O(k)
        where k = number of set bits (faster than O(log n))
    ✅ Space Complexity: O(1)
    ==============================================================================
*/
int countSetBits_Optimized(int n)
{
    int count = 0;

    while (n > 0)
    {
        n = n & (n - 1); // Removes the rightmost set bit
        count++;
    }

    return count;
}

/*
    ==============================================================================
    🧪 DRIVER CODE — Testing Both Approaches
    ==============================================================================
*/
int main()
{
    cout << "=========================================================\n";
    cout << "💡 COUNT NUMBER OF SET BITS (1s) IN A GIVEN INTEGER\n";
    cout << "=========================================================\n\n";

    vector<int> testCases = {0, 1, 5, 7, 12, 15, 32, 255, 1023};

    for (int n : testCases)
    {
        cout << "Number: " << setw(4) << n
             << " | Binary: " << bitset<12>(n)
             << "\n";

        cout << "🔹 Brute Force (n & 1): " << countSetBits_BruteForce(n) << " set bits\n";
        cout << "🔹 Optimized (n & (n - 1)): " << countSetBits_Optimized(n) << " set bits\n";
        cout << "---------------------------------------------------------\n";
    }

    /*
        ==============================================================================
        ✅ SAMPLE OUTPUT:
        ---------------------------------------------------------
        Number:    0 | Binary: 000000000000
        Brute Force (n & 1): 0 set bits
        Optimized (n & (n - 1)): 0 set bits
        ---------------------------------------------------------
        Number:    5 | Binary: 000000000101
        Brute Force (n & 1): 2 set bits
        Optimized (n & (n - 1)): 2 set bits
        ---------------------------------------------------------
        Number:   12 | Binary: 000000001100
        Brute Force (n & 1): 2 set bits
        Optimized (n & (n - 1)): 2 set bits
        ---------------------------------------------------------
        Number:  255 | Binary: 000011111111
        Brute Force (n & 1): 8 set bits
        Optimized (n & (n - 1)): 8 set bits
        ---------------------------------------------------------
        Number: 1023 | Binary: 001111111111
        Brute Force (n & 1): 10 set bits
        Optimized (n & (n - 1)): 10 set bits
        ==============================================================================
    */

    cout << "\n=========================================================\n";
    cout << "✅ Execution Complete — Both Approaches Tested Successfully!\n";
    cout << "=========================================================\n";

    return 0;
}

/*
    ==============================================================================
    🧮 COMPLEXITY SUMMARY
    ------------------------------------------------------------------------------
    | Approach     | Technique                 | Time Complexity | Space Complexity |
    |---------------|--------------------------|-----------------|-----------------|
    | Brute Force   | n & 1 / n % 2 + shifting | O(log₂ n)       | O(1)            |
    | Optimized     | Brian Kernighan’s Trick  | O(k)            | O(1)            |
    ------------------------------------------------------------------------------
    🧠 Key Notes:
    - (n % 2) or (n & 1) → Check if LSB is set.
    - (n >> 1) → Right shift to next bit.
    - (n & (n - 1)) → Removes the rightmost set bit.
    - Optimized method runs only for the number of set bits, not total bits.
    - Efficient for large inputs and competitive programming.
    ==============================================================================
*/
