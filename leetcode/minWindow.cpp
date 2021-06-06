#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int need_count = 0;
        unordered_map<char, int> map;
        for (int i = 0; i < t.size(); ++i) {
            map[t[i]]++;
            need_count++;
        }

        int result_left = 0;
        int result_right = 1e5;

        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            if (map[s[right]] > 0) {
                need_count--;
            }

            map[s[right]]--;

            if (need_count == 0) {
                while (map[s[left]] < 0) {
                    map[s[left]]++;
                    left++;
                }

                if (right - left < result_right - result_left) {
                    result_left = left;
                    result_right = right;
                }

                map[s[left]]++;
                left++;
                need_count++;
            }
        }

        if (result_right > s.size()){
            return "";
        } else{
            return s.substr(result_left, result_right - result_left + 1);
        }
    }
};

int test_minWindow(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution solution;
    cout << solution.minWindow(s, t) << endl;

    return 0;
}