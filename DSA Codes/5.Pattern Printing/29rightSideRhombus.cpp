/*
    RIGHT-SIDE RHOMBUS STAR PATTERN

    This program prints a rhombus aligned towards the right side.

    Example for n = 5:

            * * * * *
          * * * * *
        * * * * *
      * * * * *
    * * * * *


    LOGIC:

    The program uses three loops.

    1. OUTER LOOP:
       Controls the rows.

       for (int row = 1; row <= n; row++)


    2. SPACE LOOP:
       Prints spaces before the stars.

       Number of spaces decreases with every row.

       Row 1 -> n - 1 spaces
       Row 2 -> n - 2 spaces
       Row 3 -> n - 3 spaces
       ...
       Row n -> 0 spaces


    3. STAR LOOP:
       Prints n stars in every row.

       Therefore, every row has the same number
       of stars.


    IMPORTANT:

    Spaces decrease:
        n - row

    Stars remain constant:
        n

    This creates a rhombus shifted towards the right.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    // Outer loop controls the rows
    for (int row = 1; row <= n; row++)
    {
        // Print decreasing spaces
        for (int space = 1; space <= n - row; space++)
        {
            cout << "  ";
        }

        // Print n stars in every row
        for (int column = 1; column <= n; column++)
        {
            cout << "* ";
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}