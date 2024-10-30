#include <iostream>
using namespace std;


//even swap altertative
void array_even(int arr[], int size)
{
    
    int start =0;
    int end= size-1;
    while (start<end)
    {
        if (start+1<end)
        {
            swap(arr[start],arr[start+1]);
        }
        start+=2;
    }
    
    // for (int i = 0; i <size; i+=2)
    // {
    //     if (i+1 < size)
    //     {
    //         swap(arr[i], arr[i+1]);
    //     }
        
    // }
    
    
}

//odd swap altertative


void array_print (int arr[] , int size)
{
    for (int i = 0; i <= size; i++)
    {
        cout << arr[i] <<" ";
    } cout<<endl;
    
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int size = 5;

    cout << "Array's First Program" << endl;
     array_even(arr,size);
    // Print the array
    array_print(arr, size);
   
}