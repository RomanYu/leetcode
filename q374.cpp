#include<iostream>
#include<climits>

using namespace std;

int guess(int num);

class Solution
{
    public:
        int guessNumber(int n)
        {
           int l = 1;
            int r = n;
            while(l <= r)
            {
                int mid = l + (r - l) / 2;
                int ret = guess(mid);
                if(ret == 0)
                {
                    return mid;
                }
                else if (ret == -1)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            return l;
        }
};
