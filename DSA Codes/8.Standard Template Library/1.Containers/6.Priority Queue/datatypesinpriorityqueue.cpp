#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    // ============================================================
    // PRIORITY QUEUE WITH DIFFERENT DATA TYPES
    // ============================================================
    //
    // priority_queue is an STL CONTAINER ADAPTOR.
    //
    // General syntax:
    //
    // priority_queue<data_type> pq;
    //
    // priority_queue ka main concept:
    //
    // HIGHEST PRIORITY ELEMENT is always available at top().
    //
    // By default:
    //
    // priority_queue<int>
    //
    // is a MAX-HEAP.
    //
    // Therefore:
    //
    // LARGEST value
    //      ↓
    // HIGHEST PRIORITY
    //      ↓
    // top()
    //
    // A priority_queue can store many different data types:
    //
    // priority_queue<int>
    // priority_queue<float>
    // priority_queue<double>
    // priority_queue<char>
    // priority_queue<bool>
    // priority_queue<string>
    // priority_queue<long long>
    // priority_queue<pair<int,int>>
    // priority_queue<vector<int>>
    // priority_queue<custom_struct>
    //
    // Basic idea:
    //
    // priority_queue<T>
    //              ↑
    //         element type

    // ============================================================
    // 1. priority_queue<int>
    // ============================================================
    //
    // int integer values store karta hai.
    //
    // Default priority_queue<int> = MAX-HEAP.
    //
    // Largest value = highest priority.

    priority_queue<int> intPQ;

    intPQ.push(10);
    intPQ.push(40);
    intPQ.push(20);
    intPQ.push(50);
    intPQ.push(30);

    // Values:
    //
    // 10, 40, 20, 50, 30
    //
    // Largest = 50
    //
    // Therefore:
    //
    // intPQ.top() = 50

    cout << "priority_queue<int> top: "
         << intPQ.top()
         << endl;

    cout << "priority_queue<int> size: "
         << intPQ.size()
         << endl;

    // ============================================================
    // PROCESSING int PRIORITY QUEUE
    // ============================================================
    //
    // top() highest-priority element deta hai.
    //
    // pop() highest-priority element ko remove karta hai.
    //
    // Current priority order:
    //
    // 50 -> 40 -> 30 -> 20 -> 10

    cout << "int priority order: ";

    while (!intPQ.empty())
    {
        cout << intPQ.top() << " ";

        intPQ.pop();
    }

    cout << endl;

    // ============================================================
    // 2. priority_queue<float>
    // ============================================================
    //
    // float decimal values store karta hai.
    //
    // Default ordering:
    //
    // largest float = highest priority.

    priority_queue<float> floatPQ;

    floatPQ.push(10.5f);
    floatPQ.push(50.25f);
    floatPQ.push(20.75f);
    floatPQ.push(30.50f);

    // Largest:
    //
    // 50.25
    //
    // So top() = 50.25

    cout << "priority_queue<float> top: "
         << floatPQ.top()
         << endl;

    // Process float priority queue.

    cout << "float priority order: ";

    while (!floatPQ.empty())
    {
        cout << floatPQ.top() << " ";

        floatPQ.pop();
    }

    cout << endl;

    // ============================================================
    // 3. priority_queue<double>
    // ============================================================
    //
    // double bhi decimal values ke liye use hota hai.
    //
    // Generally double float se higher precision provide karta hai.

    priority_queue<double> doublePQ;

    doublePQ.push(3.14159);
    doublePQ.push(99.9999);
    doublePQ.push(2.71828);
    doublePQ.push(50.1234);

    // Highest value:
    //
    // 99.9999

    cout << "priority_queue<double> top: "
         << doublePQ.top()
         << endl;

    // ============================================================
    // 4. priority_queue<char>
    // ============================================================
    //
    // char ek character store karta hai.
    //
    // Character values:
    //
    // 'A'
    // 'B'
    // 'Z'
    //
    // Characters ke beech comparison hota hai.
    //
    // Default priority_queue mein greater character
    // higher priority deta hai according to the ordering rules
    // for char.

    priority_queue<char> charPQ;

    charPQ.push('A');
    charPQ.push('Z');
    charPQ.push('M');
    charPQ.push('B');

    // Top = 'Z'

    cout << "priority_queue<char> top: "
         << charPQ.top()
         << endl;

    // ============================================================
    // 5. priority_queue<bool>
    // ============================================================
    //
    // bool:
    //
    // true
    // false
    //
    // Default ordering mein true ko false se higher maana jayega.

    priority_queue<bool> boolPQ;

    boolPQ.push(false);
    boolPQ.push(true);
    boolPQ.push(false);

    // Since true has higher ordering priority:
    //
    // boolPQ.top() -> true

    cout << boolalpha;

    cout << "priority_queue<bool> top: "
         << boolPQ.top()
         << endl;

    cout << noboolalpha;

    // ============================================================
    // 6. priority_queue<string>
    // ============================================================
    //
    // Strings bhi priority queue mein store ki ja sakti hain.
    //
    // Default comparison string ordering use karega.
    //
    // The lexicographically greatest string gets highest priority
    // under the default ordering.

    priority_queue<string> stringPQ;

    stringPQ.push("Rahul");
    stringPQ.push("Aman");
    stringPQ.push("Priya");
    stringPQ.push("Zoya");

    // Default ordering ke hisaab se:
    //
    // "Zoya" sabse high priority ho sakta hai.

    cout << "priority_queue<string> top: "
         << stringPQ.top()
         << endl;

    // Process strings.

    cout << "string priority order: ";

    while (!stringPQ.empty())
    {
        cout << stringPQ.top() << " ";

        stringPQ.pop();
    }

    cout << endl;

    // ============================================================
    // 7. priority_queue<long long>
    // ============================================================
    //
    // long long large integer values ke liye useful hai.
    //
    // DSA mein bahut common hai.

    priority_queue<long long> longLongPQ;

    longLongPQ.push(10000000000LL);
    longLongPQ.push(50000000000LL);
    longLongPQ.push(20000000000LL);

    // Largest value:
    //
    // 50000000000

    cout << "priority_queue<long long> top: "
         << longLongPQ.top()
         << endl;

    // ============================================================
    // 8. priority_queue<pair<int, int>>
    // ============================================================
    //
    // Priority queue pairs ko bhi store kar sakti hai.
    //
    // pair<int,int> mein:
    //
    // first
    // second
    //
    // Default pair comparison:
    //
    // 1. first compare hota hai
    // 2. Agar first same ho, to second compare hota hai
    //
    // Ye lexicographical comparison hai.

    priority_queue<pair<int, int>> pairPQ;

    pairPQ.push({1, 100});
    pairPQ.push({3, 200});
    pairPQ.push({2, 300});
    pairPQ.push({3, 150});

    // Compare pairs:
    //
    // {1,100}
    // {2,300}
    // {3,200}
    // {3,150}
    //
    // Among first = 3:
    //
    // 200 > 150
    //
    // Therefore top:
    //
    // {3,200}

    cout << "priority_queue<pair<int,int>> top: {"
         << pairPQ.top().first
         << ", "
         << pairPQ.top().second
         << "}"
         << endl;

    // Process pair priority queue.

    cout << "pair priority order: ";

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
    // 9. MIN HEAP WITH int
    // ============================================================
    //
    // Ab tak:
    //
    // priority_queue<int>
    //
    // MAX-HEAP thi.
    //
    // Agar smallest value ko highest priority dena ho,
    // to MIN-HEAP use karte hain.
    //
    // Syntax:
    //
    // priority_queue<
    //     int,
    //     vector<int>,
    //     greater<int>
    // > pq;
    //
    // Breakdown:
    //
    // int
    // -> element type
    //
    // vector<int>
    // -> underlying container
    //
    // greater<int>
    // -> comparison rule
    //
    // Result:
    //
    // smallest value = highest priority.

    priority_queue<int, vector<int>, greater<int>> minPQ;

    minPQ.push(50);
    minPQ.push(10);
    minPQ.push(30);
    minPQ.push(20);
    minPQ.push(40);

    // Top:
    //
    // 10

    cout << "Min-heap top: "
         << minPQ.top()
         << endl;

    // Processing min heap:
    //
    // 10 -> 20 -> 30 -> 40 -> 50

    cout << "Min-heap priority order: ";

    while (!minPQ.empty())
    {
        cout << minPQ.top() << " ";

        minPQ.pop();
    }

    cout << endl;

    // ============================================================
    // 10. MIN HEAP OF pair<int, int>
    // ============================================================
    //
    // Pair ke liye bhi min heap bana sakte hain.
    //
    // Syntax:
    //
    // priority_queue<
    //     pair<int,int>,
    //     vector<pair<int,int>>,
    //     greater<pair<int,int>>
    // >
    //
    // Ye especially graph algorithms mein useful hai.
    //
    // Example:
    //
    // {distance, node}
    //
    // Smallest distance should have highest priority.

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        minPairPQ;

    minPairPQ.push({10, 5});
    minPairPQ.push({3, 8});
    minPairPQ.push({7, 2});
    minPairPQ.push({1, 9});

    // Smallest pair:
    //
    // {1,9}
    //
    // So top() = {1,9}

    cout << "Min pair PQ top: {"
         << minPairPQ.top().first
         << ", "
         << minPairPQ.top().second
         << "}"
         << endl;

    // ============================================================
    // 11. priority_queue<vector<int>>
    // ============================================================
    //
    // Priority queue ke element ke roop mein vector bhi
    // use kiya ja sakta hai, provided the element type
    // has an ordering that the priority queue can use.
    //
    // vector comparison lexicographical hoti hai.
    //
    // Example:
    //
    // {1,2}
    // {1,5}
    // {2,0}
    //
    // Default priority order comparison rules ke according hoga.

    priority_queue<vector<int>> vectorPQ;

    vectorPQ.push({1, 2});
    vectorPQ.push({1, 5});
    vectorPQ.push({2, 0});

    // Top vector is the highest according to vector comparison.

    cout << "Top vector: [ ";

    for (int x : vectorPQ.top())
    {
        cout << x << " ";
    }

    cout << "]" << endl;

    // ============================================================
    // 12. CUSTOM STRUCT
    // ============================================================
    //
    // User-defined type ko priority queue mein use karne ke liye
    // hume ordering define karni pad sakti hai.
    //
    // Iske liye custom comparator bahut common approach hai.

    struct Student
    {
        string name;
        int marks;
    };

    // Custom comparator:
    //
    // Hum chahte hain:
    //
    // Higher marks = Higher priority

    struct CompareStudent
    {
        bool operator()(const Student &a,
                        const Student &b) const
        {
            // Return true when 'a' should come
            // AFTER 'b' in priority ordering.
            //
            // Since we want higher marks first,
            // student with smaller marks gets lower priority.

            return a.marks < b.marks;
        }
    };

    // Create priority queue of Student objects.

    priority_queue<
        Student,
        vector<Student>,
        CompareStudent>
        studentPQ;

    // Add students.

    studentPQ.push({"Rahul", 80});
    studentPQ.push({"Aman", 95});
    studentPQ.push({"Priya", 88});

    // Highest marks = highest priority.
    //
    // Therefore:
    //
    // Aman -> 95
    //
    // will be at top.

    cout << "Top Student: "
         << studentPQ.top().name
         << " "
         << studentPQ.top().marks
         << endl;

    // ============================================================
    // PROCESS CUSTOM STRUCT PRIORITY QUEUE
    // ============================================================

    cout << "Students by priority:" << endl;

    while (!studentPQ.empty())
    {
        cout << studentPQ.top().name
             << " -> "
             << studentPQ.top().marks
             << endl;

        studentPQ.pop();
    }

    // ============================================================
    // IMPORTANT: PRIORITY QUEUE IS NOT FULLY SORTED
    // ============================================================
    //
    // Ye bahut important concept hai.
    //
    // priority_queue internally HEAP maintain karti hai.
    //
    // Iska matlab ye nahi hai ki andar ke saare elements
    // fully sorted form mein stored hain.
    //
    // Guarantee:
    //
    // top() = highest-priority element
    //
    // Jab pop() karte ho:
    //
    // next highest-priority element top par aa jata hai.
    //
    // Example:
    //
    // 10, 40, 20, 50, 30
    //
    // top() = 50
    //
    // pop()
    //
    // top() = 40
    //
    // pop()
    //
    // top() = 30
    //
    // and so on.

    // ============================================================
    // IMPORTANT: priority_queue HAS NO begin()/end()
    // ============================================================
    //
    // priority_queue is a container adaptor.
    //
    // Standard interface mein:
    //
    // pq.begin()   // ❌
    // pq.end()     // ❌
    //
    // Normally processing ke liye:
    //
    // while (!pq.empty())
    // {
    //     cout << pq.top();
    //     pq.pop();
    // }
    //
    // use karte hain.

    // ============================================================
    // IMPORTANT FUNCTIONS
    // ============================================================
    //
    // push()
    // ------------------------------------------------------------
    // New element add karta hai.
    //
    //
    // top()
    // ------------------------------------------------------------
    // Highest-priority element access karta hai.
    //
    //
    // pop()
    // ------------------------------------------------------------
    // Highest-priority element remove karta hai.
    //
    //
    // size()
    // ------------------------------------------------------------
    // Number of elements.
    //
    //
    // empty()
    // ------------------------------------------------------------
    // Check whether priority queue is empty.
    //
    //
    // swap()
    // ------------------------------------------------------------
    // Do compatible priority queues ke complete contents exchange.
    //
    //
    // ============================================================

    // ============================================================
    // IMPORTANT SAFETY RULE
    // ============================================================
    //
    // Empty priority queue par:
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
    // ya:
    //
    // while (!pq.empty())
    // {
    //     int x = pq.top();
    //     pq.pop();
    // }

    // ============================================================
    // COMMON PRIORITY QUEUE DATA TYPES
    // ============================================================
    //
    // Simple types:
    //
    // priority_queue<int>
    // priority_queue<float>
    // priority_queue<double>
    // priority_queue<char>
    // priority_queue<bool>
    // priority_queue<string>
    // priority_queue<long long>
    //
    // STL / compound types:
    //
    // priority_queue<pair<int,int>>
    // priority_queue<vector<int>>
    //
    // Custom:
    //
    // priority_queue<Student, vector<Student>, CompareStudent>
    //
    // Min heap:
    //
    // priority_queue<
    //     int,
    //     vector<int>,
    //     greater<int>
    // >

    // ============================================================
    // FINAL CHEAT SHEET
    // ============================================================

    /*
        MAX HEAP
        ------------------------------------------------------------
        priority_queue<int> pq;

        Largest value -> highest priority
        pq.top()       -> largest value


        MIN HEAP
        ------------------------------------------------------------
        priority_queue<int,
                       vector<int>,
                       greater<int>> pq;

        Smallest value -> highest priority
        pq.top()       -> smallest value


        STRING
        ------------------------------------------------------------
        priority_queue<string> pq;


        PAIR
        ------------------------------------------------------------
        priority_queue<pair<int,int>> pq;


        MIN HEAP OF PAIR
        ------------------------------------------------------------
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;


        CUSTOM STRUCT
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
    // priority_queue<T>
    //
    // T = element type.
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
    // DEFAULT:
    //
    // MAX-HEAP
    //
    // largest -> top
    //
    //
    // WITH greater<T>:
    //
    // MIN-HEAP
    //
    // smallest -> top.

    return 0;
}