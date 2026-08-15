/*
    RIGHT-ALIGNED STAR TRIANGLE

    This program prints a right-aligned triangle using stars.

    Example:

    If n = 5:

            *
          * *
        * * *
      * * * *
    * * * * *


    LOGIC:

    The program uses two nested loops for each row.

    1. SPACE LOOP:

       for (int space = 1; space <= n - row; space++)

       This prints spaces before the stars.

       Number of spaces:

       Row 1 -> n - 1 spaces
       Row 2 -> n - 2 spaces
       Row 3 -> n - 3 spaces
       ...
       Row n -> 0 spaces

       Therefore, the stars move towards the right
       as we go from the first row to the last row.


    2. STAR LOOP:

       for (int star = 1; star <= row; star++)

       This prints stars according to the row number.

       Row 1 -> 1 star
       Row 2 -> 2 stars
       Row 3 -> 3 stars
       ...
       Row n -> n stars


    IMPORTANT:

    Spaces decrease:

        n - row

    Stars increase:

        row

    Therefore, the pattern becomes right-aligned.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    // Take the number of rows from the user
    cout << "Enter n: ";
    cin >> n;

    for (int row = 1; row <= n; row++)
    {
        // Print spaces before the stars
        for (int space = 1; space <= n - row; space++)
        {
            cout << "  ";
        }

        // Print stars according to the row number
        for (int star = 1; star <= row; star++)
        {
            cout << "* ";
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}