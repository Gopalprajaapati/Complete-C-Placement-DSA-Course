#include <iostream>
using namespace std;




void arrya_print(int arr[], int size)
{
  int fin=0;
   int count =1;
    for (int i = 0; i <=size; i++)
    {
        
        
        int s=1;
        for (int j = 1; j <=size-i; j++)
        {           
            cout <<"("<<arr[i] <<","<< arr[i+s]<< ") ";
            //   cout << pos <<" ";
        s++; 
        count ++;
        }
       
       cout <<"count " <<count;
        cout << endl;
    }
     fin=fin +count;
    cout <<fin;


    
    
}


int main()
{
    int arr[] = {2,3,4,5,6};
    int size = 4;

    arrya_print(arr,size);
}