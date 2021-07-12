#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int m = matrix.size();

        if (m == 0) return 0;

        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    if (j == 0) dp[i][j] = 1;
                    else {
                        dp[i][j] = dp[i][j - 1] + 1;
                    }
                }
            }
        }

        int ret = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] != '0') {
                    int with = dp[i][j];
                    int area = with;
                    for (int k = i - 1; k >= 0; --k) {
                        with = min(with, dp[k][j]);
                        area = max(area, (i - k + 1) * with);
                    }
                    ret = max(ret, area);
                }
            }
        }

        return ret;
    }
};

int test_maximalRectangle() {
    Solution solution;

    vector<vector<char>> matrix{{'1', '0', '1', '0', '0'},
                                {'1', '0', '1', '1', '1'},
                                {'1', '1', '1', '1', '1'},
                                {'1', '0', '0', '1', '0'}};

    cout << solution.maximalRectangle(matrix) << endl;

    return 0;
}