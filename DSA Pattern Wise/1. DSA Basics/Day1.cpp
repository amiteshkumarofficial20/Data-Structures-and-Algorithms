#include <bits/stdc++.h> // Header file that includes almost all standard C++ libraries
using namespace std;     // Allows us to use standard functions without std::

/*
    ============================================
              BASIC C++ & DSA THEORY
    ============================================

    1. C++ Basics
       - C++ is a programming language used in DSA, competitive programming,
         software development, game development, etc.
       - Programs execute from the main() function.

    2. Variables
       - Variables store data in memory.
       - Example:
            int a = 10;
         Here:
            int -> data type
            a   -> variable name
            10  -> value stored

    3. Input & Output
       - cout is used to print output.
       - cin is used to take input from user.

    4. Operators
       Arithmetic Operators:
            +  Addition
            -  Subtraction
            *  Multiplication
            /  Division
            %  Modulus (remainder)

    5. Blocks {}
       - Curly braces create a local scope.
       - Variables declared inside a block can only be used there.

    6. Importance in DSA
       - Input/output, variables, and operators are the foundation of:
            Arrays
            Loops
            Patterns
            Functions
            Recursion
            Sorting
            Searching
            etc.

    ============================================
*/

int main()
{
    /*
        --------------------------------------------
        BLOCK 1 : Variable Declaration & Output
        --------------------------------------------

        Theory:
        - A variable is created and assigned a value.
        - cout prints text and variables.
        - endl moves cursor to next line.

        Syntax:
            int a = 10;

        Reassignment:
            a = 5;
        means old value is replaced by new value.
    */
    {
        int a = 10; // Variable declaration and initialization

        a = 5; // Updating/Reassigning variable value

        cout << "Hello World!";

        // Printing string and variable together
        cout << "Hello" << a;
    }

    // Moves output to next line
    cout << endl;

    /*
        --------------------------------------------
        BLOCK 2 : Addition of Two Numbers
        --------------------------------------------

        Theory:
        - Arithmetic operators are used for calculations.
        - '+' operator performs addition.

        Example:
            int sum = a + b;

        This is one of the most basic DSA operations.
    */
    {
        int a = 10;
        int b = 5;

        // Storing addition result
        int sum = a + b;

        // Directly printing addition
        cout << a + b;

        // Printing stored result
        cout << sum;
    }

    cout << endl;

    /*
        --------------------------------------------
        BLOCK 3 : Taking User Input
        --------------------------------------------

        Theory:
        - cin is used to take input from user.
        - User enters values during runtime.

        Example:
            cin >> a >> b;

        >> is extraction operator.
    */
    {
        int a, b;

        cout << "Enter a and b " << endl;

        // Taking input from user
        cin >> a >> b;

        // Calculating sum
        int sum = a + b;

        // Printing values
        cout << a << b << sum;
    }

    cout << endl;

    /*
        --------------------------------------------
        BLOCK 4 : Modulus Operator
        --------------------------------------------

        Theory:
        - % operator gives remainder after division.

        Example:
            10 % 3 = 1

        Important in DSA for:
            - Even/Odd checking
            - Cyclic problems
            - Number theory
            - Hashing
    */
    {
        int a, b;

        cout << "Enter a and b " << endl;

        cin >> a >> b;

        // Finding remainder
        int sum = a % b;

        cout << a << b << sum;
    }

    cout << endl;

    /*
        --------------------------------------------
        BLOCK 5 : Product of 3 Numbers
        --------------------------------------------

        Theory:
        - '*' operator performs multiplication.
        - Product means multiplication of numbers.

        Formula:
            product = num1 * num2 * num3
    */
    {
        int num1, num2, num3, product;

        cout << "Enter 3 Numbers: ";

        // Taking 3 inputs
        cin >> num1 >> num2 >> num3;

        cout << endl;

        // Multiplication
        product = num1 * num2 * num3;

        cout << "Product is: " << product;
    }

    cout << endl;

    /*
        --------------------------------------------
        BLOCK 6 : Average of Two Numbers
        --------------------------------------------

        Theory:
        - Average means sum divided by total count.

        Formula:
            average = (a + b) / 2

        Important Note:
        - Since average is integer type,
          decimal values are truncated.

        Example:
            5 / 2 = 2
    */
    {
        int num1, num2, average;

        cout << "Enter 2 Numbers: ";

        cin >> num1 >> num2;

        cout << endl;

        // Average calculation
        average = (num1 + num2) / 2;

        cout << "Average is: " << average;
    }

    /*
        return 0;
        ----------------
        Indicates successful program execution.
    */
    return 0;
}