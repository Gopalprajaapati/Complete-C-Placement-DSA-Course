

#include <iostream>
using namespace std;

int main()
{
    int num = 10;
    cout << "num :" << num << endl;
   

    int *ptr = &num;
    (*ptr)++;
    cout << "ptr num :" << *ptr << endl;
    cout << "num :" << num << endl;
 
//     int **q = &ptr;
//     cout << "ptr q :" << **q << endl;
//    int ***e  = **q;
//     cout << "ptr e :" << ***e << endl;
// 


    // int *q = ptr;
    // cout << "ptr a :" << *q << endl;
    // (*q)--;
    // cout << "ptr q-- :" << *q << endl;
    // (*q)--;
    // cout << "ptr --q :" << *q << endl;
    // cout << "num :" << num << endl;



}
