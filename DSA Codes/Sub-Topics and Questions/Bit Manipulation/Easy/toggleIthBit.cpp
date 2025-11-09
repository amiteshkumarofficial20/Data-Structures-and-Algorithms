/*
    ==============================================================================
                             🔁 TOGGLE THE i-th BIT OF A NUMBER
    ==============================================================================

    🧩 Problem Statement:
    ---------------------
    Given two integers `n` and `i`, toggle (flip) the i-th bit of `n`
    (0-indexed from the Least Significant Bit, i.e., LSB).

    - If the i-th bit is 0 → turn it into 1.
    - If the i-th bit is 1 → turn it into 0.

    Return the updated number after toggling the bit.

    ------------------------------------------------------------------------------
    🧠 Intuition:
    -------------
    Toggling means **flipping** a bit.
    Example: 0 → 1, and 1 → 0.

    ------------------------------------------------------------------------------
    🔢 Examples:
    ------------

    Example 1:
        Input: n = 5, i = 1
        Binary of 5: 0101
        Toggle bit at index 1 → 0111
        Output: 7

    Example 2:
        Input: n = 10, i = 3
        Binary of 10: 1010
        Toggle bit at index 3 → 0010
        Output: 2

    ------------------------------------------------------------------------------
    🧾 Constraints:
    ----------------
    - 0 ≤ n ≤ 10^9
    - 0 ≤ i ≤ 31  (for 32-bit integer)
    ------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================================
    🪜 APPROACH 1: Brute Force (Binary Representation Method)
    ------------------------------------------------------------------------------

    ✅ Intuition:
        - Consider each bit as representing powers of 2.
        - The i-th bit corresponds to the value 2^i.
        - If the i-th bit is set (1), subtract 2^i.
        - If the i-th bit is not set (0), add 2^i.

    ✅ Algorithm:
        1. Compute `power = 2^i` (use 1 << i).
        2. Check if the i-th bit is 1 using ((n >> i) & 1).
        3. If it's 1 → subtract `power`.
           Else → add `power`.
        4. Return the updated number.

    ✅ Example:
        n = 5 (0101), i = 1
        (n >> 1) & 1 → 0 (bit not set)
        Add (1 << 1) = 2 → 5 + 2 = 7 → 0111

    ✅ Time Complexity: O(1)
    ✅ Space Complexity: O(1)
    ==============================================================================
*/
int toggleIthBit_BruteForce(int n, int i)
{
    int power = (1 << i); // 2^i

    // Check whether i-th bit is currently set
    if (((n >> i) & 1) == 1)
        n -= power; // If bit is 1 → turn it off
    else
        n += power; // If bit is 0 → turn it on

    return n;
}

/*
    ==============================================================================
    ⚡ APPROACH 2: Optimized Bit Manipulation (Using XOR)
    ------------------------------------------------------------------------------

    ✅ Intuition:
        - XOR (^) flips a bit when we XOR it with 1.
        - So if we XOR `n` with `(1 << i)`, the i-th bit toggles automatically:
            n ^ (1 << i)

    ✅ Example:
        n = 5 (0101)
        i = 1
        (1 << i) = 0010
        n ^ (1 << i) = 0111 = 7

    ✅ Formula:
        result = n ^ (1 << i)

    ✅ Time Complexity: O(1)
    ✅ Space Complexity: O(1)
    ==============================================================================
*/
int toggleIthBit_LeftShift(int n, int i)
{
    return n ^ (1 << i); // XOR toggles the i-th bit
}

/*
    ==============================================================================
    ⚙️ APPROACH 3: Right Shift (Conceptual Variant)
    ------------------------------------------------------------------------------

    ✅ Intuition:
        - Move the i-th bit to the least significant position (LSB) using right shift.
        - Flip it using XOR with 1.
        - Restore the bit to its original position using left shift.

    ✅ Steps:
        1. Extract i-th bit to LSB position: (n >> i)
        2. Toggle it: ^ 1
        3. Insert back into the original number.

    ✅ Implementation:
        - Create a mask with only the i-th bit set.
        - Use XOR (^) with this mask → flips only that bit.

    ✅ Time Complexity: O(1)
    ✅ Space Complexity: O(1)
    ==============================================================================
*/
int toggleIthBit_RightShift(int n, int i)
{
    int mask = (1 << i); // Mask with only i-th bit set
    return n ^ mask;     // XOR toggles that specific bit
}

/*
    ==============================================================================
    🧪 DRIVER CODE (Testing All Approaches)
    ==============================================================================
*/
int main()
{
    cout << "=============================================\n";
    cout << "🔁 Toggle i-th Bit of a Number\n";
    cout << "=============================================\n\n";

    // Example 1
    int n1 = 5, i1 = 1;
    cout << "Example 1: n = " << n1 << ", i = " << i1 << endl;
    cout << "Binary of n: " << bitset<8>(n1) << endl;
    cout << "Brute Force Result: " << toggleIthBit_BruteForce(n1, i1)
         << " (Binary: " << bitset<8>(toggleIthBit_BruteForce(n1, i1)) << ")\n";
    cout << "Left Shift XOR Result: " << toggleIthBit_LeftShift(n1, i1)
         << " (Binary: " << bitset<8>(toggleIthBit_LeftShift(n1, i1)) << ")\n";
    cout << "Right Shift XOR Result: " << toggleIthBit_RightShift(n1, i1)
         << " (Binary: " << bitset<8>(toggleIthBit_RightShift(n1, i1)) << ")\n";

    cout << "\n---------------------------------------------\n";

    // Example 2
    int n2 = 10, i2 = 3;
    cout << "Example 2: n = " << n2 << ", i = " << i2 << endl;
    cout << "Binary of n: " << bitset<8>(n2) << endl;
    cout << "Brute Force Result: " << toggleIthBit_BruteForce(n2, i2)
         << " (Binary: " << bitset<8>(toggleIthBit_BruteForce(n2, i2)) << ")\n";
    cout << "Left Shift XOR Result: " << toggleIthBit_LeftShift(n2, i2)
         << " (Binary: " << bitset<8>(toggleIthBit_LeftShift(n2, i2)) << ")\n";
    cout << "Right Shift XOR Result: " << toggleIthBit_RightShift(n2, i2)
         << " (Binary: " << bitset<8>(toggleIthBit_RightShift(n2, i2)) << ")\n";

    /*
        ==============================================================================
        ✅ SAMPLE OUTPUT:
        ---------------------------------------------
        Example 1: n = 5, i = 1
        Binary of n: 00000101
        Brute Force Result: 7 (Binary: 00000111)
        Left Shift XOR Result: 7 (Binary: 00000111)
        Right Shift XOR Result: 7 (Binary: 00000111)

        Example 2: n = 10, i = 3
        Binary of n: 00001010
        Brute Force Result: 2 (Binary: 00000010)
        Left Shift XOR Result: 2 (Binary: 00000010)
        Right Shift XOR Result: 2 (Binary: 00000010)
        ==============================================================================
    */

    cout << "\n=============================================\n";
    cout << "✅ Execution Complete — All Approaches Tested!\n";
    cout << "=============================================\n";

    return 0;
}

/*
    ==============================================================================
    🧮 COMPLEXITY SUMMARY
    ------------------------------------------------------------------------------
    | Approach     | Technique               | Time Complexity | Space Complexity |
    |---------------|------------------------|-----------------|-----------------|
    | Brute Force   | Binary & Math (2^i)    | O(1)            | O(1)            |
    | Left Shift    | XOR Bit Mask           | O(1)            | O(1)            |
    | Right Shift   | Masking + XOR          | O(1)            | O(1)            |
    ------------------------------------------------------------------------------
    🧠 Key Takeaways:
    - XOR (^) toggles bits efficiently.
    - Both Left Shift & Right Shift methods are equivalent.
    - Brute force is intuitive but less elegant.
    - Works for all valid (n, i) within 32-bit integers.
    ==============================================================================
*/
