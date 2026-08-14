CONDITIONAL STATEMENTS IN C++

============================================================

Conditional statements are used to make decisions in a C++ program.

They allow a program to execute different blocks of code depending
on whether a given condition is true or false.

A condition normally produces a Boolean result:

true
or
false

Conditional statements are very important because they allow a
program to make decisions instead of executing every statement
in the same order.

For example:

If a person's age is 18 or more, the person is considered an adult.

If the age is less than 18, the person is considered a minor.

This type of decision-making is performed using conditional
statements.

============================================================

TYPES OF CONDITIONAL STATEMENTS

The main conditional statements in C++ are:

1. if statement
2. if-else statement
3. else-if ladder
4. nested if statement
5. switch statement
6. conditional / ternary operator

============================================================

1. IF STATEMENT

The 'if' statement is used when we want to execute a block of code
only when a particular condition is true.

Syntax:

if(condition)
{
// statements
}

If the condition is true, the statements inside the 'if' block
are executed.

If the condition is false, the statements inside the 'if' block
are skipped.

Example:

int age = 20;

if(age >= 18)
{
cout << "You are an adult";
}

Here:

age >= 18

is the condition.

Since age is 20, the condition is true.

Therefore, the output is:

You are an adult

============================================================

2. IF-ELSE STATEMENT

The 'if-else' statement is used when there are two possible
situations.

If the condition is true, the 'if' block is executed.

If the condition is false, the 'else' block is executed.

Syntax:

if(condition)
{
// statements when condition is true
}
else
{
// statements when condition is false
}

Example:

int age;

cin >> age;

if(age >= 18)
{
cout << "Adult";
}
else
{
cout << "Minor";
}

If the input is:

20

Output:

Adult

If the input is:

15

Output:

Minor

============================================================

3. ELSE-IF LADDER

An else-if ladder is used when there are multiple conditions.

The conditions are checked from top to bottom.

As soon as one condition becomes true, its corresponding block
is executed and the remaining conditions are skipped.

Syntax:

if(condition1)
{
// statements
}
else if(condition2)
{
// statements
}
else if(condition3)
{
// statements
}
else
{
// statements
}

Example:

int marks;

cin >> marks;

if(marks >= 90)
{
cout << "Grade A";
}
else if(marks >= 80)
{
cout << "Grade B";
}
else if(marks >= 70)
{
cout << "Grade C";
}
else if(marks >= 60)
{
cout << "Grade D";
}
else
{
cout << "Fail";
}

If the input is:

85

The output is:

Grade B

The condition marks >= 90 is false.

Then:

marks >= 80

is true.

Therefore, Grade B is printed.

============================================================

4. NESTED IF STATEMENT

A nested if statement means placing one 'if' statement inside
another 'if' statement.

It is useful when one condition needs to be checked only after
another condition is satisfied.

Example:

int age;
int hasID;

cin >> age;
cin >> hasID;

if(age >= 18)
{
if(hasID == 1)
{
cout << "Entry allowed";
}
}

In this example, the second condition is checked only if:

age >= 18

is true.

Then:

hasID == 1

is checked.

============================================================

5. SWITCH STATEMENT

The 'switch' statement is used when we need to select one option
from multiple fixed choices.

It is commonly used with integer, character and enumeration values.

Syntax:

switch(expression)
{
case value1:
// statements
break;

    case value2:
        // statements
        break;

    default:
        // statements

}

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

If the input is:

2

Output:

Tuesday

============================================================

BREAK IN SWITCH

The 'break' statement is used to stop execution of the switch
after a matching case has been executed.

Example:

switch(choice)
{
case 1:
cout << "One";
break;

    case 2:
        cout << "Two";
        break;

}

Without 'break', execution may continue into the following cases.
This behavior is called fall-through.

============================================================

DEFAULT IN SWITCH

The 'default' block is executed when none of the cases match
the given value.

Example:

int choice;

cin >> choice;

switch(choice)
{
case 1:
cout << "Option 1";
break;

    case 2:
        cout << "Option 2";
        break;

    default:
        cout << "Invalid option";

}

If the user enters:

5

the output will be:

Invalid option

============================================================

6. CONDITIONAL / TERNARY OPERATOR

The conditional operator is also called the ternary operator.

It is a short form of a simple if-else statement.

Syntax:

condition ? expression1 : expression2;

Example:

int age = 20;

string result;

result = (age >= 18) ? "Adult" : "Minor";

cout << result;

Output:

Adult

The ternary operator contains three parts:

1. Condition
2. Expression when true
3. Expression when false

============================================================

COMPARISON OF CONDITIONAL STATEMENTS

IF:

Used when a block should execute only when a condition is true.

IF-ELSE:

Used when there are two possible outcomes.

ELSE-IF LADDER:

Used when there are multiple conditions.

NESTED IF:

Used when one condition depends on another condition.

SWITCH:

Used when selecting between multiple fixed values.

TERNARY:

Used for short and simple conditional expressions.

============================================================

CONDITIONAL OPERATORS

Conditions commonly use relational and logical operators.

Relational operators:

> # <

# <=

!=

Logical operators:

&&
||
!

Example:

int age = 25;

if(age >= 18 && age <= 60)
{
cout << "Eligible";
}

Here:

age >= 18

and:

age <= 60

are combined using the logical AND operator '&&'.

============================================================

IMPORTANT POINT

A condition should produce a value that can be interpreted as
true or false.

Example:

if(10 > 5)
{
cout << "True";
}

Here:

10 > 5

is true.

Therefore, the code inside the if block is executed.

============================================================

IF-ELSE EXAMPLE PROGRAM

#include <iostream>
using namespace std;

int main()
{
int number;

    cout << "Enter a number: ";
    cin >> number;

    if(number > 0)
    {
        cout << "Positive number";
    }
    else if(number < 0)
    {
        cout << "Negative number";
    }
    else
    {
        cout << "Zero";
    }

    return 0;

}

============================================================

SUMMARY

Conditional statements allow a C++ program to make decisions.

The main conditional statements are:

if
if-else
else-if ladder
nested if
switch
ternary operator

The 'if' statement checks a condition.

The 'if-else' statement provides two possible paths.

The 'else-if ladder' is used for multiple conditions.

The 'nested if' statement places one condition inside another.

The 'switch' statement is useful when choosing between multiple
fixed options.

The ternary operator provides a short way to write simple
if-else expressions.

Conditional statements form the foundation of decision-making
and are essential for writing logical C++ programs.

============================================================
