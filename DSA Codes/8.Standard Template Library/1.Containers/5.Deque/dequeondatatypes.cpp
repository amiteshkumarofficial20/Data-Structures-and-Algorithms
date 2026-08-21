#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    // ============================================================
    // DEQUE WITH DIFFERENT DATA TYPES
    // ============================================================
    //
    // deque = Double Ended Queue
    //
    // A deque can store many different C++ data types.
    //
    // General syntax:
    //
    // deque<data_type> deque_name;
    //
    // Here:
    //
    // data_type -> type of element stored in deque
    //
    // Examples:
    //
    // deque<int>
    // deque<float>
    // deque<double>
    // deque<char>
    // deque<bool>
    // deque<string>
    // deque<long long>
    // deque<pair<int,int>>
    // deque<vector<int>>
    // deque<custom_struct>
    //
    // Important:
    //
    // The basic deque operations remain the same for different
    // data types:
    //
    // push_back()
    // push_front()
    // pop_back()
    // pop_front()
    // front()
    // back()
    // size()
    // empty()
    // etc.

    // ============================================================
    // 1. DEQUE OF int
    // ============================================================
    //
    // int stores integer values.
    //
    // Examples:
    //
    // 10, 20, 30, 100, -5
    //
    // This is one of the most common deque types in DSA.

    deque<int> intDeque;

    // Add elements at the back.

    intDeque.push_back(10);
    intDeque.push_back(20);
    intDeque.push_back(30);

    // Add an element at the front.

    intDeque.push_front(5);

    // Current deque:
    //
    // FRONT                 BACK
    //   ↓                     ↓
    // [5] [10] [20] [30]

    cout << "deque<int>:";

    for (int x : intDeque)
    {
        cout << " " << x;
    }

    cout << endl;

    // ============================================================
    // 2. DEQUE OF float
    // ============================================================
    //
    // float stores decimal values.
    //
    // Example:
    //
    // 10.5f
    // 20.25f
    // 30.75f

    deque<float> floatDeque;

    floatDeque.push_back(10.5f);
    floatDeque.push_back(20.25f);
    floatDeque.push_front(5.5f);

    cout << "deque<float>:";

    for (float x : floatDeque)
    {
        cout << " " << x;
    }

    cout << endl;

    // ============================================================
    // 3. DEQUE OF double
    // ============================================================
    //
    // double bhi decimal values ke liye use hota hai.
    //
    // Generally, double provides more precision than float.

    deque<double> doubleDeque;

    doubleDeque.push_back(3.14159);
    doubleDeque.push_back(2.71828);
    doubleDeque.push_front(1.41421);

    cout << "deque<double>:";

    for (double x : doubleDeque)
    {
        cout << " " << x;
    }

    cout << endl;

    // ============================================================
    // 4. DEQUE OF char
    // ============================================================
    //
    // char ek SINGLE character store karta hai.
    //
    // Examples:
    //
    // 'A'
    // 'B'
    // 'C'
    //
    // Character ke liye SINGLE quotes use hote hain:
    //
    // 'A'
    //
    // String literal:
    //
    // "A"
    //
    // alag cheez hai.

    deque<char> charDeque;

    charDeque.push_back('A');
    charDeque.push_back('B');
    charDeque.push_front('Z');

    cout << "deque<char>:";

    for (char ch : charDeque)
    {
        cout << " " << ch;
    }

    cout << endl;

    // ============================================================
    // 5. DEQUE OF bool
    // ============================================================
    //
    // bool ke main values:
    //
    // true
    // false

    deque<bool> boolDeque;

    boolDeque.push_back(true);
    boolDeque.push_back(false);
    boolDeque.push_front(true);

    // By default cout:
    //
    // true  -> 1
    // false -> 0

    cout << "deque<bool>: ";

    for (bool value : boolDeque)
    {
        cout << value << " ";
    }

    cout << endl;

    // ============================================================
    // boolalpha
    // ============================================================
    //
    // Agar true / false words print karne hain:
    //
    // boolalpha use kar sakte hain.

    cout << boolalpha;

    cout << "deque<bool> with boolalpha: ";

    for (bool value : boolDeque)
    {
        cout << value << " ";
    }

    cout << endl;

    // Normal bool output mode par wapas.

    cout << noboolalpha;

    // ============================================================
    // 6. DEQUE OF string
    // ============================================================
    //
    // string multiple characters ka sequence hai.
    //
    // Examples:
    //
    // "Rahul"
    // "Aman"
    // "Priya"

    deque<string> stringDeque;

    stringDeque.push_back("Aman");
    stringDeque.push_back("Priya");
    stringDeque.push_front("Rahul");

    // Current:
    //
    // FRONT                         BACK
    //   ↓                             ↓
    // ["Rahul"] ["Aman"] ["Priya"]

    cout << "deque<string>:";

    for (const string &name : stringDeque)
    {
        cout << " " << name;
    }

    cout << endl;

    // ============================================================
    // 7. DEQUE OF long long
    // ============================================================
    //
    // long long large integer values ke liye commonly used hai.
    //
    // DSA mein useful hai jab values int se badi ho sakti hain.

    deque<long long> longLongDeque;

    longLongDeque.push_back(10000000000LL);
    longLongDeque.push_back(20000000000LL);
    longLongDeque.push_front(5000000000LL);

    cout << "deque<long long>:";

    for (long long x : longLongDeque)
    {
        cout << " " << x;
    }

    cout << endl;

    // ============================================================
    // 8. DEQUE OF short
    // ============================================================
    //
    // short bhi integer data type hai.

    deque<short> shortDeque;

    shortDeque.push_back(10);
    shortDeque.push_back(20);
    shortDeque.push_front(5);

    cout << "deque<short>:";

    for (short x : shortDeque)
    {
        cout << " " << x;
    }

    cout << endl;

    // ============================================================
    // 9. DEQUE OF unsigned int
    // ============================================================
    //
    // unsigned int unsigned integer type hai.
    //
    // Negative values ke saath signed/unsigned conversion
    // rules ko dhyan se samajhna chahiye.

    deque<unsigned int> unsignedDeque;

    unsignedDeque.push_back(10);
    unsignedDeque.push_back(20);
    unsignedDeque.push_front(5);

    cout << "deque<unsigned int>:";

    for (unsigned int x : unsignedDeque)
    {
        cout << " " << x;
    }

    cout << endl;

    // ============================================================
    // 10. DEQUE OF pair<int, int>
    // ============================================================
    //
    // deque sirf basic data types tak limited nahi hai.
    //
    // Hum pair ko bhi store kar sakte hain.
    //
    // pair<int, int> ke andar:
    //
    // first
    // second
    //
    // do values hoti hain.

    deque<pair<int, int>> pairDeque;

    pairDeque.push_back({1, 100});
    pairDeque.push_back({2, 200});
    pairDeque.push_front({0, 50});

    // Current:
    //
    // FRONT
    //   ↓
    // {0,50} -> {1,100} -> {2,200}

    cout << "deque<pair<int,int>>:" << endl;

    for (const auto &p : pairDeque)
    {
        cout << "First = "
             << p.first
             << ", Second = "
             << p.second
             << endl;
    }

    // ============================================================
    // 11. DEQUE OF vector<int>
    // ============================================================
    //
    // deque ke andar vector<int> bhi store kar sakte hain.
    //
    // Syntax:
    //
    // deque<vector<int>> dq;
    //
    // Iska matlab:
    //
    // Every deque element is a complete vector<int>.

    deque<vector<int>> vectorDeque;

    vectorDeque.push_back({1, 2, 3});
    vectorDeque.push_back({4, 5});
    vectorDeque.push_front({100, 200});

    cout << "deque<vector<int>>:" << endl;

    // row = one vector<int>

    for (const auto &row : vectorDeque)
    {
        cout << "[ ";

        // x = one integer inside current vector

        for (int x : row)
        {
            cout << x << " ";
        }

        cout << "]" << endl;
    }

    // ============================================================
    // 12. DEQUE OF vector<string>
    // ============================================================
    //
    // Nested STL types bhi possible hain.

    deque<vector<string>> namesDeque;

    namesDeque.push_back({"Rahul", "Aman"});
    namesDeque.push_back({"Priya", "Riya"});

    cout << "deque<vector<string>>:" << endl;

    for (const auto &names : namesDeque)
    {
        cout << "[ ";

        for (const string &name : names)
        {
            cout << name << " ";
        }

        cout << "]" << endl;
    }

    // ============================================================
    // 13. DEQUE OF CUSTOM STRUCT
    // ============================================================
    //
    // Hum apna khud ka data type bhi define kar sakte hain.
    //
    // Example:
    //
    // Student structure

    struct Student
    {
        string name;
        int age;
    };

    // Ab Student objects ka deque bana sakte hain.

    deque<Student> studentDeque;

    // Add Student at back.

    studentDeque.push_back({"Rahul", 20});
    studentDeque.push_back({"Aman", 21});

    // Add Student at front.

    studentDeque.push_front({"Priya", 19});

    // Current:
    //
    // FRONT
    //   ↓
    // Priya -> Rahul -> Aman

    cout << "deque<Student>:" << endl;

    for (const auto &student : studentDeque)
    {
        cout << "Name = "
             << student.name
             << ", Age = "
             << student.age
             << endl;
    }

    // ============================================================
    // ACCESSING FRONT AND BACK FOR DIFFERENT TYPES
    // ============================================================
    //
    // front() aur back() almost har deque type par
    // same tarah kaam karte hain.

    cout << "\nFront int: "
         << intDeque.front()
         << endl;

    cout << "Back int: "
         << intDeque.back()
         << endl;

    cout << "Front string: "
         << stringDeque.front()
         << endl;

    cout << "Back string: "
         << stringDeque.back()
         << endl;

    // ============================================================
    // SIZE FOR DIFFERENT TYPES
    // ============================================================
    //
    // size() batata hai current deque mein kitne elements hain.
    //
    // Element ka data type change hone se size() ka use
    // change nahi hota.

    cout << "\nint deque size: "
         << intDeque.size()
         << endl;

    cout << "string deque size: "
         << stringDeque.size()
         << endl;

    cout << "pair deque size: "
         << pairDeque.size()
         << endl;

    // ============================================================
    // RANDOM ACCESS WITH DIFFERENT TYPES
    // ============================================================
    //
    // Deque random access support karta hai.
    //
    // Example with int:

    cout << "\nintDeque[0] = "
         << intDeque[0]
         << endl;

    // Example with string:

    cout << "stringDeque[0] = "
         << stringDeque[0]
         << endl;

    // Example with pair:
    //
    // pairDeque[0] returns a pair.
    //
    // .first and .second se values access kar sakte hain.

    cout << "pairDeque[0].first = "
         << pairDeque[0].first
         << endl;

    cout << "pairDeque[0].second = "
         << pairDeque[0].second
         << endl;

    // ============================================================
    // at() WITH DIFFERENT DATA TYPES
    // ============================================================
    //
    // at() bounds checking ke saath random access provide karta hai.

    cout << "intDeque.at(1) = "
         << intDeque.at(1)
         << endl;

    cout << "stringDeque.at(1) = "
         << stringDeque.at(1)
         << endl;

    // ============================================================
    // MODIFYING ELEMENTS
    // ============================================================
    //
    // Deque ke elements ko index se modify kar sakte hain,
    // agar element type assignable hai.

    intDeque[0] = 500;

    // First int element becomes 500.

    cout << "\nModified intDeque front: "
         << intDeque.front()
         << endl;

    // String element modify karna:

    stringDeque[0] = "Virat";

    cout << "Modified stringDeque front: "
         << stringDeque.front()
         << endl;

    // ============================================================
    // RANGE-BASED LOOP WITH auto
    // ============================================================
    //
    // auto compiler ko type automatically deduce karne deta hai.
    //
    // For intDeque:
    //
    // auto x -> int
    //
    // For stringDeque:
    //
    // auto x -> string

    cout << "\nUsing auto with intDeque: ";

    for (auto x : intDeque)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // const auto& WITH DEQUE
    // ============================================================
    //
    // const auto& useful hai jab:
    //
    // 1. Sirf read karna ho
    // 2. Copy avoid karni ho
    //
    // Particularly useful for large objects like:
    //
    // vector
    // string
    // custom struct

    cout << "Reading Student deque using const auto&:"
         << endl;

    for (const auto &student : studentDeque)
    {
        cout << student.name
             << " "
             << student.age
             << endl;
    }

    // ============================================================
    // MODIFYING USING auto&
    // ============================================================
    //
    // auto& original element ka reference deta hai.
    //
    // Therefore changes original deque ko modify karenge.

    for (auto &student : studentDeque)
    {
        student.age += 1;
    }

    // Ab sab students ki age 1 se increase ho gayi.

    cout << "\nAfter modifying Student ages:" << endl;

    for (const auto &student : studentDeque)
    {
        cout << student.name
             << " "
             << student.age
             << endl;
    }

    // ============================================================
    // DIFFERENT TYPES CAN HAVE THE SAME DEQUE OPERATIONS
    // ============================================================
    //
    // int:
    //
    // intDeque.push_back(10);
    //
    // string:
    //
    // stringDeque.push_back("Hello");
    //
    // pair:
    //
    // pairDeque.push_back({1, 100});
    //
    // Student:
    //
    // studentDeque.push_back({"Rahul", 20});
    //
    // Basic idea same hai:
    //
    // deque<T>
    //
    // sirf T change hota hai.

    // ============================================================
    // DEQUE DATA TYPES QUICK LIST
    // ============================================================
    //
    // Common examples:
    //
    // deque<int>
    // deque<float>
    // deque<double>
    // deque<char>
    // deque<bool>
    // deque<string>
    // deque<long long>
    // deque<short>
    // deque<unsigned int>
    //
    // STL / nested types:
    //
    // deque<pair<int,int>>
    // deque<vector<int>>
    // deque<vector<string>>
    //
    // User-defined:
    //
    // deque<Student>

    // ============================================================
    // IMPORTANT CONCEPT
    // ============================================================
    //
    // deque<T>
    //
    // mein:
    //
    // T = element type
    //
    // Example:
    //
    // deque<int>
    // T = int
    //
    // deque<string>
    // T = string
    //
    // deque<pair<int,int>>
    // T = pair<int,int>
    //
    // deque<Student>
    // T = Student

    // ============================================================
    // MOST IMPORTANT DSA TYPES
    // ============================================================
    //
    // DSA ke liye especially ye yaad rakho:
    //
    // 1. deque<int>
    // 2. deque<long long>
    // 3. deque<string>
    // 4. deque<pair<int,int>>
    // 5. deque<vector<int>>
    //
    // Aur custom structs/classes bhi use ho sakte hain.

    // ============================================================
    // FINAL CHEAT SHEET
    // ============================================================

    /*
        deque<int>
        -------------------------
        Integer values


        deque<float>
        -------------------------
        Float decimal values


        deque<double>
        -------------------------
        Double decimal values


        deque<char>
        -------------------------
        Characters


        deque<bool>
        -------------------------
        true / false


        deque<string>
        -------------------------
        Strings


        deque<long long>
        -------------------------
        Large integers


        deque<pair<int,int>>
        -------------------------
        Pair of two integers


        deque<vector<int>>
        -------------------------
        Every deque element is a vector<int>


        deque<Student>
        -------------------------
        Every deque element is a Student object
    */

    // ============================================================
    // FINAL RULE
    // ============================================================
    //
    // Syntax:
    //
    // deque<data_type> dq;
    //
    // data_type almost koi bhi suitable C++ type ho sakta hai.
    //
    // Main concept:
    //
    // deque<T>
    //     ↓
    // T = type of each element

    return 0;
}