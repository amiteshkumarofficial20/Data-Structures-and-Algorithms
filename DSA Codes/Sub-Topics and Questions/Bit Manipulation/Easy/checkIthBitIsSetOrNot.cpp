/*
    ==============================================================================
                          🔍 CHECK IF THE i-th BIT IS SET OR NOT
    ==============================================================================

    🧩 Problem Statement:
    ---------------------
    Given two integers `n` and `i`, determine whether the i-th bit (0-indexed from
    the least significant bit) in the binary representation of `n` is set (i.e., 1)
    or not.

    Return:
        ✅ true   → if the i-th bit is 1
        ❌ false  → if the i-th bit is 0

    ------------------------------------------------------------------------------
    💡 Understanding the Problem:
    ------------------------------
    Every integer `n` can be represented in binary form.
    Example:
        n = 5 → binary = (101)

    Bits are counted from the **rightmost side (Least Significant Bit)**:
        Bit positions (0-indexed):  [2] [1] [0]
        Binary digits:               1   0   1

    If i = 0 → bit = 1 (set)
    If i = 1 → bit = 0 (not set)
    If i = 2 → bit = 1 (set)

    ------------------------------------------------------------------------------
    🧠 Example 1:
    -------------
        Input:  n = 5, i = 0
        Output: true
        Explanation: Binary of 5 → 101, the 0th bit is 1 (set).

    🧠 Example 2:
    -------------
        Input:  n = 10, i = 1
        Output: true
        Explanation: Binary of 10 → 1010, the 1st bit from LSB is 1 (set).

    ------------------------------------------------------------------------------
    🧩 Constraints:
    ----------------
        - 0 ≤ n ≤ 10^9
        - 0 ≤ i ≤ 31  (for 32-bit integer)
    ------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================================
    🪜 APPROACH 1: Brute Force (Binary Representation Check)
    ------------------------------------------------------------------------------
    ✅ Intuition:
        - Convert the number into its binary representation.
        - Iterate through bits from LSB to MSB.
        - Stop when we reach the i-th position.
        - If the bit at that position is 1, return true; else false.

    ✅ Algorithm:
        1. Initialize a counter `pos = 0`.
        2. While n > 0:
              - Extract the last bit using (n % 2).
              - If pos == i → return (last bit == 1)
              - Right-shift (or divide by 2) the number.
              - Increment pos.
        3. If loop ends and i wasn’t reached, return false.

    ✅ Pseudocode:
        function checkIthBit_Brute(n, i):
            pos = 0
            while n > 0:
                bit = n % 2
                if pos == i:
                    return (bit == 1)
                n = n / 2
                pos++
            return false

    ✅ Time Complexity:  O(i)  → may loop up to i bits
    ✅ Space Complexity: O(1)  → constant extra space
    ==============================================================================
*/
bool checkIthBit_BruteForce(int n, int i)
{
    int pos = 0; // Current bit index

    while (n > 0)
    {
        int bit = n % 2; // Extract least significant bit
        if (pos == i)
        {
            return bit == 1; // Return true if i-th bit is set
        }
        n = n / 2; // Move to next bit
        pos++;
    }

    // If the number has fewer bits than i
    return false;
}

/*
    ==============================================================================
    ⚡ APPROACH 2: Bit Manipulation (Optimized)
    ------------------------------------------------------------------------------
    ✅ Intuition:
        - Bit manipulation allows us to check any bit efficiently using shift operations.
        - There are TWO main ways to check if the i-th bit is set:

        ----------------------------------------------------------------------
        🧩 METHOD 1: LEFT SHIFT + BIT MASKING
        ----------------------------------------------------------------------
        - Create a mask that has only the i-th bit set.
              mask = (1 << i)
        - Perform bitwise AND (&) between the number and mask.
              result = n & mask
        - If the result is non-zero → i-th bit is set.

        ✅ Example:
            n = 10 (binary: 1010)
            i = 1
            mask = (1 << 1) = 0010
            n & mask = 1010 & 0010 = 0010 → non-zero ✅ → i-th bit is set.

        ✅ Pseudocode:
            function checkIthBit_LeftShift(n, i):
                return (n & (1 << i)) != 0


        ----------------------------------------------------------------------
        🧩 METHOD 2: RIGHT SHIFT + LEAST SIGNIFICANT BIT CHECK
        ----------------------------------------------------------------------
        - Right shift the number by i bits → this moves the i-th bit to the LSB (bit 0) position.
              shifted = n >> i
        - Then, perform bitwise AND with 1 to isolate the LSB.
              bit = shifted & 1
        - If bit == 1 → i-th bit is set.

        ✅ Example:
            n = 10 (binary: 1010)
            i = 1
            shifted = n >> 1 → 0101
            bit = shifted & 1 → 0101 & 0001 = 0001 → 1 → i-th bit is set ✅

        ✅ Pseudocode:
            function checkIthBit_RightShift(n, i):
                return ((n >> i) & 1) == 1

    ✅ Comparison:
        ----------------------------------------------------------------------
        | Method        | Operation Used | Explanation                | Example Syntax |
        |----------------|----------------|-----------------------------|----------------|
        | Left Shift     | (1 << i)       | Creates a bitmask           | n & (1 << i)   |
        | Right Shift    | (n >> i) & 1   | Moves bit to LSB position   | (n >> i) & 1   |
        ----------------------------------------------------------------------

    ✅ Time Complexity:  O(1)
    ✅ Space Complexity: O(1)
    ==============================================================================
*/

// 🧩 Method 1: Using Left Shift (Bit Masking)
bool checkIthBit_LeftShift(int n, int i)
{
    // Create a mask by shifting 1 to the left by i positions.
    // Example: if i=3 → mask = 00001000
    // Then, use bitwise AND to isolate the i-th bit.
    return (n & (1 << i)) != 0; // Returns true if i-th bit is 1
}

// 🧩 Method 2: Using Right Shift
bool checkIthBit_RightShift(int n, int i)
{
    // Right shift n by i bits to bring the i-th bit to the LSB position.
    // Then AND it with 1 to check if it's set.
    return ((n >> i) & 1) == 1; // Returns true if i-th bit is 1
}

/*
    ==============================================================================
    🧪 DRIVER CODE
    ==============================================================================
*/
int main()
{
    // Example 1
    int n1 = 5, i1 = 0;
    cout << "=========================================\n";
    cout << "Example 1: n = " << n1 << ", i = " << i1 << endl;
    cout << "Binary of n: " << bitset<8>(n1) << endl; // shows 8-bit binary for clarity

    // Using Brute Force
    cout << "Brute Force Result: "
         << (checkIthBit_BruteForce(n1, i1) ? "Set (1)" : "Not Set (0)") << endl;

    // Using Left Shift Method (Bit Masking)
    cout << "Left Shift Method Result: "
         << (checkIthBit_LeftShift(n1, i1) ? "Set (1)" : "Not Set (0)") << endl;

    // Using Right Shift Method
    cout << "Right Shift Method Result: "
         << (checkIthBit_RightShift(n1, i1) ? "Set (1)" : "Not Set (0)") << endl;

    // Example 2
    int n2 = 10, i2 = 1;
    cout << "\n=========================================\n";
    cout << "Example 2: n = " << n2 << ", i = " << i2 << endl;
    cout << "Binary of n: " << bitset<8>(n2) << endl;

    // Brute Force check
    cout << "Brute Force Result: "
         << (checkIthBit_BruteForce(n2, i2) ? "Set (1)" : "Not Set (0)") << endl;

    // --- Bitwise methods ---
    cout << "----------------------------------------" << endl;
    cout << "Checking using both Bitwise Techniques:" << endl;

    // Left Shift (Bit Masking)
    cout << "Left Shift Method Result: "
         << (checkIthBit_LeftShift(n2, i2) ? "Set (1)" : "Not Set (0)") << endl;

    // Right Shift (Move bit to LSB)
    cout << "Right Shift Method Result: "
         << (checkIthBit_RightShift(n2, i2) ? "Set (1)" : "Not Set (0)") << endl;
    return 0;
} // <-- closes main()

/*
    ==============================================================================
    ✅ SAMPLE OUTPUT:
    ----------------------------------------
    Example 1: n = 5, i = 0
    Binary of n: 00000101
    Brute Force Result: Set (1)
    Left Shift Method Result: Set (1)
    Right Shift Method Result: Set (1)

    Example 2: n = 10, i = 1
    Binary of n: 00001010
    Brute Force Result: Set (1)
    Left Shift Method Result: Set (1)
    Right Shift Method Result: Set (1)
    ==============================================================================
*/

/*
    ==============================================================================
    🧮 COMPLEXITY SUMMARY
    ------------------------------------------------------------------------------
    | Approach  | Technique       | Time Complexity | Space Complexity | Notes              |
    |------------|----------------|------------------|------------------|--------------------|
    | BruteForce | Binary Check   | O(i)             | O(1)             | Iterates bit-by-bit|
    | Bitwise    | Bit Masking    | O(1)             | O(1)             | Most efficient     |
    ------------------------------------------------------------------------------
    🏁 Final Verdict:
        - Bit masking is the preferred method for constant-time bit queries.
        - Brute force is educational to understand bit traversal.
    ==============================================================================
*/
