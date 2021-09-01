#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.empty()) return {-1, -1};
        int lower = lower_bound(nums, target);
        int upper = upper_bound(nums, target) - 1;
        if (lower == nums.size() || nums[lower] != target) {
            return {-1, -1};
        }
        return {lower, upper};
    }

    static int lower_bound(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size();
        int mid;

        while (left < right) {
            mid = (left + right) / 2;

            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    static int upper_bound(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size();
        int mid;

        while (left < right) {
            mid = (left + right) / 2;

            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int test_searchRange() {
    vector<int> nums{5,7,7,8,8,10};
    int target = 8;
    vector<int> result = Solution::searchRange(nums, target);

    cout << result[0] << result[1] << endl;

    return 0;
}