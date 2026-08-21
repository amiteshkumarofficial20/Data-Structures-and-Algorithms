# C++ STL — Queue Notes

## 1. What is `queue`?

`queue` is a container adaptor provided by the C++ Standard Template Library (STL).

It follows the **FIFO** principle:

```text
FIFO = First In, First Out
```

The element that enters first is the element that leaves first.

Real-life example:

```text
Person 1 -> Person 2 -> Person 3 -> Person 4
   ↑
First person in line
```

Person 1 will be served first.

In C++:

```cpp
#include <queue>
```

Basic declaration:

```cpp
queue<int> q;
```

---

# 2. Queue Concept

Suppose we insert:

```cpp
q.push(10);
q.push(20);
q.push(30);
q.push(40);
```

The queue conceptually looks like:

```text
FRONT                         BACK
  ↓                             ↓
[10] -> [20] -> [30] -> [40]
```

Here:

```text
10 = first element
40 = last element
```

If we call:

```cpp
q.pop();
```

`10` will be removed first.

Remaining:

```text
[20] -> [30] -> [40]
```

This is why queue follows:

```text
First In → First Out
```

---

# 3. Header File

To use queue:

```cpp
#include <queue>
```

Example:

```cpp
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;

    return 0;
}
```

---

# 4. Creating a Queue

## Empty Queue

```cpp
queue<int> q;
```

Initially:

```text
[]
```

---

## Queue of Other Data Types

Queue can store different data types.

```cpp
queue<int> q1;
queue<double> q2;
queue<char> q3;
queue<string> q4;
```

Examples:

```cpp
queue<int> numbers;
queue<string> names;
```

---

# 5. `push()`

`push()` adds an element at the **back** of the queue.

Example:

```cpp
queue<int> q;

q.push(10);
q.push(20);
q.push(30);
```

Queue becomes:

```text
FRONT                BACK
 ↓                     ↓
[10] -> [20] -> [30]
```

Important:

```text
push() → insertion at BACK
```

---

# 6. `pop()`

`pop()` removes the element from the **front** of the queue.

Example:

```cpp
queue<int> q;

q.push(10);
q.push(20);
q.push(30);

q.pop();
```

Before:

```text
[10] -> [20] -> [30]
 ↑
FRONT
```

After:

```text
[20] -> [30]
 ↑
FRONT
```

So `10` gets removed.

Important:

```text
pop() → removes FRONT element
```

---

# 7. Important: `pop()` Does Not Return the Element

This is a very common mistake.

Wrong:

```cpp
int x = q.pop();
```

This is invalid because `pop()` does not return the removed value.

Correct:

```cpp
int x = q.front();

q.pop();
```

Example:

```cpp
queue<int> q;

q.push(10);
q.push(20);

int x = q.front();

q.pop();

cout << x;
```

Output:

```text
10
```

---

# 8. `front()`

`front()` returns the element currently at the front.

Example:

```cpp
queue<int> q;

q.push(10);
q.push(20);
q.push(30);

cout << q.front();
```

Output:

```text
10
```

Conceptually:

```text
FRONT
 ↓
[10] -> [20] -> [30]
```

`front()` gives:

```text
10
```

---

# 9. `back()`

`back()` returns the element currently at the back.

Example:

```cpp
queue<int> q;

q.push(10);
q.push(20);
q.push(30);

cout << q.back();
```

Output:

```text
30
```

Conceptually:

```text
[10] -> [20] -> [30]
                   ↑
                  BACK
```

---

# 10. `size()`

`size()` returns the number of elements currently present.

Example:

```cpp
queue<int> q;

q.push(10);
q.push(20);
q.push(30);

cout << q.size();
```

Output:

```text
3
```

After:

```cpp
q.pop();
```

size becomes:

```text
2
```

---

# 11. `empty()`

`empty()` checks whether the queue contains no elements.

It returns:

```text
true  → queue is empty
false → queue is not empty
```

Example:

```cpp
queue<int> q;

if (q.empty())
{
    cout << "Queue is Empty";
}
```

Output:

```text
Queue is Empty
```

After adding:

```cpp
q.push(10);
```

Now:

```cpp
q.empty()
```

returns false.

---

# 12. Complete Basic Example

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Creating an empty queue of integers.
    queue<int> q;

    // Add elements at the back.
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    // Queue:
    //
    // FRONT                    BACK
    //   ↓                        ↓
    // [10] -> [20] -> [30] -> [40]


    // Print the front element.
    cout << "Front: " << q.front() << endl;


    // Print the back element.
    cout << "Back: " << q.back() << endl;


    // Print the number of elements.
    cout << "Size: " << q.size() << endl;


    // Remove the front element.
    q.pop();

    // Now:
    //
    // [20] -> [30] -> [40]


    cout << "Front after pop: "
         << q.front() << endl;


    return 0;
}
```

Output:

```text
Front: 10
Back: 40
Size: 4
Front after pop: 20
```

---

# 13. Why Queue Does Not Have `[]`

Queue does not support random access.

This is invalid:

```cpp
queue<int> q;

cout << q[2];
```

There is no:

```cpp
q[2]
```

There is also no:

```cpp
q.at(2)
```

Queue is designed around:

```text
front
   ↓
remove from front

back
   ↓
insert at back
```

So you normally access only:

```cpp
q.front();
q.back();
```

---

# 14. Queue Does Not Have Iterators

Unlike `vector` or `list`, the standard `queue` interface does not provide:

```cpp
q.begin();
q.end();
```

So this is invalid:

```cpp
for (auto it = q.begin(); it != q.end(); ++it)
{
    cout << *it;
}
```

A queue is meant to be processed from the front.

Typical processing:

```cpp
while (!q.empty())
{
    cout << q.front() << endl;
    q.pop();
}
```

---

# 15. Traversing a Queue

A queue does not normally support direct iteration.

If you want to process all elements, one common technique is:

```cpp
while (!q.empty())
{
    cout << q.front() << " ";

    q.pop();
}
```

Example:

```cpp
queue<int> q;

q.push(10);
q.push(20);
q.push(30);
q.push(40);

while (!q.empty())
{
    cout << q.front() << " ";

    q.pop();
}
```

Output:

```text
10 20 30 40
```

### Important

After this loop:

```cpp
q
```

becomes empty.

Because `pop()` permanently removes each element.

---

# 16. Step-by-Step Queue Traversal

Suppose:

```text
q = [10] -> [20] -> [30] -> [40]
```

### First iteration

```cpp
cout << q.front();
```

prints:

```text
10
```

Then:

```cpp
q.pop();
```

Queue becomes:

```text
[20] -> [30] -> [40]
```

### Second iteration

Print:

```text
20
```

Then pop.

Queue:

```text
[30] -> [40]
```

### Third iteration

Print:

```text
30
```

Then pop.

Queue:

```text
[40]
```

### Fourth iteration

Print:

```text
40
```

Then pop.

Queue:

```text
[]
```

Now:

```cpp
q.empty()
```

returns true and loop stops.

---

# 17. Safe Use of `front()` and `back()`

Do not call:

```cpp
q.front();
```

or:

```cpp
q.back();
```

when the queue is empty.

Unsafe:

```cpp
queue<int> q;

cout << q.front();
```

The queue has no elements, so this is invalid.

Safe:

```cpp
if (!q.empty())
{
    cout << q.front();
}
```

Similarly:

```cpp
if (!q.empty())
{
    cout << q.back();
}
```

---

# 18. `swap()`

Two queues can exchange their contents.

Example:

```cpp
queue<int> q1;
queue<int> q2;

q1.push(10);
q1.push(20);

q2.push(100);
q2.push(200);

q1.swap(q2);
```

Before:

```text
q1 = [10, 20]
q2 = [100, 200]
```

After:

```text
q1 = [100, 200]
q2 = [10, 20]
```

You can also use:

```cpp
swap(q1, q2);
```

---

# 19. Queue with String

Queue does not have to store integers.

Example:

```cpp
queue<string> q;

q.push("Rahul");
q.push("Aman");
q.push("Priya");
```

Queue:

```text
"Rahul" -> "Aman" -> "Priya"
```

Processing:

```cpp
while (!q.empty())
{
    cout << q.front() << endl;
    q.pop();
}
```

Output:

```text
Rahul
Aman
Priya
```

---

# 20. Queue with `pair`

Queue can store pairs too.

```cpp
queue<pair<int, int>> q;

q.push({1, 10});
q.push({2, 20});
q.push({3, 30});
```

Access:

```cpp
cout << q.front().first << " ";
cout << q.front().second;
```

Output:

```text
1 10
```

---

# 21. Queue in BFS

One of the most important uses of queue in DSA is:

```text
BFS = Breadth First Search
```

In graph or tree traversal, queue helps process elements level by level.

Example idea:

```text
        1
       / \
      2   3
     / \
    4   5
```

BFS order:

```text
1 2 3 4 5
```

Queue helps maintain the order.

Example:

```cpp
queue<int> q;

q.push(1);

while (!q.empty())
{
    int node = q.front();
    q.pop();

    // Process node...

    // Add next nodes...
}
```

---

# 22. Queue in Level Order Traversal

For a binary tree, queue is commonly used for level-order traversal.

Concept:

```text
Level 1:
1

Level 2:
2 3

Level 3:
4 5
```

Queue processes:

```text
1
↓
2, 3
↓
4, 5
```

This is why queue is a natural data structure for BFS and level-order traversal.

---

# 23. Queue vs Stack

This is a very important DSA comparison.

## Queue

```text
FIFO
First In First Out
```

Example:

```text
10 -> 20 -> 30

remove -> 10
```

Main operations:

```cpp
push()
pop()
front()
back()
```

## Stack

```text
LIFO
Last In First Out
```

Example:

```text
10
20
30

remove -> 30
```

Main operations:

```cpp
push()
pop()
top()
```

---

# 24. Queue vs Vector

| Feature       | Queue                     | Vector                     |
| ------------- | ------------------------- | -------------------------- |
| Main idea     | FIFO                      | Dynamic array              |
| Random access | No                        | Yes                        |
| `[]`          | No                        | Yes                        |
| `front()`     | Yes                       | Yes, as vector member      |
| `back()`      | Yes                       | Yes                        |
| `push()`      | Yes                       | No                         |
| `push_back()` | No direct queue interface | Yes                        |
| `pop()`       | Yes                       | No direct vector interface |
| Iterators     | No public queue interface | Yes                        |
| Main use      | Processing in order       | General-purpose storage    |

---

# 25. Queue vs List

| Feature        | Queue                       | List               |
| -------------- | --------------------------- | ------------------ |
| Type           | Container adaptor           | Sequence container |
| FIFO interface | Yes                         | No                 |
| `push()`       | Yes                         | No                 |
| `pop()`        | Yes                         | No                 |
| `push_front()` | Not part of queue interface | Yes                |
| `push_back()`  | Not part of queue interface | Yes                |
| Iterators      | No public interface         | Yes                |
| `front()`      | Yes                         | Yes                |
| `back()`       | Yes                         | Yes                |

Important:

`queue` is an **adapter**. It provides a restricted interface on top of an underlying container.

---

# 26. Underlying Container

By default, `std::queue` is commonly backed by:

```cpp
deque
```

Conceptually:

```cpp
queue<int> q;
```

uses a `deque<int>` underneath unless another suitable container is specified.

The queue exposes only the operations appropriate for FIFO behavior.

---

# 27. Custom Underlying Container

A queue can be created using another suitable container.

For example:

```cpp
queue<int, list<int>> q;
```

This means:

```text
queue
  ↓
uses list<int> internally
```

Example:

```cpp
queue<int, list<int>> q;

q.push(10);
q.push(20);
q.push(30);
```

The queue interface still remains:

```cpp
q.push();
q.pop();
q.front();
q.back();
```

---

# 28. Complete Detailed Program

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // ============================================================
    // CREATING QUEUE
    // ============================================================

    // Creating an empty queue of integers.

    queue<int> q;


    // ============================================================
    // ADDING ELEMENTS USING push()
    // ============================================================

    // push() inserts the new element at the BACK.

    q.push(10);
    // Queue:
    //
    // FRONT             BACK
    //   ↓                 ↓
    // [10]

    q.push(20);
    // Queue:
    //
    // FRONT             BACK
    //   ↓                 ↓
    // [10] -> [20]

    q.push(30);
    // Queue:
    //
    // FRONT                    BACK
    //   ↓                        ↓
    // [10] -> [20] -> [30]

    q.push(40);
    // Queue:
    //
    // FRONT                           BACK
    //   ↓                               ↓
    // [10] -> [20] -> [30] -> [40]


    // ============================================================
    // front()
    // ============================================================

    // front() returns the first element.
    //
    // Current front = 10

    cout << "Front = " << q.front() << endl;


    // ============================================================
    // back()
    // ============================================================

    // back() returns the last element.
    //
    // Current back = 40

    cout << "Back = " << q.back() << endl;


    // ============================================================
    // size()
    // ============================================================

    // There are 4 elements currently.

    cout << "Size = " << q.size() << endl;


    // ============================================================
    // empty()
    // ============================================================

    // The queue is not empty.

    cout << "Empty = " << q.empty() << endl;


    // ============================================================
    // pop()
    // ============================================================

    // pop() removes the FRONT element.
    //
    // Current:
    //
    // [10] -> [20] -> [30] -> [40]
    //   ↑
    // FRONT
    //
    // 10 will be removed.

    q.pop();

    // Now:
    //
    // [20] -> [30] -> [40]

    cout << "Front after pop = "
         << q.front() << endl;


    // ============================================================
    // PROCESSING THE COMPLETE QUEUE
    // ============================================================

    // We can process every element from front to back.
    //
    // IMPORTANT:
    //
    // This loop destroys the queue because pop()
    // removes every element.

    while (!q.empty())
    {
        // Read the front element.

        cout << "Processing: "
             << q.front() << endl;

        // Remove it.

        q.pop();
    }


    // Queue is now empty.

    cout << "Final size = "
         << q.size() << endl;


    return 0;
}
```

---

# 29. Queue Operations Cheat Sheet

```cpp
#include <queue>
```

### Create

```cpp
queue<int> q;
```

### Add

```cpp
q.push(10);
```

### Remove front

```cpp
q.pop();
```

### Get front

```cpp
q.front();
```

### Get back

```cpp
q.back();
```

### Number of elements

```cpp
q.size();
```

### Check empty

```cpp
q.empty();
```

### Swap

```cpp
q1.swap(q2);
```

or:

```cpp
swap(q1, q2);
```

---

# 30. Time Complexity

For the standard queue interface, these operations are generally constant time:

| Operation | Complexity |
| --------- | ---------- |
| `push()`  | O(1)       |
| `pop()`   | O(1)       |
| `front()` | O(1)       |
| `back()`  | O(1)       |
| `size()`  | O(1)       |
| `empty()` | O(1)       |

---

# 31. Important Mistakes

## Mistake 1: Calling `pop()` and expecting a value

Wrong:

```cpp
int x = q.pop();
```

Correct:

```cpp
int x = q.front();
q.pop();
```

---

## Mistake 2: Accessing an empty queue

Wrong:

```cpp
queue<int> q;

cout << q.front();
```

Correct:

```cpp
if (!q.empty())
{
    cout << q.front();
}
```

---

## Mistake 3: Using `[]`

Wrong:

```cpp
q[2];
```

Queue does not support random access.

---

## Mistake 4: Trying to use iterators

Wrong:

```cpp
q.begin();
q.end();
```

The standard queue interface does not expose these.

---

# 32. Complete Mental Model

Suppose:

```cpp
queue<int> q;

q.push(10);
q.push(20);
q.push(30);
```

Think:

```text
FRONT                       BACK
 ↓                            ↓
[10] -> [20] -> [30]
```

Then:

```cpp
q.front();
```

gives:

```text
10
```

Then:

```cpp
q.back();
```

gives:

```text
30
```

Then:

```cpp
q.pop();
```

removes:

```text
10
```

Now:

```text
FRONT             BACK
 ↓                   ↓
[20] -> [30]
```

---

# 33. Final Revision

```text
QUEUE
  ↓
FIFO
  ↓
First In First Out
```

```cpp
q.push(x);
```

```text
Add at BACK
```

```cpp
q.pop();
```

```text
Remove from FRONT
```

```cpp
q.front();
```

```text
First element
```

```cpp
q.back();
```

```text
Last element
```

```cpp
q.size();
```

```text
Number of elements
```

```cpp
q.empty();
```

```text
Check whether empty
```

The most important queue pattern for DSA is:

```cpp
while (!q.empty())
{
    int x = q.front();
    q.pop();

    // Process x
}
```

This pattern appears very frequently in **BFS, level-order traversal, scheduling, and simulation problems**.
