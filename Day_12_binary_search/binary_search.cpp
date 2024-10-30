#include <iostream>
using namespace std;

int binary_search(int arr[], int size, int key)
{
    int start=0;
    int end=size-1;
    

    while (start<=end)
    {
        int mid = start + (end - start) / 2;  

        if (arr[mid] == key)
        {
            return mid;
        }
        if (key > arr[mid])
        {
            start = mid+1;
        }else
        {
            end = mid-1;
        }
        
        mid= (start+end)/2;

        
    }
    return -1;
}

int main() {
    
    int arr[5] = {10,20,30,40,50};
    int size = 5;
    int key = 40;

    int index= binary_search(arr,size,key);
   

    for (int i = 0; i <=size; i++)
    {
        if (arr[index] == arr[i])
        {
            cout << "KEy value " <<arr[i] <<" ";
        }
        
    }
     cout << "index : "<<index <<" ";
}