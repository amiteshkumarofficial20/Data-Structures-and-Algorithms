#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    // ============================================================
    // ITERATORS IN MIN HEAP
    // ============================================================
    //
    // A MIN HEAP in C++ is commonly created using:
    //
    // priority_queue<
    //     int,
    //     vector<int>,
    //     greater<int>
    // >
    //
    // Example:
    //
    // priority_queue<int, vector<int>, greater<int>> pq;
    //
    // Here:
    //
    // int
    // -> data type of elements.
    //
    // vector<int>
    // -> underlying container.
    //
    // greater<int>
    // -> comparison rule.
    //
    // Result:
    //
    // SMALLEST element = HIGHEST PRIORITY = top()
    //
    //
    // IMPORTANT:
    //
    // Even though the underlying container is a vector,
    // std::priority_queue DOES NOT expose the vector's
    // iterators through its public interface.
    //
    // Therefore:
    //
    // pq.begin();              // ❌
    // pq.end();                // ❌
    //
    // and:
    //
    // priority_queue<int>::iterator it;  // ❌
    //
    // are NOT valid.

    // ============================================================
    // CREATING A MIN HEAP
    // ============================================================

    priority_queue<
        int,
        vector<int>,
        greater<int>>
        pq;

    // ============================================================
    // ADDING ELEMENTS
    // ============================================================

    pq.push(40);
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(50);

    // Elements:
    //
    // 40, 10, 30, 20, 50
    //
    // Since this is a MIN HEAP:
    //
    // smallest element = highest priority
    //
    // Therefore:
    //
    // pq.top() = 10

    // ============================================================
    // CAN WE CREATE AN ITERATOR?
    // ============================================================
    //
    // For vector:
    //
    // vector<int> v = {10, 20, 30};
    //
    // auto it = v.begin();      // ✅
    //
    // For deque:
    //
    // deque<int> dq = {10,20,30};
    //
    // auto it = dq.begin();     // ✅
    //
    // For list:
    //
    // list<int> l = {10,20,30};
    //
    // auto it = l.begin();      // ✅
    //
    //
    // But for priority_queue:
    //
    // auto it = pq.begin();     // ❌
    //
    // pq.end();                 // ❌
    //
    // There is NO public iterator interface.

    // ============================================================
    // WHY DOES MIN HEAP NOT HAVE ITERATORS?
    // ============================================================
    //
    // A priority_queue is a CONTAINER ADAPTOR.
    //
    // Its purpose is not general traversal.
    //
    // Its purpose is:
    //
    // 1. Add an element using push()
    // 2. Get the highest-priority element using top()
    // 3. Remove the highest-priority element using pop()
    //
    // For a MIN HEAP:
    //
    // top()
    //   ↓
    // smallest element
    //
    // So the standard interface intentionally does not provide
    // begin() / end().

    // ============================================================
    // WRONG ITERATOR CODE
    // ============================================================

    /*
        This is INVALID:

        auto it = pq.begin();

        while (it != pq.end())
        {
            cout << *it << " ";
            ++it;
        }

        Why?

        Because priority_queue does not provide:
        begin()
        end()
        iterator
    */

    // ============================================================
    // RANDOM ACCESS ALSO NOT AVAILABLE
    // ============================================================
    //
    // These are also invalid:
    //
    // pq[0];        // ❌
    // pq[2];        // ❌
    // pq.at(2);     // ❌
    //
    // You cannot directly access an arbitrary element.
    //
    // Only the highest-priority element is directly accessible:
    //
    // pq.top();

    // ============================================================
    // CORRECT WAY TO PROCESS A MIN HEAP
    // ============================================================
    //
    // Since there are no iterators,
    // we process a min heap using:
    //
    // top()
    // pop()
    //
    // repeatedly.
    //
    // This gives elements in ascending priority order.

    cout << "Min Heap elements: ";

    while (!pq.empty())
    {
        // top() gives the smallest remaining element.

        cout << pq.top() << " ";

        // pop() removes the smallest element.

        pq.pop();
    }

    cout << endl;

    // Output:
    //
    // 10 20 30 40 50

    // ============================================================
    // IMPORTANT:
    // THIS PROCESS DESTROYS THE MIN HEAP
    // ============================================================
    //
    // Every:
    //
    // pq.pop();
    //
    // removes one element.
    //
    // Therefore, after the loop:
    //
    // pq.empty() == true

    // ============================================================
    // PRESERVE ORIGINAL MIN HEAP
    // ============================================================
    //
    // Agar original min heap ko destroy nahi karna hai,
    // to uski COPY bana lo.
    //
    // Then traversal/process copy par perform karo.

    priority_queue<
        int,
        vector<int>,
        greater<int>>
        original;

    original.push(40);
    original.push(10);
    original.push(30);
    original.push(20);
    original.push(50);

    // Create a copy.

    priority_queue<
        int,
        vector<int>,
        greater<int>>
        temp = original;

    // Process COPY.

    cout << "Copied Min Heap: ";

    while (!temp.empty())
    {
        // Smallest element from temp.

        cout << temp.top() << " ";

        // Remove from temp.

        temp.pop();
    }

    cout << endl;

    // ============================================================
    // ORIGINAL MIN HEAP IS STILL AVAILABLE
    // ============================================================

    // temp is now empty.
    //
    // original is still unchanged.
    //
    // original.top() is still:
    //
    // 10

    cout << "Original Min Heap Top: "
         << original.top()
         << endl;

    cout << "Original Min Heap Size: "
         << original.size()
         << endl;

    // ============================================================
    // IMPORTANT:
    // UNDERLYING VECTOR HAS ITERATORS
    // ============================================================
    //
    // You may wonder:
    //
    // "If vector has iterators, why can't I use them
    //  through priority_queue?"
    //
    // Because priority_queue HIDES the underlying container.
    //
    // Conceptually:
    //
    // priority_queue
    //       ↓
    // underlying container
    //       ↓
    // vector
    //
    // vector itself has:
    //
    // begin()
    // end()
    //
    // But priority_queue does not expose them.
    //
    // So:
    //
    // vector<int> v;
    //
    // v.begin();        // ✅
    //
    //
    // priority_queue<int, vector<int>, greater<int>> pq;
    //
    // pq.begin();       // ❌

    // ============================================================
    // MIN HEAP VS VECTOR ITERATORS
    // ============================================================

    /*
        VECTOR
        ------------------------------------------------------------
        vector<int> v = {10,20,30};

        v.begin()       -> ✅
        v.end()         -> ✅
        iterator        -> ✅
        v[2]            -> ✅


        MIN HEAP
        ------------------------------------------------------------
        priority_queue<
            int,
            vector<int>,
            greater<int>
        > pq;

        pq.begin()      -> ❌
        pq.end()        -> ❌
        iterator        -> ❌
        pq[2]           -> ❌
    */

    // ============================================================
    // MIN HEAP IS NOT A SORTED VECTOR
    // ============================================================
    //
    // Another important concept:
    //
    // Do NOT think that the internal vector is simply:
    //
    // 10 20 30 40 50
    //
    // in fully sorted order.
    //
    // A heap only guarantees:
    //
    // smallest element = top()
    //
    // The remaining elements are arranged according to
    // heap rules, not complete sorting.
    //
    // If you do:
    //
    // top()
    // pop()
    //
    // repeatedly,
    //
    // then you get:
    //
    // 10 20 30 40 50
    //
    // in priority order.

    // ============================================================
    // MIN HEAP AND REVERSE ITERATORS
    // ============================================================
    //
    // Since priority_queue itself has no begin()/end(),
    // it also does NOT have:
    //
    // rbegin()
    // rend()
    //
    // So:
    //
    // pq.rbegin();     // ❌
    // pq.rend();       // ❌
    //
    // These are available in containers like vector,
    // deque, and list, but not in std::priority_queue.

    // ============================================================
    // MIN HEAP AND const ITERATORS
    // ============================================================
    //
    // Similarly:
    //
    // pq.cbegin();     // ❌
    // pq.cend();       // ❌
    //
    // because priority_queue does not expose iterator operations.

    // ============================================================
    // MIN HEAP PROCESSING PATTERN
    // ============================================================
    //
    // The most important min-heap processing pattern is:

    priority_queue<
        int,
        vector<int>,
        greater<int>>
        processPQ;

    processPQ.push(100);
    processPQ.push(20);
    processPQ.push(50);
    processPQ.push(10);

    while (!processPQ.empty())
    {
        // --------------------------------------------------------
        // STEP 1:
        // Get the smallest element.
        // --------------------------------------------------------

        int current = processPQ.top();

        // --------------------------------------------------------
        // STEP 2:
        // Process the current element.
        // --------------------------------------------------------

        cout << "Processing: "
             << current
             << endl;

        // --------------------------------------------------------
        // STEP 3:
        // Remove the processed element.
        // --------------------------------------------------------

        processPQ.pop();
    }

    // Processing order:
    //
    // 10
    // 20
    // 50
    // 100

    // ============================================================
    // MIN HEAP OF PAIR AND ITERATORS
    // ============================================================
    //
    // Pair min heap is very common in DSA.
    //
    // Example:
    //
    // priority_queue<
    //     pair<int,int>,
    //     vector<pair<int,int>>,
    //     greater<pair<int,int>>
    // > pq;
    //
    // Still, even though the underlying container is vector:
    //
    // pq.begin();      // ❌
    // pq.end();        // ❌
    //
    // We use:
    //
    // pq.top()
    // pq.pop()

    // ============================================================
    // Dijkstra EXAMPLE IDEA
    // ============================================================
    //
    // A common min-heap in Dijkstra:
    //
    // {distance, node}
    //
    // Declaration:
    //
    // priority_queue<
    //     pair<int,int>,
    //     vector<pair<int,int>>,
    //     greater<pair<int,int>>
    // > pq;
    //
    //
    // Suppose:
    //
    // pq.push({10, 5});
    // pq.push({3, 8});
    // pq.push({7, 2});
    //
    // Then:
    //
    // pq.top()
    //
    // gives:
    //
    // {3,8}
    //
    // because 3 is the smallest distance.
    //
    // Again:
    //
    // no iterator required.
    //
    // Process:
    //
    // auto current = pq.top();
    // pq.pop();

    // ============================================================
    // MIN HEAP VS DEQUE/LIST/VECTOR ITERATORS
    // ============================================================

    /*
        VECTOR
        ------------------------------------------------------------
        begin() / end()        ✅
        random access          ✅
        iterator               ✅


        DEQUE
        ------------------------------------------------------------
        begin() / end()        ✅
        random access          ✅
        iterator               ✅


        LIST
        ------------------------------------------------------------
        begin() / end()        ✅
        random access          ❌
        iterator               ✅


        QUEUE
        ------------------------------------------------------------
        begin() / end()        ❌
        public iterator        ❌


        STACK
        ------------------------------------------------------------
        begin() / end()        ❌
        public iterator        ❌


        PRIORITY_QUEUE
        ------------------------------------------------------------
        begin() / end()        ❌
        public iterator        ❌


        MIN HEAP
        ------------------------------------------------------------
        Min heap is a priority_queue,
        so:

        begin() / end()        ❌
        public iterator        ❌
    */

    // ============================================================
    // WHY TOP() INSTEAD OF ITERATOR?
    // ============================================================
    //
    // The purpose of a min heap is:
    //
    // Keep the SMALLEST element immediately available.
    //
    // Therefore:
    //
    // top()
    //   ↓
    // smallest
    //
    // Then:
    //
    // pop()
    //   ↓
    // remove smallest
    //
    // Then heap automatically reorganizes itself.
    //
    // Again:
    //
    // top()
    //   ↓
    // next smallest
    //
    // This continues until the heap becomes empty.

    // ============================================================
    // COMMON WRONG CODE
    // ============================================================

    /*
        priority_queue<
            int,
            vector<int>,
            greater<int>
        > pq;

        pq.push(10);
        pq.push(20);
        pq.push(30);

        // ❌ WRONG
        for (auto it = pq.begin();
             it != pq.end();
             ++it)
        {
            cout << *it;
        }
    */

    // ============================================================
    // CORRECT CODE
    // ============================================================

    /*
        priority_queue<
            int,
            vector<int>,
            greater<int>
        > pq;

        pq.push(10);
        pq.push(20);
        pq.push(30);

        // ✅ CORRECT
        while (!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
    */

    // ============================================================
    // IMPORTANT SAFETY RULE
    // ============================================================
    //
    // Empty min heap par:
    //
    // pq.top();    // ❌
    // pq.pop();    // ❌
    //
    // Safe:
    //
    // if (!pq.empty())
    // {
    //     cout << pq.top();
    // }
    //
    // Or:
    //
    // while (!pq.empty())
    // {
    //     cout << pq.top();
    //     pq.pop();
    // }

    // ============================================================
    // TIME COMPLEXITY
    // ============================================================
    //
    // Min heap operations:
    //
    // push()
    //     O(log n)
    //
    // pop()
    //     O(log n)
    //
    // top()
    //     O(1)
    //
    // size()
    //     O(1)
    //
    // empty()
    //     O(1)
    //
    //
    // We do NOT use iterators to traverse because priority_queue
    // is designed around priority operations rather than
    // arbitrary traversal.

    // ============================================================
    // FINAL CHEAT SHEET
    // ============================================================

    /*
        MIN HEAP:

        priority_queue<
            int,
            vector<int>,
            greater<int>
        > pq;


        ITERATOR:
        pq.begin();       // ❌
        pq.end();         // ❌
        pq.rbegin();      // ❌
        pq.rend();        // ❌


        RANDOM ACCESS:
        pq[0];            // ❌
        pq.at(0);         // ❌


        ACCESS:
        pq.top();         // ✅
        -> smallest element


        REMOVE:
        pq.pop();         // ✅
        -> removes smallest


        TRAVERSAL:
        while (!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }


        PRESERVE ORIGINAL:
        priority_queue<
            int,
            vector<int>,
            greater<int>
        > temp = pq;

        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
    */

    // ============================================================
    // FINAL MEMORY TRICK
    // ============================================================
    //
    // VECTOR:
    //
    // begin() → iterator
    // end()   → iterator
    //
    //
    // DEQUE:
    //
    // begin() → iterator
    // end()   → iterator
    //
    //
    // LIST:
    //
    // begin() → iterator
    // end()   → iterator
    //
    //
    // MIN HEAP:
    //
    // priority_queue
    //       ↓
    // no public begin()/end()
    //       ↓
    // use top() + pop()
    //
    //
    // MIN HEAP:
    //
    // smallest → top()
    // remove smallest → pop()

    return 0;
}