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

    // Constructor with only data (used for end or standalone nodes)
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// ==========================================
// 🔁 Function to traverse and print a linked list
// ==========================================
void traverseLinkedList(Node *head)
{
    Node *temp = head; // Start traversal from the head node

    cout << "Linked List Elements: ";

    // Traverse the linked list until we reach NULL
    while (temp != nullptr)
    {
        cout << temp->data << " "; // Print the data of the current node
        temp = temp->next;         // Move to the next node
    }

    cout << endl; // Print newline after traversal
}

// ==========================================
// 🧠 Main Function
// ==========================================
int main()
{
    // Step 1️⃣: Manually create a linked list: 10 -> 20 -> 30 -> 40
    Node *head = new Node(10);             // First node
    head->next = new Node(20);             // Second node
    head->next->next = new Node(30);       // Third node
    head->next->next->next = new Node(40); // Fourth node

    // Step 2️⃣: Call traversal function
    traverseLinkedList(head);

    return 0; // Successful program execution
}

/*
==================================================
📊 OUTPUT
==================================================
Linked List Elements: 10 20 30 40

==================================================
⏱️ TIME & SPACE COMPLEXITY ANALYSIS
==================================================
Time Complexity (TC): O(N)
- The function visits each node exactly once.
- N = number of nodes in the linked list.

Space Complexity (SC): O(1)
- Only uses a few pointer variables (no recursion or extra memory).
- Hence, constant extra space.
*/
