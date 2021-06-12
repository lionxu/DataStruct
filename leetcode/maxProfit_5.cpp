#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit_5(vector<int> &prices) {
        int n = prices.size();

        if (n == 0) return 0;

        vector<vector<int>> dp(n, vector<int>(2, 0));

        for (int i = 0; i < n; ++i) {
            if (i - 1 == -1) {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }

            if (i < 2) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                dp[i][1] = max(dp[i - 1][1], 0 - prices[i]);
            } else {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
            }
        }

        return dp[n - 1][0];
    }
};

int test_maxProfit_5() {
    vector<int> prices{1, 2, 3, 0, 2};
    Solution solution;
    cout << solution.maxProfit_5(prices) << endl;

    return 0;
}