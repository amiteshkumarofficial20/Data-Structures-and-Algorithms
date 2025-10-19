#include <iostream>
#include <vector>
using namespace std;

// ============================================================
// 🧩 Node Class — Represents a single node in a singly linked list
// ============================================================
class Node
{
public:
    int data;   // value stored in the node
    Node *next; // pointer to the next node

    // Constructor with both data and next pointer
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor with only data
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// ============================================================
// ⚙️ Function to convert an array into a linked list
// ============================================================
Node *convertArrayToLL(const vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// ============================================================
// 🖨️ Function to print a linked list
// ============================================================
void printLL(Node *head)
{
    Node *temp = head;
    cout << "Linked List: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ============================================================
// ➕ INSERTION OPERATIONS
// ============================================================

// 1️⃣ Insert at Head
Node *insertAtHead(Node *head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    return newNode;
}

// 2️⃣ Insert at Tail
Node *insertAtTail(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
        return newNode; // if list is empty

    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

// 3️⃣ Insert at Kth Position (1-based index)
Node *insertAtPosition(Node *head, int k, int val)
{
    if (k == 1)
        return insertAtHead(head, val);

    Node *temp = head;
    int count = 1;

    while (temp != nullptr && count < k - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr)
    {
        cout << "⚠️ Position out of range!" << endl;
        return head;
    }

    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// 4️⃣ Insert After a Given Element
Node *insertAfterValue(Node *head, int element, int val)
{
    Node *temp = head;
    while (temp != nullptr && temp->data != element)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "⚠️ Element " << element << " not found!" << endl;
        return head;
    }

    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// ============================================================
// ➖ DELETION OPERATIONS
// ============================================================

// 1️⃣ Delete Head Node
Node *deleteHead(Node *head)
{
    if (head == nullptr)
        return nullptr;

    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

// 2️⃣ Delete Tail Node
Node *deleteTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;

    delete temp->next;
    temp->next = nullptr;
    return head;
}

// 3️⃣ Delete Node at Kth Position
Node *deleteAtPosition(Node *head, int k)
{
    if (head == nullptr)
        return nullptr;
    if (k == 1)
        return deleteHead(head);

    Node *temp = head;
    int count = 1;

    while (temp->next != nullptr && count < k - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == nullptr)
    {
        cout << "⚠️ Position out of range!" << endl;
        return head;
    }

    Node *delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
    return head;
}

// 4️⃣ Delete Node by Value
Node *deleteByValue(Node *head, int val)
{
    if (head == nullptr)
        return nullptr;
    if (head->data == val)
        return deleteHead(head);

    Node *temp = head;
    while (temp->next != nullptr && temp->next->data != val)
        temp = temp->next;

    if (temp->next == nullptr)
    {
        cout << "⚠️ Value " << val << " not found!" << endl;
        return head;
    }

    Node *delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
    return head;
}

// ============================================================
// 🧠 Main Function — Demonstration
// ============================================================
int main()
{
    vector<int> arr = {10, 20, 30, 40};
    Node *head = convertArrayToLL(arr);

    cout << "Initial ";
    printLL(head);

    // Insertions
    head = insertAtHead(head, 5);
    cout << "After inserting 5 at Head: ";
    printLL(head);

    head = insertAtTail(head, 50);
    cout << "After inserting 50 at Tail: ";
    printLL(head);

    head = insertAtPosition(head, 3, 15);
    cout << "After inserting 15 at Position 3: ";
    printLL(head);

    head = insertAfterValue(head, 30, 35);
    cout << "After inserting 35 after Element 30: ";
    printLL(head);

    // Deletions
    head = deleteHead(head);
    cout << "After deleting Head: ";
    printLL(head);

    head = deleteTail(head);
    cout << "After deleting Tail: ";
    printLL(head);

    head = deleteAtPosition(head, 3);
    cout << "After deleting node at Position 3: ";
    printLL(head);

    head = deleteByValue(head, 20);
    cout << "After deleting node with value 20: ";
    printLL(head);

    return 0;
}

/*
==================================================
📊 SAMPLE OUTPUT
==================================================
Initial Linked List: 10 20 30 40
After inserting 5 at Head: 5 10 20 30 40
After inserting 50 at Tail: 5 10 20 30 40 50
After inserting 15 at Position 3: 5 10 15 20 30 40 50
After inserting 35 after Element 30: 5 10 15 20 30 35 40 50
After deleting Head: 10 15 20 30 35 40 50
After deleting Tail: 10 15 20 30 35 40
After deleting node at Position 3: 10 15 30 35 40
After deleting node with value 20: ⚠️ Value 20 not found!
10 15 30 35 40

==================================================
⏱️ TIME & SPACE COMPLEXITY
==================================================
🔹 Insertion Operations:
   - At Head → O(1)
   - At Tail → O(N)
   - At Kth Position → O(K) ≈ O(N)
   - After Element → O(N)
🔹 Deletion Operations:
   - At Head → O(1)
   - At Tail → O(N)
   - At Kth Position → O(K) ≈ O(N)
   - By Value → O(N)
🔹 Traversal (printLL) → O(N)
🔹 Space Complexity (all ops) → O(1)
   - Only uses pointers, no extra data structures.
==================================================
*/
