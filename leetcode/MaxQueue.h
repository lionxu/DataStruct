#ifndef MAXQUEUE_H
#define MAXQUEUE_H
#include <queue>

class MaxQueue {
    std::deque<int> deque;
    std::queue<int> queue;

public:
    MaxQueue(){}

    int max_value(){
        if(deque.empty()) return -1;
        return deque.front();
    }

    void push_back(int value){
        while (!deque.empty() && deque.back() < value){
            deque.pop_back();
        }
        deque.push_back(value);
        queue.push(value);
    }

    int pop_front(){
        if(queue.empty()) return -1;
        int result = queue.front();
        if(deque.front() == result){
            deque.pop_front();
        }

        queue.pop();

        return result;
    }
};


#endif
