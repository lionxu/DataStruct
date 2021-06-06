#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    explicit ListNode(int x): val(x), next(nullptr){}
};

class Solution{
public:
    int kthToLast(ListNode* head, int k) {
        ListNode *former = head;
        ListNode *latter = head;

        for (int i = 0; i < k; ++i) {
            former = former->next;
        }

        while (former){
            former = former->next;
            latter = latter->next;
        }

        return latter->val;
    }
};

int test_kthToLast(){
    ListNode node1(1);
    ListNode node2(2);
    node1.next = &node2;

    ListNode node3(3);
    node2.next = &node3;

    ListNode node4(4);
    node3.next = &node4;

    ListNode node5(5);
    node4.next = &node5;

    int k = 2;

    Solution solution;
    cout << solution.kthToLast(&node1, k) << endl;

    return 0;
}