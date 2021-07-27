#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int left = 0;
        int right = height.size() - 1;
        int res = 0;

        while (left < right) {
            res = max(res, min(height[left], height[right]) * (right - left));

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return res;
    }
};

int test_maxArea() {

    Solution solution;

    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << solution.maxArea(height) << endl;

    return 0;
}