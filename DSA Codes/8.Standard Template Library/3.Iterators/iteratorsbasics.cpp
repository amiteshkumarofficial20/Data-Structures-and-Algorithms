/*
===============================================================================
                    ITERATORS BASICS - COMPLETE C++ FILE
===============================================================================

This file covers the IMPORTANT iterator basics needed for STL + DSA.

TOPICS COVERED
--------------

1. What is an iterator?
2. Why iterators are needed
3. begin()
4. end()
5. Dereferencing *
6. ++ iterator
7. -- iterator
8. Iterator traversal
9. auto with iterators
10. Iterator range [begin, end)
11. vector iterator
12. array iterator
13. deque iterator
14. list iterator
15. forward_list iterator
16. set iterator
17. map iterator
18. unordered_set iterator
19. unordered_map iterator
20. Iterator categories
21. Input Iterator
22. Output Iterator
23. Forward Iterator
24. Bidirectional Iterator
25. Random Access Iterator
26. Contiguous Iterator
27. Iterator category table
28. Iterator arithmetic
29. advance()
30. next()
31. prev()
32. distance()
33. const_iterator
34. cbegin()
35. cend()
36. reverse_iterator
37. rbegin()
38. rend()
39. reverse_iterator::base()
40. find() with iterator
41. find_if()
42. min_element()
43. max_element()
44. lower_bound()
45. upper_bound()
46. binary_search()
47. erase() with iterator
48. safe erase while iterating
49. back_inserter()
50. front_inserter()
51. inserter()
52. iterator invalidation basics
53. vector invalidation
54. list/set invalidation
55. iterator vs pointer
56. iterator vs value
57. range-based for loop
58. common mistakes
59. complete final revision

===============================================================================
IMPORTANT IDEA
===============================================================================

An iterator represents a POSITION in a container/range.

Example:

    vector<int> v = {10, 20, 30};

    auto it = v.begin();

Here:

    it
        = iterator / position

    *it
        = value at that position

So:

    cout << *it;

prints:

    10

MEMORY TRICK:

    iterator = position
    *iterator = value

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
#include <algorithm>
#include <numeric>
#include <iterator>
#include <string>

using namespace std;


// ============================================================================
// HELPER FUNCTION
// ============================================================================

template <typename Container>
void printContainer(
    const Container& container,
    const string& name
)
{
    cout << name << ": ";

    for (const auto& value : container)
    {
        cout << value << " ";
    }

    cout << "\n";
}


// ============================================================================
// 1. BASIC ITERATOR
// ============================================================================

void basicIterator()
{
    cout << "\n========== 1. BASIC ITERATOR ==========\n";

    vector<int> v = {
        10, 20, 30, 40
    };

    /*
        begin() returns an iterator pointing to the FIRST element.
    */

    vector<int>::iterator it = v.begin();

    /*
        *it dereferences the iterator.

        Since it points to 10:

            *it == 10
    */

    cout << "First element = "
         << *it
         << "\n";

    /*
        Move iterator to next element.
    */

    ++it;

    cout << "Second element = "
         << *it
         << "\n";

    ++it;

    cout << "Third element = "
         << *it
         << "\n";
}


// ============================================================================
// 2. begin() AND end()
// ============================================================================

void beginAndEnd()
{
    cout << "\n========== 2. begin() AND end() ==========\n";

    vector<int> v = {
        10, 20, 30
    };

    /*
        begin():
            points to first element.

        end():
            points ONE POSITION AFTER the last element.

        IMPORTANT:

            end() is NOT the last element.

        For:

            10 20 30

        conceptually:

            begin()             end()
               |                  |
               v                  v
            [10] [20] [30] [X]
    */

    cout << "First = "
         << *v.begin()
         << "\n";

    /*
        To get the last element using iterator:

            prev(v.end())

        This is safe only when the container is not empty.
    */

    cout << "Last = "
         << *prev(v.end())
         << "\n";

    /*
        NEVER do:

            *v.end();

        because end() is a past-the-end iterator.
    */
}


// ============================================================================
// 3. BASIC ITERATOR LOOP
// ============================================================================

void iteratorLoop()
{
    cout << "\n========== 3. ITERATOR LOOP ==========\n";

    vector<int> v = {
        10, 20, 30, 40, 50
    };

    /*
        Standard iterator loop:

            start at begin()
            continue until end()
            increment iterator
    */

    for (
        auto it = v.begin();
        it != v.end();
        ++it
    )
    {
        /*
            *it = current element
        */

        cout << *it << " ";
    }

    cout << "\n";
}


// ============================================================================
// 4. MODIFY USING ITERATOR
// ============================================================================

void modifyUsingIterator()
{
    cout << "\n========== 4. MODIFY USING ITERATOR ==========\n";

    vector<int> v = {
        10, 20, 30, 40
    };

    /*
        Normal vector iterator allows modification.
    */

    for (
        auto it = v.begin();
        it != v.end();
        ++it
    )
    {
        /*
            Multiply every value by 2.
        */

        *it = *it * 2;
    }

    printContainer(
        v,
        "After modification"
    );
}


// ============================================================================
// 5. auto WITH ITERATORS
// ============================================================================

void autoWithIterators()
{
    cout << "\n========== 5. auto WITH ITERATORS ==========\n";

    vector<int> v = {
        10, 20, 30
    };

    /*
        Instead of writing:

            vector<int>::iterator

        we can use:

            auto
    */

    auto it = v.begin();

    cout << *it << "\n";

    /*
        auto automatically determines the correct iterator type.
    */
}


// ============================================================================
// 6. ITERATOR RANGE [first, last)
// ============================================================================

void iteratorRange()
{
    cout << "\n========== 6. ITERATOR RANGE ==========\n";

    vector<int> v = {
        10, 20, 30, 40, 50
    };

    /*
        Most STL algorithms use:

            [first, last)

        Meaning:

            first -> INCLUDED
            last  -> EXCLUDED

        Therefore:

            v.begin()
            v.end()

        means all elements.

        Example:

            begin() -------------------- end()
               |                           |
               v                           v
              10 20 30 40 50
              included             end excluded
    */

    auto first = v.begin();

    /*
        next(first, 1) points to 20.

        Range:

            [first, next(first, 3))

        contains:

            10 20 30
    */

    auto last = next(
        v.begin(),
        3
    );

    for (
        auto it = first;
        it != last;
        ++it
    )
    {
        cout << *it << " ";
    }

    cout << "\n";
}


// ============================================================================
// 7. ITERATOR CATEGORIES
// ============================================================================

void iteratorCategories()
{
    cout << "\n========== 7. ITERATOR CATEGORIES ==========\n";

    /*
        Main iterator categories:

        1. Input Iterator
        2. Output Iterator
        3. Forward Iterator
        4. Bidirectional Iterator
        5. Random Access Iterator

        Modern C++ additionally has:

        6. Contiguous Iterator
    */

    cout << "Iterator categories are explained in comments.\n";
}


// ============================================================================
// 8. VECTOR ITERATOR
// ============================================================================

void vectorIterator()
{
    cout << "\n========== 8. VECTOR ITERATOR ==========\n";

    vector<int> v = {
        10, 20, 30, 40, 50
    };

    /*
        vector iterator:

            Random Access
            Contiguous

        Therefore vector iterator supports:

            ++it
            --it
            it + n
            it - n
            it += n
            it -= n
            it[n]
            it1 - it2
            comparisons such as <
    */

    auto it = v.begin();

    cout << "First = "
         << *it
         << "\n";

    /*
        Random access:

            it + 2

        means move directly two positions.
    */

    cout << "Third = "
         << *(it + 2)
         << "\n";

    /*
        Array-style iterator access:

            it[3]

        is supported for random-access iterators.
    */

    cout << "Fourth = "
         << it[3]
         << "\n";
}


// ============================================================================
// 9. ARRAY ITERATOR
// ============================================================================

void arrayIterator()
{
    cout << "\n========== 9. ARRAY ITERATOR ==========\n";

    array<int, 5> arr = {
        10, 20, 30, 40, 50
    };

    /*
        std::array iterators are:

            Random Access
            Contiguous
    */

    for (
        auto it = arr.begin();
        it != arr.end();
        ++it
    )
    {
        cout << *it << " ";
    }

    cout << "\n";

    cout << "Third element = "
         << *(arr.begin() + 2)
         << "\n";
}


// ============================================================================
// 10. DEQUE ITERATOR
// ============================================================================

void dequeIterator()
{
    cout << "\n========== 10. DEQUE ITERATOR ==========\n";

    deque<int> dq = {
        10, 20, 30, 40, 50
    };

    /*
        deque iterator is:

            Random Access

        But deque is NOT a contiguous container like vector.
    */

    auto it = dq.begin();

    cout << "Third = "
         << *(it + 2)
         << "\n";
}


// ============================================================================
// 11. LIST ITERATOR
// ============================================================================

void listIterator()
{
    cout << "\n========== 11. LIST ITERATOR ==========\n";

    list<int> li = {
        10, 20, 30, 40
    };

    /*
        list iterator:

            Bidirectional

        Therefore:

            ++it   YES
            --it   YES

        But:

            it + 2

        is NOT supported.
    */

    auto it = li.begin();

    ++it;
    ++it;

    cout << "Third element = "
         << *it
         << "\n";

    /*
        Move backwards.
    */

    --it;

    cout << "After --it = "
         << *it
         << "\n";
}


// ============================================================================
// 12. FORWARD_LIST ITERATOR
// ============================================================================

void forwardListIterator()
{
    cout << "\n========== 12. FORWARD_LIST ITERATOR ==========\n";

    forward_list<int> fl = {
        10, 20, 30, 40
    };

    /*
        forward_list iterator:

            Forward Iterator

        It supports:

            ++it

        It does NOT support:

            --it
            it + n
    */

    auto it = fl.begin();

    cout << *it << "\n";

    ++it;

    cout << *it << "\n";
}


// ============================================================================
// 13. SET ITERATOR
// ============================================================================

void setIterator()
{
    cout << "\n========== 13. SET ITERATOR ==========\n";

    set<int> s = {
        30, 10, 40, 20
    };

    /*
        std::set automatically sorts:

            10 20 30 40

        Its iterator is:

            Bidirectional

        So:

            ++it
            --it

        are supported.

        But:

            it + 2

        is NOT supported.
    */

    for (
        auto it = s.begin();
        it != s.end();
        ++it
    )
    {
        cout << *it << " ";
    }

    cout << "\n";

    /*
        Set elements cannot normally be modified through iterator.

        This would be invalid:

            *it = 100;

        because modifying a key could break the set's ordering.
    */
}


// ============================================================================
// 14. MAP ITERATOR
// ============================================================================

void mapIterator()
{
    cout << "\n========== 14. MAP ITERATOR ==========\n";

    map<int, string> mp = {
        {1, "One"},
        {2, "Two"},
        {3, "Three"}
    };

    /*
        map iterator is Bidirectional.

        map iterator points to:

            pair<const Key, Value>

        Therefore:

            it->first
                = key

            it->second
                = value
    */

    for (
        auto it = mp.begin();
        it != mp.end();
        ++it
    )
    {
        cout << it->first
             << " -> "
             << it->second
             << "\n";
    }
}


// ============================================================================
// 15. UNORDERED_SET ITERATOR
// ============================================================================

void unorderedSetIterator()
{
    cout << "\n========== 15. UNORDERED_SET ITERATOR ==========\n";

    unordered_set<int> s = {
        10, 20, 30, 40
    };

    /*
        unordered_set is not sorted.

        Its iterator provides forward traversal.

        Do not expect a predictable sorted order.
    */

    for (
        auto it = s.begin();
        it != s.end();
        ++it
    )
    {
        cout << *it << " ";
    }

    cout << "\n";
}


// ============================================================================
// 16. UNORDERED_MAP ITERATOR
// ============================================================================

void unorderedMapIterator()
{
    cout << "\n========== 16. UNORDERED_MAP ITERATOR ==========\n";

    unordered_map<int, string> mp = {
        {1, "One"},
        {2, "Two"},
        {3, "Three"}
    };

    /*
        unordered_map iterator provides forward traversal.

        Order is NOT sorted.
    */

    for (
        auto it = mp.begin();
        it != mp.end();
        ++it
    )
    {
        cout << it->first
             << " -> "
             << it->second
             << "\n";
    }
}


// ============================================================================
// 17. --it
// ============================================================================

void decrementIterator()
{
    cout << "\n========== 17. --it ==========\n";

    vector<int> v = {
        10, 20, 30, 40
    };

    /*
        v.end() is one past 40.

        Move backwards once:

            --it

        Now it points to 40.
    */

    auto it = v.end();

    --it;

    cout << *it << "\n";
}


// ============================================================================
// 18. advance()
// ============================================================================

void advanceExample()
{
    cout << "\n========== 18. advance() ==========\n";

    list<int> li = {
        10, 20, 30, 40, 50
    };

    auto it = li.begin();

    /*
        list does not support:

            it + 3

        But advance() works with the iterator category.
    */

    advance(
        it,
        3
    );

    cout << "After advance by 3 = "
         << *it
         << "\n";
}


// ============================================================================
// 19. next()
// ============================================================================

void nextExample()
{
    cout << "\n========== 19. next() ==========\n";

    vector<int> v = {
        10, 20, 30, 40, 50
    };

    auto first = v.begin();

    /*
        next() returns a NEW iterator.

        Original 'first' does not change.
    */

    auto third = next(
        first,
        2
    );

    cout << "Original first = "
         << *first
         << "\n";

    cout << "Third = "
         << *third
         << "\n";
}


// ============================================================================
// 20. prev()
// ============================================================================

void prevExample()
{
    cout << "\n========== 20. prev() ==========\n";

    vector<int> v = {
        10, 20, 30, 40, 50
    };

    /*
        end() is after 50.

        prev(end, 1) -> 50
        prev(end, 2) -> 40
    */

    auto it = prev(
        v.end(),
        2
    );

    cout << *it << "\n";
}


// ============================================================================
// 21. distance()
// ============================================================================

void distanceExample()
{
    cout << "\n========== 21. distance() ==========\n";

    vector<int> v = {
        10, 20, 30, 40, 50
    };

    auto it = next(
        v.begin(),
        3
    );

    auto d = distance(
        v.begin(),
        it
    );

    cout << "Distance = "
         << d
         << "\n";
}


// ============================================================================
// 22. CONST ITERATOR
// ============================================================================

void constIteratorExample()
{
    cout << "\n========== 22. CONST ITERATOR ==========\n";

    vector<int> v = {
        10, 20, 30
    };

    /*
        const_iterator allows reading but not modifying through iterator.
    */

    vector<int>::const_iterator it =
        v.cbegin();

    cout << *it << "\n";

    /*
        This would be ERROR:

            *it = 100;

        because it is a const_iterator.
    */
}


// ============================================================================
// 23. cbegin() / cend()
// ============================================================================

void cbeginCendExample()
{
    cout << "\n========== 23. cbegin() / cend() ==========\n";

    vector<int> v = {
        10, 20, 30
    };

    for (
        auto it = v.cbegin();
        it != v.cend();
        ++it
    )
    {
        cout << *it << " ";
    }

    cout << "\n";
}


// ============================================================================
// 24. REVERSE ITERATOR
// ============================================================================

void reverseIteratorExample()
{
    cout << "\n========== 24. REVERSE ITERATOR ==========\n";

    vector<int> v = {
        10, 20, 30, 40
    };

    /*
        rbegin() points to the last element.

            40

        ++ reverse iterator moves towards:

            30
            20
            10
    */

    for (
        auto it = v.rbegin();
        it != v.rend();
        ++it
    )
    {
        cout << *it << " ";
    }

    cout << "\n";
}


// ============================================================================
// 25. reverse_iterator::base()
// ============================================================================

void reverseBaseExample()
{
    cout << "\n========== 25. reverse_iterator::base() ==========\n";

    vector<int> v = {
        10, 20, 30, 40
    };

    auto rit = v.rbegin();

    /*
        rit points to 40.

        But:

            rit.base()

        points to v.end().

        General rule:

            reverse iterator represents the element BEFORE base().
    */

    cout << "Reverse value = "
         << *rit
         << "\n";

    cout << "Same element using base = "
         << *prev(rit.base())
         << "\n";
}


// ============================================================================
// 26. find()
// ============================================================================

void findExample()
{
    cout << "\n========== 26. find() ==========\n";

    vector<int> v = {
        10, 20, 30, 40
    };

    /*
        find() returns an iterator.

        If found:
            iterator points to element.

        If not found:
            iterator == end()
    */

    auto it = find(
        v.begin(),
        v.end(),
        30
    );

    if (it != v.end())
    {
        cout << "Found = "
             << *it
             << "\n";
    }
    else
    {
        cout << "Not found\n";
    }
}


// ============================================================================
// 27. find_if()
// ============================================================================

void findIfExample()
{
    cout << "\n========== 27. find_if() ==========\n";

    vector<int> v = {
        11, 13, 16, 19, 22
    };

    /*
        find_if() returns the first element satisfying the condition.
    */

    auto it = find_if(
        v.begin(),
        v.end(),
        [](int x)
        {
            return x % 2 == 0;
        }
    );

    if (it != v.end())
    {
        cout << "First even = "
             << *it
             << "\n";
    }
}


// ============================================================================
// 28. min_element()
// ============================================================================

void minElementExample()
{
    cout << "\n========== 28. min_element() ==========\n";

    vector<int> v = {
        50, 20, 40, 10, 30
    };

    /*
        min_element() returns an iterator.

        Therefore dereference it:

            *it
    */

    auto it = min_element(
        v.begin(),
        v.end()
    );

    cout << "Minimum = "
         << *it
         << "\n";
}


// ============================================================================
// 29. max_element()
// ============================================================================

void maxElementExample()
{
    cout << "\n========== 29. max_element() ==========\n";

    vector<int> v = {
        50, 20, 40, 10, 30
    };

    auto it = max_element(
        v.begin(),
        v.end()
    );

    cout << "Maximum = "
         << *it
         << "\n";
}


// ============================================================================
// 30. lower_bound()
// ============================================================================

void lowerBoundExample()
{
    cout << "\n========== 30. lower_bound() ==========\n";

    vector<int> v = {
        10, 20, 30, 40, 50
    };

    /*
        lower_bound(x):

            first element >= x

        lower_bound(25):

            30
    */

    auto it = lower_bound(
        v.begin(),
        v.end(),
        25
    );

    if (it != v.end())
    {
        cout << "lower_bound(25) = "
             << *it
             << "\n";
    }
}


// ============================================================================
// 31. upper_bound()
// ============================================================================

void upperBoundExample()
{
    cout << "\n========== 31. upper_bound() ==========\n";

    vector<int> v = {
        10, 20, 30, 40, 50
    };

    /*
        upper_bound(x):

            first element > x
    */

    auto it = upper_bound(
        v.begin(),
        v.end(),
        30
    );

    if (it != v.end())
    {
        cout << "upper_bound(30) = "
             << *it
             << "\n";
    }
}


// ============================================================================
// 32. binary_search()
// ============================================================================

void binarySearchExample()
{
    cout << "\n========== 32. binary_search() ==========\n";

    vector<int> v = {
        10, 20, 30, 40, 50
    };

    /*
        binary_search() returns bool.

        It does NOT return an iterator.
    */

    bool found = binary_search(
        v.begin(),
        v.end(),
        30
    );

    cout << boolalpha;

    cout << "30 present? "
         << found
         << "\n";
}


// ============================================================================
// 33. ITERATOR + INDEX
// ============================================================================

void iteratorIndex()
{
    cout << "\n========== 33. ITERATOR INDEX ==========\n";

    vector<int> v = {
        10, 20, 30, 40
    };

    auto it = find(
        v.begin(),
        v.end(),
        30
    );

    if (it != v.end())
    {
        /*
            vector is Random Access.

            Therefore:

                it - v.begin()

            gives index.
        */

        auto index =
            it - v.begin();

        cout << "Index = "
             << index
             << "\n";
    }
}


// ============================================================================
// 34. distance() FOR NON-RANDOM ACCESS
// ============================================================================

void distanceForList()
{
    cout << "\n========== 34. distance() FOR LIST ==========\n";

    list<int> li = {
        10, 20, 30, 40
    };

    auto it = find(
        li.begin(),
        li.end(),
        30
    );

    if (it != li.end())
    {
        /*
            list iterator does NOT support:

                it - li.begin()

            Use distance().
        */

        auto position =
            distance(
                li.begin(),
                it
            );

        cout << "Position = "
             << position
             << "\n";
    }
}


// ============================================================================
// 35. ERASE USING ITERATOR
// ============================================================================

void eraseUsingIterator()
{
    cout << "\n========== 35. ERASE USING ITERATOR ==========\n";

    vector<int> v = {
        10, 20, 30, 40
    };

    auto it = find(
        v.begin(),
        v.end(),
        30
    );

    if (it != v.end())
    {
        /*
            erase(it) removes the element at iterator position.

            Modern erase overload returns an iterator to the element
            following the erased element.
        */

        it = v.erase(it);
    }

    printContainer(
        v,
        "After erase"
    );
}


// ============================================================================
// 36. SAFE ERASE WHILE ITERATING
// ============================================================================

void safeEraseWhileIterating()
{
    cout << "\n========== 36. SAFE ERASE WHILE ITERATING ==========\n";

    vector<int> v = {
        10, 11, 12, 13, 14, 15
    };

    /*
        Remove all even values.

        IMPORTANT:

        After erase(), the old iterator can no longer be used
        as if it still referred to the erased element.

        erase() gives us the next valid iterator.

            it = v.erase(it);
    */

    for (
        auto it = v.begin();
        it != v.end();
    )
    {
        if (*it % 2 == 0)
        {
            it = v.erase(it);
        }
        else
        {
            ++it;
        }
    }

    printContainer(
        v,
        "After removing even values"
    );
}


// ============================================================================
// 37. back_inserter()
// ============================================================================

void backInserterExample()
{
    cout << "\n========== 37. back_inserter() ==========\n";

    vector<int> source = {
        10, 20, 30
    };

    vector<int> result;

    /*
        back_inserter(result) creates an output iterator.

        Assigning through it effectively calls:

            result.push_back(value)
    */

    copy(
        source.begin(),
        source.end(),
        back_inserter(result)
    );

    printContainer(
        result,
        "Copied"
    );
}


// ============================================================================
// 38. front_inserter()
// ============================================================================

void frontInserterExample()
{
    cout << "\n========== 38. front_inserter() ==========\n";

    deque<int> result;

    /*
        front_inserter uses push_front().

        Therefore insertion order appears reversed.
    */

    auto it = front_inserter(result);

    *it = 10;
    *it = 20;
    *it = 30;

    printContainer(
        result,
        "Result"
    );
}


// ============================================================================
// 39. inserter()
// ============================================================================

void inserterExample()
{
    cout << "\n========== 39. inserter() ==========\n";

    set<int> result;

    /*
        set does not have push_back().

        Therefore back_inserter() is not appropriate.

        inserter() uses insert().
    */

    auto it = inserter(
        result,
        result.begin()
    );

    *it = 30;
    *it = 10;
    *it = 20;

    printContainer(
        result,
        "Set result"
    );
}


// ============================================================================
// 40. OUTPUT STREAM ITERATOR
// ============================================================================

void ostreamIteratorExample()
{
    cout << "\n========== 40. ostream_iterator ==========\n";

    vector<int> v = {
        10, 20, 30
    };

    /*
        ostream_iterator writes values to cout.
    */

    copy(
        v.begin(),
        v.end(),
        ostream_iterator<int>(
            cout,
            " "
        )
    );

    cout << "\n";
}


// ============================================================================
// 41. INPUT STREAM ITERATOR
// ============================================================================

void istreamIteratorExplanation()
{
    cout << "\n========== 41. istream_iterator ==========\n";

    /*
        istream_iterator can treat an input stream as an iterator range.

        Example concept:

            istream_iterator<int> first(cin);
            istream_iterator<int> last;

            vector<int> v(first, last);

        This reads integers until EOF.

        We are not actually waiting for input in this demo, so the
        concept is shown in comments only.
    */

    cout << "istream_iterator treats input as an iterator range.\n";
}


// ============================================================================
// 42. ITERATOR INVALIDATION BASICS
// ============================================================================

void iteratorInvalidationBasics()
{
    cout << "\n========== 42. ITERATOR INVALIDATION ==========\n";

    /*
        Iterator invalidation means:

            An iterator that used to be valid may become invalid
            after modifying the container.

        IMPORTANT CONTAINERS:

        vector:
            insertion that causes reallocation invalidates old iterators.

        set:
            inserting elements does not invalidate iterators to existing
            elements; erasing an element invalidates its iterator.

        list:
            insertion/erasure generally preserves iterators to unaffected
            elements.

        unordered containers:
            rehash can invalidate iterators.

        deque:
            has special invalidation rules; do not assume all iterators
            survive every modification.
    */

    cout << "Iterator invalidation depends on container + operation.\n";
}


// ============================================================================
// 43. VECTOR INVALIDATION EXAMPLE
// ============================================================================

void vectorInvalidationExample()
{
    cout << "\n========== 43. VECTOR INVALIDATION ==========\n";

    vector<int> v;

    /*
        reserve() gives the vector capacity in advance.

        This can prevent reallocation until capacity is exceeded.
    */

    v.reserve(100);

    v.push_back(10);
    v.push_back(20);

    auto it = v.begin();

    /*
        Since there is enough reserved capacity, this push_back does not
        require reallocation here.

        However, never generalize this to every vector operation.
    */

    v.push_back(30);

    cout << "Iterator value = "
         << *it
         << "\n";
}


// ============================================================================
// 44. SET ITERATOR VALIDITY
// ============================================================================

void setIteratorValidity()
{
    cout << "\n========== 44. SET ITERATOR VALIDITY ==========\n";

    set<int> s = {
        10, 20, 30
    };

    auto it = s.find(20);

    /*
        Inserting another element does not invalidate the iterator to 20.
    */

    s.insert(40);

    cout << "Still valid = "
         << *it
         << "\n";

    /*
        Now erase the element itself.

            s.erase(it);

        After this, 'it' is invalid and must not be dereferenced.
    */

    s.erase(it);

    printContainer(
        s,
        "After erase"
    );
}


// ============================================================================
// 45. RANGE-BASED FOR LOOP
// ============================================================================

void rangeBasedFor()
{
    cout << "\n========== 45. RANGE-BASED FOR ==========\n";

    vector<int> v = {
        10, 20, 30
    };

    /*
        Modern C++ often uses range-based for loops.

        For simple traversal, this is usually cleaner than explicit
        iterator code.
    */

    for (const auto& value : v)
    {
        cout << value << " ";
    }

    cout << "\n";

    /*
        Conceptually, range-based traversal is based on begin/end-style
        iteration.

        Explicit iterators are still required when you need the POSITION.
    */
}


// ============================================================================
// 46. ITERATOR VS POINTER
// ============================================================================

void iteratorVsPointer()
{
    cout << "\n========== 46. ITERATOR VS POINTER ==========\n";

    int arr[] = {
        10, 20, 30
    };

    /*
        Raw pointer:
    */

    int* p = arr;

    cout << "Pointer value = "
         << *p
         << "\n";

    vector<int> v = {
        10, 20, 30
    };

    /*
        Iterator:

            auto it = v.begin();

        It behaves similarly to a pointer for many operations,
        but it is an abstraction supplied by the container.
    */

    auto it = v.begin();

    cout << "Iterator value = "
         << *it
         << "\n";
}


// ============================================================================
// 47. ALGORITHM RETURN TYPES
// ============================================================================

void algorithmReturnTypes()
{
    cout << "\n========== 47. ALGORITHM RETURN TYPES ==========\n";

    vector<int> v = {
        50, 20, 40, 10, 30
    };

    /*
        Algorithms returning ITERATORS:

            find()
            find_if()
            min_element()
            max_element()
            lower_bound()
            upper_bound()
            equal_range()
            remove()
            remove_if()
            unique()
            partition()

        Algorithms returning other things:

            binary_search() -> bool
            count()         -> count
            count_if()      -> count
            is_sorted()     -> bool
    */

    auto minIt = min_element(
        v.begin(),
        v.end()
    );

    cout << "Minimum = "
         << *minIt
         << "\n";

    bool exists = binary_search(
        v.begin(),
        v.end(),
        30
    );

    cout << boolalpha;

    cout << "30 exists? "
         << exists
         << "\n";
}


// ============================================================================
// 48. remove() AND LOGICAL END
// ============================================================================

void removeAlgorithmExample()
{
    cout << "\n========== 48. remove() ==========\n";

    vector<int> v = {
        10, 20, 10, 30, 10
    };

    /*
        IMPORTANT:

        std::remove() does NOT reduce vector size.

        It rearranges the range and returns a new logical end.

        Therefore:
    */

    auto newEnd = remove(
        v.begin(),
        v.end(),
        10
    );

    /*
        To actually reduce vector size:

            erase(newEnd, v.end())
    */

    v.erase(
        newEnd,
        v.end()
    );

    printContainer(
        v,
        "After erase-remove"
    );
}


// ============================================================================
// 49. unique() AND ITERATOR
// ============================================================================

void uniqueExample()
{
    cout << "\n========== 49. unique() ==========\n";

    vector<int> v = {
        1, 1, 2, 2, 3, 3
    };

    /*
        unique() moves duplicate-removal result toward the beginning
        and returns a logical new end.

        It does not resize the vector by itself.
    */

    auto newEnd = unique(
        v.begin(),
        v.end()
    );

    v.erase(
        newEnd,
        v.end()
    );

    printContainer(
        v,
        "After unique + erase"
    );
}


// ============================================================================
// 50. ITERATOR CATEGORY CHEAT SHEET
// ============================================================================

void iteratorCategoryCheatSheet()
{
    cout << "\n========== 50. ITERATOR CATEGORY CHEAT SHEET ==========\n";

    /*
        INPUT:
            read
            move forward

        OUTPUT:
            write

        FORWARD:
            forward movement
            multiple passes

        BIDIRECTIONAL:
            forward + backward

        RANDOM ACCESS:
            bidirectional +
            arithmetic/indexing

        CONTIGUOUS:
            random access +
            contiguous memory guarantee


        CONTAINER SUMMARY:

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

        map:
            Bidirectional

        unordered_set:
            Forward

        unordered_map:
            Forward
    */

    cout << "See source comments for complete category details.\n";
}


// ============================================================================
// MAIN
// ============================================================================

int main()
{
    basicIterator();

    beginAndEnd();

    iteratorLoop();

    modifyUsingIterator();

    autoWithIterators();

    iteratorRange();

    iteratorCategories();

    vectorIterator();

    arrayIterator();

    dequeIterator();

    listIterator();

    forwardListIterator();

    setIterator();

    mapIterator();

    unorderedSetIterator();

    unorderedMapIterator();

    decrementIterator();

    advanceExample();

    nextExample();

    prevExample();

    distanceExample();

    constIteratorExample();

    cbeginCendExample();

    reverseIteratorExample();

    reverseBaseExample();

    findExample();

    findIfExample();

    minElementExample();

    maxElementExample();

    lowerBoundExample();

    upperBoundExample();

    binarySearchExample();

    iteratorIndex();

    distanceForList();

    eraseUsingIterator();

    safeEraseWhileIterating();

    backInserterExample();

    frontInserterExample();

    inserterExample();

    ostreamIteratorExample();

    istreamIteratorExplanation();

    iteratorInvalidationBasics();

    vectorInvalidationExample();

    setIteratorValidity();

    rangeBasedFor();

    iteratorVsPointer();

    algorithmReturnTypes();

    removeAlgorithmExample();

    uniqueExample();

    iteratorCategoryCheatSheet();

    return 0;
}


/*
===============================================================================
                         FINAL QUICK REVISION
===============================================================================

ITERATOR:
    position in a container/range

*it:
    current value

begin():
    first element

end():
    one past last

++it:
    next

--it:
    previous, if supported

advance(it, n):
    modifies it

next(it, n):
    returns new iterator

prev(it, n):
    returns new iterator backward

distance(a, b):
    distance between iterators


VECTOR:
    Random Access + Contiguous

ARRAY:
    Random Access + Contiguous

DEQUE:
    Random Access

LIST:
    Bidirectional

FORWARD_LIST:
    Forward

SET:
    Bidirectional

MAP:
    Bidirectional

UNORDERED_SET:
    Forward

UNORDERED_MAP:
    Forward


IMPORTANT:

sort()
    requires Random Access iterators.

find()
    works with much weaker iterator requirements.

For set/map:
    prefer member find/lower_bound/upper_bound when you want
    the ordered-container complexity.

Do not:
    dereference end()

Do not:
    use invalidated iterators.

For vector:
    be especially careful after operations that may reallocate.

For set/list:
    iterators to unaffected elements generally remain valid
    across insertion/erasure of other elements.

For output:
    vector/deque/list -> back_inserter
    deque/list/forward_list -> front_inserter where supported
    set/map -> inserter

===============================================================================
END
===============================================================================
*/
