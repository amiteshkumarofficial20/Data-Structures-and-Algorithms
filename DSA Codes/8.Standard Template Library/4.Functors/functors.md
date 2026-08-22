# C++ STL Functors & Comparators — Detailed Notes

## 1. Functor / Function Object

A **functor** (function object) is an object that behaves like a function by defining `operator()`.

```cpp
#include <iostream>
using namespace std;

struct Add
{
    int operator()(int a, int b) const
    {
        return a + b;
    }
};

int main()
{
    Add add;

    cout << add(10, 20) << endl;

    // Equivalent call:
    // add.operator()(10, 20);

    return 0;
}
```

A functor can also store state:

```cpp
struct AddValue
{
    int value;

    AddValue(int v) : value(v) {}

    int operator()(int x) const
    {
        return x + value;
    }
};

AddValue add10(10);

cout << add10(5); // 15
```

This is one major advantage of functors: **the callable object can remember configuration/state**.

---

# 2. Predicate

A **predicate** is a callable representing a condition, normally producing `true` or `false`.

### Unary predicate

```cpp
struct IsEven
{
    bool operator()(int x) const
    {
        return x % 2 == 0;
    }
};
```

Used with:

```cpp
count_if(v.begin(), v.end(), IsEven());
find_if(v.begin(), v.end(), IsEven());
all_of(v.begin(), v.end(), IsEven());
any_of(v.begin(), v.end(), IsEven());
none_of(v.begin(), v.end(), IsEven());
```

### Binary predicate

```cpp
struct Greater
{
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};
```

A comparator is commonly a binary predicate used to establish ordering.

---

# 3. Comparator

A comparator answers:

> **Should `a` come before `b` according to this ordering?**

Ascending:

```cpp
struct Ascending
{
    bool operator()(int a, int b) const
    {
        return a < b;
    }
};
```

Descending:

```cpp
struct Descending
{
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};
```

Do not think:

```text
true = swap
false = don't swap
```

Better mental model:

```text
comp(a,b) = "Should a appear before b?"
```

---

# 4. Functor vs Predicate vs Comparator

```text
FUNCTOR / FUNCTION OBJECT
    |
    +-- callable object
    +-- can return anything
    +-- can store state

PREDICATE
    |
    +-- callable representing a condition
    +-- usually returns true/false
    +-- unary or binary

COMPARATOR
    |
    +-- usually binary predicate
    +-- establishes an ordering
```

A functor does **not** have to be a comparator.

---

# 5. `operator()` — Core of a Functor

```cpp
struct Square
{
    int operator()(int x) const
    {
        return x * x;
    }
};

Square square;

cout << square(5); // 25
```

Conceptually:

```cpp
square.operator()(5);
```

`operator()` may accept any number/type of arguments and can be overloaded.

---

# 6. Why `const` on `operator()`?

Common comparator style:

```cpp
bool operator()(int a, int b) const
{
    return a > b;
}
```

The final `const` means calling the functor does not modify its observable state.

A stateful comparator can also be const:

```cpp
struct FlexibleCompare
{
    bool descending;

    bool operator()(int a, int b) const
    {
        return descending ? a > b : a < b;
    }
};
```

---

# 7. Functors With STL Algorithms

```cpp
struct IsEven
{
    bool operator()(int x) const
    {
        return x % 2 == 0;
    }
};

auto it = find_if(
    v.begin(),
    v.end(),
    IsEven()
);
```

The algorithm repeatedly invokes the callable on elements.

`count_if()`:

```cpp
int count = count_if(
    v.begin(),
    v.end(),
    IsEven()
);
```

`for_each()`:

```cpp
struct Print
{
    void operator()(int x) const
    {
        cout << x << " ";
    }
};

for_each(v.begin(), v.end(), Print());
```

`transform()`:

```cpp
struct Square
{
    int operator()(int x) const
    {
        return x * x;
    }
};

transform(
    v.begin(),
    v.end(),
    v.begin(),
    Square()
);
```

---

# 8. Comparator With `sort()`

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Descending
{
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};

int main()
{
    vector<int> v = {
        10, 50, 20, 40, 30
    };

    sort(
        v.begin(),
        v.end(),
        Descending()
    );

    for (int x : v)
        cout << x << " ";

    return 0;
}
```

Output:

```text
50 40 30 20 10
```

---

# 9. Comparator Meaning in `sort()`

With:

```cpp
return a < b;
```

the rule is:

```text
a should come before b if a < b
```

With:

```cpp
return a > b;
```

the rule is:

```text
a should come before b if a > b
```

The comparator is **not a swap function**.

---

# 10. Strict Weak Ordering

Comparators used by ordered STL operations/containers must provide a **strict weak ordering**.

Important practical properties:

### Irreflexive

```cpp
comp(a, a) == false;
```

Therefore this is a bad strict comparator:

```cpp
return a <= b;
```

because `5 <= 5` is true.

### Asymmetric

If:

```cpp
comp(a,b) == true
```

then:

```cpp
comp(b,a) == false
```

### Transitive

If:

```text
a comes before b
b comes before c
```

then:

```text
a comes before c
```

Avoid random/inconsistent comparators:

```cpp
return rand() % 2; // BAD
```

---

# 11. Lambda vs Functor

Functor:

```cpp
struct Descending
{
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};
```

Lambda:

```cpp
[](int a, int b)
{
    return a > b;
}
```

Both can be passed to `sort`.

Use a lambda for a short local rule. A named functor is useful for reusable logic, state, or a larger policy.

---

# 12. Standard Function Objects

Header:

```cpp
#include <functional>
```

Comparison:

```cpp
less<>
greater<>
less_equal<>
greater_equal<>
equal_to<>
not_equal_to<>
```

Arithmetic:

```cpp
plus<>
minus<>
multiplies<>
divides<>
modulus<>
negate<>
```

Logical:

```cpp
logical_and<>
logical_or<>
logical_not<>
```

Examples:

```cpp
sort(v.begin(), v.end(), greater<int>());
```

and:

```cpp
plus<int> add;
cout << add(10, 20);
```

---

# 13. Pair Comparator

By first:

```cpp
struct CompareFirst
{
    bool operator()(
        const pair<int,int>& a,
        const pair<int,int>& b
    ) const
    {
        return a.first < b.first;
    }
};
```

By second:

```cpp
struct CompareSecond
{
    bool operator()(
        const pair<int,int>& a,
        const pair<int,int>& b
    ) const
    {
        return a.second < b.second;
    }
};
```

---

# 14. Multiple Conditions / Tie Breaker

Very common DSA pattern:

> Higher marks first; equal marks → name ascending.

```cpp
struct Student
{
    string name;
    int marks;
};

struct CompareStudent
{
    bool operator()(
        const Student& a,
        const Student& b
    ) const
    {
        // Primary ordering.
        if (a.marks != b.marks)
        {
            return a.marks > b.marks;
        }

        // Secondary ordering.
        return a.name < b.name;
    }
};
```

Use:

```cpp
sort(
    students.begin(),
    students.end(),
    CompareStudent()
);
```

The tie-breaker is important whenever the primary key can be equal.

---

# 15. String Length Comparator

```cpp
struct CompareLength
{
    bool operator()(
        const string& a,
        const string& b
    ) const
    {
        if (a.length() != b.length())
            return a.length() < b.length();

        // Tie-breaker.
        return a < b;
    }
};
```

---

# 16. Absolute Value Comparator

```cpp
struct CompareAbsolute
{
    bool operator()(int a, int b) const
    {
        if (abs(a) != abs(b))
            return abs(a) < abs(b);

        return a < b;
    }
};
```

The second comparison handles equal absolute values such as `-5` and `5`.

---

# 17. Stateful Functor

```cpp
struct GreaterThan
{
    int limit;

    GreaterThan(int x)
        : limit(x)
    {
    }

    bool operator()(int x) const
    {
        return x > limit;
    }
};
```

Use:

```cpp
int count = count_if(
    v.begin(),
    v.end(),
    GreaterThan(50)
);
```

This shows why a functor can be more powerful than a simple function: the object carries the `limit`.

---

# 18. `std::ref()` With Stateful Functors

Algorithms may copy callable objects.

If you need the original callable object's state to be updated:

```cpp
#include <functional>

struct Counter
{
    int count = 0;

    void operator()(int)
    {
        ++count;
    }
};

Counter c;

for_each(
    v.begin(),
    v.end(),
    ref(c)
);

cout << c.count;
```

`std::ref(c)` provides a reference wrapper to the original object.

---

# 19. Comparator in `set`

Default:

```cpp
set<int> s;
```

uses ascending ordering.

Descending:

```cpp
set<int, greater<int>> s;
```

Example:

```cpp
set<int, greater<int>> s = {
    10, 50, 20, 40
};

for (int x : s)
    cout << x << " ";
```

Output:

```text
50 40 20 10
```

Custom functor:

```cpp
struct Descending
{
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};

set<int, Descending> s;
```

---

# 20. Comparator in `map`

```cpp
map<int, string, greater<int>> mp = {
    {1, "One"},
    {2, "Two"},
    {3, "Three"}
};
```

Keys iterate in descending order.

The comparator orders **keys**, not mapped values.

---

# 21. Comparator in `set<pair<int,int>>`

```cpp
struct ComparePair
{
    bool operator()(
        const pair<int,int>& a,
        const pair<int,int>& b
    ) const
    {
        if (a.second != b.second)
            return a.second < b.second;

        return a.first < b.first;
    }
};

set<
    pair<int,int>,
    ComparePair
> s;
```

---

# 22. Comparator for Custom Class in `set`

```cpp
struct Student
{
    string name;
    int marks;
};

struct CompareStudent
{
    bool operator()(
        const Student& a,
        const Student& b
    ) const
    {
        if (a.marks != b.marks)
            return a.marks > b.marks;

        return a.name < b.name;
    }
};

set<Student, CompareStudent> students;
```

---

# 23. Very Important: `set` Equivalence

For an ordered associative container, `a` and `b` are equivalent under comparator `comp` when:

```cpp
!comp(a, b) && !comp(b, a)
```

This is **not necessarily**:

```cpp
a == b
```

Example:

```cpp
struct CompareLength
{
    bool operator()(
        const string& a,
        const string& b
    ) const
    {
        return a.length() < b.length();
    }
};
```

Then `"cat"` and `"dog"` are equivalent according to this ordering because neither is shorter.

A `set<string, CompareLength>` can therefore retain only one representative from that equivalent group.

---

# 24. `priority_queue` Comparator

Default:

```cpp
priority_queue<int> pq;
```

is a max-heap.

Min-heap:

```cpp
priority_queue<
    int,
    vector<int>,
    greater<int>
> pq;
```

Now:

```cpp
pq.top()
```

is the smallest element.

Custom:

```cpp
struct Compare
{
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};

priority_queue<
    int,
    vector<int>,
    Compare
> pq;
```

For `priority_queue`, reason in terms of **which element gets the highest priority / appears at `top()`** rather than blindly applying the `sort()` "comes before" mental model.

---

# 25. Custom Object in `priority_queue`

```cpp
struct Student
{
    string name;
    int marks;
};

struct CompareStudent
{
    bool operator()(
        const Student& a,
        const Student& b
    ) const
    {
        return a.marks < b.marks;
    }
};

priority_queue<
    Student,
    vector<Student>,
    CompareStudent
> pq;
```

The comparator defines the heap's priority relationship.

---

# 26. Ordered vs Unordered Containers

Ordered:

```text
set
multiset
map
multimap
    ↓
ordering comparator
```

Unordered:

```text
unordered_set
unordered_multiset
unordered_map
unordered_multimap
    ↓
hash + equality
```

Therefore an `unordered_map` does not use an ordering comparator in the same sense as `map`.

---

# 27. `lower_bound()` With Comparator

```cpp
vector<int> v = {
    50, 40, 30, 20, 10
};

auto it = lower_bound(
    v.begin(),
    v.end(),
    30,
    greater<int>()
);
```

The range must be ordered/partitioned consistently with the supplied comparator.

Do not sort ascending and then use an incompatible descending comparator.

---

# 28. `upper_bound()` and `equal_range()`

```cpp
auto it = upper_bound(
    v.begin(),
    v.end(),
    x,
    comp
);
```

and:

```cpp
auto range = equal_range(
    v.begin(),
    v.end(),
    x,
    comp
);
```

These require the range to be partitioned consistently with the comparison.

---

# 29. `binary_search()` With Comparator

```cpp
bool found = binary_search(
    v.begin(),
    v.end(),
    x,
    comp
);
```

The range must be ordered consistently with the comparator.

---

# 30. `is_sorted()` With Comparator

```cpp
bool ok = is_sorted(
    v.begin(),
    v.end(),
    greater<int>()
);
```

Checks whether the sequence is sorted according to that comparison.

---

# 31. `min_element()` / `max_element()`

A comparator can customize the ordering used by these algorithms:

```cpp
auto it = min_element(
    v.begin(),
    v.end(),
    [](int a, int b)
    {
        return abs(a) < abs(b);
    }
);
```

The comparator defines which value is considered earlier/smaller in the ordering.

---

# 32. `stable_sort()` With Comparator

```cpp
stable_sort(
    students.begin(),
    students.end(),
    CompareStudent()
);
```

When elements are equivalent according to the comparator, `stable_sort` preserves their previous relative order.

`sort()` does not provide that stability guarantee.

---

# 33. Comparator With Custom Objects — Complete Example

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Student
{
    string name;
    int marks;
};

struct CompareStudent
{
    bool operator()(
        const Student& a,
        const Student& b
    ) const
    {
        // Higher marks first.
        if (a.marks != b.marks)
            return a.marks > b.marks;

        // Equal marks -> alphabetical name.
        return a.name < b.name;
    }
};

struct IsPassed
{
    bool operator()(
        const Student& s
    ) const
    {
        return s.marks >= 40;
    }
};

int main()
{
    vector<Student> students = {
        {"Riya", 85},
        {"Aman", 90},
        {"Karan", 85},
        {"Neha", 35}
    };

    sort(
        students.begin(),
        students.end(),
        CompareStudent()
    );

    for (const auto& s : students)
    {
        cout << s.name
             << " "
             << s.marks
             << "\n";
    }

    int passed = count_if(
        students.begin(),
        students.end(),
        IsPassed()
    );

    cout << "Passed = "
         << passed
         << "\n";

    return 0;
}
```

---

# 34. `std::function` and Functors

A concrete functor:

```cpp
struct Square
{
    int operator()(int x) const
    {
        return x * x;
    }
};
```

can be stored as:

```cpp
std::function<int(int)> f = Square();

cout << f(5);
```

`std::function` is a **type-erased callable wrapper**.

It can hold compatible:

- function pointers
- lambdas
- functors
- other callable objects

Do not confuse a concrete functor type with `std::function`.

---

# 35. Generic Functor

```cpp
struct Less
{
    template <typename T>
    bool operator()(
        const T& a,
        const T& b
    ) const
    {
        return a < b;
    }
};
```

Usage:

```cpp
Less less;

cout << less(10, 20);
cout << less(2.5, 3.5);
```

---

# 36. Multiple `operator()` Overloads

```cpp
struct Calculator
{
    int operator()(int a, int b) const
    {
        return a + b;
    }

    double operator()(double a, double b) const
    {
        return a + b;
    }
};
```

Functors can therefore support multiple call signatures.

---

# 37. Comparator Should Not Modify Elements

Avoid:

```cpp
bool operator()(int& a, int& b)
{
    a++;
    return a < b;
}
```

Prefer:

```cpp
bool operator()(
    const int& a,
    const int& b
) const
{
    return a < b;
}
```

A comparator should describe ordering rather than mutate the values it compares.

---

# 38. One Type, Multiple Orderings

A class can have many independent comparators:

```cpp
struct Student
{
    string name;
    int marks;
};
```

Possible policies:

```text
CompareByMarks
CompareByName
CompareByMarksDescending
CompareByNameLength
```

Then:

```cpp
sort(
    students.begin(),
    students.end(),
    CompareByMarks()
);
```

or:

```cpp
sort(
    students.begin(),
    students.end(),
    CompareByName()
);
```

This is a major reason to use external comparators.

---

# 39. Functor vs Function Pointer

Function:

```cpp
bool greaterThan(int a, int b)
{
    return a > b;
}
```

Function pointer:

```cpp
bool (*cmp)(int, int) = greaterThan;
```

Functor:

```cpp
struct Greater
{
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};
```

Functor advantage:

```text
can carry state
```

Modern C++ often uses lambdas for short local policies.

---

# 40. Complete Usage Table

| STL Feature      | Callable/Comparator Role |
| ---------------- | ------------------------ |
| `sort`           | comparator               |
| `stable_sort`    | comparator               |
| `find_if`        | unary predicate          |
| `count_if`       | unary predicate          |
| `all_of`         | unary predicate          |
| `any_of`         | unary predicate          |
| `none_of`        | unary predicate          |
| `for_each`       | callable                 |
| `transform`      | callable                 |
| `min_element`    | comparator overload      |
| `max_element`    | comparator overload      |
| `lower_bound`    | comparator overload      |
| `upper_bound`    | comparator overload      |
| `equal_range`    | comparator overload      |
| `binary_search`  | comparator overload      |
| `is_sorted`      | comparator overload      |
| `set`            | ordering comparator      |
| `multiset`       | ordering comparator      |
| `map`            | key ordering comparator  |
| `multimap`       | key ordering comparator  |
| `priority_queue` | heap comparator          |
| `unordered_set`  | hash + equality          |
| `unordered_map`  | hash + equality          |

---

# 41. Final Mental Model

```text
FUNCTOR
    object that can be called

        object(args)


PREDICATE
    callable representing a condition

        true / false


COMPARATOR
    binary callable defining an ordering

        "Should a come before b?"


SORT
    comparator -> sequence ordering


SET / MAP
    comparator -> ordered keys + equivalence


PRIORITY_QUEUE
    comparator -> heap priority


UNORDERED CONTAINERS
    hash + equality
```

---

# 42. Golden Rules

1. A functor is an object with callable behavior, usually through `operator()`.

2. A predicate represents a boolean condition.

3. A comparator is generally a binary callable used to define an ordering.

4. For ordered STL operations, use a valid **strict weak ordering**.

5. Do not normally use:

```cpp
a <= b
```

as a strict comparator.

Prefer:

```cpp
a < b
```

6. When writing a comparator, ask:

```text
"Should a come before b?"
```

7. For multiple keys:

```cpp
if (primary differs)
    return primary rule;

return secondary rule;
```

8. `set` equivalence is:

```cpp
!comp(a,b) && !comp(b,a)
```

not necessarily `a == b`.

9. `unordered_set` and `unordered_map` are hash-based, not ordered by comparator.

10. `priority_queue` comparator controls heap priority; reason specifically about what should reach `top()`.

---

# 43. Final One-Page Cheat Sheet

```cpp
// FUNCTOR
struct F
{
    ReturnType operator()(args...) const
    {
        ...
    }
};

// UNARY PREDICATE
struct IsEven
{
    bool operator()(int x) const
    {
        return x % 2 == 0;
    }
};

// COMPARATOR
struct Descending
{
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};

// SORT
sort(
    v.begin(),
    v.end(),
    Descending()
);

// SET
set<int, greater<int>> s;

// MAP
map<int, string, greater<int>> mp;

// MIN HEAP
priority_queue<
    int,
    vector<int>,
    greater<int>
> pq;

// STATEFUL FUNCTOR
struct GreaterThan
{
    int limit;

    GreaterThan(int x) : limit(x) {}

    bool operator()(int x) const
    {
        return x > limit;
    }
};

// PREDICATE
count_if(
    v.begin(),
    v.end(),
    GreaterThan(50)
);
```

---

# 44. Final Summary

```text
FUNCTOR
    =
    callable object

PREDICATE
    =
    callable representing a condition

COMPARATOR
    =
    binary callable establishing ordering

operator()
    =
    makes object callable

less<>
    =
    ascending-style ordering

greater<>
    =
    descending-style ordering

sort
    =
    comparator controls sequence order

set/map
    =
    comparator controls ordered-key structure

priority_queue
    =
    comparator controls heap priority

unordered containers
    =
    hash + equality, not ordering comparator

strict weak ordering
    =
    essential requirement for comparator-based ordering
```
