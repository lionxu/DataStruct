#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        int n = nums.size();

        int negative = 0;

        vector<int> result;

        for (int i = 0; i < n; ++i) {
            if (nums[i] < 0) {
                negative = i;
            } else {
                break;
            }
        }

        int left = negative;
        int right = negative + 1;

        while (left >= 0 || right < n) {
            if (left < 0) {
                result.push_back(nums[right] * nums[right]);
                right++;
            } else if (right == n) {
                result.push_back(nums[left] * nums[left]);
                left--;
            } else if (nums[left] * nums[left] < nums[right] * nums[right]) {
                result.push_back(nums[left] * nums[left]);
                left--;
            } else {
                result.push_back(nums[right] * nums[right]);
                right++;
            }
        }

        return result;
    }
};

int test_sortedSquares() {

    Solution solution;

    vector<int> nums1{-4, -1, 0, 3, 10};

    vector<int> result1 = solution.sortedSquares(nums1);

    for (int i : result1) {
        cout << i << ",";
    }

    cout << endl;

    vector<int> nums2{-7, -3, 2, 3, 11};
    vector<int> result2 = solution.sortedSquares(nums2);

    for (int i : result2) {
        cout << i << ",";
    }

    cout << endl;

    return 0;
}