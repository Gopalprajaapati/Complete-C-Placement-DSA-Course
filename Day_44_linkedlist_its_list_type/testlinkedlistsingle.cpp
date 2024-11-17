#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (tail != NULL)
    {
        tail->next = temp;
    }
    tail = temp;
}

void InsertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        InsertAtHead(head, d);
        if (tail == NULL)
        {
            tail = head;
        }
        return;
    }

    Node *temp = head;
    int count = 1;

    // Traverse to the node before the desired position
    while (count < position - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    // If position is beyond the current list length, add at the tail
    if (temp == NULL || temp->next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }

    // Insert the new node at the specified position
    Node *newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    InsertAtTail(tail, 40);
    if (head == NULL) head = tail;
    print(head);

    InsertAtTail(tail, 50);
    if (head == NULL) head = tail;
    print(head);

    InsertAtTail(tail, 60);
    if (head == NULL) head = tail;
    print(head);

    // Insert 25 at position 2
    InsertAtPosition(head, tail, 2, 25);
    print(head);

    // Insert 10 at position 1 (new head)
    InsertAtPosition(head, tail, 1, 10);
    print(head);

    // Insert 70 at position 6 (new tail)
    InsertAtPosition(head, tail, 6, 70);
    print(head);

    return 0;
}
