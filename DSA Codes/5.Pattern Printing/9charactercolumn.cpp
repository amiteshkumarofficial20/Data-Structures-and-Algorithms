/*
    CHARACTER COLUMN PATTERN

    This program prints alphabets from 'a' onwards
    in every row.

    Example:

    If n = 4:

    a b c d
    a b c d
    a b c d
    a b c d


    LOGIC:

    The program uses two nested loops.

    1. OUTER LOOP:

       for (row = 1; row <= n; row++)

       The outer loop controls the number of rows.


    2. INNER LOOP:

       for (column = 1; column <= n; column++)

       The inner loop controls the number of characters
       printed in each row.


    3. ASCII VALUE ADDITION:

       We use:

       char ch = 'a' + (column - 1);

       The character 'a' has ASCII value 97.

       Therefore:

       column = 1
       'a' + (1 - 1) = 'a'

       column = 2
       'a' + (2 - 1) = 'b'

       column = 3
       'a' + (3 - 1) = 'c'

       column = 4
       'a' + (4 - 1) = 'd'


    4. The character depends on the COLUMN,
       not on the ROW.

       Therefore every row prints:

       a b c d ...


    IMPORTANT:

    If we use:

       char ch = 'a' + (row - 1);

    the character changes according to the row.

    Output:

       a a a a
       b b b b
       c c c c
       d d d d


    But here we use:

       char ch = 'a' + (column - 1);

    So the character changes according to the column.

    Output:

       a b c d
       a b c d
       a b c d
       a b c d
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int row, column;

    // Take the size of the pattern
    cout << "Enter n: ";
    cin >> n;

    // Outer loop controls the rows
    for (row = 1; row <= n; row++)
    {
        // Inner loop controls the columns
        for (column = 1; column <= n; column++)
        {
            // Convert ASCII value into a character
            char ch = 'A' + (column - 1);

            // Print the current character
            cout << ch << " ";
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}