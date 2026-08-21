#include <iostream>
#include <stack>

using namespace std;

int main()
{
    // ============================================================
    // CREATING FIRST STACK
    // ============================================================

    // Creating an empty stack of integers.
    //
    // Stack follows LIFO:
    //
    // LIFO = Last In, First Out
    //
    // The element inserted last is removed first.

    stack<int> first;

    // ============================================================
    // PUSHING ELEMENTS INTO FIRST STACK
    // ============================================================

    first.push(10);
    // first:
    //
    // TOP
    //  ↓
    // [10]

    first.push(20);
    // first:
    //
    // TOP
    //  ↓
    // [20]
    // [10]

    first.push(30);
    // first:
    //
    // TOP
    //  ↓
    // [30]
    // [20]
    // [10]

    first.push(40);
    // first:
    //
    // TOP
    //  ↓
    // [40]
    // [30]
    // [20]
    // [10]

    // ============================================================
    // CREATING SECOND STACK
    // ============================================================

    // Creating another empty stack.

    stack<int> second;

    // ============================================================
    // PUSHING ELEMENTS INTO SECOND STACK
    // ============================================================

    second.push(100);

    // second:
    //
    // TOP
    //  ↓
    // [100]

    second.push(200);

    // second:
    //
    // TOP
    //  ↓
    // [200]
    // [100]

    second.push(300);

    // second:
    //
    // TOP
    //  ↓
    // [300]
    // [200]
    // [100]

    second.push(400);

    // second:
    //
    // TOP
    //  ↓
    // [400]
    // [300]
    // [200]
    // [100]

    // ============================================================
    // STATE BEFORE SWAP
    // ============================================================

    /*
        FIRST STACK

        TOP
         ↓
        [40]
        [30]
        [20]
        [10]


        SECOND STACK

        TOP
         ↓
        [400]
        [300]
        [200]
        [100]
    */

    // ============================================================
    // swap()
    // ============================================================

    // swap() exchanges the contents of two stacks.
    //
    // Syntax:
    //
    // first.swap(second);
    //
    // BEFORE SWAP:
    //
    // first  = [40, 30, 20, 10]
    // second = [400, 300, 200, 100]
    //
    //
    // AFTER SWAP:
    //
    // first  = [400, 300, 200, 100]
    // second = [40, 30, 20, 10]
    //
    // IMPORTANT:
    //
    // The two stack objects remain the same.
    // Only their contents are exchanged.

    first.swap(second);

    // ============================================================
    // PRINTING FIRST STACK AFTER SWAP
    // ============================================================

    cout << "First stack after swap: ";

    // stack does not provide begin() / end().
    //
    // So to print all elements, we use:
    //
    // top() + pop()
    //
    // BUT this would destroy the stack.
    //
    // Therefore, create a temporary copy.

    stack<int> temp1 = first;

    while (!temp1.empty())
    {
        // Print top element.

        cout << temp1.top() << " ";

        // Remove from temporary copy.

        temp1.pop();
    }

    cout << endl;

    // ============================================================
    // PRINTING SECOND STACK AFTER SWAP
    // ============================================================

    cout << "Second stack after swap: ";

    // Create a copy of second stack.

    stack<int> temp2 = second;

    while (!temp2.empty())
    {
        cout << temp2.top() << " ";

        temp2.pop();
    }

    cout << endl;

    // ============================================================
    // CHECKING SIZE AFTER SWAP
    // ============================================================

    // In this example both stacks contain 4 elements.
    //
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
    // Size remains the same because both stacks have equal size.
    // But their CONTENTS have been exchanged.

    cout << "Size of first stack: "
         << first.size() << endl;

    cout << "Size of second stack: "
         << second.size() << endl;

    // ============================================================
    // ANOTHER WAY TO SWAP
    // ============================================================

    // We can also use the standard swap() function:
    //
    // swap(first, second);
    //
    // This does the same thing as:
    //
    // first.swap(second);
    //
    // We are NOT calling it here because that would perform
    // another swap and return the stacks to their old contents.

    // ============================================================
    // VISUAL UNDERSTANDING
    // ============================================================

    /*
        BEFORE:

        first:

           TOP
            ↓
          [40]
          [30]
          [20]
          [10]


        second:

           TOP
            ↓
          [400]
          [300]
          [200]
          [100]


        ==========================================================

                      first.swap(second);

        ==========================================================


        AFTER:

        first:

           TOP
            ↓
          [400]
          [300]
          [200]
          [100]


        second:

           TOP
            ↓
          [40]
          [30]
          [20]
          [10]
    */

    return 0;
}