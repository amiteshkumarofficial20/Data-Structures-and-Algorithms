/*
    EQUALITY OPERATORS IN C++

    Equality operators are used to compare two values
    and check whether they are equal or different.

    There are two equality operators in C++:

    ==    Equal to
    !=    Not equal to


    EQUAL TO OPERATOR (==)

    The '==' operator checks whether two values are equal.

    If both values are equal, the result is true.

    Example:

    10 == 10

    Result:

    true


    If the values are different:

    10 == 20

    Result:

    false


    NOT EQUAL TO OPERATOR (!=)

    The '!=' operator checks whether two values are different.

    If the values are different, the result is true.

    Example:

    10 != 20

    Result:

    true


    If the values are equal:

    10 != 10

    Result:

    false


    IMPORTANT DIFFERENCE BETWEEN = AND ==

    '=' and '==' are completely different operators.

    '=' is the assignment operator.

    Example:

    int a = 10;

    Here, the value 10 is assigned to variable 'a'.


    '==' is the equality operator.

    Example:

    a == 10;

    Here, C++ checks whether 'a' is equal to 10.


    REMEMBER:

    =       Assignment
    ==      Equal to
    !=      Not equal to


    BOOLEAN RESULT

    Equality operators return a Boolean result.

    The result can be:

    true
    false


    By default, C++ represents:

    true  = 1
    false = 0


    To display true and false instead of 1 and 0,
    we can use:

    cout << boolalpha;


    USE OF EQUALITY OPERATORS

    Equality operators are commonly used in conditions
    and if statements.

    Example:

    if(age == 18)
    {
        cout << "Age is exactly 18";
    }


    Another example:

    if(number != 0)
    {
        cout << "Number is not zero";
    }


    SUMMARY

    ==      Checks whether two values are equal.

    !=      Checks whether two values are different.

    Both operators produce a Boolean result.

    Always remember:

    =       Assignment operator
    ==      Equality operator
    !=      Not equal operator
*/

#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << boolalpha;

    cout << "a == b : " << (a == b) << endl;
    cout << "a != b : " << (a != b) << endl;

    return 0;
}
