#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>> envelops) {
        sort(envelops.begin(), envelops.end(), my_comp);

        vector<int> height;

        height.reserve(envelops.size());
        for (auto &envelop : envelops) {
            height.push_back(envelop[1]);
        }

        return lengthOfLIS(height);
    }

private:

    static int lengthOfLIS(vector<int> height) {
        int n = height.size();
        vector<int> dp(n, 1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (height[i] > height[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            result = max(result, dp[i]);
        }

        return result;
    }

    static bool my_comp(vector<int> &a, vector<int> &b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }
};

int test_maxEnvelops(){
    Solution solution;

    vector<vector<int>> envelops{{5, 4}, {6, 4}, {6, 7}, {2, 3}};

    cout << solution.maxEnvelopes(envelops) << endl;

    return 0;
}