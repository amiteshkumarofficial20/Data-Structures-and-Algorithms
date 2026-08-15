/*
    NTH FIBONACCI NUMBER - ITERATIVE APPROACH

    The Fibonacci series is a sequence in which every term is
    obtained by adding the previous two terms.

    Fibonacci Series:

    0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

    Formula:

    F(n) = F(n - 1) + F(n - 2)

    The first two Fibonacci numbers are:

    F(0) = 0
    F(1) = 1

    To find the nth Fibonacci number using the iterative
    approach, we use a loop instead of recursion.

    We keep two variables:

    first  -> stores the previous Fibonacci number
    second -> stores the current Fibonacci number

    Then we calculate:

    next = first + second

    After calculating the next term:

    first = second
    second = next

    Example:

    n = 6

    Fibonacci sequence:

    0  1  1  2  3  5  8

    Therefore:

    F(6) = 8
*/

#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    int first = 0;
    int second = 1;
    int next;

    if (n == 0)
    {
        cout << "Fibonacci number = 0";
    }
    else if (n == 1)
    {
        cout << "Fibonacci number = 1";
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            // Calculate the next Fibonacci number
            next = first + second;

            // Move the values forward
            first = second;
            second = next;
        }

        cout << "Fibonacci number = " << second;
    }

    return 0;
}