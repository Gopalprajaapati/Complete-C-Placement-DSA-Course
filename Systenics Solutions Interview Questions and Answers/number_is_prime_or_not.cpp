#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n ;
    cin >>n;

    if (n <= 1)
    {
        cout << "Number is not prime : " <<n;
    }
    else
    {
        bool isprime = true;
        for (int i = 2; i <+sqrt(n); i++)
        {
            if (n %2 == 0)
            {
                isprime = false;
                break;
            }
            
        }
         if (isprime)
    {
        cout << "Number is  prime : " <<n;
    }else
    {
        cout << "Number is not prime : " <<n;
    }
    
    }
   
    
    
    
}