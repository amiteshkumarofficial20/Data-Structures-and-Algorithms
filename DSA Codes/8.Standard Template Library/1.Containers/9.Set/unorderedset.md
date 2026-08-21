# C++ STL — `unordered_set`

## Complete Detailed Notes, Theory, Syntax, Examples, Operations, Iterators, Hashing, Complexity & DSA Notes

---

# 1. Introduction to `unordered_set`

`unordered_set` is an associative container provided by the C++ Standard Template Library (STL).

Header file:

```cpp
#include <unordered_set>
```

Namespace:

```cpp
using namespace std;
```

Basic declaration:

```cpp
unordered_set<int> us;
```

An `unordered_set` stores **unique elements**.

Unlike `set`, an `unordered_set` does **not maintain sorted order**.

Example:

```cpp
unordered_set<int> us;

us.insert(50);
us.insert(10);
us.insert(30);
us.insert(20);
us.insert(40);
```

The order in which elements are displayed is **not guaranteed**.

You might see:

```text
40
20
50
10
30
```

or another order.

Do NOT expect:

```text
10
20
30
40
50
```

because `unordered_set` does not sort its elements.

---

# 2. Main Properties of `unordered_set`

Important properties:

1. Stores unique elements.
2. Does not maintain sorted order.
3. Uses hashing internally.
4. Provides average `O(1)` search.
5. Provides average `O(1)` insertion.
6. Provides average `O(1)` deletion.
7. Worst-case operations can become `O(n)`.
8. Supports iterators.
9. Does not support random-access iterators.
10. Does not support reverse iterators like `rbegin()` and `rend()`.
11. Does not provide `lower_bound()` or `upper_bound()`.
12. Supports bucket-related functions.
13. Very useful for fast membership checking.
14. Commonly used in DSA for duplicate detection, visited sets, graph problems, etc.

---

# 3. `set` vs `unordered_set`

| Feature            | `set`         | `unordered_set`     |
| ------------------ | ------------- | ------------------- |
| Header             | `<set>`       | `<unordered_set>`   |
| Duplicate elements | Not allowed   | Not allowed         |
| Order              | Sorted        | No guaranteed order |
| Internal structure | Balanced tree | Hash table          |
| Search average     | `O(log n)`    | `O(1)` average      |
| Search worst case  | `O(log n)`    | `O(n)`              |
| Insert average     | `O(log n)`    | `O(1)`              |
| Erase average      | `O(log n)`    | `O(1)`              |
| `begin()`          | Yes           | Yes                 |
| `end()`            | Yes           | Yes                 |
| `find()`           | Yes           | Yes                 |
| `count()`          | Yes           | Yes                 |
| `erase()`          | Yes           | Yes                 |
| `lower_bound()`    | Yes           | No                  |
| `upper_bound()`    | Yes           | No                  |
| `rbegin()`         | Yes           | No                  |
| `rend()`           | Yes           | No                  |
| Bucket functions   | No            | Yes                 |
| Sorted iteration   | Yes           | No                  |

---

# 4. Basic Syntax

```cpp
unordered_set<DataType> variableName;
```

Examples:

```cpp
unordered_set<int> numbers;
```

```cpp
unordered_set<double> prices;
```

```cpp
unordered_set<char> letters;
```

```cpp
unordered_set<string> names;
```

---

# 5. Required Header

Always include:

```cpp
#include <unordered_set>
```

Example:

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> us;

    return 0;
}
```

---

# 6. Creating an `unordered_set`

## Empty `unordered_set`

```cpp
unordered_set<int> us;
```

Initially:

```text
us = {}
```

No elements are stored.

---

# 7. Inserting Elements

The most common way to insert an element is:

```cpp
us.insert(value);
```

Example:

```cpp
unordered_set<int> us;

us.insert(10);
us.insert(20);
us.insert(30);
```

Now the set contains:

```text
10
20
30
```

The display order is not guaranteed.

---

# 8. Duplicate Elements

One of the most important properties of `unordered_set` is:

> It does not allow duplicate elements.

Example:

```cpp
unordered_set<int> us;

us.insert(10);
us.insert(20);
us.insert(10);
us.insert(30);
us.insert(20);
```

Only these unique values remain:

```text
10
20
30
```

The duplicate `10` and `20` are ignored.

---

# 9. Complete Basic Example

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> us;

    us.insert(10);
    us.insert(20);
    us.insert(30);
    us.insert(10);

    cout << "Size = " << us.size() << endl;

    return 0;
}
```

Output:

```text
Size = 3
```

The duplicate `10` was not inserted.

---

# 10. `insert()` Return Value

`insert()` does not simply return `true` or `false`.

For a normal insertion, it returns something conceptually like:

```cpp
pair<iterator, bool>
```

The second value tells us whether insertion actually happened.

Example:

```cpp
auto result = us.insert(10);
```

Then:

```cpp
result.second
```

is:

```text
true
```

if insertion happened.

If the element already existed:

```text
false
```

---

# 11. Checking Whether Insertion Happened

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> us;

    auto result1 = us.insert(100);

    if (result1.second)
    {
        cout << "100 inserted successfully" << endl;
    }
    else
    {
        cout << "100 was already present" << endl;
    }

    auto result2 = us.insert(100);

    if (result2.second)
    {
        cout << "100 inserted successfully" << endl;
    }
    else
    {
        cout << "100 was already present" << endl;
    }

    return 0;
}
```

Output:

```text
100 inserted successfully
100 was already present
```

---

# 12. `size()`

`size()` returns the number of elements currently stored.

Syntax:

```cpp
us.size();
```

Example:

```cpp
unordered_set<int> us;

us.insert(10);
us.insert(20);
us.insert(30);

cout << us.size() << endl;
```

Output:

```text
3
```

---

# 13. `empty()`

`empty()` checks whether the container contains zero elements.

Syntax:

```cpp
us.empty();
```

It returns:

```text
true
```

if empty.

It returns:

```text
false
```

if not empty.

Example:

```cpp
if (us.empty())
{
    cout << "Unordered Set is Empty" << endl;
}
else
{
    cout << "Unordered Set is Not Empty" << endl;
}
```

---

# 14. `clear()`

`clear()` removes all elements.

Syntax:

```cpp
us.clear();
```

Example:

```cpp
unordered_set<int> us;

us.insert(10);
us.insert(20);
us.insert(30);

cout << "Before clear = " << us.size() << endl;

us.clear();

cout << "After clear = " << us.size() << endl;
```

Output:

```text
Before clear = 3
After clear = 0
```

After `clear()`:

```cpp
us.empty()
```

will return:

```text
true
```

---

# 15. `find()`

`find()` is one of the most important functions.

It searches for a specific element.

Syntax:

```cpp
us.find(value);
```

It returns an iterator.

If the element exists:

```cpp
iterator != us.end()
```

If the element does not exist:

```cpp
iterator == us.end()
```

---

# 16. `find()` Example

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> us;

    us.insert(10);
    us.insert(20);
    us.insert(30);

    auto it = us.find(20);

    if (it != us.end())
    {
        cout << "Element Found = " << *it << endl;
    }
    else
    {
        cout << "Element Not Found" << endl;
    }

    return 0;
}
```

---

# 17. Why Compare With `end()`?

Very important:

```cpp
auto it = us.find(20);
```

If `20` exists:

```cpp
it
```

points to `20`.

If `20` does not exist:

```cpp
it == us.end()
```

Therefore always use:

```cpp
if (it != us.end())
```

before dereferencing.

Correct:

```cpp
if (it != us.end())
{
    cout << *it;
}
```

Incorrect:

```cpp
cout << *it;
```

when `it == us.end()`.

---

# 18. `count()`

Because `unordered_set` stores unique elements, `count()` returns either:

```text
0
```

or:

```text
1
```

Syntax:

```cpp
us.count(value);
```

Example:

```cpp
if (us.count(20) == 1)
{
    cout << "20 exists" << endl;
}
else
{
    cout << "20 does not exist" << endl;
}
```

---

# 19. `count()` vs `find()`

Both can be used for membership checking.

### Using `count()`

```cpp
if (us.count(20))
{
    cout << "Found";
}
```

### Using `find()`

```cpp
auto it = us.find(20);

if (it != us.end())
{
    cout << "Found";
}
```

Use `count()` when you only need to know whether the element exists.

Use `find()` when you need the iterator.

---

# 20. `erase(value)`

You can directly erase a value.

Syntax:

```cpp
us.erase(value);
```

Example:

```cpp
unordered_set<int> us;

us.insert(10);
us.insert(20);
us.insert(30);

us.erase(20);
```

Now `20` is removed.

---

# 21. `erase()` Return Value

For:

```cpp
us.erase(value);
```

the return value is the number of elements removed.

Because `unordered_set` contains unique values:

```text
0 -> element was not present

1 -> element was removed
```

Example:

```cpp
size_t result = us.erase(20);

cout << result << endl;
```

If `20` existed:

```text
1
```

If it did not:

```text
0
```

---

# 22. `erase(iterator)`

You can erase using an iterator.

Example:

```cpp
auto it = us.find(20);

if (it != us.end())
{
    us.erase(it);
}
```

This is useful when you already have an iterator.

---

# 23. Complete `find()` + `erase()` Pattern

This is a very important STL pattern:

```cpp
auto it = us.find(30);

if (it != us.end())
{
    us.erase(it);
}
```

Meaning:

1. Search for `30`.
2. Check whether it exists.
3. If it exists, erase it.

---

# 24. `erase(first, last)`

A range of elements can also be erased.

Syntax:

```cpp
us.erase(first, last);
```

Example:

```cpp
us.erase(us.begin(), us.end());
```

This removes all elements.

However, if your intention is simply to remove everything, use:

```cpp
us.clear();
```

because it clearly communicates the intention.

---

# 25. `swap()`

Two `unordered_set` objects can exchange their contents using `swap()`.

Syntax:

```cpp
us1.swap(us2);
```

Example:

```cpp
unordered_set<int> us1;

us1.insert(10);
us1.insert(20);

unordered_set<int> us2;

us2.insert(100);
us2.insert(200);

us1.swap(us2);
```

After swap:

```text
us1 -> 100, 200
us2 -> 10, 20
```

The exact iteration order remains unspecified.

---

# 26. `std::swap()`

You can also use:

```cpp
swap(us1, us2);
```

Example:

```cpp
#include <iostream>
#include <unordered_set>
#include <utility>

using namespace std;

int main()
{
    unordered_set<int> us1;
    unordered_set<int> us2;

    us1.insert(10);
    us1.insert(20);

    us2.insert(100);
    us2.insert(200);

    swap(us1, us2);

    return 0;
}
```

---

# 27. Iterators in `unordered_set`

An iterator is an object used to traverse a container.

For:

```cpp
unordered_set<int>
```

the iterator type is:

```cpp
unordered_set<int>::iterator
```

Example:

```cpp
unordered_set<int>::iterator it;
```

---

# 28. `begin()`

`begin()` returns an iterator to the first element in the container's iteration sequence.

Syntax:

```cpp
us.begin();
```

Important:

For `unordered_set`, `begin()` does NOT mean:

```text
smallest element
```

It means the first element according to the container's current iteration order.

---

# 29. `end()`

`end()` returns an iterator representing the position just after the last element in the iteration sequence.

Syntax:

```cpp
us.end();
```

Important:

`end()` is NOT an actual element.

Therefore:

```cpp
*us.end()
```

should not be used.

Instead:

```cpp
it != us.end()
```

is used to detect the end of iteration.

---

# 30. Basic Iterator Traversal

```cpp
for (unordered_set<int>::iterator it = us.begin();
     it != us.end();
     ++it)
{
    cout << *it << endl;
}
```

Explanation:

```cpp
us.begin()
```

starts the iterator.

```cpp
it != us.end()
```

continues until the end.

```cpp
++it
```

moves to the next element.

```cpp
*it
```

gives the current element.

---

# 31. Modern Iterator Syntax Using `auto`

Instead of:

```cpp
unordered_set<int>::iterator it;
```

you can write:

```cpp
auto it = us.begin();
```

Example:

```cpp
for (auto it = us.begin();
     it != us.end();
     ++it)
{
    cout << *it << endl;
}
```

This is shorter and commonly used in modern C++.

---

# 32. Range-Based For Loop

You can also iterate using:

```cpp
for (const auto &x : us)
{
    cout << x << endl;
}
```

This is often the simplest way to read all values.

---

# 33. Important Difference From `unordered_map`

`unordered_set` stores only values.

Example:

```cpp
unordered_set<int> us;
```

Element:

```text
10
```

Therefore:

```cpp
*it
```

is used.

There is no:

```cpp
it->first
it->second
```

Those are used with `unordered_map`.

---

# 34. `unordered_set` Does NOT Store Key-Value Pairs

For:

```cpp
unordered_set<int>
```

the element itself is the key.

Conceptually:

```text
10
20
30
```

There is no separate value.

Therefore:

```cpp
*it
```

returns the element.

---

# 35. `const_iterator`

A `const_iterator` is used when you want to read elements without modifying them.

Syntax:

```cpp
unordered_set<int>::const_iterator it;
```

Example:

```cpp
for (unordered_set<int>::const_iterator it = us.begin();
     it != us.end();
     ++it)
{
    cout << *it << endl;
}
```

Modern syntax:

```cpp
for (auto it = us.cbegin();
     it != us.cend();
     ++it)
{
    cout << *it << endl;
}
```

---

# 36. `cbegin()` and `cend()`

`cbegin()` returns a constant iterator.

```cpp
us.cbegin();
```

`cend()` returns the constant end iterator.

```cpp
us.cend();
```

Example:

```cpp
for (auto it = us.cbegin();
     it != us.cend();
     ++it)
{
    cout << *it << endl;
}
```

---

# 37. Can We Modify an Element Through an Iterator?

No.

Do NOT do:

```cpp
*it = 100;
```

for an `unordered_set`.

Why?

Because the element is part of the hash table's organization.

Changing the element directly could invalidate the hashing relationship.

Instead, remove the old value and insert the new value.

Example:

```cpp
us.erase(20);
us.insert(100);
```

---

# 38. Correct Way to Replace an Element

Suppose:

```cpp
unordered_set<int> us;

us.insert(10);
us.insert(20);
us.insert(30);
```

Suppose we want to replace:

```text
20
```

with:

```text
200
```

Use:

```cpp
us.erase(20);
us.insert(200);
```

---

# 39. Reverse Iteration

`unordered_set` does NOT provide:

```cpp
rbegin()
rend()
```

like an ordered `set`.

Do NOT write:

```cpp
us.rbegin();
```

for standard `unordered_set` reverse traversal.

Why?

Because its iterators are forward iterators rather than bidirectional iterators.

---

# 40. `++it`

`unordered_set` iterator supports moving forward:

```cpp
++it;
```

Example:

```cpp
auto it = us.begin();

if (it != us.end())
{
    ++it;
}
```

---

# 41. `--it`

`unordered_set` iterators do NOT support:

```cpp
--it;
```

This is a major difference from `set`.

### `set`

```cpp
++it;
--it;
```

### `unordered_set`

```cpp
++it;
```

but not:

```cpp
--it;
```

---

# 42. Random Access Is Not Supported

You cannot do:

```cpp
it + 2;
```

or:

```cpp
it - 2;
```

with an `unordered_set` iterator.

These operations are associated with random-access iterators such as vector iterators.

---

# 43. `std::advance()`

If you want to move an iterator several positions forward, you can use:

```cpp
advance(it, n);
```

Include:

```cpp
#include <iterator>
```

Example:

```cpp
auto it = us.begin();

advance(it, 2);
```

Important:

For `unordered_set`, this still requires moving forward step-by-step.

It is not random access.

---

# 44. `equal_range()`

`unordered_set` provides:

```cpp
equal_range(value);
```

It returns a pair of iterators.

Conceptually:

```cpp
pair<iterator, iterator>
```

Example:

```cpp
auto range = us.equal_range(20);
```

For a unique-key container like `unordered_set`, there can be at most one matching element.

---

# 45. Important Note About `lower_bound()` and `upper_bound()`

`unordered_set` does NOT provide:

```cpp
lower_bound()
```

or:

```cpp
upper_bound()
```

Why?

Because these operations depend on sorted ordering.

`unordered_set` has no sorted order.

For example, in `set`:

```text
10 20 30 40 50
```

You can ask:

```cpp
lower_bound(25)
```

and get:

```text
30
```

But `unordered_set` does not maintain this ordering.

---

# 46. Hashing

The major difference between `set` and `unordered_set` is hashing.

`unordered_set` is based on a hash table.

Conceptually:

```text
                    unordered_set

                         |
                         v
                    Hash Function
                         |
          +--------------+--------------+
          |              |              |
       Bucket 0       Bucket 1       Bucket 2
          |              |              |
       elements       elements       elements
```

The hash function determines where an element should be placed.

---

# 47. What Is a Bucket?

A bucket is a location in the internal hash table.

The hash table contains multiple buckets.

Each element is assigned to a bucket according to its hash value.

Conceptually:

```text
Bucket 0 -> elements
Bucket 1 -> elements
Bucket 2 -> elements
Bucket 3 -> elements
...
```

---

# 48. `bucket_count()`

`bucket_count()` returns the number of buckets currently used by the container.

Syntax:

```cpp
us.bucket_count();
```

Example:

```cpp
cout << "Number of buckets = "
     << us.bucket_count()
     << endl;
```

The exact number of buckets is implementation-dependent.

Do not assume a particular number.

---

# 49. `bucket(value)`

The function:

```cpp
us.bucket(value);
```

returns the bucket index associated with the specified value.

Example:

```cpp
cout << us.bucket(20) << endl;
```

This is useful for understanding how the hash table distributes values.

---

# 50. `bucket_size()`

`bucket_size(bucketNumber)` tells you how many elements are currently in a particular bucket.

Example:

```cpp
size_t b = us.bucket(20);

cout << us.bucket_size(b) << endl;
```

---

# 51. Local Iterators

A local iterator allows us to traverse elements belonging to one particular bucket.

Type:

```cpp
unordered_set<int>::local_iterator
```

Example:

```cpp
size_t bucketNumber = us.bucket(20);

for (auto it = us.begin(bucketNumber);
     it != us.end(bucketNumber);
     ++it)
{
    cout << *it << endl;
}
```

---

# 52. `begin(bucket)` and `end(bucket)`

For a specific bucket:

```cpp
us.begin(bucket);
```

returns a local iterator to the first element in that bucket.

And:

```cpp
us.end(bucket);
```

represents the end of that bucket's local sequence.

---

# 53. Iterate Through Every Bucket

Example:

```cpp
for (size_t bucket = 0;
     bucket < us.bucket_count();
     ++bucket)
{
    cout << "Bucket " << bucket << ": ";

    for (auto it = us.begin(bucket);
         it != us.end(bucket);
         ++it)
    {
        cout << *it << " ";
    }

    cout << endl;
}
```

This is mainly useful for learning and understanding hashing internals.

Normal DSA code usually does not need to manually inspect buckets.

---

# 54. Load Factor

Load factor is an important hashing concept.

Conceptually:

```text
load factor = number of elements / number of buckets
```

The STL provides:

```cpp
us.load_factor();
```

Example:

```cpp
cout << "Load factor = "
     << us.load_factor()
     << endl;
```

---

# 55. Why Load Factor Matters

If too many elements are placed into too few buckets, collisions can increase.

More collisions can negatively affect lookup performance.

The implementation can increase the number of buckets through rehashing.

---

# 56. `max_load_factor()`

The function:

```cpp
us.max_load_factor();
```

returns the current maximum load factor threshold.

You can also set it:

```cpp
us.max_load_factor(0.7);
```

Example:

```cpp
cout << us.max_load_factor() << endl;

us.max_load_factor(0.7);

cout << us.max_load_factor() << endl;
```

---

# 57. `rehash()`

`rehash()` requests that the container have at least a specified number of buckets.

Syntax:

```cpp
us.rehash(numberOfBuckets);
```

Example:

```cpp
us.rehash(100);
```

This is related to hash-table organization.

Important:

Do not use `rehash()` just because you can.

Normal STL code usually lets the container manage its buckets automatically.

---

# 58. `reserve()`

`reserve()` requests enough buckets for at least the specified number of elements without exceeding the maximum load factor.

Example:

```cpp
us.reserve(1000);
```

This can be useful when you know approximately how many elements you are going to insert.

It can reduce unnecessary rehashing during repeated insertions.

---

# 59. `reserve()` vs `rehash()`

### `reserve(n)`

Think in terms of:

```text
I expect approximately n elements.
```

Example:

```cpp
us.reserve(1000);
```

### `rehash(n)`

Think in terms of:

```text
I want at least n buckets.
```

Example:

```cpp
us.rehash(100);
```

---

# 60. Hash Function

You can obtain the hash function object using:

```cpp
us.hash_function();
```

Example:

```cpp
auto hasher = us.hash_function();
```

For an `unordered_set<int>`, the default hash function is generally:

```cpp
hash<int>
```

You normally do not need to call this function in everyday DSA code.

It is useful for understanding the internals of hashing.

---

# 61. Key Equal Function

`unordered_set` also has a key equality function.

You can access it using:

```cpp
us.key_eq();
```

This is used to determine whether keys/elements are considered equivalent.

For ordinary integer sets, this generally corresponds to equality comparison.

---

# 62. Important Hashing Terms

### Hash Function

Converts an element into a hash value.

### Bucket

A location in the hash table.

### Collision

When multiple elements are associated with the same bucket.

### Load Factor

Ratio related to elements and buckets.

### Rehashing

Changing/rebuilding the bucket arrangement to maintain suitable load.

---

# 63. Complete Hashing Demonstration

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> us;

    us.insert(10);
    us.insert(20);
    us.insert(30);
    us.insert(40);
    us.insert(50);

    cout << "Number of elements = "
         << us.size()
         << endl;

    cout << "Number of buckets = "
         << us.bucket_count()
         << endl;

    cout << "Load factor = "
         << us.load_factor()
         << endl;

    cout << "Maximum load factor = "
         << us.max_load_factor()
         << endl;

    cout << "Bucket of 30 = "
         << us.bucket(30)
         << endl;

    return 0;
}
```

---

# 64. `unordered_set<string>`

`unordered_set` can store strings.

Example:

```cpp
unordered_set<string> names;

names.insert("Amit");
names.insert("Rahul");
names.insert("Riya");
names.insert("Neha");
```

Iteration:

```cpp
for (const auto &name : names)
{
    cout << name << endl;
}
```

Again, the order is not guaranteed.

---

# 65. `unordered_set<char>`

You can store characters:

```cpp
unordered_set<char> letters;

letters.insert('a');
letters.insert('b');
letters.insert('c');
letters.insert('a');
```

Only unique characters remain.

---

# 66. `unordered_set<double>`

You can also store floating-point values:

```cpp
unordered_set<double> values;

values.insert(10.5);
values.insert(20.5);
values.insert(10.5);
```

However, remember that floating-point equality can have precision considerations.

For most DSA work, integer or string keys are more common.

---

# 67. Different Data Types

Common examples:

```cpp
unordered_set<int> s1;
```

```cpp
unordered_set<long long> s2;
```

```cpp
unordered_set<char> s3;
```

```cpp
unordered_set<string> s4;
```

```cpp
unordered_set<double> s5;
```

The type must have suitable hashing and equality support.

---

# 68. User-Defined Types

For a custom class/struct, you generally need to provide:

1. A hash function.
2. An equality comparison.

For example:

```cpp
struct Student
{
    int id;
    string name;
};
```

A custom hash and equality mechanism would be needed before using:

```cpp
unordered_set<Student>
```

This is an advanced topic.

---

# 69. Complete Basic Operations Example

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> us;

    // ------------------------------------------------------------
    // INSERTION
    // ------------------------------------------------------------

    us.insert(10);
    us.insert(20);
    us.insert(30);
    us.insert(40);
    us.insert(50);

    // Duplicate insertion
    us.insert(30);

    // ------------------------------------------------------------
    // SIZE
    // ------------------------------------------------------------

    cout << "Size = "
         << us.size()
         << endl;

    // ------------------------------------------------------------
    // ITERATION
    // ------------------------------------------------------------

    cout << "\nElements:" << endl;

    for (auto it = us.begin();
         it != us.end();
         ++it)
    {
        cout << *it << endl;
    }

    // ------------------------------------------------------------
    // FIND
    // ------------------------------------------------------------

    auto it = us.find(30);

    if (it != us.end())
    {
        cout << "\n30 found" << endl;
    }
    else
    {
        cout << "\n30 not found" << endl;
    }

    // ------------------------------------------------------------
    // COUNT
    // ------------------------------------------------------------

    if (us.count(40))
    {
        cout << "40 exists" << endl;
    }

    // ------------------------------------------------------------
    // ERASE
    // ------------------------------------------------------------

    us.erase(20);

    cout << "\nAfter erasing 20:" << endl;

    for (const auto &x : us)
    {
        cout << x << endl;
    }

    // ------------------------------------------------------------
    // EMPTY
    // ------------------------------------------------------------

    if (us.empty())
    {
        cout << "Set is empty" << endl;
    }
    else
    {
        cout << "Set is not empty" << endl;
    }

    // ------------------------------------------------------------
    // CLEAR
    // ------------------------------------------------------------

    us.clear();

    cout << "\nAfter clear:" << endl;

    cout << "Size = "
         << us.size()
         << endl;

    return 0;
}
```

---

# 70. Complete Detailed Operations Example

```cpp
#include <iostream>
#include <unordered_set>
#include <string>
#include <iterator>

using namespace std;

int main()
{
    // ============================================================
    // CREATE
    // ============================================================

    unordered_set<int> us;

    // ============================================================
    // INSERT
    // ============================================================

    us.insert(10);
    us.insert(20);
    us.insert(30);
    us.insert(40);
    us.insert(50);

    // Duplicate
    us.insert(30);

    cout << "Size = "
         << us.size()
         << endl;

    // ============================================================
    // ITERATION
    // ============================================================

    cout << "\nIteration:" << endl;

    for (auto it = us.begin();
         it != us.end();
         ++it)
    {
        cout << *it << endl;
    }

    // ============================================================
    // FIND
    // ============================================================

    auto findIt = us.find(30);

    if (findIt != us.end())
    {
        cout << "\n30 found = "
             << *findIt
             << endl;
    }

    // ============================================================
    // COUNT
    // ============================================================

    cout << "\nCount of 30 = "
         << us.count(30)
         << endl;

    cout << "Count of 100 = "
         << us.count(100)
         << endl;

    // ============================================================
    // ERASE BY VALUE
    // ============================================================

    size_t removed = us.erase(20);

    cout << "\nRemoved = "
         << removed
         << endl;

    // ============================================================
    // ERASE BY ITERATOR
    // ============================================================

    auto eraseIt = us.find(30);

    if (eraseIt != us.end())
    {
        us.erase(eraseIt);
    }

    // ============================================================
    // SIZE
    // ============================================================

    cout << "\nCurrent size = "
         << us.size()
         << endl;

    // ============================================================
    // EMPTY
    // ============================================================

    if (us.empty())
    {
        cout << "Empty" << endl;
    }
    else
    {
        cout << "Not Empty" << endl;
    }

    // ============================================================
    // BUCKET INFORMATION
    // ============================================================

    cout << "\nBucket count = "
         << us.bucket_count()
         << endl;

    cout << "Load factor = "
         << us.load_factor()
         << endl;

    cout << "Maximum load factor = "
         << us.max_load_factor()
         << endl;

    // ============================================================
    // CLEAR
    // ============================================================

    us.clear();

    cout << "\nAfter clear:" << endl;

    cout << "Size = "
         << us.size()
         << endl;

    if (us.empty())
    {
        cout << "unordered_set is empty." << endl;
    }

    return 0;
}
```

---

# 71. Safe Erase While Iterating

This is an important interview and DSA pattern.

Suppose we want to remove all even numbers.

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> us;

    us.insert(10);
    us.insert(11);
    us.insert(12);
    us.insert(13);
    us.insert(14);
    us.insert(15);

    for (auto it = us.begin();
         it != us.end();)
    {
        if (*it % 2 == 0)
        {
            // erase() returns the next valid iterator.
            it = us.erase(it);
        }
        else
        {
            // Move to next element manually.
            ++it;
        }
    }

    cout << "After removing even numbers:" << endl;

    for (const auto &x : us)
    {
        cout << x << endl;
    }

    return 0;
}
```

After this, only odd numbers remain.

The exact output order is unspecified.

---

# 72. Why `it = us.erase(it)`?

Suppose:

```cpp
it
```

points to the current element.

If you do:

```cpp
us.erase(it);
```

the iterator that pointed to the erased element can no longer be used as a valid iterator to that erased element.

The erase operation returns the next valid iterator.

Therefore:

```cpp
it = us.erase(it);
```

is the safe pattern.

---

# 73. Wrong Erase Pattern

Avoid:

```cpp
for (auto it = us.begin();
     it != us.end();
     ++it)
{
    if (*it % 2 == 0)
    {
        us.erase(it);
    }
}
```

Why?

Because after:

```cpp
us.erase(it);
```

the iterator may be invalidated.

Then the loop's:

```cpp
++it
```

can attempt to increment an invalid iterator.

Use:

```cpp
for (auto it = us.begin();
     it != us.end();)
{
    if (*it % 2 == 0)
    {
        it = us.erase(it);
    }
    else
    {
        ++it;
    }
}
```

---

# 74. Complete Bucket Traversal Example

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> us;

    us.insert(10);
    us.insert(20);
    us.insert(30);
    us.insert(40);
    us.insert(50);

    // ------------------------------------------------------------
    // Number of buckets
    // ------------------------------------------------------------

    size_t totalBuckets = us.bucket_count();

    cout << "Total buckets = "
         << totalBuckets
         << endl;

    // ------------------------------------------------------------
    // Traverse every bucket
    // ------------------------------------------------------------

    for (size_t bucket = 0;
         bucket < totalBuckets;
         ++bucket)
    {
        cout << "\nBucket "
             << bucket
             << ": ";

        // Local iterator for this bucket.
        for (auto it = us.begin(bucket);
             it != us.end(bucket);
             ++it)
        {
            cout << *it << " ";
        }
    }

    cout << endl;

    return 0;
}
```

Important:

The exact bucket distribution is implementation-dependent.

Do not write code that depends on a particular bucket number unless you have a specific reason.

---

# 75. `reserve()`

Suppose you know you are going to insert approximately one million values.

You can write:

```cpp
unordered_set<int> us;

us.reserve(1000000);
```

Then insert:

```cpp
for (int i = 0; i < 1000000; ++i)
{
    us.insert(i);
}
```

This can reduce repeated rehashing.

---

# 76. `rehash()`

Example:

```cpp
unordered_set<int> us;

us.rehash(100);
```

This requests at least 100 buckets.

Then:

```cpp
cout << us.bucket_count();
```

can be used to inspect the current bucket count.

The actual bucket count may be greater than the requested value because the implementation chooses an appropriate bucket count.

---

# 77. `max_load_factor()`

Example:

```cpp
unordered_set<int> us;

cout << us.max_load_factor() << endl;

us.max_load_factor(0.7);

cout << us.max_load_factor() << endl;
```

A lower maximum load factor generally means the table may maintain more buckets relative to its number of elements, potentially reducing collisions at the cost of additional memory.

Do not change this unnecessarily in normal DSA problems.

---

# 78. `hash_function()`

Example:

```cpp
unordered_set<int> us;

auto hashFunction = us.hash_function();

cout << hashFunction(100) << endl;
```

This obtains the hash function object.

The exact hash value is implementation-dependent.

Do not depend on a particular numeric hash value in normal programs.

---

# 79. `key_eq()`

Example:

```cpp
unordered_set<int> us;

auto equalFunction = us.key_eq();

if (equalFunction(10, 10))
{
    cout << "Values are considered equal." << endl;
}
```

This gives access to the equality predicate used by the container.

---

# 80. Complete Hash Table Information Program

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> us;

    us.insert(10);
    us.insert(20);
    us.insert(30);
    us.insert(40);
    us.insert(50);

    cout << "Size = "
         << us.size()
         << endl;

    cout << "Bucket count = "
         << us.bucket_count()
         << endl;

    cout << "Load factor = "
         << us.load_factor()
         << endl;

    cout << "Maximum load factor = "
         << us.max_load_factor()
         << endl;

    cout << "Bucket of 30 = "
         << us.bucket(30)
         << endl;

    cout << "Bucket size = "
         << us.bucket_size(us.bucket(30))
         << endl;

    return 0;
}
```

---

# 81. Important Difference: `set` and `unordered_set` Iterators

## `set`

```cpp
set<int> s;

for (auto it = s.begin();
     it != s.end();
     ++it)
{
    cout << *it;
}
```

The elements are visited in sorted order.

Also:

```cpp
--it;
```

is supported.

And:

```cpp
s.lower_bound(x);
s.upper_bound(x);
```

are supported.

---

## `unordered_set`

```cpp
unordered_set<int> us;

for (auto it = us.begin();
     it != us.end();
     ++it)
{
    cout << *it;
}
```

The order is not guaranteed.

Backward movement:

```cpp
--it;
```

is not supported.

Also:

```cpp
us.lower_bound(x);
us.upper_bound(x);
```

are not available.

---

# 82. Iterator Category

The iterator category for `unordered_set` is a forward iterator.

That means it supports forward traversal:

```cpp
++it;
```

but not backward traversal:

```cpp
--it;
```

It also does not support:

```cpp
it + n
```

or:

```cpp
it - n
```

---

# 83. `unordered_set` Does Not Guarantee Iteration Order

This is one of the most important points.

Never write logic that assumes:

```cpp
unordered_set<int> us;

us.insert(1);
us.insert(2);
us.insert(3);
```

will iterate as:

```text
1
2
3
```

It may happen, but it is not guaranteed.

The iteration order depends on the hash table's organization.

---

# 84. Why Does Iteration Order Change?

Operations such as insertion and rehashing can change the internal bucket arrangement.

For example:

```cpp
us.insert(100);
us.insert(200);
us.insert(300);
```

then later:

```cpp
us.insert(400);
```

may cause a rehash.

After rehashing, iteration order can change.

Therefore never rely on it.

---

# 85. Iterator Invalidation

Iterator invalidation is an important advanced topic.

Certain container operations can invalidate iterators.

For `unordered_set`, insertion may trigger a rehash.

If rehashing occurs, iterators can be invalidated.

Therefore, do not assume an iterator remains valid across arbitrary insertions.

Example:

```cpp
auto it = us.begin();

us.insert(1000);
```

If the insertion causes a rehash, the old iterator may no longer be valid.

---

# 86. Practical Rule for Iterators

If you perform a potentially rehashing operation such as insertion, do not casually keep using old iterators.

A simple safe approach is to reacquire the iterator when necessary:

```cpp
auto it = us.find(value);
```

after the modification.

---

# 87. `clear()` and Iterators

If you do:

```cpp
us.clear();
```

all elements are removed.

Iterators pointing to those elements should no longer be used.

Example:

```cpp
auto it = us.begin();

us.clear();

// Do not use old 'it' here.
```

---

# 88. Practical DSA Use Case — Duplicate Detection

One of the most common uses of `unordered_set` is detecting duplicates.

Example:

```cpp
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {
        10, 20, 30, 10, 40, 50
    };

    unordered_set<int> seen;

    for (int x : arr)
    {
        if (seen.count(x))
        {
            cout << "Duplicate found: "
                 << x
                 << endl;
        }
        else
        {
            seen.insert(x);
        }
    }

    return 0;
}
```

---

# 89. DSA Use Case — Remove Duplicates

```cpp
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {
        10, 20, 10, 30, 20, 40
    };

    unordered_set<int> uniqueValues;

    for (int x : arr)
    {
        uniqueValues.insert(x);
    }

    cout << "Unique values:" << endl;

    for (int x : uniqueValues)
    {
        cout << x << endl;
    }

    return 0;
}
```

Important:

The output order is not guaranteed.

If you need unique values in sorted order, use:

```cpp
set<int>
```

instead.

---

# 90. DSA Use Case — Visited Nodes

`unordered_set` is commonly useful in graph traversal.

Example:

```cpp
unordered_set<int> visited;

if (visited.count(node) == 0)
{
    visited.insert(node);

    // Process node.
}
```

This provides average constant-time membership checks.

---

# 91. DSA Use Case — Fast Membership

Suppose:

```cpp
unordered_set<int> allowed;
```

Then:

```cpp
if (allowed.count(x))
{
    // x exists
}
```

is a common pattern.

---

# 92. Complete Membership Example

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> allowed;

    allowed.insert(10);
    allowed.insert(20);
    allowed.insert(30);

    int x = 20;

    if (allowed.count(x))
    {
        cout << x << " exists." << endl;
    }
    else
    {
        cout << x << " does not exist." << endl;
    }

    return 0;
}
```

---

# 93. `unordered_set<string>` for Duplicate Words

```cpp
#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
    unordered_set<string> words;

    words.insert("apple");
    words.insert("banana");
    words.insert("apple");
    words.insert("orange");

    cout << "Unique words:" << endl;

    for (const auto &word : words)
    {
        cout << word << endl;
    }

    return 0;
}
```

---

# 94. Complete `unordered_set` Operations Program

```cpp
#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
    // ============================================================
    // CREATE
    // ============================================================

    unordered_set<string> countries;

    // ============================================================
    // INSERTION
    // ============================================================

    countries.insert("India");
    countries.insert("England");
    countries.insert("Brazil");
    countries.insert("Japan");

    // Duplicate
    countries.insert("India");

    // ============================================================
    // SIZE
    // ============================================================

    cout << "Size = "
         << countries.size()
         << endl;

    // ============================================================
    // ITERATION
    // ============================================================

    cout << "\nCountries:" << endl;

    for (auto it = countries.begin();
         it != countries.end();
         ++it)
    {
        cout << *it << endl;
    }

    // ============================================================
    // FIND
    // ============================================================

    auto it = countries.find("India");

    if (it != countries.end())
    {
        cout << "\nIndia Found" << endl;
    }
    else
    {
        cout << "\nIndia Not Found" << endl;
    }

    // ============================================================
    // COUNT
    // ============================================================

    if (countries.count("Japan"))
    {
        cout << "Japan exists." << endl;
    }

    // ============================================================
    // ERASE
    // ============================================================

    countries.erase("Brazil");

    // ============================================================
    // CHECK EMPTY
    // ============================================================

    if (countries.empty())
    {
        cout << "Set is empty." << endl;
    }
    else
    {
        cout << "Set is not empty." << endl;
    }

    // ============================================================
    // BUCKET INFORMATION
    // ============================================================

    cout << "\nBucket count = "
         << countries.bucket_count()
         << endl;

    cout << "Load factor = "
         << countries.load_factor()
         << endl;

    // ============================================================
    // CLEAR
    // ============================================================

    countries.clear();

    cout << "\nAfter clear:" << endl;

    cout << "Size = "
         << countries.size()
         << endl;

    return 0;
}
```

---

# 95. Important Functions Cheat Sheet

## Creation

```cpp
unordered_set<int> us;
```

---

## Insert

```cpp
us.insert(10);
```

---

## Size

```cpp
us.size();
```

---

## Empty

```cpp
us.empty();
```

---

## Clear

```cpp
us.clear();
```

---

## Find

```cpp
us.find(10);
```

---

## Count

```cpp
us.count(10);
```

---

## Erase by value

```cpp
us.erase(10);
```

---

## Erase by iterator

```cpp
auto it = us.find(10);

if (it != us.end())
{
    us.erase(it);
}
```

---

## Begin

```cpp
us.begin();
```

---

## End

```cpp
us.end();
```

---

## Constant begin

```cpp
us.cbegin();
```

---

## Constant end

```cpp
us.cend();
```

---

## Equal range

```cpp
us.equal_range(10);
```

---

## Swap

```cpp
us1.swap(us2);
```

---

## Bucket count

```cpp
us.bucket_count();
```

---

## Bucket of an element

```cpp
us.bucket(10);
```

---

## Bucket size

```cpp
us.bucket_size(bucketNumber);
```

---

## Load factor

```cpp
us.load_factor();
```

---

## Maximum load factor

```cpp
us.max_load_factor();
```

---

## Set maximum load factor

```cpp
us.max_load_factor(0.7);
```

---

## Reserve

```cpp
us.reserve(1000);
```

---

## Rehash

```cpp
us.rehash(100);
```

---

## Hash function

```cpp
us.hash_function();
```

---

## Equality function

```cpp
us.key_eq();
```

---

# 96. Functions NOT Available Like `set`

These are important to remember.

`unordered_set` does NOT provide:

```cpp
lower_bound()
```

```cpp
upper_bound()
```

```cpp
rbegin()
```

```cpp
rend()
```

and its iterator does not support:

```cpp
--it
```

or:

```cpp
it + 2
```

or:

```cpp
it - 2
```

---

# 97. Why `lower_bound()` Is Not Available

`lower_bound()` requires ordered data.

For:

```cpp
set<int>
```

we have:

```text
10 20 30 40 50
```

Therefore:

```cpp
lower_bound(25)
```

can find:

```text
30
```

But for:

```cpp
unordered_set<int>
```

there is no sorted sequence.

Therefore there is no meaningful standard `lower_bound()` operation.

---

# 98. Why `rbegin()` Is Not Available

Reverse traversal requires the ability to move backward.

A `set` iterator is bidirectional.

An `unordered_set` iterator is forward.

Therefore:

```cpp
set<int>::iterator
```

supports backward traversal.

But:

```cpp
unordered_set<int>::iterator
```

does not.

---

# 99. Complexity Table

| Operation         | Average Complexity |                        Worst Case |
| ----------------- | -----------------: | --------------------------------: |
| `insert()`        |             `O(1)` |                            `O(n)` |
| `find()`          |             `O(1)` |                            `O(n)` |
| `count()`         |             `O(1)` |                            `O(n)` |
| `erase(value)`    |             `O(1)` |                            `O(n)` |
| `erase(iterator)` |     Average `O(1)` | Depends on implementation/details |
| `size()`          |             `O(1)` |                            `O(1)` |
| `empty()`         |             `O(1)` |                            `O(1)` |
| `clear()`         |             `O(n)` |                            `O(n)` |
| `begin()`         |             `O(1)` |                            `O(1)` |
| `end()`           |             `O(1)` |                            `O(1)` |
| `bucket_count()`  |             `O(1)` |                            `O(1)` |
| `bucket()`        |     Average `O(1)` |                Depends on hashing |
| `bucket_size()`   |             `O(1)` |                            `O(1)` |
| Full iteration    |             `O(n)` |                            `O(n)` |

The important DSA point is:

> `unordered_set` provides average constant-time lookup, not guaranteed constant-time lookup.

---

# 100. Why Is `unordered_set` Fast?

Because it uses hashing.

Suppose we have:

```text
10
20
30
40
50
```

Instead of maintaining these in sorted tree order, a hash function is used to determine where elements belong in the hash table.

Conceptually:

```text
value
  |
  v
hash function
  |
  v
bucket index
  |
  v
bucket
```

This allows average constant-time lookup.

---

# 101. Collision

A collision occurs when multiple values are associated with the same bucket.

Conceptually:

```text
Hash(10) -> Bucket 2
Hash(20) -> Bucket 2
```

Both values end up associated with the same bucket.

The container handles collisions internally.

---

# 102. Worst Case

Although average lookup is:

```text
O(1)
```

the theoretical worst case can be:

```text
O(n)
```

if many elements end up in the same bucket or hashing becomes highly unfavorable.

This is why we should say:

```text
Average O(1)
```

instead of simply claiming:

```text
Always O(1)
```

---

# 103. Space Complexity

If an `unordered_set` stores `n` elements:

```text
Space Complexity = O(n)
```

Additional hash-table bucket memory is also used.

Therefore, compared with a simple array, an `unordered_set` can have additional memory overhead.

---

# 104. When Should You Use `unordered_set`?

Use `unordered_set` when:

- You need unique values.
- You need fast average lookup.
- You do not care about sorted order.
- You need membership checking.
- You are detecting duplicates.
- You are tracking visited nodes.
- You need average `O(1)` insert/find/erase.

---

# 105. When Should You NOT Use `unordered_set`?

Do not use it when:

- You need sorted order.
- You need `lower_bound()`.
- You need `upper_bound()`.
- You need reverse traversal.
- You need deterministic ordered iteration.
- You specifically need tree-based ordering.

In those situations, consider:

```cpp
set<int>
```

---

# 106. `set` or `unordered_set`?

## Use `set`

When you need:

```text
unique + sorted
```

Example:

```cpp
set<int> s;
```

---

## Use `unordered_set`

When you need:

```text
unique + fast average lookup
```

and sorting is not required.

Example:

```cpp
unordered_set<int> us;
```

---

# 107. Interview Question — What Is `unordered_set`?

Answer:

> `unordered_set` is an STL associative container that stores unique elements using a hash table. It does not maintain sorted order and provides average constant-time insertion, search, and deletion.

---

# 108. Interview Question — Is `unordered_set` Ordered?

No.

`unordered_set` does not guarantee any sorted or insertion order.

---

# 109. Interview Question — Does `unordered_set` Allow Duplicates?

No.

It stores unique elements.

---

# 110. Interview Question — What Is Average Complexity of `find()`?

Average:

```text
O(1)
```

Worst case:

```text
O(n)
```

---

# 111. Interview Question — What Is the Difference Between `set` and `unordered_set`?

### `set`

- Ordered.
- Sorted.
- Tree-based.
- `O(log n)` lookup.

### `unordered_set`

- Unordered.
- Hash-based.
- Average `O(1)` lookup.
- Worst-case `O(n)`.

---

# 112. Interview Question — Why Can't We Use `lower_bound()` on `unordered_set`?

Because `unordered_set` does not maintain sorted order.

`lower_bound()` depends on ordering.

---

# 113. Interview Question — Can We Modify an Element Through an `unordered_set` Iterator?

No.

Direct modification is not allowed.

Use:

```cpp
erase(oldValue);
insert(newValue);
```

instead.

---

# 114. Interview Question — Can We Iterate Backwards?

No, not with the standard `unordered_set` iterator.

It is a forward iterator.

Therefore:

```cpp
++it;
```

is supported.

But:

```cpp
--it;
```

is not.

---

# 115. Interview Question — Does `unordered_set` Have `rbegin()`?

No standard reverse iteration interface like `set::rbegin()` is provided for `unordered_set`.

---

# 116. Interview Question — What Does `find()` Return?

`find()` returns an iterator.

If found:

```cpp
it != us.end()
```

If not found:

```cpp
it == us.end()
```

---

# 117. Interview Question — What Does `count()` Return?

Because `unordered_set` stores unique elements:

```text
0 -> element absent
1 -> element present
```

---

# 118. Interview Question — What Is a Bucket?

A bucket is a position/group in the internal hash table where elements associated with a particular hash result are stored.

---

# 119. Interview Question — What Is Rehashing?

Rehashing is the process of reorganizing the hash table into a new bucket arrangement, usually when the current table needs more capacity according to its load-factor constraints.

---

# 120. Interview Question — What Is Load Factor?

Conceptually:

```text
load factor = number of elements / number of buckets
```

It indicates how full the hash table is relative to its bucket count.

---

# 121. Final Complete Revision Program

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    // ============================================================
    // CREATE unordered_set
    // ============================================================

    unordered_set<int> us;

    // ============================================================
    // INSERT
    // ============================================================

    us.insert(10);
    us.insert(20);
    us.insert(30);
    us.insert(40);
    us.insert(50);

    // Duplicate
    us.insert(30);

    // ============================================================
    // SIZE
    // ============================================================

    cout << "Size = "
         << us.size()
         << endl;

    // ============================================================
    // EMPTY
    // ============================================================

    if (us.empty())
    {
        cout << "Empty" << endl;
    }
    else
    {
        cout << "Not Empty" << endl;
    }

    // ============================================================
    // ITERATION
    // ============================================================

    cout << "\nElements:" << endl;

    for (auto it = us.begin();
         it != us.end();
         ++it)
    {
        cout << *it << endl;
    }

    // ============================================================
    // FIND
    // ============================================================

    auto it = us.find(30);

    if (it != us.end())
    {
        cout << "\n30 Found" << endl;
    }
    else
    {
        cout << "\n30 Not Found" << endl;
    }

    // ============================================================
    // COUNT
    // ============================================================

    if (us.count(40))
    {
        cout << "40 exists." << endl;
    }

    // ============================================================
    // ERASE BY VALUE
    // ============================================================

    us.erase(20);

    // ============================================================
    // ERASE BY ITERATOR
    // ============================================================

    auto eraseIt = us.find(30);

    if (eraseIt != us.end())
    {
        us.erase(eraseIt);
    }

    // ============================================================
    // ITERATE AFTER ERASE
    // ============================================================

    cout << "\nAfter erase:" << endl;

    for (const auto &x : us)
    {
        cout << x << endl;
    }

    // ============================================================
    // BUCKET INFORMATION
    // ============================================================

    cout << "\nBucket count = "
         << us.bucket_count()
         << endl;

    cout << "Load factor = "
         << us.load_factor()
         << endl;

    cout << "Maximum load factor = "
         << us.max_load_factor()
         << endl;

    // ============================================================
    // BUCKET OF AN ELEMENT
    // ============================================================

    if (us.count(40))
    {
        cout << "Bucket of 40 = "
             << us.bucket(40)
             << endl;
    }

    // ============================================================
    // CLEAR
    // ============================================================

    us.clear();

    cout << "\nAfter clear:" << endl;

    cout << "Size = "
         << us.size()
         << endl;

    if (us.empty())
    {
        cout << "unordered_set is Empty" << endl;
    }

    return 0;
}
```

---

# 122. Final `unordered_set` Cheat Sheet

```text
===============================================================
                    UNORDERED_SET CHEAT SHEET
===============================================================

HEADER:

    #include <unordered_set>


CREATE:

    unordered_set<int> us;


INSERT:

    us.insert(10);


DUPLICATES:

    us.insert(10);
    us.insert(10);

    Only one 10 exists.


SIZE:

    us.size();


EMPTY:

    us.empty();


CLEAR:

    us.clear();


FIND:

    auto it = us.find(10);


CHECK FIND:

    if (it != us.end())
    {
        cout << *it;
    }


COUNT:

    us.count(10);

    0 -> absent
    1 -> present


ERASE BY VALUE:

    us.erase(10);


ERASE BY ITERATOR:

    auto it = us.find(10);

    if (it != us.end())
    {
        us.erase(it);
    }


ITERATOR:

    auto it = us.begin();


END:

    us.end();


CURRENT VALUE:

    *it


MOVE FORWARD:

    ++it


MOVE BACKWARD:

    --it

    NOT SUPPORTED


REVERSE:

    rbegin()
    rend()

    NOT SUPPORTED


LOWER BOUND:

    lower_bound()

    NOT SUPPORTED


UPPER BOUND:

    upper_bound()

    NOT SUPPORTED


EQUAL RANGE:

    us.equal_range(10);


CONSTANT ITERATOR:

    us.cbegin();
    us.cend();


SWAP:

    us.swap(us2);


BUCKET COUNT:

    us.bucket_count();


BUCKET OF VALUE:

    us.bucket(10);


BUCKET SIZE:

    us.bucket_size(bucket);


LOAD FACTOR:

    us.load_factor();


MAX LOAD FACTOR:

    us.max_load_factor();


CHANGE MAX LOAD FACTOR:

    us.max_load_factor(0.7);


RESERVE:

    us.reserve(1000);


REHASH:

    us.rehash(100);


HASH FUNCTION:

    us.hash_function();


EQUALITY FUNCTION:

    us.key_eq();


ITERATION:

    for (auto it = us.begin();
         it != us.end();
         ++it)
    {
        cout << *it;
    }


RANGE LOOP:

    for (const auto &x : us)
    {
        cout << x;
    }


SAFE ERASE WHILE ITERATING:

    for (auto it = us.begin();
         it != us.end();)
    {
        if (condition)
        {
            it = us.erase(it);
        }
        else
        {
            ++it;
        }
    }


===============================================================
                      COMPLEXITY
===============================================================

insert:
    Average O(1)
    Worst O(n)

find:
    Average O(1)
    Worst O(n)

count:
    Average O(1)
    Worst O(n)

erase:
    Average O(1)
    Worst O(n)

size:
    O(1)

empty:
    O(1)

clear:
    O(n)

Full iteration:
    O(n)


===============================================================
                       GOLDEN RULE
===============================================================

set:

    UNIQUE + SORTED
    O(log n)

unordered_set:

    UNIQUE + UNORDERED
    Average O(1)


If you need:

    SORTED UNIQUE VALUES

use:

    set<int>


If you need:

    FAST AVERAGE LOOKUP
    + UNIQUE VALUES
    + NO SORTING REQUIREMENT

use:

    unordered_set<int>


Most important iterator:

    *it


Most important search pattern:

    auto it = us.find(x);

    if (it != us.end())
    {
        // found
    }


Most important membership pattern:

    if (us.count(x))
    {
        // exists
    }


Most important safe erase pattern:

    it = us.erase(it);


===============================================================
                           END
===============================================================
```
