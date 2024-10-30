#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAthead(node *&head, int newdata)
{
    node *temp = new node(newdata);
    temp->next = head;
    head = temp;
}

int insertAttail(node *&tail, int newdata)
{
    node *temp = new node(newdata);
    tail->next = temp;
    tail = temp;
}

void print(node *&head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
}

int main()
{
      cout << "Linked list:" << endl;

    // Create initial node
    node* node1 = new node(10);
    cout << node1->data << endl;

    // Initialize head and tail
    node* head = node1;
    node* tail = node1;

    // Insert at head and tail
    insertAthead(head, 20); print(head);
    insertAttail(tail, 30);

    // Print the entire linked list
   

    // Print the entire linked list
    print(tail);
}