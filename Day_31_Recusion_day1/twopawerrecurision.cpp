#include <iostream>
using namespace std;


int twopwer(int n)
{
    if (n ==0)
    {
        return 1;
    }
    return 2*twopwer(n-1);
}

int main (){
    cout << "two pwer n : ";
    int n;
    cin >> n;

 
int ans =twopwer(n);
    cout << ans;


} 
