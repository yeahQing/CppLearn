#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

class Solution
{
public:
    /**
     *
     * @param root TreeNode类
     * @param sum int整型
     * @return bool布尔型
     */
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return false;
        // write code here
        stack<pair<TreeNode *, int>> s;
        s.push(make_pair(root, root->val));

        while (!s.empty())
        {
            auto temp = s.top();
            s.pop();

            if (temp.first->left == nullptr && temp.first->right == nullptr && temp.second == sum)
            {
                return true;
            }

            if (temp.first->left != nullptr)
            {
                s.push(make_pair(temp.first->left, temp.second + temp.first->left->val));
            }

            if (temp.first->right != nullptr)
            {
                s.push(make_pair(temp.first->right, temp.second + temp.first->right->val));
            }
        }
        return false;
    }
};