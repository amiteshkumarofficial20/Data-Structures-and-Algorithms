/*
==========================================================================================
  Problem: LeetCode 06 — Reverse Linked List
  Purpose: Provide three complete, detailed implementations (stack, iterative, recursive)
           with thorough comments, intuition, complexity, and example usage (main).
==========================================================================================

PROBLEM (short):
Given the head of a singly linked list, reverse the list, and return the new head.

Example:
  Input:  1 -> 2 -> 3 -> 4 -> 5 -> NULL
  Output: 5 -> 4 -> 3 -> 2 -> 1 -> NULL

Why multiple approaches?
  - Different interviewers value different constraints (space vs clarity).
  - Understanding multiple techniques demonstrates depth: using helpers (stack),
    in-place pointer manipulation (iterative), and recursion (elegant stack-implicit).
==========================================================================================
*/

#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;

// --------------------------- Basic ListNode Definition ---------------------------
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// --------------------------- Helper Utilities -----------------------------------

// Create linked list from vector of ints, returns head pointer.
// Example: makeList({1,2,3}) -> 1->2->3->NULL
ListNode *makeList(const vector<int> &vals)
{
    if (vals.empty())
        return nullptr;
    ListNode *head = new ListNode(vals[0]);
    ListNode *cur = head;
    for (size_t i = 1; i < vals.size(); ++i)
    {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

// Print linked list on one line: "1 -> 2 -> 3 -> NULL"
void printList(ListNode *head)
{
    ListNode *cur = head;
    while (cur != nullptr)
    {
        cout << cur->val;
        if (cur->next)
            cout << " -> ";
        cur = cur->next;
    }
    cout << " -> NULL\n";
}

// Delete list to free memory (good practice for local testing)
void deleteList(ListNode *head)
{
    while (head)
    {
        ListNode *tmp = head->next;
        delete head;
        head = tmp;
    }
}

// Helper to clone a list (useful to reuse same input across approaches).
ListNode *cloneList(ListNode *head)
{
    if (!head)
        return nullptr;
    ListNode *newHead = new ListNode(head->val);
    ListNode *src = head->next;
    ListNode *dst = newHead;
    while (src)
    {
        dst->next = new ListNode(src->val);
        dst = dst->next;
        src = src->next;
    }
    return newHead;
}

// --------------------------- Approach 1: Stack (Data Replacement) ----------------
/*
IDEA:
  - Traverse the list and push node values into a stack.
  - Traverse again and pop values from stack, writing them back into the nodes.
  - Result: the sequence of node values becomes reversed, but the node objects/links
    remain in the same order.

WHEN TO USE:
  - When you only need reversed *values* (rare in real systems).
  - Good to demonstrate stacks and get a correct solution quickly.
  - Not preferred in interviews when asked to "reverse the list" (they expect pointers changed).

PROS:
  - Simple to implement and reason about.
  - Time O(n), straightforward.

CONS:
  - Extra O(n) memory for the stack.
  - Does NOT reverse links — some problems explicitly require pointer reversal.

Time Complexity: O(n) — traverse twice (push + pop/write)
Space Complexity: O(n) — stack stores n values
*/
ListNode *reverseList_stack(ListNode *head)
{
    if (!head)
        return nullptr;

    stack<int> st;
    ListNode *cur = head;

    // Push all values onto the stack
    while (cur)
    {
        st.push(cur->val);
        cur = cur->next;
    }

    // Write them back in reversed order
    cur = head;
    while (cur)
    {
        cur->val = st.top();
        st.pop();
        cur = cur->next;
    }

    // Head pointer unchanged (structure unchanged); values reversed.
    return head;
}

// --------------------------- Approach 2: Iterative 3-Pointer ---------------------
/*
IDEA:
  - Use three pointers: prev, curr, nextNode (commonly named prev, curr, next)
  - Walk through the list; for each node:
      - Save curr->next into nextNode
      - Point curr->next to prev (reverse the link)
      - Move prev = curr, curr = nextNode
  - At the end, prev points to the new head (old tail).

WHY THIS IS PREFERRED:
  - Reverses the list in-place: O(1) extra space.
  - Simple loop, O(n) time.

TRICKY PARTS:
  - Must save curr->next before re-pointing it; otherwise you lose the rest of list.
  - Careful with initial conditions: prev = nullptr, curr = head.
  - Return prev (not head) — head becomes tail with next = nullptr.

Time Complexity: O(n) — single pass
Space Complexity: O(1) — in-place
*/
ListNode *reverseList_iterative(ListNode *head)
{
    ListNode *prev = nullptr; // Will become the new head at the end
    ListNode *curr = head;    // Iterator for traversal

    while (curr != nullptr)
    {
        ListNode *nextNode = curr->next; // Save next node (prevent losing remainder)
        curr->next = prev;               // Reverse current node's pointer
        prev = curr;                     // Move prev forward
        curr = nextNode;                 // Move curr forward
    }

    // prev points to new head (old tail). curr is nullptr here.
    return prev;
}

// --------------------------- Approach 3: Recursive -------------------------------
/*
IDEA:
  - Treat reversing as: reverse the sublist starting at head->next, then append head to the end.
  - Base case: head == nullptr or head->next == nullptr => return head (single node or empty).
  - After reversing the tail, the node after head (original head->next) is the tail of reversed
    sublist; set that node's next to head, and head->next = nullptr to finalize.

WHY USE RECURSION:
  - Elegant and concise.
  - Uses the call stack to remember previous nodes.
  - Not ideal for extremely long lists (stack depth = n could overflow real stack).

TRICKY PARTS:
  - Must set head->next = nullptr after connecting tail->next = head.
  - Understand that recursive call returns newHead (the tail of original list).

Time Complexity: O(n)
Space Complexity: O(n) due to recursion call stack (one frame per node)
*/
ListNode *reverseList_recursive(ListNode *head)
{
    // Base cases: empty list or single node list -> it's already reversed
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // Recursively reverse the sublist starting at head->next
    ListNode *newHead = reverseList_recursive(head->next);

    // At this point:
    // head->next is the last node in the reversed sublist (call it tail)
    // We want tail->next = head
    head->next->next = head; // Point the next node back to current head

    // Break the original forward link to avoid a cycle
    head->next = nullptr;

    // newHead is the head of reversed sublist (original tail) -> bubble it up
    return newHead;
}

// --------------------------- Extra: Compact "one-liner" recursive variant -----
// The below is equivalent to reverseList_recursive but sometimes shown shorter.
// It is intentionally left commented to show alternative style:
/*
ListNode* reverseList_recursive_compact(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* p = reverseList_recursive_compact(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
}
*/

// --------------------------- Main & Tests --------------------------------------
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "LeetCode #206 — Reverse Linked List (detailed implementations)\n\n";

    // Prepare sample input
    vector<int> vals = {1, 2, 3, 4, 5};
    cout << "Original values: ";
    for (int v : vals)
        cout << v << " ";
    cout << "\n\n";

    // Build original list
    ListNode *original = makeList(vals);
    cout << "Original list: ";
    printList(original);

    // ---- Test Approach 1: Stack (value reversal) ----
    {
        ListNode *input1 = cloneList(original); // clone to preserve original
        cout << "\n[Approach 1] Stack (data replacement) - Before: ";
        printList(input1);

        ListNode *out1 = reverseList_stack(input1);

        cout << "[Approach 1] After reversing (stack => values reversed): ";
        printList(out1);

        // Clean up
        deleteList(out1);
    }

    // ---- Test Approach 2: Iterative 3-pointer ----
    {
        ListNode *input2 = cloneList(original);
        cout << "\n[Approach 2] Iterative (3-pointer) - Before: ";
        printList(input2);

        ListNode *out2 = reverseList_iterative(input2);

        cout << "[Approach 2] After reversing (iterative pointers): ";
        printList(out2);

        // Reverse back to verify correctness (reverse again to get original sequence)
        ListNode *restored = reverseList_iterative(out2);
        cout << "[Approach 2] Reversed back to original: ";
        printList(restored);

        deleteList(restored);
    }

    // ---- Test Approach 3: Recursive ----
    {
        ListNode *input3 = cloneList(original);
        cout << "\n[Approach 3] Recursive - Before: ";
        printList(input3);

        ListNode *out3 = reverseList_recursive(input3);

        cout << "[Approach 3] After reversing (recursive): ";
        printList(out3);

        // Clean up
        deleteList(out3);
    }

    // cleanup original
    deleteList(original);

    cout << "\nSummary (quick):\n";
    cout << " - Stack approach:    O(n) time, O(n) space  (reverses values only)\n";
    cout << " - Iterative approach:O(n) time, O(1) space  (in-place pointer reversal)  <-- Preferred\n";
    cout << " - Recursive approach:O(n) time, O(n) space  (uses call stack; elegant)\n";

    cout << "\nNotes for interviews:\n";
    cout << " - If asked to 'reverse the list', prefer the in-place iterative 3-pointer method.\n";
    cout << " - Mention tradeoffs: recursive uses call stack (risk of stack overflow for very large lists).\n";
    cout << " - Explain pointer updates step-by-step and edge cases (empty list, single node).\n";

    return 0;
}
