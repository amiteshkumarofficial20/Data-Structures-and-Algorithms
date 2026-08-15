/*
    SQUARE NUMBER PATTERN

    This program prints the square of each column number
    in every row.

    Example:

    If n = 4:

    1 4 9 16
    1 4 9 16
    1 4 9 16
    1 4 9 16


    LOGIC:

    The program uses two nested for loops.

    1. OUTER LOOP:

       for (int row = 1; row <= n; row++)

       The outer loop controls the number of rows.

       It runs from 1 to n.


    2. INNER LOOP:

       for (int column = 1; column <= n; column++)

       The inner loop controls the columns.

       It also runs from 1 to n.


    3. SQUARE OF COLUMN:

       Inside the inner loop:

       column * column

       is used to calculate the square of the
       current column number.

       For example:

       column = 1
       1 * 1 = 1

       column = 2
       2 * 2 = 4

       column = 3
       3 * 3 = 9

       column = 4
       4 * 4 = 16


    Therefore, every row contains:

    1 4 9 16 ...


    IMPORTANT:

    We are printing 'column * column', not 'row * row'.

    Therefore, the same square-number sequence is
    repeated in every row.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    // Take the size of the pattern from the user
    cout << "Enter n: ";
    cin >> n;

    // Outer loop controls the rows
    for (int row = 1; row <= n; row++)
    {
        // Inner loop controls the columns
        for (int column = 1; column <= n; column++)
        {
            // Print the square of the current column
            cout << column * column << " ";
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}