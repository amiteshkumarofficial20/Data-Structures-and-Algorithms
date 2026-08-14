LOOPS IN C++

============================================================

A loop is a control structure in C++ that is used to execute a
block of statements repeatedly.

Loops are useful when we need to perform the same task multiple
times without writing the same code again and again.

For example, if we want to print numbers from 1 to 10, instead of
writing ten separate cout statements, we can use a loop.

============================================================

WHY DO WE USE LOOPS?

Loops help us:

1. Repeat a block of code.
2. Reduce code repetition.
3. Make programs shorter and easier to maintain.
4. Perform operations on a sequence of numbers or data.
5. Execute a statement until a particular condition becomes false.

============================================================

TYPES OF LOOPS IN C++

There are mainly three types of loops in C++:

1. for loop
2. while loop
3. do-while loop

============================================================

1. FOR LOOP

The for loop is generally used when the number of iterations is
known beforehand.

SYNTAX:

for(initialization; condition; update)
{
// statements
}

The for loop has three main parts:

1. Initialization
   It is executed only once at the beginning.

2. Condition
   It is checked before every iteration.

3. Update
   It changes the loop variable after every iteration.

Example:

for(int i = 1; i <= 5; i++)
{
cout << i << endl;
}

Output:

1
2
3
4
5

Working:

i = 1
Check: 1 <= 5 -> true
Print 1
i++

i = 2
Check: 2 <= 5 -> true
Print 2
i++

This continues until the condition becomes false.

============================================================

2. WHILE LOOP

The while loop is used when a block of code should execute
repeatedly as long as a condition is true.

SYNTAX:

while(condition)
{
// statements
}

The condition is checked before executing the loop body.

Example:

int i = 1;

while(i <= 5)
{
cout << i << endl;
i++;
}

Output:

1
2
3
4
5

If the condition is false from the beginning, the while loop
will not execute even once.

============================================================

3. DO-WHILE LOOP

The do-while loop is similar to the while loop, but there is one
important difference.

In a do-while loop, the loop body is executed at least once.

SYNTAX:

do
{
// statements
}
while(condition);

Example:

int i = 1;

do
{
cout << i << endl;
i++;
}
while(i <= 5);

Output:

1
2
3
4
5

The condition is checked after executing the loop body.

============================================================

WHILE LOOP VS DO-WHILE LOOP

WHILE LOOP:

while(condition)
{
// statements
}

The condition is checked first.

Therefore, the loop may execute zero times.

DO-WHILE LOOP:

do
{
// statements
}
while(condition);

The loop body executes first.

Therefore, it executes at least once.

============================================================

FOR LOOP VS WHILE LOOP

FOR LOOP:

A for loop is commonly used when the number of iterations is
known.

Example:

for(int i = 1; i <= 10; i++)

WHILE LOOP:

A while loop is commonly used when the number of iterations is
not known beforehand and depends mainly on a condition.

Example:

while(number != 0)

However, both loops can often be used to solve the same problem.

============================================================

INFINITE LOOP

An infinite loop is a loop that never terminates because its
condition always remains true.

Example:

while(true)
{
cout << "Hello";
}

This loop will continue executing until the program is stopped
or another control statement is used to terminate it.

Another example:

for(int i = 1; i <= 10;)
{
cout << i;
}

Here, i is never updated, so the condition remains true.

============================================================

BREAK STATEMENT

The break statement is used to immediately terminate a loop.

Example:

for(int i = 1; i <= 10; i++)
{
if(i == 5)
{
break;
}

    cout << i << endl;

}

Output:

1
2
3
4

When i becomes 5, break terminates the loop.

============================================================

CONTINUE STATEMENT

The continue statement skips the current iteration and moves to
the next iteration of the loop.

Example:

for(int i = 1; i <= 5; i++)
{
if(i == 3)
{
continue;
}

    cout << i << endl;

}

Output:

1
2
4
5

When i is 3, continue skips the remaining statements of that
iteration.

============================================================

NESTED LOOPS

A loop inside another loop is called a nested loop.

Example:

for(int i = 1; i <= 3; i++)
{
for(int j = 1; j <= 3; j++)
{
cout << "\* ";
}

    cout << endl;

}

Output:

---

---

---

The outer loop controls the rows.

The inner loop controls the columns.

============================================================

EXAMPLE: PRINT NUMBERS FROM 1 TO 10

#include <iostream>
using namespace std;

int main()
{
for(int i = 1; i <= 10; i++)
{
cout << i << endl;
}

    return 0;

}

============================================================

EXAMPLE: PRINT EVEN NUMBERS

#include <iostream>
using namespace std;

int main()
{
for(int i = 1; i <= 20; i++)
{
if(i % 2 == 0)
{
cout << i << " ";
}
}

    return 0;

}

Output:

2 4 6 8 10 12 14 16 18 20

============================================================

EXAMPLE: SUM OF FIRST N NATURAL NUMBERS

#include <iostream>
using namespace std;

int main()
{
int n;
int sum = 0;

    cout << "Enter a number: ";
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        sum = sum + i;
    }

    cout << "Sum = " << sum;

    return 0;

}

For n = 5:

1 + 2 + 3 + 4 + 5 = 15

Output:

Sum = 15

============================================================

IMPORTANT POINTS

1. A loop repeatedly executes a block of code.

2. The for loop is commonly used when the number of iterations
   is known.

3. The while loop checks the condition before execution.

4. The do-while loop executes the body at least once.

5. break terminates the loop immediately.

6. continue skips the current iteration.

7. A loop inside another loop is called a nested loop.

8. The loop condition must eventually become false if the loop is
   intended to terminate.

9. Incorrect loop conditions or updates can create an infinite
   loop.

============================================================

CONCLUSION

Loops are one of the most important control structures in C++.

They allow a programmer to repeat a block of code efficiently.

The three main loops are:

for
while
do-while

The choice of loop depends on the problem and the way the
repetition needs to be controlled.

============================================================
