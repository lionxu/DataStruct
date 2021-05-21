#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<TreeNode*> generateTrees(int n){
        return build(1, n);
    }

    vector<TreeNode*> build(int low, int high){
        vector<TreeNode*> result;

        if (low > high){
            result.push_back(nullptr);
            return result;
        }

        for (int i = low; i <= high; ++i) {
            vector<TreeNode*> left = build(low, i - 1);
            vector<TreeNode*> right = build(i + 1, high);

            for (int j = 0; j < left.size(); ++j) {
                for (int k = 0; k < right.size(); ++k) {
                    auto root = new TreeNode(i);
                    root->left = left[i];
                    root->right = right[i];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};