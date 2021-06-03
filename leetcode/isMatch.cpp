#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        unordered_map<string, bool> memo;
        return dp(s, 0, p, 0, memo);
    }

private:
    bool dp(string &s, int i, string &p, int j, unordered_map<string, bool> &memo) {
        int m = s.size();
        int n = p.size();

        if (j == n) return i == m;

        if (i == m) {
            if ((n - j) % 2 != 0) return false;

            int k = j;

            while (k + 1 < n) {
                if (p[k + 1] != '*') return false;
                k += 2;
            }

            return true;
        }

        string history_key = to_string(i) + "," + to_string(j);

        if (memo.count(history_key)) return memo[history_key];

        bool result;

        if (s[i] == p[j] || p[j] == '.') {
            if (j < n && p[j + 1] == '*') {
                result = dp(s, i + 1, p, j, memo) || dp(s, i, p, j + 2, memo);
            } else {
                result = dp(s, i + 1, p, j + 1, memo);
            }
        } else {
            if (j < n && p[j + 1] == '*') {
                result = dp(s, i, p, j + 2, memo);
            } else {
                result = false;
            }
        }
        memo[history_key] = result;

        return result;
    }
};