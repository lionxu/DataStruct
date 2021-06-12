#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit_6(vector<int> &prices, int fee) {
        int n = prices.size();

        if (n == 0) return 0;

        vector<vector<int>> dp(n, vector<int>(2, 0));

        for (int i = 0; i < n; ++i) {
            if (i - 1 == -1) {
                dp[i][0] = 0;
                dp[i][1] = -prices[i] - fee;

                continue;
            }

            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee);
        }

        return dp[n - 1][0];
    }
};

int main() {
    vector<int> prices{1, 3, 2, 8, 4, 9};
    int fee = 2;

    Solution solution;

    cout << solution.maxProfit_6(prices, fee) << endl;

    return 0;
}