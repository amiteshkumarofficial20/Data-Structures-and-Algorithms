#include <iostream>
#include <deque>

using namespace std;

int main()
{
    // ============================================================
    // INSERT, ERASE AND CLEAR IN DEQUE
    // ============================================================
    //
    // deque supports:
    //
    // insert()
    // erase()
    // clear()
    //
    // Because deque supports random-access iterators,
    // we can use:
    //
    // dq.begin() + index
    //
    // to reach a particular position.

    // ============================================================
    // CREATING A DEQUE
    // ============================================================

    // Creating a deque with some initial values.
    //
    // Current deque:
    //
    // [10] [20] [30] [40]

    deque<int> dq = {10, 20, 30, 40};

    // ============================================================
    // INSERTION
    // ============================================================
    //
    // insert() is used to add elements at a specific position.
    //
    // General syntax:
    //
    // dq.insert(position, value);
    //
    // IMPORTANT:
    //
    // insert() adds the new element BEFORE the position
    // pointed to by the iterator.

    // ============================================================
    // INSERT ONE ELEMENT
    // ============================================================

    // We want to insert 15 before 20.
    //
    // Current:
    //
    // Index:   0    1    2    3
    // Value:  [10] [20] [30] [40]
    //
    // dq.begin() points to index 0.
    //
    // dq.begin() + 1 points to index 1, which contains 20.
    //
    // So:
    //
    // dq.insert(dq.begin() + 1, 15);
    //
    // means:
    //
    // "Insert 15 before the element at index 1."

    dq.insert(dq.begin() + 1, 15);

    // Now deque becomes:
    //
    // [10] [15] [20] [30] [40]
    //
    // Index:
    //
    //  0    1    2    3    4
    //
    // Notice that all elements after the insertion point
    // shift to accommodate the new element.

    cout << "After inserting 15: ";

    for (int x : dq)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // INSERT AT BEGINNING
    // ============================================================

    // We can insert at the very beginning using:
    //
    // dq.begin()
    //
    // Example:
    //
    // Current:
    //
    // [10] [15] [20] [30] [40]
    //
    // Insert 5 before the first element.

    dq.insert(dq.begin(), 5);

    // Now:
    //
    // [5] [10] [15] [20] [30] [40]

    cout << "After inserting 5 at beginning: ";

    for (int x : dq)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // INSERT BEFORE LAST ELEMENT
    // ============================================================

    // end() points just AFTER the last element.
    //
    // So:
    //
    // dq.end() - 1
    //
    // points to the last element.
    //
    // We can insert before the last element.

    dq.insert(dq.end() - 1, 35);

    // Before:
    //
    // [5] [10] [15] [20] [30] [40]
    //
    // dq.end() - 1 -> 40
    //
    // Insert 35 BEFORE 40.
    //
    // After:
    //
    // [5] [10] [15] [20] [30] [35] [40]

    cout << "After inserting 35 before last element: ";

    for (int x : dq)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // INSERT MULTIPLE COPIES
    // ============================================================
    //
    // Another form of insert():
    //
    // dq.insert(position, count, value);
    //
    // This inserts the same value multiple times.
    //
    // Example:
    //
    // Insert three 100s before 30.

    // Current:
    //
    // [5] [10] [15] [20] [30] [35] [40]
    //
    // index of 30 = 4

    dq.insert(dq.begin() + 4, 3, 100);

    // After:
    //
    // [5] [10] [15] [20] [100] [100] [100] [30] [35] [40]

    cout << "After inserting three 100s: ";

    for (int x : dq)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // INSERT USING INITIALIZER LIST
    // ============================================================
    //
    // We can insert multiple different values at once.
    //
    // Syntax:
    //
    // dq.insert(position, {value1, value2, value3});
    //
    // Example:
    //
    // Insert 200, 300, 400 before 30.

    // Find 30.
    //
    // Current:
    //
    // [5] [10] [15] [20] [100] [100] [100] [30] ...

    auto it = dq.begin() + 7;

    // it points to 30.
    //
    // Insert:
    //
    // 200, 300, 400
    //
    // before 30.

    dq.insert(it, {200, 300, 400});

    // Result:
    //
    // [5] [10] [15] [20]
    // [100] [100] [100]
    // [200] [300] [400]
    // [30] [35] [40]

    cout << "After inserting multiple different values: ";

    for (int x : dq)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // ERASE
    // ============================================================
    //
    // erase() is used to remove elements.
    //
    // There are mainly two common forms:
    //
    // 1. erase(iterator)
    // 2. erase(first, last)
    //
    // Remember:
    //
    // [first, last)
    //
    // first is INCLUDED
    // last is NOT INCLUDED.

    // ============================================================
    // ERASE ONE ELEMENT
    // ============================================================
    //
    // Let's remove 20.
    //
    // Current:
    //
    // [5] [10] [15] [20] [100] ...
    //
    // 20 is at index 3.
    //
    // So:
    //
    // dq.begin() + 3
    //
    // points to 20.

    dq.erase(dq.begin() + 3);

    // 20 is removed.
    //
    // New beginning:
    //
    // [5] [10] [15] [100] [100] [100] ...

    cout << "After erasing 20: ";

    for (int x : dq)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // ERASE USING ITERATOR
    // ============================================================

    // Instead of directly passing:
    //
    // dq.begin() + index
    //
    // we can create an iterator.

    auto eraseIt = dq.begin() + 1;

    // eraseIt currently points to:
    //
    // 10

    dq.erase(eraseIt);

    // 10 is removed.

    cout << "After erasing element at index 1: ";

    for (int x : dq)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // ERASE A RANGE
    // ============================================================
    //
    // Syntax:
    //
    // dq.erase(first, last);
    //
    // Range:
    //
    // [first, last)
    //
    // first included
    // last excluded

    // Suppose current deque is:
    //
    // [5] [15] [100] [100] [100] [200] [300] [400] [30] [35] [40]
    //
    // We want to remove:
    //
    // 100, 100, 100
    //
    // Their indexes are:
    //
    // 2, 3, 4
    //
    // So:
    //
    // first = begin() + 2
    // last  = begin() + 5
    //
    // Because index 5 is NOT included.

    dq.erase(dq.begin() + 2,
             dq.begin() + 5);

    // Result:
    //
    // [5] [15] [200] [300] [400] [30] [35] [40]

    cout << "After range erase: ";

    for (int x : dq)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // ERASE FROM A POSITION TO END
    // ============================================================
    //
    // We can erase everything from a position up to the end.
    //
    // Example:
    //
    // dq.erase(dq.begin() + 2, dq.end());
    //
    // This would keep:
    //
    // index 0
    // index 1
    //
    // and remove all elements after them.

    // We will demonstrate it on a separate deque
    // so that the main deque remains easy to understand.

    deque<int> temp = {10, 20, 30, 40, 50};

    // Remove from index 2 until the end.
    //
    // index 2 = 30
    //
    // Everything from 30 onwards will be removed.

    temp.erase(temp.begin() + 2, temp.end());

    // temp becomes:
    //
    // [10] [20]

    cout << "After erase from index 2 to end: ";

    for (int x : temp)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // CLEAR
    // ============================================================
    //
    // clear() removes ALL elements from the deque.
    //
    // Syntax:
    //
    // dq.clear();
    //
    // Example:
    //
    // Current dq:
    //
    // [5] [15] [200] [300] [400] [30] [35] [40]
    //
    // After clear():
    //
    // []

    dq.clear();

    // ============================================================
    // SIZE AFTER clear()
    // ============================================================

    // clear() removes all elements.
    //
    // Therefore:
    //
    // dq.size() = 0

    cout << "Size after clear: "
         << dq.size()
         << endl;

    // ============================================================
    // empty() AFTER clear()
    // ============================================================

    // Since clear() removed all elements:
    //
    // dq.empty()
    //
    // returns true.

    if (dq.empty())
    {
        cout << "Deque is Empty after clear()"
             << endl;
    }
    else
    {
        cout << "Deque is Not Empty"
             << endl;
    }

    // ============================================================
    // IMPORTANT: clear() vs erase()
    // ============================================================
    //
    // erase():
    //
    // Removes one element or a selected range.
    //
    // Example:
    //
    // dq.erase(dq.begin() + 2);
    //
    // OR:
    //
    // dq.erase(dq.begin() + 1,
    //          dq.begin() + 4);
    //
    //
    // clear():
    //
    // Removes ALL elements.
    //
    // dq.clear();

    // ============================================================
    // INSERT vs ERASE vs CLEAR
    // ============================================================

    /*
        INSERT
        ------------------------------------------------------------
        Adds elements.

        dq.insert(position, value);


        ERASE
        ------------------------------------------------------------
        Removes one element or a range.

        dq.erase(position);

        dq.erase(first, last);


        CLEAR
        ------------------------------------------------------------
        Removes ALL elements.

        dq.clear();
    */

    // ============================================================
    // IMPORTANT DIFFERENCE:
    // pop_front/pop_back vs erase
    // ============================================================

    /*
        pop_front()
        ------------------------------------------------------------
        Removes only the FIRST element.

        Example:
        [10] [20] [30]

        pop_front()

        [20] [30]


        pop_back()
        ------------------------------------------------------------
        Removes only the LAST element.

        Example:
        [10] [20] [30]

        pop_back()

        [10] [20]


        erase()
        ------------------------------------------------------------
        Can remove an element from an arbitrary position.

        Example:
        [10] [20] [30]

        erase(begin() + 1)

        [10] [30]


        clear()
        ------------------------------------------------------------
        Removes EVERYTHING.

        [10] [20] [30]

        clear()

        []
    */

    // ============================================================
    // IMPORTANT: insert() POSITION
    // ============================================================
    //
    // insert() places the new value BEFORE the given iterator.
    //
    // Example:
    //
    // deque:
    //
    // [10] [20] [30]
    //
    // auto it = dq.begin() + 1;
    //
    // it points to 20.
    //
    // dq.insert(it, 15);
    //
    // Result:
    //
    // [10] [15] [20] [30]

    // ============================================================
    // IMPORTANT: erase() RANGE
    // ============================================================
    //
    // erase(first, last)
    //
    // follows:
    //
    // [first, last)
    //
    // Example:
    //
    // [10] [20] [30] [40] [50]
    //
    // dq.erase(begin() + 1,
    //          begin() + 4);
    //
    // Removes:
    //
    // 20, 30, 40
    //
    // Does NOT remove 50.
    //
    // Result:
    //
    // [10] [50]

    // ============================================================
    // TIME COMPLEXITY
    // ============================================================
    //
    // Important basic idea:
    //
    // push_front()  -> O(1) amortized
    // push_back()   -> O(1) amortized
    // pop_front()   -> O(1)
    // pop_back()    -> O(1)
    //
    // Insertion/erasure in the middle generally requires
    // moving elements and can take O(n).
    //
    // clear() visits/removes all elements:
    //
    // O(n)
    //
    // Exact constant factors depend on implementation and
    // the type stored.

    // ============================================================
    // FINAL CHEAT SHEET
    // ============================================================

    /*
        INSERT:

        dq.insert(dq.begin(), 10);

        dq.insert(dq.begin() + 2, 50);

        dq.insert(dq.begin() + 2, 3, 100);

        dq.insert(dq.begin() + 2,
                  {10, 20, 30});


        ERASE:

        dq.erase(dq.begin() + 2);

        dq.erase(dq.begin() + 1,
                 dq.begin() + 4);


        CLEAR:

        dq.clear();


        CHECK:

        dq.size();

        dq.empty();
    */

    // ============================================================
    // FINAL MEMORY TRICK
    // ============================================================

    /*
        INSERT
        ↓
        Add element
        ↓
        insert(position, value)


        ERASE
        ↓
        Remove element/range
        ↓
        erase(position)
        erase(first, last)


        CLEAR
        ↓
        Remove ALL
        ↓
        clear()
    */

    return 0;
}