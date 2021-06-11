#include<vector>
#include<iostream>

using namespace std;

class Solution
{
public:
	int maxProfit_1(vector<int>& prices) {
		int n = prices.size();

		vector<vector<int>> dp(n, vector<int>(2, 0));

		for (int i = 0; i < n; i++)
		{
			if (i - 1 == -1)
			{
				dp[i][0] = 0;
				dp[i][1] = -prices[i];
				continue;
			}

			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
			dp[i][1] = max(dp[i - 1][1], - prices[i]);
		}

		return dp[n - 1][0];
	}
};

int test_maxProfit() {

	Solution solution;

	vector<int> nums{7, 6, 4, 3, 1};

	cout << solution.maxProfit_1(nums) << endl;

	return 0;
}