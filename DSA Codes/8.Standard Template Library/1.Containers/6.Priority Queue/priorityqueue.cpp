#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // ============================================================
    // PRIORITY QUEUE
    // ============================================================
    //
    // priority_queue is an STL container adaptor.
    //
    // Unlike a normal queue, which follows FIFO:
    //
    // FIFO = First In, First Out
    //
    // priority_queue removes elements according to their
    // PRIORITY.
    //
    // By default:
    //
    // priority_queue<int>
    //
    // is a MAX-HEAP.
    //
    // MAX-HEAP means:
    //
    // Maximum value
    //      ↓
    // Highest Priority
    //
    // Therefore, the LARGEST element is always available
    // at the top().
    //
    // Header file:
    //
    // #include <queue>

    // ============================================================
    // CREATING A PRIORITY QUEUE
    // ============================================================

    // Creating an empty priority queue of integers.
    //
    // By default, this is a MAX-HEAP.
    //
    // So:
    //
    // largest value -> highest priority -> top()

    priority_queue<int> pq;

    // ============================================================
    // push()
    // ============================================================
    //
    // push() inserts an element into the priority queue.
    //
    // IMPORTANT:
    //
    // The elements are NOT simply stored in insertion order
    // like a normal queue.
    //
    // The priority queue internally maintains heap structure
    // so that the highest-priority element is available at top().
    //
    // For int MAX-HEAP:
    //
    // larger value = higher priority.

    pq.push(10);

    // Insert 10.
    //
    // Current highest priority:
    //
    // 10
    //
    // top() = 10

    pq.push(20);

    // Insert 20.
    //
    // 20 is greater than 10,
    // so 20 gets higher priority.
    //
    // Highest priority:
    //
    // 20
    //
    // 10
    //
    // IMPORTANT:
    //
    // This diagram is only for understanding priority.
    // The actual internal heap storage is NOT guaranteed
    // to be fully sorted.

    pq.push(30);

    // Insert 30.
    //
    // 30 is now the largest value.
    //
    // Therefore:
    //
    // top() = 30

    pq.push(40);

    // Insert 40.
    //
    // 40 is the largest value.
    //
    // Therefore:
    //
    // top() = 40

    // ============================================================
    // TOP ELEMENT
    // ============================================================

    // top() returns the HIGHEST-PRIORITY element.
    //
    // Since this is a MAX-HEAP:
    //
    // highest priority = largest value.
    //
    // Current inserted values:
    //
    // 10, 20, 30, 40
    //
    // Largest = 40
    //
    // Therefore:
    //
    // pq.top() = 40

    cout << "Top Element Of the Priority Queue is: "
         << pq.top()
         << endl;

    // ============================================================
    // size()
    // ============================================================

    // size() returns the number of elements currently
    // present in the priority queue.
    //
    // Current elements:
    //
    // 10, 20, 30, 40
    //
    // Total = 4

    cout << "Size the Priority Queue is: "
         << pq.size()
         << endl;

    // ============================================================
    // FIRST pop()
    // ============================================================

    // pop() removes the HIGHEST-PRIORITY element.
    //
    // Current top:
    //
    // 40
    //
    // So:
    //
    // pq.pop();
    //
    // removes 40.
    //
    // Remaining elements:
    //
    // 30, 20, 10
    //
    // Highest priority now:
    //
    // 30

    pq.pop();

    // ============================================================
    // TOP AFTER FIRST pop()
    // ============================================================

    // Now top() returns:
    //
    // 30

    cout << "Top Element Of the Priority Queue is: "
         << pq.top()
         << endl;

    // ============================================================
    // SIZE AFTER FIRST pop()
    // ============================================================

    // Originally:
    //
    // size = 4
    //
    // One element removed:
    //
    // 4 - 1 = 3

    cout << "Size the Priority Queue is: "
         << pq.size()
         << endl;

    // ============================================================
    // SECOND pop()
    // ============================================================

    // Current top:
    //
    // 30
    //
    // So 30 will be removed.

    pq.pop();

    // Remaining:
    //
    // 20, 10
    //
    // Highest priority:
    //
    // 20

    // ============================================================
    // TOP AFTER SECOND pop()
    // ============================================================

    // top() now returns 20.

    cout << "Top Element Of the Priority Queue is: "
         << pq.top()
         << endl;

    // ============================================================
    // SIZE AFTER SECOND pop()
    // ============================================================

    // Size before second pop:
    //
    // 3
    //
    // One more element removed:
    //
    // 3 - 1 = 2

    cout << "Size the Priority Queue is: "
         << pq.size()
         << endl;

    // ============================================================
    // empty()
    // ============================================================
    //
    // empty() checks whether the priority queue contains
    // zero elements.
    //
    // It returns:
    //
    // true  -> priority queue is empty
    // false -> priority queue is NOT empty
    //
    // Current priority queue still contains:
    //
    // 20, 10
    //
    // Therefore:
    //
    // pq.empty() = false

    if (pq.empty())
    {
        // This block executes only when the priority queue
        // contains zero elements.

        cout << "Priority Queue is Empty"
             << endl;
    }
    else
    {
        // Since 20 and 10 are still present,
        // this block will execute.

        cout << "Priority Queue is not Empty"
             << endl;
    }

    // ============================================================
    // COMPLETE FLOW
    // ============================================================

    /*
        ------------------------------------------------------------
        Initially
        ------------------------------------------------------------

        pq = []


        ------------------------------------------------------------
        pq.push(10)
        ------------------------------------------------------------

        Values:
        10

        top = 10
        size = 1


        ------------------------------------------------------------
        pq.push(20)
        ------------------------------------------------------------

        Values:
        10, 20

        Highest priority = 20

        top = 20
        size = 2


        ------------------------------------------------------------
        pq.push(30)
        ------------------------------------------------------------

        Values:
        10, 20, 30

        Highest priority = 30

        top = 30
        size = 3


        ------------------------------------------------------------
        pq.push(40)
        ------------------------------------------------------------

        Values:
        10, 20, 30, 40

        Highest priority = 40

        top = 40
        size = 4


        ------------------------------------------------------------
        FIRST pop()
        ------------------------------------------------------------

        40 removed.

        Remaining:
        10, 20, 30

        top = 30
        size = 3


        ------------------------------------------------------------
        SECOND pop()
        ------------------------------------------------------------

        30 removed.

        Remaining:
        10, 20

        top = 20
        size = 2


        ------------------------------------------------------------
        empty()
        ------------------------------------------------------------

        false

        Because:

        10 and 20 are still present.
    */

    // ============================================================
    // FINAL OUTPUT
    // ============================================================

    /*
        Top Element Of the Priority Queue is: 40
        Size the Priority Queue is: 4

        Top Element Of the Priority Queue is: 30
        Size the Priority Queue is: 3

        Top Element Of the Priority Queue is: 20
        Size the Priority Queue is: 2

        Priority Queue is not Empty
    */

    return 0;
}