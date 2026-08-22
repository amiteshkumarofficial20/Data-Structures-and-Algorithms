/*
===============================================================================
                         C++ STL ITERATOR OPERATIONS
                         DETAILED NOTES + CODE
===============================================================================

PURPOSE
-------
This file is specifically about OPERATIONS performed on STL iterators.

It is NOT a general STL containers file.

The main focus is:

    *itr
    &*itr
    itr->member

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

    itr1 == itr2
    itr1 != itr2

    itr1 < itr2
    itr1 > itr2
    itr1 <= itr2
    itr1 >= itr2

And also:

    advance()
    next()
    prev()
    distance()

IMPORTANT IDEA
--------------

An iterator represents a POSITION in a container/range.

    iterator
        |
        v
    [ 10 ][ 20 ][ 30 ]

If iterator points to 20:

    itr       = position of 20
    *itr      = 20
    &*itr     = address of 20

For object/pair:

    itr->member

is equivalent to:

    (*itr).member

===============================================================================
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

using namespace std;


// ============================================================================
// 1. *itr
// ============================================================================

void dereferenceOperation()
{
    cout << "\n========== *itr : DEREFERENCE ==========\n";

    vector<int> v = {10, 20, 30};

    auto itr = v.begin();

    /*
        itr points to the FIRST element.

            itr
             |
             v
            [10] [20] [30]

        *itr gives the VALUE at that position.
    */

    cout << "Value = " << *itr << "\n";

    /*
        Because this is a normal mutable iterator, we can also modify
        the element through *itr.
    */

    *itr = 100;

    cout << "After modification = "
         << *itr
         << "\n";
}


// ============================================================================
// 2. &*itr
// ============================================================================

void addressOperation()
{
    cout << "\n========== &*itr : ADDRESS ==========\n";

    vector<int> v = {10, 20, 30};

    auto itr = v.begin();

    /*
        First:

            *itr
                -> current element

        Then:

            &(*itr)
                -> address of current element

        Writing:

            &*itr

        is the same idea.
    */

    cout << "Value = "
         << *itr
         << "\n";

    cout << "Address = "
         << &*itr
         << "\n";

    /*
        IMPORTANT:

        &*itr is valid only when itr is dereferenceable.

        Therefore:

            &*v.end()

        is NOT valid because end() is not dereferenceable.
    */
}


// ============================================================================
// 3. itr->member
// ============================================================================

void arrowOperation()
{
    cout << "\n========== itr->member : ARROW ==========\n";

    map<int, string> mp = {
        {1, "One"},
        {2, "Two"},
        {3, "Three"}
    };

    auto itr = mp.begin();

    /*
        map iterator points to:

            pair<const int, string>

        Therefore:

            itr->first
                -> key

            itr->second
                -> value
    */

    cout << "Key = "
         << itr->first
         << "\n";

    cout << "Value = "
         << itr->second
         << "\n";

    /*
        itr->first

        is equivalent to:

        (*itr).first

        Similarly:

        itr->second

        is equivalent to:

        (*itr).second
    */

    cout << "Using (*itr).first = "
         << (*itr).first
         << "\n";
}


// ============================================================================
// 4. ++itr PREFIX INCREMENT
// ============================================================================

void prefixIncrementOperation()
{
    cout << "\n========== ++itr : PREFIX INCREMENT ==========\n";

    vector<int> v = {
        10, 20, 30
    };

    auto itr = v.begin();

    cout << "Before = "
         << *itr
         << "\n";

    /*
        ++itr moves the iterator to the next position.

        After:

            ++itr

        itr points to 20.
    */

    ++itr;

    cout << "After = "
         << *itr
         << "\n";

    /*
        PREFIX means:

            increment first
            then use the updated iterator
    */
}


// ============================================================================
// 5. itr++ POSTFIX INCREMENT
// ============================================================================

void postfixIncrementOperation()
{
    cout << "\n========== itr++ : POSTFIX INCREMENT ==========\n";

    vector<int> v = {
        10, 20, 30
    };

    auto itr = v.begin();

    /*
        itr++ returns the OLD iterator value and then increments itr.

        So:
    */

    auto old = itr++;

    cout << "Old iterator points to = "
         << *old
         << "\n";

    cout << "Current iterator points to = "
         << *itr
         << "\n";

    /*
        Result:

            old -> 10
            itr -> 20

        For normal loops, ++itr is commonly preferred because postfix
        needs to preserve the old iterator value for the expression.
    */
}


// ============================================================================
// 6. --itr PREFIX DECREMENT
// ============================================================================

void prefixDecrementOperation()
{
    cout << "\n========== --itr : PREFIX DECREMENT ==========\n";

    vector<int> v = {
        10, 20, 30
    };

    /*
        Start from end().

        end() is one position AFTER 30.

            10 20 30 [end]

        --itr moves it to 30.
    */

    auto itr = v.end();

    --itr;

    cout << *itr << "\n";

    /*
        --itr requires a Bidirectional Iterator or stronger.

        Therefore it works with:

            vector
            deque
            list
            set
            map

        But NOT with forward_list iterators.
    */
}


// ============================================================================
// 7. itr-- POSTFIX DECREMENT
// ============================================================================

void postfixDecrementOperation()
{
    cout << "\n========== itr-- : POSTFIX DECREMENT ==========\n";

    vector<int> v = {
        10, 20, 30
    };

    auto itr = v.end();

    --itr; // points to 30

    auto old = itr--;

    /*
        old -> 30
        itr -> 20
    */

    cout << "Old = "
         << *old
         << "\n";

    cout << "Current = "
         << *itr
         << "\n";
}


// ============================================================================
// 8. itr + n
// ============================================================================

void plusNOperation()
{
    cout << "\n========== itr + n ==========\n";

    vector<int> v = {
        10, 20, 30, 40, 50
    };

    auto itr = v.begin();

    /*
        itr + 3:

            move three positions forward.

        begin:
            10

        +1:
            20

        +2:
            30

        +3:
            40
    */

    auto result = itr + 3;

    cout << *result << "\n";

    /*
        IMPORTANT:

        itr + n requires a RANDOM ACCESS ITERATOR.

        Works with:
            vector
            array
            deque

        Does NOT work with:
            list
            forward_list
            set
            map
            unordered_set
            unordered_map
    */
}


// ============================================================================
// 9. itr - n
// ============================================================================

void minusNOperation()
{
    cout << "\n========== itr - n ==========\n";

    vector<int> v = {
        10, 20, 30, 40, 50
    };

    auto itr = v.end();

    /*
        end() is after 50.

        end() - 1 -> 50
        end() - 2 -> 40
    */

    auto result = itr - 2;

    cout << *result << "\n";
}


// ============================================================================
// 10. itr += n
// ============================================================================

void plusEqualOperation()
{
    cout << "\n========== itr += n ==========\n";

    vector<int> v = {
        10, 20, 30, 40, 50
    };

    auto itr = v.begin();

    /*
        itr += 3 modifies the SAME iterator.

        It moves from:

            10 -> 40
    */

    itr += 3;

    cout << *itr << "\n";
}


// ============================================================================
// 11. itr -= n
// ============================================================================

void minusEqualOperation()
{
    cout << "\n========== itr -= n ==========\n";

    vector<int> v = {
        10, 20, 30, 40, 50
    };

    auto itr = v.end();

    /*
        Move two positions backwards.
    */

    itr -= 2;

    cout << *itr << "\n"; // 40
}


// ============================================================================
// 12. itr[n]
// ============================================================================

void subscriptOperation()
{
    cout << "\n========== itr[n] ==========\n";

    vector<int> v = {
        10, 20, 30, 40, 50
    };

    auto itr = v.begin();

    /*
        itr[n] is equivalent to:

            *(itr + n)

        Therefore:

            itr[0] -> 10
            itr[1] -> 20
            itr[2] -> 30
            itr[3] -> 40
            itr[4] -> 50
    */

    cout << itr[0] << "\n";
    cout << itr[2] << "\n";
    cout << itr[4] << "\n";

    /*
        itr[n] requires Random Access Iterator.
    */
}


// ============================================================================
// 13. itr1 - itr2
// ============================================================================

void iteratorDifferenceOperation()
{
    cout << "\n========== itr1 - itr2 ==========\n";

    vector<int> v = {
        10, 20, 30, 40, 50
    };

    auto first = v.begin();

    auto last = v.end();

    /*
        Difference gives number of iterator steps between positions.

            end - begin = 5
    */

    cout << "Number of elements = "
         << last - first
         << "\n";

    auto a = v.begin() + 1;
    auto b = v.begin() + 4;

    cout << "b - a = "
         << b - a
         << "\n";
}


// ============================================================================
// 14. itr1 == itr2
// ============================================================================

void equalityOperation()
{
    cout << "\n========== itr1 == itr2 ==========\n";

    vector<int> v = {
        10, 20, 30
    };

    auto itr1 = v.begin();
    auto itr2 = v.begin();

    if (itr1 == itr2)
    {
        cout << "Both point to the same position.\n";
    }
}


// ============================================================================
// 15. itr1 != itr2
// ============================================================================

void inequalityOperation()
{
    cout << "\n========== itr1 != itr2 ==========\n";

    vector<int> v = {
        10, 20, 30
    };

    auto itr1 = v.begin();
    auto itr2 = v.end();

    if (itr1 != itr2)
    {
        cout << "They are different positions.\n";
    }

    /*
        This is why the standard iterator loop works:

            for (auto itr = begin;
                 itr != end;
                 ++itr)
    */
}


// ============================================================================
// 16. itr1 < itr2
// ============================================================================

void lessThanOperation()
{
    cout << "\n========== itr1 < itr2 ==========\n";

    vector<int> v = {
        10, 20, 30, 40
    };

    auto a = v.begin();
    auto b = v.begin() + 2;

    /*
        For Random Access Iterators:

            a < b

        means a occurs before b in the same random-access range.
    */

    if (a < b)
    {
        cout << "a comes before b.\n";
    }
}


// ============================================================================
// 17. itr1 > itr2
// ============================================================================

void greaterThanOperation()
{
    cout << "\n========== itr1 > itr2 ==========\n";

    vector<int> v = {
        10, 20, 30, 40
    };

    auto a = v.begin() + 3;
    auto b = v.begin() + 1;

    if (a > b)
    {
        cout << "a comes after b.\n";
    }
}


// ============================================================================
// 18. itr1 <= itr2
// ============================================================================

void lessEqualOperation()
{
    cout << "\n========== itr1 <= itr2 ==========\n";

    vector<int> v = {
        10, 20, 30
    };

    auto a = v.begin();
    auto b = v.begin() + 2;

    if (a <= b)
    {
        cout << "a is before or same as b.\n";
    }
}


// ============================================================================
// 19. itr1 >= itr2
// ============================================================================

void greaterEqualOperation()
{
    cout << "\n========== itr1 >= itr2 ==========\n";

    vector<int> v = {
        10, 20, 30
    };

    auto a = v.begin() + 2;
    auto b = v.begin();

    if (a >= b)
    {
        cout << "a is after or same as b.\n";
    }
}


// ============================================================================
// 20. advance()
// ============================================================================

void advanceOperation()
{
    cout << "\n========== advance() ==========\n";

    list<int> li = {
        10, 20, 30, 40, 50
    };

    auto itr = li.begin();

    /*
        list does NOT support:

            itr + 3

        because list has Bidirectional Iterator.

        advance() can move the iterator according to the capabilities
        of the iterator.

        For list, internally this means moving step-by-step.
    */

    advance(itr, 3);

    cout << *itr << "\n"; // 40
}


// ============================================================================
// 21. next()
// ============================================================================

void nextOperation()
{
    cout << "\n========== next() ==========\n";

    list<int> li = {
        10, 20, 30, 40
    };

    auto itr = li.begin();

    /*
        next() RETURNS A NEW ITERATOR.

        Original itr remains unchanged.
    */

    auto result = next(itr, 2);

    cout << "Original = "
         << *itr
         << "\n";

    cout << "Result = "
         << *result
         << "\n";
}


// ============================================================================
// 22. prev()
// ============================================================================

void prevOperation()
{
    cout << "\n========== prev() ==========\n";

    list<int> li = {
        10, 20, 30, 40
    };

    auto itr = li.end();

    /*
        prev() moves backward and returns a new iterator.

        end() -> after 40

        prev(end) -> 40
    */

    auto result = prev(itr);

    cout << *result << "\n";
}


// ============================================================================
// 23. distance()
// ============================================================================

void distanceOperation()
{
    cout << "\n========== distance() ==========\n";

    list<int> li = {
        10, 20, 30, 40, 50
    };

    auto itr = next(
        li.begin(),
        3
    );

    /*
        distance(first, last)

        gives number of increments needed to reach last from first.

        For Random Access:
            usually O(1)

        For Forward/Bidirectional:
            generally O(n)
    */

    cout << distance(
        li.begin(),
        itr
    ) << "\n";
}


// ============================================================================
// 24. OPERATION ON VECTOR
// ============================================================================

void vectorAllOperations()
{
    cout << "\n========== VECTOR: ALL OPERATIONS ==========\n";

    vector<int> v = {
        10, 20, 30, 40, 50
    };

    auto itr = v.begin();

    /*
        VECTOR ITERATOR:

            Random Access
            Contiguous

        Therefore:

            *itr       YES
            &*itr      YES
            ++itr      YES
            itr++      YES
            --itr      YES
            itr--      YES
            itr+n      YES
            itr-n      YES
            itr+=n     YES
            itr-=n     YES
            itr[n]     YES
            itr1-itr2  YES
            comparisons YES
            itr->      if value is object/pair with member
    */

    cout << *itr << "\n";
    cout << *(itr + 2) << "\n";
    cout << itr[3] << "\n";
}


// ============================================================================
// 25. OPERATION ON ARRAY
// ============================================================================

void arrayAllOperations()
{
    cout << "\n========== ARRAY: ALL OPERATIONS ==========\n";

    array<int, 5> arr = {
        10, 20, 30, 40, 50
    };

    auto itr = arr.begin();

    /*
        std::array iterator is:

            Random Access + Contiguous

        So random-access operations work.
    */

    cout << *(itr + 2) << "\n";
}


// ============================================================================
// 26. OPERATION ON DEQUE
// ============================================================================

void dequeAllOperations()
{
    cout << "\n========== DEQUE: ALL OPERATIONS ==========\n";

    deque<int> dq = {
        10, 20, 30, 40, 50
    };

    auto itr = dq.begin();

    /*
        deque iterator = Random Access.

        Therefore:

            itr + n
            itr - n
            itr[n]
            itr1 - itr2

        work.

        But deque is NOT contiguous like vector.
    */

    cout << *(itr + 3) << "\n";
}


// ============================================================================
// 27. OPERATION ON LIST
// ============================================================================

void listAllOperations()
{
    cout << "\n========== LIST: ALL OPERATIONS ==========\n";

    list<int> li = {
        10, 20, 30, 40
    };

    auto itr = li.begin();

    /*
        list iterator = Bidirectional.

        Valid:

            *itr
            ++itr
            itr++
            --itr
            itr--

        Invalid:

            itr + 2
            itr - 2
            itr[2]
            itr1 - itr2
            itr1 < itr2
    */

    ++itr;
    --itr;

    cout << *itr << "\n";
}


// ============================================================================
// 28. OPERATION ON FORWARD_LIST
// ============================================================================

void forwardListAllOperations()
{
    cout << "\n========== FORWARD_LIST: ALL OPERATIONS ==========\n";

    forward_list<int> fl = {
        10, 20, 30
    };

    auto itr = fl.begin();

    /*
        forward_list iterator = Forward Iterator.

        Valid:

            *itr
            ++itr
            itr++

        Invalid:

            --itr
            itr--
            itr+n
            itr-n
            itr[n]
            itr1-itr2
            relational ordering
    */

    ++itr;

    cout << *itr << "\n";
}


// ============================================================================
// 29. SET
// ============================================================================

void setAllOperations()
{
    cout << "\n========== SET: ALL OPERATIONS ==========\n";

    set<int> s = {
        10, 20, 30
    };

    auto itr = s.begin();

    /*
        set iterator = Bidirectional.

        ++ and -- work.

        Random access arithmetic does NOT work.

        Also:

            *itr = value;

        is not allowed because set elements are keys and must remain
        consistent with the container's ordering.
    */

    cout << *itr << "\n";

    ++itr;

    cout << *itr << "\n";
}


// ============================================================================
// 30. MAP
// ============================================================================

void mapAllOperations()
{
    cout << "\n========== MAP: ALL OPERATIONS ==========\n";

    map<int, string> mp = {
        {1, "One"},
        {2, "Two"},
        {3, "Three"}
    };

    auto itr = mp.begin();

    /*
        map iterator = Bidirectional.

        itr->first
            key

        itr->second
            value

        The key is const through the iterator.
    */

    cout << itr->first
         << " "
         << itr->second
         << "\n";

    ++itr;

    cout << itr->first
         << " "
         << itr->second
         << "\n";
}


// ============================================================================
// 31. UNORDERED SET
// ============================================================================

void unorderedSetAllOperations()
{
    cout << "\n========== UNORDERED_SET ==========\n";

    unordered_set<int> s = {
        10, 20, 30
    };

    auto itr = s.begin();

    /*
        unordered_set iterator is Forward.

        ++ works.

        -- and random-access arithmetic do not work.
    */

    cout << *itr << "\n";
}


// ============================================================================
// 32. UNORDERED MAP
// ============================================================================

void unorderedMapAllOperations()
{
    cout << "\n========== UNORDERED_MAP ==========\n";

    unordered_map<int, string> mp = {
        {1, "One"},
        {2, "Two"}
    };

    auto itr = mp.begin();

    /*
        unordered_map iterator is Forward.

        itr->first
        itr->second

        are supported.
    */

    cout << itr->first
         << " -> "
         << itr->second
         << "\n";
}


// ============================================================================
// 33. PREFIX VS POSTFIX
// ============================================================================

void prefixVsPostfix()
{
    cout << "\n========== PREFIX VS POSTFIX ==========\n";

    vector<int> v = {
        10, 20, 30
    };

    auto a = v.begin();

    /*
        PREFIX:

            ++a

        increments a and gives updated iterator.
    */

    ++a;

    cout << "After ++a = "
         << *a
         << "\n";

    /*
        POSTFIX:

            a++

        gives old iterator for the expression, then increments a.
    */

    auto old = a++;

    cout << "old from a++ = "
         << *old
         << "\n";

    cout << "a after a++ = "
         << *a
         << "\n";
}


// ============================================================================
// 34. CONST ITERATOR OPERATIONS
// ============================================================================

void constIteratorOperations()
{
    cout << "\n========== CONST ITERATOR ==========\n";

    vector<int> v = {
        10, 20, 30
    };

    vector<int>::const_iterator itr =
        v.cbegin();

    /*
        Read operations are allowed:

            *itr
            ++itr
            comparisons

        But modifying the element is not allowed:

            *itr = 100;   // ERROR
    */

    cout << *itr << "\n";

    ++itr;

    cout << *itr << "\n";
}


// ============================================================================
// 35. REVERSE ITERATOR OPERATIONS
// ============================================================================

void reverseIteratorOperations()
{
    cout << "\n========== REVERSE ITERATOR OPERATIONS ==========\n";

    vector<int> v = {
        10, 20, 30, 40
    };

    auto itr = v.rbegin();

    /*
        rbegin() points to 40.

        ++itr moves in REVERSE direction:

            40 -> 30 -> 20 -> 10

        So ++ on a reverse iterator means movement toward the beginning
        of the original container.
    */

    cout << *itr << "\n";

    ++itr;

    cout << *itr << "\n";
}


// ============================================================================
// 36. itr->member WITH CUSTOM OBJECT
// ============================================================================

struct Student
{
    string name;
    int marks;
};

void arrowWithObject()
{
    cout << "\n========== itr->member WITH OBJECT ==========\n";

    vector<Student> students = {
        {"Aman", 90},
        {"Riya", 95}
    };

    auto itr = students.begin();

    /*
        itr points to a Student object.

        Therefore:

            itr->name
            itr->marks

        work.

        They are equivalent to:

            (*itr).name
            (*itr).marks
    */

    cout << itr->name
         << " "
         << itr->marks
         << "\n";

    ++itr;

    cout << itr->name
         << " "
         << itr->marks
         << "\n";
}


// ============================================================================
// 37. COMMON WRONG OPERATIONS
// ============================================================================

void commonWrongOperations()
{
    cout << "\n========== COMMON WRONG OPERATIONS ==========\n";

    /*
        The following are intentionally NOT executed because they would
        produce compilation errors or undefined behavior.

        -----------------------------------------------------------------------
        WRONG #1: Dereferencing end()

            vector<int> v = {10, 20, 30};
            auto itr = v.end();
            cout << *itr;

        end() is not dereferenceable.

        -----------------------------------------------------------------------
        WRONG #2: itr + n on list

            list<int> li = {10, 20, 30};
            auto itr = li.begin();
            itr = itr + 2;

        list iterator is Bidirectional, not Random Access.

        Use:

            advance(itr, 2);

        -----------------------------------------------------------------------
        WRONG #3: -- on forward_list

            forward_list<int> fl = {10, 20};
            auto itr = fl.begin();
            --itr;

        forward_list iterator cannot move backward.

        -----------------------------------------------------------------------
        WRONG #4: itr[n] on set

            set<int> s = {10, 20, 30};
            auto itr = s.begin();
            cout << itr[2];

        set iterator is not Random Access.

        -----------------------------------------------------------------------
        WRONG #5: modify set key

            *itr = 100;

        Set elements are treated as keys and are not mutable this way.

        -----------------------------------------------------------------------
        WRONG #6: dereference after erase

            auto itr = v.begin();
            itr = v.erase(itr);
            cout << *itr;

        The last line is only valid if itr != v.end().
        Always check before dereferencing.

        -----------------------------------------------------------------------
    */

    cout << "Wrong operations are explained in comments.\n";
}


// ============================================================================
// 38. OPERATION COMPATIBILITY TABLE
// ============================================================================

void compatibilityTable()
{
    cout << "\n========== OPERATION COMPATIBILITY ==========\n";

    /*
    ===========================================================================
    OPERATION        FORWARD   BIDIRECTIONAL   RANDOM ACCESS
    ===========================================================================

    *itr               YES          YES             YES

    ++itr              YES          YES             YES

    itr++              YES          YES             YES

    --itr               NO          YES             YES

    itr--               NO          YES             YES

    itr+n                NO           NO             YES

    itr-n                NO           NO             YES

    itr+=n               NO           NO             YES

    itr-=n               NO           NO             YES

    itr[n]               NO           NO             YES

    itr1-itr2            NO           NO             YES

    itr1 < itr2          NO           NO             YES

    itr1 > itr2          NO           NO             YES

    itr1 <= itr2         NO           NO             YES

    itr1 >= itr2         NO           NO             YES

    itr1 == itr2         YES          YES             YES

    itr1 != itr2         YES          YES             YES

    ===========================================================================
    CONTAINER MAPPING
    ===========================================================================

    vector:
        Random Access + Contiguous

    array:
        Random Access + Contiguous

    deque:
        Random Access

    list:
        Bidirectional

    forward_list:
        Forward

    set:
        Bidirectional

    multiset:
        Bidirectional

    map:
        Bidirectional

    multimap:
        Bidirectional

    unordered_set:
        Forward

    unordered_map:
        Forward
    ===========================================================================
    */

    cout << "Complete compatibility table is in the comments above.\n";
}


// ============================================================================
// 39. ITERATOR OPERATIONS WITH ALGORITHMS
// ============================================================================

void operationsWithAlgorithms()
{
    cout << "\n========== ITERATOR + ALGORITHMS ==========\n";

    vector<int> v = {
        50, 20, 40, 10, 30
    };

    /*
        Many STL algorithms return iterators.

        find()
        min_element()
        max_element()
        lower_bound()
        upper_bound()
        remove()
        unique()
        partition()

        Example:
    */

    auto itr = min_element(
        v.begin(),
        v.end()
    );

    /*
        itr is a POSITION.

        Therefore:

            *itr

        gives the minimum VALUE.
    */

    cout << "Minimum = "
         << *itr
         << "\n";

    /*
        If we want its index in a vector:

            itr - v.begin()
    */

    cout << "Index = "
         << itr - v.begin()
         << "\n";
}


// ============================================================================
// 40. ERASE USING ITERATOR
// ============================================================================

void eraseOperation()
{
    cout << "\n========== erase(iterator) ==========\n";

    vector<int> v = {
        10, 20, 30, 40
    };

    auto itr = find(
        v.begin(),
        v.end(),
        30
    );

    if (itr != v.end())
    {
        /*
            erase(itr) removes the element at itr.

            IMPORTANT:
            The old iterator should not be used after erasing that element.

            erase() returns a valid iterator to the following element.
        */

        itr = v.erase(itr);
    }

    /*
        Check before dereference because itr could be end().
    */

    if (itr != v.end())
    {
        cout << "Next element = "
             << *itr
             << "\n";
    }
}


// ============================================================================
// 41. FINAL REVISION
// ============================================================================

void finalRevision()
{
    cout << "\n========== FINAL REVISION ==========\n";

    /*
    ---------------------------------------------------------------------------
    BASIC
    ---------------------------------------------------------------------------

    itr
        = position

    *itr
        = value

    &*itr
        = address of current value

    itr->member
        = member access through iterator


    ---------------------------------------------------------------------------
    MOVEMENT
    ---------------------------------------------------------------------------

    ++itr
        prefix forward

    itr++
        postfix forward

    --itr
        prefix backward

    itr--
        postfix backward


    ---------------------------------------------------------------------------
    RANDOM ACCESS
    ---------------------------------------------------------------------------

    itr + n
    itr - n
    itr += n
    itr -= n
    itr[n]
    itr1 - itr2

    These require Random Access Iterators.


    ---------------------------------------------------------------------------
    COMPARISON
    ---------------------------------------------------------------------------

    itr1 == itr2
    itr1 != itr2

    General equality comparison for compatible iterators.

    itr1 < itr2
    itr1 > itr2
    itr1 <= itr2
    itr1 >= itr2

    These ordering comparisons require Random Access Iterators.


    ---------------------------------------------------------------------------
    HELPER FUNCTIONS
    ---------------------------------------------------------------------------

    advance(itr, n)
        modifies itr

    next(itr, n)
        returns a new iterator

    prev(itr, n)
        returns a new iterator going backward

    distance(first, last)
        number of steps between iterators


    ---------------------------------------------------------------------------
    CONTAINER CATEGORY
    ---------------------------------------------------------------------------

    vector          Random Access
    array           Random Access
    deque           Random Access

    list            Bidirectional
    set             Bidirectional
    map             Bidirectional

    forward_list    Forward
    unordered_set   Forward
    unordered_map   Forward


    ---------------------------------------------------------------------------
    GOLDEN RULE
    ---------------------------------------------------------------------------

    If you remember only one thing:

        *itr       = VALUE
        itr        = POSITION

    And:

        itr->x

    is basically:

        (*itr).x

    ---------------------------------------------------------------------------
    */
}


// ============================================================================
// MAIN
// ============================================================================

int main()
{
    dereferenceOperation();

    addressOperation();

    arrowOperation();

    prefixIncrementOperation();

    postfixIncrementOperation();

    prefixDecrementOperation();

    postfixDecrementOperation();

    plusNOperation();

    minusNOperation();

    plusEqualOperation();

    minusEqualOperation();

    subscriptOperation();

    iteratorDifferenceOperation();

    equalityOperation();

    inequalityOperation();

    lessThanOperation();

    greaterThanOperation();

    lessEqualOperation();

    greaterEqualOperation();

    advanceOperation();

    nextOperation();

    prevOperation();

    distanceOperation();

    vectorAllOperations();

    arrayAllOperations();

    dequeAllOperations();

    listAllOperations();

    forwardListAllOperations();

    setAllOperations();

    mapAllOperations();

    unorderedSetAllOperations();

    unorderedMapAllOperations();

    prefixVsPostfix();

    constIteratorOperations();

    reverseIteratorOperations();

    arrowWithObject();

    commonWrongOperations();

    compatibilityTable();

    operationsWithAlgorithms();

    eraseOperation();

    finalRevision();

    return 0;
}

/*
===============================================================================
                                  END
===============================================================================
*/
