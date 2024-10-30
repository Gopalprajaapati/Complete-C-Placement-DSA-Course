#include <iostream>

using namespace std;


void selection_sort(int arr[], int size)
{

    for (int  i = 0; i < size-1 ; i++)
    {
        int minIndex= i;

        for (int j = i+1; j < size; j++)
        {
            if (arr[j] <arr[minIndex])
            {
                minIndex = j;
            }
            
        }
      int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
    
}

void print_array(int arr[], int size)
{
      for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main ()
{
    int arr[] ={5,3,4,6,8,1};
    int size = 6;
     selection_sort(arr, size);
   print_array(arr,size);
}