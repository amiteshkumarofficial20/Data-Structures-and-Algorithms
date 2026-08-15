/*
    CONTINUOUS NUMBER PATTERN

    This program prints continuous numbers in a square pattern.

    The user enters a number 'n'.
    The value of 'n' represents the number of rows
    and the number of columns.

    Example:

    If n = 4:

    1 2 3 4
    5 6 7 8
    9 10 11 12
    13 14 15 16


    LOGIC:

    We use a variable 'k' to store the number that
    needs to be printed.

    Initially:

    k = 1

    The program uses two nested loops.

    1. Outer loop:
       The outer loop controls the rows.

    2. Inner loop:
       The inner loop controls the columns.

    Inside the inner loop:

    cout << k << " ";

    This prints the current value of k.

    After printing the number:

    k++;

    increases the value of k by 1.

    Therefore:

    1 -> 2 -> 3 -> 4 -> 5 -> 6 -> ...

    The value of k continues increasing even when
    the next row starts.

    Example for n = 4:

    First row:

    k = 1
    1 2 3 4

    Second row:

    k = 5
    5 6 7 8

    Third row:

    k = 9
    9 10 11 12

    Fourth row:

    k = 13
    13 14 15 16


    IMPORTANT:

    k is declared outside both loops because we want
    its value to continue from one row to the next.

    If k were declared inside the inner loop,
    it would restart again for every row.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    int k = 1;

    // Take the size of the pattern from the user
    cout << "Enter n: ";
    cin >> n;

    // Outer loop controls the rows
    for (int row = 1; row <= n; row++)
    {
        // Inner loop controls the columns
        for (int column = 1; column <= n; column++)
        {
            // Print the current value of k
            cout << k << " ";

            // Increase k by 1
            k++;
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}