/*
    ==============================================================================
                      🧮 LeetCode Problem #29 — Divide Two Integers
    ==============================================================================

    🧩 Problem Statement:
    ---------------------
    Given two integers, `dividend` and `divisor`, perform integer division **without**
    using the multiplication (*), division (/), or modulo (%) operators.

    Return the **quotient** after dividing `dividend` by `divisor`.

    🔹 The integer division should truncate toward zero (discard fractional part).
    🔹 If the result overflows a 32-bit signed integer, return INT_MAX (2³¹ - 1).

    ------------------------------------------------------------------------------

    🧠 Constraints:
    ---------------
    - -2³¹ ≤ dividend, divisor ≤ 2³¹ - 1
    - divisor != 0

    ------------------------------------------------------------------------------

    🧾 Overflow Handling:
    ---------------------
    Since 32-bit integer range is:
        INT_MIN = -2³¹  = -2147483648
        INT_MAX =  2³¹-1 = 2147483647

    Division edge case:
        dividend = INT_MIN and divisor = -1
        → quotient = 2147483648 → overflow
        → return INT_MAX (per problem statement)
    ------------------------------------------------------------------------------

    🔢 Example Walkthroughs:
    ------------------------

    Example 1:
    ----------
        Input: dividend = 10, divisor = 3
        10 / 3 = 3.3333 → truncate → 3
        Output: 3

    Example 2:
    ----------
        Input: dividend = 7, divisor = -3
        7 / -3 = -2.333 → truncate → -2
        Output: -2

    Example 3:
    ----------
        Input: dividend = 0, divisor = 1
        Output: 0

    Example 4:
    ----------
        Input: dividend = 1, divisor = 1
        Output: 1

    Example 5:
    ----------
        Input: dividend = -2147483648, divisor = -1
        Output: 2147483647 (INT_MAX due to overflow)
    ------------------------------------------------------------------------------
*/

#include <iostream>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

/*
    ==============================================================================
    🪜 APPROACH 1: Brute Force (Repeated Subtraction)
    ------------------------------------------------------------------------------
    ✅ Intuition:
        Division can be thought of as repeatedly subtracting the divisor
        from the dividend until the dividend becomes smaller than divisor.
        The number of times subtraction happens = quotient.

    ✅ Algorithm Steps:
        1. Handle overflow case: if (dividend == INT_MIN && divisor == -1)
              → return INT_MAX
        2. Determine the final sign of the quotient:
              → If exactly one of (dividend, divisor) is negative → result negative.
        3. Work with absolute (positive) values for simplicity.
        4. Subtract divisor from dividend repeatedly.
        5. Count how many subtractions → quotient.
        6. Apply the sign and clamp result within 32-bit range.

    ✅ Time Complexity: O(|dividend / divisor|)
    ✅ Space Complexity: O(1)
    ==============================================================================
*/
int divideBruteForce(int dividend, int divisor)
{
    // Edge Case: Overflow condition
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    // Determine result sign (using XOR for differing signs)
    bool isNegative = (dividend < 0) ^ (divisor < 0);

    // Convert both to positive long long to prevent overflow
    long long absDividend = labs(dividend);
    long long absDivisor = labs(divisor);

    long long quotient = 0;

    // Repeated subtraction until dividend < divisor
    while (absDividend >= absDivisor)
    {
        absDividend -= absDivisor;
        quotient++;
    }

    // Apply the sign
    if (isNegative)
        quotient = -quotient;

    // Clamp to 32-bit signed integer range
    if (quotient > INT_MAX)
        return INT_MAX;
    if (quotient < INT_MIN)
        return INT_MIN;

    return (int)quotient;
}

/*
    ==============================================================================
    ⚡ APPROACH 2: Optimized (Bit Manipulation using Shifts)
    ------------------------------------------------------------------------------
    ✅ Intuition:
        Instead of subtracting divisor one by one, we can subtract it in powers of 2.
        Using left shifts (<<), we can efficiently determine how many times the divisor
        fits into the dividend.

    ✅ Algorithm Steps:
        1. Handle overflow edge case: (INT_MIN / -1)
        2. Determine result sign using XOR (negative if one operand negative)
        3. Convert dividend and divisor to positive long long
        4. While dividend >= divisor:
             a. Initialize temp = divisor, multiple = 1
             b. Keep doubling (temp <<= 1) while (temp << 1) ≤ dividend
             c. Subtract temp from dividend and add multiple to quotient
        5. Apply sign and clamp within 32-bit signed range.

    ✅ Example:
        dividend = 43, divisor = 5
        43 ≥ 5 → shift divisor:
            5, 10, 20, 40 → 40 fits into 43 → subtract
            dividend = 43 - 40 = 3
            quotient = 8
        remainder = 3 (ignored, since truncated)
        Final answer = 8

    ✅ Time Complexity: O(log(|dividend|))
    ✅ Space Complexity: O(1)
    ==============================================================================
*/
int divideOptimized(int dividend, int divisor)
{
    // Handle overflow case
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    // Determine the result's sign
    bool isNegative = (dividend < 0) ^ (divisor < 0);

    // Work with absolute long values
    long long absDividend = labs(dividend);
    long long absDivisor = labs(divisor);
    long long quotient = 0;

    // Bitwise division
    while (absDividend >= absDivisor)
    {
        long long temp = absDivisor;
        long long multiple = 1;

        // Find largest multiple such that (temp << 1) ≤ absDividend
        while ((temp << 1) <= absDividend)
        {
            temp <<= 1;     // Multiply divisor by 2
            multiple <<= 1; // Track power of 2
        }

        // Subtract largest multiple and add to quotient
        absDividend -= temp;
        quotient += multiple;
    }

    // Apply final sign
    if (isNegative)
        quotient = -quotient;

    // Clamp result within 32-bit range
    if (quotient > INT_MAX)
        return INT_MAX;
    if (quotient < INT_MIN)
        return INT_MIN;

    return (int)quotient;
}

/*
    ==============================================================================
    🧪 MAIN FUNCTION — Test Both Approaches
    ==============================================================================
*/
int main()
{
    cout << "=====================================================\n";
    cout << "           💡 LeetCode #29 — Divide Two Integers\n";
    cout << "=====================================================\n\n";

    // Test Cases
    int dividend1 = 10, divisor1 = 3;
    int dividend2 = 7, divisor2 = -3;
    int dividend3 = 0, divisor3 = 1;
    int dividend4 = 1, divisor4 = 1;
    int dividend5 = -2147483648, divisor5 = -1; // overflow case

    // Brute Force Tests
    cout << "🧩 Test Case 1: (Brute Force)\n";
    cout << "Input: dividend = " << dividend1 << ", divisor = " << divisor1 << endl;
    cout << "Output: " << divideBruteForce(dividend1, divisor1) << "\n\n";

    cout << "🧩 Test Case 2: (Brute Force)\n";
    cout << "Input: dividend = " << dividend2 << ", divisor = " << divisor2 << endl;
    cout << "Output: " << divideBruteForce(dividend2, divisor2) << "\n\n";

    // Optimized Tests
    cout << "🧩 Test Case 3: (Optimized)\n";
    cout << "Input: dividend = " << dividend3 << ", divisor = " << divisor3 << endl;
    cout << "Output: " << divideOptimized(dividend3, divisor3) << "\n\n";

    cout << "🧩 Test Case 4: (Optimized)\n";
    cout << "Input: dividend = " << dividend4 << ", divisor = " << divisor4 << endl;
    cout << "Output: " << divideOptimized(dividend4, divisor4) << "\n\n";

    cout << "🧩 Test Case 5: (Overflow Handling)\n";
    cout << "Input: dividend = " << dividend5 << ", divisor = " << divisor5 << endl;
    cout << "Output: " << divideOptimized(dividend5, divisor5) << "\n\n";

    cout << "=====================================================\n";
    cout << "✅ Execution Complete — Both Approaches Tested!\n";
    cout << "=====================================================\n";

    return 0;
}

/*
    ==============================================================================
    🧮 COMPLEXITY SUMMARY
    ------------------------------------------------------------------------------
    | Approach   | Description           | Time Complexity       | Space Complexity |
    |-------------|----------------------|------------------------|------------------|
    | Brute Force | Repeated Subtraction | O(|dividend/divisor|) | O(1)             |
    | Optimized   | Bitwise Shift Method | O(log(|dividend|))    | O(1)             |
    ------------------------------------------------------------------------------
    🧠 Key Notes:
    - Avoid *, /, % operators
    - Use XOR to determine sign efficiently
    - Handle overflow case (INT_MIN / -1)
    - Left shift helps multiply divisor by powers of 2 quickly
    - Truncate toward zero (no rounding)
    ------------------------------------------------------------------------------

    ✅ SAMPLE OUTPUT:

    =====================================================
               💡 LeetCode #29 — Divide Two Integers
    =====================================================

    🧩 Test Case 1: (Brute Force)
    Input: dividend = 10, divisor = 3
    Output: 3

    🧩 Test Case 2: (Brute Force)
    Input: dividend = 7, divisor = -3
    Output: -2

    🧩 Test Case 3: (Optimized)
    Input: dividend = 0, divisor = 1
    Output: 0

    🧩 Test Case 4: (Optimized)
    Input: dividend = 1, divisor = 1
    Output: 1

    🧩 Test Case 5: (Overflow Handling)
    Input: dividend = -2147483648, divisor = -1
    Output: 2147483647

    =====================================================
    ✅ Execution Complete — Both Approaches Tested!
    =====================================================
*/
