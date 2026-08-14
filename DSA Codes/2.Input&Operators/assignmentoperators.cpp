// Assignment Operators in C++
//
// Assignment operators are used to assign a value
// to a variable.
//
// Basic Assignment Operator:
// =    Assigns a value to a variable
//
// Compound Assignment Operators:
// +=   Add and assign
// -=   Subtract and assign
// *=   Multiply and assign
// /=   Divide and assign
// %=   Modulus and assign

#include <iostream>
using namespace std;

int main()
{
    int a = 10;

    // Basic assignment
    a = 20;

    cout << "After a = 20: " << a << endl;

    // Add and assign
    a += 5; // Same as: a = a + 5
    cout << "After a += 5: " << a << endl;

    // Subtract and assign
    a -= 5; // Same as: a = a - 5
    cout << "After a -= 5: " << a << endl;

    // Multiply and assign
    a *= 2; // Same as: a = a * 2
    cout << "After a *= 2: " << a << endl;

    // Divide and assign
    a /= 2; // Same as: a = a / 2
    cout << "After a /= 2: " << a << endl;

    // Modulus and assign
    a %= 3; // Same as: a = a % 3
    cout << "After a %= 3: " << a << endl;

    return 0;
}