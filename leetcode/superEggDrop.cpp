#include<climits>
#include<algorithm>
#include<unordered_map>
#include<iostream>
#include<string>

using namespace std;

class Solution
{
public:
	int superEggDrop(int k, int n) {

		unordered_map<string, int> memo;

		return dp(k, n, memo);
	}

private:
	int dp(int k, int n, unordered_map<string, int>& memo) {

		// 楼层为零,无需测试
		if (n == 0)
		{
			return 0;
		}

		// 只有一个鸡蛋,只能一层一层的测试
		if (k == 1)
		{
			return n;
		}

		string history_key = to_string(k) + "," + to_string(n);

		// 通过历史记录来减少重叠子问题的计算次数
		if (memo.count(history_key))
		{
			return memo[history_key];
		}

		int result = INT_MAX;

		// 遍历所有楼层进行测试
		int low = 1;
		int high = n;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			int broken = dp(k - 1, mid - 1, memo);
			int not_broken = dp(k, n - mid, memo);

			if (broken > not_broken)
			{
				high = mid - 1;
				result = min(result, broken + 1);
			}
			else
			{
				low = mid + 1;
				result = min(result, not_broken + 1);
			}
		}

		memo[history_key] = result;

		return result;
	}
};


int main() {
	Solution solution;

	cout << solution.superEggDrop(4, 7547) << endl;

	return 0;
}