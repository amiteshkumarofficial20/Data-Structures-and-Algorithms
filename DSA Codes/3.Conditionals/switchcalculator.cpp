#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

float divide(int a, int b)
{
    return (float)a / b;
}

int main()
{
    int a, b;
    char op;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> b;

    switch (op)
    {
    case '+':
        cout << "Result = " << add(a, b);
        break;

    case '-':
        cout << "Result = " << subtract(a, b);
        break;

    case '*':
        cout << "Result = " << multiply(a, b);
        break;

    case '/':
        if (b != 0)
        {
            cout << "Result = " << divide(a, b);
        }
        else
        {
            cout << "Division by zero is not allowed";
        }
        break;

    default:
        cout << "Invalid operator";
    }

    return 0;
}