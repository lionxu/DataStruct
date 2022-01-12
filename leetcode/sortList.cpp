//
// Created by Administrator on 2022/1/12.
//

#include "ListNode.h"

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return sortList_1(head, nullptr);
    }

    /**
     * 归并排序,自底向上,非递归实现
     * 时间复杂度为:nlog(n)
     * 空间复杂度为:o(1)
     * @return
     */
    static ListNode* sortList_2(ListNode *head) {

        if (!head) {
            return head;
        }

        int length = getLength(head);

        auto* dummy = new ListNode(-1, head);

        for (int i = 1; i < length; i <<= 1) {
            ListNode* prev = dummy;
            ListNode* curr = dummy->next;

            while (curr) {
                ListNode* list1 = curr;

                for (int j = 1; j < i && curr->next; ++j) {
                    curr = curr->next;
                }

                ListNode* list2 = curr->next;
                curr->next = nullptr;
                curr = list2;

                for (int j = 1; j < i && curr && curr->next; ++j) {
                    curr = curr->next;
                }

                ListNode *next = nullptr;

                if (curr) {
                    next = curr->next;
                    curr->next = nullptr;
                }

                prev->next = merge(list1, list2);
                while (prev->next) {
                    prev = prev->next;
                }

                curr = next;
            }
        }
        return dummy->next;
    }

    static int getLength(ListNode *head) {
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }

        return length;
    }

    /**
     * 归并排序,自顶向下,递归实现
     * 时间复杂度:nlog(n)
     * 空间复杂度:log(n)
     * @return
     */
    ListNode* sortList_1(ListNode* head, ListNode* tail) {
        if (!head) return head;
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        return merge(sortList_1(head, slow), sortList_1(slow, tail));
    }

    /**
     * 合并有序的链表
     */
    static ListNode* merge(ListNode* list1, ListNode* list2) {
        auto *dummy = new ListNode(-1);
        auto *curr = dummy;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if (list1) {
            curr->next = list1;
        } else {
            curr->next = list2;
        }
        return dummy->next;
    }
};