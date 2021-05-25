#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> memo(m, vector<int>(n, 0));

        return dp(s1, s2, m - 1, n - 1, memo);
    }

private:
    int dp(string &s1, string &s2, int i, int j, vector<vector<int>> &memo) {
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;

        if (memo[i][j] != 0) {
            return memo[i][j];
        }

        if (s1[i] == s2[j]) {
            memo[i][j] = dp(s1, s2, i - 1, j - 1, memo);
        } else {
            memo[i][j] = min_three(
                    dp(s1, s2, i - 1, j, memo) + 1,
                    dp(s1, s2, i, j - 1,memo) + 1,
                    dp(s1, s2, i - 1, j - 1, memo) + 1
            );
        }

        return memo[i][j];
    }

    static int min_three(int a, int b, int c) {
        return min(min(a, b), c);
    }
};

int test_minDistance() {
    Solution solution;

    string s1 = "horse";
    string s2 = "ros";
    cout << solution.minDistance(s1, s2) << endl;

    return 0;
}