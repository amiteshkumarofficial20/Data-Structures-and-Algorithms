/***********************************************************************************************
 * 💡 LeetCode Problem: 234. Palindrome Linked List
 * ---------------------------------------------------------------------------------------------
 * 🧾 Problem Description:
 * Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
 *
 * A linked list is said to be a palindrome if the sequence of node values reads the same
 * forward and backward.
 *
 * Example 1:
 * Input: head = [1,2,2,1]
 * Output: true
 *
 * Example 2:
 * Input: head = [1,2]
 * Output: false
 *
 * ---------------------------------------------------------------------------------------------
 * 🧠 Intuition:
 * 1️⃣ In the first approach, we use a stack to reverse the order of values and compare.
 * 2️⃣ In the optimized approach, we reverse the *second half* of the list in-place and compare.
 *
 * ---------------------------------------------------------------------------------------------
 * 🧩 APPROACH 1: Using Stack (O(n) Extra Space)
 * ---------------------------------------------------------------------------------------------
 * 1. Traverse the linked list and push all values onto a stack.
 * 2. Again traverse from the head and compare each node’s value with the top of the stack.
 * 3. If all match, it’s a palindrome; otherwise, it’s not.
 *
 * ⏱️ Time Complexity: O(n)
 * 💾 Space Complexity: O(n)
 *
 * ---------------------------------------------------------------------------------------------
 * 🧩 APPROACH 2: Reverse Second Half (O(1) Space)
 * ---------------------------------------------------------------------------------------------
 * 1. Use the slow and fast pointer technique to find the middle of the linked list.
 * 2. Reverse the second half of the linked list.
 * 3. Compare the first half and reversed second half node by node.
 * 4. Restore the list by reversing the second half again (good practice).
 * 5. If all matched, return true; else, false.
 *
 * ⏱️ Time Complexity: O(n)
 * 💾 Space Complexity: O(1)
 *
 ***********************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*********************************************
 * Definition for singly-linked list node
 *********************************************/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/***********************************************************************************************
 * 🧩 APPROACH 1: Using Stack
 ***********************************************************************************************/
class Solution_Stack
{
public:
    bool isPalindrome(ListNode *head)
    {
        stack<int> st;
        ListNode *temp = head;

        // Step 1️⃣: Push all values onto the stack
        while (temp != nullptr)
        {
            st.push(temp->val);
            temp = temp->next;
        }

        // Step 2️⃣: Compare stack values with the linked list
        temp = head;
        while (temp != nullptr)
        {
            if (temp->val != st.top())
            {
                return false; // Mismatch ⇒ Not a palindrome
            }
            st.pop();
            temp = temp->next;
        }

        // Step 3️⃣: All values matched ⇒ Palindrome
        return true;
    }
};

/***********************************************************************************************
 * 🧩 APPROACH 2: Reverse Second Half (O(1) Extra Space)
 ***********************************************************************************************/
class Solution_Optimized
{
public:
    // Helper function: Recursively reverse a linked list
    ListNode *reverseList(ListNode *head)
    {
        // Base case: if list is empty or single node
        if (head == nullptr || head->next == nullptr)
            return head;

        // Recursive step: reverse remaining list
        ListNode *newHead = reverseList(head->next);

        // Reconnect links in reverse direction
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }

    bool isPalindrome(ListNode *head)
    {
        // Edge case: 0 or 1 node ⇒ palindrome
        if (head == nullptr || head->next == nullptr)
            return true;

        /*********************************************
         * Step 1️⃣: Find middle using slow-fast pointers
         *********************************************/
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Now, 'slow' points to the middle node

        /*********************************************
         * Step 2️⃣: Reverse the second half of the list
         *********************************************/
        ListNode *secondHead = reverseList(slow->next);

        /*********************************************
         * Step 3️⃣: Compare both halves
         *********************************************/
        ListNode *first = head;
        ListNode *second = secondHead;
        bool isPalin = true;

        while (second != nullptr)
        {
            if (first->val != second->val)
            {
                isPalin = false; // Mismatch ⇒ Not palindrome
                break;
            }
            first = first->next;
            second = second->next;
        }

        /*********************************************
         * Step 4️⃣: Restore the list (optional but clean)
         *********************************************/
        slow->next = reverseList(secondHead);

        /*********************************************
         * Step 5️⃣: Return result
         *********************************************/
        return isPalin;
    }
};

/***********************************************************************************************
 * 🔧 Utility Functions for Local Testing
 ***********************************************************************************************/

// Function to create linked list from vector
ListNode *createLinkedList(const vector<int> &arr)
{
    if (arr.empty())
        return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Function to print linked list
void printLinkedList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << (temp->next ? " -> " : "");
        temp = temp->next;
    }
    cout << endl;
}

/***********************************************************************************************
 * 🧪 MAIN FUNCTION (For Local Testing)
 ***********************************************************************************************/
int main()
{
    // Example 1: Palindrome case
    vector<int> arr1 = {1, 2, 2, 1};
    ListNode *head1 = createLinkedList(arr1);

    cout << "🔹 Linked List 1: ";
    printLinkedList(head1);

    Solution_Stack sol1;
    cout << "➡️ Using Stack: "
         << (sol1.isPalindrome(head1) ? "Palindrome ✅" : "Not Palindrome ❌")
         << endl;

    Solution_Optimized sol2;
    cout << "➡️ Using Reverse Half: "
         << (sol2.isPalindrome(head1) ? "Palindrome ✅" : "Not Palindrome ❌")
         << endl;

    cout << "\n";

    // Example 2: Not a palindrome
    vector<int> arr2 = {1, 2, 3};
    ListNode *head2 = createLinkedList(arr2);

    cout << "🔹 Linked List 2: ";
    printLinkedList(head2);

    cout << "➡️ Using Stack: "
         << (sol1.isPalindrome(head2) ? "Palindrome ✅" : "Not Palindrome ❌")
         << endl;

    cout << "➡️ Using Reverse Half: "
         << (sol2.isPalindrome(head2) ? "Palindrome ✅" : "Not Palindrome ❌")
         << endl;

    return 0;
}

/***********************************************************************************************
 * 🧭 SUMMARY:
 * ---------------------------------------------------------------------------------------------
 * ✔️ Approach 1 (Stack): Easy to implement, but O(n) space.
 * ✔️ Approach 2 (Reverse Half): Optimal O(1) space, slightly more complex.
 *
 * Both achieve O(n) time.
 ***********************************************************************************************/
