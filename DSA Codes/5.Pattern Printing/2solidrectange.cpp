/*
    SOLID RECTANGLE STAR PATTERN

    This program prints a solid rectangle using stars.

    The user enters the number of rows and columns.

    Example:

    rows = 3
    columns = 5

    Output:

    * * * * *
    * * * * *
    * * * * *


    LOGIC:

    We use two nested for loops.

    1. Outer loop:
       Controls the number of rows.

    2. Inner loop:
       Controls the number of stars in each row.

    The inner loop runs 'columns' times for every row.

    Therefore:

    Total number of stars = rows × columns
*/

#include <iostream>
using namespace std;

int main()
{
    int rows, columns;

    // Take number of rows from the user
    cout << "Enter rows: ";
    cin >> rows;

    // Take number of columns from the user
    cout << "Enter columns: ";
    cin >> columns;

    // Outer loop controls rows
    for (int row = 1; row <= rows; row++)
    {
        // Inner loop controls columns
        for (int column = 1; column <= columns; column++)
        {
            // Print star
            cout << "* ";
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}