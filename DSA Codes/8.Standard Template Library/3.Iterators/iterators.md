# C++ STL ITERATORS — VERY DETAILED COMPLETE NOTES

> **Language:** C++  
> **Topic:** STL Iterators  
> **Level:** Beginner → Intermediate → DSA  
> **Style:** Theory + detailed comments + runnable examples  
>
> This file is designed to be read as a complete chapter. It explains not only
> *how* to use iterators, but also **why they exist, which iterator category
> supports which operation, which STL containers provide which iterator type,
> invalidation rules, algorithms, reverse iterators, const iterators, stream
> iterators, iterator adapters, and common mistakes.**

---

# 1. What is an Iterator?

An **iterator** is an object that behaves somewhat like a pointer and is used to
move through elements of an STL container.

For example:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40};

    // begin() gives an iterator pointing to the first element.
    vector<int>::iterator it = v.begin();

    // *it means:
    // "give me the element to which this iterator is pointing."
    cout << *it << endl; // 10

    return 0;
}
```

Think of:

```cpp
it
```

as a position, and:

```cpp
*it
```

as the value stored at that position.

---

# 2. Iterator vs Value

This distinction is extremely important.

Suppose:

```cpp
vector<int> v = {10, 20, 30};
```

Then:

```cpp
auto it = v.begin();
```

`it` is NOT `10`.

It is an iterator pointing to the location/position of `10`.

So:

```cpp
cout << it;
```

is not how you normally print the value.

Instead:

```cpp
cout << *it;
```

prints:

```text
10
```

### Memory trick

```text
iterator = position
*iterator = value
```

---

# 3. Why Do Iterators Exist?

Different containers have completely different internal structures.

For example:

```text
vector
------
contiguous memory

list
----
linked nodes

set
---
ordered tree structure

unordered_set
--------------
hash table
```

If every STL algorithm had to know the internal implementation of every
container, the STL would become extremely complicated.

Instead, STL uses a common abstraction:

```text
Container
   ↓
Iterator
   ↓
Algorithm
```

Example:

```cpp
sort(v.begin(), v.end());
```

The `sort()` algorithm does not need to know the implementation details of
the vector.

It only needs an iterator range with the operations required by `sort()`.

This is one of the central ideas of the STL.

---

# 4. Iterator Range

Most STL algorithms work on a range:

```cpp
[first, last)
```

The notation means:

- `first` is included.
- `last` is excluded.

Example:

```cpp
vector<int> v = {10, 20, 30, 40, 50};

sort(v.begin(), v.end());
```

The algorithm works on:

```text
10 20 30 40 50
^              ^
first           last
included        excluded
```

`v.end()` does NOT point to `50`.

It points one position after `50`.

---

# 5. begin()

```cpp
v.begin()
```

returns an iterator pointing to the first element.

Example:

```cpp
vector<int> v = {10, 20, 30};

auto it = v.begin();

cout << *it;
```

Output:

```text
10
```

---

# 6. end()

```cpp
v.end()
```

returns an iterator representing the position **one past the last element**.

Example:

```cpp
vector<int> v = {10, 20, 30};

auto it = v.end();
```

You must NOT do:

```cpp
cout << *it; // WRONG
```

because `end()` is not a valid element.

Correct traversal:

```cpp
for (auto it = v.begin(); it != v.end(); ++it)
{
    cout << *it << " ";
}
```

Output:

```text
10 20 30
```

---

# 7. The Most Common Iterator Loop

```cpp
vector<int> v = {10, 20, 30, 40};

for (auto it = v.begin(); it != v.end(); ++it)
{
    cout << *it << " ";
}
```

Breakdown:

```cpp
auto it = v.begin();
```

Start at first element.

```cpp
it != v.end();
```

Continue until one-past-the-end.

```cpp
++it;
```

Move to the next element.

```cpp
*it
```

Access current element.

---

# 8. Iterator Dereferencing

The `*` operator dereferences an iterator.

```cpp
vector<int> v = {10, 20, 30};

auto it = v.begin();

cout << *it << endl;
```

Output:

```text
10
```

You can also modify the value if the iterator is mutable:

```cpp
*it = 100;
```

Now:

```text
100 20 30
```

But this depends on the iterator/container and whether the iterator is const.

---

# 9. Iterator Increment

```cpp
++it;
```

moves the iterator forward.

Example:

```cpp
vector<int> v = {10, 20, 30};

auto it = v.begin();

cout << *it << endl; // 10

++it;

cout << *it << endl; // 20

++it;

cout << *it << endl; // 30
```

---

# 10. Prefix vs Postfix Increment

Both exist:

```cpp
++it;
it++;
```

For normal iterator traversal, prefer:

```cpp
++it;
```

because prefix increment generally avoids creating an unnecessary old-value
copy for iterator types where that matters.

Example:

```cpp
for (auto it = v.begin(); it != v.end(); ++it)
{
    cout << *it;
}
```

---

# 11. Decrement

Some iterator categories support:

```cpp
--it;
it--;
```

For example, vector iterators support decrement.

```cpp
vector<int> v = {10, 20, 30};

auto it = v.end();

--it;

cout << *it;
```

Output:

```text
30
```

This is one way to access the last element.

Another common way:

```cpp
cout << v.back();
```

---

# 12. Iterator Categories

This is one of the MOST IMPORTANT sections.

Classic STL iterator categories are:

1. Input Iterator
2. Output Iterator
3. Forward Iterator
4. Bidirectional Iterator
5. Random Access Iterator

Modern C++ also has a more refined iterator concept system including:

6. Contiguous Iterator

For DSA/STL learning, understand all of them.

---

# 13. Iterator Category Hierarchy

Conceptually:

```text
                 Iterator capabilities
                        |
          +-------------+-------------+
          |                           |
     Input Iterator             Output Iterator
          |
     Forward Iterator
          |
  Bidirectional Iterator
          |
  Random Access Iterator
          |
   Contiguous Iterator
```

The hierarchy is easiest to understand as increasing capability.

A stronger iterator category supports operations of weaker categories.

For example:

```text
Random Access
    supports Bidirectional operations
    supports Forward operations
    supports Input-style traversal
```

Output is conceptually separate because it represents writing through iterators.

---

# 14. Input Iterator

An input iterator is used primarily for reading values while moving forward.

Typical operations include:

```cpp
*it
++it
it == other
it != other
```

Input iterators are generally single-pass.

A classic example is input stream iteration.

```cpp
istream_iterator<int>
```

Input iterator is important because many STL algorithms only need to read a
range once.

---

# 15. Output Iterator

Output iterators are used to write values.

Example:

```cpp
*it = value;
```

A very important example is:

```cpp
back_inserter(vector)
```

Example:

```cpp
vector<int> result;

auto it = back_inserter(result);

*it = 10;
++it;

*it = 20;
```

Now:

```text
result = {10, 20}
```

The iterator is adapting `push_back()` into iterator-style output.

---

# 16. Forward Iterator

Forward iterators support:

```cpp
*it
++it
```

and can make multiple passes over a range.

Examples include:

```text
forward_list
```

and iterators of unordered associative containers have at least forward
capability.

---

# 17. Bidirectional Iterator

Bidirectional iterators support:

```cpp
++it
--it
```

Examples:

```text
list
set
multiset
map
multimap
```

Example:

```cpp
list<int> li = {10, 20, 30};

auto it = li.end();

--it;

cout << *it;
```

Output:

```text
30
```

But this is NOT supported:

```cpp
it + 2; // ERROR
```

because bidirectional iterators do not provide random-access arithmetic.

---

# 18. Random Access Iterator

Random access iterators support all the common iterator movement operations.

For example:

```cpp
it + n
it - n
it += n
it -= n
it[n]
it1 - it2
it1 < it2
it1 > it2
```

Typical containers:

```text
vector
deque
array
```

Example:

```cpp
vector<int> v = {10, 20, 30, 40, 50};

auto it = v.begin();

cout << *(it + 3);
```

Output:

```text
40
```

---

# 19. Contiguous Iterator

A contiguous iterator is stronger than random access.

It guarantees that successive elements are stored contiguously in memory.

Examples:

```text
vector
array
C-style arrays
```

This is important for operations involving raw pointers and contiguous memory.

For example, a vector's data is contiguous:

```cpp
vector<int> v = {10, 20, 30};

int* p = v.data();

cout << p[1];
```

Output:

```text
20
```

---

# 20. Iterator Capability Table

| Operation | Input | Output | Forward | Bidirectional | Random Access | Contiguous |
|---|---:|---:|---:|---:|---:|---:|
| `*it` read | YES | NO/WRITE | YES | YES | YES | YES |
| `*it = x` | NO | YES | depends | depends | depends | depends |
| `++it` | YES | YES | YES | YES | YES | YES |
| `--it` | NO | NO | NO | YES | YES | YES |
| `it + n` | NO | NO | NO | NO | YES | YES |
| `it - n` | NO | NO | NO | NO | YES | YES |
| `it[n]` | NO | NO | NO | NO | YES | YES |
| `it1 - it2` | NO | NO | NO | NO | YES | YES |
| ordering `<` | NO | NO | NO | NO | YES | YES |

For actual code, exact readable/writable behavior depends on the iterator type
and reference type, but the table is the useful conceptual model.

---

# 21. Container → Iterator Category

## vector

```text
Random Access
Contiguous
```

Supports:

```cpp
it + 5
it - 5
it[5]
it2 - it1
```

---

## array

```text
Random Access
Contiguous
```

---

## deque

```text
Random Access
```

Deque iterators are random access, but deque is not contiguous like vector.

---

## list

```text
Bidirectional
```

Supports:

```cpp
++it
--it
```

Does NOT support:

```cpp
it + 5
```

---

## forward_list

```text
Forward
```

Supports:

```cpp
++it
```

Does NOT support:

```cpp
--it
it + 5
```

---

## set

```text
Bidirectional
```

---

## multiset

```text
Bidirectional
```

---

## map

```text
Bidirectional
```

---

## multimap

```text
Bidirectional
```

---

## unordered_set

```text
Forward
```

---

## unordered_map

```text
Forward
```

---

# 22. Why Does Container Iterator Category Matter?

Because algorithms have iterator requirements.

Example:

```cpp
sort(v.begin(), v.end());
```

`sort()` requires random-access iterators.

Therefore:

```cpp
vector<int> v;
sort(v.begin(), v.end()); // YES
```

But:

```cpp
list<int> li;
sort(li.begin(), li.end()); // NOT valid
```

For list use:

```cpp
li.sort();
```

The list's own member function knows how to sort linked-list nodes.

---

# 23. std::sort and Iterator Requirement

`std::sort()` requires Random Access Iterators.

Therefore:

```text
vector   YES
array    YES
deque    YES
list     NO
set      NO
map      NO
```

For `list`:

```cpp
li.sort();
```

For `set`:

The elements are already sorted according to the set comparator.

---

# 24. std::find and Iterator Requirement

`find()` is much less demanding.

It can work with input-style traversal.

Example:

```cpp
vector<int> v = {10, 20, 30};

auto it = find(
    v.begin(),
    v.end(),
    20
);
```

It also works with list:

```cpp
list<int> li = {10, 20, 30};

auto it = find(
    li.begin(),
    li.end(),
    20
);
```

And set:

```cpp
set<int> s = {10, 20, 30};

auto it = find(
    s.begin(),
    s.end(),
    20
);
```

BUT for set, prefer:

```cpp
s.find(20);
```

because the set member function can use tree ordering and generally runs in
O(log n), while generic `std::find()` performs linear traversal.

---

# 25. Iterator + Iterator Range

Many algorithms use:

```cpp
algorithm(
    begin,
    end
);
```

Examples:

```cpp
sort(v.begin(), v.end());

reverse(v.begin(), v.end());

find(v.begin(), v.end(), 30);

count(v.begin(), v.end(), 10);

accumulate(v.begin(), v.end(), 0);
```

This makes algorithms independent of the exact container type, provided the
iterator requirements are satisfied.

---

# 26. Iterator with Algorithms — Example

```cpp
vector<int> v = {
    50, 20, 40, 10, 30
};

sort(
    v.begin(),
    v.end()
);
```

After sorting:

```text
10 20 30 40 50
```

The algorithm receives:

```text
first = v.begin()
last  = v.end()
```

and processes:

```text
[first, last)
```

---

# 27. std::advance()

`advance()` moves an iterator by a specified number of positions.

Syntax:

```cpp
advance(it, n);
```

Example:

```cpp
vector<int> v = {
    10, 20, 30, 40, 50
};

auto it = v.begin();

advance(it, 3);

cout << *it;
```

Output:

```text
40
```

---

# 28. advance() vs Iterator Arithmetic

For vector:

```cpp
it += 3;
```

works.

For list:

```cpp
it += 3; // ERROR
```

Instead:

```cpp
advance(it, 3);
```

works with list iterators.

Important:

`advance()` does not magically make movement O(1).

For a vector random-access iterator:

```text
O(1)
```

For a list bidirectional iterator:

```text
O(n)
```

for moving many positions.

---

# 29. std::distance()

`distance(first, last)` returns the number of increments needed to reach
`last` from `first`.

Example:

```cpp
vector<int> v = {
    10, 20, 30, 40, 50
};

auto it = v.begin();

advance(it, 3);

cout << distance(
    v.begin(),
    it
);
```

Output:

```text
3
```

---

# 30. distance() Complexity

For random-access iterators:

```text
O(1)
```

For input/forward/bidirectional iterators:

Generally:

```text
O(n)
```

because the iterator may need to be incremented one step at a time.

---

# 31. std::next()

`next(it, n)` returns a new iterator advanced by `n`.

Example:

```cpp
vector<int> v = {
    10, 20, 30, 40, 50
};

auto it = next(
    v.begin(),
    2
);

cout << *it;
```

Output:

```text
30
```

Important:

`next()` does NOT modify the original iterator.

---

# 32. std::prev()

`prev(it, n)` returns a new iterator moved backwards by `n`.

Example:

```cpp
vector<int> v = {
    10, 20, 30, 40, 50
};

auto it = prev(
    v.end(),
    2
);

cout << *it;
```

Output:

```text
40
```

The original `v.end()` is not changed.

---

# 33. advance vs next vs prev

```text
advance(it, 3)
    modifies it

next(it, 3)
    returns new iterator
    does not modify it

prev(it, 3)
    returns iterator before it
```

Example:

```cpp
auto it = v.begin();

auto a = next(it, 2);

// it still points to first element
// a points to third element
```

---

# 34. const_iterator

A `const_iterator` allows reading but not modifying the element through the
iterator.

Example:

```cpp
vector<int> v = {
    10, 20, 30
};

vector<int>::const_iterator it =
    v.begin();

cout << *it;
```

This is NOT allowed:

```cpp
*it = 100;
```

because the iterator provides const access.

---

# 35. cbegin() and cend()

Containers provide:

```cpp
cbegin()
cend()
```

to obtain const iterators.

Example:

```cpp
vector<int> v = {
    10, 20, 30
};

auto it = v.cbegin();

cout << *it;
```

This cannot modify the element:

```cpp
*it = 100; // ERROR
```

---

# 36. begin() vs cbegin()

```cpp
v.begin()
```

may give a mutable iterator when `v` is non-const.

```cpp
v.cbegin()
```

gives a const iterator.

Example:

```cpp
vector<int> v = {10, 20, 30};

auto it = v.begin();

*it = 100; // valid
```

But:

```cpp
auto it2 = v.cbegin();

*it2 = 100; // invalid
```

---

# 37. const Container

If the container itself is const:

```cpp
const vector<int> v = {
    10, 20, 30
};
```

then:

```cpp
auto it = v.begin();
```

behaves as a const iterator.

So:

```cpp
*it = 100;
```

is not allowed.

---

# 38. reverse_iterator

A reverse iterator traverses the container in reverse direction.

Example:

```cpp
vector<int> v = {
    10, 20, 30, 40
};

for (
    auto it = v.rbegin();
    it != v.rend();
    ++it
)
{
    cout << *it << " ";
}
```

Output:

```text
40 30 20 10
```

---

# 39. rbegin() and rend()

```cpp
v.rbegin()
```

points to the last element.

```cpp
v.rend()
```

represents the position before the first element in reverse traversal.

Conceptually:

```text
Normal:

10 20 30 40
^           ^
begin       end


Reverse:

40 30 20 10
^           ^
rbegin      rend
```

---

# 40. Reverse Iterator Base()

This is a VERY important concept.

Suppose:

```cpp
vector<int> v = {
    10, 20, 30, 40
};

auto rit = v.rbegin();
```

Then:

```cpp
*rit
```

is:

```text
40
```

But:

```cpp
rit.base()
```

points to:

```text
end()
```

not directly to `40`.

General rule:

```text
reverse_iterator points to element BEFORE base()
```

Example:

```cpp
auto rit = v.rbegin();

cout << *rit << endl;          // 40
cout << *prev(rit.base()) << endl; // 40
```

---

# 41. Finding with reverse iterator

```cpp
auto rit = find(
    v.rbegin(),
    v.rend(),
    30
);

if (rit != v.rend())
{
    cout << *rit;
}
```

If you need the corresponding normal iterator, use:

```cpp
auto normalIt = rit.base();
```

But remember the base points one position AFTER the element represented by the
reverse iterator.

So often:

```cpp
auto normalIt = prev(rit.base());
```

is needed to refer to the same element.

---

# 42. std::reverse_iterator Type

You can explicitly write:

```cpp
vector<int>::reverse_iterator rit =
    v.rbegin();
```

But usually:

```cpp
auto rit = v.rbegin();
```

is cleaner.

---

# 43. Iterator Type with auto

Instead of:

```cpp
vector<int>::iterator it =
    v.begin();
```

prefer:

```cpp
auto it = v.begin();
```

This is especially useful for complicated iterator types such as:

```cpp
set<int>::iterator
map<int, string>::iterator
vector<pair<int, string>>::iterator
```

---

# 44. Map Iterator

A map iterator points to a key-value pair.

Example:

```cpp
map<int, string> mp = {
    {1, "A"},
    {2, "B"},
    {3, "C"}
};

for (
    auto it = mp.begin();
    it != mp.end();
    ++it
)
{
    cout << it->first
         << " "
         << it->second
         << endl;
}
```

Here:

```cpp
it->first
```

is key.

```cpp
it->second
```

is value.

---

# 45. Equivalent Map Syntax

Because:

```cpp
it
```

is an iterator to a pair, you can write:

```cpp
cout << (*it).first;
```

or:

```cpp
cout << it->first;
```

The arrow form is cleaner.

---

# 46. Set Iterator

Example:

```cpp
set<int> s = {
    10, 20, 30
};

auto it = s.begin();

cout << *it;
```

Output:

```text
10
```

But:

```cpp
*it = 100;
```

is not allowed because changing set elements directly can break ordering.

---

# 47. Vector Iterator Supports Arithmetic

```cpp
vector<int> v = {
    10, 20, 30, 40, 50
};

auto it = v.begin();

cout << *(it + 2);
```

Output:

```text
30
```

You can also:

```cpp
it += 3;
```

or:

```cpp
it -= 1;
```

---

# 48. List Iterator Does Not Support Arithmetic

```cpp
list<int> li = {
    10, 20, 30, 40
};

auto it = li.begin();

++it;
++it;

cout << *it;
```

works.

But:

```cpp
it + 2; // ERROR
```

does not work.

Use:

```cpp
advance(it, 2);
```

---

# 49. Set Iterator Does Not Support Arithmetic

```cpp
set<int> s = {
    10, 20, 30, 40
};

auto it = s.begin();

advance(it, 2);

cout << *it;
```

works.

But:

```cpp
s.begin() + 2; // ERROR
```

---

# 50. Iterator Comparison

For random-access iterators:

```cpp
it1 < it2
it1 <= it2
it1 > it2
it1 >= it2
```

are supported.

Example:

```cpp
vector<int> v = {
    10, 20, 30, 40
};

auto a = v.begin();
auto b = v.begin() + 2;

if (a < b)
{
    cout << "a comes before b";
}
```

For general iterators, prefer:

```cpp
it1 == it2
it1 != it2
```

because these are much more widely supported.

---

# 51. Why Use != end() in Loops?

The standard idiom is:

```cpp
for (
    auto it = v.begin();
    it != v.end();
    ++it
)
{
    cout << *it;
}
```

This works for many container iterator categories.

Do NOT assume:

```cpp
it < v.end()
```

works for every container.

For example, set iterators do not support `<`.

---

# 52. Iterator Invalidation

This is one of the most important practical topics.

An iterator can become invalid when the container changes.

If an iterator is invalidated and you dereference it, the program can have
undefined behavior.

The exact rules depend on the container and operation.

---

# 53. Vector Iterator Invalidation

Vector is particularly important.

Example:

```cpp
vector<int> v = {
    10, 20, 30
};

auto it = v.begin();

v.push_back(40);
```

If reallocation happens, old iterators can become invalid.

Therefore do not blindly keep using:

```cpp
it
```

after operations that may reallocate the vector.

---

# 54. vector reserve()

You can reduce reallocations using:

```cpp
v.reserve(100);
```

Example:

```cpp
vector<int> v;

v.reserve(100);

for (int i = 0; i < 100; ++i)
{
    v.push_back(i);
}
```

This can help avoid repeated reallocations during insertion.

But reserve does not mean iterators are permanently safe under every modification;
operations that change the vector can still invalidate iterators according to
the vector invalidation rules.

---

# 55. List Iterator Invalidation

For `list`, inserting or erasing other elements generally does not invalidate
iterators to unaffected elements.

Example:

```cpp
list<int> li = {
    10, 20, 30
};

auto it = li.begin();

li.push_back(40);

cout << *it;
```

The iterator to `10` remains valid.

If the element itself is erased, its iterator becomes invalid.

---

# 56. Set Iterator Invalidation

For `set`, insertion does not invalidate iterators to existing elements.

Erasing an element invalidates the iterator referring to that erased element.

Example:

```cpp
set<int> s = {
    10, 20, 30
};

auto it = s.find(20);

s.insert(40);

cout << *it; // still valid
```

Then:

```cpp
s.erase(it);
```

After erasing:

```cpp
it
```

must not be dereferenced.

---

# 57. Safe Erasing While Iterating

A common pattern:

```cpp
for (auto it = s.begin(); it != s.end(); )
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

Why?

Modern associative container `erase(iterator)` returns an iterator to the
next element.

This makes the pattern safe.

---

# 58. Vector Erase While Iterating

For vector:

```cpp
for (auto it = v.begin(); it != v.end(); )
{
    if (*it % 2 == 0)
    {
        it = v.erase(it);
    }
    else
    {
        ++it;
    }
}
```

This is the correct general pattern.

Do NOT do:

```cpp
v.erase(it);
++it;
```

without considering that `erase()` invalidates iterators at/after the erased
position for vector.

---

# 59. erase() Return Value

Many STL containers provide:

```cpp
it = container.erase(it);
```

The returned iterator points to the element following the erased element.

This is extremely useful in loops.

---

# 60. Iterator and References

An iterator often provides access to an element:

```cpp
*it
```

A reference can bind to the element:

```cpp
int& ref = *it;
```

Example:

```cpp
vector<int> v = {
    10, 20, 30
};

auto it = v.begin();

int& ref = *it;

ref = 100;
```

Now:

```text
100 20 30
```

But again, if the container operation invalidates the iterator/reference,
continuing to use it may be unsafe.

---

# 61. Iterator Traits

STL provides:

```cpp
iterator_traits<Iterator>
```

This can provide information such as:

```cpp
iterator_category
value_type
difference_type
reference
pointer
```

Example:

```cpp
vector<int>::iterator it;

using Traits =
    iterator_traits<
        vector<int>::iterator
    >;
```

Then:

```cpp
Traits::value_type
```

is:

```text
int
```

---

# 62. value_type

For:

```cpp
vector<int>::iterator
```

the iterator's `value_type` is:

```text
int
```

For:

```cpp
map<int, string>::iterator
```

the value type is approximately:

```text
pair<const int, string>
```

---

# 63. difference_type

Iterator distance calculations use an associated difference type.

Example:

```cpp
auto d = distance(
    v.begin(),
    v.end()
);
```

The type is conceptually:

```cpp
iterator_traits<Iterator>::difference_type
```

This is why `difference_type` is useful for generic code.

---

# 64. Iterator Adapters

STL provides useful iterator adapters.

Important ones:

```text
back_inserter
front_inserter
inserter
reverse_iterator
istream_iterator
ostream_iterator
```

---

# 65. back_inserter()

Used with containers supporting:

```cpp
push_back()
```

Example:

```cpp
vector<int> result;

auto it = back_inserter(result);

*it = 10;
*it = 20;
*it = 30;
```

Result:

```text
10 20 30
```

It automatically calls:

```cpp
result.push_back(value);
```

---

# 66. front_inserter()

Used with containers supporting:

```cpp
push_front()
```

Example:

```cpp
deque<int> d;

auto it = front_inserter(d);

*it = 10;
*it = 20;
*it = 30;
```

Because each insertion occurs at the front, the resulting order can be:

```text
30 20 10
```

This is useful to understand because `front_inserter` does not behave like
normal append.

---

# 67. inserter()

Used with containers that support positional insertion.

Example with set:

```cpp
set<int> result;

auto it = inserter(
    result,
    result.begin()
);

*it = 30;
*it = 10;
*it = 20;
```

The set maintains its own ordering:

```text
10 20 30
```

---

# 68. back_inserter with Algorithms

Example:

```cpp
vector<int> a = {
    1, 2, 3
};

vector<int> b = {
    4, 5, 6
};

vector<int> result;

copy(
    a.begin(),
    a.end(),
    back_inserter(result)
);

copy(
    b.begin(),
    b.end(),
    back_inserter(result)
);
```

Result:

```text
1 2 3 4 5 6
```

---

# 69. istream_iterator

An input stream can be treated like an iterator range.

Example:

```cpp
#include <iterator>

istream_iterator<int> input(
    cin
);

istream_iterator<int> end;
```

You can read integers using iterator syntax.

A classic pattern:

```cpp
vector<int> v(
    istream_iterator<int>(cin),
    istream_iterator<int>()
);
```

This reads integers from standard input until EOF.

---

# 70. ostream_iterator

Used to write values to an output stream.

Example:

```cpp
vector<int> v = {
    10, 20, 30
};

copy(
    v.begin(),
    v.end(),
    ostream_iterator<int>(
        cout,
        " "
    )
);
```

Output:

```text
10 20 30
```

---

# 71. Iterator + copy()

```cpp
vector<int> a = {
    10, 20, 30
};

vector<int> b;

copy(
    a.begin(),
    a.end(),
    back_inserter(b)
);
```

Now `b` contains:

```text
10 20 30
```

---

# 72. Iterator + find()

```cpp
vector<int> v = {
    10, 20, 30, 40
};

auto it = find(
    v.begin(),
    v.end(),
    30
);

if (it != v.end())
{
    cout << "Found: "
         << *it;
}
```

---

# 73. Iterator + find_if()

```cpp
vector<int> v = {
    11, 12, 13, 14
};

auto it = find_if(
    v.begin(),
    v.end(),
    [](int x)
    {
        return x % 2 == 0;
    }
);

if (it != v.end())
{
    cout << *it;
}
```

Output:

```text
12
```

---

# 74. Iterator + count()

`count()` returns a number, not an iterator.

```cpp
vector<int> v = {
    10, 20, 10, 30
};

int ans = count(
    v.begin(),
    v.end(),
    10
);

cout << ans;
```

Output:

```text
2
```

---

# 75. Iterator + min_element()

`min_element()` RETURNS AN ITERATOR.

This is very important.

```cpp
vector<int> v = {
    50, 20, 40, 10, 30
};

auto it = min_element(
    v.begin(),
    v.end()
);

cout << *it;
```

Output:

```text
10
```

Similarly:

```cpp
auto it = max_element(
    v.begin(),
    v.end()
);
```

returns iterator to maximum.

---

# 76. Iterator + binary_search()

`binary_search()` returns:

```text
bool
```

not an iterator.

```cpp
vector<int> v = {
    10, 20, 30, 40
};

bool found = binary_search(
    v.begin(),
    v.end(),
    30
);
```

For an iterator to the position, use:

```cpp
lower_bound()
```

or:

```cpp
find()
```

depending on requirements.

---

# 77. lower_bound() Returns Iterator

```cpp
vector<int> v = {
    10, 20, 30, 40, 50
};

auto it = lower_bound(
    v.begin(),
    v.end(),
    25
);

if (it != v.end())
{
    cout << *it;
}
```

Output:

```text
30
```

---

# 78. upper_bound() Returns Iterator

```cpp
auto it = upper_bound(
    v.begin(),
    v.end(),
    30
);

if (it != v.end())
{
    cout << *it;
}
```

Output:

```text
40
```

---

# 79. Iterator Difference and Index

For vector:

```cpp
auto it = find(
    v.begin(),
    v.end(),
    30
);

if (it != v.end())
{
    int index =
        it - v.begin();

    cout << index;
}
```

Output for:

```text
10 20 30 40
```

is:

```text
2
```

This works because vector iterators are random access.

---

# 80. Finding Index in list/set

Do NOT do:

```cpp
it - container.begin();
```

for list or set.

Instead:

```cpp
auto index =
    distance(
        container.begin(),
        it
    );
```

But remember that this can be O(n) for non-random-access iterators.

---

# 81. Iterator Invalidation — Quick Table

| Container | Typical important invalidation rule |
|---|---|
| vector | reallocation invalidates all iterators/references; erase can invalidate at/after position |
| deque | insertion/erase has special invalidation rules; do not assume iterators survive |
| list | iterators to unaffected elements remain valid |
| forward_list | iterators to unaffected elements remain valid |
| set | insertion does not invalidate existing iterators; erased iterator becomes invalid |
| map | insertion does not invalidate existing iterators; erased iterator becomes invalid |
| unordered_set | rehash can invalidate iterators |
| unordered_map | rehash can invalidate iterators |

Always check the exact operation when iterator validity matters.

---

# 82. Why `end()` Is Not Dereferenceable

This is one of the most common beginner errors:

```cpp
auto it = v.end();

cout << *it; // WRONG
```

`end()` is a sentinel/past-the-end position.

Correct:

```cpp
if (it != v.end())
{
    cout << *it;
}
```

---

# 83. Empty Container

For an empty container:

```cpp
vector<int> v;

v.begin() == v.end()
```

is true.

Therefore:

```cpp
if (v.begin() != v.end())
{
    cout << *v.begin();
}
```

is safe.

Do not dereference:

```cpp
v.begin()
```

when the container is empty.

---

# 84. Invalid Iterator

An iterator can become invalid because:

- the element is erased,
- vector reallocation happens,
- unordered container rehash happens,
- certain deque operations occur,
- the container is destroyed,
- or another operation specifically invalidates it.

Using an invalid iterator can lead to undefined behavior.

---

# 85. Iterator Lifetime Example

Wrong idea:

```cpp
auto it = v.begin();

v.clear();

cout << *it; // invalid
```

After `clear()`, elements are gone and old iterators cannot be used to access
those elements.

---

# 86. Safe Iterator Loop for Erasing

```cpp
for (auto it = v.begin(); it != v.end(); )
{
    if (*it == 20)
    {
        it = v.erase(it);
    }
    else
    {
        ++it;
    }
}
```

This avoids incrementing an invalidated iterator after erase.

---

# 87. const_iterator with Algorithms

Example:

```cpp
const vector<int> v = {
    10, 20, 30
};

auto it = find(
    v.cbegin(),
    v.cend(),
    20
);

if (it != v.cend())
{
    cout << *it;
}
```

This guarantees read-only access.

---

# 88. Iterator Type Aliases in Containers

Containers commonly expose:

```text
iterator
const_iterator
reverse_iterator
const_reverse_iterator
```

Example:

```cpp
vector<int>::iterator
vector<int>::const_iterator
vector<int>::reverse_iterator
vector<int>::const_reverse_iterator
```

Usually:

```cpp
auto
```

is easier.

---

# 89. Range-Based for Loop and Iterators

This:

```cpp
for (int x : v)
{
    cout << x;
}
```

is based on iterator-style traversal conceptually.

For mutable access:

```cpp
for (int& x : v)
{
    x *= 2;
}
```

For read-only access:

```cpp
for (const int& x : v)
{
    cout << x;
}
```

Modern C++ usually prefers range-based loops when you do not need explicit
iterator operations.

---

# 90. When Should You Use Explicit Iterators?

Use explicit iterators when you need:

- finding a position,
- inserting/erasing at iterator position,
- comparing positions,
- traversing a range manually,
- reverse traversal with iterator control,
- algorithms returning iterators,
- map/set operations,
- iterator-based generic code.

Example:

```cpp
auto it = s.lower_bound(50);

if (it != s.end())
{
    s.erase(it);
}
```

---

# 91. When Should You Use Range-Based for?

If you simply need values:

```cpp
for (const auto& x : v)
{
    cout << x << " ";
}
```

This is usually cleaner than manually writing:

```cpp
for (
    auto it = v.begin();
    it != v.end();
    ++it
)
{
    cout << *it << " ";
}
```

Both are valid.

---

# 92. Iterator Concepts in Modern C++

Modern C++20 provides concepts such as:

```text
input_iterator
output_iterator
forward_iterator
bidirectional_iterator
random_access_iterator
contiguous_iterator
```

This lets generic functions express their requirements directly.

Example:

```cpp
#include <iterator>

template <std::random_access_iterator It>
void myFunction(It first, It last)
{
    // Random-access operations are allowed here.
}
```

This is a C++20 feature.

---

# 93. Legacy Iterator Tags

Older/generic STL code may use:

```cpp
iterator_traits<It>::iterator_category
```

and tags such as:

```text
input_iterator_tag
output_iterator_tag
forward_iterator_tag
bidirectional_iterator_tag
random_access_iterator_tag
```

Modern C++ concepts are more expressive, but iterator categories remain important
for understanding existing STL code.

---

# 94. Iterator vs Pointer

They are similar in syntax:

```cpp
*it
```

and:

```cpp
*p
```

But they are not necessarily raw pointers.

An iterator can be a class object that overloads operators such as:

```cpp
*
++
--
==
!=
+
-
```

For example, a vector iterator may behave similarly to a pointer, while a
set iterator must navigate a tree.

This abstraction is what makes STL algorithms generic.

---

# 95. Why `it->member` Works

For iterators to objects/pairs, STL iterators often support `operator->`.

Example:

```cpp
map<int, string> mp = {
    {1, "One"},
    {2, "Two"}
};

auto it = mp.begin();

cout << it->first << endl;
cout << it->second << endl;
```

Equivalent:

```cpp
cout << (*it).first << endl;
cout << (*it).second << endl;
```

---

# 96. Iterator Insertion with lower_bound

A powerful set pattern:

```cpp
set<int> s = {
    10, 20, 30, 40
};

auto it = s.lower_bound(25);

s.insert(it, 25);
```

The iterator gives a useful insertion position/hint.

Modern implementations can exploit insertion hints when they are correct or
near the correct position.

---

# 97. upper_bound + erase

Example:

```cpp
set<int> s = {
    10, 20, 30, 40, 50
};

auto first = s.lower_bound(20);
auto last = s.upper_bound(40);

s.erase(first, last);
```

Result:

```text
10 50
```

Because:

```text
20 30 40
```

were in the erased range.

---

# 98. Reverse Traversal of set

```cpp
set<int> s = {
    10, 20, 30, 40
};

for (
    auto it = s.rbegin();
    it != s.rend();
    ++it
)
{
    cout << *it << " ";
}
```

Output:

```text
40 30 20 10
```

---

# 99. Iterator + accumulate

```cpp
#include <numeric>

vector<int> v = {
    10, 20, 30
};

int sum = accumulate(
    v.begin(),
    v.end(),
    0
);

cout << sum;
```

Output:

```text
60
```

The algorithm consumes the iterator range.

---

# 100. Iterator + transform

```cpp
vector<int> v = {
    1, 2, 3
};

transform(
    v.begin(),
    v.end(),
    v.begin(),
    [](int x)
    {
        return x * 2;
    }
);
```

Result:

```text
2 4 6
```

Here the first range is input and the third iterator is output.

---

# 101. Iterator + remove

Important:

```cpp
remove(
    v.begin(),
    v.end(),
    20
);
```

does NOT necessarily change vector size.

It returns an iterator to the new logical end.

Typical erase-remove idiom:

```cpp
v.erase(
    remove(
        v.begin(),
        v.end(),
        20
    ),
    v.end()
);
```

This is an important iterator concept.

---

# 102. remove_if

```cpp
v.erase(
    remove_if(
        v.begin(),
        v.end(),
        [](int x)
        {
            return x % 2 == 0;
        }
    ),
    v.end()
);
```

This removes even values from a vector.

Again:

```text
remove_if -> rearranges + returns logical new end
erase     -> actually changes container size
```

---

# 103. Iterator Returned by Algorithms

Many algorithms return iterators.

Examples:

```text
find
find_if
find_if_not
min_element
max_element
lower_bound
upper_bound
equal_range
remove
remove_if
unique
partition
is_heap_until
```

Other algorithms return bool/counts instead.

Examples:

```text
binary_search -> bool
count         -> count
count_if      -> count
is_sorted     -> bool
```

Understanding the return type is important.

---

# 104. unique() and Iterator

Example:

```cpp
vector<int> v = {
    1, 1, 2, 2, 3, 3
};

auto newEnd = unique(
    v.begin(),
    v.end()
);
```

`unique()` returns an iterator representing the new logical end.

To actually shrink vector:

```cpp
v.erase(
    newEnd,
    v.end()
);
```

Final:

```text
1 2 3
```

---

# 105. partition() and Iterator

```cpp
vector<int> v = {
    1, 2, 3, 4, 5, 6
};

auto it = partition(
    v.begin(),
    v.end(),
    [](int x)
    {
        return x % 2 == 0;
    }
);
```

`it` points to the partition boundary.

The exact ordering within the two groups is not guaranteed by ordinary
`partition()`.

---

# 106. Iterator and `next()` in erase

For a set:

```cpp
auto it = s.begin();

while (it != s.end())
{
    if (*it < 20)
    {
        it = s.erase(it);
    }
    else
    {
        ++it;
    }
}
```

This is often cleaner than trying to manually compute the next iterator.

---

# 107. `std::prev(end())`

Very common:

```cpp
auto last = prev(
    v.end()
);
```

Then:

```cpp
cout << *last;
```

prints the last element, provided the container is non-empty and supports the
required backward movement.

For vector/list/set this works.

But for an empty container:

```cpp
prev(v.end())
```

would be invalid to dereference.

---

# 108. `std::next(begin())`

Second element:

```cpp
auto second = next(
    v.begin()
);
```

Then:

```cpp
cout << *second;
```

provided the container has at least two elements.

---

# 109. Iterator Safety Checklist

Before dereferencing:

```cpp
*it
```

ask:

1. Is the iterator valid?
2. Is it not `end()`?
3. Does the container contain an element there?
4. Has the container operation invalidated it?

Safe pattern:

```cpp
if (it != container.end())
{
    cout << *it;
}
```

---

# 110. Complete Iterator Demo

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    vector<int> v = {
        50, 10, 40, 20, 30
    };

    // ------------------------------------------------------------
    // NORMAL ITERATION
    // ------------------------------------------------------------

    for (
        auto it = v.begin();
        it != v.end();
        ++it
    )
    {
        cout << *it << " ";
    }

    cout << endl;

    // ------------------------------------------------------------
    // RANDOM ACCESS
    // ------------------------------------------------------------

    auto it = v.begin();

    cout << *(it + 2) << endl;

    // ------------------------------------------------------------
    // SORT
    // ------------------------------------------------------------

    sort(
        v.begin(),
        v.end()
    );

    // ------------------------------------------------------------
    // FIND
    // ------------------------------------------------------------

    auto found = find(
        v.begin(),
        v.end(),
        30
    );

    if (found != v.end())
    {
        cout << "Found: "
             << *found
             << endl;
    }

    // ------------------------------------------------------------
    // REVERSE ITERATION
    // ------------------------------------------------------------

    for (
        auto rit = v.rbegin();
        rit != v.rend();
        ++rit
    )
    {
        cout << *rit << " ";
    }

    cout << endl;

    // ------------------------------------------------------------
    // DISTANCE
    // ------------------------------------------------------------

    cout << distance(
        v.begin(),
        found
    ) << endl;

    return 0;
}
```

---

# 111. Complete Container Iterator Demonstration

```cpp
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <unordered_set>

using namespace std;

int main()
{
    // ============================================================
    // VECTOR
    // Random Access + Contiguous
    // ============================================================

    vector<int> v = {
        10, 20, 30, 40
    };

    auto vit = v.begin();

    cout << *(vit + 2) << endl;

    // ============================================================
    // DEQUE
    // Random Access
    // ============================================================

    deque<int> dq = {
        10, 20, 30, 40
    };

    auto dit = dq.begin();

    cout << *(dit + 2) << endl;

    // ============================================================
    // LIST
    // Bidirectional
    // ============================================================

    list<int> li = {
        10, 20, 30, 40
    };

    auto lit = li.begin();

    ++lit;
    ++lit;

    cout << *lit << endl;

    // ============================================================
    // FORWARD LIST
    // Forward only
    // ============================================================

    forward_list<int> fl = {
        10, 20, 30
    };

    auto fit = fl.begin();

    ++fit;

    cout << *fit << endl;

    // ============================================================
    // SET
    // Bidirectional
    // ============================================================

    set<int> s = {
        30, 10, 20
    };

    auto sit = s.begin();

    ++sit;

    cout << *sit << endl;

    // ============================================================
    // UNORDERED SET
    // Forward traversal
    // ============================================================

    unordered_set<int> us = {
        10, 20, 30
    };

    for (
        auto uit = us.begin();
        uit != us.end();
        ++uit
    )
    {
        cout << *uit << " ";
    }

    return 0;
}
```

---

# 112. Iterator Quick Revision

## Basic

```cpp
begin()
end()
```

```text
begin -> first element
end   -> one past last
```

---

## Dereference

```cpp
*it
```

means:

```text
current value
```

---

## Move Forward

```cpp
++it
```

---

## Move Backward

```cpp
--it
```

only when supported.

---

## Random Access

```cpp
it + n
it - n
it += n
it -= n
it[n]
```

---

## Generic Movement

```cpp
advance(it, n)
next(it, n)
prev(it, n)
```

---

## Distance

```cpp
distance(first, last)
```

---

## Reverse

```cpp
rbegin()
rend()
```

---

## Const

```cpp
cbegin()
cend()
```

---

## Output Adapters

```cpp
back_inserter()
front_inserter()
inserter()
```

---

# 113. Iterator Category Cheat Sheet

```text
INPUT
    read + forward
    single pass concept

OUTPUT
    write

FORWARD
    read/write as permitted
    forward
    multiple pass

BIDIRECTIONAL
    forward + backward

RANDOM ACCESS
    bidirectional +
    arithmetic/indexing

CONTIGUOUS
    random access +
    physically contiguous storage guarantee
```

---

# 114. Container Cheat Sheet

```text
vector
    Random Access
    Contiguous

array
    Random Access
    Contiguous

deque
    Random Access
    NOT contiguous

list
    Bidirectional

forward_list
    Forward

set
    Bidirectional

multiset
    Bidirectional

map
    Bidirectional

multimap
    Bidirectional

unordered_set
    Forward

unordered_map
    Forward
```

---

# 115. Most Important DSA Rules

### Rule 1

If you need:

```cpp
it + k
```

you need Random Access Iterator.

Think:

```text
vector
array
deque
```

### Rule 2

If you only need:

```cpp
++it
```

many more containers work.

### Rule 3

If you need:

```cpp
--it
```

you need Bidirectional or stronger.

### Rule 4

If you need sorted traversal:

```text
set
map
```

already maintain ordering.

### Rule 5

If you need random access:

```text
vector
```

is usually the first container to consider.

### Rule 6

Do not dereference:

```cpp
end()
```

### Rule 7

After an operation that may invalidate an iterator, do not blindly use the old
iterator.

### Rule 8

For set/map, prefer container member functions such as:

```cpp
s.find(x)
s.lower_bound(x)
mp.find(key)
```

over generic algorithms when you want the ordered-container complexity.

---

# 116. Final Mental Model

Think of STL as:

```text
                 CONTAINER
                     |
                     |
                  ITERATOR
                     |
                     |
                 ALGORITHM
```

Example:

```cpp
vector<int> v;

sort(
    v.begin(),
    v.end()
);
```

means:

```text
vector
  ↓
vector iterators
  ↓
random-access range
  ↓
sort()
```

Another example:

```cpp
set<int> s;

auto it =
    s.lower_bound(30);
```

means:

```text
set
 ↓
set's ordered tree
 ↓
set iterator
 ↓
position of first element >= 30
```

---

# 117. One-Page Final Cheat Sheet

```text
ITERATOR
    = object representing a position in a range

*it
    = current element

++it
    = next element

--it
    = previous element if supported

begin()
    = first element

end()
    = one past last

rbegin()
    = last element in normal order

rend()
    = reverse past-the-end

cbegin()
cend()
    = const iterators

advance(it, n)
    = modify iterator

next(it, n)
    = new iterator forward

prev(it, n)
    = new iterator backward

distance(a, b)
    = number of steps/difference

back_inserter()
    = output through push_back

front_inserter()
    = output through push_front

inserter()
    = output through insert
```

```text
VECTOR
    Random Access + Contiguous

ARRAY
    Random Access + Contiguous

DEQUE
    Random Access

LIST
    Bidirectional

FORWARD_LIST
    Forward

SET
    Bidirectional

MAP
    Bidirectional

UNORDERED_SET
    Forward

UNORDERED_MAP
    Forward
```

```text
NEED it + n?
    vector / array / deque

NEED --it?
    list / set / map and stronger

NEED only ++it?
    almost all normal STL containers

NEED read-only traversal?
    cbegin / cend

NEED reverse traversal?
    rbegin / rend

NEED output into vector?
    back_inserter

NEED output into set?
    inserter
```

---

# 118. Final Important Reminder

The iterator category determines what operations an algorithm is allowed to
perform.

Do not memorize only:

```text
vector = random
list = bidirectional
set = bidirectional
```

Understand WHY.

For example:

```cpp
sort(list.begin(), list.end());
```

does not work with `std::sort()` because `std::sort()` requires random-access
iterators.

But:

```cpp
list.sort();
```

works because `list` has its own sorting operation designed for linked-list
structure.

Similarly:

```cpp
s.begin() + 3;
```

does not work for `std::set`, but:

```cpp
auto it = s.begin();
advance(it, 3);
```

works because `advance()` knows how to repeatedly increment a bidirectional
iterator.

The whole point of iterators is to provide a common interface between STL
containers and STL algorithms while preserving the capabilities and limitations
of each container's traversal mechanism.

================================================================================
END OF COMPLETE ITERATOR NOTES
================================================================================
