#include <iostream>
using namespace std;

void home (int des, int scr)
{

cout << " scr : "<<scr << " desition : " << des; 
cout <<endl;
    // base case
    if (scr == des)
    {
        cout << "pucha gya :";
        return ;
    }

    //processing 
    scr ++;
        cout << scr;
    
    // recusion call
    home(des, scr);
    
}


int main()
{
    int des = 10;
    int scr = 1;
    home(des,scr);
}