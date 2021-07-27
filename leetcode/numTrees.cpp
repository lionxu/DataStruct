#include "TreeNode.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);

        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

int test_numTrees() {
    Solution solution;

    cout << solution.numTrees(3) << endl;

    return 0;
}