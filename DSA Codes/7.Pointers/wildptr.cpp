// Demonstration of Wild Pointer

#include <iostream>
using namespace std;

int main()
{
    // Wild pointer
    // It is declared but not initialized
    int *p;

    // ❌ DO NOT dereference a wild pointer
    // cout << *p << endl;

    cout << "p is a wild pointer because it is not initialized."
         << endl;

    // Make the pointer safe by initializing it
    p = nullptr;

    if (p == nullptr)
    {
        cout << "p is now a null pointer." << endl;
    }

    return 0;
}

/*
DESCRIPTION:

A wild pointer is a pointer that has been declared
but not initialized.

Example:

int *p;

Here, p contains an indeterminate/unknown value.

If we do:

cout << *p;

it may cause undefined behavior.

SAFE PRACTICE:

Initialize pointers when declaring them:

int *p = nullptr;

DIFFERENCE:

Wild Pointer:
    int *p;
    -> Uninitialized pointer

Null Pointer:
    int *p = nullptr;
    -> Intentionally points to nothing

Dangling Pointer:
    -> Points to an object whose lifetime has ended
*/