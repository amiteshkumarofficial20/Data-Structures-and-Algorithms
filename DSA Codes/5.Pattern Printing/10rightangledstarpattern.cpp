/*
    RIGHT ANGLED STAR PATTERN

    This program prints a right-angled triangle pattern
    using stars.

    Example:

    If n = 5:

    *
    * *
    * * *
    * * * *
    * * * * *


    LOGIC:

    The program uses two nested for loops.

    1. OUTER LOOP:

       for (int row = 1; row <= n; row++)

       The outer loop controls the number of rows.

       It runs from 1 to n.


    2. INNER LOOP:

       for (int column = 1; column <= row; column++)

       The inner loop controls the number of stars
       printed in each row.

       The important point is:

       column <= row

       This means the number of stars depends on
       the current row number.


    WORKING:

    Row 1:
    column = 1
    → 1 star

    Row 2:
    column = 1, 2
    → 2 stars

    Row 3:
    column = 1, 2, 3
    → 3 stars

    Row 4:
    column = 1, 2, 3, 4
    → 4 stars

    Row 5:
    column = 1, 2, 3, 4, 5
    → 5 stars


    Therefore, the number of stars in each row is
    equal to the row number.

    Row 1 → 1 star
    Row 2 → 2 stars
    Row 3 → 3 stars
    Row 4 → 4 stars
    Row 5 → 5 stars


    IMPORTANT:

    If we used:

    column <= n

    then every row would contain n stars and we
    would get a solid square.

    But here:

    column <= row

    so the number of stars increases by one in every row.
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
        // Inner loop prints stars according to the row number
        for (int column = 1; column <= row; column++)
        {
            cout << "* ";
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}