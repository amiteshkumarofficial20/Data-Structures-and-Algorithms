/*
===============================================================================
                    C++ STL - unordered_set
             DETAILED NOTES + COMPLETE CODE + DSA
===============================================================================

HEADER FILE:

    #include <unordered_set>


WHAT IS unordered_set?

    std::unordered_set is an STL container used to store UNIQUE elements.

    It is based on HASHING.

    Unlike std::set, it does NOT maintain sorted order.


MAIN IDEA:

    set
        = UNIQUE + SORTED

    unordered_set
        = UNIQUE + UNORDERED + HASHING


IMPORTANT PROPERTIES:

    1. Stores UNIQUE elements.
    2. Duplicate elements are ignored.
    3. Does NOT maintain sorted order.
    4. Traversal order is NOT guaranteed.
    5. Uses hashing internally.
    6. Average insertion    -> O(1)
    7. Average searching    -> O(1)
    8. Average deletion     -> O(1)
    9. Worst case           -> O(n)
   10. No indexing.
   11. lower_bound() is NOT available.
   12. upper_bound() is NOT available.
   13. Best for fast membership checking.
   14. Rehashing can happen when the container grows.


BASIC SYNTAX:

    unordered_set<int> s;

    unordered_set<string> names;

    unordered_set<char> letters;


EXAMPLE:

    unordered_set<int> s;

    s.insert(10);
    s.insert(20);
    s.insert(10);

    Final elements:

        10
        20

    because duplicates are not allowed.


===============================================================================
*/

#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{

    //==========================================================================
    // 1. BASIC DECLARATION
    //==========================================================================
    //
    // Syntax:
    //
    //      unordered_set<DataType> variableName;
    //
    // Example:
    //
    //      unordered_set<int> numbers;
    //
    //==========================================================================

    unordered_set<int> numbers;

    //==========================================================================
    // 2. INSERT()
    //==========================================================================
    //
    // insert() is used to insert elements.
    //
    // Syntax:
    //
    //      s.insert(value);
    //
    // Duplicate values are automatically ignored.
    //
    //==========================================================================

    numbers.insert(10);
    numbers.insert(20);
    numbers.insert(30);
    numbers.insert(40);
    numbers.insert(10);

    cout << "==================================================" << endl;
    cout << "1. insert()" << endl;
    cout << "==================================================" << endl;

    cout << "Size = "
         << numbers.size()
         << endl;

    cout << "Elements: ";

    for (int x : numbers)
    {
        cout << x << " ";
    }

    cout << endl;

    //==========================================================================
    // 3. DUPLICATE ELEMENTS
    //==========================================================================
    //
    // unordered_set duplicate values store nahi karta.
    //
    // Example:
    //
    //      10
    //      20
    //      10
    //      30
    //
    // Final:
    //
    //      10
    //      20
    //      30
    //
    //==========================================================================

    unordered_set<int> duplicateSet = {
        10,
        20,
        10,
        30,
        20,
        10};

    cout << "\n==================================================" << endl;
    cout << "2. Duplicate Handling" << endl;
    cout << "==================================================" << endl;

    cout << "Elements: ";

    for (int x : duplicateSet)
    {
        cout << x << " ";
    }

    cout << endl;

    cout << "Unique count = "
         << duplicateSet.size()
         << endl;

    //==========================================================================
    // 4. INITIALIZATION
    //==========================================================================
    //
    // We can initialize unordered_set directly.
    //
    //==========================================================================

    unordered_set<int> initializedSet = {
        100,
        200,
        300,
        400,
        500};

    cout << "\n==================================================" << endl;
    cout << "3. Direct Initialization" << endl;
    cout << "==================================================" << endl;

    for (int x : initializedSet)
    {
        cout << x << " ";
    }

    cout << endl;

    //==========================================================================
    // 5. unordered_set<string>
    //==========================================================================
    //
    // Strings ko bhi store kar sakte hain.
    //
    //==========================================================================

    unordered_set<string> names = {
        "Amit",
        "Rahul",
        "Riya",
        "Aman",
        "Amit"};

    cout << "\n==================================================" << endl;
    cout << "4. unordered_set<string>" << endl;
    cout << "==================================================" << endl;

    for (const string &name : names)
    {
        cout << name << endl;
    }

    //==========================================================================
    // 6. unordered_set<char>
    //==========================================================================

    unordered_set<char> characters = {
        'a',
        'b',
        'c',
        'a',
        'd'};

    cout << "\n==================================================" << endl;
    cout << "5. unordered_set<char>" << endl;
    cout << "==================================================" << endl;

    for (char ch : characters)
    {
        cout << ch << " ";
    }

    cout << endl;

    //==========================================================================
    // 7. unordered_set<double>
    //==========================================================================

    unordered_set<double> decimalValues = {
        1.5,
        2.5,
        3.5,
        1.5};

    cout << "\n==================================================" << endl;
    cout << "6. unordered_set<double>" << endl;
    cout << "==================================================" << endl;

    for (double value : decimalValues)
    {
        cout << value << " ";
    }

    cout << endl;

    //==========================================================================
    // 8. size()
    //==========================================================================
    //
    // size() number of elements return karta hai.
    //
    // Complexity:
    //
    //      O(1)
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "7. size()" << endl;
    cout << "==================================================" << endl;

    cout << "Size = "
         << initializedSet.size()
         << endl;

    //==========================================================================
    // 9. empty()
    //==========================================================================
    //
    // empty() check karta hai ki container empty hai ya nahi.
    //
    // true  -> empty
    // false -> not empty
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "8. empty()" << endl;
    cout << "==================================================" << endl;

    if (initializedSet.empty())
    {
        cout << "Set is empty." << endl;
    }
    else
    {
        cout << "Set is NOT empty." << endl;
    }

    //==========================================================================
    // 10. find()
    //==========================================================================
    //
    // find(value) value ko search karta hai.
    //
    // Return:
    //
    //      iterator
    //
    // If found:
    //
    //      iterator != end()
    //
    // If not found:
    //
    //      iterator == end()
    //
    // Average:
    //
    //      O(1)
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "9. find()" << endl;
    cout << "==================================================" << endl;

    auto foundIterator = initializedSet.find(300);

    if (foundIterator != initializedSet.end())
    {
        cout << "300 found." << endl;
        cout << "Value = "
             << *foundIterator
             << endl;
    }
    else
    {
        cout << "300 not found." << endl;
    }

    //==========================================================================
    // 11. FIND - ELEMENT NOT PRESENT
    //==========================================================================

    auto missingIterator = initializedSet.find(999);

    if (missingIterator != initializedSet.end())
    {
        cout << "999 found." << endl;
    }
    else
    {
        cout << "999 not found." << endl;
    }

    //==========================================================================
    // 12. count()
    //==========================================================================
    //
    // count(value) checks whether value exists.
    //
    // Since unordered_set stores unique values:
    //
    //      count(value)
    //
    // returns:
    //
    //      0 -> not present
    //      1 -> present
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "10. count()" << endl;
    cout << "==================================================" << endl;

    cout << "Count of 200 = "
         << initializedSet.count(200)
         << endl;

    cout << "Count of 999 = "
         << initializedSet.count(999)
         << endl;

    //==========================================================================
    // 13. ERASE BY VALUE
    //==========================================================================
    //
    // Syntax:
    //
    //      s.erase(value);
    //
    // Removes the given value.
    //
    // Return:
    //
    //      Number of elements removed.
    //
    // For unordered_set:
    //
    //      0 or 1
    //
    //==========================================================================

    unordered_set<int> eraseValueSet = {
        10,
        20,
        30,
        40,
        50};

    cout << "\n==================================================" << endl;
    cout << "11. erase(value)" << endl;
    cout << "==================================================" << endl;

    size_t removedCount = eraseValueSet.erase(30);

    cout << "Removed = "
         << removedCount
         << endl;

    cout << "Remaining elements: ";

    for (int x : eraseValueSet)
    {
        cout << x << " ";
    }

    cout << endl;

    //==========================================================================
    // 14. ERASE USING ITERATOR
    //==========================================================================
    //
    // First find the element.
    //
    // Then erase using iterator.
    //
    //==========================================================================

    unordered_set<int> eraseIteratorSet = {
        10,
        20,
        30,
        40};

    auto eraseIterator = eraseIteratorSet.find(20);

    if (eraseIterator != eraseIteratorSet.end())
    {
        eraseIteratorSet.erase(eraseIterator);
    }

    cout << "\n==================================================" << endl;
    cout << "12. erase(iterator)" << endl;
    cout << "==================================================" << endl;

    for (int x : eraseIteratorSet)
    {
        cout << x << " ";
    }

    cout << endl;

    //==========================================================================
    // 15. CLEAR()
    //==========================================================================
    //
    // clear() removes ALL elements.
    //
    // Complexity:
    //
    //      O(n)
    //
    //==========================================================================

    unordered_set<int> clearSet = {
        10,
        20,
        30,
        40};

    cout << "\n==================================================" << endl;
    cout << "13. clear()" << endl;
    cout << "==================================================" << endl;

    cout << "Before clear = "
         << clearSet.size()
         << endl;

    clearSet.clear();

    cout << "After clear = "
         << clearSet.size()
         << endl;

    //==========================================================================
    // 16. BEGIN() AND END()
    //==========================================================================
    //
    // begin() gives iterator to the beginning of traversal.
    //
    // IMPORTANT:
    //
    // In unordered_set:
    //
    //      *begin()
    //
    // does NOT mean smallest element.
    //
    // Because the container is NOT sorted.
    //
    // end() represents the position after the last traversable
    // element.
    //
    //==========================================================================

    unordered_set<int> iteratorSet = {
        50,
        10,
        40,
        20,
        30};

    cout << "\n==================================================" << endl;
    cout << "14. begin() and end()" << endl;
    cout << "==================================================" << endl;

    auto beginIterator = iteratorSet.begin();

    cout << "Element at begin = "
         << *beginIterator
         << endl;

    //==========================================================================
    // 17. ITERATOR TRAVERSAL
    //==========================================================================

    cout << "\nIterator traversal:" << endl;

    for (auto it = iteratorSet.begin();
         it != iteratorSet.end();
         ++it)
    {
        cout << *it << " ";
    }

    cout << endl;

    //==========================================================================
    // 18. RANGE BASED FOR LOOP
    //==========================================================================
    //
    // Modern and easiest way to traverse.
    //
    //==========================================================================

    cout << "\nRange based loop:" << endl;

    for (int x : iteratorSet)
    {
        cout << x << " ";
    }

    cout << endl;

    //==========================================================================
    // 19. IMPORTANT - ORDER IS NOT GUARANTEED
    //==========================================================================
    //
    // unordered_set does NOT sort elements.
    //
    // Example:
    //
    //      unordered_set<int> s = {
    //          5, 1, 4, 2, 3
    //      };
    //
    // You cannot assume output will be:
    //
    //      1 2 3 4 5
    //
    // It may appear in a different order.
    //
    //==========================================================================

    //==========================================================================
    // 20. NO INDEXING
    //==========================================================================
    //
    // This is WRONG:
    //
    //      s[0]
    //
    // unordered_set does not provide random indexing.
    //
    // You must use iterators or range-based loops.
    //
    //==========================================================================

    //==========================================================================
    // 21. INSERT RETURN VALUE
    //==========================================================================
    //
    // insert(value) generally returns:
    //
    //      pair<iterator, bool>
    //
    // second:
    //
    //      true  -> insertion happened
    //      false -> value already existed
    //
    //==========================================================================

    unordered_set<int> insertResultSet;

    auto firstInsertResult =
        insertResultSet.insert(100);

    auto secondInsertResult =
        insertResultSet.insert(100);

    cout << "\n==================================================" << endl;
    cout << "15. insert() return value" << endl;
    cout << "==================================================" << endl;

    cout << boolalpha;

    cout << "First insertion successful = "
         << firstInsertResult.second
         << endl;

    cout << "Second insertion successful = "
         << secondInsertResult.second
         << endl;

    //==========================================================================
    // 22. INSERT + DUPLICATE DETECTION
    //==========================================================================
    //
    // This is an extremely useful DSA pattern.
    //
    //      auto result = s.insert(x);
    //
    //      if (!result.second)
    //      {
    //          // duplicate
    //      }
    //
    //==========================================================================

    unordered_set<int> duplicateDetectionSet;

    vector<int> duplicateArray = {
        10,
        20,
        30,
        20,
        40};

    cout << "\n==================================================" << endl;
    cout << "16. Duplicate Detection" << endl;
    cout << "==================================================" << endl;

    for (int x : duplicateArray)
    {
        auto result =
            duplicateDetectionSet.insert(x);

        if (!result.second)
        {
            cout << "Duplicate found = "
                 << x
                 << endl;

            break;
        }
    }

    //==========================================================================
    // 23. UNIQUE ELEMENTS
    //==========================================================================
    //
    // unordered_set automatically removes duplicates logically.
    //
    //==========================================================================

    vector<int> originalArray = {
        1,
        2,
        2,
        3,
        4,
        4,
        5};

    unordered_set<int> uniqueElements(
        originalArray.begin(),
        originalArray.end());

    cout << "\n==================================================" << endl;
    cout << "17. Unique Elements" << endl;
    cout << "==================================================" << endl;

    for (int x : uniqueElements)
    {
        cout << x << " ";
    }

    cout << endl;

    //==========================================================================
    // 24. NUMBER OF UNIQUE ELEMENTS
    //==========================================================================

    cout << "Number of unique elements = "
         << uniqueElements.size()
         << endl;

    //==========================================================================
    // 25. BUCKET CONCEPT
    //==========================================================================
    //
    // unordered_set internally uses HASHING.
    //
    // Basic mental model:
    //
    //
    //          value
    //             |
    //             v
    //       hash function
    //             |
    //             v
    //          bucket
    //
    //
    // Multiple values can sometimes map to the same bucket.
    //
    // This is called a COLLISION.
    //
    //==========================================================================

    //==========================================================================
    // 26. bucket_count()
    //==========================================================================
    //
    // Returns the number of buckets currently used by the
    // unordered_set.
    //
    //==========================================================================

    unordered_set<int> bucketSet = {
        10,
        20,
        30,
        40,
        50};

    cout << "\n==================================================" << endl;
    cout << "18. bucket_count()" << endl;
    cout << "==================================================" << endl;

    cout << "Number of buckets = "
         << bucketSet.bucket_count()
         << endl;

    //==========================================================================
    // 27. bucket(value)
    //==========================================================================
    //
    // Returns the bucket index associated with the value.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "19. bucket()" << endl;
    cout << "==================================================" << endl;

    cout << "Bucket of 30 = "
         << bucketSet.bucket(30)
         << endl;

    //==========================================================================
    // 28. bucket_size()
    //==========================================================================
    //
    // Returns the number of elements in a particular bucket.
    //
    //==========================================================================

    size_t selectedBucket =
        bucketSet.bucket(30);

    cout << "\n==================================================" << endl;
    cout << "20. bucket_size()" << endl;
    cout << "==================================================" << endl;

    cout << "Elements in bucket "
         << selectedBucket
         << " = "
         << bucketSet.bucket_size(selectedBucket)
         << endl;

    //==========================================================================
    // 29. DISPLAY ALL BUCKETS
    //==========================================================================

    cout << "\nAll buckets:" << endl;

    for (size_t i = 0;
         i < bucketSet.bucket_count();
         ++i)
    {
        cout << "Bucket "
             << i
             << " -> "
             << bucketSet.bucket_size(i)
             << " element(s)"
             << endl;
    }

    //==========================================================================
    // 30. load_factor()
    //==========================================================================
    //
    // Conceptually:
    //
    //      load_factor =
    //
    //      number of elements / number of buckets
    //
    // A high load factor can mean more collisions.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "21. load_factor()" << endl;
    cout << "==================================================" << endl;

    cout << "Load factor = "
         << bucketSet.load_factor()
         << endl;

    //==========================================================================
    // 31. max_load_factor()
    //==========================================================================
    //
    // Returns the maximum load factor threshold.
    //
    // It can also be changed.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "22. max_load_factor()" << endl;
    cout << "==================================================" << endl;

    cout << "Maximum load factor = "
         << bucketSet.max_load_factor()
         << endl;

    //==========================================================================
    // 32. CHANGE max_load_factor()
    //==========================================================================

    unordered_set<int> loadFactorSet;

    loadFactorSet.max_load_factor(0.5f);

    cout << "New maximum load factor = "
         << loadFactorSet.max_load_factor()
         << endl;

    //==========================================================================
    // 33. reserve()
    //==========================================================================
    //
    // reserve(n) prepares the unordered_set for approximately
    // n elements.
    //
    // It can help reduce unnecessary rehashing when we already
    // know the approximate number of elements.
    //
    //==========================================================================

    unordered_set<int> reserveSet;

    reserveSet.reserve(1000);

    cout << "\n==================================================" << endl;
    cout << "23. reserve()" << endl;
    cout << "==================================================" << endl;

    cout << "Bucket count after reserve = "
         << reserveSet.bucket_count()
         << endl;

    //==========================================================================
    // 34. rehash()
    //==========================================================================
    //
    // rehash(n) requests at least n buckets.
    //
    // The implementation may choose an appropriate bucket count.
    //
    //==========================================================================

    unordered_set<int> rehashSet = {
        10,
        20,
        30};

    cout << "\n==================================================" << endl;
    cout << "24. rehash()" << endl;
    cout << "==================================================" << endl;

    cout << "Before rehash = "
         << rehashSet.bucket_count()
         << endl;

    rehashSet.rehash(100);

    cout << "After rehash = "
         << rehashSet.bucket_count()
         << endl;

    //==========================================================================
    // 35. HASH FUNCTION
    //==========================================================================
    //
    // std::hash<T> is used to create a hash value.
    //
    // For int:
    //
    //      hash<int>
    //
    //==========================================================================

    hash<int> integerHash;

    cout << "\n==================================================" << endl;
    cout << "25. std::hash<int>" << endl;
    cout << "==================================================" << endl;

    cout << "Hash of 10 = "
         << integerHash(10)
         << endl;

    cout << "Hash of 20 = "
         << integerHash(20)
         << endl;

    //==========================================================================
    // 36. COLLISION
    //==========================================================================
    //
    // Collision occurs when different values are mapped to the
    // same bucket.
    //
    //
    // Example concept:
    //
    //      value A ---> bucket 5
    //
    //      value B ---> bucket 5
    //
    //
    // Both values are now in the same bucket.
    //
    // Too many collisions can hurt performance.
    //
    // Therefore:
    //
    //      Average -> O(1)
    //      Worst   -> O(n)
    //
    //==========================================================================

    //==========================================================================
    // 37. erase() + find()
    //==========================================================================
    //
    // Common pattern:
    //
    //      auto it = s.find(x);
    //
    //      if (it != s.end())
    //      {
    //          s.erase(it);
    //      }
    //
    //==========================================================================

    unordered_set<int> erasePatternSet = {
        10,
        20,
        30,
        40};

    auto erasePatternIterator =
        erasePatternSet.find(30);

    if (erasePatternIterator != erasePatternSet.end())
    {
        erasePatternSet.erase(erasePatternIterator);
    }

    cout << "\n==================================================" << endl;
    cout << "26. find() + erase()" << endl;
    cout << "==================================================" << endl;

    for (int x : erasePatternSet)
    {
        cout << x << " ";
    }

    cout << endl;

    //==========================================================================
    // 38. CLEAR + EMPTY
    //==========================================================================

    unordered_set<int> clearExample = {
        1,
        2,
        3,
        4};

    clearExample.clear();

    cout << "\n==================================================" << endl;
    cout << "27. clear() + empty()" << endl;
    cout << "==================================================" << endl;

    if (clearExample.empty())
    {
        cout << "Container is empty after clear()." << endl;
    }

    //==========================================================================
    // 39. COPY CONSTRUCTOR
    //==========================================================================
    //
    // One unordered_set can be copied into another.
    //
    //==========================================================================

    unordered_set<int> originalSet = {
        10,
        20,
        30};

    unordered_set<int> copiedSet =
        originalSet;

    cout << "\n==================================================" << endl;
    cout << "28. Copy Constructor" << endl;
    cout << "==================================================" << endl;

    for (int x : copiedSet)
    {
        cout << x << " ";
    }

    cout << endl;

    //==========================================================================
    // 40. ASSIGNMENT OPERATOR
    //==========================================================================
    //
    // One unordered_set can be assigned to another.
    //
    // IMPORTANT:
    //
    // We intentionally use DIFFERENT variable names here.
    //
    // This avoids redeclaration errors.
    //
    //==========================================================================

    unordered_set<int> assignmentSourceSet = {
        1,
        2,
        3};

    unordered_set<int> assignmentTargetSet = {
        100,
        200};

    assignmentTargetSet =
        assignmentSourceSet;

    cout << "\n==================================================" << endl;
    cout << "29. Assignment Operator" << endl;
    cout << "==================================================" << endl;

    cout << "Target after assignment: ";

    for (int x : assignmentTargetSet)
    {
        cout << x << " ";
    }

    cout << endl;

    //==========================================================================
    // 41. swap()
    //==========================================================================
    //
    // Exchanges the contents of two unordered_sets.
    //
    //==========================================================================

    unordered_set<int> swapSetA = {
        10,
        20,
        30};

    unordered_set<int> swapSetB = {
        100,
        200,
        300};

    swapSetA.swap(swapSetB);

    cout << "\n==================================================" << endl;
    cout << "30. swap()" << endl;
    cout << "==================================================" << endl;

    cout << "swapSetA: ";

    for (int x : swapSetA)
    {
        cout << x << " ";
    }

    cout << endl;

    cout << "swapSetB: ";

    for (int x : swapSetB)
    {
        cout << x << " ";
    }

    cout << endl;

    //==========================================================================
    // 42. unordered_set VS set
    //==========================================================================
    //
    // std::set:
    //
    //      UNIQUE
    //      SORTED
    //      TREE BASED
    //      O(log n)
    //
    //
    // unordered_set:
    //
    //      UNIQUE
    //      NOT SORTED
    //      HASH BASED
    //      AVERAGE O(1)
    //
    //==========================================================================

    /*

        FEATURE              set              unordered_set
        ---------------------------------------------------------
        Unique               YES              YES
        Duplicate            NO               NO
        Sorted                YES              NO
        Hashing               NO               YES
        Random indexing       NO               NO
        Average find          O(log n)         O(1)
        Average insert        O(log n)         O(1)
        Average erase         O(log n)         O(1)
        Worst lookup          O(log n)         O(n)
        lower_bound           YES              NO
        upper_bound           YES              NO
        Order guaranteed      YES              NO

    */

    //==========================================================================
    // 43. unordered_set VS vector
    //==========================================================================
    //
    // vector:
    //
    //      duplicates allowed
    //      insertion order preserved
    //      indexing available
    //      v[0]
    //      random access
    //
    //
    // unordered_set:
    //
    //      duplicates not allowed
    //      order not guaranteed
    //      indexing not available
    //      fast average lookup
    //
    //==========================================================================

    //==========================================================================
    // 44. unordered_set VS unordered_multiset
    //==========================================================================
    //
    // unordered_set:
    //
    //      UNIQUE
    //
    //
    // unordered_multiset:
    //
    //      DUPLICATES ALLOWED
    //
    // Example:
    //
    //      unordered_set:
    //
    //          10 20 30
    //
    //
    //      unordered_multiset:
    //
    //          10 10 20 20 30
    //
    //==========================================================================

    //==========================================================================
    // 45. DSA USE CASE - MEMBERSHIP CHECK
    //==========================================================================
    //
    // One of the most important applications.
    //
    // Question:
    //
    //      "Does x exist?"
    //
    // Use:
    //
    //      s.count(x)
    //
    // or:
    //
    //      s.find(x)
    //
    //==========================================================================

    unordered_set<int> membershipSet = {
        10,
        20,
        30,
        40,
        50};

    int searchValue = 30;

    cout << "\n==================================================" << endl;
    cout << "31. DSA - Membership Check" << endl;
    cout << "==================================================" << endl;

    if (membershipSet.count(searchValue))
    {
        cout << searchValue
             << " exists."
             << endl;
    }
    else
    {
        cout << searchValue
             << " does not exist."
             << endl;
    }

    //==========================================================================
    // 46. DSA USE CASE - DUPLICATE DETECTION
    //==========================================================================
    //
    // Algorithm:
    //
    //      1. Create empty unordered_set.
    //      2. Traverse array.
    //      3. If x already exists -> duplicate.
    //      4. Otherwise insert x.
    //
    // Average complexity:
    //
    //      O(n)
    //
    //==========================================================================

    vector<int> duplicateCheckArray = {
        5,
        10,
        20,
        30,
        20};

    unordered_set<int> seenValues;

    bool duplicateFound = false;

    for (int x : duplicateCheckArray)
    {
        if (seenValues.count(x))
        {
            duplicateFound = true;

            cout << "\nDuplicate = "
                 << x
                 << endl;

            break;
        }

        seenValues.insert(x);
    }

    if (!duplicateFound)
    {
        cout << "\nNo duplicate found." << endl;
    }

    //==========================================================================
    // 47. DSA USE CASE - UNIQUE CHARACTERS
    //==========================================================================

    string text = "programming";

    unordered_set<char> uniqueCharacters;

    for (char ch : text)
    {
        uniqueCharacters.insert(ch);
    }

    cout << "\n==================================================" << endl;
    cout << "32. DSA - Unique Characters" << endl;
    cout << "==================================================" << endl;

    cout << "Number of unique characters = "
         << uniqueCharacters.size()
         << endl;

    //==========================================================================
    // 48. DSA - CHECK ALL CHARACTERS UNIQUE
    //==========================================================================

    string uniqueText = "abcde";

    unordered_set<char> uniqueCharacterCheck(
        uniqueText.begin(),
        uniqueText.end());

    cout << "\n==================================================" << endl;
    cout << "33. DSA - All Characters Unique?" << endl;
    cout << "==================================================" << endl;

    if (uniqueCharacterCheck.size() ==
        uniqueText.size())
    {
        cout << "All characters are unique." << endl;
    }
    else
    {
        cout << "Duplicate character exists." << endl;
    }

    //==========================================================================
    // 49. DSA - UNIQUE WORDS
    //==========================================================================

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

    cout << "\n==================================================" << endl;
    cout << "34. DSA - Unique Words" << endl;
    cout << "==================================================" << endl;

    for (const string &word : uniqueWords)
    {
        cout << word << endl;
    }

    //==========================================================================
    // 50. DSA - COMMON ELEMENT
    //==========================================================================
    //
    // Store first array in unordered_set.
    //
    // Then traverse second array and search each value.
    //
    // Average:
    //
    //      O(n + m)
    //
    //==========================================================================

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

    unordered_set<int> firstArrayLookup(
        firstArray.begin(),
        firstArray.end());

    bool commonFound = false;

    cout << "\n==================================================" << endl;
    cout << "35. DSA - Common Element" << endl;
    cout << "==================================================" << endl;

    for (int x : secondArray)
    {
        if (firstArrayLookup.count(x))
        {
            cout << "Common element = "
                 << x
                 << endl;

            commonFound = true;
            break;
        }
    }

    if (!commonFound)
    {
        cout << "No common element." << endl;
    }

    //==========================================================================
    // 51. DSA - INTERSECTION
    //==========================================================================

    vector<int> arrayA = {
        1,
        2,
        3,
        4,
        5};

    vector<int> arrayB = {
        3,
        4,
        5,
        6,
        7};

    unordered_set<int> intersectionLookup(
        arrayA.begin(),
        arrayA.end());

    unordered_set<int> intersectionResult;

    for (int x : arrayB)
    {
        if (intersectionLookup.count(x))
        {
            intersectionResult.insert(x);
        }
    }

    cout << "\n==================================================" << endl;
    cout << "36. DSA - Intersection" << endl;
    cout << "==================================================" << endl;

    for (int x : intersectionResult)
    {
        cout << x << " ";
    }

    cout << endl;

    //==========================================================================
    // 52. DSA - VISITED SET
    //==========================================================================
    //
    // Graph/BFS/DFS/state problems mein visited nodes ko store
    // karne ke liye unordered_set useful ho sakta hai.
    //
    //==========================================================================

    unordered_set<int> visited;

    visited.insert(1);
    visited.insert(2);
    visited.insert(3);

    int node = 2;

    cout << "\n==================================================" << endl;
    cout << "37. DSA - Visited Set" << endl;
    cout << "==================================================" << endl;

    if (visited.count(node))
    {
        cout << "Node "
             << node
             << " is already visited."
             << endl;
    }
    else
    {
        cout << "Node "
             << node
             << " is not visited."
             << endl;
    }

    //==========================================================================
    // 53. DSA - TWO SUM STYLE LOOKUP
    //==========================================================================
    //
    // For every x:
    //
    //      required = target - x
    //
    // Check whether required already exists.
    //
    // Average complexity:
    //
    //      O(n)
    //
    //==========================================================================

    vector<int> twoSumArray = {
        2,
        7,
        11,
        15};

    int target = 9;

    unordered_set<int> twoSumSeen;

    cout << "\n==================================================" << endl;
    cout << "38. DSA - Two Sum Style" << endl;
    cout << "==================================================" << endl;

    for (int x : twoSumArray)
    {
        int required = target - x;

        if (twoSumSeen.count(required))
        {
            cout << "Pair found: "
                 << required
                 << " + "
                 << x
                 << " = "
                 << target
                 << endl;

            break;
        }

        twoSumSeen.insert(x);
    }

    //==========================================================================
    // 54. DSA - LONGEST CONSECUTIVE SEQUENCE
    //==========================================================================
    //
    // Example:
    //
    //      100, 4, 200, 1, 3, 2
    //
    // Longest consecutive sequence:
    //
    //      1, 2, 3, 4
    //
    // Answer:
    //
    //      4
    //
    // unordered_set provides fast membership checking.
    //
    //==========================================================================

    vector<int> sequenceArray = {
        100,
        4,
        200,
        1,
        3,
        2};

    unordered_set<int> sequenceSet(
        sequenceArray.begin(),
        sequenceArray.end());

    int longestLength = 0;

    for (int x : sequenceSet)
    {
        // x is a starting point if x - 1 does not exist.

        if (!sequenceSet.count(x - 1))
        {
            int current = x;
            int length = 1;

            while (sequenceSet.count(current + 1))
            {
                current++;
                length++;
            }

            longestLength =
                max(longestLength, length);
        }
    }

    cout << "\n==================================================" << endl;
    cout << "39. DSA - Longest Consecutive Sequence" << endl;
    cout << "==================================================" << endl;

    cout << "Longest length = "
         << longestLength
         << endl;

    //==========================================================================
    // 55. DSA - FIRST REPEATING ELEMENT
    //==========================================================================

    vector<int> repeatingArray = {
        5,
        3,
        1,
        4,
        3,
        5};

    unordered_set<int> repeatingSeen;

    cout << "\n==================================================" << endl;
    cout << "40. DSA - First Repeating Element" << endl;
    cout << "==================================================" << endl;

    for (int x : repeatingArray)
    {
        if (repeatingSeen.count(x))
        {
            cout << "First repeating element = "
                 << x
                 << endl;

            break;
        }

        repeatingSeen.insert(x);
    }

    //==========================================================================
    // 56. DSA - REMOVE DUPLICATES
    //==========================================================================
    //
    // unordered_set can be used to get unique values from a vector.
    //
    // IMPORTANT:
    //
    // Original order is NOT preserved.
    //
    //==========================================================================

    vector<int> duplicateVector = {
        5,
        1,
        2,
        5,
        3,
        2,
        1};

    unordered_set<int> duplicateRemoved(
        duplicateVector.begin(),
        duplicateVector.end());

    cout << "\n==================================================" << endl;
    cout << "41. DSA - Remove Duplicates" << endl;
    cout << "==================================================" << endl;

    for (int x : duplicateRemoved)
    {
        cout << x << " ";
    }

    cout << endl;

    //==========================================================================
    // 57. DSA - UNIQUE COUNT
    //==========================================================================

    vector<int> countArray = {
        1,
        2,
        2,
        3,
        3,
        3,
        4};

    unordered_set<int> countUnique(
        countArray.begin(),
        countArray.end());

    cout << "\n==================================================" << endl;
    cout << "42. DSA - Count Unique Values" << endl;
    cout << "==================================================" << endl;

    cout << "Unique count = "
         << countUnique.size()
         << endl;

    //==========================================================================
    // 58. DSA - LARGE VALUES
    //==========================================================================

    unordered_set<long long> largeNumbers = {
        10000000000LL,
        20000000000LL,
        30000000000LL};

    long long largeSearchValue =
        20000000000LL;

    cout << "\n==================================================" << endl;
    cout << "43. DSA - Large Values" << endl;
    cout << "==================================================" << endl;

    if (largeNumbers.count(largeSearchValue))
    {
        cout << "Large value found." << endl;
    }
    else
    {
        cout << "Large value not found." << endl;
    }

    //==========================================================================
    // 59. CONVERT unordered_set TO vector
    //==========================================================================
    //
    // unordered_set sorted nahi hai.
    //
    // Agar sorted output chahiye:
    //
    //      unordered_set
    //              |
    //              v
    //           vector
    //              |
    //              v
    //            sort()
    //
    //==========================================================================

    unordered_set<int> unorderedData = {
        50,
        10,
        40,
        20,
        30};

    vector<int> sortedData(
        unorderedData.begin(),
        unorderedData.end());

    sort(
        sortedData.begin(),
        sortedData.end());

    cout << "\n==================================================" << endl;
    cout << "44. unordered_set -> vector -> sort" << endl;
    cout << "==================================================" << endl;

    for (int x : sortedData)
    {
        cout << x << " ";
    }

    cout << endl;

    //==========================================================================
    // 60. MINIMUM AND MAXIMUM
    //==========================================================================
    //
    // IMPORTANT:
    //
    // In unordered_set:
    //
    //      *begin()
    //
    // is NOT guaranteed to be minimum.
    //
    // We must manually traverse to find min/max.
    //
    //==========================================================================

    unordered_set<int> minMaxSet = {
        50,
        10,
        40,
        20,
        30};

    int minimumValue =
        *minMaxSet.begin();

    int maximumValue =
        *minMaxSet.begin();

    for (int x : minMaxSet)
    {
        if (x < minimumValue)
        {
            minimumValue = x;
        }

        if (x > maximumValue)
        {
            maximumValue = x;
        }
    }

    cout << "\n==================================================" << endl;
    cout << "45. Minimum and Maximum" << endl;
    cout << "==================================================" << endl;

    cout << "Minimum = "
         << minimumValue
         << endl;

    cout << "Maximum = "
         << maximumValue
         << endl;

    //==========================================================================
    // 61. CASE SENSITIVITY
    //==========================================================================
    //
    // Strings are case-sensitive.
    //
    // "Apple" and "apple" are different values.
    //
    //==========================================================================

    unordered_set<string> caseSensitiveSet = {
        "Apple",
        "apple",
        "BANANA",
        "banana"};

    cout << "\n==================================================" << endl;
    cout << "46. Case Sensitivity" << endl;
    cout << "==================================================" << endl;

    for (const string &word : caseSensitiveSet)
    {
        cout << word << endl;
    }

    //==========================================================================
    // 62. IMPORTANT: lower_bound() DOES NOT EXIST
    //==========================================================================
    //
    // std::set has:
    //
    //      lower_bound()
    //      upper_bound()
    //
    // unordered_set does NOT have these operations.
    //
    // Reason:
    //
    // unordered_set is not ordered.
    //
    // lower_bound/upper_bound need ordered data.
    //
    //==========================================================================

    //==========================================================================
    // 63. IMPORTANT: NO rbegin()/rend() LIKE ordered set
    //==========================================================================
    //
    // Do not treat unordered_set like a sorted set.
    //
    // There is no meaningful "reverse sorted order" because
    // there is no sorted order in the first place.
    //
    //==========================================================================

    //==========================================================================
    // 64. REHASHING
    //==========================================================================
    //
    // When the hash table grows, it may need more buckets.
    //
    // This process is called REHASHING.
    //
    // Rehashing changes the internal bucket arrangement.
    //
    // Therefore iterator validity must be considered when the
    // container is modified.
    //
    //==========================================================================

    //==========================================================================
    // 65. ITERATOR INVALIDATION - BASIC NOTE
    //==========================================================================
    //
    // Insertion can cause rehashing.
    //
    // If rehashing happens, existing iterators can be invalidated.
    //
    // Erasing an element invalidates the iterator referring to
    // that erased element.
    //
    // Always be careful when keeping iterators while modifying
    // an unordered_set.
    //
    //==========================================================================

    //==========================================================================
    // 66. CUSTOM DATA TYPES
    //==========================================================================
    //
    // unordered_set can store custom classes/structs too.
    //
    // But for custom types, hashing and equality comparison need
    // to be supported.
    //
    // Built-in types like int/string already have standard hashing
    // support.
    //
    //==========================================================================

    //==========================================================================
    // 67. CUSTOM HASH - EXAMPLE
    //==========================================================================
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
    //      unordered_set<MyType, MyHash> s;
    //
    //
    // For beginner DSA, first master unordered_set<int> and
    // unordered_set<string>.
    //
    //==========================================================================

    //==========================================================================
    // 68. TIME COMPLEXITY
    //==========================================================================
    //
    /*

        OPERATION                  AVERAGE          WORST
        -------------------------------------------------------
        insert()                    O(1)             O(n)
        find()                      O(1)             O(n)
        count()                     O(1)             O(n)
        erase(value)                O(1)             O(n)
        erase(iterator)             O(1)             O(n)
        size()                      O(1)             O(1)
        empty()                     O(1)             O(1)
        clear()                     O(n)             O(n)


        IMPORTANT:

        O(1) means AVERAGE/AMORTIZED hashing performance,
        NOT an absolute guarantee for every possible input.

    */

    //==========================================================================
    // 69. WHEN TO USE unordered_set
    //==========================================================================
    //
    // Use unordered_set when:
    //
    //      1. You need UNIQUE values.
    //
    //      2. Sorting is NOT required.
    //
    //      3. You need fast average lookup.
    //
    //      4. You need duplicate detection.
    //
    //      5. You need membership checking.
    //
    //      6. You need visited states/nodes.
    //
    //      7. You need unique characters/words.
    //
    //      8. You need hash-based DSA solutions.
    //
    //==========================================================================

    //==========================================================================
    // 70. WHEN NOT TO USE unordered_set
    //==========================================================================
    //
    // Avoid unordered_set when:
    //
    //      1. Sorted order is required.
    //
    //      2. lower_bound() is required.
    //
    //      3. upper_bound() is required.
    //
    //      4. Ordered predecessor/successor is required.
    //
    //      5. Range queries depend on sorted values.
    //
    //      6. Stable/insertion order is required.
    //
    // In such cases, another container may be more suitable.
    //
    //==========================================================================

    //==========================================================================
    // 71. INTERVIEW QUESTIONS
    //==========================================================================
    //
    /*

        Q1. Does unordered_set allow duplicates?

            NO.


        Q2. Is unordered_set sorted?

            NO.


        Q3. What does unordered_set use internally?

            HASHING / HASH TABLE.


        Q4. Average lookup complexity?

            O(1).


        Q5. Worst-case lookup complexity?

            O(n).


        Q6. Does unordered_set support indexing?

            NO.


        Q7. Does unordered_set support lower_bound()?

            NO.


        Q8. Does unordered_set support upper_bound()?

            NO.


        Q9. Why is unordered_set generally faster than set
            for membership checking?

            Because average hash lookup is O(1), while set lookup
            is generally O(log n).


        Q10. What is a collision?

            When different values map to the same hash bucket.


        Q11. What is rehashing?

            Reorganizing the hash table into a new bucket arrangement.


        Q12. What is load factor?

            Roughly the ratio of elements to buckets.

    */

    //==========================================================================
    // 72. FINAL CHEAT SHEET
    //==========================================================================
    //
    /*

        HEADER:

            #include <unordered_set>


        DECLARATION:

            unordered_set<int> s;


        INITIALIZATION:

            unordered_set<int> s = {
                10, 20, 30
            };


        INSERT:

            s.insert(40);


        SEARCH:

            s.find(40);


        EXISTENCE CHECK:

            if (s.count(40))


        ERASE BY VALUE:

            s.erase(40);


        ERASE BY ITERATOR:

            auto it = s.find(40);

            if (it != s.end())
                s.erase(it);


        SIZE:

            s.size();


        EMPTY:

            s.empty();


        CLEAR:

            s.clear();


        ITERATION:

            for (int x : s)
            {
                cout << x;
            }


        BUCKET COUNT:

            s.bucket_count();


        BUCKET:

            s.bucket(x);


        BUCKET SIZE:

            s.bucket_size(i);


        LOAD FACTOR:

            s.load_factor();


        MAX LOAD FACTOR:

            s.max_load_factor();


        RESERVE:

            s.reserve(n);


        REHASH:

            s.rehash(n);


        SWAP:

            s1.swap(s2);


        IMPORTANT:

            s[0]                  // WRONG
            s.lower_bound(x)      // WRONG
            s.upper_bound(x)      // WRONG


        COMPLEXITY:

            Average lookup        -> O(1)
            Average insertion     -> O(1)
            Average deletion      -> O(1)
            Worst case            -> O(n)

    */

    //==========================================================================
    // 73. MOST IMPORTANT DSA PATTERN
    //==========================================================================
    //
    // Duplicate detection:
    //
    //      unordered_set<int> seen;
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
    // This pattern is extremely common in DSA.
    //
    //==========================================================================

    //==========================================================================
    // 74. FAST MEMBERSHIP PATTERN
    //==========================================================================
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
    //==========================================================================

    //==========================================================================
    // 75. FINAL MEMORY TRICK
    //==========================================================================
    //
    /*

        set
            =
        UNIQUE + SORTED
        O(log n)


        unordered_set
            =
        UNIQUE + UNORDERED + HASHING
        Average O(1)
        Worst O(n)


        multiset
            =
        DUPLICATES + SORTED


        unordered_multiset
            =
        DUPLICATES + UNORDERED + HASHING


    */

    //==========================================================================
    // 76. FINAL SUMMARY
    //==========================================================================
    //
    /*

        unordered_set is best remembered as:

            "UNIQUE VALUES + FAST AVERAGE LOOKUP"


        Main operations:

            insert()
            find()
            count()
            erase()
            size()
            empty()
            clear()


        Hash-related operations:

            bucket_count()
            bucket()
            bucket_size()
            load_factor()
            max_load_factor()
            reserve()
            rehash()


        DSA applications:

            Duplicate detection
            Unique elements
            Membership checking
            Visited nodes
            Unique characters
            Unique words
            Intersection
            Two Sum style lookup
            Longest consecutive sequence


        Biggest difference from set:

            set
                -> sorted

            unordered_set
                -> NOT sorted


        Biggest performance advantage:

            Average O(1) lookup.

    */

    cout << "\n==================================================" << endl;
    cout << "       UNORDERED_SET COMPLETE NOTES DONE" << endl;
    cout << "==================================================" << endl;

    return 0;
}