#include "TreeNode.h"
#include "ListNode.h"

class Solution {
public:
    static TreeNode *sortedListToBST(ListNode *head) {
        int length = get_length(head);
        return build_tree(head, 0, length - 1);
    }

private:
    static int get_length(ListNode *head) {
        int length = 0;

        while (head) {
            length++;
            head = head->next;
        }

        return length;
    }

    static TreeNode *build_tree(ListNode *&head, int left, int right) {
        if (left > right) return nullptr;

        int mid = (left + right + 1) / 2;

        auto *root = new TreeNode();
        root->left = build_tree(head, left, mid - 1);
        root->val = head->val;
        head = head->next;
        root->right = build_tree(head, mid + 1, right);

        return root;
    }
};