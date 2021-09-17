#include <iostream>
#include "ListNode.h"

using namespace std;


class Solution {
public:
    static ListNode* reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

int test_reverseList() {

    auto *head = new ListNode(1);
    auto *second = new ListNode(2);
    head->next = second;
    auto *third = new ListNode(3);
    second->next = third;
    auto *fourth = new ListNode(4);
    third->next = fourth;
    auto *fifth = new ListNode(5);
    fourth->next = fifth;

    head = Solution::reverseList(head);

    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;

    return 0;
}