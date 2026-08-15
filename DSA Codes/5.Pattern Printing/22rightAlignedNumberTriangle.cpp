/*
    RIGHT-ALIGNED NUMBER TRIANGLE

    This program prints numbers from 1 to the current
    row number in a right-aligned triangular pattern.

    Example:

    If n = 5:

        1
       12
      123
     1234
    12345


    LOGIC:

    The program uses three loops/parts:

    1. OUTER LOOP:

       for (int row = 1; row <= n; row++)

       The outer loop controls the number of rows.


    2. SPACE LOOP:

       for (int space = 1; space <= n - row; space++)

       This prints spaces before the numbers.

       Number of spaces decreases as the row increases:

       Row 1 -> n - 1 spaces
       Row 2 -> n - 2 spaces
       Row 3 -> n - 3 spaces
       ...
       Row n -> 0 spaces


    3. NUMBER LOOP:

       for (int num = 1; num <= row; num++)

       This prints numbers from 1 to the current row number.

       Row 1 -> 1
       Row 2 -> 1 2
       Row 3 -> 1 2 3
       Row 4 -> 1 2 3 4
       Row 5 -> 1 2 3 4 5


    IMPORTANT:

    Spaces decrease:

        n - row

    Numbers increase:

        1 to row

    Therefore, the triangle becomes right-aligned.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    // Take the number of rows from the user
    cout << "Enter n: ";
    cin >> n;

    // Outer loop controls the rows
    for (int row = 1; row <= n; row++)
    {
        // Print spaces before the numbers
        for (int space = 1; space <= n - row; space++)
        {
            cout << " ";
        }

        // Print numbers from 1 to row
        for (int num = 1; num <= row; num++)
        {
            cout << num;
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}