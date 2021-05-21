#include "TreeNode.h"

class Solution {
    TreeNode *searchBST(TreeNode *root, int val) {
        if(root == nullptr) return nullptr;
        else if(root->val == val) return root;
        else if(root->val > val) return searchBST(root->left, val);
        else if(root->val < val) return searchBST(root->right, val);
        return nullptr;
    }
};