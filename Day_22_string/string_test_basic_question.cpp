#include <iostream>
using namespace std;

int main()
{
    string name ="Gopal";
    char onlyone[] = "Gopal";
    cout << onlyone;
    cout <<name;
    cout <<endl;
    for (int i = 0; i < name.length(); i++)
    {
        cout <<name[i] <<" ";
    }
    
    for (int j = 0; j < 5; j++)
    {
        cout << onlyone[j] << "g";
    }

    // char length  using funcation 

    cout << " char onlyone length : " << endl;

    
        int count = 0;
        for (int i = 0; i < onlyone[i]!='\0'; i++)
        {
            count++;

        }
        cout << count ;        
   

   cout << endl;

cout << "string revers :" ;
   cout << endl;

    char rev_name[] = "gopal5";
    int len = sizeof(rev_name)/ sizeof(rev_name[0])-2;
    for (int i = len; i >= 0; i--)
    {
        cout << rev_name[i];
    }
    cout << endl;
    cout << endl;
    cout << endl;
        // char rev_name[] = "gopal";
    // int len = sizeof(rev_name) / sizeof(rev_name[0]) - 2;  // Calculate the length of the string excluding the null terminator

    for (int i = len; i >= 1; --i) {
        cout << rev_name[i];
    }

    cout << endl;
    
    
    cout << " using binary search revers  prajapati:";
    cout << endl;
    cout << endl;

    char word[] = "prajapati";
  int n = sizeof(word)/ sizeof(word[0]);

  int start = 0;
  int end = n-1;

  while ( start <= end)
  {
     
        {
            swap(word[start] , word[end]);
        }
        start ++;
        end --;
  }
    for (int i = 0; i < n; i++)
    {
        cout << word[i];
    }
    

    cout << "chek paidrome : staring : noon" ;
    cout << endl;
    cout << endl;

    char pai[] = "nofvon";
    int p_n = sizeof(pai)/ sizeof(pai[0]);

      int start1 = 0;
  int end1 =(p_n) - 1;

    while (start1 <= end1)
    {
        if (pai[start]!=pai[end1])
        {  
            return 0;
        }else{
            start1++;
            end --;
        }
       
    }
      
       cout << "not paildrome";
         for (int i = 0; i < p_n; i++)
    {
        cout << pai[i];
    }


//     cout << " upper level to lower level ";
    
//    char ch = 'G';  // Use single quotes to assign a character

//     if (ch >= 'a' && ch <= 'z') {  // Use logical AND operator &&
//         cout << ch;
//     } else {
//         char temp = ch - 'A' + 'a';  // Convert uppercase to lowercase
//         cout << temp;
//     }

    cout << endl;
cout <<"steering : ";
string s = "gergwee##$%%%%tb45645464df";
    string filtered;
    
    // Step 1: Filter out non-alphanumeric characters and convert to lowercase
    for (char c : s) {
        if (isalnum(c)) {
            filtered += tolower(c);
        }
    }
    cout <<filtered;
    
    


   
}