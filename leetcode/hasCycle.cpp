#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static bool hasCycle(ListNode *head){
        if (head == nullptr || head->next == nullptr){
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (slow != fast){
            if (fast == nullptr || fast->next == nullptr){
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};

int test_hasCycle(){
    Solution solution;

    auto *head10 = new ListNode(3);
    auto *head11 = new ListNode(2);
    head10->next = head11;
    auto *head12 = new ListNode(0);
    head11->next = head12;
    auto *head13 = new ListNode(4);
    head12->next = head13;
    head13->next = head11;

    cout << solution.hasCycle(head10) << endl;

    auto *head20 = new ListNode(1);
    auto *head21 = new ListNode(2);
    head20->next = head21;
    head21->next = head20;
    cout << solution.hasCycle(head20) << endl;

    auto *head30 = new ListNode(1);
    cout << solution.hasCycle(head30) << endl;

    return 0;
}