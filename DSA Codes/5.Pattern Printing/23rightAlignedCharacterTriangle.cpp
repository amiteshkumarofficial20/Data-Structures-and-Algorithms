/*
    RIGHT-ALIGNED CHARACTER TRIANGLE

    This program prints characters from A to the current
    row character in a right-aligned triangular pattern.

    Example:

    If n = 5:

        A
       AB
      ABC
     ABCD
    ABCDE


    LOGIC:

    The program uses three parts:

    1. OUTER LOOP:

       for (int row = 1; row <= n; row++)

       The outer loop controls the rows.


    2. SPACE LOOP:

       for (int space = 1; space <= n - row; space++)

       This prints spaces before the characters.

       Number of spaces decreases as the row increases:

       Row 1 -> n - 1 spaces
       Row 2 -> n - 2 spaces
       Row 3 -> n - 3 spaces
       ...
       Row n -> 0 spaces


    3. CHARACTER LOOP:

       for (char character = 'A';
            character <= 'A' + (row - 1);
            character++)

       The character starts from 'A'.

       The ending character depends on the row.

       Row 1:
       A

       Row 2:
       A B

       Row 3:
       A B C

       Row 4:
       A B C D

       Row 5:
       A B C D E


    ASCII LOGIC:

       'A' = 65

       'A' + 0 = A
       'A' + 1 = B
       'A' + 2 = C
       'A' + 3 = D
       'A' + 4 = E


    IMPORTANT:

    Spaces decrease:

        n - row

    Characters increase:

        A to 'A' + (row - 1)

    Therefore, the character triangle becomes
    right-aligned.
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
        // Print spaces before the characters
        for (int space = 1; space <= n - row; space++)
        {
            cout << " ";
        }

        // Print characters from A to the current row character
        for (char character = 'A';
             character <= 'A' + (row - 1);
             character++)
        {
            cout << character;
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}