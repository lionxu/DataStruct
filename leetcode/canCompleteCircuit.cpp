#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = cost.size();

        int curSum = 0;
        int totalSum = 0;
        int start = 0;

        for (int i = 0; i < n; ++i) {
            curSum += (gas[i] - cost[i]);
            totalSum += (gas[i] - cost[i]);
            if (curSum < 0) {
                curSum = 0;
                start = i + 1;
            }
        }

        if (totalSum < 0) return -1;
        return start;
    }
};

int test_canCompleteCircuit() {
    Solution solution;

    vector<int> gas{1, 2, 3, 4, 5};
    vector<int> cost{3, 4, 5, 1, 2};

    cout << solution.canCompleteCircuit(gas, cost) << endl;

    return 0;
}