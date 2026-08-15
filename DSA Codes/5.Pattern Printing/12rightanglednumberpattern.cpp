/*
    NUMBER TRIANGLE PATTERN

    This program prints the row number repeatedly in each row.

    Example:

    If n = 5:

    1
    2 2
    3 3 3
    4 4 4 4
    5 5 5 5 5


    LOGIC:

    The program uses two nested for loops.

    1. OUTER LOOP:

       for (int row = 1; row <= n; row++)

       The outer loop controls the rows.

       It runs from 1 to n.


    2. INNER LOOP:

       for (int column = 1; column <= row; column++)

       The inner loop controls how many numbers
       are printed in each row.

       The condition:

       column <= row

       means the number of values increases
       with every new row.


    3. PRINTING THE ROW NUMBER:

       Inside the inner loop we use:

       cout << row << " ";

       Here we print 'row', not 'column'.

       Therefore, the same number is repeated
       throughout the current row.


    WORKING:

    Row 1:
    row = 1
    → 1

    Row 2:
    row = 2
    → 2 2

    Row 3:
    row = 3
    → 3 3 3

    Row 4:
    row = 4
    → 4 4 4 4

    Row 5:
    row = 5
    → 5 5 5 5 5


    IMPORTANT:

    If we use:

        cout << column << " ";

    the pattern becomes:

    1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5

    But when we use:

        cout << row << " ";

    the row number is repeated.
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
        // Inner loop controls the number of values in each row
        for (int column = 1; column <= row; column++)
        {
            // Print the current row number
            cout << row << " ";
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}