#include "TreeNode.h"
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSumBST(TreeNode *root) {
        traverse(root);
        return result;
    }

    static bool isValidBST(TreeNode *root, TreeNode *min, TreeNode *max) {
        if (root == nullptr) return true;
        if (min != nullptr && root->val <= min->val) return false;
        if (max != nullptr && root->val >= max->val) return false;
        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }

    int sumBST(TreeNode *root) {
        if (root == nullptr) return 0;
        int current_sum = root->val + sumBST(root->left) + sumBST(root->right);
        result = max(current_sum, result);
        return current_sum;
    }

    void traverse(TreeNode *root) {
        if (isValidBST(root, nullptr, nullptr)) {
            sumBST(root);
            return;
        }
        traverse(root->left);
        traverse(root->right);
    }

private:
    int result = 0;
};