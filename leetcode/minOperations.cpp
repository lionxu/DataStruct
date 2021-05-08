#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        int max_length = -1;
        int left = 0;
        int right = 0;
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }

        if (sum - x < 0) {
            return -1;
        }

        int sub_sum = 0;
        while (right < n) {
            sub_sum += nums[right];

            while (sub_sum > sum - x) {
                sub_sum -= nums[left];
                left++;
            }

            if (sub_sum == sum - x) {
                max_length = max(max_length, right - left + 1);
            }

            right++;
        }

        if (max_length == -1) {
            return -1;
        } else {
            return n - max_length;
        }
    }
};

int test_minOperations() {

    Solution solution;

    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(1);
    nums1.push_back(4);
    nums1.push_back(2);
    nums1.push_back(3);
    int k1 = 5;

    cout << solution.minOperations(nums1, k1) << endl;

    vector<int> nums2;
    nums2.push_back(5);
    nums2.push_back(6);
    nums2.push_back(7);
    nums2.push_back(8);
    nums2.push_back(9);
    int k2 = 4;
    cout << solution.minOperations(nums2, k2) << endl;

    vector<int> nums3;
    nums3.push_back(3);
    nums3.push_back(2);
    nums3.push_back(20);
    nums3.push_back(1);
    nums3.push_back(1);
    nums3.push_back(3);
    int k3 = 10;
    cout << solution.minOperations(nums3, k3) << endl;

    return 0;
}