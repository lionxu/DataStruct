#include "TreeNode.h"

class Solution {
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (root == nullptr) return new TreeNode(val);
        else if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        } else if (root->val < val) {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};