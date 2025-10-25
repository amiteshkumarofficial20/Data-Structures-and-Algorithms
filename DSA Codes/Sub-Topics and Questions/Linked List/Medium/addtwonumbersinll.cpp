/*
------------------------------------------------------------
🧮 LeetCode Problem: 2. Add Two Numbers
------------------------------------------------------------
🧾 Description:
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each node contains a single digit.
Add the two numbers and return the sum as a linked list (also in reverse order).

Example:
Input:  (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807

------------------------------------------------------------
🏢 Asked In:
Amazon, Google, Microsoft, Facebook, Apple, Bloomberg,
Adobe, Uber, Goldman Sachs, LinkedIn, Flipkart
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// ------------------------------------------------------------
// 🧩 Core Solution Class
// ------------------------------------------------------------
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        /*
        💡 Why use a Dummy Node?
        ------------------------
        A dummy (or sentinel) node is a placeholder at the start of the new list.
        It simplifies code because:
          ✅ We don't need to handle the "first node" as a special case.
          ✅ We can always safely append new nodes using 'current->next'.
          ✅ Final result can be returned as 'dummyHead->next'.

        Without it, we’d need extra conditions to check if the list is empty
        before adding each new node.
        */

        // Create dummy node to simplify result list construction
        ListNode *dummyHead = new ListNode(-1);
        ListNode *current = dummyHead; // Pointer for result list
        int carry = 0;                 // Stores carry between additions

        // Traverse both lists
        while (l1 != nullptr || l2 != nullptr)
        {
            int sum = carry; // Include previous carry

            // Add current digits if available
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            // Compute new digit and carry
            carry = sum / 10;
            int digit = sum % 10;

            // Append new digit node to result list
            current->next = new ListNode(digit);
            current = current->next;
        }

        // If carry remains after final addition, add a new node
        if (carry)
        {
            current->next = new ListNode(carry);
        }

        // The first node (dummy) was just a placeholder
        // Actual result starts from dummyHead->next
        return dummyHead->next;
    }
};

// ------------------------------------------------------------
// 🧰 Utility Functions
// ------------------------------------------------------------

// Create a linked list from an array
ListNode *createList(int arr[], int n)
{
    if (n == 0)
        return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *tail = head;
    for (int i = 1; i < n; ++i)
    {
        tail->next = new ListNode(arr[i]);
        tail = tail->next;
    }
    return head;
}

// Print linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// ------------------------------------------------------------
// 🧪 Main Function (for local VS Code testing)
// ------------------------------------------------------------
int main()
{
    // Example Input:
    // (2 -> 4 -> 3) + (5 -> 6 -> 4)
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Create linked lists
    ListNode *l1 = createList(arr1, n1);
    ListNode *l2 = createList(arr2, n2);

    // Display inputs
    cout << "Input List 1: ";
    printList(l1);
    cout << "Input List 2: ";
    printList(l2);

    // Compute result
    Solution solution;
    ListNode *result = solution.addTwoNumbers(l1, l2);

    // Display output
    cout << "Resultant Sum List: ";
    printList(result);

    return 0;
}

/*
------------------------------------------------------------
🧠 Algorithm (Iterative):

1️⃣ Initialize a dummy node and set carry = 0.
2️⃣ Traverse both linked lists:
     ➤ Add corresponding digits and the carry.
     ➤ Compute new digit = (sum % 10).
     ➤ Update carry = (sum / 10).
     ➤ Create a node for the digit and attach it.
3️⃣ If carry remains at the end, add it as a final node.
4️⃣ Return dummyHead->next (head of the actual result list).

------------------------------------------------------------
💡 Why Dummy Node?
   ➤ Prevents handling special cases for head node.
   ➤ Simplifies node linking logic.
   ➤ Makes the algorithm cleaner and easier to maintain.

------------------------------------------------------------
⏱️ Time Complexity:  O(max(m, n))
   Each list is traversed once.

💾 Space Complexity: O(max(m, n))
   New nodes created for each digit of the sum.

🧩 Category: Linked List, Math Simulation
🧑‍💻 Difficulty: Medium
------------------------------------------------------------
*/
