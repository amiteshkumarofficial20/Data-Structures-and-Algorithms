#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:         // lowercase 'public', not 'Public'
    int data;   // the data value
    Node *next; // the pointer to the next node

public:
    // constructor with both data and next
    Node(int data1, Node *next1)
    {
        data = data1; // Initialize data with the provided value
        next = next1; // Initialize next with the provided pointer
    }

    // constructor with only data
    Node(int data1)
    {
        data = data1;   // Initialize data with the provided value
        next = nullptr; // Initialize next as null since it's the end of the list
    }
};

int main()
{
    vector<int> arr = {2, 5, 8, 7};
    Node *y = new Node(arr[0]);

    cout << y << '\n';       // prints the memory address of the node
    cout << y->data << '\n'; // prints the data stored in that node

    return 0;
}
