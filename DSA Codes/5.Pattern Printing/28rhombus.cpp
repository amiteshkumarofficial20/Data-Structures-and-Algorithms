/*
    RHOMBUS STAR PATTERN

    This program prints a rhombus pattern using stars.

    Example:

    If n = 5:

    * * * * *
      * * * * *
        * * * * *
          * * * * *
            * * * * *


    LOGIC:

    The program uses two inner loops inside the outer loop.

    1. OUTER LOOP:

       for (int row = 1; row <= n; row++)

       Controls the number of rows.


    2. SPACE LOOP:

       for (int space = 1; space <= row - 1; space++)

       Prints spaces before the stars.

       As the row increases, the number of spaces
       also increases.

       Row 1 -> 0 spaces
       Row 2 -> 1 space
       Row 3 -> 2 spaces
       Row 4 -> 3 spaces
       Row 5 -> 4 spaces


    3. STAR LOOP:

       for (int column = 1; column <= n; column++)

       Prints n stars in every row.

       Therefore, every row has the same number
       of stars.


    IMPORTANT:

    Spaces increase:
        row - 1

    Stars remain constant:
        n

    This shifting of each row creates the rhombus shape.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    // Take the size of the rhombus from the user
    cout << "Enter n: ";
    cin >> n;

    // Outer loop controls the rows
    for (int row = 1; row <= n; row++)
    {
        // Print spaces before the stars
        for (int space = 1; space <= row - 1; space++)
        {
            cout << "  ";
        }

        // Print stars
        for (int column = 1; column <= n; column++)
        {
            cout << "* ";
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}