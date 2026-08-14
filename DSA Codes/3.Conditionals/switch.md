SWITCH STATEMENT IN C++

============================================================

The switch statement is a conditional control statement in C++.

It is used to execute one block of code from multiple possible
options.

The switch statement is especially useful when we need to compare
one expression with several fixed values.

Instead of writing many if-else-if conditions, we can use a
switch statement to make the code more organized and readable.

============================================================

SYNTAX

switch(expression)
{
case value1:
// statements
break;

    case value2:
        // statements
        break;

    case value3:
        // statements
        break;

    default:
        // statements

}

============================================================

IMPORTANT PARTS OF SWITCH

1. switch

The 'switch' keyword starts the switch statement.

Example:

switch(choice)
{
}

2. EXPRESSION

The expression is the value that C++ compares with each case.

Example:

switch(choice)

3. CASE

The 'case' keyword represents a possible value of the expression.

Example:

case 1:
cout << "Option One";
break;

4. BREAK

The 'break' statement terminates the switch statement.

After executing a matching case, 'break' prevents execution from
continuing into the next cases.

5. DEFAULT

The 'default' case is executed when none of the cases match the
switch expression.

============================================================

HOW SWITCH WORKS

Suppose:

int choice = 2;

switch(choice)
{
case 1:
cout << "One";
break;

    case 2:
        cout << "Two";
        break;

    case 3:
        cout << "Three";
        break;

    default:
        cout << "Invalid";

}

The value of 'choice' is 2.

C++ compares 2 with the case values.

case 1:

Not matched.

case 2:

Matched.

Therefore:

Two

is printed.

Then 'break' terminates the switch statement.

============================================================

SWITCH WITH USER INPUT

Example:

#include <iostream>
using namespace std;

int main()
{
int choice;

    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            cout << "You selected option 1";
            break;

        case 2:
            cout << "You selected option 2";
            break;

        case 3:
            cout << "You selected option 3";
            break;

        default:
            cout << "Invalid choice";
    }

    return 0;

}

============================================================

BREAK STATEMENT

The 'break' statement is very important in a switch statement.

Example:

switch(number)
{
case 1:
cout << "One";
break;

    case 2:
        cout << "Two";
        break;

}

When a matching case is found, its statements are executed.

Then 'break' exits the switch statement.

============================================================

WHAT HAPPENS WITHOUT BREAK?

If 'break' is not used, execution can continue into the following
cases.

This behavior is called FALL-THROUGH.

Example:

switch(number)
{
case 1:
cout << "One";

    case 2:
        cout << "Two";

    case 3:
        cout << "Three";

}

If number is 1, the output can be:

One
Two
Three

because there is no 'break' after case 1 or case 2.

============================================================

DEFAULT CASE

The default case is executed when no case matches the expression.

Example:

int day;

cin >> day;

switch(day)
{
case 1:
cout << "Monday";
break;

    case 2:
        cout << "Tuesday";
        break;

    case 3:
        cout << "Wednesday";
        break;

    default:
        cout << "Invalid day";

}

If the user enters:

10

there is no matching case.

Therefore:

Invalid day

is printed.

============================================================

SWITCH WITH CHARACTERS

A switch statement can also be used with characters.

Example:

char grade;

cin >> grade;

switch(grade)
{
case 'A':
cout << "Excellent";
break;

    case 'B':
        cout << "Good";
        break;

    case 'C':
        cout << "Average";
        break;

    default:
        cout << "Invalid grade";

}

============================================================

SWITCH VS IF-ELSE

SWITCH:

Switch is useful when one expression needs to be compared with
multiple fixed values.

Example:

switch(choice)

IF-ELSE:

If-else is more suitable for conditions involving ranges,
comparisons, and complex logical expressions.

Example:

if(age >= 18)

For example, this type of condition is suitable for if-else:

if(marks >= 90)
{
cout << "Grade A";
}

A switch statement is generally not the natural choice for
checking ranges such as:

marks >= 90

============================================================

EXAMPLE: SIMPLE CALCULATOR USING SWITCH

#include <iostream>
using namespace std;

int main()
{
int a, b;
char operation;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter operator (+, -, *, /): ";
    cin >> operation;

    cout << "Enter second number: ";
    cin >> b;

    switch(operation)
    {
        case '+':
            cout << "Result = " << a + b;
            break;

        case '-':
            cout << "Result = " << a - b;
            break;

        case '*':
            cout << "Result = " << a * b;
            break;

        case '/':
            cout << "Result = " << a / b;
            break;

        default:
            cout << "Invalid operator";
    }

    return 0;

}

============================================================

IMPORTANT RULES OF SWITCH

1. The switch expression should be of an integral, enumeration,
   or compatible type.

2. Each case represents a constant value.

3. Case values must be unique within the same switch statement.

4. The break statement is normally used to prevent fall-through.

5. The default case is optional.

6. Multiple cases can execute the same block intentionally.

Example:

switch(day)
{
case 1:
case 7:
cout << "Weekend";
break;

    default:
        cout << "Weekday";

}

Here, both case 1 and case 7 execute the same block.

============================================================

CONCLUSION

The switch statement is a multi-way selection statement in C++.

It allows a program to choose one block of code from several
possible options.

The main components of a switch statement are:

switch
case
break
default

Switch is most useful when comparing one value against several
fixed choices.

For complex conditions, ranges, and logical expressions,
if-else is generally more appropriate.

============================================================
