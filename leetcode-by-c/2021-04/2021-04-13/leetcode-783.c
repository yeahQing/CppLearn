/* 二叉搜索树 */

#include <stdio.h>
#include <math.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*结构体变量用. 结构体指针用->*/

void middleBST(struct TreeNode *root, int *min, int *preNode)
{
    if (root == NULL)
        return;

    middleBST(root->left, min, preNode);

    if (preNode == NULL) // if (*preNode == -1)
    {
        // preNode = (int *)malloc(sizeof(int));
        *preNode = root->val;
    }
    else
    {
        *min = fmin(*min, root->val - *preNode); // (int)fmin(*min, root->val - *preNode)
        *preNode = root->val;
    }

    middleBST(root->right, min, preNode);
}

int minDiffInBST(struct TreeNode *root)
{
    // int p=-1;
    int *p = (int *)malloc(sizeof(int));
    int min = 100000;
    middleBST(root, &min, p);
    return min;
}