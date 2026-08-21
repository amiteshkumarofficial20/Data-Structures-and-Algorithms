# C++ STL — Deque Notes

## 1. What is `deque`?

`deque` stands for:

```text
Double Ended Queue
```

It is an STL sequence container that allows insertion and deletion from **both ends**.

Header file:

```cpp
#include <deque>
```

Basic syntax:

```cpp
deque<int> dq;
```

A deque supports:

```text
push_front()
push_back()

pop_front()
pop_back()
```

It also supports **random access** like a vector:

```cpp
dq[0]
dq[1]
dq[2]
```

---

# 2. Basic Concept of Deque

Suppose:

```cpp
deque<int> dq = {20, 30};
```

Conceptually:

```text
FRONT                    BACK
  ↓                        ↓
[20] -> [30]
```

Now:

```cpp
dq.push_front(10);
```

becomes:

```text
FRONT                           BACK
  ↓                               ↓
[10] -> [20] -> [30]
```

Now:

```cpp
dq.push_back(40);
```

becomes:

```text
FRONT                                   BACK
  ↓                                       ↓
[10] -> [20] -> [30] -> [40]
```

So deque allows insertion at **both front and back**.

---

# 3. Deque vs Queue

This is important.

### Queue

Queue mainly follows:

```text
FIFO
First In, First Out
```

Its public interface mainly gives:

```cpp
push()
pop()
front()
back()
```

### Deque

Deque allows operations at both ends:

```cpp
push_front()
push_back()

pop_front()
pop_back()
```

Deque also supports random access:

```cpp
dq[i]
```

So deque is more flexible than a queue.

---

# 4. Deque vs Vector

Vector:

```cpp
vector<int> v;
```

Deque:

```cpp
deque<int> dq;
```

Both support random access:

```cpp
v[2];
dq[2];
```

But deque provides efficient insertion/removal at **both ends**.

### Vector

```cpp
v.push_back(10);  // ✅
v.pop_back();     // ✅

v.push_front(10); // ❌
v.pop_front();    // ❌
```

### Deque

```cpp
dq.push_front(10); // ✅
dq.push_back(20);  // ✅

dq.pop_front();    // ✅
dq.pop_back();     // ✅
```

---

# 5. Creating a Deque

## Empty deque

```cpp
deque<int> dq;
```

Initially:

```text
[]
```

---

## Deque with values

```cpp
deque<int> dq = {10, 20, 30, 40};
```

Conceptually:

```text
[10] [20] [30] [40]
```

---

## Deque with same value

```cpp
deque<int> dq(5, 10);
```

Creates:

```text
[10] [10] [10] [10] [10]
```

Size:

```text
5
```

---

## Deque with size

```cpp
deque<int> dq(5);
```

Creates 5 integer elements initialized to `0`:

```text
[0] [0] [0] [0] [0]
```

---

# 6. `push_back()`

`push_back()` adds an element at the **back**.

```cpp
deque<int> dq;

dq.push_back(10);
dq.push_back(20);
dq.push_back(30);
```

Deque:

```text
FRONT              BACK
  ↓                  ↓
[10] -> [20] -> [30]
```

Time complexity:

```text
O(1) amortized
```

---

# 7. `push_front()`

`push_front()` adds an element at the **front**.

```cpp
deque<int> dq = {20, 30};

dq.push_front(10);
```

Result:

```text
[10] -> [20] -> [30]
```

This is one of the biggest advantages of deque over vector.

Time complexity:

```text
O(1) amortized
```

---

# 8. `pop_back()`

`pop_back()` removes the last element.

```cpp
deque<int> dq = {10, 20, 30};

dq.pop_back();
```

Result:

```text
[10] -> [20]
```

Time complexity:

```text
O(1)
```

Important:

`pop_back()` does not return the removed value.

---

# 9. `pop_front()`

`pop_front()` removes the first element.

```cpp
deque<int> dq = {10, 20, 30};

dq.pop_front();
```

Result:

```text
[20] -> [30]
```

Time complexity:

```text
O(1)
```

---

# 10. `front()`

`front()` returns the first element.

```cpp
deque<int> dq = {10, 20, 30};

cout << dq.front();
```

Output:

```text
10
```

---

# 11. `back()`

`back()` returns the last element.

```cpp
cout << dq.back();
```

Output:

```text
30
```

---

# 12. `size()`

`size()` returns the current number of elements.

```cpp
deque<int> dq = {10, 20, 30, 40};

cout << dq.size();
```

Output:

```text
4
```

---

# 13. `empty()`

`empty()` checks whether the deque contains zero elements.

```cpp
deque<int> dq;

if (dq.empty())
{
    cout << "Deque is empty";
}
```

Return values:

```text
true  -> empty
false -> not empty
```

---

# 14. `clear()`

`clear()` removes all elements.

```cpp
deque<int> dq = {10, 20, 30};

dq.clear();
```

Now:

```text
[]
```

And:

```cpp
dq.size()
```

is:

```text
0
```

---

# 15. Random Access

Unlike `queue`, deque supports random access.

Example:

```cpp
deque<int> dq = {10, 20, 30, 40};

cout << dq[2];
```

Output:

```text
30
```

Indexing starts from `0`.

```text
Index:   0   1   2   3
Value:  10  20  30  40
```

---

# 16. `at()`

Deque also supports bounds-checked access using `at()`.

```cpp
deque<int> dq = {10, 20, 30};

cout << dq.at(1);
```

Output:

```text
20
```

Difference:

```cpp
dq[1]
```

does not perform bounds checking.

```cpp
dq.at(1)
```

performs bounds checking.

If the index is invalid, `at()` can throw `std::out_of_range`.

---

# 17. `operator[]` vs `at()`

```cpp
deque<int> dq = {10, 20, 30};
```

### Using `[]`

```cpp
cout << dq[1];
```

Gives:

```text
20
```

### Using `at()`

```cpp
cout << dq.at(1);
```

Also gives:

```text
20
```

But `at()` checks bounds.

---

# 18. `begin()` and `end()`

Unlike `queue` and `stack`, deque provides iterators.

```cpp
deque<int> dq = {10, 20, 30, 40};

deque<int>::iterator it = dq.begin();

while (it != dq.end())
{
    cout << *it << " ";
    ++it;
}
```

Output:

```text
10 20 30 40
```

---

# 19. Understanding `begin()`

`begin()` points to the first element.

```text
[10] [20] [30] [40]
 ↑
begin()
```

So:

```cpp
auto it = dq.begin();
```

means:

```text
it → 10
```

Then:

```cpp
*it
```

gives:

```text
10
```

---

# 20. Understanding `end()`

`end()` points just after the last element.

Conceptually:

```text
[10] [20] [30] [40] [END]
                                ↑
                              end()
```

Do not dereference `end()`:

```cpp
* dq.end();   // ❌
```

Correct traversal:

```cpp
for (auto it = dq.begin(); it != dq.end(); ++it)
{
    cout << *it << " ";
}
```

---

# 21. Reverse Iterators

Deque also supports:

```cpp
rbegin()
rend()
```

Example:

```cpp
deque<int> dq = {10, 20, 30, 40};

for (auto it = dq.rbegin(); it != dq.rend(); ++it)
{
    cout << *it << " ";
}
```

Output:

```text
40 30 20 10
```

---

# 22. Range-Based For Loop

Deque works with range-based loops.

```cpp
deque<int> dq = {10, 20, 30, 40};

for (int x : dq)
{
    cout << x << " ";
}
```

Output:

```text
10 20 30 40
```

Using `auto`:

```cpp
for (auto x : dq)
{
    cout << x << " ";
}
```

Using const reference:

```cpp
for (const auto& x : dq)
{
    cout << x << " ";
}
```

---

# 23. `insert()`

Deque supports insertion at arbitrary positions.

Example:

```cpp
deque<int> dq = {10, 20, 30};

dq.insert(dq.begin() + 1, 15);
```

Result:

```text
[10] [15] [20] [30]
```

Here:

```cpp
dq.begin() + 1
```

points to index `1`.

Important:

Insertion in the middle is generally not constant time.

It can require moving elements.

---

# 24. `erase()`

Deque supports `erase()`.

Example:

```cpp
deque<int> dq = {10, 20, 30, 40};

dq.erase(dq.begin() + 1);
```

Removes:

```text
20
```

Result:

```text
[10] [30] [40]
```

---

# 25. Erasing a Range

```cpp
deque<int> dq = {10, 20, 30, 40, 50};

dq.erase(dq.begin() + 1,
         dq.begin() + 4);
```

The range is:

```text
[start, end)
```

So these are removed:

```text
20, 30, 40
```

Result:

```text
[10] [50]
```

---

# 26. `insert()` Multiple Elements

You can insert multiple copies of a value.

```cpp
deque<int> dq = {10, 40};

dq.insert(dq.begin() + 1, 3, 20);
```

Result:

```text
[10] [20] [20] [20] [40]
```

Syntax:

```cpp
dq.insert(position, count, value);
```

---

# 27. `resize()`

`resize()` changes the number of elements.

Example:

```cpp
deque<int> dq = {10, 20, 30};

dq.resize(5);
```

New elements are value-initialized:

```text
[10] [20] [30] [0] [0]
```

---

# 28. `resize()` with a Value

```cpp
deque<int> dq = {10, 20};

dq.resize(5, 100);
```

Result:

```text
[10] [20] [100] [100] [100]
```

---

# 29. `swap()`

Two deques can exchange their contents.

```cpp
deque<int> first = {10, 20};
deque<int> second = {100, 200, 300};

first.swap(second);
```

Before:

```text
first  = [10, 20]
second = [100, 200, 300]
```

After:

```text
first  = [100, 200, 300]
second = [10, 20]
```

Alternative:

```cpp
swap(first, second);
```

---

# 30. `assign()`

`assign()` replaces the existing contents.

Example:

```cpp
deque<int> dq;

dq.assign(5, 10);
```

Result:

```text
[10] [10] [10] [10] [10]
```

Another form:

```cpp
deque<int> dq = {10, 20, 30, 40};

dq.assign({100, 200, 300});
```

Result:

```text
[100] [200] [300]
```

---

# 31. Deque with Other Data Types

Deque can store many data types.

```cpp
deque<int> d1;

deque<float> d2;

deque<double> d3;

deque<char> d4;

deque<bool> d5;

deque<string> d6;

deque<long long> d7;

deque<pair<int, int>> d8;

deque<vector<int>> d9;
```

The idea is:

```text
deque<T>
     ↓
T = element type
```

---

# 32. Deque of String

```cpp
#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    deque<string> dq;

    dq.push_back("Aman");
    dq.push_front("Rahul");
    dq.push_back("Priya");

    for (const auto& name : dq)
    {
        cout << name << endl;
    }

    return 0;
}
```

Output:

```text
Rahul
Aman
Priya
```

---

# 33. Deque of Pair

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<pair<int, int>> dq;

    dq.push_back({1, 100});
    dq.push_back({2, 200});
    dq.push_front({0, 50});

    for (const auto& p : dq)
    {
        cout << p.first << " "
             << p.second << endl;
    }

    return 0;
}
```

Output:

```text
0 50
1 100
2 200
```

---

# 34. Deque and Iterators

Deque iterators are **random-access iterators**.

This means operations like these are supported:

```cpp
it + 2
it - 2
it += 2
it -= 2
it[2]
```

Example:

```cpp
deque<int> dq = {10, 20, 30, 40, 50};

auto it = dq.begin();

it += 3;

cout << *it;
```

Output:

```text
40
```

Because:

```text
begin() -> 10

+1 -> 20
+2 -> 30
+3 -> 40
```

---

# 35. `distance()`

Because deque provides random-access iterators, we can calculate distance between iterators.

```cpp
deque<int> dq = {10, 20, 30, 40, 50};

auto first = dq.begin();
auto last = dq.end();

cout << distance(first, last);
```

Output:

```text
5
```

---

# 36. Complete Basic Deque Program

```cpp
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    // ============================================================
    // CREATING DEQUE
    // ============================================================

    // Creating an empty deque of integers.

    deque<int> dq;


    // ============================================================
    // PUSHING AT BACK
    // ============================================================

    // push_back() inserts an element at the BACK.

    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    // Current:
    //
    // FRONT              BACK
    //   ↓                  ↓
    // [10] -> [20] -> [30]


    // ============================================================
    // PUSHING AT FRONT
    // ============================================================

    // push_front() inserts an element at the FRONT.

    dq.push_front(5);

    // Current:
    //
    // FRONT                    BACK
    //   ↓                        ↓
    // [5] -> [10] -> [20] -> [30]


    // ============================================================
    // FRONT ELEMENT
    // ============================================================

    cout << "Front: "
         << dq.front()
         << endl;


    // ============================================================
    // BACK ELEMENT
    // ============================================================

    cout << "Back: "
         << dq.back()
         << endl;


    // ============================================================
    // SIZE
    // ============================================================

    cout << "Size: "
         << dq.size()
         << endl;


    // ============================================================
    // RANDOM ACCESS
    // ============================================================

    // Indexing starts from 0.
    //
    // Current:
    //
    // Index:  0   1   2   3
    // Value:  5  10  20  30

    cout << "Element at index 2: "
         << dq[2]
         << endl;


    // ============================================================
    // at()
    // ============================================================

    cout << "Element at index 1 using at(): "
         << dq.at(1)
         << endl;


    // ============================================================
    // POP FROM FRONT
    // ============================================================

    dq.pop_front();

    // 5 removed.
    //
    // Now:
    //
    // [10] -> [20] -> [30]


    // ============================================================
    // POP FROM BACK
    // ============================================================

    dq.pop_back();

    // 30 removed.
    //
    // Now:
    //
    // [10] -> [20]


    // ============================================================
    // PRINT USING RANGE-BASED LOOP
    // ============================================================

    cout << "Current deque: ";

    for (int x : dq)
    {
        cout << x << " ";
    }

    cout << endl;


    return 0;
}
```

Output:

```text
Front: 5
Back: 30
Size: 4
Element at index 2: 20
Element at index 1 using at(): 10
Current deque: 10 20
```

---

# 37. Deque with Iterators — Detailed Example

```cpp
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    // Create deque.

    deque<int> dq = {10, 20, 30, 40, 50};


    // ============================================================
    // FORWARD ITERATOR
    // ============================================================

    // begin() points to the first element.
    //
    // end() points just after the last element.

    deque<int>::iterator it = dq.begin();

    while (it != dq.end())
    {
        cout << *it << " ";

        ++it;
    }

    cout << endl;


    // ============================================================
    // RANDOM ACCESS USING ITERATOR
    // ============================================================

    it = dq.begin();

    // Move iterator 2 positions forward.

    it += 2;

    // Now it points to:
    //
    // 30

    cout << "Element: "
         << *it
         << endl;


    // ============================================================
    // MOVE BACKWARD
    // ============================================================

    it -= 1;

    // Now it points to:
    //
    // 20

    cout << "After it -= 1: "
         << *it
         << endl;


    // ============================================================
    // ITERATOR INDEXING
    // ============================================================

    // Random-access iterators support [].

    cout << "it[1]: "
         << it[1]
         << endl;

    // Current iterator points to 20.
    //
    // it[1] means:
    //
    // next position after current iterator
    //
    // So output = 30


    return 0;
}
```

---

# 38. Reverse Traversal

```cpp
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> dq = {10, 20, 30, 40};

    // rbegin() starts from the last element.
    //
    // rend() represents the position before the first element.

    for (auto it = dq.rbegin(); it != dq.rend(); ++it)
    {
        cout << *it << " ";
    }

    return 0;
}
```

Output:

```text
40 30 20 10
```

---

# 39. `erase()` with Iterator

```cpp
deque<int> dq = {10, 20, 30, 40};

auto it = dq.begin() + 1;

// it points to 20.

dq.erase(it);
```

Result:

```text
[10] [30] [40]
```

---

# 40. `insert()` with Iterator

```cpp
deque<int> dq = {10, 20, 30};

auto it = dq.begin() + 1;

// it points to 20.

dq.insert(it, 15);
```

Result:

```text
[10] [15] [20] [30]
```

---

# 41. Deque vs Vector vs List vs Queue

| Feature          | Vector | Deque | List | Queue        |
| ---------------- | ------ | ----- | ---- | ------------ |
| Random access    | ✅     | ✅    | ❌   | ❌           |
| `[]`             | ✅     | ✅    | ❌   | ❌           |
| Iterators        | ✅     | ✅    | ✅   | ❌ public    |
| `push_front()`   | ❌     | ✅    | ✅   | ❌ interface |
| `push_back()`    | ✅     | ✅    | ✅   | ❌ interface |
| `pop_front()`    | ❌     | ✅    | ✅   | ❌ interface |
| `pop_back()`     | ✅     | ✅    | ✅   | ❌ interface |
| `front()`        | ✅     | ✅    | ✅   | ✅           |
| `back()`         | ✅     | ✅    | ✅   | ✅           |
| FIFO abstraction | ❌     | ❌    | ❌   | ✅           |

---

# 42. Deque vs Stack

A `stack` is a container adaptor.

It allows:

```text
push
pop
top
```

Only one end is exposed.

Deque supports both ends:

```text
push_front
push_back
pop_front
pop_back
```

and also random access:

```cpp
dq[i]
```

---

# 43. Common Uses of Deque

Deque is useful when:

```text
1. You need insertion at both ends.
2. You need deletion at both ends.
3. You need random access.
4. You need a more flexible structure than queue.
5. You are implementing certain sliding-window algorithms.
6. You need a double-ended data structure.
```

---

# 44. Deque in Sliding Window Problems

Deque is very commonly used in DSA for:

```text
Sliding Window Maximum
Sliding Window Minimum
Monotonic Queue / Monotonic Deque
```

Example concept:

```text
window:
[1, 3, -1, -3]
```

A deque can help maintain useful candidates while elements enter from one side and leave from the other.

Typical operations:

```cpp
dq.push_back(index);
dq.pop_back();
dq.pop_front();
dq.front();
dq.back();
```

---

# 45. Important Safety Rules

Do not access `front()` or `back()` on an empty deque.

Wrong:

```cpp
deque<int> dq;

cout << dq.front();  // ❌
cout << dq.back();   // ❌
```

Safe:

```cpp
if (!dq.empty())
{
    cout << dq.front();
}
```

Similarly:

```cpp
if (!dq.empty())
{
    cout << dq.back();
}
```

---

# 46. Important Time Complexities

| Operation            | Typical Complexity |
| -------------------- | -----------------: |
| `push_back()`        |     O(1) amortized |
| `push_front()`       |     O(1) amortized |
| `pop_back()`         |               O(1) |
| `pop_front()`        |               O(1) |
| `front()`            |               O(1) |
| `back()`             |               O(1) |
| `operator[]`         |               O(1) |
| `at()`               |               O(1) |
| `size()`             |               O(1) |
| `empty()`            |               O(1) |
| `insert()` in middle |               O(n) |
| `erase()` in middle  |               O(n) |

---

# 47. Important Differences to Remember

## Vector

```text
Fast random access
↓
Good general-purpose dynamic array
↓
Efficient insertion/removal at back
```

## Deque

```text
Fast random access
↓
Efficient insertion/removal at BOTH ends
```

## List

```text
No random access
↓
Linked-list structure
↓
Efficient insertion/deletion when iterator is available
```

## Queue

```text
FIFO
↓
First In, First Out
↓
Restricted interface
```

---

# 48. Complete Deque Cheat Sheet

```cpp
#include <deque>
```

### Create

```cpp
deque<int> dq;
```

### Add at back

```cpp
dq.push_back(10);
```

### Add at front

```cpp
dq.push_front(10);
```

### Remove from back

```cpp
dq.pop_back();
```

### Remove from front

```cpp
dq.pop_front();
```

### First element

```cpp
dq.front();
```

### Last element

```cpp
dq.back();
```

### Size

```cpp
dq.size();
```

### Empty check

```cpp
dq.empty();
```

### Remove everything

```cpp
dq.clear();
```

### Random access

```cpp
dq[2];
```

### Bounds-checked access

```cpp
dq.at(2);
```

### First iterator

```cpp
dq.begin();
```

### End iterator

```cpp
dq.end();
```

### Reverse iterator

```cpp
dq.rbegin();
dq.rend();
```

### Insert

```cpp
dq.insert(dq.begin() + 1, 50);
```

### Erase

```cpp
dq.erase(dq.begin() + 1);
```

### Resize

```cpp
dq.resize(10);
```

### Swap

```cpp
dq1.swap(dq2);
```

or:

```cpp
swap(dq1, dq2);
```

---

# 49. Final Mental Model

```text
                    DEQUE
                      |
           +----------+----------+
           |                     |
       FRONT                    BACK
           |                     |
    push_front()            push_back()
    pop_front()             pop_back()
           |                     |
           +----------+----------+
                      |
                Random Access
                      |
                    dq[i]
```

The easiest way to remember deque is:

```text
DEQUE
↓
Double Ended Queue
↓
Front + Back dono par kaam
↓
push_front()
push_back()
pop_front()
pop_back()
↓
Random access bhi available
↓
dq[i]
```

### One-line comparison

```text
vector → random access + back operations
deque  → random access + front & back operations
list   → linked list + easy insertion/deletion
queue  → FIFO interface
stack  → LIFO interface
```
