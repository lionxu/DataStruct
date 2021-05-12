#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int n = nums.size();

        int left = 0, right = 0;

        while (right < n) {
            if (nums[right]) {
                nums[left] = nums[right];
                left++;
            }
            right++;
        }

        while (left < n) {
            nums[left] = 0;
            left++;
        }
    }
};

int test_moveZeroes() {
    vector<int> nums{0, 1, 0, 3, 12};
    Solution solution;
    solution.moveZeroes(nums);

    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ",";
    }
    cout << endl;

    return 0;
}
