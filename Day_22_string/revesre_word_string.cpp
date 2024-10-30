#include <iostream>
#include <algorithm> // for reverse
#include <string>

using namespace std;

class Solution
{
public:
    void reverseWords(string &s)
    {
        reverse(s.begin(), s.end());

        int start = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (i == s.size() || s[i] == ' ')
            {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
    }
};

int main()
{
    Solution solution;
    string s = "the sky is blue";

    solution.reverseWords(s);

    cout << '"' << s << '"' << endl; // Output: "blue is sky the"

    return 0;
}