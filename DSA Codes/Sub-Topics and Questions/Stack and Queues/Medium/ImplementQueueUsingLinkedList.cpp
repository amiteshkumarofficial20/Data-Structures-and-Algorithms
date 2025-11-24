/*
===================================================================================================
    FILE: ImplementQueueUsingLinkedList.cpp
    TOPIC: Queue Implementation Using Linked List
===================================================================================================

📘 FULL PROBLEM STATEMENT
-------------------------
Implement a Queue using a Linked List.

The queue must support:

    1. Enqueue(x) → Insert element at rear
    2. Dequeue()  → Remove the element from the front
    3. Peek()     → Return front element without removing it
    4. Empty()    → Return true if queue is empty
    5. Size()     → Return number of elements

The queue works on **FIFO (First In First Out)** principle.

Compare this with Queue implementation using Array (Static vs Dynamic).

===================================================================================================
🆚 COMPARISON: ARRAY vs LINKED LIST IMPLEMENTATION
--------------------------------------------------

| Feature                      | Array Queue                           | Linked List Queue                             |
|-----------------------------|----------------------------------------|-----------------------------------------------|
| Memory Type                 | Static (fixed size)                    | Dynamic (grows until heap is full)            |
| Overflow                    | Yes, when max capacity reached         | No overflow unless heap memory ends           |
| Resizing                    | Not Possible                           | Automatic (dynamic allocation)                |
| Enqueue Time                | O(1) (Circular)                        | O(1)                                          |
| Dequeue Time                | O(1)                                   | O(1)                                          |
| Extra Memory Overhead       | No                                     | Yes (pointer per node)                        |
| Best For                    | Limited memory, predictable usage      | Flexible size, unpredictable input size       |

===================================================================================================
🪓 BRUTE FORCE APPROACH (ARRAY-BASED, NAIVE)
--------------------------------------------
INTUITION:
    Use an array. For each dequeue, shift all elements left → O(n).

STEPS:
    Enqueue(x):
        if full → overflow
        arr[end] = x
        end++

    Dequeue():
        ans = arr[0]
        shift all elements left
        size--

TIME COMPLEXITY:
    Enqueue → O(1)
    Dequeue → O(n)

WHY BAD?
    Shifting makes dequeue slow.

===================================================================================================
⚡ OPTIMAL APPROACH — LINKED LIST QUEUE
---------------------------------------

INTUITION:
    Use a Linked List where:
        Front → first element
        Rear  → last element

    Enqueue → insert at rear
    Dequeue → remove from front

DIAGRAM:

        FRONT                      REAR
          ↓                         ↓
        [10] → [20] → [30] → [40] → NULL

After Enqueue(50):

        [10] → [20] → [30] → [40] → [50]

After Dequeue():

        [20] → [30] → [40] → [50]

===================================================================================================
🧠 STEP-BY-STEP ALGORITHM
-------------------------

INITIALIZE:
    Front = NULL
    Rear = NULL
    size = 0

ENQUEUE(x):
    node = new Node(x)
    if queue empty:
        Front = Rear = node
    else:
        Rear->next = node
        Rear = node
    size++

DEQUEUE():
    if empty → return -1
    temp = Front
    ans = Front->val
    Front = Front->next
    delete temp
    size--
    return ans

PEEK():
    if empty → return -1
    return Front->val

EMPTY():
    return Front == NULL

SIZE():
    return size

===================================================================================================
📌 PSEUDOCODE (FULL)
--------------------

ENQUEUE(x):
    node = new Node(x)
    if Front == NULL:
        Front = Rear = node
    else:
        Rear.next = node
        Rear = node
    size++

DEQUEUE():
    if Front == NULL:
        return -1
    temp = Front
    ans = Front.val
    Front = Front.next
    delete temp
    size--
    return ans

===================================================================================================
⏳ TIME & SPACE COMPLEXITY
--------------------------

Operation      Time        Space
-----------------------------------------
Enqueue        O(1)        O(n)
Dequeue        O(1)        O(n)
Peek           O(1)        O(1)
Empty          O(1)        O(1)
Size           O(1)        O(1)

Notes:
    Linked List grows dynamically; hence total memory O(n).

===================================================================================================
*/

#include <iostream>
using namespace std;

// ============================================================================
//                       NODE STRUCTURE
// ============================================================================
class QueueNode
{
public:
    int val;
    QueueNode *next;

    QueueNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

// Global front and rear (optional, but kept to match your format)
QueueNode *Front = nullptr;
QueueNode *Rear = nullptr;

// ============================================================================
//                        QUEUE CLASS
// ============================================================================
class Queue
{
public:
    int size = 0;

    // Check if queue is empty
    bool Empty()
    {
        return Front == nullptr;
    }

    // Return front without removing
    int Peek()
    {
        if (Empty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }
        return Front->val;
    }

    // Insert at rear
    void Enqueue(int value)
    {
        QueueNode *Temp = new QueueNode(value);

        if (Temp == nullptr)
        {
            cout << "Queue is Full (Heap exhausted)\n";
            return;
        }

        if (Front == nullptr)
        {
            Front = Rear = Temp;
        }
        else
        {
            Rear->next = Temp;
            Rear = Temp;
        }

        cout << value << " Inserted into Queue\n";
        size++;
    }

    // Remove front element
    void Dequeue()
    {
        if (Front == nullptr)
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << Front->val << " Removed From Queue\n";
        QueueNode *Temp = Front;
        Front = Front->next;
        delete Temp;
        size--;
    }
};

// ============================================================================
//                                 MAIN
// ============================================================================
int main()
{

    cout << "==== TESTING QUEUE USING LINKED LIST ====\n\n";

    Queue q;

    // Testcase 1
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    cout << "Peek: " << q.Peek() << endl;
    cout << "Size: " << q.size << endl;

    // Testcase 2
    q.Dequeue();
    cout << "Peek after Dequeue: " << q.Peek() << endl;

    // Testcase 3
    q.Enqueue(40);
    q.Enqueue(50);

    cout << "\nDraining queue...\n";
    while (!q.Empty())
    {
        q.Dequeue();
    }

    // Underflow check
    q.Dequeue();

    return 0;
}
