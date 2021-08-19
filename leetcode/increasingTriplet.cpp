#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static bool increasingTriplet(vector<int> &nums) {

        int len = nums.size();

        if (len < 3) return false;

        int min = INT_MAX;
        int mid = INT_MAX;

        for (auto n: nums) {
            if (n <= min) min = n;
            else if (n <= mid) mid = n;
            else if (n > mid) return true;
        }

        return false;
    }
};

int test_increasingTriplet() {

    vector<int> nums{1, 2, 3, 4, 5};

    cout << Solution::increasingTriplet(nums) << endl;

    return 0;
}