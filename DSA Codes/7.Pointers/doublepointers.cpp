// double_pointer.cpp
// Double Pointer (Pointer to Pointer)

#include <iostream>
using namespace std;

int main()
{
    int a = 10;

    // First pointer stores the address of variable 'a'
    int *p = &a;

    // Double pointer stores the address of pointer 'p'
    int **q = &p;

    // Display value of variable
    cout << "Value of a: " << a << endl;

    // p stores the address of a
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in p: " << p << endl;

    // *p gives the value of a
    cout << "Value using *p: " << *p << endl;

    // q stores the address of p
    cout << "Address of p: " << &p << endl;
    cout << "Value stored in q: " << q << endl;

    // *q gives the value stored in p
    // That value is the address of a
    cout << "Value using *q: " << *q << endl;

    // **q gives the actual value of a
    cout << "Value using **q: " << **q << endl;

    // Changing a's value using double pointer
    **q = 50;

    cout << "New value of a: " << a << endl;

    return 0;
}

/*
DESCRIPTION:

A double pointer is a pointer that stores the
address of another pointer.

int a = 10;

int *p = &a;
int **q = &p;

Memory relationship:

q  --->  p  --->  a
         |        |
       address   10

p      -> address of a
*p     -> value of a

q      -> address of p
*q     -> value of p (address of a)
**q    -> value of a

IMPORTANT:

*  = Dereference one level
** = Dereference two levels
*/