/*
====================================================================================================
    FILE: LC232_ImplementQueueUsingStacks.cpp
    LEETCODE PROBLEM: 232 — Implement Queue using Stacks
    TOPIC: Data Structure Simulation (Stack → Queue)
====================================================================================================

📘 FULL PROBLEM STATEMENT
-------------------------
Implement a **FIFO Queue** using **two LIFO Stacks**.

Class: StackQueue
Operations:
    • push(int x)   → Insert element at back of queue
    • pop()         → Remove and return front element
    • peek()        → Return front element without removing
    • isEmpty()     → Return true/false

Rules:
    - You may ONLY use stack operations:
        push(), pop(), top(), size(), empty()
    - You may use **two** stacks
    - Push and Pop should satisfy queue FIFO order

===========================================================================================
🪓 BRUTE FORCE APPROACH (Push = O(N), Pop = O(1))
-------------------------------------------------

INTUITION:
    Maintain two stacks:
        st1 → main stack (queue order)
        st2 → helper

    For push(x):
        1. Move all elements from st1 → st2
        2. Push x into st1
        3. Move all elements back st2 → st1

    This ensures st1 stores items in queue-order.

PSEUDOCODE:
    push(x):
        while st1 not empty:
            st2.push(st1.top())
            st1.pop()
        st1.push(x)
        while st2 not empty:
            st1.push(st2.top())
            st2.pop()

    pop(): return st1.pop()
    peek(): return st1.top()

TIME:
    push → O(N)
    pop  → O(1)
    peek → O(1)

WHY SUBOPTIMAL?
    Too much movement on every push.

===========================================================================================
⚡ OPTIMAL APPROACH (Amortized O(1) Using 2 Stacks)
--------------------------------------------------

INTUITION:
    Use two stacks:
        input  → receives all pushes
        output → used for pops (reverse order)

    FIFO simulation:
        When output is empty:
            move every element input → output
            (this reverses order so front is on top)

DIAGRAM:
    input stack (top on right):
        [3,2,1]   push 3,2,1

    Move to output:
        output: [1,2,3]   → front = 1

    pop() removes 1 first ✔

===========================================================================================
📊 COMPARISON TABLE
--------------------

| Feature                        | Push O(N) Brute | Optimal O(1) Push |
|--------------------------------|------------------|--------------------|
| push(x)                        | O(N)             | O(1)               |
| pop()                          | O(1)             | O(N) (amortized O(1)) |
| peek()                         | O(1)             | O(N) (amortized O(1)) |
| Extra Stack                    | Yes              | Yes                |
| Overall Performance            | ❌ Slower         | ✅ Faster          |

===========================================================================================
🧠 STEP-BY-STEP ALGORITHM (Optimal)
------------------------------------

PUSH(x):
    input.push(x)

POP():
    if output empty:
        while input not empty:
            output.push(input.top())
            input.pop()
    return output.pop()

PEEK():
    if output empty:
        while input not empty:
            output.push(input.top())
            input.pop()
    return output.top()

isEmpty():
    return input.empty() && output.empty()

===========================================================================================
📌 PSEUDOCODE
--------------

PUSH(x):
    input.push(x)

POP():
    if output empty:
        move all elements from input to output
    return output.pop()

PEEK():
    if output empty:
        move all elements from input to output
    return output.top()

isEmpty():
    return input.empty() and output.empty()

===========================================================================================
⏳ TIME & SPACE COMPLEXITY
---------------------------

Operation     Time                   Space
-------------------------------------------------
push          O(1)                   O(n)
pop           O(1) amortized         O(n)
peek          O(1) amortized         O(n)
isEmpty       O(1)                   O(1)

===========================================================================================
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// ============================================================================
//                         OPTIMAL QUEUE USING TWO STACKS
// ============================================================================
class StackQueue
{
public:
    stack<int> input, output;

    StackQueue() {}

    // Push element to back of queue
    void push(int x)
    {
        input.push(x);
    }

    // Pop front element
    int pop()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        if (output.empty())
        {
            cout << "Queue is empty, cannot pop.\n";
            return -1;
        }
        int x = output.top();
        output.pop();
        return x;
    }

    // Return front element
    int peek()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        if (output.empty())
        {
            cout << "Queue is empty, cannot peek.\n";
            return -1;
        }
        return output.top();
    }

    // Check if queue empty
    bool isEmpty()
    {
        return input.empty() && output.empty();
    }
};

// ============================================================================
//                                   MAIN
// ============================================================================
int main()
{

    cout << "=== TESTING QUEUE USING STACKS (LC232) ===\n\n";

    StackQueue q;

    // Testcases
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Peek: " << q.peek() << endl; // 10
    cout << "Pop: " << q.pop() << endl;   // 10

    q.push(40);
    q.push(50);

    cout << "Peek: " << q.peek() << endl; // 20

    cout << "\nDraining queue:\n";
    while (!q.isEmpty())
    {
        cout << q.pop() << " ";
    }
    cout << endl;

    cout << "Pop empty: " << q.pop() << endl; // Underflow test

    return 0;
}
