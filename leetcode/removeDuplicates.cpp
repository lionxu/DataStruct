#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();

        if (n == 0) {
            return 0;
        }

        int slow = 1;
        int fast = 1;
        while (fast < n) {
            if (nums[fast - 1] != nums[fast]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }

        return slow;
    }
};

int test_removeDuplicates() {

    Solution solution;

    vector<int> nums1{1, 1, 2};

    int len1 = solution.removeDuplicates(nums1);

    for (int i = 0; i < len1; ++i) {
        cout << nums1[i] << ",";
    }

    cout << endl;

    vector<int> nums2{0, 0, 1, 1, 1, 2, 2, 3, 4};
    int len2 = solution.removeDuplicates(nums2);
    for (int i = 0; i < len2; ++i) {
        cout << nums2[i] << ",";
    }

    cout << endl;

}