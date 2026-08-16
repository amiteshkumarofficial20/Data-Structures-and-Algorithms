/*
    DEFAULT VALUE / FUNCTION ARGUMENTS

    This program demonstrates different ways of
    passing arguments to functions.

    CASES:

    1. Function with NO arguments
    2. Function with ONE argument
    3. Function with MULTIPLE arguments
    4. Function with DIFFERENT DATA TYPES
    5. Function with DEFAULT ARGUMENT
    6. Function with ONE DEFAULT VALUE
    7. Function with MULTIPLE DEFAULT VALUES
*/

#include <iostream>
#include <string>
using namespace std;

// ==========================================================
// 1. NO ARGUMENT
// ==========================================================

/*
    The function does not take any argument.

        greeting();
*/

void greeting()
{
    cout << "Hello Amitesh!" << endl;
}

// ==========================================================
// 2. ONE ARGUMENT
// ==========================================================

/*
    One value is passed to the function.

        square(5);
*/

void square(int n)
{
    cout << "Square = " << n * n << endl;
}

// ==========================================================
// 3. MULTIPLE ARGUMENTS
// ==========================================================

/*
    Multiple values can be passed to a function.

        add(10, 20);
*/

void add(int a, int b)
{
    cout << "Sum = " << a + b << endl;
}

// ==========================================================
// 4. DIFFERENT DATA TYPES
// ==========================================================

/*
    A function can accept parameters of different
    data types.

        display(10, 5.5, 'A');
*/

void display(int a, double b, char c)
{
    cout << "Integer = " << a << endl;
    cout << "Double = " << b << endl;
    cout << "Character = " << c << endl;
}

// ==========================================================
// 5. DEFAULT ARGUMENT
// ==========================================================

/*
    A parameter can have a default value.

        void message(string name = "Amitesh")

    If no argument is passed, the default value is used.

        message();

    If an argument is passed, the passed value is used.

        message("Rahul");
*/

void message(string name = "Amitesh")
{
    cout << "Hello " << name << endl;
}

// ==========================================================
// 6. ONE DEFAULT VALUE
// ==========================================================

/*
    If the second argument is not passed,
    its default value is used.
*/

void addition(int a, int b = 10)
{
    cout << "Sum = " << a + b << endl;
}

// ==========================================================
// 7. MULTIPLE DEFAULT VALUES
// ==========================================================

/*
    Multiple parameters can have default values.
*/

void calculate(int a = 10, int b = 20)
{
    cout << "Sum = " << a + b << endl;
}

int main()
{
    // ======================================================
    // 1. NO ARGUMENT
    // ======================================================

    greeting();

    // ======================================================
    // 2. ONE ARGUMENT
    // ======================================================

    square(5);

    // ======================================================
    // 3. MULTIPLE ARGUMENTS
    // ======================================================

    add(10, 20);

    // ======================================================
    // 4. DIFFERENT DATA TYPES
    // ======================================================

    display(10, 5.5, 'A');

    // ======================================================
    // 5. DEFAULT ARGUMENT
    // ======================================================

    // No argument → default value "Amitesh" is used
    message();

    // Argument passed → default value is replaced
    message("Rahul");

    // ======================================================
    // 6. ONE DEFAULT VALUE
    // ======================================================

    // b = 10 by default
    addition(20);

    // Both arguments are passed
    addition(20, 30);

    // ======================================================
    // 7. MULTIPLE DEFAULT VALUES
    // ======================================================

    // Uses a = 10 and b = 20
    calculate();

    // Uses a = 50 and default b = 20
    calculate(50);

    // Uses both given values
    calculate(50, 60);

    return 0;
}

/*
    ==========================================================
    IMPORTANT RULES
    ==========================================================

    Default arguments are used when the caller does not
    provide a value.

    Example:

        void add(int a, int b = 10)


    add(5);

    Here:

        a = 5
        b = 10


    add(5, 20);

    Here:

        a = 5
        b = 20


    IMPORTANT:

    Default arguments are given from RIGHT TO LEFT.

    Correct:

        void fun(int a, int b = 10)

        void fun(int a, int b = 10, int c = 20)


    Incorrect:

        void fun(int a = 10, int b)


    ==========================================================
    SUMMARY
    ==========================================================

    No argument:
        greeting();

    One argument:
        square(5);

    Multiple arguments:
        add(10, 20);

    Different data types:
        display(10, 5.5, 'A');

    Default argument:
        message();

    Default + given argument:
        addition(20);

    Multiple default arguments:
        calculate();
*/