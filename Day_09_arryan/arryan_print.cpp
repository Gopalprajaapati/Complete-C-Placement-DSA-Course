#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

int array_max(int arr[], int size)
{
    int min = INT_MAX;
    for (int i = 0; i <= size; i++)
    {
        if (arr[i] >min )
        {
           min= arr[i];
        }
        return min;
    }
    
}


//function mininum array

int array_min(int arr[] , int size)
{
   
    int max = INT_MIN;
    for (int i = 0; i <=size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        return max;
    }
    
    
    
}


void array_print (int arr[] , int size)
{
    for (int i = 0; i <= size; i++)
    {
        cout << arr[i];
    }
    
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int size = 5;

    cout << "Array's First Program" << endl;
    
    // Print the array
    array_print(arr, size);
    
    // Find and print the minimum value in the array
    int min = array_min(arr, size);
     int max = array_max(arr, size);
    cout << "Minimum value in the array: " << min <<max << endl;

    return 0;
}
