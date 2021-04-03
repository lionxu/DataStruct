#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        vector<double> result;
        multiset<double> set;
        int left = 0;
        int right = 0;
        for (; right < nums.size(); ++right) {
            if (set.size() >= k) set.erase(set.find(nums[left++]));
            set.insert(nums[right]);
            if (right - left >= k - 1) {
                auto iterator = set.begin();
                advance(iterator, k / 2);
                double mid = (*iterator + *prev(iterator, 1 - k % 2)) / 2;
                result.push_back(mid);
            }
        }
        return result;
    }
};


int test_medianSlidingWindow(){
    Solution solution;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);

    vector<double> result = solution.medianSlidingWindow(nums, 2);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }

    return 0;
}