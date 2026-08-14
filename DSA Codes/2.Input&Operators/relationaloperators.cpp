// Relational Operators in C++
//
// Relational operators are used to compare two values.
// The result of a relational expression is either:
// true  (1)
// false (0)
//
// Relational Operators:
// ==   Equal to
// !=   Not equal to
// >    Greater than
// <    Less than
// >=   Greater than or equal to
// <=   Less than or equal to

#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << boolalpha;

    // Equal to
    cout << "a == b : " << (a == b) << endl;

    // Not equal to
    cout << "a != b : " << (a != b) << endl;

    // Greater than
    cout << "a > b  : " << (a > b) << endl;

    // Less than
    cout << "a < b  : " << (a < b) << endl;

    // Greater than or equal to
    cout << "a >= b : " << (a >= b) << endl;

    // Less than or equal to
    cout << "a <= b : " << (a <= b) << endl;

    return 0;
}