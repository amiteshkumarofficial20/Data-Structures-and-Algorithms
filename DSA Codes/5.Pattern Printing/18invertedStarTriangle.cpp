/*
    INVERTED STAR TRIANGLE

    This program prints a decreasing number of stars
    from n to 1.

    Example:

    If n = 4:

    * * * *
    * * *
    * *
    *


    LOGIC:

    The program uses two nested for loops.

    1. OUTER LOOP:

       for (int row = n; row >= 1; row--)

       The outer loop starts from n and decreases
       up to 1.

       Therefore, the number of rows is n.


    2. INNER LOOP:

       for (int column = 1; column <= row; column++)

       The inner loop prints stars according to
       the current value of row.

       Since row decreases by 1 after every iteration,
       the number of stars also decreases by 1.


    WORKING FOR n = 4:

    Row 1:
    row = 4
    → 4 stars

    Row 2:
    row = 3
    → 3 stars

    Row 3:
    row = 2
    → 2 stars

    Row 4:
    row = 1
    → 1 star


    OUTPUT:

    * * * *
    * * *
    * *
    *


    IMPORTANT:

    Outer loop:
        n → 1

    Inner loop:
        1 → row

    Therefore, the pattern contains:

    n stars
    n-1 stars
    n-2 stars
    ...
    1 star
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    // Take the number of stars from the user
    cout << "Enter n: ";
    cin >> n;

    // Outer loop controls the rows and decreases from n to 1
    for (int row = n; row >= 1; row--)
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