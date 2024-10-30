#include <iostream>
using namespace std;


// to findDulipcate in array
void tofindduplicate(int arr[], int size)
{
    int ans =0;

    for (int i = 0; i <size; i++)
    {
        ans=ans ^arr[i];
    }
    
    for (int i = 1; i <size; i++)
    {
        ans = ans^i;
    }
    cout << ans <<endl; 
}

void arrya_print(int arr[] , int size )
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] <<" ";

    }cout <<endl;
    
}

int main()
{
   int arr[5] ={5,5,2,2,1};
   int size=5;
    tofindduplicate(arr,size);
    // arrya_print(arr,size);
} 
