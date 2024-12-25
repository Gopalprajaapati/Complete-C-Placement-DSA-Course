#include <iostream>
using namespace std;

class TestStack
{
private:
    int size;
    int *arr;
    int top;

public:
    TestStack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    ~TestStack()
    {
        delete[] arr;
    }

    void push(int element)
    {
        if (top < size - 1) // Check if the stack has space
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0) // Check if the stack has elements
        {
            top--;
        }
        else
        {
            cout << "Stack underflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }

    int currentSize()
    {
        return top + 1;
    }
};

int main()
{
    TestStack s(5); // Create a stack of size 5

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Top element: " << s.peek() << endl;

    int size = s.currentSize();
    int *arr = new int[size];

    // Transfer stack elements to the array
    for (int i = size - 1; i >= 0; --i)
    {
        arr[i] = s.peek();
        s.pop();
    }

    // Print the array
    cout << "Array elements: ";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // Free the dynamically allocated array

    return 0;
}
