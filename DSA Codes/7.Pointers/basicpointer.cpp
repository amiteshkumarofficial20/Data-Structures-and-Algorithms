#include <iostream>
using namespace std;

int main()
{

    int a = 10; // First integer variable
    int b = 20; // Second integer variable

    int *p = &a; // First pointer stores address of 'a'
    int *q = &b; // Second pointer stores address of 'b'

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    // &a gives the memory address of variable 'a'

    cout << "Value stored in p: " << p << endl;
    // p contains the address of 'a'

    cout << "Value pointed by p: " << *p << endl;
    // * = dereference operator
    // *p gives the value stored at the address pointed by p

    cout << "\nValue of b: " << b << endl;
    cout << "Address of b: " << &b << endl;
    // &b gives the memory address of variable 'b'

    cout << "Value stored in q: " << q << endl;
    // q contains the address of 'b'

    cout << "Value pointed by q: " << *q << endl;
    // *q gives the value stored at the address pointed by q

    return 0;
}
// datatype * pointername; can do with all data types
//  datatype var = 1;
// samedatatype pointer = address of var;