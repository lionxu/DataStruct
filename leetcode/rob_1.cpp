#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob_1(vector<int> &nums) {
        int n = nums.size();

        if (n == 0) return 0;

        vector<int> dp(n + 2, 0);

        for (int i = n - 1; i >= 0; --i) {
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        }

        return dp[0];
    }
};

int test_rob_1() {
    vector<int> nums{1, 2, 3, 1};
    Solution solution;

    cout << solution.rob_1(nums) << endl;

    return 0;
}