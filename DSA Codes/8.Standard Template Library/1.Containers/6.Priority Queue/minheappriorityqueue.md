# C++ STL — Min Heap / Priority Queue Detailed Notes

## 1. What is a Min Heap?

A **Min Heap** is a special type of **Complete Binary Tree** in which the **smallest element is always present at the root**.

The basic rule is:

```text
parent <= children
```

For example:

```text
        10
       /  \
      20   30
     / \
    40  50
```

Here:

```text
10 <= 20
10 <= 30
20 <= 40
20 <= 50
```

Therefore, this is a valid Min Heap.

The most important property is:

```text
MINIMUM ELEMENT
       ↓
      ROOT
       ↓
    top()
```

In C++ STL, we can implement a Min Heap using:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

---

# 2. Min Heap in C++ STL

C++ STL provides:

```cpp
priority_queue
```

which is a **container adaptor**.

By default, `priority_queue` does not behave as a Min Heap.

To make it work like a Min Heap, we use:

```cpp
greater<int>
```

The syntax is:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

This means:

```text
int
 ↓
Data type

vector<int>
 ↓
Underlying container

greater<int>
 ↓
Comparison rule
```

The result:

```text
Smallest element → highest priority → top()
```

---

# 3. Header Files

For a Min Heap using `priority_queue`:

```cpp
#include <queue>
#include <vector>
#include <functional>
```

Usually, in competitive programming:

```cpp
#include <bits/stdc++.h>
```

is enough.

Example:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {

    priority_queue<int, vector<int>, greater<int>> pq;

    return 0;
}
```

---

# 4. Basic Min Heap Syntax

The most important syntax:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

Remember this:

```text
priority_queue
      ↓
     int
      ↓
   vector<int>
      ↓
  greater<int>
      ↓
    Min Heap
```

The meaning is:

> Store integers in a priority queue where the smallest integer gets the highest priority.

Therefore:

```cpp
pq.top();
```

will always give the smallest element.

---

# 5. Creating an Empty Min Heap

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

Initially:

```text
[]
```

There are no elements.

We can add elements using:

```cpp
pq.push(x);
```

---

# 6. `push()`

`push()` is used to insert an element into the Min Heap.

Example:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;

pq.push(10);
pq.push(30);
pq.push(5);
pq.push(20);
```

The elements are:

```text
10, 30, 5, 20
```

Since this is a Min Heap:

```text
smallest = 5
```

Therefore:

```cpp
cout << pq.top();
```

outputs:

```text
5
```

---

# 7. What Happens Internally During `push()`?

When a new element is inserted into a heap:

1. The element is initially added at the end.
2. It is compared with its parent.
3. If it is smaller than its parent, they are swapped.
4. This continues until the Min Heap property is restored.

This process is called:

```text
Heapify Up
```

or:

```text
Sift Up
```

or:

```text
Bubble Up
```

All three terms describe the same basic process.

---

# 8. Example of Heapify Up

Suppose we have:

```text
        10
       /  \
      20   30
```

Now insert:

```text
5
```

Initially:

```text
        10
       /  \
      20   30
     /
    5
```

But:

```text
5 < 20
```

So swap:

```text
        10
       /  \
      5    30
     /
    20
```

Now:

```text
5 < 10
```

So swap again:

```text
        5
       / \
      10  30
     /
    20
```

Now the Min Heap property is restored.

Therefore:

```text
5
```

is at the root.

---

# 9. `top()`

`top()` returns the element having the highest priority.

For a Min Heap:

```cpp
pq.top();
```

returns:

```text
smallest element
```

Example:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;

pq.push(50);
pq.push(10);
pq.push(30);
pq.push(20);

cout << pq.top();
```

Output:

```text
10
```

Important:

```cpp
top()
```

does **not remove** the element.

It only gives access to it.

---

# 10. `top()` is O(1)

Why?

Because the Min Heap guarantees:

```text
smallest element = root
```

And the root is stored at:

```text
index 0
```

Therefore, finding the minimum does not require searching the entire heap.

So:

```text
top() = O(1)
```

---

# 11. `pop()`

`pop()` removes the current top element.

For a Min Heap:

```cpp
pq.pop();
```

removes:

```text
smallest element
```

Example:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;

pq.push(10);
pq.push(30);
pq.push(20);
pq.push(5);
```

Current:

```text
top() = 5
```

Now:

```cpp
pq.pop();
```

removes:

```text
5
```

The next smallest element becomes:

```text
10
```

Therefore:

```cpp
cout << pq.top();
```

outputs:

```text
10
```

---

# 12. Important: `pop()` Does NOT Return the Value

This is a very common mistake.

Wrong:

```cpp
int x = pq.pop();
```

This is invalid because:

```cpp
pop()
```

returns nothing.

Correct:

```cpp
int x = pq.top();

pq.pop();
```

Think:

```text
top()
 ↓
Read the smallest element

pop()
 ↓
Remove the smallest element
```

So:

```cpp
int x = pq.top();
pq.pop();
```

is the correct pattern.

---

# 13. What Happens Internally During `pop()`?

When we remove the root:

1. The root is removed.
2. The last element is moved to the root.
3. The new root is compared with its children.
4. It is swapped with the smaller child if necessary.
5. This continues until the Min Heap property is restored.

This process is called:

```text
Heapify Down
```

or:

```text
Sift Down
```

---

# 14. Example of Heapify Down

Suppose:

```text
        5
       / \
      10  20
     / \
    30  40
```

The root `5` is removed.

The last element `40` moves to the root:

```text
        40
       /  \
      10   20
     /
    30
```

Now `40` violates the Min Heap property.

Its children are:

```text
10
20
```

The smaller child is:

```text
10
```

Swap:

```text
        10
       /  \
      40   20
     /
    30
```

Now `40` is compared with its child:

```text
30
```

Since:

```text
30 < 40
```

swap again:

```text
        10
       /  \
      30   20
     /
    40
```

Now the Min Heap property is restored.

---

# 15. `pop()` Complexity

A heap has height:

```text
O(log n)
```

During `pop()`, an element can move from the root toward the bottom.

Therefore:

```text
pop() = O(log n)
```

---

# 16. `push()` Complexity

During insertion, an element can move from the bottom toward the root.

The height of the heap is:

```text
O(log n)
```

Therefore:

```text
push() = O(log n)
```

---

# 17. `size()`

`size()` returns the number of elements currently present.

Example:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;

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

Complexity:

```text
size() = O(1)
```

---

# 18. `empty()`

`empty()` checks whether the Min Heap contains no elements.

Example:

```cpp
if (pq.empty()) {

    cout << "Min Heap is empty";

}
else {

    cout << "Min Heap is not empty";
}
```

Return values:

```text
true
 ↓
empty

false
 ↓
not empty
```

Complexity:

```text
empty() = O(1)
```

---

# 19. Complete Basic Min Heap Example

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {

    // ============================================================
    // CREATING A MIN HEAP
    // ============================================================

    // priority_queue normally gives priority according
    // to its comparator.
    //
    // greater<int> reverses the normal ordering so that
    // the smallest element gets the highest priority.
    //
    // Therefore, this behaves like a MIN HEAP.

    priority_queue<int, vector<int>, greater<int>> pq;


    // ============================================================
    // INSERTING ELEMENTS
    // ============================================================

    pq.push(50);
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(40);


    // ============================================================
    // TOP ELEMENT
    // ============================================================

    // Since this is a Min Heap,
    // the smallest element is always at the top.

    cout << "Minimum element: "
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

    // Removes the smallest element.

    pq.pop();


    // Now the next smallest element is 20.

    cout << "Minimum after pop: "
         << pq.top()
         << endl;


    // ============================================================
    // EMPTY CHECK
    // ============================================================

    if (pq.empty()) {

        cout << "Min Heap is empty" << endl;

    }
    else {

        cout << "Min Heap is not empty" << endl;
    }


    return 0;
}
```

Output:

```text
Minimum element: 10
Size: 5
Minimum after pop: 20
Min Heap is not empty
```

---

# 20. Processing All Elements

A very common pattern is:

```cpp
while (!pq.empty()) {

    cout << pq.top() << " ";

    pq.pop();
}
```

For a Min Heap, elements will be processed from:

```text
smallest → largest
```

Example:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;

pq.push(40);
pq.push(10);
pq.push(50);
pq.push(20);
pq.push(30);

while (!pq.empty()) {

    cout << pq.top() << " ";

    pq.pop();
}
```

Output:

```text
10 20 30 40 50
```

---

# 21. Important: This Does NOT Mean Heap is Sorted

Suppose the values are:

```text
10, 50, 20, 40, 30
```

The internal heap is **not necessarily stored as**:

```text
10 20 30 40 50
```

A Min Heap only guarantees:

```text
parent <= children
```

It does NOT guarantee:

```text
array is completely sorted
```

However, if we repeatedly do:

```cpp
top();
pop();
```

we get the elements in increasing order.

Why?

Because every time:

```text
top()
```

gives the current minimum.

---

# 22. Min Heap Tree Representation

Consider:

```cpp
pq.push(10);
pq.push(20);
pq.push(5);
pq.push(30);
pq.push(15);
```

Conceptually, the heap follows:

```text
        5
       / \
     15   10
    / \
   30  20
```

The exact internal arrangement can depend on insertion/heap operations, so don't rely on a particular shape.

What is guaranteed?

```text
Root = minimum
```

and for every parent:

```text
parent <= children
```

---

# 23. Complete Binary Tree

A heap is a **Complete Binary Tree**.

Complete Binary Tree means:

- Every level is completely filled except possibly the last.
- The last level is filled from left to right.

Example:

```text
        5
       / \
      10  20
     / \ /
    30 40 50
```

This structure allows the heap to be efficiently stored in an array/vector.

---

# 24. Heap Array Representation

Suppose:

```text
        5
       / \
      10  20
     / \ /
    30 40 50
```

Array representation:

```text
[5, 10, 20, 30, 40, 50]
```

For an index `i`:

```cpp
parent = (i - 1) / 2;

left child = 2 * i + 1;

right child = 2 * i + 2;
```

These formulas are important if you implement a Min Heap manually.

---

# 25. Parent and Child Index Example

Suppose:

```text
index:  0   1   2   3   4   5
value:  5  10  20  30  40  50
```

For index `1`:

```cpp
left = 2 * 1 + 1;
```

so:

```text
left = 3
```

and:

```cpp
right = 2 * 1 + 2;
```

so:

```text
right = 4
```

Therefore:

```text
       10
      /  \
     30  40
```

---

# 26. Why `greater<int>` Creates a Min Heap

This is one of the most important concepts.

The syntax:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

contains:

```cpp
greater<int>
```

as the comparison rule.

This changes the priority ordering so that:

```text
smaller value
     ↓
higher priority
     ↓
top()
```

Therefore:

```cpp
pq.top()
```

returns the minimum value.

Example:

```text
Elements:

50
10
30
20
40

       ↓

Min Heap

       ↓

top() = 10
```

---

# 27. Understanding the Three Template Parameters

General syntax:

```cpp
priority_queue<
    T,
    Container,
    Compare
> pq;
```

For Min Heap:

```cpp
priority_queue<
    int,
    vector<int>,
    greater<int>
> pq;
```

### First parameter

```cpp
int
```

Means:

```text
Data type = int
```

### Second parameter

```cpp
vector<int>
```

Means:

```text
Underlying container = vector<int>
```

### Third parameter

```cpp
greater<int>
```

Means:

```text
Comparison rule
```

Together:

```text
int + vector<int> + greater<int>
                ↓
             Min Heap
```

---

# 28. `greater<>` Modern Syntax

In modern C++, you can also write:

```cpp
priority_queue<int, vector<int>, greater<>> pq;
```

instead of:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

Both are commonly used.

For beginner/interview notes, this is perfectly fine to remember:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

---

# 29. Min Heap of `pair`

A Min Heap can also store pairs.

Syntax:

```cpp
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;
```

Example:

```cpp
pq.push({5, 100});
pq.push({2, 200});
pq.push({3, 50});
```

The smallest pair gets the highest priority.

Therefore:

```cpp
pq.top();
```

returns:

```text
{2, 200}
```

---

# 30. Pair Comparison

Pairs are compared lexicographically.

That means:

```text
First compare first
        ↓
If first is equal
        ↓
Compare second
```

Example:

```text
(2, 100)
(2, 50)
(3, 10)
```

The smallest pair is:

```text
(2, 50)
```

because:

```text
2 = 2
```

so we compare the second values:

```text
50 < 100
```

---

# 31. Min Heap of Pairs Example

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {

    // Min Heap of pairs.
    //
    // The pair with the smallest first value
    // gets the highest priority.
    //
    // If first values are equal,
    // second values are compared.

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;


    pq.push({5, 100});
    pq.push({2, 200});
    pq.push({3, 50});
    pq.push({2, 100});


    auto top = pq.top();

    cout << top.first << " "
         << top.second
         << endl;


    return 0;
}
```

Output:

```text
2 100
```

Because:

```text
(2, 100)
```

is smaller than:

```text
(2, 200)
```

and:

```text
(3, 50)
```

---

# 32. Why Min Heap of Pair is Important

This pattern is extremely common in DSA:

```cpp
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;
```

It is commonly used when we want:

```text
{priority, value}
```

For example:

```text
{distance, node}
```

in graph algorithms.

---

# 33. Min Heap in Dijkstra

Dijkstra's Algorithm needs the node having the smallest current distance.

Therefore we use a Min Heap.

Typical syntax:

```cpp
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;
```

We can store:

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

Because this is a Min Heap:

```text
smallest distance
        ↓
      top()
```

So the node with the smallest distance gets processed first.

---

# 34. Min Heap with Custom Comparator

Sometimes `greater<int>` is not enough.

For example, suppose we have:

```cpp
struct Student {

    string name;
    int marks;
};
```

And we want the student with the **smallest marks** at the top.

We can create a custom comparator:

```cpp
struct Compare {

    bool operator()(const Student& a,
                    const Student& b) {

        return a.marks > b.marks;
    }
};
```

Then:

```cpp
priority_queue<
    Student,
    vector<Student>,
    Compare
> pq;
```

Now the student with the smallest marks has the highest priority.

---

# 35. Custom Comparator Example

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Student {

    string name;
    int marks;
};


struct Compare {

    bool operator()(const Student& a,
                    const Student& b) {

        // Smaller marks should come first.
        return a.marks > b.marks;
    }
};


int main() {

    priority_queue<
        Student,
        vector<Student>,
        Compare
    > pq;


    pq.push({"Rahul", 80});
    pq.push({"Aman", 60});
    pq.push({"Priya", 90});


    // Student with smallest marks is on top.

    cout << pq.top().name << " "
         << pq.top().marks
         << endl;


    return 0;
}
```

Output:

```text
Aman 60
```

---

# 36. Min Heap for K-th Largest Element

A Min Heap is useful for maintaining the **K largest elements**.

Suppose:

```text
Find the K-th largest element.
```

We can maintain a Min Heap of size `k`.

```cpp
priority_queue<int, vector<int>, greater<int>> pq;

for (int x : nums) {

    pq.push(x);

    if (pq.size() > k) {

        pq.pop();
    }
}
```

At the end:

```cpp
pq.top()
```

contains the:

```text
K-th largest element
```

Why?

Because we keep only the `k` largest elements.

Among those `k` elements, the smallest one is the K-th largest.

---

# 37. Complexity of K-th Largest Using Min Heap

For every element:

```text
push → O(log k)
```

because the heap size never exceeds `k`.

For `n` elements:

```text
O(n log k)
```

This is often better than sorting:

```text
O(n log n)
```

when:

```text
k << n
```

---

# 38. Min Heap for Smallest Elements

A Min Heap naturally gives:

```text
minimum
```

through:

```cpp
pq.top();
```

So it is useful when a problem repeatedly asks:

```text
Give me the smallest element.
Remove the smallest element.
Give me the next smallest element.
```

This is exactly the kind of problem where a Min Heap is useful.

---

# 39. Common Min Heap Pattern

Whenever the problem says:

> "Repeatedly find/remove the minimum."

Think:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

Then:

```cpp
while (!pq.empty()) {

    int smallest = pq.top();

    pq.pop();

    // Process smallest
}
```

This pattern is extremely important.

---

# 40. `top()` + `pop()` Pattern

Always remember:

```cpp
int x = pq.top();
pq.pop();
```

Meaning:

```text
Step 1:
Read minimum

Step 2:
Remove minimum
```

Or directly:

```cpp
while (!pq.empty()) {

    cout << pq.top() << " ";

    pq.pop();
}
```

For a Min Heap, this prints:

```text
ascending order
```

---

# 41. Never Call `top()` on Empty Heap

Wrong:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;

cout << pq.top();
```

because there is no element.

Correct:

```cpp
if (!pq.empty()) {

    cout << pq.top();
}
```

Similarly, don't call:

```cpp
pq.pop();
```

when the heap is empty.

Safe pattern:

```cpp
while (!pq.empty()) {

    int x = pq.top();

    pq.pop();

    // Process x
}
```

---

# 42. `priority_queue` Does Not Provide Iterators

You cannot normally do:

```cpp
pq.begin();
pq.end();
```

The standard `priority_queue` interface does not provide public iterators.

Instead, process elements using:

```cpp
while (!pq.empty()) {

    cout << pq.top();

    pq.pop();
}
```

Remember:

```text
top() + pop()
```

is the normal way to process a priority queue.

---

# 43. Important: Processing Destroys the Heap

If you do:

```cpp
while (!pq.empty()) {

    cout << pq.top();

    pq.pop();
}
```

then all elements are removed.

If you want to preserve the original heap, make a copy:

```cpp
auto temp = pq;

while (!temp.empty()) {

    cout << temp.top() << " ";

    temp.pop();
}
```

Now:

```text
temp
 ↓
destroyed

pq
 ↓
still unchanged
```

---

# 44. Duplicate Elements are Allowed

Min Heap allows duplicate values.

Example:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;

pq.push(10);
pq.push(10);
pq.push(5);
pq.push(5);
```

The elements can be processed as:

```text
5 5 10 10
```

There is no uniqueness restriction.

---

# 45. Min Heap vs Set

A Min Heap and a `set` are not the same.

### Min Heap

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

allows duplicates:

```text
5
5
10
10
```

### Set

```cpp
set<int> s;
```

stores unique values.

So if duplicates matter:

```text
Min Heap → duplicates allowed
Set      → unique values
```

---

# 46. Min Heap vs Sorted Array

Suppose we have:

```text
10 5 20 2 15
```

A sorted array would be:

```text
2 5 10 15 20
```

But a Min Heap does not need to keep the entire structure sorted.

It only guarantees:

```text
minimum = root
```

and:

```text
parent <= children
```

This is why Heap operations can be efficient.

---

# 47. Min Heap Time Complexity

For a binary Min Heap:

| Operation | Time Complexity |
| --------- | --------------: |
| `top()`   |            O(1) |
| `push()`  |        O(log n) |
| `pop()`   |        O(log n) |
| `size()`  |            O(1) |
| `empty()` |            O(1) |

Space:

```text
O(n)
```

because the heap stores `n` elements.

---

# 48. Why is `push()` O(log n)?

When inserting an element:

```text
Insert at bottom
       ↓
Compare with parent
       ↓
Swap if smaller
       ↓
Move upward
```

The element can travel at most the height of the heap.

For `n` elements:

```text
height = O(log n)
```

Therefore:

```text
push() = O(log n)
```

---

# 49. Why is `pop()` O(log n)?

When removing the minimum:

```text
Remove root
    ↓
Move last element to root
    ↓
Compare with children
    ↓
Swap with smaller child
    ↓
Move downward
```

Again, the element can travel at most the height of the heap:

```text
O(log n)
```

Therefore:

```text
pop() = O(log n)
```

---

# 50. Why is `top()` O(1)?

Because:

```text
Min Heap
   ↓
Minimum is always root
   ↓
Root is at index 0
   ↓
Direct access
```

Therefore:

```text
top() = O(1)
```

---

# 51. Build Min Heap

If we insert `n` elements one by one:

```text
O(n log n)
```

But a heap can also be built using bottom-up heapification.

That takes:

```text
O(n)
```

This is an important interview fact.

---

# 52. Min Heap From Scratch

Understanding the STL is good, but knowing how a Min Heap works internally is even more important.

Basic class:

```cpp
class MinHeap {

private:

    vector<int> heap;

public:

    void push(int value) {

        heap.push_back(value);

        int i = heap.size() - 1;

        // Heapify Up
        while (i > 0) {

            int parent = (i - 1) / 2;

            if (heap[parent] <= heap[i]) {

                break;
            }

            swap(heap[parent], heap[i]);

            i = parent;
        }
    }
};
```

---

# 53. Manual `top()`

Since the minimum is always at the root:

```cpp
int top() {

    if (heap.empty()) {

        throw runtime_error("Heap is empty");
    }

    return heap[0];
}
```

The important point:

```text
heap[0]
   ↓
root
   ↓
minimum
```

---

# 54. Manual `pop()`

```cpp
void pop() {

    if (heap.empty()) {

        return;
    }

    // Move last element to root.
    heap[0] = heap.back();

    // Remove last element.
    heap.pop_back();

    int i = 0;

    // Heapify Down.
    while (true) {

        int left = 2 * i + 1;

        int right = 2 * i + 2;

        int smallest = i;


        // Check left child.
        if (left < heap.size() &&
            heap[left] < heap[smallest]) {

            smallest = left;
        }


        // Check right child.
        if (right < heap.size() &&
            heap[right] < heap[smallest]) {

            smallest = right;
        }


        // Heap property is already satisfied.
        if (smallest == i) {

            break;
        }


        // Swap with smaller child.
        swap(heap[i], heap[smallest]);

        i = smallest;
    }
}
```

---

# 55. Complete Min Heap From Scratch

```cpp
#include <bits/stdc++.h>

using namespace std;

class MinHeap {

private:

    vector<int> heap;


public:

    // ============================================================
    // PUSH
    // ============================================================

    void push(int value) {

        // Add new value at the end.
        heap.push_back(value);

        // Start from the newly inserted element.
        int i = heap.size() - 1;


        // --------------------------------------------------------
        // HEAPIFY UP
        // --------------------------------------------------------

        while (i > 0) {

            int parent = (i - 1) / 2;


            // If parent is already smaller,
            // Min Heap property is satisfied.
            if (heap[parent] <= heap[i]) {

                break;
            }


            // Otherwise swap.
            swap(heap[parent], heap[i]);


            // Move upward.
            i = parent;
        }
    }


    // ============================================================
    // TOP
    // ============================================================

    int top() {

        if (heap.empty()) {

            throw runtime_error("Heap is empty");
        }

        // Root contains minimum.
        return heap[0];
    }


    // ============================================================
    // POP
    // ============================================================

    void pop() {

        if (heap.empty()) {

            return;
        }


        // Move last element to root.
        heap[0] = heap.back();


        // Remove last element.
        heap.pop_back();


        int i = 0;


        // --------------------------------------------------------
        // HEAPIFY DOWN
        // --------------------------------------------------------

        while (true) {

            int left = 2 * i + 1;

            int right = 2 * i + 2;


            int smallest = i;


            // Check left child.
            if (left < heap.size() &&
                heap[left] < heap[smallest]) {

                smallest = left;
            }


            // Check right child.
            if (right < heap.size() &&
                heap[right] < heap[smallest]) {

                smallest = right;
            }


            // If current node is already the smallest,
            // the Min Heap property is restored.
            if (smallest == i) {

                break;
            }


            // Swap current node with smaller child.
            swap(heap[i], heap[smallest]);


            // Continue downward.
            i = smallest;
        }
    }


    // ============================================================
    // EMPTY
    // ============================================================

    bool empty() {

        return heap.empty();
    }


    // ============================================================
    // SIZE
    // ============================================================

    int size() {

        return heap.size();
    }
};
```

---

# 56. Heapify Up vs Heapify Down

This is extremely important.

### During `push()`

```text
New element
     ↓
Added at bottom
     ↓
May need to move UP
```

Therefore:

```text
push()
  ↓
Heapify Up
```

### During `pop()`

```text
Root removed
     ↓
Last element comes to root
     ↓
May need to move DOWN
```

Therefore:

```text
pop()
  ↓
Heapify Down
```

Memory trick:

```text
PUSH → UP

POP → DOWN
```

---

# 57. Min Heap Applications

Min Heap is useful in many DSA problems.

Common applications:

```text
1. Dijkstra's Algorithm

2. Prim's Algorithm

3. K-th largest element

4. Top K problems

5. Merge K sorted arrays

6. Merge K sorted linked lists

7. Scheduling

8. Event simulation

9. Greedy algorithms

10. Best-first search
```

The common idea is:

```text
We repeatedly need the smallest / highest-priority element.
```

---

# 58. Merge K Sorted Arrays

Suppose we have multiple sorted arrays.

We want to repeatedly select the smallest current element.

A Min Heap is ideal:

```text
Min Heap
   ↓
smallest current element
   ↓
process it
   ↓
insert next element
```

This is a very common heap pattern.

---

# 59. Scheduling Problems

Suppose tasks have different priorities or finishing times.

A Min Heap can maintain:

```text
smallest time
```

or:

```text
earliest deadline
```

or:

```text
lowest cost
```

depending on the problem.

The general pattern is:

```cpp
priority_queue<
    ...
    greater<...>
> pq;
```

Then:

```cpp
pq.top();
```

gives the current minimum-priority item.

---

# 60. Min Heap Mental Model

Whenever you see:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

immediately think:

```text
             MIN HEAP
                 |
                 ↓
       Smallest element
                 |
                 ↓
               top()
                 |
                 ↓
            pop() removes it
```

The entire purpose is:

```text
Smallest element
       ↓
   Easily available
       ↓
      O(1) top
```

---

# 61. Most Important Syntax

### Create Min Heap

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

### Insert

```cpp
pq.push(x);
```

### Get minimum

```cpp
pq.top();
```

### Remove minimum

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

---

# 62. Most Important Complexity

```text
top()   → O(1)

push()  → O(log n)

pop()   → O(log n)

size()  → O(1)

empty() → O(1)
```

Space:

```text
O(n)
```

---

# 63. Common Mistakes

## Mistake 1: Forgetting `greater<int>`

Wrong for Min Heap:

```cpp
priority_queue<int> pq;
```

Use:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

---

## Mistake 2: Thinking `pop()` returns the value

Wrong:

```cpp
int x = pq.pop();
```

Correct:

```cpp
int x = pq.top();

pq.pop();
```

---

## Mistake 3: Calling `top()` on an empty heap

Wrong:

```cpp
cout << pq.top();
```

without checking whether the heap is empty.

Correct:

```cpp
if (!pq.empty()) {

    cout << pq.top();
}
```

---

## Mistake 4: Thinking Min Heap is completely sorted

Wrong assumption:

```text
Heap = Sorted Array
```

Correct:

```text
Heap only guarantees:

parent <= children
```

---

## Mistake 5: Thinking `top()` removes the element

It doesn't.

```cpp
pq.top();
```

only reads.

```cpp
pq.pop();
```

removes.

---

# 64. Quick Revision

```text
MIN HEAP
   ↓
Smallest element at root
   ↓
Smallest element at top()
```

C++ STL:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

Operations:

```cpp
pq.push(x);   // Insert
pq.top();     // Minimum
pq.pop();     // Remove minimum
pq.size();    // Number of elements
pq.empty();   // Check empty
```

Complexities:

```text
push()  → O(log n)

pop()   → O(log n)

top()   → O(1)

size()  → O(1)

empty() → O(1)
```

---

# 65. One-Line Memory Trick

```text
Min Heap
   ↓
Minimum element
   ↓
top()
```

and:

```text
push()
   ↓
Heapify Up
```

```text
pop()
   ↓
Heapify Down
```

The most important STL declaration:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

means:

```text
"Create a priority queue where the smallest element
has the highest priority."
```

---

# 66. Final Min Heap Cheat Sheet

```cpp
#include <queue>
#include <vector>
#include <functional>

using namespace std;


// ============================================================
// MIN HEAP
// ============================================================

priority_queue<
    int,
    vector<int>,
    greater<int>
> pq;


// ============================================================
// INSERT
// ============================================================

pq.push(10);
pq.push(5);
pq.push(20);


// ============================================================
// MINIMUM
// ============================================================

cout << pq.top();


// ============================================================
// REMOVE MINIMUM
// ============================================================

pq.pop();


// ============================================================
// SIZE
// ============================================================

cout << pq.size();


// ============================================================
// EMPTY CHECK
// ============================================================

if (pq.empty()) {

    cout << "Empty";
}


// ============================================================
// PROCESS ALL ELEMENTS
// ============================================================

while (!pq.empty()) {

    int smallest = pq.top();

    pq.pop();

    cout << smallest << " ";
}
```

Output:

```text
5 10 20
```

---

# 67. Final Mental Picture

```text
                    MIN HEAP
                       |
                       ↓
             Smallest element
                       |
                       ↓
                     ROOT
                       |
                       ↓
                    top()
                       |
                       ↓
              Remove minimum
                       |
                       ↓
                     pop()
```

Internally:

```text
                 Parent
                   |
                   ↓
          Parent <= Children
                   |
                   ↓
              Min Heap
```

Insertion:

```text
push()
  ↓
Add at bottom
  ↓
Heapify Up
  ↓
Min Heap restored
```

Deletion:

```text
pop()
  ↓
Remove root
  ↓
Move last element to root
  ↓
Heapify Down
  ↓
Min Heap restored
```

---

# 68. Final Interview Answer

If an interviewer asks:

> "How do you create a Min Heap using C++ STL?"

Answer:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

Then explain:

> `priority_queue` is a container adaptor. By using `greater<int>` as the comparator, the smallest element gets the highest priority, so `top()` returns the minimum element.

Complexities:

```text
top()  → O(1)

push() → O(log n)

pop()  → O(log n)
```

And the core Min Heap property is:

```text
parent <= children
```

So the **minimum element is always at the root/top**.

---

# 69. Final 10-Second Revision

```text
MIN HEAP
↓
Smallest element first
↓
priority_queue<int, vector<int>, greater<int>>
↓
top() = minimum
↓
push() = O(log n)
↓
pop() = O(log n)
↓
top() = O(1)
↓
push → Heapify Up
↓
pop → Heapify Down
↓
parent <= children
```

**बस यही Min Heap का core hai.**
