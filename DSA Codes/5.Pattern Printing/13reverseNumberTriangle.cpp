/*
    RIGHT-ALIGNED REVERSE NUMBER TRIANGLE

    This program prints numbers in decreasing order
    from the current row number down to 1.

    Example:

    If n = 5:

        1
       21
      321
     4321
    54321


    LOGIC:

    The program uses three parts:

    1. OUTER LOOP:

       for (int row = 1; row <= n; row++)

       The outer loop controls the rows.


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

       for (int num = row; num >= 1; num--)

       The number starts from the current row number
       and decreases down to 1.

       Row 1:
       1

       Row 2:
       2 1

       Row 3:
       3 2 1

       Row 4:
       4 3 2 1

       Row 5:
       5 4 3 2 1


    IMPORTANT:

    Spaces decrease:

        n - row

    Numbers decrease:

        row → 1

    Therefore, the pattern is both right-aligned
    and in reverse number order.
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

        // Print numbers from row down to 1
        for (int num = row; num >= 1; num--)
        {
            cout << num;
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}