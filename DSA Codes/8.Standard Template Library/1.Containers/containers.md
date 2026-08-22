# C++ STL Containers — Complete Detailed Guide

> **Language:** C++17 / C++20  
> **Topic:** C++ Standard Template Library Containers  
> **Focus:** Detailed explanations, syntax, operations, complexity, examples, common mistakes, and practical patterns.

---

# Table of Contents

1. What Are STL Containers?
2. Container Categories
3. `vector`
4. `array`
5. `deque`
6. `list`
7. `forward_list`
8. `stack`
9. `queue`
10. `priority_queue`
11. `set`
12. `multiset`
13. `unordered_set`
14. `map`
15. `multimap`
16. `unordered_map`
17. `unordered_multiset`
18. `unordered_multimap`
19. `pair`
20. `tuple`
21. `bitset`
22. `string`
23. Container Adaptors
24. Iterators
25. Iterator Categories
26. References, Pointers, and Iterators
27. `begin/end` and Reverse Iterators
28. `insert`, `erase`, and `emplace`
29. Erase Patterns
30. Custom Comparators
31. Container-Specific Functions
32. Choosing the Right Container
33. Iterator Invalidation
34. Complexity Cheat Sheet
35. Common Mistakes
36. Competitive Programming Templates

---

# 1. What Are STL Containers?

A **container** is an STL class used to store a collection of objects.

C++ STL provides containers for different requirements:

```text
Dynamic array        -> vector
Fixed-size array     -> array
Double-ended array   -> deque
Doubly linked list   -> list
Singly linked list   -> forward_list

Stack                -> stack
Queue                -> queue
Heap                 -> priority_queue

Sorted unique        -> set
Sorted duplicates    -> multiset
Hash unique          -> unordered_set

Sorted key-value     -> map
Sorted duplicate keys-> multimap
Hash key-value       -> unordered_map
```

The correct container depends on the operations your problem needs.

---

# 2. Container Categories

## Sequence Containers

```text
vector
array
deque
list
forward_list
```

## Ordered Associative Containers

```text
set
multiset
map
multimap
```

These maintain an ordering, normally implemented using balanced trees.

## Unordered Associative Containers

```text
unordered_set
unordered_multiset
unordered_map
unordered_multimap
```

These use hashing.

Average lookup/insertion/removal is usually `O(1)`.

## Container Adaptors

```text
stack
queue
priority_queue
```

These expose a restricted interface over an underlying container.

---

# 3. `vector`

`vector` is a dynamic array and is usually the first STL container you should reach for.

It provides:

- Fast random access
- Contiguous memory
- Dynamic size
- Fast insertion/removal at the end
- Excellent compatibility with STL algorithms

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (int x : v) {
        cout << x << ' ';
    }

    return 0;
}
```

Output:

```text
10 20 30
```

---

## 3.1 Creating a Vector

Empty:

```cpp
vector<int> v;
```

Five zero-initialized elements:

```cpp
vector<int> v(5);
```

Five elements initialized to `10`:

```cpp
vector<int> v(5, 10);
```

Initializer list:

```cpp
vector<int> v = {
    10,
    20,
    30,
    40
};
```

Copy:

```cpp
vector<int> a = {1, 2, 3};

vector<int> b = a;
```

---

## 3.2 Access

```cpp
vector<int> a = {
    10,
    20,
    30
};

cout << a[0] << '\n';
```

`operator[]` does not perform bounds checking.

```cpp
cout << a.at(0) << '\n';
```

`.at()` performs bounds checking and can throw `std::out_of_range`.

First and last:

```cpp
cout << a.front() << '\n';
cout << a.back() << '\n';
```

Do not call `front()` or `back()` on an empty vector.

---

## 3.3 `push_back`

```cpp
vector<int> a;

a.push_back(10);
a.push_back(20);
a.push_back(30);
```

Complexity:

```text
O(1) amortized
```

An individual insertion can be `O(n)` if reallocation is required.

---

## 3.4 `emplace_back`

```cpp
vector<pair<int, string>> users;

users.emplace_back(
    1,
    "Alice"
);
```

The pair is constructed directly at the end.

---

## 3.5 `pop_back`

```cpp
vector<int> a = {
    10,
    20,
    30
};

a.pop_back();
```

Result:

```text
10 20
```

Complexity:

```text
O(1)
```

---

## 3.6 `size`

```cpp
cout << a.size();
```

Typical loop:

```cpp
for (int i = 0;
     i < (int)a.size();
     ++i) {

    cout << a[i] << ' ';
}
```

---

## 3.7 `empty`

```cpp
if (a.empty()) {
    cout << "Vector is empty";
}
```

---

## 3.8 `clear`

```cpp
a.clear();
```

After this:

```text
size == 0
```

`clear()` removes elements. Do not rely on it as a guaranteed capacity-release operation.

---

## 3.9 `capacity`

```cpp
cout << a.capacity();
```

Important distinction:

```text
size
    Number of actual elements.

capacity
    Allocated storage currently available
    before another reallocation is needed.
```

Example:

```text
size = 5
capacity = 8
```

---

## 3.10 `reserve`

Use `reserve()` when you know approximately how many elements will be inserted.

```cpp
vector<int> a;

a.reserve(1000000);

for (int i = 0;
     i < 1000000;
     ++i) {

    a.push_back(i);
}
```

Important:

```cpp
a.reserve(100);
```

does NOT create 100 elements.

```cpp
cout << a.size();
// 0
```

It changes capacity.

---

## 3.11 `resize`

```cpp
vector<int> a = {
    1,
    2,
    3
};

a.resize(5);
```

Result:

```text
1 2 3 0 0
```

With a value:

```cpp
a.resize(
    7,
    100
);
```

---

## 3.12 `insert`

```cpp
vector<int> a = {
    10,
    20,
    30
};

a.insert(
    a.begin() + 1,
    15
);
```

Result:

```text
10 15 20 30
```

Middle insertion is generally `O(n)` because elements may need to move.

---

## 3.13 Insert Multiple Values

```cpp
a.insert(
    a.begin(),
    3,
    100
);
```

Adds three copies of `100`.

---

## 3.14 Insert Another Range

```cpp
vector<int> b = {
    7,
    8,
    9
};

a.insert(
    a.end(),
    b.begin(),
    b.end()
);
```

---

## 3.15 Erase One Element

```cpp
a.erase(
    a.begin() + 2
);
```

Middle erase is generally `O(n)`.

---

## 3.16 Erase a Range

```cpp
a.erase(
    a.begin() + 1,
    a.begin() + 4
);
```

Ranges use:

```text
[first, last)
```

So `first` is included and `last` is excluded.

---

## 3.17 Vector Iteration

Range-based:

```cpp
for (int x : a) {
    cout << x << ' ';
}
```

Modify through reference:

```cpp
for (int& x : a) {
    x *= 2;
}
```

Read-only:

```cpp
for (const int& x : a) {
    cout << x << ' ';
}
```

Iterator:

```cpp
for (
    auto it = a.begin();
    it != a.end();
    ++it
) {
    cout << *it << ' ';
}
```

Reverse:

```cpp
for (
    auto it = a.rbegin();
    it != a.rend();
    ++it
) {
    cout << *it << ' ';
}
```

---

## 3.18 Vector Complexity

| Operation     |     Complexity |
| ------------- | -------------: |
| Random access |           O(1) |
| `front`       |           O(1) |
| `back`        |           O(1) |
| `push_back`   | O(1) amortized |
| `pop_back`    |           O(1) |
| Insert front  |           O(n) |
| Insert middle |           O(n) |
| Erase front   |           O(n) |
| Erase middle  |           O(n) |
| `size`        |           O(1) |

---

# 4. `array`

`std::array` is a fixed-size STL container.

```cpp
array<int, 5> a = {
    1,
    2,
    3,
    4,
    5
};
```

The size is part of the type:

```cpp
array<int, 5>
```

and:

```cpp
array<int, 10>
```

are different types.

---

## 4.1 Access

```cpp
cout << a[0] << '\n';
cout << a.at(0) << '\n';

cout << a.front() << '\n';
cout << a.back() << '\n';
```

---

## 4.2 Size

```cpp
cout << a.size();
```

For `array<int, 5>`:

```text
5
```

---

## 4.3 Fill

```cpp
a.fill(100);
```

Result:

```text
100 100 100 100 100
```

---

## 4.4 Swap

```cpp
array<int, 3> a = {
    1,
    2,
    3
};

array<int, 3> b = {
    4,
    5,
    6
};

a.swap(b);
```

---

## 4.5 When to Use `array`

Use `std::array` when:

- Size is known at compile time.
- You want STL compatibility.
- Dynamic resizing is unnecessary.

---

# 5. `deque`

`deque` means **double-ended queue**.

It supports efficient insertion and removal at both ends.

```cpp
deque<int> dq;

dq.push_back(10);
dq.push_front(20);

cout << dq.front() << '\n';
cout << dq.back() << '\n';
```

---

## 5.1 Operations

```cpp
dq.push_back(30);
dq.push_front(40);

dq.pop_back();
dq.pop_front();
```

Random access:

```cpp
cout << dq[0];
cout << dq.at(0);
```

---

## 5.2 Complexity

Typical:

```text
Random access: O(1)
push_front:    O(1)
push_back:     O(1)
pop_front:     O(1)
pop_back:      O(1)
```

Middle operations are generally linear.

---

## 5.3 When to Use

Use `deque` when you frequently need:

```text
push_front
pop_front
push_back
pop_back
```

---

# 6. `list`

`std::list` is a doubly linked list.

A node conceptually stores:

```text
previous pointer
value
next pointer
```

Declaration:

```cpp
list<int> li;
```

---

## 6.1 Insert at Ends

```cpp
li.push_back(10);
li.push_front(20);
```

---

## 6.2 Insert at Iterator

```cpp
auto it = li.begin();

++it;

li.insert(
    it,
    15
);
```

Insertion at a known position is `O(1)` after obtaining the iterator.

---

## 6.3 Erase

```cpp
auto it = li.begin();

++it;

li.erase(it);
```

Known-position erase is `O(1)`.

---

## 6.4 No Random Access

This is invalid:

```cpp
li[3];
```

Unlike vector, a list does not support random access.

---

## 6.5 List Sort

Do not use:

```cpp
sort(
    li.begin(),
    li.end()
);
```

because list iterators are not random-access iterators.

Use:

```cpp
li.sort();
```

Descending:

```cpp
li.sort(
    greater<int>()
);
```

---

## 6.6 `remove`

```cpp
li.remove(10);
```

Removes all elements equal to `10`.

---

## 6.7 `remove_if`

```cpp
li.remove_if(
    [](int x) {
        return x % 2 == 0;
    }
);
```

Removes all even values.

---

## 6.8 `unique`

```cpp
list<int> li = {
    1,
    1,
    2,
    2,
    2,
    3
};

li.unique();
```

Result:

```text
1 2 3
```

Important: `unique()` only removes consecutive duplicates.

To remove all duplicates:

```cpp
li.sort();
li.unique();
```

---

## 6.9 `splice`

Transfers nodes between lists.

```cpp
list<int> a = {
    1,
    2,
    3
};

list<int> b = {
    4,
    5
};

a.splice(
    a.end(),
    b
);
```

Now:

```text
a = 1 2 3 4 5
b = empty
```

---

## 6.10 List Complexity

| Operation                | Complexity |
| ------------------------ | ---------: |
| Access nth element       |       O(n) |
| Insert at known iterator |       O(1) |
| Erase at known iterator  |       O(1) |
| Push front               |       O(1) |
| Push back                |       O(1) |
| Pop front                |       O(1) |
| Pop back                 |       O(1) |
| Sort                     | O(n log n) |

---

# 7. `forward_list`

`forward_list` is a singly linked list.

```cpp
forward_list<int> fl;

fl.push_front(10);
fl.push_front(20);
fl.push_front(30);
```

Result:

```text
30 20 10
```

It only supports forward traversal.

---

## 7.1 Important Differences

No:

```cpp
fl.back();
```

No normal:

```cpp
fl.push_back();
```

It has:

```cpp
before_begin()
insert_after()
erase_after()
```

---

## 7.2 `insert_after`

```cpp
auto it = fl.begin();

fl.insert_after(
    it,
    50
);
```

---

## 7.3 `erase_after`

```cpp
auto it = fl.begin();

fl.erase_after(it);
```

---

## 7.4 `before_begin`

```cpp
auto it =
    fl.before_begin();

fl.insert_after(
    it,
    100
);
```

This inserts at the beginning.

---

# 8. `stack`

`stack` follows:

```text
LIFO
Last In, First Out
```

```cpp
stack<int> st;

st.push(10);
st.push(20);
st.push(30);

cout << st.top() << '\n';
// 30

st.pop();

cout << st.top() << '\n';
// 20
```

Operations:

```cpp
st.push(x);
st.pop();
st.top();
st.empty();
st.size();
```

Complexity:

```text
push:  O(1)
pop:   O(1)
top:   O(1)
size:  O(1)
empty: O(1)
```

Default underlying container is usually `deque`.

You can use vector:

```cpp
stack<
    int,
    vector<int>
> st;
```

---

# 9. `queue`

`queue` follows:

```text
FIFO
First In, First Out
```

```cpp
queue<int> q;

q.push(10);
q.push(20);
q.push(30);

cout << q.front() << '\n';
// 10

cout << q.back() << '\n';
// 30

q.pop();
```

Operations:

```cpp
q.push(x);
q.pop();
q.front();
q.back();
q.empty();
q.size();
```

All normal end operations are `O(1)`.

---

# 10. `priority_queue`

`priority_queue` provides heap functionality.

Default:

```cpp
priority_queue<int> pq;
```

is a max heap.

```cpp
pq.push(10);
pq.push(50);
pq.push(20);

cout << pq.top();
// 50
```

---

## 10.1 Min Heap

```cpp
priority_queue<
    int,
    vector<int>,
    greater<int>
> pq;
```

Now:

```cpp
pq.push(10);
pq.push(50);
pq.push(20);

cout << pq.top();
// 10
```

---

## 10.2 Pair Priority Queue

```cpp
priority_queue<
    pair<int, int>
> pq;

pq.push({10, 2});
pq.push({20, 1});
pq.push({20, 5});
```

Top:

```text
{20, 5}
```

Pairs use lexicographical comparison.

---

## 10.3 Min Heap of Pairs

```cpp
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;
```

---

## 10.4 Complexity

```text
push: O(log n)
pop:  O(log n)
top:  O(1)
```

---

# 11. `set`

`set` stores unique values in sorted order.

```cpp
set<int> s;

s.insert(30);
s.insert(10);
s.insert(20);
s.insert(20);
```

Contents:

```text
10 20 30
```

---

## 11.1 Find

```cpp
auto it = s.find(20);

if (it != s.end()) {
    cout << "Found";
}
```

Complexity:

```text
O(log n)
```

---

## 11.2 Count

```cpp
if (s.count(20)) {
    cout << "Exists";
}
```

For `set`, count is `0` or `1`.

---

## 11.3 Erase

By value:

```cpp
s.erase(20);
```

By iterator:

```cpp
auto it = s.find(20);

if (it != s.end()) {
    s.erase(it);
}
```

---

## 11.4 Lower Bound

```cpp
auto it =
    s.lower_bound(25);
```

Returns first element:

```text
>= 25
```

---

## 11.5 Upper Bound

```cpp
auto it =
    s.upper_bound(25);
```

Returns first element:

```text
> 25
```

---

## 11.6 First / Last

```cpp
if (!s.empty()) {
    cout << *s.begin();
    cout << *s.rbegin();
}
```

---

# 12. `multiset`

`multiset` is a sorted container that allows duplicates.

```cpp
multiset<int> ms;

ms.insert(10);
ms.insert(10);
ms.insert(20);
```

Contents:

```text
10 10 20
```

---

## 12.1 Count

```cpp
cout << ms.count(10);
// 2
```

---

## 12.2 Important `erase` Difference

This:

```cpp
ms.erase(10);
```

removes all occurrences of `10`.

To remove only one:

```cpp
auto it =
    ms.find(10);

if (it != ms.end()) {
    ms.erase(it);
}
```

This is an important interview/competitive-programming detail.

---

# 13. `unordered_set`

`unordered_set` stores unique values using hashing.

```cpp
unordered_set<int> s;

s.insert(10);
s.insert(20);
s.insert(10);
```

Only one `10` is stored.

Unlike `set`, it does not maintain sorted order.

---

## 13.1 Complexity

Average:

```text
insert: O(1)
find:   O(1)
erase:  O(1)
```

Worst case can be:

```text
O(n)
```

---

## 13.2 Duplicate Detection

```cpp
unordered_set<int> seen;

for (int x : a) {

    if (seen.count(x)) {
        cout << "Duplicate found";
        break;
    }

    seen.insert(x);
}
```

---

# 14. `map`

`map` stores key-value pairs sorted by key.

```cpp
map<string, int> marks;

marks["Alice"] = 95;
marks["Bob"] = 87;
marks["Charlie"] = 92;
```

Iteration is sorted by key:

```cpp
for (
    const auto& [name, mark]
    : marks
) {
    cout << name
         << ' '
         << mark
         << '\n';
}
```

---

## 14.1 `operator[]`

```cpp
map<string, int> mp;

mp["Alice"] = 100;
```

Important:

```cpp
cout << mp["Bob"];
```

If `Bob` does not exist, `operator[]` inserts it with default value `0`.

If you only want to check existence:

```cpp
if (mp.find("Bob") != mp.end()) {
    // Exists.
}
```

---

## 14.2 `find`

```cpp
auto it =
    mp.find("Alice");

if (it != mp.end()) {
    cout << it->second;
}
```

---

## 14.3 `count`

```cpp
if (mp.count("Alice")) {
    cout << "Exists";
}
```

---

## 14.4 `insert`

```cpp
mp.insert({
    "David",
    90
});
```

---

## 14.5 `emplace`

```cpp
mp.emplace(
    "Eve",
    88
);
```

---

## 14.6 `lower_bound` / `upper_bound`

```cpp
auto first =
    mp.lower_bound("Bob");

auto after =
    mp.upper_bound("Bob");
```

---

# 15. `multimap`

`multimap` allows duplicate keys.

```cpp
multimap<string, int> mm;

mm.insert({
    "Alice",
    90
});

mm.insert({
    "Alice",
    95
});
```

Both entries exist.

---

## 15.1 `equal_range`

```cpp
auto [first, last] =
    mm.equal_range("Alice");

for (
    auto it = first;
    it != last;
    ++it
) {
    cout << it->second << '\n';
}
```

---

# 16. `unordered_map`

`unordered_map` is a hash-table-based key-value container.

Frequency counting:

```cpp
unordered_map<int, int> freq;

for (int x : a) {
    ++freq[x];
}
```

---

## 16.1 Complexity

Average:

```text
insert: O(1)
find:   O(1)
erase:  O(1)
```

Worst case:

```text
O(n)
```

---

## 16.2 `reserve`

```cpp
unordered_map<int, int> mp;

mp.reserve(100000);
```

Useful when many entries are expected because it can reduce repeated rehashing.

---

## 16.3 `operator[]` Side Effect

```cpp
unordered_map<int, int> mp;

cout << mp[100];
```

This inserts `100` with value `0`.

For a pure existence check:

```cpp
if (mp.find(100) != mp.end()) {
    // Exists.
}
```

C++20:

```cpp
if (mp.contains(100)) {
    // Exists.
}
```

---

# 17. `unordered_multiset`

Allows duplicate values without sorting.

```cpp
unordered_multiset<int> ms;

ms.insert(10);
ms.insert(10);
ms.insert(20);
```

Average operations are usually `O(1)`.

---

# 18. `unordered_multimap`

Allows duplicate keys without sorted ordering.

```cpp
unordered_multimap<string, int> mm;

mm.insert({
    "Alice",
    90
});

mm.insert({
    "Alice",
    95
});
```

---

# 19. `pair`

`pair` stores two values.

```cpp
pair<int, string> p = {
    10,
    "Alice"
};

cout << p.first << '\n';
cout << p.second << '\n';
```

Useful in:

```text
vector<pair<int,int>>
map
priority_queue
graph edges
coordinates
```

---

## 19.1 Structured Binding

C++17:

```cpp
auto [id, name] = p;

cout << id << ' ';
cout << name;
```

---

# 20. `tuple`

`tuple` stores multiple values.

```cpp
tuple<int, string, double> student = {
    101,
    "Alice",
    95.5
};
```

Access:

```cpp
cout << get<0>(student);
cout << get<1>(student);
cout << get<2>(student);
```

Structured binding:

```cpp
auto [id, name, score] =
    student;
```

---

# 21. `bitset`

`bitset<N>` stores a fixed number of bits.

```cpp
bitset<8> bits;

bits[0] = 1;
bits[3] = 1;

cout << bits << '\n';
```

---

## 21.1 Initialize from String

```cpp
bitset<8> bits(
    string("10101010")
);
```

---

## 21.2 Useful Operations

```cpp
bits.set();
bits.reset();
bits.flip();

bits.set(2);
bits.reset(2);
bits.flip(2);
```

Check bit:

```cpp
if (bits.test(2)) {
    // Bit 2 is set.
}
```

Count:

```cpp
cout << bits.count();
```

Check whether any bit is set:

```cpp
bits.any();
```

Check whether no bits are set:

```cpp
bits.none();
```

Check whether all bits are set:

```cpp
bits.all();
```

---

# 22. `string`

`std::string` is an STL container-like sequence type specialized for characters.

```cpp
string s = "hello";
```

---

## 22.1 Access

```cpp
cout << s[0];
cout << s.front();
cout << s.back();
```

---

## 22.2 Append

```cpp
s += " world";
```

or:

```cpp
s.append(" world");
```

---

## 22.3 Add Character

```cpp
s.push_back('!');
```

---

## 22.4 Remove Last Character

```cpp
s.pop_back();
```

---

## 22.5 Size

```cpp
cout << s.size();
```

or:

```cpp
cout << s.length();
```

---

## 22.6 Find

```cpp
size_t pos =
    s.find("world");

if (pos != string::npos) {
    cout << "Found at "
         << pos;
}
```

---

## 22.7 Substring

```cpp
string part =
    s.substr(
        2,
        5
    );
```

Parameters:

```text
starting position
number of characters
```

---

# 23. Container Adaptors

Main adaptors:

```text
stack
queue
priority_queue
```

They do not expose the complete interface of their underlying container.

---

# 24. Stack Underlying Container

Default:

```cpp
stack<int> st;
```

Conceptually uses:

```cpp
deque<int>
```

You can specify:

```cpp
stack<
    int,
    vector<int>
> st;
```

---

# 25. Queue Underlying Container

Default:

```cpp
queue<int> q;
```

uses a deque-like underlying container.

Possible:

```cpp
queue<
    int,
    list<int>
> q;
```

---

# 26. Priority Queue Underlying Container

Default:

```cpp
priority_queue<int> pq;
```

uses `vector` plus heap operations.

---

# 27. Iterators

An iterator provides a common way to traverse a container.

```cpp
vector<int> a = {
    10,
    20,
    30
};

auto it =
    a.begin();

cout << *it;
```

Dereferencing:

```cpp
*it
```

returns the element referred to by the iterator.

---

# 28. `begin()` and `end()`

```cpp
auto first =
    a.begin();

auto last =
    a.end();
```

Conceptually:

```text
begin -> first element
end   -> one position after last element
```

Never do:

```cpp
*a.end();
```

---

# 29. Reverse Iterators

```cpp
for (
    auto it = a.rbegin();
    it != a.rend();
    ++it
) {
    cout << *it << ' ';
}
```

`rbegin()` starts from the last element.

---

# 30. `cbegin()` and `cend()`

Constant iterators:

```cpp
auto it =
    a.cbegin();
```

You cannot modify elements through a const iterator.

---

# 31. Iterator Categories

## Input Iterator

Can read sequentially.

## Output Iterator

Can write sequentially.

## Forward Iterator

Can move forward repeatedly.

Example:

```text
forward_list
```

## Bidirectional Iterator

Can move both directions.

Examples:

```text
list
set
map
```

## Random Access Iterator

Supports arithmetic and jumping.

Examples:

```text
vector
array
deque
```

## Contiguous Iterator

Provides contiguous storage guarantees.

Examples:

```text
vector
array
```

---

# 32. Why Iterator Category Matters

For vector:

```cpp
auto it =
    a.begin();

it += 5;
```

This is constant time.

For a list:

```cpp
auto it =
    li.begin();

advance(
    it,
    5
);
```

The traversal is linear because list iterators are not random-access iterators.

---

# 33. `distance`

```cpp
auto it =
    find(
        a.begin(),
        a.end(),
        30
    );

if (it != a.end()) {

    cout <<
        distance(
            a.begin(),
            it
        );
}
```

For random-access iterators, `distance` is `O(1)`.

For linked-list iterators, it is `O(n)`.

---

# 34. `advance`

```cpp
auto it =
    a.begin();

advance(
    it,
    3
);

cout << *it;
```

Moves an iterator forward according to its iterator category.

---

# 35. `next` and `prev`

```cpp
auto it =
    next(
        a.begin(),
        3
);
```

Returns an advanced iterator without modifying the original.

```cpp
auto it2 =
    prev(
        a.end(),
        2
);
```

---

# 36. `insert` vs `emplace`

`insert` generally receives an object/value:

```cpp
set<pair<int, string>> s;

s.insert({
    1,
    "Alice"
});
```

`emplace` constructs it from arguments:

```cpp
s.emplace(
    1,
    "Alice"
);
```

For simple primitive values, do not obsess over the difference.

---

# 37. Erase While Iterating

Correct pattern:

```cpp
for (
    auto it = s.begin();
    it != s.end();
) {

    if (*it % 2 == 0) {

        it = s.erase(it);

    } else {

        ++it;
    }
}
```

Why?

Because erasing the current element invalidates the iterator referring to that element. The returned iterator points to the next valid position.

---

# 38. Vector Erase-Remove Idiom

```cpp
vector<int> a = {
    1,
    2,
    3,
    2,
    4,
    2
};

a.erase(
    remove(
        a.begin(),
        a.end(),
        2
    ),
    a.end()
);
```

Result:

```text
1 3 4
```

---

# 39. Remove by Condition

```cpp
a.erase(
    remove_if(
        a.begin(),
        a.end(),
        [](int x) {
            return x % 2 == 0;
        }
    ),
    a.end()
);
```

Removes all even values.

---

# 40. Remove Duplicates from Vector

```cpp
sort(
    a.begin(),
    a.end()
);

a.erase(
    unique(
        a.begin(),
        a.end()
    ),
    a.end()
);
```

Important:

```text
unique()
    Does not shrink the vector itself.

erase()
    Actually removes the unwanted tail.
```

---

# 41. Custom Comparator for `set`

Descending set:

```cpp
set<
    int,
    greater<int>
> s;
```

Contents:

```text
30 20 10
```

---

# 42. Custom Comparator for `map`

```cpp
map<
    int,
    string,
    greater<int>
> mp;
```

Keys are sorted descending.

---

# 43. Custom Comparator for `priority_queue`

```cpp
using P =
    pair<int, int>;

priority_queue<
    P,
    vector<P>,
    greater<P>
> pq;
```

This creates a min heap using pair comparison.

---

# 44. Struct as Set Key

```cpp
struct Student {

    int id;
    string name;

    bool operator<(
        const Student& other
    ) const {

        if (id != other.id) {
            return id < other.id;
        }

        return name < other.name;
    }
};
```

Then:

```cpp
set<Student> students;
```

---

# 45. Lambda Comparator

```cpp
sort(
    students.begin(),
    students.end(),
    [](const Student& a,
       const Student& b) {

        return a.id < b.id;
    }
);
```

---

# 46. Vector of Pairs

Very common in competitive programming:

```cpp
vector<pair<int, int>> points;

points.push_back({
    10,
    20
});

points.emplace_back(
    30,
    40
);
```

Default sort:

```cpp
sort(
    points.begin(),
    points.end()
);
```

Pairs compare:

```text
first first
then second
```

---

# 47. Vector of Vectors

Matrix:

```cpp
vector<vector<int>> matrix(
    5,
    vector<int>(5, 0)
);
```

Access:

```cpp
matrix[2][3] = 100;
```

---

# 48. Jagged Vector

Different rows can have different sizes:

```cpp
vector<vector<int>> graph(5);

graph[0].push_back(1);
graph[0].push_back(2);

graph[1].push_back(3);
```

This is a standard adjacency-list representation.

---

# 49. Vector of Strings

```cpp
vector<string> words = {
    "apple",
    "banana",
    "orange"
};
```

Grid:

```cpp
vector<string> grid(
    n,
    string(m, '.')
);
```

---

# 50. Passing Containers to Functions

Read-only parameter:

```cpp
void print(
    const vector<int>& a
) {
    for (int x : a) {
        cout << x << ' ';
    }
}
```

Why `const&`?

```text
const
    Function cannot modify the vector.

&
    No copy is made.
```

Modify:

```cpp
void sortArray(
    vector<int>& a
) {
    sort(
        a.begin(),
        a.end()
    );
}
```

---

# 51. Returning Containers

Modern C++ handles return-by-value efficiently:

```cpp
vector<int> createVector() {

    vector<int> result = {
        1,
        2,
        3
    };

    return result;
}
```

Return-value optimization and move semantics make this practical.

---

# 52. `const` Container

```cpp
const vector<int> a = {
    1,
    2,
    3
};
```

This is invalid:

```cpp
a.push_back(4);
```

Reading is allowed:

```cpp
cout << a[0];
```

---

# 53. `map` vs `unordered_map`

## `map`

```text
Sorted keys
O(log n)
lower_bound / upper_bound
Ordered iteration
```

## `unordered_map`

```text
No sorted order
Average O(1)
Hash table
Possible worst-case O(n)
```

Choose according to the required operations.

---

# 54. `set` vs `unordered_set`

## `set`

```text
Unique
Sorted
O(log n)
```

## `unordered_set`

```text
Unique
Unordered
Average O(1)
```

---

# 55. `vector` vs `list`

`vector` generally has:

```text
Contiguous memory
Fast random access
Excellent cache locality
Fast iteration
```

`list` provides:

```text
Node-based storage
O(1) insertion/erase at known position
No random access
```

Do not choose `list` merely because insertion is `O(1)`. Finding the position can still cost `O(n)`.

---

# 56. `vector` vs `deque`

Use `vector` when:

```text
Random access
Mostly push_back
Contiguous storage
```

Use `deque` when:

```text
Frequent operations at both ends
```

---

# 57. `array` vs `vector`

Use:

```cpp
array<int, 100>
```

when the size is fixed and known at compile time.

Use:

```cpp
vector<int>
```

when the size changes at runtime.

---

# 58. Container Invalidation

A very important advanced STL topic is **iterator/reference/pointer invalidation**.

An iterator becomes invalid when an operation changes the storage or removes the element it refers to.

---

## 58.1 Vector Reallocation

```cpp
vector<int> v;

v.reserve(2);

v.push_back(1);
v.push_back(2);

// The next push may cause reallocation.
v.push_back(3);
```

If reallocation happens, pointers/references/iterators to old elements are invalidated.

This is why storing an iterator and then modifying a vector requires care.

---

## 58.2 `reserve` Helps

```cpp
vector<int> v;

v.reserve(100000);

for (int i = 0;
     i < 100000;
     ++i) {

    v.push_back(i);
}
```

If capacity is sufficient, further insertions do not need to reallocate the vector.

---

## 58.3 Ordered Associative Containers

For:

```text
set
map
multiset
multimap
```

inserting another element generally does not invalidate existing iterators.

Erasing an element invalidates iterators referring to the erased element.

---

## 58.4 Unordered Containers

For:

```text
unordered_set
unordered_map
```

rehashing can invalidate iterators.

If many elements are expected:

```cpp
mp.reserve(
    expectedSize
);
```

can reduce unnecessary rehashes.

---

# 59. `unordered_map` Load Factor

```cpp
unordered_map<int, int> mp;

cout << mp.load_factor();
```

Maximum load factor:

```cpp
cout <<
    mp.max_load_factor();
```

Can be adjusted:

```cpp
mp.max_load_factor(
    0.7
);
```

Normal code usually does not need manual tuning.

---

# 60. `bucket_count`

```cpp
cout <<
    mp.bucket_count();
```

Shows the current number of buckets.

Useful mainly for understanding/debugging hash-table behavior.

---

# 61. `extract`

C++17 node extraction:

```cpp
set<int> s = {
    1,
    2,
    3
};

auto node =
    s.extract(2);
```

Now `2` is removed from the set and stored in the node handle.

Node handles can be moved into compatible associative containers without copying the stored value in the normal way.

---

# 62. `merge`

```cpp
set<int> a = {
    1,
    2
};

set<int> b = {
    2,
    3,
    4
};

a.merge(b);
```

Afterward:

```text
a = 1 2 3 4
b = 2
```

The duplicate `2` remains in `b` because `a` already contains `2`.

---

# 63. `contains`

C++20:

```cpp
set<int> s = {
    1,
    2,
    3
};

if (s.contains(2)) {
    cout << "Found";
}
```

For map:

```cpp
if (mp.contains(100)) {
    cout << "Key exists";
}
```

---

# 64. `try_emplace`

C++17:

```cpp
map<int, string> mp;

mp.try_emplace(
    1,
    "Alice"
);
```

Useful when you want to construct the mapped value only if insertion actually happens.

---

# 65. `insert_or_assign`

C++17:

```cpp
map<int, string> mp;

mp.insert_or_assign(
    1,
    "Alice"
);
```

If key exists:

```text
replace value
```

Otherwise:

```text
insert new key/value
```

---

# 66. `operator[]` vs `at()`

For maps:

```cpp
mp[key]
```

may insert the key if it does not exist.

Whereas:

```cpp
mp.at(key)
```

does not insert.

If key is absent, `at()` throws `std::out_of_range`.

For simple existence checks, prefer:

```cpp
mp.find(key)
```

or C++20:

```cpp
mp.contains(key)
```

---

# 67. Memory Characteristics

Asymptotic complexity is not everything.

## Vector

```text
Contiguous
Excellent cache locality
Low per-element overhead
```

## List

```text
Separate nodes
Pointer overhead
Poorer cache locality
```

## Set/Map

```text
Tree nodes
Pointers + balancing information
```

## Unordered Map/Set

```text
Hash buckets
Nodes
Potential rehashing
```

This is why a vector can often outperform a linked list even when both solutions look similar asymptotically.

---

# 68. Frequency Counting

```cpp
unordered_map<int, int> freq;

for (int x : a) {
    ++freq[x];
}

for (
    auto [value, count]
    : freq
) {
    cout << value
         << " -> "
         << count
         << '\n';
}
```

If sorted keys are required:

```cpp
map<int, int> freq;

for (int x : a) {
    ++freq[x];
}
```

---

# 69. Unique Elements

Using `set`:

```cpp
set<int> uniqueValues(
    a.begin(),
    a.end()
);
```

---

# 70. Unique Elements While Preserving First Appearance

```cpp
unordered_set<int> seen;

vector<int> result;

for (int x : a) {

    if (!seen.count(x)) {

        seen.insert(x);

        result.push_back(x);
    }
}
```

The resulting vector preserves first occurrence order.

---

# 71. Top K Elements

Use a min heap:

```cpp
priority_queue<
    int,
    vector<int>,
    greater<int>
> minHeap;

for (int x : a) {

    minHeap.push(x);

    if ((int)minHeap.size() > k) {
        minHeap.pop();
    }
}
```

Complexity:

```text
O(n log k)
```

---

# 72. Sliding Window Maximum with Deque

```cpp
deque<int> dq;

for (int i = 0;
     i < (int)a.size();
     ++i) {

    // Remove indices that are outside
    // the current window.
    while (
        !dq.empty() &&
        dq.front() <= i - k
    ) {
        dq.pop_front();
    }

    // Remove smaller values from the back.
    while (
        !dq.empty() &&
        a[dq.back()] <= a[i]
    ) {
        dq.pop_back();
    }

    dq.push_back(i);

    // The front is the maximum.
    if (i >= k - 1) {
        cout <<
            a[dq.front()]
            << ' ';
    }
}
```

Complexity:

```text
O(n)
```

---

# 73. BFS Using Queue

```cpp
queue<int> q;

vector<bool> visited(n, false);

q.push(start);
visited[start] = true;

while (!q.empty()) {

    int node = q.front();
    q.pop();

    cout << node << ' ';

    for (int neighbor : graph[node]) {

        if (!visited[neighbor]) {

            visited[neighbor] = true;

            q.push(neighbor);
        }
    }
}
```

---

# 74. DFS Using Stack

```cpp
stack<int> st;

vector<bool> visited(n, false);

st.push(start);

while (!st.empty()) {

    int node = st.top();
    st.pop();

    if (visited[node]) {
        continue;
    }

    visited[node] = true;

    cout << node << ' ';

    for (int neighbor : graph[node]) {

        if (!visited[neighbor]) {
            st.push(neighbor);
        }
    }
}
```

---

# 75. Dijkstra Priority Queue

```cpp
using State =
    pair<long long, int>;

priority_queue<
    State,
    vector<State>,
    greater<State>
> pq;

pq.push({
    0,
    source
});

while (!pq.empty()) {

    auto [distance, node] =
        pq.top();

    pq.pop();

    // Process state.
}
```

This is the standard min-heap structure for Dijkstra.

---

# 76. Nested Containers

STL containers can be combined.

```cpp
vector<set<int>> graph;

map<int, vector<int>> groups;

unordered_map<
    string,
    set<int>
> data;

vector<
    unordered_map<int, int>
> tables;
```

---

# 77. Grid Container

```cpp
int n, m;

cin >> n >> m;

vector<string> grid(
    n,
    string(m, '.')
);
```

Input:

```cpp
for (string& row : grid) {
    cin >> row;
}
```

Access:

```cpp
char cell =
    grid[r][c];
```

---

# 78. Adjacency List

Unweighted graph:

```cpp
vector<vector<int>> graph(n);

graph[u].push_back(v);
graph[v].push_back(u);
```

Weighted graph:

```cpp
vector<
    vector<pair<int, int>>
> graph(n);

graph[u].push_back({
    v,
    weight
});

graph[v].push_back({
    u,
    weight
});
```

---

# 79. Passing STL Containers Efficiently

Read-only:

```cpp
void solve(
    const vector<int>& a
) {
    // No copy.
    // Cannot modify a.
}
```

Modify:

```cpp
void solve(
    vector<int>& a
) {
    a.push_back(100);
}
```

Move when ownership transfer is intended:

```cpp
vector<int> makeVector();

vector<int> result =
    makeVector();
```

Modern C++ handles return values efficiently.

---

# 80. Common Mistakes

## Mistake 1: Dereferencing `end()`

Wrong:

```cpp
cout << *v.end();
```

Correct:

```cpp
cout << *v.begin();
```

only when the container is non-empty.

---

## Mistake 2: Using `[]` on `map` for existence

This:

```cpp
if (mp[x]) {
    // ...
}
```

can insert `x`.

Prefer:

```cpp
if (mp.find(x) != mp.end()) {
    // ...
}
```

or C++20:

```cpp
if (mp.contains(x)) {
    // ...
}
```

---

## Mistake 3: `multiset::erase(value)`

This:

```cpp
ms.erase(x);
```

removes all copies of `x`.

For one copy:

```cpp
auto it = ms.find(x);

if (it != ms.end()) {
    ms.erase(it);
}
```

---

## Mistake 4: Forgetting `erase` after `unique`

Wrong:

```cpp
unique(
    a.begin(),
    a.end()
);
```

Correct:

```cpp
a.erase(
    unique(
        a.begin(),
        a.end()
    ),
    a.end()
);
```

usually after sorting if all duplicates need removal.

---

## Mistake 5: Using `sort` directly on `list`

Wrong:

```cpp
sort(
    li.begin(),
    li.end()
);
```

Correct:

```cpp
li.sort();
```

---

## Mistake 6: Assuming `unordered_map` Is Sorted

It is not.

If sorted iteration is needed:

```cpp
map
```

is the straightforward choice.

---

# 81. Master STL Container Template

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // -----------------------------
    // Sequence Containers
    // -----------------------------

    vector<int> v = {
        1,
        2,
        3
    };

    array<int, 3> a = {
        1,
        2,
        3
    };

    deque<int> dq;

    list<int> li;

    forward_list<int> fl;


    // -----------------------------
    // Container Adaptors
    // -----------------------------

    stack<int> st;

    queue<int> q;

    priority_queue<int> maxHeap;

    priority_queue<
        int,
        vector<int>,
        greater<int>
    > minHeap;


    // -----------------------------
    // Ordered Associative
    // -----------------------------

    set<int> s;

    multiset<int> ms;

    map<int, int> mp;

    multimap<int, int> mmap;


    // -----------------------------
    // Unordered Associative
    // -----------------------------

    unordered_set<int> us;

    unordered_map<int, int> ump;

    unordered_multiset<int> ums;

    unordered_multimap<int, int> umm;


    // -----------------------------
    // Common Operations
    // -----------------------------

    v.push_back(10);

    dq.push_front(10);

    li.push_back(10);

    fl.push_front(10);

    st.push(10);

    q.push(10);

    maxHeap.push(10);

    minHeap.push(10);

    s.insert(10);

    ms.insert(10);

    mp[10] = 100;

    us.insert(10);

    ump[10] = 100;


    return 0;
}
```

---

# 82. Complexity Cheat Sheet

| Container        |    Access |   Search |              Insert |               Erase |
| ---------------- | --------: | -------: | ------------------: | ------------------: |
| `vector`         |      O(1) |     O(n) |          End O(1)\* |            End O(1) |
| `array`          |      O(1) |     O(n) |                 N/A |                 N/A |
| `deque`          |      O(1) |     O(n) |           Ends O(1) |           Ends O(1) |
| `list`           |      O(n) |     O(n) | Known position O(1) | Known position O(1) |
| `forward_list`   |      O(n) |     O(n) | Known position O(1) | Known position O(1) |
| `set`            |  O(log n) | O(log n) |            O(log n) |            O(log n) |
| `multiset`       |  O(log n) | O(log n) |            O(log n) |            O(log n) |
| `unordered_set`  |       N/A | Avg O(1) |            Avg O(1) |            Avg O(1) |
| `map`            |  O(log n) | O(log n) |            O(log n) |            O(log n) |
| `multimap`       |  O(log n) | O(log n) |            O(log n) |            O(log n) |
| `unordered_map`  |       N/A | Avg O(1) |            Avg O(1) |            Avg O(1) |
| `stack`          |  Top only |      N/A |                O(1) |                O(1) |
| `queue`          | Ends only |      N/A |                O(1) |                O(1) |
| `priority_queue` |  Top O(1) |      N/A |            O(log n) |            O(log n) |

`* vector::push_back` is O(1) amortized; an individual reallocation can be O(n).

---

# 83. Container Selection Cheat Sheet

```text
Dynamic array
    -> vector

Fixed-size array
    -> array

Efficient operations at both ends
    -> deque

Doubly linked list
    -> list

Singly linked list
    -> forward_list

LIFO
    -> stack

FIFO
    -> queue

Repeated minimum/maximum
    -> priority_queue

Unique + sorted
    -> set

Duplicate + sorted
    -> multiset

Unique + average O(1) lookup
    -> unordered_set

Sorted key/value
    -> map

Duplicate keys + sorted
    -> multimap

Average O(1) key/value lookup
    -> unordered_map

Duplicate keys + hashing
    -> unordered_multimap
```

---

# 84. Most Important Containers for Competitive Programming

Master these first:

```text
1. vector
2. set
3. multiset
4. unordered_set
5. map
6. unordered_map
7. priority_queue
8. queue
9. deque
10. stack
```

Then learn:

```text
array
list
forward_list
multimap
unordered_multiset
unordered_multimap
```

The most important skill is not memorizing every method. Learn to recognize the required operation:

```text
Random access?
    -> vector / array / deque

Sorted unique?
    -> set

Sorted duplicates?
    -> multiset

Fast average membership?
    -> unordered_set

Sorted key-value?
    -> map

Fast average key-value?
    -> unordered_map

LIFO?
    -> stack

FIFO?
    -> queue

Best/worst priority repeatedly?
    -> priority_queue

Both ends?
    -> deque

Known-node insertion/erase?
    -> list / forward_list
```

---

# 85. Final Reference

```text
vector
    Dynamic contiguous array
    Random access O(1)
    push_back O(1) amortized

array
    Fixed-size contiguous array
    Random access O(1)

deque
    Double-ended sequence
    Random access O(1)
    Efficient insertion/removal at both ends

list
    Doubly linked list
    No random access
    Known-position insertion/erase O(1)

forward_list
    Singly linked list
    Forward traversal only

stack
    LIFO
    top/push/pop

queue
    FIFO
    front/back/push/pop

priority_queue
    Heap
    top O(1)
    push/pop O(log n)

set
    Unique sorted values
    O(log n)

multiset
    Sorted values with duplicates
    O(log n)

unordered_set
    Unique hash-based values
    Average O(1)

map
    Sorted key-value pairs
    O(log n)

multimap
    Sorted key-value pairs with duplicate keys
    O(log n)

unordered_map
    Hash-based key-value pairs
    Average O(1)

unordered_multiset
    Hash-based duplicate values

unordered_multimap
    Hash-based duplicate keys
```

---

# End of `containers.md`
