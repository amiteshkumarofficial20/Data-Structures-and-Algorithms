/*
    NUMBER PYRAMID PATTERN

    This program prints a centered pyramid using numbers.

    Example:

    If n = 5:

        1
       121
      12321
     1234321
    123454321


    LOGIC:

    The program uses one outer loop and four inner loops.

    1. OUTER LOOP:

       for (int row = 1; row <= n; row++)

       Controls the number of rows.


    2. LEFT SPACE LOOP:

       for (int space = 1; space <= n - row; space++)

       Prints spaces before the numbers.

       Spaces decrease as the row increases.


    3. INCREASING NUMBER LOOP:

       for (int num = 1; num <= row; num++)

       Prints numbers from 1 up to the current row.

       Row 1 -> 1
       Row 2 -> 1 2
       Row 3 -> 1 2 3
       Row 4 -> 1 2 3 4


    4. DECREASING NUMBER LOOP:

       for (int num = row - 1; num >= 1; num--)

       Prints numbers from row - 1 back down to 1.

       We start from row - 1 so that the middle number
       is not printed twice.

       Example for row = 4:

       First loop:
       1 2 3 4

       Second loop:
       3 2 1

       Combined:
       1 2 3 4 3 2 1


    5. RIGHT SPACE LOOP:

       for (int space = 1; space <= n - row; space++)

       Prints spaces after the numbers.


    IMPORTANT:

    Left spaces:
        n - row

    Increasing numbers:
        1 → row

    Decreasing numbers:
        row - 1 → 1

    This creates a centered number pyramid.
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

        // Print numbers in increasing order
        for (int num = 1; num <= row; num++)
        {
            cout << num;
        }

        // Print numbers in decreasing order
        for (int num = row - 1; num >= 1; num--)
        {
            cout << num;
        }

        // Print spaces after the numbers
        for (int space = 1; space <= n - row; space++)
        {
            cout << " ";
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}