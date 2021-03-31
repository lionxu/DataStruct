#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int K){

        unordered_map<char, int> map;
        int count = 0;
        int length = 0;
        int left = 0;

        for (int right = 0; right < s.size(); ++right) {
            if (map[s[right]]++ == 0){
                count++;
            }

            while (count > K){
                if (--map[s[left++]] == 0) count--;
            }

            if (length < (right - left + 1)){
                length = right - left + 1;
            }
        }

        return length;
    }
};


int test_lengthOfLongestSubstringKDistinct(){
    Solution solution;
    cout << solution.lengthOfLongestSubstringKDistinct("eceba", 2) << endl;
    cout << solution.lengthOfLongestSubstringKDistinct("aa", 1) << endl;
}