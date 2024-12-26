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

void insertAtHead(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1 && temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp == NULL)
    {
        cout << "linkedlist is empty" << endl;
        return;
    }

    Node *nodeIndex = new Node(d);
    nodeIndex->next = temp->next;
    temp->next = nodeIndex;

    if (nodeIndex->next == NULL)
    {
        tail = nodeIndex;
        return;
    }
}

void print(Node *head)
{
    Node *temp = head;
    int cnt = 1;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
        cnt++;
    }
    cout << endl;
}

void deleteByPosition(Node *&head, Node *&tail, int position)
{
    if (head == NULL)
    {
        cout << "linkedlist is empty:";
        return;
    }

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        if (head == NULL)
        {

            tail = NULL;
        }
        return;
    }

    Node *curr = head;
    Node *prev = NULL;
    int cnt = 1;
    while (cnt < position && curr != NULL)
    {
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    if (curr == NULL)
    {
        cout << "Position is out of bounds." << endl;
        return;
    }

    prev->next = curr->next;

    if (curr->next == NULL)
    {
        tail = prev;
    }
    delete curr;
}

void deleteByValue(Node *&head, Node *&tail, int value)
{
    if (head ==NULL)
    {
       cout << "Linked list empty";
       return;
    }
    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        if (head == NULL)
        {
            tail = NULL;
        }
        return;
    }

    Node* curr= head;
    Node* prev = NULL;
    int cnt =1;
    while (curr != NULL && curr->data != value)
    {
       prev = curr;
       curr = curr->next;
       cnt++;
    }

    if (curr == NULL)
    {
        cout << "LInked lis bound";
        return;
    }
    prev->next = curr->next;
    if (curr->next == NULL)
    {
        tail = prev;
        return;
    }
    delete curr;
    

    
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    // Insert nodes
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    insertAtPosition(head, tail, 1, 100); // Insert at head
    insertAtPosition(head, tail, 5, 200); // Insert in the middle
    insertAtPosition(head, tail, 8, 300); // Insert at tail

    print(head);

    // Delete nodes
    deleteByPosition(head, tail, 5); // Delete node at position 5
    print(head);

    deleteByPosition(head, tail, 1); // Delete the head
    print(head);

    deleteByPosition(head, tail, 7); // Delete the tail
    print(head); 
       // Delete node by value
    deleteByValue(head, tail, 20); // Delete node with value 20
    print(head);

    deleteByValue(head, tail, 300); // Delete node with value 300
    print(head);

    deleteByValue(head, tail, 1000); // Attempt to delete a non-existent value
    print(head);

    return 0;
}