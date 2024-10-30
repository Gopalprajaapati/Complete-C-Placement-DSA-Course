#include <iostream>
using namespace std ;


int fib_number(int n){
    
    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;     

    }
    
    int ans= fib_number(n-1)+fib_number(n-2);
    return ans;
}
int main ()
{
    cout <<"Fibnom number first 0 and second 1 : ";
    cout <<"Next number enter : ";
    int n ;
    cin >>n;
    int ans = fib_number(n);
    cout << ans;
}