#include <iostream>
using namespace std;


bool shuf(string s1, string s2, string result)
{
    if (s1.length() + s2.length() != result.length())
    {
       return false;
    }
    int k =0;  int i=0; int j=0;
   while (k < result.length())
 
   
    {
       
        if (i < s1.length() && s1[i] == result[k])
        {
           i++; 
        }
      else   if (j < s2.length() && s2[j] == result[k])
        {
           j++; 
        }else {
            return false;
        }
        k++;
    }
    
      // If all characters of s1 and s2 have been used
    if (i == s1.length() && j == s2.length()) {
        return true;
    }

    
    return false;
}

int main()
{
    string s1 = "abc";
    string s2 = "def";
    string result = "adbcef";

    if (shuf(s1,s2,result)) 
    {
       cout << "string shulff:";
    }else{
        cout << "not stding shulrr";
    }
    
}