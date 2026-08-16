/*
    SUM USING FUNCTION

    This program takes two numbers from the user
    and calculates their sum using a function.

    LOGIC:

    1. Create a function named sum().
    2. Pass two numbers as arguments.
    3. Add the two numbers inside the function.
    4. Return the result.
    5. Print the returned result in main().

    Function:

        int sum(int a, int b)

    Here:
        a and b -> parameters
        int     -> return type
        return  -> returns the sum
*/

#include <iostream>
using namespace std;

// Function to calculate sum
int sum(int a, int b)
{
    return a + b;
}

int main()
{
    int a, b;

    // Take two numbers from the user
    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    // Function call
    int result = sum(a, b);

    // Print the result
    cout << "Sum = " << result;

    return 0;
}