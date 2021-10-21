#include "ListNode.h"

class Solution {
public:
    static ListNode* partition(ListNode *head, int x) {
        auto *small = new ListNode(-1);
        auto *small_head = small;

        auto *large = new ListNode(-1);
        auto *large_head = large;

        while (head) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }

            head = head->next;
        }

        large->next = nullptr;
        small->next = large_head->next;
        return small_head->next;
    }
};