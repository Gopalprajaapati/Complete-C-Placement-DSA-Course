#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtTail(int data) {
        Node* newNode = new Node(data);
        if (tail == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertAtPosition(int position, int data) {
        if (position == 1) {
            insertAtHead(data);
            return;
        }

        Node* temp = head;
        int count = 1;

        while (temp != NULL && count < position - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {
            insertAtTail(data);
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;

        if (newNode->next == NULL) {
            tail = newNode;
        }
    }

    void deleteAtPosition(int position) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            } else {
                tail = NULL; // If list becomes empty
            }
            delete temp;
            return;
        }

        Node* temp = head;
        int count = 1;

        while (temp != NULL && count < position) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {
            cout << "Position out of bounds!" << endl;
            return;
        }

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev; // If deleting the tail
        }

        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }

        delete temp;
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printReverse() {
        Node* temp = tail;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    int length() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtHead(10);
    dll.insertAtHead(20);
    dll.insertAtTail(30);
    dll.insertAtTail(40);
    dll.insertAtPosition(3, 25); // Insert 25 at position 3

    cout << "Doubly Linked List: ";
    dll.print();

    cout << "Reverse: ";
    dll.printReverse();

    cout << "Length: " << dll.length() << endl;

    dll.deleteAtPosition(3); // Delete node at position 3
    cout << "After Deletion at Position 3: ";
    dll.print();

    return 0;
}
