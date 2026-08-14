// Ternary (Conditional) Operator in C++
//
// The ternary operator is a conditional operator.
// It is used as a short and simple alternative to
// an if-else statement.
//
// Syntax:
//
// condition ? expression_if_true : expression_if_false;
//
// If the condition is true, the first expression is executed.
// If the condition is false, the second expression is executed.

#include <iostream>
using namespace std;

int main()
{
    int age;

    cout << "Enter your age: ";
    cin >> age;

    // Basic ternary operator
    string result = (age >= 18) ? "Adult" : "Minor";

    cout << "Result: " << result << endl;

    // Finding the greater number
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    int greater = (a > b) ? a : b;

    cout << "Greater number: " << greater << endl;

    return 0;
}