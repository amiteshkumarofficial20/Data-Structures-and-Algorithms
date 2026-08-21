#include <iostream>
#include <deque>

using namespace std;

int main()
{
    // ============================================================
    // ITERATORS ON DEQUE
    // ============================================================
    //
    // deque supports ITERATORS.
    //
    // Unlike queue and stack, deque provides:
    //
    // begin()
    // end()
    // rbegin()
    // rend()
    //
    // Deque iterators are RANDOM-ACCESS ITERATORS.
    //
    // This means we can do:
    //
    // ++it
    // --it
    // it + n
    // it - n
    // it += n
    // it -= n
    // it[n]
    //
    // This is similar to vector iterators.

    // ============================================================
    // CREATING A DEQUE
    // ============================================================

    // Creating a deque with initial values.

    deque<int> dq = {10, 20, 30, 40, 50};

    // Current deque:
    //
    // Index:
    //
    //   0    1    2    3    4
    // [10] [20] [30] [40] [50]
    //
    // The first element is 10.
    // The last element is 50.

    // ============================================================
    // CREATING AN ITERATOR
    // ============================================================

    // Syntax:
    //
    // deque<int>::iterator it;
    //
    // Here:
    //
    // deque<int>
    // -> deque stores int values.
    //
    // ::
    // -> Scope Resolution Operator.
    //
    // iterator
    // -> iterator type provided by deque.
    //
    // it
    // -> iterator variable.

    deque<int>::iterator it;

    // ============================================================
    // begin()
    // ============================================================

    // dq.begin() returns an iterator pointing to
    // the FIRST element.
    //
    // Current deque:
    //
    // [10] [20] [30] [40] [50]
    //  ^
    //  |
    // begin()
    //
    // So:
    //
    // it = dq.begin();
    //
    // means iterator 'it' points to 10.

    it = dq.begin();

    // ============================================================
    // DEREFERENCE OPERATOR *
    // ============================================================

    // An iterator points to an element.
    //
    // To get the actual value at the position,
    // we use the dereference operator:
    //
    // *
    //
    // So:
    //
    // *it
    //
    // gives the value stored where 'it' is pointing.
    //
    // Currently:
    //
    // it -> 10
    //
    // Therefore:
    //
    // *it = 10

    cout << "First element: "
         << *it
         << endl;

    // ============================================================
    // ++it
    // ============================================================

    // ++it moves the iterator ONE position forward.
    //
    // Before:
    //
    // [10] [20] [30] [40] [50]
    //  ^
    //  |
    //  it
    //
    // After ++it:
    //
    // [10] [20] [30] [40] [50]
    //       ^
    //       |
    //       it
    //
    // Now *it = 20.

    ++it;

    cout << "After ++it: "
         << *it
         << endl;

    // ============================================================
    // --it
    // ============================================================

    // --it moves the iterator ONE position backward.
    //
    // Current:
    //
    // [10] [20] [30] [40] [50]
    //       ^
    //       |
    //       it
    //
    // After --it:
    //
    // [10] [20] [30] [40] [50]
    //  ^
    //  |
    //  it
    //
    // Now *it = 10.

    --it;

    cout << "After --it: "
         << *it
         << endl;

    // ============================================================
    // it + n
    // ============================================================

    // Because deque iterator is a random-access iterator,
    // we can directly jump multiple positions.
    //
    // Example:
    //
    // it = dq.begin();
    //
    // it + 2
    //
    // means move 2 positions forward.
    //
    // begin() -> 10
    // +1      -> 20
    // +2      -> 30

    it = dq.begin();

    it = it + 2;

    cout << "After it + 2: "
         << *it
         << endl;

    // Output:
    //
    // 30

    // ============================================================
    // it - n
    // ============================================================

    // We can also move backward by multiple positions.

    // Current:
    //
    // it -> 30

    it = it - 1;

    // Now:
    //
    // it -> 20

    cout << "After it - 1: "
         << *it
         << endl;

    // ============================================================
    // it += n
    // ============================================================

    // += moves the iterator forward by n positions.

    // Current:
    //
    // it -> 20

    it += 2;

    // Now:
    //
    // it -> 40

    cout << "After it += 2: "
         << *it
         << endl;

    // ============================================================
    // it -= n
    // ============================================================

    // -= moves the iterator backward by n positions.

    // Current:
    //
    // it -> 40

    it -= 2;

    // Now:
    //
    // it -> 20

    cout << "After it -= 2: "
         << *it
         << endl;

    // ============================================================
    // begin() + n
    // ============================================================

    // Since deque has random-access iterators,
    // we don't need to first create an iterator
    // and then move it separately.
    //
    // We can directly write:
    //
    // dq.begin() + n

    it = dq.begin() + 3;

    // begin() -> 10
    // +1 -> 20
    // +2 -> 30
    // +3 -> 40
    //
    // So *it = 40.

    cout << "dq.begin() + 3: "
         << *it
         << endl;

    // ============================================================
    // it[n]
    // ============================================================

    // Random-access iterators also support [].
    //
    // If it points to 40:
    //
    // it[0] -> 40
    // it[1] -> 50
    //
    // Example:

    cout << "it[0]: "
         << it[0]
         << endl;

    cout << "it[1]: "
         << it[1]
         << endl;

    // ============================================================
    // end()
    // ============================================================

    // dq.end() does NOT point to the last element.
    //
    // It points to the position JUST AFTER the last element.
    //
    // Conceptually:
    //
    // [10] [20] [30] [40] [50] [END]
    //                              ^
    //                              |
    //                             end()
    //
    // Therefore:
    //
    // *dq.end()
    //
    // is INVALID.
    //
    // Do NOT dereference end() directly.

    // ============================================================
    // FORWARD TRAVERSAL
    // ============================================================

    // The most common iterator traversal:
    //
    // Start from begin()
    // Continue until end()
    // Move using ++it

    cout << "\nForward traversal: ";

    it = dq.begin();

    while (it != dq.end())
    {
        // Print current element.

        cout << *it << " ";

        // Move to next element.

        ++it;
    }

    cout << endl;

    // Output:
    //
    // 10 20 30 40 50

    // ============================================================
    // FOR LOOP WITH ITERATOR
    // ============================================================

    // Same thing can be written using a for loop.

    cout << "Forward traversal using for loop: ";

    for (auto it2 = dq.begin(); it2 != dq.end(); ++it2)
    {
        cout << *it2 << " ";
    }

    cout << endl;

    // ============================================================
    // REVERSE ITERATORS
    // ============================================================

    // deque also supports reverse iterators:
    //
    // rbegin()
    // rend()
    //
    // rbegin() points to the LAST element.
    //
    // rend() represents the position BEFORE the first element.

    // Current deque:
    //
    // [10] [20] [30] [40] [50]
    //                         ^
    //                         |
    //                       rbegin()
    //
    // So rbegin() points to 50.

    deque<int>::reverse_iterator rit = dq.rbegin();

    cout << "\nReverse first element: "
         << *rit
         << endl;

    // ============================================================
    // REVERSE TRAVERSAL
    // ============================================================

    cout << "Reverse traversal: ";

    for (auto rit2 = dq.rbegin();
         rit2 != dq.rend();
         ++rit2)
    {
        cout << *rit2 << " ";
    }

    cout << endl;

    // Output:
    //
    // 50 40 30 20 10

    // ============================================================
    // RANDOM ACCESS USING REVERSE ITERATOR
    // ============================================================

    // Reverse iterators also provide random access.
    //
    // Example:
    //
    // rit points to 50.
    //
    // rit + 1 -> 40
    // rit + 2 -> 30

    rit = dq.rbegin();

    cout << "Reverse iterator current: "
         << *rit
         << endl;

    cout << "rit + 2: "
         << *(rit + 2)
         << endl;

    // ============================================================
    // DIFFERENCE BETWEEN ++ AND +=
    // ============================================================

    /*
        ++it
        ------------------------------------------------------------
        Moves one position.


        it += 3
        ------------------------------------------------------------
        Moves three positions.


        Example:

        [10] [20] [30] [40] [50]
         ^
         |
         it

        ++it

        [10] [20] [30] [40] [50]
               ^
               |
               it


        it += 3 from 10:

        [10] [20] [30] [40] [50]
                         ^
                         |
                         it
    */

    // ============================================================
    // COMPARING ITERATORS
    // ============================================================

    // Random-access iterators can also be compared.

    auto it1 = dq.begin();
    auto it2 = dq.begin() + 3;

    // it1 points to 10.
    // it2 points to 40.

    if (it1 < it2)
    {
        cout << "\nit1 comes before it2"
             << endl;
    }

    if (it2 > it1)
    {
        cout << "it2 comes after it1"
             << endl;
    }

    // ============================================================
    // DISTANCE BETWEEN ITERATORS
    // ============================================================

    // We can use:
    //
    // it2 - it1
    //
    // because deque iterators are random-access iterators.
    //
    // it1 -> 10
    // it2 -> 40
    //
    // Distance:
    //
    // 3 positions

    cout << "Distance between it1 and it2: "
         << (it2 - it1)
         << endl;

    // ============================================================
    // ITERATOR AND INDEX RELATIONSHIP
    // ============================================================

    /*
        Deque:

        Index:   0    1    2    3    4
                [10] [20] [30] [40] [50]

        begin()
           ↓
          10

        begin() + 1
           ↓
          20

        begin() + 2
           ↓
          30

        begin() + 3
           ↓
          40

        begin() + 4
           ↓
          50

        end()
           ↓
        after 50
    */

    // ============================================================
    // ITERATOR VS INDEXING
    // ============================================================

    // Direct indexing:

    cout << "\nUsing index: "
         << dq[2]
         << endl;

    // Iterator:

    auto position = dq.begin() + 2;

    cout << "Using iterator: "
         << *position
         << endl;

    // Both give:
    //
    // 30

    // ============================================================
    // MODIFYING DEQUE THROUGH ITERATOR
    // ============================================================

    // IMPORTANT:
    //
    // A normal iterator allows us to modify the element
    // it points to.

    auto modifyIt = dq.begin() + 2;

    // modifyIt points to:
    //
    // 30

    *modifyIt = 300;

    // Deque becomes:
    //
    // [10] [20] [300] [40] [50]

    cout << "\nAfter modifying through iterator: ";

    for (int x : dq)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // CONST ITERATOR
    // ============================================================

    // If we only want to READ elements and do not want
    // to modify them, we can use cbegin() and cend().

    cout << "Using const iterator: ";

    for (auto cit = dq.cbegin(); cit != dq.cend(); ++cit)
    {
        cout << *cit << " ";

        // This would be INVALID:
        //
        // *cit = 100;
        //
        // because cit is a const iterator.
    }

    cout << endl;

    // ============================================================
    // crbegin() AND crend()
    // ============================================================

    // const reverse iterators:
    //
    // crbegin()
    // crend()
    //
    // These allow reverse traversal without modifying elements.

    cout << "Using const reverse iterator: ";

    for (auto crit = dq.crbegin();
         crit != dq.crend();
         ++crit)
    {
        cout << *crit << " ";
    }

    cout << endl;

    // ============================================================
    // COMPLETE ITERATOR FLOW
    // ============================================================

    /*
        Initial deque:

        [10] [20] [30] [40] [50]


        ------------------------------------------------------------
        Forward
        ------------------------------------------------------------

        begin()
           ↓
          10

        ++it
           ↓
          20

        ++it
           ↓
          30

        ++it
           ↓
          40

        ++it
           ↓
          50

        ++it
           ↓
         end()


        ------------------------------------------------------------
        Backward
        ------------------------------------------------------------

        rbegin()
           ↓
          50

        ++rit
           ↓
          40

        ++rit
           ↓
          30

        ++rit
           ↓
          20

        ++rit
           ↓
          10

        ++rit
           ↓
         rend()
    */

    // ============================================================
    // VECTOR vs DEQUE ITERATORS
    // ============================================================

    /*
        VECTOR:
        ------------------------------------------------------------
        Random-access iterator ✅
        begin()               ✅
        end()                 ✅
        it + n                ✅
        it - n                ✅
        it[n]                 ✅


        DEQUE:
        ------------------------------------------------------------
        Random-access iterator ✅
        begin()               ✅
        end()                 ✅
        it + n                ✅
        it - n                ✅
        it[n]                 ✅


        LIST:
        ------------------------------------------------------------
        Bidirectional iterator ✅
        begin()               ✅
        end()                 ✅
        ++it                  ✅
        --it                  ✅
        it + n                ❌
        it[n]                 ❌


        STACK:
        ------------------------------------------------------------
        Public iterators       ❌


        QUEUE:
        ------------------------------------------------------------
        Public iterators       ❌
    */

    // ============================================================
    // IMPORTANT DEQUE ITERATOR RULES
    // ============================================================

    /*
        1. begin()
           -> first element


        2. end()
           -> one position after last element


        3. *it
           -> current element


        4. ++it
           -> next element


        5. --it
           -> previous element


        6. it + n
           -> move n positions forward


        7. it - n
           -> move n positions backward


        8. it[n]
           -> access relative element


        9. rbegin()
           -> last element


        10. rend()
            -> position before first element


        11. cbegin()
            -> const forward iterator


        12. cend()
            -> const end iterator


        13. crbegin()
            -> const reverse iterator


        14. crend()
            -> const reverse-end iterator
    */

    return 0;
}