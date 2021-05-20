#include "TreeNode.h"

class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        traverse(root, k);
        return res;
    }

    void traverse(TreeNode *root, int k) {
        if(root == nullptr) return;

        traverse(root->left, k);
        rank++;
        if(rank == k){
            res = root->val;
            return;
        }
        traverse(root->right, k);
    }

private:
    int rank = 0;
    int res = 0;
};