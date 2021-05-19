#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
    TreeNode *buildTree(vector<int> inorder, vector<int> postorder) {
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    /**
     * 构建二叉树
     * @param inorder
     * @param in_start
     * @param in_end
     * @param postorder
     * @param post_start
     * @param post_end
     * @return
     */
    TreeNode* build(vector<int>& inorder, int in_start, int in_end, vector<int>& postorder, int post_start, int post_end) {
        if (in_start > in_end) return nullptr;

        int root_value = postorder[post_end];
        int index = 0;
        for (int i = in_start; i <= in_end; ++i) {
            if (inorder[i] == root_value){
                index = i;
                break;
            }
        }

        int left_size = index - in_start;

        auto *root = new TreeNode(root_value);
        root->left = build(inorder, in_start, index - 1, postorder, post_start, post_start + left_size - 1);
        root->right = build(inorder, index + 1, in_end, postorder, post_start + left_size, post_end - 1);
        return root;
    }
};