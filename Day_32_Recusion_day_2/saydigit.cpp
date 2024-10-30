#include <iostream>
using namespace std;

void syadigit(int n,string arr[])
{

     if (n == 0)
     {
            return ;
     }
     
    int rem = n%10;
     n = n/10;
      syadigit(n,arr);
   cout << arr[rem];
  

    
    
}

int main()
{
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int n ;
    cin >> n;
    syadigit(n,arr);
            
}
