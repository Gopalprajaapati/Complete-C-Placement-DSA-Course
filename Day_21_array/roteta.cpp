#include <iostream>
using namespace std;

void rotate(int arr[], int size, int k)
{
    int temp[size];

    for (int i = 0; i < size; i++)
    {
        temp[(i+k) % size] = arr[i];
    }
    
    for (int i = 0; i < size; ++i)
    {
        arr[i] = temp[i];
    }
    
    
}


int main ()
{
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    rotate(arr,size,k);
    for (int i = 0; i < size; i++)
    {
        cout <<arr[i] << " ";
    }cout <<endl;
    return 0;
}