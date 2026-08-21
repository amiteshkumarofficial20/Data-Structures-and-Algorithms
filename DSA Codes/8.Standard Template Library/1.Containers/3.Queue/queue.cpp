#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // ============================================================
    // CREATING A QUEUE
    // ============================================================

    // queue<int> q;
    //
    // This creates an EMPTY queue of integers.
    //
    // Queue follows the FIFO principle:
    //
    // FIFO = First In, First Out
    //
    // Matlab:
    //
    // Jo element sabse pehle queue mein enter karega,
    // wahi sabse pehle bahar niklega.
    //
    // Initially:
    //
    // q = []
    //
    queue<int> q;

    // ============================================================
    // push()
    // ============================================================

    // push() adds an element at the BACK of the queue.

    q.push(10);

    // Queue:
    //
    // FRONT        BACK
    //   ↓            ↓
    // [10]

    q.push(20);

    // Queue:
    //
    // FRONT                 BACK
    //   ↓                     ↓
    // [10] -> [20]

    q.push(30);

    // Queue:
    //
    // FRONT                         BACK
    //   ↓                             ↓
    // [10] -> [20] -> [30]

    q.push(40);

    // Queue:
    //
    // FRONT                               BACK
    //   ↓                                   ↓
    // [10] -> [20] -> [30] -> [40]
    //
    // Important:
    //
    // push() always adds at the BACK.
    //
    // So after all push operations:
    //
    // Front = 10
    // Back  = 40

    // ============================================================
    // size()
    // ============================================================

    // size() returns the total number of elements
    // currently present in the queue.
    //
    // Current queue:
    //
    // [10] -> [20] -> [30] -> [40]
    //
    // Total elements = 4

    cout << "Size: " << q.size() << endl;

    // ============================================================
    // pop()
    // ============================================================

    // pop() removes the FRONT element of the queue.
    //
    // IMPORTANT:
    //
    // pop() does NOT return the removed element.
    //
    // Before pop():
    //
    // [10] -> [20] -> [30] -> [40]
    //   ↑
    // FRONT
    //
    // First pop removes 10.

    q.pop();

    // After first pop():
    //
    // [20] -> [30] -> [40]
    //   ↑
    // FRONT

    // Second pop removes the current front element,
    // which is 20.

    q.pop();

    // After second pop():
    //
    // [30] -> [40]
    //   ↑       ↑
    // FRONT    BACK
    //
    // So:
    //
    // Front = 30
    // Back  = 40

    // ============================================================
    // size() AFTER pop()
    // ============================================================

    // We had 4 elements.
    //
    // Removed 2 elements:
    //
    // 4 - 2 = 2
    //
    // Current queue:
    //
    // [30] -> [40]
    //
    // Therefore size = 2.

    cout << "Size: " << q.size() << endl;

    // ============================================================
    // empty()
    // ============================================================

    // empty() checks whether the queue has zero elements.
    //
    // It returns:
    //
    // true  -> queue is empty
    // false -> queue is NOT empty
    //
    // Current queue:
    //
    // [30] -> [40]
    //
    // So the queue is NOT empty.
    //
    // Therefore:
    //
    // q.empty()
    //
    // returns false.

    if (q.empty())
    {
        // This block executes only when the queue is empty.

        cout << "Queue is Empty" << endl;
    }
    else
    {
        // Since our queue contains:
        //
        // [30] -> [40]
        //
        // it is NOT empty.
        //
        // Therefore this block executes.

        cout << "Queue is not Empty" << endl;
    }

    // ============================================================
    // front()
    // ============================================================

    // front() returns the element currently present
    // at the FRONT of the queue.
    //
    // Current queue:
    //
    // [30] -> [40]
    //   ↑
    // FRONT
    //
    // Therefore:
    //
    // q.front() = 30

    cout << "Front Element: "
         << q.front() << endl;

    // ============================================================
    // back()
    // ============================================================

    // back() returns the element currently present
    // at the BACK of the queue.
    //
    // Current queue:
    //
    // [30] -> [40]
    //          ↑
    //         BACK
    //
    // Therefore:
    //
    // q.back() = 40

    cout << "Back Element: "
         << q.back() << endl;

    // ============================================================
    // FINAL STATE
    // ============================================================

    /*
        Let's see the complete flow:

        ------------------------------------------------------------
        Initially:
        ------------------------------------------------------------

        q = []


        ------------------------------------------------------------
        q.push(10)
        ------------------------------------------------------------

        [10]


        ------------------------------------------------------------
        q.push(20)
        ------------------------------------------------------------

        [10] -> [20]


        ------------------------------------------------------------
        q.push(30)
        ------------------------------------------------------------

        [10] -> [20] -> [30]


        ------------------------------------------------------------
        q.push(40)
        ------------------------------------------------------------

        [10] -> [20] -> [30] -> [40]

        size = 4


        ------------------------------------------------------------
        q.pop()
        ------------------------------------------------------------

        10 is removed.

        [20] -> [30] -> [40]

        size = 3


        ------------------------------------------------------------
        q.pop()
        ------------------------------------------------------------

        20 is removed.

        [30] -> [40]

        size = 2


        ------------------------------------------------------------
        empty()
        ------------------------------------------------------------

        false

        Because queue still contains:

        30, 40


        ------------------------------------------------------------
        front()
        ------------------------------------------------------------

        30


        ------------------------------------------------------------
        back()
        ------------------------------------------------------------

        40
    */

    // ============================================================
    // FINAL OUTPUT
    // ============================================================

    /*
        Size: 4
        Size: 2
        Queue is not Empty
        Front Element: 30
        Back Element: 40
    */

    return 0;
}