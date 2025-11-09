/*
    ==============================================================================
                           ⚡ CHECK IF A NUMBER IS POWER OF 2
    ==============================================================================

    🧩 Problem Statement:
    ---------------------
    Given an integer `n`, determine whether it is a **power of 2**.

    Return:
        - true  → if n is a power of 2
        - false → otherwise

    ------------------------------------------------------------------------------
    🧠 Intuition:
    -------------
    A number is a power of 2 if it has **exactly one set bit (1)** in its binary form.

    For example:
        1  -> 0001 → true (2⁰)
        2  -> 0010 → true (2¹)
        4  -> 0100 → true (2²)
        8  -> 1000 → true (2³)
        10 -> 1010 → false (two set bits)

    ------------------------------------------------------------------------------
    🔢 Examples:
    ------------

    Example 1:
        Input: n = 1
        Output: true
        Explanation: 1 = 2⁰

    Example 2:
        Input: n = 16
        Output: true
        Explanation: 16 = 2⁴

    Example 3:
        Input: n = 18
        Output: false
        Explanation: 18 = 10010 (has more than one set bit)

    Example 4:
        Input: n = 0
        Output: false (0 is not a power of 2)

    ------------------------------------------------------------------------------
    🧾 Constraints:
    ----------------
    - -2³¹ ≤ n ≤ 2³¹ - 1
    ------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================================
    🪜 APPROACH 1: Brute Force (Repeated Division)
    ------------------------------------------------------------------------------

    ✅ Intuition:
        - A number n is a power of 2 if it can be repeatedly divided by 2
          until we get 1, and at no point does it produce a remainder.

        Example:
            n = 16
            16 → 8 → 4 → 2 → 1 → ✅ Power of 2

            n = 18
            18 → 9 → ❌ Not divisible by 2 cleanly → false

    ✅ Algorithm:
        1. If n ≤ 0 → false (negative and zero aren’t powers of 2)
        2. While n is divisible by 2:
            Divide n by 2.
        3. After the loop, if n == 1 → true; else → false.

    ✅ Time Complexity: O(log₂ n)
        (because we divide by 2 each step)
    ✅ Space Complexity: O(1)
    ==============================================================================
*/
bool isPowerOfTwo_BruteForce(int n)
{
    if (n <= 0)
        return false;

    while (n % 2 == 0)
        n /= 2;

    return (n == 1);
}

/*
    ==============================================================================
    ⚡ APPROACH 2: Optimized (Bit Manipulation)
    ------------------------------------------------------------------------------

    ✅ Intuition:
        - Power of 2 numbers have **only one set bit** in their binary representation.
        - Example:
            1  = 0001
            2  = 0010
            4  = 0100
            8  = 1000
        - Trick:
            n & (n - 1) == 0  ⇒  n is a power of 2 (if n > 0)

        Why it works:
        -------------
        Subtracting 1 from n flips all bits after the rightmost set bit, including it.
        ANDing clears that bit, giving 0 only when exactly one bit was set.

        Example:
            n = 8 (1000)
            n - 1 = 7 (0111)
            n & (n - 1) = 1000 & 0111 = 0000 → ✅ Power of 2

    ✅ Algorithm:
        1. Check if n > 0
        2. Return true if (n & (n - 1)) == 0, else false

    ✅ Time Complexity: O(1)
    ✅ Space Complexity: O(1)
    ==============================================================================
*/
bool isPowerOfTwo_Optimized(int n)
{
    if (n <= 0)
        return false;

    return (n & (n - 1)) == 0;
}

/*
    ==============================================================================
    🧪 DRIVER CODE (Testing Both Approaches)
    ==============================================================================
*/
int main()
{
    cout << "===========================================================\n";
    cout << "💡 CHECK IF A NUMBER IS A POWER OF 2\n";
    cout << "===========================================================\n\n";

    vector<int> testCases = {1, 2, 3, 4, 5, 8, 16, 18, 32, 0, -8};

    for (int n : testCases)
    {
        cout << "Number: " << n << " (Binary: " << bitset<8>(n) << ")\n";

        cout << "Brute Force Result: "
             << (isPowerOfTwo_BruteForce(n) ? "✅ True" : "❌ False") << endl;

        cout << "Optimized (Bit Manipulation) Result: "
             << (isPowerOfTwo_Optimized(n) ? "✅ True" : "❌ False") << endl;

        cout << "-------------------------------------------\n";
    }

    /*
        ==============================================================================
        ✅ SAMPLE OUTPUT:
        -------------------------------------------
        Number: 1  (Binary: 00000001)
        Brute Force Result: ✅ True
        Optimized (Bit Manipulation) Result: ✅ True

        Number: 2  (Binary: 00000010)
        Brute Force Result: ✅ True
        Optimized (Bit Manipulation) Result: ✅ True

        Number: 3  (Binary: 00000011)
        Brute Force Result: ❌ False
        Optimized (Bit Manipulation) Result: ❌ False

        Number: 4  (Binary: 00000100)
        Brute Force Result: ✅ True
        Optimized (Bit Manipulation) Result: ✅ True

        Number: 18 (Binary: 00010010)
        Brute Force Result: ❌ False
        Optimized (Bit Manipulation) Result: ❌ False

        Number: 0  (Binary: 00000000)
        Brute Force Result: ❌ False
        Optimized (Bit Manipulation) Result: ❌ False

        Number: -8 (Binary: 11111000)
        Brute Force Result: ❌ False
        Optimized (Bit Manipulation) Result: ❌ False
        ==============================================================================
    */

    cout << "===========================================================\n";
    cout << "✅ Execution Complete — Both Approaches Tested Successfully!\n";
    cout << "===========================================================\n";

    return 0;
}

/*
    ==============================================================================
    🧮 COMPLEXITY SUMMARY
    ------------------------------------------------------------------------------
    | Approach     | Technique                | Time Complexity | Space Complexity |
    |---------------|--------------------------|-----------------|-----------------|
    | Brute Force   | Repeated Division by 2   | O(log₂ n)       | O(1)            |
    | Optimized     | Bit Manipulation (n&(n-1))| O(1)           | O(1)            |
    ------------------------------------------------------------------------------
    🧠 Key Takeaways:
    - Power of 2 ⇒ exactly one set bit.
    - Use n & (n-1) for quick detection.
    - Works only for positive integers.
    ==============================================================================
*/
