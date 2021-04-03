#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> map;
        int max_count = 0;
        int left = 0;
        int right = 0;
        for (; right < s.size(); ++right) {
            map[s[right]]++;

            max_count = max(max_count, map[s[right]]);

            while (max_count + k < right - left + 1){
                map[s[left]]--;
                left++;
            }
        }

        return right - left;
    }
};

int test_characterReplacement(){
    Solution solution;

    cout << solution.characterReplacement("ABAB", 2) << endl;
    cout << solution.characterReplacement("AABABBA", 1) << endl;
    cout << solution.characterReplacement("ABAA", 0) << endl;
    return 0;
}