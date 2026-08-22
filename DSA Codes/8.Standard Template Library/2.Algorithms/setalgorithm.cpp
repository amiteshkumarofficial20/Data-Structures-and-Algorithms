/*
================================================================================
                    C++ STL std::set — COMPLETE DETAILED NOTES
================================================================================

This file is a COMPLETE study/reference file for std::set.

It covers:

1. What is std::set?
2. Core properties
3. Unique elements
4. Sorted order
5. Internal tree concept
6. Iterator category
7. Header and syntax
8. Declaration
9. Initialization
10. insert()
11. emplace()
12. insert return value
13. insert range
14. find()
15. count()
16. contains() [C++20]
17. lower_bound()
18. upper_bound()
19. equal_range()
20. begin()
21. end()
22. rbegin()
23. rend()
24. size()
25. empty()
26. max_size()
27. erase(value)
28. erase(iterator)
29. erase(range)
30. clear()
31. swap()
32. extract()
33. merge()
34. key_comp()
35. value_comp()
36. get_allocator()
37. custom comparator
38. descending set
39. pair/custom object in set
40. set of strings
41. set of pairs
42. set vs multiset
43. set vs unordered_set
44. set vs vector
45. set vs map
46. set algorithms
47. union
48. intersection
49. difference
50. symmetric difference
51. includes()
52. iterator invalidation
53. complexity
54. container compatibility
55. common mistakes
56. complete runnable examples

================================================================================
IMPORTANT: std::set VS SET ALGORITHMS
================================================================================

std::set is a CONTAINER.

Example:

    set<int> s;

Set algorithms are GENERIC ALGORITHMS:

    set_union()
    set_intersection()
    set_difference()
    set_symmetric_difference()
    includes()

They are different things.

The generic set algorithms can work on sorted ranges such as:

    vector
    array
    deque
    list
    set
    multiset

provided the required ordering condition is satisfied.

================================================================================
1. WHAT IS std::set?
================================================================================

std::set is an associative container that stores UNIQUE keys/elements
in SORTED order.

Example:

    set<int> s;

    s.insert(50);
    s.insert(10);
    s.insert(30);
    s.insert(20);

Iteration gives:

    10 20 30 50

Even though insertion order was:

    50 10 30 20

the set automatically maintains sorted order.

================================================================================
2. MAIN PROPERTIES OF std::set
================================================================================

PROPERTY 1:
    UNIQUE ELEMENTS

If:

    s.insert(10);
    s.insert(10);
    s.insert(10);

only one 10 is stored.

Therefore:

    set<int> s = {10, 10, 20};

contains:

    10 20

--------------------------------------------------------------------------------

PROPERTY 2:
    SORTED

Default ordering is ascending using std::less<T>.

Example:

    set<int> s = {50, 10, 30};

stores:

    10 30 50

--------------------------------------------------------------------------------

PROPERTY 3:
    NO RANDOM ACCESS

This is WRONG:

    s[2];

std::set does not support operator[].

This is also WRONG:

    s.begin() + 2;

because set iterator is not Random Access.

Use iterator movement:

    auto it = s.begin();
    advance(it, 2);

--------------------------------------------------------------------------------

PROPERTY 4:
    ITERATOR IS BIDIRECTIONAL

You can:

    ++it;
    --it;

But you cannot:

    it + 5;

--------------------------------------------------------------------------------

PROPERTY 5:
    NOT CONTIGUOUS

set elements are not stored like vector elements in one contiguous block.

--------------------------------------------------------------------------------

PROPERTY 6:
    TREE-BASED ORDERED STRUCTURE

The C++ standard specifies ordered associative behavior and logarithmic
search/insertion/erasure complexity. Typical implementations use a
balanced binary search tree such as a Red-Black Tree.

Do not rely on the exact internal implementation as a language guarantee.

--------------------------------------------------------------------------------

PROPERTY 7:
    SEARCH IS GENERALLY O(log n)

    s.find(x);

--------------------------------------------------------------------------------

PROPERTY 8:
    INSERTION IS GENERALLY O(log n)

    s.insert(x);

--------------------------------------------------------------------------------

PROPERTY 9:
    ERASE BY KEY IS GENERALLY O(log n)

    s.erase(x);

--------------------------------------------------------------------------------

PROPERTY 10:
    ELEMENT CANNOT BE MODIFIED THROUGH A SET ITERATOR

This would break ordering.

Therefore:

    *it = newValue;

is not allowed.

If you need to change a value:

    erase old value
    insert new value

================================================================================
3. HEADER
================================================================================

    #include <set>

Usually:

    #include <iostream>
    #include <set>

================================================================================
4. DECLARATION
================================================================================

    set<int> s;

This creates an empty set of integers.

String:

    set<string> names;

Character:

    set<char> chars;

Long long:

    set<long long> s;

================================================================================
5. INITIALIZATION
================================================================================

Direct initialization:

    set<int> s = {
        10, 20, 30, 40
    };

Duplicates disappear:

    set<int> s = {
        10, 20, 20, 30, 30
    };

Result:

    10 20 30

================================================================================
6. INSERT()
================================================================================

Basic:

    s.insert(10);

Multiple:

    s.insert(20);
    s.insert(30);

The set remains sorted automatically.

Example:

    set<int> s;

    s.insert(50);
    s.insert(10);
    s.insert(30);

Stored order:

    10 30 50

================================================================================
7. INSERT RETURN VALUE
================================================================================

Very important.

For:

    auto result = s.insert(10);

result is approximately:

    pair<iterator, bool>

result.first:
    iterator to element

result.second:
    true  -> insertion happened
    false -> element already existed

Example:

    auto result = s.insert(10);

    if (result.second)
    {
        cout << "Inserted";
    }
    else
    {
        cout << "Already exists";
    }

Second insertion:

    auto result2 = s.insert(10);

result2.second:

    false

================================================================================
8. INSERT RANGE
================================================================================

You can insert a complete range:

    vector<int> v = {
        10, 20, 30, 40
    };

    set<int> s;

    s.insert(
        v.begin(),
        v.end()
    );

The set sorts the values and removes duplicates.

================================================================================
9. EMPLACE()
================================================================================

    s.emplace(10);

For simple int:

    insert()
    and
    emplace()

are usually conceptually equivalent.

emplace constructs the element in place.

It becomes especially useful with complex objects.

================================================================================
10. FIND()
================================================================================

Purpose:

    Search for an element.

Syntax:

    auto it = s.find(x);

Found:

    it != s.end()

Not found:

    it == s.end()

Example:

    auto it = s.find(30);

    if (it != s.end())
    {
        cout << "Found: " << *it;
    }

Complexity:

    O(log n)

================================================================================
11. COUNT()
================================================================================

For std::set, an element can occur at most once.

Therefore:

    s.count(x)

returns:

    0
    or
    1

Example:

    if (s.count(30))
    {
        cout << "Present";
    }

For multiset, count() can be greater than 1.

================================================================================
12. CONTAINS() — C++20
================================================================================

C++20 provides:

    s.contains(x)

Returns:

    true
    false

Example:

    if (s.contains(30))
    {
        cout << "Found";
    }

This is often cleaner than:

    s.find(30) != s.end()

Important:

    contains() is available from C++20.

================================================================================
13. LOWER_BOUND()
================================================================================

lower_bound(x):

    first element >= x

Example:

    set<int> s = {
        10, 20, 30, 40, 50
    };

    auto it = s.lower_bound(25);

Result:

    30

Because 30 is the first element >= 25.

For:

    lower_bound(30)

result:

    30

For:

    lower_bound(51)

result:

    end()

Complexity:

    O(log n)

================================================================================
14. UPPER_BOUND()
================================================================================

upper_bound(x):

    first element > x

Example:

    set<int> s = {
        10, 20, 30, 40, 50
    };

    auto it = s.upper_bound(30);

Result:

    40

Because 40 is the first element strictly greater than 30.

================================================================================
15. EQUAL_RANGE()
================================================================================

Returns:

    pair<iterator, iterator>

Conceptually:

    {
        lower_bound(x),
        upper_bound(x)
    }

For std::set there can be at most one matching element.

Example:

    auto p = s.equal_range(30);

    p.first
        -> lower_bound(30)

    p.second
        -> upper_bound(30)

For a unique set, the range contains either:

    one element
or:
    zero elements

================================================================================
16. BEGIN()
================================================================================

    s.begin()

returns iterator to the smallest element under the set's ordering.

Example:

    set<int> s = {
        30, 10, 20
    };

    cout << *s.begin();

Output:

    10

Complexity:

    O(1) for retrieving the iterator.

================================================================================
17. END()
================================================================================

    s.end()

points ONE POSITION AFTER the last element.

Never do:

    *s.end();

That is invalid.

To get the largest element:

    *prev(s.end())

provided the set is not empty.

================================================================================
18. REVERSE ITERATORS
================================================================================

rbegin():

    largest element first under default ascending ordering.

Example:

    *s.rbegin()

gives largest element.

rend():

    position before the first reverse element.

Example:

    for (
        auto it = s.rbegin();
        it != s.rend();
        ++it
    )
    {
        cout << *it;
    }

prints descending order.

================================================================================
19. SIZE()
================================================================================

    s.size()

returns number of elements.

Example:

    set<int> s = {
        10, 20, 30
    };

    s.size()

returns:

    3

Complexity:

    O(1) in modern standard-conforming implementations.

================================================================================
20. EMPTY()
================================================================================

    s.empty()

returns true if there are zero elements.

Example:

    if (s.empty())
    {
        cout << "Set is empty";
    }

================================================================================
21. MAX_SIZE()
================================================================================

    s.max_size()

returns the theoretical maximum number of elements the container
could hold according to allocator/container limits.

It is rarely used in normal DSA code.

================================================================================
22. ERASE BY VALUE
================================================================================

    s.erase(30);

If 30 exists:
    it is removed.

For std::set:
    return value is usually 0 or 1.

Example:

    size_t removed = s.erase(30);

================================================================================
23. ERASE BY ITERATOR
================================================================================

    auto it = s.find(30);

    if (it != s.end())
    {
        s.erase(it);
    }

This is useful when you already have the iterator.

================================================================================
24. ERASE RANGE
================================================================================

Remove everything from first to last, where last is exclusive.

Example:

    auto first = s.lower_bound(20);
    auto last = s.upper_bound(40);

    s.erase(first, last);

This removes the elements in:

    [20, 40]

that actually exist in the set.

================================================================================
25. CLEAR()
================================================================================

    s.clear();

Removes all elements.

After:

    s.empty()

is true.

================================================================================
26. SWAP()
================================================================================

    s1.swap(s2);

Swaps contents of two sets.

Example:

    set<int> a = {1, 2};
    set<int> b = {10, 20};

    a.swap(b);

Now:

    a = {10, 20}
    b = {1, 2}

================================================================================
27. DESCENDING SET
================================================================================

Default:

    set<int>

means ascending order.

For descending:

    set<int, greater<int>> s;

Example:

    set<int, greater<int>> s = {
        10, 50, 20, 40
    };

Iteration:

    50 40 20 10

Now:

    *s.begin()

is the largest element.

And:

    *s.rbegin()

is the smallest element.

IMPORTANT:

The meaning of lower_bound/upper_bound is based on the set's comparator,
so always think in terms of the configured ordering rather than assuming
numeric ascending order.

================================================================================
28. CUSTOM COMPARATOR
================================================================================

Example:

    set<int, greater<int>> s;

For custom objects:

    struct Person
    {
        string name;
        int age;
    };

You can define a comparator.

Example:

    struct Compare
    {
        bool operator()(
            const Person& a,
            const Person& b
        ) const
        {
            return a.age < b.age;
        }
    };

Then:

    set<Person, Compare> people;

Elements are ordered by age.

IMPORTANT:

Comparator must provide a strict weak ordering.

================================================================================
29. SET OF STRINGS
================================================================================

    set<string> names = {
        "Zebra",
        "Apple",
        "Mango"
    };

Iteration:

    Apple
    Mango
    Zebra

because strings are compared lexicographically by default.

================================================================================
30. SET OF PAIRS
================================================================================

    set<pair<int, int>> s;

Default pair ordering:

    first is compared first.

If first values are equal:

    second is compared.

Example:

    {1, 20}
    {1, 30}
    {2, 10}

order:

    {1,20}
    {1,30}
    {2,10}

================================================================================
31. SET DOES NOT ALLOW MODIFYING ELEMENTS
================================================================================

Suppose:

    set<int> s = {
        10, 20, 30
    };

    auto it = s.begin();

This is NOT allowed:

    *it = 100;

Why?

Because changing 10 to 100 through the iterator could violate the
container's ordering rules.

Correct approach:

    s.erase(it);
    s.insert(100);

================================================================================
32. ITERATOR INVALIDATION
================================================================================

Important practical rule:

Insertion into std::set does not invalidate iterators to existing elements.

Erasing an element invalidates the iterator to that erased element,
but iterators to other elements remain valid.

Example:

    auto it = s.find(20);

    s.insert(50);

    cout << *it;

The iterator to 20 remains valid.

After:

    s.erase(it);

that iterator is invalid and must not be dereferenced.

================================================================================
33. SET VS MULTISET
================================================================================

set:

    unique
    sorted

multiset:

    duplicates allowed
    sorted

Example:

    set<int> s = {
        10, 10, 20
    };

contains:

    10 20


multiset<int> ms = {
    10, 10, 20
};

contains:

    10 10 20


count():

set:
    0 or 1

multiset:
    0, 1, 2, 3, ...


================================================================================
34. SET VS UNORDERED_SET
================================================================================

set:

    sorted
    unique
    tree-based ordered behavior
    O(log n) search

unordered_set:

    not sorted
    unique
    hash-based
    average O(1) search

If you need ordered traversal:

    set

If you need average constant-time lookup and do not need order:

    unordered_set


================================================================================
35. SET VS VECTOR
================================================================================

vector:

    contiguous
    random access
    duplicates allowed
    insertion in middle expensive

set:

    sorted
    unique
    no random access
    search O(log n)

If you need:

    v[5]

use vector.

If you need:

    automatically sorted unique values

use set.


================================================================================
36. SET VS MAP
================================================================================

set:

    key only

map:

    key + value

Example set:

    set<int> s;

Example map:

    map<int, string> mp;


================================================================================
37. set_union()
================================================================================

Generic set algorithm.

Header:

    <algorithm>

Requires sorted ranges.

Example:

    A = {1,2,3,4}
    B = {3,4,5,6}

Result:

    1 2 3 4 5 6

For vector output:

    vector<int> result;

    set_union(
        A.begin(),
        A.end(),
        B.begin(),
        B.end(),
        back_inserter(result)
    );


================================================================================
38. set_intersection()
================================================================================

Only common elements.

    A = {1,2,3,4}
    B = {3,4,5,6}

Result:

    3 4


================================================================================
39. set_difference()
================================================================================

First range minus second range.

    A - B

Example:

    A = {1,2,3,4}
    B = {3,4,5,6}

Result:

    1 2

For B - A:

    reverse the input ranges.


================================================================================
40. set_symmetric_difference()
================================================================================

Elements that exist in exactly one range.

    A = {1,2,3,4}
    B = {3,4,5,6}

Result:

    1 2 5 6


================================================================================
41. includes()
================================================================================

Checks whether second sorted range is contained in first.

    A = {1,2,3,4,5}
    B = {2,4}

    includes(A, B)

returns true.


================================================================================
42. MERGE() — std::set MEMBER FUNCTION
================================================================================

This is NOT the generic set_union algorithm.

std::set has:

    s1.merge(s2);

It transfers elements from s2 into s1 where possible.

Example:

    set<int> a = {
        1, 2, 3
    };

    set<int> b = {
        3, 4, 5
    };

    a.merge(b);


After merge:

    a:
        1 2 3 4 5

Because 3 already existed in a, the node containing 3 cannot be
inserted into a and remains in b.

This is a major difference from set_union().

set_union:
    creates output range

merge:
    transfers nodes between compatible associative containers


================================================================================
43. EXTRACT() — std::set MEMBER FUNCTION (C++17)
================================================================================

extract() removes a node from the set and returns a node handle.

Example:

    auto node = s.extract(20);

Now 20 is no longer in s.

You can change the key in the node handle:

    node.value() = 25;

Then:

    s.insert(
        move(node)
    );

This allows modifying a set key without copying the object through
the normal iterator interface.

Requires:

    C++17


================================================================================
44. SET ALGORITHM OUTPUT WITH std::set
================================================================================

For vector output:

    back_inserter(result)


For set output:

    inserter(
        result,
        result.begin()
    )


Example:

    set<int> result;

    set_union(
        a.begin(),
        a.end(),
        b.begin(),
        b.end(),
        inserter(
            result,
            result.begin()
        )
    );


================================================================================
45. COMPLEXITY TABLE
================================================================================

std::set MEMBER FUNCTIONS:

find:
    O(log n)

insert:
    O(log n)

erase(key):
    O(log n)

lower_bound:
    O(log n)

upper_bound:
    O(log n)

count:
    O(log n)

contains:
    O(log n)

begin:
    O(1)

end:
    O(1)

size:
    O(1)

clear:
    O(n)


GENERIC SET ALGORITHMS:

set_union:
    O(N + M)

set_intersection:
    O(N + M)

set_difference:
    O(N + M)

set_symmetric_difference:
    O(N + M)

includes:
    O(N + M)


================================================================================
46. CONTAINER COMPATIBILITY SUMMARY
================================================================================

                         std::set MEMBER OPS    Generic set algorithms
vector                          NO                     YES*
array                           NO                     YES*
deque                           NO                     YES*
list                            NO                     YES*
forward_list                    NO                     YES*
set                             YES                    YES*
multiset                        YES                    YES*
unordered_set                   YES                    NO*
map                             YES                    YES*
multimap                        YES                    YES*
unordered_map                   YES                    NO*

* Generic set algorithms require sorted input ranges.

Why:

    vector/array/deque/list/forward_list
    do not have std::set member functions.

But they can be used as sorted ranges with generic algorithms.

unordered containers are not sorted, so sort/copy first.


================================================================================
47. IMPORTANT: set MEMBER FUNCTION VS GENERIC ALGORITHM
================================================================================

std::set:

    s.find(x)

is a member function.

Generic:

    find(
        s.begin(),
        s.end(),
        x
    )

also works, but generic find performs linear traversal.

Therefore for std::set:

    s.find(x)

is normally much better.

Similarly:

    s.lower_bound(x)

is preferable to generic lower_bound over the range in normal code,
because the member function uses the set's tree structure directly.


================================================================================
48. COMPLETE DSA EXAMPLES
================================================================================

EXAMPLE 1:
    Remove duplicates from an array.

Use:

    set<int> s(
        v.begin(),
        v.end()
    );


EXAMPLE 2:
    Find common values between two sorted arrays.

Use:

    set_intersection()


EXAMPLE 3:
    Find all values only in A.

Use:

    set_difference(A, B)


EXAMPLE 4:
    Find values only in B.

Use:

    set_difference(B, A)


EXAMPLE 5:
    Combine sorted unique values.

Use:

    set_union()


EXAMPLE 6:
    Find values present in exactly one array.

Use:

    set_symmetric_difference()


EXAMPLE 7:
    Check whether one sorted list is contained in another.

Use:

    includes()


================================================================================
49. COMMON MISTAKES
================================================================================

MISTAKE 1:

    Using set algorithms on unsorted vectors.

FIX:

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());


MISTAKE 2:

    Thinking set_union() requires std::set.

FALSE.

It works on sorted ranges.


MISTAKE 3:

    Thinking set_difference(A,B) == set_difference(B,A).

FALSE.

Difference is directional.


MISTAKE 4:

    Using back_inserter() with std::set.

Wrong because set has no push_back().

Use inserter().


MISTAKE 5:

    Using generic find() on set and expecting O(log n).

Generic find:
    O(n)

Use:

    s.find(x)


MISTAKE 6:

    Assuming unordered_set is sorted.

It is not.


MISTAKE 7:

    Trying:

        s[2]

    with std::set.

Not supported.


MISTAKE 8:

    Trying:

        s.begin() + 2

Not supported because set iterator is Bidirectional.


================================================================================
50. FINAL MEMORY MAP
================================================================================

std::set:

    UNIQUE
    SORTED
    NO RANDOM ACCESS
    BIDIRECTIONAL ITERATOR
    O(log n) SEARCH/INSERT/ERASE
    NO DUPLICATES


GENERIC SET ALGORITHMS:

    UNION
        -> everything

    INTERSECTION
        -> common

    DIFFERENCE
        -> first minus second

    SYMMETRIC DIFFERENCE
        -> exactly one side

    INCLUDES
        -> second contained in first


MEMORY:

    OR
        -> UNION

    AND
        -> INTERSECTION

    A NOT B
        -> DIFFERENCE

    XOR
        -> SYMMETRIC DIFFERENCE

    B inside A?
        -> INCLUDES


================================================================================
END OF NOTES
================================================================================
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <unordered_set>
#include <string>
#include <iterator>
#include <functional>

using namespace std;

// ============================================================================
// Helper function
// ============================================================================

template <typename Container>
void printContainer(
    const Container &c,
    const string &name)
{
    cout << name << ": ";

    for (const auto &x : c)
    {
        cout << x << ' ';
    }

    cout << '\n';
}

// ============================================================================
// 1. BASIC std::set PROPERTIES
// ============================================================================

void demoBasicSet()
{
    set<int> s;

    s.insert(50);
    s.insert(10);
    s.insert(30);
    s.insert(10);

    /*
        Duplicate 10 is ignored.

        Set automatically sorts:

            10 30 50
    */

    printContainer(
        s,
        "set");

    cout << "size = "
         << s.size()
         << '\n';

    cout << "smallest = "
         << *s.begin()
         << '\n';

    cout << "largest = "
         << *prev(s.end())
         << '\n';
}

// ============================================================================
// 2. INSERT RETURN VALUE
// ============================================================================

void demoInsertReturn()
{
    set<int> s;

    auto result1 = s.insert(10);

    if (result1.second)
    {
        cout << "10 inserted\n";
    }

    auto result2 = s.insert(10);

    if (!result2.second)
    {
        cout << "10 already exists\n";
    }
}

// ============================================================================
// 3. find(), count(), contains()
// ============================================================================

void demoSearch()
{
    set<int> s = {
        10, 20, 30, 40};

    auto it = s.find(30);

    if (it != s.end())
    {
        cout << "find(30) -> "
             << *it
             << '\n';
    }

    cout << "count(30) -> "
         << s.count(30)
         << '\n';

#if __cplusplus >= 202002L
    cout << boolalpha;

    cout << "contains(30) -> "
         << s.contains(30)
         << '\n';
#endif
}

// ============================================================================
// 4. lower_bound / upper_bound / equal_range
// ============================================================================

void demoBounds()
{
    set<int> s = {
        10, 20, 30, 40, 50};

    auto low = s.lower_bound(25);

    if (low != s.end())
    {
        cout << "lower_bound(25) -> "
             << *low
             << '\n';
    }

    auto high = s.upper_bound(30);

    if (high != s.end())
    {
        cout << "upper_bound(30) -> "
             << *high
             << '\n';
    }

    auto range = s.equal_range(30);

    cout << "equal_range(30): ";

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
// 5. set_union()
// ============================================================================

void demoUnion()
{
    vector<int> a = {
        1, 2, 3, 4};

    vector<int> b = {
        3, 4, 5, 6};

    vector<int> result;

    set_union(
        a.begin(),
        a.end(),
        b.begin(),
        b.end(),
        back_inserter(result));

    printContainer(
        result,
        "A union B");
}

// ============================================================================
// 6. set_intersection()
// ============================================================================

void demoIntersection()
{
    vector<int> a = {
        1, 2, 3, 4};

    vector<int> b = {
        3, 4, 5, 6};

    vector<int> result;

    set_intersection(
        a.begin(),
        a.end(),
        b.begin(),
        b.end(),
        back_inserter(result));

    printContainer(
        result,
        "A intersection B");
}

// ============================================================================
// 7. set_difference()
// ============================================================================

void demoDifference()
{
    vector<int> a = {
        1, 2, 3, 4};

    vector<int> b = {
        3, 4, 5, 6};

    vector<int> result;

    set_difference(
        a.begin(),
        a.end(),
        b.begin(),
        b.end(),
        back_inserter(result));

    printContainer(
        result,
        "A - B");

    result.clear();

    set_difference(
        b.begin(),
        b.end(),
        a.begin(),
        a.end(),
        back_inserter(result));

    printContainer(
        result,
        "B - A");
}

// ============================================================================
// 8. set_symmetric_difference()
// ============================================================================

void demoSymmetricDifference()
{
    vector<int> a = {
        1, 2, 3, 4};

    vector<int> b = {
        3, 4, 5, 6};

    vector<int> result;

    set_symmetric_difference(
        a.begin(),
        a.end(),
        b.begin(),
        b.end(),
        back_inserter(result));

    printContainer(
        result,
        "A symmetric difference B");
}

// ============================================================================
// 9. includes()
// ============================================================================

void demoIncludes()
{
    vector<int> a = {
        1, 2, 3, 4, 5};

    vector<int> b = {
        2, 4};

    vector<int> c = {
        2, 6};

    cout << boolalpha;

    cout << "A includes B? "
         << includes(
                a.begin(),
                a.end(),
                b.begin(),
                b.end())
         << '\n';

    cout << "A includes C? "
         << includes(
                a.begin(),
                a.end(),
                c.begin(),
                c.end())
         << '\n';
}

// ============================================================================
// 10. std::set as input + std::set as output
// ============================================================================

void demoSetInputOutput()
{
    set<int> a = {
        1, 2, 3, 4};

    set<int> b = {
        3, 4, 5, 6};

    set<int> result;

    /*
        std::set has no push_back().

        Therefore:
            back_inserter(result)

        is NOT correct.

        Use:
            inserter(result, result.begin())
    */

    set_union(
        a.begin(),
        a.end(),
        b.begin(),
        b.end(),
        inserter(
            result,
            result.begin()));

    printContainer(
        result,
        "set union");

    result.clear();

    set_intersection(
        a.begin(),
        a.end(),
        b.begin(),
        b.end(),
        inserter(
            result,
            result.begin()));

    printContainer(
        result,
        "set intersection");
}

// ============================================================================
// 11. Duplicate / multiset semantics
// ============================================================================

void demoDuplicates()
{
    vector<int> a = {
        1, 2, 2, 4};

    vector<int> b = {
        2, 2, 2, 5};

    vector<int> result;

    set_union(
        a.begin(),
        a.end(),
        b.begin(),
        b.end(),
        back_inserter(result));

    printContainer(
        result,
        "Union duplicates");

    result.clear();

    set_intersection(
        a.begin(),
        a.end(),
        b.begin(),
        b.end(),
        back_inserter(result));

    printContainer(
        result,
        "Intersection duplicates");

    result.clear();

    set_difference(
        a.begin(),
        a.end(),
        b.begin(),
        b.end(),
        back_inserter(result));

    printContainer(
        result,
        "Difference duplicates");

    result.clear();

    set_symmetric_difference(
        a.begin(),
        a.end(),
        b.begin(),
        b.end(),
        back_inserter(result));

    printContainer(
        result,
        "Symmetric difference duplicates");
}

// ============================================================================
// 12. Unordered set -> sorted vector -> set algorithm
// ============================================================================

void demoUnorderedSet()
{
    unordered_set<int> aSet = {
        4, 1, 3, 2};

    unordered_set<int> bSet = {
        3, 5, 2, 6};

    vector<int> a(
        aSet.begin(),
        aSet.end());

    vector<int> b(
        bSet.begin(),
        bSet.end());

    /*
        unordered_set is not sorted.

        Sort both ranges first.
    */

    sort(
        a.begin(),
        a.end());

    sort(
        b.begin(),
        b.end());

    vector<int> result;

    set_intersection(
        a.begin(),
        a.end(),
        b.begin(),
        b.end(),
        back_inserter(result));

    printContainer(
        result,
        "Intersection");
}

// ============================================================================
// 13. List + set algorithm
// ============================================================================

void demoList()
{
    list<int> a = {
        4, 1, 3, 2};

    list<int> b = {
        3, 5, 2, 6};

    /*
        list can be used with generic set algorithms.

        But the input ranges must be sorted.

        list has its own sort() member function.
    */

    a.sort();
    b.sort();

    list<int> result;

    set_union(
        a.begin(),
        a.end(),
        b.begin(),
        b.end(),
        back_inserter(result));

    printContainer(
        result,
        "List union");
}

// ============================================================================
// 14. Descending order + comparator
// ============================================================================

void demoDescending()
{
    vector<int> a = {
        9, 7, 5, 3, 1};

    vector<int> b = {
        8, 6, 4, 2};

    vector<int> result;

    /*
        Both ranges are sorted descending.

        Therefore the SAME comparator must be provided.
    */

    set_union(
        a.begin(),
        a.end(),
        b.begin(),
        b.end(),
        back_inserter(result),
        greater<int>());

    printContainer(
        result,
        "Descending union");
}

// ============================================================================
// 15. std::set merge()
// ============================================================================

void demoMerge()
{
    set<int> a = {
        1, 2, 3};

    set<int> b = {
        3, 4, 5};

    /*
        merge() is a MEMBER FUNCTION of std::set.

        It is NOT the same as set_union().

        It transfers nodes from b into a where possible.
    */

    a.merge(b);

    printContainer(
        a,
        "A after merge");

    /*
        3 already existed in A.

        Therefore its node could not be transferred.

        So B still contains 3.
    */

    printContainer(
        b,
        "B after merge");
}

// ============================================================================
// 16. extract()
// ============================================================================

void demoExtract()
{
    set<int> s = {
        10, 20, 30};

    /*
        C++17 node handle.

        extract(20) removes 20 from the set and returns its node.
    */

    auto node = s.extract(20);

    cout << "After extract(20):\n";

    printContainer(
        s,
        "set");

    /*
        The extracted node can be changed before reinsertion.
    */

    if (!node.empty())
    {
        node.value() = 25;

        s.insert(
            move(node));
    }

    cout << "After changing extracted node 20 -> 25:\n";

    printContainer(
        s,
        "set");
}

// ============================================================================
// 17. Main
// ============================================================================

int main()
{
    cout << "========== BASIC SET ==========\n";
    demoBasicSet();

    cout << "\n========== INSERT RETURN ==========\n";
    demoInsertReturn();

    cout << "\n========== SEARCH ==========\n";
    demoSearch();

    cout << "\n========== BOUNDS ==========\n";
    demoBounds();

    cout << "\n========== UNION ==========\n";
    demoUnion();

    cout << "\n========== INTERSECTION ==========\n";
    demoIntersection();

    cout << "\n========== DIFFERENCE ==========\n";
    demoDifference();

    cout << "\n========== SYMMETRIC DIFFERENCE ==========\n";
    demoSymmetricDifference();

    cout << "\n========== INCLUDES ==========\n";
    demoIncludes();

    cout << "\n========== SET INPUT / OUTPUT ==========\n";
    demoSetInputOutput();

    cout << "\n========== DUPLICATES ==========\n";
    demoDuplicates();

    cout << "\n========== UNORDERED SET ==========\n";
    demoUnorderedSet();

    cout << "\n========== LIST ==========\n";
    demoList();

    cout << "\n========== DESCENDING ==========\n";
    demoDescending();

    cout << "\n========== MERGE ==========\n";
    demoMerge();

    cout << "\n========== EXTRACT ==========\n";
    demoExtract();

    return 0;
}
