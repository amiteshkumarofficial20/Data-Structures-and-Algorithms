/*
    NUMBER TRIANGLE PATTERN

    This program prints numbers from 1 to the current row number.

    Example:

    If n = 5:

    1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5


    LOGIC:

    The program uses two nested for loops.

    1. OUTER LOOP:

       for (int row = 1; row <= n; row++)

       The outer loop controls the number of rows.

       It runs from 1 to n.


    2. INNER LOOP:

       for (int column = 1; column <= row; column++)

       The inner loop controls how many numbers
       are printed in each row.

       The condition is:

       column <= row

       Therefore, the number of values printed
       increases with every row.


    WORKING:

    Row 1:
    column = 1
    Output: 1

    Row 2:
    column = 1, 2
    Output: 1 2

    Row 3:
    column = 1, 2, 3
    Output: 1 2 3

    Row 4:
    column = 1, 2, 3, 4
    Output: 1 2 3 4

    Row 5:
    column = 1, 2, 3, 4, 5
    Output: 1 2 3 4 5


    IMPORTANT:

    We print 'column' instead of 'row':

        cout << column << " ";

    Therefore, the numbers start from 1 in every row.

    If we printed 'row' instead, the pattern would be:

    1
    2 2
    3 3 3
    4 4 4 4
    5 5 5 5 5
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
        // Inner loop prints numbers from 1 to row
        for (int column = 1; column <= row; column++)
        {
            cout << column << " ";
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}