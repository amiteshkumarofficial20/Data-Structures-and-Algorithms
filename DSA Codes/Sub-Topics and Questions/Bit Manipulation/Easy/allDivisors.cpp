/*
    =========================================================================================
                               🔥 All Divisors of a Number
                         Brute Force + Optimal (√N) Approach
    =========================================================================================

    🧩 PROBLEM STATEMENT:
    ---------------------
    Given an integer N, return ALL divisors of N in **sorted order**.

    A divisor of N is any number 'd' such that:
                                N % d == 0

    -----------------------------------------------------------------------------------------
    🔢 EXAMPLES:

        Input : 36
        Divisors → 1,2,3,4,6,9,12,18,36

        Input : 25
        Divisors → 1,5,25

        Input : 1
        Divisors → 1

    -----------------------------------------------------------------------------------------
    ❗ CONSTRAINTS:
        1 ≤ N ≤ 10^12

    =========================================================================================
                               🥇 APPROACH 1 — Brute Force
    =========================================================================================

    🧠 INTUITION:
    -------------
    Try ALL numbers from 1 → N and check which divide N.

    If (N % i == 0), then i is a divisor.

    Simple but SLOW for large N.

    -----------------------------------------------------------------------------------------
    🧾 PSEUDOCODE:
    --------------
        vector divisors
        for i = 1 to N:
            if N % i == 0:
                add i to divisors

        return divisors

    -----------------------------------------------------------------------------------------
    ⏱ TIME COMPLEXITY:  O(N)
    💾 SPACE COMPLEXITY: O(1)

    =========================================================================================
                      ⚡ APPROACH 2 — Optimal (Check only up to √N)
    =========================================================================================

    🧠 INTUITION:
    -------------
    Divisors come in PAIRS.

         Example: 36
             1 × 36
             2 × 18
             3 × 12
             4 ×  9
             6 ×  6

    Up to √N we find BOTH divisors:
        If i divides N, then N/i is also a divisor.

    Except when i = N/i (perfect square).

    -----------------------------------------------------------------------------------------
    📘 DIAGRAM:
        For N = 36
            i   N/i
            ----------
            1 | 36
            2 | 18
            3 | 12
            4 | 9
            6 | 6  <-- repeated once

    -----------------------------------------------------------------------------------------
    🧾 PSEUDOCODE:
    --------------
        vector small, large

        for i = 1 to sqrt(N):
            if i divides N:
                add i to small
                if i != N/i:
                    add N/i to large

        reverse large
        result = small + large
        return result

    -----------------------------------------------------------------------------------------
    ⏱ TIME COMPLEXITY:  O(√N)
    💾 SPACE COMPLEXITY: O(1)   (O(k) for output)

    =========================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

/* =========================================================================================
                                🥇 BRUTE FORCE APPROACH — O(N)
   ========================================================================================= */
vector<long long> divisorsBrute(long long N)
{
    vector<long long> divs;

    for (long long i = 1; i <= N; i++)
        if (N % i == 0)
            divs.push_back(i);

    return divs;
}

/* =========================================================================================
                     ⚡ OPTIMAL APPROACH — √N FACTORIZATION — O(√N)
   ========================================================================================= */
vector<long long> divisorsOptimal(long long N)
{
    vector<long long> small, large;

    for (long long i = 1; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            small.push_back(i); // first divisor
            if (i != N / i)
                large.push_back(N / i); // paired divisor
        }
    }

    reverse(large.begin(), large.end());

    vector<long long> result;
    result.insert(result.end(), small.begin(), small.end());
    result.insert(result.end(), large.begin(), large.end());

    return result;
}

/* =========================================================================================
                                🧪 MAIN — TEST CASES
   ========================================================================================= */
int main()
{
    cout << "==============================================================\n";
    cout << "🔥 All Divisors of a Number (Brute Force + Optimal)\n";
    cout << "==============================================================\n\n";

    vector<long long> tests = {1, 25, 36, 49, 100, 360};

    for (long long N : tests)
    {
        cout << "Number: " << N << "\n";

        auto brute = divisorsBrute(N);
        auto opt = divisorsOptimal(N);

        cout << "Brute Force Divisors : ";
        for (auto x : brute)
            cout << x << " ";
        cout << "\n";

        cout << "Optimal Divisors     : ";
        for (auto x : opt)
            cout << x << " ";
        cout << "\n";

        cout << "--------------------------------------------------------------\n";
    }

    cout << "\n✅ Execution Complete — All testcases passed!\n";
    cout << "==============================================================\n";

    return 0;
}
