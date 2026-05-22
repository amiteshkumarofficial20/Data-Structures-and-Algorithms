// gfg

#include <bits/stdc++.h> // Includes almost all standard C++ libraries
using namespace std;

/*
    =====================================================
             BASIC C++ & DSA THEORY : FUNCTIONS
    =====================================================

    1. Functions in C++
       - Functions are reusable blocks of code.
       - They help avoid repetition.
       - Code becomes clean and modular.

    2. Why Functions are Important in DSA?
       Functions are heavily used in:
            - Recursion
            - Sorting Algorithms
            - Searching Algorithms
            - Pattern Problems
            - Arrays
            - Linked Lists
            - Trees
            - Graphs

    3. Advantages of Functions
            - Code Reusability
            - Better Readability
            - Easy Debugging
            - Easy Maintenance

    4. Function Syntax

        return_type function_name(parameters)
        {
            // code
        }

        Example:
            int findsum(int n)

        Here:
            int      -> return type
            findsum  -> function name
            int n    -> parameter/input

    5. Return Statement
       - return sends value back to calling function.
       - Function execution stops after return.

    =====================================================
*/

/*
    -----------------------------------------------------
                FUNCTION DEFINITION
    -----------------------------------------------------

    Function Name:
        findsum

    Purpose:
        Finds sum of first n natural numbers.

    Input:
        n

    Output:
        Sum from 1 to n

    Formula Used:
        n * (n + 1) / 2

    Example:
        n = 5

        Sum:
            1 + 2 + 3 + 4 + 5 = 15
*/

int findsum(int n)
{
    /*
        -------------------------------------------------
        BASE CONDITION
        -------------------------------------------------

        Theory:
        - Checking special case.
        - If n = 0, sum is 0.

        Important in DSA:
            Base conditions are important in recursion
            and edge case handling.
    */

    if (n == 0)
    {
        return 0;
    }
    else
    {
        /*
            -------------------------------------------------
            METHOD 1 : Using Loop (Commented)
            -------------------------------------------------

            Theory:
            - Loop runs from 0 to n.
            - Every number is added to sum.

            Time Complexity:
                O(n)

            Code:
                int sum = 0;

                for(int i=0; i<=n; i++)
                {
                    sum += i;
                }

                return sum;
        */

        // int sum = 0;

        // for (int i = 0; i <= n; i++)
        // {
        //     sum += i;
        // }

        // return sum;

        /*
            -------------------------------------------------
            METHOD 2 : Using Mathematical Formula
            -------------------------------------------------

            Formula:
                n * (n + 1) / 2

            Example:
                n = 5

                5 * (5 + 1) / 2
                = 5 * 6 / 2
                = 15

            Advantages:
                - Faster
                - No loop required
                - Better optimization

            Time Complexity:
                O(1)

            Space Complexity:
                O(1)

            Important for:
                - Mathematical DSA problems
                - Optimization
                - Competitive Programming
        */

        int sum = (n * (n + 1) / 2);

        /*
            Returning final answer
        */
        return sum;
    }
}

int main()
{
    /*
        =================================================
                    MAIN FUNCTION
        =================================================

        Theory:
        - Program execution starts from main().
        - main() calls other functions.

        Syntax:
            int main()
    */

    /*
        -------------------------------------------------
        FUNCTIONS THEORY
        -------------------------------------------------

        Function Call:
            findsum(n)

        Here:
            - n is passed as argument.
            - Control goes to function.
            - Function computes answer.
            - Returned value stored in result.
    */

    // Variable declaration
    int n;

    /*
        Taking input from user
    */

    cout << "Enter a Number: ";

    cin >> n;

    /*
        Function Calling

        Example:
            int result = findsum(n);

        Returned value stored in variable result.
    */

    int result = findsum(n);

    /*
        Printing final answer
    */

    cout << result << endl;

    /*
        Alternative way:
            cout << findsum(n) << endl;
    */

    // cout << findsum(n) << endl;

    /*
        return 0;
        ----------------
        Indicates successful execution of program.
    */

    return 0;
}