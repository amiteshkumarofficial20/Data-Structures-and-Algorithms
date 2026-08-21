#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // ============================================================
    // CREATING FIRST QUEUE
    // ============================================================

    // Creating an empty queue of integers.
    //
    // Initially:
    //
    // first = []

    queue<int> first;

    // Adding elements to first queue.
    //
    // push() always adds the element at the BACK.

    first.push(10);
    first.push(20);
    first.push(30);
    first.push(40);

    // Current first queue:
    //
    // FRONT                         BACK
    //   ↓                             ↓
    // [10] -> [20] -> [30] -> [40]

    // ============================================================
    // CREATING SECOND QUEUE
    // ============================================================

    // Creating another empty queue.

    queue<int> second;

    // Adding elements to second queue.

    second.push(100);
    second.push(200);
    second.push(300);
    second.push(400);

    // Current second queue:
    //
    // FRONT                              BACK
    //   ↓                                  ↓
    // [100] -> [200] -> [300] -> [400]

    // ============================================================
    // STATE BEFORE SWAP
    // ============================================================

    cout << "Before swap:" << endl;

    // ------------------------------------------------------------
    // Printing first queue
    // ------------------------------------------------------------

    cout << "First queue: ";

    // IMPORTANT:
    //
    // queue does NOT provide begin() and end().
    //
    // So we cannot use:
    //
    // for (auto it = first.begin(); ...)
    //
    // Instead, if we want to print all elements,
    // we can use front() and pop().
    //
    // BUT this would destroy the queue.
    //
    // Therefore, we create a COPY of the queue.

    queue<int> temp1 = first;

    while (!temp1.empty())
    {
        // Print the current front element.

        cout << temp1.front() << " ";

        // Remove the front element from the COPY.
        //
        // Original 'first' queue remains unchanged.

        temp1.pop();
    }

    cout << endl;

    // ------------------------------------------------------------
    // Printing second queue
    // ------------------------------------------------------------

    cout << "Second queue: ";

    // Create a copy of second queue.

    queue<int> temp2 = second;

    while (!temp2.empty())
    {
        cout << temp2.front() << " ";
        temp2.pop();
    }

    cout << endl;

    // ============================================================
    // swap()
    // ============================================================

    // swap() exchanges the contents of two queues.
    //
    // Syntax:
    //
    // first.swap(second);
    //
    // BEFORE:
    //
    // first  = [10, 20, 30, 40]
    // second = [100, 200, 300, 400]
    //
    //
    // AFTER:
    //
    // first  = [100, 200, 300, 400]
    // second = [10, 20, 30, 40]

    first.swap(second);

    // ============================================================
    // STATE AFTER SWAP
    // ============================================================

    cout << "\nAfter swap:" << endl;

    // ------------------------------------------------------------
    // Printing first queue after swap
    // ------------------------------------------------------------

    cout << "First queue: ";

    // Again, make a copy because using pop()
    // on the original queue would destroy its contents.

    temp1 = first;

    while (!temp1.empty())
    {
        cout << temp1.front() << " ";
        temp1.pop();
    }

    cout << endl;

    // ------------------------------------------------------------
    // Printing second queue after swap
    // ------------------------------------------------------------

    cout << "Second queue: ";

    temp2 = second;

    while (!temp2.empty())
    {
        cout << temp2.front() << " ";
        temp2.pop();
    }

    cout << endl;

    // ============================================================
    // CHECKING SIZE AFTER SWAP
    // ============================================================

    // Before swap:
    //
    // first.size()  = 4
    // second.size() = 4
    //
    // After swap:
    //
    // Both still have size 4 in this example,
    // but their CONTENTS have been exchanged.

    cout << "\nSize of first: "
         << first.size() << endl;

    cout << "Size of second: "
         << second.size() << endl;

    // ============================================================
    // IMPORTANT: ANOTHER WAY TO SWAP
    // ============================================================

    // We can also use the standard swap() function:
    //
    // swap(first, second);
    //
    // This does the same thing.
    //
    // If we called it now, the queues would swap again
    // and return to their original contents.
    //
    // We are NOT calling it here.

    // ============================================================
    // VISUAL UNDERSTANDING
    // ============================================================

    /*
        BEFORE SWAP
        ============================================================

        first:

        FRONT                         BACK
          ↓                             ↓
        [10] -> [20] -> [30] -> [40]


        second:

        FRONT                              BACK
          ↓                                  ↓
        [100] -> [200] -> [300] -> [400]


        ============================================================
        first.swap(second);
        ============================================================


        AFTER SWAP
        ============================================================

        first:

        FRONT                              BACK
          ↓                                  ↓
        [100] -> [200] -> [300] -> [400]


        second:

        FRONT                         BACK
          ↓                             ↓
        [10] -> [20] -> [30] -> [40]
    */

    return 0;
}