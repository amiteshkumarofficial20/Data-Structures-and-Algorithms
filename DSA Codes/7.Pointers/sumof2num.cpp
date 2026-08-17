// Program to find sum of two numbers using pointers

#include <iostream>
using namespace std;

int main()
{
    int a, b;

    // Taking input from user
    cout << "Enter first number: ";
    cin >> a; // cin >> *p; same

    cout << "Enter second number: ";
    cin >> b; // cin >> *q; same

    // Pointer declaration and initialization
    int *p = &a;
    int *q = &b;

    // Dereferencing pointers to access values
    int sum = *p + *q;

    // Display result
    cout << "Sum: " << sum << endl;
    cout << "Sum: " << *p + *q << endl;

    return 0;
}