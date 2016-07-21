#include<iostream>
#include<vector>
#include<stack>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> sta;
        if(!root)
            return ret;
        TreeNode* node = root;
        while(node || !sta.empty())
        {
            while(node)
            {
                sta.push(node);
                node = node -> left;
            }
            if(!sta.empty())
            {
                node = sta.top();
                sta.pop();
                ret.push_back(node -> val);
                node = node -> right;
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    TreeNode* one = new TreeNode(1);
    TreeNode* two = new TreeNode(2);
    TreeNode* three = new TreeNode(3);
    TreeNode* four = new TreeNode(4);
    TreeNode* five = new TreeNode(5);
    one -> left = two;
    one -> right = three;
    two -> left = four;
    two -> right = five;
    vector<int> ret = s.inorderTraversal(one);
    for(vector<int>::iterator it = ret.begin(); it != ret.end(); ++it)
    {
        cout<<*it<<" ";
    }
}
