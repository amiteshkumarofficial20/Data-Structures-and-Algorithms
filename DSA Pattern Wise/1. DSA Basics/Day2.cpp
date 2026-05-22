#include <bits/stdc++.h> // Includes almost all standard C++ libraries
using namespace std;

/*
    ===================================================
           BASIC C++ & DSA THEORY (CONDITIONS + LOOPS)
    ===================================================

    1. Decision Making
       - Programs often need to take decisions.
       - In C++, decisions are made using:
            if
            else if
            else

    2. Relational Operators
       Used for comparison between values.

            <   Less than
            >   Greater than
            ==  Equal to
            <=  Less than or equal to
            >=  Greater than or equal to
            !=  Not equal to

       These operators return:
            true  (1)
            false (0)

    3. Logical Operators
            && or and   -> Logical AND
            || or or    -> Logical OR
            !           -> Logical NOT

    4. Loops
       Loops are used to repeat tasks multiple times.

       Types:
            for loop
            while loop

    5. Importance in DSA
       Conditions and loops are the backbone of:
            Pattern Problems
            Arrays
            Searching
            Sorting
            Recursion
            Number Theory
            Competitive Programming

    ===================================================
*/

int main()
{
    /*
        ------------------------------------------
        VARIABLE DECLARATION
        ------------------------------------------

        Theory:
        - Variables store values in memory.
        - Here two integer variables are created.

        Example:
            int a, b;

        Assignment:
            a = 10;
            b = 20;
    */

    int a, b;

    // Assigning values
    a = 10, b = 20;

    /*
        ------------------------------------------------
        RELATIONAL OPERATORS
        ------------------------------------------------

        Operators:
            ==  Equal to
            <   Less than
            >   Greater than
            <=  Less than or equal to
            >=  Greater than or equal to

        Logical Operators:
            and / &&   -> both conditions must be true
            or  / ||   -> at least one condition true
    */

    /*
        ------------------------------------------------
        BLOCK 1 : Simple if-else
        ------------------------------------------------

        Theory:
        - if checks condition.
        - else executes when condition is false.

        Syntax:
            if(condition)
            {
                statement;
            }
            else
            {
                statement;
            }

        Here:
            if a is smaller than b
            print "a is smaller"
    */

    {
        if (a < b)
            cout << "a is smaller" << endl;
        else
            cout << "b is smaller" << endl;
    }

    /*
        ------------------------------------------------
        BLOCK 2 : if - else if - else Ladder
        ------------------------------------------------

        Theory:
        - Used when multiple conditions are checked.

        Flow:
            1. First if is checked
            2. If false, else if is checked
            3. If all false, else executes

        Important in DSA for:
            - grading systems
            - menu driven programs
            - comparisons
            - decision making
    */

    {
        if (a < b)
        {
            cout << "a is smaller" << endl;
        }
        else if (a > b)
        {
            cout << "b is smaller" << endl;
        }
        else
        {
            cout << "a and b are equal" << endl;
        }
    }

    /*
        ------------------------------------------------
        BLOCK 3 : Divisibility Check
        ------------------------------------------------

        Theory:
        - % operator gives remainder.
        - Number is divisible when remainder is 0.

        Example:
            10 % 2 = 0
            therefore 10 is divisible by 2

        Logical AND:
            condition1 and condition2

        Both conditions must be true.
    */

    {
        int num;

        cout << "Enter a Number:";

        cin >> num;

        // Checking divisibility by both 2 and 3
        if (num % 2 == 0 and num % 3 == 0)
        {
            cout << "num is divisible by 2 and 3" << endl;
        }
        else
        {
            cout << "num is not divisible by 2 and 3" << endl;
        }
    }

    /*
        =================================================
                        LOOPS
        =================================================

        Theory:
        - Loops repeat a block of code multiple times.

        FOR LOOP Syntax:

            for(initialization; condition; update)
            {
                code;
            }

        Steps:
            1. Initialization
            2. Condition check
            3. Execute code
            4. Update variable
            5. Repeat
    */

    /*
        ------------------------------------------------
        BLOCK 4 : Printing Numbers using for loop
        ------------------------------------------------

        Theory:
        - i starts from 0
        - Loop runs while i < 5
        - i++ increases i by 1

        Output:
            0 1 2 3 4
    */

    for (int i = 0; i < 5; i++)
    {
        cout << i << endl;
    }

    /*
        ------------------------------------------------
        BLOCK 5 : Sum of First 10 Numbers
        ------------------------------------------------

        Theory:
        - sum variable stores total.
        - sum += i means:
                sum = sum + i

        Loop:
            i goes from 0 to 9

        Formula:
            0+1+2+3+4+5+6+7+8+9
    */

    {
        int sum = 0;

        for (int i = 0; i < 10; i++)
        {
            sum += i;
        }

        cout << "Sum of 10 Numbers: " << sum << endl;
    }

    /*
        ------------------------------------------------
        BLOCK 6 : Sum of First 10 Even Numbers
        ------------------------------------------------

        Theory:
        - Even numbers are divisible by 2.

        Condition:
            i % 2 == 0

        Numbers:
            0 2 4 6 8 10 12 14 16 18
    */

    {
        int sum = 0;

        for (int i = 0; i < 20; i++)
        {
            // Checking even number
            if (i % 2 == 0)
            {
                sum += i;
            }
        }

        cout << "Sum of First 10 Even Numbers: " << sum << endl;
    }

    /*
        ------------------------------------------------
        BLOCK 7 : Sum of Even Numbers Between 20 and 40
        ------------------------------------------------

        Theory:
        - Loop starts from 20
        - Loop ends at 40
        - Only even numbers are added

        Important in DSA:
            - Range based problems
            - Number theory
            - Prefix sums
            - Mathematical logic
    */

    {
        int sum = 0;

        for (int i = 20; i <= 40; i++)
        {
            // Checking even condition
            if (i % 2 == 0)
            {
                sum += i;
            }
        }

        cout << "Sum of Even Numbers Between 20 and 40: " << sum << endl;
    }

    /*
        return 0;
        ----------------
        Indicates successful execution of program.
    */

    return 0;
}