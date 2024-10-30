#include <iostream>
using namespace std;

void reverse(int arr[], int size)
{
    int revs[size];
     for (int i = 1; i <= size; i++)
    {
      revs[i] =+ arr[size-i];
     cout << revs [i] <<" ";
    }
    // return true ;
}

int main (){
    
    int arr[] = {10,20,30,40,50};
    int size = 5;

   reverse(arr, size);
   

} // namespace std;
