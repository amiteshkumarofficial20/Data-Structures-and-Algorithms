/*
    POWER OF A NUMBER WITH NEGATIVE POWER

    We want to calculate:

    A^(-B)

    Formula:

    A^(-B) = 1 / A^B

    Example:

    2^(-3)

    = 1 / 2^3
    = 1 / 8
    = 0.125

    First, we calculate A^B using a loop.

    Then, because the power is negative, we take:

    1 / power
*/

#include <iostream>
using namespace std;

int main()
{
    int A, B;
    double power = 1;

    cout << "Enter base A: ";
    cin >> A;

    cout << "Enter power B: ";
    cin >> B;

    for (int i = 1; i <= B; i++)
    {
        power = power * A;
    }

    power = 1 / power;

    cout << "Answer = " << power;

    return 0;
}