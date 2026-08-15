/*
    ROW NUMBER PATTERN

    This program prints the row number repeatedly in every column.

    Example:

    If n = 4:

    1 1 1 1
    2 2 2 2
    3 3 3 3
    4 4 4 4


    LOGIC:

    The program uses two nested for loops.

    1. Outer loop:
       The outer loop controls the rows.

       for (int row = 1; row <= n; row++)

       The value of 'row' changes from 1 to n.


    2. Inner loop:
       The inner loop controls the columns.

       for (int column = 1; column <= n; column++)

       It runs n times for every row.


    3. Inside the inner loop, we print:

       cout << row << " ";

       We print 'row', NOT 'column'.

       Therefore, for row = 1:
       1 1 1 1

       For row = 2:
       2 2 2 2

       For row = 3:
       3 3 3 3

       For row = 4:
       4 4 4 4
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
            // Print the current row number
            cout << row << " ";
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}