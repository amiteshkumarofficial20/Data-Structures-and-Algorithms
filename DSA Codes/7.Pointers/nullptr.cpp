// nullptr.cpp
// Demonstration of nullptr

#include <iostream>
using namespace std;

int main()
{
    // Pointer initialized with nullptr
    int *p = nullptr;

    // nullptr means the pointer is not pointing
    // to any valid memory location

    if (p == nullptr)
    {
        cout << "Pointer is NULL" << endl;
    }
    else
    {
        cout << "Pointer is pointing to a valid address" << endl;
    }

    // ❌ Do NOT dereference nullptr
    // cout << *p << endl;

    // It can cause a runtime error because
    // p is not pointing to a valid object.

    return 0;
}