# C++ STL — List Notes

## 1. What is `list`?

`list` is a **sequence container** provided by the C++ Standard Template Library (STL).

It is implemented as a **doubly linked list**.

Header file:

```cpp
#include <list>
```

Basic declaration:

```cpp
list<int> l;
```

A list stores elements in separate nodes connected with links.

Conceptually:

```text
10 <-> 20 <-> 30 <-> 40
```

Each node is connected to both:

- previous node
- next node

---

# 2. Why is `list` different from `vector`?

A `vector` stores elements in **contiguous memory**.

A `list` stores elements as **separate linked nodes**.

### Vector

```text
[10][20][30][40]
```

Elements are stored next to each other in memory.

### List

```text
[10] <-> [20] <-> [30] <-> [40]
```

Nodes can be located at different memory addresses.

---

# 3. Creating a List

## Empty List

```cpp
list<int> l;
```

Creates an empty list.

```text
[]
```

---

## List with Values

```cpp
list<int> l = {10, 20, 30, 40};
```

List:

```text
10 <-> 20 <-> 30 <-> 40
```

---

## List with Same Value

```cpp
list<int> l(5, 10);
```

Creates:

```text
10 <-> 10 <-> 10 <-> 10 <-> 10
```

Here:

```text
size = 5
```

---

## List with Given Size

```cpp
list<int> l(5);
```

Creates 5 integer elements initialized to `0`.

```text
0 <-> 0 <-> 0 <-> 0 <-> 0
```

---

# 4. `push_back()`

`push_back()` adds an element at the **end** of the list.

```cpp
list<int> l;

l.push_back(10);
l.push_back(20);
l.push_back(30);
```

List becomes:

```text
10 <-> 20 <-> 30
```

Time complexity:

```text
O(1)
```

---

# 5. `push_front()`

`push_front()` adds an element at the **beginning** of the list.

```cpp
list<int> l = {20, 30};

l.push_front(10);
```

Now:

```text
10 <-> 20 <-> 30
```

Time complexity:

```text
O(1)
```

This is one of the important differences between `list` and `vector`.

---

# 6. `pop_back()`

`pop_back()` removes the last element.

```cpp
list<int> l = {10, 20, 30};

l.pop_back();
```

Now:

```text
10 <-> 20
```

Time complexity:

```text
O(1)
```

Important:

`pop_back()` does not return the removed element.

---

# 7. `pop_front()`

`pop_front()` removes the first element.

```cpp
list<int> l = {10, 20, 30};

l.pop_front();
```

Now:

```text
20 <-> 30
```

Time complexity:

```text
O(1)
```

---

# 8. `front()`

`front()` returns the first element.

```cpp
list<int> l = {10, 20, 30};

cout << l.front();
```

Output:

```text
10
```

---

# 9. `back()`

`back()` returns the last element.

```cpp
cout << l.back();
```

Output:

```text
30
```

---

# 10. `size()`

`size()` returns the number of elements currently present.

```cpp
list<int> l = {10, 20, 30, 40};

cout << l.size();
```

Output:

```text
4
```

---

# 11. `empty()`

`empty()` checks whether the list contains any elements.

```cpp
list<int> l;

if (l.empty())
{
    cout << "List is empty";
}
```

Return values:

```text
true  -> list is empty
false -> list is not empty
```

---

# 12. `clear()`

`clear()` removes all elements.

```cpp
list<int> l = {10, 20, 30};

l.clear();
```

Now:

```text
[]
```

And:

```cpp
cout << l.size();
```

Output:

```text
0
```

---

# 13. Iterators

A list supports iterators.

Basic syntax:

```cpp
list<int>::iterator it;
```

Example:

```cpp
list<int> l = {10, 20, 30, 40};

list<int>::iterator it = l.begin();

while (it != l.end())
{
    cout << *it << " ";
    it++;
}
```

Output:

```text
10 20 30 40
```

---

# 14. `begin()` and `end()`

`begin()` points to the first element.

```cpp
l.begin();
```

`end()` points just after the last element.

Conceptually:

```text
10 <-> 20 <-> 30 <-> 40
 ^                         ^
 |                         |
begin()                   end()
```

Important:

Do not dereference `end()`.

Wrong:

```cpp
cout << *l.end();
```

Correct traversal:

```cpp
for (auto it = l.begin(); it != l.end(); ++it)
{
    cout << *it << " ";
}
```

---

# 15. Reverse Iterators

A list also supports:

```cpp
rbegin()
rend()
```

Example:

```cpp
list<int> l = {10, 20, 30, 40};

for (auto it = l.rbegin(); it != l.rend(); ++it)
{
    cout << *it << " ";
}
```

Output:

```text
40 30 20 10
```

---

# 16. Range-Based For Loop

We can directly traverse a list using a range-based loop.

```cpp
list<int> l = {10, 20, 30, 40};

for (int x : l)
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
for (auto x : l)
{
    cout << x << " ";
}
```

Using const reference:

```cpp
for (const auto& x : l)
{
    cout << x << " ";
}
```

---

# 17. `insert()`

`insert()` adds an element at a specified position.

Example:

```cpp
list<int> l = {10, 20, 30};

auto it = l.begin();

advance(it, 1);

l.insert(it, 15);
```

List becomes:

```text
10 <-> 15 <-> 20 <-> 30
```

Important:

A `list` iterator is **not random-access**.

So this is invalid:

```cpp
l.begin() + 1
```

Unlike a vector, list iterators do not support jumping with `+`.

Instead, use:

```cpp
advance(it, 1);
```

---

# 18. `erase()`

`erase()` removes an element using an iterator.

Example:

```cpp
list<int> l = {10, 20, 30};

auto it = l.begin();

advance(it, 1);

l.erase(it);
```

Now:

```text
10 <-> 30
```

Time complexity:

```text
O(1)
```

when you already have the iterator to the element.

---

# 19. Erasing a Range

Example:

```cpp
list<int> l = {10, 20, 30, 40, 50};

auto first = l.begin();
advance(first, 1);

auto last = l.begin();
advance(last, 4);

l.erase(first, last);
```

Range is:

```text
[start, end)
```

So:

```text
20, 30, 40
```

are removed.

Result:

```text
10 <-> 50
```

---

# 20. `remove()`

`remove(value)` removes all elements equal to the specified value.

Example:

```cpp
list<int> l = {10, 20, 20, 30, 20};

l.remove(20);
```

Result:

```text
10 <-> 30
```

All `20`s are removed.

---

# 21. `remove_if()`

`remove_if()` removes elements that satisfy a condition.

Example:

```cpp
list<int> l = {1, 2, 3, 4, 5, 6};

l.remove_if([](int x)
{
    return x % 2 == 0;
});
```

Even numbers are removed.

Result:

```text
1 <-> 3 <-> 5
```

---

# 22. `sort()`

A `list` has its own `sort()` member function.

```cpp
list<int> l = {40, 10, 30, 20};

l.sort();
```

Result:

```text
10 <-> 20 <-> 30 <-> 40
```

Important:

For a normal list, do not use:

```cpp
sort(l.begin(), l.end());
```

because `std::sort()` requires random-access iterators, and `list` does not provide them.

Use:

```cpp
l.sort();
```

---

# 23. Descending Sort

```cpp
list<int> l = {10, 40, 20, 30};

l.sort(greater<int>());
```

Result:

```text
40 <-> 30 <-> 20 <-> 10
```

---

# 24. `reverse()`

`reverse()` reverses the order of the elements.

```cpp
list<int> l = {10, 20, 30, 40};

l.reverse();
```

Result:

```text
40 <-> 30 <-> 20 <-> 10
```

---

# 25. `unique()`

`unique()` removes **consecutive duplicate elements**.

Example:

```cpp
list<int> l = {1, 1, 2, 2, 2, 3, 3};

l.unique();
```

Result:

```text
1 <-> 2 <-> 3
```

Important:

`unique()` only removes consecutive duplicates.

Example:

```cpp
list<int> l = {1, 2, 1, 2};

l.unique();
```

No elements are removed because duplicates are not adjacent.

---

# 26. `merge()`

`merge()` combines two sorted lists.

Example:

```cpp
list<int> l1 = {1, 3, 5};
list<int> l2 = {2, 4, 6};

l1.merge(l2);
```

Now:

```text
l1 = 1 2 3 4 5 6
```

And:

```text
l2
```

becomes empty.

Important:

Both lists should be sorted appropriately before merging.

---

# 27. `splice()`

`splice()` transfers elements from one list into another.

This is one of the most powerful operations of `list`.

Example:

```cpp
list<int> l1 = {1, 2, 5};
list<int> l2 = {3, 4};

auto it = l1.begin();
advance(it, 2);

l1.splice(it, l2);
```

Result:

```text
l1 = 1 2 3 4 5
l2 = empty
```

The elements are transferred from `l2` to `l1`.

---

# 28. No Random Access

This is a VERY important difference from vector.

With vector:

```cpp
vector<int> v = {10, 20, 30, 40};

cout << v[2];
```

Works.

With list:

```cpp
list<int> l = {10, 20, 30, 40};

// l[2];   // ERROR
```

A `list` does not support:

```cpp
l[i]
```

or:

```cpp
l.at(i)
```

because it is a linked list, not a random-access container.

---

# 29. How to Reach an Element in List?

Use an iterator and `advance()`.

Example:

```cpp
list<int> l = {10, 20, 30, 40};

auto it = l.begin();

advance(it, 2);

cout << *it;
```

Output:

```text
30
```

Explanation:

```text
begin()
  ↓
10 -> 20 -> 30 -> 40
             ^
             |
          after 2 steps
```

Time complexity of advancing a list iterator by `n` positions:

```text
O(n)
```

---

# 30. List vs Vector

| Feature              | Vector         | List                 |
| -------------------- | -------------- | -------------------- |
| Data structure       | Dynamic array  | Doubly linked list   |
| Memory               | Contiguous     | Non-contiguous nodes |
| Random access        | Yes            | No                   |
| `v[i]`               | Yes            | No                   |
| `at()`               | Yes            | No                   |
| `push_back()`        | O(1) amortized | O(1)                 |
| `push_front()`       | O(n)           | O(1)                 |
| `pop_back()`         | O(1)           | O(1)                 |
| `pop_front()`        | O(n)           | O(1)                 |
| Insert with iterator | O(n) generally | O(1)                 |
| Erase with iterator  | O(n) generally | O(1)                 |
| Cache locality       | Good           | Poorer               |
| Memory overhead      | Lower          | Higher               |

---

# 31. Why List Is Good for Insertion/Deletion

Suppose we have:

```text
10 <-> 20 <-> 30 <-> 40
```

We want to insert `25` before `30`.

The list can change links:

```text
10 <-> 20 <-> 25 <-> 30 <-> 40
```

No shifting of all later elements is required.

That is why insertion/deletion can be efficient when you already have the correct iterator.

---

# 32. Why Vector Is Better for Random Access

Vector stores elements continuously:

```text
[10][20][30][40][50]
```

So if you ask for:

```cpp
v[3]
```

the address can be calculated directly.

Therefore:

```text
Random access = O(1)
```

List does not have this property.

To reach the fourth element:

```text
10 -> 20 -> 30 -> 40
```

you have to follow links.

So access by position is:

```text
O(n)
```

---

# 33. Iterator Types

A list iterator supports movement like:

```cpp
++it
--it
```

But not:

```cpp
it + 2
```

and not:

```cpp
it - 2
```

Example:

```cpp
auto it = l.begin();

++it;
--it;
```

Valid.

But:

```cpp
// it + 2;   // INVALID
```

To move multiple positions:

```cpp
advance(it, 2);
```

---

# 34. Complete Example

```cpp
#include <iostream>
#include <list>
using namespace std;

int main()
{
    // Creating a list
    list<int> l = {30, 10, 40, 20};

    // Print original list
    cout << "Original list: ";

    for (const auto& x : l)
    {
        cout << x << " ";
    }

    cout << endl;


    // Add element at front
    l.push_front(5);

    // Add element at back
    l.push_back(50);

    cout << "After push operations: ";

    for (const auto& x : l)
    {
        cout << x << " ";
    }

    cout << endl;


    // Sort list
    l.sort();

    cout << "After sort: ";

    for (const auto& x : l)
    {
        cout << x << " ";
    }

    cout << endl;


    // Reverse list
    l.reverse();

    cout << "After reverse: ";

    for (const auto& x : l)
    {
        cout << x << " ";
    }

    cout << endl;


    // Remove a value
    l.remove(30);

    cout << "After remove(30): ";

    for (const auto& x : l)
    {
        cout << x << " ";
    }

    cout << endl;


    // Print size
    cout << "Size: " << l.size() << endl;

    // First element
    cout << "Front: " << l.front() << endl;

    // Last element
    cout << "Back: " << l.back() << endl;


    return 0;
}
```

---

# 35. Important List Functions

Remember these:

```cpp
push_back()
push_front()

pop_back()
pop_front()

front()
back()

size()
empty()
clear()

begin()
end()

rbegin()
rend()

insert()
erase()

remove()
remove_if()

sort()
reverse()
unique()

merge()
splice()
```

---

# 36. List Iterator Example

```cpp
#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l = {10, 20, 30, 40};

    // Iterator points to the first element.
    list<int>::iterator it = l.begin();

    // Traverse until end().
    while (it != l.end())
    {
        cout << *it << endl;

        // Move to the next node.
        ++it;
    }

    return 0;
}
```

Output:

```text
10
20
30
40
```

---

# 37. Reverse Iterator Example

```cpp
#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l = {10, 20, 30, 40};

    // rbegin() points to the LAST element.
    // rend() represents the position before the first element.

    auto it = l.rbegin();

    while (it != l.rend())
    {
        cout << *it << endl;

        ++it;
    }

    return 0;
}
```

Output:

```text
40
30
20
10
```

---

# 38. Insert with Iterator — Detailed Example

```cpp
#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l = {10, 20, 30};

    // Start from first element.
    auto it = l.begin();

    // Move iterator one position forward.
    //
    // Before:
    //
    // 10 <-> 20 <-> 30
    // ^
    // it
    //
    // After advance(it, 1):
    //
    // 10 <-> 20 <-> 30
    //        ^
    //        it

    advance(it, 1);

    // Insert 15 BEFORE the position where it points.
    l.insert(it, 15);

    // Result:
    //
    // 10 <-> 15 <-> 20 <-> 30

    for (int x : l)
    {
        cout << x << " ";
    }

    return 0;
}
```

Output:

```text
10 15 20 30
```

---

# 39. Erase with Iterator — Detailed Example

```cpp
#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l = {10, 20, 30, 40};

    // Get iterator to beginning.
    auto it = l.begin();

    // Move to element 30.
    //
    // begin() -> 10
    // ++it    -> 20
    // ++it    -> 30

    advance(it, 2);

    // Erase the element pointed to by it.
    //
    // 30 will be removed.

    l.erase(it);

    // Result:
    //
    // 10 <-> 20 <-> 40

    for (int x : l)
    {
        cout << x << " ";
    }

    return 0;
}
```

Output:

```text
10 20 40
```

---

# 40. Important Rules to Remember

```text
list = doubly linked list
```

```text
Random access      -> No
v[i]               -> No
at(i)              -> No
push_front()       -> O(1)
push_back()        -> O(1)
pop_front()        -> O(1)
pop_back()         -> O(1)
```

When you already have an iterator:

```text
insert() -> O(1)
erase()  -> O(1)
```

For moving an iterator:

```text
++it / --it -> one step
advance(it, n) -> move n steps
```

---

# 41. Quick Revision Cheat Sheet

```cpp
#include <list>

list<int> l;
```

### Add at end

```cpp
l.push_back(10);
```

### Add at beginning

```cpp
l.push_front(10);
```

### Remove from end

```cpp
l.pop_back();
```

### Remove from beginning

```cpp
l.pop_front();
```

### First element

```cpp
l.front();
```

### Last element

```cpp
l.back();
```

### Number of elements

```cpp
l.size();
```

### Check empty

```cpp
l.empty();
```

### Remove everything

```cpp
l.clear();
```

### First iterator

```cpp
l.begin();
```

### End iterator

```cpp
l.end();
```

### Insert

```cpp
l.insert(it, value);
```

### Erase

```cpp
l.erase(it);
```

### Remove value

```cpp
l.remove(value);
```

### Sort

```cpp
l.sort();
```

### Reverse

```cpp
l.reverse();
```

### Remove consecutive duplicates

```cpp
l.unique();
```

### Merge sorted lists

```cpp
l1.merge(l2);
```

### Transfer nodes

```cpp
l1.splice(it, l2);
```

---

# 42. Vector vs List — Interview Summary

### Vector

Use vector when you need:

```text
Fast random access
v[i]
Good cache locality
Usually lower memory overhead
```

### List

Use list when you need:

```text
Frequent insertion/deletion
Especially when you already have an iterator
Fast insertion/removal at both ends
No requirement for random access
```

### Most important limitation of `list`

```cpp
list<int> l = {10, 20, 30, 40};

// ❌ Not allowed
// cout << l[2];

// ❌ Not allowed
// cout << l.at(2);
```

Instead:

```cpp
auto it = l.begin();

advance(it, 2);

cout << *it;
```

Output:

```text
30
```

---

# Final Memory Trick

```text
VECTOR
↓
Dynamic Array
↓
Fast access
↓
O(1) random access
↓
v[i] possible


LIST
↓
Doubly Linked List
↓
No random access
↓
l[i] NOT possible
↓
Fast insertion/deletion with iterator
```

The most important distinction is:

```text
vector → access-focused
list   → insertion/deletion-focused
```
