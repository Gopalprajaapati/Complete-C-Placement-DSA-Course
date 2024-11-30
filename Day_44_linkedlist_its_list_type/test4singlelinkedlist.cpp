#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data= data;
        this->next=NULL;
    }

};

void   inserAthead(Node* &head,Node* &tail, int d)
{
    Node* temp = new Node(d);
    if(head == NULL)
    {
        head = temp;
        tail= temp;
    }else{
        temp->next = head;
        head= temp;
    }
}

void inserAttail(Node* &head, Node* &tail,int d)
{
    Node* temp = new Node(d);
    if (tail ==NULL)
    {
        head = temp;
        tail = temp;
    }else
    {
        tail->next = temp;
        tail = temp;
    }
    

}

void inserAtposition(Node* head, Node* &tail, int position, int d)
{
   
    if (position == 1)
    {
        inserAthead(head,tail,d);
        return;
    }
  
    Node* temp = head;
    int cnt = 1;
    while (cnt <position-1 && temp !=NULL)
    {
        temp = temp->next ;
        cnt ++;
    }
   if (temp == NULL) {
        cout << "Position out of bounds" << endl;
        return;
    }
    
    Node* nodeIndex = new Node(d);
    nodeIndex->next = temp->next;
    temp->next = nodeIndex;

    if (nodeIndex->next == NULL)
    {
      tail = nodeIndex;
     
    }
    
    
}

void insertAtpositiondelete(Node* &head, Node* &tail, int position )
{
    if (head == NULL)
    {
        cout << "out bound list";
    }
    if (position == 1)
    {
        Node* temp = head;
        head = head->next;
        if (head= NULL)
        {
           tail = NULL;
        }
        delete temp;
        return;
        
    }
    

    Node* temp = head;
    int cnt = 1;
    while (cnt < position-1 && temp !=NULL)
    {
        temp = temp->next;
        cnt++;
    }
    
    if (temp->next == NULL && temp !=NULL)
    {
      cout << "position out of bound";
    }
    
    Node* nodeIndexdeleted =temp->next;

    temp->next = nodeIndexdeleted->next;

    if (temp->next = NULL)
    {
       tail = temp;
    }
    delete nodeIndexdeleted;

    
}

void print(Node* head){
        if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;

    while (temp!= NULL )
    {
        cout << temp->data <<" ";
        temp = temp->next;        
    }
    
}
int main()
{
   
    Node* head= NULL;
    Node* tail = NULL;
    inserAthead(head,tail,10);
    inserAthead(head,tail,20);
    inserAthead(head,tail,30);
  
    inserAttail(head,tail,40);
    inserAttail(head,tail,50);
    inserAttail(head,tail,60);
      // Insert nodes at specific positions
    inserAtposition(head, tail, 2, 100); // Insert ṇt position 2
    inserAtposition(head, tail, 10, 200); // Position out of bounds
    print(head);
}