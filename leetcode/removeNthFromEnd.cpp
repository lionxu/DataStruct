#include "ListNode.h"

class Solution {
public:
    static ListNode *removeNthFromEnd(ListNode *head, int n) {
        auto *dummy = new ListNode(0, head);

        auto *fast = head;
        auto *slow = dummy;

        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        auto *ans = dummy->next;

        delete dummy;

        return ans;
    }
};