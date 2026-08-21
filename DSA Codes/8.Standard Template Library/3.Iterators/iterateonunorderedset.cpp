/*
===============================================================================
                    C++ STL - ITERATOR ON UNORDERED_SET
                  COMPLETE DETAILED NOTES + THEORY + CODE
===============================================================================

TOPIC:
    Iterators on std::unordered_set

HEADER:
    #include <unordered_set>

MAIN CONCEPT:
    unordered_set is an associative container that stores UNIQUE elements
    without maintaining any sorted order.

-------------------------------------------------------------------------------
IMPORTANT DIFFERENCE:

    set:
        Ordered
        Sorted
        Tree based

    unordered_set:
        Unordered
        Hash based
        Average O(1) search

-------------------------------------------------------------------------------
IMPORTANT ITERATOR DIFFERENCE:

    set:
        Supports bidirectional traversal.

        ++it
        --it

        rbegin()
        rend()

        lower_bound()
        upper_bound()

    unordered_set:
        Iterator is only forward.

        ++it       -> YES
        --it       -> NO

        rbegin()   -> NO
        rend()     -> NO

        lower_bound() -> NO
        upper_bound() -> NO

-------------------------------------------------------------------------------
VERY IMPORTANT:

    unordered_set does NOT guarantee sorted order.

    Example:

        We insert:

            10
            20
            30
            40
            50

        Iteration might produce:

            50
            10
            40
            20
            30

        OR some other order.

    NEVER depend on the iteration order of unordered_set.

-------------------------------------------------------------------------------
SET ITERATOR:

        *it

    gives the current element.

-------------------------------------------------------------------------------
UNORDERED_SET ITERATOR:

        *it

    also gives the current element.

-------------------------------------------------------------------------------
IMPORTANT:

    unordered_set does NOT have:

        it->first
        it->second

    because there is no key-value pair.

    Each element itself acts as the key.

===============================================================================
*/

#include <iostream>
#include <unordered_set>
#include <string>
#include <iterator>

using namespace std;

int main()
{

    //==========================================================================
    // 1. CREATE AN unordered_set
    //==========================================================================
    //
    // Syntax:
    //
    //      unordered_set<DataType> variableName;
    //
    // Example:
    //
    //      unordered_set<int> us;
    //
    // This creates an unordered_set that stores integer values.
    //
    //==========================================================================

    unordered_set<int> us;

    //==========================================================================
    // 2. INSERT ELEMENTS
    //==========================================================================
    //
    // insert() adds elements to unordered_set.
    //
    // unordered_set stores only UNIQUE elements.
    //
    //==========================================================================

    us.insert(10);
    us.insert(20);
    us.insert(30);
    us.insert(40);
    us.insert(50);

    /*
    IMPORTANT:

        Unlike set, unordered_set does NOT sort elements.

        Therefore:

            DO NOT expect:

                10
                20
                30
                40
                50

        during iteration.

        The actual iteration order depends on the hash table
        and its buckets.

        Therefore output order is NOT guaranteed.
    */

    //==========================================================================
    // 3. BASIC ITERATOR DECLARATION
    //==========================================================================
    //
    // Iterator type:
    //
    //      unordered_set<int>::iterator
    //
    // Syntax:
    //
    //      unordered_set<int>::iterator it;
    //
    //==========================================================================

    unordered_set<int>::iterator it;

    //==========================================================================
    // 4. begin()
    //==========================================================================
    //
    // begin() returns an iterator pointing to the first element
    // in the unordered_set's iteration sequence.
    //
    // IMPORTANT:
    //
    // "first" here DOES NOT mean smallest element.
    //
    // It simply means the first element encountered by the iterator.
    //
    //==========================================================================

    it = us.begin();

    cout << "==================================================" << endl;
    cout << "1. begin()" << endl;
    cout << "==================================================" << endl;

    if (it != us.end())
    {
        cout << "Element pointed by begin() = "
             << *it
             << endl;
    }

    /*
    IMPORTANT:

        For set:

            begin()
                generally points to smallest element.

        For unordered_set:

            begin()
                points to an element in the hash table's
                iteration order.

        It is NOT necessarily the smallest element.
    */

    //==========================================================================
    // 5. DEREFERENCE OPERATOR *
    //==========================================================================
    //
    // Iterator current element ko point karta hai.
    //
    // Current element ki value obtain karne ke liye:
    //
    //      *it
    //
    // use karte hain.
    //
    // Example:
    //
    //      it -> 30
    //
    //      *it
    //
    // gives:
    //
    //      30
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "2. DEREFERENCE OPERATOR *" << endl;
    cout << "==================================================" << endl;

    if (it != us.end())
    {
        cout << "Current element = "
             << *it
             << endl;
    }

    //==========================================================================
    // 6. COMPLETE ITERATION USING ITERATOR
    //==========================================================================
    //
    // Standard iterator loop:
    //
    //      for
    //      (
    //          iterator = begin();
    //          iterator != end();
    //          ++iterator
    //      )
    //
    //
    // Breakdown:
    //
    //      begin()
    //          -> first iteration position
    //
    //      != end()
    //          -> continue until end
    //
    //      ++iterator
    //          -> move to next element
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "3. COMPLETE ITERATION USING ITERATOR" << endl;
    cout << "==================================================" << endl;

    for (unordered_set<int>::iterator iter = us.begin();
         iter != us.end();
         ++iter)
    {
        // *iter gives the current element.

        cout << *iter
             << endl;
    }

    //==========================================================================
    // 7. end()
    //==========================================================================
    //
    // end() represents a position AFTER the last valid element
    // in the iterator sequence.
    //
    //
    // IMPORTANT:
    //
    //      end() is NOT an actual element.
    //
    // Therefore:
    //
    //      *us.end()
    //
    // is WRONG.
    //
    //
    // Correct use:
    //
    //      iter != us.end()
    //
    //==========================================================================

    //==========================================================================
    // 8. ITERATOR COMPARISON
    //==========================================================================
    //
    // We commonly use:
    //
    //      iter != us.end()
    //
    // to check whether iterator is still pointing to a valid element.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "4. ITERATOR COMPARISON" << endl;
    cout << "==================================================" << endl;

    it = us.begin();

    if (it != us.end())
    {
        cout << "Iterator is pointing to a valid element."
             << endl;

        cout << "Element = "
             << *it
             << endl;
    }

    //==========================================================================
    // 9. ++it
    //==========================================================================
    //
    // unordered_set iterator is a FORWARD iterator.
    //
    // Therefore:
    //
    //      ++it
    //
    // is supported.
    //
    // It moves iterator to the next element in the unordered iteration order.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "5. ++it" << endl;
    cout << "==================================================" << endl;

    it = us.begin();

    if (it != us.end())
    {
        cout << "Before ++it = "
             << *it
             << endl;

        ++it;

        if (it != us.end())
        {
            cout << "After ++it = "
                 << *it
                 << endl;
        }
    }

    //==========================================================================
    // 10. IMPORTANT: --it IS NOT SUPPORTED
    //==========================================================================
    //
    // unordered_set iterator is NOT bidirectional.
    //
    // Therefore:
    //
    //      --it
    //
    // is NOT supported.
    //
    //
    // This is a major difference between:
    //
    //      set
    //
    // and:
    //
    //      unordered_set
    //
    //
    // set:
    //
    //      ++it  -> YES
    //      --it  -> YES
    //
    //
    // unordered_set:
    //
    //      ++it  -> YES
    //      --it  -> NO
    //
    //==========================================================================

    //==========================================================================
    // 11. RANGE-BASED FOR LOOP
    //==========================================================================
    //
    // C++11 range-based for loop can also be used.
    //
    // Syntax:
    //
    //      for (const auto &x : us)
    //
    // x represents the current element.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "6. RANGE-BASED FOR LOOP" << endl;
    cout << "==================================================" << endl;

    for (const auto &x : us)
    {
        cout << x
             << endl;
    }

    //==========================================================================
    // 12. RANGE-BASED LOOP WITH auto
    //==========================================================================
    //
    // auto compiler ko type automatically determine karne deta hai.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "7. RANGE-BASED LOOP WITH auto" << endl;
    cout << "==================================================" << endl;

    for (auto x : us)
    {
        cout << x
             << endl;
    }

    //==========================================================================
    // 13. const_iterator
    //==========================================================================
    //
    // Agar humein sirf values read karni hain,
    // to const_iterator use kar sakte hain.
    //
    // Syntax:
    //
    //      unordered_set<int>::const_iterator
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "8. const_iterator" << endl;
    cout << "==================================================" << endl;

    unordered_set<int>::const_iterator cit;

    for (cit = us.begin();
         cit != us.end();
         ++cit)
    {
        cout << *cit
             << endl;
    }

    //==========================================================================
    // 14. IMPORTANT: ELEMENT MODIFICATION IS NOT ALLOWED
    //==========================================================================
    //
    // unordered_set mein elements unique keys ki tarah behave karte hain.
    //
    // Agar element ko directly modify kar diya:
    //
    //      *it = 100;
    //
    // to hash table ki internal organization invalid ho sakti hai.
    //
    //
    // Therefore direct modification through iterator is NOT allowed.
    //
    //
    // WRONG:
    //
    //      *it = 100;
    //
    //
    // Correct approach:
    //
    //      erase old element
    //      insert new element
    //
    // Example:
    //
    //      us.erase(20);
    //      us.insert(100);
    //
    //==========================================================================

    //==========================================================================
    // 15. find() + ITERATOR
    //==========================================================================
    //
    // find() returns an iterator to the requested element.
    //
    // Syntax:
    //
    //      unordered_set<int>::iterator it = us.find(value);
    //
    //
    // If element exists:
    //
    //      iterator != us.end()
    //
    //
    // If element does not exist:
    //
    //      iterator == us.end()
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "9. find() + ITERATOR" << endl;
    cout << "==================================================" << endl;

    unordered_set<int>::iterator found = us.find(30);

    if (found != us.end())
    {
        cout << "Element found = "
             << *found
             << endl;
    }
    else
    {
        cout << "Element not found."
             << endl;
    }

    //==========================================================================
    // 16. SEARCH FOR NON-EXISTING ELEMENT
    //==========================================================================

    unordered_set<int>::iterator notFound = us.find(999);

    cout << "\n==================================================" << endl;
    cout << "10. SEARCH FOR 999" << endl;
    cout << "==================================================" << endl;

    if (notFound != us.end())
    {
        cout << "999 is present."
             << endl;
    }
    else
    {
        cout << "999 is NOT present."
             << endl;
    }

    //==========================================================================
    // 17. count()
    //==========================================================================
    //
    // unordered_set contains UNIQUE elements.
    //
    // Therefore count(x) can return:
    //
    //      0 -> element does not exist
    //
    //      1 -> element exists
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "11. count()" << endl;
    cout << "==================================================" << endl;

    if (us.count(30) == 1)
    {
        cout << "30 is present."
             << endl;
    }
    else
    {
        cout << "30 is not present."
             << endl;
    }

    if (us.count(999) == 0)
    {
        cout << "999 is not present."
             << endl;
    }

    //==========================================================================
    // 18. equal_range()
    //==========================================================================
    //
    // unordered_set also supports equal_range().
    //
    // It returns:
    //
    //      pair<iterator, iterator>
    //
    //
    // For unordered_set:
    //
    //      first  -> lower range position
    //      second -> upper range position
    //
    //
    // Since unordered_set contains unique elements,
    // there can be at most one matching element.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "12. equal_range()" << endl;
    cout << "==================================================" << endl;

    pair<
        unordered_set<int>::iterator,
        unordered_set<int>::iterator>
        range = us.equal_range(30);

    for (unordered_set<int>::iterator iter = range.first;
         iter != range.second;
         ++iter)
    {
        cout << *iter
             << endl;
    }

    //==========================================================================
    // 19. ERASE USING ITERATOR
    //==========================================================================
    //
    // We can erase an element by passing its iterator.
    //
    // Syntax:
    //
    //      us.erase(iterator);
    //
    //
    // Example:
    //
    //      find 40
    //      erase iterator
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "13. ERASE USING ITERATOR" << endl;
    cout << "==================================================" << endl;

    unordered_set<int>::iterator eraseIt = us.find(40);

    if (eraseIt != us.end())
    {
        cout << "Erasing = "
             << *eraseIt
             << endl;

        us.erase(eraseIt);
    }

    // Print remaining elements.

    cout << "After erase:" << endl;

    for (unordered_set<int>::iterator iter = us.begin();
         iter != us.end();
         ++iter)
    {
        cout << *iter
             << endl;
    }

    //==========================================================================
    // 20. SAFE ERASE WHILE ITERATING
    //==========================================================================
    //
    // Agar iteration ke during elements erase karne hain,
    // to erase() ka returned iterator use karna safest pattern hai.
    //
    //
    // Syntax:
    //
    //      it = us.erase(it);
    //
    //
    // erase(iterator) next valid iterator return karta hai.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "14. SAFE ERASE WHILE ITERATING" << endl;
    cout << "==================================================" << endl;

    for (unordered_set<int>::iterator iter = us.begin();
         iter != us.end();)
    {
        if (*iter == 20)
        {
            /*
            Current element erase kar rahe hain.

            erase(iter) ke baad:
                iter invalid ho jayega.

            Isliye returned next iterator ko assign karte hain.
            */

            iter = us.erase(iter);
        }
        else
        {
            /*
            Current element erase nahi kiya.

            Therefore manually next element par move karo.
            */

            ++iter;
        }
    }

    cout << "After removing 20:" << endl;

    for (unordered_set<int>::iterator iter = us.begin();
         iter != us.end();
         ++iter)
    {
        cout << *iter
             << endl;
    }

    //==========================================================================
    // 21. DUPLICATE ELEMENTS
    //==========================================================================
    //
    // unordered_set duplicates allow nahi karta.
    //
    //==========================================================================

    unordered_set<int> duplicateSet;

    duplicateSet.insert(10);
    duplicateSet.insert(10);
    duplicateSet.insert(20);
    duplicateSet.insert(20);
    duplicateSet.insert(30);
    duplicateSet.insert(30);

    cout << "\n==================================================" << endl;
    cout << "15. DUPLICATE ELEMENTS" << endl;
    cout << "==================================================" << endl;

    for (unordered_set<int>::iterator iter =
             duplicateSet.begin();
         iter != duplicateSet.end();
         ++iter)
    {
        cout << *iter
             << endl;
    }

    /*
    IMPORTANT:

        Even though we inserted:

            10
            10
            20
            20
            30
            30

        only:

            10
            20
            30

        exist.

        Order is NOT guaranteed.
    */

    //==========================================================================
    // 22. SIZE WHILE ITERATING
    //==========================================================================
    //
    // size() number of elements batata hai.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "16. SIZE" << endl;
    cout << "==================================================" << endl;

    cout << "Number of elements = "
         << us.size()
         << endl;

    //==========================================================================
    // 23. EMPTY SET
    //==========================================================================
    //
    // Empty unordered_set:
    //
    //      begin() == end()
    //
    // Therefore loop execute nahi hoga.
    //
    //==========================================================================

    unordered_set<int> emptySet;

    cout << "\n==================================================" << endl;
    cout << "17. EMPTY unordered_set" << endl;
    cout << "==================================================" << endl;

    if (emptySet.begin() == emptySet.end())
    {
        cout << "unordered_set is empty."
             << endl;
    }

    for (unordered_set<int>::iterator iter =
             emptySet.begin();
         iter != emptySet.end();
         ++iter)
    {
        cout << *iter
             << endl;
    }

    //==========================================================================
    // 24. ITERATION ON STRING unordered_set
    //==========================================================================
    //
    // unordered_set sirf integers ke liye nahi hota.
    //
    // Example:
    //
    //      unordered_set<string>
    //
    //==========================================================================

    unordered_set<string> names;

    names.insert("Amit");
    names.insert("Rahul");
    names.insert("Riya");
    names.insert("Neha");

    cout << "\n==================================================" << endl;
    cout << "18. unordered_set<string>" << endl;
    cout << "==================================================" << endl;

    for (unordered_set<string>::iterator iter =
             names.begin();
         iter != names.end();
         ++iter)
    {
        cout << *iter
             << endl;
    }

    //==========================================================================
    // 25. ITERATION ON CHAR unordered_set
    //==========================================================================

    unordered_set<char> letters;

    letters.insert('a');
    letters.insert('b');
    letters.insert('c');
    letters.insert('d');

    cout << "\n==================================================" << endl;
    cout << "19. unordered_set<char>" << endl;
    cout << "==================================================" << endl;

    for (unordered_set<char>::iterator iter =
             letters.begin();
         iter != letters.end();
         ++iter)
    {
        cout << *iter
             << endl;
    }

    //==========================================================================
    // 26. const_iterator WITH STRING
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "20. const_iterator WITH STRING" << endl;
    cout << "==================================================" << endl;

    unordered_set<string>::const_iterator stringCit;

    for (stringCit = names.begin();
         stringCit != names.end();
         ++stringCit)
    {
        cout << *stringCit
             << endl;
    }

    //==========================================================================
    // 27. BUCKET CONCEPT
    //==========================================================================
    //
    // unordered_set hash table use karta hai.
    //
    // Hash table mein elements different buckets mein distribute hote hain.
    //
    // Useful functions:
    //
    //      bucket_count()
    //      bucket(value)
    //      bucket_size(bucketNumber)
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "21. BUCKET INFORMATION" << endl;
    cout << "==================================================" << endl;

    cout << "Number of buckets = "
         << us.bucket_count()
         << endl;

    //==========================================================================
    // 28. bucket(value)
    //==========================================================================
    //
    // bucket(value) batata hai ki given element kis bucket mein hai.
    //
    //==========================================================================

    if (us.find(30) != us.end())
    {
        cout << "Bucket containing 30 = "
             << us.bucket(30)
             << endl;
    }

    //==========================================================================
    // 29. bucket_size()
    //==========================================================================
    //
    // Kisi bucket mein kitne elements hain.
    //
    //==========================================================================

    if (us.find(30) != us.end())
    {
        size_t bucketNumber = us.bucket(30);

        cout << "Size of bucket containing 30 = "
             << us.bucket_size(bucketNumber)
             << endl;
    }

    //==========================================================================
    // 30. LOCAL ITERATOR
    //==========================================================================
    //
    // unordered_set mein global iterator ke alawa
    // local_iterator bhi hota hai.
    //
    //
    // Global iterator:
    //
    //      begin()
    //      end()
    //
    // poore container ko traverse karta hai.
    //
    //
    // Local iterator:
    //
    //      begin(bucket)
    //      end(bucket)
    //
    // ek specific bucket ke elements ko traverse karta hai.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "22. LOCAL ITERATOR" << endl;
    cout << "==================================================" << endl;

    if (us.find(30) != us.end())
    {
        size_t bucketNumber = us.bucket(30);

        unordered_set<int>::local_iterator localIt;

        cout << "Elements in bucket "
             << bucketNumber
             << ":" << endl;

        for (localIt = us.begin(bucketNumber);
             localIt != us.end(bucketNumber);
             ++localIt)
        {
            cout << *localIt
                 << endl;
        }
    }

    //==========================================================================
    // 31. ALL BUCKETS + LOCAL ITERATORS
    //==========================================================================
    //
    // Hash table ke every bucket ko inspect karne ke liye:
    //
    //      for each bucket
    //          begin(bucket)
    //          end(bucket)
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "23. ALL BUCKETS USING LOCAL ITERATORS" << endl;
    cout << "==================================================" << endl;

    for (size_t bucket = 0;
         bucket < us.bucket_count();
         ++bucket)
    {
        cout << "Bucket "
             << bucket
             << ": ";

        for (unordered_set<int>::local_iterator localIt =
                 us.begin(bucket);
             localIt != us.end(bucket);
             ++localIt)
        {
            cout << *localIt
                 << " ";
        }

        cout << endl;
    }

    //==========================================================================
    // 32. load_factor()
    //==========================================================================
    //
    // load_factor tells average number of elements per bucket.
    //
    // Conceptually:
    //
    //      load_factor = size / bucket_count
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "24. LOAD FACTOR" << endl;
    cout << "==================================================" << endl;

    cout << "Load factor = "
         << us.load_factor()
         << endl;

    //==========================================================================
    // 33. max_load_factor()
    //==========================================================================
    //
    // max_load_factor hash table ki maximum preferred load factor batata hai.
    //
    // Ye hashing performance se related concept hai.
    //
    //==========================================================================

    cout << "Maximum load factor = "
         << us.max_load_factor()
         << endl;

    //==========================================================================
    // 34. NO RANDOM ACCESS
    //==========================================================================
    //
    // unordered_set iterator random access iterator nahi hai.
    //
    // Therefore:
    //
    //      it + 2
    //
    //      it - 2
    //
    // invalid hai.
    //
    //
    // unordered_set iterator supports:
    //
    //      ++it
    //
    // but not:
    //
    //      --it
    //
    //==========================================================================

    //==========================================================================
    // 35. std::advance()
    //==========================================================================
    //
    // Agar iterator ko multiple positions forward move karna ho,
    // to std::advance() use kar sakte hain.
    //
    // Example:
    //
    //      advance(it, 2);
    //
    //
    // IMPORTANT:
    //
    // unordered_set iterator forward iterator hai.
    //
    // Isliye advance internally repeated ++ operations perform karega.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "25. std::advance()" << endl;
    cout << "==================================================" << endl;

    if (us.size() >= 3)
    {
        unordered_set<int>::iterator advanceIt = us.begin();

        cout << "Starting element = "
             << *advanceIt
             << endl;

        advance(advanceIt, 2);

        if (advanceIt != us.end())
        {
            cout << "After advance by 2 = "
                 << *advanceIt
                 << endl;
        }
    }

    //==========================================================================
    // 36. iterator WITH find()
    //==========================================================================
    //
    // Practical DSA pattern:
    //
    //      find element
    //      check against end()
    //      use iterator
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "26. PRACTICAL find() PATTERN" << endl;
    cout << "==================================================" << endl;

    unordered_set<int>::iterator searchIt =
        us.find(50);

    if (searchIt == us.end())
    {
        cout << "50 not found."
             << endl;
    }
    else
    {
        cout << "50 found at iterator."
             << endl;

        cout << "Value = "
             << *searchIt
             << endl;
    }

    //==========================================================================
    // 37. ITERATOR + ERASE
    //==========================================================================
    //
    // Another practical pattern:
    //
    //      auto it = us.find(value);
    //
    //      if (it != us.end())
    //      {
    //          us.erase(it);
    //      }
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "27. find() + erase(iterator)" << endl;
    cout << "==================================================" << endl;

    unordered_set<int>::iterator removeIt =
        us.find(10);

    if (removeIt != us.end())
    {
        cout << "Removing "
             << *removeIt
             << endl;

        us.erase(removeIt);
    }

    //==========================================================================
    // 38. FINAL ITERATION
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "28. FINAL ITERATION" << endl;
    cout << "==================================================" << endl;

    for (unordered_set<int>::iterator iter =
             us.begin();
         iter != us.end();
         ++iter)
    {
        cout << *iter
             << endl;
    }

    //==========================================================================
    // 39. FINAL MESSAGE
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "UNORDERED_SET ITERATOR COURSE COMPLETE" << endl;
    cout << "==================================================" << endl;

    return 0;
}

/*
===============================================================================
                       UNORDERED_SET ITERATOR
                            CHEAT SHEET
===============================================================================


1. INCLUDE HEADER

        #include <unordered_set>


2. CREATE unordered_set

        unordered_set<int> us;


3. ITERATOR DECLARATION

        unordered_set<int>::iterator it;


4. BEGIN

        it = us.begin();

    Gives iterator to the first element in the iteration sequence.

    IMPORTANT:

        It is NOT the smallest element.

        unordered_set is NOT sorted.


5. END

        us.end();

    Represents position after the last element.

    NEVER dereference:

        *us.end();


6. DEREFERENCE

        *it

    Gives current element.


7. COMPLETE ITERATION

        for (unordered_set<int>::iterator it = us.begin();
             it != us.end();
             ++it)
        {
            cout << *it;
        }


8. RANGE-BASED LOOP

        for (const auto &x : us)
        {
            cout << x;
        }


9. const_iterator

        unordered_set<int>::const_iterator it;


10. FIND

        auto it = us.find(30);


11. FIND CHECK

        if (it != us.end())
        {
            cout << *it;
        }


12. COUNT

        us.count(30)

    Returns:

        0 -> absent
        1 -> present

    because unordered_set stores unique elements.


13. EQUAL_RANGE

        us.equal_range(30);

    Returns a pair of iterators.


14. ERASE USING ITERATOR

        us.erase(it);


15. SAFE ERASE WHILE ITERATING

        for (auto it = us.begin();
             it != us.end();)
        {
            if (condition)
            {
                it = us.erase(it);
            }
            else
            {
                ++it;
            }
        }


16. FORWARD MOVEMENT

        ++it

    YES.


17. BACKWARD MOVEMENT

        --it

    NO.


18. RANDOM ACCESS

        it + 2
        it - 2

    NO.


19. REVERSE ITERATORS

        rbegin()
        rend()

    NOT available for unordered_set.


20. LOWER BOUND

        lower_bound()

    NOT available.


21. UPPER BOUND

        upper_bound()

    NOT available.


22. BUCKET COUNT

        us.bucket_count();


23. ELEMENT'S BUCKET

        us.bucket(value);


24. BUCKET SIZE

        us.bucket_size(bucketNumber);


25. LOCAL ITERATOR

        us.begin(bucketNumber);
        us.end(bucketNumber);


26. LOAD FACTOR

        us.load_factor();


27. MAX LOAD FACTOR

        us.max_load_factor();


===============================================================================
                    SET VS UNORDERED_SET ITERATORS
===============================================================================


+----------------------+----------------------+---------------------------+
| Feature              | set                  | unordered_set             |
+----------------------+----------------------+---------------------------+
| Ordering             | Sorted               | No guaranteed order       |
| Iterator category    | Bidirectional        | Forward                   |
| ++it                 | YES                  | YES                       |
| --it                 | YES                  | NO                        |
| rbegin()             | YES                  | NO                        |
| rend()               | YES                  | NO                        |
| lower_bound()        | YES                  | NO                        |
| upper_bound()        | YES                  | NO                        |
| find()               | YES                  | YES                       |
| count()              | YES                  | YES                       |
| equal_range()        | YES                  | YES                       |
| erase(iterator)      | YES                  | YES                       |
| Bucket API           | NO                   | YES                       |
+----------------------+----------------------+---------------------------+


===============================================================================
                         MOST IMPORTANT POINT
===============================================================================


BOTH:

        set<int>

and:

        unordered_set<int>

use:

        *it

to access the current element.


Neither uses:

        it->first
        it->second


Because they contain individual elements, not key-value pairs.


===============================================================================
                         ITERATOR TYPES
===============================================================================


For:

        unordered_set<int>


NORMAL ITERATOR:

        unordered_set<int>::iterator


CONST ITERATOR:

        unordered_set<int>::const_iterator


LOCAL ITERATOR:

        unordered_set<int>::local_iterator


CONST LOCAL ITERATOR:

        unordered_set<int>::const_local_iterator


===============================================================================
                         WHY NO --it?
===============================================================================


unordered_set is hash-table based.

Its iterator does not provide a previous-element operation.

Therefore:

        ++it

is supported.


But:

        --it

is NOT supported.


If you need reverse traversal in sorted order:

        use std::set instead.


===============================================================================
                      WHY NO lower_bound()?
===============================================================================


lower_bound() depends on ordered searching.

For example, in set:

        10 20 30 40 50

lower_bound(25)

gives:

        30


But unordered_set does not maintain sorted order.

Therefore:

        lower_bound()

and:

        upper_bound()

are not available.


===============================================================================
                         HASH TABLE + ITERATOR
===============================================================================


unordered_set internally uses buckets.


Conceptually:


                    unordered_set

                         |
                         v

                   HASH FUNCTION
                         |
          +--------------+--------------+
          |              |              |
        Bucket 0       Bucket 1       Bucket 2
          |              |              |
        elements       elements       elements


The exact bucket distribution depends on the implementation,
hash function and current table state.


Therefore iteration order should NEVER be assumed.


===============================================================================
                         DSA USE CASES
===============================================================================


unordered_set is commonly useful when you need:

    1. Fast average lookup.

    2. Unique values.

    3. No requirement for sorted order.


Example:

    unordered_set<int> visited;


Very common in:

    Graph traversal
    BFS
    DFS
    Duplicate detection
    Membership checking
    Fast lookup


Example:

        if (visited.find(node) == visited.end())
        {
            visited.insert(node);
        }


Or simply:

        if (visited.count(node) == 0)
        {
            visited.insert(node);
        }


===============================================================================
                         TIME COMPLEXITY
===============================================================================


Average:

    insert:
        O(1)

    find:
        O(1)

    erase:
        O(1)

    count:
        O(1)


Worst case:

    insert:
        O(n)

    find:
        O(n)

    erase:
        O(n)


Full iteration:

    O(n)


Important:

    unordered_set provides average constant-time lookup,
    NOT guaranteed constant-time lookup.


===============================================================================
                         FINAL REVISION
===============================================================================


Create:

    unordered_set<int> us;


Insert:

    us.insert(10);


Iterator:

    unordered_set<int>::iterator it;


Begin:

    it = us.begin();


End:

    us.end();


Current element:

    *it


Move forward:

    ++it


Complete traversal:

    for (auto it = us.begin();
         it != us.end();
         ++it)
    {
        cout << *it;
    }


Search:

    auto it = us.find(10);


Check:

    if (it != us.end())


Erase:

    us.erase(it);


Count:

    us.count(10);


Reverse:

    NOT AVAILABLE


Backward:

    --it

    NOT AVAILABLE


Sorted traversal:

    NOT GUARANTEED


lower_bound:

    NOT AVAILABLE


upper_bound:

    NOT AVAILABLE


Bucket:

    us.bucket(value);


Number of buckets:

    us.bucket_count();


Local bucket iterator:

    us.begin(bucket);
    us.end(bucket);


===============================================================================
                           GOLDEN RULE
===============================================================================


For unordered_set:

            +-----------------------------+
            |     unordered_set<T>        |
            +-----------------------------+
                         |
                         v
                    iterator
                         |
                         v
                       *it
                         |
                         v
                   current value


Remember:

        unordered_set

        = UNIQUE
        = UNORDERED
        = HASH BASED
        = FAST AVERAGE LOOKUP
        = FORWARD ITERATOR


Most important traversal:

        for (auto it = us.begin();
             it != us.end();
             ++it)
        {
            cout << *it << endl;
        }


===============================================================================
                              END
===============================================================================
*/