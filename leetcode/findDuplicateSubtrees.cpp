#include <vector>
#include <unordered_map>
#include <string>
#include "TreeNode.h"

using namespace std;

class Solution {
private:
    vector<TreeNode*> result;
    unordered_map<string, int> history;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode *root){
        traverse(root);
        return result;
    }

    /**
     * 辅助函数
     * @param root
     * @return
     */
    string traverse(TreeNode *root){
        if (root == nullptr) return string("#");

        string left = traverse(root->left);
        string right = traverse(root->right);

        string sub_tree = left + "," + right + "," + to_string(root->val);

        if (history[sub_tree] == 1){
            result.push_back(root);
        }

        history[sub_tree]++;
        return sub_tree;
    }
};