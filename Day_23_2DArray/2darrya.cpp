#include <iostream>
using namespace std;

int main()
{
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
    int sum = 0;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {

            sum = sum + arr[col][row];
            // cout <<arr[row][col]<<endl;
        }
        cout << "col " << sum << " ";
        cout << endl;
    }

    int sum1 = 0;

    for (int col = 0; col < 3; col++)
    {
        for (int row = 0; row < 3; row++)
        {
            sum1 = sum1+arr[col][row];
        }
        cout << "row " << sum1 << " ";
        cout << endl;
    }
    
    // int largestrowsum 
int sum2= 0;
    int maxi = INT_MIN;
int rowindex = -1;
    for (int col = 0; col < 3; col++)
    {
        for (int row = 0; row < 3; row++)
        {
           sum2 = sum2+arr[row][col];
            
        }
        cout <<  "lageestsum" << sum2 <<endl;
    }
    
    if (sum2 > maxi)
    {
        maxi = sum2;
        rowindex = row;
    }
    
    cout << rowindex;

}
