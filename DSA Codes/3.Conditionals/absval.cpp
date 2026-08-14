/*
    ABSOLUTE VALUE IN C++

    Absolute value means the positive value of a number.

    Examples:

    10   -> 10
    -10  -> 10
    0    -> 0


    METHOD 1: USING abs() FUNCTION

    The abs() function directly returns the absolute value
    of an integer.

    Example:

    abs(-10) = 10


    METHOD 2: WITHOUT USING abs() FUNCTION

    We can find the absolute value using an if statement.

    If the number is negative, multiply it by -1.

    Example:

    number = -10

    number = -number

    number becomes:

    10
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    // Using abs() function
    cout << "Absolute value using abs() = "
         << abs(number) << endl;

    // Without using abs() function
    int absoluteValue = number;

    if (absoluteValue < 0)
    {
        absoluteValue = -absoluteValue;
    }

    cout << "Absolute value without function = "
         << absoluteValue << endl;

    return 0;
}