#include "ListNode.h"

class Solution {
public:
    static ListNode* reverseKGroup(ListNode *head, int k) {
        auto *dummy = new ListNode(-1, head);

        auto *pre = dummy;
        auto *end = dummy;

        while (end->next) {
            for (int i = 0; i < k && end; ++i) {
                end = end->next;
            }

            if (!end) break;

            auto *start = pre->next;
            auto *next = end->next;
            end->next = nullptr;
            pre->next = reverse(start);
            start->next = next;
            pre = start;
            end = pre;
        }

        auto *ans = dummy->next;
        delete dummy;
        return ans;
    }

private:
    static ListNode* reverse(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *curr = head;

        while (curr) {
            ListNode *next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }

        return pre;
    }
};