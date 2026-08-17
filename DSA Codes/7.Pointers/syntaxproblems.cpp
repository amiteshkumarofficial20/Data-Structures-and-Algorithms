// pointer_syntax_mistakes.cpp
// Common Pointer Syntax Mistakes

#include <iostream>
using namespace std;

int main()
{
    int a = 10;

    // 1. Correct declaration
    int *p;

    // 2. Correct initialization
    p = &a;

    // 3. Correct declaration + initialization
    int *q = &a;

    // ❌ WRONG: Pointer ko value assign karna
    // int *r = a;

    // ✅ CORRECT:
    int *r = &a;

    // ❌ WRONG: Normal int variable mein address store karna
    // int x = &a;

    // ✅ CORRECT:
    int *x = &a;

    // ❌ WRONG: Pointer ko pointer ke bina dereference karna
    // cout << p*;

    // ✅ CORRECT:
    cout << *p << endl;

    // ❌ WRONG: Address ke liye *
    // cout << *a;

    // ✅ CORRECT:
    cout << &a << endl;

    // ❌ WRONG: Value ke liye &
    // cout << &p;

    // &p actually pointer 'p' ka address deta hai.
    // Value ke liye:
    cout << *p << endl;

    // ❌ WRONG: Uninitialized pointer ko dereference karna
    // int *u;
    // cout << *u;

    // ✅ CORRECT:
    int *u = nullptr;

    // ❌ WRONG: nullptr ko dereference karna
    // cout << *u;

    // nullptr ko dereference mat karo.

    // ❌ WRONG: Different data type ka pointer
    // double d = 10.5;
    // int *dp = &d;

    // ✅ CORRECT:
    double d = 10.5;
    double *dp = &d;

    // ❌ WRONG: Pointer ko direct number dena
    // int *n = 100;

    // ✅ CORRECT:
    int *n = &a;

    // ❌ WRONG: Pointer declaration mein * bhool jana
    // int p2 = &a;

    // ✅ CORRECT:
    int *p2 = &a;

    // 4. Address of variable
    cout << "Address of a: " << &a << endl;

    // 5. Address stored in pointer
    cout << "Value of p: " << p << endl;

    // 6. Dereferencing
    cout << "Value using *p: " << *p << endl;

    // 7. Change value using pointer
    *p = 50;

    cout << "New value of a: " << a << endl;

    return 0;
}

/*
 int a = 10, b = 20;

    // Two pointers declared and initialized together
    int *p = &a, *q = &b;

    cout << "Value of a: " << a << endl;
    cout << "Value of b: " << b << endl;

    cout << "Value using p: " << *p << endl;
    cout << "Value using q: " << *q << endl;
    int *p, q;   // ❌ Only p is a pointer, q is normal int
    int *p, *q;  // ✅ Both are pointers
*/