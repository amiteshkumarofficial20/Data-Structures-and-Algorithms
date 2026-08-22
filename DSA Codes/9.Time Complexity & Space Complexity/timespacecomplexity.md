# Time Complexity and Space Complexity — Complete DSA Notes

## 1. Introduction

Complexity analysis tells us how an algorithm's resource usage grows as the input grows.

The two primary resources are:

- **Time Complexity** — growth of computational work.
- **Space Complexity** — growth of memory usage.

Example:

```cpp
for (int i = 0; i < n; i++)
{
    cout << arr[i] << ' ';
}
```

The loop runs `n` times.

```text
Time = O(n)
Auxiliary Space = O(1)
```

---

# 2. Input Size

Always identify the actual input parameters.

Common examples:

```text
Array/string       -> n
Matrix              -> rows, cols
Tree                -> n nodes, h height
Graph               -> V vertices, E edges
Two arrays          -> n, m
Queries              -> q
```

Do not automatically replace every parameter with `n`.

Example:

```cpp
for (int i = 0; i < rows; i++)
{
    for (int j = 0; j < cols; j++)
    {
        // constant work
    }
}
```

Complexity:

```text
O(rows * cols)
```

Only when:

```text
rows = cols = n
```

does this become:

```text
O(n²)
```

---

# 3. Time Complexity

Time complexity describes how the amount of computational work grows.

It does **not** mean exact seconds.

```text
O(n)
```

does not mean:

```text
n seconds
```

Actual runtime also depends on:

- hardware
- compiler
- implementation
- cache behavior
- I/O
- constant factors
- cost of individual operations

Complexity focuses on growth.

---

# 4. Space Complexity

Space complexity describes memory growth.

Example:

```cpp
vector<int> copy;

for (int x : arr)
{
    copy.push_back(x);
}
```

For `n` elements:

```text
Auxiliary Space = O(n)
```

---

# 5. Total Space vs Auxiliary Space

### Total Space

Includes:

```text
input + extra memory + output
```

### Auxiliary Space

Usually means:

```text
extra memory used by the algorithm
```

Example:

```cpp
void print(const vector<int>& arr)
{
    for (int x : arr)
        cout << x << ' ';
}
```

No new `n`-sized structure is created:

```text
Auxiliary Space = O(1)
```

The input itself still occupies `O(n)` memory.

---

# 6. Asymptotic Analysis

Asymptotic analysis focuses on behavior for large input.

Example:

```text
T(n) = 5n² + 10n + 100
```

For large `n`, `n²` dominates.

Therefore:

```text
T(n) = Θ(n²)
```

Constants and lower-order terms are ignored for asymptotic classification.

---

# 7. Big-O

Big-O gives an asymptotic upper bound.

Informally:

```text
f(n) = O(g(n))
```

means that eventually `f(n)` grows no faster than a constant multiple of `g(n)`.

Formal idea:

There exist constants `c > 0` and `n₀` such that:

```text
0 <= f(n) <= c*g(n)
```

for all:

```text
n >= n₀
```

---

# 8. Big-Omega

Big-Omega gives an asymptotic lower bound.

```text
f(n) = Ω(g(n))
```

means that eventually `f(n)` grows at least as fast as a constant multiple of `g(n)`.

Example:

```text
3n + 5 = Ω(n)
```

---

# 9. Big-Theta

Big-Theta is a tight asymptotic bound.

```text
f(n) = Θ(g(n))
```

when both:

```text
f(n) = O(g(n))
```

and:

```text
f(n) = Ω(g(n))
```

hold.

Example:

```text
3n + 5 = Θ(n)
```

---

# 10. Little-o and Little-omega

### Little-o

```text
f(n) = o(g(n))
```

means `f` grows strictly slower than `g`.

Example:

```text
n = o(n²)
```

because:

```text
n / n² = 1/n -> 0
```

### Little-omega

```text
f(n) = ω(g(n))
```

means `f` grows strictly faster than `g`.

Example:

```text
n² = ω(n)
```

---

# 11. Common Growth Rates

Generally:

```text
O(1)
<
O(log n)
<
O(sqrt(n))
<
O(n)
<
O(n log n)
<
O(n²)
<
O(n³)
<
O(2^n)
<
O(n!)
```

This is a growth-rate hierarchy, not a guarantee that one algorithm is always faster for every finite input.

---

# 12. O(1) — Constant Complexity

```cpp
int getFirst(const vector<int>& v)
{
    return v[0];
}
```

One array access:

```text
Time = O(1)
Space = O(1)
```

Another example:

```cpp
int add(int a, int b)
{
    return a + b;
}
```

---

# 13. O(n) — Linear Complexity

```cpp
for (int i = 0; i < n; i++)
{
    cout << i << ' ';
}
```

There are approximately `n` iterations:

```text
O(n)
```

Even:

```cpp
for (int i = 0; i < n; i++) {}

for (int i = 0; i < n; i++) {}
```

is:

```text
O(n + n)
= O(2n)
= O(n)
```

---

# 14. O(log n) — Logarithmic Complexity

A common pattern repeatedly divides the problem.

```cpp
int x = n;

while (x > 1)
{
    x /= 2;
}
```

Values:

```text
n
n/2
n/4
n/8
...
1
```

Therefore:

```text
O(log n)
```

Similarly:

```cpp
for (int i = 1; i < n; i *= 2)
{
    // ...
}
```

is:

```text
O(log n)
```

The base of the logarithm does not matter asymptotically because bases differ by a constant factor.

---

# 15. O(n log n)

```cpp
for (int i = 0; i < n; i++)
{
    for (int j = 1; j < n; j *= 2)
    {
        // O(1)
    }
}
```

Outer:

```text
n
```

Inner:

```text
log n
```

Total:

```text
O(n log n)
```

Common examples:

```text
Merge Sort
Heap Sort
```

---

# 16. O(n²)

```cpp
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        // constant work
    }
}
```

Total:

```text
n * n
= n²
```

Therefore:

```text
O(n²)
```

---

# 17. O(n³)

```cpp
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            // constant work
        }
    }
}
```

Total:

```text
n³
```

Therefore:

```text
O(n³)
```

---

# 18. O(2^n)

Naive Fibonacci:

```cpp
int fib(int n)
{
    if (n <= 1)
        return n;

    return fib(n - 1)
         + fib(n - 2);
}
```

This creates a branching recursion tree.

A common upper-bound description is:

```text
O(2^n)
```

A tighter analysis is related to:

```text
Θ(φ^n)
```

where:

```text
φ ≈ 1.618
```

---

# 19. O(n!)

Generating all permutations produces:

```text
n!
```

different permutations for `n` distinct elements.

```cpp
void generate(
    vector<int>& v,
    int index
)
{
    if (index == v.size())
    {
        // One complete permutation.
        return;
    }

    for (int i = index; i < v.size(); i++)
    {
        swap(v[index], v[i]);

        generate(v, index + 1);

        // Backtrack.
        swap(v[index], v[i]);
    }
}
```

Number of leaves:

```text
n!
```

If each complete permutation is processed in `O(n)` work:

```text
O(n * n!)
```

---

# 20. Sequential Statements

If blocks have:

```text
O(n)
O(n²)
O(log n)
```

then:

```text
O(n + n² + log n)
```

Dominant term:

```text
O(n²)
```

Rule:

> Sequential complexities are added, then simplified.

---

# 21. Nested Loops

Independent nested loops:

```cpp
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        // ...
    }
}
```

Multiply:

```text
n * n = n²
```

But this rule must not be applied blindly to every nested loop.

---

# 22. Triangular Loop

```cpp
for (int i = 0; i < n; i++)
{
    for (int j = i; j < n; j++)
    {
        // ...
    }
}
```

Number of operations:

```text
n + (n-1) + (n-2) + ... + 1
```

Using:

```text
1 + 2 + ... + n
= n(n+1)/2
```

we get:

```text
Θ(n²)
```

---

# 23. Dependent Loop

```cpp
for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= i; j++)
    {
        // ...
    }
}
```

Total:

```text
1 + 2 + ... + n
= Θ(n²)
```

---

# 24. Harmonic Loop

```cpp
for (int i = 1; i <= n; i++)
{
    for (int j = 0; j < n; j += i)
    {
        // ...
    }
}
```

For each `i`, inner iterations are approximately:

```text
n/i
```

Total:

```text
n/1 + n/2 + n/3 + ... + n/n
```

Factor out `n`:

```text
n(1 + 1/2 + 1/3 + ... + 1/n)
```

Harmonic sum:

```text
Θ(log n)
```

Therefore:

```text
Θ(n log n)
```

---

# 25. Geometric Series

Important:

```text
n + n/2 + n/4 + n/8 + ...
```

is:

```text
O(n)
```

Also:

```text
1 + 2 + 4 + 8 + ... + n
```

is:

```text
O(n)
```

These patterns appear frequently in divide-and-conquer algorithms.

---

# 26. Nested Loop That Is Actually O(n)

Consider:

```cpp
int left = 0;

for (int right = 0; right < n; right++)
{
    while (left < right)
    {
        left++;
    }
}
```

The `while` does not execute `n` times for every `right`.

Across the entire algorithm:

```text
right moves at most n times
left moves at most n times
```

Therefore:

```text
O(n)
```

This is a very important pattern for:

```text
two pointers
sliding window
monotonic techniques
```

---

# 27. Break and Early Termination

```cpp
for (int i = 0; i < n; i++)
{
    if (arr[i] == target)
        break;
}
```

Best case:

```text
target at first element
=> O(1)
```

Worst case:

```text
target absent / at end
=> O(n)
```

---

# 28. Best, Average, Worst Case

Algorithms may have:

```text
Best Case
Average Case
Worst Case
```

Linear search:

```text
Best    O(1)
Average O(n)
Worst   O(n)
```

Do not say just "O(n)" without understanding which case is being discussed.

---

# 29. Expected Complexity

Expected complexity often involves probability or randomized choices.

Example:

```text
Randomized Quick Sort
```

can have expected:

```text
O(n log n)
```

while worst case remains:

```text
O(n²)
```

---

# 30. Amortized Complexity

Amortized analysis studies a sequence of operations.

A single operation can be expensive while the average cost over a sequence remains small.

Classic example:

```cpp
vector<int> v;

v.push_back(x);
```

Typical:

```text
Amortized O(1)
```

but a reallocation can cost:

```text
O(n)
```

for one particular push.

---

# 31. Why `vector::push_back()` Is Amortized O(1)

When capacity grows geometrically:

```text
1
2
4
8
16
32
...
```

reallocations happen increasingly far apart.

Across many pushes, the total number of moved elements is:

```text
O(n)
```

for `n` insertions.

Therefore:

```text
n pushes = O(n) total
```

and:

```text
amortized cost per push = O(1)
```

---

# 32. Aggregate Method

If `n` operations have total cost:

```text
O(n)
```

then amortized cost per operation is:

```text
O(n) / n
= O(1)
```

This is the aggregate method.

---

# 33. Accounting Method

The accounting method assigns an amortized charge.

Cheap operations may be charged slightly more than their immediate cost.

The extra "credit" is saved to pay for future expensive operations.

Dynamic arrays are a classic example.

---

# 34. Potential Method

The potential method stores an abstract potential value:

```text
Amortized Cost
=
Actual Cost
+
Change in Potential
```

A high potential can pay for future expensive work.

It is a more formal amortized-analysis technique.

---

# 35. Recursion and Time Complexity

Every recursive algorithm should be analyzed by asking:

```text
How many recursive calls?
How much does the input shrink?
How much work occurs outside recursion?
```

Example:

```cpp
void f(int n)
{
    if (n == 0)
        return;

    f(n - 1);
}
```

Recurrence:

```text
T(n) = T(n-1) + O(1)
```

Therefore:

```text
O(n)
```

---

# 36. Recursion and Space

Every active recursive call generally consumes stack memory.

For:

```cpp
void f(int n)
{
    if (n == 0)
        return;

    f(n - 1);
}
```

Depth:

```text
O(n)
```

Therefore:

```text
Time  = O(n)
Space = O(n)
```

---

# 37. Binary Recursion

```cpp
void f(int n)
{
    if (n <= 0)
        return;

    f(n - 1);
    f(n - 1);
}
```

Time:

```text
O(2^n)
```

Maximum recursion depth:

```text
O(n)
```

Therefore:

```text
Time  = O(2^n)
Space = O(n)
```

The number of calls is exponential, but all calls do not remain active simultaneously.

---

# 38. Recursion Tree vs Stack Space

This is extremely important.

A recursion tree may contain:

```text
O(2^n)
```

total nodes.

But stack memory measures:

```text
maximum depth of simultaneously active calls
```

Therefore it can be only:

```text
O(n)
```

---

# 39. Binary Search Recurrence

Binary search halves the input:

```text
T(n) = T(n/2) + O(1)
```

Therefore:

```text
T(n) = O(log n)
```

Iterative binary search:

```text
Time  = O(log n)
Space = O(1)
```

Recursive binary search:

```text
Time  = O(log n)
Space = O(log n)
```

because of recursion depth.

---

# 40. Binary Search Code

```cpp
int binarySearch(
    const vector<int>& arr,
    int low,
    int high,
    int target
)
{
    if (low > high)
        return -1;

    int mid =
        low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;

    if (target < arr[mid])
    {
        return binarySearch(
            arr,
            low,
            mid - 1,
            target
        );
    }

    return binarySearch(
        arr,
        mid + 1,
        high,
        target
    );
}
```

Time:

```text
O(log n)
```

Auxiliary space:

```text
O(log n)
```

---

# 41. Merge Sort

Merge sort recurrence:

```text
T(n)
=
2T(n/2)
+
O(n)
```

Two subproblems:

```text
2T(n/2)
```

Linear merge:

```text
O(n)
```

Therefore:

```text
O(n log n)
```

Typical array implementation uses:

```text
O(n)
```

auxiliary merge storage.

Recursion depth is:

```text
O(log n)
```

but `O(n)` merge storage dominates.

---

# 42. Master Theorem

For:

```text
T(n) = aT(n/b) + f(n)
```

compare:

```text
f(n)
```

against:

```text
n^(log_b a)
```

This gives the classic three-case Master Theorem framework.

---

# 43. Master Theorem Case 1

If:

```text
f(n)
```

is polynomially smaller than:

```text
n^(log_b a)
```

then:

```text
T(n)
=
Θ(n^(log_b a))
```

Example:

```text
T(n) = 2T(n/2) + 1
```

Here:

```text
n^(log₂2)
= n
```

so:

```text
T(n) = Θ(n)
```

---

# 44. Master Theorem Case 2

If:

```text
f(n)
=
Θ(n^(log_b a) log^k n)
```

then:

```text
T(n)
=
Θ(n^(log_b a) log^(k+1)n)
```

Example:

```text
T(n)
=
2T(n/2)
+
Θ(n)
```

Therefore:

```text
Θ(n log n)
```

---

# 45. Master Theorem Case 3

If `f(n)` is polynomially larger than:

```text
n^(log_b a)
```

and the regularity condition is satisfied, then:

```text
T(n) = Θ(f(n))
```

Always check the theorem's conditions rather than applying it mechanically.

---

# 46. Common Recurrences

```text
T(n) = T(n-1) + O(1)
    -> O(n)

T(n) = T(n/2) + O(1)
    -> O(log n)

T(n) = 2T(n/2) + O(n)
    -> O(n log n)

T(n) = 2T(n/2) + O(1)
    -> O(n)

T(n) = T(n-1) + O(n)
    -> O(n²)
```

---

# 47. Divide and Conquer

General structure:

```text
Divide
Solve
Combine
```

Examples:

```text
Binary Search
Merge Sort
Quick Sort
```

Analyze:

```text
number of subproblems
size of each
combine cost
```

---

# 48. Backtracking Complexity

Generic backtracking:

```cpp
void solve(State state)
{
    if (isComplete(state))
        return;

    for (auto choice : choices)
    {
        make(choice);

        solve(state);

        undo(choice);
    }
}
```

If there are approximately:

```text
b choices
```

at each of:

```text
d levels
```

the search tree can contain roughly:

```text
O(b^d)
```

nodes before accounting for work at each node.

---

# 49. Subsets

For `n` elements:

```text
number of subsets = 2^n
```

Therefore generating all subsets has at least:

```text
Ω(2^n)
```

output count.

If each subset is explicitly copied/printed and can contain `O(n)` elements, total output work can be:

```text
O(n * 2^n)
```

---

# 50. Permutations

Number of permutations:

```text
n!
```

If each complete permutation is output:

```text
O(n * n!)
```

total output work is common.

---

# 51. N-Queens

Naive backtracking explores a rapidly growing search tree.

A common simple upper-bound discussion starts around:

```text
O(n!)
```

for row-by-row placement with one queen per row and one chosen column per row, though actual runtime depends strongly on pruning and implementation.

Optimizations such as:

```text
column sets
diagonal sets
bitmasks
```

reduce constant factors and can substantially improve practical performance.

---

# 52. Output-Sensitive Complexity

If an algorithm must produce `K` output objects, output generation itself requires at least:

```text
Ω(K)
```

time.

Example:

```text
K = 2^n subsets
```

means the output itself is exponential.

Always consider output size.

---

# 53. Array Complexity

Typical array operations:

```text
Access             O(1)
Search             O(n)
Insert beginning   O(n)
Delete beginning   O(n)
Insert middle      O(n)
Delete middle      O(n)
```

Reason:

Contiguous storage allows direct access, but maintaining order after insertion/deletion can require shifting elements.

---

# 54. Vector Complexity

For `std::vector`:

```text
operator[]        O(1)
front()           O(1)
back()            O(1)
push_back()       O(1) amortized
pop_back()        O(1)
```

Middle insertion/erase:

```text
O(n)
```

because elements may need to move.

---

# 55. Linked List Complexity

Typical linked-list properties:

```text
Access by index          O(n)
Search                   O(n)
Insert at known node     O(1)
Erase at known node      O(1)
Push front               O(1)
Push back                O(1) if tail maintained
```

Important:

> Finding the position is separate from performing the insertion.

If you first traverse `n` nodes:

```text
find position = O(n)
insert = O(1)
total = O(n)
```

---

# 56. Stack Complexity

Typical stack:

```text
push    O(1)
pop     O(1)
top     O(1)
```

Space for `n` elements:

```text
O(n)
```

Searching arbitrary elements:

```text
O(n)
```

if required.

---

# 57. Queue Complexity

Typical queue:

```text
enqueue   O(1)
dequeue   O(1)
front     O(1)
back      O(1)
```

Implementation matters.

A circular buffer/deque-based design can provide constant-time end operations.

---

# 58. Deque Complexity

Typical:

```text
push_front   O(1) amortized
push_back    O(1) amortized
pop_front    O(1)
pop_back     O(1)
random access O(1)
```

Middle insertion/erase is generally:

```text
O(n)
```

---

# 59. Hash Table Complexity

Typical expected/average:

```text
insert  O(1)
find    O(1)
erase   O(1)
```

Worst case can degrade to:

```text
O(n)
```

depending on collisions and implementation details.

Space:

```text
O(n)
```

for `n` stored keys/elements, up to constant-factor bucket overhead.

---

# 60. Ordered Set / Map

Balanced-tree-based ordered containers:

```text
set
multiset
map
multimap
```

Typical guaranteed operation complexity:

```text
find         O(log n)
insert       O(log n)
erase        O(log n)
lower_bound  O(log n)
upper_bound  O(log n)
```

They maintain ordering.

---

# 61. Binary Search Tree Complexity

For a BST with height `h`:

```text
search   O(h)
insert   O(h)
delete   O(h)
```

Balanced:

```text
h = O(log n)
```

so:

```text
O(log n)
```

Worst-case skewed tree:

```text
h = O(n)
```

so:

```text
O(n)
```

---

# 62. Balanced BST

AVL trees and Red-Black trees maintain:

```text
height = O(log n)
```

Therefore:

```text
search = O(log n)
insert = O(log n)
delete = O(log n)
```

This is the foundation of the expected complexity of ordered associative STL containers.

---

# 63. Heap Complexity

Binary heap:

```text
top      O(1)
push     O(log n)
pop      O(log n)
```

Building a heap from `n` elements using bottom-up heap construction:

```text
O(n)
```

---

# 64. `make_heap()`

```cpp
make_heap(
    v.begin(),
    v.end()
);
```

Complexity:

```text
O(n)
```

This is why:

```text
make_heap
```

is asymptotically better than inserting every element individually into an empty heap:

```text
O(n log n)
```

---

# 65. `push_heap()`

```cpp
v.push_back(x);

push_heap(
    v.begin(),
    v.end()
);
```

The new element may move upward:

```text
O(log n)
```

---

# 66. `pop_heap()`

```cpp
pop_heap(
    v.begin(),
    v.end()
);
```

The top element is moved toward the end and the remaining range is restored as a heap.

Complexity:

```text
O(log n)
```

---

# 67. `sort_heap()`

```cpp
sort_heap(
    v.begin(),
    v.end()
);
```

Repeated heap extraction:

```text
O(n log n)
```

---

# 68. Graph Representation

## Adjacency Matrix

Space:

```text
O(V²)
```

Edge existence:

```text
O(1)
```

Iterating all possible neighbors:

```text
O(V)
```

## Adjacency List

Space:

```text
O(V + E)
```

Iterating all adjacency entries:

```text
O(V + E)
```

---

# 69. BFS

For adjacency list:

```text
Time = O(V + E)
Auxiliary Space = O(V)
```

Why?

Each vertex is discovered/processed a bounded number of times.

Each edge is examined a bounded number of times.

The queue and visited structure require `O(V)` additional memory.

---

# 70. DFS

Adjacency list:

```text
Time = O(V + E)
Auxiliary Space = O(V)
```

Recursive DFS:

```text
visited = O(V)
recursion stack = O(V) worst case
```

Iterative DFS:

```text
visited = O(V)
explicit stack = O(V)
```

---

# 71. Topological Sort

For adjacency lists:

```text
Time = O(V + E)
Space = O(V)
```

Typical implementations:

```text
Kahn's algorithm:
    indegree + queue

DFS:
    visited states + recursion/explicit stack
```

---

# 72. Dijkstra

Adjacency list + binary heap:

```text
O((V + E) log V)
```

Often simplified to:

```text
O(E log V)
```

for common sparse-graph reasoning.

Space including graph:

```text
O(V + E)
```

Exact details depend on implementation.

---

# 73. Bellman-Ford

Relax every edge up to `V-1` times:

```text
O(VE)
```

Space including graph:

```text
O(V + E)
```

---

# 74. Floyd-Warshall

```cpp
for (int k = 0; k < V; k++)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] =
                min(
                    dist[i][j],
                    dist[i][k] + dist[k][j]
                );
        }
    }
}
```

Three dimensions:

```text
V * V * V
```

Therefore:

```text
Time = O(V³)
Space = O(V²)
```

---

# 75. Kruskal

Steps:

```text
sort edges
process edges with DSU
```

Sorting:

```text
O(E log E)
```

DSU with:

```text
path compression
+
union by rank/size
```

has almost constant amortized cost per operation:

```text
O(α(V))
```

Overall:

```text
O(E log E)
```

---

# 76. Prim

With adjacency list + binary heap:

```text
O(E log V)
```

With adjacency matrix and simple implementation:

```text
O(V²)
```

The supporting data structure changes the complexity.

---

# 77. Disjoint Set Union

With:

```text
path compression
union by rank/size
```

amortized complexity per operation:

```text
O(α(n))
```

where `α` is the inverse Ackermann function.

For practical sizes:

```text
α(n)
```

is extremely small.

---

# 78. Prefix Sum

Building:

```cpp
prefix[0] = 0;

for (int i = 0; i < n; i++)
{
    prefix[i + 1] =
        prefix[i] + arr[i];
}
```

Time:

```text
O(n)
```

Space:

```text
O(n)
```

Range query:

```cpp
int rangeSum(
    int l,
    int r
)
{
    return prefix[r + 1] - prefix[l];
}
```

Time:

```text
O(1)
```

---

# 79. Two Pointers

```cpp
int left = 0;
int right = n - 1;

while (left < right)
{
    if (condition)
        left++;
    else
        right--;
}
```

Each pointer moves at most `n` times.

Therefore:

```text
O(n)
```

not automatically `O(n²)`.

---

# 80. Sliding Window

```cpp
int left = 0;

for (int right = 0; right < n; right++)
{
    // Add arr[right].

    while (condition_is_bad())
    {
        // Remove arr[left].
        left++;
    }
}
```

Although there is a nested `while`, `left` only moves forward overall.

Therefore:

```text
Time = O(n)
```

for the common monotonic-window pattern.

---

# 81. Dynamic Programming

DP trades memory for reduced repeated computation.

Naive Fibonacci:

```text
exponential
```

Memoized Fibonacci:

```text
O(n) time
O(n) memo space
```

Tabulation:

```text
O(n) time
O(n) table space
```

Space optimized:

```text
O(n) time
O(1) extra space
```

---

# 82. Memoization Code

```cpp
int fib(
    int n,
    vector<int>& dp
)
{
    if (n <= 1)
        return n;

    // If already computed,
    // return immediately.
    if (dp[n] != -1)
        return dp[n];

    // Compute this state once.
    dp[n] =
        fib(n - 1, dp)
        +
        fib(n - 2, dp);

    return dp[n];
}
```

There are only:

```text
n + 1
```

states.

Therefore:

```text
Time = O(n)
Space = O(n)
```

plus recursion-stack considerations.

---

# 83. Space-Optimized Fibonacci

```cpp
int fib(int n)
{
    if (n <= 1)
        return n;

    int prev2 = 0;
    int prev1 = 1;

    for (int i = 2; i <= n; i++)
    {
        int current =
            prev1 + prev2;

        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}
```

Time:

```text
O(n)
```

Space:

```text
O(1)
```

---

# 84. Sorting Complexity

## Bubble Sort

Typical:

```text
Best    O(n)   with early-exit optimization
Average O(n²)
Worst   O(n²)
Space   O(1)
```

## Selection Sort

```text
Best    O(n²)
Average O(n²)
Worst   O(n²)
Space   O(1)
```

## Insertion Sort

```text
Best    O(n)
Average O(n²)
Worst   O(n²)
Space   O(1)
```

---

# 85. Merge Sort

```text
Best    O(n log n)
Average O(n log n)
Worst   O(n log n)
```

Typical array implementation:

```text
Auxiliary space = O(n)
```

Recursion:

```text
O(log n)
```

but the merge buffer dominates.

---

# 86. Quick Sort

Typical:

```text
Average = O(n log n)
```

Worst:

```text
O(n²)
```

Recursion stack:

```text
Average = O(log n)
Worst   = O(n)
```

With a good partition/pivot strategy, worst-case behavior can often be reduced in practice but not eliminated from the standard worst-case bound.

---

# 87. Heap Sort

```text
Best    O(n log n)
Average O(n log n)
Worst   O(n log n)
```

Typical in-place auxiliary space:

```text
O(1)
```

---

# 88. Counting Sort

Let:

```text
n = number of elements
k = key range
```

Typical:

```text
Time  = O(n + k)
Space = O(n + k)
```

It is not comparison-based.

---

# 89. Radix Sort

If:

```text
d = number of digit positions
k = digit/key range
```

and each pass costs approximately:

```text
O(n + k)
```

then:

```text
O(d(n + k))
```

The exact bound depends on representation and digit-sorting method.

---

# 90. String Complexity

For `std::string`:

```cpp
s[i]
```

is typically:

```text
O(1)
```

Scanning:

```cpp
for (char c : s)
{
    // ...
}
```

is:

```text
O(n)
```

String comparison can be:

```text
O(L)
```

in the worst case where `L` is the relevant compared prefix/length.

Therefore sorting strings may require considering comparison cost in addition to the number of comparisons.

---

# 91. Hidden Cost of Comparators

Suppose:

```cpp
sort(
    strings.begin(),
    strings.end()
);
```

The sorting framework performs roughly:

```text
O(n log n)
```

comparisons.

But one string comparison may itself take:

```text
O(L)
```

in the worst case.

A more detailed bound can therefore be:

```text
O(n log n * L)
```

under suitable equal-length/max-length assumptions.

---

# 92. Hidden Cost of Hashing

Similarly, a complex key's hash function may not be constant in the size of the key.

For a string key of length `L`, hashing can be:

```text
O(L)
```

So a hash lookup can have:

```text
hash computation cost
+
expected bucket operation cost
```

Do not blindly treat every operation as constant if the object being processed has growing internal size.

---

# 93. Matrix Multiplication

```cpp
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            C[i][j] +=
                A[i][k] * B[k][j];
        }
    }
}
```

Time:

```text
O(n³)
```

Matrices themselves require:

```text
O(n²)
```

storage each.

---

# 94. Transpose

For an `r × c` matrix:

```text
Time = O(r*c)
```

A new transposed matrix requires:

```text
O(r*c)
```

extra space.

For a square matrix, an in-place transpose can use:

```text
O(1)
```

auxiliary space.

---

# 95. Tree Traversal

```cpp
void inorder(Node* root)
{
    if (root == nullptr)
        return;

    inorder(root->left);

    cout << root->data;

    inorder(root->right);
}
```

Every node is visited once:

```text
Time = O(n)
```

Space:

```text
O(h)
```

where `h` is tree height.

Balanced:

```text
O(log n)
```

Skewed:

```text
O(n)
```

---

# 96. Tree Height Matters

For a balanced tree:

```text
h = O(log n)
```

For a completely skewed tree:

```text
h = O(n)
```

Therefore recursive tree algorithms often have space complexity:

```text
O(h)
```

rather than automatically `O(log n)`.

---

# 97. Graph Complexity Summary

```text
BFS                    O(V + E)
DFS                    O(V + E)
Topological Sort       O(V + E)
Dijkstra + binary heap O((V+E) log V)
Bellman-Ford            O(VE)
Floyd-Warshall          O(V³)
Kruskal                 O(E log E)
Prim + binary heap      O(E log V)
```

Always mention:

```text
graph representation
supporting data structure
```

when necessary.

---

# 98. STL Vector Complexity

| Operation     | Typical Complexity |
| ------------- | -----------------: |
| `v[i]`        |               O(1) |
| `front()`     |               O(1) |
| `back()`      |               O(1) |
| `push_back()` |     O(1) amortized |
| `pop_back()`  |               O(1) |
| insert middle |               O(n) |
| erase middle  |               O(n) |
| linear search |               O(n) |
| `size()`      |               O(1) |

---

# 99. STL Deque Complexity

| Operation        | Typical Complexity |
| ---------------- | -----------------: |
| random access    |               O(1) |
| `front()`        |               O(1) |
| `back()`         |               O(1) |
| `push_front()`   |     O(1) amortized |
| `push_back()`    |     O(1) amortized |
| `pop_front()`    |               O(1) |
| `pop_back()`     |               O(1) |
| middle insertion |               O(n) |

---

# 100. STL List Complexity

| Operation            | Typical Complexity |
| -------------------- | -----------------: |
| access by position   |               O(n) |
| search               |               O(n) |
| insert with iterator |               O(1) |
| erase with iterator  |               O(1) |
| push front           |               O(1) |
| push back            |               O(1) |
| pop front            |               O(1) |
| pop back             |               O(1) |

Important:

```text
Finding the iterator can cost O(n).
```

The insertion/erase operation itself can then be O(1).

---

# 101. STL Forward List

Typical:

```text
access by position    O(n)
search                O(n)
insert_after(iterator) O(1)
erase_after(iterator)  O(1)
push_front             O(1)
```

It supports forward traversal rather than random access.

---

# 102. STL Set / Multiset

Typical:

```text
find         O(log n)
insert       O(log n)
erase        O(log n)
lower_bound  O(log n)
upper_bound  O(log n)
```

They maintain sorted order through their comparison relation.

---

# 103. STL Map / Multimap

Typical:

```text
find         O(log n)
insert       O(log n)
erase        O(log n)
lower_bound  O(log n)
upper_bound  O(log n)
```

The comparator orders keys.

---

# 104. STL Unordered Containers

Expected/average:

```text
find    O(1)
insert  O(1)
erase   O(1)
```

Worst-case:

```text
O(n)
```

depending on collision behavior and relevant guarantees.

---

# 105. STL Priority Queue

```text
top       O(1)
push      O(log n)
emplace   O(log n)
pop       O(log n)
size      O(1)
```

Building from a range using heap construction is:

```text
O(n)
```

---

# 106. STL Algorithm Complexity

Common patterns:

| Algorithm       |   Typical Complexity |
| --------------- | -------------------: |
| `find`          |                 O(n) |
| `find_if`       |                 O(n) |
| `count`         |                 O(n) |
| `count_if`      |                 O(n) |
| `all_of`        |                 O(n) |
| `any_of`        |                 O(n) |
| `none_of`       |                 O(n) |
| `reverse`       |                 O(n) |
| `rotate`        |                 O(n) |
| `sort`          |           O(n log n) |
| `make_heap`     |                 O(n) |
| `push_heap`     |             O(log n) |
| `pop_heap`      |             O(log n) |
| `sort_heap`     |           O(n log n) |
| `binary_search` | O(log n) comparisons |
| `lower_bound`   | O(log n) comparisons |
| `upper_bound`   | O(log n) comparisons |

Important:

> Iterator category can affect actual traversal cost for some algorithms even when the number of comparisons is logarithmic.

---

# 107. `std::sort()` and Iterator Category

`std::sort()` requires Random Access Iterators.

Therefore:

```cpp
vector
array
deque
```

can be sorted using:

```cpp
std::sort()
```

but:

```cpp
list
forward_list
```

should use their member sorting functions.

For example:

```cpp
list<int> li = {40, 10, 30};

li.sort();
```

---

# 108. `forward_list` Sorting

```cpp
forward_list<int> fl = {
    40, 10, 30
};

fl.sort();
```

This works because the container provides its own sorting member function.

---

# 109. Iterator Category and Complexity

Do not analyze an algorithm only from its comparison count.

Some standard algorithms have a logarithmic number of comparisons but may need more iterator increments when the iterator is not random access.

Therefore distinguish:

```text
comparison complexity
```

from:

```text
iterator movement / total operational complexity
```

when precision matters.

---

# 110. Binary Search and Sortedness

Binary search requires an appropriately ordered/partitioned range.

Example ascending:

```cpp
sort(
    v.begin(),
    v.end()
);

binary_search(
    v.begin(),
    v.end(),
    x
);
```

Descending:

```cpp
sort(
    v.begin(),
    v.end(),
    greater<int>()
);

binary_search(
    v.begin(),
    v.end(),
    x,
    greater<int>()
);
```

The search ordering must match the range ordering.

---

# 111. Prefix Sum Time-Space Tradeoff

Naive range sum:

```text
O(n) per query
```

With `q` queries:

```text
O(nq)
```

Prefix sum:

```text
Build: O(n)
Query: O(1)
Total: O(n + q)
Space: O(n)
```

This is a classic optimization.

---

# 112. Hashing Time-Space Tradeoff

Without a hash set:

```text
repeated membership search = O(n)
```

With a hash set:

```text
expected membership search = O(1)
```

but memory becomes:

```text
O(n)
```

This is another classic time-space tradeoff.

---

# 113. DP Time-Space Tradeoff

Naive recursion:

```text
large repeated computation
```

Memoization:

```text
store previously solved states
```

This changes:

```text
time ↓
space ↑
```

---

# 114. In-Place Algorithms

An in-place algorithm uses very little additional storage.

Example:

```cpp
void reverseArray(vector<int>& v)
{
    int left = 0;
    int right = v.size() - 1;

    while (left < right)
    {
        swap(v[left], v[right]);

        left++;
        right--;
    }
}
```

Complexity:

```text
Time = O(n)
Auxiliary Space = O(1)
```

---

# 115. In-Place Does Not Automatically Mean O(1) Stack

Recursive quicksort may be in-place regarding the array partitioning, but recursion still consumes stack.

Average:

```text
O(log n)
```

stack.

Worst:

```text
O(n)
```

stack.

Therefore always count recursion separately.

---

# 116. Space Complexity of Merge Sort

Typical array merge sort:

```text
temporary merge buffer = O(n)
recursion depth = O(log n)
```

Total:

```text
O(n + log n)
=
O(n)
```

---

# 117. Space Complexity of Binary Search

Iterative:

```text
O(1)
```

Recursive:

```text
O(log n)
```

The difference comes entirely from the recursion stack.

---

# 118. Space Complexity of BFS

```text
visited = O(V)
queue   = O(V)
```

Therefore:

```text
O(V)
```

auxiliary space.

Graph storage is separate:

```text
adjacency list = O(V + E)
```

---

# 119. Space Complexity of DFS

```text
visited = O(V)
stack/recursion = O(V)
```

Therefore:

```text
O(V)
```

auxiliary space.

---

# 120. Output and Space

If an algorithm generates all subsets:

```text
2^n
```

and stores all of them simultaneously, space can become exponential.

If it generates one subset, processes it, and backtracks:

```text
stack/path space
```

may remain only:

```text
O(n)
```

This demonstrates that output handling changes space complexity.

---

# 121. Complexity of Repeated String Concatenation

Consider:

```cpp
string result;

for (const string& part : parts)
{
    result += part;
}
```

Actual complexity depends on:

```text
total output length
capacity growth
copy/move behavior
```

If repeated reallocations copy an ever-growing string, quadratic-style behavior can arise in certain patterns.

The correct analysis counts total data movement, not just loop iterations.

---

# 122. Complexity Depends on Element Cost

Suppose:

```cpp
vector<LargeObject> v;
```

and moving/copying a `LargeObject` itself costs:

```text
O(k)
```

Then a vector operation involving many object moves may cost more than simply counting each move as a constant.

Advanced complexity analysis should consider:

```text
cost per comparison
cost per copy
cost per move
cost per hash
```

when those costs scale with another parameter.

---

# 123. Multi-Parameter Complexity

If an algorithm processes:

```text
n elements
m queries
```

and does `O(n)` work for each query:

```text
O(nm)
```

Do not collapse it to `O(n²)` unless:

```text
m = Θ(n)
```

is an explicit assumption.

---

# 124. Preprocessing + Queries

Suppose:

```text
sort n elements
q binary-search queries
```

Then:

```text
sorting = O(n log n)
each query = O(log n)
q queries = O(q log n)
```

Total:

```text
O(n log n + q log n)
```

Preprocessing cost matters.

---

# 125. Comparison Sorting Lower Bound

There are:

```text
n!
```

possible permutations of `n` distinct elements.

A comparison decision tree of height `h` has at most:

```text
2^h
```

leaves.

Therefore:

```text
2^h >= n!
```

so:

```text
h >= log₂(n!)
```

and:

```text
log(n!) = Θ(n log n)
```

Therefore general comparison sorting requires:

```text
Ω(n log n)
```

comparisons in the worst case.

---

# 126. Why Counting Sort Beats the Comparison Lower Bound

Counting sort uses key information rather than only pairwise comparisons.

If the key range is `k`:

```text
O(n + k)
```

can be smaller than:

```text
O(n log n)
```

when `k` is sufficiently small.

This does not violate the comparison-sorting lower bound because counting sort is not a comparison sort.

---

# 127. Complexity Under Constraints

Rough intuition:

```text
n <= 10
    exponential/factorial may be possible

n <= 20
    O(2^n) may be possible

n <= 100
    O(n³) can sometimes be possible

n <= 1,000
    O(n²) can sometimes be possible

n <= 100,000
    O(n log n) or O(n) usually preferred

n <= 1,000,000
    O(n) is often the target
```

These are heuristics only.

Actual limits depend on:

```text
language
constant factors
time limit
memory limit
operation cost
```

---

# 128. Common Mistake — Counting Every Statement

```cpp
int a = 10;
int b = 20;
int c = a + b;
```

This is:

```text
O(1)
```

not:

```text
O(3)
```

Constants are ignored asymptotically.

---

# 129. Common Mistake — Writing O(2n)

```text
O(2n)
```

simplifies to:

```text
O(n)
```

Likewise:

```text
O(5n²)
=
O(n²)
```

---

# 130. Common Mistake — Not Removing Lower Terms

```text
O(n² + n + 100)
```

simplifies to:

```text
O(n²)
```

---

# 131. Common Mistake — Assuming Nested Means Quadratic

Incorrect reasoning:

```text
"There are two loops, so O(n²)."
```

Correct reasoning:

```text
"How many times does the inner loop execute in total?"
```

Sliding window and two-pointer algorithms frequently contain nested loops but remain:

```text
O(n)
```

---

# 132. Common Mistake — Ignoring Data Structure Operations

```cpp
for (int x : v)
{
    s.insert(x);
}
```

If:

```text
s = set
```

then:

```text
n * O(log n)
=
O(n log n)
```

If:

```text
s = unordered_set
```

expected:

```text
n * O(1)
=
O(n)
```

The data structure changes the complexity.

---

# 133. Common Mistake — Ignoring Recursion Stack

A recursive algorithm can have:

```text
Time = O(n log n)
```

and:

```text
Space = O(n)
```

or:

```text
Space = O(log n)
```

depending on temporary storage and recursion depth.

Never infer space directly from time.

---

# 134. Common Mistake — Confusing Average and Amortized

Hash table:

```text
O(1) expected/average
```

Vector push:

```text
O(1) amortized
```

These are different concepts.

```text
Average/expected
    -> probability/input distribution/randomness

Amortized
    -> sequence of operations
```

---

# 135. Common Mistake — Ignoring Output Size

Generating:

```text
2^n
```

subsets cannot be done in less than:

```text
Ω(2^n)
```

if all subsets must be output individually.

If each output itself has `O(n)` size:

```text
O(n2^n)
```

output writing can be necessary.

---

# 136. How to Analyze Code — Complete Method

Use this checklist:

```text
1. Identify input size.
2. Identify all independent parameters.
3. Find loops.
4. Calculate exact/approximate iteration counts.
5. Check whether loops are independent or dependent.
6. Check logarithmic growth.
7. Check nested pointer movement.
8. Identify expensive data-structure operations.
9. Identify recursion.
10. Write recurrence.
11. Determine recursion depth.
12. Count arrays/vectors/maps/sets.
13. Count temporary memory.
14. Count output if relevant.
15. Add sequential work.
16. Multiply truly nested independent work.
17. Drop constants.
18. Drop lower-order terms.
19. State best/average/worst/expected/amortized case when relevant.
20. Give final time and auxiliary-space complexity.
```

---

# 137. Example — Complete Analysis

```cpp
int solve(
    vector<int>& arr
)
{
    int n = arr.size();

    unordered_set<int> seen;

    for (int x : arr)
    {
        seen.insert(x);
    }

    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        if (seen.find(arr[i]) != seen.end())
        {
            answer++;
        }
    }

    return answer;
}
```

Analysis:

First loop:

```text
n expected O(1) hash insertions
=
O(n)
```

Second loop:

```text
n expected O(1) lookups
=
O(n)
```

Total:

```text
O(n) + O(n)
=
O(n)
```

Hash table stores up to `n` elements:

```text
Auxiliary Space = O(n)
```

Final:

```text
Expected Time = O(n)
Auxiliary Space = O(n)
```

Worst-case hashing can differ.

---

# 138. Example — Hidden Quadratic

```cpp
for (int i = 0; i < n; i++)
{
    if (
        find(
            v.begin(),
            v.end(),
            i
        ) != v.end()
    )
    {
        // ...
    }
}
```

Outer loop:

```text
n
```

`find`:

```text
O(n)
```

Total:

```text
O(n²)
```

---

# 139. Example — Sort + Scan

```cpp
sort(
    v.begin(),
    v.end()
);

for (int x : v)
{
    // O(1)
}
```

Total:

```text
O(n log n) + O(n)
=
O(n log n)
```

---

# 140. Example — Prefix Optimization

Naive:

```text
q range queries
each query scans O(n)
```

Total:

```text
O(nq)
```

Prefix sum:

```text
build = O(n)
q queries = O(q)
```

Total:

```text
O(n + q)
```

Space:

```text
O(n)
```

---

# 141. Example — Fibonacci Optimization

Naive:

```text
Time  = exponential
Space = O(n) recursion depth
```

Memoization:

```text
Time  = O(n)
Space = O(n)
```

Space-optimized iterative:

```text
Time  = O(n)
Space = O(1)
```

This is a complete example of algorithmic optimization through:

```text
avoiding repeated work
+
reducing state storage
```

---

# 142. Master Data Structure Table

| Structure    |             Access |            Search |                              Insert |             Delete | Space |
| ------------ | -----------------: | ----------------: | ----------------------------------: | -----------------: | ----: |
| Array        |               O(1) |              O(n) |                                O(n) |               O(n) |  O(n) |
| Vector       |               O(1) |              O(n) | O(1) amortized at end / O(n) middle |        O(n) middle |  O(n) |
| Linked List  |               O(n) |              O(n) |              O(1) at known position | O(1) at known node |  O(n) |
| Stack        |           O(1) top | O(n) if searching |                                O(1) |               O(1) |  O(n) |
| Queue        |          O(1) ends | O(n) if searching |                                O(1) |               O(1) |  O(n) |
| Deque        | O(1) random access |              O(n) |                 O(1) amortized ends |          O(1) ends |  O(n) |
| Hash Table   |                  — |     O(1) expected |                       O(1) expected |      O(1) expected |  O(n) |
| Balanced BST |                  — |          O(log n) |                            O(log n) |           O(log n) |  O(n) |
| Binary Heap  |           O(1) top |    O(n) arbitrary |                            O(log n) |       O(log n) top |  O(n) |

---

# 143. Master Algorithm Table

| Algorithm              |               Best | Average/Typical |         Worst |                 Auxiliary Space |
| ---------------------- | -----------------: | --------------: | ------------: | ------------------------------: |
| Linear Search          |               O(1) |            O(n) |          O(n) |                            O(1) |
| Binary Search          |               O(1) |        O(log n) |      O(log n) |                  O(1) iterative |
| Bubble Sort            |             O(n)\* |           O(n²) |         O(n²) |                            O(1) |
| Selection Sort         |              O(n²) |           O(n²) |         O(n²) |                            O(1) |
| Insertion Sort         |               O(n) |           O(n²) |         O(n²) |                            O(1) |
| Merge Sort             |         O(n log n) |      O(n log n) |    O(n log n) |              O(n) typical array |
| Quick Sort             | O(n log n) typical |      O(n log n) |         O(n²) | O(log n) avg stack / O(n) worst |
| Heap Sort              |         O(n log n) |      O(n log n) |    O(n log n) |                            O(1) |
| BFS                    |                  — |          O(V+E) |        O(V+E) |                            O(V) |
| DFS                    |                  — |          O(V+E) |        O(V+E) |                            O(V) |
| Dijkstra + binary heap |                  — |               — | O((V+E)log V) |              O(V+E) incl. graph |
| Bellman-Ford           |                  — |               — |         O(VE) |              O(V+E) incl. graph |
| Floyd-Warshall         |                  — |               — |         O(V³) |                           O(V²) |

`*` Bubble sort reaches `O(n)` best case with the usual early-exit optimization on already sorted input.

---

# 144. Final Complexity Hierarchy

```text
O(1)
    ↓
O(log n)
    ↓
O(sqrt n)
    ↓
O(n)
    ↓
O(n log n)
    ↓
O(n²)
    ↓
O(n³)
    ↓
O(2^n)
    ↓
O(n!)
```

---

# 145. Final Formula Sheet

```text
1 + 2 + ... + n
    = n(n+1)/2
    = Θ(n²)

1 + 2 + 4 + ... + n
    = Θ(n)

n + n/2 + n/4 + ...
    = Θ(n)

1 + 1/2 + 1/3 + ... + 1/n
    = Θ(log n)

log_a(n)
    = log_b(n) / log_b(a)

2^(log₂ n)
    = n

T(n) = T(n-1) + O(1)
    = O(n)

T(n) = T(n/2) + O(1)
    = O(log n)

T(n) = 2T(n/2) + O(n)
    = O(n log n)
```

---

# 146. Final Golden Rules

1. **Complexity describes growth, not exact seconds.**

2. Always identify the real input parameters.

3. Use `V` and `E` for graph problems when appropriate.

4. Use rows/columns for matrix problems when appropriate.

5. Sequential blocks add.

6. Independent nested loops multiply.

7. Dependent loops require summation.

8. A nested loop can still be `O(n)` if total pointer movement is linear.

9. Recursion requires both recurrence analysis and stack analysis.

10. Total recursion-tree nodes are not the same as stack depth.

11. Include the complexity of data-structure operations.

12. Amortized complexity is different from average/expected complexity.

13. Auxiliary space is different from total memory.

14. Output size can create a lower bound.

15. Time-space tradeoffs are extremely common.

16. Hash tables are usually expected/average `O(1)`, not universally worst-case `O(1)`.

17. Balanced BST operations are `O(log n)`.

18. Heap top is `O(1)`, push/pop are `O(log n)`.

19. Building a heap bottom-up is `O(n)`.

20. Binary search is `O(log n)` only when its ordering/precondition is satisfied.

21. Comparison sorting has an `Ω(n log n)` lower bound in the comparison model.

22. Counting/radix sort use additional assumptions and therefore can beat the comparison-sorting bound.

23. Never say "two loops = O(n²)" without calculating total work.

24. Never say "exponential recursion = exponential space" without calculating maximum simultaneous depth.

25. For a precise answer, state:
    - time complexity,
    - auxiliary space,
    - case/assumptions,
    - and important data-structure costs.

---

# 147. Final Mental Model

```text
INPUT
  |
  v
Identify input size
  |
  v
Identify repeated work
  |
  v
Count iterations / calls
  |
  +---- loops
  |
  +---- recursion
  |
  +---- data-structure operations
  |
  +---- comparisons / hashing / copying
  |
  v
Calculate total work
  |
  v
Simplify asymptotically
  |
  v
Analyze memory separately
  |
  +---- arrays
  +---- vectors
  +---- maps/sets
  +---- queues/stacks
  +---- temporary buffers
  +---- recursion stack
  |
  v
FINAL ANSWER

Time Complexity = O(...)
Auxiliary Space = O(...)
```

---

# 148. One-Page Revision

```text
CONSTANT
    O(1)

LOGARITHMIC
    O(log n)
    -> binary search
    -> divide by constant repeatedly

LINEAR
    O(n)
    -> scan
    -> BFS/DFS

LINEARITHMIC
    O(n log n)
    -> merge sort
    -> heap sort

QUADRATIC
    O(n²)
    -> simple double loop

CUBIC
    O(n³)
    -> naive matrix multiplication

EXPONENTIAL
    O(2^n)
    -> subset generation / brute-force recursion

FACTORIAL
    O(n!)
    -> permutations
```

```text
ARRAY ACCESS              O(1)
LINKED LIST ACCESS        O(n)
HASH LOOKUP               O(1) expected
BALANCED BST LOOKUP       O(log n)
BINARY SEARCH             O(log n)
HEAP TOP                  O(1)
HEAP PUSH/POP             O(log n)
VECTOR PUSH_BACK          O(1) amortized
VECTOR MIDDLE INSERT      O(n)
```

```text
BFS                       O(V+E)
DFS                       O(V+E)
DIJKSTRA + HEAP           O((V+E)log V)
BELLMAN-FORD              O(VE)
FLOYD-WARSHALL            O(V³)
KRUSKAL                   O(E log E)
PRIM + HEAP               O(E log V)
```

```text
ITERATIVE BINARY SEARCH
    Time O(log n)
    Space O(1)

RECURSIVE BINARY SEARCH
    Time O(log n)
    Space O(log n)

MERGE SORT
    Time O(n log n)
    Space O(n) typical array version

HEAP SORT
    Time O(n log n)
    Space O(1) auxiliary

QUICK SORT
    Average O(n log n)
    Worst O(n²)
    Stack average O(log n), worst O(n)
```

---

# 149. Final Exam/Interview Checklist

Before submitting your complexity answer:

```text
□ Did I identify n correctly?
□ Are there multiple parameters?
□ Did I count loop iterations?
□ Did I analyze dependent loops?
□ Did I check logarithmic growth?
□ Did I check harmonic/geometric sums?
□ Did I analyze recursive calls?
□ Did I write the recurrence if necessary?
□ Did I count recursion depth?
□ Did I include data-structure operation costs?
□ Did I account for preprocessing?
□ Did I account for output generation?
□ Did I count temporary memory?
□ Did I distinguish total vs auxiliary space?
□ Did I specify average/worst/expected/amortized?
□ Did I remove constants?
□ Did I remove lower-order terms?
□ Did I give the tightest useful asymptotic bound?
```

---

# 150. FINAL SUMMARY

The most important concepts are:

```text
TIME COMPLEXITY
    =
    growth of computational work

SPACE COMPLEXITY
    =
    growth of memory usage

BIG-O
    =
    asymptotic upper bound

BIG-OMEGA
    =
    asymptotic lower bound

BIG-THETA
    =
    tight asymptotic bound

AMORTIZED ANALYSIS
    =
    cost over a sequence of operations

AUXILIARY SPACE
    =
    extra memory used by the algorithm

RECURSION SPACE
    =
    maximum simultaneously active calls

OUTPUT COMPLEXITY
    =
    work required to produce the result
```

The most reliable analysis process is:

```text
1. Identify input parameters.
2. Count total work.
3. Analyze loops carefully.
4. Analyze recursion mathematically.
5. Include the cost of data-structure operations.
6. Analyze memory separately.
7. Include stack, temporary storage, and output where appropriate.
8. Simplify using asymptotic notation.
9. State assumptions and the relevant case.
```

> **Core rule:** Do not judge complexity merely by counting loops. Count the **total amount of work actually performed** and separately calculate the **maximum additional memory simultaneously required**.

# END OF NOTES
