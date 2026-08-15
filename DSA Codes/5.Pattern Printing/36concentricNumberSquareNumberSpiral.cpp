/*
    CONCENTRIC NUMBER SQUARE PATTERN

    This program prints numbers in concentric layers.

    Example for n = 4:

    4 4 4 4 4 4 4
    4 3 3 3 3 3 4
    4 3 2 2 2 3 4
    4 3 2 1 2 3 4
    4 3 2 2 2 3 4
    4 3 3 3 3 3 4
    4 4 4 4 4 4 4


    LOGIC:

    The size of the pattern is:

        2 * n - 1

    For n = 4:

        2 * 4 - 1 = 7

    So the pattern has 7 rows and 7 columns.


    For every position (row, column), we calculate
    the minimum distance from the four boundaries.

        top    = row
        left   = column
        bottom = size - row - 1
        right  = size - column - 1

    The smallest of these four values tells us
    which layer the position belongs to.

    Then:

        value = n - layer


    For n = 4:

    Outer layer  -> 4
    Next layer   -> 3
    Next layer   -> 2
    Center       -> 1


    Example:

    At the outer boundary:

        layer = 0
        value = 4 - 0 = 4


    One layer inside:

        layer = 1
        value = 4 - 1 = 3


    Center:

        layer = 3
        value = 4 - 3 = 1
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    // Take the size of the pattern
    cout << "Enter n: ";
    cin >> n;

    // Total size of the square
    int size = 2 * n - 1;

    // Loop through every row
    for (int row = 0; row < size; row++)
    {
        // Loop through every column
        for (int column = 0; column < size; column++)
        {
            // Distance from all four boundaries
            int top = row;
            int left = column;
            int bottom = size - row - 1;
            int right = size - column - 1;

            // Find the nearest boundary
            int layer = min(min(top, bottom), min(left, right));

            // Calculate the number for this layer
            int value = n - layer;

            cout << value << " ";
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}

// int layer = min(min(row, size - row - 1),
//                 min(column, size - column - 1));

// int value = n - layer;