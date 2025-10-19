#include <iostream>
#include <vector>
using namespace std;

// ============================================================
// 🧩 Node Class — Represents a single node in a singly linked list
// ============================================================
class Node
{
public:
    int data;   // stores the node's value
    Node *next; // pointer to the next node

    // Constructor with both data and next pointer
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor with only data (default next = nullptr)
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// ============================================================
// 🔄 Function to convert an array to a singly linked list
// ============================================================
Node *convertArrayToLL(const vector<int> &arr)
{
    // If array is empty, return null pointer
    if (arr.empty())
        return nullptr;

    // Step 1️⃣: Create the head node using the first element
    Node *head = new Node(arr[0]);

    // Step 2️⃣: Use a "mover" pointer to track the last node while adding new ones
    Node *mover = head;

    // Step 3️⃣: Loop through the rest of the array to create and link nodes
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]); // Create a new node with current element
        mover->next = temp;            // Link the previous node to the new one
        mover = temp;                  // Move pointer to the new last node
    }

    // Step 4️⃣: Return the head pointer (start of the linked list)
    return head;
}

// ============================================================
// 📜 Function to print all elements of the linked list (Traversal)
// ============================================================
void printLL(Node *head)
{
    Node *temp = head; // start from the head
    cout << "Linked List Elements: ";

    // Traverse the entire list until reaching the end (nullptr)
    while (temp != nullptr)
    {
        cout << temp->data << " "; // print current node's data
        temp = temp->next;         // move to next node
    }

    cout << endl; // end line after traversal
}

// ============================================================
// 🧠 Main Function — Entry point of the program
// ============================================================
int main()
{
    // Step 1️⃣: Create an array of integers
    vector<int> arr = {2, 1, 3, 8};

    // Step 2️⃣: Convert the array into a linked list
    Node *head = convertArrayToLL(arr);

    // Step 3️⃣: Print the linked list
    printLL(head);

    return 0; // successful program termination
}

/*
==================================================
📊 SAMPLE OUTPUT
==================================================
Linked List Elements: 2 1 3 8

==================================================
⏱️ TIME & SPACE COMPLEXITY ANALYSIS
==================================================

🕒 Time Complexity (TC):
--------------------------------------------------
convertArrayToLL() → O(N)
- We iterate once through all N array elements to create nodes.
printLL() → O(N)
- We again traverse all N nodes to print values.
Total: O(N) + O(N) = O(N)

💾 Space Complexity (SC):
--------------------------------------------------
O(N)
- Each element of the array becomes one node in the linked list.
- Each node takes space proportional to the number of elements (N).
- No extra data structures (except pointers).

✅ Overall:
Time Complexity: O(N)
Space Complexity: O(N)
*/
