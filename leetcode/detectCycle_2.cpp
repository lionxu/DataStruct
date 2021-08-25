#include <iostream>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    static ListNode* detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        do {
            if (!fast || !fast->next) {
                return nullptr;
            }

            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);

        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    }
};

int test_detectCycle() {
    auto *head = new ListNode(3);
    auto *second = new ListNode(2);
    head->next = second;
    auto *third = new ListNode(0);
    second->next = third;
    auto *fourth = new ListNode(-4);
    third->next = fourth;
    fourth->next = second;
    auto *start = Solution::detectCycle(head);
    cout << start->val << endl;
    return 0;
}