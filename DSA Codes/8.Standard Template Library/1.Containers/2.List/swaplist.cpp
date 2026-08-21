#include <iostream>
#include <list>
using namespace std;

int main()
{
    // ============================================================
    // CREATING FIRST LIST
    // ============================================================

    // Creating an empty list named 'first'.
    //
    // Since the type is list<int>,
    // this list can store integer values.
    //
    // Initially:
    //
    // first = []
    list<int> first;

    // ============================================================
    // ADDING ELEMENTS TO FIRST LIST
    // ============================================================

    // push_back() adds an element at the END of the list.

    first.push_back(10);
    // first:
    //
    // 10

    first.push_back(20);
    // first:
    //
    // 10 <-> 20

    first.push_back(30);
    // first:
    //
    // 10 <-> 20 <-> 30

    first.push_back(40);
    // first:
    //
    // 10 <-> 20 <-> 30 <-> 40

    // ============================================================
    // CREATING SECOND LIST
    // ============================================================

    // Creating another empty list named 'second'.

    list<int> second;

    // ============================================================
    // ADDING ELEMENTS TO SECOND LIST
    // ============================================================

    second.push_back(101);
    // second:
    //
    // 101

    second.push_back(201);
    // second:
    //
    // 101 <-> 201

    second.push_back(301);
    // second:
    //
    // 101 <-> 201 <-> 301

    second.push_back(401);
    // second:
    //
    // 101 <-> 201 <-> 301 <-> 401

    // ============================================================
    // STATE BEFORE SWAP
    // ============================================================

    // At this point:
    //
    // first:
    //
    // 10 <-> 20 <-> 30 <-> 40
    //
    //
    // second:
    //
    // 101 <-> 201 <-> 301 <-> 401
    //
    //
    // We now want to EXCHANGE the contents of both lists.

    // ============================================================
    // swap()
    // ============================================================

    // swap() exchanges the contents of two lists.
    //
    // Syntax:
    //
    // first.swap(second);
    //
    // Before swap:
    //
    // first  = [10, 20, 30, 40]
    // second = [101, 201, 301, 401]
    //
    // After swap:
    //
    // first  = [101, 201, 301, 401]
    // second = [10, 20, 30, 40]
    //
    // IMPORTANT:
    //
    // The lists themselves are NOT destroyed.
    // Their contents are simply exchanged.

    first.swap(second);

    // ============================================================
    // PRINTING AFTER SWAP
    // ============================================================

    cout << "After swap:" << endl;

    // Print first list.

    cout << "First list: ";

    for (int x : first)
    {
        cout << x << " ";
    }

    cout << endl;

    // Print second list.

    cout << "Second list: ";

    for (int x : second)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // CHECKING SIZE AFTER SWAP
    // ============================================================

    // Before swap:
    //
    // first.size()  = 4
    // second.size() = 4
    //
    // In this example both have the same size,
    // but their values are different.
    //
    // After swap:
    //
    // first.size()  = 4
    // second.size() = 4
    //
    // Size remains 4 for both,
    // but the CONTENTS have changed.

    cout << "Size of first: "
         << first.size() << endl;

    cout << "Size of second: "
         << second.size() << endl;

    // ============================================================
    // UNDERSTANDING SWAP VISUALLY
    // ============================================================

    /*
        BEFORE SWAP
        ============================================================

        first:

        10 <-> 20 <-> 30 <-> 40


        second:

        101 <-> 201 <-> 301 <-> 401


        ============================================================
        AFTER:

        first.swap(second);
        ============================================================


        first:

        101 <-> 201 <-> 301 <-> 401


        second:

        10 <-> 20 <-> 30 <-> 40
    */

    // ============================================================
    // ANOTHER WAY TO SWAP
    // ============================================================

    // We can also use the standard swap() function:
    //
    // swap(first, second);
    //
    // This also exchanges their contents.
    //
    // Example:
    //
    // swap(first, second);
    //
    // After this, the lists would swap again and return
    // to their original contents.
    //
    // We are NOT calling it here because that would perform
    // another swap.

    return 0;
}