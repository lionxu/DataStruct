#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        priority_queue<pair<int, int>> priorityQueue;
        vector<int> vector;
        for (int i = 0; i < k; ++i) {
            pair<int, int> pair(nums[i], i);
            priorityQueue.push(pair);
        }

        vector.push_back(priorityQueue.top().first);

        for (int i = k; i < nums.size(); ++i) {
            pair<int, int> pair(nums[i], i);

            priorityQueue.push(pair);

            while (priorityQueue.top().second <= i - k){
                priorityQueue.pop();
            }

            vector.push_back(priorityQueue.top().first);

        }
        return vector;
    }

};

int test_maxSlidingWindow() {
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(-2);

    Solution solution;
    vector<int> vector = solution.maxSlidingWindow(nums, 2);
    for (int i = 0; i < vector.size(); ++i) {
        cout << vector[i] << endl;
    }
}