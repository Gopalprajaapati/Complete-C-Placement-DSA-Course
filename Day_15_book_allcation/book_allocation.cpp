#include <iostream>
using namespace std;

bool isPossible(int arr[],int size, int m,int mid)
{
    int studentCount = 1;
    int pageCount = 0;

    for (int i = 0; i < size; i++)
    {
        if (pageCount + arr[i] <= mid)
        {
           pageCount = +  arr[i];
        }else
        {
            studentCount++;
            
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            
            }
            pageCount = arr[i];

        }
        
        
    }
 return true;

}


int binary_search(int arr[], int size, int m)
{
    int start =0;
    int ans = -1;
    int sum = 0;
    
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    int end = sum;
    int mid = start + (end - start)/2;

    while (start<=end)  
    {
        if (isPossible(arr,size,m,mid))
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

int main ()
{
    int arr[] = {10,20,30,40};
    int size = 4;
    int m = 2;

    //reasone use binary search search space aa rah hai 

    int index = binary_search(arr,size,m);
    cout << index;


}