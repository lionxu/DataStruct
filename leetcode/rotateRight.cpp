# include "ListNode.h"

class Solution {
public:
    static ListNode* rotateRight(ListNode *head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        }

        int n = 1;
        ListNode *iter = head;

        while (iter->next) {
            n++;
            iter = iter->next;
        }

        int add = n - k % n;

        if(add == n) return head;

        while (add) {
            iter = iter->next;
            add--;
        }

        ListNode *ans = iter->next;
        iter->next = nullptr;
        return ans;
    }
};