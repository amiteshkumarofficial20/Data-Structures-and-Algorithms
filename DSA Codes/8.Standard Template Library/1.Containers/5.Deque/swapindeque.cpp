#include <iostream>
#include <deque>

using namespace std;

int main()
{
    // ============================================================
    // SWAP IN DEQUE
    // ============================================================
    //
    // swap() is used to EXCHANGE the contents of two deques.
    //
    // Suppose:
    //
    // first  = [10, 20, 30]
    // second = [100, 200, 300]
    //
    // After:
    //
    // first.swap(second);
    //
    // first  = [100, 200, 300]
    // second = [10, 20, 30]
    //
    // IMPORTANT:
    //
    // The two deque objects remain the same.
    // Only their CONTENTS are exchanged.

    // ============================================================
    // CREATING FIRST DEQUE
    // ============================================================

    // Create an empty deque of integers.

    deque<int> first;

    // Add elements to the BACK of first deque.

    first.push_back(10);
    // first:
    //
    // [10]

    first.push_back(20);
    // first:
    //
    // [10] [20]

    first.push_back(30);
    // first:
    //
    // [10] [20] [30]

    first.push_back(40);
    // first:
    //
    // [10] [20] [30] [40]

    // ============================================================
    // CREATING SECOND DEQUE
    // ============================================================

    deque<int> second;

    // Add elements to the second deque.

    second.push_back(100);
    // second:
    //
    // [100]

    second.push_back(200);
    // second:
    //
    // [100] [200]

    second.push_back(300);
    // second:
    //
    // [100] [200] [300]

    second.push_back(400);
    // second:
    //
    // [100] [200] [300] [400]

    // ============================================================
    // STATE BEFORE SWAP
    // ============================================================

    /*
        FIRST DEQUE:

        [10] [20] [30] [40]


        SECOND DEQUE:

        [100] [200] [300] [400]
    */

    // ============================================================
    // PRINTING BEFORE SWAP
    // ============================================================

    cout << "Before swap:" << endl;

    // Print first deque.

    cout << "First deque: ";

    for (int x : first)
    {
        cout << x << " ";
    }

    cout << endl;

    // Print second deque.

    cout << "Second deque: ";

    for (int x : second)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // swap() MEMBER FUNCTION
    // ============================================================

    // Syntax:
    //
    // first.swap(second);
    //
    // This exchanges the complete contents of first and second.
    //
    // BEFORE:
    //
    // first  = [10, 20, 30, 40]
    // second = [100, 200, 300, 400]
    //
    // AFTER:
    //
    // first  = [100, 200, 300, 400]
    // second = [10, 20, 30, 40]

    first.swap(second);

    // ============================================================
    // STATE AFTER SWAP
    // ============================================================

    /*
        FIRST DEQUE:

        [100] [200] [300] [400]


        SECOND DEQUE:

        [10] [20] [30] [40]
    */

    // ============================================================
    // PRINTING AFTER SWAP
    // ============================================================

    cout << "\nAfter swap:" << endl;

    // Print first deque after swap.

    cout << "First deque: ";

    for (int x : first)
    {
        cout << x << " ";
    }

    cout << endl;

    // Print second deque after swap.

    cout << "Second deque: ";

    for (int x : second)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // CHECKING SIZE
    // ============================================================

    // Before swap:
    //
    // first.size()  = 4
    // second.size() = 4
    //
    // After swap:
    //
    // first.size()  = 4
    // second.size() = 4
    //
    // In this example, both sizes are equal.
    // But their CONTENTS have changed.

    cout << "\nSize of first deque: "
         << first.size()
         << endl;

    cout << "Size of second deque: "
         << second.size()
         << endl;

    // ============================================================
    // SWAP WITH DIFFERENT SIZES
    // ============================================================
    //
    // swap() does NOT require both deques to have the same size.
    //
    // Example:
    //
    // deque<int> a = {1, 2};
    // deque<int> b = {10, 20, 30, 40};
    //
    // a.swap(b);
    //
    // After:
    //
    // a = {10, 20, 30, 40}
    // b = {1, 2}
    //
    // So the entire contents are exchanged,
    // including their sizes.

    // ============================================================
    // EXAMPLE WITH DIFFERENT SIZES
    // ============================================================

    deque<int> a = {1, 2};
    deque<int> b = {10, 20, 30, 40, 50};

    cout << "\nBefore second swap:" << endl;

    cout << "a: ";

    for (int x : a)
    {
        cout << x << " ";
    }

    cout << endl;

    cout << "b: ";

    for (int x : b)
    {
        cout << x << " ";
    }

    cout << endl;

    // Swap the contents.

    a.swap(b);

    cout << "After second swap:" << endl;

    cout << "a: ";

    for (int x : a)
    {
        cout << x << " ";
    }

    cout << endl;

    cout << "b: ";

    for (int x : b)
    {
        cout << x << " ";
    }

    cout << endl;

    // ============================================================
    // SIZE AFTER SWAPPING DIFFERENT-SIZE DEQUES
    // ============================================================

    // Before:
    //
    // a.size() = 2
    // b.size() = 5
    //
    // After:
    //
    // a.size() = 5
    // b.size() = 2

    cout << "Size of a after swap: "
         << a.size()
         << endl;

    cout << "Size of b after swap: "
         << b.size()
         << endl;

    // ============================================================
    // ANOTHER WAY TO SWAP
    // ============================================================

    // We can also use the standard C++ swap() function:
    //
    // swap(a, b);
    //
    // This performs the same content exchange.
    //
    // Example:
    //
    // swap(a, b);
    //
    // After this, a and b would swap again.
    //
    // We are NOT calling it here because that would undo
    // the previous swap.

    // ============================================================
    // swap() MEMBER FUNCTION vs std::swap()
    // ============================================================

    /*
        METHOD 1:
        ------------------------------------------------------------
        a.swap(b);


        METHOD 2:
        ------------------------------------------------------------
        swap(a, b);


        Both exchange the contents of the two deques.


        Before:

        a = [1, 2]
        b = [10, 20, 30]


        After:

        a = [10, 20, 30]
        b = [1, 2]
    */

    // ============================================================
    // VISUAL UNDERSTANDING
    // ============================================================

    /*
        BEFORE:

        first:
        [10] [20] [30] [40]

        second:
        [100] [200] [300] [400]


                    ↓
              first.swap(second)
                    ↓


        AFTER:

        first:
        [100] [200] [300] [400]

        second:
        [10] [20] [30] [40]
    */

    // ============================================================
    // IMPORTANT POINT
    // ============================================================
    //
    // swap() does NOT mean:
    //
    // "swap only the first elements"
    //
    // or:
    //
    // "swap only the last elements"
    //
    // It exchanges the COMPLETE contents of both deques.

    // ============================================================
    // COMMON MISTAKE
    // ============================================================

    /*
        Suppose:

        deque<int> a = {10, 20, 30};
        deque<int> b = {100, 200};

        a.swap(b);

        Correct result:

        a = {100, 200}
        b = {10, 20, 30}


        It does NOT mean:

        a = {200, 20, 30}
        b = {100, 10}

        ❌ Wrong idea.
    */

    // ============================================================
    // TIME COMPLEXITY
    // ============================================================
    //
    // Swapping containers is designed to be very efficient.
    //
    // For deque, swap is generally O(1) because it exchanges
    // the container's internal state rather than moving every
    // element individually.
    //
    // So conceptually:
    //
    // swap -> O(1)

    // ============================================================
    // FINAL CHEAT SHEET
    // ============================================================

    /*
        MEMBER FUNCTION:

        dq1.swap(dq2);


        STANDARD FUNCTION:

        swap(dq1, dq2);


        Example:

        deque<int> dq1 = {10, 20, 30};
        deque<int> dq2 = {100, 200};

        dq1.swap(dq2);


        BEFORE:

        dq1 = [10, 20, 30]
        dq2 = [100, 200]


        AFTER:

        dq1 = [100, 200]
        dq2 = [10, 20, 30]
    */

    return 0;
}