#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    cout << "Enter the three Langest number: ";
    cin >> a>>b>>c;

    if (a>b && a>c)
    {
        cout << " Langest number is a: " <<a;
    }else if (b>a && b >c)
    {
        cout << " Langest Number is b :" << b;

    }else{
        cout << "langest Number is c : "<<c;
    }
    
}