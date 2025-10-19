#include <bits/stdc++.h>
using namespace std;

// -----------------------------
// LeetCode 1922: Count Good Numbers
// -----------------------------
/*
   Problem Summary:
   ----------------
   - A digit string of length `n` is called "good" if:
        - At even indices (0-based): digit is EVEN → {0, 2, 4, 6, 8} → 5 choices
        - At odd indices: digit is PRIME → {2, 3, 5, 7} → 4 choices

   - Task: Count the total number of such "good" digit strings of length n.
   - Since answer can be huge, return result modulo 1e9+7.

   Example:
    --------
    Input: n = 4
    Output: 400
    Explanation:
        Possible choices:
        Index 0 (even) → 5 choices (0,2,4,6,8)
        Index 1 (odd)  → 4 choices (2,3,5,7)
        Index 2 (even) → 5 choices
        Index 3 (odd)  → 4 choices
        Total = 5*4*5*4 = 400
    */

const long long MOD = 1e9 + 7;

// ===================================================
// ✅ Helper: Check if digit is prime (for Brute Force)
// ===================================================
bool isPrimeDigit(int d)
{
    return (d == 2 || d == 3 || d == 5 || d == 7);
}
/*
-----------------------------------------------------------------
✅ Brute Force Approach:
------------------------
1. Generate all numbers of length n (from 0 to 10^n - 1).
2. For each number, check digit by digit:
    - If position is even → digit must be even.
    - If position is odd  → digit must be prime.
3. Count how many numbers satisfy this condition.

⚠️ NOTE:
This approach works only for very small n (like n <= 6 or 7),
because generating 10^n numbers becomes impossible for large n.
(e.g., n = 15 → 10^15 possibilities → infeasible).

-----------------------------------------------------------------
Time Complexity (Brute Force):
------------------------------
- We generate up to 10^n numbers.
- Each number has n digits → checking each takes O(n).
- Total = O(n * 10^n) → exponential growth, NOT feasible for big n.

Space Complexity:
-----------------
- O(1) extra space (only counters and variables).
*/
bool isGood(int num, int n)
{
    for (int i = 0; i < n; i++)
    {
        int digit = num % 10;
        if (i % 2 == 0)
        { // even index
            if (digit % 2 != 0)
                return false;
        }
        else
        { // odd index
            if (!isPrimeDigit(digit))
                return false;
        }
        num /= 10;
    }
    return true;
}

long long bruteCountGoodNumbers(int n)
{
    int limit = pow(10, n);
    long long total = 0;
    for (int num = 0; num < limit; num++)
    {
        if (isGood(num, n))
            total++;
    }
    return total;
}

/*
 ----------------------------------------------------------------
   ✅ Better Approach: Iterative Multiplication
   ----------------------------------------------------------------
   - Instead of brute forcing all possible numbers (10^n possibilities, infeasible),
     we directly calculate the number of options for each position.

   - Logic:
       * If index is even → multiply by 5
       * If index is odd  → multiply by 4
       * Do this iteratively for all n positions.

   - Take modulo 1e9+7 at each step to avoid overflow.

   ----------------------------------------------------------------
   Time Complexity:
   ----------------
   - We loop over all n positions → O(n)
   - Each step involves constant-time multiplication/modulo.
   - ✅ TC = O(n)

   Space Complexity:
   -----------------
   - We only use a few variables (`ans`, loop counter).
   - ✅ SC = O(1)
*/
long long betterCountGoodNumbers(long long n)
{
    long long ans = 1;
    for (long long i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            ans = (ans * 5) % MOD;
        else
            ans = (ans * 4) % MOD;
    }
    return ans;
}

// ===================================================
// ✅ Helper: Modular Exponentiation (Binary Exponentiation)
// ===================================================
long long modPow(long long a, long long b, long long M)
{
    if (b == 0)
        return 1;

    long long half = modPow(a, b / 2, M);
    long long result = (half * half) % M;

    if (b % 2 == 1)
        result = (result * a) % M;

    return result;
}

/*
----------------------------------------------------------------
   ✅ Optimal Approach: Modular Exponentiation
   ----------------------------------------------------------------
   - Observation:
        * Even positions = ceil(n/2) → 5 choices each
        * Odd positions  = floor(n/2) → 4 choices each
        * Answer = (5^(ceil(n/2)) * 4^(floor(n/2))) % MOD

   - Why Modular Exponentiation?
        * Directly computing 5^n or 4^n will cause overflow for large n (up to 10^15).
        * Instead, we compute powers in O(log n) time using Fast Exponentiation.

   ----------------------------------------------------------------
   Fast Exponentiation (Binary Exponentiation):
   --------------------------------------------
   - To compute a^b:
        If b = 0 → return 1
        If b is even → a^b = (a^(b/2))^2
        If b is odd  → a^b = (a^(b/2))^2 * a
   - Each step reduces exponent by half → O(log b).

   ----------------------------------------------------------------
   Time Complexity:
   ----------------
   - modPow runs in O(log n) for each exponentiation.
   - We call it twice (once for 5^(ceil(n/2)), once for 4^(floor(n/2))).
   - ✅ TC = O(log n)

   Space Complexity:
   -----------------
   - Recursive call stack = O(log n).
   - ✅ SC = O(log n)
*/

long long optimalCountGoodNumbers(long long n)
{
    long long evenCount = (n + 1) / 2; // ceil(n/2)
    long long oddCount = n / 2;        // floor(n/2)

    long long powerOf5 = modPow(5, evenCount, MOD);
    long long powerOf4 = modPow(4, oddCount, MOD);

    return (powerOf5 * powerOf4) % MOD;
}

// ===================================================
// Driver Code for VS Code
// ===================================================
int main()
{
    long long n;

    cout << "Enter n: ";
    cin >> n;

    // ⚠️ Brute force only works for very small n
    if (n <= 6)
    {
        cout << "Brute Force Result = " << bruteCountGoodNumbers(n) << endl;
    }
    else
    {
        cout << "Brute Force Skipped (too slow for n > 6)" << endl;
    }

    cout << "Better Result       = " << betterCountGoodNumbers(n) << endl;
    cout << "Optimal Result      = " << optimalCountGoodNumbers(n) << endl;

    return 0;
}
