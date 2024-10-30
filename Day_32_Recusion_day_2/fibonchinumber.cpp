#include <iostream>
using namespace std;

int fib(int n)
{

    int n1 = 0;
    int n2 = 1;
    //base case
    if (n1 == n)
    {
        return 0;
    }
    if (n2 == n)
    {
        return 1;
    }

    //  proessing 
    n = fib(n - 1) + fib(n - 2);

    //  recusion call
    return n;
}

int main()
{
    cout << "Enter number fibolchi  :";

    int n;
    cin >> n;
    int ans = fib(n);
    cout << ans;
}