#include <iostream>
using namespace std;

void binary_search(int arr[], int size)
{
    int start = 0;
    int end = size -1;

    while (start < end)
    {
        
            swap(arr[start], arr[end]);
            start ++;
            end--;
      
        
    }

}

void array_print (int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] <<" ";
    }cout <<endl;
    
}

int main()
{
    int arr[]= {4,5,62,5,12,3};
    int size= 6;

    array_print(arr,size);
    binary_search(arr,size);
     array_print(arr,size);
}