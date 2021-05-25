#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int result = 0;
        vector<int> memo(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            result = max(result, dp(nums, i, memo));
        }

        return result;
    }

private:
    int dp(vector<int> &nums, int i, vector<int> &memo) {
        if (i < 0) return 0;
        if (i == 0) return 1;

        if (memo[i] != 0) {
            return memo[i];
        }

        int result = 1;

        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                result = max(result, dp(nums, j, memo) + 1);
            }
        }

        memo[i] = result;

        return result;
    }
};

int main() {

    Solution solution;
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};

    cout << solution.lengthOfLIS(nums) << endl;

    return 0;
}