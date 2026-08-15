/*
    STAR CROSS PATTERN

    This program prints a cross (X) pattern using stars.

    Example:

    If n = 5:

    *       *
      *   *
        *
      *   *
    *       *


    LOGIC:

    A star is printed when it lies on either of the
    two diagonals.

    1. Main diagonal:

       row == column

       This creates:

       *
         *
           *
             *
               *


    2. Opposite diagonal:

       row + column == n + 1

       This creates:

               *
             *
           *
         *
       *


    Therefore, we print a star when:

       row == column || row + column == n + 1

    Otherwise, we print spaces.

    For proper alignment, we use two spaces for empty
    positions and "* " for stars.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    for (int row = 1; row <= n; row++)
    {
        for (int column = 1; column <= n; column++)
        {
            // Check both diagonals
            if (row == column || row + column == n + 1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }

        cout << endl;
    }

    return 0;
}