//arr are sort value and dulipicate value position show

#include <iostream>
using namespace std;

int last_occ(int arr[], int size, int key)
{
    int ans =-1;
    int start =0;
    int end =size-1;
    
    while (start<=end)
    {
        int mid = start + (end - start) / 2;
       
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid+1;
        }
       else if (key > arr[mid])
        {
          start = mid+1;
        }else if (key < arr[mid] )
        {
            
           end = mid-1;
        }      
        
    }
    
 return ans;

}


int fisrt_occ(int arr[], int size, int key)
{
    int ans =-1;
    int start =0;
    int end =size-1;
    
    while (start<=end)
    {
        int mid = start + (end - start) / 2;
       
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid-1;
        }
       else if (key > arr[mid])
        {
          start = mid+1;
        }else if (key < arr[mid] )
        {
            
           end = mid-1;
        }      
        
    }
    
 return ans;

}

int main()
{
    cout <<"Fist and last position value duplication nunmber : " <<endl;
    int arr[5] ={0,1,1,1,2};
    int size = 5;
    int key = 1;

    int index = fisrt_occ(arr,size,key);
    cout << "first Occ value index "  << index <<endl;
    int index1 = last_occ(arr,size,key);
    cout << "last  Occ value index "  << index1 <<endl;
    int total_occ = (index1 - index)+1;
    cout <<"Total occ of number : "<<total_occ;
}
