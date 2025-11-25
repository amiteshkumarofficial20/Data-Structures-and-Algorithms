/*
====================================================================================================
     FILE: ImplementStackUsingSingleQueue.cpp
    LEETCODE PROBLEM: 225 — Implement Stack using Queues
====================================================================================================

📘 FULL PROBLEM STATEMENT
-------------------------
Implement a **LIFO Stack** using **only one FIFO Queue**.

Class: QueueStack
Operations required:
    1. push(x)    → Push element onto stack
    2. pop()      → Remove and return top element
    3. top()      → Return top without removing
    4. isEmpty()  → Return true if stack is empty

Constraints:
- Use only ONE queue (no list, no array explicitly).
- Stack follows LIFO behavior.
- Queue follows FIFO behavior.

Goal:
Convert FIFO queue behavior → LIFO stack behavior.

====================================================================================================
🪓 BRUTE FORCE APPROACH
------------------------
Option 1:
    Use two queues: q1 for push, q2 for pop/top helper.
    This uses extra space and more movement.

    PUSH(x):
        enqueue into q1

    POP():
        move n-1 items from q1 → q2
        pop last element from q1
        swap(q1, q2)

TIME COMPLEXITY:
    push → O(1)
    pop  → O(n)

SPACE:
    O(n) + O(n)

WHY NOT IDEAL?
    Uses two queues → not allowed by problem.

====================================================================================================
⚡ OPTIMAL APPROACH — SINGLE QUEUE ROTATION METHOD
--------------------------------------------------

INTUITION:
    A stack requires that the most recent element inserted is removed first.

    Queue always removes the oldest element first.

    So: **After inserting x → rotate all previous elements behind it.**

    Example queue flow:

    Before push(50):
        FRONT → [40, 30, 20, 10]

    After push(50):
        Insert at rear:
            [40, 30, 20, 10, 50]

        Rotate previous elements to the back:
            pop(40) push(40)
            pop(30) push(30)
            pop(20) push(20)
            pop(10) push(10)

    Now queue becomes:

        FRONT → [50, 40, 30, 20, 10]

    So:
        front = top of stack ✔

====================================================================================================
📊 COMPARISON TABLE
-------------------

| Feature                | Using 1 Queue (Optimal) | Using 2 Queues (Brute) |
|------------------------|--------------------------|--------------------------|
| Space                  | O(n)                     | O(n) + extra queue       |
| Push Complexity        | O(n)                     | O(1)                     |
| Pop Complexity         | O(1)                     | O(n)                     |
| Extra Data Structure   | No                       | Yes                      |
| Simplicity             | High                     | Medium                   |

====================================================================================================
🧠 STEP-BY-STEP ALGORITHM
--------------------------

PUSH(x):
    s = size of queue
    enqueue x
    repeat s times:
        move q.front() to rear
    Now x is at front → becomes top of stack

POP():
    ans = q.front()
    q.pop()
    return ans

TOP():
    return q.front()

isEmpty():
    return q.empty()

====================================================================================================
📌 PSEUDOCODE
--------------

PUSH(x):
    s = q.size()
    q.push(x)
    loop i = 1 to s:
        q.push(q.front())
        q.pop()

POP():
    ans = q.front()
    q.pop()
    return ans

TOP():
    return q.front()

isEmpty():
    return (queue is empty)

====================================================================================================
⏳ TIME & SPACE COMPLEXITY
---------------------------

Operation     Time         Space
----------------------------------------
push          O(n)          O(n)
pop           O(1)          O(n)
top           O(1)          O(n)
isEmpty       O(1)          O(1)

====================================================================================================
*/

#include <iostream>
#include <queue>
using namespace std;

// ============================================================================
//                       IMPLEMENT STACK USING 1 QUEUE
// ============================================================================
class QueueStack
{
    queue<int> q; // Only one queue used

public:
    // Push element onto stack
    void push(int x)
    {
        int s = q.size(); // number of existing elements
        q.push(x);        // insert new element

        // Rotate existing elements behind x
        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }

        cout << "Pushed: " << x << endl;
    }

    // Pop top element
    int pop()
    {
        if (q.empty())
        {
            cout << "Stack Underflow!\n";
            return -1;
        }
        int val = q.front();
        q.pop();
        return val;
    }

    // Return top element
    int top()
    {
        if (q.empty())
        {
            cout << "Stack Empty!\n";
            return -1;
        }
        return q.front();
    }

    // Check empty
    bool isEmpty()
    {
        return q.empty();
    }
};

// ============================================================================
//                                   MAIN
// ============================================================================
int main()
{
    cout << "=== STACK USING SINGLE QUEUE ===\n\n";

    QueueStack st;

    // Testcase 1
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl; // 30
    cout << "Pop: " << st.pop() << endl; // 30

    // Testcase 2
    st.push(40);
    st.push(50);

    cout << "Top: " << st.top() << endl; // 50

    cout << "\nDraining stack:\n";
    while (!st.isEmpty())
    {
        cout << st.pop() << " ";
    }
    cout << endl;

    // Underflow check
    cout << "Pop on empty: " << st.pop() << endl;

    return 0;
}
