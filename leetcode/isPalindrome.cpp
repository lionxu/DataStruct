#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode *end_of_first_half(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    static ListNode *reverse_list(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    static bool isPalindrome(ListNode *head) {

        if (head == nullptr) {
            return false;
        }

        ListNode *endOfFirstHalf = end_of_first_half(head);
        ListNode *startOfSendHalf = reverse_list(endOfFirstHalf->next);

        ListNode *p1 = head;
        ListNode *p2 = startOfSendHalf;
        bool result = true;
        while (result && p2 != nullptr) {
            if (p1->val != p2->val) {
                result = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        endOfFirstHalf->next = reverse_list(startOfSendHalf);
        return result;
    }

};

int test_isPalindrome() {

    auto *head10 = new ListNode(1);
    auto *head11 = new ListNode(2);
    head10->next = head11;

    cout << Solution::isPalindrome(head10) << endl;

    auto *head20 = new ListNode(1);
    auto *head21 = new ListNode(2);
    head20->next = head21;
    auto *head22 = new ListNode(2);
    head21->next = head22;
    auto *head23 = new ListNode(1);
    head22->next = head23;
    cout << Solution::isPalindrome(head20) << endl;

    return 0;
}