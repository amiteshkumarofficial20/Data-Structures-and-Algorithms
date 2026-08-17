// dereference.cpp
// Program to demonstrate Dereferencing of a Pointer

#include <iostream>
using namespace std;

int main()
{
    int a = 10;

    // Pointer stores the address of variable 'a'
    int *p = &a;

    // Dereferencing the pointer using '*'
    // *p gives the value stored at the address held by p
    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Address stored in p: " << p << endl;
    cout << "Value using dereference: " << *p << endl;

    // Changing the value using pointer
    *p = 20;

    cout << "New value of a: " << a << endl;

    return 0;
}