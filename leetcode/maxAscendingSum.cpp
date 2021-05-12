#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int> &nums) {
        int sum = nums[0], tmp = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                tmp += nums[i];
            } else {
                sum = max(sum, tmp);
                tmp = nums[i];
            }
        }

        return max(sum, tmp);
    }
};

int test_maxAscendingSum() {
    vector<int> nums{10, 20, 30, 5, 10, 50};
    Solution solution;
    cout << solution.maxAscendingSum(nums) << endl;
}