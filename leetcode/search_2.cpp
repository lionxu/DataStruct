#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static bool search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return true;

            if (nums[left] == nums[mid]) {
                left++;
            } else if (nums[mid] <= nums[right]) {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return false;
    }
};

int test_search2() {
    vector<int> nums{2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    cout << Solution::search(nums, target) << endl;
    return 0;
}