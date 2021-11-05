//
// Created by Administrator on 2021/11/5.
//

#ifndef DATASTRUCT_NODE_H
#define DATASTRUCT_NODE_H

class Node {
public:
    int val;
    Node *next;
    Node *random;

    explicit Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

#endif //DATASTRUCT_NODE_H
