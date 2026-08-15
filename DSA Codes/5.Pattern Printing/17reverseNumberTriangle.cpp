/*
    REVERSE NUMBER TRIANGLE

    This program prints numbers starting from n and
    moving backwards up to the starting number of each row.

    Example:

    If n = 5:

    5
    5 4
    5 4 3
    5 4 3 2
    5 4 3 2 1


    LOGIC:

    The program uses two nested for loops.

    1. OUTER LOOP:

       for (int row = 1; row <= n; row++)

       The outer loop controls the number of rows.


    2. INNER LOOP:

       for (int column = n; column >= n - row + 1; column--)

       The inner loop starts from n and decreases
       until it reaches:

       n - row + 1


    WORKING FOR n = 5:

    Row 1:
    column = 5 to 5
    → 5

    Row 2:
    column = 5 to 4
    → 5 4

    Row 3:
    column = 5 to 3
    → 5 4 3

    Row 4:
    column = 5 to 2
    → 5 4 3 2

    Row 5:
    column = 5 to 1
    → 5 4 3 2 1


    IMPORTANT:

    The starting value of the inner loop is always n.

    The ending value changes according to the row:

    n - row + 1

    As the row number increases, the ending value decreases.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    // Take the size of the pattern from the user
    cout << "Enter n: ";
    cin >> n;

    // Outer loop controls the rows
    for (int row = 1; row <= n; row++)
    {
        // Inner loop prints numbers from n down to n-row+1
        for (int column = n; column >= n - row + 1; column--)
        {
            cout << column << " ";
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}