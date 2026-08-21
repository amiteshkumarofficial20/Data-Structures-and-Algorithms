# C++ STL — Vector Notes

## 1. What is a Vector?

`vector` is a **dynamic array** provided by the C++ Standard Template Library (STL).

Unlike a normal array, a vector can **automatically resize itself** when elements are added or removed.

Header file:

```cpp
#include <vector>
```

Basic declaration:

```cpp
vector<int> v;
```

Here:

- `vector` = STL container
- `int` = type of elements
- `v` = vector name

Example:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (int x : v) {
        cout << x << " ";
    }

    return 0;
}
```

Output:

```text
10 20 30
```

---

# 2. Important Properties of Vector

A vector:

- Stores elements in **contiguous memory**
- Allows **random access**
- Can **grow dynamically grow or shrink in size**
- Supports indexing using `[]`
- Usually provides fast access: **O(1)**
- Adding an element at the end is usually **O(1) amortized**
- Inserting/removing in the middle is generally **O(n)**

Example:

```cpp
vector<int> v = {10, 20, 30, 40};

cout << v[2];
```

Output:

```text
30
```

---

# 3. Creating a Vector

## Empty Vector

```cpp
vector<int> v;
```

## Vector with Initial Values

```cpp
vector<int> v = {10, 20, 30, 40};
```

## Using Constructor

```cpp
vector<int> v(5);
```

Creates a vector of size `5`.

Default values for `int` will be `0`:

```text
0 0 0 0 0
```

## Vector with Same Value

```cpp
vector<int> v(5, 10);
```

Creates:

```text
10 10 10 10 10
```

---

# 4. Adding Elements — `push_back()`

`push_back()` adds an element at the end of the vector.

```cpp
vector<int> v;

v.push_back(10);
v.push_back(20);
v.push_back(30);
```

Vector becomes:

```text
10 20 30
```

Time complexity:

```text
O(1) amortized
```

---

# 5. Removing the Last Element — `pop_back()`

`pop_back()` removes the last element.

```cpp
vector<int> v = {10, 20, 30};

v.pop_back();
```

Now:

```text
10 20
```

Time complexity:

```text
O(1)
```

Important:

`pop_back()` does **not return** the removed value.

Incorrect:

```cpp
int x = v.pop_back();   // Wrong
```

---

# 6. Accessing Elements

## Using `[]`

```cpp
vector<int> v = {10, 20, 30};

cout << v[0];
```

Output:

```text
10
```

## Using `at()`

```cpp
cout << v.at(0);
```

`at()` performs bounds checking.

Example:

```cpp
vector<int> v = {10, 20, 30};

cout << v.at(5);
```

This can throw an `out_of_range` exception.

---

# 7. `front()` and `back()`

## `front()`

Returns the first element.

```cpp
vector<int> v = {10, 20, 30};

cout << v.front();
```

Output:

```text
10
```

## `back()`

Returns the last element.

```cpp
cout << v.back();
```

Output:

```text
30
```

---

# 8. Finding Vector Size — `size()`

`size()` returns the number of elements.

```cpp
vector<int> v = {10, 20, 30, 40};

cout << v.size();
```

Output:

```text
4
```

Return type is:

```cpp
size_t
```

Example:

```cpp
for (size_t i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
}
```

---

# 9. Checking Empty Vector — `empty()`

`empty()` returns:

- `true` → vector has no elements
- `false` → vector has at least one element

Example:

```cpp
vector<int> v;

if (v.empty()) {
    cout << "Vector is empty";
}
```

Output:

```text
Vector is empty
```

---

# 10. Clearing a Vector — `clear()`

`clear()` removes all elements.

```cpp
vector<int> v = {10, 20, 30};

v.clear();
```

Now:

```text
v.size() == 0
```

Example:

```cpp
cout << v.size();
```

Output:

```text
0
```

---

# 11. Iterating Through a Vector

## Using Normal `for` Loop

```cpp
vector<int> v = {10, 20, 30, 40};

for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
}
```

Output:

```text
10 20 30 40
```

## Using Range-Based `for` Loop

```cpp
for (int x : v) {
    cout << x << " ";
}
```

## Using `auto`

```cpp
for (auto x : v) {
    cout << x << " ";
}
```

---

# 12. Iterators

A vector provides iterators using:

```cpp
begin()
end()
```

Example:

```cpp
vector<int> v = {10, 20, 30, 40};

for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}
```

Output:

```text
10 20 30 40
```

Important:

- `begin()` points to the first element.
- `end()` points **just after** the last element.

So we do not dereference `end()`.

---

# 13. Reverse Iteration

Use:

```cpp
rbegin()
rend()
```

Example:

```cpp
vector<int> v = {10, 20, 30, 40};

for (auto it = v.rbegin(); it != v.rend(); it++) {
    cout << *it << " ";
}
```

Output:

```text
40 30 20 10
```

---

# 14. Insert Elements — `insert()`

`insert()` can add an element at a specific position.

Example:

```cpp
vector<int> v = {10, 20, 30};

v.insert(v.begin() + 1, 15);
```

Now:

```text
10 15 20 30
```

Explanation:

```cpp
v.begin() + 1
```

points to the second position.

Another example:

```cpp
v.insert(v.begin(), 5);
```

Result:

```text
5 10 15 20 30
```

Insertion in the middle is generally:

```text
O(n)
```

---

# 15. Erase Elements — `erase()`

`erase()` removes an element using an iterator.

Example:

```cpp
vector<int> v = {10, 20, 30, 40};

v.erase(v.begin() + 1);
```

Now:

```text
10 30 40
```

To erase a range:

```cpp
v.erase(v.begin() + 1, v.begin() + 3);
```

The range is:

```text
[start, end)
```

So `end` is not included.

---

# 16. `resize()`

`resize()` changes the vector's size.

Example:

```cpp
vector<int> v = {10, 20, 30};

v.resize(5);
```

New vector:

```text
10 20 30 0 0
```

Example with a value:

```cpp
v.resize(5, 100);
```

New elements get the value `100`.

---

# 17. `capacity()`

A vector has two important properties:

```text
size
capacity
```

### Size

Number of elements currently stored.

### Capacity

Number of elements that can be stored in the currently allocated memory before another allocation is needed.

Example:

```cpp
vector<int> v;

v.push_back(10);
v.push_back(20);

cout << "Size: " << v.size() << endl;
cout << "Capacity: " << v.capacity() << endl;
```

Capacity is implementation-dependent.

Important:

```text
size <= capacity
```

---

# 18. `reserve()`

`reserve()` requests memory for at least a specified number of elements.

Example:

```cpp
vector<int> v;

v.reserve(100);
```

This reserves capacity for at least `100` elements.

Important:

`reserve()` changes **capacity**, not size.

Example:

```cpp
vector<int> v;

v.reserve(100);

cout << v.size();
```

Output:

```text
0
```

---

# 19. `resize()` vs `reserve()`

This is a very important interview concept.

### `resize()`

Changes the number of elements.

```cpp
vector<int> v;

v.resize(5);
```

Now:

```text
size = 5
```

### `reserve()`

Changes the allocated capacity.

```cpp
vector<int> v;

v.reserve(5);
```

Now:

```text
size = 0
capacity >= 5
```

Remember:

```text
resize  -> changes size
reserve -> changes capacity
```

---

# 20. `shrink_to_fit()`

`shrink_to_fit()` requests that the vector reduce unused capacity.

Example:

```cpp
vector<int> v = {1, 2, 3, 4, 5};

v.resize(2);

v.shrink_to_fit();
```

Important:

This is a **non-binding request**. The implementation may or may not reduce the capacity.

---

# 21. 2D Vector

A vector can store another vector.

Example:

```cpp
vector<vector<int>> matrix;
```

Initialization:

```cpp
vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
```

Access:

```cpp
cout << matrix[1][2];
```

Output:

```text
6
```

Traversal:

```cpp
for (auto row : matrix) {
    for (auto x : row) {
        cout << x << " ";
    }
    cout << endl;
}
```

Output:

```text
1 2 3
4 5 6
7 8 9
```

---

# 22. Vector of Pairs

Example:

```cpp
vector<pair<int, int>> v;

v.push_back({1, 10});
v.push_back({2, 20});
v.push_back({3, 30});
```

Traversal:

```cpp
for (auto p : v) {
    cout << p.first << " " << p.second << endl;
}
```

Output:

```text
1 10
2 20
3 30
```

Modern C++:

```cpp
for (auto [x, y] : v) {
    cout << x << " " << y << endl;
}
```

---

# 23. Vector of Strings

```cpp
vector<string> names = {
    "Rahul",
    "Aman",
    "Priya"
};
```

Traversal:

```cpp
for (string name : names) {
    cout << name << endl;
}
```

---

# 24. Sorting a Vector

Use the STL `sort()` function.

Header:

```cpp
#include <algorithm>
```

Example:

```cpp
vector<int> v = {40, 10, 30, 20};

sort(v.begin(), v.end());
```

Result:

```text
10 20 30 40
```

Time complexity:

```text
O(n log n)
```

---

# 25. Sorting in Descending Order

```cpp
sort(v.begin(), v.end(), greater<int>());
```

Example:

```cpp
vector<int> v = {40, 10, 30, 20};

sort(v.begin(), v.end(), greater<int>());
```

Result:

```text
40 30 20 10
```

---

# 26. Searching in a Vector

## Using `find()`

```cpp
#include <algorithm>

vector<int> v = {10, 20, 30, 40};

auto it = find(v.begin(), v.end(), 30);

if (it != v.end()) {
    cout << "Found";
} else {
    cout << "Not Found";
}
```

Time complexity:

```text
O(n)
```

---

# 27. Binary Search

For a sorted vector, we can use:

```cpp
binary_search()
```

Example:

```cpp
vector<int> v = {10, 20, 30, 40, 50};

if (binary_search(v.begin(), v.end(), 30)) {
    cout << "Found";
}
```

Output:

```text
Found
```

Time complexity:

```text
O(log n)
```

Important:

The vector should be sorted for normal binary search usage.

---

# 28. `lower_bound()`

`lower_bound()` returns an iterator to the first element that is:

```text
>= target
```

Example:

```cpp
vector<int> v = {10, 20, 20, 30, 40};

auto it = lower_bound(v.begin(), v.end(), 20);

cout << (it - v.begin());
```

Output:

```text
1
```

---

# 29. `upper_bound()`

`upper_bound()` returns an iterator to the first element that is:

```text
> target
```

Example:

```cpp
vector<int> v = {10, 20, 20, 30, 40};

auto it = upper_bound(v.begin(), v.end(), 20);

cout << (it - v.begin());
```

Output:

```text
3
```

---

# 30. Removing Duplicates

A common STL technique:

```cpp
sort(v.begin(), v.end());

v.erase(unique(v.begin(), v.end()), v.end());
```

Example:

```cpp
vector<int> v = {1, 2, 2, 3, 3, 4};

sort(v.begin(), v.end());

v.erase(unique(v.begin(), v.end()), v.end());
```

Result:

```text
1 2 3 4
```

Important:

`unique()` does not actually reduce the vector's size by itself.

That is why we use:

```cpp
erase()
```

after `unique()`.

---

# 31. Copying a Vector

```cpp
vector<int> v1 = {10, 20, 30};

vector<int> v2 = v1;
```

Now both vectors contain:

```text
10 20 30
```

This creates a separate vector.

Changing `v2` does not change `v1`.

---

# 32. Swapping Two Vectors

Use:

```cpp
swap(v1, v2);
```

Example:

```cpp
vector<int> v1 = {1, 2, 3};
vector<int> v2 = {10, 20};

v1.swap(v2);
```

Now:

```text
v1 = {10, 20}
v2 = {1, 2, 3}
```

---

# 33. Passing Vector to a Function

## Pass by Value

```cpp
void print(vector<int> v) {
    for (int x : v) {
        cout << x << " ";
    }
}
```

A copy is made.

---

# 34. Pass by Reference

```cpp
void print(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
}
```

This avoids copying.

For a function that only reads the vector, this is usually preferred:

```cpp
const vector<int>&
```

---

# 35. Returning a Vector from a Function

```cpp
vector<int> createVector() {
    vector<int> v = {1, 2, 3};
    return v;
}
```

Usage:

```cpp
vector<int> ans = createVector();
```

Modern C++ handles returning vectors efficiently through move semantics and copy elision.

---

# 36. Vector and `sizeof()`

Do not use:

```cpp
sizeof(v)
```

to find the number of elements.

Use:

```cpp
v.size()
```

Correct:

```cpp
cout << v.size();
```

---

# 37. Important Time Complexities

| Operation            | Complexity     |
| -------------------- | -------------- |
| Access `v[i]`        | O(1)           |
| `front()`            | O(1)           |
| `back()`             | O(1)           |
| `push_back()`        | O(1) amortized |
| `pop_back()`         | O(1)           |
| `insert()` at end    | O(1) amortized |
| `insert()` in middle | O(n)           |
| `erase()` in middle  | O(n)           |
| `find()`             | O(n)           |
| `sort()`             | O(n log n)     |
| `binary_search()`    | O(log n)       |
| `size()`             | O(1)           |
| `empty()`            | O(1)           |
| `clear()`            | O(n)           |

---

# 38. Vector vs Array

| Feature            | Vector             | Array                        |
| ------------------ | ------------------ | ---------------------------- |
| Size               | Dynamic            | Fixed                        |
| Resizing           | Yes                | No                           |
| Random Access      | Yes                | Yes                          |
| Memory             | Dynamic allocation | Fixed storage                |
| STL Support        | High               | Limited compared to vector   |
| `push_back()`      | Yes                | No                           |
| `size()`           | Yes                | For STL array/container, yes |
| Easy to use in DSA | Yes                | Sometimes                    |

Example array:

```cpp
int arr[5];
```

Example vector:

```cpp
vector<int> v;
```

---

# 39. Vector vs `deque`

Both support dynamic storage, but their characteristics differ.

### Vector

- Contiguous memory
- Fast random access
- Fast insertion/removal at the end
- Insertion/removal at the front is expensive

### Deque

- Supports efficient insertion/removal at both ends
- Random access is supported
- Memory is not guaranteed to be one contiguous block

Example:

```cpp
deque<int> dq;
```

---

# 40. Common Mistakes

## Mistake 1: Accessing an Empty Vector

Wrong:

```cpp
vector<int> v;

cout << v[0];
```

The vector has no element at index `0`.

---

## Mistake 2: Dereferencing `end()`

Wrong:

```cpp
cout << *v.end();
```

`end()` points past the last element.

---

## Mistake 3: Confusing `size()` and `capacity()`

Remember:

```text
size     = number of elements
capacity = allocated storage for elements
```

---

## Mistake 4: Using `reserve()` When You Need Elements

Wrong assumption:

```cpp
vector<int> v;
v.reserve(5);

cout << v[0];  // Invalid
```

`reserve()` does not create elements.

---

# 41. Vector Invalidation Concept

Some vector operations can invalidate iterators, pointers, and references to elements.

For example, when a vector needs to reallocate memory because its capacity is insufficient, previously stored addresses/iterators/references may become invalid.

Example:

```cpp
vector<int> v = {1, 2, 3};

auto it = v.begin();

v.push_back(4);
```

The iterator `it` may become invalid if reallocation occurs.

This is important in advanced C++ and interview questions.

---

# 42. Complete Example

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<int> v;

    // Add elements
    v.push_back(40);
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);

    // Print vector
    cout << "Original vector: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    // Sort
    sort(v.begin(), v.end());

    cout << "Sorted vector: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    // Size
    cout << "Size: " << v.size() << endl;

    // First and last element
    cout << "First: " << v.front() << endl;
    cout << "Last: " << v.back() << endl;

    // Remove last element
    v.pop_back();

    cout << "After pop_back(): ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
```

---

# 43. Most Important Vector Functions

For DSA and competitive programming, remember these functions first:

```cpp
push_back()
pop_back()
size()
empty()
clear()
front()
back()
begin()
end()
rbegin()
rend()
insert()
erase()
resize()
reserve()
capacity()
sort()
find()
binary_search()
lower_bound()
upper_bound()
```

---

# 44. Quick Revision

### Declaration

```cpp
vector<int> v;
```

### Add

```cpp
v.push_back(x);
```

### Remove Last

```cpp
v.pop_back();
```

### Size

```cpp
v.size();
```

### First Element

```cpp
v.front();
```

### Last Element

```cpp
v.back();
```

### Access

```cpp
v[i];
```

### Check Empty

```cpp
v.empty();
```

### Remove All

```cpp
v.clear();
```

### Insert

```cpp
v.insert(v.begin() + i, x);
```

### Erase

```cpp
v.erase(v.begin() + i);
```

### Sort

```cpp
sort(v.begin(), v.end());
```

### Reverse

```cpp
reverse(v.begin(), v.end());
```

### Search

```cpp
find(v.begin(), v.end(), x);
```

### Binary Search

```cpp
binary_search(v.begin(), v.end(), x);
```

### Reserve Capacity

```cpp
v.reserve(n);
```

### Resize

```cpp
v.resize(n);
```

---

# 45. Interview One-Liners

**Q: What is a vector?**

A vector is a dynamic array container from the C++ STL that stores elements contiguously and can automatically grow or shrink.

**Q: What is the difference between size and capacity?**

`size()` tells how many elements are currently stored, while `capacity()` tells how many elements can be stored in the currently allocated memory without reallocation.

**Q: What is the complexity of accessing a vector element?**

```text
O(1)
```

**Q: What is the complexity of `push_back()`?**

```text
O(1) amortized
```

**Q: Why is insertion in the middle costly?**

Because elements after the insertion point generally need to be shifted.

**Q: Does `reserve()` increase vector size?**

No. It only increases or prepares capacity.

**Q: Does `clear()` reduce capacity?**

`clear()` removes all elements, but it does not guarantee that the allocated capacity will be reduced.

**Q: Why is vector useful in DSA?**

Because it provides dynamic sizing, fast random access, easy STL integration, and works efficiently with common algorithms such as `sort`, `find`, `binary_search`, `lower_bound`, and `upper_bound`.

---

# Final Cheat Sheet

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> v = {10, 20, 30};

    // Add
    v.push_back(40);

    // Remove last
    v.pop_back();

    // Access
    cout << v[0] << endl;

    // First / Last
    cout << v.front() << endl;
    cout << v.back() << endl;

    // Size
    cout << v.size() << endl;

    // Empty
    cout << v.empty() << endl;

    // Iterate
    for (int x : v) {
        cout << x << " ";
    }

    // Sort
    sort(v.begin(), v.end());

    // Reverse
    reverse(v.begin(), v.end());

    // Find
    auto it = find(v.begin(), v.end(), 20);

    // Binary Search
    bool found = binary_search(v.begin(), v.end(), 20);

    // Insert
    v.insert(v.begin(), 5);

    // Erase
    v.erase(v.begin());

    // Resize
    v.resize(10);

    // Reserve
    v.reserve(100);

    // Capacity
    cout << v.capacity() << endl;

    // Clear
    v.clear();

    return 0;
}
```

## Remember

```text
Vector = Dynamic Array

Access       -> O(1)
push_back    -> O(1) amortized
pop_back     -> O(1)
Middle insert/delete -> O(n)
Sorting      -> O(n log n)
```
