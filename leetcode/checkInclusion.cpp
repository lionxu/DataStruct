#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        unordered_map<char, int> s1_map;
        unordered_map<char, int> s2_map;

        for (char & i : s1) {
            s1_map[i]++;
        }

        int left = 0;
        int right = 0;
        int count = 0;

        for (; right < s2.size(); ++right) {
            s2_map[s2[right]]++;
            count++;

            if (s1_map == s2_map) return true;

            if (count >= s1.size()){
                s2_map[s2[left]]--;
                if (s2_map[s2[left]] == 0) s2_map.erase(s2[left]);
                left++;
                count--;
            }
        }

        return false;
    }
};

int test_checkInclusion() {
    Solution solution;
    cout << solution.checkInclusion("adc", "dcda") << endl;
    return 0;
}
