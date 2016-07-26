#include<iostream>

using namespace std;

class Solution
{
    public:
        bool isPerfectSquare(int num)
        {
            int i = 1;
            int j = 46340;
            while(i <= j)
            {
                int mid = (i + j) / 2;
                int squareMid = mid * mid;
                if(squareMid == num)
                    return true;
                else if(squareMid > num)
                    j = mid - 1;
                else
                    i = mid + 1;
            }
            return false;
        }
};

int main()
{
    Solution s;
    cout<<s.isPerfectSquare(9);
}
