#include <iostream>
using namespace std;

void merge(int arr1[], int n, int arr2[], int m, int arr3[])
{   
    int i = 0;
    int j = 0;
    int k = 0;

    // Merging the two arrays
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }

    // Copying the remaining elements of arr1, if any
    while (i < n)
    {
        arr3[k] = arr1[i];
        k++;
        i++;
    }

    // Copying the remaining elements of arr2, if any
    while (j < m)
    {
        arr3[k] = arr2[j];
        k++;
        j++;
    }
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[] = {10, 240, 30, 440};
    int arr2[] = {540, 20, 5430, 40, 50};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int k = n + m;
    int arr3[k];

    merge(arr1, n, arr2, m, arr3);

    print_array(arr3, k);
    int sum = 0;
    float median = 0;
    for (int i = 0; i < k; i++)
    {
        sum = sum+ arr3[i];
    }
    median = sum/k;
    cout << median;
    

    return 0;
}
