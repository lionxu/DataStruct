#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();

        int left = 0;
        int right = n - 1;

        while (left < right) {
            if (!isVowel(s[left])) {
                left++;
                continue;
            } else if (!isVowel(s[right])) {
                right--;
                continue;
            } else {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }

    static bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' ||
               c == 'O' || c == 'U';
    }
};

int test_reverseVowels(){
    Solution solution;
    string s1 = "hello";
    cout << solution.reverseVowels(s1) << endl;
    string s2 = "leetcode";
    cout << solution.reverseVowels(s2) << endl;
    return 0;
}
