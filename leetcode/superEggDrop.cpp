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
		if (n == 0)
		{
			return 0;
		}

		if (k == 1)
		{
			return n;
		}

		string history_key = to_string(k) + "," + to_string(n);

		if (memo.count(history_key))
		{
			return memo[history_key];
		}

		int result = INT_MAX;
		
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


int test_superEggDrop() {
	Solution solution;

	cout << solution.superEggDrop(4, 7547) << endl;

	return 0;
}