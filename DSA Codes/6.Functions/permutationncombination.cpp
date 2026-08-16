/*
    PERMUTATION AND COMBINATION USING FUNCTIONS

    Permutation:

        nPr = n! / (n-r)!

    Combination:

        nCr = n! / (r! * (n-r)!)


    LOGIC:

    First, we create a factorial function.

    factorial(n)
        -> calculates n!


    Then we use factorial() to calculate:

    Permutation:
        nPr = n! / (n-r)!

    Combination:
        nCr = n! / (r! * (n-r)!)


    Example:

    n = 5
    r = 2

    5P2 = 5! / 3!
        = 20

    5C2 = 5! / (2! * 3!)
        = 10
*/

#include <iostream>
using namespace std;

// ==========================================================
// FACTORIAL FUNCTION
// ==========================================================

int factorial(int n)
{
    int fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    return fact;
}

// ==========================================================
// PERMUTATION FUNCTION
// ==========================================================

int permutation(int n, int r)
{
    return factorial(n) / factorial(n - r);
}

// ==========================================================
// COMBINATION FUNCTION
// ==========================================================

int combination(int n, int r)
{
    return factorial(n) /
           (factorial(r) * factorial(n - r));
}

int main()
{
    int n, r;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter r: ";
    cin >> r;

    // ======================================================
    // PERMUTATION
    // ======================================================

    cout << "Permutation (nPr) = "
         << permutation(n, r) << endl;

    // ======================================================
    // COMBINATION
    // ======================================================

    cout << "Combination (nCr) = "
         << combination(n, r) << endl;

    return 0;
}