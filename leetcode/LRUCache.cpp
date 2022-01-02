//
// Created by Administrator on 2022/1/2.
//

#include <unordered_map>
#include "DLinkedNode.h"

using namespace std;

class LRUCache {
public:
    LRUCache(int _capacity) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        size = 0;
        capacity = _capacity;
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        } else {
            DLinkedNode* node = cache[key];
            // 将缓存节点移动到链表的开头
            move_to_head(node);
            return node->value;
        }
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            DLinkedNode* node = new DLinkedNode(key, value);

            // 将新增节点放入链表的头部
            add_to_head(node);
            // 将新增的节点放入缓存
            cache[key] = node;
            // 增加节点数量的计数
            ++size;

            // 如果节点数量超过容量的限制,则进行节点淘汰
            if (size > capacity) {
                DLinkedNode* node = remove_tail();
                // 清除缓存中的该节点
                cache.erase(node->key);
                // 释放内存
                delete node;
                // 减小节点数量
                --size;
            }
        } else {
            DLinkedNode *node = cache[key];

            // 修改值
            node->value = value;
            // 移动节点在链表中的位置
            move_to_head(node);
        }
    }

    void move_to_head(DLinkedNode* node) {
        remove_node(node);
        add_to_head(node);
    }

    void add_to_head(DLinkedNode* node) {
        node->next = head->next;
        node->pre = head;
        head->next->pre = node;
        head->next = node;
    }

    DLinkedNode* remove_tail() {
        DLinkedNode* node = tail->pre;
        remove_node(node);
        return node;
    }

    void remove_node(DLinkedNode *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;
};