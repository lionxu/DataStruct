#include "ListNode.h"

class Solution {
public:
    static ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        auto *prevNode = new ListNode(-1);

        auto *prev = prevNode;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }

            prev = prev->next;
        }

        prev->next = !l1 ? l2 : l1;

        return prevNode->next;
    }
};