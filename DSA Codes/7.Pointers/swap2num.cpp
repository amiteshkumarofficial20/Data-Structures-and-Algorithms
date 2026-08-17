// Program to swap two numbers using pointers and function

#include <iostream>
using namespace std;

// Function to swap two numbers
void swapNumbers(int *p, int *q)
{
    int temp = *p; // Store value of first number
    *p = *q;       // Copy second number into first
    *q = temp;     // Copy first number into second
}

int main()
{
    int a, b;

    // Taking input from user
    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    cout << "\nBefore Swapping:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // Passing addresses to the function
    swapNumbers(&a, &b);

    cout << "\nAfter Swapping:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}