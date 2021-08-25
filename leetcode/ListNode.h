//
// Created by Administrator on 2021/8/25.
//

#ifndef DATASTRUCT_LISTNODE_H
#define DATASTRUCT_LISTNODE_H

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x): val(x), next(nullptr) {}
};

#endif //DATASTRUCT_LISTNODE_H
