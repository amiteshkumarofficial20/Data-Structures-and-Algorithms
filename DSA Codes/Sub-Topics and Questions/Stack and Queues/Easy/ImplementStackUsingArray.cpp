/*
===============================================================================
    FILE: ImplementStackUsingArray.cpp
    TITLE: Stack Implementation Using Array
===============================================================================

    📘 FULL PROBLEM STATEMENT
    -------------------------
    Implement a Stack using an array of fixed size (1000). The stack must
    support these operations:

        1. push(x) – Insert element x on the top
        2. pop()   – Remove and return the top element
        3. top()   – Return the top element (without removing)
        4. size()  – Return current number of elements
        5. Handle OVERFLOW and UNDERFLOW safely

    Initial state: TOP = -1 (Empty stack)

===============================================================================
    🪓 BRUTE FORCE APPROACH
    ------------------------
    IDEA:
        Insert at index 0 and SHIFT all elements right. For pop(), remove
        index 0 and SHIFT left.

    TIME COMPLEXITY:
        push  -> O(n)
        pop   -> O(n)

    Inefficient. Only used for understanding.
===============================================================================
    ⚡ OPTIMAL APPROACH (USING TOP POINTER)
    ---------------------------------------
    IDEA:
        Maintain a TOP index.

        - For push:  Increase TOP, add at arr[TOP]
        - For pop:   Return arr[TOP], decrease TOP
        - For top:   Return arr[TOP]
        - For size:  Return TOP + 1

    TIME COMPLEXITY:
        push  -> O(1)
        pop   -> O(1)
        top   -> O(1)
        size  -> O(1)

    SPACE COMPLEXITY: O(N)

===============================================================================
    🧠 INTUITION + DIAGRAM
    ----------------------

        Index: 0   1   2   3
        Stack: 5  10  23  50
        TOP ----------------^

    Last element (TOP) is always the first to be removed → LIFO

===============================================================================
    🧾 STEP-BY-STEP ALGORITHM
    --------------------------
    1. Initialize:
            TOP = -1
            SIZE = 1000
            Create array of SIZE

    2. PUSH(x):
            If TOP == SIZE-1 → Overflow
            Else TOP++
                 arr[TOP] = x

    3. POP():
            If TOP == -1 → Underflow
            Else x = arr[TOP]
                 TOP--
                 return x

    4. TOP():
            If TOP == -1 → Empty
            Else return arr[TOP]

    5. SIZE():
            return TOP + 1

===============================================================================
    📌 PSEUDOCODE
    --------------
    PUSH(x):
        if TOP == SIZE - 1:
            print OVERFLOW
        else:
            TOP = TOP + 1
            arr[TOP] = x

    POP():
        if TOP == -1:
            print UNDERFLOW
        else:
            x = arr[TOP]
            TOP = TOP - 1
            return x

===============================================================================
*/

#include <iostream>
using namespace std;

// ============================================================================
//                      STACK CLASS USING ARRAY
// ============================================================================

class Stack
{
private:
    int size;
    int top;
    int *arr;

public:
    // Constructor → Initialize stack
    Stack()
    {
        size = 1000;
        top = -1;
        arr = new int[size];
    }

    // PUSH operation (O(1))
    void push(int x)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow! Cannot push " << x << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    // POP operation (O(1))
    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow! Cannot pop.\n";
            return -1;
        }
        int x = arr[top];
        top--;
        return x;
    }

    // Return TOP element (O(1))
    int Top()
    {
        if (top == -1)
        {
            cout << "Stack is Empty!\n";
            return -1;
        }
        return arr[top];
    }

    // Return current size (O(1))
    int Size()
    {
        return top + 1;
    }
};

// ============================================================================
//                              MAIN FUNCTION
// ============================================================================

int main()
{

    cout << "=== STACK USING ARRAY (Testing Multiple Cases) ===\n\n";

    Stack s;

    // Testcase 1
    cout << "Pushing 10, 20, 30...\n";
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.Top() << endl;   // 30
    cout << "Size: " << s.Size() << endl; // 3

    // Testcase 2
    cout << "\nPopping...\n";
    cout << "Popped: " << s.pop() << endl;  // 30
    cout << "Top now: " << s.Top() << endl; // 20

    // Testcase 3
    cout << "\nPopping all...\n";
    cout << s.pop() << endl; // 20
    cout << s.pop() << endl; // 10

    cout << "Trying to pop from empty stack:\n";
    s.pop(); // Underflow

    return 0;
}