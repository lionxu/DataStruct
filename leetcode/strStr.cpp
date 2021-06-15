#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();

        if (m == 0) {
            return 0;
        }

        vector<vector<int>> dp(m, vector<int>(256, 0));

        dp[0][needle[0]] = 1;

        int x = 0;

        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < 256; ++j) {
                if (j == needle[i]) {
                    dp[i][j] = i + 1;
                } else {
                    dp[i][j] = dp[x][j];
                }
            }
            x = dp[x][needle[i]];
        }

        int j = 0;

        for (int i = 0; i < n; ++i) {
            j = dp[j][haystack[i]];

            if (j == m) return i - m + 1;
        }

        return -1;
    }
};

int test_strStr() {

    Solution solution;

    string haystack1 = "hello";
    string needle1 = "ll";

    cout << solution.strStr(haystack1, needle1) << endl;

    string haystack2 = "aaaaa";
    string needle2 = "bba";
    cout << solution.strStr(haystack2, needle2) << endl;

    string haystack3;
    string needle3;
    cout << solution.strStr(haystack3, needle3) << endl;

    return 0;
}