/*
    FACTORIAL - ITERATIVE APPROACH

    Factorial of a number n is the product of all positive
    integers from 1 to n.

    Formula:

    n! = n × (n-1) × (n-2) × ... × 2 × 1

    Example:

    5! = 5 × 4 × 3 × 2 × 1
       = 120

    In the iterative approach, we use a loop to calculate
    the factorial.

    We start with factorial = 1 because multiplying by 1
    does not change the result.

    Then, in every iteration, we multiply factorial by i.

    factorial = factorial * i

    For n = 5:

    factorial = 1

    i = 1
    factorial = 1 × 1 = 1

    i = 2
    factorial = 1 × 2 = 2

    i = 3
    factorial = 2 × 3 = 6

    i = 4
    factorial = 6 × 4 = 24

    i = 5
    factorial = 24 × 5 = 120

    Therefore:

    5! = 120
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    int factorial = 1;

    cout << "Enter a number: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        factorial = factorial * i;
    }

    cout << "Factorial = " << factorial;

    return 0;
}