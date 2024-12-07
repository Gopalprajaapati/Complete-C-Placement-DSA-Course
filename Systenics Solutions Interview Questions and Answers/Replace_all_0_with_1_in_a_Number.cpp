// Replace all 0’s with 1’s in a Number.
#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int rem;
  int ans = 0;
  int multiplier = 1;
  while (n > 0)

  {
    rem = n % 10;
    if (rem == 0)
    {
      rem = 1;
    }
    ans = ans + rem * multiplier;
    multiplier = multiplier * 10;
    n = n / 10;
  }

  cout << ans;
}