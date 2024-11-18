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
    ~Node()
    {
        int val = this->data;
        if (this->next = NULL)
        {
            delete next;
        }
    }
};

void insertAtHead(Node *&head, int d)
{
   
    
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void print(Node* &head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
       temp = temp->next;
    }
    cout << endl;
}
void insertAtTail(Node* &tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

int main()
{
    cout << "single linkedlist node code ";
    Node *node1 = new Node(10);
    cout << node1->data;
    Node *head = node1;
    Node *tail = node1;
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    insertAtHead(head, 50);
   

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    print(head);

}