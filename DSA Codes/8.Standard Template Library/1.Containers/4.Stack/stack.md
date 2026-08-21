# C++ STL — Stack Notes

## 1. What is `stack`?

`stack` is a **container adaptor** provided by the C++ Standard Template Library (STL).

It follows the:

```text
LIFO
Last In, First Out
```

principle.

The element inserted **last** is removed **first**.

Example:

```text
        TOP
         ↓
       [40]  ← Last inserted
       [30]
       [20]
       [10]  ← First inserted
```

If we call:

```cpp
s.pop();
```

`40` will be removed first.

---

# 2. Header File

To use stack:

```cpp
#include <stack>
```

Basic syntax:

```cpp
stack<int> s;
```

Here:

```text
stack<int>
     ↑
     Stack will store int values
```

---

# 3. Stack Concept

Suppose:

```cpp
stack<int> s;

s.push(10);
s.push(20);
s.push(30);
s.push(40);
```

The stack conceptually looks like:

```text
        TOP
         ↓
       [40]
       [30]
       [20]
       [10]
```

The last element inserted was `40`, so `40` is removed first.

This is:

```text
Last In → First Out
```

---

# 4. Creating a Stack

## Empty Stack

```cpp
stack<int> s;
```

Initially:

```text
[]
```

---

## Stack with Other Data Types

```cpp
stack<int> s1;
stack<double> s2;
stack<char> s3;
stack<string> s4;
```

Stack can store many different types.

---

# 5. `push()`

`push()` adds an element to the **top** of the stack.

Example:

```cpp
stack<int> s;

s.push(10);
s.push(20);
s.push(30);
```

Stack becomes:

```text
TOP
 ↓
[30]
[20]
[10]
```

Important:

```text
push() → adds at TOP
```

---

# 6. `pop()`

`pop()` removes the element from the **top**.

Example:

```cpp
stack<int> s;

s.push(10);
s.push(20);
s.push(30);

s.pop();
```

Before:

```text
TOP
 ↓
[30]
[20]
[10]
```

After:

```text
TOP
 ↓
[20]
[10]
```

So:

```text
30
```

is removed.

Important:

```text
pop() → removes TOP element
```

---

# 7. `pop()` Does Not Return the Removed Element

This is a very common mistake.

Wrong:

```cpp
int x = s.pop();
```

This is invalid.

Why?

Because:

```cpp
s.pop();
```

does not return the removed value.

Correct:

```cpp
int x = s.top();

s.pop();
```

Example:

```cpp
stack<int> s;

s.push(10);
s.push(20);
s.push(30);

int x = s.top();

s.pop();

cout << x;
```

Output:

```text
30
```

---

# 8. `top()`

`top()` returns the element currently at the top.

Example:

```cpp
stack<int> s;

s.push(10);
s.push(20);
s.push(30);

cout << s.top();
```

Output:

```text
30
```

Conceptually:

```text
TOP
 ↓
[30]
[20]
[10]
```

So:

```cpp
s.top()
```

gives:

```text
30
```

---

# 9. `size()`

`size()` returns the number of elements currently in the stack.

Example:

```cpp
stack<int> s;

s.push(10);
s.push(20);
s.push(30);

cout << s.size();
```

Output:

```text
3
```

After:

```cpp
s.pop();
```

size becomes:

```text
2
```

---

# 10. `empty()`

`empty()` checks whether the stack contains zero elements.

It returns:

```text
true  → stack is empty
false → stack is not empty
```

Example:

```cpp
stack<int> s;

if (s.empty())
{
    cout << "Stack is Empty";
}
```

Output:

```text
Stack is Empty
```

---

# 11. Complete Basic Example

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // Creating an empty stack of integers.
    stack<int> s;

    // Push elements onto the stack.
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    // Stack:
    //
    // TOP
    //  ↓
    // [40]
    // [30]
    // [20]
    // [10]


    // top() gives the top element.
    cout << "Top: " << s.top() << endl;


    // size() gives the number of elements.
    cout << "Size: " << s.size() << endl;


    // pop() removes the top element.
    s.pop();

    // 40 is removed.
    //
    // Stack:
    //
    // TOP
    //  ↓
    // [30]
    // [20]
    // [10]


    cout << "Top after pop: "
         << s.top() << endl;


    return 0;
}
```

Output:

```text
Top: 40
Size: 4
Top after pop: 30
```

---

# 12. Traversing a Stack

A standard `stack` does **not provide public `begin()` and `end()` iterators**.

So this is invalid:

```cpp
stack<int> s;

// ❌ Invalid
// s.begin();
// s.end();
```

You generally process a stack using:

```cpp
while (!s.empty())
{
    cout << s.top() << " ";
    s.pop();
}
```

Example:

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while (!s.empty())
    {
        // Read the top element.
        cout << s.top() << " ";

        // Remove the top element.
        s.pop();
    }

    return 0;
}
```

Output:

```text
40 30 20 10
```

Notice the reverse order.

Elements were inserted:

```text
10 20 30 40
```

but removed:

```text
40 30 20 10
```

This is LIFO.

---

# 13. Traversal Destroys the Stack

Consider:

```cpp
while (!s.empty())
{
    cout << s.top();
    s.pop();
}
```

Every `pop()` removes an element.

Therefore, after the loop:

```text
stack = empty
```

If you want to preserve the original stack, make a copy.

```cpp
stack<int> temp = s;

while (!temp.empty())
{
    cout << temp.top() << " ";

    temp.pop();
}
```

Now:

```text
temp   → empty
s      → unchanged
```

---

# 14. Stack of `string`

A stack can store strings.

```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<string> s;

    s.push("Rahul");
    s.push("Aman");
    s.push("Priya");

    cout << "Top: " << s.top() << endl;

    return 0;
}
```

Output:

```text
Top: Priya
```

Because `"Priya"` was inserted last.

---

# 15. Stack of `char`

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<char> s;

    s.push('A');
    s.push('B');
    s.push('C');

    cout << s.top();

    return 0;
}
```

Output:

```text
C
```

---

# 16. Stack of `double`

```cpp
stack<double> s;

s.push(10.5);
s.push(20.75);
s.push(30.25);
```

Top:

```text
30.25
```

---

# 17. Stack of `pair<int, int>`

Stack can store pairs too.

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // Every stack element is pair<int,int>.
    stack<pair<int, int>> s;

    s.push({1, 10});
    s.push({2, 20});
    s.push({3, 30});

    // top() returns a pair.
    //
    // We can access:
    //
    // first
    // second

    cout << "First: "
         << s.top().first << endl;

    cout << "Second: "
         << s.top().second << endl;

    return 0;
}
```

Output:

```text
First: 3
Second: 30
```

---

# 18. Stack of `vector<int>`

A stack can also contain vectors.

```cpp
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    // Every stack element is vector<int>.
    stack<vector<int>> s;

    s.push({1, 2, 3});
    s.push({4, 5});
    s.push({6, 7, 8});

    // Top vector is:
    //
    // [6, 7, 8]

    const vector<int>& current = s.top();

    for (int x : current)
    {
        cout << x << " ";
    }

    return 0;
}
```

Output:

```text
6 7 8
```

---

# 19. Stack of Custom `struct`

We can create our own data type and store it in a stack.

```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
};

int main()
{
    stack<Student> s;

    s.push({"Rahul", 20});
    s.push({"Aman", 21});
    s.push({"Priya", 19});

    // Last inserted Student is at the top.
    //
    // Top:
    //
    // Priya, 19

    cout << "Name: "
         << s.top().name << endl;

    cout << "Age: "
         << s.top().age << endl;

    return 0;
}
```

Output:

```text
Name: Priya
Age: 19
```

---

# 20. `swap()`

Two stacks can exchange their contents.

Example:

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> first;
    stack<int> second;

    first.push(10);
    first.push(20);
    first.push(30);

    second.push(100);
    second.push(200);

    // Before swap:
    //
    // first:
    // TOP
    //  ↓
    // [30]
    // [20]
    // [10]
    //
    // second:
    // TOP
    //  ↓
    // [200]
    // [100]


    first.swap(second);

    // After swap:
    //
    // first:
    // TOP
    //  ↓
    // [200]
    // [100]
    //
    // second:
    // TOP
    //  ↓
    // [30]
    // [20]
    // [10]

    return 0;
}
```

You can also use:

```cpp
swap(first, second);
```

---

# 21. Stack Does Not Support Random Access

This is invalid:

```cpp
stack<int> s;

s.push(10);
s.push(20);
s.push(30);

// ❌ Invalid
// cout << s[1];
```

There is no:

```cpp
s[i]
```

There is also no:

```cpp
s.at(i)
```

A stack intentionally exposes only its top.

---

# 22. Stack Does Not Have `begin()` / `end()`

This is invalid:

```cpp
stack<int> s;

// ❌ Invalid
// s.begin();
// s.end();
```

Because `stack` is a **container adaptor**.

Its intended interface is:

```cpp
s.push();
s.pop();
s.top();
s.size();
s.empty();
```

---

# 23. Why Stack Has No Iterator?

The stack abstraction is designed to allow access to only one end:

```text
        TOP
         ↓
       [40]
       [30]
       [20]
       [10]
```

You should interact with it through the top.

If arbitrary traversal were exposed, it would weaken the normal stack abstraction.

So:

```text
stack
  ↓
LIFO interface
  ↓
top() / push() / pop()
```

---

# 24. Stack vs Queue

This is one of the most important DSA comparisons.

## Stack

```text
LIFO
Last In, First Out
```

Example:

```text
        TOP
         ↓
       [30]
       [20]
       [10]
```

Remove:

```text
30
```

Main operations:

```cpp
push()
pop()
top()
```

---

## Queue

```text
FIFO
First In, First Out
```

Example:

```text
FRONT                 BACK
  ↓                     ↓
[10] -> [20] -> [30]
```

Remove:

```text
10
```

Main operations:

```cpp
push()
pop()
front()
back()
```

---

# 25. Stack vs Vector

| Feature        | Stack                     | Vector                    |
| -------------- | ------------------------- | ------------------------- |
| Main principle | LIFO                      | Dynamic array             |
| `push()`       | Yes                       | No                        |
| `push_back()`  | No direct stack interface | Yes                       |
| `pop()`        | Yes                       | No direct stack interface |
| `top()`        | Yes                       | No                        |
| `[]`           | No                        | Yes                       |
| Iterators      | No public interface       | Yes                       |
| Random access  | No                        | Yes                       |

---

# 26. Stack vs List

| Feature        | Stack                     | List               |
| -------------- | ------------------------- | ------------------ |
| Main principle | LIFO                      | Sequence container |
| `push()`       | Yes                       | No                 |
| `pop()`        | Yes                       | No                 |
| `top()`        | Yes                       | No                 |
| `push_front()` | No direct stack interface | Yes                |
| `push_back()`  | No direct stack interface | Yes                |
| Iterators      | No public interface       | Yes                |
| Random access  | No                        | No                 |

---

# 27. Stack Uses

Stack is extremely important in DSA.

Common applications:

```text
1. Function call stack
2. Recursion
3. Undo/Redo
4. Browser back history
5. Balanced parentheses
6. Expression evaluation
7. Infix / postfix / prefix problems
8. DFS
9. Monotonic stack problems
10. Backtracking
```

---

# 28. Stack for Balanced Parentheses

Suppose:

```text
({[]})
```

We can use a stack.

Idea:

```text
Opening bracket:
(
{
[
```

push them.

When a closing bracket comes:

```text
]
}
)
```

check the top and pop the matching opening bracket.

Example:

```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string s = "({[]})";

    stack<char> st;

    for (char ch : s)
    {
        // If opening bracket, push it.

        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            // If stack is empty, there is no opening bracket
            // to match the closing bracket.

            if (st.empty())
            {
                cout << "Not Balanced";
                return 0;
            }

            char top = st.top();

            // Check matching pairs.

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
            {
                cout << "Not Balanced";
                return 0;
            }

            // Matching opening bracket found.
            st.pop();
        }
    }

    // If stack is empty, all brackets matched.

    if (st.empty())
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Not Balanced";
    }

    return 0;
}
```

Output:

```text
Balanced
```

---

# 29. Stack for Reversing Data

A stack naturally reverses order.

Suppose:

```text
10 20 30 40
```

Push:

```text
10
20
30
40
```

Stack:

```text
TOP
 ↓
40
30
20
10
```

Pop order:

```text
40 30 20 10
```

Example:

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while (!s.empty())
    {
        cout << s.top() << " ";

        s.pop();
    }

    return 0;
}
```

Output:

```text
40 30 20 10
```

---

# 30. Stack and DFS

Stack is used in **Depth First Search (DFS)**.

Basic idea:

```cpp
stack<int> s;

s.push(start);

while (!s.empty())
{
    int node = s.top();
    s.pop();

    // Process node

    // Push next nodes
}
```

Because stack follows LIFO, the most recently added node is processed first.

---

# 31. Complete Stack Program

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // ============================================================
    // CREATING STACK
    // ============================================================

    // Create an empty stack of integers.

    stack<int> s;


    // ============================================================
    // PUSH ELEMENTS
    // ============================================================

    // push() adds elements at the TOP.

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    // Stack:
    //
    // TOP
    //  ↓
    // [40]
    // [30]
    // [20]
    // [10]


    // ============================================================
    // TOP ELEMENT
    // ============================================================

    cout << "Top Element: "
         << s.top() << endl;


    // ============================================================
    // SIZE
    // ============================================================

    cout << "Size: "
         << s.size() << endl;


    // ============================================================
    // CHECK EMPTY
    // ============================================================

    if (s.empty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Stack is Not Empty" << endl;
    }


    // ============================================================
    // POP
    // ============================================================

    // Remove top element.
    //
    // Current top = 40
    //
    // After pop():
    //
    // TOP
    //  ↓
    // [30]
    // [20]
    // [10]

    s.pop();


    // Check new top.

    cout << "Top after pop: "
         << s.top() << endl;


    // ============================================================
    // PROCESS COMPLETE STACK
    // ============================================================

    cout << "Remaining elements: ";

    while (!s.empty())
    {
        cout << s.top() << " ";

        s.pop();
    }

    cout << endl;


    // After this loop:
    //
    // stack is empty.

    cout << "Final size: "
         << s.size() << endl;


    return 0;
}
```

Output:

```text
Top Element: 40
Size: 4
Stack is Not Empty
Top after pop: 30
Remaining elements: 30 20 10
Final size: 0
```

---

# 32. Important Stack Functions

Remember these:

```cpp
push()
pop()
top()
size()
empty()
swap()
```

### Add

```cpp
s.push(10);
```

### Remove

```cpp
s.pop();
```

### Top element

```cpp
s.top();
```

### Size

```cpp
s.size();
```

### Check empty

```cpp
s.empty();
```

### Swap

```cpp
s1.swap(s2);
```

or:

```cpp
swap(s1, s2);
```

---

# 33. Time Complexity

| Operation | Complexity |
| --------- | ---------: |
| `push()`  |       O(1) |
| `pop()`   |       O(1) |
| `top()`   |       O(1) |
| `size()`  |       O(1) |
| `empty()` |       O(1) |
| `swap()`  |       O(1) |

---

# 34. Important Mistakes

## Mistake 1 — `pop()` return value

Wrong:

```cpp
int x = s.pop();
```

Correct:

```cpp
int x = s.top();
s.pop();
```

---

## Mistake 2 — Accessing empty stack

Wrong:

```cpp
stack<int> s;

cout << s.top();
```

Correct:

```cpp
if (!s.empty())
{
    cout << s.top();
}
```

---

## Mistake 3 — Using `[]`

Wrong:

```cpp
s[2];
```

Stack does not support random access.

---

## Mistake 4 — Using iterators

Wrong:

```cpp
s.begin();
s.end();
```

`std::stack` does not expose public iterators.

---

# 35. Stack Mental Model

Suppose:

```cpp
stack<int> s;

s.push(10);
s.push(20);
s.push(30);
```

Think:

```text
       TOP
        ↓
      [30]  ← Last In
      [20]
      [10]  ← First In
```

Then:

```cpp
s.top();
```

gives:

```text
30
```

Then:

```cpp
s.pop();
```

removes:

```text
30
```

Now:

```text
       TOP
        ↓
      [20]
      [10]
```

---

# 36. Final Cheat Sheet

```cpp
#include <stack>

stack<int> s;
```

```cpp
s.push(10);
```

```text
Add at TOP
```

```cpp
s.pop();
```

```text
Remove TOP
```

```cpp
s.top();
```

```text
Access TOP
```

```cpp
s.size();
```

```text
Number of elements
```

```cpp
s.empty();
```

```text
Check whether empty
```

```cpp
s.swap(other);
```

```text
Exchange contents
```

---

# 37. One-Line Memory Trick

```text
STACK
  ↓
LIFO
  ↓
Last In → First Out
  ↓
push() → TOP par add
pop()  → TOP se remove
top()  → TOP ko dekho
```

Example:

```text
Push:
10 → 20 → 30 → 40

Stack:

       TOP
        ↓
       40
       30
       20
       10

Pop order:

40 → 30 → 20 → 10
```

The main difference between stack and queue:

```text
STACK  → LIFO → Last In, First Out
QUEUE  → FIFO → First In, First Out
```
