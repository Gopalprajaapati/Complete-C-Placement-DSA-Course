#include <iostream>
using namespace std;

int main()
{
    cout<<"Hollw Rectangle patten :" << endl;

    int row,col;
    cin >> row;
    cin >> col;

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
             if (j==1 || j==col)
            {
              cout <<"8";      
            }   
            else if (i==1 || i==row)
            {
              cout <<"8";      
            }else
            {
                cout <<" ";      
            }
            
                      
        }
       cout <<endl;  
    }
    
}