
#include <iostream>
using namespace std;

int linear_search(int arr[],int size,int key)
{
    for (int i = 0; i <=size; i++)
    {
       if (key == arr[i])
       {
       return 1;        
       }   
    }
    return 0;
}


int main()
{
    cout <<"arryan linear search :" <<endl;
    int arr[6] = {10,50,40,8,4,6};
    int size= 6;
    int key;
    cout << "search linear element : " <<endl;
    cin >>key;
   bool found =   linear_search(arr,size,key);

    if (found)
    {
        cout <<"key is found"<<endl;
    }else
    {
         cout <<"key is not  found"<<endl;
    }
    
    

}