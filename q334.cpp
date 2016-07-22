#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int s = INT_MAX;
        int m = INT_MAX;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        {
            if(*it <= s)
            {
                s = *it;
            }
            else if(*it <= m)
            {
                m = *it;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    int a[] = {3,4,1,2,1};
    vector<int> nums (a, a + sizeof(a) / sizeof(a[0]));
    Solution s;
    cout<<s.increasingTriplet(nums);
}
