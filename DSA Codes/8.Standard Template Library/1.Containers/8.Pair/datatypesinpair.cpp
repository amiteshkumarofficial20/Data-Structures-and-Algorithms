#include <iostream>
#include <utility>       // std::pair, std::make_pair
#include <string>        // std::string
#include <vector>        // std::vector
#include <list>          // std::list
#include <set>           // std::set
#include <map>           // std::map
#include <unordered_map> // std::unordered_map

using namespace std;

int main()
{
     // ============================================================
     //                    STL : std::pair
     // ============================================================
     //
     // std::pair C++ STL ka ek utility class/template hai.
     //
     // Iska main purpose:
     //
     //      DO values ko ek single object ke andar store karna.
     //
     //
     // General syntax:
     //
     //      pair<Type1, Type2> variableName;
     //
     //
     // Example:
     //
     //      pair<int, string> student;
     //
     //
     // Yahan:
     //
     //      int
     //          -> first value ka data type
     //
     //      string
     //          -> second value ka data type
     //
     //      student
     //          -> pair ka variable
     //
     //
     // Internally conceptually:
     //
     //              pair
     //             /    \
    //            /      \
    //        first      second
     //          |           |
     //        int         string
     //
     //
     // Example value:
     //
     //      {101, "Rahul"}
     //
     //
     // Is pair mein:
     //
     //      first  = 101
     //      second = "Rahul"
     //
     // ============================================================

     // ============================================================
     // IMPORTANT:
     // PAIR MEIN KITNI VALUES HOTI HAIN?
     // ============================================================
     //
     // std::pair EXACTLY TWO values ko represent karta hai.
     //
     //      pair<T1, T2>
     //
     // Isliye:
     //
     //      T1 -> first
     //      T2 -> second
     //
     //
     // Agar tumhe 3 values store karni hain:
     //
     //      pair<int, int, int>
     //
     // WRONG hai.
     //
     // pair sirf TWO template type parameters accept karta hai.
     //
     // Lekin nested pair ka use karke indirectly more values
     // store kar sakte hain.
     //
     // Uska example neeche diya gaya hai.
     //
     // ============================================================

     // ============================================================
     // 1. pair<int, int>
     // ============================================================
     //
     // Dono values int ho sakti hain.
     //
     // Example:
     //
     //      pair<int, int> p;
     //
     // first  -> int
     // second -> int
     //
     // Useful examples:
     //
     //      coordinates
     //      ranges
     //      indices
     //      graph edges
     //      min/max values
     //
     //
     // Example:
     //
     //      (10, 20)
     //
     // ============================================================

     pair<int, int> p1 = {10, 20};

     cout << "========== pair<int, int> ==========" << endl;

     cout << "first  = "
          << p1.first
          << endl;

     cout << "second = "
          << p1.second
          << endl;

     // ============================================================
     // 2. pair<int, string>
     // ============================================================
     //
     // First value int hai.
     //
     // Second value string hai.
     //
     // Example:
     //
     //      Student ID + Student Name
     //
     //      {101, "Rahul"}
     //
     // ============================================================

     pair<int, string> p2 = {101, "Rahul"};

     cout << "\n========== pair<int, string> ==========" << endl;

     cout << "ID   = "
          << p2.first
          << endl;

     cout << "Name = "
          << p2.second
          << endl;

     // ============================================================
     // 3. pair<string, int>
     // ============================================================
     //
     // Order important hai.
     //
     //      pair<int, string>
     //
     // aur:
     //
     //      pair<string, int>
     //
     // SAME nahi hain.
     //
     //
     // pair<int, string>:
     //
     //      first  -> int
     //      second -> string
     //
     //
     // pair<string, int>:
     //
     //      first  -> string
     //      second -> int
     //
     //
     // Example:
     //
     //      {"Rahul", 101}
     //
     // ============================================================

     pair<string, int> p3 = {"Rahul", 101};

     cout << "\n========== pair<string, int> ==========" << endl;

     cout << "Name = "
          << p3.first
          << endl;

     cout << "ID   = "
          << p3.second
          << endl;

     // ============================================================
     // 4. pair<string, string>
     // ============================================================
     //
     // Dono values string ho sakti hain.
     //
     // Example:
     //
     //      First Name + Last Name
     //
     //      {"Amit", "Sharma"}
     //
     // ============================================================

     pair<string, string> p4 = {"Amit", "Sharma"};

     cout << "\n========== pair<string, string> ==========" << endl;

     cout << "First name = "
          << p4.first
          << endl;

     cout << "Last name  = "
          << p4.second
          << endl;

     // ============================================================
     // 5. pair<double, double>
     // ============================================================
     //
     // Decimal values bhi pair mein store kar sakte hain.
     //
     // Example:
     //
     //      latitude + longitude
     //
     //      {26.4499, 80.3319}
     //
     // ============================================================

     pair<double, double> p5 = {26.4499, 80.3319};

     cout << "\n========== pair<double, double> ==========" << endl;

     cout << "First  = "
          << p5.first
          << endl;

     cout << "Second = "
          << p5.second
          << endl;

     // ============================================================
     // 6. pair<float, float>
     // ============================================================
     //
     // float bhi use kar sakte hain.
     //
     // ============================================================

     pair<float, float> p6 = {10.5f, 20.5f};

     cout << "\n========== pair<float, float> ==========" << endl;

     cout << "first  = "
          << p6.first
          << endl;

     cout << "second = "
          << p6.second
          << endl;

     // ============================================================
     // 7. pair<char, char>
     // ============================================================
     //
     // char bhi pair ka data type ho sakta hai.
     //
     // Example:
     //
     //      starting character
     //      ending character
     //
     // ============================================================

     pair<char, char> p7 = {'A', 'Z'};

     cout << "\n========== pair<char, char> ==========" << endl;

     cout << "first  = "
          << p7.first
          << endl;

     cout << "second = "
          << p7.second
          << endl;

     // ============================================================
     // 8. pair<bool, bool>
     // ============================================================
     //
     // bool values bhi store kar sakte hain.
     //
     // bool ki possible values:
     //
     //      true
     //      false
     //
     // ============================================================

     pair<bool, bool> p8 = {true, false};

     cout << "\n========== pair<bool, bool> ==========" << endl;

     cout << boolalpha;

     cout << "first  = "
          << p8.first
          << endl;

     cout << "second = "
          << p8.second
          << endl;

     // ============================================================
     // 9. MIXED DATA TYPES
     // ============================================================
     //
     // Pair ke dono types SAME hona compulsory nahi hai.
     //
     // Ye bahut important point hai.
     //
     //
     // Valid:
     //
     //      pair<int, string>
     //      pair<string, double>
     //      pair<char, int>
     //      pair<bool, string>
     //      pair<float, string>
     //
     //
     // Example:
     //
     //      pair<string, double>
     //
     //      {"Price", 99.99}
     //
     // ============================================================

     pair<string, double> p9 = {"Price", 99.99};

     cout << "\n========== pair<string, double> ==========" << endl;

     cout << "first  = "
          << p9.first
          << endl;

     cout << "second = "
          << p9.second
          << endl;

     // ============================================================
     // 10. pair WITH const char*
     // ============================================================
     //
     // String literal ka type technically const char[] hota hai.
     //
     // Lekin commonly:
     //
     //      pair<int, const char*>
     //
     // bhi use kar sakte hain.
     //
     // ============================================================

     pair<int, const char *> p10 = {101, "Rahul"};

     cout << "\n========== pair<int, const char*> ==========" << endl;

     cout << "first  = "
          << p10.first
          << endl;

     cout << "second = "
          << p10.second
          << endl;

     // ============================================================
     // 11. pair WITH VECTOR
     // ============================================================
     //
     // Pair ke andar STL container bhi rakh sakte hain.
     //
     // Example:
     //
     //      pair<vector<int>, vector<int>>
     //
     // first  -> vector<int>
     // second -> vector<int>
     //
     // ============================================================

     pair<vector<int>, vector<int>> p11;

     p11.first = {10, 20, 30};

     p11.second = {40, 50, 60};

     cout << "\n========== pair<vector<int>, vector<int>> ==========" << endl;

     cout << "First vector: ";

     for (int x : p11.first)
     {
          cout << x << " ";
     }

     cout << endl;

     cout << "Second vector: ";

     for (int x : p11.second)
     {
          cout << x << " ";
     }

     cout << endl;

     // ============================================================
     // 12. pair<vector<int>, string>
     // ============================================================
     //
     // First ek vector ho sakta hai.
     //
     // Second string ho sakta hai.
     //
     // Example:
     //
     //      vector of marks + student name
     //
     // ============================================================

     pair<vector<int>, string> p12;

     p12.first = {90, 85, 95};

     p12.second = "Amit";

     cout << "\n========== pair<vector<int>, string> ==========" << endl;

     cout << "Name = "
          << p12.second
          << endl;

     cout << "Marks = ";

     for (int marks : p12.first)
     {
          cout << marks << " ";
     }

     cout << endl;

     // ============================================================
     // 13. pair WITH LIST
     // ============================================================
     //
     // STL list bhi pair ka data type ho sakti hai.
     //
     // ============================================================

     pair<list<int>, string> p13;

     p13.first = {10, 20, 30};

     p13.second = "Numbers";

     cout << "\n========== pair<list<int>, string> ==========" << endl;

     cout << "Name = "
          << p13.second
          << endl;

     cout << "List = ";

     for (int x : p13.first)
     {
          cout << x << " ";
     }

     cout << endl;

     // ============================================================
     // 14. pair WITH SET
     // ============================================================
     //
     // set bhi pair ke andar store ho sakta hai.
     //
     // ============================================================

     pair<set<int>, string> p14;

     p14.first = {30, 10, 20};

     p14.second = "Set";

     cout << "\n========== pair<set<int>, string> ==========" << endl;

     cout << "Name = "
          << p14.second
          << endl;

     cout << "Set = ";

     for (int x : p14.first)
     {
          cout << x << " ";
     }

     cout << endl;

     // ============================================================
     // 15. pair WITH MAP
     // ============================================================
     //
     // Pair ke andar map bhi store kar sakte hain.
     //
     // Example:
     //
     //      pair<map<int,string>, int>
     //
     // ============================================================

     pair<map<int, string>, int> p15;

     p15.first[1] = "Aman";
     p15.first[2] = "Rahul";
     p15.first[3] = "Riya";

     p15.second = 3;

     cout << "\n========== pair<map<int,string>, int> ==========" << endl;

     cout << "Number of students = "
          << p15.second
          << endl;

     cout << "Students:" << endl;

     for (const auto &x : p15.first)
     {
          cout << x.first
               << " -> "
               << x.second
               << endl;
     }

     // ============================================================
     // 16. pair WITH unordered_map
     // ============================================================
     //
     // unordered_map bhi pair ke andar use ho sakta hai.
     //
     // ============================================================

     pair<unordered_map<int, string>, string> p16;

     p16.first[101] = "Amit";
     p16.first[102] = "Rahul";

     p16.second = "Students";

     cout << "\n========== pair<unordered_map<int,string>, string> ==========" << endl;

     cout << "Type = "
          << p16.second
          << endl;

     for (const auto &x : p16.first)
     {
          cout << x.first
               << " -> "
               << x.second
               << endl;
     }

     // ============================================================
     // 17. NESTED PAIR
     // ============================================================
     //
     // Pair ke andar another pair bhi store kar sakte hain.
     //
     // Example:
     //
     //      pair<int, pair<int, int>>
     //
     //
     // Ismein:
     //
     //      first
     //          -> int
     //
     //      second
     //          -> pair<int, int>
     //
     //
     // Example:
     //
     //      {1, {10, 20}}
     //
     //
     // Conceptually:
     //
     //              pair
     //             /    \
    //            /      \
    //           1       pair
     //                  /    \
    //                10      20
     //
     // ============================================================

     pair<int, pair<int, int>> p17 = {1, {10, 20}};

     cout << "\n========== Nested Pair ==========" << endl;

     cout << "Outer first = "
          << p17.first
          << endl;

     cout << "Inner first = "
          << p17.second.first
          << endl;

     cout << "Inner second = "
          << p17.second.second
          << endl;

     // ============================================================
     // 18. pair<pair<int,int>, pair<int,int>>
     // ============================================================
     //
     // Pair ke first aur second dono khud pair ho sakte hain.
     //
     // Example:
     //
     //      pair<
     //          pair<int,int>,
     //          pair<int,int>
     //      >
     //
     //
     // Value:
     //
     //      {{10,20}, {30,40}}
     //
     // ============================================================

     pair<pair<int, int>, pair<int, int>> p18 =
         {
             {10, 20},
             {30, 40}};

     cout << "\n========== pair<pair<int,int>, pair<int,int>> ==========" << endl;

     cout << "First pair first = "
          << p18.first.first
          << endl;

     cout << "First pair second = "
          << p18.first.second
          << endl;

     cout << "Second pair first = "
          << p18.second.first
          << endl;

     cout << "Second pair second = "
          << p18.second.second
          << endl;

     // ============================================================
     // 19. pair OF pair AND STRING
     // ============================================================
     //
     // Nested combinations bahut flexible hote hain.
     //
     // Example:
     //
     //      pair<pair<int,int>, string>
     //
     // ============================================================

     pair<pair<int, int>, string> p19 =
         {
             {10, 20},
             "Coordinates"};

     cout << "\n========== pair<pair<int,int>, string> ==========" << endl;

     cout << "X = "
          << p19.first.first
          << endl;

     cout << "Y = "
          << p19.first.second
          << endl;

     cout << "Description = "
          << p19.second
          << endl;

     // ============================================================
     // 20. PAIR WITH POINTER
     // ============================================================
     //
     // Pointer bhi ek valid C++ type hai.
     //
     // Isliye pair mein pointer bhi store kar sakte hain.
     //
     // Example:
     //
     //      pair<int*, int*>
     //
     // ============================================================

     int a = 100;
     int b = 200;

     pair<int *, int *> p20 = {&a, &b};

     cout << "\n========== pair<int*, int*> ==========" << endl;

     cout << "First pointed value = "
          << *p20.first
          << endl;

     cout << "Second pointed value = "
          << *p20.second
          << endl;

     // ============================================================
     // 21. PAIR WITH REFERENCE
     // ============================================================
     //
     // IMPORTANT:
     //
     // std::pair ke template parameters normally reference types
     // ke saath directly store nahi kiye jaate in the same way as
     // ordinary objects.
     //
     // Example:
     //
     //      pair<int&, int&>
     //
     // technically possible type hai, lekin iske saath assignment
     // aur copy behavior unusual ho sakta hai.
     //
     // Practical programming mein references ko pair ke saath
     // handle karne ke liye std::reference_wrapper useful hota hai.
     //
     // ============================================================

     // ============================================================
     // 22. pair WITH reference_wrapper
     // ============================================================
     //
     // reference_wrapper ko use karne ke liye:
     //
     //      #include <functional>
     //
     // chahiye.
     //
     // Is example mein simplicity ke liye hum sirf concept
     // explain kar rahe hain.
     //
     // Practical form:
     //
     //      pair<reference_wrapper<int>,
     //           reference_wrapper<int>>
     //
     //
     // Ye pair ke andar references jaisa behavior provide kar sakta
     // hai while remaining assignable/copyable as wrapper objects.
     //
     // ============================================================

     // ============================================================
     // 23. pair WITH CUSTOM CLASS / STRUCT
     // ============================================================
     //
     // Pair mein sirf built-in data types hi use karna compulsory nahi.
     //
     // Tum apni khud ki class ya struct bhi pair ke andar
     // store kar sakte ho.
     //
     // Example:
     //
     //      struct Student
     //      {
     //          int id;
     //          string name;
     //      };
     //
     //
     // Then:
     //
     //      pair<Student, int>
     //
     // valid hai.
     //
     // ============================================================

     // ============================================================
     // 24. PAIR DATA TYPE CAN BE ALMOST ANY VALID C++ TYPE
     // ============================================================
     //
     // General rule:
     //
     //      pair<T1, T2>
     //
     // mein T1 aur T2 almost any suitable C++ type ho sakte hain.
     //
     //
     // Examples:
     //
     //      pair<int, int>
     //      pair<int, double>
     //      pair<int, string>
     //      pair<string, int>
     //      pair<string, string>
     //      pair<char, int>
     //      pair<bool, string>
     //      pair<float, double>
     //      pair<vector<int>, int>
     //      pair<list<int>, string>
     //      pair<set<int>, string>
     //      pair<map<int,string>, int>
     //      pair<int, pair<int,int>>
     //      pair<pair<int,int>, string>
     //
     //
     // Basically:
     //
     //      T1
     //      T2
     //
     // are independently selected types.
     //
     // ============================================================

     // ============================================================
     // 25. FIRST AND SECOND
     // ============================================================
     //
     // Pair ke two public members hote hain:
     //
     //      first
     //      second
     //
     //
     // Example:
     //
     //      pair<int, string> student = {101, "Amit"};
     //
     //
     // Access:
     //
     //      student.first
     //
     // gives:
     //
     //      101
     //
     //
     // And:
     //
     //      student.second
     //
     // gives:
     //
     //      "Amit"
     //
     // ============================================================

     pair<int, string> student = {101, "Amit"};

     cout << "\n========== first and second ==========" << endl;

     cout << "first = "
          << student.first
          << endl;

     cout << "second = "
          << student.second
          << endl;

     // ============================================================
     // 26. MODIFYING first AND second
     // ============================================================
     //
     // Normal non-const pair ke first aur second members ko
     // modify kar sakte hain.
     //
     // ============================================================

     student.first = 202;

     student.second = "Rahul";

     cout << "\nAfter modification:" << endl;

     cout << "first = "
          << student.first
          << endl;

     cout << "second = "
          << student.second
          << endl;

     // ============================================================
     // 27. PAIR INITIALIZATION
     // ============================================================
     //
     // Pair ko initialize karne ke multiple common ways hain.
     //
     // ------------------------------------------------------------
     // METHOD 1:
     // ------------------------------------------------------------
     //
     //      pair<int,string> p = {101, "Amit"};
     //
     // ============================================================

     pair<int, string> p21 = {101, "Amit"};

     // ============================================================
     // METHOD 2:
     // CONSTRUCTOR STYLE
     // ============================================================

     pair<int, string> p22(102, "Rahul");

     // ============================================================
     // METHOD 3:
     // make_pair()
     // ============================================================
     //
     //      make_pair(value1, value2)
     //
     // compiler types deduce kar leta hai.
     //
     // ============================================================

     auto p23 = make_pair(103, string("Riya"));

     cout << "\n========== Initialization methods ==========" << endl;

     cout << p21.first << " "
          << p21.second
          << endl;

     cout << p22.first << " "
          << p22.second
          << endl;

     cout << p23.first << " "
          << p23.second
          << endl;

     // ============================================================
     // 28. AUTO WITH PAIR
     // ============================================================
     //
     // auto pair ka exact type automatically determine kar sakta hai.
     //
     // Example:
     //
     //      auto p = make_pair(10, 20);
     //
     // Compiler samjhega:
     //
     //      pair<int, int>
     //
     // ============================================================

     auto p24 = make_pair(10, 20);

     cout << "\n========== auto + pair ==========" << endl;

     cout << "first = "
          << p24.first
          << endl;

     cout << "second = "
          << p24.second
          << endl;

     // ============================================================
     // 29. PAIR WITH DIFFERENT INTEGER TYPES
     // ============================================================
     //
     // first aur second ka integer type different ho sakta hai.
     //
     // Example:
     //
     //      pair<int, long long>
     //
     // ============================================================

     pair<int, long long> p25 = {10, 10000000000LL};

     cout << "\n========== pair<int, long long> ==========" << endl;

     cout << "first = "
          << p25.first
          << endl;

     cout << "second = "
          << p25.second
          << endl;

     // ============================================================
     // 30. PAIR AS A FUNCTION RETURN TYPE
     // ============================================================
     //
     // Pair ka ek bahut important real-world use:
     //
     // Function se TWO related values return karna.
     //
     //
     // Example:
     //
     //      pair<int,int>
     //
     // function ek saath:
     //
     //      minimum
     //      maximum
     //
     // return kar sakta hai.
     //
     // ============================================================

     auto getMinMax = []()
     {
          int minimum = 10;
          int maximum = 100;

          return make_pair(minimum, maximum);
     };

     pair<int, int> minMax = getMinMax();

     cout << "\n========== Pair as return value ==========" << endl;

     cout << "Minimum = "
          << minMax.first
          << endl;

     cout << "Maximum = "
          << minMax.second
          << endl;

     // ============================================================
     // 31. PAIR IN VECTOR
     // ============================================================
     //
     // Ye DSA mein EXTREMELY IMPORTANT hai.
     //
     // Hum vector ke andar pairs store kar sakte hain:
     //
     //      vector<pair<int,int>>
     //
     //
     // Example:
     //
     //      vector<pair<int,int>> edges;
     //
     //
     // Graph mein:
     //
     //      {1,2}
     //      {2,3}
     //      {3,4}
     //
     // jaise edges represent karne ke liye useful.
     //
     // ============================================================

     vector<pair<int, int>> edges;

     edges.push_back({1, 2});
     edges.push_back({2, 3});
     edges.push_back({3, 4});

     cout << "\n========== vector<pair<int,int>> ==========" << endl;

     for (const auto &edge : edges)
     {
          cout << "("
               << edge.first
               << ", "
               << edge.second
               << ")"
               << endl;
     }

     // ============================================================
     // 32. ITERATING vector<pair<int,int>>
     // ============================================================
     //
     // Vector ke har element ka type:
     //
     //      pair<int,int>
     //
     //
     // Isliye:
     //
     //      edge.first
     //
     //      edge.second
     //
     // access kar sakte hain.
     //
     // ============================================================

     cout << "\nUsing range-based loop:" << endl;

     for (const auto &edge : edges)
     {
          cout << "First  = "
               << edge.first
               << ", Second = "
               << edge.second
               << endl;
     }

     // ============================================================
     // 33. MAP AND PAIR
     // ============================================================
     //
     // Ye DSA/STL ka MOST IMPORTANT pair concept hai.
     //
     // map ke andar har element conceptually:
     //
     //      pair<const Key, Value>
     //
     // hota hai.
     //
     //
     // Example:
     //
     //      map<int,string>
     //
     // elements:
     //
     //      {101, "Amit"}
     //      {102, "Rahul"}
     //      {103, "Riya"}
     //
     //
     // Isliye map ko iterate karte waqt:
     //
     //      x.first
     //
     // key deta hai.
     //
     //
     //      x.second
     //
     // value deta hai.
     //
     // ============================================================

     map<int, string> students;

     students[101] = "Amit";
     students[102] = "Rahul";
     students[103] = "Riya";

     cout << "\n========== map and pair ==========" << endl;

     for (const auto &x : students)
     {
          cout << "Key = "
               << x.first
               << ", Value = "
               << x.second
               << endl;
     }

     // ============================================================
     // 34. MAP ITERATOR + PAIR
     // ============================================================
     //
     // Map iterator current element par point karta hai.
     //
     // Current element:
     //
     //      *it
     //
     // Jo pair hota hai.
     //
     //
     // Therefore:
     //
     //      (*it).first
     //
     // aur:
     //
     //      (*it).second
     //
     //
     // Short syntax:
     //
     //      it->first
     //      it->second
     //
     // ============================================================

     map<int, string>::iterator it = students.begin();

     cout << "\n========== Map iterator + pair ==========" << endl;

     cout << "Key = "
          << it->first
          << endl;

     cout << "Value = "
          << it->second
          << endl;

     // ============================================================
     // 35. pair DOES NOT HAVE begin() AND end()
     // ============================================================
     //
     // VERY IMPORTANT:
     //
     // std::pair ko directly iterate nahi kar sakte.
     //
     //
     // Ye WRONG hai:
     //
     //      pair<int,int> p;
     //
     //      p.begin();
     //
     //
     // pair ek container nahi hai.
     //
     // Pair ke andar exactly:
     //
     //      first
     //      second
     //
     // hote hain.
     //
     //
     // Isliye pair ke liye:
     //
     //      p.first
     //      p.second
     //
     // use karo.
     //
     //
     // Lekin:
     //
     //      vector<pair<int,int>>
     //
     // ko iterate kar sakte hain,
     // kyunki vector container hai.
     //
     //
     // Aur:
     //
     //      map<int,string>
     //
     // ko iterate kar sakte hain,
     // kyunki map container hai aur uske elements pairs hote hain.
     //
     // ============================================================

     // ============================================================
     // 36. STRUCTURED BINDING - C++17
     // ============================================================
     //
     // Tum C++17 use kar rahe ho.
     //
     // Isliye pair ko directly unpack kar sakte ho.
     //
     //
     // Example:
     //
     //      pair<int,string> p = {101, "Amit"};
     //
     //      auto [id, name] = p;
     //
     //
     // Ab:
     //
     //      id
     //          -> p.first
     //
     //      name
     //          -> p.second
     //
     // ============================================================

     pair<int, string> p26 = {101, "Amit"};

     int id = p26.first;
     string name = p26.second;

     cout << "\n========== Structured Binding Alternative ==========" << endl;

     cout << "id   = "
          << id
          << endl;

     cout << "name = "
          << name
          << endl;

     // ============================================================
     // 37. STRUCTURED BINDING WITH MAP
     // ============================================================
     //
     // Since map ka element pair hota hai,
     // C++17 mein:
     //
     //      for (const auto &[key, value] : students)
     //
     // likh sakte hain.
     //
     //
     // key:
     //      pair.first
     //
     // value:
     //      pair.second
     //
     // ============================================================

     cout << "\n========== Structured Binding with map ==========" << endl;

     for (const auto &entry : students)
     {
          cout << "Key = "
               << entry.first
               << ", Value = "
               << entry.second
               << endl;
     }

     // ============================================================
     // 38. STRUCTURED BINDING WITH VECTOR OF PAIRS
     // ============================================================
     //
     // vector<pair<int,int>> mein bhi structured binding use kar
     // sakte hain.
     //
     // ============================================================

     cout << "\n========== Structured Binding with vector<pair> ==========" << endl;

     for (const auto &edge : edges)
     {
          cout << "("
               << edge.first
               << ", "
               << edge.second
               << ")"
               << endl;
     }

     // ============================================================
     // 39. PAIR COMPARISON
     // ============================================================
     //
     // Pairs ko compare bhi kar sakte hain.
     //
     // Pair comparison LEXICOGRAPHICAL ORDER mein hoti hai.
     //
     //
     // Example:
     //
     //      pair<int,int> a = {10,20};
     //      pair<int,int> b = {10,30};
     //
     //
     // First compare:
     //
     //      a.first
     //      b.first
     //
     //
     // Agar first equal hain,
     // tab second compare hota hai.
     //
     //
     // Since:
     //
     //      10 == 10
     //
     // second compare hoga:
     //
     //      20 < 30
     //
     // Therefore:
     //
     //      a < b
     //
     // true hoga.
     //
     // ============================================================

     pair<int, int> pairA = {10, 20};

     pair<int, int> pairB = {10, 30};

     cout << "\n========== Pair comparison ==========" << endl;

     if (pairA < pairB)
     {
          cout << "pairA is smaller than pairB"
               << endl;
     }

     // ============================================================
     // 40. PAIR SORTING
     // ============================================================
     //
     // vector<pair<int,int>> ko sort karne par default comparison
     // pair ki lexicographical ordering follow karta hai.
     //
     //
     // Example:
     //
     //      {2, 50}
     //      {1, 100}
     //      {2, 20}
     //
     //
     // Sorting ke baad:
     //
     //      {1, 100}
     //      {2, 20}
     //      {2, 50}
     //
     //
     // Pehle first compare hota hai.
     //
     // Agar first equal ho,
     // to second compare hota hai.
     //
     // ============================================================

     // ============================================================
     // 41. COMMON PAIR TYPES FOR DSA
     // ============================================================
     //
     // DSA mein tumhe frequently ye pair types milenge:
     //
     //
     // ------------------------------------------------------------
     // pair<int, int>
     // ------------------------------------------------------------
     //
     // Common uses:
     //
     //      coordinates
     //      graph edges
     //      ranges
     //      index pairs
     //      min/max
     //
     //
     // ------------------------------------------------------------
     // pair<int, string>
     // ------------------------------------------------------------
     //
     // Common use:
     //
     //      ID + Name
     //
     //
     // ------------------------------------------------------------
     // pair<string, int>
     // ------------------------------------------------------------
     //
     // Common use:
     //
     //      Name + Frequency
     //      Word + Count
     //
     //
     // ------------------------------------------------------------
     // pair<int, pair<int,int>>
     // ------------------------------------------------------------
     //
     // Common use:
     //
     //      weighted graph
     //      priority queue problems
     //      multiple related values
     //
     //
     // Example:
     //
     //      {weight, {node1, node2}}
     //
     //
     // ------------------------------------------------------------
     // vector<pair<int,int>>
     // ------------------------------------------------------------
     //
     // Very common in:
     //
     //      Graph
     //      Coordinates
     //      Intervals
     //      Sorting problems
     //
     //
     // ------------------------------------------------------------
     // map<int,int>
     // ------------------------------------------------------------
     //
     // Map ke elements pairs hote hain:
     //
     //      pair<const int, int>
     //
     //
     // ============================================================

     // ============================================================
     // 42. PAIR VS TUPLE
     // ============================================================
     //
     // pair:
     //
     //      EXACTLY 2 values
     //
     //
     // tuple:
     //
     //      2, 3, 4, ... multiple values
     //
     //
     // Example:
     //
     //      pair<int,string>
     //
     // versus:
     //
     //      tuple<int,string,double>
     //
     //
     // Agar exactly TWO related values hain,
     // pair simple aur readable choice hota hai.
     //
     // Agar TWO se zyada values hain,
     // tuple ya custom struct/class better ho sakta hai.
     //
     // ============================================================

     // ============================================================
     // 43. MOST IMPORTANT SYNTAX CHEAT SHEET
     // ============================================================
     //
     /*

         Create:

             pair<int, int> p;


         Initialize:

             pair<int, int> p = {10, 20};


         Constructor:

             pair<int, int> p(10, 20);


         make_pair:

             auto p = make_pair(10, 20);


         First:

             p.first


         Second:

             p.second


         Modify:

             p.first = 100;
             p.second = 200;


         Nested pair:

             pair<int, pair<int,int>> p;


         Vector of pairs:

             vector<pair<int,int>> v;


         Map:

             map<int,string> m;


         Map element:

             pair<const int, string>


         Map iterator:

             map<int,string>::iterator it;


         Map key:

             it->first


         Map value:

             it->second


         Range-based:

             for (const auto &x : v)
             {
                 cout << x.first;
                 cout << x.second;
             }


         C++17 structured binding:

             for (const auto &p : v)
             {
                 cout << p.first;
                 cout << p.second;
             }

     */

     // ============================================================
     // 44. FINAL CONCEPT
     // ============================================================
     //
     // Pair ka sabse important concept:
     //
     //
     //      pair<T1, T2>
     //
     //
     // Yahan T1 aur T2 independently choose kiye jaate hain.
     //
     //
     // Example:
     //
     //      pair<int, string>
     //
     //          T1 = int
     //          T2 = string
     //
     //
     //      pair<double, char>
     //
     //          T1 = double
     //          T2 = char
     //
     //
     //      pair<vector<int>, string>
     //
     //          T1 = vector<int>
     //          T2 = string
     //
     //
     //      pair<int, pair<int,int>>
     //
     //          T1 = int
     //          T2 = pair<int,int>
     //
     //
     // So pair ke first aur second ka type same hona
     // REQUIRED nahi hai.
     //
     //
     // Pair ka basic mental model:
     //
     //
     //                  pair<T1, T2>
     //                       |
     //              -----------------
     //              |               |
     //           first           second
     //              |               |
     //             T1              T2
     //
     //
     // Example:
     //
     //              pair<int, string>
     //                       |
     //              -----------------
     //              |               |
     //            first           second
     //              |               |
     //             101            "Amit"
     //
     //
     // ============================================================

     cout << "\n========================================" << endl;
     cout << "       PAIR CONCEPT COMPLETED          " << endl;
     cout << "========================================" << endl;

     return 0;
}