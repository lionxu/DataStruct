//
// Created by Administrator on 2021/11/5.
//

#include "Node.h"

class Solution {
public:
    static Node* copyRandomList(Node *head) {
        if (!head) return nullptr;

        for (Node *node = head; node != nullptr; node = node->next->next) {
            Node *new_node = new Node(node->val);
            new_node->next = node->next;
            node->next = new_node;
        }

        for (Node *node = head; node != nullptr; node = node->next->next) {
            Node *new_node = node->next;
            new_node->random = node->random != nullptr ? node->random->next : nullptr;
        }

        Node *new_head = head->next;
        for (Node *node = head; node != nullptr; node = node->next->next) {
            Node *new_node = node->next;
            node->next = node->next->next;
            new_node->next = new_node->next != nullptr ? new_node->next->next : nullptr;
        }

        return new_head;
    }
};