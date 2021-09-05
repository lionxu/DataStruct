#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int m = nums1.size();
        int n = nums2.size();

        int total = (m + n + 1) / 2;

        int left = 0;
        int right = m;

        while (left < right) {
            int i = left + (right - left + 1) / 2;
            int j = total - i;

            if (nums1[i - 1] > nums2[j]) {
                right = i - 1;
            } else {
                left = i;
            }
        }

        int i = left;
        int j = total - i;

        int nums1_left_max = i == 0 ? INT_MIN : nums1[i - 1];
        int nums1_right_min = i == m ? INT_MAX : nums1[i];
        int nums2_left_max = j == 0 ? INT_MIN : nums2[j - 1];
        int nums2_right_min = j == n ? INT_MAX : nums2[j];

        if ((m + n) % 2 == 1) {
            return max(nums1_left_max, nums2_left_max);
        } else {
            return (max(nums1_left_max, nums2_left_max) + min(nums1_right_min, nums2_right_min)) / 2.0;
        }
    }
};

int main() {
    vector<int> nums1{1, 3};
    vector<int> nums2{2};

    cout << Solution::findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}