#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int left = 0, right = 0;

        while (right < nums.size()) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                left++;
            }
            right++;
        }
        return left;
    }
};

int test_removeElement() {
    vector<int> nums1{3, 2, 2, 3};
    int k1 = 3;
    Solution solution;

    int count1 = solution.removeElement(nums1, k1);

    for (int i = 0; i < count1; ++i) {
        cout << nums1[i] << ",";
    }
    cout << endl;

    vector<int> nums2{0, 1, 2, 2, 3, 0, 4, 2};
    int k2 = 2;
    int result2 = solution.removeElement(nums2, k2);
    for (int i = 0; i < result2; ++i) {
        cout << nums2[i] << ",";
    }

    cout << endl;

    return 0;
}