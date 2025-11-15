/*
=================================================================================================
                        🔥 PRIME FACTORIZATION USING SIEVE OF SMALLEST PRIME FACTOR (SPF)
=================================================================================================

    🧩 PROBLEM STATEMENT:
    ---------------------
    Given an integer array queries of size n, return the **prime factorization** of each number
    using an efficient sieve-based technique.

    Each number must be factorized into its **prime factors in sorted order**.

    ---------------------------------------------------------------------------------------------
    🔢 EXAMPLES:

        Input : queries = [2, 3, 4, 5, 6]
        Output:
            2 → 2
            3 → 3
            4 → 2 2
            5 → 5
            6 → 2 3

    ---------------------------------------------------------------------------------------------
    ❗ WHY SPF SIEVE?
    -----------------
    Brute force factorization takes:     O(√N)
    Factorization for Q queries:         Q * O(√N)

    Using SPF (Smallest Prime Factor), we get:

        Preprocessing:  O(N log log N)
        Each Query:     O(log N)

    SUPER FAST for large constraints!

=================================================================================================
                            🥇 APPROACH 1 — Brute Force (O√N per query)
=================================================================================================

    🧠 INTUITION:
    -------------
    For each number:
        Repeatedly check divisibility from 2 → √n.
        Extract factors one by one.

    ❌ Slow for large input ranges.

    ---------------------------------------------------------------------------------------------
    🧾 PSEUDOCODE:
    --------------
        function bruteFactor(n):
            for i = 2 to i*i <= n:
                while n % i == 0:
                    print i
                    n /= i
            if n > 1:
                print n

    ---------------------------------------------------------------------------------------------
    ⏱ TIME COMPLEXITY:  O(√N)
    💾 SPACE COMPLEXITY: O(1)

=================================================================================================
                        ⚡ APPROACH 2 — Optimal Using SPF (Smallest Prime Factor)
=================================================================================================

    🧠 INTUITION:
    -------------
    Use a modified sieve to precompute the SMALLEST PRIME FACTOR for every number up to MAX_N.

       Example SPF Table up to 10:
            1 → 1
            2 → 2
            3 → 3
            4 → 2
            5 → 5
            6 → 2
            7 → 7
            8 → 2
            9 → 3
           10 → 2

    Then factorization is easy:
        n = 84
        SPF[84] = 2   → factor 2
        84/2 = 42
        SPF[42] = 2   → factor 2
        42/2 = 21
        SPF[21] = 3   → factor 3
        21/3 = 7
        SPF[7] = 7    → factor 7

    Final result = 2, 2, 3, 7

    ---------------------------------------------------------------------------------------------
    🧾 PSEUDOCODE:
    --------------
        buildSPF():
            for i = 2 to MAX_N:
                if SPF[i] == 1:
                    for j = i to MAX_N step i:
                        if SPF[j] == 1:
                            SPF[j] = i

        getPrimeFactors(n):
            while n != 1:
                print SPF[n]
                n /= SPF[n]

    ---------------------------------------------------------------------------------------------
    ⏱ TIME COMPLEXITY:
        Precomputation:    O(N log log N)
        Each factorization: O(log N)

    💾 SPACE COMPLEXITY:   O(N)

=================================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

// Global array to store smallest prime factors
vector<int> SPF(MAX_N + 1, 1);

/* =========================================================================================
                          ⚙️ BUILD SPF SIEVE (Optimal)
   ========================================================================================= */
void buildSPF()
{
    for (int i = 2; i <= MAX_N; i++)
    {
        if (SPF[i] == 1) // i is prime
        {
            for (int j = i; j <= MAX_N; j += i)
            {
                if (SPF[j] == 1)
                    SPF[j] = i;
            }
        }
    }
}

/* =========================================================================================
                        🔍 GET PRIME FACTORIZATION USING SPF
   ========================================================================================= */
vector<int> getPrimeFactors(int n)
{
    vector<int> factors;

    while (n != 1)
    {
        factors.push_back(SPF[n]);
        n /= SPF[n];
    }

    return factors;
}

/* =========================================================================================
                                      🧪 MAIN — TESTING
   ========================================================================================= */
int main()
{
    cout << "===============================================================\n";
    cout << "🔥 Prime Factorization Using Sieve (SPF Table)\n";
    cout << "===============================================================\n\n";

    buildSPF(); // Precompute smallest prime factors

    vector<int> queries = {2, 3, 4, 5, 6, 12, 97, 100};

    for (int n : queries)
    {
        cout << "Prime factors of " << n << " → ";

        vector<int> f = getPrimeFactors(n);
        for (int x : f)
            cout << x << " ";

        cout << "\n";
    }

    cout << "\n✅ Execution Completed!\n";
    cout << "===============================================================\n";

    return 0;
}
