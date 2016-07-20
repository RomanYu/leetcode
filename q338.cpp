#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
        vector<int> countBits(int nums)
        {
            vector<int> ret;
            ret.push_back(0);
            int last_power_of_two = 0;
            for(int i = 1; i <= nums; i++)
            {
                if((i & (i - 1)) == 0)
                {
                    last_power_of_two = i;
                    ret.push_back(1);
                }
                else
                {
                    ret.push_back(ret[last_power_of_two] + ret[i - last_power_of_two]);
                }
            }
            return ret;
        }
};

int main()
{
    Solution s;
    vector<int> ret = s.countBits(8);
    for(vector<int>::iterator it = ret.begin(); it != ret.end(); ++it)
    {
        cout<<*it<<" "<<endl;
    }
}
