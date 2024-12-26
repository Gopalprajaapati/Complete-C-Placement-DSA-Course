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

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool detectCycle(Node* head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // Cycle detected
        }
    }
    return false; // No cycle found
}

// Create a cycle for testing
void createCycle(Node*& head, int position) {
    if (head == NULL || position <= 0) return;

    Node* temp = head;
    Node* cycleNode = NULL;
    int count = 1;

    while (temp->next != NULL) {
        if (count == position) {
            cycleNode = temp;
        }
        temp = temp->next;
        count++;
    }

    if (cycleNode != NULL) {
        temp->next = cycleNode; // Create a cycle
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Insert nodes into the doubly linked list
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);

    cout << "Original List: ";
    print(head);

    // Create a cycle for testing
    createCycle(head, 3);

    // Detect cycle
    if (detectCycle(head)) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle detected!" << endl;
    }

    return 0;
}
