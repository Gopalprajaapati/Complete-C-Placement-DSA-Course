#include <iostream>
using namespace std;

// int arrayn_sum(int arr[], int size)
// {
//     int sum =0;
//     for (int i = 0; i <= size; i++)
//     {
//        sum = arr[i]+arr[i+1];
//     }
//     return sum;

// }

int main()
{
    cout <<"Arryan index sum" <<endl;
    int arr[5]={10,20,30,40,50};
    int size = 5;

    // int ans = arrayn_sum(arr,size);
    // cout << ans;
    int sum =0;
    for (int i = 0; i <size; i++)
    {
        sum= sum+arr[i];
       
    }
     cout << sum <<endl;
}