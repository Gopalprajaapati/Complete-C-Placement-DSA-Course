#include <iostream>
using namespace std;


int main()
{
     
     int arr[]=  {-1,-2,-3,-4};
 int n = sizeof(arr) / sizeof(arr[0]);
 long long  ans = 0;
 long long max = LLONG_MIN;
 for (int i = 0; i < n; i++)
 {
     ans = ans + arr[i];
    
    if (ans > max)
    {
     max = ans;
    }
      if (ans < 0) {
            ans = 0;
        }
    }

  cout << "Max contiguous subarray sum: " << max << endl;
    
    return 0;
}