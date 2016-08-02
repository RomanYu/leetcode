#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    private:
        void qsort(vector<int>& vec, int i, int j)
        {
            if(i >= j)
                return;
            int low = i;
            int high = j;
            int pivot = vec[low];
            while(low < high)
            {
                while(low < high && vec[high] >= pivot)
                {
                    --high;
                }
                vec[low] = vec[high];
                while(low < high && vec[low] <= pivot)
                {
                    ++low;
                }
                vec[high] = vec[low];
            }
            vec[low] = pivot;
            qsort(vec, i, low - 1);
            qsort(vec, low + 1, j);
        }
    public:
        int hIndex(vector<int>& citations)
        {
            qsort(citations, 0, citations.size() - 1);
            int i = 0;
            for(; i < int(citations.size()); ++i)
            {
                if(int(citations.size()) - i <= citations[i])
                {
                    break;
                }
            }
            return int(citations.size()) - i;
        }
};

int main()
{
    int a[] = {3,3,3,3};
    //int a[] = {232,161,89,177,117,212,126,247,155,197,88,217,81,207};
    vector<int> vec (a, a + sizeof(a) / sizeof(a[0]));
    Solution s;
    //s.hIndex(vec);
    cout<<s.hIndex(vec)<<endl;
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        cout<<*it<<" ";
    }
}
