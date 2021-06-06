#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {

        int m = ring.size();
        int n = key.size();

        unordered_map<char, vector<int>> char_2_index;

        vector<vector<int>> memo(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            char_2_index[ring[i]].push_back(i);
        }

        return dp(ring, 0, key, 0, char_2_index, memo);
    }

private:
    int dp(string &ring, int i, string &key, int j, unordered_map<char, vector<int>> &char_2_index, vector<vector<int>> &memo) {
        int n = key.size();

        if (j == n) return 0;

        if (memo[i][j] != 0) {
            return memo[i][j];
        }

        int m = ring.size();

        int result = INT_MAX;

        for (int k: char_2_index[key[j]]) {
            int delta = abs(k - i);
            delta = min(delta, m - delta);
            int sub_result = dp(ring, k, key, j + 1, char_2_index, memo);
            result = min(result, 1 + delta + sub_result);
        }

        memo[i][j] = result;

        return result;
    }
};

int test_findRotateSteps() {
    Solution solution;

    string ring = "godding";
    string key = "gd";

    cout << solution.findRotateSteps(ring, key) << endl;
    return 0;
}