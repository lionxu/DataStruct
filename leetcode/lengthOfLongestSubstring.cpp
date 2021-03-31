#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;

        int length = 0;

        unordered_map<char, int> map;

        for (int j = 0; j < s.size(); ++j) {
            map[s[j]]++;
            while (map[s[j]] > 1){
                map[s[i]] -= 1;
                i++;
            }
            length = max(length, j - i + 1);
        }

        return length;
    }
};

int test_lengthOfLongestSubstring(){
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << solution.lengthOfLongestSubstring("bbbbb") << endl;
    cout << solution.lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}

