#include <bits/stdc++.h> // Header file that includes almost all standard C++ libraries
using namespace std;     // Allows usage of standard names without writing std::

/*
    ============================================================
                BASIC C++ & DSA THEORY : FUNCTIONS
    ============================================================

    WHAT IS A FUNCTION?
    ------------------------------------------------------------
    - A function is a reusable block of code.
    - It performs a specific task.
    - Instead of writing the same code again and again,
      we create a function and call it whenever needed.

    Real Life Example:
    ------------------------------------------------------------
    Think of a calculator:
        - Addition button does only addition
        - Multiplication button does only multiplication

    Similarly in programming:
        - One function performs one task.

    WHY FUNCTIONS ARE IMPORTANT IN DSA?
    ------------------------------------------------------------
    Functions are the backbone of DSA because they help in:
        - Code Reusability
        - Modularity
        - Clean Code
        - Easy Debugging
        - Better Understanding

    Functions are used in:
        - Pattern Problems
        - Arrays
        - Searching
        - Sorting
        - Recursion
        - Linked Lists
        - Trees
        - Graphs
        - Dynamic Programming

    ============================================================

    GENERAL SYNTAX OF FUNCTION
    ------------------------------------------------------------

        return_type function_name(parameters)
        {
            // code
            return value;
        }

    Example:
        int doub(int num)

    Here:
        int      -> return type
        doub     -> function name
        int num  -> parameter/input

    ============================================================

    IMPORTANT TERMINOLOGIES
    ------------------------------------------------------------

    1. Function Declaration
       - Tells compiler that function exists.

    2. Function Definition
       - Actual implementation of function.

    3. Function Call
       - Invoking/running the function.

    4. Parameter
       - Variable received by function.

    5. Argument
       - Actual value passed to function.

    ============================================================

    RETURN TYPE
    ------------------------------------------------------------
    - Function can return a value using return statement.

    Example:
        return result;

    Here:
        result value goes back to calling function.

    ============================================================

    TIME COMPLEXITY
    ------------------------------------------------------------
    This program performs only one multiplication.

    Time Complexity:
        O(1)

    Space Complexity:
        O(1)

    O(1) means constant time operation.

    ============================================================
*/

/*
    ------------------------------------------------------------
                    FUNCTION DEFINITION
    ------------------------------------------------------------

    Function Name:
        doub

    Purpose:
        To calculate double of a number.

    Input:
        num

    Output:
        2 * num

    Example:
        Input  = 5
        Output = 10

    Mathematical Representation:
        result = 2 × num

    ------------------------------------------------------------
*/

int doub(int num)
{
    /*
        --------------------------------------------------------
                    LOCAL VARIABLE
        --------------------------------------------------------

        Theory:
        - Variables declared inside a function are called
          local variables.

        - They can only be accessed inside that function.

        Example:
            int result;

        'result' cannot be used outside doub() function.
    */

    int result = 2 * num;

    /*
        --------------------------------------------------------
                    MULTIPLICATION OPERATOR
        --------------------------------------------------------

        '*' is multiplication operator.

        Example:
            2 * 5 = 10
    */

    /*
        --------------------------------------------------------
                    RETURN STATEMENT
        --------------------------------------------------------

        Theory:
        - return sends value back to the caller.
        - Function execution stops after return.

        Here:
            result value is returned to main().
    */

    return result;
}

/*
    ============================================================
                        MAIN FUNCTION
    ============================================================

    Theory:
    - Every C++ program starts execution from main().
    - main() is the entry point of the program.

    Syntax:
        int main()

    ============================================================
*/

int main()
{
    /*
        --------------------------------------------------------
                    FUNCTIONS THEORY
        --------------------------------------------------------

        Function Call:
            doub(n)

        Process:
            1. main() calls doub()
            2. Value of n goes into num
            3. Function calculates double
            4. Result is returned back
            5. Returned value stored in variable
    */

    // Variable declaration
    int n;

    /*
        --------------------------------------------------------
                    INPUT SECTION
        --------------------------------------------------------

        cout:
            Used for output

        cin:
            Used for input

        >> is extraction operator.
    */

    cout << "Enter a Number: ";

    cin >> n;

    /*
        --------------------------------------------------------
                    FUNCTION CALLING
        --------------------------------------------------------

        Syntax:
            function_name(arguments);

        Here:
            doub(n)

        n is argument passed to function.

        Returned value is stored in result variable.
    */

    int result = doub(n);

    /*
        --------------------------------------------------------
                    OUTPUT SECTION
        --------------------------------------------------------

        Printing final doubled value.
    */

    cout << result << endl;

    /*
        --------------------------------------------------------
                    ALTERNATIVE METHOD
        --------------------------------------------------------

        We can directly print function result without storing.

        Example:
            cout << doub(n) << endl;

        This line is commented below.
    */

    // cout << doub(n) << endl;

    /*
        --------------------------------------------------------
                    return 0;
        --------------------------------------------------------

        Indicates successful execution of program.

        0 means:
            Program executed successfully.
    */

    return 0;
}