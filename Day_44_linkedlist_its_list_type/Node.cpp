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

void insertAtHead(Node*& head, Node*& tail, int d) {
    Node* temp = new Node(d);
    if (head == NULL) {
        head = temp;
        tail = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node*& head, Node*& tail, int d) {
    Node* temp = new Node(d);
    if (tail == NULL) {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node*& head, Node*& tail, int position, int d) {
    if (position == 1) {
        insertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL) {
        cout << "Position out of bounds. Inserting at the end." << endl;
        insertAtTail(head, tail, d);
        return;
    }

    Node* nodeIndex = new Node(d);
    nodeIndex->next = temp->next;
    nodeIndex->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = nodeIndex;
    } else {
        tail = nodeIndex;
    }
    temp->next = nodeIndex;
}

void deleteByPosition(Node*& head, Node*& tail, int position) {
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
            tail = NULL;
        }
        delete temp;
        return;
    }

    Node* curr = head;
    int cnt = 1;
    while (cnt < position && curr != NULL) {
        curr = curr->next;
        cnt++;
    }

    if (curr == NULL) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    if (curr->next != NULL) {
        curr->next->prev = curr->prev;
    } else {
        tail = curr->prev;
    }

    curr->prev->next = curr->next;
    delete curr;
}

void deleteByValue(Node*& head, Node*& tail, int value) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        delete temp;
        return;
    }

    Node* curr = head;
    while (curr != NULL && curr->data != value) {
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Value not found in the list!" << endl;
        return;
    }

    if (curr->next != NULL) {
        curr->next->prev = curr->prev;
    } else {
        tail = curr->prev;
    }

    curr->prev->next = curr->next;
    delete curr;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printReverse(Node* tail) {
    Node* temp = tail;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Insert nodes
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    insertAtPosition(head, tail, 1, 100); // Insert at head
    insertAtPosition(head, tail, 5, 200); // Insert in the middle
    insertAtPosition(head, tail, 8, 300); // Insert at tail

    cout << "Doubly Linked List: ";
    print(head);

    cout << "Reverse: ";
    printReverse(tail);

    // Delete nodes
    deleteByPosition(head, tail, 5); // Delete node at position 5
    cout << "After deleting at position 5: ";
    print(head);

    deleteByPosition(head, tail, 1); // Delete the head
    cout << "After deleting the head: ";
    print(head);

    deleteByPosition(head, tail, 7); // Delete the tail
    cout << "After deleting the tail: ";
    print(head);

    // Delete by value
    deleteByValue(head, tail, 20); // Delete node with value 20
    cout << "After deleting value 20: ";
    print(head);

    deleteByValue(head, tail, 300); // Delete node with value 300
    cout << "After deleting value 300: ";
    print(head);

    deleteByValue(head, tail, 1000); // Attempt to delete a non-existent value
    cout << "After attempting to delete non-existent value: ";
    print(head);

    return 0;
}
