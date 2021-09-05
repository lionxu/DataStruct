#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int singleNonDuplicate(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            bool even = (right - mid) % 2 == 0;

            if (nums[mid + 1] == nums[mid]) {
                if (even) {
                    left = mid + 2;
                } else {
                    right = mid - 1;
                }
            } else if (nums[mid - 1] == nums[mid]) {
                if (even) {
                    right = mid - 2;
                } else {
                    left = mid + 1;
                }
            } else {
                return nums[mid];
            }
        }
        return nums[left];
    }
};

int test_singleNonDuplicate() {

    vector<int> nums{1, 1, 2, 3, 3, 4, 4, 8, 8};

    cout << Solution::singleNonDuplicate(nums) << endl;

    return 0;
}