# C++ STL — Priority Queue Detailed Notes

# 1. What is `priority_queue`?

`priority_queue` is an STL **container adaptor** in C++.

Unlike a normal queue, which follows FIFO:

```text
First In, First Out
```

a `priority_queue` removes elements according to their **priority**.

By default, the element with the **largest value** has the highest priority.

So by default:

```text
priority_queue = Max Heap
```

Header file:

```cpp
#include <queue>
```

Basic syntax:

```cpp
priority_queue<int> pq;
```

---

# 2. Basic Concept

Suppose:

```cpp
priority_queue<int> pq;

pq.push(10);
pq.push(30);
pq.push(20);
pq.push(50);
pq.push(40);
```

The largest element gets the highest priority.

So:

```text
TOP
 ↓
50
40
30
20
10
```

The important thing is:

```cpp
pq.top();
```

will always give:

```text
50
```

because `50` is the largest element.

---

# 3. Priority Queue vs Normal Queue

## Normal Queue

A normal queue follows:

```text
FIFO
```

Example:

```text
10 -> 20 -> 30 -> 40
```

First inserted:

```text
10
```

First removed:

```text
10
```

---

## Priority Queue

A priority queue removes according to priority.

Example:

```text
10, 20, 30, 40
```

The largest element has the highest priority:

```text
40
```

So:

```cpp
pq.top();
```

gives:

```text
40
```

and:

```cpp
pq.pop();
```

removes:

```text
40
```

---

# 4. Header File

Use:

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
    priority_queue<int> pq;

    return 0;
}
```

---

# 5. Creating a Priority Queue

## Empty Priority Queue

```cpp
priority_queue<int> pq;
```

Initially:

```text
[]
```

---

## Priority Queue with Values

You can create a priority queue using a container and comparator, but for basic learning the common approach is:

```cpp
priority_queue<int> pq;
```

and then use:

```cpp
push()
```

to insert elements.

---

# 6. `push()`

`push()` inserts an element into the priority queue.

Example:

```cpp
priority_queue<int> pq;

pq.push(10);
pq.push(30);
pq.push(20);
```

The highest-priority element is automatically maintained at the top.

Conceptually:

```text
TOP
 ↓
30
20
10
```

Important:

The internal arrangement is heap-based, so you should **not assume the whole priority queue is sorted**.

Only the top element is guaranteed to have the highest priority.

---

# 7. `top()`

`top()` returns the highest-priority element.

For a default `priority_queue<int>`:

```cpp
priority_queue<int> pq;

pq.push(10);
pq.push(50);
pq.push(20);

cout << pq.top();
```

Output:

```text
50
```

Because `50` is the largest value.

---

# 8. `pop()`

`pop()` removes the highest-priority element.

Example:

```cpp
priority_queue<int> pq;

pq.push(10);
pq.push(50);
pq.push(20);
```

Current top:

```text
50
```

Now:

```cpp
pq.pop();
```

removes:

```text
50
```

Now the highest-priority remaining element is:

```text
20
```

Therefore:

```cpp
cout << pq.top();
```

outputs:

```text
20
```

---

# 9. Important: `pop()` Does NOT Return the Value

This is a common mistake.

Wrong:

```cpp
int x = pq.pop();
```

This is invalid because `pop()` returns nothing.

Correct:

```cpp
int x = pq.top();
pq.pop();
```

Meaning:

```text
Step 1 → highest-priority value read karo
Step 2 → usko remove karo
```

---

# 10. `size()`

`size()` returns the number of elements currently present.

Example:

```cpp
priority_queue<int> pq;

pq.push(10);
pq.push(20);
pq.push(30);

cout << pq.size();
```

Output:

```text
3
```

After:

```cpp
pq.pop();
```

size becomes:

```text
2
```

---

# 11. `empty()`

`empty()` checks whether the priority queue contains no elements.

Example:

```cpp
priority_queue<int> pq;

if (pq.empty())
{
    cout << "Priority Queue is Empty";
}
else
{
    cout << "Priority Queue is Not Empty";
}
```

Return values:

```text
true  -> empty
false -> not empty
```

---

# 12. Basic Complete Example

```cpp
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // ============================================================
    // CREATING PRIORITY QUEUE
    // ============================================================

    // By default, priority_queue<int> is a MAX HEAP.
    //
    // The largest value will always have the highest priority.

    priority_queue<int> pq;


    // ============================================================
    // ADDING ELEMENTS
    // ============================================================

    pq.push(10);
    pq.push(40);
    pq.push(20);
    pq.push(50);
    pq.push(30);


    // ============================================================
    // TOP ELEMENT
    // ============================================================

    // The largest element is at the top.
    //
    // Elements inserted:
    //
    // 10, 40, 20, 50, 30
    //
    // Largest = 50

    cout << "Top: "
         << pq.top()
         << endl;


    // ============================================================
    // SIZE
    // ============================================================

    cout << "Size: "
         << pq.size()
         << endl;


    // ============================================================
    // POP
    // ============================================================

    // Remove the highest-priority element.
    //
    // 50 will be removed.

    pq.pop();


    // Now highest-priority remaining value is:
    //
    // 40

    cout << "Top after pop: "
         << pq.top()
         << endl;


    // ============================================================
    // EMPTY CHECK
    // ============================================================

    if (pq.empty())
    {
        cout << "Priority Queue is Empty"
             << endl;
    }
    else
    {
        cout << "Priority Queue is Not Empty"
             << endl;
    }


    return 0;
}
```

Output:

```text
Top: 50
Size: 5
Top after pop: 40
Priority Queue is Not Empty
```

---

# 13. Default Priority Queue = Max Heap

This is one of the most important points.

```cpp
priority_queue<int> pq;
```

is a:

```text
MAX HEAP
```

Meaning:

```text
largest element → top
```

Example:

```cpp
priority_queue<int> pq;

pq.push(5);
pq.push(100);
pq.push(20);
pq.push(1);
```

Then:

```cpp
pq.top();
```

gives:

```text
100
```

---

# 14. How to Create a Min Heap

Sometimes we want the **smallest** element at the top.

Use:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

This creates a:

```text
MIN HEAP
```

Meaning:

```text
smallest element → top
```

---

# 15. Min Heap Example

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    // ============================================================
    // MIN HEAP
    // ============================================================

    // Syntax:
    //
    // priority_queue<
    //     int,
    //     vector<int>,
    //     greater<int>
    // >
    //
    // First int:
    // -> data type
    //
    // vector<int>:
    // -> underlying container
    //
    // greater<int>:
    // -> comparison rule
    //
    // Result:
    // -> smallest element gets highest priority.

    priority_queue<int, vector<int>, greater<int>> pq;


    pq.push(50);
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(40);


    // Smallest value is at the top.
    //
    // Therefore:
    //
    // pq.top() = 10

    cout << "Top: "
         << pq.top()
         << endl;


    // Remove 10.

    pq.pop();


    // Now smallest remaining element is 20.

    cout << "Top after pop: "
         << pq.top()
         << endl;


    return 0;
}
```

Output:

```text
Top: 10
Top after pop: 20
```

---

# 16. Max Heap vs Min Heap

## Max Heap

```cpp
priority_queue<int> pq;
```

Top:

```text
largest value
```

Example:

```text
10, 50, 20, 30
```

Top:

```text
50
```

---

## Min Heap

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

Top:

```text
smallest value
```

Example:

```text
10, 50, 20, 30
```

Top:

```text
10
```

---

# 17. Why is `vector` Written in Min Heap Syntax?

This syntax:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

has three template parameters:

```text
priority_queue<
    data_type,
    underlying_container,
    comparator
>
```

So:

```text
int
 ↓
Element type
```

```text
vector<int>
 ↓
Underlying container
```

```text
greater<int>
 ↓
Comparison rule
```

The default underlying container of `priority_queue` is commonly `vector`.

---

# 18. `greater<int>`

`greater<int>` changes the priority ordering.

Default:

```cpp
priority_queue<int>
```

behaves like:

```text
largest first
```

Using:

```cpp
greater<int>
```

makes:

```text
smallest first
```

Example:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

Now:

```cpp
pq.top();
```

returns the smallest element.

---

# 19. Traversing a Priority Queue

A priority queue does **not provide public `begin()` and `end()` iterators**.

So:

```cpp
pq.begin(); // ❌
pq.end();   // ❌
```

are not available through the standard `priority_queue` interface.

To process elements, use:

```cpp
while (!pq.empty())
{
    cout << pq.top() << " ";
    pq.pop();
}
```

---

# 20. Printing a Max Heap

```cpp
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> pq;

    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);
    pq.push(30);

    // Process highest-priority element first.

    while (!pq.empty())
    {
        cout << pq.top() << " ";

        pq.pop();
    }

    return 0;
}
```

Output:

```text
50 40 30 20 10
```

Notice:

This output is sorted in descending order because we repeatedly remove the largest element.

---

# 21. Printing a Min Heap

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    // Min heap.

    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);
    pq.push(30);

    while (!pq.empty())
    {
        cout << pq.top() << " ";

        pq.pop();
    }

    return 0;
}
```

Output:

```text
10 20 30 40 50
```

---

# 22. Important: Priority Queue is NOT a Sorted Container

Suppose:

```cpp
priority_queue<int> pq;

pq.push(10);
pq.push(50);
pq.push(20);
pq.push(40);
pq.push(30);
```

Do NOT think the internal structure is:

```text
50 40 30 20 10
```

The underlying structure is a **heap**, not a fully sorted array.

What is guaranteed?

```text
top() = highest-priority element
```

After `pop()`, the heap reorganizes itself so that the next highest-priority element is on top.

---

# 23. Priority Queue Iterator Comparison

```text
vector:
begin() / end() → ✅

list:
begin() / end() → ✅

deque:
begin() / end() → ✅

queue:
public begin() / end() → ❌

stack:
public begin() / end() → ❌

priority_queue:
public begin() / end() → ❌
```

Priority queue is another container adaptor.

---

# 24. `priority_queue` With `pair`

Priority queues can store pairs.

```cpp
priority_queue<pair<int, int>> pq;
```

By default, pairs are compared lexicographically.

That means:

1. Compare `first`
2. If `first` is equal, compare `second`

Example:

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<pair<int, int>> pq;

    pq.push({1, 10});
    pq.push({3, 20});
    pq.push({2, 30});
    pq.push({3, 15});

    // Top pair:
    //
    // {3, 20}
    //
    // because first = 3 is greater than 1 and 2,
    // and among first = 3:
    //
    // 20 > 15

    cout << pq.top().first << " "
         << pq.top().second
         << endl;

    return 0;
}
```

Output:

```text
3 20
```

---

# 25. Min Heap of Pairs

We can also create:

```cpp
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;
```

This makes the smallest pair have the highest priority.

---

# 26. Priority Queue of `string`

You can also store strings.

```cpp
priority_queue<string> pq;

pq.push("Apple");
pq.push("Orange");
pq.push("Banana");
```

The ordering follows the comparison rules for `string`.

Example:

```cpp
cout << pq.top();
```

For the default priority queue, the lexicographically greatest string has the highest priority.

---

# 27. Custom Comparator

Sometimes priority should not be based on the normal `<` comparison.

We can create our own comparator.

Example:

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Compare
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int main()
{
    // Custom comparator.
    //
    // This makes smaller values have higher priority.

    priority_queue<int, vector<int>, Compare> pq;

    pq.push(50);
    pq.push(10);
    pq.push(30);

    cout << pq.top();

    return 0;
}
```

Output:

```text
10
```

---

# 28. Priority Queue With Custom Struct

We can create a custom structure and comparator.

Example:

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Student
{
    string name;
    int marks;
};

struct Compare
{
    bool operator()(const Student& a,
                    const Student& b)
    {
        return a.marks < b.marks;
    }
};

int main()
{
    // Priority queue of Student objects.
    //
    // Student with HIGHER marks gets higher priority.

    priority_queue<Student,
                   vector<Student>,
                   Compare> pq;

    pq.push({"Rahul", 80});
    pq.push({"Aman", 95});
    pq.push({"Priya", 88});

    // Top student:
    //
    // Aman, 95

    cout << "Top student: "
         << pq.top().name
         << " "
         << pq.top().marks
         << endl;

    return 0;
}
```

Output:

```text
Top student: Aman 95
```

---

# 29. Priority Queue and `swap()`

Two priority queues can swap their contents.

Example:

```cpp
priority_queue<int> first;
priority_queue<int> second;

first.push(10);
first.push(20);

second.push(100);
second.push(200);

first.swap(second);
```

Before:

```text
first:
20
10

second:
200
100
```

After:

```text
first:
200
100

second:
20
10
```

You can also use:

```cpp
swap(first, second);
```

---

# 30. Safe Use of `top()`

Do not call:

```cpp
pq.top();
```

on an empty priority queue.

Wrong:

```cpp
priority_queue<int> pq;

cout << pq.top();
```

Correct:

```cpp
if (!pq.empty())
{
    cout << pq.top();
}
```

Similarly, do not call:

```cpp
pq.pop();
```

on an empty priority queue.

---

# 31. Priority Queue Processing Pattern

This is a very important DSA pattern:

```cpp
while (!pq.empty())
{
    int current = pq.top();

    pq.pop();

    // Process current
}
```

For a max heap:

```text
largest → process first
```

For a min heap:

```text
smallest → process first
```

---

# 32. Max Heap Complete Example

```cpp
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // ============================================================
    // MAX HEAP
    // ============================================================

    // Default priority_queue is a max heap.
    //
    // Largest element = highest priority.

    priority_queue<int> pq;


    // Add elements.

    pq.push(10);
    pq.push(50);
    pq.push(30);
    pq.push(20);
    pq.push(40);


    // Current highest-priority element:
    //
    // 50

    cout << "Top: "
         << pq.top()
         << endl;


    // Process complete priority queue.

    cout << "Elements by priority: ";

    while (!pq.empty())
    {
        // Highest-priority element.

        cout << pq.top() << " ";

        // Remove it.

        pq.pop();
    }

    cout << endl;


    return 0;
}
```

Output:

```text
Top: 50
Elements by priority: 50 40 30 20 10
```

---

# 33. Min Heap Complete Example

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    // ============================================================
    // MIN HEAP
    // ============================================================

    // Smallest element = highest priority.

    priority_queue<int,
                   vector<int>,
                   greater<int>> pq;


    pq.push(10);
    pq.push(50);
    pq.push(30);
    pq.push(20);
    pq.push(40);


    // Top is the smallest element.

    cout << "Top: "
         << pq.top()
         << endl;


    // Process in increasing order.

    cout << "Elements by priority: ";

    while (!pq.empty())
    {
        cout << pq.top() << " ";

        pq.pop();
    }

    cout << endl;


    return 0;
}
```

Output:

```text
Top: 10
Elements by priority: 10 20 30 40 50
```

---

# 34. Priority Queue in DSA

Priority queue is extremely important in DSA.

Common applications:

```text
1. Dijkstra's Algorithm
2. Prim's Algorithm
3. Huffman Coding
4. Scheduling
5. Top K problems
6. Kth largest / Kth smallest
7. Merge K sorted arrays
8. Merge K sorted linked lists
9. Sliding window problems
10. Best-first search
11. Event simulation
```

---

# 35. Dijkstra Example Concept

In Dijkstra's algorithm, we commonly need the node with the **smallest current distance**.

Therefore a min heap is useful:

```cpp
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;
```

A common representation is:

```text
{distance, node}
```

Example:

```cpp
pq.push({0, source});
```

Then:

```cpp
auto [distance, node] = pq.top();
pq.pop();
```

The smallest distance is processed first.

---

# 36. Top K Problems

Priority queue is frequently used when we need:

```text
Top K largest
Top K smallest
Kth largest
Kth smallest
```

For example, a max heap naturally gives the largest element:

```cpp
priority_queue<int> pq;
```

and:

```cpp
pq.top();
```

gives the current largest element.

A min heap gives the smallest:

```cpp
priority_queue<int,
               vector<int>,
               greater<int>> pq;
```

---

# 37. Time Complexity

For a binary-heap based priority queue, the standard operations are typically:

| Operation | Complexity |
| --------- | ---------: |
| `push()`  |   O(log n) |
| `pop()`   |   O(log n) |
| `top()`   |       O(1) |
| `size()`  |       O(1) |
| `empty()` |       O(1) |

Why is `push()` O(log n)?

Because after insertion, the heap may need to move the new element upward to restore the heap property.

Why is `pop()` O(log n)?

Because after removing the top, the replacement element may need to move downward.

---

# 38. Priority Queue vs Queue

| Feature          | Queue           | Priority Queue             |
| ---------------- | --------------- | -------------------------- |
| Principle        | FIFO            | Priority                   |
| `push()`         | Back            | Heap according to priority |
| `pop()`          | Front           | Highest-priority element   |
| `front()`        | Yes             | No                         |
| `back()`         | Yes             | No                         |
| `top()`          | No              | Yes                        |
| Random access    | No              | No                         |
| Public iterators | No              | No                         |
| Main use         | FIFO processing | Priority-based processing  |

---

# 39. Priority Queue vs Stack

| Feature                   | Stack                  | Priority Queue   |
| ------------------------- | ---------------------- | ---------------- |
| Principle                 | LIFO                   | Priority         |
| Add                       | `push()`               | `push()`         |
| Remove                    | `pop()`                | `pop()`          |
| Access                    | `top()`                | `top()`          |
| Highest priority based on | Most recently inserted | Comparator/order |
| Public iterators          | No                     | No               |

Important:

```text
Stack:
Last inserted → first removed

Priority Queue:
Highest priority → first removed
```

---

# 40. Priority Queue vs Set

These are often confused.

### Priority Queue

Allows duplicate values:

```cpp
priority_queue<int> pq;

pq.push(10);
pq.push(10);
pq.push(20);
```

Duplicates are allowed.

### Set

Stores unique values:

```cpp
set<int> s;

s.insert(10);
s.insert(10);
s.insert(20);
```

Only one `10` remains.

---

# 41. Important: `priority_queue` Allows Duplicates

Example:

```cpp
priority_queue<int> pq;

pq.push(50);
pq.push(50);
pq.push(20);
```

The queue contains three elements.

Processing:

```text
50
50
20
```

Duplicates are allowed.

---

# 42. Important: Heap Is Not Fully Sorted

Suppose:

```cpp
priority_queue<int> pq;

pq.push(10);
pq.push(50);
pq.push(20);
pq.push(40);
pq.push(30);
```

You cannot assume the internal container is:

```text
50 40 30 20 10
```

The heap guarantees that:

```cpp
pq.top()
```

is the highest-priority element.

If you repeatedly call:

```cpp
top()
pop()
```

then you will retrieve elements in priority order.

---

# 43. Complete Priority Queue Notes Program

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    // ============================================================
    // MAX HEAP
    // ============================================================

    // Default priority_queue:
    //
    // Largest value gets highest priority.

    priority_queue<int> pq;


    // ============================================================
    // PUSH
    // ============================================================

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(50);
    pq.push(40);


    // Current highest-priority element:
    //
    // 50

    cout << "Top element: "
         << pq.top()
         << endl;


    // ============================================================
    // SIZE
    // ============================================================

    cout << "Size: "
         << pq.size()
         << endl;


    // ============================================================
    // POP
    // ============================================================

    // Remove 50.

    pq.pop();


    // Now top = 40

    cout << "Top after pop: "
         << pq.top()
         << endl;


    // ============================================================
    // EMPTY CHECK
    // ============================================================

    if (pq.empty())
    {
        cout << "Priority Queue is Empty"
             << endl;
    }
    else
    {
        cout << "Priority Queue is Not Empty"
             << endl;
    }


    // ============================================================
    // PROCESSING ALL ELEMENTS
    // ============================================================

    cout << "Processing: ";

    while (!pq.empty())
    {
        // Highest-priority element.

        cout << pq.top() << " ";

        // Remove it.

        pq.pop();
    }

    cout << endl;


    // ============================================================
    // MIN HEAP
    // ============================================================

    // Create a MIN HEAP.
    //
    // Smallest value will have highest priority.

    priority_queue<int,
                   vector<int>,
                   greater<int>> minPQ;


    minPQ.push(50);
    minPQ.push(10);
    minPQ.push(30);
    minPQ.push(20);
    minPQ.push(40);


    cout << "Min heap top: "
         << minPQ.top()
         << endl;


    // Process min heap.

    cout << "Min heap processing: ";

    while (!minPQ.empty())
    {
        cout << minPQ.top() << " ";

        minPQ.pop();
    }

    cout << endl;


    return 0;
}
```

---

# 44. Important Syntax to Memorize

## Max Heap

```cpp
priority_queue<int> pq;
```

Meaning:

```text
Largest → top
```

---

## Min Heap

```cpp
priority_queue<int,
               vector<int>,
               greater<int>> pq;
```

Meaning:

```text
Smallest → top
```

---

## Pair Min Heap

```cpp
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;
```

Useful for:

```text
{distance, node}
```

in graph algorithms.

---

# 45. Important Safety Rules

Never do:

```cpp
pq.top();
```

when:

```cpp
pq.empty() == true
```

Never do:

```cpp
pq.pop();
```

on an empty priority queue.

Safe pattern:

```cpp
if (!pq.empty())
{
    cout << pq.top();

    pq.pop();
}
```

Or:

```cpp
while (!pq.empty())
{
    int x = pq.top();
    pq.pop();

    // Process x
}
```

---

# 46. Final Cheat Sheet

```cpp
#include <queue>
```

### Create Max Heap

```cpp
priority_queue<int> pq;
```

### Add

```cpp
pq.push(10);
```

### Highest-priority element

```cpp
pq.top();
```

### Remove highest-priority element

```cpp
pq.pop();
```

### Number of elements

```cpp
pq.size();
```

### Check empty

```cpp
pq.empty();
```

### Swap

```cpp
pq1.swap(pq2);
```

or:

```cpp
swap(pq1, pq2);
```

### Create Min Heap

```cpp
priority_queue<int,
               vector<int>,
               greater<int>> pq;
```

---

# 47. Final Mental Model

```text
                 PRIORITY QUEUE
                       |
               +-------+-------+
               |               |
            MAX HEAP          MIN HEAP
               |               |
          largest top      smallest top
               |               |
            pq.top()        pq.top()
               |               |
            pq.pop()         pq.pop()
```

### Max Heap

```text
push:
10, 50, 20, 40

top:
50
```

### Min Heap

```text
push:
10, 50, 20, 40

top:
10
```

### One-line memory trick

```text
Queue         → FIFO
Stack         → LIFO
Priority Queue→ Highest Priority First
Deque         → Both Ends
```

And the two most important priority queue declarations are:

```cpp
// MAX HEAP
priority_queue<int> pq;
```

```cpp
// MIN HEAP
priority_queue<int, vector<int>, greater<int>> pq;
```
