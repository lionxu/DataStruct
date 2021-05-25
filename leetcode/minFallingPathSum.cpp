#include <vector>
#include <iostream>

using namespace std;

#define MAX_VALUE (1e5)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; ++i) {
            history.emplace_back(m, MAX_VALUE);
        }

        int res = MAX_VALUE;

        for (int i = 0; i < m; ++i) {
            res = min(res, dp(matrix, n - 1, i));
        }

        return res;
    }

    int dp(vector<vector<int>> &matrix, int i, int j) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) {
            return MAX_VALUE;
        }

        if (i == 0) {
            return matrix[0][j];
        }

        if (history[i][j] != MAX_VALUE) {
            return history[i][j];
        }

        history[i][j] = matrix[i][j] + min_inner(dp(matrix, i - 1, j),
                                                 dp(matrix, i - 1, j + 1),
                                                 dp(matrix, i - 1, j - 1));

        return history[i][j];
    }

private:
    vector<vector<int>> history;

    static int min_inner(int a, int b, int c) {
        return min(min(a, b), c);
    }
};

int test_minFallingPathSum() {
    Solution solution;

    vector<vector<int>> matrix{{2,1,3}, {6, 5, 4}, {7, 8, 9}};

    cout << solution.minFallingPathSum(matrix) << endl;


    return 0;
}