#include "TreeNode.h"

class Solution {
public:
    TreeNode *convertBST(TreeNode *root) {
        traverse(root);
        return root;
    }

    void traverse(TreeNode *root) {
        if(root == nullptr) return;
        traverse(root->right);
        sum += root->val;
        root->val = sum;
        traverse(root->left);
    }

private:
    int sum = 0;
};
