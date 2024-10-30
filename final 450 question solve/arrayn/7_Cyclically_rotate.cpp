#include <iostream>
using namespace std;

void rotate(int arr[], int n)
{
}

int main()
{
    int arr[] = {1,2,3,4,5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k= 1;
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = arr[i]; 
     }

     for (int i = 0; i < n; i++)
     {
        arr[i] = temp [i];
     }
     
     for (int i = 0; i < n; i++)
     {
        cout << arr[i]; 
     } 
     cout << endl;
     
    
}