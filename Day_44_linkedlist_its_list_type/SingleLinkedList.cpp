#include <iostream>
using namespace std;

// Definition of the Node class
class Node
{
public:
    int data;
    Node* next;

    // Constructor to initialize the node with data
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to insert a node at the head of the list
void InsertAtHead(Node*& head, int d)
{
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

// Function to insert a node at the tail of the list
void InsertAtTail(Node*& tail, int d)
{
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

// Function to insert a node at a specific position in the list
void InsertAtPosition(Node*& head, int position, int d)
{
    if (position <= 0)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    // If inserting at the head
    if (position == 1)
    {
        InsertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    // Traverse the list until the position is reached or end of the list
    while (temp != nullptr && cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // Check if the position is valid (it should not exceed the current length of the list)
    if (temp == nullptr)
    {
        cout << "Position is out of range!" << endl;
        return;
    }

    // Insert the new node
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// Function to print the linked list
void print(const Node* head)
{
    const Node* temp = head;

    // Traverse the list and print each node's data
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Create the first node with data 10
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    // Print the initial list
    cout << "Initial list: ";
    print(head);

    // Insert nodes at the head
    InsertAtHead(head, 12);
    cout << "After inserting 12 at head: ";
    print(head);

    InsertAtHead(head, 14);
    cout << "After inserting 14 at head: ";
    print(head);

    InsertAtHead(head, 16);
    cout << "After inserting 16 at head: ";
    print(head);

    // Insert nodes at the tail
    InsertAtTail(tail, 18);
    cout << "After inserting 18 at tail: ";
    print(head);

    InsertAtTail(tail, 20);
    cout << "After inserting 20 at tail: ";
    print(head);

    InsertAtTail(tail, 22);
    cout << "After inserting 22 at tail: ";
    print(head);

    // Insert a node at a specific position
    InsertAtPosition(head, 4, 555);
    cout << "After inserting 555 at position 4: ";
    print(head);

    // Attempt an out-of-bounds insertion (invalid position)
    InsertAtPosition(head, 10, 999);
    cout << "After attempting to insert 999 at position 10 (invalid): ";
    print(head);

    return 0;
}
