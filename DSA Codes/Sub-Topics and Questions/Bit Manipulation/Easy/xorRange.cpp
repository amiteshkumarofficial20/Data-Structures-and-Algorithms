/*
    ======================================================================================
                        🔥 Find XOR of Numbers from L to R
                         (Brute Force + Optimal Approach)
    ======================================================================================

    🧩 PROBLEM STATEMENT:
    ---------------------
    Given two integers L and R (L ≤ R), return the XOR of ALL numbers in the range:

            L ⊕ (L+1) ⊕ (L+2) ⊕ ... ⊕ R

    --------------------------------------------------------------------------------------
    🔢 EXAMPLES:

        Example 1:
            Input : L = 3, R = 6
            XOR   = 3 ⊕ 4 ⊕ 5 ⊕ 6
                  = (3 ⊕ 4) ⊕ (5 ⊕ 6)
                  = 7 ⊕ 3
                  = 4
            Output: 4

        Example 2:
            Input : L = 1, R = 10
            Output: 11

    --------------------------------------------------------------------------------------
    ❗ CONSTRAINTS:
        0 ≤ L ≤ R ≤ 10^18
        Large range → brute force WILL TLE → optimal needed.

    ======================================================================================
                                   🥇 APPROACH 1 — Brute Force
    ======================================================================================

    🧠 INTUITION:
    -------------
    XOR is cumulative:
            ans = L ⊕ (L+1) ⊕ ... ⊕ R

    We simply XOR all numbers from L → R.

    --------------------------------------------------------------------------------------
    🧾 PSEUDOCODE:
    --------------
        function xorRangeBrute(L, R):
            result = 0
            for i = L to R:
                result = result XOR i
            return result

    --------------------------------------------------------------------------------------
    ⏱ TIME COMPLEXITY:  O(R − L + 1)
    💾 SPACE COMPLEXITY: O(1)

    (Not usable for large ranges, but good as baseline.)

    ======================================================================================
                             ⚡ APPROACH 2 — Optimal (Prefix XOR Trick)
    ======================================================================================

    🧠 INTUITION:
    -------------
    XOR of numbers from 1 to n follows a pattern:

            n % 4 == 0 → f(n) = n
            n % 4 == 1 → f(n) = 1
            n % 4 == 2 → f(n) = n + 1
            n % 4 == 3 → f(n) = 0

    This gives XOR from 1 to n in O(1).

    To get XOR from L to R:

            XOR(L..R) = XOR(1..R) ⊕ XOR(1..L−1)

    Because all common prefix numbers cancel out.

    --------------------------------------------------------------------------------------
    🧾 PSEUDOCODE:
    --------------
        function prefixXOR(n):
            if n % 4 == 0: return n
            if n % 4 == 1: return 1
            if n % 4 == 2: return n + 1
            else         : return 0

        function xorRange(L, R):
            return prefixXOR(R) XOR prefixXOR(L-1)

    --------------------------------------------------------------------------------------
    ⏱ TIME COMPLEXITY:  O(1)
    💾 SPACE COMPLEXITY: O(1)
    (FASTEST possible solution)

    ======================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

/* ======================================================================================
                         🥇 BRUTE FORCE — O(R-L+1)
   ====================================================================================== */
long long xorRangeBrute(long long L, long long R)
{
    long long result = 0;
    for (long long i = L; i <= R; i++)
        result ^= i;
    return result;
}

/* ======================================================================================
                         🧠 Prefix XOR Function f(n)
   ====================================================================================== */
long long prefixXOR(long long n)
{
    if (n < 0)
        return 0; // since XOR of empty prefix is 0

    switch (n % 4)
    {
    case 0:
        return n;
    case 1:
        return 1;
    case 2:
        return n + 1;
    case 3:
        return 0;
    }
    return 0;
}

/* ======================================================================================
                         ⚡ OPTIMAL RANGE XOR — O(1)
   ====================================================================================== */
long long xorRangeOptimal(long long L, long long R)
{
    return prefixXOR(R) ^ prefixXOR(L - 1);
}

/* ======================================================================================
                         🧪 MAIN (Test Cases)
   ====================================================================================== */
int main()
{
    cout << "=============================================================\n";
    cout << "🔥 Find XOR of Numbers from L to R (Brute + Optimal)\n";
    cout << "=============================================================\n\n";

    vector<pair<long long, long long>> tests = {
        {3, 6},
        {1, 10},
        {5, 5},
        {0, 7},
        {10, 20},
        {123, 456},
        {1, 1000000000LL} // huge range (brute not executed)
    };

    for (auto &t : tests)
    {
        long long L = t.first;
        long long R = t.second;

        cout << "Range: L = " << L << ", R = " << R << "\n";

        if (R - L <= 1000000)
            cout << "Brute Force Result : " << xorRangeBrute(L, R) << "\n";
        else
            cout << "Brute Force Skipped (too large)\n";

        cout << "Optimal Result     : " << xorRangeOptimal(L, R) << "\n";
        cout << "-------------------------------------------------------------\n";
    }

    cout << "\n✅ Execution Complete — All Approaches Tested!\n";
    cout << "=============================================================\n";
    return 0;
}
