#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit_2(vector<int> &prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, 0));

        for (int i = 0; i < n; ++i) {
            if (i - 1 == -1) {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }

            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[n - 1][0];
    }
};

int test_maxProfit_2() {

    vector<int> prices{7, 1, 5, 3, 6, 4};

    Solution solution;

    cout << solution.maxProfit_2(prices) << endl;

    return 0;
}