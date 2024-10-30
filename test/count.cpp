#include <iostream>
using namespace std;

int main()
{
    int arr[] = {7,4,8,2,9}
    int n = sizeof(arr)/ sizeof(arr[0]);
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[0] < arr[i+1])
        {
            count++;
        }
        
    }
    cout << count;
}
