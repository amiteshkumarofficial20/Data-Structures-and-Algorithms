#include <iostream>
using namespace std;

/* =========================================================
   ✅ FACTORIAL OF N
   Formula:
       N! = N × (N-1) × (N-2) × ... × 2 × 1
       Special Case: 0! = 1
   ========================================================= */

/* =========================================================
   ITERATIVE APPROACH
   ---------------------------------------------------------
   Approach:
     - Start result = 1.
     - Multiply result by all numbers from 1 to N.
     - Return result.

   Time Complexity:  O(N)  → loop runs N times
   Space Complexity: O(1)  → uses constant extra space
   ========================================================= */
long long factorialIterative(int N)
{
    long long result = 1; // will store the factorial
    for (int i = 1; i <= N; i++)
    {
        result *= i; // multiply result with current number
    }
    return result;
}

/* =========================================================
   RECURSIVE APPROACH
   ---------------------------------------------------------
   Approach:
     - Base Case: if N == 0 or N == 1 → return 1
     - Recursive Case: N! = N × (N-1)!

   Time Complexity:  O(N)  → N recursive calls
   Space Complexity: O(N)  → recursion call stack depth = N
   ========================================================= */
long long factorialRecursive(int N)
{
    // Base Case
    if (N == 0 || N == 1)
    {
        return 1;
    }
    // Recursive Case
    return N * factorialRecursive(N - 1);
}

/* =========================================================
   MAIN FUNCTION
   ---------------------------------------------------------
   - Takes input N
   - Calls both iterative and recursive factorial functions
   - Prints results for comparison
   ========================================================= */
int main()
{
    int N;
    cout << "Enter a number: ";
    cin >> N;

    // Iterative result
    cout << "Factorial (Iterative) of " << N << " = "
         << factorialIterative(N) << endl;

    // Recursive result
    cout << "Factorial (Recursive) of " << N << " = "
         << factorialRecursive(N) << endl;

    return 0;
}
