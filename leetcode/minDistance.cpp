#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        if (m == 0) return n;

        if (n == 0) return m;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }

        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i-1][j-1] + 1, min(dp[i-1][j] + 1, dp[i][j-1] + 1));
                }
            }
        }

        return dp[m][n];
    }

};

int test_minDistance() {
    Solution solution;

    string s1 = "horse";
    string s2 = "ros";
    cout << solution.minDistance(s1, s2) << endl;

    return 0;
}