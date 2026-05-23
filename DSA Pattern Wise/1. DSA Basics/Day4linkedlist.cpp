#include <bits/stdc++.h> // Includes almost all standard C++ libraries
using namespace std;

/*
    ============================================================
                    LINKED LIST IN C++ & DSA
    ============================================================

    WHAT IS A LINKED LIST?
    ------------------------------------------------------------
    - Linked List is a linear data structure.
    - Elements are stored in separate memory locations.
    - Each element is connected using pointers.

    Each element of linked list is called NODE.

    A NODE contains:
        1. Data
        2. Address of next node

    ============================================================

    VISUAL REPRESENTATION
    ------------------------------------------------------------

        [10 | * ] ----> [20 | * ] ----> [30 | NULL]

        Data              Data             Data
        Next Address      Next Address     NULL

    ============================================================

    WHY LINKED LIST IS IMPORTANT IN DSA?
    ------------------------------------------------------------

    Linked Lists are used in:
        - Stacks
        - Queues
        - Graphs
        - Hash Tables
        - Dynamic Memory Allocation
        - Browser History
        - Music Playlist
        - Undo/Redo Operations

    ============================================================

    ADVANTAGES OF LINKED LIST
    ------------------------------------------------------------

    1. Dynamic Size
       - Size can grow or shrink at runtime.

    2. Easy Insertion/Deletion
       - Faster compared to arrays.

    3. Better Memory Utilization
       - Memory allocated when needed.

    ============================================================

    DISADVANTAGES OF LINKED LIST
    ------------------------------------------------------------

    1. Extra Memory Required
       - Pointer needs additional memory.

    2. No Direct Access
       - Cannot access using index like arrays.

    3. Traversal is Sequential
       - Need to move node by node.

    ============================================================

    TYPES OF LINKED LIST
    ------------------------------------------------------------

    1. Singly Linked List
    2. Doubly Linked List
    3. Circular Linked List

    This program demonstrates:
        SINGLY LINKED LIST

    ============================================================

    TIME COMPLEXITIES
    ------------------------------------------------------------

    Insertion at Beginning:
        O(1)

    Insertion at End:
        O(n)

    Deletion:
        O(n)

    Traversal:
        O(n)

    Searching:
        O(n)

    ============================================================
*/

/*
    ============================================================
                        NODE STRUCTURE
    ============================================================

    Structure is user-defined data type.

    struct Node
    {
        data part
        address part
    };

    ============================================================
*/

struct Node
{
    /*
        Data part
        Stores actual value
    */
    int data;

    /*
        Pointer part
        Stores address of next node
    */
    Node *next;

    /*
        --------------------------------------------------------
                        CONSTRUCTOR
        --------------------------------------------------------

        Constructor initializes object automatically.

        Here:
            data = value
            next = NULL
    */

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

/*
    ============================================================
                    PRINT LINKED LIST FUNCTION
    ============================================================

    Purpose:
        Traverse and print linked list.

    Traversal:
        Moving node by node.

    temp pointer used for traversal.

    ============================================================
*/

void printList(Node *head)
{
    /*
        temp starts from head
    */
    Node *temp = head;

    /*
        Loop runs until temp becomes NULL
    */

    while (temp != NULL)
    {
        cout << temp->data << " -> ";

        /*
            Move to next node
        */
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

/*
    ============================================================
                INSERT AT BEGINNING FUNCTION
    ============================================================

    Steps:
        1. Create new node
        2. New node points to head
        3. Move head to new node

    Time Complexity:
        O(1)

    ============================================================
*/

void insertAtBeginning(Node *&head, int value)
{
    /*
        Creating new node dynamically
    */
    Node *newNode = new Node(value);

    /*
        New node points to current head
    */
    newNode->next = head;

    /*
        Head updated
    */
    head = newNode;
}

/*
    ============================================================
                    INSERT AT END FUNCTION
    ============================================================

    Steps:
        1. Create new node
        2. Traverse till last node
        3. Last node points to new node

    Time Complexity:
        O(n)

    ============================================================
*/

void insertAtEnd(Node *&head, int value)
{
    /*
        Create new node
    */
    Node *newNode = new Node(value);

    /*
        If list is empty
    */
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    /*
        temp used for traversal
    */
    Node *temp = head;

    /*
        Reach last node
    */
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    /*
        Attach new node
    */
    temp->next = newNode;
}

/*
    ============================================================
                        SEARCH FUNCTION
    ============================================================

    Purpose:
        Find element in linked list.

    Linear Search is used.

    Time Complexity:
        O(n)

    ============================================================
*/

bool searchElement(Node *head, int key)
{
    Node *temp = head;

    while (temp != NULL)
    {
        /*
            Element found
        */
        if (temp->data == key)
        {
            return true;
        }

        temp = temp->next;
    }

    /*
        Element not found
    */
    return false;
}

/*
    ============================================================
                    DELETE FIRST NODE
    ============================================================

    Steps:
        1. Store current head
        2. Move head forward
        3. Delete old node

    Time Complexity:
        O(1)

    ============================================================
*/

void deleteBeginning(Node *&head)
{
    /*
        Empty list check
    */
    if (head == NULL)
    {
        return;
    }

    /*
        Temporary pointer
    */
    Node *temp = head;

    /*
        Move head forward
    */
    head = head->next;

    /*
        Free memory
    */
    delete temp;
}

/*
    ============================================================
                            MAIN FUNCTION
    ============================================================

    Program execution starts from main().

    ============================================================
*/

int main()
{
    /*
        ========================================================
                    CREATING LINKED LIST
        ========================================================

        head stores address of first node.

        Initially:
            head = NULL

        Means linked list is empty.
    */

    Node *head = NULL;

    /*
        ========================================================
                    INSERT AT END
        ========================================================
    */

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    /*
        Current Linked List:
            10 -> 20 -> 30 -> NULL
    */

    cout << "Linked List After Insert At End:" << endl;

    printList(head);

    /*
        ========================================================
                    INSERT AT BEGINNING
        ========================================================
    */

    insertAtBeginning(head, 5);

    /*
        Current Linked List:
            5 -> 10 -> 20 -> 30 -> NULL
    */

    cout << "After Insert At Beginning:" << endl;

    printList(head);

    /*
        ========================================================
                        SEARCH OPERATION
        ========================================================
    */

    int key;

    cout << "Enter Element to Search: ";

    cin >> key;

    /*
        Calling search function
    */

    if (searchElement(head, key))
    {
        cout << "Element Found" << endl;
    }
    else
    {
        cout << "Element Not Found" << endl;
    }

    /*
        ========================================================
                    DELETE FROM BEGINNING
        ========================================================
    */

    deleteBeginning(head);

    /*
        Current Linked List:
            10 -> 20 -> 30 -> NULL
    */

    cout << "After Deleting First Node:" << endl;

    printList(head);

    /*
        ========================================================
                    TRAVERSAL THEORY
        ========================================================

        Traversal means visiting every node one by one.

        Example:
            temp = head

            while(temp != NULL)
            {
                process data
                temp = temp->next
            }

        ========================================================
    */

    /*
        ========================================================
                    IMPORTANT DSA CONCEPTS
        ========================================================

        Linked List Concepts Used In:
            - Stack using Linked List
            - Queue using Linked List
            - Graph Adjacency List
            - Hashing
            - Dynamic Memory

        ========================================================
                    COMMON MISTAKES
        ========================================================

        1. Forgetting NULL checks

        2. Losing head pointer

        3. Incorrect pointer updates

        4. Memory leaks
           (forgetting delete)

        ========================================================
    */

    /*
        return 0;
        ----------------
        Indicates successful execution.
    */

    return 0;
}