//
// Created by Administrator on 2022/1/2.
//

#ifndef DATASTRUCT_DLINKEDNODE_H
#define DATASTRUCT_DLINKEDNODE_H
struct DLinkedNode {
    int key;
    int value;
    DLinkedNode* pre;
    DLinkedNode* next;

    DLinkedNode(): key(0), value(0), pre(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), pre(nullptr), next(nullptr) {}
};
#endif //DATASTRUCT_DLINKEDNODE_H
