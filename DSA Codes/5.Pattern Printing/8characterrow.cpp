/*
    CHARACTER ROW PATTERN

    This program prints the same character in every column
    of a row.

    The character changes according to the row number.

    Example:

    If n = 4:

    a a a a
    b b b b
    c c c c
    d d d d


    LOGIC:

    The program uses two nested for loops.

    1. OUTER LOOP:

       for (int row = 1; row <= n; row++)

       The outer loop controls the rows.

       It runs from 1 to n.


    2. CHARACTER CALCULATION:

       We use:

       'a' + (row - 1)

       In ASCII:

       'a' = 97
       'b' = 98
       'c' = 99
       'd' = 100

       Therefore:

       row = 1:
       'a' + (1 - 1)
       = 'a' + 0
       = 'a'

       row = 2:
       'a' + (2 - 1)
       = 'a' + 1
       = 'b'

       row = 3:
       'a' + (3 - 1)
       = 'a' + 2
       = 'c'

       row = 4:
       'a' + (4 - 1)
       = 'a' + 3
       = 'd'


    3. char CONVERSION:

       'a' + (row - 1) produces an integer ASCII value.

       We use char() to convert that integer value
       back into a character.

       char('a' + (row - 1))


    4. INNER LOOP:

       for (int column = 1; column <= n; column++)

       The inner loop prints the same character n times.

       For example, when row = 2:

       ch = 'b'

       The inner loop prints:

       b b b b


    IMPORTANT:

    'char' is required if we want the output to be characters.

    Without char conversion, the ASCII values would be printed.

    Example:

    int ch = 'a' + (row - 1);

    Output:

    97 97 97 97
    98 98 98 98
    99 99 99 99
    100 100 100 100
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
        // Calculate the character using ASCII values
        char ch = char('A' + (row - 1));

        // Inner loop prints the character n times
        for (int column = 1; column <= n; column++)
        {
            cout << ch << " ";
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}