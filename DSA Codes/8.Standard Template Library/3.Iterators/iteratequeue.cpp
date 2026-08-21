#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // ============================================================
    // CREATING A QUEUE
    // ============================================================

    // Creating an empty queue of integers.
    //
    // Queue follows FIFO:
    //
    // FIFO = First In, First Out
    //
    // The element that enters first
    // will be removed first.

    queue<int> q;

    // ============================================================
    // ADDING ELEMENTS
    // ============================================================

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    // Current queue:
    //
    // FRONT                         BACK
    //   ↓                             ↓
    // [10] -> [20] -> [30] -> [40]

    // ============================================================
    // CAN WE USE ITERATORS WITH queue?
    // ============================================================

    // With vector, we can write:
    //
    // vector<int>::iterator it = v.begin();
    //
    // With list, we can write:
    //
    // list<int>::iterator it = l.begin();
    //
    // BUT with standard queue:
    //
    // queue<int>::iterator it;
    //
    // ❌ This is NOT available.
    //
    // queue does not provide the public begin() and end()
    // functions that vector and list provide.
    //
    // Therefore, we cannot normally write:
    //
    // q.begin();
    // q.end();
    //
    // or:
    //
    // for (auto it = q.begin(); it != q.end(); ++it)
    //
    // ❌ Invalid for std::queue.

    // ============================================================
    // WHY DOES queue NOT PROVIDE ITERATORS?
    // ============================================================

    // queue is a CONTAINER ADAPTOR.
    //
    // Its purpose is to provide a restricted FIFO interface.
    //
    // The important operations are:
    //
    // push()
    // pop()
    // front()
    // back()
    // empty()
    // size()
    //
    // It intentionally does not expose general traversal
    // operations like begin() and end().
    //
    // The idea is:
    //
    // "You should process the queue from FRONT to BACK."

    // ============================================================
    // WRONG APPROACH
    // ============================================================

    /*
        This is NOT valid:

        queue<int> q;

        q.push(10);
        q.push(20);
        q.push(30);

        auto it = q.begin();       // ❌ ERROR
        auto endIt = q.end();     // ❌ ERROR

        while (it != endIt)
        {
            cout << *it << endl;
            ++it;
        }
    */

    // ============================================================
    // CORRECT WAY TO PROCESS A QUEUE
    // ============================================================

    // Queue can be processed using:
    //
    // front()
    // pop()
    //
    // Typical pattern:

    cout << "Queue elements: ";

    while (!q.empty())
    {
        // front() gives the current FRONT element.

        cout << q.front() << " ";

        // pop() removes that FRONT element.

        q.pop();
    }

    cout << endl;

    // Output:
    //
    // 10 20 30 40
    //
    // IMPORTANT:
    //
    // After this loop, q becomes EMPTY.
    //
    // Because every element was removed using pop().

    // ============================================================
    // WHY THIS IS DIFFERENT FROM vector/list
    // ============================================================

    /*
        VECTOR:

        vector<int> v = {10, 20, 30};

        auto it = v.begin();

        while (it != v.end())
        {
            cout << *it << " ";
            ++it;
        }

        ✅ Valid


        LIST:

        list<int> l = {10, 20, 30};

        auto it = l.begin();

        while (it != l.end())
        {
            cout << *it << " ";
            ++it;
        }

        ✅ Valid


        QUEUE:

        queue<int> q;

        auto it = q.begin();

        ❌ Invalid

        queue does not expose begin()/end().
    */

    // ============================================================
    // HOW TO TRAVERSE WITHOUT DESTROYING ORIGINAL QUEUE
    // ============================================================

    // Suppose we do NOT want to destroy the original queue.
    //
    // If we use pop() directly on q,
    // q will become empty.
    //
    // Solution:
    //
    // Create a COPY of the queue.

    queue<int> original;

    original.push(10);
    original.push(20);
    original.push(30);
    original.push(40);

    // Make a copy.
    //
    // temp contains the same elements as original.

    queue<int> temp = original;

    cout << "Traversing copied queue: ";

    while (!temp.empty())
    {
        // Print front of copied queue.

        cout << temp.front() << " ";

        // Remove from copied queue.

        temp.pop();
    }

    cout << endl;

    // original is still unchanged.

    cout << "Original queue size: "
         << original.size() << endl;

    // Output:
    //
    // Original queue size: 4

    // ============================================================
    // IMPORTANT CONCEPT:
    //
    // queue HAS ITERATOR-LIKE INTERNAL IMPLEMENTATION?
    // ============================================================

    // Internally, a queue is usually implemented using
    // another container such as deque.
    //
    // Default:
    //
    // queue<int>
    //
    // is commonly backed by:
    //
    // deque<int>
    //
    // BUT the queue interface does not expose the underlying
    // container's iterators.
    //
    // So even if the underlying container supports iterators,
    // std::queue itself does not provide begin()/end().

    // ============================================================
    // UNDERLYING CONTAINER
    // ============================================================

    // We can explicitly specify the underlying container.
    //
    // Example:
    //
    // queue<int, deque<int>> q;
    //
    // Here deque<int> is the underlying container.
    //
    // But queue still gives us only the queue interface.

    // ============================================================
    // QUEUE USING list AS UNDERLYING CONTAINER
    // ============================================================

    // A queue can also use list as the underlying container,
    // because list supports the required front/back operations.

    // Example:
    //
    // queue<int, list<int>> q;
    //
    // But to use this we would need:
    //
    // #include <list>

    // ============================================================
    // CAN WE GET THE UNDERLYING CONTAINER?
    // ============================================================

    // The standard public queue interface does not normally
    // provide a direct way to access the underlying container.
    //
    // So you should NOT think:
    //
    // q.begin()
    //
    // or:
    //
    // q.end()
    //
    // The intended way is still:
    //
    // front()
    // pop()

    // ============================================================
    // QUEUE ITERATOR ALTERNATIVE:
    // USE THE UNDERLYING CONTAINER DIRECTLY
    // ============================================================

    // If your actual requirement is:
    //
    // "I need iterators and random access/traversal"
    //
    // then perhaps queue is not the correct container.
    //
    // Use:
    //
    // vector
    //
    // or:
    //
    // list
    //
    // depending on what operations you need.

    // ============================================================
    // VECTOR vs LIST vs QUEUE
    // ============================================================

    /*
        VECTOR
        ------------------------------------------------------------
        begin() / end() -> ✅
        Iterator        -> ✅
        Random access   -> ✅
        v[i]             -> ✅
        FIFO interface  -> ❌


        LIST
        ------------------------------------------------------------
        begin() / end() -> ✅
        Iterator        -> ✅
        Random access   -> ❌
        l[i]             -> ❌
        FIFO interface  -> ❌


        QUEUE
        ------------------------------------------------------------
        begin() / end() -> ❌
        Iterator        -> ❌ (public queue interface)
        Random access   -> ❌
        q[i]             -> ❌
        FIFO interface  -> ✅
    */

    // ============================================================
    // QUEUE PROCESSING PATTERN
    // ============================================================

    // This is the most important queue pattern for DSA:

    queue<int> q2;

    q2.push(100);
    q2.push(200);
    q2.push(300);

    while (!q2.empty())
    {
        // 1. Read front element
        int current = q2.front();

        // 2. Process it
        cout << current << endl;

        // 3. Remove it
        q2.pop();
    }

    // ============================================================
    // BFS EXAMPLE
    // ============================================================

    // Queue is extremely common in BFS:
    //
    // Breadth First Search
    //
    // Typical pattern:

    queue<int> bfsQueue;

    bfsQueue.push(1);

    while (!bfsQueue.empty())
    {
        // Get current node.

        int node = bfsQueue.front();

        // Remove current node.

        bfsQueue.pop();

        // Process node.
        cout << "Processing node: "
             << node << endl;

        // Normally, neighboring nodes
        // would be pushed here.
    }

    return 0;
}