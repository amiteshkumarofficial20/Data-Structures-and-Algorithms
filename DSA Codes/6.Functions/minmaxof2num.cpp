/*
    MINIMUM AND MAXIMUM USING FUNCTIONS + IN-BUILT FUNCTIONS

    This program demonstrates two ways to find the minimum
    and maximum of two numbers.

    1. Using our own user-defined functions:
       minNumber()
       maxNumber()

    2. Using C++ in-built functions:
       min()
       max()


    USER-DEFINED FUNCTIONS:

    int minNumber(int a, int b)

    int maxNumber(int a, int b)


    IN-BUILT FUNCTIONS:

    min(a, b) -> returns the smaller value
    max(a, b) -> returns the larger value

    min() and max() are available through <algorithm>.
*/

#include <iostream>
#include <algorithm>
using namespace std;

// ==========================================================
// USER-DEFINED MIN FUNCTION
// ==========================================================

int minNumber(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// ==========================================================
// USER-DEFINED MAX FUNCTION
// ==========================================================

int maxNumber(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    int a, b;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    // ======================================================
    // USING USER-DEFINED FUNCTIONS
    // ======================================================

    cout << "\nUsing User-Defined Functions:" << endl;

    cout << "Minimum = " << minNumber(a, b) << endl;
    cout << "Maximum = " << maxNumber(a, b) << endl;

    // ======================================================
    // USING IN-BUILT FUNCTIONS
    // ======================================================

    cout << "\nUsing In-Built Functions:" << endl;

    cout << "Minimum = " << min(a, b) << endl;
    cout << "Maximum = " << max(a, b) << endl;

    return 0;
}