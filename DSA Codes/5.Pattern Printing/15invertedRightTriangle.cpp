/*
    INVERTED RIGHT-ANGLED STAR TRIANGLE

    This program prints a decreasing right-angled triangle
    using stars.

    Example:

    If n = 5:

    * * * * *
    * * * *
    * * *
    * *
    *


    LOGIC:

    The program uses two nested for loops.

    1. OUTER LOOP:

       for (int row = 1; row <= n; row++)

       The outer loop controls the number of rows.

       It starts from 1 and goes up to n.


    2. INNER LOOP:

       for (int column = 1; column <= n - (row - 1); column++)

       The inner loop controls the number of stars
       printed in each row.

       The number of stars decreases by 1 after every row.


    WORKING FOR n = 5:

    Row 1:
    n - (row - 1)
    = 5 - 0
    = 5 stars

    Row 2:
    5 - 1
    = 4 stars

    Row 3:
    5 - 2
    = 3 stars

    Row 4:
    5 - 3
    = 2 stars

    Row 5:
    5 - 4
    = 1 star


    Therefore:

    * * * * *
    * * * *
    * * *
    * *
    *


    ALTERNATIVE LOGIC:

    The same pattern can also be created by starting
    the outer loop from n and decreasing it:

    for (int row = n; row >= 1; row--)

    and then:

    for (int column = 1; column <= row; column++)

    Both approaches produce the same pattern.
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
        // Inner loop prints decreasing number of stars
        for (int column = 1; column <= n - (row - 1); column++)
        {
            cout << "* ";
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}