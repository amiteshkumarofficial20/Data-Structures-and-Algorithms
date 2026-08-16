/*
    GREETING FUNCTION

    This program demonstrates how to create and call
    a simple function.

    The function 'greeting()' prints:

    Hello Amitesh

    The function does not take any argument and does
    not return any value.

    Therefore, its return type is:

        void


    LOGIC:

    1. FUNCTION DEFINITION:

       void greeting()
       {
           cout << "Hello Amitesh" << endl;
       }

       This defines a function named greeting.


    2. FUNCTION CALL:

       greeting();

       This executes the code inside the greeting function.


    3. MULTIPLE FUNCTION CALLS:

       The function is called five times inside main():

       greeting();
       greeting();
       greeting();
       greeting();
       greeting();

       Therefore, "Hello Amitesh" is printed five times.


    IMPORTANT:

    Instead of writing:

        cout << "Hello Amitesh" << endl;

    five times, we write it once inside a function
    and call the function whenever we need it.

    This is called CODE REUSABILITY.
*/

#include <iostream>
using namespace std;

// Function definition
void greeting()
{
    // Print the greeting message
    cout << "Hello Amitesh" << endl;
}

int main()
{
    // Function calls
    greeting();
    greeting();
    greeting();
    greeting();
    greeting();

    return 0;
}