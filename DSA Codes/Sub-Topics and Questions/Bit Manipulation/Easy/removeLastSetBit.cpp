/*
    ==============================================================================
                        💡 REMOVE THE LAST (RIGHTMOST) SET BIT
    ==============================================================================

    🧩 Problem Statement:
    ---------------------
    Given an integer `n`, remove (turn OFF) the rightmost set bit (1) in its binary
    representation and return the resulting number.

    - "Rightmost set bit" means the **lowest-order 1-bit** in binary from the LSB side.
    - If `n` has no set bits (i.e., n == 0), the result remains 0.

    ------------------------------------------------------------------------------
    🧠 Example Intuition:
    ---------------------
    The operation effectively removes the last 1 in binary form.

    Example 1:
        Input: n = 12
        Binary: 1100
        Rightmost set bit = 0100 (2nd position)
        Result = 1100 - 0100 = 1000 (8)
        Output: 8

    Example 2:
        Input: n = 10
        Binary: 1010
        Rightmost set bit = 0010 (bit at position 1)
        Result = 1010 - 0010 = 1000
        Output: 8

    Example 3:
        Input: n = 7
        Binary: 0111
        Remove rightmost set bit → 0110 → 6
        Output: 6

    ------------------------------------------------------------------------------
    🧾 Constraints:
    ----------------
    - 0 ≤ n ≤ 10^9
    ------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================================
    🪜 APPROACH 1: Brute Force (Manual Binary Check)
    ------------------------------------------------------------------------------

    ✅ Intuition:
        - Find the position of the **rightmost set bit** manually.
        - Once found, subtract its value (2^position) from the number.

    ✅ Algorithm:
        1. If n == 0 → return 0.
        2. Find the index (i) of the first 1 from the right:
             while ((n >> i) & 1) == 0 → increment i
        3. Compute value = (1 << i)
        4. Subtract that value from n → removes that bit.

    ✅ Example:
        n = 10 (1010)
        Rightmost set bit at i = 1 → 2^1 = 2
        Result = 10 - 2 = 8 (1000)

    ✅ Time Complexity: O(log n)
    ✅ Space Complexity: O(1)
    ==============================================================================
*/
int removeLastSetBit_BruteForce(int n)
{
    if (n == 0)
        return 0;

    int i = 0;

    // Find the first 1-bit from right
    while (((n >> i) & 1) == 0)
        i++;

    // Subtract 2^i to turn off that bit
    return n - (1 << i);
}

/*
    ==============================================================================
    ⚡ APPROACH 2: Optimized (Bit Manipulation using LEFT SHIFT Logic)
    ------------------------------------------------------------------------------

    ✅ Intuition:
        - The simplest and most elegant formula to remove the last set bit:
              n = n & (n - 1)
        - Subtracting 1 from n flips all bits after the rightmost 1 (including that 1).
          ANDing it with n clears that bit.

    ✅ Example:
        n = 10 (1010)
        n - 1 = 9 (1001)
        n & (n - 1) = 1000 = 8

    ✅ Steps:
        1. If n == 0 → return 0
        2. Return n & (n - 1)

    ✅ Time Complexity: O(1)
    ✅ Space Complexity: O(1)
    ==============================================================================
*/
int removeLastSetBit_LeftShift(int n)
{
    if (n == 0)
        return 0;
    return n & (n - 1);
}

/*
    ==============================================================================
    ⚙️ APPROACH 3: Right Shift (Conceptual Method)
    ------------------------------------------------------------------------------

    ✅ Intuition:
        - Conceptually isolate and remove the lowest set bit using masking:
            1. Identify rightmost 1-bit → `n & -n` (gives mask of last set bit)
            2. XOR with original → toggles (removes) that bit.

        Example:
            n = 10 (1010)
            n & -n = 0010  (rightmost 1)
            n ^ (n & -n) = 1000 → removes last set bit.

    ✅ Formula:
        result = n ^ (n & -n)

    ✅ Time Complexity: O(1)
    ✅ Space Complexity: O(1)
    ==============================================================================
*/
int removeLastSetBit_RightShift(int n)
{
    if (n == 0)
        return 0;

    return n ^ (n & -n);
}

/*
    ==============================================================================
    🧪 DRIVER CODE (Testing All Approaches)
    ==============================================================================
*/
int main()
{
    cout << "=============================================================\n";
    cout << "💡 REMOVE THE LAST (RIGHTMOST) SET BIT — All Approaches\n";
    cout << "=============================================================\n\n";

    // Example 1
    int n1 = 12;
    cout << "Example 1: n = " << n1 << endl;
    cout << "Binary of n: " << bitset<8>(n1) << endl;
    cout << "Brute Force Result: " << removeLastSetBit_BruteForce(n1)
         << " (Binary: " << bitset<8>(removeLastSetBit_BruteForce(n1)) << ")\n";
    cout << "Left Shift Optimized Result: " << removeLastSetBit_LeftShift(n1)
         << " (Binary: " << bitset<8>(removeLastSetBit_LeftShift(n1)) << ")\n";
    cout << "Right Shift Optimized Result: " << removeLastSetBit_RightShift(n1)
         << " (Binary: " << bitset<8>(removeLastSetBit_RightShift(n1)) << ")\n\n";

    // Example 2
    int n2 = 10;
    cout << "Example 2: n = " << n2 << endl;
    cout << "Binary of n: " << bitset<8>(n2) << endl;
    cout << "Brute Force Result: " << removeLastSetBit_BruteForce(n2)
         << " (Binary: " << bitset<8>(removeLastSetBit_BruteForce(n2)) << ")\n";
    cout << "Left Shift Optimized Result: " << removeLastSetBit_LeftShift(n2)
         << " (Binary: " << bitset<8>(removeLastSetBit_LeftShift(n2)) << ")\n";
    cout << "Right Shift Optimized Result: " << removeLastSetBit_RightShift(n2)
         << " (Binary: " << bitset<8>(removeLastSetBit_RightShift(n2)) << ")\n\n";

    // Example 3
    int n3 = 7;
    cout << "Example 3: n = " << n3 << endl;
    cout << "Binary of n: " << bitset<8>(n3) << endl;
    cout << "Brute Force Result: " << removeLastSetBit_BruteForce(n3)
         << " (Binary: " << bitset<8>(removeLastSetBit_BruteForce(n3)) << ")\n";
    cout << "Left Shift Optimized Result: " << removeLastSetBit_LeftShift(n3)
         << " (Binary: " << bitset<8>(removeLastSetBit_LeftShift(n3)) << ")\n";
    cout << "Right Shift Optimized Result: " << removeLastSetBit_RightShift(n3)
         << " (Binary: " << bitset<8>(removeLastSetBit_RightShift(n3)) << ")\n";

    /*
        ==============================================================================
        ✅ SAMPLE OUTPUT:
        ---------------------------------------------
        Example 1: n = 12
        Binary of n: 00001100
        Brute Force Result: 8 (Binary: 00001000)
        Left Shift Optimized Result: 8 (Binary: 00001000)
        Right Shift Optimized Result: 8 (Binary: 00001000)

        Example 2: n = 10
        Binary of n: 00001010
        Brute Force Result: 8 (Binary: 00001000)
        Left Shift Optimized Result: 8 (Binary: 00001000)
        Right Shift Optimized Result: 8 (Binary: 00001000)

        Example 3: n = 7
        Binary of n: 00000111
        Brute Force Result: 6 (Binary: 00000110)
        Left Shift Optimized Result: 6 (Binary: 00000110)
        Right Shift Optimized Result: 6 (Binary: 00000110)
        ==============================================================================
    */

    cout << "\n=============================================================\n";
    cout << "✅ Execution Complete — All Approaches Tested!\n";
    cout << "=============================================================\n";

    return 0;
}

/*
    ==============================================================================
    🧮 COMPLEXITY SUMMARY
    ------------------------------------------------------------------------------
    | Approach     | Technique              | Time Complexity | Space Complexity |
    |---------------|-----------------------|-----------------|-----------------|
    | Brute Force   | Manual Binary Search  | O(log n)        | O(1)            |
    | Left Shift    | n & (n - 1) Trick     | O(1)            | O(1)            |
    | Right Shift   | n ^ (n & -n) Concept  | O(1)            | O(1)            |
    ------------------------------------------------------------------------------
    🧠 Key Takeaways:
    - n & (n - 1) is the **fastest** and most elegant way to clear the lowest set bit.
    - n ^ (n & -n) is an alternate XOR-based trick that achieves the same effect.
    - Brute Force helps understand how bit positions work manually.
    ==============================================================================
*/
