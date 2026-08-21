/*
===============================================================================
                         C++ STL - SET
              COMPLETE OPERATIONS + DETAILED NOTES + CODE
===============================================================================

HEADER FILE:

    #include <set>

WHAT IS std::set?

    std::set is an associative container provided by the C++ STL.

    A set stores UNIQUE elements in SORTED ORDER.

IMPORTANT PROPERTIES OF SET:

    1. Elements are UNIQUE.
    2. Duplicate elements are automatically ignored.
    3. Elements are stored in sorted order.
    4. Default sorting order is ascending.
    5. Searching is generally O(log n).
    6. Insertion is generally O(log n).
    7. Erasing an element is generally O(log n).
    8. Iterators can be used to traverse the set.
    9. set is normally implemented using a balanced tree.
   10. set does NOT store key-value pairs.

Example:

    set<int> s;

    If we insert:

        40
        10
        30
        20

    Set stores them as:

        10
        20
        30
        40

===============================================================================
*/

#include <iostream>
#include <set>

using namespace std;

int main()
{

    //==========================================================================
    // 1. CREATING A SET
    //==========================================================================
    //
    // Syntax:
    //
    //      set<DataType> variableName;
    //
    //
    // Example:
    //
    //      set<int> s;
    //
    // This creates a set that stores integer values.
    //
    //==========================================================================

    set<int> s;

    //==========================================================================
    // 2. INSERTING ELEMENTS
    //==========================================================================
    //
    // insert() is used to add an element to the set.
    //
    // Syntax:
    //
    //      s.insert(value);
    //
    //==========================================================================

    s.insert(1000);
    s.insert(2000);
    s.insert(3000);
    s.insert(3000);
    s.insert(4000);

    /*
    IMPORTANT:

        We inserted:

            1000
            2000
            3000
            3000
            4000

        But 3000 was inserted twice.

        set does NOT allow duplicate elements.

        Therefore actual set contains:

            1000
            2000
            3000
            4000


        Size will therefore be:

            4

        NOT:

            5
    */

    cout << "==================================================" << endl;
    cout << "1. INSERT + DUPLICATE HANDLING" << endl;
    cout << "==================================================" << endl;

    cout << "Size: "
         << s.size()
         << endl;

    //==========================================================================
    // 3. DISPLAY ALL ELEMENTS
    //==========================================================================
    //
    // Set automatically maintains sorted order.
    //
    //==========================================================================

    cout << "\nElements of set:" << endl;

    for (set<int>::iterator it = s.begin();
         it != s.end();
         ++it)
    {
        cout << *it << endl;
    }

    /*
    OUTPUT:

        1000
        2000
        3000
        4000

    Even though insertion order was:

        1000
        2000
        3000
        3000
        4000

    Set stores unique values in sorted order.
    */

    //==========================================================================
    // 4. size()
    //==========================================================================
    //
    // size() returns the number of elements currently present in the set.
    //
    // Syntax:
    //
    //      s.size();
    //
    // Return type:
    //
    //      size_t
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "2. size()" << endl;
    cout << "==================================================" << endl;

    cout << "Number of elements = "
         << s.size()
         << endl;

    //==========================================================================
    // 5. empty()
    //==========================================================================
    //
    // empty() checks whether the set contains zero elements.
    //
    // It returns:
    //
    //      true
    //
    // if the set is empty.
    //
    //
    // It returns:
    //
    //      false
    //
    // if the set contains at least one element.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "3. empty()" << endl;
    cout << "==================================================" << endl;

    if (s.empty())
    {
        cout << "Set is Empty"
             << endl;
    }
    else
    {
        cout << "Set is Not Empty"
             << endl;
    }

    //==========================================================================
    // 6. find()
    //==========================================================================
    //
    // find() searches for a particular element.
    //
    // Syntax:
    //
    //      s.find(value);
    //
    //
    // find() returns an iterator.
    //
    //
    // If the element exists:
    //
    //      iterator != s.end()
    //
    //
    // If the element does NOT exist:
    //
    //      iterator == s.end()
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "4. find()" << endl;
    cout << "==================================================" << endl;

    set<int>::iterator it = s.find(3000);

    if (it != s.end())
    {
        cout << "3000 is Found"
             << endl;

        cout << "Found Value = "
             << *it
             << endl;
    }
    else
    {
        cout << "3000 is Not Found"
             << endl;
    }

    //==========================================================================
    // 7. find() WITH AN ELEMENT THAT DOES NOT EXIST
    //==========================================================================

    set<int>::iterator it2 = s.find(5000);

    if (it2 != s.end())
    {
        cout << "5000 is Found"
             << endl;
    }
    else
    {
        cout << "5000 is Not Found"
             << endl;
    }

    //==========================================================================
    // 8. count()
    //==========================================================================
    //
    // count() checks whether a particular value exists in the set.
    //
    // Since set stores UNIQUE elements:
    //
    //      count(value)
    //
    // can return only:
    //
    //      0 -> element does not exist
    //
    //      1 -> element exists
    //
    //
    // Syntax:
    //
    //      s.count(value);
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "5. count()" << endl;
    cout << "==================================================" << endl;

    if (s.count(3000) == 1)
    {
        cout << "3000 is Present"
             << endl;
    }
    else
    {
        cout << "3000 is Not Present"
             << endl;
    }

    if (s.count(5000) == 0)
    {
        cout << "5000 is Not Present"
             << endl;
    }
    else
    {
        cout << "5000 is Present"
             << endl;
    }

    //==========================================================================
    // 9. erase(value)
    //==========================================================================
    //
    // erase(value) directly removes the specified value.
    //
    // Syntax:
    //
    //      s.erase(value);
    //
    //
    // Example:
    //
    //      s.erase(3000);
    //
    // This removes 3000 from the set.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "6. erase(value)" << endl;
    cout << "==================================================" << endl;

    cout << "Before erase(3000), size = "
         << s.size()
         << endl;

    s.erase(3000);

    cout << "After erase(3000), size = "
         << s.size()
         << endl;

    // Display set after deletion.

    cout << "Set after erase(3000):" << endl;

    for (set<int>::iterator iter = s.begin();
         iter != s.end();
         ++iter)
    {
        cout << *iter << endl;
    }

    //==========================================================================
    // 10. erase(iterator)
    //==========================================================================
    //
    // We can also erase an element using its iterator.
    //
    // Syntax:
    //
    //      s.erase(iterator);
    //
    //
    // First find the element:
    //
    //      iterator = s.find(value);
    //
    // Then erase:
    //
    //      s.erase(iterator);
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "7. erase(iterator)" << endl;
    cout << "==================================================" << endl;

    set<int>::iterator eraseIt = s.find(2000);

    if (eraseIt != s.end())
    {
        cout << "Erasing element = "
             << *eraseIt
             << endl;

        s.erase(eraseIt);
    }

    cout << "Set after erase using iterator:" << endl;

    for (set<int>::iterator iter = s.begin();
         iter != s.end();
         ++iter)
    {
        cout << *iter << endl;
    }

    //==========================================================================
    // 11. erase(first, last)
    //==========================================================================
    //
    // A range of elements can also be erased.
    //
    // Syntax:
    //
    //      s.erase(first, last);
    //
    //
    // IMPORTANT:
    //
    // The range is:
    //
    //      [first, last)
    //
    //
    // Meaning:
    //
    //      first is included.
    //
    //      last is NOT included.
    //
    //
    // Example:
    //
    //      s.erase(s.begin(), s.end());
    //
    // removes all elements.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "8. erase(first, last)" << endl;
    cout << "==================================================" << endl;

    cout << "Size before range erase = "
         << s.size()
         << endl;

    s.erase(s.begin(), s.end());

    cout << "Size after range erase = "
         << s.size()
         << endl;

    //==========================================================================
    // 12. clear()
    //==========================================================================
    //
    // clear() removes ALL elements from the set.
    //
    // Syntax:
    //
    //      s.clear();
    //
    //
    // After clear():
    //
    //      s.size() == 0
    //
    //      s.empty() == true
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "9. clear()" << endl;
    cout << "==================================================" << endl;

    // Reinsert elements so that clear() can be demonstrated.

    s.insert(1000);
    s.insert(2000);
    s.insert(3000);
    s.insert(4000);

    cout << "Size before clear() = "
         << s.size()
         << endl;

    s.clear();

    cout << "Size after clear() = "
         << s.size()
         << endl;

    //==========================================================================
    // 13. empty() AFTER clear()
    //==========================================================================

    if (s.empty())
    {
        cout << "Set is Empty"
             << endl;
    }
    else
    {
        cout << "Set is Not Empty"
             << endl;
    }

    //==========================================================================
    // 14. INSERT AGAIN AFTER clear()
    //==========================================================================
    //
    // clear() does NOT destroy the set object.
    //
    // We can insert new elements after clear().
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "10. INSERT AFTER clear()" << endl;
    cout << "==================================================" << endl;

    s.insert(500);
    s.insert(100);
    s.insert(400);
    s.insert(200);
    s.insert(300);

    cout << "Elements after reinsertion:" << endl;

    for (set<int>::iterator iter = s.begin();
         iter != s.end();
         ++iter)
    {
        cout << *iter << endl;
    }

    /*
    IMPORTANT:

        We inserted:

            500
            100
            400
            200
            300

        But output will be sorted:

            100
            200
            300
            400
            500
    */

    //==========================================================================
    // 15. begin()
    //==========================================================================
    //
    // begin() returns iterator pointing to the first element.
    //
    // Since set is sorted:
    //
    //      begin()
    //
    // points to the smallest element.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "11. begin()" << endl;
    cout << "==================================================" << endl;

    set<int>::iterator beginIt = s.begin();

    cout << "First element = "
         << *beginIt
         << endl;

    //==========================================================================
    // 16. end()
    //==========================================================================
    //
    // end() does NOT point to the last element.
    //
    // It points to the position just AFTER the last element.
    //
    //
    // Therefore:
    //
    //      *s.end()
    //
    // is INVALID.
    //
    //
    // Correct:
    //
    //      it != s.end()
    //
    //==========================================================================

    //==========================================================================
    // 17. LAST ELEMENT USING ITERATOR
    //==========================================================================
    //
    // To get the last element:
    //
    //      --s.end()
    //
    // BUT:
    //
    // Do not directly write:
    //
    //      cout << *--s.end();
    //
    // for learning code.
    //
    // Better:
    //
    //      iterator last = s.end();
    //      --last;
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "12. LAST ELEMENT" << endl;
    cout << "==================================================" << endl;

    set<int>::iterator lastIt = s.end();

    --lastIt;

    cout << "Last element = "
         << *lastIt
         << endl;

    //==========================================================================
    // 18. lower_bound()
    //==========================================================================
    //
    // lower_bound(value) returns iterator to the first element
    // which is greater than or equal to the given value.
    //
    //
    // Example:
    //
    //      Set:
    //
    //          100
    //          200
    //          300
    //          400
    //          500
    //
    //
    //      lower_bound(250)
    //
    // returns:
    //
    //      300
    //
    // Because 300 is the first element >= 250.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "13. lower_bound()" << endl;
    cout << "==================================================" << endl;

    set<int>::iterator lowerIt = s.lower_bound(250);

    if (lowerIt != s.end())
    {
        cout << "lower_bound(250) = "
             << *lowerIt
             << endl;
    }
    else
    {
        cout << "No lower bound found."
             << endl;
    }

    //==========================================================================
    // 19. upper_bound()
    //==========================================================================
    //
    // upper_bound(value) returns iterator to the first element
    // strictly GREATER than the given value.
    //
    //
    // Example:
    //
    //      upper_bound(300)
    //
    // returns:
    //
    //      400
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "14. upper_bound()" << endl;
    cout << "==================================================" << endl;

    set<int>::iterator upperIt = s.upper_bound(300);

    if (upperIt != s.end())
    {
        cout << "upper_bound(300) = "
             << *upperIt
             << endl;
    }
    else
    {
        cout << "No upper bound found."
             << endl;
    }

    //==========================================================================
    // 20. equal_range()
    //==========================================================================
    //
    // equal_range(value) returns a pair of iterators.
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
    // Syntax:
    //
    //      auto range = s.equal_range(value);
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "15. equal_range()" << endl;
    cout << "==================================================" << endl;

    pair<set<int>::iterator, set<int>::iterator> range =
        s.equal_range(300);

    cout << "Elements in equal_range(300):" << endl;

    for (set<int>::iterator iter = range.first;
         iter != range.second;
         ++iter)
    {
        cout << *iter << endl;
    }

    //==========================================================================
    // 21. INSERT RETURN VALUE
    //==========================================================================
    //
    // insert() returns a pair:
    //
    //      pair<iterator, bool>
    //
    //
    // first:
    //
    //      iterator to element
    //
    //
    // second:
    //
    //      true  -> insertion happened
    //
    //      false -> element already existed
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "16. INSERT RETURN VALUE" << endl;
    cout << "==================================================" << endl;

    pair<set<int>::iterator, bool> result =
        s.insert(600);

    if (result.second)
    {
        cout << "600 was inserted."
             << endl;
    }
    else
    {
        cout << "600 was already present."
             << endl;
    }

    // Try inserting duplicate.

    pair<set<int>::iterator, bool> duplicateResult =
        s.insert(600);

    if (duplicateResult.second)
    {
        cout << "600 was inserted again."
             << endl;
    }
    else
    {
        cout << "600 already exists, so duplicate was ignored."
             << endl;
    }

    //==========================================================================
    // 22. erase() RETURN VALUE
    //==========================================================================
    //
    // erase(value) returns the number of elements erased.
    //
    // Since set contains unique elements:
    //
    //      0 -> value did not exist
    //
    //      1 -> value was erased
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "17. erase() RETURN VALUE" << endl;
    cout << "==================================================" << endl;

    size_t erasedCount = s.erase(600);

    cout << "Number of elements erased = "
         << erasedCount
         << endl;

    // Try erasing an element that does not exist.

    size_t erasedCount2 = s.erase(9999);

    cout << "Trying to erase 9999." << endl;

    cout << "Number of elements erased = "
         << erasedCount2
         << endl;

    //==========================================================================
    // 23. ITERATE USING const_iterator
    //==========================================================================
    //
    // const_iterator is useful when we only want to READ elements.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "18. const_iterator" << endl;
    cout << "==================================================" << endl;

    set<int>::const_iterator cit;

    for (cit = s.begin();
         cit != s.end();
         ++cit)
    {
        cout << *cit << endl;
    }

    //==========================================================================
    // 24. RANGE-BASED FOR LOOP
    //==========================================================================
    //
    // Modern C++ syntax:
    //
    //      for (const auto &x : s)
    //
    // This is internally based on iterator-style traversal.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "19. RANGE-BASED FOR LOOP" << endl;
    cout << "==================================================" << endl;

    for (const auto &x : s)
    {
        cout << x << endl;
    }

    //==========================================================================
    // 25. REMOVE ELEMENTS WHILE ITERATING
    //==========================================================================
    //
    // Safe pattern:
    //
    //      it = s.erase(it);
    //
    //
    // erase(iterator) returns the next valid iterator.
    //
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "20. SAFE ERASE WHILE ITERATING" << endl;
    cout << "==================================================" << endl;

    for (set<int>::iterator iter = s.begin();
         iter != s.end();)
    {
        if (*iter == 200)
        {
            // Remove current element.

            iter = s.erase(iter);
        }
        else
        {
            // Move to next element.

            ++iter;
        }
    }

    cout << "Set after removing 200:" << endl;

    for (set<int>::iterator iter = s.begin();
         iter != s.end();
         ++iter)
    {
        cout << *iter << endl;
    }

    //==========================================================================
    // 26. FINAL SIZE
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "21. FINAL SIZE" << endl;
    cout << "==================================================" << endl;

    cout << "Final Size = "
         << s.size()
         << endl;

    //==========================================================================
    // 27. FINAL EMPTY CHECK
    //==========================================================================

    if (s.empty())
    {
        cout << "Set is Empty"
             << endl;
    }
    else
    {
        cout << "Set is Not Empty"
             << endl;
    }

    //==========================================================================
    // 28. FINAL ITERATION
    //==========================================================================

    cout << "\n==================================================" << endl;
    cout << "22. FINAL SET" << endl;
    cout << "==================================================" << endl;

    for (set<int>::iterator iter = s.begin();
         iter != s.end();
         ++iter)
    {
        cout << *iter << endl;
    }

    //==========================================================================
    // 29. END OF PROGRAM
    //==========================================================================

    return 0;
}

/*
===============================================================================
                            SET OPERATIONS SUMMARY
===============================================================================


1. CREATE SET
-------------------------------------------------------------------------------

    set<int> s;


2. INSERT
-------------------------------------------------------------------------------

    s.insert(10);


3. DUPLICATE INSERT
-------------------------------------------------------------------------------

    s.insert(10);
    s.insert(10);

    Only one 10 remains.


4. SIZE
-------------------------------------------------------------------------------

    s.size();


5. EMPTY
-------------------------------------------------------------------------------

    s.empty();


6. CLEAR
-------------------------------------------------------------------------------

    s.clear();


7. FIND
-------------------------------------------------------------------------------

    auto it = s.find(10);


8. CHECK FIND
-------------------------------------------------------------------------------

    if (it != s.end())
    {
        cout << *it;
    }


9. COUNT
-------------------------------------------------------------------------------

    s.count(10);

    Returns:

        0 -> absent
        1 -> present


10. ERASE BY VALUE
-------------------------------------------------------------------------------

    s.erase(10);


11. ERASE BY ITERATOR
-------------------------------------------------------------------------------

    auto it = s.find(10);

    if (it != s.end())
    {
        s.erase(it);
    }


12. ERASE RANGE
-------------------------------------------------------------------------------

    s.erase(s.begin(), s.end());


13. BEGIN
-------------------------------------------------------------------------------

    s.begin();


14. END
-------------------------------------------------------------------------------

    s.end();


15. LOWER_BOUND
-------------------------------------------------------------------------------

    s.lower_bound(25);


    Returns first element >= 25.


16. UPPER_BOUND
-------------------------------------------------------------------------------

    s.upper_bound(25);


    Returns first element > 25.


17. EQUAL_RANGE
-------------------------------------------------------------------------------

    s.equal_range(25);


    Returns:

        pair<iterator, iterator>


18. ITERATE
-------------------------------------------------------------------------------

    for (auto it = s.begin();
         it != s.end();
         ++it)
    {
        cout << *it;
    }


19. RANGE-BASED ITERATION
-------------------------------------------------------------------------------

    for (const auto &x : s)
    {
        cout << x;
    }


===============================================================================
                         IMPORTANT SET RULES
===============================================================================


RULE 1:
    set stores UNIQUE values.


RULE 2:
    Duplicate insertion is ignored.


RULE 3:
    set automatically maintains SORTED ORDER.


RULE 4:
    Default sorting is ASCENDING.


RULE 5:
    begin() points to the smallest element.


RULE 6:
    end() is one position after the last element.


RULE 7:
    Never dereference end().


RULE 8:
    find() returns an iterator.


RULE 9:
    If find() fails:

        iterator == end()


RULE 10:
    count() returns 0 or 1 because set is unique.


RULE 11:
    erase(value) removes by value.


RULE 12:
    erase(iterator) removes the element pointed to by iterator.


RULE 13:
    erase(first, last) removes a range.


RULE 14:
    clear() removes all elements.


RULE 15:
    lower_bound(x):

        first element >= x


RULE 16:
    upper_bound(x):

        first element > x


RULE 17:
    equal_range(x):

        { lower_bound(x), upper_bound(x) }


RULE 18:
    Set elements cannot be modified directly through iterator.


WRONG:

    *it = 500;


CORRECT WAY TO REPLACE:

    s.erase(oldValue);
    s.insert(newValue);


===============================================================================
                         TIME COMPLEXITY
===============================================================================


For std::set:


insert(value):

    O(log n)


find(value):

    O(log n)


count(value):

    O(log n)


erase(value):

    O(log n)


lower_bound():

    O(log n)


upper_bound():

    O(log n)


equal_range():

    O(log n)


erase(iterator):

    amortized constant for the iterator removal itself,
    with tree rebalancing handled by the container.


begin():

    O(1)


end():

    O(1)


size():

    O(1)


empty():

    O(1)


clear():

    O(n)


Full traversal:

    O(n)


===============================================================================
                     SET vs VECTOR vs UNORDERED_SET
===============================================================================


std::set:

    UNIQUE
    SORTED
    O(log n) search


std::vector:

    Allows duplicates
    Sequential
    Random access
    Search generally O(n)


std::unordered_set:

    UNIQUE
    NOT SORTED
    Average O(1) search


===============================================================================
                           IMPORTANT EXAMPLE
===============================================================================


Suppose:

    set<int> s;

    s.insert(50);
    s.insert(10);
    s.insert(30);
    s.insert(20);
    s.insert(40);


Set becomes:

    10
    20
    30
    40
    50


Iteration:

    for (auto it = s.begin();
         it != s.end();
         ++it)
    {
        cout << *it;
    }


Output:

    10
    20
    30
    40
    50


===============================================================================
                              END
===============================================================================
*/