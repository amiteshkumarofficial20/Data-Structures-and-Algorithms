# C++ STL `set`

## Complete Detailed Notes, Theory, Syntax, Operations, Functions & Code

---

# 1. What is `set` in C++?

`set` is an **associative container** provided by the C++ Standard Template Library (STL).

It is used to store a collection of **unique elements** in **sorted order**.

Header file:

```cpp
#include <set>
```

Basic syntax:

```cpp
set<DataType> setName;
```

Example:

```cpp
set<int> s;
```

This creates a set that stores `int` values.

---

# 2. Main Properties of `set`

A `set` has three very important properties:

1. **Duplicate elements are not allowed.**
2. **Elements are automatically sorted.**
3. **Elements can be searched efficiently.**

Example:

```cpp
set<int> s;

s.insert(50);
s.insert(10);
s.insert(30);
s.insert(10);
s.insert(20);
```

Although we inserted:

```text
50
10
30
10
20
```

The set will contain:

```text
10
20
30
50
```

The second `10` will not be inserted because duplicate values are not allowed.

---

# 3. Header File

To use `set`, include:

```cpp
#include <set>
```

Example:

```cpp
#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> s;

    return 0;
}
```

---

# 4. Basic Syntax

```cpp
set<DataType> setName;
```

Examples:

```cpp
set<int> s1;

set<float> s2;

set<double> s3;

set<char> s4;

set<string> s5;
```

---

# 5. `set<int>`

The most common example is:

```cpp
set<int> s;
```

This means:

- `set` = STL container
- `int` = type of elements
- `s` = name of the set

Example:

```cpp
set<int> s;

s.insert(10);
s.insert(20);
s.insert(30);
```

The set becomes:

```text
10
20
30
```

---

# 6. Insertion in `set`

The main function used for insertion is:

```cpp
insert()
```

Syntax:

```cpp
s.insert(value);
```

Example:

```cpp
set<int> s;

s.insert(10);
s.insert(20);
s.insert(30);
```

---

# 7. Duplicate Insertion

A `set` does not allow duplicate values.

Example:

```cpp
set<int> s;

s.insert(10);
s.insert(20);
s.insert(10);
```

The set contains:

```text
10
20
```

Not:

```text
10
10
20
```

The second `10` is ignored.

---

# 8. `insert()` Return Value

`insert()` does not simply return `void`.

For a normal `set`, insertion returns a pair containing:

```text
iterator
bool
```

The `bool` tells whether insertion was successful.

Example:

```cpp
set<int> s;

pair<set<int>::iterator, bool> result;

result = s.insert(10);
```

If the element was successfully inserted:

```cpp
result.second == true
```

If the element already existed:

```cpp
result.second == false
```

Example:

```cpp
set<int> s;

pair<set<int>::iterator, bool> result;

result = s.insert(10);

if (result.second)
{
    cout << "Element inserted" << endl;
}
else
{
    cout << "Element already exists" << endl;
}
```

---

# 9. Automatic Sorting

One of the most important properties of `set` is automatic sorting.

Example:

```cpp
set<int> s;

s.insert(50);
s.insert(10);
s.insert(40);
s.insert(20);
s.insert(30);
```

Even though insertion order is:

```text
50
10
40
20
30
```

The set stores elements in:

```text
10
20
30
40
50
```

This happens automatically.

---

# 10. Default Ordering

By default, `set` uses ascending order.

Example:

```cpp
set<int> s;

s.insert(5);
s.insert(1);
s.insert(4);
s.insert(2);
s.insert(3);
```

Output:

```text
1
2
3
4
5
```

---

# 11. Iterating Through a `set`

There are several ways to iterate through a set.

The traditional iterator method is:

```cpp
for (set<int>::iterator it = s.begin();
     it != s.end();
     ++it)
{
    cout << *it << endl;
}
```

---

# 12. `begin()`

`begin()` returns an iterator pointing to the first element.

Example:

```cpp
set<int> s;

s.insert(30);
s.insert(10);
s.insert(20);

set<int>::iterator it = s.begin();
```

Since the set is ordered:

```text
10
20
30
```

`begin()` points to:

```text
10
```

---

# 13. `end()`

`end()` returns an iterator pointing to the position **after the last element**.

Important:

```cpp
s.end()
```

does not point to the last element.

Conceptually:

```text
10  20  30  END
^           ^
|           |
begin       end
```

Therefore:

```cpp
* s.end()
```

should not be used.

---

# 14. Dereferencing a Set Iterator

A set iterator points directly to an element.

Therefore:

```cpp
*it
```

gives the current element.

Example:

```cpp
set<int>::iterator it = s.begin();

cout << *it << endl;
```

---

# 15. Complete Iteration Using Iterator

```cpp
for (set<int>::iterator it = s.begin();
     it != s.end();
     ++it)
{
    cout << *it << endl;
}
```

Explanation:

### `s.begin()`

Starts from the first element.

### `it != s.end()`

Continues until the iterator reaches the position after the last element.

### `++it`

Moves to the next element.

### `*it`

Accesses the current element.

---

# 16. Range-Based `for` Loop

Modern C++ provides a simpler way to iterate:

```cpp
for (const auto &x : s)
{
    cout << x << endl;
}
```

Here:

```cpp
x
```

represents the current element.

Example:

```cpp
set<int> s;

s.insert(10);
s.insert(20);
s.insert(30);

for (const auto &x : s)
{
    cout << x << endl;
}
```

Output:

```text
10
20
30
```

---

# 17. Why `const auto &`?

This:

```cpp
for (const auto &x : s)
```

is useful because:

- `const` prevents modification.
- `&` avoids unnecessary copying.
- `auto` automatically determines the type.

Since set elements should not be modified directly, using:

```cpp
const auto &x
```

is a good practice for read-only iteration.

---

# 18. Set Elements Cannot Be Modified Directly

This is an important concept.

Suppose:

```cpp
set<int> s;

s.insert(10);
s.insert(20);
s.insert(30);
```

You cannot safely do:

```cpp
for (auto &x : s)
{
    x = 100;
}
```

Why?

Because `set` maintains its elements in sorted order.

If an element could be modified directly, the internal ordering could become invalid.

Therefore, set elements are treated as effectively constant.

If you want to change an element:

1. Erase the old element.
2. Insert the new element.

Example:

```cpp
s.erase(20);
s.insert(100);
```

---

# 19. `size()`

`size()` returns the number of elements in the set.

Syntax:

```cpp
s.size();
```

Example:

```cpp
set<int> s;

s.insert(10);
s.insert(20);
s.insert(30);

cout << s.size() << endl;
```

Output:

```text
3
```

Duplicate elements do not increase the size.

Example:

```cpp
s.insert(10);
s.insert(10);
s.insert(10);
```

Only one `10` exists.

---

# 20. `empty()`

`empty()` checks whether the set contains zero elements.

Syntax:

```cpp
s.empty();
```

It returns:

```text
true
```

if the set is empty.

It returns:

```text
false
```

if the set contains elements.

Example:

```cpp
if (s.empty())
{
    cout << "Set is empty" << endl;
}
else
{
    cout << "Set is not empty" << endl;
}
```

---

# 21. `clear()`

`clear()` removes all elements from the set.

Syntax:

```cpp
s.clear();
```

Example:

```cpp
set<int> s;

s.insert(10);
s.insert(20);
s.insert(30);

cout << s.size() << endl;

s.clear();

cout << s.size() << endl;
```

Output:

```text
3
0
```

---

# 22. Searching Using `find()`

`find()` is used to search for an element.

Syntax:

```cpp
s.find(value);
```

It returns an iterator.

If the element is found:

```cpp
iterator != s.end()
```

If the element is not found:

```cpp
iterator == s.end()
```

Example:

```cpp
set<int> s;

s.insert(10);
s.insert(20);
s.insert(30);

set<int>::iterator it = s.find(20);

if (it != s.end())
{
    cout << "Element found" << endl;
}
else
{
    cout << "Element not found" << endl;
}
```

---

# 23. `find()` and Dereferencing

If `find()` finds the element, the returned iterator points to that element.

Example:

```cpp
set<int>::iterator it = s.find(20);

if (it != s.end())
{
    cout << "Found element = " << *it << endl;
}
```

---

# 24. Searching for a Missing Element

```cpp
set<int>::iterator it = s.find(100);

if (it == s.end())
{
    cout << "100 is not present" << endl;
}
```

---

# 25. `count()`

`count()` checks whether an element exists.

Syntax:

```cpp
s.count(value);
```

For a normal `set`, a value can occur at most once.

Therefore:

```text
count(value) == 0
```

means element does not exist.

And:

```text
count(value) == 1
```

means element exists.

Example:

```cpp
if (s.count(20) == 1)
{
    cout << "20 exists" << endl;
}
else
{
    cout << "20 does not exist" << endl;
}
```

---

# 26. `find()` vs `count()`

## `find()`

Returns an iterator.

```cpp
set<int>::iterator it = s.find(20);
```

Useful when you want the actual position/iterator.

---

## `count()`

Returns the number of matching elements.

```cpp
s.count(20);
```

For a `set`, result is only:

```text
0 or 1
```

---

# 27. `erase()` by Value

You can remove an element by directly providing its value.

Syntax:

```cpp
s.erase(value);
```

Example:

```cpp
set<int> s;

s.insert(10);
s.insert(20);
s.insert(30);

s.erase(20);
```

Now the set contains:

```text
10
30
```

---

# 28. `erase()` by Iterator

You can also erase an element using an iterator.

Example:

```cpp
set<int>::iterator it = s.find(20);

if (it != s.end())
{
    s.erase(it);
}
```

This removes the element pointed to by `it`.

---

# 29. `erase()` by Range

You can erase a range of elements.

Syntax:

```cpp
s.erase(startIterator, endIterator);
```

Example:

```cpp
s.erase(s.begin(), s.end());
```

This removes all elements.

This produces the same final state as:

```cpp
s.clear();
```

---

# 30. Safe Erasing While Iterating

If you want to erase selected elements while traversing, be careful.

A safe pattern is:

```cpp
for (set<int>::iterator it = s.begin();
     it != s.end();)
{
    if (*it % 2 == 0)
    {
        it = s.erase(it);
    }
    else
    {
        ++it;
    }
}
```

Here:

```cpp
it = s.erase(it);
```

returns the next valid iterator.

If the element is not erased:

```cpp
++it;
```

moves to the next element.

---

# 31. `lower_bound()`

`lower_bound()` returns an iterator pointing to the first element that is:

```text
>= given value
```

Example:

```cpp
set<int> s;

s.insert(10);
s.insert(20);
s.insert(30);
s.insert(40);
```

Now:

```cpp
set<int>::iterator it = s.lower_bound(25);
```

The result is:

```text
30
```

Because `30` is the first element greater than or equal to `25`.

---

# 32. `lower_bound()` When Element Exists

Suppose:

```text
10
20
30
40
```

Then:

```cpp
s.lower_bound(20);
```

returns:

```text
20
```

Because `20 >= 20`.

---

# 33. `upper_bound()`

`upper_bound()` returns an iterator pointing to the first element that is:

```text
> given value
```

Example:

```cpp
set<int> s;

s.insert(10);
s.insert(20);
s.insert(30);
s.insert(40);
```

Then:

```cpp
set<int>::iterator it = s.upper_bound(20);
```

returns:

```text
30
```

Because `30` is the first element strictly greater than `20`.

---

# 34. Difference Between `lower_bound()` and `upper_bound()`

Suppose:

```text
10  20  30  40
```

For:

```cpp
s.lower_bound(20);
```

result:

```text
20
```

Because:

```text
20 >= 20
```

For:

```cpp
s.upper_bound(20);
```

result:

```text
30
```

Because:

```text
30 > 20
```

Remember:

```text
lower_bound -> >=
upper_bound -> >
```

---

# 35. `equal_range()`

`equal_range(value)` returns a pair of iterators:

```text
{
    lower_bound(value),
    upper_bound(value)
}
```

Syntax:

```cpp
pair<set<int>::iterator, set<int>::iterator> range;

range = s.equal_range(20);
```

For a normal `set`, elements are unique, so the range contains at most one matching element.

---

# 36. Reverse Iteration

A set can also be traversed in reverse order.

Use:

```cpp
rbegin()
```

and:

```cpp
rend()
```

Example:

```cpp
for (set<int>::reverse_iterator it = s.rbegin();
     it != s.rend();
     ++it)
{
    cout << *it << endl;
}
```

If the set contains:

```text
10
20
30
40
```

Output:

```text
40
30
20
10
```

---

# 37. `rbegin()`

`rbegin()` returns a reverse iterator pointing to the last/largest element.

For:

```text
10
20
30
40
```

`rbegin()` points to:

```text
40
```

---

# 38. `rend()`

`rend()` represents the position before the first element in reverse traversal.

Conceptually:

```text
40  30  20  10  REND
^              ^
|              |
rbegin         rend
```

---

# 39. `const_iterator`

If you only want to read the set:

```cpp
set<int>::const_iterator it;
```

Example:

```cpp
for (set<int>::const_iterator it = s.begin();
     it != s.end();
     ++it)
{
    cout << *it << endl;
}
```

A `const_iterator` prevents modification through the iterator.

---

# 40. Set of Strings

A set can store strings.

```cpp
set<string> names;

names.insert("Amit");
names.insert("Rahul");
names.insert("Riya");
names.insert("Amit");
```

The duplicate `"Amit"` will not be stored.

The strings will be maintained in sorted order.

---

# 41. Set of Characters

```cpp
set<char> letters;

letters.insert('z');
letters.insert('a');
letters.insert('m');
letters.insert('b');
```

Iteration:

```cpp
for (set<char>::iterator it = letters.begin();
     it != letters.end();
     ++it)
{
    cout << *it << " ";
}
```

Output:

```text
a b m z
```

---

# 42. Set of `pair`

A `set` can also store pairs.

Example:

```cpp
set<pair<int, int>> s;
```

Insert:

```cpp
s.insert(make_pair(10, 20));
s.insert(make_pair(5, 30));
s.insert(make_pair(10, 10));
```

Pairs are ordered lexicographically.

For example:

```text
(5, 30)
(10, 10)
(10, 20)
```

The first element is compared first.

If the first elements are equal, the second elements are compared.

---

# 43. Lexicographical Ordering of Pair

Suppose:

```cpp
set<pair<int, int>> s;

s.insert({2, 20});
s.insert({1, 30});
s.insert({2, 10});
s.insert({1, 20});
```

The order becomes:

```text
(1, 20)
(1, 30)
(2, 10)
(2, 20)
```

Comparison happens like dictionary ordering:

1. Compare first element.
2. If first elements are equal, compare second element.

---

# 44. `set` Does Not Support Indexing

This is invalid:

```cpp
cout << s[0];
```

Why?

Because `set` is not a random-access container.

You should use an iterator:

```cpp
set<int>::iterator it = s.begin();

cout << *it;
```

---

# 45. Accessing the First Element

Use:

```cpp
*s.begin()
```

Example:

```cpp
if (!s.empty())
{
    cout << "First element = " << *s.begin() << endl;
}
```

Since a normal set is sorted, the first element is the smallest element.

---

# 46. Accessing the Largest Element

Use:

```cpp
*s.rbegin()
```

Example:

```cpp
if (!s.empty())
{
    cout << "Largest element = " << *s.rbegin() << endl;
}
```

---

# 47. Set vs Vector

| Feature              | `set`      | `vector`              |
| -------------------- | ---------- | --------------------- |
| Duplicate values     | No         | Yes                   |
| Sorted automatically | Yes        | No                    |
| Indexing             | No         | Yes                   |
| Search               | `O(log n)` | `O(n)` normally       |
| Insert               | `O(log n)` | Usually `O(1)` at end |
| Erase                | `O(log n)` | Depends on position   |
| Random access        | No         | Yes                   |

---

# 48. Set vs Unordered Set

| Feature          | `set`      | `unordered_set`     |
| ---------------- | ---------- | ------------------- |
| Ordering         | Sorted     | No guaranteed order |
| Duplicate values | No         | No                  |
| Implementation   | Tree-based | Hash-based          |
| Search           | `O(log n)` | Average `O(1)`      |
| Insert           | `O(log n)` | Average `O(1)`      |
| Erase            | `O(log n)` | Average `O(1)`      |
| Header           | `<set>`    | `<unordered_set>`   |

---

# 49. Set vs Multiset

## `set`

Only unique values:

```cpp
set<int> s;

s.insert(10);
s.insert(10);
s.insert(10);
```

Result:

```text
10
```

---

## `multiset`

Duplicates are allowed:

```cpp
multiset<int> ms;

ms.insert(10);
ms.insert(10);
ms.insert(10);
```

Result:

```text
10
10
10
```

---

# 50. Important Set Functions

The most important `set` functions are:

```cpp
insert()
erase()
find()
count()
size()
empty()
clear()
begin()
end()
rbegin()
rend()
lower_bound()
upper_bound()
equal_range()
```

---

# 51. Function Summary

## `insert()`

Adds an element.

```cpp
s.insert(10);
```

---

## `erase()`

Removes an element.

```cpp
s.erase(10);
```

---

## `find()`

Searches for an element.

```cpp
s.find(10);
```

---

## `count()`

Checks whether an element exists.

```cpp
s.count(10);
```

---

## `size()`

Returns number of elements.

```cpp
s.size();
```

---

## `empty()`

Checks whether set is empty.

```cpp
s.empty();
```

---

## `clear()`

Removes everything.

```cpp
s.clear();
```

---

## `begin()`

Returns iterator to first element.

```cpp
s.begin();
```

---

## `end()`

Returns iterator after last element.

```cpp
s.end();
```

---

## `rbegin()`

Returns reverse iterator to largest element.

```cpp
s.rbegin();
```

---

## `rend()`

Returns reverse end iterator.

```cpp
s.rend();
```

---

## `lower_bound()`

Returns first element:

```text
>= key
```

```cpp
s.lower_bound(20);
```

---

## `upper_bound()`

Returns first element:

```text
> key
```

```cpp
s.upper_bound(20);
```

---

## `equal_range()`

Returns:

```text
{lower_bound, upper_bound}
```

```cpp
s.equal_range(20);
```

---

# 52. Complete Example

The following program demonstrates the most important `set` operations in one place.

```cpp
#include <iostream>
#include <set>

using namespace std;

int main()
{
    // ========================================================================
    // 1. CREATE SET
    // ========================================================================

    set<int> s;


    // ========================================================================
    // 2. INSERTION
    // ========================================================================

    s.insert(50);
    s.insert(10);
    s.insert(40);
    s.insert(20);
    s.insert(30);


    // ========================================================================
    // 3. DUPLICATE INSERTION
    // ========================================================================
    //
    // 10 already exists.
    //
    // Therefore this insertion will not create another 10.
    //

    s.insert(10);


    // ========================================================================
    // 4. ITERATE USING ITERATOR
    // ========================================================================

    cout << "Set elements:" << endl;

    for (set<int>::iterator it = s.begin();
         it != s.end();
         ++it)
    {
        cout << *it << " ";
    }

    cout << endl;


    // ========================================================================
    // 5. SIZE
    // ========================================================================

    cout << "Size = "
         << s.size()
         << endl;


    // ========================================================================
    // 6. EMPTY
    // ========================================================================

    if (s.empty())
    {
        cout << "Set is empty" << endl;
    }
    else
    {
        cout << "Set is not empty" << endl;
    }


    // ========================================================================
    // 7. FIND
    // ========================================================================

    set<int>::iterator it = s.find(30);

    if (it != s.end())
    {
        cout << "30 found" << endl;
    }
    else
    {
        cout << "30 not found" << endl;
    }


    // ========================================================================
    // 8. COUNT
    // ========================================================================

    if (s.count(40) == 1)
    {
        cout << "40 exists" << endl;
    }
    else
    {
        cout << "40 does not exist" << endl;
    }


    // ========================================================================
    // 9. ERASE BY VALUE
    // ========================================================================

    s.erase(20);


    cout << "After erasing 20:" << endl;

    for (set<int>::iterator iter = s.begin();
         iter != s.end();
         ++iter)
    {
        cout << *iter << " ";
    }

    cout << endl;


    // ========================================================================
    // 10. ERASE BY ITERATOR
    // ========================================================================

    set<int>::iterator eraseIt = s.find(30);

    if (eraseIt != s.end())
    {
        s.erase(eraseIt);
    }


    // ========================================================================
    // 11. RANGE-BASED LOOP
    // ========================================================================

    cout << "After erasing 30:" << endl;

    for (const auto &x : s)
    {
        cout << x << " ";
    }

    cout << endl;


    // ========================================================================
    // 12. LOWER_BOUND
    // ========================================================================

    set<int>::iterator lb = s.lower_bound(25);

    if (lb != s.end())
    {
        cout << "lower_bound(25) = "
             << *lb
             << endl;
    }
    else
    {
        cout << "No lower bound found." << endl;
    }


    // ========================================================================
    // 13. UPPER_BOUND
    // ========================================================================

    set<int>::iterator ub = s.upper_bound(25);

    if (ub != s.end())
    {
        cout << "upper_bound(25) = "
             << *ub
             << endl;
    }
    else
    {
        cout << "No upper bound found." << endl;
    }


    // ========================================================================
    // 14. REVERSE ITERATION
    // ========================================================================

    cout << "Reverse order:" << endl;

    for (set<int>::reverse_iterator rit = s.rbegin();
         rit != s.rend();
         ++rit)
    {
        cout << *rit << " ";
    }

    cout << endl;


    // ========================================================================
    // 15. FIRST ELEMENT
    // ========================================================================

    if (!s.empty())
    {
        cout << "First element = "
             << *s.begin()
             << endl;
    }


    // ========================================================================
    // 16. LAST / LARGEST ELEMENT
    // ========================================================================

    if (!s.empty())
    {
        cout << "Largest element = "
             << *s.rbegin()
             << endl;
    }


    // ========================================================================
    // 17. CLEAR
    // ========================================================================

    s.clear();


    cout << "Size after clear = "
         << s.size()
         << endl;


    return 0;
}
```

---

# 53. Time Complexity Cheat Sheet

| Operation         |                                                               Complexity |
| ----------------- | -----------------------------------------------------------------------: |
| `insert()`        |                                                               `O(log n)` |
| `erase(value)`    |                                                               `O(log n)` |
| `erase(iterator)` | Amortized/implementation-dependent; iterator lookup is already available |
| `find()`          |                                                               `O(log n)` |
| `count()`         |                                                               `O(log n)` |
| `lower_bound()`   |                                                               `O(log n)` |
| `upper_bound()`   |                                                               `O(log n)` |
| `size()`          |                                                                   `O(1)` |
| `empty()`         |                                                                   `O(1)` |
| `clear()`         |                                                                   `O(n)` |
| `begin()`         |                                                                   `O(1)` |
| `end()`           |                                                                   `O(1)` |

---

# 54. Important Interview / DSA Points

### Point 1

`set` stores **unique elements**.

```cpp
set<int> s;

s.insert(10);
s.insert(10);
```

Only one `10` exists.

---

### Point 2

`set` automatically maintains sorted order.

```cpp
s.insert(50);
s.insert(10);
s.insert(30);
```

Iteration:

```text
10
30
50
```

---

### Point 3

`set` does not support indexing.

This is invalid:

```cpp
s[0];
```

Use:

```cpp
*s.begin();
```

or an iterator.

---

### Point 4

`find()` returns an iterator.

```cpp
set<int>::iterator it = s.find(20);
```

---

### Point 5

For `set`, `count()` can only return:

```text
0
1
```

because duplicate elements are not allowed.

---

### Point 6

Set elements cannot be modified directly.

Wrong:

```cpp
for (auto &x : s)
{
    x = 100;
}
```

Correct approach:

```cpp
s.erase(oldValue);
s.insert(newValue);
```

---

### Point 7

`lower_bound()` means:

```text
>=
```

`upper_bound()` means:

```text
>
```

---

### Point 8

Normal `set` uses ascending order by default.

---

# 55. Quick Revision

```text
                    SET
                     |
          -------------------------
          |           |           |
       UNIQUE       SORTED      SEARCH
          |           |           |
       No dup.     Ascending    O(log n)
```

Important functions:

```text
insert()
erase()
find()
count()
size()
empty()
clear()
begin()
end()
rbegin()
rend()
lower_bound()
upper_bound()
equal_range()
```

---

# 56. One-Line Definitions

### `set`

> A `set` is an ordered associative STL container that stores unique elements.

### `insert()`

> Adds an element if it does not already exist.

### `erase()`

> Removes an element or range of elements.

### `find()`

> Searches for an element and returns an iterator.

### `count()`

> Checks whether an element exists.

### `lower_bound()`

> Returns the first element greater than or equal to the given value.

### `upper_bound()`

> Returns the first element strictly greater than the given value.

### `begin()`

> Returns an iterator to the first element.

### `end()`

> Returns an iterator to the position after the last element.

### `clear()`

> Removes all elements from the set.

---

# 57. Final Comparison

```text
                set
                 |
        ---------------------
        |                   |
      UNIQUE              ORDERED
        |                   |
   No duplicates       Sorted keys
        |                   |
        ----------- ---------
                   |
              O(log n)
          search/insert/erase
```

The most important line to remember:

> **`set` = Unique + Sorted + Efficient Search**
