/*
==========================================================================================
    FILE:
    1ImplementQueueUsingArray.cpp
    TOPIC: Queue Implementation Using Array
==========================================================================================

📘 FULL PROBLEM STATEMENT
-------------------------
Implement a Queue using an array. The queue must support:

    1. push(x) → Insert at the end
    2. pop() → Remove element from the front
    3. top() → Front element
    4. size() → Current number of elements
    5. Circular handling (when end or start crosses array bounds)
    6. Handle Queue Overflow and Underflow

The queue operates in FIFO order → First In First Out.

Constraints:
- Maximum size = N (given in constructor)
- Do NOT use STL queue.

==========================================================================================
🪓 BRUTE FORCE APPROACH
------------------------
INTUITION:
    Use a normal array. For pop(), shift every element one step left.
    This ensures front always stays at index 0.

ALGORITHM (Brute):
    push(x):
        if full → overflow
        arr[size] = x
        size++

    pop():
        if empty → underflow
        ans = arr[0]
        shift all elements left
        size--

TIME COMPLEXITY:
    push → O(1)
    pop  → O(n)   (because of shifting)

SPACE COMPLEXITY: O(n)

WHY NOT GOOD?
    Because shifting makes pop extremely slow.

==========================================================================================
⚡ OPTIMAL APPROACH — CIRCULAR QUEUE
-----------------------------------
INTUITION:
    Use a circular array with:
        start → index of front element
        end   → index of last element
        currSize → number of active elements

    After popping, do NOT shift elements.
    Instead, increment start using:

            start = (start + 1) % maxSize

    Similarly:

            end = (end + 1) % maxSize

    This avoids shifting → O(1) operations.

DIAGRAM (Circular Indexing):
--------------------------------

    Array index: 0 1 2 3 4  (maxSize = 5)

    Suppose queue has:
        [_, 10, 20, 30, _]
                  ↑    ↑
                start  end

    After pop() → remove 10
    start = (start + 1) % 5

    Now:
        [_, _, 20, 30, _]
                    ↑   ↑
                 start end

==========================================================================================
🧠 STEP-BY-STEP ALGORITHM (OPTIMAL)
-----------------------------------

INITIALIZE(maxSize):
    Create array of maxSize
    start = -1
    end = -1
    currSize = 0

PUSH(x):
    if currSize == maxSize → overflow
    if end == -1:
        start = 0
        end = 0
    else:
        end = (end + 1) % maxSize
    arr[end] = x
    currSize++

POP():
    if start == -1 → underflow
    ans = arr[start]
    if currSize == 1:
        start = end = -1
    else:
        start = (start + 1) % maxSize
    currSize--
    return ans

TOP():
    if start == -1 → empty
    return arr[start]

SIZE():
    return currSize

==========================================================================================
📌 PSEUDOCODE (FULL)
--------------------

PUSH(x):
    if currSize == maxSize:
        print "Overflow"
        exit
    if end == -1:
        start = 0
        end = 0
    else:
        end = (end + 1) % maxSize
    arr[end] = x
    currSize++

POP():
    if start == -1:
        print "Underflow"
        exit
    x = arr[start]
    if currSize == 1:
        start = -1
        end = -1
    else:
        start = (start + 1) % maxSize
    currSize--
    return x

TOP():
    if start == -1:
        print "Empty"
        exit
    return arr[start]

==========================================================================================
⏳ TIME & SPACE COMPLEXITY
---------------------------

Operation      Time        Space
-----------------------------------
push           O(1)         O(n)
pop            O(1)         O(n)
top            O(1)         O(n)
size           O(1)         O(1)

==========================================================================================
*/

#include <iostream>
using namespace std;

// ============================================================================
//                           QUEUE CLASS (CIRCULAR)
// ============================================================================

class Queue
{
    int *arr;
    int start, end, currSize, maxSize;

public:
    // Constructors
    Queue(int maxSize = 16)
    {
        this->maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    // PUSH (enqueue) - O(1)
    void push(int x)
    {
        if (currSize == maxSize)
        {
            cout << "Queue is full! Cannot push " << x << endl;
            return;
        }

        if (end == -1)
        { // first element
            start = end = 0;
        }
        else
        {
            end = (end + 1) % maxSize;
        }

        arr[end] = x;
        currSize++;

        cout << "Pushed: " << x << endl;
    }

    // POP (dequeue) - O(1)
    int pop()
    {
        if (start == -1)
        {
            cout << "Queue is empty! Cannot pop.\n";
            return -1;
        }

        int popped = arr[start];

        if (currSize == 1)
        {
            start = end = -1;
        }
        else
        {
            start = (start + 1) % maxSize;
        }

        currSize--;
        return popped;
    }

    // FRONT element - O(1)
    int top()
    {
        if (start == -1)
        {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[start];
    }

    // SIZE of queue
    int size()
    {
        return currSize;
    }
};

// ============================================================================
//                            MAIN FUNCTION
// ============================================================================

int main()
{

    cout << "=== TESTING QUEUE USING ARRAY (CIRCULAR QUEUE) ===\n\n";

    Queue q(5);

    // Testcase 1
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Top element: " << q.top() << endl; // 10
    cout << "Size: " << q.size() << endl;       // 3

    // Testcase 2
    cout << "\nPop: " << q.pop() << endl;   // 10
    cout << "Top now: " << q.top() << endl; // 20

    // Testcase 3 — Test wrap-around (circular behavior)
    q.push(40);
    q.push(50);
    q.push(60); // Should fill last spot (wrap-around)

    cout << "\nPop: " << q.pop() << endl;   // 20
    cout << "Top now: " << q.top() << endl; // 30

    // Testcase 4 — Pop all
    cout << "\nEmptying queue...\n";
    while (q.size() > 0)
    {
        cout << q.pop() << " ";
    }
    cout << endl;

    // Underflow check
    q.pop();

    return 0;
}
