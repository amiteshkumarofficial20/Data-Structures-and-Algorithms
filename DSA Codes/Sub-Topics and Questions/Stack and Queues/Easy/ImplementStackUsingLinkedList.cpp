/*
============================================================================================
    FILE: ImplementStackUsingLinkedList.cpp
    TOPIC: Stack Implementation Using Linked List
============================================================================================

📘 FULL PROBLEM STATEMENT
-------------------------
Implement a **Stack using a Linked List**.
The stack must support the following operations:

    1. push(x)      → Insert an element at the top of the stack
    2. pop()        → Remove the top element and return it
    3. top()        → Return the top-most element without removing it
    4. size()       → Return current size of the stack
    5. isEmpty()    → Return true if stack is empty

The stack must follow **LIFO — Last In First Out**.

Do NOT use STL stack.

============================================================================================
🪓 BRUTE FORCE APPROACH (NOT GOOD)
----------------------------------
INTUITION:
    Use an array and insert/delete only at index 0.

BRUTE STEPS:
    push(x):
        shift all elements right → arr[0] = x
    pop():
        read arr[0], shift all elements left

PSEUDOCODE:
    PUSH_BRUTE(x):
        shift right O(n)
        arr[0] = x

    POP_BRUTE():
        ans = arr[0]
        shift left O(n)
        return ans

TIME COMPLEXITY:
    push → O(n)
    pop  → O(n)

WHY BAD?
    Frequent shifting makes operations slow.

============================================================================================
⚡ OPTIMAL APPROACH — USE LINKED LIST
--------------------------------------
INTUITION:
    Treat the **head of linked list as TOP of stack**.

    push() → Insert at head
    pop()  → Remove from head

DIAGRAM:
                TOP
                 ↓
        [50] → [40] → [30] → [20]
         ↑
       stack top (head)

This keeps ALL operations O(1).

============================================================================================
🧠 STEP-BY-STEP ALGORITHM
-------------------------

INITIALIZE:
    top = NULL
    size = 0

PUSH(x):
    create newNode(x)
    newNode->next = top
    top = newNode
    size++

POP():
    if top == NULL → return -1 (underflow)
    temp = top
    ans = top->data
    top = top->next
    delete temp
    size--
    return ans

TOP():
    if top == NULL → return -1
    return top->data

SIZE():
    return size

isEmpty():
    return (top == NULL)

============================================================================================
📌 PSEUDOCODE (FULL)
--------------------

PUSH(x):
    node = new Node(x)
    node.next = top
    top = node
    size++

POP():
    if top == NULL:
        return -1
    temp = top
    ans  = top.data
    top  = top.next
    delete temp
    size--
    return ans

TOP():
    if top == NULL:
        return -1
    return top.data

============================================================================================
⏳ TIME & SPACE COMPLEXITY
--------------------------

Operation      Time        Space
-----------------------------------
push           O(1)         O(n)
pop            O(1)         O(n)
top            O(1)         O(n)
size           O(1)         O(1)
isEmpty        O(1)         O(1)

============================================================================================
*/

#include <iostream>
using namespace std;

// ============================================================================
//                        NODE STRUCTURE
// ============================================================================
struct StackNode
{
    int data;
    StackNode *next;

    StackNode(int d)
    {
        data = d;
        next = NULL;
    }
};

// ============================================================================
//                        STACK CLASS USING LINKED LIST
// ============================================================================
class Stack
{
private:
    StackNode *topNode;
    int sz;

public:
    // Constructor
    Stack()
    {
        topNode = NULL;
        sz = 0;
    }

    // PUSH operation
    void push(int x)
    {
        StackNode *element = new StackNode(x);
        element->next = topNode;
        topNode = element;
        sz++;
        cout << "Pushed: " << x << endl;
    }

    // POP operation
    int pop()
    {
        if (topNode == NULL)
        {
            cout << "Stack Underflow! Cannot pop.\n";
            return -1;
        }
        int value = topNode->data;
        StackNode *temp = topNode;
        topNode = topNode->next;
        delete temp;
        sz--;
        return value;
    }

    // TOP operation
    int top()
    {
        if (topNode == NULL)
        {
            cout << "Stack is Empty!\n";
            return -1;
        }
        return topNode->data;
    }

    // SIZE operation
    int size()
    {
        return sz;
    }

    // EMPTY check
    bool isEmpty()
    {
        return topNode == NULL;
    }

    // Print entire stack (debug)
    void print()
    {
        StackNode *curr = topNode;
        cout << "Stack (top to bottom): ";
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }
};

// ============================================================================
//                                  MAIN
// ============================================================================
int main()
{

    cout << "=== TESTING STACK USING LINKED LIST ===\n\n";

    Stack s;

    // Testcase 1
    s.push(10);
    s.push(20);
    s.push(30);
    s.print();

    cout << "Top Element: " << s.top() << endl;
    cout << "Size: " << s.size() << endl;

    // Testcase 2
    cout << "\nPop: " << s.pop() << endl;
    cout << "Top Now: " << s.top() << endl;

    // Testcase 3
    cout << "\nEmptying stack...\n";
    while (!s.isEmpty())
    {
        cout << s.pop() << " ";
    }
    cout << endl;

    cout << "Trying to pop from empty: " << s.pop() << endl;

    return 0;
}
