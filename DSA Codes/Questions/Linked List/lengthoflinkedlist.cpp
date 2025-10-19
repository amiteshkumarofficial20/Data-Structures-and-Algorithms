#include <iostream>
#include <vector>
using namespace std;

// =============================
// Definition of a Node
// =============================
class Node
{
public:
    int data;   // stores the data value
    Node *next; // pointer to the next node

    // Constructor with both data and next pointer
    Node(int data1, Node *next1)
    {
        data = data1; // assign value to data
        next = next1; // assign next pointer
    }

    // Constructor with only data (used for creating the last node)
    Node(int data1)
    {
        data = data1;
        next = nullptr; // last node points to NULL
    }
};

// =============================
// Function to calculate length of a linked list
// =============================
int lengthOfLinkedList(Node *head)
{
    Node *temp = head; // start from head
    int cnt = 0;       // initialize counter

    // Traverse until end of linked list
    while (temp != NULL)
    {
        cnt++;             // increment count for each node
        temp = temp->next; // move to next node
    }

    return cnt; // total number of nodes
}

// =============================
// Main Function
// =============================
int main()
{
    // Step 1: Create an array
    vector<int> arr = {2, 5, 8, 7};

    // Step 2: Manually create linked list from array
    Node *head = new Node(arr[0]);             // first node
    head->next = new Node(arr[1]);             // second node
    head->next->next = new Node(arr[2]);       // third node
    head->next->next->next = new Node(arr[3]); // fourth node

    // Step 3: Call function and print the length
    cout << "Length of Linked List: " << lengthOfLinkedList(head) << '\n';

    return 0;
}

/*
=============================
🧩 OUTPUT
=============================
Length of Linked List: 4

=============================
📊 TIME & SPACE COMPLEXITY
=============================

Time Complexity (TC): O(N)
- The loop runs once for each node (N = number of nodes).
- Hence linear time.

Space Complexity (SC): O(1)
- We only use a few variables (temp, cnt).
- No extra data structure or recursion stack used.
*/
