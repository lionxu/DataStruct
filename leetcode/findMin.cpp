#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] < nums[right]) {
                right = mid;
            } else if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right--;
            }
        }

        return nums[left];
    }
};

int test_findMin() {
    vector<int> nums{1,3,5};
    cout << Solution::findMin(nums) << endl;
    return 0;
}