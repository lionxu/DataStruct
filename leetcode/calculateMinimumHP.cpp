#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (i == n - 1 && j == m - 1) {
                    dp[i][j] = max(1 - dungeon[i][j], 1);
                } else if (i == n - 1) {
                    dp[i][j] = max(dp[i][j + 1] - dungeon[i][j], 1);
                } else if (j == m - 1) {
                    dp[i][j] = max(dp[i + 1][j] - dungeon[i][j], 1);
                } else {
                    dp[i][j] = max(min(dp[i+1][j], dp[i][j+1])-dungeon[i][j], 1);
                }
            }
        }

        return dp[0][0];
    }
};