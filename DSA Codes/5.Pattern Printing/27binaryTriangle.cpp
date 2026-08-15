/*
    BINARY TRIANGLE

    This program prints a binary number triangle.

    Example:

    If n = 5:

    1
    01
    101
    0101
    10101


    LOGIC:

    The program uses two nested for loops.

    1. OUTER LOOP:

       Controls the number of rows.

       for (int row = 1; row <= n; row++)


    2. INNER LOOP:

       Controls the number of elements in each row.

       for (int column = 1; column <= row; column++)


    3. BINARY LOGIC:

       We use:

       (row + column) % 2

       If the result is 0, print 1.
       Otherwise, print 0.

       Example:

       Row 1:
       (1 + 1) % 2 = 0 → 1

       Row 2:
       (2 + 1) % 2 = 1 → 0
       (2 + 2) % 2 = 0 → 1

       Therefore:

       1
       01
       101
       0101
       10101
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    // Take the number of rows from the user
    cout << "Enter n: ";
    cin >> n;

    // Outer loop controls the rows
    for (int row = 1; row <= n; row++)
    {
        // Inner loop controls the columns
        for (int column = 1; column <= row; column++)
        {
            // Print 1 and 0 alternately
            if ((row + column) % 2 == 0)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}