/*
    CHARACTER NUMBER TRIANGLE PATTERN

    This program prints characters in a triangular pattern.

    Example:

    If n = 5:

    a
    b b
    c c c
    d d d d
    e e e e e


    LOGIC:

    The program uses two nested for loops.

    1. OUTER LOOP:

       for (int row = 1; row <= n; row++)

       The outer loop controls the number of rows.


    2. CHARACTER CALCULATION:

       char ch = 'a' + (row - 1);

       The character changes according to the row.

       'a' + 0 = 'a'
       'a' + 1 = 'b'
       'a' + 2 = 'c'
       'a' + 3 = 'd'
       'a' + 4 = 'e'


    3. INNER LOOP:

       for (int column = 1; column <= row; column++)

       The inner loop prints the current character
       according to the row number.

       Row 1 -> 1 character
       Row 2 -> 2 characters
       Row 3 -> 3 characters
       Row 4 -> 4 characters
       Row 5 -> 5 characters


    IMPORTANT:

    The character depends on the ROW:

        char ch = 'a' + (row - 1);

    But the number of times the character is printed
    depends on the current ROW:

        column <= row

    Therefore, the pattern becomes:

    a
    b b
    c c c
    d d d d
    e e e e e
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
        // Calculate character using ASCII value
        char ch = 'a' + (row - 1);

        // Inner loop prints the character row times
        for (int column = 1; column <= row; column++)
        {
            cout << ch << " ";
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}
