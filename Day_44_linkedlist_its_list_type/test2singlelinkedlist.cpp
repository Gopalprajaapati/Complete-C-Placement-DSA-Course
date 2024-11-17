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
    // create new Node
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
    cout << endl;
}

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    // cout << endl;
}

void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void InsertAtPOsition(Node* &head, int Position,int d)
{

    if(Position ==1)
    {
        InsertAtHead(head,d);
        return;
    }
    Node* temp = head;
    int cnt= 1;

    while (cnt<Position-1 && temp !=NULL)
    {
        temp=temp->next;
        cnt++;
    }
    if(temp == NULL)
    {
        cout<< "POsition out of Bound :";
        return;
    }
    Node* newNodeindex= new Node(d);
    newNodeindex->next =temp->next;
    temp->next=newNodeindex;
}



int main()
{
    cout << " main Node object print ";

    Node *node1 = new Node(10);
    cout << node1->data;
    cout << node1->next;
    cout << endl;

    cout << " main Node object create head print ";
 cout<<endl;

    Node *head = node1;
    InsertAtHead(head, 10);
    print(head);
        InsertAtHead(head, 20);
    print(head);
        InsertAtHead(head, 30);
    print(head);
 cout<<endl;
   
    cout << " main Node object create Tail print ";
 cout<<endl;
    Node *tail = node1;
    InsertAtTail(tail, 1);
    print(head);
     InsertAtTail(tail, 2);
    print(head);
     InsertAtTail(tail, 3);
    print(head);
 cout<<endl;

 cout<<endl;
      cout << " main Node object create InserAt Posiotion print ";
 cout<<endl;
    InsertAtPOsition(head,2,100);
    print(head);
    InsertAtPOsition(tail,2,4);
    print(head);
     InsertAtPOsition(tail,5,5);
    print(head);
 cout<<endl;

}
