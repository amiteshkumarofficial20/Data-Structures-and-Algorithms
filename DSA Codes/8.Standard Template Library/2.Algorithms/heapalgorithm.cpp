/*
===============================================================================
             C++ STL HEAP ALGORITHMS — COMPLETE DETAILED NOTES
===============================================================================

TOPICS COVERED
---------------

1. What is a heap?
2. Max-heap vs Min-heap
3. heap representation in vector/array
4. parent / child index formulas
5. make_heap()
6. push_heap()
7. pop_heap()
8. sort_heap()
9. is_heap()
10. is_heap_until()
11. default max-heap behavior
12. custom comparator for min-heap
13. vector container compatibility
14. array / deque / list / set / map / unordered containers
15. why heap algorithms need Random Access Iterators
16. push_back() + push_heap()
17. pop_heap() + pop_back()
18. heap sort
19. priority_queue connection
20. complexity
21. common mistakes
22. DSA patterns
23. complete runnable code

===============================================================================
MOST IMPORTANT IDEA
===============================================================================

STL heap algorithms are:

    make_heap()
    push_heap()
    pop_heap()
    sort_heap()
    is_heap()
    is_heap_until()

HEADER:

    #include <algorithm>

These algorithms work on RANDOM-ACCESS iterator ranges.

Therefore they are directly suitable for:

    vector
    array
    deque

They are NOT directly suitable for:

    list
    forward_list
    set
    multiset
    map
    multimap
    unordered_set
    unordered_map

Why?

Because heap algorithms use random-access operations such as:

    it + n
    it - n
    it[n]

and the heap is represented using array-style indexing.

===============================================================================
WHAT IS A HEAP?
===============================================================================

A heap is a special COMPLETE BINARY TREE.

There are two common forms:

    1. Max-Heap
    2. Min-Heap


MAX-HEAP
--------

Every parent is >= its children.

Example:

              50
             /  \
           30    40
          / \    /
        10  20  35

The largest element is at the root.

Therefore:

    max-heap -> largest element at front/root


MIN-HEAP
--------

Every parent is <= its children.

Example:

              10
             /  \
           20    15
          / \    /
        40  30  25

The smallest element is at the root.

Therefore:

    min-heap -> smallest element at front/root


===============================================================================
HEAP IN ARRAY / VECTOR
===============================================================================

STL heap is usually represented inside a random-access container such as:

    vector<int> v;

For zero-based indexing:

    parent(i) = (i - 1) / 2

    left child(i) = 2*i + 1

    right child(i) = 2*i + 2


Example:

Array:

    index:
      0   1   2   3   4   5   6

    value:
     50  30  40  10  20  35  25


Tree:

                    50
                  /    \
                30      40
               /  \    /  \
             10   20  35  25


For index 0:

    left  = 1
    right = 2

For index 1:

    left  = 3
    right = 4

For index 2:

    left  = 5
    right = 6


IMPORTANT:

A heap is NOT the same as a sorted array.

Example valid max-heap:

    50 30 40 10 20 35 25

This is NOT sorted.

But it satisfies:

    parent >= children


===============================================================================
MAX-HEAP — DEFAULT STL BEHAVIOR
===============================================================================

VERY IMPORTANT:

    make_heap()
    push_heap()
    pop_heap()
    sort_heap()

use std::less<T> by default.

This creates a:

    MAX-HEAP


Example:

    vector<int> v = {
        10, 30, 20, 50, 40
    };

    make_heap(
        v.begin(),
        v.end()
    );

After this:

    v.front()

contains:

    50


But the remaining elements are NOT sorted.

Only heap property is guaranteed.


===============================================================================
1. make_heap()
===============================================================================

PURPOSE:

Convert an existing random-access range into a heap.

SYNTAX:

    make_heap(
        first,
        last
    );


Example:

    vector<int> v = {
        10, 30, 20, 50, 40
    };

    make_heap(
        v.begin(),
        v.end()
    );


Now:

    v.front()

is the maximum element.

For this example:

    v.front() == 50


IMPORTANT:

make_heap():

    does NOT sort the vector.

It only rearranges elements enough to satisfy heap property.


BEFORE:

    10 30 20 50 40

AFTER:

    50 40 20 10 30

One valid heap representation.

Another valid heap representation may also exist.

Do NOT depend on one exact arrangement except for the heap property.


COMPLEXITY:

    O(n)


WHY O(n)?

Heap construction can be performed bottom-up in linear time.


===============================================================================
make_heap() CONTAINER COMPATIBILITY
===============================================================================

vector:
    YES

array:
    YES

deque:
    YES

list:
    NO
    no random-access iterators

forward_list:
    NO
    no random-access iterators

set:
    NO

multiset:
    NO

map:
    NO

multimap:
    NO

unordered_set:
    NO

unordered_map:
    NO


IMPORTANT:

"NO" here means the GENERIC heap algorithm cannot be directly applied
to that container's iterators because random-access iterators are required.

You can always copy data into a vector and build a heap there.


===============================================================================
2. push_heap()
===============================================================================

PURPOSE:

After adding a NEW element at the END of an existing heap,
restore the heap property.

VERY IMPORTANT:

push_heap() expects:

    [first, last - 1)

to already be a heap.

The NEW element must be at:

    last - 1


CORRECT PROCESS:

    v.push_back(newValue);

    push_heap(
        v.begin(),
        v.end()
    );


Example:

Initial heap:

    50 40 30 10 20

Add:

    45

First:

    v.push_back(45);


Now:

    50 40 30 10 20 45

The old part was a heap.

Now call:

    push_heap(
        v.begin(),
        v.end()
    );


It moves 45 upward until the heap property is restored.

Possible result:

    50 40 45 10 20 30


Again, exact internal arrangement can vary, but heap property is valid.


COMPLEXITY:

    O(log n)

Because the newly inserted element can move upward along the height
of the heap.


===============================================================================
push_heap() — GOLDEN RULE
===============================================================================

WRONG:

    push_heap(
        v.begin(),
        v.end()
    );

when v was NOT a heap before the push.


Correct:

    v.push_back(x);

    push_heap(
        v.begin(),
        v.end()
    );


The range excluding the new last element must already be a heap.


===============================================================================
3. pop_heap()
===============================================================================

PURPOSE:

Move the heap's top element to the END of the range and restore the
heap property in the remaining range.

This is extremely important:

    pop_heap() does NOT reduce vector size.

It only moves the top element to the end.


Example max-heap:

    50 40 45 10 20 30


Call:

    pop_heap(
        v.begin(),
        v.end()
    );


After pop_heap, conceptually:

    45 40 30 10 20 | 50

The maximum element 50 is moved to the last position.

The prefix:

    [v.begin(), v.end() - 1)

is still a heap.


IMPORTANT:

Vector size is STILL the same.

Therefore:

    v.size()

has NOT decreased.


If you want to actually remove the maximum:

    pop_heap(
        v.begin(),
        v.end()
    );

    v.pop_back();


Now vector size decreases by one.


===============================================================================
pop_heap() COMPLEXITY
===============================================================================

    O(log n)


Why?

The root is moved to the end and the remaining heap is repaired
by moving an element downward.


===============================================================================
4. sort_heap()
===============================================================================

PURPOSE:

Sort an existing heap.

IMPORTANT:

The range MUST already be a heap.

Example:

    vector<int> v = {
        10, 40, 30, 20, 50
    };

    make_heap(
        v.begin(),
        v.end()
    );

Now:

    sort_heap(
        v.begin(),
        v.end()
    );


For default max-heap comparator:

Result:

    ascending order


Example:

    10 20 30 40 50


VERY IMPORTANT:

After sort_heap():

    the range is SORTED.

    It is no longer treated as a heap in the same sense,
    because sorting destroys the heap property except in trivial cases.


COMPLEXITY:

    O(n log n)


===============================================================================
5. is_heap()
===============================================================================

PURPOSE:

Check whether a range is currently a valid heap.

SYNTAX:

    bool result = is_heap(
        v.begin(),
        v.end()
    );


Returns:

    true
    false


Example:

    vector<int> v = {
        50, 40, 30, 10, 20
    };


    is_heap(
        v.begin(),
        v.end()
    );

Result:

    true


If:

    vector<int> v = {
        10, 50, 30, 20
    };

then likely:

    false

because 10 cannot be parent of 50 in a max-heap.


COMPLEXITY:

    O(n)


===============================================================================
6. is_heap_until()
===============================================================================

PURPOSE:

Find the first position where the heap property stops being valid.

SYNTAX:

    auto it = is_heap_until(
        v.begin(),
        v.end()
    );


If entire range is a heap:

    it == v.end()


If invalidity occurs:

    it points to the first element that breaks the heap property.


This is useful for debugging.


===============================================================================
MIN-HEAP
===============================================================================

Default STL heap algorithms create a MAX-HEAP.

To create a MIN-HEAP:

    use greater<int>()


Example:

    vector<int> v = {
        10, 30, 20, 50, 40
    };

    make_heap(
        v.begin(),
        v.end(),
        greater<int>()
    );


Now:

    v.front()

contains the SMALLEST value.

Therefore:

    v.front() == 10


===============================================================================
MIN-HEAP WITH push_heap()
===============================================================================

When using a custom comparator, use the SAME comparator consistently.

Example:

    v.push_back(5);

    push_heap(
        v.begin(),
        v.end(),
        greater<int>()
    );


Do NOT mix:

    make_heap(..., greater<int>())

with:

    push_heap(...)

because default push_heap uses max-heap ordering.

Comparator must remain consistent.


===============================================================================
MIN-HEAP WITH pop_heap()
===============================================================================

    pop_heap(
        v.begin(),
        v.end(),
        greater<int>()
    );

Then:

    v.pop_back();


For min-heap, the smallest element is moved to the end by pop_heap.


===============================================================================
MIN-HEAP WITH sort_heap()
===============================================================================

    sort_heap(
        v.begin(),
        v.end(),
        greater<int>()
    );


With greater<int>(), the resulting sorted order is:

    descending


Example:

    50 40 30 20 10


So:

DEFAULT max-heap:
    sort_heap()
    -> ascending


MIN-HEAP using greater:
    sort_heap(..., greater<int>())
    -> descending


===============================================================================
HEAP ALGORITHM COMPLETE FLOW
===============================================================================

BUILD:

    vector<int> v = {
        10, 20, 30, 40
    };

    make_heap(
        v.begin(),
        v.end()
    );


INSERT:

    v.push_back(50);

    push_heap(
        v.begin(),
        v.end()
    );


REMOVE TOP:

    pop_heap(
        v.begin(),
        v.end()
    );

    v.pop_back();


SORT:

    make_heap(
        v.begin(),
        v.end()
    );

    sort_heap(
        v.begin(),
        v.end()
    );


CHECK:

    is_heap(
        v.begin(),
        v.end()
    );


===============================================================================
HEAP VS priority_queue
===============================================================================

priority_queue internally uses a heap-like structure.

Instead of manually doing:

    make_heap()
    push_heap()
    pop_heap()

you can use:

    priority_queue<int> pq;


Then:

    pq.push(x);

    pq.top();

    pq.pop();


DEFAULT:

    priority_queue<int>

is a MAX-HEAP.

For MIN-HEAP:

    priority_queue<
        int,
        vector<int>,
        greater<int>
    > pq;


IMPORTANT:

Heap algorithms operate directly on a random-access range.

priority_queue gives a convenient container adaptor interface.


===============================================================================
HEAP SORT
===============================================================================

Heap sort can be implemented using:

    make_heap()
    sort_heap()


Example:

    vector<int> v = {
        40, 10, 50, 20, 30
    };

    make_heap(
        v.begin(),
        v.end()
    );

    sort_heap(
        v.begin(),
        v.end()
    );


Result:

    10 20 30 40 50


COMPLEXITY:

    make_heap:
        O(n)

    sort_heap:
        O(n log n)

Total:
    O(n log n)


===============================================================================
IMPORTANT DIFFERENCE:
sort() VS sort_heap()
===============================================================================

sort():

    sort(
        v.begin(),
        v.end()
    );


does NOT require the range to be a heap.


sort_heap():

    sort_heap(
        v.begin(),
        v.end()
    );


REQUIRES:
    range must already be a heap.


If you just want to sort a vector:

    sort()

is normally simpler.


If you specifically have a heap:

    sort_heap()


===============================================================================
IMPORTANT DIFFERENCE:
push_back() VS push_heap()
===============================================================================

push_back():

    adds an element at the end.

It does NOT maintain heap property.


Example:

    v.push_back(100);


After this:
    heap may be invalid.


Then:

    push_heap(
        v.begin(),
        v.end()
    );


restores heap property.


===============================================================================
IMPORTANT DIFFERENCE:
pop_back() VS pop_heap()
===============================================================================

pop_back():

    simply removes the last element.

It does NOT remove the heap top correctly.


For heap top removal:

    pop_heap(
        v.begin(),
        v.end()
    );

    v.pop_back();


First:
    top moves to end.

Second:
    last element is actually removed.


===============================================================================
CONTAINER DETAILS
===============================================================================

VECTOR
------

Heap algorithms:
    YES

Why:
    Random Access Iterator.

This is the most common container for manual heaps.


ARRAY
-----

Heap algorithms:
    YES

Why:
    Random Access Iterator.

Example:

    array<int, 5> a = {...};

    make_heap(
        a.begin(),
        a.end()
    );


DEQUE
-----

Heap algorithms:
    YES

Why:
    Random Access Iterator.


LIST
----

Heap algorithms:
    NO

Why:
    list has Bidirectional Iterator, not Random Access.

If you need a heap from list data:

    copy into vector.

Example:

    vector<int> v(
        li.begin(),
        li.end()
    );

    make_heap(
        v.begin(),
        v.end()
    );


FORWARD_LIST
------------

Heap algorithms:
    NO

Why:
    only Forward Iterator.


SET
---

Heap algorithms:
    NO

Why:
    set iterator is Bidirectional, not Random Access.

Also set itself is already an ordered tree structure, so heap algorithms
are not the natural operation.


MULTISET
--------

Heap algorithms:
    NO

Same reason as set.


MAP
---

Heap algorithms:
    NO

Same iterator limitation.

Also map is an ordered associative container.


MULTIMAP
--------

Heap algorithms:
    NO


UNORDERED_SET
-------------

Heap algorithms:
    NO

Why:
    unordered_set iterator is not Random Access.

Also it is hash-based, not an array-style heap range.


UNORDERED_MAP
-------------

Heap algorithms:
    NO


===============================================================================
COPY NON-RANDOM-ACCESS DATA INTO VECTOR
===============================================================================

If you have a list:

    list<int> li = {
        10, 50, 20, 40
    };


Create vector:

    vector<int> v(
        li.begin(),
        li.end()
    );


Then:

    make_heap(
        v.begin(),
        v.end()
    );


Now v is a heap.


===============================================================================
COMPLEXITY TABLE
===============================================================================

Algorithm       Complexity
--------------------------------
make_heap       O(n)
push_heap       O(log n)
pop_heap        O(log n)
sort_heap       O(n log n)
is_heap         O(n)
is_heap_until   O(n)


===============================================================================
COMMON MISTAKES
===============================================================================

MISTAKE 1:
    Thinking make_heap sorts the vector.

FALSE.

make_heap only creates heap structure.


MISTAKE 2:
    Thinking v.front() is always minimum.

DEFAULT heap is MAX-HEAP.

Therefore:

    v.front()
        -> maximum


For min-heap with greater:

    v.front()
        -> minimum


MISTAKE 3:
    Calling push_heap() after push_back() on a non-heap.

push_heap requires old range to already be a heap.


MISTAKE 4:
    Thinking pop_heap() removes an element.

FALSE.

pop_heap moves the top to the end.

You still need:

    pop_back()


MISTAKE 5:
    Mixing comparators.

If make_heap uses:

    greater<int>()

then push_heap/pop_heap/sort_heap/is_heap
should use the same comparator.


MISTAKE 6:
    Using list directly.

Heap algorithms need Random Access Iterators.

Use vector/array/deque.


MISTAKE 7:
    Assuming heap array is sorted.

Heap only guarantees parent-child relationship.


===============================================================================
DSA PATTERNS
===============================================================================

PATTERN 1:
    Need maximum repeatedly.

Use:

    max-heap


PATTERN 2:
    Need minimum repeatedly.

Use:

    min-heap


PATTERN 3:
    Insert + get max/min + remove max/min.

Use:

    priority_queue


PATTERN 4:
    Existing vector needs to become heap.

Use:

    make_heap()


PATTERN 5:
    Add one value to existing heap.

Use:

    push_back()
    push_heap()


PATTERN 6:
    Remove top from heap.

Use:

    pop_heap()
    pop_back()


PATTERN 7:
    Heap is already built and you want sorted output.

Use:

    sort_heap()


PATTERN 8:
    Check whether range is heap.

Use:

    is_heap()


PATTERN 9:
    Find where heap property breaks.

Use:

    is_heap_until()


===============================================================================
FINAL MEMORY TRICK
===============================================================================

MAKE:
    make_heap
    -> create heap

PUSH:
    push_back
    +
    push_heap
    -> add element and repair heap

POP:
    pop_heap
    +
    pop_back
    -> remove top

SORT:
    sort_heap
    -> sort an existing heap

CHECK:
    is_heap
    -> valid heap?

WHERE BREAKS:
    is_heap_until


DEFAULT:
    MAX-HEAP

MIN-HEAP:
    greater<T>()


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
#include <functional>

using namespace std;

// ============================================================================
// Helper function: print a range
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
// 1. make_heap() — MAX HEAP
// ============================================================================

void demoMakeHeap()
{
    vector<int> v = {
        10, 30, 20, 50, 40};

    cout << "Before make_heap:\n";
    printContainer(v, "v");

    make_heap(
        v.begin(),
        v.end());

    cout << "After make_heap:\n";
    printContainer(v, "v");

    /*
        IMPORTANT:

        v.front() is now the maximum.

        Do NOT expect the entire vector to be sorted.
    */

    cout << "Heap top = "
         << v.front()
         << '\n';

    cout << "Is valid heap? "
         << boolalpha
         << is_heap(
                v.begin(),
                v.end())
         << '\n';
}

// ============================================================================
// 2. push_heap()
// ============================================================================

void demoPushHeap()
{
    vector<int> v = {
        50, 40, 30, 10, 20};

    /*
        v is already a valid max-heap.

        Add a new value.
    */

    v.push_back(45);

    cout << "After push_back(45):\n";
    printContainer(v, "v");

    /*
        The new last element has been inserted,
        but heap property may be broken.

        Repair it using push_heap().
    */

    push_heap(
        v.begin(),
        v.end());

    cout << "After push_heap():\n";
    printContainer(v, "v");

    cout << "Top = "
         << v.front()
         << '\n';
}

// ============================================================================
// 3. pop_heap()
// ============================================================================

void demoPopHeap()
{
    vector<int> v = {
        50, 40, 45, 10, 20, 30};

    cout << "Before pop_heap:\n";
    printContainer(v, "v");

    pop_heap(
        v.begin(),
        v.end());

    /*
        IMPORTANT:

        pop_heap DOES NOT reduce vector size.

        It moves the old heap top to the last position.

        Therefore 50 is now at the end.
    */

    cout << "After pop_heap():\n";
    printContainer(v, "v");

    cout << "Last element = "
         << v.back()
         << '\n';

    /*
        To actually remove the old top:
    */

    v.pop_back();

    cout << "After pop_back():\n";
    printContainer(v, "v");

    cout << "New top = "
         << v.front()
         << '\n';
}

// ============================================================================
// 4. sort_heap()
// ============================================================================

void demoSortHeap()
{
    vector<int> v = {
        40, 10, 50, 20, 30};

    /*
        First create a heap.
    */

    make_heap(
        v.begin(),
        v.end());

    cout << "After make_heap:\n";
    printContainer(v, "v");

    /*
        Now sort the HEAP.

        With default max-heap comparator,
        result is ascending.
    */

    sort_heap(
        v.begin(),
        v.end());

    cout << "After sort_heap:\n";
    printContainer(v, "v");
}

// ============================================================================
// 5. is_heap()
// ============================================================================

void demoIsHeap()
{
    vector<int> heap = {
        50, 40, 45, 10, 20, 30};

    vector<int> notHeap = {
        10, 50, 30, 20};

    cout << boolalpha;

    cout << "heap is heap? "
         << is_heap(
                heap.begin(),
                heap.end())
         << '\n';

    cout << "notHeap is heap? "
         << is_heap(
                notHeap.begin(),
                notHeap.end())
         << '\n';
}

// ============================================================================
// 6. is_heap_until()
// ============================================================================

void demoIsHeapUntil()
{
    vector<int> v = {
        50, 40, 45, 10, 20, 60};

    /*
        The last value may break the max-heap property.

        is_heap_until() returns the first position where
        the heap property stops being valid.
    */

    auto it = is_heap_until(
        v.begin(),
        v.end());

    if (it == v.end())
    {
        cout << "Entire range is a heap.\n";
    }
    else
    {
        cout << "Heap property breaks at value = "
             << *it
             << '\n';

        cout << "Index = "
             << it - v.begin()
             << '\n';
    }
}

// ============================================================================
// 7. MIN-HEAP
// ============================================================================

void demoMinHeap()
{
    vector<int> v = {
        10, 30, 20, 50, 40};

    /*
        greater<int>() changes the ordering.

        Default:
            max-heap

        greater<int>():
            min-heap
    */

    make_heap(
        v.begin(),
        v.end(),
        greater<int>());

    printContainer(
        v,
        "Min-heap");

    cout << "Minimum at top = "
         << v.front()
         << '\n';

    cout << "Is min-heap? "
         << boolalpha
         << is_heap(
                v.begin(),
                v.end(),
                greater<int>())
         << '\n';
}

// ============================================================================
// 8. MIN-HEAP PUSH
// ============================================================================

void demoMinHeapPush()
{
    vector<int> v = {
        10, 30, 20, 50, 40};

    make_heap(
        v.begin(),
        v.end(),
        greater<int>());

    v.push_back(5);

    push_heap(
        v.begin(),
        v.end(),
        greater<int>());

    printContainer(
        v,
        "Min-heap after push");

    cout << "Top = "
         << v.front()
         << '\n';
}

// ============================================================================
// 9. MIN-HEAP POP
// ============================================================================

void demoMinHeapPop()
{
    vector<int> v = {
        10, 30, 20, 50, 40};

    make_heap(
        v.begin(),
        v.end(),
        greater<int>());

    pop_heap(
        v.begin(),
        v.end(),
        greater<int>());

    /*
        Smallest element moved to end.
    */

    cout << "Removed top = "
         << v.back()
         << '\n';

    v.pop_back();

    cout << "New min-heap top = "
         << v.front()
         << '\n';
}

// ============================================================================
// 10. Heap Sort
// ============================================================================

void demoHeapSort()
{
    vector<int> v = {
        70, 20, 50, 10, 40, 60, 30};

    /*
        Heap sort manually:

            Step 1:
                make_heap()

            Step 2:
                sort_heap()
    */

    make_heap(
        v.begin(),
        v.end());

    sort_heap(
        v.begin(),
        v.end());

    printContainer(
        v,
        "Heap sorted");
}

// ============================================================================
// 11. array works
// ============================================================================

void demoArray()
{
    array<int, 6> a = {
        10, 50, 20, 40, 30, 60};

    make_heap(
        a.begin(),
        a.end());

    cout << "array heap top = "
         << a.front()
         << '\n';

    sort_heap(
        a.begin(),
        a.end());

    cout << "array after sort_heap = ";

    for (int x : a)
    {
        cout << x << ' ';
    }

    cout << '\n';
}

// ============================================================================
// 12. deque works
// ============================================================================

void demoDeque()
{
    deque<int> dq = {
        10, 40, 20, 50, 30};

    make_heap(
        dq.begin(),
        dq.end());

    cout << "deque heap top = "
         << dq.front()
         << '\n';
}

// ============================================================================
// 13. list DOES NOT work directly
// ============================================================================

void demoListConversion()
{
    list<int> li = {
        10, 50, 20, 40};

    /*
        This would NOT compile:

            make_heap(
                li.begin(),
                li.end()
            );

        because list iterator is Bidirectional,
        while heap algorithms require Random Access Iterator.

        Solution:
        Copy into vector.
    */

    vector<int> v(
        li.begin(),
        li.end());

    make_heap(
        v.begin(),
        v.end());

    printContainer(
        v,
        "Heap created from list");
}

// ============================================================================
// 14. Complete manual priority queue style
// ============================================================================

void demoManualPriorityQueue()
{
    vector<int> heap;

    // INSERT 10
    heap.push_back(10);
    push_heap(
        heap.begin(),
        heap.end());

    // INSERT 30
    heap.push_back(30);
    push_heap(
        heap.begin(),
        heap.end());

    // INSERT 20
    heap.push_back(20);
    push_heap(
        heap.begin(),
        heap.end());

    // INSERT 50
    heap.push_back(50);
    push_heap(
        heap.begin(),
        heap.end());

    cout << "Current max = "
         << heap.front()
         << '\n';

    // REMOVE MAX
    pop_heap(
        heap.begin(),
        heap.end());

    cout << "Removed max = "
         << heap.back()
         << '\n';

    heap.pop_back();

    cout << "New max = "
         << heap.front()
         << '\n';
}

// ============================================================================
// MAIN
// ============================================================================

int main()
{
    cout << "========== make_heap() ==========\n";
    demoMakeHeap();

    cout << "\n========== push_heap() ==========\n";
    demoPushHeap();

    cout << "\n========== pop_heap() ==========\n";
    demoPopHeap();

    cout << "\n========== sort_heap() ==========\n";
    demoSortHeap();

    cout << "\n========== is_heap() ==========\n";
    demoIsHeap();

    cout << "\n========== is_heap_until() ==========\n";
    demoIsHeapUntil();

    cout << "\n========== MIN-HEAP ==========\n";
    demoMinHeap();

    cout << "\n========== MIN-HEAP PUSH ==========\n";
    demoMinHeapPush();

    cout << "\n========== MIN-HEAP POP ==========\n";
    demoMinHeapPop();

    cout << "\n========== HEAP SORT ==========\n";
    demoHeapSort();

    cout << "\n========== array ==========\n";
    demoArray();

    cout << "\n========== deque ==========\n";
    demoDeque();

    cout << "\n========== list -> vector ==========\n";
    demoListConversion();

    cout << "\n========== Manual Priority Queue Style ==========\n";
    demoManualPriorityQueue();

    return 0;
}
