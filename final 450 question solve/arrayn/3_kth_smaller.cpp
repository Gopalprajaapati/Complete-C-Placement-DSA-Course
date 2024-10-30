#include <iostream>
using namespace std;


void bubsort(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < n-i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}



void array_print(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  int arr[] = {7,10, 4, 20,  15};
  int k = 4;
  int l = 0;
  int r = 5;

  int ans = 0;
array_print(arr,r);
bubsort(arr,r);


  for (int i = 0; i < r; i++)
  {
    if (arr[i] ==arr[k-1])
    {
      ans = arr[k-1];
    }
    
    
  }
  cout << ans;




}
