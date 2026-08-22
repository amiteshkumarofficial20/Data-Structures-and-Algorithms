/*
===============================================================================
             C++ STL MIN / MAX ALGORITHMS — COMPLETE DETAILED FILE
===============================================================================

TOPICS COVERED
---------------

1. min()
2. max()
3. min_element()
4. max_element()
5. minmax()
6. minmax_element()
7. min with initializer_list
8. max with initializer_list
9. custom comparator
10. min/max of vector
11. min/max of array
12. min/max of deque
13. min/max of list
14. min/max of forward_list
15. min/max of set
16. min/max of multiset
17. min/max of map
18. min/max of multimap
19. min/max of unordered containers
20. empty-container safety
21. iterator return values
22. difference between min() and min_element()
23. difference between max() and max_element()
24. difference between minmax() and minmax_element()
25. complexity
26. container compatibility
27. DSA patterns
28. common mistakes


===============================================================================
VERY IMPORTANT: min() VS min_element()
===============================================================================

This is the FIRST thing to understand.

min()
-----

    min(a, b)

takes VALUES.

Example:

    int a = 10;
    int b = 20;

    cout << min(a, b);

Output:

    10


min_element()
-------------

    min_element(first, last)

takes an ITERATOR RANGE and returns an ITERATOR.

Example:

    vector<int> v = {
        10, 20, 5, 40
    };

    auto it = min_element(
        v.begin(),
        v.end()
    );

    cout << *it;

Output:

    5


MEMORY:

    min()
        -> compares values

    min_element()
        -> searches a range and returns iterator


Similarly:

    max()
        -> compares values

    max_element()
        -> searches a range and returns iterator


===============================================================================
CONTAINER ITERATORS
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

set
    -> Bidirectional
    -> sorted automatically

multiset
    -> Bidirectional
    -> sorted automatically

map
    -> Bidirectional
    -> sorted by key

multimap
    -> Bidirectional
    -> sorted by key

unordered_set
    -> Forward
    -> NOT sorted

unordered_multiset
    -> Forward
    -> NOT sorted

unordered_map
    -> Forward
    -> NOT sorted

unordered_multimap
    -> Forward
    -> NOT sorted


===============================================================================
CONTAINER COMPATIBILITY — min_element / max_element
===============================================================================

Algorithm:

    min_element(begin, end)
    max_element(begin, end)

Requires:
    Forward Iterator

Therefore:

    vector              -> YES
    array               -> YES
    deque               -> YES
    list                -> YES
    forward_list        -> YES
    set                 -> YES
    multiset            -> YES
    map                 -> YES
    multimap            -> YES
    unordered_set       -> YES
    unordered_multiset  -> YES
    unordered_map       -> YES
    unordered_multimap  -> YES


IMPORTANT:

min_element() / max_element() do NOT require sorted data.

They scan the range.

So:

    unsorted vector -> YES
    sorted vector   -> YES
    unsorted list   -> YES
    set             -> YES
    unordered_set   -> YES


Complexity:

    O(n)

because every element may need to be checked.


===============================================================================
1. min()
===============================================================================

HEADER:

    #include <algorithm>

PURPOSE:

    Two values mein smaller value return karta hai.

SYNTAX:

    min(a, b)

Example:

    int a = 10;
    int b = 20;

    int ans = min(a, b);

    // ans = 10


IMPORTANT:

    min() does NOT return an iterator.

It returns:
    const T&

conceptually/reference to the smaller argument.

For normal int usage:

    int ans = min(a, b);


Works with:
    int
    long long
    double
    char
    string
    custom comparable types

provided comparison is valid.


COMPLEXITY:

    O(1)


===============================================================================
2. max()
===============================================================================

PURPOSE:

    Two values mein larger value return karta hai.

Example:

    int a = 10;
    int b = 20;

    int ans = max(a, b);

    // ans = 20


COMPLEXITY:

    O(1)


===============================================================================
3. min_element()
===============================================================================

HEADER:

    <algorithm>

PURPOSE:

    Entire iterator range mein minimum element find karta hai.

SYNTAX:

    auto it = min_element(
        first,
        last
    );


Example:

    vector<int> v = {
        40, 10, 50, 5, 30
    };

    auto it = min_element(
        v.begin(),
        v.end()
    );


Result:

    *it == 5


IMPORTANT:

    Return value iterator hai.

Therefore:

    cout << *it;


If you need index in vector:

    cout << it - v.begin();


COMPLEXITY:

    O(n)


REQUIRED:

    Forward Iterator


CONTAINERS:

    vector              YES
    array               YES
    deque               YES
    list                YES
    forward_list        YES
    set                 YES
    multiset            YES
    map                 YES
    multimap            YES
    unordered_set       YES
    unordered_multiset  YES
    unordered_map       YES
    unordered_multimap  YES


===============================================================================
4. max_element()
===============================================================================

Same concept as min_element().

It returns iterator to the largest element.

Example:

    vector<int> v = {
        40, 10, 50, 5, 30
    };

    auto it = max_element(
        v.begin(),
        v.end()
    );

    cout << *it;

Output:

    50


COMPLEXITY:

    O(n)


REQUIRED:

    Forward Iterator


===============================================================================
5. minmax()
===============================================================================

PURPOSE:

    TWO VALUES ka minimum aur maximum ek saath return karta hai.

Example:

    int a = 10;
    int b = 20;

    auto result = minmax(a, b);

Then:

    result.first
        -> minimum

    result.second
        -> maximum


Example:

    cout << result.first;
    cout << result.second;


Output:

    10 20


RETURN TYPE:

    pair


COMPLEXITY:

    O(1)


IMPORTANT:

    minmax() only works on the VALUES you give it.

For a container range use:

    minmax_element()


===============================================================================
6. minmax_element()
===============================================================================

PURPOSE:

    Range ka minimum AND maximum dono find karta hai.

SYNTAX:

    auto result = minmax_element(
        v.begin(),
        v.end()
    );


RETURN:

    pair<iterator, iterator>


Therefore:

    result.first
        -> iterator to minimum

    result.second
        -> iterator to maximum


Example:

    vector<int> v = {
        40, 10, 50, 5, 30
    };

    auto result = minmax_element(
        v.begin(),
        v.end()
    );


Then:

    *result.first
        -> 5

    *result.second
        -> 50


COMPLEXITY:

    O(n)


IMPORTANT:

    This is generally better than independently doing:

        min_element()
        max_element()

when you need both, because minmax_element can determine both
with an optimized comparison strategy.


===============================================================================
7. min_element() ON VECTOR
===============================================================================

vector:

    vector<int> v = {
        7, 2, 9, 1, 5
    };

    auto it = min_element(
        v.begin(),
        v.end()
    );

    cout << *it;

Output:

    1


Index:

    int index = it - v.begin();

Output:

    3


WHY index subtraction works?

Because vector iterator is Random Access.


===============================================================================
8. max_element() ON VECTOR
===============================================================================

    auto it = max_element(
        v.begin(),
        v.end()
    );

    cout << *it;


Index:

    it - v.begin()


Works because vector has Random Access Iterators.


===============================================================================
9. min_element() ON ARRAY
===============================================================================

std::array:

    array<int, 5> a = {
        10, 5, 30, 2, 20
    };

    auto it = min_element(
        a.begin(),
        a.end()
    );

    cout << *it;


Result:

    2


Works:

    YES


array has:
    Random Access + Contiguous iterators.


===============================================================================
10. min_element() ON DEQUE
===============================================================================

    deque<int> dq = {
        50, 20, 80, 10
    };

    auto it = min_element(
        dq.begin(),
        dq.end()
    );


Result:

    10


Works:
    YES


===============================================================================
11. min_element() ON LIST
===============================================================================

    list<int> li = {
        50, 10, 40, 5
    };

    auto it = min_element(
        li.begin(),
        li.end()
    );

    cout << *it;


Result:

    5


Works:
    YES


WHY?

min_element only requires:
    Forward Iterator

list gives:
    Bidirectional Iterator

Bidirectional is stronger than Forward.


IMPORTANT:

    it - li.begin()

does NOT work.

Because list iterator is not Random Access.

Use:

    distance(
        li.begin(),
        it
    );

to find position.


===============================================================================
12. min_element() ON FORWARD_LIST
===============================================================================

    forward_list<int> fl = {
        50, 20, 10, 40
    };

    auto it = min_element(
        fl.begin(),
        fl.end()
    );


Works:
    YES


Why?

min_element needs Forward Iterator.

forward_list provides Forward Iterator.


But:

    it - fl.begin()

does NOT work.

Use:

    distance(
        fl.begin(),
        it
    );


===============================================================================
13. min_element() ON SET
===============================================================================

    set<int> s = {
        50, 20, 10, 40
    };

set automatically stores:

    10 20 40 50


Therefore:

    *s.begin()

is already the minimum.


But generic:

    min_element(
        s.begin(),
        s.end()
    );

also works.

IMPORTANT PERFORMANCE / DESIGN POINT:

For set:

    s.begin()

is preferable for minimum.

For maximum:

    prev(s.end())

is preferable.

Why?

Because set is already sorted.

Generic min_element/max_element would scan all elements.


===============================================================================
14. max_element() ON SET
===============================================================================

Because set is sorted:

    prev(s.end())

gives the maximum element.

Generic:

    max_element(
        s.begin(),
        s.end()
    );

also works, but scans the range.


Therefore:

SET:

    minimum:
        *s.begin()

    maximum:
        *prev(s.end())


Complexity:

    *s.begin()
        O(1)

    *prev(s.end())
        O(1) for standard bidirectional set iterator movement by one


===============================================================================
15. MULTISET
===============================================================================

multiset is sorted and allows duplicates.

Example:

    multiset<int> ms = {
        10, 20, 20, 40, 5
    };


Stored order:

    5 10 20 20 40


Minimum:

    *ms.begin()


Maximum:

    *prev(ms.end())


Generic min_element/max_element also work.


===============================================================================
16. MAP
===============================================================================

map stores:

    key -> value

and is sorted by KEY.

Example:

    map<int, string> mp = {
        {3, "three"},
        {1, "one"},
        {2, "two"}
    };


Order:

    1 -> one
    2 -> two
    3 -> three


IMPORTANT:

If you use:

    min_element(
        mp.begin(),
        mp.end()
    );

the comparison is based on the map's value_type:

    pair<const Key, T>

By default, pair comparison first compares:
    key

Then:
    value if keys are equal.


Therefore generic min_element on map normally gives the smallest KEY
because map keys are unique.


For minimum key:

    mp.begin()


For maximum key:

    prev(mp.end())


===============================================================================
17. MAX VALUE IN MAP
===============================================================================

VERY IMPORTANT:

Suppose:

    map<int, int> mp = {
        {1, 500},
        {2, 100},
        {3, 300}
    };


Smallest KEY:
    1

Largest KEY:
    3


But what if we want:

    smallest VALUE?

Then:

    min_element(
        mp.begin(),
        mp.end(),
        comparator
    );

Example comparator:

    [](auto &a, auto &b)
    {
        return a.second < b.second;
    }


Then minimum VALUE:
    100


Similarly maximum VALUE:

    max_element(
        mp.begin(),
        mp.end(),
        comparator
    );


===============================================================================
18. MAP MINIMUM BY VALUE — DETAILED
===============================================================================

    map<int, int> mp = {
        {101, 500},
        {102, 100},
        {103, 300}
    };


We want minimum value.

Use:

    auto it = min_element(
        mp.begin(),
        mp.end(),
        [](const auto& a, const auto& b)
        {
            return a.second < b.second;
        }
    );


Then:

    it->first
        -> key

    it->second
        -> minimum value


Result:

    key = 102
    value = 100


IMPORTANT:

    Default min_element on map:
        compares pairs

    Custom comparator:
        can compare .second


===============================================================================
19. MULTIMAP
===============================================================================

multimap:

    sorted by key
    duplicate keys allowed


Generic min_element works.

By default:
    compares pair<const Key, T>

So minimum key is obtained first.


If minimum VALUE is needed:
    use custom comparator comparing second.


===============================================================================
20. UNORDERED_SET
===============================================================================

unordered_set is NOT sorted.

Example:

    unordered_set<int> us = {
        50, 10, 30, 5
    };


There is no:

    begin() == minimum

guarantee.

Therefore:

    *us.begin()

is NOT necessarily minimum.


Use:

    min_element(
        us.begin(),
        us.end()
    );


for minimum.

And:

    max_element(
        us.begin(),
        us.end()
    );


for maximum.


Complexity:
    O(n)


===============================================================================
21. UNORDERED_MAP
===============================================================================

unordered_map is NOT sorted.

Therefore:

    um.begin()

does NOT mean minimum key.

Use:

    min_element(
        um.begin(),
        um.end()
    );

for minimum according to pair comparison.

For minimum VALUE:
    custom comparator.


===============================================================================
22. EMPTY CONTAINER — VERY IMPORTANT
===============================================================================

If:

    vector<int> v;

is empty:

    min_element(
        v.begin(),
        v.end()
    );

returns:

    v.end()


Same for:

    max_element()
    minmax_element()


IMPORTANT:

Never do:

    cout << *min_element(
        v.begin(),
        v.end()
    );

without checking emptiness.


Safe:

    if (!v.empty())
    {
        auto it = min_element(
            v.begin(),
            v.end()
        );

        cout << *it;
    }


===============================================================================
23. min() WITH MORE THAN TWO VALUES
===============================================================================

Modern C++ allows initializer_list overload.

Example:

    int ans = min({
        10,
        20,
        5,
        40
    });


Result:

    5


Similarly:

    int ans = max({
        10,
        20,
        5,
        40
    });


Result:

    40


IMPORTANT:

For a CONTAINER RANGE:

    min({
        ...values...
    });

is not what we normally use.

Use:

    min_element(
        begin,
        end
    );


===============================================================================
24. minmax() WITH INITIALIZER_LIST
===============================================================================

Example:

    auto p = minmax({
        10,
        20,
        5,
        40
    });


Then:

    p.first
        -> 5

    p.second
        -> 40


For container:

    minmax_element(
        begin,
        end
    );


===============================================================================
25. CUSTOM COMPARATOR
===============================================================================

min_element() can receive a custom comparator.

Normal:

    min_element(
        v.begin(),
        v.end()
    );


Custom:

    min_element(
        v.begin(),
        v.end(),
        comparator
    );


Comparator returns true when first argument should be considered
"smaller" than second according to the chosen ordering.


===============================================================================
26. FIND MINIMUM ABSOLUTE VALUE
===============================================================================

Example:

    vector<int> v = {
        -10, 5, -3, 8
    };


Normal minimum:

    -10


But minimum absolute value:

    3


Use:

    auto it = min_element(
        v.begin(),
        v.end(),
        [](int a, int b)
        {
            return abs(a) < abs(b);
        }
    );


Result:

    -3


IMPORTANT:
    Custom comparator changes the meaning of "minimum".


===============================================================================
27. FIND MAXIMUM ABSOLUTE VALUE
===============================================================================

    auto it = max_element(
        v.begin(),
        v.end(),
        [](int a, int b)
        {
            return abs(a) < abs(b);
        }
    );


This finds the element with largest absolute value.


===============================================================================
28. MINIMUM STRING
===============================================================================

    vector<string> names = {
        "Zebra",
        "Apple",
        "Mango"
    };


    auto it = min_element(
        names.begin(),
        names.end()
    );


Result:

    "Apple"


Default comparison is lexicographical ordering.


===============================================================================
29. MAXIMUM STRING
===============================================================================

    auto it = max_element(
        names.begin(),
        names.end()
    );


Result:

    "Zebra"


===============================================================================
30. min() VS min_element() — EXAM/INTERVIEW
===============================================================================

min():

    min(a, b)


Input:
    two values


Output:
    value/reference


Complexity:
    O(1)


min_element():

    min_element(begin, end)


Input:
    range


Output:
    iterator


Complexity:
    O(n)


MEMORY:

    min()
        "MIN OF VALUES"

    min_element()
        "MIN ELEMENT OF RANGE"


===============================================================================
31. max() VS max_element()
===============================================================================

max():

    max(a, b)

    -> values

max_element():

    max_element(begin, end)

    -> range iterator


===============================================================================
32. minmax() VS minmax_element()
===============================================================================

minmax():

    minmax(a, b)

    -> pair of values


minmax_element():

    minmax_element(begin, end)

    -> pair of iterators


MEMORY:

    VALUE INPUT
        -> min / max / minmax

    RANGE INPUT
        -> min_element / max_element / minmax_element


===============================================================================
33. DSA: MINIMUM VALUE
===============================================================================

If given vector:

    vector<int> v = {
        10, 20, 5, 40
    };


Minimum:

    *min_element(
        v.begin(),
        v.end()
    );


Complexity:
    O(n)


===============================================================================
34. DSA: MAXIMUM VALUE
===============================================================================

Maximum:

    *max_element(
        v.begin(),
        v.end()
    );


Complexity:
    O(n)


===============================================================================
35. DSA: MINIMUM INDEX
===============================================================================

For vector:

    auto it = min_element(
        v.begin(),
        v.end()
    );

    int index = it - v.begin();


Because vector has Random Access.


For list:

    int index = distance(
        li.begin(),
        it
    );


===============================================================================
36. DSA: BOTH MIN AND MAX
===============================================================================

Use:

    auto p = minmax_element(
        v.begin(),
        v.end()
    );


Minimum:

    *p.first


Maximum:

    *p.second


This is convenient when both are required.


===============================================================================
37. CONTAINER-WISE QUICK TABLE
===============================================================================

Container          min_element   max_element   Special faster way
----------------------------------------------------------------------
vector                  YES          YES        none necessary
array                   YES          YES        none necessary
deque                   YES          YES        none necessary
list                    YES          YES        none necessary
forward_list            YES          YES        none necessary
set                     YES          YES        begin()/prev(end())
multiset                YES          YES        begin()/prev(end())
map                     YES          YES        begin()/prev(end()) for keys
multimap                YES          YES        begin()/prev(end()) for keys
unordered_set           YES          YES        must scan
unordered_multiset      YES          YES        must scan
unordered_map           YES          YES        must scan
unordered_multimap      YES          YES        must scan


===============================================================================
38. COMPLEXITY CHEAT SHEET
===============================================================================

min(a, b):
    O(1)

max(a, b):
    O(1)

minmax(a, b):
    O(1)

min({values...}):
    O(k)

max({values...}):
    O(k)

min_element(begin, end):
    O(n)

max_element(begin, end):
    O(n)

minmax_element(begin, end):
    O(n)


Special ordered containers:

set:
    minimum key:
        *s.begin()
        O(1)

    maximum key:
        *prev(s.end())
        O(1)


unordered containers:

    minimum:
        min_element(...)
        O(n)

    maximum:
        max_element(...)
        O(n)


===============================================================================
39. COMMON MISTAKES
===============================================================================

MISTAKE 1:

    cout << min_element(
        v.begin(),
        v.end()
    );


This prints an iterator/address-like representation incorrectly.

Correct:

    cout << *min_element(
        v.begin(),
        v.end()
    );


-------------------------------------------------------------------------------

MISTAKE 2:

    *min_element(
        v.begin(),
        v.end()
    );

when v is empty.

Wrong because returned iterator == end().

-------------------------------------------------------------------------------

MISTAKE 3:

    *s.begin()

assuming it works for unordered_set.

Wrong.

unordered_set is NOT sorted.

-------------------------------------------------------------------------------

MISTAKE 4:

    min_element(
        mp.begin(),
        mp.end()
    );

and assuming it finds minimum VALUE.

Default pair comparison is primarily by KEY.

For minimum VALUE use custom comparator on second.


-------------------------------------------------------------------------------

MISTAKE 5:

    it - li.begin()

for list.

Wrong.

Use:

    distance(li.begin(), it)


-------------------------------------------------------------------------------

MISTAKE 6:

    Confusing min() and min_element().

    min(a, b)
        -> values

    min_element(begin, end)
        -> iterator


===============================================================================
40. FINAL MEMORY MAP
===============================================================================

TWO VALUES:
    min(a, b)
        -> smaller value

    max(a, b)
        -> larger value

    minmax(a, b)
        -> pair {minimum, maximum}


RANGE:
    min_element(begin, end)
        -> iterator to minimum

    max_element(begin, end)
        -> iterator to maximum

    minmax_element(begin, end)
        -> pair of iterators


CONTAINER:
    vector/list/etc:
        min_element / max_element

    set/multiset:
        *begin()
        *prev(end())

    unordered containers:
        min_element / max_element
        because they are not sorted


===============================================================================
END
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
#include <cmath>
#include <iterator>

using namespace std;

// ============================================================================
// 1. min() and max()
// ============================================================================

void demoMinMax()
{
    int a = 10;
    int b = 20;

    cout << "min(10, 20) = "
         << min(a, b)
         << '\n';

    cout << "max(10, 20) = "
         << max(a, b)
         << '\n';
}

// ============================================================================
// 2. min_element() / max_element() on vector
// ============================================================================

void demoVector()
{
    vector<int> v = {
        40, 10, 50, 5, 30};

    auto minIt = min_element(
        v.begin(),
        v.end());

    auto maxIt = max_element(
        v.begin(),
        v.end());

    cout << "Vector minimum = "
         << *minIt
         << '\n';

    cout << "Vector maximum = "
         << *maxIt
         << '\n';

    // Vector has Random Access Iterators,
    // so iterator subtraction gives the index.

    cout << "Minimum index = "
         << minIt - v.begin()
         << '\n';

    cout << "Maximum index = "
         << maxIt - v.begin()
         << '\n';
}

// ============================================================================
// 3. minmax_element()
// ============================================================================

void demoMinMaxElement()
{
    vector<int> v = {
        40, 10, 50, 5, 30};

    auto result = minmax_element(
        v.begin(),
        v.end());

    cout << "minmax_element minimum = "
         << *result.first
         << '\n';

    cout << "minmax_element maximum = "
         << *result.second
         << '\n';
}

// ============================================================================
// 4. initializer_list
// ============================================================================

void demoInitializerList()
{
    int minimum = min({40,
                       10,
                       50,
                       5,
                       30});

    int maximum = max({40,
                       10,
                       50,
                       5,
                       30});

    auto both = minmax({40,
                        10,
                        50,
                        5,
                        30});

    cout << "min({values}) = "
         << minimum
         << '\n';

    cout << "max({values}) = "
         << maximum
         << '\n';

    cout << "minmax({values}) = "
         << both.first
         << ' '
         << both.second
         << '\n';
}

// ============================================================================
// 5. array
// ============================================================================

void demoArray()
{
    array<int, 5> a = {
        10, 50, 5, 30, 20};

    auto mn = min_element(
        a.begin(),
        a.end());

    auto mx = max_element(
        a.begin(),
        a.end());

    cout << "array min = "
         << *mn
         << '\n';

    cout << "array max = "
         << *mx
         << '\n';
}

// ============================================================================
// 6. deque
// ============================================================================

void demoDeque()
{
    deque<int> dq = {
        50, 20, 80, 10};

    auto mn = min_element(
        dq.begin(),
        dq.end());

    auto mx = max_element(
        dq.begin(),
        dq.end());

    cout << "deque min = "
         << *mn
         << '\n';

    cout << "deque max = "
         << *mx
         << '\n';
}

// ============================================================================
// 7. list
// ============================================================================

void demoList()
{
    list<int> li = {
        50, 10, 40, 5};

    auto mn = min_element(
        li.begin(),
        li.end());

    auto mx = max_element(
        li.begin(),
        li.end());

    cout << "list min = "
         << *mn
         << '\n';

    cout << "list max = "
         << *mx
         << '\n';

    // list does NOT support:
    //
    //     mn - li.begin()
    //
    // because list iterator is not Random Access.
    //
    // Use distance():

    cout << "Minimum position in list = "
         << distance(
                li.begin(),
                mn)
         << '\n';
}

// ============================================================================
// 8. forward_list
// ============================================================================

void demoForwardList()
{
    forward_list<int> fl = {
        50, 20, 10, 40};

    auto mn = min_element(
        fl.begin(),
        fl.end());

    auto mx = max_element(
        fl.begin(),
        fl.end());

    cout << "forward_list min = "
         << *mn
         << '\n';

    cout << "forward_list max = "
         << *mx
         << '\n';
}

// ============================================================================
// 9. set
// ============================================================================

void demoSet()
{
    set<int> s = {
        50, 10, 40, 5, 30};

    /*
        set automatically sorts:

            5 10 30 40 50

        Therefore:
            begin() -> minimum
            prev(end()) -> maximum
    */

    cout << "set minimum = "
         << *s.begin()
         << '\n';

    cout << "set maximum = "
         << *prev(s.end())
         << '\n';

    // Generic algorithms ALSO work:

    auto mn = min_element(
        s.begin(),
        s.end());

    auto mx = max_element(
        s.begin(),
        s.end());

    cout << "generic min_element(set) = "
         << *mn
         << '\n';

    cout << "generic max_element(set) = "
         << *mx
         << '\n';
}

// ============================================================================
// 10. multiset
// ============================================================================

void demoMultiset()
{
    multiset<int> ms = {
        50, 10, 10, 40, 5};

    /*
        multiset is sorted but allows duplicates.

            5 10 10 40 50
    */

    cout << "multiset minimum = "
         << *ms.begin()
         << '\n';

    cout << "multiset maximum = "
         << *prev(ms.end())
         << '\n';

    auto mn = min_element(
        ms.begin(),
        ms.end());

    auto mx = max_element(
        ms.begin(),
        ms.end());

    cout << "generic multiset min = "
         << *mn
         << '\n';

    cout << "generic multiset max = "
         << *mx
         << '\n';
}

// ============================================================================
// 11. map — minimum/maximum KEY
// ============================================================================

void demoMapKeys()
{
    map<int, string> mp = {
        {3, "three"},
        {1, "one"},
        {2, "two"}};

    /*
        map sorts by KEY:

            1 -> one
            2 -> two
            3 -> three
    */

    cout << "map minimum key = "
         << mp.begin()->first
         << '\n';

    cout << "map maximum key = "
         << prev(mp.end())->first
         << '\n';

    auto mn = min_element(
        mp.begin(),
        mp.end());

    auto mx = max_element(
        mp.begin(),
        mp.end());

    cout << "generic min_element map key = "
         << mn->first
         << '\n';

    cout << "generic max_element map key = "
         << mx->first
         << '\n';
}

// ============================================================================
// 12. map — minimum/maximum VALUE
// ============================================================================

void demoMapValues()
{
    map<int, int> mp = {
        {101, 500},
        {102, 100},
        {103, 300}};

    /*
        Need MINIMUM VALUE, not minimum key.

        Therefore compare second.
    */

    auto mn = min_element(
        mp.begin(),
        mp.end(),
        [](const auto &a, const auto &b)
        {
            return a.second < b.second;
        });

    auto mx = max_element(
        mp.begin(),
        mp.end(),
        [](const auto &a, const auto &b)
        {
            return a.second < b.second;
        });

    cout << "Minimum value = "
         << mn->second
         << " at key "
         << mn->first
         << '\n';

    cout << "Maximum value = "
         << mx->second
         << " at key "
         << mx->first
         << '\n';
}

// ============================================================================
// 13. unordered_set
// ============================================================================

void demoUnorderedSet()
{
    unordered_set<int> us = {
        50, 10, 30, 5};

    /*
        unordered_set is NOT sorted.

        So:
            *us.begin()

        is NOT guaranteed to be minimum.

        We MUST scan using min_element/max_element.
    */

    auto mn = min_element(
        us.begin(),
        us.end());

    auto mx = max_element(
        us.begin(),
        us.end());

    cout << "unordered_set min = "
         << *mn
         << '\n';

    cout << "unordered_set max = "
         << *mx
         << '\n';
}

// ============================================================================
// 14. unordered_map
// ============================================================================

void demoUnorderedMap()
{
    unordered_map<int, int> um = {
        {101, 500},
        {102, 100},
        {103, 300}};

    /*
        unordered_map is NOT sorted.

        Therefore begin() is not minimum key.

        Generic min_element compares pairs, primarily by key.

        For minimum VALUE use custom comparator.
    */

    auto mn = min_element(
        um.begin(),
        um.end(),
        [](const auto &a, const auto &b)
        {
            return a.second < b.second;
        });

    auto mx = max_element(
        um.begin(),
        um.end(),
        [](const auto &a, const auto &b)
        {
            return a.second < b.second;
        });

    cout << "unordered_map minimum value = "
         << mn->second
         << " at key "
         << mn->first
         << '\n';

    cout << "unordered_map maximum value = "
         << mx->second
         << " at key "
         << mx->first
         << '\n';
}

// ============================================================================
// 15. Custom comparator — absolute value
// ============================================================================

void demoCustomComparator()
{
    vector<int> v = {
        -10, 5, -3, 8};

    /*
        Normal min:
            -10

        But we want minimum ABSOLUTE value:

            |-10| = 10
            |5|   = 5
            |-3|  = 3
            |8|   = 8

        Therefore answer:
            -3
    */

    auto it = min_element(
        v.begin(),
        v.end(),
        [](int a, int b)
        {
            return abs(a) < abs(b);
        });

    cout << "Minimum absolute-value element = "
         << *it
         << '\n';
}

// ============================================================================
// 16. Strings
// ============================================================================

void demoStrings()
{
    vector<string> names = {
        "Zebra",
        "Apple",
        "Mango"};

    auto mn = min_element(
        names.begin(),
        names.end());

    auto mx = max_element(
        names.begin(),
        names.end());

    cout << "Minimum string = "
         << *mn
         << '\n';

    cout << "Maximum string = "
         << *mx
         << '\n';
}

// ============================================================================
// 17. Empty container safety
// ============================================================================

void demoEmpty()
{
    vector<int> v;

    /*
        Empty range:

            min_element(begin, end)
            max_element(begin, end)

        returns end().

        Never dereference it.
    */

    if (v.empty())
    {
        cout << "Vector is empty. No min/max.\n";
        return;
    }

    cout << *min_element(
        v.begin(),
        v.end());
}

// ============================================================================
// MAIN
// ============================================================================

int main()
{
    cout << "========== min() / max() ==========\n";
    demoMinMax();

    cout << "\n========== vector ==========\n";
    demoVector();

    cout << "\n========== minmax_element() ==========\n";
    demoMinMaxElement();

    cout << "\n========== initializer_list ==========\n";
    demoInitializerList();

    cout << "\n========== array ==========\n";
    demoArray();

    cout << "\n========== deque ==========\n";
    demoDeque();

    cout << "\n========== list ==========\n";
    demoList();

    cout << "\n========== forward_list ==========\n";
    demoForwardList();

    cout << "\n========== set ==========\n";
    demoSet();

    cout << "\n========== multiset ==========\n";
    demoMultiset();

    cout << "\n========== map keys ==========\n";
    demoMapKeys();

    cout << "\n========== map values ==========\n";
    demoMapValues();

    cout << "\n========== unordered_set ==========\n";
    demoUnorderedSet();

    cout << "\n========== unordered_map ==========\n";
    demoUnorderedMap();

    cout << "\n========== custom comparator ==========\n";
    demoCustomComparator();

    cout << "\n========== strings ==========\n";
    demoStrings();

    cout << "\n========== empty container ==========\n";
    demoEmpty();

    return 0;
}
