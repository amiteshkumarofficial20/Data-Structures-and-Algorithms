/*
    STAR PLUS PATTERN

    This program prints a Star Plus (+) pattern.

    Example for n = 5:

        *
        *
    * * * * *
        *
        *

    We use two spaces for every empty position so that
    the horizontal and vertical spacing looks consistent.

    LOGIC:

    The middle row contains stars.
    The middle column contains stars.

    For n = 5:

    Middle position = n / 2 + 1
                    = 5 / 2 + 1
                    = 3

    Therefore:

    row == 3
    OR
    column == 3

    If either condition is true, print a star.
    Otherwise, print two spaces.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    // Find the middle row and middle column
    int middle = n / 2 + 1;

    for (int row = 1; row <= n; row++)
    {
        for (int column = 1; column <= n; column++)
        {
            if (row == middle || column == middle)
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