#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main()
{
    // ============================================================
    // MIN HEAP USING priority_queue
    // ============================================================
    //
    // Normally:
    //
    // priority_queue<int> pq;
    //
    // creates a MAX-HEAP.
    //
    // MAX-HEAP:
    //
    // Largest value = Highest Priority = top()
    //
    //
    // But many DSA problems need:
    //
    // Smallest value = Highest Priority
    //
    // For this we use a MIN-HEAP.
    //
    // Syntax:
    //
    // priority_queue<
    //     int,
    //     vector<int>,
    //     greater<int>
    // > pq;
    //
    //
    // Is syntax ko properly samajhna bahut important hai.

    // ============================================================
    // MIN HEAP SYNTAX BREAKDOWN
    // ============================================================
    //
    // priority_queue<int, vector<int>, greater<int>> pq;
    //
    // Iske 3 important parts hain:
    //
    // ------------------------------------------------------------
    // PART 1:
    // int
    // ------------------------------------------------------------
    //
    // Ye batata hai ki priority queue ke andar
    // kaunsa data type store hoga.
    //
    // Yahan:
    //
    // int
    //
    // isliye queue integer values store karegi.
    //
    //
    // ------------------------------------------------------------
    // PART 2:
    // vector<int>
    // ------------------------------------------------------------
    //
    // Ye underlying container hai.
    //
    // priority_queue internally ek container ka use karti hai
    // elements ko manage karne ke liye.
    //
    // Default underlying container commonly vector hota hai.
    //
    //
    // ------------------------------------------------------------
    // PART 3:
    // greater<int>
    // ------------------------------------------------------------
    //
    // Ye comparison rule define karta hai.
    //
    // greater<int> use karne se:
    //
    // SMALLER value = HIGHER PRIORITY
    //
    // Therefore:
    //
    // MIN-HEAP
    //
    //
    // Final meaning:
    //
    // priority_queue<
    //     int,             // element type
    //     vector<int>,     // underlying container
    //     greater<int>     // comparison
    // >
    //
    // = MIN HEAP

    // ============================================================
    // CREATING MIN HEAP
    // ============================================================

    priority_queue<int, vector<int>, greater<int>> pq;

    // ============================================================
    // PUSHING ELEMENTS
    // ============================================================
    //
    // push() priority queue mein element add karta hai.
    //
    // MIN-HEAP mein:
    //
    // smallest element ko highest priority milegi.
    //
    // IMPORTANT:
    //
    // Elements internally fully sorted array ki tarah stored
    // nahi hote.
    //
    // Heap structure maintain hota hai.
    //
    // Sirf ye guarantee hai:
    //
    // pq.top()
    //
    // hamesha SMALLEST element dega.

    pq.push(40);

    // Current values:
    //
    // [40]
    //
    // top() = 40

    pq.push(10);

    // Ab:
    //
    // 10 is smaller than 40.
    //
    // Therefore:
    //
    // top() = 10

    pq.push(30);

    // Values:
    //
    // 10, 40, 30
    //
    // Smallest = 10
    //
    // top() = 10

    pq.push(20);

    // Values:
    //
    // 10, 20, 30, 40
    //
    // Smallest = 10

    pq.push(50);

    // Values:
    //
    // 10, 20, 30, 40, 50
    //
    // Smallest = 10

    // ============================================================
    // TOP
    // ============================================================
    //
    // top() highest-priority element deta hai.
    //
    // MIN-HEAP mein:
    //
    // smallest element = highest priority.
    //
    // Therefore:
    //
    // pq.top() = 10

    cout << "Top Element of Min Heap: "
         << pq.top()
         << endl;

    // ============================================================
    // SIZE
    // ============================================================
    //
    // size() number of elements batata hai.
    //
    // Current:
    //
    // 10, 20, 30, 40, 50
    //
    // Total = 5

    cout << "Size of Min Heap: "
         << pq.size()
         << endl;

    // ============================================================
    // POP
    // ============================================================
    //
    // pop() HIGHEST-PRIORITY element remove karta hai.
    //
    // MIN-HEAP mein highest priority = smallest value.
    //
    // Current:
    //
    // top() = 10
    //
    // Therefore:
    //
    // pq.pop();
    //
    // 10 remove karega.

    pq.pop();

    // ============================================================
    // TOP AFTER FIRST POP
    // ============================================================
    //
    // Remaining:
    //
    // 20, 30, 40, 50
    //
    // Smallest = 20
    //
    // Therefore:
    //
    // pq.top() = 20

    cout << "Top after first pop: "
         << pq.top()
         << endl;

    // ============================================================
    // SIZE AFTER FIRST POP
    // ============================================================

    // Before:
    //
    // size = 5
    //
    // After removing one element:
    //
    // size = 4

    cout << "Size after first pop: "
         << pq.size()
         << endl;

    // ============================================================
    // SECOND POP
    // ============================================================
    //
    // Current top = 20.
    //
    // So 20 will be removed.

    pq.pop();

    // Remaining:
    //
    // 30, 40, 50
    //
    // top = 30

    cout << "Top after second pop: "
         << pq.top()
         << endl;

    cout << "Size after second pop: "
         << pq.size()
         << endl;

    // ============================================================
    // THIRD POP
    // ============================================================
    //
    // Current top = 30.
    //
    // Remove 30.

    pq.pop();

    // Remaining:
    //
    // 40, 50
    //
    // top = 40

    cout << "Top after third pop: "
         << pq.top()
         << endl;

    // ============================================================
    // EMPTY CHECK
    // ============================================================
    //
    // empty() checks whether priority queue contains
    // zero elements.
    //
    // Current:
    //
    // 40, 50
    //
    // So queue is NOT empty.

    if (pq.empty())
    {
        cout << "Min Heap is Empty"
             << endl;
    }
    else
    {
        cout << "Min Heap is Not Empty"
             << endl;
    }

    // ============================================================
    // PROCESSING COMPLETE MIN HEAP
    // ============================================================
    //
    // Agar hum saare elements ko priority order mein
    // process karna chahte hain:
    //
    // top()
    // pop()
    //
    // repeatedly use karte hain.
    //
    // Current:
    //
    // 40, 50
    //
    // Processing order:
    //
    // 40 -> 50

    cout << "Remaining elements in priority order: ";

    while (!pq.empty())
    {
        // Smallest remaining element.

        cout << pq.top() << " ";

        // Remove it.

        pq.pop();
    }

    cout << endl;

    // ============================================================
    // VERY IMPORTANT:
    // MIN HEAP PROCESSING ORDER
    // ============================================================
    //
    // Suppose we insert:
    //
    // 50
    // 10
    // 40
    // 20
    // 30
    //
    // Then repeated:
    //
    // top()
    // pop()
    //
    // will produce:
    //
    // 10
    // 20
    // 30
    // 40
    // 50
    //
    // Because every time the SMALLEST element is selected.

    // ============================================================
    // MAX HEAP VS MIN HEAP
    // ============================================================
    //
    // MAX HEAP:
    //
    // priority_queue<int> pq;
    //
    // Largest value = highest priority.
    //
    // Example:
    //
    // Values:
    // 10, 50, 20, 30
    //
    // top() = 50
    //
    //
    // MIN HEAP:
    //
    // priority_queue<int, vector<int>, greater<int>> pq;
    //
    // Smallest value = highest priority.
    //
    // Example:
    //
    // Values:
    // 10, 50, 20, 30
    //
    // top() = 10

    // ============================================================
    // COMPLETE VISUAL UNDERSTANDING
    // ============================================================

    /*
        Insert:

        40
        10
        30
        20
        50


        MIN HEAP ka important property:

        smallest value TOP par hoti hai.


               TOP
                ↓
               [10]
               [20]
               [30]
               [40]
               [50]

        NOTE:
        Ye sirf conceptual priority order hai.
        Actual heap memory arrangement necessarily
        fully sorted nahi hota.


        pop():

        10 removed.


               TOP
                ↓
               [20]
               [30]
               [40]
               [50]


        pop():

        20 removed.


               TOP
                ↓
               [30]
               [40]
               [50]


        pop():

        30 removed.


               TOP
                ↓
               [40]
               [50]
    */

    // ============================================================
    // IMPORTANT: pop() VALUE RETURN NAHI KARTA
    // ============================================================
    //
    // Wrong:
    //
    // int x = pq.pop();
    //
    // ❌ Invalid
    //
    // Correct:
    //
    // int x = pq.top();
    // pq.pop();
    //
    // Step 1:
    // smallest element read karo.
    //
    // Step 2:
    // usko remove karo.

    // ============================================================
    // IMPORTANT: EMPTY MIN HEAP PAR top()/pop()
    // ============================================================
    //
    // Wrong:
    //
    // priority_queue<int, vector<int>, greater<int>> pq;
    //
    // pq.top();   // ❌
    // pq.pop();   // ❌
    //
    // Pehle:
    //
    // if (!pq.empty())
    // {
    //     cout << pq.top();
    // }
    //
    // check karo.

    // ============================================================
    // MIN HEAP WITHOUT USING greater<int>
    // ============================================================
    //
    // Custom comparator bhi banaya ja sakta hai.
    //
    // Example:
    //
    // struct Compare
    // {
    //     bool operator()(int a, int b)
    //     {
    //         return a > b;
    //     }
    // };
    //
    // priority_queue<int, vector<int>, Compare> pq;
    //
    // Ye bhi min heap banayega.
    //
    // Lekin basic DSA ke liye:
    //
    // greater<int>
    //
    // easiest hai.

    // ============================================================
    // MIN HEAP WITH long long
    // ============================================================
    //
    // Agar large integer values hain:
    //
    // priority_queue<
    //     long long,
    //     vector<long long>,
    //     greater<long long>
    // > pq;
    //
    // Example:
    //
    // smallest long long value top par hogi.

    // ============================================================
    // MIN HEAP WITH pair<int,int>
    // ============================================================
    //
    // Ye DSA mein EXTREMELY IMPORTANT hai.
    //
    // Syntax:
    //
    // priority_queue<
    //     pair<int,int>,
    //     vector<pair<int,int>>,
    //     greater<pair<int,int>>
    // > pq;
    //
    // Isme pairs ko ascending lexicographical order mein
    // priority milti hai.
    //
    // Example:
    //
    // {10, 5}
    // {3, 8}
    // {7, 2}
    // {1, 9}
    //
    // Smallest pair:
    //
    // {1,9}
    //
    // top() = {1,9}

    // ============================================================
    // PAIR MIN HEAP EXAMPLE
    // ============================================================

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pairPQ;

    // Add:
    //
    // {distance, node}

    pairPQ.push({10, 5});
    pairPQ.push({3, 8});
    pairPQ.push({7, 2});
    pairPQ.push({1, 9});

    // Smallest first element has highest priority.
    //
    // Therefore:
    //
    // {1,9} -> TOP

    cout << "Top pair: {"
         << pairPQ.top().first
         << ", "
         << pairPQ.top().second
         << "}"
         << endl;

    // ============================================================
    // PROCESS PAIR MIN HEAP
    // ============================================================
    //
    // Priority order:
    //
    // {1,9}
    // {3,8}
    // {7,2}
    // {10,5}

    cout << "Pair min-heap priority order: ";

    while (!pairPQ.empty())
    {
        cout << "{"
             << pairPQ.top().first
             << ","
             << pairPQ.top().second
             << "} ";

        pairPQ.pop();
    }

    cout << endl;

    // ============================================================
    // MIN HEAP + Dijkstra
    // ============================================================
    //
    // Graph algorithms mein min heap ka bahut important use hai.
    //
    // Dijkstra algorithm mein commonly:
    //
    // {distance, node}
    //
    // store karte hain.
    //
    // Hume smallest distance wala node pehle chahiye.
    //
    // Isliye:
    //
    // priority_queue<
    //     pair<int,int>,
    //     vector<pair<int,int>>,
    //     greater<pair<int,int>>
    // > pq;
    //
    //
    // Example:
    //
    // pq.push({0, source});
    //
    // Then:
    //
    // auto current = pq.top();
    // pq.pop();
    //
    // current.first  -> distance
    // current.second -> node
    //
    // smallest distance first process hota hai.

    // ============================================================
    // MIN HEAP + custom data
    // ============================================================
    //
    // Custom struct ke saath bhi min heap bana sakte hain,
    // but uske liye comparator define karna padta hai.
    //
    // Example idea:
    //
    // struct Student
    // {
    //     string name;
    //     int marks;
    // };
    //
    // Agar hume LOWEST marks ko highest priority dena hai,
    // to comparator accordingly define karenge.

    // ============================================================
    // ITERATORS ON MIN HEAP
    // ============================================================
    //
    // Important:
    //
    // Min heap bhi priority_queue hi hai.
    //
    // Therefore:
    //
    // pq.begin();   // ❌
    // pq.end();     // ❌
    //
    // Public iterators available nahi hote.
    //
    // Processing:
    //
    // while (!pq.empty())
    // {
    //     cout << pq.top();
    //     pq.pop();
    // }

    // ============================================================
    // RANDOM ACCESS
    // ============================================================
    //
    // Min heap mein:
    //
    // pq[2]       // ❌
    // pq.at(2)    // ❌
    //
    // Direct random access nahi hota.
    //
    // Only highest-priority element:
    //
    // pq.top()
    //
    // directly accessible hai.

    // ============================================================
    // SWAP IN MIN HEAP
    // ============================================================
    //
    // Do compatible min heaps ko swap kar sakte hain.
    //
    // Example:
    //
    // minPQ1.swap(minPQ2);
    //
    // Complete contents exchange hote hain.

    // ============================================================
    // TIME COMPLEXITY
    // ============================================================
    //
    // MIN HEAP ke standard operations:
    //
    // push()
    //     -> O(log n)
    //
    // pop()
    //     -> O(log n)
    //
    // top()
    //     -> O(1)
    //
    // size()
    //     -> O(1)
    //
    // empty()
    //     -> O(1)
    //
    // Why push/pop O(log n)?
    //
    // Because heap structure ko maintain karne ke liye
    // element ko upar ya neeche move karna pad sakta hai.

    // ============================================================
    // MIN HEAP VS SORTING
    // ============================================================
    //
    // Important:
    //
    // Min heap ka matlab ye nahi hai ki underlying container
    // permanently sorted hai.
    //
    // Guarantee:
    //
    // smallest element = top
    //
    // Agar repeatedly:
    //
    // top()
    // pop()
    //
    // karoge, tab ascending priority order milega.

    // ============================================================
    // MIN HEAP VS MAX HEAP
    // ============================================================

    /*
        MAX HEAP:

        priority_queue<int> pq;

        Values:
        10, 50, 30, 20

        top() = 50

        Processing:
        50 30 20 10


        MIN HEAP:

        priority_queue<int,
                       vector<int>,
                       greater<int>> pq;

        Values:
        10, 50, 30, 20

        top() = 10

        Processing:
        10 20 30 50
    */

    // ============================================================
    // FINAL CHEAT SHEET
    // ============================================================

    /*
        MIN HEAP:

        priority_queue<int,
                       vector<int>,
                       greater<int>> pq;


        PUSH:

        pq.push(10);


        TOP:

        pq.top();


        POP:

        pq.pop();


        SIZE:

        pq.size();


        EMPTY:

        pq.empty();


        PAIR MIN HEAP:

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;


        IMPORTANT:

        smallest value = highest priority
        pq.top()        = smallest element
    */

    // ============================================================
    // FINAL MEMORY TRICK
    // ============================================================
    //
    // MAX HEAP:
    //
    // largest → top
    //
    // priority_queue<int>
    //
    //
    // MIN HEAP:
    //
    // smallest → top
    //
    // priority_queue<
    //     int,
    //     vector<int>,
    //     greater<int>
    // >
    //
    //
    // DSA mein:
    //
    // MIN HEAP
    //    ↓
    // smallest element first
    //    ↓
    // Dijkstra
    //    ↓
    // Prim
    //    ↓
    // K-th smallest / Top K variations
    //    ↓
    // scheduling / greedy problems

    return 0;
}