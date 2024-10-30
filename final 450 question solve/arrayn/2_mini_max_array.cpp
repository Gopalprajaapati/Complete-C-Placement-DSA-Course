#include <iostream>
using namespace std;


int mini_array(int arr[], int size)
{
    int mini = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < mini)
        {
            mini = arr[i];
        }
        
    }
    return mini;
}

int max_array(int arr[], int size)
{
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        
    }
    return max;
}

void  print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] <<" ";
    }
    
}

int main ()
{
    int arr[] = {1,5,7,9,4,8};
    int size= 6;

    print_array(arr, size);

   int max = max_array(arr,size);
   cout << endl <<"mini : " << max;
   int mini = mini_array(arr,size);
   cout << endl <<"mini : " << mini;



}