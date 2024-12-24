#include <iostream>
using namespace std;

class Stack {
private:
    int size;
    int top;
    int *arr;

public:
    // Constructor
    Stack(int size) {
        this->size = size;
        top = -1;
        arr = new int[size];
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Push an element onto the stack
    void push(int element) {
        if (top < size - 1) {
            top++;
            arr[top] = element;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    // Pop the top element from the stack
    void pop() {
        if (top >= 0) {
            top--;
        } else {
            cout << "Stack Underflow" << endl;
        }
    }

    // Peek at the top element of the stack
    int peek() {
        if (top >= 0) {
            return arr[top];
        } else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Get the current size of the stack
    int currentSize() {
        return top + 1;
    }
};

int main() {
    Stack s(5); // Create a stack of size 5

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Top element: " << s.peek() << endl;

    int size = s.currentSize();
    int arr[size];

    // Transfer stack elements to the array
    for (int i = size - 1; i >= 0; --i) {
        arr[i] = s.peek();
        s.pop();
    }

    // Print the array
    cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
