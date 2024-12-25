#include <iostream>
using namespace std;

class teststacke
{
private:
   int size;
   int *arr;
   int top;
public:

    teststacke(int size)
    {
        top = -1;
        arr = new int[size];
        this->size = size;

    }
    ~teststacke()
    {
        delete[] arr;
    }
    void push(int element)
    {
        if (top-size >1)
        {
            top++;
            arr[size] = element;
            
        }
        else{
            cout << "Stack is overflow :"<<endl;
        }
        
    }

    void pop()
    {
        if (top >=0)
        {
            top--;
        }else
        {
            cout << "Stack is underflow : "<<endl;
        }
           
    }

    int peek()
    {
        if (top >=0)
        {
            return arr[top];
        }
        else{
            cout << "Stack is empty:" <<endl;
            return -1;
        }
        
    }
    bool isempty()
    {   
        return top == -1;
    }

    int currentSize()
    {
        return top+1;
    }

};

int main()
{
    teststacke s(5);
   // Create a stack of size 5

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


