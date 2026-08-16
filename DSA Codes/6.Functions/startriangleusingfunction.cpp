/*
    STAR TRIANGLE USING FUNCTION

    This program prints a star triangle using a function.

    Example for n = 4:

    *
    * *
    * * *
    * * * *


    LOGIC:

    1. FUNCTION:

       void starTriangle(int n)

       The function takes 'n' as an argument.

       'n' decides the number of rows in the triangle.


    2. NESTED LOOPS:

       Outer loop:
           Controls the rows.

       Inner loop:
           Prints stars according to the current row.


    3. FUNCTION CALL:

       starTriangle(n);

       The function is called three times in main().

       Therefore, the complete star triangle is printed
       three times.


    IMPORTANT:

    Instead of writing the complete pattern code
    three times, we write it once inside the function
    and call the function whenever required.

    This demonstrates CODE REUSABILITY.
*/

#include <iostream>
using namespace std;

// Function to print a star triangle
void starTriangle(int n)
{
    // Outer loop controls the rows
    for (int row = 1; row <= n; row++)
    {
        // Inner loop prints stars according to the row
        for (int column = 1; column <= row; column++)
        {
            cout << "* ";
        }

        // Move to the next row
        cout << endl;
    }
}

int main()
{
    int n;

    // Take the number of rows from the user
    cout << "Enter n: ";
    cin >> n;

    // Call the function three times
    starTriangle(n);
    starTriangle(n);
    starTriangle(n);

    return 0;
}