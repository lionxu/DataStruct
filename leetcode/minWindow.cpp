#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static string minWindow(const string& s, const string& t) {
        vector<int> chars(128, 0);
        vector<int> flag(128, false);

        for (char c: t) {
            chars[c]++;
            flag[c] = true;
        }

        int count = 0;
        int left = 0;
        int min_left = 0;
        int min_size = s.size() + 1;

        for (int right = 0; right < s.size(); ++right) {
            if (flag[s[right]]) {
                if (--chars[s[right]] >= 0) {
                    ++count;
                }

                while (count == t.size()) {
                    if (right - left + 1 < min_size) {
                        min_left = left;
                        min_size = right - left + 1;
                    }

                    if (flag[s[left]] && ++chars[s[left]] > 0) {
                        --count;
                    }
                    ++left;
                }
            }
        }

        if (min_size > s.size()) {
            return "";
        } else {
            return s.substr(min_left, min_size);
        }
    }
};

int test_minWindow() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << Solution::minWindow(s, t) << endl;

    return 0;
}