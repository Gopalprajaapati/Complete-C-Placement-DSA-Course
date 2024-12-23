#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAthead(Node*& head, Node*& tail, int d)
{
    Node* temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    temp->next = head;
    head = temp;
}

void insertAttail(Node*& head, Node*& tail, int d)
{
    Node* temp = new Node(d);
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void print(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtposition(Node*& head, Node*& tail, int position, int d)
{
    if (position == 1) // Insert at the head
    {
        insertAthead(head, tail, d);
        return;
    }

    int cnt = 1;
    Node* temp = head;
    while (cnt < position - 1 && temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL) // Out-of-range position
    {
        cout << "Position is out of range." << endl;
        return;
    }

    Node* nodeIndex = new Node(d);
    nodeIndex->next = temp->next;
    temp->next = nodeIndex;

    // Update the tail if the new node is inserted at the end
    if (nodeIndex->next == NULL)
    {
        tail = nodeIndex;
    }
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    // Testing the linked list functions
    insertAthead(head, tail, 10);
    insertAthead(head, tail, 20);
    insertAttail(head, tail, 30);
    insertAttail(head, tail, 40);

    // Insert at an out-of-range position
    insertAtposition(head, tail, 6, 100);

    // Print the list
    print(head);

    return 0;
}
