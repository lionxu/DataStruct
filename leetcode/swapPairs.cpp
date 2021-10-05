#include "ListNode.h"

class Solution {
public:
    static ListNode* swapPairs(ListNode *head) {
        auto* dummy = new ListNode(-1, head);
        auto* tmp = dummy;

        while (tmp->next && tmp->next->next) {
            auto *node1 = tmp->next;
            auto *node2 = tmp->next->next;

            tmp->next = node2;
            node1->next = node2->next;
            node2->next = node1;

            tmp = node1;
        }

        ListNode* ans = dummy->next;

        delete dummy;

        return ans;
    }
};