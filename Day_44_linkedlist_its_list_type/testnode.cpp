#include <iostream>
using namespace std;

class testnode
{
public:
    int data;
    testnode *next;

    testnode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAthead(testnode* &head, int newdata)
{
    testnode* temp = new testnode(newdata);
    temp->next = head;
    head = temp;
}

void print(testnode* head)
{
    testnode* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    testnode* node = new testnode(10);
    testnode* head = node;

    cout << "Initial list: ";
    print(head);

    insertAthead(head, 20);
    cout << "After inserting 20 at head: ";
    print(head);

    return 0;
}
