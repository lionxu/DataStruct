#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();

        if (n == 0) return 0;

        vector<int> dp(n, 0);

        dp[0] = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
        }

        int result = -1e9;
        for (int i = 0; i < n; ++i) {
            result = max(result, dp[i]);
        }

        return result;
    }
};

int test_maxSubArray() {
    Solution solution;

    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << solution.maxSubArray(nums) << endl;

    return 0;
}