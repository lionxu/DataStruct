#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int  x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    TreeNode *invertTree(TreeNode *root){
        if (root == nullptr) return nullptr;

        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
    void traverse(TreeNode *root){
        if (root != nullptr) {
            cout << root->val << endl;
            traverse(root->left);
            traverse(root->right);
        }
    }
};

int test_invertTree() {
    Solution solution;

    auto *root = new TreeNode(4);
    auto *child1 = new TreeNode(2);
    auto *child2 = new TreeNode(7);
    root->left = child1;
    root->right = child2;
    auto *child3 = new TreeNode(1);
    auto *child4 = new TreeNode(3);
    child1->left = child3;
    child1->right = child4;
    auto *child5 = new TreeNode(6);
    auto *child6 = new TreeNode(9);
    child2->left = child5;
    child2->right = child6;

    solution.traverse(root);

    cout << endl;

    root = solution.invertTree(root);

    solution.traverse(root);

    return 0;
}