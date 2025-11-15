/*
    =========================================================================================
                           🔥 PRINT ALL PRIME FACTORS OF A NUMBER
    =========================================================================================

    🧩 PROBLEM STATEMENT:
    ---------------------
    Given an integer N, print ALL **prime factors** of N.

    NOTE:
        - Prime factors include repeated occurrences.
        - Example:
                N = 36 → Output: 2 2 3 3
                N = 100 → Output: 2 2 5 5

    -----------------------------------------------------------------------------------------
    🔢 EXAMPLES:

        Input : 36
        Output: 2 2 3 3

        Input : 97
        Output: 97   (because 97 is prime)

        Input : 84
        Breakdown:
               84 = 2 × 2 × 3 × 7
        Output: 2 2 3 7

    -----------------------------------------------------------------------------------------
    ❗ CONSTRAINTS:
        1 ≤ N ≤ 10^12

    =========================================================================================
                         🥇 APPROACH 1 — Brute Force (Check All Numbers)
    =========================================================================================

    🧠 INTUITION:
    -------------
    Try dividing N by all numbers from 2 to N.
    Whenever divisible → factor found.

    But this takes O(N) → too slow for large N.

    -----------------------------------------------------------------------------------------
    🧾 PSEUDOCODE:
    --------------
        result = []
        for i from 2 to N:
            while N % i == 0:
                print i
                N /= i

        if N > 1:
            print N

    -----------------------------------------------------------------------------------------
    ⏱ TIME COMPLEXITY:  O(N)
    💾 SPACE COMPLEXITY: O(1)

    =========================================================================================
                      ⚡ APPROACH 2 — OPTIMAL (Trial Division up to √N)
    =========================================================================================

    🧠 INTUITION (VERY IMPORTANT):
    ------------------------------
    Any composite number N can be expressed as:

                N = p1 * p2 * p3 * ... * pk

    If N has any factor > √N,
    then the paired factor MUST be < √N.

    So, we only need to check divisors up to √N.

    AFTER removing all smaller factors:
        If N > 1 → remaining N IS PRIME.

    -----------------------------------------------------------------------------------------
    📘 DIAGRAM — Prime Factorization of 84:

            84
          /    \
        (2)    42
               / \
             (2) 21
                 / \
               (3)  7

        Final factors = 2, 2, 3, 7

    -----------------------------------------------------------------------------------------
    🧾 PSEUDOCODE:
    --------------
        function primeFactors(N):
            for i = 2 to sqrt(N):
                while N % i == 0:
                    print i
                    N /= i

            if N > 1:
                print N

    -----------------------------------------------------------------------------------------
    ⏱ TIME COMPLEXITY:  O(√N)
    💾 SPACE COMPLEXITY: O(1)
    (FASTEST for individual prime-factor queries)

    =========================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

/* =========================================================================================
                        🥇 Brute Force — O(N)
   ========================================================================================= */
vector<long long> primeFactorsBrute(long long N)
{
    vector<long long> factors;

    for (long long i = 2; i <= N; i++)
    {
        while (N % i == 0)
        {
            factors.push_back(i);
            N /= i;
        }
    }

    return factors;
}

/* =========================================================================================
                      ⚡ Optimal — Trial Division up to √N (O√N)
   ========================================================================================= */
vector<long long> primeFactorsOptimal(long long N)
{
    vector<long long> factors;

    // Check divisibility by all numbers up to sqrt(N)
    for (long long i = 2; i * i <= N; i++)
    {
        while (N % i == 0)
        {
            factors.push_back(i);
            N /= i;
        }
    }

    // If remainder > 1 → it is a prime factor
    if (N > 1)
        factors.push_back(N);

    return factors;
}

/* =========================================================================================
                               🧪 MAIN — Test Cases
   ========================================================================================= */
int main()
{
    cout << "=====================================================================\n";
    cout << "🔥 PRINT ALL PRIME FACTORS (Brute + Optimal)\n";
    cout << "=====================================================================\n\n";

    vector<long long> tests = {36, 97, 84, 100, 99991, 10};

    for (long long N : tests)
    {
        cout << "Number: " << N << "\n";

        auto brute = primeFactorsBrute(N);
        auto opt = primeFactorsOptimal(N);

        cout << "Brute Force Factors : ";
        for (auto x : brute)
            cout << x << " ";
        cout << "\n";

        cout << "Optimal Factors     : ";
        for (auto x : opt)
            cout << x << " ";
        cout << "\n";

        cout << "---------------------------------------------------------------------\n";
    }

    cout << "\n✅ Execution Complete! All test cases tested.\n";
    cout << "=====================================================================\n";

    return 0;
}
