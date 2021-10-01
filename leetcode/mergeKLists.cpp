#include <vector>
#include <queue>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    static ListNode* mergeKLists(vector<ListNode*> &lists) {
        priority_queue<Status> queue;

        for (auto node : lists) {
            if (node) queue.push({node->val, node});
        }

        auto *head = new ListNode(-1);
        auto *tail = head;

        while (!queue.empty()) {
            auto tmp = queue.top();
            queue.pop();

            tail->next = tmp.node;
            tail = tail->next;

            if (tmp.node->next) {
                queue.push({tmp.node->next->val, tmp.node->next});
            }
        }

        return head->next;
    }

    struct Status {
        int val;
        ListNode *node;

        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };
};