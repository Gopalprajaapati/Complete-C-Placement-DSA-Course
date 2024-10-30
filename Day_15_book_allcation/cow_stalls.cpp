#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int arr[], int size, int cow, int mid)
{
    int cowCount = 1;
    int lastPosition = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] - lastPosition >= mid)
        {
            cowCount++;
            if (cowCount == cow)
            {
                return true;
            }
            lastPosition = arr[i];
        }
    }
    return false;
}

int binary_search(int arr[], int size, int cow)
{
    sort(arr, arr + size);  // Sorting the array for the algorithm to work correctly

    int start = 0;
    int end = arr[size - 1] - arr[0];
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossible(arr, size, cow, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 21, 3, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int cow = 2;
    int index = binary_search(arr, size, cow);
    cout << index;
}
