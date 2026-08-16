/*
    SWAP TWO NUMBERS

    This program demonstrates two approaches:

    1. Swapping WITH a third variable
    2. Swapping WITHOUT a third variable


    ==========================================================
    APPROACH 1: WITH THIRD VARIABLE
    ==========================================================

    We use a temporary variable 'temp'.

        temp = a;
        a = b;
        b = temp;


    ==========================================================
    APPROACH 2: WITHOUT THIRD VARIABLE
    ==========================================================

    We use addition and subtraction.

        a = a + b;
        b = a - b;
        a = a - b;


    TIME COMPLEXITY:

        Both approaches = O(1)


    SPACE COMPLEXITY:

        Both approaches = O(1)
*/

#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    // ======================================================
    // APPROACH 1: WITH THIRD VARIABLE
    // ======================================================

    int x = a;
    int y = b;

    int temp;

    temp = x;
    x = y;
    y = temp;

    cout << "\nUsing Third Variable:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    // ======================================================
    // APPROACH 2: WITHOUT THIRD VARIABLE
    // ======================================================

    int p = a;
    int q = b;

    p = p + q;
    q = p - q;
    p = p - q;

    cout << "\nWithout Third Variable:" << endl;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;

    return 0;
}

/*
    Example:

    Input:
        a = 10
        b = 20

    With third variable:
        x = 20
        y = 10

    Without third variable:
        p = 20
        q = 10


    NOTE:

    Addition/subtraction can overflow for very large
    integer values.

    Another approach without a third variable is XOR:

        p = p ^ q;
        q = p ^ q;
        p = p ^ q;
*/