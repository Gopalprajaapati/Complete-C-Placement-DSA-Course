#include <iostream>
using namespace std;

bool find(int *arr, int size,int k)
{
 
//  using loop 

    // for (int i = 0; i < size; i++)
    // {
    //     if (arr[i]== k)
    //     {
    //         return true;
    //     }  
    // }
    // return false;  

    // using recusing 

    // base case 

    if (size ==0)
    {
       return false;
    }
    
    if (arr[0] == k)
    {
        return true;
    }

    // recusion remain part 
   
   return find(arr+1,size-1,k);

    
    



}

int main()
{

    int arr[] = {1, 1, 5, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 9;
  int ans =  find(arr, size,k);
     if (ans)
     {
         cout << " find"; 
     }else
     {
         cout << "not find"; 
     }
     
     
}
