#include <iostream>
#include <set>        // std::set
#include <string>     // std::string
#include <vector>     // std::vector
#include <utility>    // std::pair
#include <functional> // std::greater
#include <iterator>   // std::distance
#include <algorithm>  // std::for_each

using namespace std;

int main()
{
    // ============================================================
    //                    STL : std::set
    // ============================================================
    //
    // std::set C++ STL ka ek associative container hai.
    //
    // std::set ka main purpose:
    //
    //      UNIQUE values ko SORTED ORDER mein store karna.
    //
    //
    // Example:
    //
    //      set<int> s = {40, 10, 30, 20, 10};
    //
    //
    // Final set:
    //
    //      10 20 30 40
    //
    //
    // Notice:
    //
    //      10 do baar insert hua,
    //      lekin set mein 10 sirf ek baar store hua.
    //
    //
    // ============================================================
    // IMPORTANT PROPERTIES OF SET
    // ============================================================
    //
    // 1. Elements UNIQUE hote hain.
    //
    // 2. Elements automatically SORTED hote hain.
    //
    // 3. Default sorting ascending order mein hoti hai.
    //
    // 4. Duplicate elements store nahi hote.
    //
    // 5. set mein random indexing nahi hoti.
    //
    //      s[0]       // WRONG
    //
    // 6. Elements ko iterators ke through access karte hain.
    //
    // 7. Search / insertion / deletion generally:
    //
    //      O(log n)
    //
    // 8. set associative container hai.
    //
    // 9. set internally balanced search-tree based implementation
    //    provide karta hai. Exact implementation standard द्वारा
    //    fixed nahi hai, but complexity guarantees ordered tree
    //    behavior ke saath match karti hain.
    //
    // ============================================================

    // ============================================================
    // 1. HEADER FILE
    // ============================================================
    //
    // std::set use karne ke liye:
    //
    //      #include <set>
    //
    // required hai.
    //
    // Humne upar:
    //
    //      #include <set>
    //
    // include kiya hai.
    //
    // ============================================================

    // ============================================================
    // 2. BASIC SYNTAX
    // ============================================================
    //
    // General syntax:
    //
    //      set<DataType> variableName;
    //
    //
    // Examples:
    //
    //      set<int> numbers;
    //      set<double> prices;
    //      set<char> letters;
    //      set<string> names;
    //
    //
    // Yahan:
    //
    //      set
    //          -> STL container
    //
    //      DataType
    //          -> set ke elements ka type
    //
    //      variableName
    //          -> set ka variable
    //
    // ============================================================

    // ============================================================
    // 3. set<int>
    // ============================================================
    //
    // Sabse common set type:
    //
    //      set<int>
    //
    // Ismein integers store hote hain.
    //
    // Example:
    //
    //      set<int> numbers;
    //
    // ============================================================

    set<int> s1;

    cout << "========== set<int> ==========" << endl;

    s1.insert(50);
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);

    for (int x : s1)
    {
        cout << x << " ";
    }

    cout << endl;

    // Output:
    //
    //      10 20 30 40 50
    //
    // Notice:
    //
    // Humne values random order mein insert ki,
    // lekin set sorted order mein print karta hai.

    // ============================================================
    // 4. set<string>
    // ============================================================
    //
    // set strings bhi store kar sakta hai.
    //
    // Strings default comparison ke according sorted hoti hain.
    //
    // ============================================================

    set<string> names;

    names.insert("Rahul");
    names.insert("Amit");
    names.insert("Riya");
    names.insert("Aman");

    cout << "\n========== set<string> ==========" << endl;

    for (const string &name : names)
    {
        cout << name << endl;
    }

    // ============================================================
    // 5. set<char>
    // ============================================================
    //
    // set mein char values bhi store kar sakte hain.
    //
    // ============================================================

    set<char> letters;

    letters.insert('Z');
    letters.insert('A');
    letters.insert('C');
    letters.insert('B');
    letters.insert('A');

    cout << "\n========== set<char> ==========" << endl;

    for (char ch : letters)
    {
        cout << ch << " ";
    }

    cout << endl;

    // Output:
    //
    //      A B C Z
    //
    // Duplicate A ignore ho gaya.

    // ============================================================
    // 6. set<double>
    // ============================================================
    //
    // Decimal values bhi store kar sakte hain.
    //
    // ============================================================

    set<double> decimals = {
        3.14,
        1.5,
        2.7,
        1.5,
        4.8};

    cout << "\n========== set<double> ==========" << endl;

    for (double value : decimals)
    {
        cout << value << " ";
    }

    cout << endl;

    // ============================================================
    // 7. set<long long>
    // ============================================================
    //
    // Large integer values ke liye:
    //
    //      long long
    //
    // use kar sakte hain.
    //
    // ============================================================

    set<long long> largeNumbers = {
        10000000000LL,
        50000000000LL,
        20000000000LL,
        10000000000LL};

    cout << "\n========== set<long long> ==========" << endl;

    for (long long x : largeNumbers)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 8. DUPLICATE VALUES
    // ============================================================
    //
    // SET ka sabse important feature:
    //
    //      DUPLICATES ALLOWED NAHI HAIN.
    //
    //
    // Example:
    //
    //      set<int> s = {10, 20, 10, 30, 20};
    //
    //
    // Final:
    //
    //      10 20 30
    //
    // ============================================================

    set<int> duplicateSet;

    duplicateSet.insert(10);
    duplicateSet.insert(20);
    duplicateSet.insert(10);
    duplicateSet.insert(30);
    duplicateSet.insert(20);
    duplicateSet.insert(10);

    cout << "\n========== Duplicate Values ==========" << endl;

    for (int x : duplicateSet)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 9. INITIALIZATION AT DECLARATION
    // ============================================================
    //
    // Set ko directly initialize kar sakte hain:
    //
    //      set<int> s = {10, 20, 30};
    //
    // ============================================================

    set<int> s2 = {50, 10, 40, 20, 30};

    cout << "\n========== Direct Initialization ==========" << endl;

    for (int x : s2)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 10. INSERT()
    // ============================================================
    //
    // Syntax:
    //
    //      s.insert(value);
    //
    //
    // Example:
    //
    //      s.insert(100);
    //
    // Value automatically sorted position par insert hoti hai.
    //
    // ============================================================

    set<int> s3;

    s3.insert(40);
    s3.insert(10);
    s3.insert(30);
    s3.insert(20);

    cout << "\n========== insert() ==========" << endl;

    for (int x : s3)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 11. INSERTING DUPLICATE
    // ============================================================
    //
    // Agar value already exist karti hai:
    //
    //      s.insert(value);
    //
    // duplicate create nahi karega.
    //
    // Insert operation ka return type:
    //
    //      pair<iterator, bool>
    //
    //
    // bool:
    //
    //      true
    //          -> insertion successful
    //
    //      false
    //          -> value already existed
    //
    // ============================================================

    set<int> s4;

    auto result1 = s4.insert(10);

    cout << "\n========== Insert Return Value ==========" << endl;

    cout << "First insertion successful = "
         << boolalpha
         << result1.second
         << endl;

    auto result2 = s4.insert(10);

    cout << "Second insertion successful = "
         << result2.second
         << endl;

    // Output:
    //
    //      First insertion successful = true
    //      Second insertion successful = false

    // ============================================================
    // 12. INSERT RETURN TYPE
    // ============================================================
    //
    // set.insert(value) generally returns:
    //
    //      pair<iterator, bool>
    //
    //
    // first:
    //
    //      iterator
    //
    // second:
    //
    //      bool
    //
    //
    // Example:
    //
    //      auto result = s.insert(50);
    //
    //      result.first
    //          -> iterator
    //
    //      result.second
    //          -> insertion success/failure
    //
    // ============================================================

    set<int> s5;

    auto result3 = s5.insert(100);

    cout << "\n========== Insert Iterator ==========" << endl;

    cout << "Inserted value = "
         << *(result3.first)
         << endl;

    // ============================================================
    // 13. SIZE()
    // ============================================================
    //
    // size() set mein currently kitne elements hain,
    // ye return karta hai.
    //
    // Syntax:
    //
    //      s.size();
    //
    // Return type:
    //
    //      size_type
    //
    // ============================================================

    set<int> s6 = {10, 20, 30, 40, 50};

    cout << "\n========== size() ==========" << endl;

    cout << "Size = "
         << s6.size()
         << endl;

    // ============================================================
    // 14. EMPTY()
    // ============================================================
    //
    // empty() check karta hai ki set empty hai ya nahi.
    //
    // Return:
    //
    //      true
    //          -> set empty
    //
    //      false
    //          -> set contains elements
    //
    // ============================================================

    cout << "\n========== empty() ==========" << endl;

    if (s6.empty())
    {
        cout << "Set is empty." << endl;
    }
    else
    {
        cout << "Set is NOT empty." << endl;
    }

    // ============================================================
    // 15. CLEAR()
    // ============================================================
    //
    // clear() set ke saare elements remove kar deta hai.
    //
    // Syntax:
    //
    //      s.clear();
    //
    // ============================================================

    set<int> s7 = {10, 20, 30};

    cout << "\n========== clear() ==========" << endl;

    cout << "Before clear: "
         << s7.size()
         << endl;

    s7.clear();

    cout << "After clear: "
         << s7.size()
         << endl;

    // ============================================================
    // 16. FIND()
    // ============================================================
    //
    // find(value) set mein value search karta hai.
    //
    // Syntax:
    //
    //      s.find(value);
    //
    //
    // Agar value mil gayi:
    //
    //      iterator to element
    //
    // Agar nahi mili:
    //
    //      s.end()
    //
    // ============================================================

    set<int> s8 = {10, 20, 30, 40, 50};

    cout << "\n========== find() ==========" << endl;

    auto it1 = s8.find(30);

    if (it1 != s8.end())
    {
        cout << "30 found." << endl;
    }
    else
    {
        cout << "30 not found." << endl;
    }

    // ============================================================
    // 17. FIND() - VALUE NOT PRESENT
    // ============================================================

    auto it2 = s8.find(100);

    cout << "\n========== find() - Not Found ==========" << endl;

    if (it2 != s8.end())
    {
        cout << "100 found." << endl;
    }
    else
    {
        cout << "100 not found." << endl;
    }

    // ============================================================
    // 18. COUNT()
    // ============================================================
    //
    // count(value) check karta hai ki equivalent value present hai
    // ya nahi.
    //
    // std::set mein duplicates allowed nahi hote.
    //
    // Therefore:
    //
    //      count(value)
    //
    // normally:
    //
    //      0 or 1
    //
    // return karega.
    //
    // ============================================================

    cout << "\n========== count() ==========" << endl;

    cout << "Count of 20 = "
         << s8.count(20)
         << endl;

    cout << "Count of 100 = "
         << s8.count(100)
         << endl;

    // ============================================================
    // 19. ERASE BY VALUE
    // ============================================================
    //
    // Syntax:
    //
    //      s.erase(value);
    //
    //
    // Agar value present hai:
    //
    //      remove ho jayegi.
    //
    //
    // Return:
    //
    //      number of elements removed
    //
    // std::set mein maximum 1 element remove hoga.
    //
    // ============================================================

    set<int> s9 = {10, 20, 30, 40, 50};

    cout << "\n========== erase(value) ==========" << endl;

    s9.erase(30);

    for (int x : s9)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 20. ERASE USING ITERATOR
    // ============================================================
    //
    // Agar element ka iterator available hai:
    //
    //      s.erase(iterator);
    //
    // use kar sakte hain.
    //
    // ============================================================

    set<int> s10 = {10, 20, 30, 40, 50};

    auto it3 = s10.find(30);

    if (it3 != s10.end())
    {
        s10.erase(it3);
    }

    cout << "\n========== erase(iterator) ==========" << endl;

    for (int x : s10)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 21. ERASE RANGE
    // ============================================================
    //
    // Do iterators ke beech ke elements erase kar sakte hain.
    //
    // Syntax:
    //
    //      s.erase(first, last);
    //
    //
    // Range:
    //
    //      [first, last)
    //
    // means first included hai,
    // last excluded hai.
    //
    // ============================================================

    set<int> s11 = {10, 20, 30, 40, 50, 60};

    auto first = s11.find(20);
    auto last = s11.find(50);

    s11.erase(first, last);

    cout << "\n========== erase(range) ==========" << endl;

    for (int x : s11)
    {
        cout << x << " ";
    }

    cout << endl;

    // Result:
    //
    //      10 50 60
    //
    // Because:
    //
    //      20, 30, 40
    //
    // were erased.

    // ============================================================
    // 22. BEGIN()
    // ============================================================
    //
    // begin() first element ka iterator return karta hai.
    //
    // set sorted hota hai, isliye:
    //
    //      begin()
    //
    // normally smallest element par point karega
    // when using default ascending ordering.
    //
    // ============================================================

    set<int> s12 = {50, 10, 30, 20, 40};

    cout << "\n========== begin() ==========" << endl;

    auto it4 = s12.begin();

    cout << "First element = "
         << *it4
         << endl;

    // ============================================================
    // 23. END()
    // ============================================================
    //
    // end() last element par point nahi karta.
    //
    // end():
    //
    //      last element ke JUST AFTER position ko represent karta hai.
    //
    // Important:
    //
    //      *s.end()
    //
    // WRONG hai.
    //
    // Correct traversal:
    //
    //      for (auto it = s.begin(); it != s.end(); ++it)
    //
    // ============================================================

    cout << "\n========== end() ==========" << endl;

    for (auto it = s12.begin(); it != s12.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;

    // ============================================================
    // 24. ITERATOR TRAVERSAL
    // ============================================================
    //
    // Set ko iterator se traverse kar sakte hain.
    //
    // Syntax:
    //
    //      for (auto it = s.begin();
    //           it != s.end();
    //           ++it)
    //
    // ============================================================

    cout << "\n========== Iterator Traversal ==========" << endl;

    for (set<int>::iterator it = s12.begin();
         it != s12.end();
         ++it)
    {
        cout << *it << " ";
    }

    cout << endl;

    // ============================================================
    // 25. CONST ITERATOR
    // ============================================================
    //
    // Read-only traversal ke liye:
    //
    //      set<int>::const_iterator
    //
    // use kar sakte hain.
    //
    // ============================================================

    cout << "\n========== const_iterator ==========" << endl;

    for (set<int>::const_iterator it = s12.begin();
         it != s12.end();
         ++it)
    {
        cout << *it << " ";
    }

    cout << endl;

    // ============================================================
    // 26. RANGE-BASED FOR LOOP
    // ============================================================
    //
    // Modern C++ mein set traverse karne ka easiest method:
    //
    //      for (int x : s)
    //
    // ============================================================

    cout << "\n========== Range Based Loop ==========" << endl;

    for (int x : s12)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 27. REVERSE ITERATOR
    // ============================================================
    //
    // rbegin():
    //
    //      last element se traversal start karta hai.
    //
    //
    // rend():
    //
    //      beginning ke just-before position ko represent karta hai.
    //
    // ============================================================

    cout << "\n========== Reverse Iteration ==========" << endl;

    for (auto it = s12.rbegin(); it != s12.rend(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;

    // ============================================================
    // 28. REVERSE ORDER
    // ============================================================
    //
    // Default set:
    //
    //      ascending
    //
    // Reverse iterator se:
    //
    //      descending traversal
    //
    // kar sakte hain.
    //
    // ============================================================

    // ============================================================
    // 29. LOWER_BOUND()
    // ============================================================
    //
    // lower_bound(value) returns iterator to the first element
    // which is NOT LESS THAN the given value.
    //
    // Simple language:
    //
    //      first element >= value
    //
    //
    // Example:
    //
    // Set:
    //
    //      10 20 30 40 50
    //
    // lower_bound(30):
    //
    //      30
    //
    // lower_bound(25):
    //
    //      30
    //
    // lower_bound(60):
    //
    //      end()
    //
    // ============================================================

    set<int> s13 = {10, 20, 30, 40, 50};

    cout << "\n========== lower_bound() ==========" << endl;

    auto lb1 = s13.lower_bound(30);

    if (lb1 != s13.end())
    {
        cout << "lower_bound(30) = "
             << *lb1
             << endl;
    }

    auto lb2 = s13.lower_bound(25);

    if (lb2 != s13.end())
    {
        cout << "lower_bound(25) = "
             << *lb2
             << endl;
    }

    // ============================================================
    // 30. UPPER_BOUND()
    // ============================================================
    //
    // upper_bound(value):
    //
    //      first element GREATER THAN value
    //
    //
    // Example:
    //
    //      10 20 30 40 50
    //
    // upper_bound(30):
    //
    //      40
    //
    // ============================================================

    cout << "\n========== upper_bound() ==========" << endl;

    auto ub1 = s13.upper_bound(30);

    if (ub1 != s13.end())
    {
        cout << "upper_bound(30) = "
             << *ub1
             << endl;
    }

    // ============================================================
    // 31. LOWER_BOUND VS UPPER_BOUND
    // ============================================================
    //
    // lower_bound(x):
    //
    //      first element >= x
    //
    //
    // upper_bound(x):
    //
    //      first element > x
    //
    //
    // Example:
    //
    //      set = {10, 20, 30, 40, 50}
    //
    //
    // lower_bound(30)
    //      -> 30
    //
    // upper_bound(30)
    //      -> 40
    //
    // ============================================================

    // ============================================================
    // 32. EQUAL_RANGE()
    // ============================================================
    //
    // equal_range(value) returns:
    //
    //      pair<lower_bound, upper_bound>
    //
    // For set, since duplicates are not allowed, the range
    // normally contains either zero or one equivalent element.
    //
    // ============================================================

    cout << "\n========== equal_range() ==========" << endl;

    auto range = s13.equal_range(30);

    if (range.first != s13.end())
    {
        cout << "First iterator = "
             << *range.first
             << endl;
    }

    if (range.second != s13.end())
    {
        cout << "Second iterator = "
             << *range.second
             << endl;
    }

    // ============================================================
    // 33. MAXIMUM / MINIMUM USING BEGIN AND RBEGIN
    // ============================================================
    //
    // Default ascending set mein:
    //
    //      *begin()
    //
    // gives smallest element.
    //
    //
    //      *rbegin()
    //
    // gives largest element.
    //
    // ============================================================

    cout << "\n========== Minimum and Maximum ==========" << endl;

    cout << "Minimum = "
         << *s13.begin()
         << endl;

    cout << "Maximum = "
         << *s13.rbegin()
         << endl;

    // ============================================================
    // 34. set DOES NOT SUPPORT INDEXING
    // ============================================================
    //
    // Vector ki tarah:
    //
    //      v[0]
    //
    // possible hai.
    //
    // Lekin set mein:
    //
    //      s[0]
    //
    // WRONG hai.
    //
    // Reason:
    //
    // set random-access container nahi hai.
    //
    // Agar nth element chahiye, iterator advance kar sakte ho.
    //
    // ============================================================

    // ============================================================
    // 35. ACCESSING Nth ELEMENT USING ITERATOR
    // ============================================================
    //
    // Example:
    //
    //      set = {10,20,30,40,50}
    //
    // Third element:
    //
    //      iterator = begin()
    //      advance(iterator, 2)
    //
    // Then:
    //
    //      *iterator = 30
    //
    // Note:
    //
    // std::set iterators random access iterators nahi hote,
    // so advance() linear steps perform kar sakta hai.
    //
    // ============================================================

    set<int> s14 = {10, 20, 30, 40, 50};

    auto nth = s14.begin();

    advance(nth, 2);

    cout << "\n========== Nth Element ==========" << endl;

    cout << "Third element = "
         << *nth
         << endl;

    // ============================================================
    // 36. SET OF PAIRS
    // ============================================================
    //
    // Ye DSA mein VERY IMPORTANT concept hai.
    //
    // Hum set ke andar pair store kar sakte hain:
    //
    //      set<pair<int,int>>
    //
    //
    // Pair ke liye default comparison lexicographical hota hai.
    //
    // First compare hota hai.
    //
    // Agar first equal ho:
    //
    //      second compare hota hai.
    //
    // ============================================================

    set<pair<int, int>> pairSet;

    pairSet.insert({10, 20});
    pairSet.insert({5, 50});
    pairSet.insert({10, 10});
    pairSet.insert({5, 20});
    pairSet.insert({10, 20});

    cout << "\n========== set<pair<int,int>> ==========" << endl;

    for (const auto &p : pairSet)
    {
        cout << "("
             << p.first
             << ", "
             << p.second
             << ")"
             << endl;
    }

    // ============================================================
    // 37. SET OF PAIRS - ORDER
    // ============================================================
    //
    // Suppose:
    //
    //      {10,20}
    //      {10,10}
    //
    // First values same:
    //
    //      10 == 10
    //
    // So second values compare honge:
    //
    //      10 < 20
    //
    // Therefore:
    //
    //      {10,10}
    //      {10,20}
    //
    // order mein aayenge.
    //
    // ============================================================

    // ============================================================
    // 38. SET OF STRINGS
    // ============================================================
    //
    // DSA example:
    //
    // Unique words store karna.
    //
    // ============================================================

    set<string> words = {
        "apple",
        "banana",
        "apple",
        "mango",
        "orange",
        "banana"};

    cout << "\n========== Unique Words ==========" << endl;

    for (const string &word : words)
    {
        cout << word << endl;
    }

    // ============================================================
    // 39. SET FOR UNIQUE ELEMENTS
    // ============================================================
    //
    // Agar array/vector mein duplicates hain aur humein
    // unique sorted values chahiye:
    //
    //      set
    //
    // bahut useful hai.
    //
    // Example:
    //
    //      vector = {5,1,2,5,3,2,1}
    //
    // set:
    //
    //      {1,2,3,5}
    //
    // ============================================================

    vector<int> data = {
        5, 1, 2, 5, 3, 2, 1};

    set<int> uniqueData(
        data.begin(),
        data.end());

    cout << "\n========== Unique Sorted Data ==========" << endl;

    for (int x : uniqueData)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 40. SET CONSTRUCTOR FROM ITERATOR RANGE
    // ============================================================
    //
    // Syntax:
    //
    //      set<int> s(first, last);
    //
    //
    // Ye kisi container ke range se set create karta hai.
    //
    // ============================================================

    vector<int> numbers = {
        100, 50, 20, 100, 40, 50};

    set<int> convertedSet(
        numbers.begin(),
        numbers.end());

    cout << "\n========== Set from Vector ==========" << endl;

    for (int x : convertedSet)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 41. COPY CONSTRUCTOR
    // ============================================================
    //
    // Ek set ko doosre set mein copy kar sakte hain.
    //
    // ============================================================

    set<int> original = {
        10, 20, 30};

    set<int> copied = original;

    cout << "\n========== Copy Set ==========" << endl;

    for (int x : copied)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 42. ASSIGNMENT OPERATOR
    // ============================================================
    //
    // Existing set ko doosre set se assign kar sakte hain.
    //
    // ============================================================

    set<int> setA = {1, 2, 3};
    set<int> setB = {100, 200};

    setB = setA;

    cout << "\n========== Assignment ==========" << endl;

    for (int x : setB)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 43. SWAP()
    // ============================================================
    //
    // swap() do sets ke contents exchange karta hai.
    //
    // Syntax:
    //
    //      s1.swap(s2);
    //
    // ============================================================

    set<int> setC = {10, 20, 30};
    set<int> setD = {100, 200, 300};

    setC.swap(setD);

    cout << "\n========== swap() ==========" << endl;

    cout << "Set C: ";

    for (int x : setC)
    {
        cout << x << " ";
    }

    cout << endl;

    cout << "Set D: ";

    for (int x : setD)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 44. DEFAULT ORDERING
    // ============================================================
    //
    // Default set:
    //
    //      set<int>
    //
    // ascending order use karta hai.
    //
    //
    // Conceptually comparator:
    //
    //      less<int>
    //
    // ============================================================

    set<int> ascendingSet = {
        50, 10, 40, 20, 30};

    cout << "\n========== Default Ascending Order ==========" << endl;

    for (int x : ascendingSet)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 45. DESCENDING ORDER SET
    // ============================================================
    //
    // Agar descending order chahiye:
    //
    //      set<int, greater<int>>
    //
    // ============================================================

    set<int, greater<int>> descendingSet = {
        50, 10, 40, 20, 30};

    cout << "\n========== Descending Set ==========" << endl;

    for (int x : descendingSet)
    {
        cout << x << " ";
    }

    cout << endl;

    // Output:
    //
    //      50 40 30 20 10

    // ============================================================
    // 46. greater<int>
    // ============================================================
    //
    // greater<int> comparator:
    //
    //      larger element first
    //
    // Example:
    //
    //      set<int, greater<int>>
    //
    // ============================================================

    // ============================================================
    // 47. CUSTOM COMPARATOR
    // ============================================================
    //
    // Set custom comparison function/object bhi use kar sakta hai.
    //
    // Example:
    //
    //      bool compareDescending(int a, int b)
    //      {
    //          return a > b;
    //      }
    //
    // Is concept ko lambda ke through bhi demonstrate kar sakte
    // hain, lekin set ke type mein comparator part of type hota hai.
    //
    // ============================================================

    // ============================================================
    // 48. SET OF PAIR WITH DEFAULT ORDER
    // ============================================================
    //
    // set<pair<int,int>> automatically pair comparison use karta hai.
    //
    // Example:
    //
    //      {2,10}
    //      {1,50}
    //      {2,5}
    //
    //
    // Sorted:
    //
    //      {1,50}
    //      {2,5}
    //      {2,10}
    //
    // ============================================================

    set<pair<int, int>> coordinates;

    coordinates.insert({2, 10});
    coordinates.insert({1, 50});
    coordinates.insert({2, 5});
    coordinates.insert({1, 20});

    cout << "\n========== Sorted Pair Set ==========" << endl;

    for (const auto &p : coordinates)
    {
        cout << "{"
             << p.first
             << ", "
             << p.second
             << "}"
             << endl;
    }

    // ============================================================
    // 49. SET OF PAIR - DUPLICATE PAIR
    // ============================================================
    //
    // Pair bhi duplicate nahi hoga.
    //
    //      {10,20}
    //
    // ko do baar insert karoge,
    // set mein ek hi copy rahegi.
    //
    // ============================================================

    set<pair<int, int>> pairDuplicates;

    pairDuplicates.insert({10, 20});
    pairDuplicates.insert({10, 20});
    pairDuplicates.insert({10, 30});

    cout << "\n========== Duplicate Pairs ==========" << endl;

    for (const auto &p : pairDuplicates)
    {
        cout << p.first
             << " "
             << p.second
             << endl;
    }

    // ============================================================
    // 50. SET OF PAIR - FIND
    // ============================================================
    //
    // Pair ko find karne ke liye:
    //
    //      s.find({x,y})
    //
    // use kar sakte hain.
    //
    // ============================================================

    auto pairIt = pairDuplicates.find({10, 20});

    cout << "\n========== Find Pair ==========" << endl;

    if (pairIt != pairDuplicates.end())
    {
        cout << "Pair found: "
             << pairIt->first
             << ", "
             << pairIt->second
             << endl;
    }
    else
    {
        cout << "Pair not found." << endl;
    }

    // ============================================================
    // 51. SET ITERATOR CANNOT MODIFY ELEMENT
    // ============================================================
    //
    // IMPORTANT:
    //
    // set ka element directly modify nahi kar sakte.
    //
    // Example:
    //
    //      auto it = s.begin();
    //      *it = 100;
    //
    // WRONG hai.
    //
    // Reason:
    //
    // Set elements sorted structure ka part hain.
    //
    // Agar element modify ho jaye aur ordering break ho jaye,
    // container invalid ho sakta hai.
    //
    // Isliye set iterator se element ko modify karna allowed nahi.
    //
    // ============================================================

    // ============================================================
    // 52. IF YOU WANT TO CHANGE A SET ELEMENT
    // ============================================================
    //
    // Correct approach:
    //
    //      1. Old element erase karo.
    //
    //      2. New value insert karo.
    //
    //
    // Example:
    //
    //      set = {10,20,30}
    //
    //      20 ko 100 karna hai.
    //
    //      erase(20)
    //      insert(100)
    //
    // ============================================================

    set<int> modifySet = {
        10, 20, 30};

    modifySet.erase(20);
    modifySet.insert(100);

    cout << "\n========== Modify Set Value ==========" << endl;

    for (int x : modifySet)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 53. SET VS VECTOR
    // ============================================================
    //
    // VECTOR:
    //
    //      vector<int> v;
    //
    // Features:
    //
    //      - duplicates allowed
    //      - insertion order maintained
    //      - indexing supported
    //      - v[0] possible
    //
    //
    // SET:
    //
    //      set<int> s;
    //
    // Features:
    //
    //      - duplicates NOT allowed
    //      - sorted order maintained
    //      - indexing NOT supported
    //      - searching generally O(log n)
    //
    // ============================================================

    // ============================================================
    // 54. SET VS UNORDERED_SET
    // ============================================================
    //
    // std::set:
    //
    //      - unique elements
    //      - sorted
    //      - ordered traversal
    //      - generally O(log n)
    //
    //
    // std::unordered_set:
    //
    //      - unique elements
    //      - no sorted order guarantee
    //      - hash-table based
    //      - average O(1) search/insert/erase
    //
    //
    // Use set when:
    //
    //      sorted order required ho.
    //
    // Use unordered_set when:
    //
    //      ordering required nahi hai and hash-based lookup useful hai.
    //
    // ============================================================

    // ============================================================
    // 55. SET VS MULTISET
    // ============================================================
    //
    // set:
    //
    //      duplicate values NOT allowed.
    //
    //
    // multiset:
    //
    //      duplicate values ALLOWED.
    //
    //
    // Example:
    //
    //      set:
    //
    //          {10,20,30}
    //
    //
    //      multiset:
    //
    //          {10,10,20,20,30}
    //
    //
    // Both are ordered associative containers.
    //
    // ============================================================

    // ============================================================
    // 56. SET TIME COMPLEXITY
    // ============================================================
    //
    // IMPORTANT DSA NOTES:
    //
    //
    // insert:
    //
    //      O(log n)
    //
    //
    // find:
    //
    //      O(log n)
    //
    //
    // erase by key:
    //
    //      O(log n) generally
    //
    //
    // lower_bound:
    //
    //      O(log n)
    //
    //
    // upper_bound:
    //
    //      O(log n)
    //
    //
    // count:
    //
    //      O(log n)
    //
    //
    // size:
    //
    //      O(1)
    //
    //
    // empty:
    //
    //      O(1)
    //
    //
    // clear:
    //
    //      O(n)
    //
    // ============================================================

    // ============================================================
    // 57. DSA USE CASE - UNIQUE ELEMENTS
    // ============================================================
    //
    // Suppose:
    //
    //      array = {1,2,2,3,4,4,5}
    //
    // Hume unique sorted values chahiye.
    //
    // set directly useful hai.
    //
    // ============================================================

    vector<int> arr = {
        1, 2, 2, 3, 4, 4, 5};

    set<int> uniqueElements(
        arr.begin(),
        arr.end());

    cout << "\n========== DSA: Unique Elements ==========" << endl;

    for (int x : uniqueElements)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 58. DSA USE CASE - CHECK DUPLICATE
    // ============================================================
    //
    // Agar hum array ke elements ko set mein insert karte hain:
    //
    //      agar insertion fail hua,
    //      element pehle se present tha.
    //
    // Isse duplicate detection kar sakte hain.
    //
    // ============================================================

    vector<int> duplicateCheck = {
        10, 20, 30, 20, 40};

    set<int> seen;

    bool duplicateFound = false;

    for (int x : duplicateCheck)
    {
        auto result = seen.insert(x);

        if (!result.second)
        {
            duplicateFound = true;

            cout << "\nDuplicate found = "
                 << x
                 << endl;

            break;
        }
    }

    if (!duplicateFound)
    {
        cout << "\nNo duplicate found." << endl;
    }

    // ============================================================
    // 59. DSA USE CASE - UNIQUE WORDS
    // ============================================================
    //
    // String array/vector ke unique words find karne ke liye
    // set useful hai.
    //
    // ============================================================

    vector<string> wordsList = {
        "apple",
        "banana",
        "apple",
        "orange",
        "banana",
        "mango"};

    set<string> uniqueWords(
        wordsList.begin(),
        wordsList.end());

    cout << "\n========== DSA: Unique Words ==========" << endl;

    for (const string &word : uniqueWords)
    {
        cout << word << endl;
    }

    // ============================================================
    // 60. DSA USE CASE - RANGE QUERY
    // ============================================================
    //
    // set ka lower_bound aur upper_bound range queries mein
    // extremely useful hain.
    //
    // Example:
    //
    //      values = {10,20,30,40,50,60}
    //
    // Humein 25 se 50 tak ke values chahiye.
    //
    // lower_bound(25)
    //      -> 30
    //
    // upper_bound(50)
    //      -> 60
    //
    // Then iterate [30,60)
    //
    // ============================================================

    set<int> rangeSet = {
        10, 20, 30, 40, 50, 60};

    cout << "\n========== DSA: Range Query ==========" << endl;

    auto rangeStart = rangeSet.lower_bound(25);
    auto rangeEnd = rangeSet.upper_bound(50);

    for (auto it = rangeStart;
         it != rangeEnd;
         ++it)
    {
        cout << *it << " ";
    }

    cout << endl;

    // ============================================================
    // 61. DSA USE CASE - NEXT GREATER OR EQUAL
    // ============================================================
    //
    // lower_bound(x) ka ek important DSA use:
    //
    //      x se greater ya equal smallest value find karna.
    //
    // Example:
    //
    //      set = {10,20,30,40}
    //
    //      lower_bound(25)
    //
    //      answer = 30
    //
    // ============================================================

    set<int> lowerBoundSet = {
        10, 20, 30, 40};

    int target = 25;

    auto nextElement = lowerBoundSet.lower_bound(target);

    cout << "\n========== Next Greater or Equal ==========" << endl;

    if (nextElement != lowerBoundSet.end())
    {
        cout << "Answer = "
             << *nextElement
             << endl;
    }
    else
    {
        cout << "No greater/equal element exists."
             << endl;
    }

    // ============================================================
    // 62. DSA USE CASE - PREVIOUS ELEMENT
    // ============================================================
    //
    // lower_bound(x) se:
    //
    //      first element >= x
    //
    // milta hai.
    //
    // Usse just previous element find karne ke liye:
    //
    //      --iterator
    //
    // use kar sakte hain, but begin() case carefully handle karna
    // zaroori hai.
    //
    // ============================================================

    set<int> previousSet = {
        10, 20, 30, 40, 50};

    int value = 35;

    auto position = previousSet.lower_bound(value);

    cout << "\n========== Previous Element ==========" << endl;

    if (position != previousSet.begin())
    {
        --position;

        cout << "Previous smaller element = "
             << *position
             << endl;
    }
    else
    {
        cout << "No smaller element exists."
             << endl;
    }

    // ============================================================
    // 63. SET WITH PAIR - GRAPH EDGE EXAMPLE
    // ============================================================
    //
    // DSA graph problems mein pair useful hota hai.
    //
    //      set<pair<int,int>>
    //
    // unique edges store kar sakta hai.
    //
    // ============================================================

    set<pair<int, int>> edges;

    edges.insert({1, 2});
    edges.insert({2, 3});
    edges.insert({1, 2});
    edges.insert({3, 4});

    cout << "\n========== DSA: Unique Graph Edges ==========" << endl;

    for (const auto &edge : edges)
    {
        cout << edge.first
             << " -> "
             << edge.second
             << endl;
    }

    // ============================================================
    // 64. SET WITH CUSTOM STRUCT
    // ============================================================
    //
    // Set mein custom class/struct store karna possible hai,
    // lekin set ko elements compare karne ka valid ordering rule
    // chahiye.
    //
    // Example concept:
    //
    //      struct Student
    //      {
    //          int id;
    //      };
    //
    // Agar custom type ke liye comparison provide kiya gaya hai,
    // to set us type ko order kar sakta hai.
    //
    // ============================================================

    // ============================================================
    // 65. SET OF VECTOR - IMPORTANT NOTE
    // ============================================================
    //
    // Modern C++ mein:
    //
    //      set<vector<int>>
    //
    // possible hai because vector has lexicographical comparison
    // support.
    //
    // Example:
    //
    //      {1,2}
    //      {1,3}
    //      {2}
    //
    // lexicographical order mein compare honge.
    //
    // ============================================================

    set<vector<int>> vectorSet;

    vectorSet.insert({1, 2});
    vectorSet.insert({1, 3});
    vectorSet.insert({2});
    vectorSet.insert({1, 2});

    cout << "\n========== set<vector<int>> ==========" << endl;

    for (const auto &v : vectorSet)
    {
        cout << "{ ";

        for (int x : v)
        {
            cout << x << " ";
        }

        cout << "}" << endl;
    }

    // ============================================================
    // 66. SET OF STRING - CASE SENSITIVITY
    // ============================================================
    //
    // Default string comparison case-sensitive hoti hai.
    //
    // Example:
    //
    //      "Apple"
    //      "apple"
    //
    // These are different strings.
    //
    // Isliye set dono ko alag elements maanega.
    //
    // ============================================================

    set<string> caseSet = {
        "Apple",
        "apple",
        "Banana",
        "banana"};

    cout << "\n========== Case Sensitive Set ==========" << endl;

    for (const string &word : caseSet)
    {
        cout << word << endl;
    }

    // ============================================================
    // 67. SET DOES NOT ALLOW DIRECT MODIFICATION
    // ============================================================
    //
    // VERY IMPORTANT INTERVIEW / DSA POINT:
    //
    //      set<int> s;
    //
    //      auto it = s.begin();
    //
    //      *it = 100;
    //
    // invalid hai.
    //
    // Why?
    //
    // Because changing the value may destroy the ordering property.
    //
    // Correct:
    //
    //      erase(oldValue);
    //      insert(newValue);
    //
    // ============================================================

    // ============================================================
    // 68. SET AND MEMORY / ORDER CONCEPT
    // ============================================================
    //
    // User ko set ko vector ki tarah continuous array samajhna
    // nahi chahiye.
    //
    // set ka main purpose:
    //
    //      ordered + unique data
    //
    // provide karna hai.
    //
    // Agar tumhe:
    //
    //      fast indexing
    //
    // chahiye:
    //
    //      vector
    //
    // Agar tumhe:
    //
    //      unique + sorted
    //
    // chahiye:
    //
    //      set
    //
    // Agar tumhe:
    //
    //      unique + average O(1) lookup
    //
    // chahiye and ordering nahi chahiye:
    //
    //      unordered_set
    //
    // ============================================================

    // ============================================================
    // 69. IMPORTANT SET FUNCTIONS - QUICK DEMO
    // ============================================================
    //
    // Common functions:
    //
    //      insert()
    //      erase()
    //      find()
    //      count()
    //      lower_bound()
    //      upper_bound()
    //      equal_range()
    //      begin()
    //      end()
    //      rbegin()
    //      rend()
    //      size()
    //      empty()
    //      clear()
    //      swap()
    //
    // ============================================================

    set<int> functionDemo = {
        10, 20, 30, 40, 50};

    cout << "\n========== Function Demo ==========" << endl;

    cout << "Size = "
         << functionDemo.size()
         << endl;

    cout << "Empty = "
         << functionDemo.empty()
         << endl;

    cout << "Count(30) = "
         << functionDemo.count(30)
         << endl;

    cout << "Count(100) = "
         << functionDemo.count(100)
         << endl;

    // ============================================================
    // 70. SET OF PAIR + STRUCTURED BINDING
    // ============================================================
    //
    // C++17 mein:
    //
    //      for (const auto &[x, y] : setOfPairs)
    //
    // use kar sakte hain.
    //
    // Ye pair ke first aur second ko directly names deta hai.
    //
    // ============================================================

    set<pair<int, int>> bindingSet = {
        {1, 10},
        {2, 20},
        {3, 30}};

    cout << "\n========== Structured Binding ==========" << endl;

    for (const auto &[firstValue, secondValue] : bindingSet)
    {
        cout << "First = "
             << firstValue
             << ", Second = "
             << secondValue
             << endl;
    }

    // ============================================================
    // 71. SET COPY + MODIFY
    // ============================================================
    //
    // Copy karne ke baad dono sets independent containers hote hain.
    //
    // ============================================================

    set<int> originalSet = {
        10, 20, 30};

    set<int> copiedSet = originalSet;

    copiedSet.insert(40);

    cout << "\n========== Copy Independence ==========" << endl;

    cout << "Original: ";

    for (int x : originalSet)
    {
        cout << x << " ";
    }

    cout << endl;

    cout << "Copied: ";

    for (int x : copiedSet)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 72. CHECKING WHETHER SET IS EMPTY
    // ============================================================
    //
    // Preferred:
    //
    //      s.empty()
    //
    // Avoid unnecessary:
    //
    //      s.size() == 0
    //
    // Although both can work logically, empty() clearly expresses
    // the intention.
    //
    // ============================================================

    set<int> emptySet;

    cout << "\n========== Empty Check ==========" << endl;

    if (emptySet.empty())
    {
        cout << "Set is empty." << endl;
    }

    // ============================================================
    // 73. CLEAR AND REUSE
    // ============================================================
    //
    // clear() ke baad same set ko dobara use kar sakte hain.
    //
    // ============================================================

    emptySet.insert(100);
    emptySet.insert(200);

    emptySet.clear();

    emptySet.insert(500);
    emptySet.insert(600);

    cout << "\n========== Reusing Set ==========" << endl;

    for (int x : emptySet)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 74. SET VS MULTISET - PRACTICAL EXAMPLE
    // ============================================================
    //
    // set:
    //
    //      {10,20,30}
    //
    // Agar same value 10 ko 5 baar insert karoge,
    // final result:
    //
    //      {10,20,30}
    //
    //
    // multiset:
    //
    //      {10,10,10,10,10,20,30}
    //
    // ho sakta hai.
    //
    // Isliye duplicate frequency preserve karni ho to multiset
    // relevant container hai.
    //
    // ============================================================

    // ============================================================
    // 75. SET VS UNORDERED_SET - PRACTICAL CHOICE
    // ============================================================
    //
    // Question:
    //
    //      "Mujhe unique elements chahiye aur sorted order bhi."
    //
    // Answer:
    //
    //      set
    //
    //
    // Question:
    //
    //      "Mujhe unique elements chahiye, order matter nahi karta."
    //
    // Possible choice:
    //
    //      unordered_set
    //
    //
    // Question:
    //
    //      "Duplicates bhi chahiye aur sorted order bhi."
    //
    // Answer:
    //
    //      multiset
    //
    // ============================================================

    // ============================================================
    // 76. IMPORTANT INTERVIEW POINT
    // ============================================================
    //
    // Q:
    //
    //      Does set allow duplicate elements?
    //
    // A:
    //
    //      No.
    //
    //
    // Q:
    //
    //      Is set sorted?
    //
    // A:
    //
    //      Yes, according to its comparator.
    //      Default comparator ascending ordering provide karta hai.
    //
    //
    // Q:
    //
    //      Does set support indexing?
    //
    // A:
    //
    //      No.
    //
    //
    // Q:
    //
    //      Average search complexity?
    //
    // A:
    //
    //      Ordered set search is generally O(log n).
    //
    //
    // Q:
    //
    //      Can set elements be modified directly?
    //
    // A:
    //
    //      No, direct modification is not allowed through the
    //      iterator because it could violate ordering.
    //
    // ============================================================

    // ============================================================
    // 77. MOST IMPORTANT DSA PATTERN
    // ============================================================
    //
    // Pattern:
    //
    //      vector<int> arr;
    //
    //      set<int> s(arr.begin(), arr.end());
    //
    //
    // Isse:
    //
    //      duplicates remove
    //
    // AND:
    //
    //      values sorted
    //
    // ho jaati hain.
    //
    // ============================================================

    // ============================================================
    // 78. SET AS UNIQUE SORTED CONTAINER
    // ============================================================
    //
    // Example:
    //
    // Input:
    //
    //      8 3 5 3 1 8 2 5
    //
    // Set:
    //
    //      1 2 3 5 8
    //
    // Ye set ka core use-case hai.
    //
    // ============================================================

    // ============================================================
    // 79. COMPLETE MINI EXAMPLE
    // ============================================================
    //
    // Ek simple practical program:
    //
    // User ke numbers mein se unique sorted values print karo.
    //
    // ============================================================

    set<int> miniSet;

    miniSet.insert(8);
    miniSet.insert(3);
    miniSet.insert(5);
    miniSet.insert(3);
    miniSet.insert(1);
    miniSet.insert(8);
    miniSet.insert(2);
    miniSet.insert(5);

    cout << "\n========== Complete Mini Example ==========" << endl;

    cout << "Unique sorted values: ";

    for (int x : miniSet)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 80. FINAL SET CHEAT SHEET
    // ============================================================
    //
    /*

        CREATE:

            set<int> s;


        INITIALIZE:

            set<int> s = {10,20,30};


        INSERT:

            s.insert(40);


        DELETE BY VALUE:

            s.erase(20);


        FIND:

            auto it = s.find(20);


        CHECK FOUND:

            if (it != s.end())


        COUNT:

            s.count(20);


        SIZE:

            s.size();


        EMPTY:

            s.empty();


        CLEAR:

            s.clear();


        FIRST ELEMENT:

            *s.begin();


        LAST ELEMENT:

            *s.rbegin();


        NORMAL ITERATION:

            for (auto x : s)
            {
                cout << x;
            }


        ITERATOR:

            for (auto it = s.begin();
                 it != s.end();
                 ++it)
            {
                cout << *it;
            }


        REVERSE ITERATION:

            for (auto it = s.rbegin();
                 it != s.rend();
                 ++it)
            {
                cout << *it;
            }


        LOWER BOUND:

            s.lower_bound(x);


        UPPER BOUND:

            s.upper_bound(x);


        EQUAL RANGE:

            s.equal_range(x);


        DESCENDING SET:

            set<int, greater<int>> s;


        SET OF PAIRS:

            set<pair<int,int>> s;


        RANGE FROM VECTOR:

            set<int> s(v.begin(), v.end());


        COPY:

            set<int> s2 = s1;


        SWAP:

            s1.swap(s2);

    */

    // ============================================================
    // 81. FINAL CONCEPT
    // ============================================================
    //
    // std::set ka basic mental model:
    //
    //
    //              SET<T>
    //                |
    //        -----------------
    //        |       |       |
    //       T1      T2      T3
    //
    //
    // BUT:
    //
    //      values UNIQUE hain
    //
    // AND:
    //
    //      values SORTED hain
    //
    //
    // Example:
    //
    //      set<int>
    //
    //          10
    //          20
    //          30
    //          40
    //
    //
    // Duplicate:
    //
    //      insert(20)
    //
    // ignored if 20 already exists.
    //
    //
    // Search:
    //
    //      find(20)
    //
    //
    // Delete:
    //
    //      erase(20)
    //
    //
    // Range:
    //
    //      lower_bound()
    //      upper_bound()
    //
    //
    // DSA mein set especially useful hai jab:
    //
    //      1. Unique values chahiye.
    //
    //      2. Sorted values chahiye.
    //
    //      3. Fast ordered searching chahiye.
    //
    //      4. Next greater / greater-or-equal element chahiye.
    //
    //      5. Previous smaller element find karna ho.
    //
    //      6. Range queries karni ho.
    //
    //      7. Duplicate detection karna ho.
    //
    // ============================================================

    cout << "\n============================================" << endl;
    cout << "          SET CONCEPT COMPLETED             " << endl;
    cout << "============================================" << endl;

    return 0;
}