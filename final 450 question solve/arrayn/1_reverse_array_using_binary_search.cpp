#include <iostream>
using namespace std;

void binary_reverse(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
   
    while (start < end)
    {
     int  temp = arr[start];
       arr[start] = arr[end];
       arr[end] = temp ;
        
        start ++;
        end --;
    }
     
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout <<arr[i] <<" ";
    }cout <<endl;
    
}

int main (){
    
    int arr[] = {10,20,30,40,50};
    int size = 5;

   print_array(arr, size);
   
   binary_reverse(arr, size);

   print_array(arr, size);
   
   return 0;

} // namespace std;
