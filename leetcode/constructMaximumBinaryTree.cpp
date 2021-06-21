#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return build(nums, 0, nums.size());
    }

    /**
     * 构建最大二叉树
     * @param nums
     * @param low
     * @param high
     * @return
     */
    TreeNode* build(vector<int>& nums, int low, int high){
        if (low > high) return nullptr;

        int index = -1;
        int max_value = -1e5;
        for (int i = low; i <= high; ++i) {
            if (nums[i] > max_value){
                index = i;
                max_value = nums[i];
            }
        }

        auto *root = new TreeNode(max_value);
        root->left = build(nums, low, index - 1);
        root->right = build(nums, index + 1, high);

        return root;
    }
};