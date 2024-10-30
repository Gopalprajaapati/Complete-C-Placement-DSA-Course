#include <iostream>
using namespace std;

bool isPossible(int arr[], int size,int p,int mid)
{
    int painter = 1;
    int unittime = 0;

    for (int i = 0; i <size; i++)
    {
        if (unittime + arr[i] <= mid)
        {
            unittime + arr[i];
        }else
        {
            painter++;
            if (painter > p || arr[i] > mid)
            {
                return false;
            }
            unittime = arr[i];
        }
        
    }
    return true;
}

int binaery_search(int arr[], int size, int p)
{
    int start = 0;
    int ans = -1;
    int sum =0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }

    int end = sum;
    int mid = start + (end - start)/2;

    while (start <= end)
    {
        if (isPossible(arr,size,p,mid))
        {
            ans = mid;
            end = mid - 1;
        }else
        {
            start = mid + 1;
        }       
        mid = start + (end - start)/2;
    }
    return ans;

    
}

int main()
{
    cout << "gopal ";
    int arr[] = {50,20,15,50};
    int size =4;
    int p=2;

    int paiter = binaery_search(arr, size, p);
    cout << paiter;
}