# Functions in C++

/\*
FUNCTION

    A function is a block of code that performs
    a specific task.

    Functions are used to:
    - Reuse code
    - Reduce code repetition
    - Make code easier to understand
    - Divide a large program into smaller parts

\*/

// ==========================================================
// FUNCTION SYNTAX
// ==========================================================

returnType functionName(parameters)
{
// function body
}

// Example:

int add(int a, int b)
{
return a + b;
}

// ==========================================================
// PARTS OF A FUNCTION
// ==========================================================

int add(int a, int b)
{
return a + b;
}

Here:

int -> Return Type
add -> Function Name
a, b -> Parameters
return -> Return Statement
a + b -> Returned Value

// ==========================================================
// FUNCTION DECLARATION
// ==========================================================

/\*
Function declaration tells the compiler that
a function exists.

    Syntax:

\*/

returnType functionName(parameters);

// Example:

int add(int a, int b);

// ==========================================================
// FUNCTION DEFINITION
// ==========================================================

/_
Function definition contains the actual code
of the function.
_/

int add(int a, int b)
{
return a + b;
}

// ==========================================================
// FUNCTION CALL
// ==========================================================

/_
Function call is used to execute a function.
_/

add(10, 20);

// ==========================================================
// PARAMETERS AND ARGUMENTS
// ==========================================================

/\*
PARAMETERS:

    Variables written inside the function definition
    are called parameters.

\*/

int add(int a, int b)

Here:
a and b -> Parameters

/\*
ARGUMENTS:

    Actual values passed during the function call
    are called arguments.

\*/

add(10, 20);

Here:
10 and 20 -> Arguments

// ==========================================================
// TYPES OF FUNCTIONS
// ==========================================================

/\* 1. No Argument, No Return Value

    2. Argument, No Return Value

    3. No Argument, Return Value

    4. Argument, Return Value

\*/

// ==========================================================
// 1. NO ARGUMENT, NO RETURN VALUE
// ==========================================================

void greet()
{
cout << "Hello";
}

// Function Call:

greet();

// ==========================================================
// 2. ARGUMENT, NO RETURN VALUE
// ==========================================================

void printNumber(int n)
{
cout << n;
}

// Function Call:

printNumber(10);

// ==========================================================
// 3. NO ARGUMENT, RETURN VALUE
// ==========================================================

int getNumber()
{
return 10;
}

// Function Call:

int x = getNumber();

// ==========================================================
// 4. ARGUMENT, RETURN VALUE
// ==========================================================

int add(int a, int b)
{
return a + b;
}

// Function Call:

int result = add(10, 20);

// ==========================================================
// EXAMPLE: ADDITION USING FUNCTION
// ==========================================================

#include <iostream>
using namespace std;

int add(int a, int b)
{
return a + b;
}

int main()
{
int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "Sum = " << add(a, b);

    return 0;

}

// ==========================================================
// EXAMPLE: EVEN OR ODD USING FUNCTION
// ==========================================================

#include <iostream>
using namespace std;

void checkEvenOdd(int n)
{
if (n % 2 == 0)
{
cout << "Even";
}
else
{
cout << "Odd";
}
}

int main()
{
int n;

    cout << "Enter n: ";
    cin >> n;

    checkEvenOdd(n);

    return 0;

}

// ==========================================================
// IMPORTANT TERMS
// ==========================================================

Function
-> Block of code that performs a specific task.

Function Declaration
-> Tells the compiler about the function.

Function Definition
-> Contains the actual code of the function.

Function Call
-> Executes the function.

Parameter
-> Variable used in the function definition.

Argument
-> Actual value passed to the function.

Return Type
-> Type of value returned by the function.

void
-> Function does not return any value.
