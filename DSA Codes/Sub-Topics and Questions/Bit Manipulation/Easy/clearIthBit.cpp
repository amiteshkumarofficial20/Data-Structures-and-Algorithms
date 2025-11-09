/*
    ==============================================================================
                         🧹 CLEARING THE i-th BIT OF A NUMBER
    ==============================================================================

    🧩 Problem Statement:
    ---------------------
    Given two integers `n` and `i`, clear (turn OFF) the i-th bit of `n` (0-indexed
    from the least significant bit, i.e., LSB).

    That means:
        - If the i-th bit is 1 → make it 0.
        - If the i-th bit is 0 → leave it unchanged.

    Return the new number after clearing the i-th bit.

    ------------------------------------------------------------------------------
    🧠 Example 1:
        Input:  n = 13, i = 2
        Output: 9
        Explanation:
            Binary of 13 → 1101
            Clearing bit at index 2 (counting from right, 0-based):
            Bit positions: [3][2][1][0]
                           1  1  0  1
            Clear bit 2 → 1001 = 9

    🧠 Example 2:
        Input:  n = 10, i = 1
        Output: 8
        Explanation:
            Binary of 10 → 1010
            Clearing bit 1 → 1000 = 8

    ------------------------------------------------------------------------------
    🧩 Constraints:
        - 0 ≤ n ≤ 10^9
        - 0 ≤ i ≤ 31   (for 32-bit integers)
    ------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================================
    🪜 APPROACH 1: Brute Force (Mathematical / Binary Representation)
    ------------------------------------------------------------------------------
    ✅ Intuition:
        - Each bit in a number corresponds to a power of 2.
        - The i-th bit corresponds to 2^i.
        - If the i-th bit is currently ON (1), we can clear it by subtracting 2^i.
        - If the i-th bit is already OFF (0), no change is needed.

    ✅ Algorithm:
        1. Compute value = 2^i.
        2. Check if the i-th bit is 1 using modulo or division logic.
        3. If it’s 1 → subtract value from n.
        4. Return the result.

    ✅ Example:
        n = 13 (1101), i = 2 → 2^2 = 4
        Bit at position 2 = 1 → subtract 4 → 9 (1001)

    ✅ Pseudocode:
        function clearIthBit_Brute(n, i):
            val = 2^i
            if ((n / val) % 2 == 1):
                n = n - val
            return n

    ✅ Time Complexity:  O(1)
    ✅ Space Complexity: O(1)
    ==============================================================================
*/
int clearIthBit_BruteForce(int n, int i)
{
    int val = pow(2, i); // equivalent to (1 << i)
    if (((n / val) % 2) == 1)
    {
        n -= val; // subtract 2^i to turn bit OFF
    }
    return n;
}

/*
    ==============================================================================
    ⚡ APPROACH 2: Bit Manipulation (Optimized)
    ------------------------------------------------------------------------------
    ✅ Intuition:
        Use bitwise operations to directly clear the i-th bit.

        ----------------------------------------------------------------------
        🧩 METHOD 1: LEFT SHIFT + BIT MASKING
        ----------------------------------------------------------------------
        - Create a mask with only the i-th bit set: mask = (1 << i)
        - Take the complement (~mask) → all bits are 1 except the i-th bit (0)
        - Perform bitwise AND (&) with n:
              n & (~mask)
        - This clears the i-th bit without affecting others.

        ✅ Example:
            n = 13 (1101)
            i = 2
            mask = 1 << 2 = 0100
            ~mask = 1011
            n & (~mask) = 1101 & 1011 = 1001 → 9

        ✅ Pseudocode:
            function clearIthBit_LeftShift(n, i):
                mask = 1 << i
                return n & (~mask)

        ✅ Time Complexity:  O(1)
        ✅ Space Complexity: O(1)

        ----------------------------------------------------------------------
        🧩 METHOD 2: RIGHT SHIFT (Conceptual Demonstration)
        ----------------------------------------------------------------------
        - Shift n right by i bits → brings i-th bit to LSB.
        - Clear the LSB using AND with (~1).
        - Shift it back left by i bits and reconstruct the number.

        ✅ Example:
            n = 13 (1101), i = 2
            n >> 2 → 0011
            clear LSB: 0011 & (~0001) = 0010
            (n & (~(1<<i))) | (0010 << i) → 1001 (9)

        ✅ Pseudocode:
            function clearIthBit_RightShift(n, i):
                shifted = n >> i
                shifted = shifted & (~1)
                n = (n & (~(1 << i))) | (shifted << i)
                return n

        ✅ Time Complexity:  O(1)
        ✅ Space Complexity: O(1)
    ==============================================================================
*/

// 🧩 Method 1: Left Shift + Bit Masking (Most common & clean)
int clearIthBit_LeftShift(int n, int i)
{
    // Step 1: Create a mask with only the i-th bit set
    int mask = 1 << i;

    // Step 2: Invert mask so that i-th bit becomes 0, rest 1
    // Step 3: AND with n to clear that bit
    return n & (~mask);
}

// 🧩 Method 2: Right Shift (Conceptual way)
int clearIthBit_RightShift(int n, int i)
{
    // Step 1: Move i-th bit to the rightmost position
    int shifted = n >> i;

    // Step 2: Clear LSB (if it was 1)
    shifted = shifted & (~1);

    // Step 3: Clear the original i-th bit and set new shifted bits back
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
    int n1 = 13, i1 = 2;
    cout << "=========================================\n";
    cout << "Example 1: n = " << n1 << ", i = " << i1 << endl;
    cout << "Binary of n: " << bitset<8>(n1) << endl;

    // Brute Force Method
    cout << "Brute Force Result: " << clearIthBit_BruteForce(n1, i1)
         << " (Binary: " << bitset<8>(clearIthBit_BruteForce(n1, i1)) << ")\n";

    // Left Shift Method
    cout << "Left Shift Method Result: " << clearIthBit_LeftShift(n1, i1)
         << " (Binary: " << bitset<8>(clearIthBit_LeftShift(n1, i1)) << ")\n";

    // Right Shift Method
    cout << "Right Shift Method Result: " << clearIthBit_RightShift(n1, i1)
         << " (Binary: " << bitset<8>(clearIthBit_RightShift(n1, i1)) << ")\n";

    cout << "-----------------------------------------\n";

    int n2 = 10, i2 = 1;
    cout << "Example 2: n = " << n2 << ", i = " << i2 << endl;
    cout << "Binary of n: " << bitset<8>(n2) << endl;

    cout << "Brute Force Result: " << clearIthBit_BruteForce(n2, i2)
         << " (Binary: " << bitset<8>(clearIthBit_BruteForce(n2, i2)) << ")\n";

    cout << "Left Shift Method Result: " << clearIthBit_LeftShift(n2, i2)
         << " (Binary: " << bitset<8>(clearIthBit_LeftShift(n2, i2)) << ")\n";

    cout << "Right Shift Method Result: " << clearIthBit_RightShift(n2, i2)
         << " (Binary: " << bitset<8>(clearIthBit_RightShift(n2, i2)) << ")\n";

    /*
        ==============================================================================
        ✅ SAMPLE OUTPUT:
        ----------------------------------------
        Example 1: n = 13, i = 2
        Binary of n: 00001101
        Brute Force Result: 9 (Binary: 00001001)
        Left Shift Method Result: 9 (Binary: 00001001)
        Right Shift Method Result: 9 (Binary: 00001001)

        Example 2: n = 10, i = 1
        Binary of n: 00001010
        Brute Force Result: 8 (Binary: 00001000)
        Left Shift Method Result: 8 (Binary: 00001000)
        Right Shift Method Result: 8 (Binary: 00001000)
        ==============================================================================
    */

    return 0;
}

/*
    ==============================================================================
    🧮 COMPLEXITY SUMMARY
    ------------------------------------------------------------------------------
    | Approach  | Technique             | Time Complexity | Space Complexity | Notes              |
    |------------|----------------------|------------------|------------------|--------------------|
    | BruteForce | Math (Subtract 2^i)  | O(1)             | O(1)             | Conceptually simple|
    | LeftShift  | Mask + AND (~mask)   | O(1)             | O(1)             | Most efficient     |
    | RightShift | Bitwise shift logic  | O(1)             | O(1)             | For demonstration  |
    ------------------------------------------------------------------------------
    🏁 Final Verdict:
        ✅ Use Left Shift + AND with (~mask) in practice.
        🧠 Right Shift method helps understand bit movement conceptually.
    ==============================================================================
*/
