
#include <iostream>
using namespace std;

void linear_revers(int arr[],int size)
{
   int start= 0;
   int end = size-1;
   while(start <=end)
    {
    //    cout << arr[i]<<endl;
       
       swap(arr[start],arr[end]);
        start++;
        end --;
        
    }
    
}
void array_print (int arr[] , int size)
{
    for (int i = 0; i <size; i++)
    {
        cout << arr[i] <<" ";
    }
    
}

int main()
{
    cout <<"arryan linear search :" <<endl;
    int arr[5] = {10,50,40,8,4};
    int size= 5;

   linear_revers(arr,size);
  
    array_print(arr,size);
}