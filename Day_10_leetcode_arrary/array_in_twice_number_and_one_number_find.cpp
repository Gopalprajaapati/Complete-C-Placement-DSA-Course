#include <iostream>
using namespace std;


void array_one(int arr[], int size)
{
    int ans=0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    cout << ans;
}

void array_print(int arr[], int size)
{
    for (int i = 0; i <size; i++)
    {
        cout << arr[i]<<" ";
    }cout<<endl;
   
}
int main()
{
    int arr[5] = {5,6,4,5,6};
    int size = 5;
    array_print(arr,size);
    array_one(arr,size);
}