//
// Created by Administrator on 2022/1/6.
//

#include "ListNode.h"

class Solution {
public:
    static ListNode* insertionSortList(ListNode* head) {
        // 判断链表是否为空
        if (!head) return head;

        auto *dummy = new ListNode(-1, head);

        // 排序链表的最后一个节点
        auto *last = head;
        // 待排序链表的头节点
        auto *curr = head->next;

        while (curr) {
            if (last->val <= curr->val) {
                last = last->next;
            } else {
                // 从拍戏链表的头节点开始遍历
                // 寻找插入节点的位置
                auto *pre = dummy;
                while (pre->next->val <= curr->val) {
                    pre = pre->next;
                }
                // 插入节点
                last->next = curr->next;
                curr->next = pre->next;
                pre->next = curr;
            }
            curr = last->next;
        }
        return dummy->next;
    }
};