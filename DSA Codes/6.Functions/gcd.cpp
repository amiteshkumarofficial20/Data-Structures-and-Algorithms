/*
    GCD USING FUNCTION

    GCD = Greatest Common Divisor

    GCD of two numbers is the greatest number that
    divides both numbers completely.

    Example:

        12 and 18

        Factors of 12:
        1, 2, 3, 4, 6, 12

        Factors of 18:
        1, 2, 3, 6, 9, 18

        GCD = 6


    LOGIC:

    We use the Euclidean Algorithm.

        gcd(a, b) = gcd(b, a % b)

    We continue until b becomes 0.

    When b = 0:

        a = GCD


    Example:

        gcd(18, 12)

        18 % 12 = 6
        12 % 6  = 0

        GCD = 6


    TIME COMPLEXITY:

        O(log(min(a, b)))

    SPACE COMPLEXITY:

        O(log(min(a, b))) for recursive calls.
*/

#include <iostream>
using namespace std;

// ==========================================================
// GCD FUNCTION
// ==========================================================

int gcd(int a, int b)
{
    // Base condition
    if (b == 0)
    {
        return a;
    }

    // Recursive Euclidean Algorithm
    return gcd(b, a % b);
}

int main()
{
    int a, b;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    // Function call
    cout << "GCD = " << gcd(a, b);

    return 0;
}