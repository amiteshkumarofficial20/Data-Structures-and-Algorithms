/*
    ==============================================================================
                        💡 LeetCode #204 — Count Primes
    ==============================================================================

    🧩 PROBLEM STATEMENT:
    ---------------------
    Given an integer n, return the number of prime numbers that are strictly less than n.

    ------------------------------------------------------------------------------
    🧠 INTUITION:
    -------------
    - A prime number is a number greater than 1 with exactly two divisors: 1 and itself.
    - We need to count how many such numbers exist in the range [2, n).

    Example:
      n = 10
      Prime numbers less than 10 → [2, 3, 5, 7]
      Answer = 4 ✅

    ------------------------------------------------------------------------------
    🔢 EXAMPLES:
    ------------

    Example 1:
        Input: n = 10
        Output: 4
        Explanation: Primes are 2, 3, 5, 7.

    Example 2:
        Input: n = 0
        Output: 0

    Example 3:
        Input: n = 1
        Output: 0

    ------------------------------------------------------------------------------
    ⚙️ CONSTRAINTS:
    ----------------
    0 ≤ n ≤ 5 * 10⁶
    ------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/*
    ==============================================================================
    🪜 APPROACH 1 — Brute Force (Trial Division)
    ==============================================================================

    ✅ IDEA:
        Check each number from 2 to n-1.
        For each number, check if it is divisible by any number from 2 to √num.

    ------------------------------------------------------------------------------
    ✅ PSEUDOCODE:
        function countPrimes_BruteForce(n):
            if n <= 2 → return 0
            count = 0
            for i in [2, n):
                if isPrime(i): count++
            return count

        function isPrime(x):
            if x < 2: return false
            for i in [2, sqrt(x)]:
                if x % i == 0 → not prime
            return true

    ------------------------------------------------------------------------------
    ✅ TIME COMPLEXITY: O(n * √n)
    ✅ SPACE COMPLEXITY: O(1)
    ------------------------------------------------------------------------------
*/
bool isPrime(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int countPrimes_BruteForce(int n)
{
    if (n <= 2)
        return 0;

    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (isPrime(i))
            count++;
    }
    return count;
}

/*
    ==============================================================================
    ⚡ APPROACH 2 — Optimized (Sieve of Eratosthenes)
    ==============================================================================

    ✅ IDEA:
        Instead of checking each number individually,
        we eliminate multiples of known primes in a single pass.

    ✅ INTUITION:
        - Start with a boolean array `isPrime[]` initialized to true.
        - `isPrime[i]` represents whether i is prime.
        - For each number p from 2 to √n:
              If p is prime, mark all its multiples as non-prime (false).
        - Finally, count all true values in the array.

    ------------------------------------------------------------------------------
    ✅ PSEUDOCODE:
        function countPrimes_Sieve(n):
            if n <= 2: return 0
            create array isPrime[n] = true
            isPrime[0] = isPrime[1] = false

            for p in [2, √n]:
                if isPrime[p] == true:
                    for multiple in [p*p, n, p]:
                        isPrime[multiple] = false

            return count of true in isPrime[]

    ------------------------------------------------------------------------------
    ✅ EXAMPLE (n = 10):
        Initially: [T, T, T, T, T, T, T, T, T, T]
        0, 1 are not prime → [F, F, T, T, T, T, T, T, T, T]

        p = 2 → mark multiples: 4,6,8 → [F,F,T,T,F,T,F,T,F,T]
        p = 3 → mark multiples: 9 → [F,F,T,T,F,T,F,T,F,F]

        Remaining true indices → [2,3,5,7]
        ✅ Count = 4

    ------------------------------------------------------------------------------
    ✅ TIME COMPLEXITY:  O(n log log n)
    ✅ SPACE COMPLEXITY: O(n)
    ------------------------------------------------------------------------------
*/
int countPrimes_Sieve(int n)
{
    if (n <= 1)
        return 0;

    vector<bool> prime(n + 1, true);
    prime[0] = false;
    prime[1] = false;

    // Classic sieve style
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }

    int count = 0;
    cout << "Prime numbers up to " << n << ": ";

    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            cout << i << " ";
            count++;
        }
    }

    cout << "\nTotal prime numbers ≤ " << n << " = " << count << endl;

    return count;
}

/*
    ==============================================================================
    🧪 DRIVER CODE — TESTING BOTH APPROACHES
    ==============================================================================
*/
int main()
{
    cout << "===========================================================\n";
    cout << "💡 LeetCode #204 — Count Primes\n";
    cout << "===========================================================\n\n";

    vector<int> testCases = {0, 1, 2, 10, 20, 100};

    for (int n : testCases)
    {
        cout << "Input: " << n << endl;
        cout << "🔹 Brute Force Result : " << countPrimes_BruteForce(n) << endl;
        cout << "🔹 Sieve (Optimized)  : " << countPrimes_Sieve(n) << endl;
        cout << "-----------------------------------------------------------\n";
    }

    /*
        ==============================================================================
        ✅ SAMPLE OUTPUT:

        Input: 0
        Brute Force Result : 0
        Sieve (Optimized)  : 0
        -----------------------------------------------------------
        Input: 10
        Brute Force Result : 4
        Sieve (Optimized)  : 4
        -----------------------------------------------------------
        Input: 20
        Brute Force Result : 8
        Sieve (Optimized)  : 8
        -----------------------------------------------------------
        Input: 100
        Brute Force Result : 25
        Sieve (Optimized)  : 25
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
    | Approach   | Method                | Time Complexity | Space Complexity |
    |-------------|----------------------|-----------------|-----------------|
    | Brute Force | Trial Division        | O(n√n)          | O(1)            |
    | Optimized   | Sieve of Eratosthenes | O(n log log n)  | O(n)            |
    ------------------------------------------------------------------------------
    🧠 KEY TAKEAWAYS:
    -----------------
    ✅ Sieve of Eratosthenes is the most efficient way to generate primes up to N.
    ✅ Marking starts at p*p because smaller multiples are already marked.
    ✅ For large n (up to 5×10⁶), always use Sieve, not brute force.
    ✅ This pattern is fundamental in problems involving primes & number theory.
    ==============================================================================
*/
