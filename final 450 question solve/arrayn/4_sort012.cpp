#include <iostream>
using namespace std;

int main()
{
    int a[] = {0, 2, 1, 0, 1, 2};
    int n = sizeof(a) / sizeof(a[0]);

    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        switch (a[mid])
        {
        case 0:
           {int temp = a[low];
            a[low] = a[mid];
            a[mid] = temp;

            low++;
            mid++;
           }
             break;
        case 1:
            mid++;
            break;
        case 2:
            int temp = a[mid];
            a[mid] = a[high];
            a[high] = temp;
            high--;
        }
    }
      for (int i = 0; i < n; i++)
        {
            cout << a[i];
        }
        cout << endl;
}
