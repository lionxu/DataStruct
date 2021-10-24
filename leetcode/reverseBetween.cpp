#include "ListNode.h"

class Solution {
public:
    static ListNode *reverseBetween(ListNode *head, int left, int right) {
        auto *dummy = new ListNode(-1, head);

        auto *pre = dummy;

        for (int i = 0; i < left - 1; ++i) {
            pre = pre->next;
        }

        auto *end = pre;

        for (int i = 0; i < right - left + 1; ++i) {
            end = end->next;
        }

        auto *start = pre->next;
        auto *next = end->next;

        end->next = nullptr;

        reverse(start);

        pre->next = end;
        start->next = next;

        return dummy->next;
    }

private:
    static void reverse(ListNode *head) {
        ListNode *pre = nullptr;
        auto *curr = head;

        while (curr) {
            auto *next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
    }
};
