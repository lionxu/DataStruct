#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {

        vector<vector<int>> memo(s.length(), vector<int>(s.length(), 0));

        return dp(s, memo, 0, s.length() - 1);
    }

private:
    int dp(string& s, vector<vector<int>>& memo, int i, int j) {

        if (i > j) return 0;

        if (i == j) return 1;

        if (memo[i][j] != 0){
            return memo[i][j];
        }

        if (s[i] == s[j]) memo[i][j] = dp(s, memo, i + 1, j - 1) + 2;
        else {
            return memo[i][j] = max(dp(s, memo, i, j - 1), dp(s, memo, i + 1, j));
        }

        return memo[i][j];
    }
};

int test_longestPalindromeSubseq() {
    Solution solution;

    string s = "bbbab";

    cout << solution.longestPalindromeSubseq(s) << endl;

    return 0;
}