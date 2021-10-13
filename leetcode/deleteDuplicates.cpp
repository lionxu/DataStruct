#include "ListNode.h"

class Solution {
public:
    static ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return head;

        auto *dummy = new ListNode(-1, head);

        auto *curr = dummy;

        while (curr->next && curr->next->next) {
            if (curr->next->val == curr->next->next->val) {
                int x = curr->next->val;

                while (curr->next && curr->next->val == x) {
                    curr->next = curr->next->next;
                }
            }
            else {
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};