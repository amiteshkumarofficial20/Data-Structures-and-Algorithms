// dangling_pointer.cpp
// Demonstration of Dangling Pointer

#include <iostream>
using namespace std;

int main()
{
    int *p = nullptr;

    {
        int a = 10;

        // p stores the address of local variable 'a'
        p = &a;

        cout << "Value of a: " << *p << endl;
    }

    // 'a' is destroyed after the block ends.
    // p still contains the old address.
    // Now p is a DANGLING POINTER.

    cout << "Pointer is now dangling." << endl;

    // ❌ Do NOT dereference p here
    // cout << *p << endl;

    // Make the pointer safe again
    p = nullptr;

    if (p == nullptr)
    {
        cout << "p is now nullptr." << endl;
    }

    return 0;
}