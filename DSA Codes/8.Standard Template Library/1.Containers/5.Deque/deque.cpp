#include <iostream>
#include <deque>

using namespace std;

int main()
{
    // ============================================================
    // CREATING A DEQUE
    // ============================================================

    // deque<int> dq;
    //
    // This creates an EMPTY deque of integers.
    //
    // deque = Double Ended Queue
    //
    // The main advantage of deque is that we can efficiently
    // insert and remove elements from BOTH ends.
    //
    // We can use:
    //
    // push_front()
    // push_back()
    //
    // pop_front()
    // pop_back()
    //
    // Initially:
    //
    // dq = []

    deque<int> dq;

    // ============================================================
    // push_back()
    // ============================================================

    // push_back() adds an element at the BACK of the deque.
    //
    // Initially:
    //
    // []
    //
    // After push_back(10):
    //
    // [10]

    dq.push_back(10);

    // ============================================================
    // SECOND push_back()
    // ============================================================

    // 20 will be added at the BACK.
    //
    // Current:
    //
    // [10]
    //
    // After:
    //
    // [10] [20]

    dq.push_back(20);

    // ============================================================
    // THIRD push_back()
    // ============================================================

    // 30 is added at the BACK.
    //
    // [10] [20] [30]

    dq.push_back(30);

    // ============================================================
    // FOURTH push_back()
    // ============================================================

    // 40 is added at the BACK.
    //
    // [10] [20] [30] [40]

    dq.push_back(40);

    // ============================================================
    // push_front()
    // ============================================================

    // push_front() adds an element at the FRONT.
    //
    // Current:
    //
    // [10] [20] [30] [40]
    //  ↑
    // FRONT
    //
    // Add 50 at the front:
    //
    // [50] [10] [20] [30] [40]

    dq.push_front(50);

    // ============================================================
    // SECOND push_front()
    // ============================================================

    // Again, push_front() adds the element at the FRONT.
    //
    // Current:
    //
    // [50] [10] [20] [30] [40]
    //
    // Add 100:
    //
    // [100] [50] [10] [20] [30] [40]

    dq.push_front(100);

    // ============================================================
    // size()
    // ============================================================

    // size() returns the total number of elements currently
    // present in the deque.
    //
    // Current deque:
    //
    // [100] [50] [10] [20] [30] [40]
    //
    // Total elements = 6

    cout << "Size of Deque is : "
         << dq.size()
         << endl;

    // ============================================================
    // pop_front()
    // ============================================================

    // pop_front() removes the FIRST element.
    //
    // Current:
    //
    // [100] [50] [10] [20] [30] [40]
    //  ↑
    // removed
    //
    // 100 will be removed.
    //
    // After pop_front():
    //
    // [50] [10] [20] [30] [40]
    //
    // Number of elements = 5

    dq.pop_front();

    // Print new size.

    cout << "Size of Deque is : "
         << dq.size()
         << endl;

    // ============================================================
    // pop_back()
    // ============================================================

    // pop_back() removes the LAST element.
    //
    // Current:
    //
    // [50] [10] [20] [30] [40]
    //                         ↑
    //                      removed
    //
    // 40 will be removed.
    //
    // After pop_back():
    //
    // [50] [10] [20] [30]
    //
    // Number of elements = 4

    dq.pop_back();

    // Print new size.

    cout << "Size of Deque is : "
         << dq.size()
         << endl;

    // ============================================================
    // front()
    // ============================================================

    // front() returns the FIRST element of the deque.
    //
    // Current deque:
    //
    // [50] [10] [20] [30]
    //  ↑
    // FRONT
    //
    // Therefore:
    //
    // dq.front() = 50

    cout << "First Element of Deque is : "
         << dq.front()
         << endl;

    // ============================================================
    // back()
    // ============================================================

    // back() returns the LAST element of the deque.
    //
    // Current:
    //
    // [50] [10] [20] [30]
    //                   ↑
    //                  BACK
    //
    // Therefore:
    //
    // dq.back() = 30

    cout << "Last Element of Deque is : "
         << dq.back()
         << endl;

    // ============================================================
    // empty()
    // ============================================================

    // empty() checks whether the deque contains zero elements.
    //
    // It returns:
    //
    // true  -> deque is empty
    // false -> deque is NOT empty
    //
    // Current deque:
    //
    // [50] [10] [20] [30]
    //
    // It contains 4 elements.
    //
    // So dq.empty() returns false.

    if (dq.empty())
    {
        // This block will execute only if the deque
        // contains zero elements.

        cout << "Deque is Empty" << endl;
    }
    else
    {
        // Since the deque contains elements,
        // this block will execute.

        cout << "Deque is not Empty" << endl;
    }

    // ============================================================
    // RANDOM ACCESS USING []
    // ============================================================

    // One major advantage of deque is:
    //
    // It supports RANDOM ACCESS.
    //
    // We can directly access elements by index.
    //
    // Current deque:
    //
    // Index:   0    1    2    3
    // Value:  [50] [10] [20] [30]
    //
    // Index starts from 0.
    //
    // So:
    //
    // dq[0] -> 50
    // dq[1] -> 10
    // dq[2] -> 20
    // dq[3] -> 30

    cout << "Value at First Index of Deque is : "
         << dq[0]
         << endl;

    // ============================================================
    // SECOND INDEX
    // ============================================================

    // dq[1] means:
    //
    // "Give me the element at index 1."
    //
    // Current:
    //
    // Index:  0    1    2    3
    // Value: 50   10   20   30
    //
    // Therefore dq[1] = 10

    cout << "Value at Second Index of Deque is : "
         << dq[1]
         << endl;

    // ============================================================
    // at(2)
    // ============================================================

    // at() is another way to access an element by index.
    //
    // dq.at(2)
    //
    // means:
    //
    // "Give me the element at index 2."
    //
    // Current:
    //
    // Index:  0    1    2    3
    // Value: 50   10   20   30
    //
    // Therefore:
    //
    // dq.at(2) = 20

    cout << "Value at Third Index of Deque is : "
         << dq.at(2)
         << endl;

    // ============================================================
    // at(3)
    // ============================================================

    // dq.at(3) gives the element at index 3.
    //
    // Current:
    //
    // [50] [10] [20] [30]
    //                    ↑
    //                  index 3
    //
    // So output = 30

    cout << "Value at Fourth Index of Deque is : "
         << dq.at(3)
         << endl;

    // ============================================================
    // at(4)  <-- IMPORTANT ERROR
    // ============================================================

    // Current deque has only FOUR elements:
    //
    // Index:   0    1    2    3
    // Value:  [50] [10] [20] [30]
    //
    // Valid indexes are:
    //
    // 0, 1, 2, 3
    //
    // Index 4 DOES NOT EXIST.
    //
    // Therefore:
    //
    // dq.at(4)
    //
    // will throw a std::out_of_range exception.
    //
    // This means the original code's next line:
    //
    // cout << dq.at(4);
    //
    // is INVALID for the current deque.
    //
    // The program can terminate with an exception.
    //
    // So this line should NOT be executed unless the deque
    // has at least 5 elements.

    // WRONG FOR CURRENT DEQUE:
    //
    // cout << "Value at Fifth Index of Deque is : "
    //      << dq.at(4)
    //      << endl;

    // ============================================================
    // SAFE WAY TO USE at()
    // ============================================================

    // Before accessing a particular index,
    // make sure the index is within the valid range.
    //
    // For a deque:
    //
    // valid index:
    //
    // 0 <= index < dq.size()

    int index = 4;

    if (index < dq.size())
    {
        cout << "Value at index "
             << index
             << " is : "
             << dq.at(index)
             << endl;
    }
    else
    {
        cout << "Index "
             << index
             << " is out of range"
             << endl;
    }

    // ============================================================
    // [] VS at()
    // ============================================================

    /*
        dq[2]
        ------------------------------------------------------------
        Accesses index 2.

        It does NOT perform bounds checking.


        dq.at(2)
        ------------------------------------------------------------
        Accesses index 2.

        It performs bounds checking.


        Example:

        deque<int> dq = {10, 20, 30};


        dq[1]
        -> 20


        dq.at(1)
        -> 20


        But:

        dq.at(5)

        -> throws std::out_of_range because index 5
           does not exist.
    */

    // ============================================================
    // COMPLETE STATE AFTER ALL VALID OPERATIONS
    // ============================================================

    /*
        Initial:

        []


        push_back(10):

        [10]


        push_back(20):

        [10] [20]


        push_back(30):

        [10] [20] [30]


        push_back(40):

        [10] [20] [30] [40]


        push_front(50):

        [50] [10] [20] [30] [40]


        push_front(100):

        [100] [50] [10] [20] [30] [40]


        pop_front():

        [50] [10] [20] [30] [40]


        pop_back():

        [50] [10] [20] [30]


        FINAL DEQUE:

        Index:   0    1    2    3
        Value:  [50] [10] [20] [30]


        front() = 50
        back()  = 30
        size()  = 4
    */

    // ============================================================
    // IMPORTANT DEQUE FUNCTIONS
    // ============================================================

    /*
        push_back(x)
        ------------------------------------------------------------
        Add x at the BACK.


        push_front(x)
        ------------------------------------------------------------
        Add x at the FRONT.


        pop_back()
        ------------------------------------------------------------
        Remove element from the BACK.


        pop_front()
        ------------------------------------------------------------
        Remove element from the FRONT.


        front()
        ------------------------------------------------------------
        Access FIRST element.


        back()
        ------------------------------------------------------------
        Access LAST element.


        size()
        ------------------------------------------------------------
        Number of elements.


        empty()
        ------------------------------------------------------------
        Check whether deque is empty.


        dq[index]
        ------------------------------------------------------------
        Random access without bounds checking.


        dq.at(index)
        ------------------------------------------------------------
        Random access WITH bounds checking.
    */

    return 0;
}