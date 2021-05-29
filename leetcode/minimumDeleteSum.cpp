#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> memo(m, vector<int>(n, -1));

        return dp(s1, 0, s2, 0, memo);
    }

private:
    int dp(string &s1, int i, string &s2, int j, vector<vector<int>> &memo) {

        int result = 0;

        if (i == s1.length()) {
            for (int k = j; k < s2.length(); ++k) {
                result += s2[k];
            }

            return result;
        }

        if (j == s2.length()) {
            for (char k : s1) {
                result += k;
            }

            return result;
        }

        if (memo[i][j] != -1){
            return memo[i][j];
        }

        if (s1[i] == s2[j]){
            memo[i][j] = dp(s1, i + 1, s2, j + 1, memo);
        }else {
            memo[i][j] = min(s1[i] + dp(s1, i + 1, s2, j, memo), s2[j] + dp(s1, i, s2, j + 1, memo));
        }

        return memo[i][j];
    }
};