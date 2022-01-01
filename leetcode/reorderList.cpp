//
// Created by Administrator on 2022/1/1.
//

#include "ListNode.h"

class Solution {
public:
    void reorderList(ListNode *head) {
        // 如果链表为空,则无需重新排序
        if (!head) return;

        ListNode* l1 = head;
        // 确定链表中间节点
        ListNode* mid = middle(head);
        ListNode*l2 = mid->next;
        mid->next = nullptr;

        // 对l2进行链表翻转
        l2 = reverse(l2);

        // 合并l1和l2
        merge(l1, l2);
    }

    /**
     * 查找链表的中间节点
     * 使用快慢指针算法,实现查找中间节点
     * @param head 表头节点
     * @return
     */
    ListNode *middle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    /**
     * 对链表进行翻转
     * @param head
     * @return
     */
    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode *next = curr->next;

            curr->next = pre;

            pre = curr;
            curr = next;
        }
        return pre;
    }

    /**
     * 对链表进行合并
     * @param l1
     * @param l2
     */
    void merge(ListNode* l1, ListNode* l2) {
        ListNode* node1;
        ListNode* node2;

        while (l1 && l2) {
            node1 = l1->next;
            node2 = l2->next;

            l1->next = l2;
            l1 = node1;
            l2->next = l1;
            l2 = node2;
        }
    }
};