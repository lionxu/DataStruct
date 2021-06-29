#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        int n = nums.size();

        if (n == 1) return true;

        bool flag = nums[0] < nums[1];

        for (int i = 1; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                if (flag) {
                    if (nums[i + 1] >= nums[i - 1]) {
                        nums[i] = nums[i + 1];
                    } else {
                        nums[i + 1] = nums[i];
                    }
                    flag = false;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int test_checkPossibility() {
    vector<int> nums{4, 2, 3};
    Solution solution;
    cout << solution.checkPossibility(nums) << endl;
    return 0;
}