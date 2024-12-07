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

void insertAthead(Node *&head, Node *&tail, int d)
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

void insertAttail(Node *&head, Node *&tail, int d)
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

void insertAtposition(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertAthead(head, tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (temp != NULL && cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp == NULL)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    Node *nodeindex = new Node(d);
    nodeindex->next = temp->next;
    temp->next = nodeindex;

    if (temp->next == NULL)
    {
        tail = nodeindex;
    }
}

void deleteAtposition(Node *&head, Node *&tail, int position)
{
    if (head == NULL)
    {
        cout << "List is empty. Nothing to deleted ." << endl;
    }
    if (position == 1)
    {
        Node *temp = head;
        head = head->next ;
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
    while (curr != NULL && cnt < position)
    {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    if (curr == NULL)
    {
        cout << "Invalid Position : " <<endl;
    }
    
    prev->next = curr->next;

    if (curr->next == NULL)

    {
        tail = prev;
    }

    delete curr;
}


void deleteme(Node* &head, Node* &tail, int position)
{
    if (head == NULL)
    {
        cout << "List is Empty : Nothis to deleted." <<endl;
        return;
    }

    if (position == 1)
    {
        Node* temp = head;
        head = head->next;
        delete temp;

        if (head == NULL)
        {
            tail = NULL;
        }
        return;
    }

    Node* curr = head;
    Node* perv = NULL;
    int cnt = 1;

    while (cnt <position && curr != NULL)
    {
        perv = curr;
        curr = curr->next;
        cnt ++;
    }

    if (curr == NULL)
    {
        cout << "invalid position ." << endl;
        return;
    }

    perv->next = curr->next;

    if (curr->next ==NULL)
    {
        tail = perv;
    }
    
    delete curr;
    
    
    
    
}


void deletebyvalue(Node* &head, Node* &tail, int val)
{
    if (head == NULL)
    {
        cout << " list is empry. Nothing is deleted."<<endl;
        return;
    }

    if (head->data == val)
    {
        Node* temp = head;
        head = head->next;
        delete head;

        if ( head == NULL)
        {
             tail = NULL;
        }
        
        return;
    }

    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;

    while (curr !=NULL && curr->data !=val)
    {
        prev = curr;
        curr= curr->next;
        cnt++;
    }
    
    if (curr == NULL)
    {
       cout << " Invalid value." << endl;
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
    cout << "Signal linked list :" << endl;
    Node *head = NULL;
    Node *tail = NULL;

    // Insert some nodes
    insertAthead(head, tail, 10);
    insertAthead(head, tail, 20);
    insertAtposition(head, tail, 3, 30); // List: 20 -> 10 -> 30
    insertAtposition(head, tail, 4, 40); // List: 20 -> 10 -> 30 -> 40

    cout << "Initial List: ";
    print(head);

    // Delete positions
    deleteme(head, tail, 1); // Delete head
    cout << "After deleting position 1: ";
    print(head);

    deleteme(head, tail, 2); // Delete middle node
    cout << "After deleting position 2: ";
    print(head);

    deleteme(head, tail, 2); // Delete tail
    cout << "After deleting position 2 (tail): ";
    print(head);

    deleteme(head, tail, 3); // Invalid position
    cout << "Final List: ";
    print(head);

    return 0;
}