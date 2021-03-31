#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {

        if (s.size() < k) return 0;

        unordered_set<char> set(s.begin(), s.end());
        unordered_map<char, int> map;

        for (int i = 0; i < s.size(); ++i) {
            map[s[i]]++;
        }

        for (char c: set) {
            if (map[c] < k) {
                vector<string> t;
                split(s, t, c);
                int res = 0;
                for (const string &tc: t) {
                    res = max(res, longestSubstring(tc, k));
                }
                return res;
            }
        }

        return s.size();
    }

    static void split(const string &s, vector<string> &t, const char flag = ' ') {
        t.clear();
        istringstream iss(s);
        string str;
        while (getline(iss, str, flag)) {
            t.push_back(str);
        }
    }
};

int test_longestSubstring(){
    Solution solution;
    cout << solution.longestSubstring("aaabb", 3) << endl;
    cout << solution.longestSubstring("ababbc", 2) << endl;
}

