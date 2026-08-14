/*
    EVEN AND ODD USING TERNARY OPERATOR

    A number is called EVEN if it is completely divisible by 2.

    Example:
    10 % 2 = 0

    Therefore, 10 is an even number.


    A number is called ODD if it is not completely divisible by 2.

    Example:
    7 % 2 = 1

    Therefore, 7 is an odd number.


    We can use the modulus operator (%) to check whether
    a number is even or odd.

    Condition:

    number % 2 == 0

    If the condition is true:
    The number is EVEN.

    If the condition is false:
    The number is ODD.


    TERNARY OPERATOR:

    condition ? true_result : false_result;


    For even and odd:

    (number % 2 == 0) ? "Even" : "Odd"

    If number % 2 == 0 is true, "Even" is selected.

    Otherwise, "Odd" is selected.
*/

#include <iostream>
using namespace std;

int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    string result = (number % 2 == 0) ? "Even" : "Odd";

    cout << "The number is " << result << endl;

    return 0;
}