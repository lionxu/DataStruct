#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution{
public:
    TreeNode* balanceBST(TreeNode *root){
        traverse(root);
        return build(0, inorder.size() - 1);
    }

    void traverse(TreeNode *root){
        if (root == nullptr) return;
        traverse(root->left);
        inorder.push_back(root->val);
        traverse(root->right);
    }

    TreeNode* build(int low, int high){
        if (low > high) return nullptr;
        int mid = (low + high) / 2;
        auto *root = new TreeNode(inorder[mid]);
        root->left = build(low, mid - 1);
        root->right = build(mid + 1, high);
        return root;
    }

private:
    vector<int> inorder;
};