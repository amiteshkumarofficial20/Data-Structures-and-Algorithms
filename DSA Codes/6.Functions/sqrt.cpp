/*
    SQUARE ROOT USING BOTH APPROACHES

    This program finds the square root of a number
    using two approaches:

    1. User-defined function
    2. In-built sqrt() function


    USER-DEFINED FUNCTION:

    We use a loop to find the square root.

    For example:

        sqrt(25) = 5

    because:

        5 * 5 = 25


    IN-BUILT FUNCTION:

    C++ provides sqrt() in the <cmath> library.

        sqrt(n)

    returns the square root of n.
*/

#include <iostream>
#include <cmath>
using namespace std;

// ==========================================================
// USER-DEFINED SQUARE ROOT FUNCTION
// ==========================================================

int squareRoot(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (i * i == n)
        {
            return i;
        }
    }

    return -1; // Not a perfect square
}

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    // ======================================================
    // USING USER-DEFINED FUNCTION
    // ======================================================

    cout << "\nUsing User-Defined Function:" << endl;

    int result = squareRoot(n);

    if (result != -1)
    {
        cout << "Square Root = " << result << endl;
    }
    else
    {
        cout << "Not a Perfect Square" << endl;
    }

    // ======================================================
    // USING IN-BUILT FUNCTION
    // ======================================================

    cout << "\nUsing In-Built Function:" << endl;

    cout << "Square Root = " << sqrt(n) << endl;

    return 0;
}