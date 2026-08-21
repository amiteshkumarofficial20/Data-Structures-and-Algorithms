#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // ============================================================
    // SWAP IN PRIORITY QUEUE
    // ============================================================
    //
    // priority_queue is an STL container adaptor.
    //
    // By default:
    //
    // priority_queue<int>
    //
    // is a MAX-HEAP.
    //
    // That means:
    //
    // Largest value = Highest Priority = TOP
    //
    // Example:
    //
    // [10, 20, 30, 40]
    //
    // TOP = 40
    //
    //
    // swap() is used to EXCHANGE THE COMPLETE CONTENTS
    // of two priority queues.
    //
    // Syntax:
    //
    // pq1.swap(pq2);
    //
    // After swap:
    //
    // pq1 gets pq2's contents
    // pq2 gets pq1's contents

    // ============================================================
    // CREATING FIRST PRIORITY QUEUE
    // ============================================================

    // Creating an empty MAX-HEAP.

    priority_queue<int> first;

    // ============================================================
    // ADDING ELEMENTS TO FIRST PRIORITY QUEUE
    // ============================================================

    first.push(10);
    first.push(20);
    first.push(30);
    first.push(40);

    // Current first priority queue contains:
    //
    // 10, 20, 30, 40
    //
    // Highest priority:
    //
    // 40
    //
    // So:
    //
    // first.top() = 40

    // ============================================================
    // CREATING SECOND PRIORITY QUEUE
    // ============================================================

    priority_queue<int> second;

    // ============================================================
    // ADDING ELEMENTS TO SECOND PRIORITY QUEUE
    // ============================================================

    second.push(100);
    second.push(200);
    second.push(300);
    second.push(400);

    // Current second priority queue:
    //
    // 100, 200, 300, 400
    //
    // Highest priority:
    //
    // 400
    //
    // So:
    //
    // second.top() = 400

    // ============================================================
    // STATE BEFORE SWAP
    // ============================================================

    /*
        FIRST PRIORITY QUEUE
        --------------------

        Values:
        10, 20, 30, 40

        TOP = 40


        SECOND PRIORITY QUEUE
        ---------------------

        Values:
        100, 200, 300, 400

        TOP = 400
    */

    // ============================================================
    // PRINT BEFORE SWAP
    // ============================================================

    cout << "Before swap:" << endl;

    // ------------------------------------------------------------
    // FIRST QUEUE
    // ------------------------------------------------------------

    cout << "First priority queue top: "
         << first.top()
         << endl;

    // ------------------------------------------------------------
    // SECOND QUEUE
    // ------------------------------------------------------------

    cout << "Second priority queue top: "
         << second.top()
         << endl;

    // ------------------------------------------------------------
    // SIZE BEFORE SWAP
    // ------------------------------------------------------------

    cout << "First size: "
         << first.size()
         << endl;

    cout << "Second size: "
         << second.size()
         << endl;

    // ============================================================
    // swap()
    // ============================================================

    // swap() exchanges the COMPLETE contents of the
    // two priority queues.
    //
    // BEFORE:
    //
    // first  = {10, 20, 30, 40}
    // second = {100, 200, 300, 400}
    //
    // AFTER:
    //
    // first  = {100, 200, 300, 400}
    // second = {10, 20, 30, 40}
    //
    // Therefore:
    //
    // first.top()  = 400
    // second.top() = 40

    first.swap(second);

    // ============================================================
    // STATE AFTER SWAP
    // ============================================================

    /*
        FIRST PRIORITY QUEUE
        --------------------

        Now contains:

        100, 200, 300, 400

        TOP = 400


        SECOND PRIORITY QUEUE
        ---------------------

        Now contains:

        10, 20, 30, 40

        TOP = 40
    */

    // ============================================================
    // PRINT AFTER SWAP
    // ============================================================

    cout << "\nAfter swap:" << endl;

    // First priority queue now has second's old contents.

    cout << "First priority queue top: "
         << first.top()
         << endl;

    // Second priority queue now has first's old contents.

    cout << "Second priority queue top: "
         << second.top()
         << endl;

    // ============================================================
    // SIZE AFTER SWAP
    // ============================================================

    // In this example both queues contained 4 elements,
    // so both sizes are still 4.
    //
    // But their CONTENTS have been exchanged.

    cout << "First size: "
         << first.size()
         << endl;

    cout << "Second size: "
         << second.size()
         << endl;

    // ============================================================
    // SWAP WITH DIFFERENT SIZES
    // ============================================================
    //
    // IMPORTANT:
    //
    // swap() does NOT require both priority queues
    // to have the same number of elements.
    //
    // Example:
    //
    // pq1 = {10, 20}
    // pq2 = {100, 200, 300, 400}
    //
    // After swap:
    //
    // pq1 = {100, 200, 300, 400}
    // pq2 = {10, 20}
    //
    // Their sizes are exchanged too.

    // ============================================================
    // EXAMPLE WITH DIFFERENT SIZES
    // ============================================================

    priority_queue<int> pq1;
    priority_queue<int> pq2;

    // pq1 has 2 elements.

    pq1.push(10);
    pq1.push(20);

    // pq2 has 4 elements.

    pq2.push(100);
    pq2.push(200);
    pq2.push(300);
    pq2.push(400);

    // Before swap:
    //
    // pq1:
    //
    // 20
    // 10
    //
    // size = 2
    //
    //
    // pq2:
    //
    // 400
    // 300
    // 200
    // 100
    //
    // size = 4

    pq1.swap(pq2);

    // After swap:
    //
    // pq1:
    //
    // 400
    // 300
    // 200
    // 100
    //
    // size = 4
    //
    //
    // pq2:
    //
    // 20
    // 10
    //
    // size = 2

    cout << "\nDifferent-size priority queues:" << endl;

    cout << "pq1 top: "
         << pq1.top()
         << endl;

    cout << "pq1 size: "
         << pq1.size()
         << endl;

    cout << "pq2 top: "
         << pq2.top()
         << endl;

    cout << "pq2 size: "
         << pq2.size()
         << endl;

    // ============================================================
    // ANOTHER WAY TO SWAP
    // ============================================================

    // We can also use the standard swap() function:
    //
    // swap(pq1, pq2);
    //
    // This also exchanges the complete contents.
    //
    // We are NOT calling it here because that would swap
    // them again.

    // ============================================================
    // MEMBER FUNCTION vs STANDARD FUNCTION
    // ============================================================

    /*
        METHOD 1:
        ------------------------------------------------------------
        pq1.swap(pq2);


        METHOD 2:
        ------------------------------------------------------------
        swap(pq1, pq2);


        Both perform the same basic operation:
        COMPLETE CONTENT EXCHANGE.
    */

    // ============================================================
    // IMPORTANT: SWAP DOES NOT SWAP ONLY TOP
    // ============================================================

    /*
        Suppose:

        pq1:
        TOP = 50

        pq2:
        TOP = 100


        After:

        pq1.swap(pq2);


        pq1:
        TOP = 100

        pq2:
        TOP = 50


        But only TOP values are NOT exchanged.

        The COMPLETE priority queues are exchanged.
    */

    // ============================================================
    // MAX HEAP SWAP
    // ============================================================

    /*
        priority_queue<int>

        DEFAULT = MAX HEAP

        So after swap, each queue still behaves
        as a MAX HEAP.

        Example:

        Before:

        pq1 = {10, 20, 30}
        pq2 = {100, 200, 300}


        After:

        pq1 = {100, 200, 300}
        pq2 = {10, 20, 30}


        Therefore:

        pq1.top() = 300
        pq2.top() = 30
    */

    // ============================================================
    // MIN HEAP CAN ALSO BE SWAPPED
    // ============================================================
    //
    // swap() is not limited to max heaps.
    //
    // Min heaps can also be swapped.
    //
    // Example syntax:
    //
    // priority_queue<
    //     int,
    //     vector<int>,
    //     greater<int>
    // > pq;
    //
    // If two min heaps have the SAME type,
    // their contents can be swapped.

    // ============================================================
    // IMPORTANT: TYPES SHOULD MATCH
    // ============================================================
    //
    // A priority_queue<int> can be swapped with another
    // priority_queue<int> of the compatible same type.
    //
    // Example:
    //
    // priority_queue<int> a;
    // priority_queue<int> b;
    //
    // a.swap(b);   // ✅
    //
    //
    // But different priority_queue types may not be
    // directly swappable because they are different C++ types.
    //
    // Example:
    //
    // priority_queue<int> maxPQ;
    //
    // priority_queue<int, vector<int>, greater<int>> minPQ;
    //
    // These are different types.

    // ============================================================
    // TIME COMPLEXITY
    // ============================================================
    //
    // swap() is designed to be very efficient.
    //
    // For compatible priority queues, swapping is generally O(1),
    // because the underlying container/comparator state is
    // exchanged rather than every element being individually
    // moved.
    //
    // So conceptually:
    //
    // swap -> O(1)

    // ============================================================
    // FINAL OUTPUT IDEA
    // ============================================================

    /*
        Before swap:

        First top: 40
        Second top: 400


        After swap:

        First top: 400
        Second top: 40
    */

    // ============================================================
    // FINAL CHEAT SHEET
    // ============================================================

    /*
        MEMBER FUNCTION:

        pq1.swap(pq2);


        STANDARD FUNCTION:

        swap(pq1, pq2);


        BASIC MEANING:

        pq1 contents <----------> pq2 contents


        Example:

        pq1 = {10, 20, 30}
        pq2 = {100, 200}


        After:

        pq1 = {100, 200}
        pq2 = {10, 20, 30}
    */

    return 0;
}