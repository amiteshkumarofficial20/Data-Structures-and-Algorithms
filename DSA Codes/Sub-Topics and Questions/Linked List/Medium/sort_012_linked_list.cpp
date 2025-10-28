/*
===========================================================================================================
🔥 FILE: sort_012_linked_list.cpp
🎯 PROBLEM: Sort a Linked List of 0s, 1s, and 2s (GFG Problem #100 / Striver SDE Sheet)
💡 DIFFICULTY: Medium
👨‍💻 AUTHOR: Striver-inspired full-detailed version by ChatGPT
===========================================================================================================

📝 PROBLEM STATEMENT:
Given the head of a singly linked list consisting of only 0, 1, or 2, sort the linked list in ascending order.
Do this IN-PLACE, i.e., by rearranging links or node data (no extra list creation).

Example 1:
Input  : head → 1 → 0 → 2 → 0 → 1 → NULL
Output : head → 0 → 0 → 1 → 1 → 2 → NULL

Example 2:
Input  : head → 1 → 1 → 1 → 0 → NULL
Output : head → 0 → 1 → 1 → 1 → NULL
*/

// ===========================================================================================================
// 🔍 APPROACH 1: Data Replacement (Counting Method)
// -----------------------------------------------------------------------------------------------------------
// 💡 INTUITION:
// ---------------------------------------------
// Think of it like the counting sort technique.

// - Since the linked list only contains 3 distinct values (0, 1, 2),
//   we can simply **count** how many 0s, 1s, and 2s exist.
// - Then, traverse the list again and **overwrite** the node values
//   in sorted order (first all 0s, then 1s, then 2s).

// 👉 We are not touching the node connections (links),
//    only replacing the data values.

// 🧠 ALGORITHM:
// ---------------------------------------------
// 1️⃣ Initialize three counters: `count0`, `count1`, `count2` = 0.
// 2️⃣ Traverse the linked list once:
//        - For each node:
//            if data == 0 → count0++
//            if data == 1 → count1++
//            if data == 2 → count2++
// 3️⃣ Now traverse the list again:
//        - Replace first `count0` nodes with 0
//        - Replace next `count1` nodes with 1
//        - Replace remaining `count2` nodes with 2
// 4️⃣ Return the head (structure unchanged).

// 💬 Example walkthrough:
//     Input: 1 → 0 → 2 → 0 → 1
//     Counts: count0 = 2, count1 = 2, count2 = 1
//     Rewrite list:
//        [0, 0, 1, 1, 2] → 0 → 0 → 1 → 1 → 2

// ⏱️ TIME COMPLEXITY:  O(2N) → O(N)
// 💾 SPACE COMPLEXITY: O(1)
// - Only constant extra space used for counters.

// 🧩 DRAWBACK:
// - This modifies node values (data replacement),
//   which might be undesirable if node data shouldn’t be altered.
// ===========================================================================================================

/*
===========================================================================================================
🔗 APPROACH 2: Link Rearrangement (3 Dummy Head Method)
-----------------------------------------------------------------------------------------------------------
💡 INTUITION:
---------------------------------------------
Instead of changing the *data* inside nodes, we can rearrange the *links*.

- The idea is to create **three separate lists**:
     1️⃣ all 0s
     2️⃣ all 1s
     3️⃣ all 2s
- Then we **stitch** these lists together in sorted order.

👉 This is the *true linked-list way* (Striver’s preferred approach),
   because it respects the linked list’s structural nature.

🧠 ALGORITHM:
---------------------------------------------
1️⃣ Create 3 dummy heads:
       zeroHead, oneHead, twoHead
   and 3 tail pointers:
       zeroTail, oneTail, twoTail

2️⃣ Traverse the original list:
       - If current node == 0 → attach to zeroTail
       - If current node == 1 → attach to oneTail
       - If current node == 2 → attach to twoTail
   Move `curr = curr->next`.

3️⃣ Connect the three lists:
       zeroTail->next = (oneHead->next) ? oneHead->next : twoHead->next
       oneTail->next = twoHead->next
       twoTail->next = nullptr

4️⃣ New head will be `zeroHead->next`.

5️⃣ Free dummy nodes (optional cleanup).

💬 Example walkthrough:
---------------------------------------------
Input: 1 → 0 → 2 → 0 → 1

- Build three separate lists while traversing:
   Zero list: 0 → 0
   One list : 1 → 1
   Two list : 2

- Then connect:
   ZeroTail → OneHead → TwoHead
   => 0 → 0 → 1 → 1 → 2

- New head = zeroHead->next

⏱️ TIME COMPLEXITY:  O(N)
💾 SPACE COMPLEXITY: O(1)
(Only a few pointers used, no extra data structures)

🎯 ADVANTAGE:
- Doesn’t modify node data.
- Clean and elegant pointer-based method.
- Most optimal for interview.
===========================================================================================================
*/

#include <iostream>
using namespace std;

// ----------------------------- Node Structure -----------------------------
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

// ==========================================================================
// ✅ APPROACH 1: Data Replacement (Counting Method)
// ==========================================================================
Node *sortListByCounting(Node *head)
{
    if (!head)
        return head;

    // Step 1: Count the occurrences of 0s, 1s, and 2s
    int count0 = 0, count1 = 0, count2 = 0;
    Node *temp = head;

    while (temp)
    {
        if (temp->data == 0)
            count0++;
        else if (temp->data == 1)
            count1++;
        else
            count2++;
        temp = temp->next;
    }

    // Step 2: Overwrite the values in the same list
    temp = head;
    while (temp)
    {
        if (count0 > 0)
        {
            temp->data = 0;
            count0--;
        }
        else if (count1 > 0)
        {
            temp->data = 1;
            count1--;
        }
        else
        {
            temp->data = 2;
            count2--;
        }
        temp = temp->next;
    }

    return head;
}

// ==========================================================================
// ✅ APPROACH 2: Link Rearrangement (3 Dummy Head Method)
// ==========================================================================
Node *sortListByLinks(Node *head)
{
    if (!head || !head->next)
        return head;

    // Step 1: Create dummy heads and tails for 0, 1, and 2 lists
    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);

    Node *zeroTail = zeroHead;
    Node *oneTail = oneHead;
    Node *twoTail = twoHead;

    // Step 2: Traverse and segregate nodes
    Node *curr = head;
    while (curr)
    {
        if (curr->data == 0)
        {
            zeroTail->next = curr;
            zeroTail = zeroTail->next;
        }
        else if (curr->data == 1)
        {
            oneTail->next = curr;
            oneTail = oneTail->next;
        }
        else
        {
            twoTail->next = curr;
            twoTail = twoTail->next;
        }
        curr = curr->next;
    }

    // Step 3: Connect the three lists
    zeroTail->next = (oneHead->next) ? oneHead->next : twoHead->next;
    oneTail->next = twoHead->next;
    twoTail->next = nullptr;

    // Step 4: Update head and clean up dummy nodes
    Node *newHead = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}

// ==========================================================================
// 🧪 Helper Functions for Testing
// ==========================================================================
void insert(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << " -> NULL\n";
}

// ==========================================================================
// 🧩 MAIN FUNCTION: Demonstration
// ==========================================================================
int main()
{
    cout << "==================== SORT 0s, 1s, and 2s IN LINKED LIST ====================\n";

    // Example 1
    Node *head1 = nullptr;
    insert(head1, 1);
    insert(head1, 0);
    insert(head1, 2);
    insert(head1, 0);
    insert(head1, 1);

    cout << "\nOriginal List 1:\n";
    printList(head1);

    head1 = sortListByCounting(head1);
    cout << "\nAfter Approach 1 (Data Replacement):\n";
    printList(head1);

    // Example 2
    Node *head2 = nullptr;
    insert(head2, 2);
    insert(head2, 1);
    insert(head2, 0);
    insert(head2, 1);
    insert(head2, 2);

    cout << "\nOriginal List 2:\n";
    printList(head2);

    head2 = sortListByLinks(head2);
    cout << "\nAfter Approach 2 (Link Rearrangement):\n";
    printList(head2);

    cout << "\n============================================================================\n";
    cout << "Both approaches are O(N) time and O(1) extra space.\n";
    cout << "Approach 2 (Link Rearrangement) is preferred in interviews\n";
    cout << "============================================================================\n";

    return 0;
}
