/*
    SQUARE STAR PATTERN

    This program prints a square pattern of stars.

    The user enters a number 'n'.
    The value of 'n' determines the number of rows and columns
    of the square.

    For example, if n = 4, the program prints:

    * * * *
    * * * *
    * * * *
    * * * *


    LOGIC:

    The program uses two nested for loops.

    1. Outer loop:
       The outer loop controls the number of rows.

       for (int row = 1; row <= n; row++)

       It runs n times, so n rows are printed.


    2. Inner loop:
       The inner loop controls the number of columns.

       for (int column = 1; column <= n; column++)

       It also runs n times for every row.


    3. Star printing:
       Inside the inner loop, "* " is printed.

       Therefore, each row contains n stars.


    4. New line:
       After the inner loop finishes, cout << endl;
       moves the cursor to the next line.

       This creates the next row.


    PATTERN FORMULA:

    Number of Rows    = n
    Number of Columns = n
    Total Stars       = n × n


    Example:

    If n = 3:

    Row 1 -> * * *
    Row 2 -> * * *
    Row 3 -> * * *

    Total stars = 3 × 3 = 9
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    // Take the size of the square from the user
    cout << "Enter n: ";
    cin >> n;

    // Outer loop controls the rows
    for (int row = 1; row <= n; row++)
    {
        // Inner loop controls the columns
        for (int column = 1; column <= n; column++)
        {
            // Print star for each column
            cout << "* ";
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}