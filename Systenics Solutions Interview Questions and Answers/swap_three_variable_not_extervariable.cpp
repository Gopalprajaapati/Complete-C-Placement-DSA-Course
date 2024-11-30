#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 20;
    int c = 30;

    a = a + b + c;
    b = a - (b + c);
    c = a - (b + c);
    a = a - (b + c);
    cout << a << " " << b << " " << c;
}