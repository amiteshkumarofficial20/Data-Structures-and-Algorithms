#include <iostream>
#include <list>
using namespace std;

int main()
{
    // ============================================================
    // CREATING A LIST
    // ============================================================

    // A list is an STL container.
    //
    // Internally, std::list is implemented as a
    // DOUBLY LINKED LIST.
    //
    // In a doubly linked list, every node is connected to:
    //
    // 1. Previous node
    // 2. Next node
    //
    // Conceptually:
    //
    //        previous       next
    //           <----------->
    //
    // [10] <-> [20] <-> [30] <-> [40]
    //
    // Unlike vector, list elements are NOT stored
    // in contiguous memory.

    // Creating an empty list of integers.
    //
    // list<int>
    // -> means the list will store int values.
    //
    // l
    // -> name of the list.
    //
    // Initially:
    //
    // l = []
    //
    // size = 0

    list<int> l;

    // ============================================================
    // ADDING ELEMENTS
    // ============================================================

    // push_back() adds an element at the END of the list.

    l.push_back(10);
    // List:
    //
    // [10]

    l.push_back(20);
    // List:
    //
    // [10] <-> [20]

    l.push_back(30);
    // List:
    //
    // [10] <-> [20] <-> [30]

    l.push_back(40);
    // List:
    //
    // [10] <-> [20] <-> [30] <-> [40]

    // ============================================================
    // LIST ITERATOR
    // ============================================================

    // An iterator is an object used to TRAVERSE
    // through the elements of a container.
    //
    // We can think of an iterator as something similar
    // to a pointer.
    //
    // It points to an element/node in the container.
    //
    // For list:
    //
    // list<int>::iterator
    //
    // is the iterator type.
    //
    // Syntax:
    //
    // list<int>::iterator it;
    //
    // Breakdown:
    //
    // list<int>
    // -> We have a list of integers.
    //
    // ::
    // -> Scope Resolution Operator.
    //
    // iterator
    // -> Iterator type provided by the list container.
    //
    // it
    // -> Name of our iterator.

    // ============================================================
    // begin()
    // ============================================================

    // l.begin() returns an iterator pointing to
    // the FIRST element.
    //
    // Current list:
    //
    // [10] <-> [20] <-> [30] <-> [40]
    //  ^
    //  |
    // begin()
    //
    // So when we write:
    //
    // list<int>::iterator it = l.begin();
    //
    // it points to 10.

    list<int>::iterator it = l.begin();

    // ============================================================
    // DEREFERENCING ITERATOR
    // ============================================================

    // The iterator itself points to an element.
    //
    // To get the actual VALUE stored at that location,
    // we use the dereference operator:
    //
    // *
    //
    // Therefore:
    //
    // *it
    //
    // means:
    //
    // "Give me the value of the element
    //  currently pointed to by it."
    //
    // Since it currently points to 10:
    //
    // *it = 10

    cout << "First element: " << *it << endl;

    // ============================================================
    // MOVING ITERATOR USING ++
    // ============================================================

    // ++it moves the iterator to the NEXT node.
    //
    // Before:
    //
    // [10] <-> [20] <-> [30] <-> [40]
    //   ^
    //   |
    //   it
    //
    // After:
    //
    // [10] <-> [20] <-> [30] <-> [40]
    //           ^
    //           |
    //           it
    //
    // Now *it = 20

    ++it;

    cout << "After ++it: " << *it << endl;

    // ============================================================
    // MOVING ITERATOR AGAIN
    // ============================================================

    // Move from 20 to 30.

    ++it;

    cout << "After another ++it: " << *it << endl;

    // Move from 30 to 40.

    ++it;

    cout << "After another ++it: " << *it << endl;

    // ============================================================
    // MOVING BACKWARD USING --
    // ============================================================

    // Since std::list is a DOUBLY LINKED LIST,
    // its iterator can move in BOTH directions.
    //
    // --it moves the iterator to the PREVIOUS node.
    //
    // Current:
    //
    // [10] <-> [20] <-> [30] <-> [40]
    //                            ^
    //                            |
    //                            it
    //
    // After --it:
    //
    // [10] <-> [20] <-> [30] <-> [40]
    //                     ^
    //                     |
    //                     it
    //
    // Now *it = 30

    --it;

    cout << "After --it: " << *it << endl;

    // Move from 30 back to 20.

    --it;

    cout << "After another --it: " << *it << endl;

    // ============================================================
    // end()
    // ============================================================

    // l.end() does NOT point to the last element.
    //
    // It points to the position JUST AFTER the last element.
    //
    // Conceptually:
    //
    // [10] <-> [20] <-> [30] <-> [40] <-> [END]
    //                                      ^
    //                                      |
    //                                    end()
    //
    // Therefore:
    //
    // *l.end()
    //
    // is INVALID.
    //
    // We should NEVER dereference end() directly.

    // ============================================================
    // MOVING TO end()
    // ============================================================

    // We can set the iterator to end():

    it = l.end();

    // Now:
    //
    // [10] <-> [20] <-> [30] <-> [40] <-> [END]
    //                                      ^
    //                                      |
    //                                      it
    //
    // IMPORTANT:
    //
    // We cannot print *it here because it == end().
    //
    // So before accessing the last element,
    // move one step backward.

    --it;

    // Now it points to the last actual element:
    //
    // [10] <-> [20] <-> [30] <-> [40]
    //                            ^
    //                            |
    //                            it
    //
    // Therefore *it = 40.

    cout << "Last element using end() and --it: "
         << *it << endl;

    // ============================================================
    // TRAVERSING LIST FROM BEGIN() TO END()
    // ============================================================

    // Reset iterator to the first element.

    it = l.begin();

    // while loop:
    //
    // Continue until the iterator reaches end().
    //
    // Condition:
    //
    // it != l.end()
    //
    // means:
    //
    // "Iterator has not reached the end."

    cout << "\nForward traversal:\n";

    while (it != l.end())
    {
        // *it gives current element.

        cout << *it << " ";

        // ++it moves to the next node.

        ++it;
    }

    cout << endl;

    // ============================================================
    // TRAVERSING LIST BACKWARD
    // ============================================================

    // Start from end().

    it = l.end();

    // IMPORTANT:
    //
    // end() is one position after the last element.
    //
    // So we FIRST move backward:
    //
    // --it
    //
    // Then it points to the last actual element.

    cout << "\nBackward traversal:\n";

    while (it != l.begin())
    {
        // Move from end / current position
        // to the previous actual element.

        --it;

        // Print current element.

        cout << *it << " ";
    }

    cout << endl;

    // ============================================================
    // WHY while (it != l.begin()) ?
    // ============================================================

    /*
        Suppose:

        l = [10] <-> [20] <-> [30] <-> [40]

        Initially:

        it = end()

        while (it != begin())

        ----------------------------------------
        First iteration:
        ----------------------------------------

        it = end()

        --it

        it -> 40

        print 40


        ----------------------------------------
        Second iteration:
        ----------------------------------------

        --it

        it -> 30

        print 30


        ----------------------------------------
        Third iteration:
        ----------------------------------------

        --it

        it -> 20

        print 20


        ----------------------------------------
        Fourth iteration:
        ----------------------------------------

        --it

        it -> 10

        print 10


        ----------------------------------------
        Now:
        ----------------------------------------

        it == begin()

        Therefore:

        while (it != begin())

        becomes FALSE.

        Loop stops.
    */

    // ============================================================
    // IMPORTANT: WHY WE DON'T DO THIS
    // ============================================================

    /*
        WRONG:

        while (it != l.begin())
        {
            cout << *it << endl;
            --it;
        }

        Why is it wrong?

        Because if it starts at end(),
        then:

        it = end()

        and *it is INVALID.

        Correct approach:

        while (it != l.begin())
        {
            --it;
            cout << *it << endl;
        }
    */

    // ============================================================
    // LIST ITERATOR AND RANDOM ACCESS
    // ============================================================

    // This is VERY important.
    //
    // A vector iterator supports random access:
    //
    // it + 2
    // it - 2
    // it[2]
    //
    // But a list iterator does NOT support these operations.
    //
    // Example:
    //
    // ❌ it + 2
    // ❌ it - 2
    // ❌ it[2]
    //
    // Because list nodes are not stored contiguously.

    // ============================================================
    // advance()
    // ============================================================

    // If we want to move a list iterator multiple positions,
    // we use advance().
    //
    // Syntax:
    //
    // advance(iterator, number_of_positions);
    //
    // Example:
    //
    // Move it 2 positions forward.

    it = l.begin();

    advance(it, 2);

    // Current:
    //
    // [10] <-> [20] <-> [30] <-> [40]
    //                     ^
    //                     |
    //                     it
    //
    // Therefore:
    //
    // *it = 30

    cout << "\nElement after advancing 2 positions: "
         << *it << endl;

    // ============================================================
    // RANGE-BASED FOR LOOP WITH LIST
    // ============================================================

    // List can also be traversed using range-based for loop.
    //
    // This is simpler when we only want the values
    // and don't need the iterator explicitly.

    cout << "\nRange-based traversal:\n";

    for (int x : l)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // RANGE-BASED LOOP USING const auto&
    // ============================================================

    // const auto&:
    //
    // const -> cannot modify the element.
    //
    // auto  -> compiler automatically determines the type.
    //
    // &     -> reference, so no unnecessary copy is created.
    //
    // This is a good choice when we only want to READ
    // elements, especially when the elements are large objects.

    cout << "\nUsing const auto&:\n";

    for (const auto &x : l)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // FINAL OUTPUT IDEA
    // ============================================================

    /*
        First element: 10
        After ++it: 20
        After another ++it: 30
        After another ++it: 40
        After --it: 30
        After another --it: 20

        Last element using end() and --it: 40

        Forward traversal:
        10 20 30 40

        Backward traversal:
        40 30 20 10
    */

    return 0;
}