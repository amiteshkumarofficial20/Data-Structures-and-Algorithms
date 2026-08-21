#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    // ============================================================
    // MIN HEAP + SWAP
    // ============================================================
    //
    // A MIN HEAP can be created using priority_queue:
    //
    // priority_queue<
    //     int,
    //     vector<int>,
    //     greater<int>
    // >
    //
    // In a MIN HEAP:
    //
    // SMALLEST value = HIGHEST PRIORITY
    //
    // Therefore:
    //
    // pq.top()
    //
    // always gives the SMALLEST element.
    //
    //
    // swap() is used to exchange the COMPLETE contents
    // of two compatible priority queues.
    //
    // Example:
    //
    // first  = {10, 20, 30}
    // second = {100, 200, 300}
    //
    // After:
    //
    // first.swap(second);
    //
    // first  = {100, 200, 300}
    // second = {10, 20, 30}

    // ============================================================
    // CREATING FIRST MIN HEAP
    // ============================================================
    //
    // Breakdown:
    //
    // priority_queue<
    //     int,             // element type
    //     vector<int>,     // underlying container
    //     greater<int>     // comparison rule
    // >
    //
    // greater<int> changes the priority order so that
    // the SMALLEST value gets the highest priority.

    priority_queue<int, vector<int>, greater<int>> first;

    // ============================================================
    // ADDING ELEMENTS TO FIRST MIN HEAP
    // ============================================================

    first.push(10);
    first.push(20);
    first.push(30);
    first.push(40);

    // Values inside first:
    //
    // 10, 20, 30, 40
    //
    // Since this is a MIN HEAP:
    //
    // smallest = 10
    //
    // Therefore:
    //
    // first.top() = 10

    // ============================================================
    // CREATING SECOND MIN HEAP
    // ============================================================

    priority_queue<int, vector<int>, greater<int>> second;

    // ============================================================
    // ADDING ELEMENTS TO SECOND MIN HEAP
    // ============================================================

    second.push(100);
    second.push(200);
    second.push(300);
    second.push(400);

    // Values inside second:
    //
    // 100, 200, 300, 400
    //
    // Smallest value:
    //
    // 100
    //
    // Therefore:
    //
    // second.top() = 100

    // ============================================================
    // STATE BEFORE SWAP
    // ============================================================

    /*
        FIRST MIN HEAP
        ------------------------------------------------------------

        Values:

        10, 20, 30, 40

        Smallest = 10

        TOP = 10


        SECOND MIN HEAP
        ------------------------------------------------------------

        Values:

        100, 200, 300, 400

        Smallest = 100

        TOP = 100
    */

    // ============================================================
    // PRINT TOP BEFORE SWAP
    // ============================================================

    cout << "Before swap:" << endl;

    cout << "First Min Heap Top: "
         << first.top()
         << endl;

    cout << "Second Min Heap Top: "
         << second.top()
         << endl;

    // ============================================================
    // PRINT SIZE BEFORE SWAP
    // ============================================================

    // Both currently contain 4 elements.

    cout << "First Size: "
         << first.size()
         << endl;

    cout << "Second Size: "
         << second.size()
         << endl;

    // ============================================================
    // swap()
    // ============================================================
    //
    // Syntax:
    //
    // first.swap(second);
    //
    // This exchanges the COMPLETE contents of both min heaps.
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
    // Because both are MIN HEAPS:
    //
    // first.top()  becomes 100
    // second.top() becomes 10

    first.swap(second);

    // ============================================================
    // STATE AFTER SWAP
    // ============================================================

    /*
        FIRST MIN HEAP
        ------------------------------------------------------------

        Now contains:

        100, 200, 300, 400

        Smallest = 100

        TOP = 100


        SECOND MIN HEAP
        ------------------------------------------------------------

        Now contains:

        10, 20, 30, 40

        Smallest = 10

        TOP = 10
    */

    // ============================================================
    // PRINT TOP AFTER SWAP
    // ============================================================

    cout << "\nAfter swap:" << endl;

    cout << "First Min Heap Top: "
         << first.top()
         << endl;

    cout << "Second Min Heap Top: "
         << second.top()
         << endl;

    // ============================================================
    // PRINT SIZE AFTER SWAP
    // ============================================================

    // Since both heaps had equal size:
    //
    // first.size()  = 4
    // second.size() = 4
    //
    // The size values remain 4.
    //
    // But their contents have been exchanged.

    cout << "First Size: "
         << first.size()
         << endl;

    cout << "Second Size: "
         << second.size()
         << endl;

    // ============================================================
    // IMPORTANT:
    // SWAP EXCHANGES COMPLETE CONTENTS
    // ============================================================
    //
    // swap() does NOT mean:
    //
    // first.top() <-> second.top()
    //
    // only.
    //
    // It exchanges the complete priority queues.
    //
    // Example:
    //
    // Before:
    //
    // first  = {10,20,30,40}
    // second = {100,200,300,400}
    //
    // After:
    //
    // first  = {100,200,300,400}
    // second = {10,20,30,40}

    // ============================================================
    // SWAP WITH DIFFERENT SIZES
    // ============================================================
    //
    // Both priority queues do NOT need to have the same size.
    //
    // Example:
    //
    // pq1 = {10,20}
    // pq2 = {100,200,300,400}
    //
    // After swap:
    //
    // pq1 = {100,200,300,400}
    // pq2 = {10,20}
    //
    // Therefore their sizes also exchange.

    // ============================================================
    // CREATING MIN HEAPS WITH DIFFERENT SIZES
    // ============================================================

    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;

    // pq1 has 2 elements.

    pq1.push(10);
    pq1.push(20);

    // pq2 has 4 elements.

    pq2.push(100);
    pq2.push(200);
    pq2.push(300);
    pq2.push(400);

    // BEFORE:
    //
    // pq1:
    //
    // Values = 10, 20
    // TOP = 10
    // SIZE = 2
    //
    //
    // pq2:
    //
    // Values = 100, 200, 300, 400
    // TOP = 100
    // SIZE = 4

    // Swap complete contents.

    pq1.swap(pq2);

    // AFTER:
    //
    // pq1:
    //
    // Values = 100, 200, 300, 400
    // TOP = 100
    // SIZE = 4
    //
    //
    // pq2:
    //
    // Values = 10, 20
    // TOP = 10
    // SIZE = 2

    cout << "\nDifferent-size Min Heaps after swap:"
         << endl;

    cout << "pq1 Top: "
         << pq1.top()
         << endl;

    cout << "pq1 Size: "
         << pq1.size()
         << endl;

    cout << "pq2 Top: "
         << pq2.top()
         << endl;

    cout << "pq2 Size: "
         << pq2.size()
         << endl;

    // ============================================================
    // ANOTHER WAY TO SWAP
    // ============================================================
    //
    // We can also use the standard swap() function:
    //
    // swap(pq1, pq2);
    //
    // This also exchanges their complete contents.
    //
    // We are NOT calling it here because it would perform
    // another swap.

    // ============================================================
    // MEMBER FUNCTION VS STANDARD swap()
    // ============================================================
    //
    // Method 1:
    //
    // pq1.swap(pq2);
    //
    //
    // Method 2:
    //
    // swap(pq1, pq2);
    //
    //
    // Both exchange the contents when the priority queue
    // types are compatible.

    // ============================================================
    // IMPORTANT: BOTH QUEUES MUST HAVE COMPATIBLE TYPES
    // ============================================================
    //
    // This works:
    //
    // priority_queue<int, vector<int>, greater<int>> a;
    // priority_queue<int, vector<int>, greater<int>> b;
    //
    // a.swap(b);   // ✅
    //
    //
    // But these are different types:
    //
    // priority_queue<int> maxHeap;
    //
    // priority_queue<
    //     int,
    //     vector<int>,
    //     greater<int>
    // > minHeap;
    //
    // maxHeap and minHeap cannot simply be swapped with
    // each other's member swap because their types differ.
    //
    // MAX HEAP:
    //
    // largest -> top
    //
    // MIN HEAP:
    //
    // smallest -> top

    // ============================================================
    // MIN HEAP PROPERTY AFTER SWAP
    // ============================================================
    //
    // swap() does NOT destroy the heap property.
    //
    // If both containers are MIN HEAPs:
    //
    // after swap, each one is still a valid MIN HEAP.
    //
    // Example:
    //
    // first before:
    // 10, 20, 30
    //
    // second before:
    // 100, 200, 300
    //
    //
    // after swap:
    //
    // first:
    // 100, 200, 300
    //
    // smallest = 100
    //
    //
    // second:
    // 10, 20, 30
    //
    // smallest = 10
    //
    // So:
    //
    // first.top()  = 100
    // second.top() = 10

    // ============================================================
    // MIN HEAP PROCESSING AFTER SWAP
    // ============================================================
    //
    // Suppose after swap:
    //
    // pq1 = {100, 200, 300, 400}
    //
    // If we process:
    //
    // top() + pop()
    //
    // the order will be:
    //
    // 100 -> 200 -> 300 -> 400
    //
    // because it is a MIN HEAP.

    cout << "\nProcessing pq1 after swap: ";

    while (!pq1.empty())
    {
        // Smallest element has highest priority.

        cout << pq1.top() << " ";

        // Remove the smallest element.

        pq1.pop();
    }

    cout << endl;

    // ============================================================
    // MIN HEAP SWAP WITH PAIRS
    // ============================================================
    //
    // The same concept works with other compatible
    // priority queue types.
    //
    // Example:
    //
    // priority_queue<
    //     pair<int,int>,
    //     vector<pair<int,int>>,
    //     greater<pair<int,int>>
    // > pq;
    //
    // Two such min heaps can be swapped too.

    // ============================================================
    // SWAP COMPLEXITY
    // ============================================================
    //
    // swap() is designed to exchange container state efficiently.
    //
    // It does NOT need to individually pop and push every element.
    //
    // For compatible priority queues, swap is generally O(1).
    //
    // Important comparison:
    //
    // Swapping:
    //
    // pq1.swap(pq2);
    //
    // is much better than manually doing:
    //
    // pop everything
    // push everything somewhere else
    //
    // because manual movement would take much more work.

    // ============================================================
    // IMPORTANT: DO NOT CONFUSE swap() WITH pop()
    // ============================================================
    //
    // pop():
    //
    // removes ONE highest-priority element.
    //
    // For MIN HEAP:
    //
    // removes smallest element.
    //
    //
    // swap():
    //
    // exchanges COMPLETE contents of TWO priority queues.

    // ============================================================
    // pop() vs swap()
    // ============================================================

    /*
        MIN HEAP:

        pq = {10,20,30,40}


        pop():
        -------------------------
        removes only 10

        remaining:
        {20,30,40}


        swap(other):
        -------------------------
        exchanges complete contents
        with another compatible min heap.
    */

    // ============================================================
    // SAFETY RULE
    // ============================================================
    //
    // Before calling:
    //
    // pq.top();
    //
    // or:
    //
    // pq.pop();
    //
    // make sure pq is NOT empty.
    //
    // Safe:
    //
    // if (!pq.empty())
    // {
    //     cout << pq.top();
    // }
    //
    //
    // In the processing loop:
    //
    // while (!pq.empty())
    // {
    //     cout << pq.top();
    //     pq.pop();
    // }

    // ============================================================
    // FINAL CHEAT SHEET
    // ============================================================
    //
    // MIN HEAP declaration:
    //
    // priority_queue<
    //     int,
    //     vector<int>,
    //     greater<int>
    // > pq;
    //
    //
    // Add:
    //
    // pq.push(10);
    //
    //
    // Smallest:
    //
    // pq.top();
    //
    //
    // Remove smallest:
    //
    // pq.pop();
    //
    //
    // Swap:
    //
    // pq1.swap(pq2);
    //
    //
    // Alternative:
    //
    // swap(pq1, pq2);
    //
    //
    // Size:
    //
    // pq.size();
    //
    //
    // Empty check:
    //
    // pq.empty();

    // ============================================================
    // FINAL MEMORY TRICK
    // ============================================================
    //
    // MIN HEAP:
    //
    // priority_queue<
    //     int,
    //     vector<int>,
    //     greater<int>
    // >
    //
    // smallest → top()
    //
    //
    // swap:
    //
    // pq1.swap(pq2);
    //
    // complete contents exchange
    //
    //
    // Example:
    //
    // pq1 = {10,20,30}
    // pq2 = {100,200}
    //
    // After:
    //
    // pq1 = {100,200}
    // pq2 = {10,20,30}

    return 0;
}