#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int splitArray(vector<int> &nums, int m) {

        int n = nums.size();

        int left = 0;
        int right = 0;

        for (int i = 0; i < n; ++i) {
            right += nums[i];

            if (left < nums[i]) {
                left = nums[i];
            }
        }

        while (left < right) {
            int mid = (left + right) >> 1;

            if (check(nums, mid, m)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    static bool check(vector<int> &nums, int target, int m) {
        int n = nums.size();
        int cnt = 1;
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            if (sum + nums[i] > target) {
                cnt++;
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }

        return cnt <= m;
    }
};

int test_splitArray() {
    vector<int> nums{7, 2, 5, 10, 8};
    int m = 2;

    cout << Solution::splitArray(nums, m) << endl;

    return 0;
}