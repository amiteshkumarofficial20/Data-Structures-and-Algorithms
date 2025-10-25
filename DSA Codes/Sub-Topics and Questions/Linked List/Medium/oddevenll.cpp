/*
=====================================================================================
🧩 Problem: 328. Odd Even Linked List
💼 Asked In: Amazon | Google | Microsoft | Facebook | Bloomberg | Apple
💻 Difficulty: Medium
🧠 Topic Tags: Linked List | Data Structure | Two Pointer | Reordering
=====================================================================================

📘 Problem Description:
-----------------------
Given the head of a singly linked list, group all nodes with odd indices together
followed by nodes with even indices, and return the reordered list.

⚠️ Note:
- Odd and even refer to the node positions (1-based index), not node values.
- You must preserve the relative order within the odd and even groups.

-------------------------------------------------------------------------------------
📥 Example:
Input:  1 -> 2 -> 3 -> 4 -> 5 -> nullptr
Output: 1 -> 3 -> 5 -> 2 -> 4 -> nullptr

-------------------------------------------------------------------------------------
🧩 Example 2:
Input:  2 -> 1 -> 3 -> 5 -> 6 -> 4 -> 7 -> nullptr
Output: 2 -> 3 -> 6 -> 7 -> 1 -> 5 -> 4 -> nullptr

=====================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

//=====================================================================================
// 📦 Definition of Singly Linked List Node
//=====================================================================================
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//=====================================================================================
// 🧠 APPROACH 1: Data Replacement using Array (Educational / Simple to Understand)
//=====================================================================================

/*
💡 Intuition:
-------------
Instead of changing node connections (which can be confusing for beginners),
we can just read the list’s data in a specific order and then rewrite it.

We’ll:
1️⃣ Traverse the linked list and store all *odd-positioned* node values.
2️⃣ Traverse again starting from the 2nd node and store *even-positioned* node values.
3️⃣ Rewrite all node values from the array back into the list.

📋 Algorithm Steps:
-------------------
1. If the list has less than 2 nodes, return it as is.
2. Create a vector `arr` to store reordered node values.
3. Start traversal with a pointer `temp = head`:
     ➤ Push all odd-positioned node values to `arr`.
     ➤ Move `temp = temp->next->next` each time to jump to the next odd node.
4. Start a second traversal from `head->next`:
     ➤ Push all even-positioned node values to `arr`.
     ➤ Move `temp = temp->next->next` each time to jump to the next even node.
5. Finally, rewrite the linked list’s values from `arr`.

📊 Dry Run Example:
-------------------
List: 1 → 2 → 3 → 4 → 5

1️⃣ First traversal (odd indices): arr = [1, 3, 5]
2️⃣ Second traversal (even indices): arr = [1, 3, 5, 2, 4]
3️⃣ Rewrite list with arr values:
    → 1 → 3 → 5 → 2 → 4 → nullptr

✅ Final List: 1 → 3 → 5 → 2 → 4

⏱️ Time Complexity:  O(n) (3 traversals)
💾 Space Complexity: O(n) (for the array)
*/

class SolutionArrayBased
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        vector<int> arr; // To store rearranged node values
        ListNode *temp = head;

        // 1️⃣ Traverse to collect odd-positioned node values
        while (temp)
        {
            arr.push_back(temp->val);
            if (temp->next)
                temp = temp->next->next;
            else
                break;
        }

        // 2️⃣ Traverse to collect even-positioned node values
        temp = head->next;
        while (temp)
        {
            arr.push_back(temp->val);
            if (temp->next)
                temp = temp->next->next;
            else
                break;
        }

        // 3️⃣ Rewrite linked list with new values from 'arr'
        temp = head;
        int index = 0;
        while (temp)
        {
            temp->val = arr[index++];
            temp = temp->next;
        }

        return head;
    }
};

//=====================================================================================
// 🧠 APPROACH 2: Data Linkage (Optimal — Rearranging Pointers In-place)
//=====================================================================================

/*
💡 Intuition:
-------------
Instead of storing values separately, we can rearrange the *links* between nodes directly.
We maintain two separate lists:
    - One for odd-indexed nodes
    - One for even-indexed nodes

After traversing, we connect the tail of the odd list to the head of the even list.

📋 Algorithm Steps:
-------------------
1️⃣ If list has 0 or 1 node, return as is.
2️⃣ Initialize:
      ListNode* odd = head;
      ListNode* even = head->next;
      ListNode* evenHead = even;   // Save for later connection
3️⃣ While even && even->next:
      ➤ odd->next = even->next;
      ➤ odd = odd->next;
      ➤ even->next = odd->next;
      ➤ even = even->next;
4️⃣ After loop ends, connect odd->next = evenHead
5️⃣ Return head.

📊 Dry Run Example:
-------------------
List: 1 → 2 → 3 → 4 → 5

Initial:
odd = 1, even = 2, evenHead = 2

Iteration 1:
odd->next = 3, even->next = 4
odd = 3, even = 4

Iteration 2:
odd->next = 5, even->next = nullptr
odd = 5, even = nullptr

Connect odd->next = evenHead → 5->2

✅ Final List: 1 → 3 → 5 → 2 → 4

⏱️ Time Complexity:  O(n) (single traversal)
💾 Space Complexity: O(1) (in-place)
*/

class SolutionInPlace
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even; // To connect later

        // Single while loop for rearrangement
        while (even && even->next)
        {
            odd->next = even->next; // link next odd node
            odd = odd->next;        // move odd pointer
            even->next = odd->next; // link next even node
            even = even->next;      // move even pointer
        }

        // Connect last odd to the first even node
        odd->next = evenHead;
        return head;
    }
};

//=====================================================================================
// 🧰 Helper Functions
//=====================================================================================

// Create linked list from vector
ListNode *createList(const vector<int> &nums)
{
    if (nums.empty())
        return nullptr;
    ListNode *head = new ListNode(nums[0]);
    ListNode *current = head;
    for (int i = 1; i < nums.size(); i++)
    {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

// Print linked list nicely
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << " -> nullptr\n";
}

//=====================================================================================
// 🧭 main() Function — Demonstration in VS Code Style
//=====================================================================================

int main()
{
    // Example Input
    vector<int> nums = {1, 2, 3, 4, 5};

    cout << "==============================================\n";
    cout << "🔹 Input Linked List:\n";
    ListNode *headOriginal = createList(nums);
    printList(headOriginal);

    cout << "==============================================\n";

    // Approach 1: Data Replacement
    cout << "✅ Output using Approach 1 (Array-Based):\n";
    SolutionArrayBased sol1;
    ListNode *result1 = sol1.oddEvenList(createList(nums));
    printList(result1);

    cout << "----------------------------------------------\n";

    // Approach 2: Data Linkage (Optimal)
    cout << "✅ Output using Approach 2 (In-place Rearrangement):\n";
    SolutionInPlace sol2;
    ListNode *result2 = sol2.oddEvenList(createList(nums));
    printList(result2);

    cout << "==============================================\n";
    return 0;
}

/*
=====================================================================================
🎯 OUTPUT:
----------
🔹 Input Linked List:
1 -> 2 -> 3 -> 4 -> 5 -> nullptr

✅ Output using Approach 1 (Array-Based):
1 -> 3 -> 5 -> 2 -> 4 -> nullptr

✅ Output using Approach 2 (In-place Rearrangement):
1 -> 3 -> 5 -> 2 -> 4 -> nullptr
=====================================================================================
*/
