#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        stack<pair<TreeNode*, int>> s;
        stack<int> cntStack;
        s.push(make_pair(root, root->val));
        vector<int> tmp;
        
        while (!s.empty())
        {
            int cnt = 0;
            auto temp = s.top(); s.pop();
            tmp.push_back(temp.first->val);
            
            
            if (temp.first->left == nullptr && temp.first->right == nullptr)
            {
                if (temp.second == expectNumber)
                {
                    ans.push_back(tmp);
                }
                tmp.pop_back();
                if (!cntStack.empty())
                {
                    int t = cntStack.top(); cntStack.pop();
                    cntStack.push(t-1);
                    if (cntStack.top() == 0) {
                        tmp.pop_back();   
                        cntStack.pop();
                    }
                }
                
            }
            
            if (temp.first->right != nullptr)
            {
                s.push(make_pair(temp.first->right, temp.second + temp.first->right->val));
                cnt++;
            } 
            
            if (temp.first->left != nullptr)
            {
                s.push(make_pair(temp.first->left, temp.second + temp.first->left->val));
                cnt++;
            }
            
            if (cnt != 0)
            {
                cntStack.push(cnt);
            }
            
        }
        
        return ans;
    }
};