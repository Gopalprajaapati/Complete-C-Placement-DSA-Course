#include <iostream>
using namespace std;
// namespace std;

int main()
{
    cout <<"inverted half pyramed";
     cout <<endl;
    int row,col;
    cin >>row;
    cin >>col;
    

    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= col; j++)
        {
            cout <<i;
            cout << "*";
        }
        cout <<endl;
    }
    
}
