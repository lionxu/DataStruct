#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> memo(m, vector<int>(n, 0));

        return dp(text1, 0, text2, 0, memo);
    }

private:
    int dp(string &text1, int i, string &text2, int j, vector<vector<int>> &memo) {
        if (i == text1.length()) return 0;
        if (j == text2.length()) return 0;

        if (memo[i][j] != 0) {
            return memo[i][j];
        }

        if (text1[i] == text2[j]) {
            memo[i][j] = 1 + dp(text1, i + 1, text2, j + 1, memo);
        } else {
            memo[i][j] = max(dp(text1, i + 1, text2, j, memo), dp(text1, i, text2, j + 1, memo));
        }

        return memo[i][j];
    }
};

int main() {

    Solution solution;

    string text1 = "abcde";
    string text2 = "ace";

    cout << solution.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}