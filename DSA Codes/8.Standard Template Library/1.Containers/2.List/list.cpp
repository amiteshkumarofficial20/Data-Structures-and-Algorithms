#include <iostream>
#include <list>
using namespace std;

int main()
{
    // ============================================================
    // CREATION OF LIST
    // ============================================================

    // Creating a list of integers with initial values.
    //
    // list<int> means:
    // "Create a list whose elements are of type int."
    //
    // Initially:
    //
    // l = [10, 20, 30, 40]
    //
    // Conceptually:
    //
    // 10 <-> 20 <-> 30 <-> 40

    list<int> l = {10, 20, 30, 40};

    // ============================================================
    // push_back()
    // ============================================================

    // push_back() inserts a new element at the END of the list.
    //
    // Current list:
    //
    // 10 <-> 20 <-> 30 <-> 40
    //
    // After adding 10:
    //
    // 10 <-> 20 <-> 30 <-> 40 <-> 10

    l.push_back(10); // Adds 10 at the back

    // Another push_back().
    //
    // Current:
    //
    // 10 <-> 20 <-> 30 <-> 40 <-> 10
    //
    // After:
    //
    // 10 <-> 20 <-> 30 <-> 40 <-> 10 <-> 20

    l.push_back(20); // Adds 20 at the back

    // Add 80 at the end.

    l.push_back(80);

    // Current:
    //
    // 10 <-> 20 <-> 30 <-> 40 <-> 10 <-> 20 <-> 80

    // Add 90 at the end.

    l.push_back(90);

    // Current:
    //
    // 10 <-> 20 <-> 30 <-> 40 <-> 10 <-> 20 <-> 80 <-> 90

    // ============================================================
    // size()
    // ============================================================

    // size() returns the total number of elements currently
    // present in the list.
    //
    // Initially we had 4 elements:
    //
    // 10, 20, 30, 40
    //
    // Then we added:
    //
    // 10
    // 20
    // 80
    // 90
    //
    // Total:
    //
    // 4 + 4 = 8 elements

    cout << "Size: " << l.size() << endl;

    // ============================================================
    // pop_back()
    // ============================================================

    // pop_back() removes the LAST element of the list.
    //
    // Current:
    //
    // 10 <-> 20 <-> 30 <-> 40 <-> 10 <-> 20 <-> 80 <-> 90
    //                                                     ^
    //                                                  removed
    //
    // 90 will be removed.
    //
    // New list:
    //
    // 10 <-> 20 <-> 30 <-> 40 <-> 10 <-> 20 <-> 80

    l.pop_back();

    // After removing one element:
    //
    // size = 7

    cout << "Size: " << l.size() << endl;

    // ============================================================
    // pop_front()
    // ============================================================

    // pop_front() removes the FIRST element of the list.
    //
    // Current:
    //
    // 10 <-> 20 <-> 30 <-> 40 <-> 10 <-> 20 <-> 80
    //  ^
    // removed
    //
    // The first 10 is removed.
    //
    // New list:
    //
    // 20 <-> 30 <-> 40 <-> 10 <-> 20 <-> 80

    l.pop_front();

    // Size becomes:
    //
    // 6

    cout << "Size: " << l.size() << endl;

    // ============================================================
    // push_front()
    // ============================================================

    // push_front() inserts an element at the BEGINNING of
    // the list.
    //
    // Current:
    //
    // 20 <-> 30 <-> 40 <-> 10 <-> 20 <-> 80
    //
    // Add 500 at front:
    //
    // 500 <-> 20 <-> 30 <-> 40 <-> 10 <-> 20 <-> 80

    l.push_front(500);

    // Add 50 at front.
    //
    // Current:
    //
    // 500 <-> 20 <-> 30 <-> 40 <-> 10 <-> 20 <-> 80
    //
    // After:
    //
    // 50 <-> 500 <-> 20 <-> 30 <-> 40 <-> 10 <-> 20 <-> 80

    l.push_front(50);

    // We added 2 elements.
    //
    // Previous size = 6
    // New size = 8

    cout << "Size: " << l.size() << endl;

    // ============================================================
    // clear()
    // ============================================================

    // clear() removes ALL elements from the list.
    //
    // Before clear():
    //
    // 50 <-> 500 <-> 20 <-> 30 <-> 40 <-> 10 <-> 20 <-> 80
    //
    // After clear():
    //
    // []
    //
    // Therefore:
    //
    // l.size() = 0

    l.clear();

    cout << "Size: " << l.size() << endl;

    // ============================================================
    // empty()
    // ============================================================

    // empty() checks whether the list contains zero elements.
    //
    // It returns:
    //
    // true  -> list is empty
    // false -> list is NOT empty
    //
    // Since we just used clear(),
    // the list is currently empty.
    //
    // l.empty() will return true.

    l.empty();

    // ============================================================
    // if(l.empty() == true)
    // ============================================================

    // We can use empty() inside an if statement.
    //
    // Current list:
    //
    // []
    //
    // Therefore:
    //
    // l.empty() == true
    //
    // condition will be TRUE.

    if (l.empty() == true)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        // This block will execute only when the list is NOT empty.
        //
        // Since our list is already empty,
        // this part will NOT execute.

        l.clear();

        cout << "List is Not Empty" << endl;
    }

    // ============================================================
    // IMPORTANT PROBLEM: front() ON AN EMPTY LIST
    // ============================================================

    // At this point, the list is EMPTY because we called:
    //
    // l.clear();
    //
    // Therefore:
    //
    // l = []
    //
    // Now this is INVALID:
    //
    // cout << l.front();
    //
    // front() expects the list to contain at least one element.
    //
    // Calling front() on an empty list results in
    // UNDEFINED BEHAVIOR.
    //
    // So these lines in the original code are WRONG:
    //
    // cout << l.front() << endl;
    // cout << l.front() << endl;

    // ============================================================
    // SAFE WAY TO USE front()
    // ============================================================

    // Before accessing front(), first check whether
    // the list is empty.

    if (!l.empty())
    {
        cout << "Front element: "
             << l.front() << endl;
    }
    else
    {
        cout << "Cannot access front(): List is empty"
             << endl;
    }

    // ============================================================
    // SAFE WAY TO USE back()
    // ============================================================

    // back() returns the LAST element.
    //
    // Just like front(), back() must NOT be called
    // on an empty list.

    if (!l.empty())
    {
        cout << "Back element: "
             << l.back() << endl;
    }
    else
    {
        cout << "Cannot access back(): List is empty"
             << endl;
    }

    // ============================================================
    // IMPORTANT DIFFERENCE:
    // empty() vs front() / back()
    // ============================================================

    // empty():
    //
    // Safe to call even when list is empty.
    //
    // l.empty()
    //
    // simply tells us whether the list has elements.

    // front():
    //
    // Returns first element.
    //
    // But list MUST NOT be empty.

    // back():
    //
    // Returns last element.
    //
    // But list MUST NOT be empty.

    // ============================================================
    // COMPLETE FLOW OF YOUR PROGRAM
    // ============================================================

    /*
        Initial:
        ------------------------------------------------------------
        l = [10, 20, 30, 40]
        size = 4


        push_back(10):
        ------------------------------------------------------------
        [10, 20, 30, 40, 10]
        size = 5


        push_back(20):
        ------------------------------------------------------------
        [10, 20, 30, 40, 10, 20]
        size = 6


        push_back(80):
        ------------------------------------------------------------
        [10, 20, 30, 40, 10, 20, 80]
        size = 7


        push_back(90):
        ------------------------------------------------------------
        [10, 20, 30, 40, 10, 20, 80, 90]
        size = 8


        pop_back():
        ------------------------------------------------------------
        [10, 20, 30, 40, 10, 20, 80]
        size = 7


        pop_front():
        ------------------------------------------------------------
        [20, 30, 40, 10, 20, 80]
        size = 6


        push_front(500):
        ------------------------------------------------------------
        [500, 20, 30, 40, 10, 20, 80]
        size = 7


        push_front(50):
        ------------------------------------------------------------
        [50, 500, 20, 30, 40, 10, 20, 80]
        size = 8


        clear():
        ------------------------------------------------------------
        []
        size = 0


        empty():
        ------------------------------------------------------------
        true

        Therefore:
        "List is Empty"
    */

    return 0;
}