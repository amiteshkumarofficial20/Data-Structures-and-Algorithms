#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main()
{
    // ============================================================
    // MIN HEAP WITH DIFFERENT DATA TYPES
    // ============================================================
    //
    // A MIN HEAP can be created using priority_queue.
    //
    // Basic syntax:
    //
    // priority_queue<
    //     data_type,
    //     underlying_container,
    //     comparison_function
    // > pq;
    //
    // For a MIN HEAP:
    //
    // priority_queue<
    //     int,
    //     vector<int>,
    //     greater<int>
    // > pq;
    //
    // Meaning:
    //
    // data_type
    //      ↓
    // Type of element stored in priority queue.
    //
    // vector<int>
    //      ↓
    // Underlying container.
    //
    // greater<int>
    //      ↓
    // Comparison rule that makes the SMALLEST
    // element the highest priority.
    //
    // Therefore:
    //
    // MIN HEAP:
    //
    // smallest value = highest priority = top()

    // ============================================================
    // 1. MIN HEAP OF int
    // ============================================================
    //
    // int stores integer values.
    //
    // Examples:
    //
    // 10, 20, 30, 40, 50
    //
    // This is the most common min-heap used in DSA.

    priority_queue<
        int,
        vector<int>,
        greater<int>>
        intMinHeap;

    // Add elements.

    intMinHeap.push(40);
    intMinHeap.push(10);
    intMinHeap.push(30);
    intMinHeap.push(20);
    intMinHeap.push(50);

    // Values:
    //
    // 40, 10, 30, 20, 50
    //
    // Smallest = 10
    //
    // Therefore:
    //
    // intMinHeap.top() = 10

    cout << "Min Heap of int - Top: "
         << intMinHeap.top()
         << endl;

    // ============================================================
    // PROCESS int MIN HEAP
    // ============================================================
    //
    // top() gives the smallest remaining value.
    //
    // pop() removes that smallest value.
    //
    // So repeated:
    //
    // top()
    // pop()
    //
    // gives values in ascending priority order.

    cout << "int Min Heap priority order: ";

    while (!intMinHeap.empty())
    {
        cout << intMinHeap.top() << " ";

        intMinHeap.pop();
    }

    cout << endl;

    // Output:
    //
    // 10 20 30 40 50

    // ============================================================
    // 2. MIN HEAP OF float
    // ============================================================
    //
    // float stores decimal values.
    //
    // Smallest float value gets the highest priority.

    priority_queue<
        float,
        vector<float>,
        greater<float>>
        floatMinHeap;

    floatMinHeap.push(30.5f);
    floatMinHeap.push(10.25f);
    floatMinHeap.push(20.75f);
    floatMinHeap.push(5.5f);

    // Smallest:
    //
    // 5.5
    //
    // So top() = 5.5

    cout << "Min Heap of float - Top: "
         << floatMinHeap.top()
         << endl;

    // Process float min heap.

    cout << "float Min Heap priority order: ";

    while (!floatMinHeap.empty())
    {
        cout << floatMinHeap.top() << " ";

        floatMinHeap.pop();
    }

    cout << endl;

    // ============================================================
    // 3. MIN HEAP OF double
    // ============================================================
    //
    // double stores decimal values with generally
    // more precision than float.

    priority_queue<
        double,
        vector<double>,
        greater<double>>
        doubleMinHeap;

    doubleMinHeap.push(3.14159);
    doubleMinHeap.push(1.41421);
    doubleMinHeap.push(2.71828);
    doubleMinHeap.push(0.57721);

    // Smallest:
    //
    // 0.57721

    cout << "Min Heap of double - Top: "
         << doubleMinHeap.top()
         << endl;

    // ============================================================
    // 4. MIN HEAP OF char
    // ============================================================
    //
    // char stores one character.
    //
    // Characters are compared according to their character
    // ordering.
    //
    // With greater<char>:
    //
    // smallest character according to the ordering
    // gets the highest priority.

    priority_queue<
        char,
        vector<char>,
        greater<char>>
        charMinHeap;

    charMinHeap.push('Z');
    charMinHeap.push('A');
    charMinHeap.push('M');
    charMinHeap.push('B');

    // Smallest according to character ordering:
    //
    // 'A'
    //
    // Therefore:
    //
    // charMinHeap.top() = 'A'

    cout << "Min Heap of char - Top: "
         << charMinHeap.top()
         << endl;

    // ============================================================
    // PROCESS CHAR MIN HEAP
    // ============================================================

    cout << "char Min Heap priority order: ";

    while (!charMinHeap.empty())
    {
        cout << charMinHeap.top() << " ";

        charMinHeap.pop();
    }

    cout << endl;

    // Output:
    //
    // A B M Z

    // ============================================================
    // 5. MIN HEAP OF long long
    // ============================================================
    //
    // long long large integer values ke liye useful hai.
    //
    // DSA mein large distances, costs, sums, etc. ke liye
    // commonly use hota hai.

    priority_queue<
        long long,
        vector<long long>,
        greater<long long>>
        longLongMinHeap;

    longLongMinHeap.push(50000000000LL);
    longLongMinHeap.push(10000000000LL);
    longLongMinHeap.push(30000000000LL);
    longLongMinHeap.push(20000000000LL);

    // Smallest:
    //
    // 10000000000

    cout << "Min Heap of long long - Top: "
         << longLongMinHeap.top()
         << endl;

    // ============================================================
    // 6. MIN HEAP OF string
    // ============================================================
    //
    // string ko bhi priority queue mein store kar sakte hain.
    //
    // greater<string> use karne par smallest string
    // according to lexicographical ordering gets highest priority.
    //
    // Example:
    //
    // "Aman"
    // "Rahul"
    // "Priya"
    // "Zoya"
    //
    // "Aman" comes first lexicographically.

    priority_queue<
        string,
        vector<string>,
        greater<string>>
        stringMinHeap;

    stringMinHeap.push("Rahul");
    stringMinHeap.push("Aman");
    stringMinHeap.push("Zoya");
    stringMinHeap.push("Priya");

    // Smallest lexicographically:
    //
    // "Aman"

    cout << "Min Heap of string - Top: "
         << stringMinHeap.top()
         << endl;

    // ============================================================
    // PROCESS STRING MIN HEAP
    // ============================================================

    cout << "string Min Heap priority order: ";

    while (!stringMinHeap.empty())
    {
        cout << stringMinHeap.top() << " ";

        stringMinHeap.pop();
    }

    cout << endl;

    // Output:
    //
    // Aman Priya Rahul Zoya

    // ============================================================
    // 7. MIN HEAP OF pair<int, int>
    // ============================================================
    //
    // This is VERY IMPORTANT in DSA.
    //
    // We can create:
    //
    // priority_queue<
    //     pair<int,int>,
    //     vector<pair<int,int>>,
    //     greater<pair<int,int>>
    // >
    //
    // pair<int,int> contains:
    //
    // first
    // second
    //
    // The default pair comparison is lexicographical:
    //
    // 1. first compare hota hai.
    // 2. Agar first equal ho, then second compare hota hai.
    //
    // With greater<pair<int,int>>:
    //
    // smallest pair gets highest priority.

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pairMinHeap;

    // Insert pairs:
    //
    // {distance, node}

    pairMinHeap.push({10, 5});
    pairMinHeap.push({3, 8});
    pairMinHeap.push({7, 2});
    pairMinHeap.push({1, 9});
    pairMinHeap.push({3, 4});

    // Compare first values:
    //
    // {1,9}
    // {3,8}
    // {3,4}
    // {7,2}
    // {10,5}
    //
    // Since {1,9} has the smallest first value,
    // it gets the highest priority.
    //
    // Therefore:
    //
    // pairMinHeap.top() = {1,9}

    cout << "Min Heap of pair - Top: {"
         << pairMinHeap.top().first
         << ", "
         << pairMinHeap.top().second
         << "}"
         << endl;

    // ============================================================
    // PROCESS PAIR MIN HEAP
    // ============================================================

    cout << "pair Min Heap priority order: ";

    while (!pairMinHeap.empty())
    {
        cout << "{"
             << pairMinHeap.top().first
             << ","
             << pairMinHeap.top().second
             << "} ";

        pairMinHeap.pop();
    }

    cout << endl;

    // ============================================================
    // IMPORTANT PAIR EXAMPLE
    // ============================================================
    //
    // Suppose:
    //
    // {3, 100}
    // {3, 20}
    //
    // Both first values are 3.
    //
    // Then second values compare honge:
    //
    // 20 < 100
    //
    // Therefore:
    //
    // {3,20}
    //
    // gets higher priority in a min heap.
    //
    // This is useful when using:
    //
    // {distance, node}
    //
    // in graph algorithms.

    // ============================================================
    // 8. MIN HEAP OF vector<int>
    // ============================================================
    //
    // priority_queue ka element type vector<int> bhi
    // ho sakta hai, because vector<int> supports comparison.
    //
    // Example:
    //
    // priority_queue<
    //     vector<int>,
    //     vector<vector<int>>,
    //     greater<vector<int>>
    // >
    //
    // Here:
    //
    // First vector compare hota hai,
    // then lexicographical ordering use hoti hai.

    priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>>
        vectorMinHeap;

    vectorMinHeap.push({3, 10});
    vectorMinHeap.push({1, 20});
    vectorMinHeap.push({2, 30});
    vectorMinHeap.push({1, 10});

    // Compare lexicographically:
    //
    // {1,10}
    // {1,20}
    // {2,30}
    // {3,10}
    //
    // Therefore:
    //
    // top() = {1,10}

    cout << "Min Heap of vector - Top: [ ";

    for (int x : vectorMinHeap.top())
    {
        cout << x << " ";
    }

    cout << "]" << endl;

    // ============================================================
    // 9. MIN HEAP OF bool
    // ============================================================
    //
    // bool contains:
    //
    // false
    // true
    //
    // false is smaller than true according to bool ordering.
    //
    // Therefore in a min heap:
    //
    // false = higher priority.

    priority_queue<
        bool,
        vector<bool>,
        greater<bool>>
        boolMinHeap;

    boolMinHeap.push(true);
    boolMinHeap.push(false);
    boolMinHeap.push(true);

    cout << boolalpha;

    cout << "Min Heap of bool - Top: "
         << boolMinHeap.top()
         << endl;

    cout << noboolalpha;

    // ============================================================
    // 10. MIN HEAP OF custom STRUCT
    // ============================================================
    //
    // For a custom structure, C++ does not automatically know
    // how you want to define the priority.
    //
    // So we create a CUSTOM COMPARATOR.
    //
    // Example:
    //
    // Student has:
    //
    // name
    // marks
    //
    // We want:
    //
    // LOWEST marks = HIGHEST PRIORITY
    //
    // So we create a comparator accordingly.

    struct Student
    {
        string name;
        int marks;
    };

    // ============================================================
    // CUSTOM COMPARATOR FOR MIN HEAP
    // ============================================================

    struct CompareStudent
    {
        bool operator()(const Student &a,
                        const Student &b) const
        {
            // We want the student with SMALLER marks
            // to have HIGHER priority.
            //
            // Example:
            //
            // a.marks = 50
            // b.marks = 70
            //
            // 50 should come before 70.
            //
            // Therefore:
            //
            // return a.marks > b.marks;

            return a.marks > b.marks;
        }
    };

    // ============================================================
    // MIN HEAP OF STUDENT
    // ============================================================

    priority_queue<
        Student,
        vector<Student>,
        CompareStudent>
        studentMinHeap;

    studentMinHeap.push({"Rahul", 80});
    studentMinHeap.push({"Aman", 60});
    studentMinHeap.push({"Priya", 90});
    studentMinHeap.push({"Riya", 50});

    // Lowest marks:
    //
    // Riya = 50
    //
    // Therefore Riya should be at top.

    cout << "Min Heap of Student - Top: "
         << studentMinHeap.top().name
         << " "
         << studentMinHeap.top().marks
         << endl;

    // ============================================================
    // PROCESS CUSTOM STRUCT MIN HEAP
    // ============================================================

    cout << "Students by lowest marks first:" << endl;

    while (!studentMinHeap.empty())
    {
        cout << studentMinHeap.top().name
             << " -> "
             << studentMinHeap.top().marks
             << endl;

        studentMinHeap.pop();
    }

    // ============================================================
    // MIN HEAP AND DSA
    // ============================================================
    //
    // Min heaps are EXTREMELY IMPORTANT in DSA.
    //
    // Common uses:
    //
    // 1. Dijkstra's Algorithm
    // 2. Prim's Algorithm
    // 3. Huffman Coding
    // 4. Kth smallest element
    // 5. Top K problems
    // 6. Scheduling
    // 7. Merge K sorted arrays
    // 8. Merge K sorted linked lists
    // 9. Greedy algorithms
    //
    // Especially important:
    //
    // priority_queue<
    //     pair<int,int>,
    //     vector<pair<int,int>>,
    //     greater<pair<int,int>>
    // >
    //
    // Used commonly as:
    //
    // {distance, node}

    // ============================================================
    // MIN HEAP IN DIJKSTRA
    // ============================================================
    //
    // Dijkstra mein hume:
    //
    // smallest distance
    //
    // wala node pehle process karna hota hai.
    //
    // Therefore:
    //
    // priority_queue<
    //     pair<int,int>,
    //     vector<pair<int,int>>,
    //     greater<pair<int,int>>
    // > pq;
    //
    // Then:
    //
    // pq.push({0, source});
    //
    // top() gives:
    //
    // smallest distance pair.

    // ============================================================
    // IMPORTANT:
    // MIN HEAP IS NOT A FULLY SORTED CONTAINER
    // ============================================================
    //
    // Suppose:
    //
    // 40, 10, 30, 20
    //
    // are inserted.
    //
    // It is WRONG to assume the internal container is:
    //
    // 10, 20, 30, 40
    //
    // The heap only guarantees that:
    //
    // smallest element = top()
    //
    // If we repeatedly call:
    //
    // top()
    // pop()
    //
    // then we get:
    //
    // 10, 20, 30, 40
    //
    // in priority order.

    // ============================================================
    // MIN HEAP OPERATIONS
    // ============================================================
    //
    // push()
    // ------------------------------------------------------------
    // Adds an element.
    //
    // Time: O(log n)
    //
    //
    // top()
    // ------------------------------------------------------------
    // Returns smallest element.
    //
    // Time: O(1)
    //
    //
    // pop()
    // ------------------------------------------------------------
    // Removes smallest element.
    //
    // Time: O(log n)
    //
    //
    // size()
    // ------------------------------------------------------------
    // Number of elements.
    //
    // Time: O(1)
    //
    //
    // empty()
    // ------------------------------------------------------------
    // Checks whether heap is empty.
    //
    // Time: O(1)

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
    // ITERATORS ON MIN HEAP
    // ============================================================
    //
    // Min heap is still a priority_queue.
    //
    // Therefore:
    //
    // pq.begin();   // ❌
    // pq.end();     // ❌
    //
    // Public iterators available nahi hote.
    //
    // Similarly:
    //
    // pq[2];        // ❌
    // pq.at(2);     // ❌
    //
    // Directly only:
    //
    // pq.top()
    //
    // accessible hai.

    // ============================================================
    // MAX HEAP VS MIN HEAP WITH DIFFERENT DATA TYPES
    // ============================================================
    //
    // MAX HEAP:
    //
    // priority_queue<int>
    //
    // largest -> top
    //
    //
    // MIN HEAP:
    //
    // priority_queue<
    //     int,
    //     vector<int>,
    //     greater<int>
    // >
    //
    // smallest -> top
    //
    //
    // Same concept other types ke saath:
    //
    // priority_queue<
    //     double,
    //     vector<double>,
    //     greater<double>
    // >
    //
    // priority_queue<
    //     string,
    //     vector<string>,
    //     greater<string>
    // >
    //
    // priority_queue<
    //     long long,
    //     vector<long long>,
    //     greater<long long>
    // >

    // ============================================================
    // FINAL CHEAT SHEET
    // ============================================================

    /*
        MIN HEAP OF int
        ------------------------------------------------------------
        priority_queue<
            int,
            vector<int>,
            greater<int>
        > pq;


        MIN HEAP OF float
        ------------------------------------------------------------
        priority_queue<
            float,
            vector<float>,
            greater<float>
        > pq;


        MIN HEAP OF double
        ------------------------------------------------------------
        priority_queue<
            double,
            vector<double>,
            greater<double>
        > pq;


        MIN HEAP OF string
        ------------------------------------------------------------
        priority_queue<
            string,
            vector<string>,
            greater<string>
        > pq;


        MIN HEAP OF long long
        ------------------------------------------------------------
        priority_queue<
            long long,
            vector<long long>,
            greater<long long>
        > pq;


        MIN HEAP OF pair
        ------------------------------------------------------------
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;


        MIN HEAP OF CUSTOM STRUCT
        ------------------------------------------------------------
        priority_queue<
            Student,
            vector<Student>,
            CompareStudent
        > pq;
    */

    // ============================================================
    // FINAL MEMORY TRICK
    // ============================================================
    //
    // MIN HEAP:
    //
    // smallest element
    //        ↓
    //    highest priority
    //        ↓
    //      top()
    //
    //
    // General syntax:
    //
    // priority_queue<
    //     T,
    //     vector<T>,
    //     greater<T>
    // >
    //
    // where:
    //
    // T = data type
    //
    //
    // Examples:
    //
    // int
    // float
    // double
    // char
    // bool
    // string
    // long long
    // pair
    // vector
    // custom struct
    //
    //
    // MOST IMPORTANT DSA MIN HEAP:
    //
    // priority_queue<
    //     pair<int,int>,
    //     vector<pair<int,int>>,
    //     greater<pair<int,int>>
    // >
    //
    // Often used for:
    //
    // {distance, node}
    //
    // in Dijkstra and related problems.

    return 0;
}