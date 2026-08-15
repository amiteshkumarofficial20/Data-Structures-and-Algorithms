/*
    INVERTED NUMBER TRIANGLE

    This program prints numbers in decreasing rows.

    Example:

    If n = 5:

    1 2 3 4 5
    1 2 3 4
    1 2 3
    1 2
    1


    LOGIC:

    The program uses two nested for loops.

    1. OUTER LOOP:

       for (int row = 1; row <= n; row++)

       The outer loop controls the number of rows.


    2. INNER LOOP:

       for (int column = 1; column <= n - (row - 1); column++)

       The inner loop controls the number of numbers
       printed in each row.

       The number of values decreases by 1 after
       every row.


    WORKING FOR n = 5:

    Row 1:
    5 - (1 - 1) = 5
    → 1 2 3 4 5

    Row 2:
    5 - (2 - 1) = 4
    → 1 2 3 4

    Row 3:
    5 - (3 - 1) = 3
    → 1 2 3

    Row 4:
    5 - (4 - 1) = 2
    → 1 2

    Row 5:
    5 - (5 - 1) = 1
    → 1


    ALTERNATIVE LOGIC:

    The same pattern can also be written as:

    for (int row = n; row >= 1; row--)
    {
        for (int column = 1; column <= row; column++)
        {
            cout << column << " ";
        }
        cout << endl;
    }

    Both approaches produce the same output.
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
        // Inner loop prints decreasing numbers of values
        for (int column = 1; column <= n - (row - 1); column++)
        {
            cout << column << " ";
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}