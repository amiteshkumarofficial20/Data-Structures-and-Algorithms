#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    // ============================================================
    // VECTOR KIN-KIN DATA TYPES KE SAATH USE HO SAKTA HAI?
    // ============================================================
    //
    // Vector ek STL container hai.
    //
    // Syntax:
    //
    // vector<data_type> vector_name;
    //
    // vector almost kisi bhi valid C++ data type ke elements
    // store kar sakta hai.
    //
    // Examples:
    //
    // vector<int>
    // vector<float>
    // vector<double>
    // vector<char>
    // vector<bool>
    // vector<string>
    // vector<long long>
    // vector<pair<int,int>>
    // vector<vector<int>>
    //
    // Ab ek-ek karke examples dekhte hain.

    // ============================================================
    // 1. VECTOR OF int
    // ============================================================
    //
    // int = integer values
    //
    // Examples:
    //
    // 10, 20, 30, -5, 100
    //
    // Syntax:
    //
    // vector<int> v;
    //
    // Ye DSA aur competitive programming mein
    // sabse commonly used vector type hai.

    vector<int> intVec = {10, 20, 30, 40};

    cout << "vector<int>: ";

    for (int x : intVec)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 2. VECTOR OF float
    // ============================================================
    //
    // float decimal values store karta hai.
    //
    // Examples:
    //
    // 10.5
    // 20.75
    // 3.14
    //
    // Syntax:
    //
    // vector<float> v;

    vector<float> floatVec = {10.5f, 20.5f, 30.75f};

    cout << "vector<float>: ";

    for (float x : floatVec)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 3. VECTOR OF double
    // ============================================================
    //
    // double bhi decimal values store karta hai.
    //
    // Generally double ko float se zyada precision milti hai.
    //
    // Syntax:
    //
    // vector<double> v;

    vector<double> doubleVec = {3.14, 2.718, 99.99};

    cout << "vector<double>: ";

    for (double x : doubleVec)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 4. VECTOR OF char
    // ============================================================
    //
    // char single character store karta hai.
    //
    // Examples:
    //
    // 'A'
    // 'B'
    // 'x'
    // '#'
    //
    // IMPORTANT:
    //
    // char ke liye SINGLE quotes use hote hain:
    //
    // 'A'
    //
    // Double quotes:
    //
    // "A"
    //
    // string/literal ke liye hote hain.

    vector<char> charVec = {'A', 'B', 'C', 'D'};

    cout << "vector<char>: ";

    for (char ch : charVec)
    {
        cout << ch << " ";
    }

    cout << endl;

    // ============================================================
    // 5. VECTOR OF bool
    // ============================================================
    //
    // bool ke possible values:
    //
    // true
    // false
    //
    // Syntax:
    //
    // vector<bool> v;
    //
    // IMPORTANT:
    //
    // vector<bool> standard vector<int> jaisa exactly behave
    // nahi karta; C++ mein vector<bool> ek specialized container
    // hai.
    //
    // Beginner level par bas itna yaad rakho ki bool values
    // store karne ke liye use kiya ja sakta hai.

    vector<bool> boolVec = {true, false, true, true};

    cout << "vector<bool>: ";

    for (bool x : boolVec)
    {
        cout << x << " ";
    }

    cout << endl;

    // By default cout:
    //
    // true  -> 1
    // false -> 0
    //
    // Agar true/false words print karne hain:
    //
    // cout << boolalpha;

    // ============================================================
    // 6. VECTOR OF string
    // ============================================================
    //
    // vector strings ki list store kar sakta hai.
    //
    // Example:
    //
    // ["Rahul", "Aman", "Priya"]
    //
    // Syntax:
    //
    // vector<string> v;
    //
    // Iske liye:
    //
    // #include <string>
    //
    // required hota hai.

    vector<string> stringVec = {
        "Rahul",
        "Aman",
        "Priya",
        "Riya"};

    cout << "vector<string>:" << endl;

    for (const string &name : stringVec)
    {
        cout << name << endl;
    }

    // ============================================================
    // 7. VECTOR OF long long
    // ============================================================
    //
    // long long bade integer values ke liye commonly use hota hai.
    //
    // DSA mein bahut useful hai jab values int ki range se
    // bahar ja sakti hain.
    //
    // Syntax:
    //
    // vector<long long> v;

    vector<long long> longLongVec = {
        10000000000LL,
        20000000000LL,
        30000000000LL};

    cout << "vector<long long>: ";

    for (long long x : longLongVec)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 8. VECTOR OF short
    // ============================================================
    //
    // short bhi integer type hai.
    //
    // Syntax:
    //
    // vector<short> v;

    vector<short> shortVec = {10, 20, 30};

    cout << "vector<short>: ";

    for (short x : shortVec)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 9. VECTOR OF unsigned int
    // ============================================================
    //
    // unsigned int negative values store nahi karta.
    //
    // Syntax:
    //
    // vector<unsigned int> v;

    vector<unsigned int> unsignedVec = {10, 20, 30};

    cout << "vector<unsigned int>: ";

    for (unsigned int x : unsignedVec)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 10. VECTOR OF pair
    // ============================================================
    //
    // Vector sirf primitive data types tak limited nahi hai.
    //
    // Hum vector ke andar pair bhi store kar sakte hain.
    //
    // Example:
    //
    // vector<pair<int,int>> v;
    //
    // Har element ek pair hoga:
    //
    // {1, 10}
    // {2, 20}
    // {3, 30}
    //
    // Pair ke do members hote hain:
    //
    // first
    // second

    vector<pair<int, int>> pairVec = {
        {1, 10},
        {2, 20},
        {3, 30}};

    cout << "vector<pair<int,int>>:" << endl;

    for (const auto &p : pairVec)
    {
        cout << "First = " << p.first
             << ", Second = " << p.second << endl;
    }

    // ============================================================
    // 11. VECTOR OF vector<int>
    // ============================================================
    //
    // Vector ke andar vector bhi store kar sakte hain.
    //
    // Isko commonly 2D vector / dynamic matrix ke liye use
    // kiya jata hai.
    //
    // Syntax:
    //
    // vector<vector<int>> matrix;
    //
    // Example:
    //
    // 1 2 3
    // 4 5 6
    // 7 8 9

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    cout << "vector<vector<int>>:" << endl;

    for (const auto &row : matrix)
    {
        for (int x : row)
        {
            cout << x << " ";
        }

        cout << endl;
    }

    // ============================================================
    // 12. VECTOR OF string WITH MODIFICATION
    // ============================================================
    //
    // Agar original elements modify karne hain,
    // to reference use kar sakte hain.
    //
    // auto& -> original element ka reference

    vector<string> names = {
        "hello",
        "world"};

    for (auto &word : names)
    {
        // word original string ko refer kar raha hai.
        //
        // Agar hum modify karenge:
        //
        // original vector bhi change hoga.

        word += "!";
    }

    cout << "Modified vector<string>:" << endl;

    for (const auto &word : names)
    {
        cout << word << endl;
    }

    // ============================================================
    // IMPORTANT: CUSTOM DATA TYPES
    // ============================================================
    //
    // Vector user-defined classes / structures ke saath bhi
    // use ho sakta hai.
    //
    // Example:
    //
    // struct Student
    // {
    //     string name;
    //     int age;
    // };
    //
    // vector<Student> students;
    //
    // Matlab vector sirf int, float, string tak limited nahi hai.
    //
    // Kisi valid type ka vector banaya ja sakta hai,
    // provided that the type is usable with the operations
    // you perform.

    // ============================================================
    // SIMPLE CUSTOM STRUCT EXAMPLE
    // ============================================================

    struct Student
    {
        string name;
        int age;
    };

    // Creating vector of Student objects.

    vector<Student> students = {
        {"Rahul", 20},
        {"Aman", 21},
        {"Priya", 19}};

    cout << "vector<Student>:" << endl;

    for (const auto &student : students)
    {
        cout << "Name = " << student.name
             << ", Age = " << student.age << endl;
    }

    // ============================================================
    // QUICK LIST
    // ============================================================
    //
    // Vector in types ke saath commonly use ho sakta hai:
    //
    // vector<int>
    // vector<float>
    // vector<double>
    // vector<char>
    // vector<bool>
    // vector<string>
    // vector<long long>
    // vector<short>
    // vector<unsigned int>
    // vector<pair<int,int>>
    // vector<vector<int>>
    // vector<Student>
    //
    // Aur bhi bahut types ke saath use ho sakta hai.
    //
    // Main idea:
    //
    // vector<data_type>
    //
    // Yahan data_type C++ ka koi suitable type ho sakta hai.

    // ============================================================
    // MOST IMPORTANT DSA VECTORS
    // ============================================================
    //
    // DSA padhte time sabse common:
    //
    // 1. vector<int>
    // 2. vector<long long>
    // 3. vector<string>
    // 4. vector<pair<int,int>>
    // 5. vector<vector<int>>
    //
    // Inko achhe se practice karna.

    return 0;
}