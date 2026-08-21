#include <iostream>
#include <stack>

using namespace std;

int main()
{
    // ============================================================
    // CREATING A STACK
    // ============================================================

    // stack<int> st;
    //
    // This creates an EMPTY stack of integers.
    //
    // A stack follows the LIFO principle:
    //
    // LIFO = Last In, First Out
    //
    // Matlab:
    //
    // Jo element sabse last mein stack mein enter karega,
    // wahi sabse pehle remove hoga.
    //
    // Initially:
    //
    // st = []
    //
    stack<int> st;

    // ============================================================
    // PUSHING ELEMENTS INTO STACK
    // ============================================================

    // push() adds an element at the TOP of the stack.

    st.push(10);

    // Stack:
    //
    // TOP
    //  ↓
    // [10]

    st.push(20);

    // 20 top par add hua.
    //
    // Stack:
    //
    // TOP
    //  ↓
    // [20]
    // [10]

    st.push(30);

    // Stack:
    //
    // TOP
    //  ↓
    // [30]
    // [20]
    // [10]

    st.push(40);

    // Stack:
    //
    // TOP
    //  ↓
    // [40]
    // [30]
    // [20]
    // [10]

    st.push(50);

    // Stack:
    //
    // TOP
    //  ↓
    // [50]
    // [40]
    // [30]
    // [20]
    // [10]
    //
    // 50 was inserted LAST,
    // so 50 is currently at the TOP.

    // ============================================================
    // size()
    // ============================================================

    // size() returns the number of elements currently
    // present in the stack.
    //
    // Current stack:
    //
    // [50]
    // [40]
    // [30]
    // [20]
    // [10]
    //
    // Total elements = 5

    cout << "Size of Stack is: "
         << st.size()
         << endl;

    // ============================================================
    // FIRST pop()
    // ============================================================

    // pop() removes the element from the TOP of the stack.
    //
    // IMPORTANT:
    //
    // pop() does NOT return the removed value.
    //
    // Current stack:
    //
    // TOP
    //  ↓
    // [50]
    // [40]
    // [30]
    // [20]
    // [10]
    //
    // So 50 will be removed.

    st.pop();

    // After pop():
    //
    // TOP
    //  ↓
    // [40]
    // [30]
    // [20]
    // [10]
    //
    // Number of elements = 4

    // ============================================================
    // size() AFTER FIRST pop()
    // ============================================================

    cout << "Size of Stack is: "
         << st.size()
         << endl;

    // Output:
    //
    // Size of Stack is: 4

    // ============================================================
    // top()
    // ============================================================

    // top() returns the element currently at the TOP.
    //
    // Current stack:
    //
    // TOP
    //  ↓
    // [40]
    // [30]
    // [20]
    // [10]
    //
    // Therefore:
    //
    // st.top() = 40

    cout << "Top of Stack is: "
         << st.top()
         << endl;

    // ============================================================
    // SECOND pop()
    // ============================================================

    // Again, pop() removes the TOP element.
    //
    // Current top = 40
    //
    // So 40 will be removed.

    st.pop();

    // After second pop():
    //
    // TOP
    //  ↓
    // [30]
    // [20]
    // [10]
    //
    // Number of elements = 3

    // ============================================================
    // size() AFTER SECOND pop()
    // ============================================================

    cout << "Size of Stack is: "
         << st.size()
         << endl;

    // Output:
    //
    // Size of Stack is: 3

    // ============================================================
    // top() AFTER SECOND pop()
    // ============================================================

    // Current stack:
    //
    // TOP
    //  ↓
    // [30]
    // [20]
    // [10]
    //
    // Therefore:
    //
    // st.top() = 30

    cout << "Top of Stack is: "
         << st.top()
         << endl;

    // ============================================================
    // empty()
    // ============================================================

    // empty() checks whether the stack contains zero elements.
    //
    // It returns:
    //
    // true  -> stack is empty
    // false -> stack is NOT empty
    //
    // Current stack:
    //
    // [30]
    // [20]
    // [10]
    //
    // Stack contains 3 elements.
    //
    // Therefore:
    //
    // st.empty() = false

    if (st.empty())
    {
        // This block will execute only if the stack
        // contains zero elements.

        cout << "Stack is Empty" << endl;
    }
    else
    {
        // Since stack currently contains:
        //
        // 30, 20, 10
        //
        // the stack is NOT empty.

        cout << "Stack is not Empty" << endl;
    }

    // ============================================================
    // COMPLETE FLOW OF THE PROGRAM
    // ============================================================

    /*
        ------------------------------------------------------------
        Initial stack
        ------------------------------------------------------------

        st = []


        ------------------------------------------------------------
        st.push(10)
        ------------------------------------------------------------

        [10]

        size = 1


        ------------------------------------------------------------
        st.push(20)
        ------------------------------------------------------------

        [20]
        [10]

        size = 2


        ------------------------------------------------------------
        st.push(30)
        ------------------------------------------------------------

        [30]
        [20]
        [10]

        size = 3


        ------------------------------------------------------------
        st.push(40)
        ------------------------------------------------------------

        [40]
        [30]
        [20]
        [10]

        size = 4


        ------------------------------------------------------------
        st.push(50)
        ------------------------------------------------------------

        [50]
        [40]
        [30]
        [20]
        [10]

        size = 5


        ------------------------------------------------------------
        First pop()
        ------------------------------------------------------------

        50 removed.

        [40]
        [30]
        [20]
        [10]

        size = 4

        top = 40


        ------------------------------------------------------------
        Second pop()
        ------------------------------------------------------------

        40 removed.

        [30]
        [20]
        [10]

        size = 3

        top = 30


        ------------------------------------------------------------
        empty()
        ------------------------------------------------------------

        Stack is NOT empty.

        Because:

        size = 3
    */

    // ============================================================
    // FINAL OUTPUT
    // ============================================================

    /*
        Size of Stack is: 5
        Size of Stack is: 4
        Top of Stack is: 40
        Size of Stack is: 3
        Top of Stack is: 30
        Stack is not Empty
    */

    return 0;
}