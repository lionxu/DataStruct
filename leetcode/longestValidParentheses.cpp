#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();

        if (n == 0) return 0;

        vector<int> dp(n, 0);

        int max_value = 0;

        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    if (i >= 2) {
                        dp[i] = dp[i - 2] + 2;
                    } else {
                        dp[i] = 2;
                    }
                } else if (s[i - 1] == ')') {
                    if (i > dp[i - 1] && s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = dp[i - 1] + 2;
                        if (i >= dp[i - 1] + 2) {
                            dp[i] += dp[i - dp[i - 1] - 2];
                        }
                    }
                }
            }
            max_value = max(max_value, dp[i]);
        }

        return max_value;
    }
};


int main() {
    Solution solution;

    cout << solution.longestValidParentheses("(()") << endl;

    return 0;
}