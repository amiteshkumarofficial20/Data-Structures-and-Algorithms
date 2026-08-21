#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    // ============================================================
    // QUEUE WITH DIFFERENT DATA TYPES
    // ============================================================
    //
    // queue is an STL container adaptor.
    //
    // Queue follows FIFO:
    //
    // FIFO = First In, First Out
    //
    // Matlab:
    //
    // Jo element queue mein sabse pehle enter karega,
    // wahi sabse pehle remove hoga.
    //
    // Example:
    //
    // [10] -> [20] -> [30] -> [40]
    //   ^
    // FRONT
    //
    // 10 sabse pehle niklega.
    //
    // Basic syntax:
    //
    // queue<data_type> queue_name;
    //
    // Example:
    //
    // queue<int> q;
    //
    // Iska matlab:
    //
    // "q ek queue hai jo int values store karegi."

    // ============================================================
    // 1. QUEUE OF int
    // ============================================================
    //
    // int integer values store karta hai.
    //
    // Examples:
    //
    // 10, 20, 30, 100, -5
    //
    // Syntax:
    //
    // queue<int> q;

    queue<int> intQueue;

    // Elements add karna:
    //
    // push() element ko BACK par add karta hai.

    intQueue.push(10);
    intQueue.push(20);
    intQueue.push(30);
    intQueue.push(40);

    // Queue:
    //
    // FRONT                    BACK
    //   ↓                        ↓
    // [10] -> [20] -> [30] -> [40]

    // front() first element return karta hai.

    cout << "int queue front: "
         << intQueue.front() << endl;

    // Output:
    //
    // 10

    // back() last element return karta hai.

    cout << "int queue back: "
         << intQueue.back() << endl;

    // Output:
    //
    // 40

    // size() number of elements batata hai.

    cout << "int queue size: "
         << intQueue.size() << endl;

    // Output:
    //
    // 4

    // ============================================================
    // 2. QUEUE OF float
    // ============================================================
    //
    // float decimal values store karta hai.
    //
    // Example:
    //
    // 10.5
    // 20.25
    // 30.75

    queue<float> floatQueue;

    floatQueue.push(10.5f);
    floatQueue.push(20.25f);
    floatQueue.push(30.75f);

    cout << "\nfloat queue front: "
         << floatQueue.front() << endl;

    // ============================================================
    // 3. QUEUE OF double
    // ============================================================
    //
    // double bhi decimal values store karta hai.
    // Generally float se more precision provide karta hai.

    queue<double> doubleQueue;

    doubleQueue.push(3.14159);
    doubleQueue.push(2.71828);
    doubleQueue.push(99.9999);

    cout << "double queue front: "
         << doubleQueue.front() << endl;

    // ============================================================
    // 4. QUEUE OF char
    // ============================================================
    //
    // char ek single character store karta hai.
    //
    // Single quotes:
    //
    // 'A'
    // 'B'
    //
    // Double quotes:
    //
    // "A"
    //
    // string ke liye use hote hain.

    queue<char> charQueue;

    charQueue.push('A');
    charQueue.push('B');
    charQueue.push('C');
    charQueue.push('D');

    cout << "char queue front: "
         << charQueue.front() << endl;

    // ============================================================
    // 5. QUEUE OF bool
    // ============================================================
    //
    // bool do values store karta hai:
    //
    // true
    // false

    queue<bool> boolQueue;

    boolQueue.push(true);
    boolQueue.push(false);
    boolQueue.push(true);

    cout << "bool queue front: "
         << boolQueue.front() << endl;

    // By default cout:
    //
    // true  -> 1
    // false -> 0

    // ============================================================
    // 6. QUEUE OF string
    // ============================================================
    //
    // queue string values bhi store kar sakta hai.
    //
    // Example:
    //
    // "Rahul"
    // "Aman"
    // "Priya"

    queue<string> stringQueue;

    stringQueue.push("Rahul");
    stringQueue.push("Aman");
    stringQueue.push("Priya");

    cout << "string queue front: "
         << stringQueue.front() << endl;

    // ============================================================
    // STRING QUEUE KA FIFO BEHAVIOR
    // ============================================================
    //
    // Current queue:
    //
    // "Rahul" -> "Aman" -> "Priya"
    //
    // front() -> Rahul
    //
    // pop() karein:
    //
    // "Aman" -> "Priya"
    //
    // Again pop():
    //
    // "Priya"

    stringQueue.pop();

    cout << "After pop, string queue front: "
         << stringQueue.front() << endl;

    // ============================================================
    // 7. QUEUE OF long long
    // ============================================================
    //
    // long long large integer values ke liye useful hai.
    //
    // DSA mein frequently use hota hai jab values int ki
    // range se bahar ja sakti hain.

    queue<long long> longLongQueue;

    longLongQueue.push(10000000000LL);
    longLongQueue.push(20000000000LL);
    longLongQueue.push(30000000000LL);

    cout << "long long queue front: "
         << longLongQueue.front() << endl;

    // ============================================================
    // 8. QUEUE OF pair<int, int>
    // ============================================================
    //
    // Queue sirf primitive data types ke saath limited nahi hai.
    //
    // Hum STL ke doosre types ko bhi queue mein store kar sakte hain.
    //
    // pair<int, int> ke andar do values hoti hain:
    //
    // first
    // second
    //
    // Syntax:
    //
    // queue<pair<int, int>> q;

    queue<pair<int, int>> pairQueue;

    // Pair add karna:
    //
    // {1, 10}
    // {2, 20}
    // {3, 30}

    pairQueue.push({1, 10});
    pairQueue.push({2, 20});
    pairQueue.push({3, 30});

    // Front pair:
    //
    // {1, 10}

    cout << "pair queue front first: "
         << pairQueue.front().first << endl;

    cout << "pair queue front second: "
         << pairQueue.front().second << endl;

    // ============================================================
    // 9. QUEUE OF vector<int>
    // ============================================================
    //
    // queue ke andar vector<int> bhi store kar sakte hain.
    //
    // Syntax:
    //
    // queue<vector<int>> q;
    //
    // Iska matlab:
    //
    // queue ka har element ek complete vector<int> hai.

    queue<vector<int>> vectorQueue;

    // Three vectors queue mein add kar rahe hain.

    vectorQueue.push({1, 2, 3});
    vectorQueue.push({4, 5});
    vectorQueue.push({6, 7, 8, 9});

    // Queue conceptually:
    //
    // [1,2,3] -> [4,5] -> [6,7,8,9]

    // ============================================================
    // VECTOR QUEUE KO PROCESS KARNA
    // ============================================================
    //
    // q.front() current front vector return karega.
    //
    // We create a reference:
    //
    // const vector<int>& current = vectorQueue.front();
    //
    // Isse unnecessary copy avoid hoti hai.
    //
    // const:
    // current vector ko modify nahi karenge.

    cout << "\nVectors inside queue:\n";

    while (!vectorQueue.empty())
    {
        const vector<int> &current = vectorQueue.front();

        cout << "[ ";

        // Current vector ke elements print karna.

        for (int x : current)
        {
            cout << x << " ";
        }

        cout << "]" << endl;

        // Front vector ko remove karo.

        vectorQueue.pop();
    }

    // ============================================================
    // 10. QUEUE OF queue<int>
    // ============================================================
    //
    // Ek queue ke andar doosri queue bhi store ho sakti hai.
    //
    // Syntax:
    //
    // queue<queue<int>> q;
    //
    // Ye advanced concept hai, but C++ mein valid hai.

    queue<queue<int>> outerQueue;

    // First inner queue.

    queue<int> first;

    first.push(10);
    first.push(20);

    // Second inner queue.

    queue<int> second;

    second.push(30);
    second.push(40);

    // Inner queues ko outer queue mein insert karo.

    outerQueue.push(first);
    outerQueue.push(second);

    // Outer queue:
    //
    // Queue 1 -> [10,20]
    // Queue 2 -> [30,40]

    // Process outer queue.

    cout << "\nQueue of queues:\n";

    while (!outerQueue.empty())
    {
        // Current inner queue.
        //
        // We make a copy because hum ise process karke
        // pop karenge.

        queue<int> current = outerQueue.front();

        cout << "Inner queue: ";

        while (!current.empty())
        {
            cout << current.front() << " ";

            current.pop();
        }

        cout << endl;

        // Remove current inner queue from outer queue.

        outerQueue.pop();
    }

    // ============================================================
    // 11. QUEUE OF CUSTOM STRUCT
    // ============================================================
    //
    // Hum apna khud ka data type bhi bana sakte hain.
    //
    // Example:
    //
    // Student naam ka struct banate hain.

    struct Student
    {
        string name;
        int age;
    };

    // Ab Student objects ki queue bana sakte hain.

    queue<Student> studentQueue;

    // Student objects add karna.

    studentQueue.push({"Rahul", 20});
    studentQueue.push({"Aman", 21});
    studentQueue.push({"Priya", 19});

    // Process Student queue.

    cout << "\nStudent queue:\n";

    while (!studentQueue.empty())
    {
        // Front student ko reference ke through access kar rahe hain.

        const Student &student = studentQueue.front();

        cout << "Name: "
             << student.name
             << ", Age: "
             << student.age
             << endl;

        // Process ke baad front student ko remove karna.

        studentQueue.pop();
    }

    // ============================================================
    // IMPORTANT QUEUE OPERATIONS
    // ============================================================
    //
    // Har data type ke queue par generally same basic operations
    // available hote hain.
    //
    // push()
    //    -> back par element add
    //
    // pop()
    //    -> front element remove
    //
    // front()
    //    -> first element access
    //
    // back()
    //    -> last element access
    //
    // size()
    //    -> total elements
    //
    // empty()
    //    -> check whether queue is empty

    // ============================================================
    // IMPORTANT: pop() VALUE RETURN NAHI KARTA
    // ============================================================
    //
    // Ye common mistake hai:
    //
    // int x = q.pop();
    //
    // ❌ Wrong
    //
    // pop() removed element ki value return nahi karta.
    //
    // Correct:
    //
    // int x = q.front();
    // q.pop();
    //
    // First value read karo,
    // phir usko remove karo.

    // ============================================================
    // IMPORTANT: EMPTY QUEUE PAR front() / back() NAHI
    // ============================================================
    //
    // Agar queue empty hai:
    //
    // queue<int> q;
    //
    // Then:
    //
    // q.front();  // ❌
    // q.back();   // ❌
    //
    // Pehle check karo:
    //
    // if (!q.empty())
    // {
    //     cout << q.front();
    // }

    // ============================================================
    // QUEUE KA MAIN FIFO CONCEPT
    // ============================================================
    //
    // Suppose:
    //
    // queue<int> q;
    //
    // q.push(10);
    // q.push(20);
    // q.push(30);
    //
    // Queue:
    //
    // FRONT              BACK
    //   ↓                   ↓
    // [10] -> [20] -> [30]
    //
    // q.front() -> 10
    // q.back()  -> 30
    //
    // q.pop()
    //
    // 10 remove hoga.
    //
    // Remaining:
    //
    // [20] -> [30]
    //
    // Ye hi FIFO hai.

    // ============================================================
    // MOST COMMON QUEUE DATA TYPES
    // ============================================================
    //
    // DSA mein commonly:
    //
    // queue<int>
    // queue<long long>
    // queue<string>
    // queue<pair<int,int>>
    // queue<vector<int>>
    //
    // Advanced / custom:
    //
    // queue<Student>
    // queue<queue<int>>
    //
    // etc.

    // ============================================================
    // FINAL CHEAT SHEET
    // ============================================================

    /*
        queue<int>
        --------------------------
        Stores integers.


        queue<float>
        --------------------------
        Stores decimal float values.


        queue<double>
        --------------------------
        Stores double values.


        queue<char>
        --------------------------
        Stores characters.


        queue<bool>
        --------------------------
        Stores true / false.


        queue<string>
        --------------------------
        Stores strings.


        queue<long long>
        --------------------------
        Stores large integers.


        queue<pair<int,int>>
        --------------------------
        Stores pairs.


        queue<vector<int>>
        --------------------------
        Each queue element is a vector<int>.


        queue<Student>
        --------------------------
        Each queue element is a Student object.
    */

    // ============================================================
    // FINAL IMPORTANT RULE
    // ============================================================
    //
    // queue<T>
    //
    // T can be:
    //
    // - int
    // - float
    // - double
    // - char
    // - bool
    // - string
    // - long long
    // - pair
    // - vector
    // - custom struct/class
    // - many other suitable C++ types
    //
    // Bas syntax yaad rakho:
    //
    // queue<data_type> q;
    //
    // Example:
    //
    // queue<int> q;
    //
    // Here int = element type.
    //
    // ============================================================

    return 0;
}