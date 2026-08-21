#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // ============================================================
    // CREATING A VECTOR
    // ============================================================

    // Creating an empty vector of integers.
    //
    // At this moment:
    //
    // v = []
    //
    // size = 0
    // capacity = implementation-dependent
    vector<int> v;

    // ============================================================
    // ADDING ELEMENTS USING push_back()
    // ============================================================

    // push_back() adds an element at the END of the vector.

    v.push_back(10);
    // v = [10]

    v.push_back(20);
    // v = [10, 20]

    v.push_back(30);
    // v = [10, 20, 30]

    v.push_back(40);
    // v = [10, 20, 30, 40]

    // ============================================================
    // VECTOR ITERATOR
    // ============================================================

    // An iterator is an object that is used to traverse
    // through the elements of a container.
    //
    // We can think of an iterator as something similar to
    // a pointer that points to elements of the vector.
    //
    // Syntax:
    //
    // vector<int>::iterator it;
    //
    // Here:
    //
    // vector<int>
    // -> tells us that this is a vector of integers.
    //
    // ::
    // -> scope resolution operator.
    //
    // iterator
    // -> iterator type provided by the vector.
    //
    // it
    // -> name of our iterator.

    // ============================================================
    // begin()
    // ============================================================

    // v.begin() returns an iterator pointing to the
    // FIRST element of the vector.
    //
    // Current vector:
    //
    // [10, 20, 30, 40]
    //  ^
    //  |
    // begin()
    //
    // So:
    //
    // it = v.begin();
    //
    // means:
    //
    // "Make it point to the first element of v."

    vector<int>::iterator it = v.begin();

    // ============================================================
    // while LOOP WITH ITERATOR
    // ============================================================

    // We want to traverse the complete vector.
    //
    // v.end() returns an iterator pointing to the position
    // JUST AFTER the last element.
    //
    // IMPORTANT:
    //
    // v.end() does NOT point to 40.
    //
    // Conceptually:
    //
    // Vector:
    //
    //        10      20      30      40
    //         ^       ^       ^       ^
    //         |       |       |       |
    //       begin
    //
    //                                      ^
    //                                      |
    //                                     end()
    //
    // end() is one position past the last element.
    //
    // Therefore we keep traversing while:
    //
    // it != v.end()
    //
    // This means:
    //
    // "Continue as long as the iterator has NOT reached
    // the position after the last element."

    while (it != v.end())
    {
        // ========================================================
        // DEREFERENCING THE ITERATOR
        // ========================================================

        // The iterator 'it' points to an element.
        //
        // To get the actual value stored at that position,
        // we use the dereference operator:
        //
        // *
        //
        // So:
        //
        // *it
        //
        // means:
        //
        // "Give me the value at the position where it is pointing."

        cout << *it << endl;

        // ========================================================
        // MOVING THE ITERATOR
        // ========================================================

        // it++ moves the iterator to the NEXT element.
        //
        // Suppose currently:
        //
        // it -> 10
        //
        // After:
        //
        // it++;
        //
        // it -> 20
        //
        // Then:
        //
        // it++ -> 30
        //
        // it++ -> 40
        //
        // it++ -> end()
        //
        // This allows us to visit every element one by one.

        it++;
    }

    // ============================================================
    // HOW THE LOOP EXECUTES
    // ============================================================

    /*
        Initial vector:

        v = [10, 20, 30, 40]


        Step 1:
        ------------------------------------------------------------
        it = v.begin()
        it points to 10

        Condition:
        it != v.end()
        TRUE

        *it = 10

        Output:
        10

        it++
        Now it points to 20


        Step 2:
        ------------------------------------------------------------
        it points to 20

        Condition:
        it != v.end()
        TRUE

        *it = 20

        Output:
        20

        it++
        Now it points to 30


        Step 3:
        ------------------------------------------------------------
        it points to 30

        Condition:
        it != v.end()
        TRUE

        *it = 30

        Output:
        30

        it++
        Now it points to 40


        Step 4:
        ------------------------------------------------------------
        it points to 40

        Condition:
        it != v.end()
        TRUE

        *it = 40

        Output:
        40

        it++
        Now it points to end()


        Step 5:
        ------------------------------------------------------------
        it == v.end()

        Condition:
        it != v.end()
        FALSE

        Loop stops.
    */

    // ============================================================
    // FINAL OUTPUT
    // ============================================================

    /*
        10
        20
        30
        40
    */

    return 0;
}