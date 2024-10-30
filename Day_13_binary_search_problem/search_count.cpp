#include <iostream>
using namespace std;


int main (){
    int arr[] ={10,10,40,40,40};
    int size = 5;
    int key =40;
    int count=0;
    for (int i = 0; i < size; i++)
    {

        cout <<arr[i] << endl;
        if (key == arr[i])
        {   
            count++;
        }
        
    }
    cout << "count : "<<key << ": "<<count;
} 