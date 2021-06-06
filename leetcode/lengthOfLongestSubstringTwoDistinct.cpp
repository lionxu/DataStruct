#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int count = 0;
        int length = 0;
        int left = 0;
        unordered_map<char, int> map;

        for (int right = 0; right < s.size(); ++right) {
            if (map[s[right]]++ == 0){
                count++;
            }

            while (count > 2){
                if (--map[s[left++]] == 0) count--;
            }

            if (length < (right - left + 1)){
                length = right - left + 1;
            }
        }

        return length;
    }
};


int test_lengthOfLongestSubstringTwoDistinct(){
    Solution solution;
    cout << solution.lengthOfLongestSubstringTwoDistinct("eceba") << endl;
    cout << solution.lengthOfLongestSubstringTwoDistinct("ccaabbb") << endl;

    return 0;
}