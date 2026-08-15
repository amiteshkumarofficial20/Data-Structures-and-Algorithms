/*
    RIGHT-ALIGNED NUMBER TRIANGLE

    This program prints a right-aligned triangle
    using numbers.

    Example:

    If n = 5:

        1
       22
      333
     4444
    55555


    LOGIC:

    The program uses three parts:

    1. OUTER LOOP:
       Controls the rows.

       for (int row = 1; row <= n; row++)


    2. SPACE LOOP:
       Prints spaces before the numbers.

       for (int space = 1; space <= n - row; space++)

       Number of spaces decreases as the row increases.

       Row 1 -> n - 1 spaces
       Row 2 -> n - 2 spaces
       ...
       Row n -> 0 spaces


    3. NUMBER LOOP:
       Prints the current row number.

       for (int num = 1; num <= row; num++)

       The current 'row' number is printed repeatedly.

       Row 1 -> 1
       Row 2 -> 22
       Row 3 -> 333
       Row 4 -> 4444
       Row 5 -> 55555


    IMPORTANT:

    Spaces decrease:
        n - row

    Numbers increase:
        row

    Number of times the row number is printed:
        row
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

        // Print the row number
        for (int num = 1; num <= row; num++)
        {
            cout << row;
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}