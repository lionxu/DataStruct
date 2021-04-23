#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums, int limit) {
        int ret = 0;
        multiset<int> set;
        int left = 0;
        int n = nums.size();
        for (int right = 0; right < n; ++right) {
            set.insert(nums[right]);
            while ((*set.rbegin() - *set.begin()) > limit) {
                set.erase(set.find(nums[left]));
                left++;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};

int main() {
    Solution solution;

    vector<int> nums1;
    nums1.push_back(8);
    nums1.push_back(2);
    nums1.push_back(4);
    nums1.push_back(7);
    int limit1 = 4;

    cout << solution.longestSubarray(nums1, limit1) << endl;

    vector<int> nums2;
    nums2.push_back(10);
    nums2.push_back(1);
    nums2.push_back(2);
    nums2.push_back(4);
    nums2.push_back(7);
    nums2.push_back(2);
    int limit2 = 5;
    cout << solution.longestSubarray(nums2, limit2) << endl;

    vector<int> nums3;
    nums3.push_back(4);
    nums3.push_back(2);
    nums3.push_back(2);
    nums3.push_back(2);
    nums3.push_back(4);
    nums3.push_back(4);
    nums3.push_back(2);
    nums3.push_back(2);
    int limit3 = 0;
    cout << solution.longestSubarray(nums3, limit3) << endl;

    return 0;
}