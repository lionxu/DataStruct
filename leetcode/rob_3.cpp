#include <vector>
#include <iostream>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    int rob_3(TreeNode *root) {
        vector<int> result = dp_3(root);

        return max(result[0], result[1]);
    }

private:
    vector<int> dp_3(TreeNode *root) {
        if (root == nullptr) return vector<int>(2, 0);

        vector<int> left = dp_3(root->left);
        vector<int> right = dp_3(root->right);

        int do_rob = root->val + left[0] + right[0];
        int no_rob = max(left[0], left[1]) + max(right[0], right[1]);

        vector<int> result(2, 0);
        result[0] = no_rob;
        result[1] = do_rob;
        return result;
    }
};

int test_rob_3() {
    Solution solution;

    auto *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = nullptr;
    root->left->right = new TreeNode(3);
    root->right->left = nullptr;
    root->right->right = new TreeNode(1);

    cout << solution.rob_3(root) << endl;

    return 0;
}