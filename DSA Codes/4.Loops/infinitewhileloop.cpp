#include <iostream>
using namespace std;

int main()
{
    int n = 10;

    // Here, n = 10 is an ASSIGNMENT.
    // It assigns 10 to n.
    //
    // The value of the assignment expression is 10.
    // Since 10 is a non-zero value, it is treated as true.
    //
    // Therefore, this loop is INFINITE.

    while (n = 10)
    {
        cout << n << endl;

        // Even though n becomes 11 here,
        // the next iteration again executes:
        //
        // n = 10
        //
        // So n becomes 10 again.
        n++;
    }

    return 0;
}

// ==========================================================
// CHARACTER CONDITION
// ==========================================================

// while ('a' < 'b')
// {
//     cout << "Hey Amitesh!" << endl;
// }

// 'a' has a smaller ASCII value than 'b'.
// Therefore:
//
// 'a' < 'b'
//
// is always true.
//
// So this is also an INFINITE LOOP.