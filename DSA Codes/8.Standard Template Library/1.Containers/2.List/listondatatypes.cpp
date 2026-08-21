#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

int main()
{
    // ============================================================
    // LIST WITH DIFFERENT DATA TYPES
    // ============================================================
    //
    // std::list is an STL container.
    //
    // General syntax:
    //
    // list<data_type> list_name;
    //
    // Just like vector, list can store different data types.
    //
    // Examples:
    //
    // list<int>
    // list<float>
    // list<double>
    // list<char>
    // list<bool>
    // list<string>
    // list<long long>
    // list<pair<int, int>>
    // list<vector<int>>
    //
    // In this file, we will see each type with examples.

    // ============================================================
    // 1. LIST OF int
    // ============================================================
    //
    // int stores integer values.
    //
    // Examples:
    //
    // 10, 20, 30, -5, 100

    list<int> intList = {10, 20, 30, 40};

    cout << "list<int>: ";

    for (int x : intList)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 2. LIST OF float
    // ============================================================
    //
    // float stores decimal values.
    //
    // Example:
    //
    // 10.5
    // 20.75
    // 3.14
    //
    // For float literals, we can use 'f' at the end.
    //
    // Example:
    //
    // 10.5f

    list<float> floatList = {
        10.5f,
        20.75f,
        30.25f};

    cout << "list<float>: ";

    for (float x : floatList)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 3. LIST OF double
    // ============================================================
    //
    // double also stores decimal values.
    //
    // It generally provides more precision than float.

    list<double> doubleList = {
        3.14159,
        2.71828,
        99.99};

    cout << "list<double>: ";

    for (double x : doubleList)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 4. LIST OF char
    // ============================================================
    //
    // char stores a SINGLE character.
    //
    // Character values are written using single quotes:
    //
    // 'A'
    // 'B'
    // 'x'
    // '#'
    //
    // NOT:
    //
    // "A"
    //
    // because double quotes are used for string literals.

    list<char> charList = {
        'A',
        'B',
        'C',
        'D'};

    cout << "list<char>: ";

    for (char ch : charList)
    {
        cout << ch << " ";
    }

    cout << endl;

    // ============================================================
    // 5. LIST OF bool
    // ============================================================
    //
    // bool stores:
    //
    // true
    // false
    //
    // By default, cout prints:
    //
    // true  -> 1
    // false -> 0

    list<bool> boolList = {
        true,
        false,
        true,
        false};

    cout << "list<bool>: ";

    for (bool x : boolList)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // PRINT bool AS true / false
    // ============================================================
    //
    // boolalpha makes cout print:
    //
    // true
    // false
    //
    // instead of:
    //
    // 1
    // 0

    cout << boolalpha;

    cout << "list<bool> with boolalpha: ";

    for (bool x : boolList)
    {
        cout << x << " ";
    }

    cout << endl;

    // Turn boolalpha off if you want normal numeric output again.
    cout << noboolalpha;

    // ============================================================
    // 6. LIST OF string
    // ============================================================
    //
    // list can store strings too.
    //
    // Example:
    //
    // "Rahul"
    // "Aman"
    // "Priya"

    list<string> stringList = {
        "Rahul",
        "Aman",
        "Priya",
        "Riya"};

    cout << "list<string>:" << endl;

    for (const string &name : stringList)
    {
        cout << name << endl;
    }

    // ============================================================
    // 7. LIST OF long long
    // ============================================================
    //
    // long long is useful for very large integer values.
    //
    // In DSA, long long is often used when int may not
    // be large enough.
    //
    // LL suffix can be used for large integer literals.

    list<long long> longList = {
        10000000000LL,
        20000000000LL,
        30000000000LL};

    cout << "list<long long>: ";

    for (long long x : longList)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 8. LIST OF short
    // ============================================================
    //
    // short is another integer type.

    list<short> shortList = {
        10,
        20,
        30};

    cout << "list<short>: ";

    for (short x : shortList)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 9. LIST OF unsigned int
    // ============================================================
    //
    // unsigned int is used for non-negative integer values.
    //
    // It does not represent negative values in the normal
    // signed-integer sense.

    list<unsigned int> unsignedList = {
        10,
        20,
        30};

    cout << "list<unsigned int>: ";

    for (unsigned int x : unsignedList)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 10. LIST OF pair<int, int>
    // ============================================================
    //
    // list does not only work with primitive types.
    //
    // We can store complex STL types as well.
    //
    // pair<int, int> contains TWO values:
    //
    // first
    // second
    //
    // Example:
    //
    // {1, 10}
    // {2, 20}
    // {3, 30}

    list<pair<int, int>> pairList = {
        {1, 10},
        {2, 20},
        {3, 30}};

    cout << "list<pair<int,int>>:" << endl;

    for (const auto &p : pairList)
    {
        cout << "First = " << p.first
             << ", Second = " << p.second << endl;
    }

    // ============================================================
    // 11. LIST OF vector<int>
    // ============================================================
    //
    // A list can even store vectors as its elements.
    //
    // So:
    //
    // list<vector<int>>
    //
    // means:
    //
    // "A list where every element is itself a vector<int>."
    //
    // This can be useful for storing multiple dynamic arrays.

    list<vector<int>> vectorList = {
        {1, 2, 3},
        {4, 5},
        {6, 7, 8, 9}};

    cout << "list<vector<int>>:" << endl;

    for (const auto &row : vectorList)
    {
        cout << "[ ";

        for (int x : row)
        {
            cout << x << " ";
        }

        cout << "]" << endl;
    }

    // ============================================================
    // 12. LIST OF list<int>
    // ============================================================
    //
    // Just like vector<vector<int>>,
    // we can create:
    //
    // list<list<int>>
    //
    // Each element of the outer list is itself a list.

    list<list<int>> nestedList = {
        {1, 2, 3},
        {4, 5},
        {6, 7, 8, 9}};

    cout << "list<list<int>>:" << endl;

    for (const auto &row : nestedList)
    {
        cout << "[ ";

        for (int x : row)
        {
            cout << x << " ";
        }

        cout << "]" << endl;
    }

    // ============================================================
    // 13. LIST OF CUSTOM STRUCT
    // ============================================================
    //
    // We can also create a list of our own data type.
    //
    // First, create a structure.

    struct Student
    {
        string name;
        int age;
    };

    // Now create a list of Student objects.
    //
    // list<Student>
    //
    // means:
    //
    // "Create a list in which every node stores
    // one Student object."

    list<Student> students = {
        {"Rahul", 20},
        {"Aman", 21},
        {"Priya", 19}};

    cout << "list<Student>:" << endl;

    for (const auto &student : students)
    {
        cout << "Name = " << student.name
             << ", Age = " << student.age << endl;
    }

    // ============================================================
    // ACCESSING FRONT AND BACK
    // ============================================================
    //
    // Every list type supports front() and back().
    //
    // Example with int list:

    cout << "\nFront of intList = "
         << intList.front() << endl;

    cout << "Back of intList = "
         << intList.back() << endl;

    // Example with string list:

    cout << "Front of stringList = "
         << stringList.front() << endl;

    cout << "Back of stringList = "
         << stringList.back() << endl;

    // ============================================================
    // ADDING ELEMENTS TO DIFFERENT DATA TYPES
    // ============================================================
    //
    // push_back() works according to the element type.

    intList.push_back(50);

    floatList.push_back(40.5f);

    doubleList.push_back(100.25);

    charList.push_back('E');

    boolList.push_back(true);

    stringList.push_back("Vikas");

    longList.push_back(40000000000LL);

    // For pair:
    pairList.push_back({4, 40});

    // ============================================================
    // pop_front() AND pop_back()
    // ============================================================
    //
    // Since list is a doubly linked list,
    // both front and back operations are efficient.

    intList.pop_front();

    intList.pop_back();

    // pop_front():
    //
    // removes first element.
    //
    // pop_back():
    //
    // removes last element.

    // ============================================================
    // ITERATOR CAN WORK WITH ALL THESE LIST TYPES
    // ============================================================
    //
    // Example with list<int>:

    list<int>::iterator it = intList.begin();

    while (it != intList.end())
    {
        cout << *it << " ";
        ++it;
    }

    cout << endl;

    // ============================================================
    // RANGE-BASED FOR LOOP WITH auto
    // ============================================================
    //
    // auto lets the compiler determine the type automatically.
    //
    // For intList:
    //
    // auto x becomes int.
    //
    // For stringList:
    //
    // auto x becomes string.
    //
    // For pairList:
    //
    // auto x becomes pair<int,int>.

    cout << "Using auto with intList: ";

    for (auto x : intList)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // const auto&
    // ============================================================
    //
    // When we only want to READ elements, we can use:
    //
    // const auto&
    //
    // const:
    // -> prevents modification.
    //
    // &:
    // -> avoids making a copy.
    //
    // auto:
    // -> compiler determines the type.

    cout << "Reading stringList using const auto&:" << endl;

    for (const auto &name : stringList)
    {
        cout << name << endl;
    }

    // ============================================================
    // MODIFYING ELEMENTS USING auto&
    // ============================================================
    //
    // auto& gives us a reference to the actual element.
    //
    // Therefore changes will affect the original list.
    //
    // Example:

    for (auto &x : intList)
    {
        x += 100;
    }

    // Every integer inside intList has now increased by 100.

    // ============================================================
    // IMPORTANT CONCEPT
    // ============================================================
    //
    // The syntax:
    //
    // list<T>
    //
    // means:
    //
    // T = element type.
    //
    // Examples:
    //
    // list<int>
    // list<double>
    // list<string>
    // list<pair<int,int>>
    // list<vector<int>>
    // list<Student>
    //
    // So T can be a built-in type,
    // STL type,
    // or user-defined type,
    // as long as it is suitable for the operations
    // you perform.

    // ============================================================
    // MOST COMMON LIST TYPES IN DSA
    // ============================================================
    //
    // In normal DSA practice, these are especially useful:
    //
    // list<int>
    // list<long long>
    // list<string>
    // list<pair<int,int>>
    //
    // Less common but possible:
    //
    // list<float>
    // list<double>
    // list<char>
    // list<bool>

    // ============================================================
    // QUICK SUMMARY
    // ============================================================

    /*
        list<int>
        --------------------------------------------------------
        Stores integers.


        list<float>
        --------------------------------------------------------
        Stores float/decimal values.


        list<double>
        --------------------------------------------------------
        Stores double/decimal values with higher precision.


        list<char>
        --------------------------------------------------------
        Stores characters.


        list<bool>
        --------------------------------------------------------
        Stores true/false values.


        list<string>
        --------------------------------------------------------
        Stores strings.


        list<long long>
        --------------------------------------------------------
        Stores large integer values.


        list<pair<int,int>>
        --------------------------------------------------------
        Stores pairs.


        list<vector<int>>
        --------------------------------------------------------
        Each list node contains a vector<int>.


        list<Student>
        --------------------------------------------------------
        Stores objects of a custom structure/class.
    */

    return 0;
}