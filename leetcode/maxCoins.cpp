#include<vector>
#include<iostream>

using namespace std;

class Solution
{
public:
	int maxCoins(vector<int>& nums) {

		int n = nums.size();

		// 定义新的数组,添加虚拟节点0和i + 1
		vector<int> points(n + 2, 1);

		for (int i = 1; i <= n; i++)
		{
			points[i] = nums[i - 1];
		}


		// 定义动态规划的数组
		// dp[i][j]的含义是戳破(i, j)范围的气球可以获得硬币的最大数量
		vector<vector<int>>dp(n + 2, vector<int>(n + 2, 0));

		// 对i从下往上进行穷举计算
		for (int i = n; i >= 0; i--)
		{
			// 对j从左到右进行遍历
			for (int j = i + 1; j < n + 2; j++)
			{
				// 状态转移,计算戳破第k个气球时,所获得硬币数量
				for (int k = i + 1; k < j; k++)
				{
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + points[i] * points[k] * points[j]);
				}
			}
		}

		return dp[0][n + 1];
	}
};

int test_maxCoins() {

	vector<int> nums{3, 1, 5, 8};

	Solution solution;

	cout << solution.maxCoins(nums) << endl;

	return 0;
}