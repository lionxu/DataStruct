#include<vector>
#include<utility>
#include<iostream>

using namespace std;

class Solution
{
public:
	bool stoneGame(vector<int>& piles) {
		int n = piles.size();

		vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dp[i][j] = make_pair(0, 0);
			}
		}

		for (int i = 0; i < n; i++)
		{
			dp[i][i] = make_pair(piles[i], 0);
		}

		// 斜着遍历dp数组进行计算
		for (int k = 2; k <= n; k++)
		{
			for (int i = 0; i <= n - k; i++)
			{
				int j = i + k - 1;

				// 先手选择左边石堆
				int left = piles[i] + dp[i + 1][j].second;
				// 先手选择右边石堆
				int right = piles[j] + dp[i][j - 1].second;

				if (left > right)
				{
					dp[i][j].first = left;
					dp[i][j].second = dp[i + 1][j].first;
				}
				else
				{
					dp[i][j].first = right;
					dp[i][j].second = dp[i][j - 1].first;
				}
			}
		}

		return dp[0][n - 1].first > dp[0][n - 1].second;
	}

};

int main() {

	Solution solution;

	vector<int> piles{5, 3, 4, 5};

	cout << solution.stoneGame(piles) << endl;

	return 0;
}