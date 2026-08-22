/*
===============================================================================
        C++ STL SEARCHING & FINDING ALGORITHMS
        DETAILED NOTES + CONTAINER COMPATIBILITY + RUNNABLE EXAMPLES
===============================================================================

IMPORTANT:
    This is a COMPLETE reference file.

    It contains:
        1. Detailed theory
        2. Which container each algorithm works with
        3. Which container it does NOT work with / should not be used with
        4. Why
        5. Iterator requirements
        6. Sorted vs unsorted requirement
        7. Complexity
        8. DSA patterns
        9. Runnable examples

===============================================================================
CONTAINERS COVERED
===============================================================================

    vector
    array
    deque
    list
    forward_list
    set
    multiset
    map
    multimap
    unordered_set
    unordered_multiset
    unordered_map
    unordered_multimap

===============================================================================
ITERATOR CATEGORIES
===============================================================================

vector
    -> Random Access + Contiguous

array
    -> Random Access + Contiguous

deque
    -> Random Access

list
    -> Bidirectional

forward_list
    -> Forward

set / multiset
    -> Bidirectional
    -> sorted automatically

map / multimap
    -> Bidirectional
    -> sorted by KEY automatically

unordered_set / unordered_map
    -> Forward
    -> NOT sorted
    -> hash based


===============================================================================
MASTER COMPATIBILITY TABLE
===============================================================================

Legend:

    YES = algorithm can operate on that container's iterator range
    *   = special condition/note applies
    NO  = not appropriate / sorted-range requirement is not satisfied

Algorithm          vector array deque list fwd_list set/map unordered
----------------------------------------------------------------------
find                YES   YES   YES  YES   YES      YES      YES
find_if             YES   YES   YES  YES   YES      YES      YES
count               YES   YES   YES  YES   YES      YES      YES
count_if            YES   YES   YES  YES   YES      YES      YES

binary_search       YES   YES   YES  YES*  YES*     YES*     NO
lower_bound         YES   YES   YES  YES*  YES*     YES*     NO
upper_bound         YES   YES   YES  YES*  YES*     YES*     NO
equal_range         YES   YES   YES  YES*  YES*     YES*     NO

search              YES   YES   YES  YES   YES      YES      YES
find_first_of       YES   YES   YES  YES   YES      YES      YES
adjacent_find       YES   YES   YES  YES   YES      YES      YES

WHY THE *?

    For generic binary_search/lower_bound/upper_bound/equal_range,
    the RANGE MUST BE SORTED according to the same ordering.

    list and forward_list can be sorted using their member sort()
    functions, so they can provide sorted ranges.

    set/map are already sorted, so their MEMBER LOOKUP FUNCTIONS
    are usually preferable.

    unordered containers are NOT sorted, so sorted-range algorithms
    are not appropriate.

===============================================================================
1. find()
===============================================================================

HEADER:
    <algorithm>

REQUIRED ITERATOR:
    Input Iterator

SORTED RANGE:
    NO

PURPOSE:
    Exact value ko find karna.

SYNTAX:

    auto it = find(
        container.begin(),
        container.end(),
        target
    );

RETURN:
    Found:
        iterator pointing to target

    Not found:
        container.end()

IMPORTANT:

    if (it != v.end())
    {
        cout << *it;
    }

    Never dereference end().

COMPLEXITY:
    O(n)

CONTAINERS:
    vector          YES
    array           YES
    deque           YES
    list            YES
    forward_list    YES
    set             YES
    multiset        YES
    map             YES
    multimap        YES
    unordered_set   YES
    unordered_map   YES

BUT:

    set:
        s.find(x)

    map:
        mp.find(key)

    unordered_set:
        us.find(x)

    unordered_map:
        um.find(key)

are normally better because they use the container's own lookup
structure.


===============================================================================
2. find_if()
===============================================================================

HEADER:
    <algorithm>

REQUIRED:
    Input Iterator

SORTED:
    NO

PURPOSE:
    Predicate/condition satisfy karne wala FIRST element.

Example predicate:

    bool isEven(int x)
    {
        return x % 2 == 0;
    }

Example:

    vector<int> v = {
        11, 15, 27, 28, 31
    };

    auto it = find_if(
        v.begin(),
        v.end(),
        isEven
    );

Result:
    28

COMPLEXITY:
    O(n)

CONTAINERS:
    ALL standard containers with readable iterators.


===============================================================================
3. count()
===============================================================================

REQUIRED:
    Input Iterator

SORTED:
    NO

PURPOSE:
    Exact value ki occurrences count karna.

Example:

    10 20 10 30 10

    count(..., 10)

    -> 3

COMPLEXITY:
    O(n)

CONTAINERS:
    All standard containers.


===============================================================================
4. count_if()
===============================================================================

REQUIRED:
    Input Iterator

SORTED:
    NO

PURPOSE:
    Predicate true hone wale elements count karna.

Example:

    1 2 3 4 5 6

    count_if(..., isEven)

    -> 3

COMPLEXITY:
    O(n)

CONTAINERS:
    All standard containers.


===============================================================================
5. binary_search()
===============================================================================

HEADER:
    <algorithm>

REQUIRED:
    SORTED RANGE

RETURN:
    bool

PURPOSE:
    "Target exists or not?"

Example:

    vector<int> v = {
        10, 20, 30, 40, 50
    };

    binary_search(
        v.begin(),
        v.end(),
        30
    );

    -> true

For 35:
    -> false

IMPORTANT:
    binary_search() iterator return nahi karta.
    It returns only true/false.

COMPLEXITY:
    Random-access range:
        O(log n)

    With weaker iterators:
        comparisons are logarithmic, but iterator movement may be
        linear.

CONTAINER NOTES:

vector:
    YES, if sorted.
    Very efficient because random access.

array:
    YES, if sorted.

deque:
    YES, if sorted.

list:
    YES, if sorted.
    But list iterator is not random access, so generic algorithm
    does not get vector-like iterator movement performance.

forward_list:
    YES, if sorted.
    Same weaker iterator consideration.

set/multiset:
    Range is already sorted.
    But prefer:
        s.find(x)
        s.lower_bound(x)
        s.upper_bound(x)

map/multimap:
    Range is sorted by pair/key ordering.
    But for searching a key, prefer map member functions.

unordered_set/unordered_map:
    NO for the sorted-range binary-search use case.
    They are not sorted.


===============================================================================
6. lower_bound()
===============================================================================

MOST IMPORTANT DEFINITION:

    lower_bound(x)
        =
    first element >= x

REQUIRED:
    Sorted range

RETURN:
    iterator

Example:

    v = {
        10, 20, 30, 30, 30, 40, 50
    };

    lower_bound(30)

    -> first 30

    lower_bound(25)

    -> 30

    lower_bound(35)

    -> 40

    lower_bound(60)

    -> end()


VISUAL:

    10 20 | 30 30 30 40 50
           ^
           |
       lower_bound(30)


FORMULA:

    [ values < x ] [ values >= x ]
                    ^
                    answer


COMPLEXITY:
    Random access:
        O(log n) comparisons

    Weaker iterators:
        iterator movement can be O(n)


CONTAINERS:

vector:
    YES, sorted

array:
    YES, sorted

deque:
    YES, sorted

list:
    YES, sorted

forward_list:
    YES, sorted

set:
    YES, already sorted
    Prefer:
        s.lower_bound(x)

multiset:
    YES, already sorted
    Prefer:
        ms.lower_bound(x)

map:
    YES conceptually for ordered ranges
    Prefer:
        mp.lower_bound(key)

multimap:
    YES
    Prefer:
        mm.lower_bound(key)

unordered_set:
    NO
    Not sorted

unordered_map:
    NO
    Not sorted


===============================================================================
7. upper_bound()
===============================================================================

MOST IMPORTANT DEFINITION:

    upper_bound(x)
        =
    first element > x

Example:

    10 20 30 30 30 40 50

    upper_bound(30)

    -> 40

Why?

Because upper_bound wants:

    strictly greater than 30

All 30s are skipped.

FORMULA:

    [ values <= x ] [ values > x ]
                     ^
                     answer


CONTAINERS:
    Same sorted-range rule as lower_bound().


===============================================================================
8. lower_bound VS upper_bound
===============================================================================

Suppose:

    10 20 30 30 30 40 50

Target:
    30

lower_bound(30):
    first 30

upper_bound(30):
    first element > 30
    -> 40


VISUAL:

    10 20 | 30 30 30 | 40 50
           ^           ^
           |           |
         lower       upper


MEMORY:

    LOWER:
        >= x

    UPPER:
        > x


===============================================================================
9. equal_range()
===============================================================================

equal_range(x) is basically:

    {
        lower_bound(x),
        upper_bound(x)
    }

RETURN:
    pair of iterators

Example:

    auto p = equal_range(
        v.begin(),
        v.end(),
        30
    );

Then:

    p.first
        -> lower_bound(30)

    p.second
        -> upper_bound(30)


Matching range:

    [p.first, p.second)


IMPORTANT:
    second is EXCLUSIVE.


===============================================================================
10. COUNT OCCURRENCES WITH EQUAL_RANGE
===============================================================================

Sorted vector:

    10 20 30 30 30 40 50

For 30:

    lower_bound -> index 2
    upper_bound -> index 5

Therefore:

    count = 5 - 2
          = 3

Code:

    auto p = equal_range(
        v.begin(),
        v.end(),
        30
    );

    int count = p.second - p.first;

This subtraction works directly for vector because vector iterators
are Random Access.

For list:

    distance(p.first, p.second)

must be used instead of iterator subtraction.


===============================================================================
11. FIRST OCCURRENCE
===============================================================================

Sorted vector:

    10 20 30 30 30 40

First 30:

    lower_bound(30)

DSA answer:
    FIRST OCCURRENCE = lower_bound()


===============================================================================
12. LAST OCCURRENCE
===============================================================================

Sorted vector:

    10 20 30 30 30 40

Use:

    upper_bound(30)

This gives iterator to:

    40

Therefore:

    upper_bound(30) - 1

points to:

    last 30

IMPORTANT:
    Boundary check before --it or -1.


===============================================================================
13. DOES X EXIST?
===============================================================================

Option 1:

    binary_search(
        v.begin(),
        v.end(),
        x
    );

Option 2:

    auto it = lower_bound(
        v.begin(),
        v.end(),
        x
    );

    if (
        it != v.end()
        &&
        *it == x
    )
    {
        // found
    }

WHY OPTION 2 WORKS:

    lower_bound returns first element >= x.

If that element equals x:
    x exists.


===============================================================================
14. search()
===============================================================================

IMPORTANT:
    search() and binary_search() are completely different.

search():
    Finds a SUBRANGE/PATTERN inside another range.

SORTED?
    NO

Example:

Main:
    1 2 3 4 5 6

Pattern:
    3 4 5

search() returns iterator to first 3 of the matching sequence.

SYNTAX:

    auto it = search(
        main.begin(),
        main.end(),
        pattern.begin(),
        pattern.end()
    );

CONTAINERS:
    vector, array, deque, list, forward_list,
    set/map and unordered containers can be traversed.

NOTE:
    For associative containers, a sequence pattern based on their
    iteration order is rarely the operation you actually want.
    For key lookup, use member functions.


===============================================================================
15. find_first_of()
===============================================================================

PURPOSE:
    First range mein woh FIRST element find karo jo second range ke
    KISI bhi element ke equal ho.

Example:

main:
    10 20 30 40 50

targets:
    35 30 50

Result:
    30

Because 30 is the first main-range element that appears in targets.

SORTED?
    NO

COMPLEXITY:
    Typically O(n * m)

CONTAINERS:
    Generic readable iterator ranges.


===============================================================================
16. adjacent_find()
===============================================================================

PURPOSE:
    First adjacent matching pair.

Example:

    1 2 3 3 4 5

adjacent_find():

    points to first 3.

It finds:
    v[i] == v[i+1]

CUSTOM PREDICATE:
    Also possible.

Example:
    adjacent elements whose sum is greater than 10.


===============================================================================
17. set SEARCHING
===============================================================================

set is:

    sorted
    unique

Use:

    s.find(x)

    s.lower_bound(x)

    s.upper_bound(x)

    s.equal_range(x)

Do NOT normally use generic:

    find(s.begin(), s.end(), x)

because generic find is linear while set member lookup is logarithmic.

COMPLEXITY:

    s.find()
        O(log n)

    s.lower_bound()
        O(log n)

    s.upper_bound()
        O(log n)


===============================================================================
18. multiset SEARCHING
===============================================================================

multiset is:

    sorted
    duplicates allowed

Example:

    10 20 20 20 30

Use:

    ms.find(20)

Use:

    ms.count(20)

Result:
    3

Use:

    ms.lower_bound(20)
    ms.upper_bound(20)

or:

    ms.equal_range(20)

to get all 20s.


===============================================================================
19. map SEARCHING
===============================================================================

map stores:

    key -> value

Example:

    1 -> "one"
    2 -> "two"
    3 -> "three"

Search by KEY:

    auto it = mp.find(2);

If found:

    it->first
        = key

    it->second
        = value

Also:

    mp.lower_bound(key)
    mp.upper_bound(key)
    mp.equal_range(key)

IMPORTANT:
    map is sorted by key.


===============================================================================
20. multimap SEARCHING
===============================================================================

multimap allows duplicate keys.

Example:

    1 -> A
    1 -> B
    1 -> C

Use:

    auto p = mm.equal_range(1);

Then:

    for (
        auto it = p.first;
        it != p.second;
        ++it
    )
    {
        cout << it->second;
    }


===============================================================================
21. unordered_set SEARCHING
===============================================================================

unordered_set is hash-based.

It is NOT sorted.

Use:

    us.find(x)

Average:
    O(1)

Worst case:
    O(n)

Do NOT use:

    lower_bound()
    upper_bound()
    binary_search()

because those generic algorithms assume sorted order.


===============================================================================
22. unordered_map SEARCHING
===============================================================================

Use:

    um.find(key)

Average:
    O(1)

Worst case:
    O(n)

It is NOT sorted.

Therefore generic sorted-range:

    lower_bound
    upper_bound
    binary_search

are not appropriate.


===============================================================================
23. VERY IMPORTANT COMPARISON
===============================================================================

SEARCH 30 IN DIFFERENT CONTAINERS

vector UNSORTED:
    find()
    O(n)

vector SORTED:
    binary_search()
    O(log n)

set:
    s.find(30)
    O(log n)

unordered_set:
    us.find(30)
    average O(1)


===============================================================================
24. WHICH ALGORITHM WHEN?
===============================================================================

QUESTION:
    "Is x present?"

UNSORTED:
    find()

SORTED VECTOR:
    binary_search()


QUESTION:
    "Where is first x?"

SORTED:
    lower_bound()


QUESTION:
    "Where does x stop?"

SORTED:
    upper_bound()


QUESTION:
    "How many x?"

UNSORTED:
    count()

SORTED VECTOR:
    upper_bound(x) - lower_bound(x)


QUESTION:
    "Give me all x positions/range"

SORTED:
    equal_range()


QUESTION:
    "Find a pattern/subarray"

    search()


QUESTION:
    "Find first element belonging to another range"

    find_first_of()


QUESTION:
    "Find adjacent duplicate"

    adjacent_find()


===============================================================================
25. CONTAINER-WISE SUMMARY
===============================================================================

VECTOR
------

find:
    YES

find_if:
    YES

count:
    YES

count_if:
    YES

binary_search:
    YES, if sorted

lower_bound:
    YES, if sorted

upper_bound:
    YES, if sorted

equal_range:
    YES, if sorted

search:
    YES

find_first_of:
    YES

adjacent_find:
    YES


ARRAY
-----

Same generic searching algorithms as vector.

binary_search/lower_bound/etc:
    YES if sorted.


DEQUE
-----

Same as vector for these generic algorithms.

binary_search/lower_bound/etc:
    YES if sorted.


LIST
----

find:
    YES

find_if:
    YES

count:
    YES

binary_search:
    YES if sorted

lower_bound:
    YES if sorted

upper_bound:
    YES if sorted

equal_range:
    YES if sorted

search:
    YES

IMPORTANT:
    list iterator is Bidirectional, not Random Access.

Therefore:
    it2 - it1

does NOT work.

Use:

    distance(it1, it2)


FORWARD_LIST
------------

find:
    YES

find_if:
    YES

count:
    YES

binary_search:
    YES if sorted

lower_bound:
    YES if sorted

upper_bound:
    YES if sorted

equal_range:
    YES if sorted

search:
    YES

IMPORTANT:
    Only Forward Iterator.

No:

    it2 - it1


SET
---

Already sorted.

Generic:
    lower_bound
    upper_bound
    binary_search

can be conceptually used on the range.

BUT prefer member functions:

    s.find()
    s.lower_bound()
    s.upper_bound()
    s.equal_range()

Why?
    Tree structure is designed for these operations.


MULTISET
--------

Same as set, but duplicate values allowed.

Use:

    ms.count()
    ms.lower_bound()
    ms.upper_bound()
    ms.equal_range()


MAP
---

Sorted by KEY.

For key search use:

    mp.find()
    mp.lower_bound()
    mp.upper_bound()
    mp.equal_range()


MULTIMAP
--------

Sorted by KEY.
Duplicate keys allowed.

Use:
    mm.equal_range(key)


UNORDERED_SET
-------------

NOT SORTED.

Use:
    us.find()
    us.count()
    us.equal_range()

Do not use sorted-range binary search algorithms.


UNORDERED_MAP
-------------

NOT SORTED.

Use:
    um.find()
    um.count()
    um.equal_range()

Do not use sorted-range binary search algorithms.


===============================================================================
26. COMPLEXITY CHEAT SHEET
===============================================================================

Generic algorithms:

find:
    O(n)

find_if:
    O(n)

count:
    O(n)

count_if:
    O(n)

search:
    generally O(n*m)

find_first_of:
    generally O(n*m)

adjacent_find:
    O(n)


Sorted random-access range:

binary_search:
    O(log n) comparisons

lower_bound:
    O(log n) comparisons

upper_bound:
    O(log n) comparisons

equal_range:
    O(log n) comparisons


Container member operations:

set.find:
    O(log n)

set.lower_bound:
    O(log n)

map.find:
    O(log n)

unordered_set.find:
    average O(1)

unordered_map.find:
    average O(1)


===============================================================================
27. COMMON ERRORS
===============================================================================

ERROR 1:
    binary_search on unsorted data.

WRONG:

    vector<int> v = {
        40, 10, 30, 20
    };

    binary_search(
        v.begin(),
        v.end(),
        30
    );

FIX:

    sort(v.begin(), v.end());

    binary_search(...)


ERROR 2:
    Dereferencing end():

WRONG:

    auto it = find(...);

    cout << *it;

FIX:

    if (it != v.end())
        cout << *it;


ERROR 3:
    Thinking lower_bound means exact search.

FALSE.

lower_bound:
    first >= x

It can return a different value.


ERROR 4:
    Thinking upper_bound returns last x.

FALSE.

upper_bound:
    first > x

Last occurrence:
    upper_bound(x) - 1

with boundary checks.


ERROR 5:
    Using generic find() on unordered_set expecting O(1).

Generic find:
    O(n)

Member:
    us.find(x)
    average O(1)


ERROR 6:
    Iterator subtraction on list.

WRONG:

    r - l

FIX:

    distance(l, r)


===============================================================================
28. FINAL MEMORY MAP
===============================================================================

UNSORTED RANGE
    |
    +--> find()
    |
    +--> find_if()
    |
    +--> count()
    |
    +--> count_if()
    |
    +--> search()
    |
    +--> find_first_of()
    |
    +--> adjacent_find()


SORTED RANGE
    |
    +--> binary_search()
    |       -> exists?
    |
    +--> lower_bound()
    |       -> first >= x
    |
    +--> upper_bound()
    |       -> first > x
    |
    +--> equal_range()
            -> [lower_bound, upper_bound)


DSA:
    first occurrence
        -> lower_bound

    last occurrence
        -> upper_bound - 1

    count in sorted vector
        -> upper_bound - lower_bound

    existence
        -> binary_search

    all equal elements
        -> equal_range


CONTAINER MEMBER LOOKUP
    |
    +--> set.find()
    +--> set.lower_bound()
    +--> set.upper_bound()
    +--> map.find()
    +--> map.lower_bound()
    +--> unordered_set.find()
    +--> unordered_map.find()


===============================================================================
END OF THEORY
===============================================================================
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

// ============================================================================
// IMPORTANT: HELPER FUNCTION
// ============================================================================
// This function MUST be declared before demoFindIf() and demoCount().
// Otherwise compiler gives:
//     'isEven' was not declared in this scope
//
// This was the exact error in the previous file.
// ============================================================================

bool isEven(int x)
{
    return x % 2 == 0;
}

// ============================================================================
// 1. find()
// ============================================================================

void demoFind()
{
    vector<int> v = {
        10, 20, 30, 40};

    auto it = find(
        v.begin(),
        v.end(),
        30);

    if (it != v.end())
    {
        cout << "find(30) -> "
             << *it
             << '\n';
    }
    else
    {
        cout << "find(30) -> Not found\n";
    }
}

// ============================================================================
// 2. find_if()
// ============================================================================

void demoFindIf()
{
    vector<int> v = {
        11, 15, 27, 28, 31};

    auto it = find_if(
        v.begin(),
        v.end(),
        isEven);

    if (it != v.end())
    {
        cout << "find_if(isEven) -> "
             << *it
             << '\n';
    }
    else
    {
        cout << "No even element\n";
    }
}

// ============================================================================
// 3. count() / count_if()
// ============================================================================

void demoCount()
{
    vector<int> v = {
        10, 20, 10, 30, 10, 40};

    cout << "count(10) -> "
         << count(
                v.begin(),
                v.end(),
                10)
         << '\n';

    cout << "count_if(isEven) -> "
         << count_if(
                v.begin(),
                v.end(),
                isEven)
         << '\n';
}

// ============================================================================
// 4. binary_search()
// ============================================================================

void demoBinarySearch()
{
    vector<int> v = {
        10, 20, 30, 40, 50};

    bool found = binary_search(
        v.begin(),
        v.end(),
        30);

    cout << boolalpha;

    cout << "binary_search(30) -> "
         << found
         << '\n';
}

// ============================================================================
// 5. lower_bound()
// ============================================================================

void demoLowerBound()
{
    vector<int> v = {
        10, 20, 30, 30, 30, 40, 50};

    int x = 30;

    auto it = lower_bound(
        v.begin(),
        v.end(),
        x);

    if (it != v.end())
    {
        cout << "lower_bound(30) -> "
             << *it
             << '\n';

        cout << "Index -> "
             << it - v.begin()
             << '\n';
    }
}

// ============================================================================
// 6. upper_bound()
// ============================================================================

void demoUpperBound()
{
    vector<int> v = {
        10, 20, 30, 30, 30, 40, 50};

    int x = 30;

    auto it = upper_bound(
        v.begin(),
        v.end(),
        x);

    if (it != v.end())
    {
        cout << "upper_bound(30) -> "
             << *it
             << '\n';

        cout << "Index -> "
             << it - v.begin()
             << '\n';
    }
    else
    {
        cout << "upper_bound(30) -> end()\n";
    }
}

// ============================================================================
// 7. equal_range()
// ============================================================================

void demoEqualRange()
{
    vector<int> v = {
        10, 20, 30, 30, 30, 40, 50};

    auto p = equal_range(
        v.begin(),
        v.end(),
        30);

    cout << "equal_range(30):\n";

    cout << "first index  -> "
         << p.first - v.begin()
         << '\n';

    cout << "second index -> "
         << p.second - v.begin()
         << '\n';

    cout << "occurrences  -> "
         << p.second - p.first
         << '\n';
}

// ============================================================================
// 8. First occurrence + Last occurrence
// ============================================================================

void demoFirstLast()
{
    vector<int> v = {
        10, 20, 30, 30, 30, 40, 50};

    int x = 30;

    // FIRST occurrence.
    auto first = lower_bound(
        v.begin(),
        v.end(),
        x);

    if (
        first != v.end() &&
        *first == x)
    {
        cout << "First occurrence index -> "
             << first - v.begin()
             << '\n';
    }
    else
    {
        cout << "Value does not exist\n";
    }

    // LAST occurrence.
    auto afterLast = upper_bound(
        v.begin(),
        v.end(),
        x);

    if (afterLast != v.begin())
    {
        auto last = afterLast - 1;

        if (*last == x)
        {
            cout << "Last occurrence index -> "
                 << last - v.begin()
                 << '\n';
        }
    }
}

// ============================================================================
// 9. search() - pattern
// ============================================================================

void demoSearch()
{
    vector<int> mainArray = {
        1, 2, 3, 4, 5, 6};

    vector<int> pattern = {
        3, 4, 5};

    auto it = search(
        mainArray.begin(),
        mainArray.end(),
        pattern.begin(),
        pattern.end());

    if (it != mainArray.end())
    {
        cout << "search(pattern) index -> "
             << it - mainArray.begin()
             << '\n';
    }
    else
    {
        cout << "Pattern not found\n";
    }
}

// ============================================================================
// 10. find_first_of()
// ============================================================================

void demoFindFirstOf()
{
    vector<int> v = {
        10, 20, 30, 40, 50};

    vector<int> targets = {
        35, 30, 50};

    auto it = find_first_of(
        v.begin(),
        v.end(),
        targets.begin(),
        targets.end());

    if (it != v.end())
    {
        cout << "find_first_of() -> "
             << *it
             << '\n';
    }
}

// ============================================================================
// 11. adjacent_find()
// ============================================================================

void demoAdjacentFind()
{
    vector<int> v = {
        1, 2, 3, 3, 4, 5};

    auto it = adjacent_find(
        v.begin(),
        v.end());

    if (it != v.end())
    {
        cout << "adjacent_find() -> "
             << *it
             << '\n';
    }
}

// ============================================================================
// 12. set
// ============================================================================

void demoSet()
{
    set<int> s = {
        10, 20, 30, 40, 50};

    auto it = s.find(30);

    if (it != s.end())
    {
        cout << "set.find(30) -> "
             << *it
             << '\n';
    }

    auto low = s.lower_bound(25);

    if (low != s.end())
    {
        cout << "set.lower_bound(25) -> "
             << *low
             << '\n';
    }

    auto high = s.upper_bound(30);

    if (high != s.end())
    {
        cout << "set.upper_bound(30) -> "
             << *high
             << '\n';
    }
}

// ============================================================================
// 13. multiset
// ============================================================================

void demoMultiset()
{
    multiset<int> ms = {
        10, 20, 20, 20, 30};

    cout << "multiset.count(20) -> "
         << ms.count(20)
         << '\n';

    auto range = ms.equal_range(20);

    cout << "multiset equal_range(20) -> ";

    for (
        auto it = range.first;
        it != range.second;
        ++it)
    {
        cout << *it << ' ';
    }

    cout << '\n';
}

// ============================================================================
// 14. map
// ============================================================================

void demoMap()
{
    map<int, string> mp = {
        {1, "one"},
        {2, "two"},
        {3, "three"}};

    auto it = mp.find(2);

    if (it != mp.end())
    {
        cout << "map.find(2) -> "
             << it->second
             << '\n';
    }

    auto low = mp.lower_bound(2);

    if (low != mp.end())
    {
        cout << "map.lower_bound(2) -> key "
             << low->first
             << '\n';
    }
}

// ============================================================================
// 15. multimap
// ============================================================================

void demoMultimap()
{
    multimap<int, string> mm;

    mm.insert({1, "A"});
    mm.insert({1, "B"});
    mm.insert({1, "C"});
    mm.insert({2, "D"});

    auto range = mm.equal_range(1);

    cout << "multimap key 1 values -> ";

    for (
        auto it = range.first;
        it != range.second;
        ++it)
    {
        cout << it->second << ' ';
    }

    cout << '\n';
}

// ============================================================================
// 16. unordered_set
// ============================================================================

void demoUnorderedSet()
{
    unordered_set<int> us = {
        10, 20, 30};

    /*
        NOT SORTED.

        Use member find().
    */

    auto it = us.find(20);

    if (it != us.end())
    {
        cout << "unordered_set.find(20) -> Found\n";
    }
}

// ============================================================================
// 17. unordered_map
// ============================================================================

void demoUnorderedMap()
{
    unordered_map<int, string> um = {
        {1, "one"},
        {2, "two"}};

    auto it = um.find(2);

    if (it != um.end())
    {
        cout << "unordered_map.find(2) -> "
             << it->second
             << '\n';
    }
}

// ============================================================================
// MAIN
// ============================================================================

int main()
{
    cout << "========== find() ==========\n";
    demoFind();

    cout << "\n========== find_if() ==========\n";
    demoFindIf();

    cout << "\n========== count() / count_if() ==========\n";
    demoCount();

    cout << "\n========== binary_search() ==========\n";
    demoBinarySearch();

    cout << "\n========== lower_bound() ==========\n";
    demoLowerBound();

    cout << "\n========== upper_bound() ==========\n";
    demoUpperBound();

    cout << "\n========== equal_range() ==========\n";
    demoEqualRange();

    cout << "\n========== First / Last occurrence ==========\n";
    demoFirstLast();

    cout << "\n========== search() ==========\n";
    demoSearch();

    cout << "\n========== find_first_of() ==========\n";
    demoFindFirstOf();

    cout << "\n========== adjacent_find() ==========\n";
    demoAdjacentFind();

    cout << "\n========== set ==========\n";
    demoSet();

    cout << "\n========== multiset ==========\n";
    demoMultiset();

    cout << "\n========== map ==========\n";
    demoMap();

    cout << "\n========== multimap ==========\n";
    demoMultimap();

    cout << "\n========== unordered_set ==========\n";
    demoUnorderedSet();

    cout << "\n========== unordered_map ==========\n";
    demoUnorderedMap();

    return 0;
}
