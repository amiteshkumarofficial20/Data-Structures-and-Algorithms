/*
    OPPOSITE CONCENTRIC NUMBER SQUARE PATTERN

    This program prints numbers in concentric layers.

    The pattern is the opposite of Pattern 36.

    For n = 4:

    1 1 1 1 1 1 1
    1 2 2 2 2 2 1
    1 2 3 3 3 2 1
    1 2 3 4 3 2 1
    1 2 3 3 3 2 1
    1 2 2 2 2 2 1
    1 1 1 1 1 1 1


    LOGIC:

    The outer boundary contains 1.

    The next layer contains 2.

    The next layer contains 3.

    The center contains n.

    For n = 4:

    Outer layer -> 1
    Layer 2     -> 2
    Layer 3     -> 3
    Center      -> 4


    We first find the layer number.

    The distance from the nearest boundary is:

        layer = min(top, bottom, left, right)

    Since the outer layer has value 1,
    we add 1 to the layer:

        value = layer + 1
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

    // Loop through rows
    for (int row = 0; row < size; row++)
    {
        // Loop through columns
        for (int column = 0; column < size; column++)
        {
            // Distance from the four boundaries
            int top = row;
            int left = column;
            int bottom = size - row - 1;
            int right = size - column - 1;

            // Find the nearest boundary
            int layer = min(min(top, bottom), min(left, right));

            // Outer layer = 1, next layer = 2, ...
            int value = layer + 1;

            cout << value << " ";
        }

        cout << endl;
    }

    return 0;
}

// int value = layer + 1;