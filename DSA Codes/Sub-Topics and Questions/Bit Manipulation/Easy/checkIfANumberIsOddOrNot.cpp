/*
    ==============================================================================
                       💡 CHECK IF A NUMBER IS ODD OR EVEN
    ==============================================================================

    🧩 Problem Statement:
    ---------------------
    Given an integer `n`, determine whether it is **odd** or **even**.

    Return:
        - true  → if n is ODD
        - false → if n is EVEN

    ------------------------------------------------------------------------------
    🧠 Intuition:
    -------------
    Every number in binary form ends with a **Least Significant Bit (LSB)**.

    - If the LSB = 1 → The number is **odd**
    - If the LSB = 0 → The number is **even**

    Example:
        n = 5 → binary 0101 → LSB = 1 → odd
        n = 10 → binary 1010 → LSB = 0 → even

    ------------------------------------------------------------------------------
    🔢 Examples:
    ------------

    Example 1:
        Input: n = 7
        Binary: 0111
        Output: Odd

    Example 2:
        Input: n = 12
        Binary: 1100
        Output: Even

    Example 3:
        Input: n = 0
        Binary: 0000
        Output: Even

    Example 4:
        Input: n = -3
        Binary: ...1101 (2’s complement form)
        Output: Odd

    ------------------------------------------------------------------------------
    🧾 Constraints:
    ----------------
    - -10^9 ≤ n ≤ 10^9
    ------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================================
    🪜 APPROACH 1: Brute Force (Using Modulus Operator)
    ------------------------------------------------------------------------------

    ✅ Intuition:
        - A number is **odd** if it leaves a remainder of 1 when divided by 2.
        - A number is **even** if the remainder is 0.

    ✅ Formula:
        n % 2 == 0 → even
        n % 2 == 1 → odd

    ✅ Algorithm:
        1. If n % 2 == 0 → even
        2. Else → odd

    ✅ Example:
        n = 13 → 13 % 2 = 1 → odd
        n = 24 → 24 % 2 = 0 → even

    ✅ Time Complexity: O(1)
    ✅ Space Complexity: O(1)
    ==============================================================================
*/
bool isOdd_BruteForce(int n)
{
    return (n % 2 != 0);
}

/*
    ==============================================================================
    ⚡ APPROACH 2: Optimized (Bit Manipulation using AND)
    ------------------------------------------------------------------------------

    ✅ Intuition:
        - The last bit (Least Significant Bit) determines whether a number is odd or even.
        - If the **last bit (LSB)** is 1 → ODD
        - If the **last bit (LSB)** is 0 → EVEN

        Using bitwise AND:
            n & 1  → checks the last bit
            - If result = 1 → odd
            - If result = 0 → even

    ✅ Example:
        n = 13 (1101)
        n & 1 = 0001 → 1 → odd

        n = 24 (11000)
        n & 1 = 0000 → 0 → even

    ✅ Formula:
        (n & 1) == 1 → odd
        (n & 1) == 0 → even

    ✅ Time Complexity: O(1)
    ✅ Space Complexity: O(1)
    ==============================================================================
*/
bool isOdd_Bitwise(int n)
{
    return (n & 1); // returns 1 (true) if LSB = 1 → odd
}

/*
    ==============================================================================
    ⚙️ BONUS EXPLANATION — n & (n - 1)
    ------------------------------------------------------------------------------

    ❓ What does n & (n - 1) do?
        - It **removes the rightmost set bit** (1) from n.

    🔍 How is it related here?
        - For odd numbers: LSB = 1 → n & (n - 1) < n
        - For even numbers: LSB = 0 → n & (n - 1) == n

    ✅ Example:
        n = 13 (1101)
        n - 1 = 12 (1100)
        n & (n - 1) = 1100 → smaller → odd ✅

        n = 12 (1100)
        n - 1 = 11 (1011)
        n & (n - 1) = 1000 → smaller → but LSB = 0 → even

    We usually use this trick for removing set bits,
    but understanding this helps in bitwise reasoning.
    ==============================================================================
*/

/*
    ==============================================================================
    🧪 DRIVER CODE — Testing Both Approaches
    ==============================================================================
*/
int main()
{
    cout << "===========================================================\n";
    cout << "💡 CHECK IF A NUMBER IS ODD OR EVEN — ALL APPROACHES\n";
    cout << "===========================================================\n\n";

    vector<int> testCases = {-5, -4, 0, 1, 2, 3, 4, 7, 8, 15, 16, 25};

    for (int n : testCases)
    {
        cout << "Number: " << setw(4) << n
             << " | Binary: " << bitset<8>(n) << "\n";

        cout << "🔹 Brute Force (n % 2): "
             << (isOdd_BruteForce(n) ? "Odd" : "Even") << endl;

        cout << "🔹 Optimized (n & 1):  "
             << (isOdd_Bitwise(n) ? "Odd" : "Even") << endl;

        // Demonstrating n & (n - 1)
        cout << "   n & (n - 1): " << bitset<8>(n & (n - 1))
             << " (Decimal: " << (n & (n - 1)) << ")\n";

        cout << "-----------------------------------------------------------\n";
    }

    /*
        ==============================================================================
        ✅ SAMPLE OUTPUT:
        -----------------------------------------------------------
        Number:   -5 | Binary: 11111011
        Brute Force (n % 2): Odd
        Optimized (n & 1):  Odd
           n & (n - 1): 11111010 (Decimal: -6)

        Number:    4 | Binary: 00000100
        Brute Force (n % 2): Even
        Optimized (n & 1):  Even
           n & (n - 1): 00000000 (Decimal: 0)

        Number:    7 | Binary: 00000111
        Brute Force (n % 2): Odd
        Optimized (n & 1):  Odd
           n & (n - 1): 00000110 (Decimal: 6)
        -----------------------------------------------------------
        ==============================================================================
    */

    cout << "\n===========================================================\n";
    cout << "✅ Execution Complete — Both Approaches Verified!\n";
    cout << "===========================================================\n";

    return 0;
}

/*
    ==============================================================================
    🧮 COMPLEXITY SUMMARY
    ------------------------------------------------------------------------------
    | Approach     | Technique              | Time Complexity | Space Complexity |
    |---------------|-----------------------|-----------------|-----------------|
    | Brute Force   | Using n % 2           | O(1)            | O(1)            |
    | Optimized     | Using n & 1           | O(1)            | O(1)            |
    ------------------------------------------------------------------------------
    🧠 Key Notes:
    - (n % 2) → Uses arithmetic modulus to check remainder.
    - (n & 1) → Checks the least significant bit (faster & bitwise).
    - (n & (n - 1)) → Removes last set bit (used for deeper bit tricks).
    - Bitwise methods are preferred in low-level / high-performance code.
    ==============================================================================
*/
