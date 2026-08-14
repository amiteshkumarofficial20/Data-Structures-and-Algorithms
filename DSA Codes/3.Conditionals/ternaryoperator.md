TERNARY OPERATOR IN C++

============================================================

The ternary operator is a conditional operator in C++.

It is called the ternary operator because it works with three
operands.

It is used to make simple decisions and is commonly used as a
short alternative to the if-else statement.

The ternary operator is represented by:

?:

============================================================

SYNTAX

condition ? expression1 : expression2;

Here:

condition
The condition that needs to be checked.

expression1
The expression executed when the condition is true.

expression2
The expression executed when the condition is false.

============================================================

HOW TERNARY OPERATOR WORKS

The condition is evaluated first.

If the condition is true:

    expression1 is selected.

If the condition is false:

    expression2 is selected.

Example:

int age = 20;

string result = (age >= 18) ? "Adult" : "Minor";

Here:

age >= 18

is the condition.

"Adult"

is selected when the condition is true.

"Minor"

is selected when the condition is false.

============================================================

TERNARY OPERATOR VS IF-ELSE

Using if-else:

if(age >= 18)
{
cout << "Adult";
}
else
{
cout << "Minor";
}

Using ternary operator:

cout << (age >= 18 ? "Adult" : "Minor");

Both perform the same basic decision.

The ternary operator is more compact and is useful when the
condition and its two possible results are simple.

============================================================

IMPORTANT POINTS

1. The ternary operator uses three operands.

2. It uses the symbols '?' and ':'.

3. The condition is written before '?'.

4. The true expression is written between '?' and ':'.

5. The false expression is written after ':'.

6. It is mainly useful for simple conditional expressions.

7. For complex decision-making, if-else or other conditional
   statements are generally easier to read.

============================================================

EVEN AND ODD USING TERNARY OPERATOR

A number is even when it is completely divisible by 2.

The remainder of an even number after division by 2 is zero.

Therefore:

number % 2 == 0

means the number is even.

If the remainder is not zero, the number is odd.

Using the ternary operator:

condition ? "Even" : "Odd"

============================================================

PROGRAM: EVEN AND ODD USING TERNARY OPERATOR

#include <iostream>
using namespace std;

int main()
{
int number;

    cout << "Enter a number: ";
    cin >> number;

    string result = (number % 2 == 0) ? "Even" : "Odd";

    cout << "The number is " << result;

    return 0;

}

============================================================

EXAMPLE 1

Input:

10

Calculation:

10 % 2 = 0

Therefore:

10 is Even

Output:

The number is Even

============================================================

EXAMPLE 2

Input:

7

Calculation:

7 % 2 = 1

Therefore:

7 is Odd

Output:

The number is Odd

============================================================

SHORT VERSION

The same program can also be written directly using the
ternary operator:

#include <iostream>
using namespace std;

int main()
{
int number;

    cout << "Enter a number: ";
    cin >> number;

    cout << ((number % 2 == 0) ? "Even" : "Odd");

    return 0;

}

============================================================

CONCLUSION

The ternary operator is a compact conditional operator used for
simple decision-making.

Its general form is:

condition ? true_expression : false_expression;

It provides a short alternative to a simple if-else statement.

For example:

number % 2 == 0 ? "Even" : "Odd"

checks whether a number is even or odd.

The ternary operator should be used when the condition is simple
and the resulting expression is easy to understand.

============================================================
