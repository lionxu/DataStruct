#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int minPatches(vector<int> &nums, int n) {

        int length = nums.size();

        int index = 0;

        long long x = 1;

        int patches = 0;

        while (x <= n) {
            if (index < length && nums[index] <= x) {
                x += nums[index];
                index++;
            } else {
                x *= 2;
                patches++;
            }
        }
        return patches;
    }
};


int test_minPatches() {

    vector<int> nums{1, 3};
    int n = 6;

    cout << Solution::minPatches(nums, n) << endl;

    return 0;
}