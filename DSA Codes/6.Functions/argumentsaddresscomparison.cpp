/*
    PASS BY VALUE - ADDRESS COMPARISON

    This program demonstrates what happens to the
    memory addresses when variables are passed to
    a function using PASS BY VALUE.

    LOGIC:

    In main(), we create two variables:

        int x = 10;
        int y = 20;

    We print their addresses using:

        &x
        &y

    Then we pass x and y to the function:

        showAddress(x, y);


    In the function:

        void showAddress(int a, int b)

    'a' and 'b' are COPIES of x and y.

    Therefore, a and b are stored at different
    memory locations.

    So:

        &x != &a
        &y != &b


    IMPORTANT:

    PASS BY VALUE:

        x → copy → a
        y → copy → b

    Therefore, the addresses are DIFFERENT.


    PASS BY REFERENCE:

        void showAddress(int &a, int &b)

    In that case:

        &x == &a
        &y == &b

    because a and b refer to the original variables.
*/

#include <iostream>
using namespace std;

// ==========================================================
// FUNCTION
// ==========================================================

// Pass by value
void showAddress(int a, int b)
{
    // Print addresses of function parameters
    cout << "Address of a in function: " << &a << endl;
    cout << "Address of b in function: " << &b << endl;
}

int main()
{
    int x = 10;
    int y = 20;

    // ======================================================
    // ADDRESSES IN MAIN
    // ======================================================

    cout << "Address of x in main: " << &x << endl;
    cout << "Address of y in main: " << &y << endl;

    // ======================================================
    // FUNCTION CALL
    // ======================================================

    showAddress(x, y);

    return 0;
}

/*
    EXPECTED CONCEPT:

    Address of x in main:    DIFFERENT
    Address of a in function: DIFFERENT

    Address of y in main:    DIFFERENT
    Address of b in function: DIFFERENT


    FINAL:

    Pass by Value
        → Copies are created
        → Different memory addresses


    Pass by Reference
        → No separate copy
        → Same memory addresses
*/