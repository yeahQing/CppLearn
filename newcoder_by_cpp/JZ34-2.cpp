
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(right) {}
};

class Solution
{
public:
    using vvi = vector<vector<int>>;
    using vi = vector<int>;
    void dfs(TreeNode *root, int sum, vi &path, vvi &ret)
    {
        path.push_back(root->val);
        if (sum == root->val && !root->left && !root->right)
        {
            ret.push_back(path);
        }
        if (root->left)
            dfs(root->left, sum - root->val, path, ret);
        if (root->right)
            dfs(root->right, sum - root->val, path, ret);
        path.pop_back(); // 代码走到这里，表明要回溯，代表当前path中的root节点我已经不需要了
    }
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        vvi ret;
        vi path;
        if (!root)
            return ret;
        dfs(root, expectNumber, path, ret);
        return ret;
    }
};
