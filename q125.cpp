#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s)
    {
        string::iterator it1 = s.begin();
        string::iterator it2 = s.end() - 1;
        for(;it1 < it2;)
        {
            if(ispunct(*it1) || isspace(*it1))
                ++it1;
            else if(ispunct(*it2) || isspace(*it2))
                --it2;
            else if(tolower(*it1) == tolower(*it2))
            {
                ++it1;
                --it2;
            }
            else
                return false;
        }
        return true;
    }
};

int main()
{
    string ss = "0P";
    Solution s;
    cout<<s.isPalindrome(ss)<<endl;
}

