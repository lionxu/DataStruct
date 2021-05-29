#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    static bool canPartition(vector<int> &nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) return false;

        int m = sum / 2;

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (j < nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][m];
    }
};

int test_canPartition() {

    vector<int> nums{1, 5, 11, 5};

    bool result = Solution::canPartition(nums);

    cout << result << endl;

    return 0;
}