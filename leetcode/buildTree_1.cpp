#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode *buildTree(vector<int> preorder, vector<int> inorder) {
        return build(preorder, 0, preorder.size() -1, inorder, 0, inorder.size() - 1);
    }

    /**
     * 构建二叉树
     * @param preorder
     * @param pre_start
     * @param pre_end
     * @param inorder
     * @param in_start
     * @param in_end
     * @return
     */
    TreeNode *build(vector<int> preorder, int pre_start, int pre_end, vector<int> inorder, int in_start, int in_end) {
        if (pre_start > pre_end) return nullptr;

        int root_value = preorder[pre_start];

        int index = 0;
        for (int i = in_start; i < in_end; i++) {
            if (inorder[i] == root_value){
                index = i;
                break;
            }
        }

        int left_size = index - in_start;

        auto *root = new TreeNode(root_value);
        root->left = build(preorder, pre_start + 1, pre_start + left_size, inorder, in_start, index - 1);
        root->right = build(preorder, pre_start + left_size + 1, pre_end, inorder, index + 1, in_end);
        return root;
    }
};