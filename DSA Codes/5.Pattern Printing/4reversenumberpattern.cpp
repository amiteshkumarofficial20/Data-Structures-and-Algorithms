/*
    REVERSE NUMBER PATTERN

    This program prints numbers from n to 1 in every row.

    Example:

    If n = 4:

    4 3 2 1
    4 3 2 1
    4 3 2 1
    4 3 2 1


    LOGIC:

    The program uses two nested for loops.

    1. Outer loop:
       The outer loop controls the number of rows.

       for (int row = 1; row <= n; row++)

       It runs n times.


    2. Inner loop:
       The inner loop prints numbers in reverse order.

       It starts from n:

       column = n

       and continues until:

       column >= 1

       After printing each number, column is decreased by 1.

       Therefore:

       n, n-1, n-2, ..., 2, 1


    3. Every time the outer loop starts a new row,
       the inner loop again starts from n.

    For n = 4:

    Row 1 -> 4 3 2 1
    Row 2 -> 4 3 2 1
    Row 3 -> 4 3 2 1
    Row 4 -> 4 3 2 1
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    // Take the number of rows and columns from the user
    cout << "Enter n: ";
    cin >> n;

    // Outer loop controls the rows
    for (int row = 1; row <= n; row++)
    {
        // Inner loop prints numbers from n to 1
        for (int column = n; column >= 1; column--)
        {
            cout << column << " ";
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}