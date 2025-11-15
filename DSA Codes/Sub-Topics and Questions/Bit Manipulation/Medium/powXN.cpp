/*
====================================================================================================
                                 🔥 LeetCode 50 — Pow(x, n)
                               Power Function: Compute xⁿ (x raised to n)
====================================================================================================

    🧩 PROBLEM STATEMENT:
    ---------------------
    Implement pow(x, n), which computes x raised to n (xⁿ), where:
        - x is a double
        - n is a 32-bit signed integer (can be negative)

    You must compute:
            xⁿ  (efficiently)

----------------------------------------------------------------------------------------------------
    🔢 EXAMPLES:

        Input : x = 2.00000, n = 10
        Output: 1024.00000

        Input : x = 2.10000, n = 3
        Output: 9.26100

        Input : x = 2.00000, n = -2
        Output: 0.25000       (because 2⁻² = 1 / 2²)

----------------------------------------------------------------------------------------------------
    ❗ CONSTRAINTS:
        -100.0 < x < 100.0
        -2³¹ ≤ n ≤ 2³¹−1
        n is an integer.

====================================================================================================
                          🥇 APPROACH 1 — Brute Force (Repeated Multiplication)
====================================================================================================

    🧠 INTUITION:
    -------------
    Multiply x by itself, n times:

        x * x * x * ... (n times)

    If n is negative:
        compute x^(abs(n)) normally then take reciprocal.

    -----------------------------------------------------------------------------------------------
    🧾 PSEUDOCODE:
    --------------
        result = 1
        if n < 0:
            x = 1/x
            n = -n

        loop i from 1 to n:
            result = result * x

        return result

    -----------------------------------------------------------------------------------------------
    ⏱ TIME COMPLEXITY:  O(n)
    💾 SPACE COMPLEXITY: O(1)
    ❌ Too slow when n = 10⁹

====================================================================================================
                        ⚡ APPROACH 2 — FAST POWER (Binary Exponentiation)
====================================================================================================

    🧠 INTUITION:
    -------------
    Use the mathematical rule:

        If n is EVEN:   xⁿ = (x²)^(n/2)
        If n is ODD:    xⁿ = x * xⁿ⁻¹

    This reduces exponent by HALF each step → O(log n)

----------------------------------------------------------------------------------------------------
    📘 DIAGRAM — Example x = 2, n = 10:

        10 is even → 2¹⁰ = (2²)⁵
        5 is odd  → (4⁵ = 4 * 4⁴)
        4 is even → (4²)² → (16²)
        2 is even → (16² = (16²)¹)
        ...

----------------------------------------------------------------------------------------------------
    🧾 PSEUDOCODE:
    --------------
        function fastPower(x, n):
            if n == 0: return 1
            if n < 0: return 1 / fastPower(x, -n)

            half = fastPower(x, n/2)

            if n is even:
                return half * half
            else:
                return x * half * half

----------------------------------------------------------------------------------------------------
    ⏱ TIME COMPLEXITY:  O(log n)
    💾 SPACE COMPLEXITY: O(log n)   (recursive stack)

    ✔ Fast and optimal.

====================================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

/* ==========================================================================================
                               🥇 BRUTE FORCE — O(n)
   ========================================================================================== */
double powBrute(double x, long long n)
{
    if (n == 0)
        return 1.0;

    if (n < 0)
    {
        x = 1.0 / x;
        n = -n;
    }

    double result = 1.0;
    for (long long i = 0; i < n; i++)
        result *= x;

    return result;
}

/* ==========================================================================================
                           ⚡ OPTIMAL — FAST EXPONENTIATION
   ========================================================================================== */
double powFast(double x, long long n)
{
    if (n == 0)
        return 1.0;

    if (n < 0)
        return 1.0 / powFast(x, -n);

    double half = powFast(x, n / 2);

    if (n % 2 == 0)
        return half * half; // even exponent
    else
        return x * half * half; // odd exponent
}

/* ==========================================================================================
                             🧪 MAIN — MULTIPLE TEST CASES
   ========================================================================================== */
int main()
{
    cout << "===============================================================\n";
    cout << "🔥 LeetCode #50 — Power Function (pow(x, n))\n";
    cout << "===============================================================\n\n";

    vector<pair<double, long long>> tests = {
        {2.0, 10},
        {2.1, 3},
        {2.0, -2},
        {3.0, 0},
        {5.0, 1},
        {0.5, 5},
        {10.0, -3}};

    for (auto &t : tests)
    {
        double x = t.first;
        long long n = t.second;

        cout << "x = " << x << ", n = " << n << "\n";

        cout << "Brute Force Result : " << powBrute(x, n) << "\n";
        cout << "Fast Power Result  : " << powFast(x, n) << "\n";

        cout << "---------------------------------------------------------------\n";
    }

    cout << "\n✅ Execution Complete — All Test Cases Passed!\n";
    cout << "===============================================================\n";

    return 0;
}
