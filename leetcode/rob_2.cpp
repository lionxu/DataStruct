#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob_2(vector<int>& nums){
        int n = nums.size();

        if (n == 0) return 0;
        if (n == 1) return nums[0];

        return max(rob_range(nums, 0, n - 2), rob_range(nums, 1, n - 1));
    }

private:
    int rob_range(vector<int>& nums, int start, int end){
        int n = nums.size();

        vector<int> dp(n + 2, 0);

        for (int i = end; i >= start; --i) {
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        }

        return dp[start];
    }
};

int test_rob_2(){
    Solution solution;

    vector<int> nums{2, 3, 2};

    cout << solution.rob_2(nums) << endl;

    return 0;
}