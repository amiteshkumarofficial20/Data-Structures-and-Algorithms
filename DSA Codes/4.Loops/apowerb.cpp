/*
    POWER OF A NUMBER

    In this program, we calculate A raised to the power B.

    Example:

    A = 2
    B = 5

    2^5 = 2 × 2 × 2 × 2 × 2
        = 32


    LOGIC:

    We take two numbers:

    A = Base
    B = Power / Exponent

    We initialize:

    power = 1

    Then we run a for loop B times.

    In every iteration:

    power = power * A

    Therefore, A gets multiplied by itself B times.


    Example:

    A = 3
    B = 4

    Initially:

    power = 1

    1st iteration:
    power = 1 × 3 = 3

    2nd iteration:
    power = 3 × 3 = 9

    3rd iteration:
    power = 9 × 3 = 27

    4th iteration:
    power = 27 × 3 = 81

    Therefore:

    3^4 = 81
*/

#include <iostream>
using namespace std;

int main()
{
    int A, B;
    int power = 1;

    cout << "Enter base A: ";
    cin >> A;

    cout << "Enter power B: ";
    cin >> B;

    for (int i = 1; i <= B; i++)
    {
        power = power * A;
    }

    cout << "Answer = " << power;

    return 0;
}