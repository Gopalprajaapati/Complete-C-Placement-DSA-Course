#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

int  main ()
{
    int row,col;
    cin >> row;
    cin >> col;
    for (int i = 0; i <= row; i++)
    {
        for (int i = 0; i <= col; i++)
        {
            cout <<"*" ;
        }
        cout <<endl;
    }
    


}