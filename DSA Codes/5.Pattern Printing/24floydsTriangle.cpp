/*
    FLOYD'S TRIANGLE

    This program prints continuous numbers in a triangular pattern.

    Example:

    If n = 5:

    1
    2 3
    4 5 6
    7 8 9 10
    11 12 13 14 15


    LOGIC:

    We use a variable 'k' to store the number
    that needs to be printed.

    Initially:

    k = 1

    The program uses two nested for loops.

    1. OUTER LOOP:

       Controls the number of rows.

       for (int row = 1; row <= n; row++)


    2. INNER LOOP:

       Controls how many numbers are printed
       in the current row.

       for (int column = 1; column <= row; column++)


    3. PRINTING:

       cout << k << " ";

       After printing the number:

       k++;

       So the value of k continuously increases.

       1 → 2 → 3 → 4 → 5 → 6 → ...


    WORKING FOR n = 5:

    Row 1:
    1

    Row 2:
    2 3

    Row 3:
    4 5 6

    Row 4:
    7 8 9 10

    Row 5:
    11 12 13 14 15


    IMPORTANT:

    The number of elements in each row is equal
    to the row number.

    Row 1 → 1 number
    Row 2 → 2 numbers
    Row 3 → 3 numbers
    Row 4 → 4 numbers
    Row 5 → 5 numbers
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int k = 1;

    // Take the number of rows from the user
    cout << "Enter n: ";
    cin >> n;

    // Outer loop controls the rows
    for (int row = 1; row <= n; row++)
    {
        // Inner loop controls the numbers in each row
        for (int column = 1; column <= row; column++)
        {
            // Print the current number
            cout << k << " ";

            // Increase k for the next number
            k++;
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}