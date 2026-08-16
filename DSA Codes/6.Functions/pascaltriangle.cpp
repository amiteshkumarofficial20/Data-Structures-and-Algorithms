/*
    PASCAL TRIANGLE - BOTH APPROACHES

    This program prints Pascal Triangle using two approaches:

    1. NORMAL APPROACH
       Using Binomial Coefficient (nCr) with factorial.

    2. OPTIMIZED APPROACH
       Using the previous value of the current row.


    ==========================================================
    APPROACH 1: NORMAL
    ==========================================================

    Each element is calculated using:

        nCr = n! / (r! * (n-r)!)


    For Pascal Triangle:

        value = (row - 1)C(column - 1)


    Example:

    For n = 5:

        1
       1 1
      1 2 1
     1 3 3 1
    1 4 6 4 1


    TIME COMPLEXITY:

    There are O(n²) elements.

    Each nCr calculation uses factorial,
    which takes O(n).

        TC = O(n²) * O(n)
           = O(n³)


    SPACE COMPLEXITY:

        SC = O(1)

    Only a few variables are used.


    ==========================================================
    APPROACH 2: OPTIMIZED
    ==========================================================

    We calculate the next value using the previous value.

    Formula:

        nextValue = currentValue * (row - column) / column


    We don't calculate factorial again and again.

    Therefore, each element takes O(1) time.

    There are O(n²) elements.

        TC = O(n²)


    SPACE COMPLEXITY:

        SC = O(1)


    ==========================================================
    COMPARISON
    ==========================================================

    Normal Approach:
        TC = O(n³)
        SC = O(1)

    Optimized Approach:
        TC = O(n²)
        SC = O(1)
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
// BINOMIAL COEFFICIENT FUNCTION
// ==========================================================

int binomial(int n, int r)
{
    return factorial(n) /
           (factorial(r) * factorial(n - r));
}

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    // ======================================================
    // APPROACH 1: NORMAL
    // USING BINOMIAL COEFFICIENT
    // ======================================================

    cout << "\nNormal Pascal Triangle:\n";

    for (int row = 1; row <= n; row++)
    {
        // Print spaces
        for (int space = 1; space <= n - row; space++)
        {
            cout << " ";
        }

        // Print nCr values
        for (int column = 1; column <= row; column++)
        {
            cout << binomial(row - 1, column - 1) << " ";
        }

        cout << endl;
    }

    // ======================================================
    // APPROACH 2: OPTIMIZED
    // USING PREVIOUS VALUE
    // ======================================================

    cout << "\nOptimized Pascal Triangle:\n";

    for (int row = 1; row <= n; row++)
    {
        // Print spaces
        for (int space = 1; space <= n - row; space++)
        {
            cout << " ";
        }

        // First value of every row is always 1
        int value = 1;

        for (int column = 1; column <= row; column++)
        {
            cout << value << " ";

            /*
                Calculate the next value using
                the current value.

                Formula:

                next value =
                value * (row - column) / column
            */

            value = value * (row - column) / column;
        }

        cout << endl;
    }

    return 0;
}

/*
    ==========================================================
    FINAL COMPLEXITY
    ==========================================================

    NORMAL:

        Time Complexity  = O(n³)
        Space Complexity = O(1)


    OPTIMIZED:

        Time Complexity  = O(n²)
        Space Complexity = O(1)


    OPTIMIZED APPROACH IS BETTER
    because it avoids repeated factorial calculations.
*/