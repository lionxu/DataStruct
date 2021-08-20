#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    static int longestPalindrome_2(string s) {
        unordered_map<char, int> unorderedMap;

        for(auto c: s) {
            unorderedMap[c]++;
        }

        int result = 0;

        for (auto m: unorderedMap) {
            result += (m.second / 2 * 2);

            if (m.second % 2 == 1 && result % 2 == 0) {
                result++;
            }
        }

        return result;
    }
};

int test_longestPalindrome_2() {
    string s = "abccccdd";

    cout << Solution::longestPalindrome_2(s) << endl;

    return 0;
}