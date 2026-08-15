/*
    ODD NUMBER TRIANGLE PATTERN

    This program prints odd numbers in a triangular pattern.

    Example:

    If n = 5:

    1
    1 3
    1 3 5
    1 3 5 7
    1 3 5 7 9


    LOGIC:

    The program uses two nested for loops.

    1. OUTER LOOP:

       for (int row = 1; row <= n; row++)

       The outer loop controls the number of rows.


    2. INNER LOOP:

       for (int column = 1; column <= row; column++)

       The inner loop controls how many odd numbers
       are printed in each row.

       Row 1 -> 1 odd number
       Row 2 -> 2 odd numbers
       Row 3 -> 3 odd numbers
       Row 4 -> 4 odd numbers
       ...


    3. ODD NUMBER FORMULA:

       The nth odd number is:

       2 * column - 1

       Therefore:

       column = 1
       2 * 1 - 1 = 1

       column = 2
       2 * 2 - 1 = 3

       column = 3
       2 * 3 - 1 = 5

       column = 4
       2 * 4 - 1 = 7


    So every row starts again from 1 and prints
    the first 'row' odd numbers.
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
        // Inner loop controls the number of odd numbers
        for (int column = 1; column <= row; column++)
        {
            // Print odd numbers using the formula 2 * column - 1
            cout << 2 * column - 1 << " ";
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}