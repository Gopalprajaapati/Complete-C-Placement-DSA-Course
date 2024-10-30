#include <iostream>
using namespace std;
void busort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

 void getMinDiff(int arr[], int n, int k) {
        if (n == 0)
        {
         cout << 0;  
        }
        busort(arr, n);
        int first = arr[0] + k;
        int last = arr[n-1] -k;

        int ans = last - first;
        cout<< "ans : " << ans;
        cout<< "last - : "<<last;
        cout<< "fisrt: "<<first;
          cout<< "ans : " << ans <<" ";
        cout << endl;

    }


int main()
{
    int arr[] = {1, 5, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
int k = 2;
    busort(arr, size);
    getMinDiff(arr,size,k);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout <<endl;

    return 0;
}
