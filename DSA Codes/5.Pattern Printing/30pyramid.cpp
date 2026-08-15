/*
    PYRAMID STAR PATTERN

    This program prints a centered pyramid using stars.

    Example:

    If n = 5:

        *
       ***
      *****
     *******
    *********


    LOGIC:

    The program uses three loops inside the outer loop.

    1. OUTER LOOP:

       for (int row = 1; row <= n; row++)

       Controls the number of rows.


    2. SPACE LOOP:

       for (int space = 1; space <= n - row; space++)

       Prints spaces before the stars.

       Spaces decrease as the row increases:

       Row 1 -> n - 1 spaces
       Row 2 -> n - 2 spaces
       Row 3 -> n - 3 spaces
       ...
       Row n -> 0 spaces


    3. STAR LOOP:

       for (int star = 1; star <= 2 * row - 1; star++)

       Prints an odd number of stars in each row.

       Number of stars:

       Row 1 -> 1 star
       Row 2 -> 3 stars
       Row 3 -> 5 stars
       Row 4 -> 7 stars
       Row 5 -> 9 stars

       Formula:

       Number of stars = 2 * row - 1


    4. END SPACES:

       for (int space = 1; space <= n - row; space++)

       Prints spaces after the stars.

       These spaces are used to keep the pattern balanced
       in the output.


    IMPORTANT:

    Spaces decrease:

        n - row

    Stars increase by 2:

        2 * row - 1

    Therefore, the pyramid becomes centered.
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
        // Print spaces before the stars
        for (int space = 1; space <= n - row; space++)
        {
            cout << " ";
        }

        // Print odd number of stars
        for (int star = 1; star <= 2 * row - 1; star++)
        {
            cout << "*";
        }

        // Print spaces after the stars
        for (int space = 1; space <= n - row; space++)
        {
            cout << " ";
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}