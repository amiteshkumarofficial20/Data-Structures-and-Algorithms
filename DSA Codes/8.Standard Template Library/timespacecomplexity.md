# Time Complexity & Space Complexity in C++ and STL

## Complete Detailed Notes for DSA

---

# 1. Introduction

When we write a program, we generally care about two major resources:

1. **Time**
2. **Memory**

A program should ideally:

- execute quickly,
- use reasonable memory,
- scale well when input size becomes large.

To analyze these requirements, we use:

```text
Time Complexity
Space Complexity
```

These concepts are extremely important in:

- Data Structures
- Algorithms
- Competitive Programming
- C++ STL
- DSA Interviews
- Problem Solving

---

# 2. What is Time Complexity?

Time complexity describes how the **running time of an algorithm grows as the input size grows**.

We usually represent input size by:

```text
n
```

For example, suppose an array contains:

```text
n = 10
```

elements.

If an algorithm checks every element once, it performs approximately:

```text
10 operations
```

If:

```text
n = 1000
```

it performs approximately:

```text
1000 operations
```

If:

```text
n = 1,000,000
```

it performs approximately:

```text
1,000,000 operations
```

Therefore, its growth is proportional to `n`.

We represent this as:

```text
O(n)
```

---

# 3. What Does Big-O Mean?

Big-O notation describes the **asymptotic upper bound** of an algorithm's growth.

Common complexities:

```text
O(1)
O(log n)
O(n)
O(n log n)
O(n²)
O(n³)
O(2ⁿ)
O(n!)
```

From generally faster to slower growth:

```text
O(1)
   ↓
O(log n)
   ↓
O(n)
   ↓
O(n log n)
   ↓
O(n²)
   ↓
O(n³)
   ↓
O(2ⁿ)
   ↓
O(n!)
```

The lower the growth rate, generally the better the algorithm scales.

---

# 4. Important Note About Big-O

Big-O does NOT mean the exact number of CPU instructions.

For example:

```cpp
for (int i = 0; i < n; i++)
{
    cout << i;
}
```

The loop executes approximately `n` times.

So:

```text
Time Complexity = O(n)
```

Even if every iteration contains multiple instructions, we normally focus on the dominant growth rate.

---

# 5. Why Constants Are Ignored

Suppose an algorithm performs:

```text
5n
```

operations.

Its complexity is:

```text
O(5n)
```

But we normally simplify this to:

```text
O(n)
```

because the constant `5` does not change the growth category.

Similarly:

```text
O(100n)
```

becomes:

```text
O(n)
```

---

# 6. Why Lower-Order Terms Are Ignored

Suppose an algorithm performs:

```text
n² + n + 10
```

operations.

For very large `n`, the dominant term is:

```text
n²
```

Therefore:

```text
O(n² + n + 10)
```

is simplified to:

```text
O(n²)
```

---

# 7. Rule of Dominant Term

When calculating Big-O:

1. Remove constants.
2. Keep the fastest-growing term.
3. Ignore lower-order terms.

Example:

```text
3n² + 5n + 100
```

becomes:

```text
O(n²)
```

Another example:

```text
7n³ + 10n² + 20n
```

becomes:

```text
O(n³)
```

---

# 8. O(1) — Constant Time

`O(1)` means the operation takes approximately constant time regardless of `n`.

Example:

```cpp
int x = arr[0];
```

Accessing an element of a vector/array by index is generally:

```text
O(1)
```

Example:

```cpp
cout << arr[5];
```

The size of the array does not determine how many steps are required to directly access index `5`.

---

# 9. Example of O(1)

```cpp
int getFirst(int arr[])
{
    return arr[0];
}
```

Complexity:

```text
Time  = O(1)
Space = O(1)
```

assuming no additional storage proportional to input size is created.

---

# 10. O(log n) — Logarithmic Time

Logarithmic complexity usually appears when the problem size is repeatedly divided.

Most famous example:

```text
Binary Search
```

Suppose:

```text
n = 16
```

Binary search may reduce the search space like:

```text
16
 ↓
8
 ↓
4
 ↓
2
 ↓
1
```

Only about:

```text
log₂(n)
```

steps are required.

Therefore:

```text
Time Complexity = O(log n)
```

---

# 11. Binary Search Example

```cpp
int binarySearch(vector<int>& arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}
```

Complexity:

```text
Time = O(log n)
Space = O(1)
```

---

# 12. O(n) — Linear Time

An algorithm is `O(n)` when work grows linearly with input size.

Example:

```cpp
for (int i = 0; i < n; i++)
{
    cout << arr[i] << endl;
}
```

The loop runs `n` times.

Therefore:

```text
Time Complexity = O(n)
```

---

# 13. Linear Search

```cpp
int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}
```

Complexity:

```text
Best Case    = O(1)
Average Case = O(n)
Worst Case   = O(n)
```

Why?

Best case:

```text
target is at first position
```

Worst case:

```text
target is at last position
```

or:

```text
target doesn't exist
```

---

# 14. O(n²) — Quadratic Time

Nested loops often produce `O(n²)`.

Example:

```cpp
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        cout << i << " " << j << endl;
    }
}
```

Outer loop:

```text
n
```

Inner loop:

```text
n
```

Total:

```text
n × n
```

Therefore:

```text
O(n²)
```

---

# 15. O(n³) — Cubic Time

Three nested loops usually produce:

```text
O(n³)
```

Example:

```cpp
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            cout << i << j << k;
        }
    }
}
```

Total iterations:

```text
n × n × n
```

Therefore:

```text
O(n³)
```

---

# 16. O(n log n)

`O(n log n)` is extremely common in efficient algorithms.

Examples:

```text
Merge Sort
Heap Sort
Many efficient sorting algorithms
```

A common pattern is:

```text
n work
×
log n levels
```

Therefore:

```text
O(n log n)
```

---

# 17. Example of O(n log n)

Suppose an algorithm performs:

```text
log n
```

levels, and each level processes:

```text
n
```

elements.

Then:

```text
n × log n
```

Therefore:

```text
O(n log n)
```

---

# 18. O(2ⁿ) — Exponential Time

Exponential complexity grows extremely quickly.

Example:

```text
O(2ⁿ)
```

Common examples include some brute-force recursive algorithms.

Example:

```cpp
void generate(int n)
{
    if (n == 0)
    {
        return;
    }

    generate(n - 1);
    generate(n - 1);
}
```

Each call creates approximately two more calls.

Therefore the number of calls grows exponentially.

Approximate complexity:

```text
O(2ⁿ)
```

---

# 19. O(n!) — Factorial Time

Factorial complexity is even worse.

Example:

```text
O(n!)
```

A common example is brute-force generation of all permutations.

For `n` elements:

```text
Number of permutations = n!
```

For example:

```text
3! = 6
5! = 120
10! = 3,628,800
```

Therefore factorial algorithms become impractical very quickly.

---

# 20. Complexity Growth Comparison

Approximate growth:

```text
O(1)
        Best scaling

O(log n)

O(n)

O(n log n)

O(n²)

O(n³)

O(2ⁿ)

O(n!)
        Worst scaling
```

---

# 21. Sequential Statements

Consider:

```cpp
int a = 10;

int b = 20;

int c = a + b;
```

Each operation is constant time.

Therefore:

```text
O(1) + O(1) + O(1)
```

becomes:

```text
O(1)
```

---

# 22. Two Separate Loops

Consider:

```cpp
for (int i = 0; i < n; i++)
{
    cout << i;
}

for (int j = 0; j < n; j++)
{
    cout << j;
}
```

First loop:

```text
O(n)
```

Second loop:

```text
O(n)
```

Total:

```text
O(n) + O(n)
```

Therefore:

```text
O(2n)
```

Ignore constant:

```text
O(n)
```

---

# 23. Different Size Loops

Consider:

```cpp
for (int i = 0; i < n; i++)
{
}

for (int j = 0; j < m; j++)
{
}
```

Complexity:

```text
O(n + m)
```

Do NOT automatically write:

```text
O(n)
```

unless `m` is known to be proportional to `n`.

---

# 24. Nested Loops With Different Variables

Consider:

```cpp
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        cout << i << j;
    }
}
```

Outer loop:

```text
n
```

Inner loop:

```text
m
```

Total:

```text
n × m
```

Therefore:

```text
O(nm)
```

---

# 25. Nested Loop With Dependent Bound

Consider:

```cpp
for (int i = 0; i < n; i++)
{
    for (int j = i; j < n; j++)
    {
        cout << i << j;
    }
}
```

Iterations are approximately:

```text
n + (n - 1) + (n - 2) + ... + 1
```

This sum is:

```text
n(n + 1) / 2
```

Which is:

```text
O(n²)
```

---

# 26. Loop That Doubles

Consider:

```cpp
for (int i = 1; i <= n; i *= 2)
{
    cout << i << endl;
}
```

Values:

```text
1
2
4
8
16
32
...
```

The number of iterations is approximately:

```text
log₂(n)
```

Therefore:

```text
O(log n)
```

---

# 27. Loop That Halves

Consider:

```cpp
for (int i = n; i > 0; i /= 2)
{
    cout << i << endl;
}
```

Each iteration divides the problem by 2.

Therefore:

```text
O(log n)
```

---

# 28. Loop With Multiplication

```cpp
for (int i = 1; i < n; i *= 3)
{
    cout << i << endl;
}
```

Values:

```text
1
3
9
27
81
...
```

Number of iterations:

```text
log₃(n)
```

Big-O ignores the logarithm base:

```text
O(log n)
```

---

# 29. Nested Logarithmic Loops

Consider:

```cpp
for (int i = 1; i <= n; i *= 2)
{
    for (int j = 1; j <= n; j *= 2)
    {
        cout << i << j;
    }
}
```

Outer:

```text
O(log n)
```

Inner:

```text
O(log n)
```

Total:

```text
O(log n × log n)
```

Therefore:

```text
O((log n)²)
```

---

# 30. Conditional Statements

Consider:

```cpp
if (x > 10)
{
    cout << "A";
}
else
{
    cout << "B";
}
```

Only a constant amount of work happens.

Therefore:

```text
O(1)
```

---

# 31. Time Complexity of Function Calls

Consider:

```cpp
void print()
{
    cout << "Hello";
}

int main()
{
    print();
}
```

`print()` performs constant work.

Therefore:

```text
O(1)
```

---

# 32. Recursive Complexity

Consider:

```cpp
void fun(int n)
{
    if (n == 0)
    {
        return;
    }

    cout << n;

    fun(n - 1);
}
```

The recursive calls are:

```text
fun(n)
fun(n-1)
fun(n-2)
...
fun(1)
fun(0)
```

Number of calls:

```text
n
```

Therefore:

```text
Time = O(n)
```

The recursion stack also contains approximately `n` calls:

```text
Space = O(n)
```

---

# 33. Recursion With Two Calls

Consider:

```cpp
void fun(int n)
{
    if (n == 0)
    {
        return;
    }

    fun(n - 1);
    fun(n - 1);
}
```

Each call creates two recursive calls.

Approximate complexity:

```text
Time = O(2ⁿ)
```

The maximum recursion depth is:

```text
O(n)
```

Therefore auxiliary stack space is:

```text
O(n)
```

Important:

```text
Time = O(2ⁿ)
Space = O(n)
```

---

# 34. What is Space Complexity?

Space complexity describes how much memory an algorithm requires as the input size grows.

We can divide memory into:

```text
Input Space
+
Auxiliary Space
```

---

# 35. Input Space

Input space is memory already required to store the input.

Example:

```cpp
vector<int> arr(n);
```

The input itself requires:

```text
O(n)
```

memory.

---

# 36. Auxiliary Space

Auxiliary space means **extra memory used by the algorithm apart from the input**.

Example:

```cpp
int sum = 0;
```

Only constant extra memory is used.

Therefore:

```text
Auxiliary Space = O(1)
```

---

# 37. Space Complexity Example

```cpp
int sumArray(vector<int>& arr)
{
    int sum = 0;

    for (int x : arr)
    {
        sum += x;
    }

    return sum;
}
```

The input vector already exists.

Additional variables:

```text
sum
x
```

require constant memory.

Therefore:

```text
Auxiliary Space = O(1)
```

---

# 38. Creating Another Array

Consider:

```cpp
vector<int> copy;

for (int x : arr)
{
    copy.push_back(x);
}
```

If `arr` contains `n` elements, `copy` also contains `n` elements.

Therefore additional memory:

```text
O(n)
```

So:

```text
Auxiliary Space = O(n)
```

---

# 39. Time and Space Together

An algorithm can have:

```text
Time  = O(n)
Space = O(1)
```

Example:

```cpp
int sum = 0;

for (int i = 0; i < n; i++)
{
    sum += arr[i];
}
```

This is generally very memory efficient.

---

# 40. Time-Space Tradeoff

Sometimes we use extra memory to make an algorithm faster.

Example:

```cpp
unordered_set<int> seen;
```

Suppose we need to check whether duplicates exist.

Without extra memory, we might compare every pair:

```text
O(n²)
```

With a hash-based set, we can often achieve average:

```text
O(n)
```

but use:

```text
O(n)
```

additional memory.

This is called a:

```text
Time-Space Tradeoff
```

---

# 41. STL Complexity

Understanding STL complexity is extremely important in DSA.

Different STL containers have different performance characteristics.

---

# 42. `vector` Complexity

`vector` is a dynamic contiguous array.

## Access

```cpp
v[i]
```

Complexity:

```text
O(1)
```

## Access using `at()`

```cpp
v.at(i)
```

Complexity:

```text
O(1)
```

## `push_back()`

Usually:

```text
O(1) amortized
```

Worst-case during reallocation:

```text
O(n)
```

## `pop_back()`

```text
O(1)
```

## Insert at beginning

```cpp
v.insert(v.begin(), value);
```

Generally:

```text
O(n)
```

because existing elements may need to move.

## Erase from beginning

```text
O(n)
```

---

# 43. `deque` Complexity

`deque` supports efficient insertion/removal at both ends.

```cpp
deque<int> dq;
```

Typical complexities:

```text
push_front() -> O(1)
push_back()  -> O(1)
pop_front()  -> O(1)
pop_back()   -> O(1)
```

Random access:

```text
O(1)
```

Insertion/erasure in the middle:

```text
O(n)
```

---

# 44. `list` Complexity

`list` is a doubly linked list.

```cpp
list<int> l;
```

Operations at known positions:

```text
insert -> O(1)
erase  -> O(1)
```

if you already have the appropriate iterator.

Search:

```text
O(n)
```

Random indexing:

```text
NOT AVAILABLE
```

This is invalid:

```cpp
l[5];
```

---

# 45. `forward_list`

`forward_list` is a singly linked list.

Typical operations:

```text
insert_after -> O(1)
erase_after  -> O(1)
```

Search:

```text
O(n)
```

It does not support random access.

---

# 46. `set` Complexity

`set` is an ordered associative container.

Typical complexity:

```text
insert      -> O(log n)
erase       -> O(log n)
find        -> O(log n)
count       -> O(log n)
lower_bound -> O(log n)
upper_bound -> O(log n)
```

Basic size queries:

```text
size  -> O(1)
empty -> O(1)
```

---

# 47. `multiset` Complexity

`multiset` is similar to `set`, but duplicate keys/elements are allowed.

Typical:

```text
insert      -> O(log n)
erase       -> O(log n) for an iterator / appropriate operation
find        -> O(log n)
count       -> O(log n)
lower_bound -> O(log n)
upper_bound -> O(log n)
```

---

# 48. `map` Complexity

`map` stores:

```text
key -> value
```

in sorted key order.

Typical operations:

```text
insert      -> O(log n)
erase       -> O(log n) for lookup by key
find        -> O(log n)
count       -> O(log n)
lower_bound -> O(log n)
upper_bound -> O(log n)
```

Access by key:

```cpp
mp.at(key)
```

or:

```cpp
mp[key]
```

is:

```text
O(log n)
```

for `std::map`.

---

# 49. `multimap` Complexity

`multimap` allows duplicate keys.

Typical:

```text
insert      -> O(log n)
find        -> O(log n)
count       -> O(log n)
lower_bound -> O(log n)
upper_bound -> O(log n)
```

---

# 50. `unordered_set` Complexity

`unordered_set` uses hashing.

Average-case:

```text
insert -> O(1)
find   -> O(1)
erase  -> O(1)
```

Worst-case can degrade to:

```text
O(n)
```

because of hash collisions.

---

# 51. `unordered_map` Complexity

`unordered_map` is hash-based.

Average:

```text
insert -> O(1)
find   -> O(1)
erase  -> O(1)
```

Worst-case:

```text
O(n)
```

---

# 52. `stack` Complexity

`stack` provides LIFO behavior.

Main operations:

```text
push -> O(1)
pop  -> O(1)
top  -> O(1)
```

Example:

```cpp
stack<int> st;

st.push(10);
st.push(20);

cout << st.top();

st.pop();
```

---

# 53. `queue` Complexity

`queue` provides FIFO behavior.

Typical:

```text
push -> O(1)
pop  -> O(1)
front -> O(1)
back  -> O(1)
```

---

# 54. `priority_queue` Complexity

Typical:

```text
push -> O(log n)
pop  -> O(log n)
top  -> O(1)
```

Why?

A priority queue is generally implemented using a heap.

Insertion requires restoring heap order.

Removal also requires heap adjustment.

The top element is immediately available.

---

# 55. STL Complexity Cheat Sheet

| Container        |  Access/Search |                  Insert |                   Erase |
| ---------------- | -------------: | ----------------------: | ----------------------: |
| `vector`         |   `O(1)` index | `O(1)` amortized at end | `O(n)` middle/beginning |
| `deque`          |   `O(1)` index |             `O(1)` ends |           `O(n)` middle |
| `list`           |  `O(n)` search |    `O(1)` with iterator |    `O(1)` with iterator |
| `forward_list`   |  `O(n)` search |    `O(1)` with iterator |    `O(1)` with iterator |
| `set`            |     `O(log n)` |              `O(log n)` |       `O(log n)` by key |
| `multiset`       |     `O(log n)` |              `O(log n)` |       `O(log n)` lookup |
| `map`            |     `O(log n)` |              `O(log n)` |       `O(log n)` by key |
| `multimap`       |     `O(log n)` |              `O(log n)` |       `O(log n)` lookup |
| `unordered_set`  | `O(1)` average |          `O(1)` average |          `O(1)` average |
| `unordered_map`  | `O(1)` average |          `O(1)` average |          `O(1)` average |
| `stack`          |     `O(1)` top |                  `O(1)` |                  `O(1)` |
| `queue`          |    `O(1)` ends |                  `O(1)` |                  `O(1)` |
| `priority_queue` |     `O(1)` top |              `O(log n)` |              `O(log n)` |

---

# 56. Important `vector` Amortized Complexity

Consider:

```cpp
vector<int> v;

for (int i = 0; i < n; i++)
{
    v.push_back(i);
}
```

It is tempting to say:

```text
O(n²)
```

because sometimes vector reallocates and copies elements.

But `push_back()` is:

```text
O(1) amortized
```

Therefore `n` push operations are:

```text
O(n)
```

amortized.

---

# 57. What is Amortized Complexity?

Amortized analysis looks at the average cost over a sequence of operations.

Example:

```cpp
vector<int> v;

v.push_back(1);
v.push_back(2);
v.push_back(3);
...
```

Most `push_back()` operations are:

```text
O(1)
```

Occasionally, the vector needs more memory.

Then it may:

1. allocate a larger block,
2. move/copy existing elements,
3. release the old block.

That particular operation may cost:

```text
O(n)
```

But over a long sequence of insertions, the average cost per insertion is:

```text
O(1) amortized
```

---

# 58. Best Case, Average Case and Worst Case

An algorithm can have different complexities depending on the input.

Three common cases:

```text
Best Case
Average Case
Worst Case
```

---

# 59. Best Case

Best case represents the most favorable input.

Example: linear search.

```cpp
for (int i = 0; i < n; i++)
{
    if (arr[i] == target)
    {
        return i;
    }
}
```

If target is at index `0`:

```text
Best Case = O(1)
```

---

# 60. Worst Case

If target is at the last position:

```text
Worst Case = O(n)
```

If target does not exist:

```text
Worst Case = O(n)
```

---

# 61. Average Case

Average case describes expected performance over a suitable distribution of inputs.

For linear search, a commonly stated average-case complexity is:

```text
O(n)
```

---

# 62. Why Worst Case is Important in DSA

When discussing algorithmic guarantees, worst-case complexity is often emphasized because it gives a predictable upper bound.

For example:

```text
Binary Search -> O(log n)
Merge Sort    -> O(n log n)
std::map find -> O(log n)
```

---

# 63. Space Complexity of Arrays

For:

```cpp
int arr[n];
```

memory required is proportional to:

```text
n
```

Therefore:

```text
Space = O(n)
```

If each integer takes constant-sized storage, total memory grows linearly.

---

# 64. Space Complexity of 2D Array

For:

```cpp
int matrix[n][n];
```

number of elements:

```text
n × n
```

Therefore:

```text
Space = O(n²)
```

---

# 65. Space Complexity of 3D Array

For:

```cpp
int cube[n][n][n];
```

number of elements:

```text
n³
```

Therefore:

```text
Space = O(n³)
```

---

# 66. Recursion Stack Space

Consider:

```cpp
void fun(int n)
{
    if (n == 0)
    {
        return;
    }

    fun(n - 1);
}
```

At maximum, approximately `n` stack frames exist.

Therefore:

```text
Auxiliary Space = O(n)
```

---

# 67. Iterative vs Recursive

Iterative version:

```cpp
for (int i = 0; i < n; i++)
{
    cout << i;
}
```

Typically:

```text
Time  = O(n)
Space = O(1)
```

Recursive version:

```cpp
void fun(int i, int n)
{
    if (i == n)
    {
        return;
    }

    cout << i;

    fun(i + 1, n);
}
```

Typically:

```text
Time  = O(n)
Space = O(n)
```

The extra space comes from the recursion stack.

---

# 68. Auxiliary Space vs Total Space

Suppose:

```cpp
vector<int> arr(n);
vector<int> temp(n);
```

If `arr` is input and `temp` is additional memory:

```text
Input Space     = O(n)
Auxiliary Space = O(n)
```

Depending on the convention being used, total memory occupied may be described as:

```text
O(n)
```

or, when separating the components:

```text
Input + Auxiliary = O(n) + O(n)
```

which asymptotically remains:

```text
O(n)
```

---

# 69. In-Place Algorithms

An in-place algorithm uses very little extra memory.

Example:

```cpp
void reverseArray(vector<int>& arr)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        swap(arr[left], arr[right]);

        left++;
        right--;
    }
}
```

Additional variables:

```text
left
right
```

Only constant extra memory is used.

Therefore:

```text
Auxiliary Space = O(1)
```

---

# 70. Sorting Complexity

Common sorting algorithms:

| Algorithm      |         Best |               Average |        Worst |
| -------------- | -----------: | --------------------: | -----------: |
| Bubble Sort    |     `O(n)`\* |               `O(n²)` |      `O(n²)` |
| Selection Sort |      `O(n²)` |               `O(n²)` |      `O(n²)` |
| Insertion Sort |       `O(n)` |               `O(n²)` |      `O(n²)` |
| Merge Sort     | `O(n log n)` |          `O(n log n)` | `O(n log n)` |
| Heap Sort      | `O(n log n)` |          `O(n log n)` | `O(n log n)` |
| Quick Sort     | `O(n log n)` | `O(n log n)` expected |      `O(n²)` |

`*` Bubble sort achieves `O(n)` best case only with an appropriate early-exit optimization.

---

# 71. `std::sort()`

C++ STL provides:

```cpp
sort()
```

from:

```cpp
#include <algorithm>
```

Example:

```cpp
vector<int> arr = {5, 2, 4, 1, 3};

sort(arr.begin(), arr.end());
```

`std::sort` has a worst-case complexity requirement of:

```text
O(n log n)
```

and is typically implemented using an introspective sorting strategy.

---

# 72. Searching Complexity in STL

For sorted vectors, binary search can be used:

```cpp
binary_search(arr.begin(), arr.end(), target);
```

Complexity:

```text
O(log n)
```

provided the range is sorted.

---

# 73. `lower_bound()` Complexity

For random-access iterators such as vector iterators:

```cpp
lower_bound()
```

runs in:

```text
O(log n)
```

For more general iterator categories, the number of comparisons is logarithmic but iterator movement can affect total complexity.

This distinction is important when comparing `vector` and node-based containers.

---

# 74. `set` vs `vector` Search

Suppose we have:

```cpp
vector<int> v;
```

and:

```cpp
set<int> s;
```

Searching a vector linearly:

```text
O(n)
```

Searching a set:

```text
O(log n)
```

because the set maintains an ordered tree structure.

---

# 75. `unordered_set` vs `set`

For search:

```text
set:
    O(log n)

unordered_set:
    O(1) average
    O(n) worst case
```

Therefore, if sorted order is required:

```text
set
```

may be appropriate.

If fast average-case hash lookup is required and ordering is not needed:

```text
unordered_set
```

may be appropriate.

---

# 76. `map` vs `unordered_map`

For searching:

```text
map:
    O(log n)

unordered_map:
    O(1) average
    O(n) worst case
```

For ordering:

```text
map:
    sorted keys

unordered_map:
    no guaranteed sorted order
```

---

# 77. Nested STL Operations

Consider:

```cpp
for (int x : arr)
{
    s.insert(x);
}
```

If:

```text
arr contains n elements
```

and each `set::insert()` costs:

```text
O(log n)
```

then total complexity is approximately:

```text
O(n log n)
```

This is an extremely common DSA pattern.

---

# 78. Example: Remove Duplicates Using Set

```cpp
vector<int> arr = {4, 2, 4, 1, 2, 3};

set<int> s;

for (int x : arr)
{
    s.insert(x);
}
```

Each insertion:

```text
O(log n)
```

There are `n` elements.

Therefore:

```text
Time = O(n log n)
```

Additional set storage:

```text
O(n)
```

Therefore:

```text
Space = O(n)
```

---

# 79. Remove Duplicates Using `unordered_set`

```cpp
unordered_set<int> s;

for (int x : arr)
{
    s.insert(x);
}
```

Average insertion:

```text
O(1)
```

For `n` elements:

```text
Average Time = O(n)
```

Additional memory:

```text
O(n)
```

---

# 80. Two Nested STL Containers

Suppose:

```cpp
for (int x : arr)
{
    if (s.find(x) != s.end())
    {
        cout << x;
    }
}
```

If:

```text
arr size = n
```

and:

```text
set find = O(log n)
```

then:

```text
Total Time = O(n log n)
```

---

# 81. Complexity of `map` Iteration

Suppose:

```cpp
map<int, string> mp;
```

contains `n` elements.

A complete iteration:

```cpp
for (auto it = mp.begin();
     it != mp.end();
     ++it)
{
    cout << it->first;
}
```

takes:

```text
O(n)
```

Why?

Each element is visited once.

Important:

```text
map search = O(log n)
map complete traversal = O(n)
```

---

# 82. Complexity of `set` Iteration

Similarly:

```cpp
for (set<int>::iterator it = s.begin();
     it != s.end();
     ++it)
{
    cout << *it;
}
```

If there are `n` elements:

```text
Time = O(n)
```

---

# 83. Complexity of `unordered_map` Iteration

A complete iteration over `n` stored elements:

```cpp
for (auto it = ump.begin();
     it != ump.end();
     ++it)
{
    cout << it->first;
}
```

is:

```text
O(n)
```

The order is not sorted.

---

# 84. Complexity of `vector` Iteration

```cpp
for (int x : v)
{
    cout << x;
}
```

For `n` elements:

```text
Time = O(n)
```

---

# 85. Common Mistake: Assuming Every STL Operation is O(1)

This is wrong.

For example:

```cpp
map<int, int> mp;

mp.find(10);
```

is:

```text
O(log n)
```

not:

```text
O(1)
```

Similarly:

```cpp
set<int> s;

s.insert(10);
```

is:

```text
O(log n)
```

---

# 86. Common Mistake: Confusing `unordered_map` With `map`

Wrong assumption:

```text
map find = O(1)
```

Correct:

```text
map find = O(log n)
```

For unordered_map:

```text
average find = O(1)
worst-case find = O(n)
```

---

# 87. Common Mistake: Forgetting STL Operation Cost

Consider:

```cpp
for (int i = 0; i < n; i++)
{
    mp.find(arr[i]);
}
```

If `mp` is a `map`:

```text
n × O(log n)
```

Therefore:

```text
O(n log n)
```

Not:

```text
O(n)
```

---

# 88. Common Mistake: Nested Loops Always Mean O(n²)

Not always.

Example:

```cpp
for (int i = 1; i <= n; i *= 2)
{
    for (int j = 1; j <= n; j *= 2)
    {
    }
}
```

Both loops are logarithmic:

```text
O(log n) × O(log n)
```

Therefore:

```text
O((log n)²)
```

---

# 89. Common Mistake: Ignoring Different Variables

This:

```cpp
for (int i = 0; i < n; i++)
{
}

for (int j = 0; j < m; j++)
{
}
```

is:

```text
O(n + m)
```

not necessarily:

```text
O(n)
```

---

# 90. Common Mistake: Ignoring Recursion Space

Consider:

```cpp
void fun(int n)
{
    if (n == 0)
        return;

    fun(n - 1);
}
```

Time:

```text
O(n)
```

But space is also:

```text
O(n)
```

because of the call stack.

---

# 91. Complexity of Common Operations

```text
Array:
    Access          O(1)
    Search          O(n)
    Insert middle   O(n)
    Delete middle   O(n)


Vector:
    Access          O(1)
    push_back       O(1) amortized
    pop_back        O(1)
    Search          O(n)
    Insert middle   O(n)


Set:
    Search          O(log n)
    Insert          O(log n)
    Erase           O(log n)


Map:
    Search          O(log n)
    Insert          O(log n)
    Erase           O(log n)


Unordered Set:
    Search          O(1) average
    Insert          O(1) average
    Erase           O(1) average


Unordered Map:
    Search          O(1) average
    Insert          O(1) average
    Erase           O(1) average


Stack:
    Push            O(1)
    Pop             O(1)
    Top             O(1)


Queue:
    Push            O(1)
    Pop             O(1)
    Front           O(1)


Priority Queue:
    Push            O(log n)
    Pop             O(log n)
    Top             O(1)
```

---

# 92. Big-O vs Big-Theta vs Big-Omega

There are three common asymptotic notations:

```text
Big-O
Big-Theta
Big-Omega
```

---

## Big-O

Usually used to describe an upper bound.

```text
O(f(n))
```

---

## Big-Omega

Represents a lower bound.

```text
Ω(f(n))
```

---

## Big-Theta

Represents a tight asymptotic bound.

```text
Θ(f(n))
```

For example, if an algorithm always performs proportional to `n` work:

```text
Θ(n)
```

can express the tight bound.

In everyday DSA discussions, Big-O is the most commonly used notation.

---

# 93. Logarithm Base in Big-O

Consider:

```text
log₂(n)
log₃(n)
log₁₀(n)
```

They differ only by a constant factor:

```text
log₂(n) = log₃(n) × constant
```

Therefore Big-O generally writes:

```text
O(log n)
```

without specifying the base.

---

# 94. Practical Complexity Ranking

Generally:

```text
O(1)
```

is extremely efficient.

Then:

```text
O(log n)
```

is also highly efficient.

Then:

```text
O(n)
```

is usually acceptable for large inputs.

Then:

```text
O(n log n)
```

is common for efficient sorting and many DSA solutions.

Then:

```text
O(n²)
```

may become expensive for large `n`.

Then:

```text
O(n³)
```

becomes expensive even faster.

Then:

```text
O(2ⁿ)
```

and:

```text
O(n!)
```

become impractical quickly.

---

# 95. Example of Complete Complexity Analysis

Consider:

```cpp
void example(vector<int>& arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i] + arr[j];
        }
    }
}
```

First loop:

```text
O(n)
```

Nested loops:

```text
O(n²)
```

Total:

```text
O(n + n²)
```

Dominant term:

```text
n²
```

Therefore:

```text
Time = O(n²)
```

If no additional memory proportional to `n` is allocated:

```text
Auxiliary Space = O(1)
```

---

# 96. Example With `set`

```cpp
void example(vector<int>& arr)
{
    set<int> s;

    for (int x : arr)
    {
        s.insert(x);
    }
}
```

Suppose:

```text
n = arr.size()
```

Each insertion:

```text
O(log n)
```

There are:

```text
n
```

insertions.

Therefore:

```text
Time = O(n log n)
```

The set may contain up to `n` unique values:

```text
Space = O(n)
```

---

# 97. Example With `unordered_set`

```cpp
void example(vector<int>& arr)
{
    unordered_set<int> s;

    for (int x : arr)
    {
        s.insert(x);
    }
}
```

Average:

```text
insert = O(1)
```

Therefore:

```text
Average Time = O(n)
```

Worst case:

```text
O(n²)
```

in a pathological collision scenario if every insertion/search operation degenerates.

Space:

```text
O(n)
```

---

# 98. Example With `map`

```cpp
void example(vector<int>& arr)
{
    map<int, int> frequency;

    for (int x : arr)
    {
        frequency[x]++;
    }
}
```

Each map access/update is:

```text
O(log n)
```

There are `n` elements.

Therefore:

```text
Time = O(n log n)
```

The map can contain up to `n` unique keys:

```text
Space = O(n)
```

---

# 99. Example With `unordered_map`

```cpp
void example(vector<int>& arr)
{
    unordered_map<int, int> frequency;

    for (int x : arr)
    {
        frequency[x]++;
    }
}
```

Average:

```text
O(1)
```

per operation.

Therefore:

```text
Average Time = O(n)
```

Space:

```text
O(n)
```

---

# 100. DSA Rule: Analyze Operations Inside Loops

Always ask:

> What is the complexity of the operation inside the loop?

Example:

```cpp
for (int i = 0; i < n; i++)
{
    s.insert(arr[i]);
}
```

Do not simply say:

```text
O(n)
```

First analyze:

```text
s.insert() = O(log n)
```

Then:

```text
n × O(log n)
```

Therefore:

```text
O(n log n)
```

---

# 101. DSA Rule: Identify Input Size

Before calculating complexity, identify what `n` represents.

Examples:

```text
Array of n elements:
    n = number of elements

String of n characters:
    n = string length

Matrix:
    n × m

Graph:
    V = vertices
    E = edges
```

For graph algorithms, complexity is often written using:

```text
V
E
```

instead of only `n`.

---

# 102. Graph Complexity Example

For a graph:

```text
V = number of vertices
E = number of edges
```

Breadth-First Search and Depth-First Search using adjacency lists generally run in:

```text
O(V + E)
```

because vertices and edges are processed a bounded number of times.

---

# 103. Matrix Complexity

Suppose:

```cpp
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        cout << matrix[i][j];
    }
}
```

Number of iterations:

```text
n × n
```

Therefore:

```text
Time = O(n²)
```

If the matrix itself requires:

```text
n²
```

storage:

```text
Space = O(n²)
```

---

# 104. Rectangular Matrix

If:

```text
rows = n
columns = m
```

then:

```cpp
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
    }
}
```

Complexity:

```text
Time = O(nm)
```

Memory for the matrix:

```text
Space = O(nm)
```

---

# 105. Complexity of Common STL Algorithms

| Algorithm                            |                                    Typical Complexity |
| ------------------------------------ | ----------------------------------------------------: |
| `sort()`                             |                   `O(n log n)` worst-case requirement |
| `reverse()`                          |                                                `O(n)` |
| `find()` on a general iterator range |                                                `O(n)` |
| `binary_search()`                    | `O(log n)` comparisons on random-access sorted ranges |
| `lower_bound()`                      |                                `O(log n)` comparisons |
| `upper_bound()`                      |                                `O(log n)` comparisons |
| `count()` on a general range         |                                                `O(n)` |
| `min_element()`                      |                                                `O(n)` |
| `max_element()`                      |                                                `O(n)` |
| `accumulate()`                       |                                                `O(n)` |
| `copy()`                             |                                                `O(n)` |
| `fill()`                             |                                                `O(n)` |

The exact total work can depend on the iterator category and operation cost of the element type.

---

# 106. `find()` Algorithm vs `set::find()`

This distinction is important.

Generic algorithm:

```cpp
find(v.begin(), v.end(), x);
```

For a normal vector range:

```text
O(n)
```

But member function:

```cpp
s.find(x);
```

for `std::set`:

```text
O(log n)
```

Similarly:

```cpp
mp.find(key);
```

for `std::map`:

```text
O(log n)
```

---

# 107. Why Container Choice Matters

Suppose you need:

```text
Fast random access
```

Use:

```text
vector
```

Suppose you need:

```text
Sorted unique values
```

Use:

```text
set
```

Suppose you need:

```text
Fast average hash lookup
```

Use:

```text
unordered_set
```

Suppose you need:

```text
Sorted key-value pairs
```

Use:

```text
map
```

Suppose you need:

```text
Fast average hash-based key-value lookup
```

Use:

```text
unordered_map
```

---

# 108. Final Complexity Cheat Sheet

```text
============================================================
                TIME COMPLEXITY CHEAT SHEET
============================================================

O(1)
    Constant

O(log n)
    Binary Search
    Tree-based search

O(n)
    Linear Search
    Array traversal
    Vector traversal

O(n log n)
    Efficient sorting
    n insertions into set/map

O(n²)
    Two nested n loops
    Basic quadratic algorithms

O(n³)
    Three nested n loops

O(2ⁿ)
    Many brute-force recursive algorithms

O(n!)
    Permutation brute force


============================================================
                SPACE COMPLEXITY CHEAT SHEET
============================================================

O(1)
    Constant extra variables

O(log n)
    Some recursive/divide-and-conquer stacks

O(n)
    One extra array
    Set/map containing up to n elements
    Linear recursion stack

O(n²)
    n × n matrix

O(n³)
    n × n × n data structure
```

---

# 109. Final STL Complexity Table

```text
============================================================
                    STL COMPLEXITY
============================================================

vector
    random access        O(1)
    push_back            O(1) amortized
    pop_back             O(1)
    search               O(n)
    insert middle        O(n)
    erase middle         O(n)


deque
    random access        O(1)
    push_front           O(1)
    push_back            O(1)
    pop_front            O(1)
    pop_back             O(1)


list
    search               O(n)
    insert with iterator O(1)
    erase with iterator  O(1)


forward_list
    search               O(n)
    insert_after         O(1)
    erase_after          O(1)


set
    find                 O(log n)
    insert               O(log n)
    erase                O(log n)
    lower_bound          O(log n)
    upper_bound          O(log n)


multiset
    find                 O(log n)
    insert               O(log n)
    erase                O(log n) lookup/operation dependent


map
    find                 O(log n)
    insert               O(log n)
    erase                O(log n) by key
    lower_bound          O(log n)
    upper_bound          O(log n)


multimap
    find                 O(log n)
    insert               O(log n)
    erase                O(log n) lookup/operation dependent


unordered_set
    find                 O(1) average
    insert               O(1) average
    erase                O(1) average
    worst case           O(n)


unordered_map
    find                 O(1) average
    insert               O(1) average
    erase                O(1) average
    worst case           O(n)


stack
    push                 O(1)
    pop                  O(1)
    top                  O(1)


queue
    push                 O(1)
    pop                  O(1)
    front                O(1)
    back                 O(1)


priority_queue
    push                 O(log n)
    pop                  O(log n)
    top                  O(1)


============================================================
```

---

# 110. Most Important Rules to Remember

## Rule 1

```text
Single loop from 0 to n
        ↓
    O(n)
```

---

## Rule 2

```text
Two independent loops
        ↓
O(n) + O(n)
        ↓
O(n)
```

---

## Rule 3

```text
Nested n loops
        ↓
O(n²)
```

---

## Rule 4

```text
Loop that doubles/halves
        ↓
O(log n)
```

---

## Rule 5

```text
n elements × log n operation
        ↓
O(n log n)
```

---

## Rule 6

```text
Tree-based set/map operation
        ↓
O(log n)
```

---

## Rule 7

```text
Hash-based unordered_map/unordered_set
        ↓
O(1) average
O(n) worst case
```

---

## Rule 8

```text
Recursion depth n
        ↓
O(n) auxiliary stack space
```

---

## Rule 9

```text
Extra array of n elements
        ↓
O(n) auxiliary space
```

---

## Rule 10

Always analyze the operation inside a loop.

For example:

```cpp
for (int i = 0; i < n; i++)
{
    mp.find(arr[i]);
}
```

For `std::map`:

```text
n × O(log n)
=
O(n log n)
```

---

# 111. Final Definition

## Time Complexity

> Time complexity describes how the running time or number of fundamental operations of an algorithm grows with respect to the input size.

## Space Complexity

> Space complexity describes how the memory requirement of an algorithm grows with respect to the input size.

## Auxiliary Space

> Auxiliary space is the extra memory used by an algorithm apart from the input storage.

## Big-O

> Big-O notation describes an asymptotic upper bound and is commonly used to express how an algorithm scales as input size becomes large.

---

# 112. Final DSA Mindset

Whenever you see a piece of code, ask these questions:

```text
1. What is the input size?

2. How many times does each loop run?

3. Are the loops independent or nested?

4. Does a loop variable double or halve?

5. Is there recursion?

6. What is the complexity of the STL operation being called?

7. Is there extra memory?

8. Is an STL container storing up to n elements?

9. Is the algorithm modifying the input in-place?

10. What is the final dominant term?
```

Then derive:

```text
Time Complexity
+
Auxiliary Space Complexity
```

---

# 113. One-Line Final Revision

```text
O(1)       -> Constant
O(log n)   -> Divide / halve / double
O(n)       -> One complete traversal
O(n log n) -> n work across log levels / log operation repeated n times
O(n²)      -> Two n-sized nested loops
O(n³)      -> Three n-sized nested loops
O(2ⁿ)      -> Exponential branching
O(n!)      -> Permutation-style brute force
```

And for STL:

```text
vector          -> O(1) random access
set             -> O(log n) search/insert/erase
map             -> O(log n) search/insert/erase
unordered_set   -> O(1) average search/insert/erase
unordered_map   -> O(1) average search/insert/erase
priority_queue  -> O(log n) push/pop, O(1) top
stack           -> O(1) push/pop/top
queue           -> O(1) push/pop/front/back
```

---

# 114. Golden Rule

> **Never calculate complexity by simply counting lines of code. Calculate it by counting how the number of operations and memory usage grows as the input size grows.**

```text
Input Size
    ↓
Operations / Memory Growth
    ↓
Dominant Term
    ↓
Time Complexity
    +
Auxiliary Space Complexity
```

This is the fundamental approach for analyzing algorithms in C++ and STL.
