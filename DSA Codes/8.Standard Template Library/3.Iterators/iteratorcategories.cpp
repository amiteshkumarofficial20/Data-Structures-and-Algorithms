/*
================================================================================
                 C++ STL ITERATOR CATEGORIES - VERY DETAILED
                 THEORY + OPERATIONS + CODE + CONTAINER MAPPING
================================================================================

PURPOSE
-------
This file explains ALL major STL iterator categories in detail:

    1. Input Iterator
    2. Output Iterator
    3. Forward Iterator
    4. Bidirectional Iterator
    5. Random Access Iterator
    6. Contiguous Iterator

For every category we cover:

    - What it means
    - Read capability
    - Write capability
    - Forward movement
    - Backward movement
    - Random access
    - Multi-pass behavior
    - Important operations
    - Which operations are NOT allowed
    - Example
    - Real STL examples
    - Container mapping
    - Algorithm compatibility
    - Complexity ideas
    - Common mistakes

================================================================================
CORE IDEA
================================================================================

An iterator represents a POSITION in a range.

Example:

    vector<int> v = {10, 20, 30};

             iterator
                 |
                 v
            [10] [20] [30]

    *itr
        means the VALUE at the current position.

So:

    itr  = position
    *itr = value

The iterator category tells us:

    "What kind of movement and access is this iterator capable of?"

================================================================================
IMPORTANT HIERARCHY
================================================================================

The standard iterator capability hierarchy can be remembered as:

    Input
       ^
       |
    Forward
       ^
       |
    Bidirectional
       ^
       |
    Random Access
       ^
       |
    Contiguous

Output is a separate write-oriented category.

Think:

    Input:
        READ

    Output:
        WRITE

    Forward:
        READ + WRITE + FORWARD

    Bidirectional:
        READ + WRITE + FORWARD + BACKWARD

    Random Access:
        everything above + JUMP DIRECTLY

    Contiguous:
        Random Access + CONTIGUOUS MEMORY


IMPORTANT NOTE ABOUT WRITE:
----------------------------

"Forward/Bidirectional/Random Access/Contiguous = writable" is a capability
idea, but an actual iterator can still be const.

For example:

    vector<int>::iterator
        can modify int

    vector<int>::const_iterator
        cannot modify int

Therefore write capability also depends on the iterator/reference type.

================================================================================
*/

#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <string>
#include <type_traits>
#include <sstream>

using namespace std;

// ================================================================================
// 1. INPUT ITERATOR
// ================================================================================

void inputIteratorTheory()
{
    cout << "\n============================================================\n";
    cout << "1. INPUT ITERATOR\n";
    cout << "============================================================\n";

    /*
    ----------------------------------------------------------------------------
    INPUT ITERATOR = READ + MOVE FORWARD
    ----------------------------------------------------------------------------

    Main idea:

        Input Iterator is used to READ values while moving forward.

    Capabilities:

        READ:
            YES

        WRITE:
            NO as a general category guarantee

        FORWARD:
            YES

        BACKWARD:
            NO

        RANDOM ACCESS:
            NO

        Multiple passes:
            NOT generally guaranteed

    Basic operations:

        *itr
        ++itr
        itr++
        itr == other
        itr != other

    Not available as general guarantees:

        --itr
        itr--
        itr + n
        itr - n
        itr[n]
        itr1 - itr2
        itr1 < itr2

    IMPORTANT:
    Input iterators are traditionally associated with single-pass traversal.

    Example idea:

        read data from an input stream.

    A classic STL example is:

        istream_iterator<int>

    ----------------------------------------------------------------------------
    */

    /*
        We can demonstrate the INPUT iterator concept using a string stream.

        istringstream provides stream input without requiring keyboard input.
    */

    istringstream input(
        "10 20 30 40");

    istream_iterator<int> itr(input);
    istream_iterator<int> end;

    while (itr != end)
    {
        /*
         *itr = current value read from stream.
         */

        cout << *itr << " ";

        /*
            ++itr reads/moves to the next input value.
        */

        ++itr;
    }

    cout << "\n";
}

// ================================================================================
// 2. OUTPUT ITERATOR
// ================================================================================

void outputIteratorTheory()
{
    cout << "\n============================================================\n";
    cout << "2. OUTPUT ITERATOR\n";
    cout << "============================================================\n";

    /*
    ----------------------------------------------------------------------------
    OUTPUT ITERATOR = WRITE + MOVE FORWARD
    ----------------------------------------------------------------------------

    Main idea:

        Output iterator is used to WRITE values to some destination.

    Capabilities:

        READ:
            NOT a general guarantee

        WRITE:
            YES

        FORWARD:
            It can be incremented to continue output.

        BACKWARD:
            NO

        RANDOM ACCESS:
            NO

        Multi-pass:
            Not generally guaranteed

    Main operations:

        *itr = value
        ++itr
        itr++

    Do NOT expect:

        value = *itr

        to be generally valid for an output iterator.

    Classic examples:

        ostream_iterator
        back_insert_iterator
        front_insert_iterator
        insert_iterator

    ----------------------------------------------------------------------------
    */

    vector<int> source = {
        10, 20, 30};

    /*
        ostream_iterator writes each assigned value to cout.
    */

    ostream_iterator<int> out(
        cout,
        " ");

    for (int value : source)
    {
        /*
            This is conceptually writing through the output iterator.
        */

        *out = value;

        ++out;
    }

    cout << "\n";

    /*
        IMPORTANT:

        Output iterator is about OUTPUT.

        You should not assume that:

            cout << *out;

        is meaningful for every output iterator.
    */
}

// ================================================================================
// 3. FORWARD ITERATOR
// ================================================================================

void forwardIteratorTheory()
{
    cout << "\n============================================================\n";
    cout << "3. FORWARD ITERATOR\n";
    cout << "============================================================\n";

    /*
    ----------------------------------------------------------------------------
    FORWARD ITERATOR = READ + FORWARD + MULTI-PASS
    ----------------------------------------------------------------------------

    Compared with Input Iterator:

        Forward Iterator supports repeated passes over the range.

    Capabilities:

        READ:
            YES

        WRITE:
            YES when the referenced value is modifiable

        FORWARD:
            YES

        BACKWARD:
            NO

        RANDOM ACCESS:
            NO

    Main operations:

        *itr
        ++itr
        itr++
        itr1 == itr2
        itr1 != itr2

    Not supported:

        --itr
        itr--
        itr + n
        itr - n
        itr[n]
        itr1 - itr2
        itr1 < itr2

    Typical STL example:

        forward_list

    unordered containers also provide forward iterators.

    ----------------------------------------------------------------------------
    */

    forward_list<int> fl = {
        10, 20, 30, 40};

    auto itr = fl.begin();

    /*
        READ:
    */

    cout << "Current = "
         << *itr
         << "\n";

    /*
        WRITE:

        Since this is a non-const iterator, we can modify the value.
    */

    *itr = 100;

    cout << "After write = "
         << *itr
         << "\n";

    /*
        FORWARD MOVEMENT:
    */

    ++itr;

    cout << "Next = "
         << *itr
         << "\n";

    /*
        The following would NOT compile:

            --itr;
            itr + 2;
            itr[2];
    */
}

// ================================================================================
// 4. BIDIRECTIONAL ITERATOR
// ================================================================================

void bidirectionalIteratorTheory()
{
    cout << "\n============================================================\n";
    cout << "4. BIDIRECTIONAL ITERATOR\n";
    cout << "============================================================\n";

    /*
    ----------------------------------------------------------------------------
    BIDIRECTIONAL = FORWARD + BACKWARD
    ----------------------------------------------------------------------------

    Everything a Forward Iterator can do, plus:

        --itr
        itr--

    Capabilities:

        READ:
            YES

        WRITE:
            YES when mutable

        FORWARD:
            YES

        BACKWARD:
            YES

        RANDOM ACCESS:
            NO

    Main operations:

        *itr
        ++itr
        itr++
        --itr
        itr--
        ==
        !=

    NOT supported as general operations:

        itr + n
        itr - n
        itr += n
        itr -= n
        itr[n]
        itr1 - itr2
        itr1 < itr2

    Typical STL examples:

        list
        set
        multiset
        map
        multimap

    ----------------------------------------------------------------------------
    */

    list<int> li = {
        10, 20, 30, 40};

    auto itr = li.begin();

    /*
        Forward:
    */

    ++itr;

    cout << "After ++itr = "
         << *itr
         << "\n";

    /*
        Backward:

        Since list is Bidirectional, -- is valid.
    */

    --itr;

    cout << "After --itr = "
         << *itr
         << "\n";

    /*
        But:

            itr + 2

        is NOT valid for list.

        If we need to move 2 positions:

            advance(itr, 2);

        can be used.
    */

    advance(
        itr,
        2);

    cout << "After advance(2) = "
         << *itr
         << "\n";
}

// ================================================================================
// 5. RANDOM ACCESS ITERATOR
// ================================================================================

void randomAccessIteratorTheory()
{
    cout << "\n============================================================\n";
    cout << "5. RANDOM ACCESS ITERATOR\n";
    cout << "============================================================\n";

    /*
    ----------------------------------------------------------------------------
    RANDOM ACCESS = BIDIRECTIONAL + DIRECT JUMP
    ----------------------------------------------------------------------------

    Random Access Iterator supports everything from Bidirectional Iterator
    plus direct movement and position arithmetic.

    Capabilities:

        READ:
            YES

        WRITE:
            YES when mutable

        FORWARD:
            YES

        BACKWARD:
            YES

        RANDOM ACCESS:
            YES

    Supported:

        *itr
        ++itr
        itr++
        --itr
        itr--

        itr + n
        itr - n

        itr += n
        itr -= n

        itr[n]

        itr1 - itr2

        itr1 < itr2
        itr1 > itr2
        itr1 <= itr2
        itr1 >= itr2

        itr1 == itr2
        itr1 != itr2

    Typical STL examples:

        vector
        array
        deque

    ----------------------------------------------------------------------------
    */

    vector<int> v = {
        10, 20, 30, 40, 50};

    auto itr = v.begin();

    /*
        Dereference:
    */

    cout << "*itr = "
         << *itr
         << "\n";

    /*
        Forward:
    */

    ++itr;

    cout << "++itr = "
         << *itr
         << "\n";

    /*
        Backward:
    */

    --itr;

    cout << "--itr = "
         << *itr
         << "\n";

    /*
        DIRECT JUMP:

            itr + 3
    */

    cout << "itr + 3 = "
         << *(itr + 3)
         << "\n";

    /*
        DIRECT BACKWARD JUMP:

            itr + 4
            then -2

        or simply:

            itr + 2
    */

    auto result = itr + 4;

    result -= 2;

    cout << "result after -= 2 = "
         << *result
         << "\n";

    /*
        INDEXING:

            itr[3]

        is equivalent to:

            *(itr + 3)
    */

    cout << "itr[3] = "
         << itr[3]
         << "\n";

    /*
        DISTANCE:

            v.end() - v.begin()
    */

    cout << "distance = "
         << v.end() - v.begin()
         << "\n";

    /*
        RELATIONAL COMPARISON:
    */

    auto a = v.begin();

    auto b = v.begin() + 3;

    if (a < b)
    {
        cout << "a is before b\n";
    }
}

// ================================================================================
// 6. CONTIGUOUS ITERATOR
// ================================================================================

void contiguousIteratorTheory()
{
    cout << "\n============================================================\n";
    cout << "6. CONTIGUOUS ITERATOR\n";
    cout << "============================================================\n";

    /*
    ----------------------------------------------------------------------------
    CONTIGUOUS = RANDOM ACCESS + CONTIGUOUS MEMORY
    ----------------------------------------------------------------------------

    A Contiguous Iterator has all Random Access capabilities.

    Additionally, successive elements are stored contiguously in memory.

    Capabilities:

        READ:
            YES

        WRITE:
            YES when mutable

        FORWARD:
            YES

        BACKWARD:
            YES

        RANDOM ACCESS:
            YES

        CONTIGUOUS MEMORY:
            YES

    Examples:

        vector<T>::iterator
        array<T, N>::iterator
        raw pointer to an array

    IMPORTANT:

        deque has Random Access Iterators,

        BUT deque is NOT a contiguous container.

    ----------------------------------------------------------------------------
    */

    vector<int> v = {
        10, 20, 30, 40};

    auto itr = v.begin();

    /*
        All Random Access operations work:
    */

    cout << *(itr + 2)
         << "\n";

    cout << itr[3]
         << "\n";

    /*
        Contiguous memory means the elements are adjacent in memory.

        &v[0], &v[1], &v[2] etc. refer to consecutive element storage.
    */

    cout << "Address of first = "
         << static_cast<const void *>(&v[0])
         << "\n";

    cout << "Address of second = "
         << static_cast<const void *>(&v[1])
         << "\n";
}

// ================================================================================
// 7. RAW POINTER AS CONTIGUOUS ITERATOR
// ================================================================================

void rawPointerAsIterator()
{
    cout << "\n============================================================\n";
    cout << "7. RAW POINTER AS CONTIGUOUS ITERATOR\n";
    cout << "============================================================\n";

    int arr[] = {
        10, 20, 30, 40};

    /*
        A raw pointer can act as an iterator for an array.

            int* itr = arr;

        This is a Contiguous Iterator.

        It supports:

            *itr
            ++itr
            --itr
            itr + n
            itr - n
            itr[n]
            itr1 - itr2
            comparisons
    */

    int *itr = arr;

    cout << *itr << "\n";

    cout << *(itr + 2)
         << "\n";

    cout << itr[3]
         << "\n";

    ++itr;

    cout << *itr << "\n";
}

// ================================================================================
// 8. INPUT VS FORWARD
// ================================================================================

void inputVsForward()
{
    cout << "\n============================================================\n";
    cout << "8. INPUT VS FORWARD\n";
    cout << "============================================================\n";

    /*
    INPUT ITERATOR:

        read
        forward
        single-pass behavior

    FORWARD ITERATOR:

        read
        forward
        multi-pass

    Example intuition:

        Input:
            "I am consuming a stream."

        Forward:
            "I can traverse the same range again."
    */

    cout << "Input = read + forward + generally single-pass\n";

    cout << "Forward = input-like reading + multi-pass traversal\n";
}

// ================================================================================
// 9. FORWARD VS BIDIRECTIONAL
// ================================================================================

void forwardVsBidirectional()
{
    cout << "\n============================================================\n";
    cout << "9. FORWARD VS BIDIRECTIONAL\n";
    cout << "============================================================\n";

    /*
        Forward:

            ++itr
            but NOT --itr

        Bidirectional:

            ++itr
            --itr

        Therefore Bidirectional adds BACKWARD MOVEMENT.
    */

    forward_list<int> fl = {
        10, 20, 30};

    auto f = fl.begin();

    ++f;

    cout << "Forward iterator after ++ = "
         << *f
         << "\n";

    list<int> li = {
        10, 20, 30};

    auto b = li.begin();

    ++b;
    --b;

    cout << "Bidirectional after ++ and -- = "
         << *b
         << "\n";
}

// ================================================================================
// 10. BIDIRECTIONAL VS RANDOM ACCESS
// ================================================================================

void bidirectionalVsRandom()
{
    cout << "\n============================================================\n";
    cout << "10. BIDIRECTIONAL VS RANDOM ACCESS\n";
    cout << "============================================================\n";

    /*
        Bidirectional:

            ++
            --

        Random Access:

            ++
            --
            + n
            - n
            +=
            -=
            [n]
            iterator difference
            relational ordering
    */

    list<int> li = {
        10, 20, 30, 40};

    auto listItr = li.begin();

    advance(
        listItr,
        3);

    cout << "List moved using advance = "
         << *listItr
         << "\n";

    vector<int> v = {
        10, 20, 30, 40};

    auto vectorItr = v.begin();

    /*
        Vector can jump directly.
    */

    cout << "Vector jump = "
         << *(vectorItr + 3)
         << "\n";
}

// ================================================================================
// 11. RANDOM ACCESS VS CONTIGUOUS
// ================================================================================

void randomVsContiguous()
{
    cout << "\n============================================================\n";
    cout << "11. RANDOM ACCESS VS CONTIGUOUS\n";
    cout << "============================================================\n";

    /*
        vector:
            Random Access
            Contiguous

        deque:
            Random Access
            NOT Contiguous

    So:

        Random Access does NOT automatically mean contiguous memory.
    */

    vector<int> v = {
        10, 20, 30};

    deque<int> d = {
        10, 20, 30};

    cout << "vector random access = "
         << v[2]
         << "\n";

    cout << "deque random access = "
         << d[2]
         << "\n";

    cout << "Both support random access.\n";
    cout << "Only vector/array guarantee contiguous storage.\n";
}

// ================================================================================
// 12. COMPLETE OPERATION TABLE
// ================================================================================

void completeOperationTable()
{
    cout << "\n============================================================\n";
    cout << "12. COMPLETE OPERATION TABLE\n";
    cout << "============================================================\n";

    /*
    =============================================================================
    OPERATION / CAPABILITY

    Legend:
        YES = category guarantees it
        NO  = category does not guarantee it
    =============================================================================


    INPUT ITERATOR
    --------------
        *itr             YES
        ++itr            YES
        itr++            YES
        --itr            NO
        itr--            NO
        itr + n          NO
        itr - n          NO
        itr += n         NO
        itr -= n         NO
        itr[n]           NO
        itr1 - itr2      NO
        itr1 == itr2     YES
        itr1 != itr2     YES
        itr1 < itr2      NO
        itr1 > itr2      NO
        itr1 <= itr2     NO
        itr1 >= itr2     NO


    OUTPUT ITERATOR
    ---------------
        *itr = value     YES
        ++itr            YES
        itr++            YES

        Reading:
            *itr         NOT generally guaranteed

        --itr            NO
        itr + n          NO
        itr[n]           NO
        relational order NO


    FORWARD ITERATOR
    ----------------
        *itr             YES
        ++itr            YES
        itr++            YES
        --itr            NO
        itr--            NO
        itr + n          NO
        itr - n          NO
        itr += n         NO
        itr -= n         NO
        itr[n]           NO
        itr1 - itr2      NO
        itr1 == itr2     YES
        itr1 != itr2     YES
        relational order NO

        Writable when underlying reference is mutable.


    BIDIRECTIONAL ITERATOR
    ----------------------
        *itr             YES
        ++itr            YES
        itr++            YES
        --itr            YES
        itr--            YES

        itr + n          NO
        itr - n          NO
        itr += n         NO
        itr -= n         NO
        itr[n]           NO
        itr1 - itr2      NO
        relational order NO

        Equality:
            == YES
            != YES


    RANDOM ACCESS ITERATOR
    ----------------------
        *itr             YES
        ++itr            YES
        itr++            YES
        --itr            YES
        itr--            YES

        itr + n          YES
        itr - n          YES
        itr += n         YES
        itr -= n         YES
        itr[n]           YES
        itr1 - itr2      YES

        == YES
        != YES
        <  YES
        >  YES
        <= YES
        >= YES


    CONTIGUOUS ITERATOR
    -------------------
        Everything Random Access has:

            *itr
            ++
            --
            +n
            -n
            +=
            -=
            [n]
            difference
            relational comparison

        PLUS:

            contiguous memory guarantee
    =============================================================================
    */
}

// ================================================================================
// 13. CONTAINER MAPPING
// ================================================================================

void containerMapping()
{
    cout << "\n============================================================\n";
    cout << "13. CONTAINER -> ITERATOR CATEGORY\n";
    cout << "============================================================\n";

    /*
    =============================================================================
    CONTAINER               ITERATOR CATEGORY
    =============================================================================

    vector<T>               Random Access + Contiguous

    array<T,N>              Random Access + Contiguous

    deque<T>                Random Access

    list<T>                 Bidirectional

    forward_list<T>         Forward

    set<T>                  Bidirectional

    multiset<T>             Bidirectional

    map<K,V>                Bidirectional

    multimap<K,V>           Bidirectional

    unordered_set<T>        Forward

    unordered_multiset      Forward

    unordered_map<K,V>      Forward

    unordered_multimap      Forward

    raw array pointer       Contiguous
    =============================================================================
    */

    cout << "Container mapping is documented in the comments.\n";
}

// ================================================================================
// 14. READ / WRITE SUMMARY
// ================================================================================

void readWriteSummary()
{
    cout << "\n============================================================\n";
    cout << "14. READ / WRITE SUMMARY\n";
    cout << "============================================================\n";

    /*
    =============================================================================
    CATEGORY             READ             WRITE
    =============================================================================

    Input                YES              NO as general guarantee

    Output               NO as general    YES
                         guarantee

    Forward              YES              YES if mutable

    Bidirectional         YES              YES if mutable

    Random Access         YES              YES if mutable

    Contiguous             YES              YES if mutable
    =============================================================================

    IMPORTANT:

        const_iterator changes the write capability.

    Example:

        vector<int>::iterator

            *itr = 100;       // allowed

        vector<int>::const_iterator

            *itr = 100;       // ERROR

    So iterator category and constness are two different concepts.
    */
}

// ================================================================================
// 15. MOVEMENT SUMMARY
// ================================================================================

void movementSummary()
{
    cout << "\n============================================================\n";
    cout << "15. MOVEMENT SUMMARY\n";
    cout << "============================================================\n";

    /*
    =============================================================================
    CATEGORY              FORWARD          BACKWARD       RANDOM JUMP
    =============================================================================

    Input                    YES               NO              NO

    Output                   YES               NO              NO

    Forward                  YES               NO              NO

    Bidirectional            YES               YES             NO

    Random Access            YES               YES             YES

    Contiguous               YES               YES             YES
    =============================================================================

    RANDOM JUMP means:

        itr + 5
        itr - 5
        itr[5]

    ============================================================================
    */
}

// ================================================================================
// 16. ALGORITHMS AND ITERATOR REQUIREMENTS
// ================================================================================

void algorithmRequirements()
{
    cout << "\n============================================================\n";
    cout << "16. ALGORITHM REQUIREMENTS\n";
    cout << "============================================================\n";

    /*
    IMPORTANT:

        Algorithms require different iterator capabilities.

    ---------------------------------------------------------------------------
    find()
    ---------------------------------------------------------------------------

        Works with input-style traversal.

        Does not need random access.

    ---------------------------------------------------------------------------
    count()
    ---------------------------------------------------------------------------

        Needs readable forward traversal.

    ---------------------------------------------------------------------------
    reverse()
    ---------------------------------------------------------------------------

        Needs Bidirectional Iterator.

    ---------------------------------------------------------------------------
    sort()
    ---------------------------------------------------------------------------

        std::sort requires Random Access Iterators.

        Therefore:

            vector -> YES
            array  -> YES
            deque  -> YES
            list   -> NO

        For list use:

            list.sort();

    ---------------------------------------------------------------------------
    lower_bound()
    ---------------------------------------------------------------------------

        Can operate on forward/random-access iterator ranges.

        But performance differs based on iterator category.

        Random access allows logarithmic-style iterator movement.

        With weaker iterator categories, movement to the midpoint may
        require linear iterator advancement.

    ---------------------------------------------------------------------------
    */

    vector<int> v = {
        10, 20, 30, 40};

    auto itr = find(
        v.begin(),
        v.end(),
        30);

    if (itr != v.end())
    {
        cout << "find() found: "
             << *itr
             << "\n";
    }
}

// ================================================================================
// 17. TYPE TRAITS: ITERATOR CATEGORY INSPECTION
// ================================================================================

void iteratorCategoryInspection()
{
    cout << "\n============================================================\n";
    cout << "17. ITERATOR CATEGORY INSPECTION\n";
    cout << "============================================================\n";

    /*
        C++ provides iterator traits.

        Example:

            iterator_traits<Iterator>::iterator_category

        Older-style category tags can be inspected this way.

        Modern C++20 also provides iterator concepts such as:

            input_iterator
            output_iterator
            forward_iterator
            bidirectional_iterator
            random_access_iterator
            contiguous_iterator

        We use static_assert below to demonstrate the modern concepts.
    */

    vector<int> v = {10, 20, 30};

    using VIterator =
        vector<int>::iterator;

    /*
        vector iterator is Random Access.
    */

    static_assert(
        random_access_iterator<VIterator>);

    static_assert(
        contiguous_iterator<VIterator>);

    cout << "vector iterator is Random Access + Contiguous.\n";
}

// ================================================================================
// 18. C++20 CONCEPT CHECKS
// ================================================================================

void cplusplus20ConceptChecks()
{
    cout << "\n============================================================\n";
    cout << "18. C++20 CONCEPT CHECKS\n";
    cout << "============================================================\n";

    /*
        C++20 iterator concepts give a direct way to ask:

            Is this iterator a forward iterator?
            Is this iterator bidirectional?
            Is this iterator random access?
            Is this iterator contiguous?

        NOTE:
        These concepts require compiling with C++20 or later.

        Example compiler:

            g++ -std=c++20 iteratorcategories.cpp
    */

    vector<int> v = {10, 20, 30};

    using V =
        vector<int>::iterator;

    using L =
        list<int>::iterator;

    using F =
        forward_list<int>::iterator;

    static_assert(
        forward_iterator<V>);

    static_assert(
        bidirectional_iterator<V>);

    static_assert(
        random_access_iterator<V>);

    static_assert(
        contiguous_iterator<V>);

    static_assert(
        forward_iterator<L>);

    static_assert(
        bidirectional_iterator<L>);

    static_assert(
        !random_access_iterator<L>);

    static_assert(
        forward_iterator<F>);

    static_assert(
        !bidirectional_iterator<F>);

    cout << "C++20 concept checks passed.\n";
}

// ================================================================================
// 19. CONST ITERATOR VS CATEGORY
// ================================================================================

void constIteratorAndCategory()
{
    cout << "\n============================================================\n";
    cout << "19. CONST ITERATOR VS CATEGORY\n";
    cout << "============================================================\n";

    vector<int> v = {
        10, 20, 30};

    /*
        const_iterator is still a Random Access + Contiguous iterator
        for vector.

        BUT it cannot modify the element.
    */

    auto itr = v.cbegin();

    cout << *itr << "\n";

    cout << *(itr + 2)
         << "\n";

    /*
        This would be ERROR:

            *itr = 100;

        So:

            iterator category
                !=
            mutability
    */
}

// ================================================================================
// 20. REVERSE ITERATOR CATEGORY
// ================================================================================

void reverseIteratorCategory()
{
    cout << "\n============================================================\n";
    cout << "20. REVERSE ITERATOR CATEGORY\n";
    cout << "============================================================\n";

    vector<int> v = {
        10, 20, 30, 40};

    auto itr = v.rbegin();

    /*
        A reverse iterator adapts another iterator and reverses movement.

        For vector:

            reverse_iterator
                is still capable of random access.

        ++itr:
            moves toward beginning of original container.

        --itr:
            moves toward end of original container.

        itr + n:
            moves n positions in reverse direction.
    */

    cout << *itr << "\n"; // 40

    ++itr;

    cout << *itr << "\n"; // 30

    cout << itr[1] << "\n"; // 20
}

// ================================================================================
// 21. COMMON MISTAKES
// ================================================================================

void commonMistakes()
{
    cout << "\n============================================================\n";
    cout << "21. COMMON MISTAKES\n";
    cout << "============================================================\n";

    /*
    ============================================================================
    MISTAKE 1: DEREFERENCE end()

        auto itr = v.end();
        cout << *itr;

    WRONG.

    end() is one-past-the-end.


    ============================================================================
    MISTAKE 2: itr + n ON list

        list<int> li = {10,20,30};
        auto itr = li.begin();

        itr + 2;        // WRONG

    Use:

        advance(itr, 2);


    ============================================================================
    MISTAKE 3: -- ON forward_list

        forward_list<int> fl;
        auto itr = fl.begin();

        --itr;          // WRONG


    ============================================================================
    MISTAKE 4: itr[n] ON set/map/list

        itr[2];         // WRONG

    These are not Random Access Iterators.


    ============================================================================
    MISTAKE 5: MODIFY const_iterator

        *itr = 100;     // WRONG if itr is const_iterator


    ============================================================================
    MISTAKE 6: ASSUME RANDOM ACCESS = CONTIGUOUS

        deque has Random Access Iterators,

        but deque is not contiguous.


    ============================================================================
    MISTAKE 7: USE INVALIDATED ITERATOR

    After certain vector insertions/reallocations, old iterators can become
    invalid.

    Always understand the invalidation rules of the container and operation.
    ============================================================================
    */

    cout << "Common mistakes are documented above.\n";
}

// ================================================================================
// 22. FINAL MASTER TABLE
// ================================================================================

void finalMasterTable()
{
    cout << "\n============================================================\n";
    cout << "22. FINAL MASTER TABLE\n";
    cout << "============================================================\n";

    /*
    =================================================================================
    CATEGORY
    =================================================================================

    INPUT
        READ                YES
        WRITE               NO general guarantee
        FORWARD             YES
        BACKWARD            NO
        RANDOM ACCESS       NO
        MULTI-PASS          NO general guarantee

    OUTPUT
        READ                NO general guarantee
        WRITE               YES
        FORWARD             YES
        BACKWARD            NO
        RANDOM ACCESS       NO
        MULTI-PASS          NO general guarantee

    FORWARD
        READ                YES
        WRITE               YES if mutable
        FORWARD             YES
        BACKWARD            NO
        RANDOM ACCESS       NO
        MULTI-PASS          YES

    BIDIRECTIONAL
        READ                YES
        WRITE               YES if mutable
        FORWARD             YES
        BACKWARD            YES
        RANDOM ACCESS       NO
        MULTI-PASS          YES

    RANDOM ACCESS
        READ                YES
        WRITE               YES if mutable
        FORWARD             YES
        BACKWARD            YES
        RANDOM ACCESS       YES
        MULTI-PASS          YES

    CONTIGUOUS
        READ                YES
        WRITE               YES if mutable
        FORWARD             YES
        BACKWARD            YES
        RANDOM ACCESS       YES
        CONTIGUOUS MEMORY   YES
        MULTI-PASS          YES


    =================================================================================
    CONTAINER
    =================================================================================

    vector              -> Random Access + Contiguous
    array               -> Random Access + Contiguous
    deque               -> Random Access
    list                -> Bidirectional
    forward_list        -> Forward
    set                 -> Bidirectional
    multiset             -> Bidirectional
    map                 -> Bidirectional
    multimap             -> Bidirectional
    unordered_set       -> Forward
    unordered_map       -> Forward


    =================================================================================
    OPERATIONS
    =================================================================================

    *itr                -> dereference/read
    *itr = value        -> write if iterator/reference is mutable
    &*itr               -> address of current element
    itr->member         -> member access

    ++itr               -> forward
    itr++               -> forward

    --itr               -> backward
    itr--               -> backward

    itr + n             -> random access
    itr - n             -> random access
    itr += n            -> random access
    itr -= n            -> random access
    itr[n]              -> random access
    itr1 - itr2         -> random access

    itr1 == itr2        -> equality
    itr1 != itr2        -> inequality

    itr1 < itr2         -> random access
    itr1 > itr2         -> random access
    itr1 <= itr2        -> random access
    itr1 >= itr2        -> random access


    =================================================================================
    HELPER FUNCTIONS
    =================================================================================

    advance(itr, n)
        moves the same iterator

    next(itr, n)
        returns a new iterator forward

    prev(itr, n)
        returns a new iterator backward

    distance(first, last)
        calculates distance between positions


    =================================================================================
    GOLDEN MEMORY TRICK
    =================================================================================

        INPUT
            READ + FORWARD

        OUTPUT
            WRITE

        FORWARD
            READ/WRITE + FORWARD + MULTI-PASS

        BIDIRECTIONAL
            FORWARD + BACKWARD

        RANDOM ACCESS
            BIDIRECTIONAL + DIRECT JUMP

        CONTIGUOUS
            RANDOM ACCESS + CONTIGUOUS MEMORY


    =================================================================================
    */
}

// ================================================================================
// MAIN
// ================================================================================

int main()
{
    inputIteratorTheory();

    outputIteratorTheory();

    forwardIteratorTheory();

    bidirectionalIteratorTheory();

    randomAccessIteratorTheory();

    contiguousIteratorTheory();

    rawPointerAsIterator();

    inputVsForward();

    forwardVsBidirectional();

    bidirectionalVsRandom();

    randomVsContiguous();

    completeOperationTable();

    containerMapping();

    readWriteSummary();

    movementSummary();

    algorithmRequirements();

    iteratorCategoryInspection();

    cplusplus20ConceptChecks();

    constIteratorAndCategory();

    reverseIteratorCategory();

    commonMistakes();

    finalMasterTable();

    return 0;
}

/*
================================================================================
                                  FINAL NOTE
================================================================================

The most important progression is:

    INPUT
       |
       | add multi-pass
       v
    FORWARD
       |
       | add backward
       v
    BIDIRECTIONAL
       |
       | add random jumping + arithmetic
       v
    RANDOM ACCESS
       |
       | add contiguous-memory guarantee
       v
    CONTIGUOUS


And remember:

    READ
        means you can obtain the value.

    WRITE
        means you can assign through a mutable iterator.

    FORWARD
        means ++ is supported.

    BACKWARD
        means -- is supported.

    RANDOM ACCESS
        means +n, -n, [n], difference and relational ordering.

    CONTIGUOUS
        means Random Access + adjacent memory representation.

================================================================================
END OF FILE
================================================================================
*/