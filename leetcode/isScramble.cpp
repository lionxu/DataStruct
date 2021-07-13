#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        if (m != n) return false;

        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(n + 1, false)));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= m - len; ++i) {
                for (int j = 0; j <= n - len; ++j) {
                    for (int k = 1; k <= len - 1; ++k) {
                        if (dp[i][j][k] && dp[i+ k][j + k][len - k]) {
                            dp[i][j][len] = true;
                            break;
                        }

                        if (dp[i][j + len - k][k] && dp[i + k][j][len - k]) {
                            dp[i][j][len] = true;
                            break;
                        }
                    }
                }
            }
        }

        return dp[0][0][m];
    }
};

int test_isScramble() {
    Solution solution;

    string s1 = "great";
    string s2 = "rgeat";

    cout << solution.isScramble(s1, s2) << endl;

    return 0;
}