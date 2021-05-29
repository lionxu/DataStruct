#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int> &nums) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= amount; ++j) {
                if (j < nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - nums[i - 1]];
                }
            }
        }

        return dp[n][amount];
    }
};

int test_change() {

    Solution solution;

    int amount = 5;
    vector<int> coins{1, 2, 5};

    cout << solution.change(amount, coins) << endl;

    return 0;
}