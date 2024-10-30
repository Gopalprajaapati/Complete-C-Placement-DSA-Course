#include <iostream>
using namespace std;

void stringrev(string name, int n) { 
    if (n > 0) { 
        // cout << name[n-1]; 
      cout <<  stringrev(name, n-1); 
    }
}

int main() {
    string name = "gopal";
    int n = name.size();
    stringrev(name, n);
    return 0;


        // for (int i = n; i >= 0; i--)
        // {
        //     cout << name[i];
        // }

    //   int start = 0;
    //   int end = n;
    //   while (start <=end )

    //   {
    //     int temp = name[start];
    //     name[start] = name[end];
    //     name[end] = temp;

    //     start ++;
    //     end--;    
    //   }
    
    //   for (int i = 0; i <=n; i++)
    //   {
    //     cout << name[i];
    //   }
    


        
        
        
    }