#include<vector>
#include<iostream>

using namespace std;

class Solution
{
public:
	int maxA(int N) {
		vector<int> dp(N + 1, 0);

		dp[0] = 0;

		for (int i = 1; i <= N; i++)
		{
			// 按下A健
			dp[i] = dp[i - 1] + 1;

			// 按下C-A和C-C组合键
			for (int j = 2; j < i; j++)
			{
				// 全选+复制后屏幕上剩下dp[j-2]个A
				// 粘贴j - i次屏幕上会增加(i - j + 1) * dp[j-2]个A
				dp[i] = max(dp[i], dp[j - 2] * (i - j + 1));
			}
		}

		// 最后屏幕上剩下的A的个数
		return dp[N];
	}
};

int main() {
	Solution solution;

	cout << solution.maxA(3) << endl;

	cout << solution.maxA(7) << endl;

	return 0;
}