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

void insertAthead(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

void insertAttail(Node *&tail, Node *&head, int d)
{
    Node *temp = new Node(d);
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp; // Append the new node at the end
        tail = temp;       // Update the tail pointer
    }
}

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    // Insert at the head
    if (position == 1)
    {
        insertAthead(head, tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    // Traverse to the position before the desired index
    while (cnt < position - 1 && temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }

    // If inserting at the end or beyond
    if (temp == NULL || temp->next == NULL)
    {
        insertAttail(tail, head, d);
        return;
    }

    // Insert in the middle
    Node *nodeIndex = new Node(d);
    nodeIndex->next = temp->next;
    temp->next = nodeIndex;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAthead(head, tail, 10);
    print(head);

    insertAthead(head, tail, 20);
    print(head);

    insertAthead(head, tail, 30);
    print(head);

    insertAttail(tail, head, 90);
    print(head);

    insertAttail(tail, head, 100);
    print(head);

    insertAttail(tail, head, 120);
    print(head);

    insertAtPosition(head, tail, 2, 65);
    print(head);

    insertAtPosition(head, tail, 1, 5);
    print(head);

    insertAtPosition(head, tail, 10, 150);
    print(head);

    return 0;
}
