#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    // ============================================================
    // STACK WITH DIFFERENT DATA TYPES
    // ============================================================
    //
    // stack is an STL container adaptor.
    //
    // Stack follows:
    //
    // LIFO = Last In, First Out
    //
    // Matlab:
    //
    // Jo element stack mein SABSE LAST mein insert hoga,
    // wahi SABSE PEHLE remove hoga.
    //
    // Basic syntax:
    //
    // stack<data_type> stack_name;
    //
    // Example:
    //
    // stack<int> st;
    //
    // Here:
    //
    // stack -> STL stack container
    // int   -> element ka data type
    // st    -> stack ka naam

    // ============================================================
    // 1. STACK OF int
    // ============================================================
    //
    // int integer values store karta hai.
    //
    // Examples:
    //
    // 10, 20, 30, 40
    //
    // DSA mein stack<int> bahut commonly use hota hai.

    stack<int> intStack;

    // Push elements.
    //
    // push() element ko TOP par add karta hai.

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.push(40);

    // Current stack:
    //
    // TOP
    //  ↓
    // [40]
    // [30]
    // [20]
    // [10]
    //
    // 40 sabse last insert hua tha,
    // isliye 40 TOP par hai.

    cout << "int stack top: "
         << intStack.top() << endl;

    // Output:
    //
    // 40

    cout << "int stack size: "
         << intStack.size() << endl;

    // Output:
    //
    // 4

    // ============================================================
    // 2. STACK OF float
    // ============================================================
    //
    // float decimal values store karta hai.
    //
    // Example:
    //
    // 10.5f
    // 20.25f
    // 30.75f

    stack<float> floatStack;

    floatStack.push(10.5f);
    floatStack.push(20.25f);
    floatStack.push(30.75f);

    cout << "float stack top: "
         << floatStack.top() << endl;

    // Output:
    //
    // 30.75

    // ============================================================
    // 3. STACK OF double
    // ============================================================
    //
    // double bhi decimal values ke liye use hota hai.
    //
    // Generally double float se zyada precision deta hai.

    stack<double> doubleStack;

    doubleStack.push(3.14159);
    doubleStack.push(2.71828);
    doubleStack.push(99.9999);

    cout << "double stack top: "
         << doubleStack.top() << endl;

    // ============================================================
    // 4. STACK OF char
    // ============================================================
    //
    // char ek single character store karta hai.
    //
    // Character ko single quotes mein likhte hain:
    //
    // 'A'
    // 'B'
    // 'C'
    //
    // "A" string literal hai,
    // 'A' char hai.

    stack<char> charStack;

    charStack.push('A');
    charStack.push('B');
    charStack.push('C');
    charStack.push('D');

    cout << "char stack top: "
         << charStack.top() << endl;

    // Output:
    //
    // D

    // ============================================================
    // 5. STACK OF bool
    // ============================================================
    //
    // bool ke only do main values hote hain:
    //
    // true
    // false

    stack<bool> boolStack;

    boolStack.push(true);
    boolStack.push(false);
    boolStack.push(true);

    // By default cout:
    //
    // true  -> 1
    // false -> 0

    cout << "bool stack top: "
         << boolStack.top() << endl;

    // ============================================================
    // boolalpha
    // ============================================================
    //
    // Agar hume:
    //
    // 1 / 0
    //
    // ki jagah:
    //
    // true / false
    //
    // print karna ho, to boolalpha use kar sakte hain.

    cout << boolalpha;

    cout << "bool stack top with boolalpha: "
         << boolStack.top() << endl;

    // Ab output:
    //
    // true

    // boolalpha ko normal mode mein wapas kar rahe hain.

    cout << noboolalpha;

    // ============================================================
    // 6. STACK OF string
    // ============================================================
    //
    // string multiple characters ka sequence hota hai.
    //
    // Examples:
    //
    // "Rahul"
    // "Aman"
    // "Priya"

    stack<string> stringStack;

    stringStack.push("Rahul");
    stringStack.push("Aman");
    stringStack.push("Priya");

    // Current stack:
    //
    // TOP
    //  ↓
    // ["Priya"]
    // ["Aman"]
    // ["Rahul"]
    //
    // Priya last inserted hai,
    // so Priya top par hai.

    cout << "string stack top: "
         << stringStack.top() << endl;

    // ============================================================
    // 7. STACK OF long long
    // ============================================================
    //
    // long long large integer values store karne ke liye useful hai.
    //
    // DSA mein jab values int ki range se badi ho sakti hain,
    // tab long long commonly use hota hai.
    //
    // Large integer literals ke saath LL suffix use kar sakte hain.

    stack<long long> longLongStack;

    longLongStack.push(10000000000LL);
    longLongStack.push(20000000000LL);
    longLongStack.push(30000000000LL);

    cout << "long long stack top: "
         << longLongStack.top() << endl;

    // ============================================================
    // 8. STACK OF short
    // ============================================================
    //
    // short bhi integer data type hai.

    stack<short> shortStack;

    shortStack.push(10);
    shortStack.push(20);
    shortStack.push(30);

    cout << "short stack top: "
         << shortStack.top() << endl;

    // ============================================================
    // 9. STACK OF unsigned int
    // ============================================================
    //
    // unsigned int non-negative integer values ke liye
    // use kiya ja sakta hai.
    //
    // Negative values ke case mein signed/unsigned conversion
    // ko carefully handle karna chahiye.

    stack<unsigned int> unsignedStack;

    unsignedStack.push(10);
    unsignedStack.push(20);
    unsignedStack.push(30);

    cout << "unsigned int stack top: "
         << unsignedStack.top() << endl;

    // ============================================================
    // 10. STACK OF pair<int, int>
    // ============================================================
    //
    // Stack ke andar pair bhi store kar sakte hain.
    //
    // pair<int, int> ke andar do values hoti hain:
    //
    // first
    // second
    //
    // Syntax:
    //
    // stack<pair<int, int>> st;

    stack<pair<int, int>> pairStack;

    // Pairs push karna.

    pairStack.push({1, 100});
    pairStack.push({2, 200});
    pairStack.push({3, 300});

    // TOP pair:
    //
    // {3, 300}

    // first value:
    cout << "pair stack top first: "
         << pairStack.top().first << endl;

    // second value:
    cout << "pair stack top second: "
         << pairStack.top().second << endl;

    // ============================================================
    // 11. STACK OF vector<int>
    // ============================================================
    //
    // Stack ke har element ko vector<int> bhi bana sakte hain.
    //
    // Syntax:
    //
    // stack<vector<int>> st;
    //
    // Iska matlab:
    //
    // Har stack element ek complete vector<int> hai.

    stack<vector<int>> vectorStack;

    // Vectors push karna.

    vectorStack.push({1, 2, 3});
    vectorStack.push({4, 5});
    vectorStack.push({6, 7, 8, 9});

    // Current stack:
    //
    // TOP
    //  ↓
    // [6, 7, 8, 9]
    // [4, 5]
    // [1, 2, 3]

    // ============================================================
    // ACCESS TOP VECTOR
    // ============================================================

    // vectorStack.top() ek vector<int> return karta hai.
    //
    // const reference use kar rahe hain:
    //
    // const vector<int>& current
    //
    // const:
    // -> vector modify nahi karenge.
    //
    // &:
    // -> unnecessary copy nahi banegi.

    const vector<int> &current = vectorStack.top();

    cout << "Top vector: ";

    for (int x : current)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 12. STACK OF vector<string>
    // ============================================================
    //
    // Nested types bhi possible hain.
    //
    // stack<vector<string>>
    //
    // means:
    //
    // Stack ka har element ek vector<string> hai.

    stack<vector<string>> namesStack;

    namesStack.push({"Rahul", "Aman"});
    namesStack.push({"Priya", "Riya"});
    namesStack.push({"Vikas", "Neha"});

    // TOP vector:
    //
    // ["Vikas", "Neha"]

    cout << "Top vector<string>: ";

    const vector<string> &names = namesStack.top();

    for (const string &name : names)
    {
        cout << name << " ";
    }

    cout << endl;

    // ============================================================
    // 13. STACK OF CUSTOM STRUCT
    // ============================================================
    //
    // Hum apna khud ka data type bana kar bhi stack mein
    // store kar sakte hain.
    //
    // Example:
    //
    // Student structure

    struct Student
    {
        string name;
        int age;
    };

    // Student objects ki stack.

    stack<Student> studentStack;

    studentStack.push({"Rahul", 20});
    studentStack.push({"Aman", 21});
    studentStack.push({"Priya", 19});

    // TOP:
    //
    // Student = Priya
    // Age = 19

    cout << "Top Student Name: "
         << studentStack.top().name << endl;

    cout << "Top Student Age: "
         << studentStack.top().age << endl;

    // ============================================================
    // STACK OF stack<int>
    // ============================================================
    //
    // Ek stack ke andar doosra stack bhi store kar sakte hain.
    //
    // Syntax:
    //
    // stack<stack<int>> outerStack;
    //
    // Ye advanced nested data structure hai.

    stack<stack<int>> outerStack;

    // First inner stack.

    stack<int> first;

    first.push(10);
    first.push(20);

    // Second inner stack.

    stack<int> second;

    second.push(30);
    second.push(40);

    // Inner stacks ko outer stack mein add karo.

    outerStack.push(first);
    outerStack.push(second);

    // Outer stack:
    //
    // TOP
    //  ↓
    // [inner stack: 30,40]
    // [inner stack: 10,20]

    // ============================================================
    // PROCESSING STACK OF STACKS
    // ============================================================

    cout << "\nStack of stacks:\n";

    while (!outerStack.empty())
    {
        // Current inner stack ko copy kar rahe hain.
        //
        // Reason:
        //
        // Hum is inner stack ke elements ko pop karenge,
        // but outer stack ke stored object ko directly
        // modify karne ki zaroorat nahi hai.

        stack<int> currentStack = outerStack.top();

        cout << "Inner stack: ";

        while (!currentStack.empty())
        {
            cout << currentStack.top() << " ";

            currentStack.pop();
        }

        cout << endl;

        // Outer stack se current inner stack remove karo.

        outerStack.pop();
    }

    // ============================================================
    // TRAVERSING / PROCESSING A STACK
    // ============================================================
    //
    // Important:
    //
    // Standard stack mein public begin() / end() iterators
    // nahi hote.
    //
    // Isliye:
    //
    // st.begin()  // ❌
    // st.end()    // ❌
    //
    // Instead:
    //
    // while (!st.empty())
    // {
    //     cout << st.top();
    //     st.pop();
    // }
    //
    // use karte hain.

    // ============================================================
    // ORIGINAL STACK KO PRESERVE KARNA
    // ============================================================
    //
    // Agar hum directly pop karenge:
    //
    // stack empty ho jayega.
    //
    // Original stack preserve karne ke liye copy banao.

    stack<int> originalStack;

    originalStack.push(10);
    originalStack.push(20);
    originalStack.push(30);

    // Copy.

    stack<int> tempStack = originalStack;

    cout << "\nOriginal stack elements: ";

    // tempStack ko process karenge,
    // originalStack unchanged rahega.

    while (!tempStack.empty())
    {
        cout << tempStack.top() << " ";

        tempStack.pop();
    }

    cout << endl;

    // Check original stack size.

    cout << "Original stack size: "
         << originalStack.size() << endl;

    // Output:
    //
    // Original stack size: 3

    // ============================================================
    // stack<T> MEIN T KYA HO SAKTA HAI?
    // ============================================================
    //
    // Basic idea:
    //
    // stack<T>
    //
    // T = element ka type.
    //
    // Common examples:
    //
    // stack<int>
    // stack<float>
    // stack<double>
    // stack<char>
    // stack<bool>
    // stack<string>
    // stack<long long>
    // stack<pair<int,int>>
    // stack<vector<int>>
    // stack<Student>
    //
    // Yani T sirf int ya primitive type nahi hona chahiye.
    // Suitable C++ types ko bhi stack mein store kar sakte hain.

    // ============================================================
    // MOST IMPORTANT DSA STACK TYPES
    // ============================================================
    //
    // DSA mein sabse commonly:
    //
    // 1. stack<int>
    // 2. stack<char>
    // 3. stack<string>
    // 4. stack<pair<int,int>>
    // 5. stack<long long>
    //
    // Advanced:
    //
    // 6. stack<vector<int>>
    // 7. stack<CustomStruct>

    // ============================================================
    // IMPORTANT STACK OPERATIONS
    // ============================================================
    //
    // push():
    // -> TOP par new element add karta hai.
    //
    // pop():
    // -> TOP element remove karta hai.
    //
    // top():
    // -> TOP element return karta hai.
    //
    // size():
    // -> total number of elements.
    //
    // empty():
    // -> check karta hai stack empty hai ya nahi.
    //
    // swap():
    // -> two stacks ke contents exchange karta hai.

    // ============================================================
    // IMPORTANT SAFETY RULE
    // ============================================================
    //
    // Empty stack par:
    //
    // st.top();
    //
    // ❌ invalid
    //
    // st.pop();
    //
    // ❌ invalid
    //
    // Pehle:
    //
    // if (!st.empty())
    // {
    //     cout << st.top();
    // }
    //
    // use karo.

    // ============================================================
    // FINAL CHEAT SHEET
    // ============================================================

    /*
        stack<int>
        --------------------------
        Integers


        stack<float>
        --------------------------
        Float decimal values


        stack<double>
        --------------------------
        Double decimal values


        stack<char>
        --------------------------
        Characters


        stack<bool>
        --------------------------
        true / false


        stack<string>
        --------------------------
        Strings


        stack<long long>
        --------------------------
        Large integers


        stack<pair<int,int>>
        --------------------------
        Pairs


        stack<vector<int>>
        --------------------------
        Vectors


        stack<Student>
        --------------------------
        Custom objects
    */

    return 0;
}