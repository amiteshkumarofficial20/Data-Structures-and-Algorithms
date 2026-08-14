INPUT AND OPERATORS IN C++

============================================================

INPUT IN C++

Input means taking data from the user during the execution of a program.

In C++, input is mainly taken from the keyboard using the 'cin' object.

The 'cin' object is provided by the <iostream> header file.

Example:

#include <iostream>
using namespace std;

int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    cout << "You entered: " << number;

    return 0;
}

Explanation:

In the above program, 'number' is an integer variable.

The statement:

cin >> number;

takes a value from the user and stores it inside the variable 'number'.

The '>>' symbol is called the extraction operator when it is used with 'cin'.

For example, if the user enters:

25

then:

number = 25


============================================================

CIN IN C++

'cin' is the standard input stream in C++.

It is used to take data from the standard input device, which is normally the keyboard.

Syntax:

cin >> variable;

Example:

int age;

cin >> age;

If the user enters:

20

then the value 20 is stored in the variable 'age'.


============================================================

TAKING MULTIPLE INPUTS

C++ allows us to take multiple values using a single 'cin' statement.

Example:

int a, b;

cin >> a >> b;

If the user enters:

10 20

then:

a = 10
b = 20

We can also take more values:

int a, b, c, d;

cin >> a >> b >> c >> d;

Input:

10 20 30 40

Values stored:

a = 10
b = 20
c = 30
d = 40


============================================================

INPUT OF DIFFERENT DATA TYPES

C++ can take input according to the data type of the variable.

INTEGER INPUT:

int number;

cin >> number;

Example input:

50


FLOAT INPUT:

float marks;

cin >> marks;

Example input:

85.5


DOUBLE INPUT:

double salary;

cin >> salary;

Example input:

50000.75


CHARACTER INPUT:

char grade;

cin >> grade;

Example input:

A


STRING INPUT:

string name;

cin >> name;

Example input:

Amitesh


============================================================

STRING INPUT USING CIN

When we use:

cin >> name;

the input operation normally reads only one word.

For example:

string name;

cin >> name;

If the user enters:

Amitesh Kumar

then only:

Amitesh

will normally be stored in the variable.

This happens because 'cin >>' stops reading when it encounters whitespace.

Whitespace includes:

Space
Tab
Newline


============================================================

GETLINE()

The 'getline()' function is used to read a complete line of text.

Unlike 'cin >>', getline() can read spaces.

Example:

string name;

getline(cin, name);

If the user enters:

Amitesh Kumar Official

then the complete text:

Amitesh Kumar Official

is stored in the variable 'name'.


Example Program:

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string fullName;

    cout << "Enter your full name: ";

    getline(cin, fullName);

    cout << "Your name is: " << fullName;

    return 0;
}


============================================================

DIFFERENCE BETWEEN CIN AND GETLINE()

cin >> variable;

is generally used to read a word or token.

Example:

Input:

Amitesh Kumar

Result:

Amitesh


getline(cin, variable);

is used to read a complete line.

Example:

Input:

Amitesh Kumar

Result:

Amitesh Kumar


Therefore:

cin >>     = reads a word/token
getline()  = reads a complete line


============================================================

CIN AND GETLINE() TOGETHER

A common problem occurs when 'cin' is used before 'getline()'.

Example:

int age;
string name;

cin >> age;
getline(cin, name);

Suppose the input is:

20
Amitesh Kumar

After reading 20, the newline character remains in the input buffer.

As a result, getline() may immediately read that newline instead of reading the name.

To solve this problem, we can use:

cin.ignore();


Example:

int age;
string name;

cin >> age;

cin.ignore();

getline(cin, name);


A more robust approach is:

#include <limits>

cin.ignore(numeric_limits<streamsize>::max(), '\n');


============================================================

WHAT ARE OPERATORS?

An operator is a special symbol that tells the compiler to perform a particular operation.

Operators are used to perform calculations, comparisons, assignments, logical operations, and many other operations.

The values or variables on which operators work are called operands.

Example:

int result = a + b;

Here:

a and b       = operands
+             = arithmetic operator
=             = assignment operator
result        = variable


============================================================

TYPES OF OPERATORS IN C++

The major categories of operators in C++ are:

1. Arithmetic Operators
2. Assignment Operators
3. Relational Operators
4. Logical Operators
5. Increment Operators
6. Decrement Operators
7. Modulus Operator
8. Bitwise Operators
9. Conditional/Ternary Operator
10. Compound Assignment Operators


============================================================

ARITHMETIC OPERATORS

Arithmetic operators are used to perform mathematical calculations.

The main arithmetic operators are:

+       Addition
-       Subtraction
*       Multiplication
/       Division
%       Modulus or Remainder


Example:

int a = 10;
int b = 3;

cout << a + b << endl;
cout << a - b << endl;
cout << a * b << endl;
cout << a / b << endl;
cout << a % b << endl;


The results are:

a + b = 13
a - b = 7
a * b = 30
a / b = 3
a % b = 1


============================================================

ADDITION OPERATOR (+)

The '+' operator is used to add two values.

Example:

int a = 10;
int b = 20;

int result = a + b;

cout << result;

Output:

30


The '+' operator can also be used with floating-point numbers.

Example:

double a = 10.5;
double b = 20.5;

cout << a + b;

Output:

31


============================================================

SUBTRACTION OPERATOR (-)

The '-' operator is used to subtract one value from another.

Example:

int a = 20;
int b = 10;

int result = a - b;

cout << result;

Output:

10


============================================================

MULTIPLICATION OPERATOR (*)

The '*' operator is used to multiply two values.

Example:

int a = 10;
int b = 5;

int result = a * b;

cout << result;

Output:

50


============================================================

DIVISION OPERATOR (/)

The '/' operator is used to divide one value by another.

Example:

int a = 10;
int b = 2;

int result = a / b;

cout << result;

Output:

5


IMPORTANT:

When both operands are integers, C++ performs integer division.

Example:

int a = 10;
int b = 3;

cout << a / b;

Output:

3

The decimal part is discarded.

If we want a decimal result, at least one operand should be floating-point.

Example:

double a = 10;
double b = 3;

cout << a / b;

Output:

3.33333...


============================================================

MODULUS OPERATOR (%)

The '%' operator is called the modulus or remainder operator.

It returns the remainder after integer division.

Example:

int a = 10;
int b = 3;

cout << a % b;

Output:

1

Because:

10 / 3 = 3 remainder 1

Therefore:

10 % 3 = 1


Another example:

17 % 5 = 2

because:

17 / 5 = 3 remainder 2


The modulus operator is commonly used to determine whether a number is even or odd.

Example:

int number;

cin >> number;

if(number % 2 == 0)
{
    cout << "Even";
}
else
{
    cout << "Odd";
}


============================================================

ASSIGNMENT OPERATOR (=)

The '=' operator is called the assignment operator.

It is used to assign a value to a variable.

Example:

int number;

number = 50;

Here, the value 50 is assigned to the variable 'number'.

The assignment operator does not mean mathematical equality.

Example:

int a = 10;

This means:

Store 10 inside a.


============================================================

RELATIONAL OPERATORS

Relational operators are used to compare two values.

The main relational operators are:

==      Equal to
!=      Not equal to
>       Greater than
<       Less than
>=      Greater than or equal to
<=      Less than or equal to


These operators produce a boolean result:

true
or
false


Example:

int a = 10;
int b = 20;

cout << (a < b);

Output:

1

By default, C++ displays 'true' as 1 and 'false' as 0.

We can use:

cout << boolalpha;

to display:

true
false


============================================================

EQUAL TO OPERATOR (==)

The '==' operator checks whether two values are equal.

Example:

int a = 10;
int b = 10;

cout << (a == b);

Output:

1

The expression is true because both values are equal.


IMPORTANT:

'=' and '==' are different.

'='

is the assignment operator.

'=='

is the equality comparison operator.


Example:

int a = 10;

a = 20;

This changes the value of a.

But:

a == 20;

checks whether a is equal to 20.


============================================================

NOT EQUAL OPERATOR (!=)

The '!=' operator checks whether two values are different.

Example:

int a = 10;
int b = 20;

cout << (a != b);

Output:

1

The result is true because 10 and 20 are different.


============================================================

GREATER THAN (>)

The '>' operator checks whether the left value is greater than the right value.

Example:

int a = 20;
int b = 10;

cout << (a > b);

Output:

1


============================================================

LESS THAN (<)

The '<' operator checks whether the left value is smaller than the right value.

Example:

int a = 10;
int b = 20;

cout << (a < b);

Output:

1


============================================================

GREATER THAN OR EQUAL TO (>=)

The '>=' operator checks whether a value is greater than or equal to another value.

Example:

int age = 18;

cout << (age >= 18);

Output:

1

Because age is equal to 18.


============================================================

LESS THAN OR EQUAL TO (<=)

The '<=' operator checks whether a value is less than or equal to another value.

Example:

int age = 18;

cout << (age <= 18);

Output:

1


============================================================

LOGICAL OPERATORS

Logical operators are used to combine or modify conditions.

The main logical operators are:

&&      Logical AND
||      Logical OR
!       Logical NOT


============================================================

LOGICAL AND (&&)

The '&&' operator returns true only when both conditions are true.

Example:

int age = 20;

cout << (age >= 18 && age <= 60);

Both conditions are true:

age >= 18
age <= 60

Therefore, the final result is true.


Truth table:

true  && true  = true
true  && false = false
false && true  = false
false && false = false


Example:

int age = 25;

if(age >= 18 && age <= 60)
{
    cout << "Eligible";
}


============================================================

LOGICAL OR (||)

The '||' operator returns true if at least one condition is true.

Example:

int age = 15;

if(age < 18 || age > 60)
{
    cout << "Special category";
}


Truth table:

true  || true  = true
true  || false = true
false || true  = true
false || false = false


============================================================

LOGICAL NOT (!)

The '!' operator reverses a boolean condition.

If a condition is true, '!' makes it false.

If a condition is false, '!' makes it true.

Example:

bool value = true;

cout << !value;

Output:

0


Another example:

int age = 20;

cout << !(age < 18);

Since:

age < 18

is false,

the NOT operator changes it to true.


============================================================

INCREMENT OPERATOR (++)

The '++' operator increases a value by 1.

Example:

int number = 10;

number++;

Now:

number = 11


It is equivalent to:

number = number + 1;


There are two forms:

1. Pre-increment
2. Post-increment


PRE-INCREMENT:

++number;

The value is increased before it is used.


POST-INCREMENT:

number++;

The current value is used first, and then the value is increased.


Example:

int a = 5;

cout << ++a;

Output:

6


Example:

int a = 5;

cout << a++;

Output:

5

After the statement:

a = 6


============================================================

DECREMENT OPERATOR (--)

The '--' operator decreases a value by 1.

Example:

int number = 10;

number--;

Now:

number = 9


It is equivalent to:

number = number - 1;


There are two forms:

--number

and:

number--


PRE-DECREMENT:

int a = 5;

cout << --a;

Output:

4


POST-DECREMENT:

int a = 5;

cout << a--;

Output:

5

After the statement:

a = 4


============================================================

COMPOUND ASSIGNMENT OPERATORS

Compound assignment operators combine an arithmetic operation with assignment.

Common compound assignment operators are:

+=
-=
*=
/=
%=


Example:

int a = 10;

a += 5;

This is equivalent to:

a = a + 5;

Therefore:

a = 15


Example:

a -= 5;

is equivalent to:

a = a - 5;


Example:

a *= 5;

is equivalent to:

a = a * 5;


Example:

a /= 5;

is equivalent to:

a = a / 5;


Example:

a %= 5;

is equivalent to:

a = a % 5;


============================================================

TERNARY OR CONDITIONAL OPERATOR

The ternary operator is a short form of a simple if-else statement.

Its syntax is:

condition ? expression1 : expression2;


Example:

int age = 20;

string result = (age >= 18) ? "Adult" : "Minor";

cout << result;


Output:

Adult


The condition is checked first.

If the condition is true, the first expression is selected.

If the condition is false, the second expression is selected.


============================================================

OPERATOR PRECEDENCE

When an expression contains multiple operators, C++ follows a specific order to determine which operation should be performed first.

Example:

int result = 10 + 5 * 2;

The multiplication is performed before addition.

Therefore:

5 * 2 = 10

Then:

10 + 10 = 20

So:

result = 20


Parentheses can be used to change the order.

Example:

int result = (10 + 5) * 2;

First:

10 + 5 = 15

Then:

15 * 2 = 30

Therefore:

result = 30


It is generally a good practice to use parentheses when an expression may be difficult to understand.


============================================================

IMPORTANT DIFFERENCE BETWEEN = AND ==

One of the most common mistakes made by beginners is confusing '=' with '=='.

'=' means assignment.

Example:

int a;

a = 10;


'==' means comparison.

Example:

if(a == 10)
{
    cout << "a is 10";
}


Remember:

=       Assignment
==      Comparison


============================================================

EXAMPLE PROGRAM USING INPUT AND OPERATORS

#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "Enter two numbers: ";

    cin >> a >> b;

    cout << "Addition = " << a + b << endl;
    cout << "Subtraction = " << a - b << endl;
    cout << "Multiplication = " << a * b << endl;
    cout << "Division = " << a / b << endl;
    cout << "Remainder = " << a % b << endl;

    return 0;
}


Example Input:

10 3


Example Output:

Addition = 13
Subtraction = 7
Multiplication = 30
Division = 3
Remainder = 1


============================================================

CONCLUSION

Input and operators are fundamental parts of C++ programming.

Input allows a program to receive information from the user. The 'cin' object is commonly used for keyboard input, while 'getline()' is useful for reading complete lines containing spaces.

Operators allow a programmer to perform different types of operations on data. Arithmetic operators perform calculations, assignment operators assign values, relational operators compare values, logical operators combine conditions, and increment/decrement operators modify values by one.

A strong understanding of input and operators is necessary before learning more advanced C++ concepts such as conditional statements, loops, functions, arrays, pointers, classes, and data structures.

============================================================ss