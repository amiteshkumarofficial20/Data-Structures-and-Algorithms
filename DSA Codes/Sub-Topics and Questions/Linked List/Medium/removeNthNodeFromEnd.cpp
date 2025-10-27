#include <bits/stdc++.h>
using namespace std;

/* ==========================================================================
   🧩 LeetCode 19 — Remove Nth Node From End of List
   ==========================================================================

   📜 PROBLEM STATEMENT:
   ---------------------
   Given the head of a singly linked list, remove the nth node from the end
   of the list and return its head.

   Example 1:
   -----------
   Input:  head = [1,2,3,4,5], n = 2
   Output: [1,2,3,5]

   Example 2:
   -----------
   Input:  head = [1], n = 1
   Output: []

   Example 3:
   -----------
   Input:  head = [1,2], n = 1
   Output: [1]

   Constraints:
   ------------
   • The number of nodes in the list is sz.
   • 1 ≤ sz ≤ 30
   • 0 ≤ Node.val ≤ 100
   • 1 ≤ n ≤ sz

   --------------------------------------------------------------------------
   🧠 INTUITION:
   -------------
   The Nth node from the end is equivalent to the (length - n + 1)th node
   from the start. So we can either:
     1. Count total nodes (brute force), then remove that specific node.
     2. Use two pointers in a single traversal to directly reach the node
        before the target and delete it (optimal).

   --------------------------------------------------------------------------
   🧩 APPROACH 1: Brute Force (Two Pass)
   -------------------------------------
   1️⃣ Traverse the entire list to count total nodes → length = count.
   2️⃣ If (length == n), remove head (since it’s the Nth from end).
   3️⃣ Otherwise, calculate the position from start to delete = (length - n).
   4️⃣ Traverse again to reach the (length - n)th node.
   5️⃣ Update pointers to skip the target node and delete it.

   Time Complexity:  O(2N)
   Space Complexity: O(1)

   --------------------------------------------------------------------------
   🧩 APPROACH 2: Optimal (One Pass - Two Pointers)
   ------------------------------------------------
   1️⃣ Create a dummy node before the head (handles edge cases cleanly).
   2️⃣ Initialize two pointers: slow and fast at dummy.
   3️⃣ Move fast pointer (n + 1) steps ahead → creates a gap of n nodes.
   4️⃣ Move both pointers one step until fast reaches the end.
       - Now, slow is just before the target node.
   5️⃣ Delete slow->next.
   6️⃣ Return dummy->next as new head.

   Time Complexity:  O(N)
   Space Complexity: O(1)
   ========================================================================== */

/* --------------------------------------------------------------------------
   STRUCT: Definition for singly linked list node
   -------------------------------------------------------------------------- */
struct ListNode
{
    int val;        // stores data
    ListNode *next; // pointer to next node

    // Constructor
    ListNode(int x) : val(x), next(nullptr) {}
};

/* --------------------------------------------------------------------------
   🧮 CLASS: Brute Force Approach (Two Pass Method)
   -------------------------------------------------------------------------- */
class BruteForceSolution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Edge case: empty list
        if (head == nullptr)
            return nullptr;

        // Step 1️⃣: Count total nodes
        int count = 0;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        // Step 2️⃣: If head itself needs to be deleted
        if (count == n)
        {
            ListNode *newHead = head->next;
            delete head; // free memory of old head
            return newHead;
        }

        // Step 3️⃣: Traverse again to reach node before target
        int pos = count - n; // position from start
        temp = head;
        while (--pos > 0)
        {
            temp = temp->next;
        }

        // Step 4️⃣: Delete the target node
        ListNode *delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;

        // Step 5️⃣: Return updated head
        return head;
    }
};

/* --------------------------------------------------------------------------
   ⚡ CLASS: Optimal Approach (One Pass - Two Pointer Method)
   -------------------------------------------------------------------------- */
class OptimalSolution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Step 1️⃣: Create dummy node to handle all cases
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        // Step 2️⃣: Initialize fast and slow pointers
        ListNode *fast = dummy;
        ListNode *slow = dummy;

        // Step 3️⃣: Move fast pointer (n + 1) steps ahead
        for (int i = 0; i <= n; i++)
        {
            fast = fast->next;
        }

        // Step 4️⃣: Move both until fast reaches the end
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 5️⃣: Now slow->next is the target node to delete
        ListNode *delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        // Step 6️⃣: Return updated head (skip dummy)
        ListNode *newHead = dummy->next;
        delete dummy; // free dummy node
        return newHead;
    }
};

/* --------------------------------------------------------------------------
   🧪 Helper Functions: To Build and Display Linked Lists
   -------------------------------------------------------------------------- */

// Function to create a linked list from a vector
ListNode *createList(const vector<int> &arr)
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

// Function to print a linked list
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val;
        if (head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

/* --------------------------------------------------------------------------
   🧭 MAIN FUNCTION: Driver Code for Testing Both Approaches
   -------------------------------------------------------------------------- */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example input
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 2;

    cout << "Original Linked List: ";
    ListNode *head = createList(arr);
    printList(head);

    // ---------------- Brute Force Approach ----------------
    cout << "\n🧮 Brute Force Approach (Two Pass)\n";
    BruteForceSolution brute;
    ListNode *bruteHead = createList(arr);
    bruteHead = brute.removeNthFromEnd(bruteHead, N);
    cout << "After removing " << N << "th node from end: ";
    printList(bruteHead);

    // ---------------- Optimal Approach ----------------
    cout << "\n⚡ Optimal Approach (One Pass)\n";
    OptimalSolution opt;
    ListNode *optHead = createList(arr);
    optHead = opt.removeNthFromEnd(optHead, N);
    cout << "After removing " << N << "th node from end: ";
    printList(optHead);

    return 0;
}

/* ==========================================================================
   ✅ OUTPUT EXAMPLE:
   ------------------
   Original Linked List: 1 -> 2 -> 3 -> 4 -> 5

   🧮 Brute Force Approach (Two Pass)
   After removing 2th node from end: 1 -> 2 -> 3 -> 5

   ⚡ Optimal Approach (One Pass)
   After removing 2th node from end: 1 -> 2 -> 3 -> 5

   --------------------------------------------------------------------------
   🧩 COMPLEXITY ANALYSIS:
   -----------------------
   🔹 Brute Force:
       Time:  O(2N)   → Two traversals of list
       Space: O(1)
   🔹 Optimal:
       Time:  O(N)    → Single traversal
       Space: O(1)

   --------------------------------------------------------------------------
   📘 SUMMARY:
   -----------
   - The brute force approach is simpler to understand and implement.
   - The optimal approach uses two pointers and is more efficient.
   - Always use a dummy node for linked list problems involving head deletion.
   ========================================================================== */
