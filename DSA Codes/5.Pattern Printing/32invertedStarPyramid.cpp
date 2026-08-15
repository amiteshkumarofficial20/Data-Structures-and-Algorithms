/*
    INVERTED STAR PYRAMID

    This program prints an inverted centered pyramid
    using stars.

    Example:

    If n = 5:

    *********
     *******
      *****
       ***
        *


    LOGIC:

    The outer loop runs from n down to 1.

        for (int row = n; row >= 1; row--)

    Therefore, the number of stars decreases in every row.


    1. SPACE LOOP:

       for (int space = 1; space <= n - row; space++)

       The number of spaces increases as row decreases.

       First row -> 0 spaces
       Second row -> 1 space
       Third row -> 2 spaces
       ...
       Last row -> n - 1 spaces


    2. STAR LOOP:

       for (int star = 1; star <= 2 * row - 1; star++)

       The number of stars is always odd.

       For n = 5:

       Row 1 -> 2(5) - 1 = 9 stars
       Row 2 -> 2(4) - 1 = 7 stars
       Row 3 -> 2(3) - 1 = 5 stars
       Row 4 -> 2(2) - 1 = 3 stars
       Row 5 -> 2(1) - 1 = 1 star


    3. RIGHT SPACE LOOP:

       for (int space = 1; space <= n - row; space++)

       Prints spaces after the stars to keep the pattern
       properly aligned.


    IMPORTANT:

    Stars decrease:

        2 * row - 1

    Spaces increase:

        n - row

    Therefore, the pyramid becomes inverted.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    // Take the number of rows from the user
    cout << "Enter n: ";
    cin >> n;

    // Outer loop runs from n down to 1
    for (int row = n; row >= 1; row--)
    {
        // Print spaces before the stars
        for (int space = 1; space <= n - row; space++)
        {
            cout << " ";
        }

        // Print stars in decreasing odd numbers
        for (int star = 1; star <= 2 * row - 1; star++)
        {
            cout << "*";
        }

        // Print spaces after the stars
        for (int space = 1; space <= n - row; space++)
        {
            cout << " ";
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}