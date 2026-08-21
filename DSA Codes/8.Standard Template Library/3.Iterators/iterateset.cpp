/*
===============================================================================
                         C++ STL - SET ITERATORS
                    COMPLETE DETAILED NOTES + CODE
===============================================================================

TOPIC:
    Iterators on std::set

HEADER:
    #include <set>

MAIN TOPICS COVERED:

    1. What is set?
    2. What is iterator?
    3. Creating a set
    4. Inserting elements
    5. iterator declaration
    6. begin()
    7. end()
    8. Dereferencing iterator *
    9. Arrow operator and why it is NOT used with set
   10. ++it
   11. --it
   12. Complete iteration
   13. const_iterator
   14. Range-based for loop
   15. Reverse iterator
   16. rbegin()
   17. rend()
   18. find() + iterator
   19. lower_bound()
   20. upper_bound()
   21. equal_range()
   22. erase() using iterator
   23. Safe erase while iterating
   24. Empty set iteration
   25. Integer set iteration
   26. String set iteration
   27. Character set iteration
   28. Important restrictions
   29. Set iterator cheat sheet
   30. Final revision notes


===============================================================================
WHAT IS std::set?
===============================================================================

std::set is an associative container of C++ STL.

It stores UNIQUE elements.

Example:

        set<int> s;

        10
        20
        30
        40


IMPORTANT PROPERTIES OF SET:

    1. Elements are UNIQUE.

    2. Duplicate elements are automatically ignored.

    3. Elements are stored in SORTED ORDER.

    4. Default sorting is ASCENDING ORDER.

    5. set is an ORDERED associative container.

    6. set is generally implemented using a balanced tree
       such as a Red-Black Tree.

    7. Search, insertion and deletion are generally:

            O(log n)


===============================================================================
SET VS UNORDERED_SET
===============================================================================

    set
        -> ordered
        -> sorted
        -> unique elements
        -> tree based
        -> O(log n) search

    unordered_set
        -> unordered
        -> hashing based
        -> unique elements
        -> average O(1) search


===============================================================================
ITERATOR
===============================================================================

Iterator ek object hota hai jo container ke element ko point karta hai.

Conceptually, iterator pointer jaisa behave karta hai.

For example:

        set<int> s;

        10
        20
        30
        40

Iterator:

        it
        |
        v
       10


Then:

        ++it

moves iterator to:

       20


===============================================================================
IMPORTANT DIFFERENCE FROM map
===============================================================================

map mein element hota hai:

        key + value

Isliye:

        it->first
        it->second

use karte hain.

Lekin set mein sirf VALUE hoti hai.

Example:

        set<int>

Element:

        10

Isliye set iterator mein:

        *it

current value deta hai.

NOT:

        it->first

NOT:

        it->second


===============================================================================
*/

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{

    //==========================================================================
    // 1. CREATE A SET
    //==========================================================================
    //
    // Syntax:
    //
    //      set<DataType> variableName;
    //
    // Example:
    //
    //      set<int> s;
    //
    // Means:
    //
    //      set will store integer values.
    //
    //==========================================================================

    set<int> s;

    //==========================================================================
    // 2. INSERT ELEMENTS
    //==========================================================================
    //
    // Set automatically keeps elements sorted.
    //
    // Hum intentionally random order mein insert kar rahe hain.
    //
    //==========================================================================

    s.insert(50);
    s.insert(10);
    s.insert(40);
    s.insert(20);
    s.insert(30);

    /*
    We inserted:

        50
        10
        40
        20
        30


    But set internally maintains sorted order:

        10
        20
        30
        40
        50


    Therefore iteration will also happen in sorted order.
    */

    cout << "==================================================" << endl;
    cout << "SET ITERATORS" << endl;
    cout << "==================================================" << endl;

    //==========================================================================
    // 3. BASIC ITERATOR DECLARATION
    //==========================================================================
    //
    // Iterator type:
    //
    //      set<int>::iterator
    //
    // Syntax:
    //
    //      set<int>::iterator it;
    //
    //==========================================================================

    set<int>::iterator it;

    //==========================================================================
    // 4. begin()
    //==========================================================================
    //
    // begin() returns an iterator pointing to the first valid element.
    //
    // Since set is ordered:
    //
    //      begin()
    //
    // points to the SMALLEST element.
    //
    //
    // Our set:
    //
    //      10
    //      20
    //      30
    //      40
    //      50
    //
    // Therefore:
    //
    //      s.begin()
    //
    // points to:
    //
    //      10
    //
    //==========================================================================

    it = s.begin();

    cout << "\n==================================================" << endl;
    cout << "1. begin()" << endl;
    cout << "==================================================" << endl;

    cout << "First element = "
         << *it
         << endl;

    //==========================================================================
    // 5. DEREFERENCE OPERATOR *
    //==========================================================================
    //
    // Iterator current element ko point karta hai.
    //
    // Current element ki actual value obtain karne ke liye:
    //
    //      *it
    //
    // use karte hain.
    //
    //
    // Example:
    //
    //      it -> 10
    //
    //      *it
    //
    // gives:
    //
    //      10
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "2. DEREFERENCE OPERATOR *" << endl;
    cout << "==================================================" << endl;

    cout << "Current element = "
         << *it
         << endl;

    //==========================================================================
    // 6. IMPORTANT: SET MEIN first/second NAHI HOTE
    //==========================================================================
    //
    // map mein:
    //
    //      it->first
    //          -> key
    //
    //      it->second
    //          -> value
    //
    //
    // Lekin set mein:
    //
    //      sirf ek element hota hai.
    //
    //
    // Example:
    //
    //      set<int>
    //
    // contains:
    //
    //      10
    //
    // Not:
    //
    //      key = 10
    //      value = something
    //
    //
    // Therefore:
    //
    //      *it
    //
    // directly element deta hai.
    //
    //
    // WRONG:
    //
    //      it->first
    //
    // WRONG:
    //
    //      it->second
    //
    //
    // CORRECT:
    //
    //      *it
    //
    //==========================================================================

    //==========================================================================
    // 7. ++it
    //==========================================================================
    //
    // Iterator ko next element par move karne ke liye:
    //
    //      ++it
    //
    // use karte hain.
    //
    //
    // Current order:
    //
    //      10 -> 20 -> 30 -> 40 -> 50
    //
    //
    // Initially:
    //
    //      it -> 10
    //
    // After:
    //
    //      ++it
    //
    // Iterator:
    //
    //      it -> 20
    //
    //==========================================================================

    ++it;

    cout << "\n==================================================" << endl;
    cout << "3. AFTER ++it" << endl;
    cout << "==================================================" << endl;

    cout << "Current element = "
         << *it
         << endl;

    //==========================================================================
    // 8. COMPLETE ITERATION USING ITERATOR
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
    //          -> first valid element
    //
    //      != end()
    //          -> loop continues until end position
    //
    //      ++iterator
    //          -> next element
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "4. COMPLETE ITERATION USING ITERATOR" << endl;
    cout << "==================================================" << endl;

    for (set<int>::iterator iter = s.begin();
         iter != s.end();
         ++iter)
    {
        // *iter gives current set element.

        cout << *iter
             << endl;
    }

    //==========================================================================
    // 9. begin() AND end()
    //==========================================================================
    //
    // begin():
    //
    //      first valid element ko point karta hai.
    //
    //
    // end():
    //
    //      LAST ELEMENT ko point nahi karta.
    //
    // It represents the position:
    //
    //      one step AFTER the last element.
    //
    //
    // Conceptually:
    //
    //      [10] [20] [30] [40] [50] [END]
    //       ^
    //       |
    //     begin
    //
    //
    //                                  ^
    //                                  |
    //                                 end
    //
    //
    // IMPORTANT:
    //
    //      *s.end()
    //
    // should NOT be used.
    //
    // end() is mainly used for comparison.
    //
    //==========================================================================

    //==========================================================================
    // 10. ITERATOR COMPARISON
    //==========================================================================
    //
    // We can check:
    //
    //      it == s.end()
    //
    // or:
    //
    //      it != s.end()
    //
    //
    // Most common:
    //
    //      it != s.end()
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "5. ITERATOR COMPARISON" << endl;
    cout << "==================================================" << endl;

    it = s.begin();

    if (it != s.end())
    {
        cout << "Iterator is pointing to a valid element."
             << endl;

        cout << "Element = "
             << *it
             << endl;
    }

    //==========================================================================
    // 11. const_iterator
    //==========================================================================
    //
    // Agar humein sirf READ karna hai aur set ko modify nahi karna,
    // to const_iterator use kar sakte hain.
    //
    // Syntax:
    //
    //      set<int>::const_iterator
    //
    //
    // const_iterator se:
    //
    //      *cit
    //
    // read kar sakte hain.
    //
    // Lekin:
    //
    //      *cit = 100;
    //
    // allowed nahi hai.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "6. const_iterator" << endl;
    cout << "==================================================" << endl;

    set<int>::const_iterator cit;

    for (cit = s.begin();
         cit != s.end();
         ++cit)
    {
        cout << *cit
             << endl;
    }

    //==========================================================================
    // 12. RANGE-BASED FOR LOOP
    //==========================================================================
    //
    // C++11 se range-based for loop available hai.
    //
    // Syntax:
    //
    //      for (const auto &x : s)
    //
    //
    // x current element ko represent karega.
    //
    // Set mein x directly value hai.
    //
    // map ki tarah:
    //
    //      x.first
    //      x.second
    //
    // nahi hota.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "7. RANGE-BASED FOR LOOP" << endl;
    cout << "==================================================" << endl;

    for (const auto &x : s)
    {
        cout << x
             << endl;
    }

    //==========================================================================
    // 13. RANGE-BASED LOOP WITH auto
    //==========================================================================
    //
    // auto compiler ko data type automatically determine karne deta hai.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "8. RANGE-BASED LOOP WITH auto" << endl;
    cout << "==================================================" << endl;

    for (auto x : s)
    {
        cout << x
             << endl;
    }

    //==========================================================================
    // 14. IMPORTANT: SET ELEMENT KO MODIFY NAHI KAR SAKTE
    //==========================================================================
    //
    // Ye bahut important concept hai.
    //
    // Suppose:
    //
    //      set<int> s;
    //
    //      10
    //      20
    //      30
    //
    //
    // Agar hum directly:
    //
    //      *it = 100;
    //
    // kar dein, to set ki ordering break ho sakti hai.
    //
    //
    // Isliye set iterator se element modification allowed nahi hai.
    //
    //
    // WRONG:
    //
    //      *it = 100;
    //
    //
    // Set elements effectively const hote hain.
    //
    // Agar value change karni hai:
    //
    //      old element erase karo
    //
    // aur:
    //
    //      new element insert karo.
    //
    // Example:
    //
    //      s.erase(20);
    //      s.insert(100);
    //
    //==========================================================================

    //==========================================================================
    // 15. ONLY ELEMENTS
    //==========================================================================
    //
    // Set mein key/value ka concept nahi hota.
    //
    // Sirf elements hote hain.
    //
    // Isliye iterator ke through:
    //
    //      *iter
    //
    // use karna enough hai.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "9. ONLY ELEMENTS" << endl;
    cout << "==================================================" << endl;

    for (set<int>::iterator iter = s.begin();
         iter != s.end();
         ++iter)
    {
        cout << "Element = "
             << *iter
             << endl;
    }

    //==========================================================================
    // 16. find() + ITERATOR
    //==========================================================================
    //
    // Kisi particular element ko search karne ke liye:
    //
    //      find()
    //
    // use kar sakte hain.
    //
    //
    // Example:
    //
    //      s.find(30)
    //
    //
    // Agar 30 present hai:
    //
    //      iterator to 30
    //
    // return hoga.
    //
    //
    // Agar 30 absent hai:
    //
    //      s.end()
    //
    // return hoga.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "10. find() + ITERATOR" << endl;
    cout << "==================================================" << endl;

    set<int>::iterator found = s.find(30);

    if (found != s.end())
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
    // 17. SEARCH ANOTHER ELEMENT
    //==========================================================================

    set<int>::iterator found2 = s.find(100);

    cout << "\n==================================================" << endl;
    cout << "11. SEARCH 100" << endl;
    cout << "==================================================" << endl;

    if (found2 != s.end())
    {
        cout << "100 is present."
             << endl;
    }
    else
    {
        cout << "100 is not present."
             << endl;
    }

    //==========================================================================
    // 18. ITERATE FROM A PARTICULAR ITERATOR
    //==========================================================================
    //
    // find() se humein iterator mil sakta hai.
    //
    // Us iterator se aage end() tak traversal kar sakte hain.
    //
    //
    // Example:
    //
    //      start = s.find(30)
    //
    //
    // Then:
    //
    //      30 -> 40 -> 50
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "12. ITERATE FROM FOUND POSITION" << endl;
    cout << "==================================================" << endl;

    set<int>::iterator start = s.find(30);

    if (start != s.end())
    {
        for (set<int>::iterator iter = start;
             iter != s.end();
             ++iter)
        {
            cout << *iter
                 << endl;
        }
    }

    //==========================================================================
    // 19. rbegin()
    //==========================================================================
    //
    // Reverse iteration ke liye:
    //
    //      rbegin()
    //
    // use karte hain.
    //
    //
    // rbegin() largest element ko point karta hai.
    //
    //
    // Our set:
    //
    //      10 20 30 40 50
    //
    //
    // rbegin():
    //
    //      50
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "13. rbegin()" << endl;
    cout << "==================================================" << endl;

    set<int>::reverse_iterator rit;

    rit = s.rbegin();

    cout << "Largest element = "
         << *rit
         << endl;

    //==========================================================================
    // 20. COMPLETE REVERSE ITERATION
    //==========================================================================
    //
    // Syntax:
    //
    //      for
    //      (
    //          reverse_iterator = rbegin();
    //          reverse_iterator != rend();
    //          ++reverse_iterator
    //      )
    //
    //
    // Output:
    //
    //      50
    //      40
    //      30
    //      20
    //      10
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "14. COMPLETE REVERSE ITERATION" << endl;
    cout << "==================================================" << endl;

    for (set<int>::reverse_iterator iter = s.rbegin();
         iter != s.rend();
         ++iter)
    {
        cout << *iter
             << endl;
    }

    //==========================================================================
    // 21. rend()
    //==========================================================================
    //
    // rend() reverse traversal ke end ke baad wali position hoti hai.
    //
    // Normal:
    //
    //      begin() -> first element
    //      end()   -> after last
    //
    //
    // Reverse:
    //
    //      rbegin() -> last/largest element
    //      rend()   -> before first in reverse traversal
    //
    //==========================================================================

    //==========================================================================
    // 22. lower_bound()
    //==========================================================================
    //
    // lower_bound(value):
    //
    // First element ka iterator return karta hai jiska value:
    //
    //      >= given value
    //
    //
    // Example:
    //
    // Set:
    //
    //      10 20 30 40 50
    //
    //
    // lower_bound(25)
    //
    // returns iterator to:
    //
    //      30
    //
    // Because 30 is the first element >= 25.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "15. lower_bound()" << endl;
    cout << "==================================================" << endl;

    set<int>::iterator lb = s.lower_bound(25);

    if (lb != s.end())
    {
        cout << "lower_bound(25) = "
             << *lb
             << endl;
    }
    else
    {
        cout << "No lower bound found."
             << endl;
    }

    //==========================================================================
    // 23. lower_bound() WHEN EXACT ELEMENT EXISTS
    //==========================================================================
    //
    // lower_bound(30):
    //
    // first element >= 30
    //
    // Result:
    //
    //      30
    //
    //==========================================================================

    set<int>::iterator lb2 = s.lower_bound(30);

    cout << "\n==================================================" << endl;
    cout << "16. lower_bound(30)" << endl;
    cout << "==================================================" << endl;

    if (lb2 != s.end())
    {
        cout << *lb2
             << endl;
    }

    //==========================================================================
    // 24. upper_bound()
    //==========================================================================
    //
    // upper_bound(value):
    //
    // First element ka iterator return karta hai jiska value:
    //
    //      > given value
    //
    //
    // Example:
    //
    //      10 20 30 40 50
    //
    //
    // upper_bound(30)
    //
    // returns:
    //
    //      40
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "17. upper_bound()" << endl;
    cout << "==================================================" << endl;

    set<int>::iterator ub = s.upper_bound(30);

    if (ub != s.end())
    {
        cout << "upper_bound(30) = "
             << *ub
             << endl;
    }
    else
    {
        cout << "No upper bound found."
             << endl;
    }

    //==========================================================================
    // 25. equal_range()
    //==========================================================================
    //
    // equal_range(value) returns:
    //
    //      pair<iterator, iterator>
    //
    //
    // First iterator:
    //
    //      lower_bound(value)
    //
    //
    // Second iterator:
    //
    //      upper_bound(value)
    //
    //
    // Since set contains UNIQUE values, range normally contains
    // zero or one matching element.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "18. equal_range()" << endl;
    cout << "==================================================" << endl;

    pair<set<int>::iterator, set<int>::iterator> range =
        s.equal_range(30);

    for (set<int>::iterator iter = range.first;
         iter != range.second;
         ++iter)
    {
        cout << *iter
             << endl;
    }

    //==========================================================================
    // 26. ERASE USING ITERATOR
    //==========================================================================
    //
    // Iterator ko erase() mein pass kar sakte hain.
    //
    // Syntax:
    //
    //      s.erase(it);
    //
    //
    // Example:
    //
    //      find 40
    //      erase it
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "19. ERASE USING ITERATOR" << endl;
    cout << "==================================================" << endl;

    set<int>::iterator eraseIt = s.find(40);

    if (eraseIt != s.end())
    {
        cout << "Erasing = "
             << *eraseIt
             << endl;

        s.erase(eraseIt);
    }

    // Print after erase.

    cout << "Set after erase:" << endl;

    for (set<int>::iterator iter = s.begin();
         iter != s.end();
         ++iter)
    {
        cout << *iter
             << endl;
    }

    //==========================================================================
    // 27. SAFE ERASE WHILE ITERATING
    //==========================================================================
    //
    // Agar iteration ke time kuch elements delete karne hain,
    // safe pattern use karna important hai.
    //
    //
    // Modern C++:
    //
    //      it = s.erase(it);
    //
    //
    // erase(iterator) next valid iterator return karta hai.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "20. SAFE ERASE WHILE ITERATING" << endl;
    cout << "==================================================" << endl;

    for (set<int>::iterator iter = s.begin();
         iter != s.end();)
    {
        if (*iter == 20)
        {
            // Current element delete.
            //
            // erase() next valid iterator return karega.

            iter = s.erase(iter);
        }
        else
        {
            // Agar erase nahi kiya,
            // manually next element par move karo.

            ++iter;
        }
    }

    cout << "Set after removing 20:" << endl;

    for (set<int>::iterator iter = s.begin();
         iter != s.end();
         ++iter)
    {
        cout << *iter
             << endl;
    }

    //==========================================================================
    // 28. IMPORTANT WRONG ERASE PATTERN
    //==========================================================================
    //
    // Avoid this style:
    //
    //
    //      for (auto it = s.begin();
    //           it != s.end();
    //           ++it)
    //      {
    //          if (...)
    //          {
    //              s.erase(it);
    //          }
    //      }
    //
    //
    // Problem:
    //
    // erase(it) ke baad it invalid ho sakta hai.
    //
    // Uske baad automatic ++it unsafe ho sakta hai.
    //
    //
    // Correct:
    //
    //      for (auto it = s.begin();
    //           it != s.end();)
    //      {
    //          if (...)
    //              it = s.erase(it);
    //          else
    //              ++it;
    //      }
    //
    //==========================================================================

    //==========================================================================
    // 29. EMPTY SET ITERATION
    //==========================================================================
    //
    // Agar set empty hai:
    //
    //      begin() == end()
    //
    //
    // Isliye:
    //
    //      for loop
    //
    // zero times execute hoga.
    //
    //==========================================================================

    set<int> emptySet;

    cout << "\n==================================================" << endl;
    cout << "21. EMPTY SET ITERATION" << endl;
    cout << "==================================================" << endl;

    for (set<int>::iterator iter = emptySet.begin();
         iter != emptySet.end();
         ++iter)
    {
        cout << *iter
             << endl;
    }

    cout << "Loop completed because set is empty."
         << endl;

    //==========================================================================
    // 30. SET OF STRINGS
    //==========================================================================
    //
    // set sirf int ke liye nahi hota.
    //
    // Example:
    //
    //      set<string>
    //
    //==========================================================================

    set<string> names;

    names.insert("Riya");
    names.insert("Amit");
    names.insert("Rahul");
    names.insert("Neha");

    cout << "\n==================================================" << endl;
    cout << "22. ITERATION ON set<string>" << endl;
    cout << "==================================================" << endl;

    for (set<string>::iterator iter = names.begin();
         iter != names.end();
         ++iter)
    {
        cout << *iter
             << endl;
    }

    //==========================================================================
    // 31. SET OF CHARACTERS
    //==========================================================================
    //
    // Example:
    //
    //      set<char>
    //
    //==========================================================================

    set<char> letters;

    letters.insert('d');
    letters.insert('a');
    letters.insert('c');
    letters.insert('b');

    cout << "\n==================================================" << endl;
    cout << "23. ITERATION ON set<char>" << endl;
    cout << "==================================================" << endl;

    for (set<char>::iterator iter = letters.begin();
         iter != letters.end();
         ++iter)
    {
        cout << *iter
             << endl;
    }

    //==========================================================================
    // 32. DUPLICATE VALUES AND ITERATION
    //==========================================================================
    //
    // Set duplicates allow nahi karta.
    //
    // Example:
    //
    //      set<int> duplicateSet;
    //
    //      insert 10
    //      insert 10
    //      insert 10
    //
    // Only one 10 will remain.
    //
    //==========================================================================

    set<int> duplicateSet;

    duplicateSet.insert(10);
    duplicateSet.insert(10);
    duplicateSet.insert(20);
    duplicateSet.insert(20);
    duplicateSet.insert(30);

    cout << "\n==================================================" << endl;
    cout << "24. DUPLICATE ELEMENTS" << endl;
    cout << "==================================================" << endl;

    for (set<int>::iterator iter = duplicateSet.begin();
         iter != duplicateSet.end();
         ++iter)
    {
        cout << *iter
             << endl;
    }

    /*
    OUTPUT:

        10
        20
        30

    NOT:

        10
        10
        20
        20
        30
    */

    //==========================================================================
    // 33. PRE-DECREMENT --it
    //==========================================================================
    //
    // Bidirectional iterator होने के कारण set iterator ko backwards
    // move kar sakte hain.
    //
    //
    // Example:
    //
    //      10 20 30 40 50
    //
    //
    // If:
    //
    //      it -> 50
    //
    // then:
    //
    //      --it
    //
    // gives:
    //
    //      40
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "25. --it : MOVE BACKWARD" << endl;
    cout << "==================================================" << endl;

    set<int>::iterator backwardIt = s.end();

    /*
    IMPORTANT:

        end() last element ko point nahi karta.

    So pehle:

        --backwardIt

    karke last valid element par jaana hoga.
    */

    if (!s.empty())
    {
        --backwardIt;

        cout << "Last element = "
             << *backwardIt
             << endl;
    }

    //==========================================================================
    // 34. MOVE BACKWARD MULTIPLE TIMES
    //==========================================================================

    if (!s.empty())
    {
        --backwardIt;

        cout << "Previous element = "
             << *backwardIt
             << endl;
    }

    //==========================================================================
    // 35. ITERATOR DOES NOT SUPPORT RANDOM ACCESS
    //==========================================================================
    //
    // set iterator is NOT a random access iterator.
    //
    // Therefore:
    //
    //      it + 2
    //
    //      it - 2
    //
    // are NOT valid operations for set iterator.
    //
    //
    // You can use:
    //
    //      ++it
    //
    //      --it
    //
    //
    // But not:
    //
    //      it + 2
    //
    //      it - 2
    //
    //
    // If you need to move multiple positions:
    //
    //      advance(it, 2);
    //
    // can be used after including:
    //
    //      #include <iterator>
    //
    //==========================================================================

    //==========================================================================
    // 36. FINAL COMPLETE ITERATION
    //==========================================================================
    //
    // Ab current set ko final time iterate karte hain.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "26. FINAL COMPLETE ITERATION" << endl;
    cout << "==================================================" << endl;

    for (set<int>::iterator iter = s.begin();
         iter != s.end();
         ++iter)
    {
        cout << *iter
             << endl;
    }

    //==========================================================================
    // 37. FINAL SUMMARY
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "SET ITERATOR COURSE COMPLETE" << endl;
    cout << "==================================================" << endl;

    return 0;
}

/*
===============================================================================
                         SET ITERATOR CHEAT SHEET
===============================================================================


1. ITERATOR DECLARATION

        set<int>::iterator it;


2. BEGIN

        it = s.begin();

        -> first/smallest element


3. END

        s.end();

        -> one position after last element

        IMPORTANT:

            Do not dereference end().


4. DEREFERENCE

        *it

        -> current set element


5. NEXT ELEMENT

        ++it


6. PREVIOUS ELEMENT

        --it


7. COMPLETE ITERATION

        for (set<int>::iterator it = s.begin();
             it != s.end();
             ++it)
        {
            cout << *it;
        }


8. CONST ITERATOR

        set<int>::const_iterator it;


9. RANGE-BASED LOOP

        for (const auto &x : s)
        {
            cout << x;
        }


10. REVERSE ITERATOR

        set<int>::reverse_iterator it;


11. REVERSE BEGIN

        s.rbegin();

        -> largest element


12. REVERSE END

        s.rend();


13. REVERSE ITERATION

        for (set<int>::reverse_iterator it = s.rbegin();
             it != s.rend();
             ++it)
        {
            cout << *it;
        }


14. FIND

        set<int>::iterator it = s.find(30);


15. FIND CHECK

        if (it != s.end())
        {
            cout << *it;
        }


16. LOWER BOUND

        s.lower_bound(x);

        -> first element >= x


17. UPPER BOUND

        s.upper_bound(x);

        -> first element > x


18. EQUAL RANGE

        s.equal_range(x);

        -> pair of iterators:

           lower_bound
           upper_bound


19. ERASE USING ITERATOR

        s.erase(it);


20. SAFE ERASE WHILE ITERATING

        for (auto it = s.begin();
             it != s.end();)
        {
            if (condition)
            {
                it = s.erase(it);
            }
            else
            {
                ++it;
            }
        }


===============================================================================
                     MOST IMPORTANT DIFFERENCE
===============================================================================


MAP:

        map<int, string>

        iterator element:

            pair<const int, string>

        Access:

            it->first
            it->second


SET:

        set<int>

        iterator element:

            int

        Access:

            *it


Therefore:

        MAP:

            it->first
            it->second


        SET:

            *it


===============================================================================
                         SET ITERATOR RULES
===============================================================================


RULE 1:

    set elements are unique.


RULE 2:

    set elements are sorted.


RULE 3:

    begin() points to the smallest element.


RULE 4:

    end() is after the last element.


RULE 5:

    *it gives the current element.


RULE 6:

    set iterator does NOT have:

        it->first
        it->second


RULE 7:

    set element cannot be modified directly through iterator.


WRONG:

    *it = 100;


RULE 8:

    To replace an element:

        erase old element
        insert new element


Example:

    s.erase(20);
    s.insert(100);


RULE 9:

    ++it moves forward.


RULE 10:

    --it moves backward.


RULE 11:

    set iterator is NOT random access.


Therefore:

    it + 2

    is not valid.


RULE 12:

    find() returns iterator.


RULE 13:

    If find() fails:

        iterator == end()


RULE 14:

    rbegin() starts from largest element.


RULE 15:

    lower_bound(x):

        first element >= x


RULE 16:

    upper_bound(x):

        first element > x


RULE 17:

    erase(iterator) removes the element at that iterator.


===============================================================================
                        TIME COMPLEXITY
===============================================================================


For std::set:

    begin():
        O(1)

    end():
        O(1)

    ++iterator:
        O(1) amortized / constant iterator step

    --iterator:
        O(1) amortized / constant iterator step

    find():
        O(log n)

    lower_bound():
        O(log n)

    upper_bound():
        O(log n)

    insert():
        O(log n)

    erase(iterator):
        amortized constant for the iterator unlinking itself
        (with tree rebalancing details handled internally)

    Full iteration:
        O(n)


===============================================================================
                         FINAL REVISION
===============================================================================


                    set<T>

                       |
                       |
                    iterator
                       |
                       v

                      *it
                       |
                       v
                 current value


Example:

    set<int> s;

    s.insert(30);
    s.insert(10);
    s.insert(20);


Internal sorted order:

    10
    20
    30


Iteration:

    for (set<int>::iterator it = s.begin();
         it != s.end();
         ++it)
    {
        cout << *it;
    }


Output:

    10
    20
    30


REVERSE:

    for (set<int>::reverse_iterator it = s.rbegin();
         it != s.rend();
         ++it)
    {
        cout << *it;
    }


Output:

    30
    20
    10


KEY POINT:

    SET:

        *it


    MAP:

        it->first
        it->second


This difference is extremely important for STL iterators.


===============================================================================
*/