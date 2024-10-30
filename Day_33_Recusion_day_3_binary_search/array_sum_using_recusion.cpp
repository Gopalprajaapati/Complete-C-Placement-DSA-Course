#include <iostream>
using namespace std;

int sum1(int *arr, int size)
{
    // int sum1 = 0;
    // for (int i = 0; i < size - 1; i++)
    // {
    //     sum1 = sum1 + arr[i];
    // }
    // return sum1;


int su =0;
    // base case 
    if (size == 0)
    {
       return 0;
    }
    
    return arr[0]+sum1(arr+1, size-1);


}

int main()
{

    int arr[] = {1, 1, 5, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int sum = sum1(arr, size);
    cout << sum;
}
