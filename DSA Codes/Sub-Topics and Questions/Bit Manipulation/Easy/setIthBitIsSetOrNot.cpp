/*
    ==============================================================================
                             🔧 SETTING THE i-th BIT OF A NUMBER
    ==============================================================================

    🧩 Problem Statement:
    ---------------------
    Given two integers `n` and `i`, set (turn ON) the i-th bit of `n` (0-indexed
    from the least significant bit, i.e., LSB).

    Return the new number after setting the i-th bit.

    ------------------------------------------------------------------------------
    🧠 Example 1:
        Input:  n = 5, i = 1
        Output: 7
        Explanation:
            Binary of 5 = 0101
            Setting the 1st bit → 0111 = 7

    🧠 Example 2:
        Input:  n = 10, i = 0
        Output: 11
        Explanation:
            Binary of 10 = 1010
            Setting the 0th bit → 1011 = 11

    ------------------------------------------------------------------------------
    🧩 Constraints:
        - 0 ≤ n ≤ 10^9
        - 0 ≤ i ≤ 31  (for 32-bit integer)
    ------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================================
    🪜 APPROACH 1: Brute Force (Manual Binary Construction)
    ------------------------------------------------------------------------------
    ✅ Intuition:
        - Convert `n` into its binary form (conceptually).
        - If the i-th bit is already 1 → leave it.
        - If it's 0 → add 2^i to the number to set that bit.

    ✅ Algorithm:
        Step 1: Compute power = 2^i.
        Step 2: If i-th bit is not already set → n = n + power.
        Step 3: Return n.

    ✅ Example:
        n = 5 (0101), i = 1
        2^i = 2
        Bit at index 1 is 0 → add 2 → new n = 7 (0111)

    ✅ Pseudocode:
        function setIthBit_BruteForce(n, i):
            power = 2^i
            if ((n / power) % 2 == 0):
                n = n + power
            return n

    ✅ Time Complexity:  O(1)
    ✅ Space Complexity: O(1)
    ==============================================================================
*/
int setIthBit_BruteForce(int n, int i)
{
    int power = pow(2, i); // Equivalent to (1 << i)

    // Check if i-th bit is already set or not
    if (((n / power) % 2) == 0)
    {
        n += power; // Add 2^i to set the bit
    }
    return n;
}

/*
    ==============================================================================
    ⚡ APPROACH 2: Bit Manipulation (Optimized)
    ------------------------------------------------------------------------------
    ✅ Intuition:
        We can use bitwise operators to set the i-th bit efficiently.

        ----------------------------------------------------------------------
        🧩 METHOD 1: LEFT SHIFT + BITWISE OR
        ----------------------------------------------------------------------
        - Create a mask that has only the i-th bit set: mask = (1 << i)
        - Perform bitwise OR (|) with n.
        - This operation turns ON the i-th bit without affecting others.

        Example:
            n = 5 (0101)
            i = 1
            mask = 1 << 1 = 0010
            n | mask = 0101 | 0010 = 0111 = 7

        ✅ Pseudocode:
            function setIthBit_LeftShift(n, i):
                return n | (1 << i)

        ✅ Time Complexity:  O(1)
        ✅ Space Complexity: O(1)


        ----------------------------------------------------------------------
        🧩 METHOD 2: RIGHT SHIFT (Conceptual View)
        ----------------------------------------------------------------------
        - Although we normally use left shift to set a bit,
          right shift can demonstrate bit movement in reverse.

        - Concept:
            Move the i-th bit to the LSB position by right shifting `n >> i`.
            Then OR it with 1 to ensure the LSB (formerly i-th bit) is set,
            and then shift it back left by i.

        - This is mainly for conceptual understanding; it’s not as clean as Method 1.

        ✅ Pseudocode:
            function setIthBit_RightShift(n, i):
                shifted = n >> i
                shifted = shifted | 1
                n = (n & (~(1 << i))) | (shifted << i)
                return n

        ✅ Time Complexity:  O(1)
        ✅ Space Complexity: O(1)
    ==============================================================================
*/

// 🧩 Method 1: Left Shift + Bitwise OR (Efficient way)
int setIthBit_LeftShift(int n, int i)
{
    // Create a mask where only the i-th bit is 1
    // Perform OR to ensure that bit becomes 1 in 'n'
    return n | (1 << i);
}

// 🧩 Method 2: Right Shift (Conceptual Demonstration)
int setIthBit_RightShift(int n, int i)
{
    // Move the i-th bit to the LSB
    int shifted = n >> i;

    // Force-set the LSB to 1
    shifted = shifted | 1;

    // Clear the original i-th bit and restore others
    n = (n & (~(1 << i))) | (shifted << i);
    return n;
}

/*
    ==============================================================================
    🧪 DRIVER CODE
    ==============================================================================
*/
int main()
{
    int n1 = 5, i1 = 1;
    cout << "=========================================\n";
    cout << "Example 1: n = " << n1 << ", i = " << i1 << endl;
    cout << "Binary of n: " << bitset<8>(n1) << endl;

    // Brute Force Method
    cout << "Brute Force Result: " << setIthBit_BruteForce(n1, i1)
         << " (Binary: " << bitset<8>(setIthBit_BruteForce(n1, i1)) << ")\n";

    // Left Shift Method
    cout << "Left Shift Method Result: " << setIthBit_LeftShift(n1, i1)
         << " (Binary: " << bitset<8>(setIthBit_LeftShift(n1, i1)) << ")\n";

    // Right Shift Method (conceptual)
    cout << "Right Shift Method Result: " << setIthBit_RightShift(n1, i1)
         << " (Binary: " << bitset<8>(setIthBit_RightShift(n1, i1)) << ")\n";

    cout << "-----------------------------------------\n";

    int n2 = 10, i2 = 0;
    cout << "Example 2: n = " << n2 << ", i = " << i2 << endl;
    cout << "Binary of n: " << bitset<8>(n2) << endl;

    cout << "Brute Force Result: " << setIthBit_BruteForce(n2, i2)
         << " (Binary: " << bitset<8>(setIthBit_BruteForce(n2, i2)) << ")\n";

    cout << "Left Shift Method Result: " << setIthBit_LeftShift(n2, i2)
         << " (Binary: " << bitset<8>(setIthBit_LeftShift(n2, i2)) << ")\n";

    cout << "Right Shift Method Result: " << setIthBit_RightShift(n2, i2)
         << " (Binary: " << bitset<8>(setIthBit_RightShift(n2, i2)) << ")\n";

    /*
        ==============================================================================
        ✅ SAMPLE OUTPUT:
        ----------------------------------------
        Example 1: n = 5, i = 1
        Binary of n: 00000101
        Brute Force Result: 7 (Binary: 00000111)
        Left Shift Method Result: 7 (Binary: 00000111)
        Right Shift Method Result: 7 (Binary: 00000111)

        Example 2: n = 10, i = 0
        Binary of n: 00001010
        Brute Force Result: 11 (Binary: 00001011)
        Left Shift Method Result: 11 (Binary: 00001011)
        Right Shift Method Result: 11 (Binary: 00001011)
        ==============================================================================
    */

    return 0;
}

/*
    ==============================================================================
    🧮 COMPLEXITY SUMMARY
    ------------------------------------------------------------------------------
    | Approach  | Technique            | Time Complexity | Space Complexity | Notes |
    |------------|---------------------|------------------|------------------|-------|
    | BruteForce | Math (2^i) Add      | O(1)             | O(1)             | Simple to understand |
    | LeftShift  | Bit Mask + OR       | O(1)             | O(1)             | Most efficient |
    | RightShift | Shift Manipulation  | O(1)             | O(1)             | Conceptual example |
    ------------------------------------------------------------------------------
    🏁 Final Verdict:
        ✅ Left Shift + Bitwise OR is the cleanest and fastest method to set bits.
        🧠 Right Shift version helps understand bit movement and masking.
    ==============================================================================
*/
