/*
    SCOPE IN C++

    Scope means the area of the program where a variable
    can be accessed or used.

    There are mainly two scopes discussed here:

    1. Local Scope
    2. Global Scope


    LOCAL SCOPE:

    A variable declared inside a function or block
    can only be accessed within that function or block.


    GLOBAL SCOPE:

    A variable declared outside all functions can be
    accessed by multiple functions.


    IMPORTANT:

    A local variable has higher priority than a global
    variable if both have the same name.
*/

#include <iostream>
using namespace std;

// ==========================================================
// GLOBAL SCOPE
// ==========================================================

// 'x' is a global variable
int x = 100;

// ==========================================================
// FUNCTION
// ==========================================================

void show()
{
    // This 'x' is a local variable
    int x = 50;

    cout << "Inside function: " << x << endl;
}

int main()
{
    // This 'x' is a local variable of main()
    int x = 10;

    cout << "Inside main: " << x << endl;

    // Function has its own local x
    show();

    // Access the global x using ::
    cout << "Global x: " << ::x << endl;

    return 0;
}

/*
    OUTPUT:

    Inside main: 10
    Inside function: 50
    Global x: 100


    SCOPE SUMMARY:

    Global x = 100
        ↓
    Available throughout the program

    main() x = 10
        ↓
    Available only inside main()

    show() x = 50
        ↓
    Available only inside show()


    ::x

    The scope resolution operator '::' is used here
    to access the global variable x when a local
    variable with the same name exists.
*/