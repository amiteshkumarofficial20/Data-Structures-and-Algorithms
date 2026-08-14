// Float Data Type in C++
//
// The 'float' data type is used to store decimal or
// floating-point numbers.
//
// Examples:
// 10.5
// 25.75
// 3.14
// 99.99
//
// A float normally uses 4 bytes of memory and provides
// approximately 6-7 decimal digits of precision.
//
// By default, a decimal literal such as 3.14 is treated
// as a double in C++. To explicitly make it a float,
// use the 'f' suffix: 3.14f

#include <iostream>
using namespace std;

int main()
{
    float number = 10.5f;

    cout << "Number = " << number << endl;

    // Taking float input from the user
    float marks;

    cout << "Enter your marks: ";
    cin >> marks;

    cout << "Your marks = " << marks << endl;

    // Float can also be used in calculations
    float a = 10.5f;
    float b = 2.5f;

    cout << "Addition = " << a + b << endl;
    cout << "Subtraction = " << a - b << endl;
    cout << "Multiplication = " << a * b << endl;
    cout << "Division = " << a / b << endl;

    return 0;
}