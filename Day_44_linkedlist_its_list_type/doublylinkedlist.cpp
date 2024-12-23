#include <iostream>
using namespace std;

class Node
{
public:
int data;
Node * perv;
Node * next;

Node(int data)
{
    this->data = data;
    this->perv= NULL;
    this->next = NULL;
}

};


void print (Node* head)
{
    Node * temp = head;
    while ( temp !=NULL)
    {
       cout << temp->data<<" ";
       temp = temp->next;
    }cout <<endl;
    
}

void insertAthead(Node*& head, Node*& tail, int d) {
    Node* temp = new Node(d);

    if (head == NULL) {
        // If the list is empty, update both head and tail
        head = temp;
        tail = temp;
        return;
    }
    temp->next = head;
    head->perv = temp;
    head= temp;
   
}


void insertAttail(Node*& head, Node*& tail, int d) {
    Node* temp = new Node(d);

    if (tail == NULL) {
        // If the list is empty, update both head and tail
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    temp->perv = tail;
    tail = temp;
    
}

int main()
{
    cout << "Doubly linked list test "<<endl;
    Node * head =NULL;
    Node * tail =NULL;
   insertAthead(head, tail, 10);
    insertAthead(head, tail, 20);
    insertAttail(head, tail, 50);
    insertAttail(head, tail, 60);
    print(head);
    print(head);

}