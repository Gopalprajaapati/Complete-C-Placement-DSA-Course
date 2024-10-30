#include <iostream>
using namespace std;

void mage_sort (int arr1[], int size1,int arr2[], int size2 , int arr3[])
{
    int i = 0; int j= 0;
    int k = 0;
    while (i < size1 && j < size2 )
    {
       if (arr1[i] < arr2[j])
       {
            arr3[k++] = arr1[i++];
       }else
       {
         arr3[k++] = arr2[j++];
       }
       
    }
    
    while (i < size1)
    {
         arr3[k++] = arr1[i++];
    }
    while (j <size2)
    {
         arr3[k++] = arr2[j++];
    }
    
}



void array_print (int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] <<" ";
    }cout <<endl;
    
}

int main()
{
    int arr1[] = {1,2,3,4,6 ,5,7,8}; 
    int arr2[] ={9,10,12,13,50};
    int size1 = 8;
    int size2 = 5 ;
       int size3 =size1 + size2 ;
    int arr3[size3] ;
 
    mage_sort (arr1, size1, arr2, size2 , arr3);
     array_print(arr3,size3);
     
     return 0;
}