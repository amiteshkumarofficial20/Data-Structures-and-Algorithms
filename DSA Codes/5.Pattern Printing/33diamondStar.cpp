/*
    DIAMOND STAR PATTERN

    This program prints a diamond-shaped pattern using stars.

    Example for n = 5:

        *
       * *
      * * *
     * * * *
    * * * * *
     * * * *
      * * *
       * *
        *


    LOGIC:

    The diamond is divided into two parts:

    1. UPPER HALF
    2. LOWER HALF


    UPPER HALF:

    The outer loop runs from 1 to n.

        for (int row = 1; row <= n; row++)

    Spaces:

        n - row

    Stars:

        row

    Therefore:

    Row 1 -> 4 spaces, 1 star
    Row 2 -> 3 spaces, 2 stars
    Row 3 -> 2 spaces, 3 stars
    Row 4 -> 1 space,  4 stars
    Row 5 -> 0 spaces, 5 stars


    LOWER HALF:

    The outer loop runs from n - 1 down to 1.

        for (int row = n - 1; row >= 1; row--)

    We start from n - 1 so that the middle row
    is NOT printed twice.

    Therefore:

    Row 4 -> 4 stars
    Row 3 -> 3 stars
    Row 2 -> 2 stars
    Row 1 -> 1 star


    IMPORTANT:

    Upper half:
        row increases

    Lower half:
        row decreases

    Spaces:
        n - row

    Stars:
        row

    The two halves together form a diamond.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    // Take the size of the diamond
    cout << "Enter n: ";
    cin >> n;

    // =========================
    // UPPER HALF
    // =========================

    for (int row = 1; row <= n; row++)
    {
        // Print spaces before the stars
        for (int space = 1; space <= n - row; space++)
        {
            cout << " ";
        }

        // Print stars
        for (int star = 1; star <= row; star++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    // =========================
    // LOWER HALF
    // =========================

    for (int row = n - 1; row >= 1; row--)
    {
        // Print spaces before the stars
        for (int space = 1; space <= n - row; space++)
        {
            cout << " ";
        }

        // Print stars
        for (int star = 1; star <= row; star++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}