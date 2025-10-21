#include <bits/stdc++.h>
using namespace std;

/*
    Doubly Linked List in C++
    --------------------------------------
    This file combines the DLL skeleton with a basic demonstration.
    Features:
    - Node class with data, next, and prev pointers.
    - DoublyLinkedList class with head and tail pointers.
    - Basic creation and linking of nodes.
*/

// Node class representing a node in DLL
class Node
{
public:
    int data;   // Stores the value of the node
    Node *next; // Pointer to the next node in the list
    Node *prev; // Pointer to the previous node in the list

    // Constructor: initializes the node with a value
    Node(int val)
    {
        data = val;
        next = nullptr; // Initially, no next node
        prev = nullptr; // Initially, no previous node
    }
};

// Doubly Linked List class skeleton
class DoublyLinkedList
{
private:
    Node *head; // Pointer to the first node
    Node *tail; // Pointer to the last node

public:
    // Constructor: initializes an empty doubly linked list
    DoublyLinkedList()
    {
        head = nullptr; // No nodes initially
        tail = nullptr;
    }

    // Future methods can be added here: insertion, deletion, traversal
};

int main()
{
    // Create an empty doubly linked list
    DoublyLinkedList dll;
    cout << "Doubly Linked List created. Currently empty." << endl;

    // Step 1: Create head node
    Node *head = new Node(10);
    Node *tail = head; // Tail points to the same node initially

    cout << "\nHead node data: " << head->data << '\n';
    cout << "Tail node data: " << tail->data << '\n';
    cout << "Head->next: " << head->next << '\n';
    cout << "Head->prev: " << head->prev << '\n';

    // Step 2: Create second node and link
    Node *second = new Node(20);
    head->next = second;
    second->prev = head;
    tail = second;

    cout << "\nAfter adding second node:\n";
    cout << "Head data: " << head->data << ", Head->next data: " << head->next->data << '\n';
    cout << "Second data: " << second->data << ", Second->prev data: " << second->prev->data << '\n';
    cout << "Tail data: " << tail->data << '\n';

    // Step 3: Create third node and link
    Node *third = new Node(30);
    tail->next = third;
    third->prev = tail;
    tail = third;

    cout << "\nAfter adding third node:\n";
    cout << "Tail data: " << tail->data << ", Tail->prev data: " << tail->prev->data << '\n';

    return 0;
}