#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev; // Added for doubly linked list

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAthead(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    // Update pointers to insert at head
    temp->next = head;
    head->prev = temp;

    // Move head to the new node
    head = temp;
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

int length(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAthead(head, tail, 10);
    insertAthead(head, tail, 20);
    insertAthead(head, tail, 30);

    print(head);

    // Print the length of the list
    cout << "Length of the list: " << length(head) << endl;

    return 0;
}
