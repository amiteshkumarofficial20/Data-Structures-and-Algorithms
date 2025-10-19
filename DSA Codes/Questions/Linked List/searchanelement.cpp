#include <iostream>
using namespace std;

// ==========================================
// 🧩 Node Class: Represents one node in a singly linked list
// ==========================================
class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node in the list

    // Constructor with both data and next node pointer
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor with only data (for end or standalone nodes)
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// ==========================================
// 🔍 Function to check if an element is present in the linked list
// ==========================================
int checkIfPresent(Node *head, int desiredElement)
{
    Node *temp = head; // Start traversal from the head node

    // Traverse the linked list until the end
    while (temp != nullptr)
    {
        // Compare current node's data with desired element
        if (temp->data == desiredElement)
            return 1; // ✅ Element found, return 1

        // Move to the next node
        temp = temp->next;
    }

    // ❌ Element not found, return 0
    return 0;
}

// ==========================================
// 🧠 Main Function
// ==========================================
int main()
{
    // Step 1️⃣: Create a linked list manually: 1 -> 2 -> 3
    Node *head = new Node(1);       // first node with data = 1
    head->next = new Node(2);       // second node with data = 2
    head->next->next = new Node(3); // third node with data = 3

    // Step 2️⃣: Define the element to search for
    int val = 5; // change this to test other values

    // Step 3️⃣: Call checkIfPresent and print result
    if (checkIfPresent(head, val))
        cout << val << " is present in the linked list ✅" << endl;
    else
        cout << val << " is NOT present in the linked list ❌" << endl;

    return 0; // successful program execution
}

/*
==================================================
📊 OUTPUT (for val = 5)
==================================================
5 is NOT present in the linked list ❌

📊 OUTPUT (for val = 2)
==================================================
2 is present in the linked list ✅

==================================================
⏱️ TIME & SPACE COMPLEXITY ANALYSIS
==================================================
Time Complexity (TC): O(N)
- The function traverses the entire linked list (N = number of nodes)
  in the worst case when the element is not found.

Space Complexity (SC): O(1)
- Only uses a few pointers (no recursion, no extra data structures)
  → constant extra space.
*/
