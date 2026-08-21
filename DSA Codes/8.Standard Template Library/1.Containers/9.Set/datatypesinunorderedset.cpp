#include <iostream>
#include <unordered_set> // std::unordered_set
#include <string>        // std::string
#include <vector>        // std::vector
#include <utility>       // std::pair
#include <functional>    // std::hash
#include <iterator>      // std::advance
#include <algorithm>     // std::find

using namespace std;

int main()
{
    // ============================================================
    //                 STL : std::unordered_set
    // ============================================================
    //
    // std::unordered_set C++ STL ka ek associative container hai.
    //
    // Iska main purpose:
    //
    //      UNIQUE values ko store karna
    //
    // Lekin std::set ke unlike:
    //
    //      unordered_set elements ko SORTED ORDER mein
    //      store karne ki guarantee nahi deta.
    //
    //
    // Example:
    //
    //      unordered_set<int> s = {
    //          40, 10, 30, 20, 10
    //      };
    //
    //
    // Ismein:
    //
    //      10 duplicate hai
    //
    // isliye 10 ek hi baar store hoga.
    //
    // Lekin output:
    //
    //      10 20 30 40
    //
    // zaroori nahi hai.
    //
    // Output ka order implementation / hash arrangement ke
    // according change ho sakta hai.
    //
    //
    // ============================================================
    // IMPORTANT PROPERTIES OF unordered_set
    // ============================================================
    //
    // 1. Elements UNIQUE hote hain.
    //
    // 2. Duplicate elements store nahi hote.
    //
    // 3. Elements SORTED nahi hote.
    //
    // 4. Ordering ki koi guarantee nahi hoti.
    //
    // 5. Hash table based container hai.
    //
    // 6. Average case:
    //
    //      search       -> O(1)
    //      insertion    -> O(1)
    //      deletion     -> O(1)
    //
    // 7. Worst case:
    //
    //      O(n)
    //
    //    ho sakta hai.
    //
    // 8. Random indexing available nahi hoti.
    //
    //      s[0]       // WRONG
    //
    // 9. lower_bound() aur upper_bound() available nahi hote.
    //
    // 10. Main use:
    //
    //      UNIQUE + FAST LOOKUP
    //
    // ============================================================

    // ============================================================
    // 1. HEADER FILE
    // ============================================================
    //
    // unordered_set use karne ke liye:
    //
    //      #include <unordered_set>
    //
    // required hai.
    //
    // ============================================================

    // ============================================================
    // 2. BASIC SYNTAX
    // ============================================================
    //
    // General syntax:
    //
    //      unordered_set<DataType> variableName;
    //
    //
    // Examples:
    //
    //      unordered_set<int> numbers;
    //
    //      unordered_set<string> names;
    //
    //      unordered_set<char> letters;
    //
    //      unordered_set<double> values;
    //
    // ============================================================

    // ============================================================
    // 3. unordered_set<int>
    // ============================================================
    //
    // Sabse common type:
    //
    //      unordered_set<int>
    //
    // Ismein unique integers store hote hain.
    //
    // ============================================================

    unordered_set<int> s1;

    cout << "========== unordered_set<int> =========="
         << endl;

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

    //
    // IMPORTANT:
    //
    // Output ka order fixed nahi hai.
    //
    // Aapko:
    //
    //      10 20 30 40 50
    //
    // mil bhi sakta hai,
    //
    // aur koi doosra order bhi aa sakta hai.
    //
    // unordered_set sorted order guarantee nahi karta.
    //
    // ============================================================

    // ============================================================
    // 4. unordered_set<string>
    // ============================================================
    //
    // Strings bhi store kar sakte hain.
    //
    // ============================================================

    unordered_set<string> names;

    names.insert("Rahul");
    names.insert("Amit");
    names.insert("Riya");
    names.insert("Aman");

    cout << "\n========== unordered_set<string> =========="
         << endl;

    for (const string &name : names)
    {
        cout << name << endl;
    }

    // ============================================================
    // 5. unordered_set<char>
    // ============================================================
    //
    // Character values bhi store kar sakte hain.
    //
    // Duplicate characters allowed nahi hain.
    //
    // ============================================================

    unordered_set<char> letters;

    letters.insert('A');
    letters.insert('B');
    letters.insert('C');
    letters.insert('A');
    letters.insert('D');

    cout << "\n========== unordered_set<char> =========="
         << endl;

    for (char ch : letters)
    {
        cout << ch << " ";
    }

    cout << endl;

    // ============================================================
    // 6. unordered_set<double>
    // ============================================================
    //
    // Floating-point values bhi store kar sakte hain.
    //
    // ============================================================

    unordered_set<double> decimals = {
        3.14,
        1.5,
        2.7,
        1.5,
        4.8};

    cout << "\n========== unordered_set<double> =========="
         << endl;

    for (double value : decimals)
    {
        cout << value << " ";
    }

    cout << endl;

    // ============================================================
    // 7. unordered_set<long long>
    // ============================================================
    //
    // Large integer values ke liye:
    //
    //      long long
    //
    // use kar sakte hain.
    //
    // ============================================================

    unordered_set<long long> largeNumbers = {
        10000000000LL,
        50000000000LL,
        20000000000LL,
        10000000000LL};

    cout << "\n========== unordered_set<long long> =========="
         << endl;

    for (long long x : largeNumbers)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 8. DUPLICATE VALUES
    // ============================================================
    //
    // unordered_set ka sabse important feature:
    //
    //      DUPLICATES ALLOWED NAHI HAIN.
    //
    //
    // Example:
    //
    //      unordered_set<int> s = {
    //          10, 20, 10, 30, 20
    //      };
    //
    //
    // Final logical contents:
    //
    //      10
    //      20
    //      30
    //
    // Order guaranteed nahi hai.
    //
    // ============================================================

    unordered_set<int> duplicateSet;

    duplicateSet.insert(10);
    duplicateSet.insert(20);
    duplicateSet.insert(10);
    duplicateSet.insert(30);
    duplicateSet.insert(20);
    duplicateSet.insert(10);

    cout << "\n========== Duplicate Values =========="
         << endl;

    for (int x : duplicateSet)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 9. INITIALIZATION AT DECLARATION
    // ============================================================
    //
    // Direct initialization possible hai:
    //
    //      unordered_set<int> s = {
    //          10, 20, 30
    //      };
    //
    // ============================================================

    unordered_set<int> s2 = {
        50,
        10,
        40,
        20,
        30};

    cout << "\n========== Direct Initialization =========="
         << endl;

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
    //
    // unordered_set value ko hash table mein insert karta hai.
    //
    // Ye value ko sorted position mein insert nahi karta.
    //
    // ============================================================

    unordered_set<int> s3;

    s3.insert(40);
    s3.insert(10);
    s3.insert(30);
    s3.insert(20);

    cout << "\n========== insert() =========="
         << endl;

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
    // duplicate value add nahi karega.
    //
    //
    // Insert generally return karta hai:
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

    unordered_set<int> s4;

    auto result1 = s4.insert(10);

    cout << "\n========== Insert Return Value =========="
         << endl;

    cout << boolalpha;

    cout << "First insertion successful = "
         << result1.second
         << endl;

    auto result2 = s4.insert(10);

    cout << "Second insertion successful = "
         << result2.second
         << endl;

    // ============================================================
    // 12. INSERT RETURN TYPE
    // ============================================================
    //
    // unordered_set.insert(value) generally:
    //
    //      pair<iterator, bool>
    //
    // return karta hai.
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
    //          -> inserted/existing element ka iterator
    //
    //      result.second
    //          -> insertion successful hua ya nahi
    //
    // ============================================================

    unordered_set<int> s5;

    auto result3 = s5.insert(100);

    cout << "\n========== Insert Iterator =========="
         << endl;

    cout << "Value = "
         << *(result3.first)
         << endl;

    // ============================================================
    // 13. SIZE()
    // ============================================================
    //
    // size() current number of elements return karta hai.
    //
    // Syntax:
    //
    //      s.size();
    //
    // ============================================================

    unordered_set<int> s6 = {
        10,
        20,
        30,
        40,
        50};

    cout << "\n========== size() =========="
         << endl;

    cout << "Size = "
         << s6.size()
         << endl;

    // ============================================================
    // 14. EMPTY()
    // ============================================================
    //
    // empty() check karta hai:
    //
    //      kya unordered_set empty hai?
    //
    //
    // true:
    //
    //      empty
    //
    // false:
    //
    //      elements present
    //
    // ============================================================

    cout << "\n========== empty() =========="
         << endl;

    if (s6.empty())
    {
        cout << "Unordered set is empty."
             << endl;
    }
    else
    {
        cout << "Unordered set is NOT empty."
             << endl;
    }

    // ============================================================
    // 15. CLEAR()
    // ============================================================
    //
    // clear() saare elements remove karta hai.
    //
    // Syntax:
    //
    //      s.clear();
    //
    // ============================================================

    unordered_set<int> s7 = {
        10,
        20,
        30};

    cout << "\n========== clear() =========="
         << endl;

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
    // find(value) unordered_set mein value search karta hai.
    //
    // Syntax:
    //
    //      s.find(value);
    //
    //
    // Agar value mil gayi:
    //
    //      iterator
    //
    // Agar nahi mili:
    //
    //      s.end()
    //
    //
    // Average complexity:
    //
    //      O(1)
    //
    // Worst case:
    //
    //      O(n)
    //
    // ============================================================

    unordered_set<int> s8 = {
        10,
        20,
        30,
        40,
        50};

    cout << "\n========== find() =========="
         << endl;

    auto it1 = s8.find(30);

    if (it1 != s8.end())
    {
        cout << "30 found."
             << endl;
    }
    else
    {
        cout << "30 not found."
             << endl;
    }

    // ============================================================
    // 17. FIND() - VALUE NOT PRESENT
    // ============================================================

    auto it2 = s8.find(100);

    cout << "\n========== find() - Not Found =========="
         << endl;

    if (it2 != s8.end())
    {
        cout << "100 found."
             << endl;
    }
    else
    {
        cout << "100 not found."
             << endl;
    }

    // ============================================================
    // 18. COUNT()
    // ============================================================
    //
    // count(value) check karta hai ki value present hai ya nahi.
    //
    // unordered_set mein duplicates allowed nahi hote.
    //
    // Therefore:
    //
    //      count(value)
    //
    // generally:
    //
    //      0 or 1
    //
    // return karega.
    //
    // ============================================================

    cout << "\n========== count() =========="
         << endl;

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
    //
    // unordered_set mein duplicate values nahi hoti,
    // isliye normally return:
    //
    //      0 or 1
    //
    // ============================================================

    unordered_set<int> s9 = {
        10,
        20,
        30,
        40,
        50};

    cout << "\n========== erase(value) =========="
         << endl;

    size_t removed = s9.erase(30);

    cout << "Elements removed = "
         << removed
         << endl;

    cout << "Remaining elements: ";

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

    unordered_set<int> s10 = {
        10,
        20,
        30,
        40,
        50};

    auto it3 = s10.find(30);

    if (it3 != s10.end())
    {
        s10.erase(it3);
    }

    cout << "\n========== erase(iterator) =========="
         << endl;

    for (int x : s10)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 21. ERASE RANGE
    // ============================================================
    //
    // unordered_set mein iterators ke range ko erase kar sakte hain.
    //
    // Syntax:
    //
    //      s.erase(first, last);
    //
    //
    // IMPORTANT:
    //
    // unordered_set sorted nahi hai.
    //
    // Isliye:
    //
    //      erase(begin(), someIterator)
    //
    // ka meaning sorted values ke according nahi hota.
    //
    // Ye iterator traversal range ke according hota hai.
    //
    // ============================================================

    unordered_set<int> s11 = {
        10,
        20,
        30,
        40,
        50};

    auto rangeStart = s11.begin();

    auto rangeEnd = s11.begin();

    // Iterator ko kuch positions advance karte hain.
    // Exact elements/order implementation dependent hai.

    int steps = 2;

    while (steps-- > 0 && rangeEnd != s11.end())
    {
        ++rangeEnd;
    }

    s11.erase(rangeStart, rangeEnd);

    cout << "\n========== erase(range) =========="
         << endl;

    for (int x : s11)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 22. BEGIN()
    // ============================================================
    //
    // begin() first iterator deta hai.
    //
    // BUT:
    //
    // unordered_set mein "first" ka matlab:
    //
    //      smallest element
    //
    // nahi hai.
    //
    // Ye sirf container ke traversal order ka first element hai.
    //
    // ============================================================

    unordered_set<int> s12 = {
        50,
        10,
        30,
        20,
        40};

    cout << "\n========== begin() =========="
         << endl;

    auto it4 = s12.begin();

    cout << "Element at begin = "
         << *it4
         << endl;

    // ============================================================
    // 23. END()
    // ============================================================
    //
    // end() last element par point nahi karta.
    //
    // Ye:
    //
    //      last traversal position ke JUST AFTER
    //
    // iterator ko represent karta hai.
    //
    //
    // Important:
    //
    //      *s.end()
    //
    // WRONG hai.
    //
    // Correct:
    //
    //      for (auto it = s.begin();
    //           it != s.end();
    //           ++it)
    //
    // ============================================================

    cout << "\n========== end() =========="
         << endl;

    for (auto it = s12.begin();
         it != s12.end();
         ++it)
    {
        cout << *it << " ";
    }

    cout << endl;

    // ============================================================
    // 24. ITERATOR TRAVERSAL
    // ============================================================
    //
    // unordered_set ko iterator ke through traverse kar sakte hain.
    //
    // ============================================================

    cout << "\n========== Iterator Traversal =========="
         << endl;

    for (unordered_set<int>::iterator it = s12.begin();
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
    //      unordered_set<int>::const_iterator
    //
    // use kar sakte hain.
    //
    // ============================================================

    cout << "\n========== const_iterator =========="
         << endl;

    for (unordered_set<int>::const_iterator it = s12.begin();
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
    // Modern C++ mein easiest traversal:
    //
    //      for (int x : s)
    //
    // ============================================================

    cout << "\n========== Range Based Loop =========="
         << endl;

    for (int x : s12)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 27. IMPORTANT: NO SORTED ORDER
    // ============================================================
    //
    // std::set:
    //
    //      sorted
    //
    //
    // std::unordered_set:
    //
    //      NOT SORTED
    //
    //
    // Example:
    //
    //      unordered_set<int> s = {
    //          5, 1, 4, 2, 3
    //      };
    //
    //
    // Aapko output:
    //
    //      1 2 3 4 5
    //
    // milna guaranteed nahi hai.
    //
    // ============================================================

    // ============================================================
    // 28. NO INDEXING
    // ============================================================
    //
    // vector mein:
    //
    //      v[0]
    //
    // possible hai.
    //
    //
    // unordered_set mein:
    //
    //      s[0]
    //
    // WRONG hai.
    //
    //
    // Reason:
    //
    // unordered_set hash-table based container hai.
    //
    // Ismein index-based random access interface nahi hota.
    //
    // ============================================================

    // ============================================================
    // 29. LOWER_BOUND() NOT AVAILABLE
    // ============================================================
    //
    // std::set mein:
    //
    //      lower_bound()
    //
    // available hai.
    //
    //
    // Lekin unordered_set mein:
    //
    //      lower_bound()
    //
    // nahi hota.
    //
    //
    // Reason:
    //
    // lower_bound ordered data par meaningful hota hai.
    //
    // unordered_set ordered container nahi hai.
    //
    // ============================================================

    // ============================================================
    // 30. UPPER_BOUND() NOT AVAILABLE
    // ============================================================
    //
    // Similarly:
    //
    //      upper_bound()
    //
    // unordered_set mein available nahi hai.
    //
    //
    // Agar tumhe:
    //
    //      first element >= x
    //
    // ya:
    //
    //      first element > x
    //
    // chahiye,
    //
    // unordered_set suitable container nahi hai.
    //
    // Ordered set use karna better hai.
    //
    // ============================================================

    // ============================================================
    // 31. REVERSE ITERATION
    // ============================================================
    //
    // std::set mein:
    //
    //      rbegin()
    //      rend()
    //
    // useful hote hain.
    //
    //
    // unordered_set ke normal iterators bidirectional reverse
    // traversal provide nahi karte.
    //
    // Isliye:
    //
    //      rbegin()
    //      rend()
    //
    // ko ordered set ki tarah use nahi karna chahiye.
    //
    // ============================================================

    // ============================================================
    // 32. FIND() IS THE MAIN WEAPON
    // ============================================================
    //
    // unordered_set ka most important operation:
    //
    //      find()
    //
    //
    // Example:
    //
    //      if (s.find(x) != s.end())
    //
    //      {
    //          // x exists
    //      }
    //
    //
    // Average:
    //
    //      O(1)
    //
    // ============================================================

    unordered_set<int> findSet = {
        10,
        20,
        30,
        40,
        50};

    int target = 30;

    cout << "\n========== Fast Lookup =========="
         << endl;

    if (findSet.find(target) != findSet.end())
    {
        cout << target
             << " exists."
             << endl;
    }
    else
    {
        cout << target
             << " does not exist."
             << endl;
    }

    // ============================================================
    // 33. COUNT() FOR EXISTENCE CHECK
    // ============================================================
    //
    // Existence check ke liye:
    //
    //      s.count(x)
    //
    // bhi use kar sakte hain.
    //
    //
    // Example:
    //
    //      if (s.count(20))
    //
    //      {
    //          // exists
    //      }
    //
    // Since unordered_set unique hai:
    //
    //      count(x) = 0 or 1
    //
    // ============================================================

    cout << "\n========== count() Existence Check =========="
         << endl;

    if (findSet.count(20))
    {
        cout << "20 exists."
             << endl;
    }

    // ============================================================
    // 34. FIND VS COUNT
    // ============================================================
    //
    // find():
    //
    //      iterator return karta hai.
    //
    //
    // count():
    //
    //      number of matching elements return karta hai.
    //
    //
    // unordered_set mein:
    //
    //      count(x)
    //
    // normally:
    //
    //      0 or 1
    //
    //
    // Agar actual element / iterator chahiye:
    //
    //      find()
    //
    //
    // Sirf existence check karna ho:
    //
    //      count()
    //
    // useful hai.
    //
    // ============================================================

    // ============================================================
    // 35. BUCKETS
    // ============================================================
    //
    // unordered_set ka IMPORTANT internal concept:
    //
    //      BUCKETS
    //
    //
    // Hash function value ko ek bucket mein map karta hai.
    //
    //
    // Conceptually:
    //
    //
    //       value
    //         |
    //         v
    //      hash function
    //         |
    //         v
    //      bucket index
    //
    //
    // Example:
    //
    //      hash(42)
    //
    // may map 42 to some bucket.
    //
    // Exact bucket arrangement implementation dependent hai.
    //
    // ============================================================

    // ============================================================
    // 36. BUCKET_COUNT()
    // ============================================================
    //
    // bucket_count() current number of buckets return karta hai.
    //
    // Syntax:
    //
    //      s.bucket_count();
    //
    // ============================================================

    unordered_set<int> bucketSet = {
        10,
        20,
        30,
        40,
        50};

    cout << "\n========== bucket_count() =========="
         << endl;

    cout << "Number of buckets = "
         << bucketSet.bucket_count()
         << endl;

    // ============================================================
    // 37. BUCKET()
    // ============================================================
    //
    // bucket(value):
    //
    // batata hai ki given value kis bucket mein mapped hai.
    //
    // Syntax:
    //
    //      s.bucket(value);
    //
    // ============================================================

    cout << "\n========== bucket() =========="
         << endl;

    cout << "Bucket of 30 = "
         << bucketSet.bucket(30)
         << endl;

    // ============================================================
    // 38. BUCKET_SIZE()
    // ============================================================
    //
    // bucket_size(index):
    //
    // particular bucket mein kitne elements hain,
    // ye batata hai.
    //
    // ============================================================

    size_t bucketIndex = bucketSet.bucket(30);

    cout << "\n========== bucket_size() =========="
         << endl;

    cout << "Elements in bucket "
         << bucketIndex
         << " = "
         << bucketSet.bucket_size(bucketIndex)
         << endl;

    // ============================================================
    // 39. LOAD_FACTOR()
    // ============================================================
    //
    // load_factor() roughly:
    //
    //      number of elements / number of buckets
    //
    // ko represent karta hai.
    //
    //
    // Conceptually:
    //
    //      load factor = size / bucket_count
    //
    //
    // High load factor se collisions badh sakte hain.
    //
    // ============================================================

    cout << "\n========== load_factor() =========="
         << endl;

    cout << "Load factor = "
         << bucketSet.load_factor()
         << endl;

    // ============================================================
    // 40. MAX_LOAD_FACTOR()
    // ============================================================
    //
    // max_load_factor():
    //
    // hash table ka maximum desired load factor inspect/set
    // karne ke liye use hota hai.
    //
    //
    // Current maximum:
    //
    //      s.max_load_factor()
    //
    // Set:
    //
    //      s.max_load_factor(value);
    //
    // ============================================================

    cout << "\n========== max_load_factor() =========="
         << endl;

    cout << "Maximum load factor = "
         << bucketSet.max_load_factor()
         << endl;

    // ============================================================
    // 41. REHASH()
    // ============================================================
    //
    // rehash(n):
    //
    // container ko kam se kam n buckets ke saath rehash karne
    // ki request karta hai.
    //
    //
    // Example:
    //
    //      s.rehash(100);
    //
    //
    // Iska purpose:
    //
    //      bucket arrangement ko change karna.
    //
    // ============================================================

    cout << "\n========== rehash() =========="
         << endl;

    cout << "Before rehash = "
         << bucketSet.bucket_count()
         << " buckets"
         << endl;

    bucketSet.rehash(100);

    cout << "After rehash = "
         << bucketSet.bucket_count()
         << " buckets"
         << endl;

    // ============================================================
    // 42. RESERVE()
    // ============================================================
    //
    // Agar pehle se idea hai ki approximately kitne elements
    // insert karne hain:
    //
    //      reserve(n)
    //
    // useful ho sakta hai.
    //
    //
    // Example:
    //
    //      unordered_set<int> s;
    //
    //      s.reserve(1000);
    //
    //
    // Ye hashing structure ko enough capacity ke liye prepare
    // karne mein help karta hai aur unnecessary rehashing ko
    // reduce kar sakta hai.
    //
    // ============================================================

    unordered_set<int> reserveSet;

    cout << "\n========== reserve() =========="
         << endl;

    reserveSet.reserve(1000);

    cout << "Reserved space for approximately "
         << "1000 elements."
         << endl;

    // ============================================================
    // 43. HASH FUNCTION
    // ============================================================
    //
    // unordered_set hashing ka use karta hai.
    //
    // Default hash object:
    //
    //      std::hash<T>
    //
    //
    // Example:
    //
    //      hash<int>
    //
    // int ko hash value mein convert karta hai.
    //
    // ============================================================

    hash<int> intHash;

    cout << "\n========== std::hash<int> =========="
         << endl;

    cout << "Hash of 10 = "
         << intHash(10)
         << endl;

    cout << "Hash of 20 = "
         << intHash(20)
         << endl;

    // ============================================================
    // 44. HASHING CONCEPT
    // ============================================================
    //
    // Simple mental model:
    //
    //
    //      VALUE
    //        |
    //        v
    //   HASH FUNCTION
    //        |
    //        v
    //   HASH VALUE
    //        |
    //        v
    //     BUCKET
    //
    //
    // Isi wajah se unordered_set average case mein fast lookup
    // provide kar sakta hai.
    //
    // ============================================================

    // ============================================================
    // 45. COLLISION
    // ============================================================
    //
    // Agar multiple values same bucket mein map ho jaayein:
    //
    //      COLLISION
    //
    // hoti hai.
    //
    //
    // Concept:
    //
    //      value A ---> bucket 3
    //
    //      value B ---> bucket 3
    //
    //
    // Dono same bucket mein aa gaye.
    //
    //
    // Too many collisions:
    //
    //      lookup performance ko affect kar sakti hain.
    //
    // Isi wajah se unordered_set ka complexity:
    //
    //      Average -> O(1)
    //
    //      Worst   -> O(n)
    //
    // ho sakta hai.
    //
    // ============================================================

    // ============================================================
    // 46. SET VS UNORDERED_SET
    // ============================================================
    //
    // std::set:
    //
    //      - unique
    //      - sorted
    //      - ordered traversal
    //      - generally O(log n)
    //
    //
    // std::unordered_set:
    //
    //      - unique
    //      - unordered
    //      - hash table based
    //      - average O(1)
    //
    //
    // Agar sorted order required hai:
    //
    //      set
    //
    //
    // Agar order matter nahi karta aur fast lookup chahiye:
    //
    //      unordered_set
    //
    // ============================================================

    // ============================================================
    // 47. UNORDERED_SET VS VECTOR
    // ============================================================
    //
    // vector:
    //
    //      - duplicates allowed
    //      - insertion order preserved
    //      - indexing available
    //      - v[0]
    //      - random access
    //
    //
    // unordered_set:
    //
    //      - duplicates NOT allowed
    //      - order not guaranteed
    //      - indexing NOT available
    //      - fast average lookup
    //
    // ============================================================

    // ============================================================
    // 48. UNORDERED_SET VS UNORDERED_MULT
    // ============================================================
    //
    // unordered_set:
    //
    //      UNIQUE values
    //
    //
    // unordered_multiset:
    //
    //      DUPLICATES allowed
    //
    //
    // Example:
    //
    // unordered_set:
    //
    //      {10, 20, 30}
    //
    //
    // unordered_multiset:
    //
    //      {10, 10, 20, 20, 30}
    //
    // ============================================================

    // ============================================================
    // 49. TIME COMPLEXITY
    // ============================================================
    //
    // IMPORTANT DSA NOTES:
    //
    //
    // insert:
    //
    //      Average -> O(1)
    //
    //      Worst   -> O(n)
    //
    //
    // find:
    //
    //      Average -> O(1)
    //
    //      Worst   -> O(n)
    //
    //
    // erase by key:
    //
    //      Average -> O(1)
    //
    //      Worst   -> O(n)
    //
    //
    // count:
    //
    //      Average -> O(1)
    //
    //      Worst   -> O(n)
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
    // 50. DSA USE CASE - UNIQUE ELEMENTS
    // ============================================================
    //
    // Suppose:
    //
    //      array = {
    //          1, 2, 2, 3, 4, 4, 5
    //      };
    //
    //
    // Agar humein sirf unique values chahiye:
    //
    //      unordered_set
    //
    // useful hai.
    //
    //
    // Difference:
    //
    //      set
    //          -> unique + sorted
    //
    //      unordered_set
    //          -> unique + fast lookup
    //
    // ============================================================

    vector<int> arr = {
        1,
        2,
        2,
        3,
        4,
        4,
        5};

    unordered_set<int> uniqueElements(
        arr.begin(),
        arr.end());

    cout << "\n========== DSA: Unique Elements =========="
         << endl;

    for (int x : uniqueElements)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 51. DSA USE CASE - DUPLICATE DETECTION
    // ============================================================
    //
    // Ye unordered_set ka VERY IMPORTANT use case hai.
    //
    //
    // Algorithm:
    //
    //      1. Empty unordered_set banao.
    //
    //      2. Array traverse karo.
    //
    //      3. Current value insert karo.
    //
    //      4. Agar insertion fail ho:
    //
    //             duplicate found
    //
    //
    // Average complexity:
    //
    //      O(n)
    //
    // ============================================================

    vector<int> duplicateCheck = {
        10,
        20,
        30,
        20,
        40};

    unordered_set<int> seen;

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
        cout << "\nNo duplicate found."
             << endl;
    }

    // ============================================================
    // 52. DSA USE CASE - FAST MEMBERSHIP TEST
    // ============================================================
    //
    // Problem:
    //
    //      Bahut saare elements diye hain.
    //
    //      Humein baar-baar check karna hai:
    //
    //          "Kya x present hai?"
    //
    //
    // unordered_set is case mein excellent choice ho sakta hai.
    //
    // ============================================================

    unordered_set<int> membership = {
        100,
        200,
        300,
        400,
        500};

    int query = 300;

    cout << "\n========== DSA: Membership Test =========="
         << endl;

    if (membership.find(query) != membership.end())
    {
        cout << query
             << " is present."
             << endl;
    }
    else
    {
        cout << query
             << " is not present."
             << endl;
    }

    // ============================================================
    // 53. DSA USE CASE - UNIQUE WORDS
    // ============================================================
    //
    // String list mein unique words find karne ke liye:
    //
    //      unordered_set<string>
    //
    // use kar sakte hain.
    //
    // ============================================================

    vector<string> words = {
        "apple",
        "banana",
        "apple",
        "orange",
        "banana",
        "mango"};

    unordered_set<string> uniqueWords(
        words.begin(),
        words.end());

    cout << "\n========== DSA: Unique Words =========="
         << endl;

    for (const string &word : uniqueWords)
    {
        cout << word << endl;
    }

    // ============================================================
    // 54. DSA USE CASE - CHECK COMMON ELEMENT
    // ============================================================
    //
    // Do arrays mein common element hai ya nahi check karna.
    //
    // Approach:
    //
    //      1. First array ke elements unordered_set mein store karo.
    //
    //      2. Second array traverse karo.
    //
    //      3. find() se check karo.
    //
    //
    // Average complexity:
    //
    //      O(n + m)
    //
    // ============================================================

    vector<int> firstArray = {
        10,
        20,
        30,
        40};

    vector<int> secondArray = {
        5,
        15,
        30,
        60};

    unordered_set<int> firstSet(
        firstArray.begin(),
        firstArray.end());

    bool commonFound = false;

    for (int x : secondArray)
    {
        if (firstSet.find(x) != firstSet.end())
        {
            commonFound = true;

            cout << "\nCommon element = "
                 << x
                 << endl;

            break;
        }
    }

    if (!commonFound)
    {
        cout << "\nNo common element."
             << endl;
    }

    // ============================================================
    // 55. DSA USE CASE - INTERSECTION
    // ============================================================
    //
    // First container ke unique elements ko hash set mein store
    // karke second container ke elements lookup kar sakte hain.
    //
    // Ye intersection-type problems mein useful hai.
    //
    // ============================================================

    vector<int> A = {
        1,
        2,
        3,
        4,
        5};

    vector<int> B = {
        3,
        4,
        5,
        6,
        7};

    unordered_set<int> setA(
        A.begin(),
        A.end());

    unordered_set<int> intersection;

    for (int x : B)
    {
        if (setA.find(x) != setA.end())
        {
            intersection.insert(x);
        }
    }

    cout << "\n========== DSA: Intersection =========="
         << endl;

    for (int x : intersection)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 56. DSA USE CASE - REMOVE DUPLICATES
    // ============================================================
    //
    // Agar vector mein duplicates hain:
    //
    //      vector<int>
    //
    // se:
    //
    //      unordered_set<int>
    //
    // bana sakte hain.
    //
    // Result:
    //
    //      unique values
    //
    // Order guaranteed nahi hoga.
    //
    // ============================================================

    vector<int> duplicateVector = {
        5,
        1,
        2,
        5,
        3,
        2,
        1};

    unordered_set<int> uniqueSet(
        duplicateVector.begin(),
        duplicateVector.end());

    cout << "\n========== Remove Duplicates =========="
         << endl;

    for (int x : uniqueSet)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 57. DSA USE CASE - LONG LONG VALUES
    // ============================================================
    //
    // Large values ke existence check ke liye:
    //
    //      unordered_set<long long>
    //
    // useful ho sakta hai.
    //
    // ============================================================

    unordered_set<long long> ids = {
        10000000001LL,
        10000000002LL,
        10000000003LL};

    long long searchID = 10000000002LL;

    cout << "\n========== Large Value Lookup =========="
         << endl;

    if (ids.find(searchID) != ids.end())
    {
        cout << "ID found."
             << endl;
    }
    else
    {
        cout << "ID not found."
             << endl;
    }

    // ============================================================
    // 58. COPY CONSTRUCTOR
    // ============================================================
    //
    // Ek unordered_set ko doosre unordered_set mein copy kar sakte
    // hain.
    //
    // ============================================================

    unordered_set<int> original = {
        10,
        20,
        30};

    unordered_set<int> copied = original;

    cout << "\n========== Copy Unordered Set =========="
         << endl;

    for (int x : copied)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 59. ASSIGNMENT OPERATOR
    // ============================================================
    //
    // Existing unordered_set ko doosre unordered_set mein assign
    // kar sakte hain.
    //
    // Syntax:
    //
    //      setB = setA;
    //
    // Iske baad setB ke andar setA ke saare elements aa jayenge.
    //
    // ============================================================

    unordered_set<int> assignmentSourceSet = {
        1,
        2,
        3};

    unordered_set<int> assignmentTargetSet = {
        100,
        200};

    // assignmentSourceSet ke elements
    // assignmentTargetSet mein copy ho jayenge.

    assignmentTargetSet = assignmentSourceSet;

    cout << "\n========== Assignment =========="
         << endl;

    cout << "Source Set: ";

    for (int x : assignmentSourceSet)
    {
        cout << x << " ";
    }

    cout << endl;

    cout << "Target Set: ";

    for (int x : assignmentTargetSet)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 60. SWAP()
    // ============================================================
    //
    // swap() do unordered_sets ke contents exchange karta hai.
    //
    // Syntax:
    //
    //      setC.swap(setD);
    //
    // ============================================================

    unordered_set<int> setC = {
        10,
        20,
        30};

    unordered_set<int> setD = {
        100,
        200,
        300};

    setC.swap(setD);

    cout << "\n========== swap() =========="
         << endl;

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
    // 61. MAXIMUM / MINIMUM
    // ============================================================
    //
    // IMPORTANT:
    //
    // unordered_set mein:
    //
    //      *begin()
    //
    // ko minimum mat samajhna.
    //
    //
    // set mein:
    //
    //      *begin()
    //
    // default ascending ordering ke kaaran smallest hota hai.
    //
    //
    // unordered_set mein:
    //
    //      *begin()
    //
    // sirf arbitrary/traversal-order element hai.
    //
    //
    // Agar minimum/maximum chahiye:
    //
    //      traversal karke find karo
    //
    // ya:
    //
    //      set
    //
    // jaise ordered container use karo.
    //
    // ============================================================

    // ============================================================
    // 62. FINDING MINIMUM MANUALLY
    // ============================================================
    //
    // unordered_set mein minimum directly begin() se nahi milta.
    //
    // Humein traverse karna padega.
    //
    // ============================================================

    unordered_set<int> minMaxSet = {
        50,
        10,
        40,
        20,
        30};

    int minimum = *minMaxSet.begin();
    int maximum = *minMaxSet.begin();

    for (int x : minMaxSet)
    {
        if (x < minimum)
        {
            minimum = x;
        }

        if (x > maximum)
        {
            maximum = x;
        }
    }

    cout << "\n========== Minimum / Maximum =========="
         << endl;

    cout << "Minimum = "
         << minimum
         << endl;

    cout << "Maximum = "
         << maximum
         << endl;

    // ============================================================
    // 63. WHY unordered_set IS FAST
    // ============================================================
    //
    // Main reason:
    //
    //      HASHING
    //
    //
    // Ordered set ko generally tree traversal karni padti hai:
    //
    //      O(log n)
    //
    //
    // unordered_set hash table use karta hai:
    //
    //      Average O(1)
    //
    //
    // Therefore membership checks bahut fast ho sakte hain.
    //
    // ============================================================

    // ============================================================
    // 64. BUT O(1) IS NOT ALWAYS GUARANTEED
    // ============================================================
    //
    // Bahut important interview point:
    //
    //      unordered_set == always O(1)
    //
    // Ye statement completely correct nahi hai.
    //
    //
    // Correct:
    //
    //      Average case -> O(1)
    //
    //      Worst case   -> O(n)
    //
    //
    // Worst case ka major reason:
    //
    //      collisions
    //
    // ============================================================

    // ============================================================
    // 65. REHASHING
    // ============================================================
    //
    // Jab hash table mein elements increase hote hain aur load
    // factor threshold cross hota hai:
    //
    //      rehashing
    //
    // ho sakti hai.
    //
    //
    // Rehashing mein:
    //
    //      buckets ka arrangement change hota hai.
    //
    //
    // Important:
    //
    // Rehashing ki wajah se iterators invalidate ho sakte hain.
    //
    // Isliye iterator use karte waqt rehashing ka concept important hai.
    //
    // ============================================================

    // ============================================================
    // 66. ITERATOR INVALIDATION - BASIC NOTE
    // ============================================================
    //
    // unordered_set mein insertion ke time rehashing ho sakti hai.
    //
    // Agar rehash hota hai:
    //
    //      existing iterators invalidate ho sakte hain.
    //
    //
    // Isliye:
    //
    //      iterator ko long time store karke
    //      container ko modify karte rehna
    //
    // carefully handle karna chahiye.
    //
    // ============================================================

    // ============================================================
    // 67. ERASE DOES NOT INVALIDATE ALL ITERATORS
    // ============================================================
    //
    // Kisi particular element ko erase karne par:
    //
    //      erased element ka iterator invalidate hota hai.
    //
    //
    // Baaki elements ke iterators generally valid rehte hain,
    // jab tak koi rehashing situation involved na ho.
    //
    // ============================================================

    // ============================================================
    // 68. SET OF STRINGS
    // ============================================================
    //
    // Fast unique word storage ke liye:
    //
    //      unordered_set<string>
    //
    // useful hai.
    //
    //
    // Example:
    //
    //      dictionary / visited words
    //
    // ============================================================

    unordered_set<string> dictionary;

    dictionary.insert("apple");
    dictionary.insert("banana");
    dictionary.insert("mango");
    dictionary.insert("apple");

    cout << "\n========== Dictionary =========="
         << endl;

    for (const string &word : dictionary)
    {
        cout << word << endl;
    }

    // ============================================================
    // 69. CASE SENSITIVITY
    // ============================================================
    //
    // unordered_set<string> mein default string hashing/comparison
    // case-sensitive hoti hai.
    //
    //
    // Therefore:
    //
    //      "Apple"
    //
    // and:
    //
    //      "apple"
    //
    // different values hain.
    //
    // ============================================================

    unordered_set<string> caseSet = {
        "Apple",
        "apple",
        "BANANA",
        "banana"};

    cout << "\n========== Case Sensitive =========="
         << endl;

    for (const string &word : caseSet)
    {
        cout << word << endl;
    }

    // ============================================================
    // 70. CUSTOM TYPE - IMPORTANT CONCEPT
    // ============================================================
    //
    // unordered_set custom class/struct ko bhi store kar sakta hai,
    // lekin us type ke liye hashing aur equality support required
    // hota hai.
    //
    //
    // Built-in types:
    //
    //      int
    //      char
    //      string
    //      long long
    //
    // ke liye standard library hash support provide karti hai.
    //
    //
    // Custom type ke liye:
    //
    //      custom hash
    //
    // and:
    //
    //      equality
    //
    // define karni pad sakti hai.
    //
    // ============================================================

    // ============================================================
    // 71. CUSTOM HASH CONCEPT
    // ============================================================
    //
    // Example concept:
    //
    //      struct MyHash
    //      {
    //          size_t operator()(const MyType &obj) const
    //          {
    //              return ...;
    //          }
    //      };
    //
    //
    // Then:
    //
    //      unordered_set<MyType, MyHash>
    //
    // use kiya ja sakta hai.
    //
    // ============================================================

    // ============================================================
    // 72. SET OF PAIR VS UNORDERED_SET OF PAIR
    // ============================================================
    //
    // std::set<pair<int,int>>:
    //
    //      pair ordered hoti hai.
    //
    //
    // unordered_set<pair<int,int>>:
    //
    //      pair ke liye suitable hash support required hai.
    //
    //
    // Modern C++ standard library versions mein direct
    // std::hash<pair<int,int>> support assumptions par depend
    // karna safe nahi hai.
    //
    // Custom hash define karna common approach hai.
    //
    // ============================================================

    // ============================================================
    // 73. CUSTOM HASH FOR PAIR
    // ============================================================
    //
    // Example:
    //
    //      struct PairHash
    //      {
    //          size_t operator()(
    //              const pair<int,int>& p
    //          ) const
    //          {
    //              return hash<int>{}(p.first)
    //                   ^
    //                   (hash<int>{}(p.second) << 1);
    //          }
    //      };
    //
    //
    // Then:
    //
    //      unordered_set<pair<int,int>, PairHash> s;
    //
    //
    // Ye concept DSA mein bahut useful hai.
    //
    // ============================================================

    // ============================================================
    // 74. DSA - UNIQUE COORDINATES
    // ============================================================
    //
    // Pair coordinates ko unique store karne ka use-case:
    //
    //      (x,y)
    //
    //
    // Example:
    //
    //      (1,2)
    //      (2,3)
    //      (1,2)
    //
    //
    // Duplicate coordinate ko avoid karna ho to hashing useful hai.
    //
    // ============================================================

    // ============================================================
    // 75. DSA - VISITED SET
    // ============================================================
    //
    // Graph / BFS / DFS / state-space problems mein:
    //
    //      visited
    //
    // states ko store karna common hai.
    //
    //
    // Agar state integer hai:
    //
    //      unordered_set<int> visited;
    //
    //
    // Check:
    //
    //      if (visited.count(node))
    //
    //
    // Mark:
    //
    //      visited.insert(node);
    //
    //
    // Average lookup:
    //
    //      O(1)
    //
    // ============================================================

    unordered_set<int> visited;

    visited.insert(1);
    visited.insert(2);
    visited.insert(3);

    cout << "\n========== DSA: Visited Set =========="
         << endl;

    int node = 2;

    if (visited.count(node))
    {
        cout << "Node "
             << node
             << " already visited."
             << endl;
    }

    // ============================================================
    // 76. DSA - TWO SUM STYLE LOOKUP
    // ============================================================
    //
    // unordered_set fast lookup ke liye useful hai.
    //
    //
    // Given:
    //
    //      array
    //
    // Target:
    //
    //      target
    //
    //
    // For each x:
    //
    //      required = target - x
    //
    //
    // Check:
    //
    //      required exists?
    //
    // using unordered_set.
    //
    // ============================================================

    vector<int> twoSumArray = {
        2,
        7,
        11,
        15};

    int twoSumTarget = 9;

    unordered_set<int> twoSumSeen;

    cout << "\n========== DSA: Two Sum Style =========="
         << endl;

    for (int x : twoSumArray)
    {
        int required = twoSumTarget - x;

        if (twoSumSeen.count(required))
        {
            cout << "Pair found: "
                 << required
                 << " + "
                 << x
                 << " = "
                 << twoSumTarget
                 << endl;

            break;
        }

        twoSumSeen.insert(x);
    }

    // ============================================================
    // 77. DSA - LONGEST CONSECUTIVE SEQUENCE
    // ============================================================
    //
    // unordered_set ka famous DSA problem:
    //
    //      Longest Consecutive Sequence
    //
    //
    // Example:
    //
    //      100, 4, 200, 1, 3, 2
    //
    //
    // Answer:
    //
    //      4
    //
    // Because:
    //
    //      1,2,3,4
    //
    //
    // unordered_set fast membership lookup provide karta hai.
    //
    // ============================================================

    vector<int> sequence = {
        100,
        4,
        200,
        1,
        3,
        2};

    unordered_set<int> sequenceSet(
        sequence.begin(),
        sequence.end());

    int longest = 0;

    for (int x : sequenceSet)
    {
        // x sequence ka starting element hai ya nahi?
        //
        // Agar x - 1 present nahi hai,
        // to x se sequence start ho sakti hai.

        if (!sequenceSet.count(x - 1))
        {
            int current = x;
            int length = 1;

            while (sequenceSet.count(current + 1))
            {
                current++;
                length++;
            }

            longest = max(longest, length);
        }
    }

    cout << "\n========== DSA: Longest Consecutive Sequence =========="
         << endl;

    cout << "Longest length = "
         << longest
         << endl;

    // ============================================================
    // 78. DSA - FIRST REPEATING ELEMENT
    // ============================================================
    //
    // unordered_set se repeated element detect kar sakte hain.
    //
    // ============================================================

    vector<int> repeatingArray = {
        5,
        3,
        1,
        4,
        3,
        5};

    unordered_set<int> repeatSeen;

    cout << "\n========== DSA: First Repeating Element =========="
         << endl;

    for (int x : repeatingArray)
    {
        if (repeatSeen.count(x))
        {
            cout << "First repeating element = "
                 << x
                 << endl;

            break;
        }

        repeatSeen.insert(x);
    }

    // ============================================================
    // 79. DSA - UNIQUE CHARACTERS
    // ============================================================
    //
    // String mein unique characters count/check karne ke liye:
    //
    //      unordered_set<char>
    //
    // useful hai.
    //
    // ============================================================

    string text = "programming";

    unordered_set<char> uniqueChars;

    for (char ch : text)
    {
        uniqueChars.insert(ch);
    }

    cout << "\n========== DSA: Unique Characters =========="
         << endl;

    cout << "Unique character count = "
         << uniqueChars.size()
         << endl;

    // ============================================================
    // 80. DSA - CHECK ALL CHARACTERS UNIQUE
    // ============================================================
    //
    // Agar:
    //
    //      set.size() == string.length()
    //
    // then all characters unique hain.
    //
    // ============================================================

    string uniqueText = "abcde";

    unordered_set<char> charSet(
        uniqueText.begin(),
        uniqueText.end());

    cout << "\n========== DSA: All Characters Unique =========="
         << endl;

    if (charSet.size() == uniqueText.size())
    {
        cout << "All characters are unique."
             << endl;
    }
    else
    {
        cout << "Duplicate character exists."
             << endl;
    }

    // ============================================================
    // 81. DSA - REMOVE DUPLICATE CHARACTERS
    // ============================================================
    //
    // Example:
    //
    //      "programming"
    //
    // unique characters:
    //
    //      p r o g a m i n
    //
    // NOTE:
    //
    // unordered_set order preserve nahi karta.
    //
    // ============================================================

    string duplicateText = "programming";

    unordered_set<char> characters;

    for (char ch : duplicateText)
    {
        characters.insert(ch);
    }

    cout << "\n========== Unique Characters =========="
         << endl;

    for (char ch : characters)
    {
        cout << ch << " ";
    }

    cout << endl;

    // ============================================================
    // 82. IMPORTANT: ORDER PRESERVE NAHI HOTA
    // ============================================================
    //
    // Ye bahut important hai.
    //
    // unordered_set ko use mat karo agar tumhe:
    //
    //      insertion order
    //
    // preserve karna hai.
    //
    //
    // Example:
    //
    // Input:
    //
    //      10 20 30 40
    //
    //
    // unordered_set:
    //
    //      output order guaranteed nahi.
    //
    //
    // Agar insertion order preserve karna hai:
    //
    //      vector
    //
    // ya additional data structure use karna padega.
    //
    // ============================================================

    // ============================================================
    // 83. IMPORTANT: SORTING NOT AVAILABLE
    // ============================================================
    //
    // unordered_set ka purpose sorting nahi hai.
    //
    //
    // Agar sorted output chahiye:
    //
    //      1. unordered_set -> vector
    //
    //      2. vector sort karo
    //
    //
    // OR:
    //
    //      directly set use karo.
    //
    // ============================================================

    // ============================================================
    // 84. CONVERT unordered_set TO vector
    // ============================================================
    //
    // Agar unordered_set ke elements ko sort karna ho:
    //
    //      vector<int> v(s.begin(), s.end());
    //
    // Then:
    //
    //      sort(v.begin(), v.end());
    //
    // ============================================================

    unordered_set<int> unsortedData = {
        50,
        10,
        40,
        20,
        30};

    vector<int> sortedVector(
        unsortedData.begin(),
        unsortedData.end());

    sort(
        sortedVector.begin(),
        sortedVector.end());

    cout << "\n========== unordered_set -> vector -> sort =========="
         << endl;

    for (int x : sortedVector)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 85. set VS unordered_set PRACTICAL CHOICE
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
    //      "Mujhe unique elements chahiye aur order matter nahi
    //       karta, but fast lookup chahiye."
    //
    // Answer:
    //
    //      unordered_set
    //
    //
    // Question:
    //
    //      "Mujhe duplicate elements bhi chahiye aur sorted order."
    //
    // Answer:
    //
    //      multiset
    //
    //
    // Question:
    //
    //      "Mujhe duplicate elements bhi chahiye aur order
    //       matter nahi karta."
    //
    // Answer:
    //
    //      unordered_multiset
    //
    // ============================================================

    // ============================================================
    // 86. set vs unordered_set - QUICK TABLE
    // ============================================================
    //
    /*

        FEATURE             set             unordered_set
        ---------------------------------------------------------
        Unique              YES             YES
        Sorted              YES             NO
        Hashing             NO              YES
        Indexing            NO              NO
        Average find        O(log n)        O(1)
        Average insert      O(log n)        O(1)
        Average erase       O(log n)        O(1)
        lower_bound         YES             NO
        upper_bound         YES             NO
        Order guaranteed    YES             NO
        Main use            Ordered         Fast lookup

    */

    // ============================================================
    // 87. INTERVIEW POINT
    // ============================================================
    //
    // Q:
    //
    //      Does unordered_set allow duplicate elements?
    //
    // A:
    //
    //      No.
    //
    //
    // Q:
    //
    //      Is unordered_set sorted?
    //
    // A:
    //
    //      No.
    //
    //
    // Q:
    //
    //      What does unordered_set use?
    //
    // A:
    //
    //      Hashing / hash table based organization.
    //
    //
    // Q:
    //
    //      Average search complexity?
    //
    // A:
    //
    //      O(1)
    //
    //
    // Q:
    //
    //      Worst-case search complexity?
    //
    // A:
    //
    //      O(n)
    //
    //
    // Q:
    //
    //      Does unordered_set support indexing?
    //
    // A:
    //
    //      No.
    //
    //
    // Q:
    //
    //      Does unordered_set have lower_bound()?
    //
    // A:
    //
    //      No.
    //
    //
    // Q:
    //
    //      Why is it generally faster than set?
    //
    // A:
    //
    //      Because it uses hashing and average lookup is O(1).
    //
    // ============================================================

    // ============================================================
    // 88. MOST IMPORTANT DSA PATTERN
    // ============================================================
    //
    // Pattern:
    //
    //      unordered_set<int> seen;
    //
    //
    //      for (int x : arr)
    //      {
    //          if (seen.count(x))
    //          {
    //              // duplicate
    //          }
    //
    //          seen.insert(x);
    //      }
    //
    //
    // Ye pattern DSA mein extremely common hai.
    //
    // ============================================================

    // ============================================================
    // 89. FAST LOOKUP PATTERN
    // ============================================================
    //
    // Pattern:
    //
    //      unordered_set<int> s;
    //
    //      if (s.count(x))
    //      {
    //          // x exists
    //      }
    //
    //
    // OR:
    //
    //      if (s.find(x) != s.end())
    //      {
    //          // x exists
    //      }
    //
    // ============================================================

    // ============================================================
    // 90. INSERT + CHECK PATTERN
    // ============================================================
    //
    // Important:
    //
    //      auto result = s.insert(x);
    //
    //
    //      result.second == true
    //
    //          -> x new tha
    //
    //
    //      result.second == false
    //
    //          -> x already present tha
    //
    //
    // Ye duplicate detection ke liye useful hai.
    //
    // ============================================================

    // ============================================================
    // 91. COMPLETE MINI EXAMPLE
    // ============================================================
    //
    // Input:
    //
    //      8 3 5 3 1 8 2 5
    //
    //
    // unordered_set:
    //
    //      unique values
    //
    // But:
    //
    //      sorted order guaranteed nahi.
    //
    // ============================================================

    unordered_set<int> miniSet;

    miniSet.insert(8);
    miniSet.insert(3);
    miniSet.insert(5);
    miniSet.insert(3);
    miniSet.insert(1);
    miniSet.insert(8);
    miniSet.insert(2);
    miniSet.insert(5);

    cout << "\n========== Complete Mini Example =========="
         << endl;

    cout << "Unique values: ";

    for (int x : miniSet)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // 92. COMPLETE DSA EXAMPLE - DUPLICATE CHECK
    // ============================================================

    vector<int> input = {
        10,
        20,
        30,
        40,
        30};

    unordered_set<int> check;

    bool hasDuplicate = false;

    for (int x : input)
    {
        if (check.count(x))
        {
            hasDuplicate = true;

            cout << "\nDuplicate exists: "
                 << x
                 << endl;

            break;
        }

        check.insert(x);
    }

    if (!hasDuplicate)
    {
        cout << "\nArray has no duplicate."
             << endl;
    }

    // ============================================================
    // 93. COMPLETE DSA EXAMPLE - UNIQUE COUNT
    // ============================================================
    //
    // Number of unique values:
    //
    //      unordered_set.size()
    //
    // ============================================================

    vector<int> uniqueCountArray = {
        1,
        2,
        2,
        3,
        3,
        3,
        4};

    unordered_set<int> uniqueCountSet(
        uniqueCountArray.begin(),
        uniqueCountArray.end());

    cout << "\n========== Unique Count =========="
         << endl;

    cout << "Number of unique values = "
         << uniqueCountSet.size()
         << endl;

    // ============================================================
    // 94. COMPLETE DSA EXAMPLE - CHECK TWO ARRAYS
    // ============================================================
    //
    // Check whether second array ka koi element first array
    // mein present hai.
    //
    // ============================================================

    vector<int> arr1 = {
        10,
        20,
        30,
        40};

    vector<int> arr2 = {
        100,
        200,
        30,
        500};

    unordered_set<int> lookup(
        arr1.begin(),
        arr1.end());

    bool foundCommon = false;

    for (int x : arr2)
    {
        if (lookup.count(x))
        {
            foundCommon = true;

            cout << "\nCommon value found = "
                 << x
                 << endl;

            break;
        }
    }

    if (!foundCommon)
    {
        cout << "\nNo common value."
             << endl;
    }

    // ============================================================
    // 95. IMPORTANT LIMITATION
    // ============================================================
    //
    // unordered_set choose MAT karo agar:
    //
    //      1. Sorted traversal chahiye.
    //
    //      2. lower_bound() chahiye.
    //
    //      3. upper_bound() chahiye.
    //
    //      4. Previous/next ordered element chahiye.
    //
    //      5. Range queries ordered values par karni hain.
    //
    //
    // In cases:
    //
    //      set
    //
    // better choice ho sakta hai.
    //
    // ============================================================

    // ============================================================
    // 96. WHEN TO USE unordered_set
    // ============================================================
    //
    // unordered_set use karo jab:
    //
    //      1. Unique values chahiye.
    //
    //      2. Ordering important nahi hai.
    //
    //      3. Fast average lookup chahiye.
    //
    //      4. Duplicate detection karna hai.
    //
    //      5. Membership checking baar-baar karni hai.
    //
    //      6. Visited states store karne hain.
    //
    //      7. Unique characters/words store karne hain.
    //
    //      8. Hash-based DSA solution banana hai.
    //
    // ============================================================

    // ============================================================
    // 97. WHEN NOT TO USE unordered_set
    // ============================================================
    //
    // unordered_set avoid karo jab:
    //
    //      1. Sorted order required ho.
    //
    //      2. lower_bound / upper_bound required ho.
    //
    //      3. Ordered predecessor/successor chahiye.
    //
    //      4. Range-based ordered queries required ho.
    //
    //      5. Stable/insertion order expected ho.
    //
    // ============================================================

    // ============================================================
    // 98. FINAL CHEAT SHEET
    // ============================================================
    //
    /*

        HEADER:

            #include <unordered_set>


        CREATE:

            unordered_set<int> s;


        INITIALIZE:

            unordered_set<int> s = {
                10, 20, 30
            };


        INSERT:

            s.insert(40);


        FIND:

            auto it = s.find(20);


        CHECK FOUND:

            if (it != s.end())


        COUNT:

            s.count(20);


        DELETE BY VALUE:

            s.erase(20);


        DELETE BY ITERATOR:

            s.erase(it);


        SIZE:

            s.size();


        EMPTY:

            s.empty();


        CLEAR:

            s.clear();


        ITERATION:

            for (auto x : s)
            {
                cout << x;
            }


        BUCKET COUNT:

            s.bucket_count();


        BUCKET OF VALUE:

            s.bucket(x);


        BUCKET SIZE:

            s.bucket_size(i);


        LOAD FACTOR:

            s.load_factor();


        MAX LOAD FACTOR:

            s.max_load_factor();


        REHASH:

            s.rehash(n);


        RESERVE:

            s.reserve(n);


        SWAP:

            s1.swap(s2);


        NO INDEXING:

            s[0];       // WRONG


        NO LOWER_BOUND:

            s.lower_bound(x);    // WRONG


        NO UPPER_BOUND:

            s.upper_bound(x);    // WRONG


        AVERAGE:

            insert   -> O(1)
            find     -> O(1)
            erase    -> O(1)


        WORST CASE:

            insert   -> O(n)
            find     -> O(n)
            erase    -> O(n)

    */

    // ============================================================
    // 99. FINAL CONCEPT
    // ============================================================
    //
    // std::unordered_set ka basic mental model:
    //
    //
    //                 VALUE
    //                   |
    //                   v
    //              HASH FUNCTION
    //                   |
    //                   v
    //                BUCKET
    //                   |
    //                   v
    //             HASH TABLE
    //
    //
    // Main properties:
    //
    //      UNIQUE
    //
    //      UNORDERED
    //
    //      HASH BASED
    //
    //      FAST AVERAGE LOOKUP
    //
    //
    // Example:
    //
    //      unordered_set<int>
    //
    //      insert(10)
    //      insert(20)
    //      insert(10)
    //
    //
    // Result:
    //
    //      10
    //      20
    //
    // But traversal order guaranteed nahi hai.
    //
    //
    // DSA mein especially useful:
    //
    //      1. Duplicate detection
    //
    //      2. Membership checking
    //
    //      3. Unique elements
    //
    //      4. Visited nodes/states
    //
    //      5. Unique characters
    //
    //      6. Unique words
    //
    //      7. Intersection/common elements
    //
    //      8. Two-sum style lookup
    //
    //      9. Longest consecutive sequence
    //
    // ============================================================

    // ============================================================
    // 100. FINAL ONE-LINE MEMORY TRICK
    // ============================================================
    //
    //      set
    //          = UNIQUE + SORTED
    //
    //
    //      unordered_set
    //          = UNIQUE + FAST AVERAGE LOOKUP
    //
    //
    //      multiset
    //          = DUPLICATES + SORTED
    //
    //
    //      unordered_multiset
    //          = DUPLICATES + HASHING
    //
    // ============================================================

    cout << "\n============================================"
         << endl;

    cout << "       UNORDERED_SET CONCEPT COMPLETED"
         << endl;

    cout << "============================================"
         << endl;

    return 0;
}