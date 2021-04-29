#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {

public:

    static constexpr int P = 1e9 + 7;
    static constexpr int MAX_N = 1e5 + 5;
    int f[MAX_N];

    void prepare() {
        f[0] = 1;
        for (int i = 1; i <= MAX_N; ++i) {
            f[i] = 2 * f[i - 1] % P;
        }
    }

    int numSubseq(vector<int> &nums, int target) {
        prepare();

        int res = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() && 2 * nums[i] <= target; ++i) {
            int max_value = target - nums[i];
            int index = upper_bound(nums.begin(), nums.end(), max_value) - nums.begin() - 1;
            int contribute = index >= i ? f[index - i] : 0;
            res = (res + contribute) % P;
        }

        return res;
    }
};

int test_numSubseq() {

    Solution solution;

    vector<int> nums1;
    nums1.push_back(3);
    nums1.push_back(5);
    nums1.push_back(6);
    nums1.push_back(7);
    int target1 = 9;

    cout << solution.numSubseq(nums1, target1) << endl;

    vector<int> nums2;
    nums2.push_back(3);
    nums2.push_back(3);
    nums2.push_back(6);
    nums2.push_back(8);
    int target2 = 10;
    cout << solution.numSubseq(nums2, target2) << endl;

    vector<int> nums3;
    nums3.push_back(2);
    nums3.push_back(3);
    nums3.push_back(3);
    nums3.push_back(4);
    nums3.push_back(6);
    nums3.push_back(7);
    int target3 = 12;
    cout << solution.numSubseq(nums3, target3) << endl;


    vector<int> nums4;
    nums4.push_back(5);
    nums4.push_back(2);
    nums4.push_back(4);
    nums4.push_back(1);
    nums4.push_back(7);
    nums4.push_back(6);
    nums4.push_back(8);
    int target4 = 16;
    cout << solution.numSubseq(nums4, target4) << endl;
    return 0;
}