#include <iostream>
using namespace std;

class Node
{
    public :
    int data;
    Node * next;
    Node(int data)
    {
        this ->data = data;
        this->next =NULL;
    }
};


void insertAthead(Node* &head, Node* &tail,int d)
{
    Node* temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        tail = head;
        return;
    }
    temp->next = head;
    head = temp;
    
}

void insertAttail(Node* &head, Node* &tail,int d)
{
    Node* temp = new Node(d);
    if (tail == NULL)
    {
        head = temp;
        tail = head;
        return;
    }
    tail->next = temp;
    tail = temp;
    
}

void print (Node* head)
{
        Node* temp = head;
    while (temp !=NULL)
    {
        cout << temp->data<<" ";
        temp =temp->next;
    }cout <<endl;
    
}


void insertAtposition(Node*&head, Node* &tail,int position, int d)
{
    if (position == 1)
    {
       insertAthead(head,tail,d);
       return;
    }
    
    Node*temp = head;
    int cnt=1;
    while (cnt <position-1 && temp!=NULL)
    {
        temp= temp->next;
        cnt++;
    }
    if (temp == NULL)
    {
        cout <<"invalid position"<<endl;
        return;
    }
    Node* nodeindex = new Node(d);
    nodeindex->next = temp->next;
    temp->next = nodeindex;
    if (nodeindex->next == NULL)
    {
        tail = nodeindex;
        return;
    }
    
}

void deleteposition(Node* &head, Node*&tail,int position)
{
    if (head==NULL)
    {
        cout << "list is empty . Nothing to deleted." <<endl;
        return;
    }

    if (position == 1)
    {
        Node* temp =head;
        head= head->next;
        delete temp;
        if (head == NULL)
        {
            tail = NULL;
        }
        return;
    }
    
Node* curr = head;
Node* perv =NULL;
int cnt=1;

while ( curr !=NULL && cnt <position  )
{
    perv = curr;
    curr= curr->next;
    cnt++;
}

if (curr == NULL)
{
    cout << " Invalied is position ."<<endl;
    return;
}
    perv->next = curr->next;

    if (curr->next ==NULL)
    {
        tail = perv;
    }
    
    delete curr;

    
}


void deltedbyvalue (Node* &head, Node* &tail, int val)
{
    if (head == NULL)
    {
        cout<<"list is empty.";
        return ;
    }

    if (head->data == val)
    {
        Node* temp = head;
        head= head->next;
        delete temp;
        if (head==NULL)
        {
            tail = NULL;
        }
        return ;
    }
    
    Node * curr = head;
    Node* perv = NULL;
    int cnt=1;

    while ( curr!=NULL &&  curr->data!=val )
    {
       perv = curr;
       curr= curr->next;
       
       cnt++;
    }

    if (curr ==NULL)
    {
        cout << " invalied is val"<<endl;
        return;
    }

    perv->next = curr->next;

    if (curr->next == NULL  )
    {
       tail = perv;
       return;
    }
    
    delete curr;
    
    
    
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Insert at head
    insertAthead(head, tail, 10);
    insertAthead(head, tail, 20);
    insertAthead(head, tail, 30);

    // Insert at tail
    insertAttail(head, tail, 40);
    insertAttail(head, tail, 50);

    // Print the list
    print(head);

    // Insert at position
    insertAtposition(head, tail, 3, 25); // Insert 25 at position 3
    print(head);

    // Delete position
    deleteposition(head, tail, 1); // Delete head node
    print(head);

    deleteposition(head, tail, 5); // Delete tail node
    print(head);

    deleteposition(head, tail, 10); // Invalid position
    print(head);

    return 0;
}