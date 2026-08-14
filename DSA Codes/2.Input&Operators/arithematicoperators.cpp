// Arithmetic Operators in C++
//
// Arithmetic operators are used to perform mathematical
// operations on numbers.
//
// Operators:
// +   Addition
// -   Subtraction
// *   Multiplication
// /   Division
// %   Modulus / Remainder

#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    // Addition
    cout << "Addition = " << a + b << endl;

    // Subtraction
    cout << "Subtraction = " << a - b << endl;

    // Multiplication
    cout << "Multiplication = " << a * b << endl;

    // Division
    cout << "Division = " << a / b << endl;

    // Modulus
    cout << "Remainder = " << a % b << endl;

    return 0;
}