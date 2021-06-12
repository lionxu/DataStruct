#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit_4(int k, vector<int> &prices) {
        int n = prices.size();

        if (n == 0) return 0;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < k + 1; ++j) {
                if (i - 1 == -1) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[i];
                    continue;
                }
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][1] - prices[i]);
            }
        }

        return dp[n - 1][k][0];
    }
};

int test_maxProfit_4() {
    vector<int> prices{2, 4, 1};
    Solution solution;
    cout << solution.maxProfit_4(2, prices) << endl;

    return 0;
}