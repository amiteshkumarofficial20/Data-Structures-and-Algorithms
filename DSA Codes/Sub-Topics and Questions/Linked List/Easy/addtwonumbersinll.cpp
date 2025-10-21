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

// Core Solution Class
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        // Dummy node simplifies result list construction
        ListNode *dummyHead = new ListNode(-1);
        ListNode *current = dummyHead; // pointer for result list
        int carry = 0;

        // Traverse both lists
        while (l1 != nullptr || l2 != nullptr)
        {
            int sum = carry; // include carry each step

            if (l1)
            { // add l1 digit if available
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            { // add l2 digit if available
                sum += l2->val;
                l2 = l2->next;
            }

            // Calculate new digit and carry
            carry = sum / 10;
            int digit = sum % 10;

            // Append the new digit node
            current->next = new ListNode(digit);
            current = current->next;
        }

        // If there's any carry left, add it as a node
        if (carry)
        {
            current->next = new ListNode(carry);
        }

        // Return the next of dummy node (actual head)
        return dummyHead->next;
    }
};

// Utility function: Create a linked list from an array
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

// Utility function: Print a linked list
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

// ---------------------- MAIN FUNCTION ----------------------
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
1️⃣ Initialize dummy node & carry = 0.
2️⃣ Traverse both lists:
     ➤ Add current digits + carry.
     ➤ Compute new digit = sum % 10.
     ➤ Update carry = sum / 10.
     ➤ Append new node with digit.
3️⃣ If carry remains, append it.
4️⃣ Return dummyHead->next (actual result).

------------------------------------------------------------
⏱️ Time Complexity:  O(max(m, n))
💾 Space Complexity: O(max(m, n))
🧩 Category: Linked List, Math Simulation
🧑‍💻 Level: Medium
------------------------------------------------------------
*/
