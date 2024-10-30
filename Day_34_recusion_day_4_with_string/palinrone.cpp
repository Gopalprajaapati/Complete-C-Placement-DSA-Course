#include <iostream>
using namespace std;

bool chech(string name, int i, int n)
{
    // Base case: when start index is greater than or equal to end index
    if (i >= n)
    {
        return true;
    }

    // Compare the characters at the start and end indices
    if (name[i] != name[n])
    {
        return false;
    }

    // Recursive call to check the next pair of characters
    return chech(name, i + 1, n - 1);
}



//using biary search ;

// bool chech(string name, int n )
// {
//     int s =0;
//     int e = n;

//     while (s<=e)
//     {
//         if (name[s] != name[e])
//         {
//             return false;
//         }
//         s++;
//         e--;
//     }
//     return true;
// }

int main()
{
    string name = "noon";
    int n = name.length() - 1;
    bool ans = chech(name, 0, n); // Start the recursion with the first and last index
    if (ans)
    {
        cout << "pali";
    }
    else
    {
        cout << "not pali ";
    }
    return 0;
}