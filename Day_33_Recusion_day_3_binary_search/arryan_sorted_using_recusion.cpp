#include <iostream>
using namespace std;

bool issort(int *arr, int size)
{
    // base case 
    if (size == 0 or size ==1)
    {
        return true;
    }

    if (arr[0] >arr[1])
    {
        return false;
    }else
    {
        return issort(arr +1, size-1);
    }
    

    // using loop 
    // for (int i = 0; i < size-1; i++)
    // {
    //     if (arr[i] > arr[i+1])
    //     {
    //         return false;
    //     }
        
        
    // }
    // return true;
    
    


}

int main()
{

    int arr[] = {1,21,5,9};
    int size = sizeof(arr) / sizeof(arr[0]);

  bool ans =  issort(arr,size);

    if (ans)
    {
        cout <<"array sort .";
    }else
    {
                cout <<"array not sort .";

    }
    
    
}
