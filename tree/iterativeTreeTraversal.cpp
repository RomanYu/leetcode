#include<iostream>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    public:
        void inOrderTraversal(TreeNode* root)
        {
            if(!root)
            {
                return;
            }
            stack<TreeNode*> s;
            TreeNode* node = root;
            while(node || !s.empty())
            {
                while(node)
                {
                    s.push(node);
                    node = node -> left;
                }
                if(!s.empty())
                {
                    node = s.top();
                    s.pop();
                    cout<<node -> val<<endl;
                    node = node -> right;
                }
            }
        }
        void preOrderTraversal(TreeNode* root)
        {
            if(!root)
            {
                return;
            }
            stack<TreeNode*> s;
            TreeNode *node = root;
            while(node || !s.empty())
            {
                while(node)
                {
                    cout<<node -> val<<endl;
                    s.push(node);
                    node = node -> left;
                }
                if(!s.empty())
                {
                    node = s.top();
                    s.pop();
                    node = node -> right;
                }
            }
        }
};


int main()
{
    TreeNode* one = new TreeNode(1);
    TreeNode* two = new TreeNode(2);
    TreeNode* three = new TreeNode(3);
    TreeNode* four = new TreeNode(4);
    TreeNode* five = new TreeNode(5);
    one -> left = two;
    one -> right = three;
    two -> left = four;
    two -> right = five;
    Solution s;
    s.inOrderTraversal(one);
    s.preOrderTraversal(one);
}
