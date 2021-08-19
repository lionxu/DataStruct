#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int wiggleMaxLength(vector<int> &nums) {
        int n = nums.size();

        if (n < 2) return n;

        int prediff = nums[1] - nums[0];

        int ret = prediff != 0 ? 2 : 1;
        for (int i = 2; i < n; ++i) {
            int diff = nums[i] - nums[i - 1];

            if ((diff > 0 && prediff <= 0) || (diff < 0 && prediff >= 0)) {
                ret++;
                prediff = diff;
            }
        }

        return ret;
    }
};

int test_wiggleMaxLength() {

    vector<int> nums{1, 7, 4, 9, 2, 5};

    cout << Solution::wiggleMaxLength(nums) << endl;

    return 0;
}