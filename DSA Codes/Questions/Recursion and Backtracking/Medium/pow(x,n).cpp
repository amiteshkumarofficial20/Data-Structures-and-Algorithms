#include <bits/stdc++.h>
using namespace std;

/*
    Problem: 50. Pow(x, n)
    ----------------------
    Implement pow(x, n), which calculates x raised to the power n (x^n).

    Examples:
    ---------
    Input: x = 2.00000, n = 10
    Output: 1024.00000

    Input: x = 2.10000, n = 3
    Output: 9.26100

    Input: x = 2.00000, n = -2
    Output: 0.25000  (since 1 / (2^2) = 0.25)

    We will implement 3 approaches:
    1) Brute Force (O(|n|) Time, O(1) Space)
    2) Iterative Binary Exponentiation (O(log |n|) Time, O(1) Space)
    3) Recursive Binary Exponentiation (O(log |n|) Time, O(log |n|) Space)
*/

class Solution
{
public:
    // ------------------------------------------------------------------
    // 1. Brute Force Approach
    // ------------------------------------------------------------------
    double myPowBruteForce(double x, int n)
    {
        long long exp = n;
        if (exp < 0)
        { // handle negative exponent
            x = 1 / x;
            exp = -exp;
        }

        double ans = 1.0;
        for (long long i = 0; i < exp; i++)
        {
            ans *= x;
        }
        return ans;
    }
    /*
    -----------------------------------------------------------------
    ⏱️ Time Complexity:
        O(|n|) → We multiply x exactly |n| times.
        If n = 10^9, this will run 1 billion multiplications (too slow).

    💾 Space Complexity:
        O(1) → We only use a few variables (ans, exp, x).

    ⚠️ Note:
        - This brute-force method is fine for small n,
          but will give TLE (Time Limit Exceeded) for large n.
        - The optimal solution is **Binary Exponentiation** (O(log n)).
    -----------------------------------------------------------------
*/

    // ------------------------------------------------------------------
    // 2. Iterative Binary Exponentiation
    // ------------------------------------------------------------------
    // -------------------------------------------------------------------
    // ✅ Approach: Binary Exponentiation (a.k.a Fast Power)
    // -------------------------------------------------------------------
    /*
        Idea:
        Instead of multiplying x exactly n times (O(n)), we can:
          - Square the base
          - Halve the exponent
          - Multiply result only when exponent is odd

        Example: x = 2, n = 13
            13 in binary = 1101
            => 2^13 = 2^(8+4+1) = (2^8 * 2^4 * 2^1)
            We compute this by squaring and multiplying selectively.
    */

    double myPowIterative(double x, int n)
    {
        long long exp = n;
        if (exp < 0)
        {
            x = 1 / x;
            exp = -exp;
        }

        double ans = 1.0;
        while (exp > 0)
        {
            if (exp % 2 == 1)
            { // if exponent is odd
                ans *= x;
            }
            x *= x;   // square the base
            exp /= 2; // reduce exponent
        }
        return ans;
    }
    /*
    -----------------------------------------------------------------
    ⏱️ Time Complexity: O(log |n|)
        - Each step halves the exponent (exp /= 2).
        - Example: for n = 1024, only ~10 steps required.

    💾 Space Complexity: O(1)
        - Only a few variables are used (ans, exp, x).

    ✅ Much faster than brute force (O(|n|)) approach.
    -----------------------------------------------------------------
*/

    // ------------------------------------------------------------------
    // 3. Recursive Binary Exponentiation
    // ------------------------------------------------------------------
    /*     Idea:- Instead of multiplying x exactly n times (O(n)), we divide the problem:
            pow(x, n) =
                if n is even → pow(x, n/2) * pow(x, n/2)
                if n is odd  → pow(x, n/2) * pow(x, n/2) * x
        - This reduces the time to O(log n).
    */
    double fastPow(double x, long long n)
    {
        if (n == 0)
            return 1.0; // base case

        double half = fastPow(x, n / 2);

        if (n % 2 == 0)
            return half * half; // even case
        else
            return half * half * x; // odd case
    }

    double myPowRecursive(double x, int n)
    {
        long long exp = n;
        if (exp < 0)
        {
            x = 1 / x;
            exp = -exp;
        }
        return fastPow(x, exp);
    }
    /*
     -------------------------------------------------------------------
     ⏱️ Time Complexity: O(log |n|)
         - Each recursive call halves n.
         - Example: For n = 1024, only ~10 recursive calls are made.

     💾 Space Complexity: O(log |n|)
         - Due to recursion stack.
         - Worst case: log |n| recursive calls.

     ✅ Much faster than brute force O(|n|).
     -------------------------------------------------------------------
 */
};

// ----------------------
// Driver code for testing
// ----------------------
int main()
{
    Solution sol;
    double x;
    int n;

    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;

    cout << "\nBrute Force Result: " << sol.myPowBruteForce(x, n) << endl;
    cout << "Iterative Binary Exponentiation Result: " << sol.myPowIterative(x, n) << endl;
    cout << "Recursive Binary Exponentiation Result: " << sol.myPowRecursive(x, n) << endl;

    return 0;
}
