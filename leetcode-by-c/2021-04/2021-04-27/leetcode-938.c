/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* 深度优先遍历 DFS */
int rangeSumBST_dfs(struct TreeNode *root, int low, int high) {
    if (root == NULL) {
        return 0;
    }
    /* 如果当前的值大于区间右端点，那节点右边的值一定都比右端点大, 所以找小的 */
    if (root->val > high) {
        return rangeSumBST(root->left, low, high);
    }
    /* 如果当前的值小于区间左端点，那节点左边的值一定都比左端点小，所以找大的 */
    if (root->val < low) {
        return rangeSumBST(root->right, low, high);
    }
    /* 依次递归返回节点的和，不需要全局变量 */
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}

/* 广度优先遍历 BFS */
int rangeSumBST_bfs(struct TreeNode *root, int low, int high) {
    int sum = 0;
    /* 
        指针数组 []的优先级比*高 
        int (*p)[4] = a; 这个必须加括号，否则就变成了指针数组
        int *p[4] 指针数组
        int (*p)[4] 二维数组指针
    */
    struct TreeNode *q[40000];
    int left = 0, right = 0;
    q[right++] = root;
    while (left < right) {
        struct TreeNode *node = q[left++];
        if (node == NULL) {
            continue;
        }
        if (node->val > high) {
            q[right++] = node->left;
        } else if (node->val < low) {
            q[right++] = node->right;
        } else {
            sum += node->val;
            q[right++] = node->left;
            q[right++] = node->right;
        }
    }
    return sum;
}
