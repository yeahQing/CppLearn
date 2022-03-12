
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return bool布尔型
     */
    bool hasPathSum(TreeNode* root, int sum) {
        // write code here
        if (root == nullptr) return false;
        return dfs(root, sum);
    }
    
    bool dfs(TreeNode* node, int target)
    {
        if (node == nullptr) return false;
        
        target -= node->val;
        
        if (node->left == nullptr && node->right == nullptr && target == 0)
        {
            return true;
        }
        
        return dfs(node->left, target) || dfs(node->right, target);
        
    }
};