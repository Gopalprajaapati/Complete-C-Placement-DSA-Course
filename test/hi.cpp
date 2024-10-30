#include <iostream>
using namespace std;

int main()
{
    int arr[] = {0, 2, 1, 2, 0};
    int n = sizeof(a) / sizeof(a[0]);

  
      long long max = LLONG_MIN; // Initialize to the smallest possible long long integer
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            ans += arr[i];

            if (max < ans) {
                max = ans;
            }

            if (ans < 0) {
                ans = 0;
            }
        }

        return max;
    }

        for (int i = 0; i < n; i++)
        {
            cout << a[i];
        }
        cout << endl;
    }
    }