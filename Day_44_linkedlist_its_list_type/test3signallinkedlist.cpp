#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }

};


int main()
{
    cout<<"gopal";
    Node* node1 = new Node(10);
    cout <<node1->data;
    cout <<node1->next;

}