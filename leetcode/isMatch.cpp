#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i] == p[j] || p[j] == '.') dp[i][j] = dp[i - 1][j - 1];
                else if (p[j] == '*') {
                    if (s[i] == p[j - 1] || p[j - 1] == '.') dp[i][j] = dp[i][j - 1] || dp[i - 1][j] || dp[i][j - 2];
                    else dp[i][j] = dp[i][j - 2];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[m][n];
    }
};

int test_isMatch() {
    Solution solution;

    string s = "aa";
    string p = "a*";

    cout << solution.isMatch(s, p) << endl;

    return 0;
}