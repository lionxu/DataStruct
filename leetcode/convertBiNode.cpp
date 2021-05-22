#include "TreeNode.h"

class Solution {
public:
    TreeNode *convertBiNode(TreeNode *root) {
        dummy = new TreeNode(0);
        traverse(root);
        return dummy->right;
    }

    void traverse(TreeNode *root) {
        if (root != nullptr) {
            traverse(root->left);

            if (prev != nullptr) {
                prev->right = root;
                prev = root;
            } else {
                prev = root;
                dummy->right = prev;
            }

            root->left = nullptr;
            traverse(root->right);
        }
    }

private:
    TreeNode *prev;
    TreeNode *dummy;
};