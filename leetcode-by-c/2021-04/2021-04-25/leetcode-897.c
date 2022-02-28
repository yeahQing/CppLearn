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

struct TreeNode* createTreeNode(int val) {
    struct TreeNode* ret = malloc(sizeof(struct TreeNode));
    ret->val = val, ret->left = ret->right = NULL;
    return ret;
}

struct TreeNode* resNode;

void inorder(struct TreeNode* node) {
    if (node == NULL) {
        return;
    }
    inorder(node->left);

    // 在中序遍历的过程中修改节点指向
    resNode->right = node;
    node->left = NULL;
    resNode = node;

    inorder(node->right);
}
struct TreeNode* increasingBST(struct TreeNode* root) {
    struct TreeNode* dummyNode = createTreeNode(-1);
    resNode = dummyNode;
    inorder(root);
    return dummyNode->right;
}