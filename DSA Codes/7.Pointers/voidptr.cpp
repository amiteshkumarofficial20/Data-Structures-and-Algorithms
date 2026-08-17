// void_pointer.cpp
// Program to demonstrate Void Pointer

#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    float b = 20.5f;
    char c = 'A';

    // Void pointer can store the address
    // of any type of variable
    void *p;

    // Pointing to int variable
    p = &a;

    // Type casting is required before dereferencing
    cout << "Integer value: "
         << *(static_cast<int *>(p)) << endl;

    // Pointing to float variable
    p = &b;

    cout << "Float value: "
         << *(static_cast<float *>(p)) << endl;

    // Pointing to char variable
    p = &c;

    cout << "Character value: "
         << *(static_cast<char *>(p)) << endl;

    return 0;
}

/*
DESCRIPTION:

A void pointer is a generic pointer.

Syntax:

    void *p;

A void pointer can store the address of
different data types.

Example:

    p = &a;     // int address
    p = &b;     // float address
    p = &c;     // char address

IMPORTANT:

A void pointer does not know the data type
of the variable it is pointing to.

Therefore, it cannot be directly dereferenced.

Wrong:

    cout << *p;

Correct:

    cout << *(static_cast<int*>(p));

Here static_cast<int*> converts the void pointer
into an int pointer before dereferencing.

LOGIC:

    int a = 10;

    void *p = &a;

    p
    ↓
    address of a
    ↓
    a = 10

    static_cast<int*>(p)
    ↓
    int pointer

    *(static_cast<int*>(p))
    ↓
    10
*/