#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        unordered_map<string, int> memo;
        return back_track(nums, 0, target, memo);
    }

private:
    /**
     * 回溯算法实现
     * @param nums
     * @param i
     * @param rest
     * @param memo
     */
    int back_track(vector<int> &nums, int i, int rest, unordered_map<string, int>& memo) {
        if (i == nums.size()) {
            if (rest == 0) {
                return 1;
            }
            return 0;
        }

        string memo_key = to_string(i) + "," + to_string(rest);

        if (memo.find(memo_key) != memo.end()){
            return memo[memo_key];
        }

        int result = back_track(nums, i + 1, rest - nums[i], memo) + back_track(nums, i + 1, rest + nums[i], memo);
        memo[memo_key] = result;
        return result;
    }
};

int test_findTargetSumWays() {

    Solution solution;

    vector<int> nums1{1, 1, 1, 1, 1};
    int target1 = 3;

    cout << solution.findTargetSumWays(nums1, target1) << endl;

    return 0;
}