/*
    ============================================================================
                            🧮 SWAP TWO NUMBERS
    ============================================================================

    🔹 Problem Statement:
    ---------------------
    Given two integers 'a' and 'b', swap their values in-place so that:
        - After swapping, 'a' should contain the value of 'b'
        - 'b' should contain the value of 'a'
    You must perform the swap using only two variables, without using extra memory.

    ---------------------------------------------------------------------------
    🔹 Example 1:
        Input:  a = 5, b = 10
        Output: a = 10, b = 5

    🔹 Example 2:
        Input:  a = -100, b = -200
        Output: a = -200, b = -100

    ---------------------------------------------------------------------------
    🔹 Constraints:
        - Integers can be positive, negative, or zero.
        - Must use only O(1) space.
        - Must not use built-in swap functions.

    ---------------------------------------------------------------------------
    🔹 We’ll Implement Two Approaches:
        1️⃣ Using a Temporary Variable (Classic Method)
        2️⃣ Using Bitwise XOR (No Extra Variable)
    ---------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/*
    ============================================================================
    🧩 APPROACH 1: Using a Temporary Variable
    ----------------------------------------------------------------------------
    ✅ Intuition:
       - Store one variable in a temporary variable.
       - Assign 'a' with 'b'.
       - Assign 'b' with the stored temporary value.

    ✅ Algorithm:
        Step 1: temp = a
        Step 2: a = b
        Step 3: b = temp

    ✅ Pseudocode:
        function swapTemp(a, b):
            temp = a
            a = b
            b = temp
            return a, b

    ✅ Time Complexity:  O(1)
    ✅ Space Complexity: O(1)   (uses 1 extra variable)
    ============================================================================
*/
void swapTemp(int &a, int &b)
{
    // Step 1: Store the value of 'a' in a temporary variable
    int temp = a;

    // Step 2: Assign the value of 'b' to 'a'
    a = b;

    // Step 3: Assign the stored 'temp' (original 'a') to 'b'
    b = temp;
}

/*
    ============================================================================
    🧩 APPROACH 2: Using XOR Bit Manipulation (No Extra Variable)
    ----------------------------------------------------------------------------
    ✅ Intuition:
       - XOR (^) is a bitwise operator that follows:
            a ^ a = 0
            a ^ 0 = a
       - The operation can be reversed to extract the original values.

    ✅ Algorithm:
        Step 1: a = a ^ b
        Step 2: b = a ^ b   (b becomes original 'a')
        Step 3: a = a ^ b   (a becomes original 'b')

    ✅ Example:
        Let a = 5 (0101), b = 10 (1010)
        Step 1: a = a ^ b = 1111 (15)
        Step 2: b = a ^ b = 1111 ^ 1010 = 0101 (5)
        Step 3: a = a ^ b = 1111 ^ 0101 = 1010 (10)
        Result: a = 10, b = 5 ✅

    ✅ Time Complexity:  O(1)
    ✅ Space Complexity: O(1)
    ============================================================================
*/
void swapXOR(int &a, int &b)
{
    // Step 1: Perform XOR and assign to 'a'
    a = a ^ b;

    // Step 2: XOR 'a' (which holds a^b) with 'b' → gives original 'a'
    b = a ^ b;

    // Step 3: XOR 'a' (which holds a^b) with new 'b' (original 'a') → gives original 'b'
    a = a ^ b;
}

/*
    ============================================================================
    🧪 DRIVER CODE
    ============================================================================
*/
int main()
{
    // Example 1: Using Temporary Variable Method
    cout << "==============================" << endl;
    cout << "Approach 1: Using Temporary Variable" << endl;
    cout << "==============================" << endl;

    int a1 = 5, b1 = 10;
    cout << "Before Swap: a = " << a1 << ", b = " << b1 << endl;

    swapTemp(a1, b1);

    cout << "After Swap:  a = " << a1 << ", b = " << b1 << endl
         << endl;

    // Example 2: Using XOR Bitwise Method
    cout << "==============================" << endl;
    cout << "Approach 2: Using XOR Bit Manipulation" << endl;
    cout << "==============================" << endl;

    int a2 = 5, b2 = 10;
    cout << "Before Swap: a = " << a2 << ", b = " << b2 << endl;

    swapXOR(a2, b2);

    cout << "After Swap:  a = " << a2 << ", b = " << b2 << endl
         << endl;

    /*
        ============================================================================
        ✅ OUTPUT:
        -----------------------------
        Approach 1: Using Temporary Variable
        Before Swap: a = 5, b = 10
        After Swap:  a = 10, b = 5

        Approach 2: Using XOR Bit Manipulation
        Before Swap: a = 5, b = 10
        After Swap:  a = 10, b = 5
        ============================================================================
    */

    return 0;
}

/*
    ============================================================================
    🧮 COMPLEXITY SUMMARY
    ----------------------------------------------------------------------------
    | Approach | Technique           | Time Complexity | Space Complexity | Extra Var |
    |-----------|--------------------|------------------|------------------|------------|
    | 1         | Temporary Variable | O(1)             | O(1)             | Yes (temp) |
    | 2         | XOR Bit Manip.     | O(1)             | O(1)             | No         |
    ----------------------------------------------------------------------------
    🏁 Conclusion:
    - Both achieve the same result in constant time.
    - XOR approach avoids extra variable but can be less readable.
    ============================================================================
*/
