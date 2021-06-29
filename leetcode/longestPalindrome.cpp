#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        if (n < 2) return s;

        int max_length = 1;
        int begin_index = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        for (int l = 2; l <= n; ++l) {
            for (int i = 0; i < n; ++i) {
                int j = l + i - 1;

                if (j >= n) break;

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j] && max_length < j - i + 1) {
                    max_length = j - i + 1;
                    begin_index = i;
                }
            }
        }
        return s.substr(begin_index, max_length);
    }
};

int test_longestPalindrome() {
    Solution solution;
    string s = "babad";
    cout << solution.longestPalindrome(s) << endl;
    return 0;
}