#include <iostream>
#include <list>
using namespace std;

int main()
{
    // ============================================================
    // INSERT AND ERASE IN LIST
    // ============================================================
    //
    // std::list is a DOUBLY LINKED LIST.
    //
    // Therefore, insertion and deletion are very efficient
    // when we already have the correct iterator.
    //
    // Important:
    //
    // list does NOT support random access like:
    //
    // l[2]        // ❌
    // l.begin()+2 // ❌
    //
    // Instead, we use ITERATORS to reach a position.

    // ============================================================
    // CREATING A LIST
    // ============================================================

    list<int> l = {10, 20, 30, 40};

    // Current list:
    //
    // 10 <-> 20 <-> 30 <-> 40

    // ============================================================
    // INSERTION USING insert()
    // ============================================================

    // Syntax:
    //
    // l.insert(position, value);
    //
    // IMPORTANT:
    //
    // insert() inserts the new element BEFORE the position
    // pointed to by the iterator.

    // ------------------------------------------------------------
    // INSERT AT BEGINNING
    // ------------------------------------------------------------

    // l.begin() points to the first element, 10.
    //
    // If we do:
    //
    // l.insert(l.begin(), 5);
    //
    // 5 will be inserted BEFORE 10.

    l.insert(l.begin(), 5);

    // List becomes:
    //
    // 5 <-> 10 <-> 20 <-> 30 <-> 40

    // ------------------------------------------------------------
    // INSERT BEFORE A PARTICULAR ELEMENT
    // ------------------------------------------------------------

    // We want to insert 25 BEFORE 30.
    //
    // We cannot write:
    //
    // l.begin() + 2
    //
    // because list iterator does not support +.
    //
    // So we create an iterator and move it using advance().

    auto it = l.begin();

    // Current:
    //
    // 5 <-> 10 <-> 20 <-> 30 <-> 40
    //  ^
    //  |
    //  it
    //
    // Move iterator 3 positions forward:
    //
    // 5 -> 10 -> 20 -> 30

    advance(it, 3);

    // Now:
    //
    // 5 <-> 10 <-> 20 <-> 30 <-> 40
    //                     ^
    //                     |
    //                     it
    //
    // *it = 30
    //
    // Insert 25 BEFORE 30.

    l.insert(it, 25);

    // List becomes:
    //
    // 5 <-> 10 <-> 20 <-> 25 <-> 30 <-> 40

    // ============================================================
    // PRINT LIST AFTER INSERTION
    // ============================================================

    cout << "After insertion: ";

    for (int x : l)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // INSERT MULTIPLE COPIES
    // ============================================================

    // insert() can also insert multiple copies of the same value.
    //
    // Syntax:
    //
    // l.insert(position, count, value);
    //
    // Example:
    //
    // Insert three 100s before 40.

    it = l.end();

    // end() points just AFTER the last element.
    //
    // To insert before 40, we move one step backward.

    --it;

    // Now it points to 40.
    //
    // Insert:
    //
    // 100, 100, 100
    //
    // before 40.

    l.insert(it, 3, 100);

    // List becomes:
    //
    // 5 <-> 10 <-> 20 <-> 25 <-> 30
    // <-> 100 <-> 100 <-> 100 <-> 40

    // Print again.

    cout << "After inserting multiple values: ";

    for (int x : l)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // ERASE USING erase()
    // ============================================================

    // erase() is used to remove elements.
    //
    // Syntax for one element:
    //
    // l.erase(iterator);
    //
    // It removes the element pointed to by the iterator.

    // ------------------------------------------------------------
    // ERASE ONE ELEMENT
    // ------------------------------------------------------------

    // Let's remove 25.
    //
    // Current list:
    //
    // 5 <-> 10 <-> 20 <-> 25 <-> 30 <-> ...
    //
    // We create an iterator at beginning.

    it = l.begin();

    // Move 3 positions:
    //
    // 0 -> 5
    // 1 -> 10
    // 2 -> 20
    // 3 -> 25

    advance(it, 3);

    // Now:
    //
    // *it = 25
    //
    // Erase that node.

    l.erase(it);

    // 25 is removed.
    //
    // List becomes:
    //
    // 5 <-> 10 <-> 20 <-> 30 <-> 100 <-> 100 <-> 100 <-> 40

    // ============================================================
    // PRINT AFTER ERASE
    // ============================================================

    cout << "After erasing 25: ";

    for (int x : l)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // ERASE A RANGE
    // ============================================================

    // erase() can also remove a RANGE of elements.
    //
    // Syntax:
    //
    // l.erase(first, last);
    //
    // The range is:
    //
    // [first, last)
    //
    // first -> INCLUDED
    // last  -> NOT INCLUDED

    // Let's remove:
    //
    // 100, 100, 100
    //
    // Current list:
    //
    // 5 <-> 10 <-> 20 <-> 30
    // <-> 100 <-> 100 <-> 100 <-> 40

    // Find first 100.

    auto first = l.begin();

    advance(first, 4);

    // first points to first 100.
    //
    //          first
    //            ↓
    // 5  10  20  30  100  100  100  40

    // Find the element AFTER the last 100.
    //
    // That is 40.
    //
    // We use another iterator.

    auto last = l.begin();

    advance(last, 7);

    // last points to 40.
    //
    // So:
    //
    // l.erase(first, last);
    //
    // removes:
    //
    // 100, 100, 100
    //
    // but does NOT remove 40.

    l.erase(first, last);

    // ============================================================
    // PRINT AFTER RANGE ERASE
    // ============================================================

    cout << "After range erase: ";

    for (int x : l)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // ERASE EVERYTHING
    // ============================================================

    // We can remove the complete list using:
    //
    // l.erase(l.begin(), l.end());
    //
    // This removes all elements.
    //
    // After this:
    //
    // l = []
    //
    // and:
    //
    // l.size() = 0
    //
    // BUT if our intention is simply to remove every element,
    // the simpler and clearer method is:
    //
    // l.clear();

    // ============================================================
    // IMPORTANT: erase() RETURNS AN ITERATOR
    // ============================================================

    // One useful property of erase():
    //
    // l.erase(it)
    //
    // returns an iterator pointing to the element
    // that comes AFTER the erased element.
    //
    // This is very useful when deleting elements while
    // traversing a list.

    // Example:
    //
    // Suppose:
    //
    // l = [10, 20, 30, 40]
    //
    // it points to 20.
    //
    // auto next = l.erase(it);
    //
    // 20 is removed.
    //
    // next now points to 30.

    // ============================================================
    // IMPORTANT DIFFERENCE: insert vs erase
    // ============================================================

    /*
        insert():

        l.insert(it, value);

        Adds value BEFORE the position 'it' points to.


        erase():

        l.erase(it);

        Removes the element at position 'it'.


        Example:

        Before:
        10 <-> 20 <-> 30

        it -> 20


        insert(it, 15):

        10 <-> 15 <-> 20 <-> 30


        erase(it):

        10 <-> 30
    */

    // ============================================================
    // TIME COMPLEXITY
    // ============================================================

    /*
        If we already have the correct iterator:

        insert() -> O(1)
        erase()  -> O(1)

        Why?

        Because list is a doubly linked list.

        Only the links between nearby nodes need to be changed.

        No shifting of all following elements is required.
    */

    // ============================================================
    // VECTOR vs LIST
    // ============================================================

    /*
        VECTOR:

        vector<int> v = {10,20,30,40};

        v.insert(v.begin()+2, 25);

        Elements may need to be shifted.

        Generally O(n).


        LIST:

        list<int> l = {10,20,30,40};

        auto it = l.begin();
        advance(it, 2);

        l.insert(it, 25);

        If iterator is already available:

        O(1)
    */

    // ============================================================
    // FINAL LIST
    // ============================================================

    // At this point, after all the operations above:
    //
    // l contains:
    //
    // 5 <-> 10 <-> 20 <-> 30 <-> 40
    //
    // because we inserted values and later erased
    // 25 and the three 100s.

    cout << "Final list: ";

    for (int x : l)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}