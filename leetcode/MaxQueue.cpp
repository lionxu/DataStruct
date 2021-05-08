#include <iostream>
#include "MaxQueue.h"

using namespace std;

int test_max_queue() {

    MaxQueue *maxQueue = new MaxQueue();

    maxQueue->push_back(1);
    maxQueue->push_back(2);
    cout << maxQueue->max_value() << endl;
    cout << maxQueue->pop_front() << endl;
    cout << maxQueue->max_value() << endl;

    return 0;
}
