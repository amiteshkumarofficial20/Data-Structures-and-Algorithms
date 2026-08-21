#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // ============================================================
    // ITERATORS ON PRIORITY QUEUE
    // ============================================================
    //
    // IMPORTANT:
    //
    // std::priority_queue DOES NOT provide public iterators.
    //
    // Therefore, unlike:
    //
    // vector
    // list
    // deque
    //
    // we cannot use:
    //
    // pq.begin();     // ❌
    // pq.end();       // ❌
    //
    // and we cannot write:
    //
    // priority_queue<int>::iterator it;   // ❌
    //
    // Why?
    //
    // priority_queue is a CONTAINER ADAPTOR.
    //
    // Its interface is intentionally restricted to
    // priority-based operations.

    // ============================================================
    // CREATING A PRIORITY QUEUE
    // ============================================================

    // By default:
    //
    // priority_queue<int>
    //
    // creates a MAX-HEAP.
    //
    // Therefore:
    //
    // Largest value = Highest Priority = TOP

    priority_queue<int> pq;

    // ============================================================
    // ADDING ELEMENTS
    // ============================================================

    pq.push(10);
    pq.push(40);
    pq.push(20);
    pq.push(50);
    pq.push(30);

    // Values inserted:
    //
    // 10, 40, 20, 50, 30
    //
    // Highest priority:
    //
    // 50
    //
    // Therefore:
    //
    // pq.top() = 50

    // ============================================================
    // CAN WE USE begin()?
    // ============================================================

    // This is WRONG:
    //
    // auto it = pq.begin();
    //
    // ❌ Compilation error
    //
    // priority_queue does not expose begin().

    // ============================================================
    // CAN WE USE end()?
    // ============================================================

    // This is also WRONG:
    //
    // auto it = pq.end();
    //
    // ❌ Compilation error
    //
    // priority_queue does not expose end().

    // ============================================================
    // WHY DOES priority_queue NOT HAVE ITERATORS?
    // ============================================================
    //
    // priority_queue is designed to give access to the
    // HIGHEST-PRIORITY element only.
    //
    // Main operations:
    //
    // push()
    // pop()
    // top()
    // size()
    // empty()
    // swap()
    //
    // The idea is:
    //
    // "Give me the highest-priority element,
    //  process it, then remove it."
    //
    // It is NOT designed as a general traversal container.

    // ============================================================
    // NORMAL WAY TO PROCESS A PRIORITY QUEUE
    // ============================================================
    //
    // Since there are no public iterators,
    // we use:
    //
    // top()
    // pop()
    //
    // repeatedly.

    cout << "Priority Queue elements: ";

    while (!pq.empty())
    {
        // top() gives the highest-priority element.

        cout << pq.top() << " ";

        // pop() removes that highest-priority element.

        pq.pop();
    }

    cout << endl;

    // Output:
    //
    // 50 40 30 20 10
    //
    // Because this is a MAX-HEAP.
    //
    // IMPORTANT:
    //
    // The priority queue is NOT necessarily stored as
    // a completely sorted sequence internally.
    //
    // We get priority order only because we repeatedly
    // call top() and pop().

    // ============================================================
    // IMPORTANT: TRAVERSAL DESTROYS THE PRIORITY QUEUE
    // ============================================================
    //
    // After the previous loop:
    //
    // pq = empty
    //
    // Why?
    //
    // Because every iteration called:
    //
    // pq.pop();
    //
    // which removed one element.

    // ============================================================
    // PRESERVING THE ORIGINAL PRIORITY QUEUE
    // ============================================================
    //
    // If we want to process/print the elements
    // without destroying the original priority queue,
    // create a COPY.

    priority_queue<int> original;

    original.push(10);
    original.push(40);
    original.push(20);
    original.push(50);
    original.push(30);

    // Create a copy.
    //
    // temp and original contain the same elements initially.

    priority_queue<int> temp = original;

    // Process the COPY.

    cout << "Copied priority queue: ";

    while (!temp.empty())
    {
        // Read highest-priority element.

        cout << temp.top() << " ";

        // Remove it from the COPY only.

        temp.pop();
    }

    cout << endl;

    // ============================================================
    // ORIGINAL QUEUE IS STILL AVAILABLE
    // ============================================================

    // temp is now empty.
    //
    // original is still unchanged.

    cout << "Original top: "
         << original.top()
         << endl;

    cout << "Original size: "
         << original.size()
         << endl;

    // ============================================================
    // VECTOR HAS ITERATORS
    // ============================================================
    //
    // Compare this with vector:
    //
    // vector<int> v = {10,20,30};
    //
    // auto it = v.begin();       // ✅
    //
    // while (it != v.end())      // ✅
    // {
    //     cout << *it;
    //     ++it;
    // }
    //
    // priority_queue:
    //
    // auto it = pq.begin();      // ❌
    // pq.end();                  // ❌
    //
    // So priority_queue and vector have different interfaces.

    // ============================================================
    // LIST HAS ITERATORS
    // ============================================================
    //
    // Example:
    //
    // list<int> l = {10,20,30};
    //
    // auto it = l.begin();       // ✅
    //
    // while (it != l.end())      // ✅
    // {
    //     cout << *it;
    //     ++it;
    // }
    //
    // priority_queue:
    //
    // begin() / end()            // ❌

    // ============================================================
    // DEQUE HAS ITERATORS
    // ============================================================
    //
    // Example:
    //
    // deque<int> dq = {10,20,30};
    //
    // auto it = dq.begin();      // ✅
    //
    // dq.end();                  // ✅
    //
    // priority_queue:
    //
    // begin() / end()            // ❌

    // ============================================================
    // QUEUE AND STACK ALSO DO NOT HAVE PUBLIC ITERATORS
    // ============================================================
    //
    // Queue:
    //
    // q.begin()                  // ❌
    // q.end()                    // ❌
    //
    //
    // Stack:
    //
    // st.begin()                 // ❌
    // st.end()                   // ❌
    //
    //
    // Priority Queue:
    //
    // pq.begin()                 // ❌
    // pq.end()                   // ❌
    //
    // These are all container adaptors with restricted
    // interfaces.

    // ============================================================
    // PRIORITY QUEUE AS CONTAINER ADAPTOR
    // ============================================================
    //
    // Conceptually:
    //
    // priority_queue
    //       ↓
    // underlying container
    //       ↓
    // usually vector
    //
    // Even though the underlying container can have iterators,
    // priority_queue itself does NOT expose those iterators
    // through its public interface.
    //
    // So:
    //
    // priority_queue<int> pq;
    //
    // pq.begin();    // ❌

    // ============================================================
    // EXPLICIT UNDERLYING CONTAINER
    // ============================================================
    //
    // We can specify the underlying container:
    //
    // priority_queue<int, vector<int>> pq;
    //
    // But even here:
    //
    // pq.begin();    // ❌
    // pq.end();      // ❌
    //
    // The priority_queue interface remains restricted.

    // ============================================================
    // MIN HEAP AND ITERATORS
    // ============================================================
    //
    // A min heap also does NOT provide public iterators.
    //
    // Example:
    //
    // priority_queue<int,
    //                vector<int>,
    //                greater<int>> minPQ;
    //
    // Still:
    //
    // minPQ.begin();   // ❌
    // minPQ.end();     // ❌
    //
    // We process it using:
    //
    // top() + pop()

    // ============================================================
    // MIN HEAP PROCESSING
    // ============================================================

    priority_queue<int,
                   vector<int>,
                   greater<int>>
        minPQ;

    minPQ.push(50);
    minPQ.push(10);
    minPQ.push(30);
    minPQ.push(20);

    cout << "Min-heap priority order: ";

    while (!minPQ.empty())
    {
        // Smallest element has highest priority.

        cout << minPQ.top() << " ";

        minPQ.pop();
    }

    cout << endl;

    // Output:
    //
    // 10 20 30 50

    // ============================================================
    // PRIORITY QUEUE DOES NOT SUPPORT RANDOM ACCESS
    // ============================================================
    //
    // These are also invalid:
    //
    // pq[0];       // ❌
    // pq[2];       // ❌
    // pq.at(2);    // ❌
    //
    // A priority_queue only gives direct access to:
    //
    // top()
    //
    // You cannot directly access an arbitrary element.

    // ============================================================
    // WHY CAN'T WE ACCESS pq[2]?
    // ============================================================
    //
    // Because priority_queue is not designed as a
    // random-access sequence container.
    //
    // Its job is:
    //
    // Maintain priority
    //       ↓
    // Keep highest-priority element at top()
    //
    // Therefore:
    //
    // pq.top()       // ✅
    // pq[2]          // ❌
    // pq.begin()     // ❌

    // ============================================================
    // STANDARD PROCESSING PATTERN
    // ============================================================
    //
    // This is the most important pattern for priority_queue:

    priority_queue<int> processPQ;

    processPQ.push(100);
    processPQ.push(500);
    processPQ.push(200);

    while (!processPQ.empty())
    {
        // 1. Read highest-priority element.

        int current = processPQ.top();

        // 2. Process it.

        cout << "Processing: "
             << current
             << endl;

        // 3. Remove it.

        processPQ.pop();
    }

    // Processing order:
    //
    // 500
    // 200
    // 100

    // ============================================================
    // IF YOU ABSOLUTELY NEED ITERATORS
    // ============================================================
    //
    // If your main requirement is:
    //
    // "I need to traverse elements with begin()/end()."
    //
    // then priority_queue may not be the appropriate container.
    //
    // Depending on your actual requirement, consider:
    //
    // vector
    // list
    // deque
    //
    // But remember:
    //
    // Those containers do NOT automatically provide the
    // same priority-queue behavior.

    // ============================================================
    // VECTOR vs DEQUE vs LIST vs PRIORITY_QUEUE
    // ============================================================

    /*
        VECTOR
        ------------------------------------------------------------
        begin() / end()      -> ✅
        iterators            -> ✅
        random access        -> ✅
        v[index]             -> ✅
        priority behavior   -> ❌


        DEQUE
        ------------------------------------------------------------
        begin() / end()      -> ✅
        iterators            -> ✅
        random access        -> ✅
        dq[index]            -> ✅
        priority behavior   -> ❌


        LIST
        ------------------------------------------------------------
        begin() / end()      -> ✅
        iterators            -> ✅
        random access        -> ❌
        l[index]             -> ❌
        priority behavior   -> ❌


        QUEUE
        ------------------------------------------------------------
        begin() / end()      -> ❌
        public iterators     -> ❌
        random access        -> ❌
        FIFO behavior        -> ✅


        STACK
        ------------------------------------------------------------
        begin() / end()      -> ❌
        public iterators     -> ❌
        random access        -> ❌
        LIFO behavior        -> ✅


        PRIORITY_QUEUE
        ------------------------------------------------------------
        begin() / end()      -> ❌
        public iterators     -> ❌
        random access        -> ❌
        priority behavior   -> ✅
    */

    // ============================================================
    // IMPORTANT INTERVIEW / EXAM POINT
    // ============================================================
    //
    // std::priority_queue does not expose iterators through
    // its public interface.
    //
    // Therefore:
    //
    // 1. pq.begin()       -> ❌
    // 2. pq.end()         -> ❌
    // 3. pq[index]       -> ❌
    // 4. pq.at(index)     -> ❌
    //
    // Use:
    //
    // pq.top()
    // pq.pop()
    //
    // to process elements according to priority.

    // ============================================================
    // FINAL CHEAT SHEET
    // ============================================================

    /*
        priority_queue<int> pq;


        ADD:
        pq.push(10);


        TOP:
        pq.top();


        REMOVE:
        pq.pop();


        SIZE:
        pq.size();


        EMPTY:
        pq.empty();


        ITERATOR:
        pq.begin();        // ❌
        pq.end();          // ❌


        RANDOM ACCESS:
        pq[2];             // ❌
        pq.at(2);          // ❌


        TRAVERSAL:
        while (!pq.empty())
        {
            cout << pq.top();
            pq.pop();
        }


        PRESERVE ORIGINAL:
        priority_queue<int> temp = pq;

        while (!temp.empty())
        {
            cout << temp.top();
            temp.pop();
        }
    */

    // ============================================================
    // FINAL MEMORY TRICK
    // ============================================================
    //
    // vector
    //   ↓
    // iterators ✅
    //
    // list
    //   ↓
    // iterators ✅
    //
    // deque
    //   ↓
    // iterators ✅
    //
    // queue
    //   ↓
    // iterators ❌
    //
    // stack
    //   ↓
    // iterators ❌
    //
    // priority_queue
    //   ↓
    // iterators ❌
    //
    //
    // Priority Queue ka main focus:
    //
    // HIGHEST PRIORITY
    //        ↓
    //      top()
    //        ↓
    //      pop()
    //
    // Not:
    //
    // begin() / end()

    return 0;
}