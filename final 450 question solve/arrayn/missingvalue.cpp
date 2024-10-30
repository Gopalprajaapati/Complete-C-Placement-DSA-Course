#include <iostream>
using namespace std;

int main ()
{
    int arr[] = {1,2,3,5,6};
    int size = sizeof(arr) / sizeof(arr[0]);
   int sum =0;
   int check =0;
  for (int i = 0; i <= size; i++)
  {
    sum = sum+ arr[i] ;
  }
  cout << sum;
  cout <<endl;
    cout << size;
     cout <<endl;

   for (int j = 0; j <= size+1 ; j++)
   {
       check = check + j;
   }
   
   cout << check;
    
    int ans = check - sum;

    cout << endl <<ans;
   
    
    
    
}