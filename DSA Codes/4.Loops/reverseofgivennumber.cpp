/*
    REVERSE OF A GIVEN NUMBER

    In this program, we take a number from the user
    and print its reverse.

    Example:

    Number = 12345

    Reverse:

    54321


    LOGIC:

    num % 10
    ----------------
    Gives the last digit of the number.

    num / 10
    ----------------
    Removes the last digit from the number.

    To create the reverse number:

    reverse = reverse * 10 + last digit


    Example:

    num = 123

    Last digit = 123 % 10 = 3
    reverse = 0 * 10 + 3 = 3

    num = 123 / 10 = 12


    Last digit = 12 % 10 = 2
    reverse = 3 * 10 + 2 = 32

    num = 12 / 10 = 1


    Last digit = 1 % 10 = 1
    reverse = 32 * 10 + 1 = 321

    num = 1 / 10 = 0

    Loop stops.

    Final reverse = 321
*/

#include <iostream>
using namespace std;

int main()
{
    int num;
    int reverse = 0;

    cout << "Enter a number: ";
    cin >> num;

    while (num > 0)
    {
        // Get the last digit
        int digit = num % 10;

        // Add the digit to the reverse number
        reverse = reverse * 10 + digit;

        // Remove the last digit
        num = num / 10;
    }

    cout << "Reverse of the number = " << reverse;

    return 0;
}