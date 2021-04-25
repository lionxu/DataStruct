#include <string>
#include <iostream>

using namespace std;

class Solution {
public:

    bool is_vowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {

        int n = s.size();
        int vowel_count = 0;
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            if (is_vowel(s[i])) vowel_count++;
        }

        ans = vowel_count;

        for (int i = k; i < n; ++i) {
            if (is_vowel(s[i])) vowel_count++;
            if (is_vowel(s[i - k])) vowel_count--;
            ans = max(ans, vowel_count);
        }

        return ans;
    }
};

int test_maxVowels() {

    Solution solution;

    string s1 = "abciiidef";
    int k1 = 3;
    cout << solution.maxVowels(s1, k1) << endl;

    string s2 = "aeiou";
    int k2 = 2;
    cout << solution.maxVowels(s2, k2) << endl;

    string s3 = "leetcode";
    int k3 = 3;
    cout << solution.maxVowels(s3, k3) << endl;

    string s4 = "rhythms";
    int k4 = 4;
    cout << solution.maxVowels(s4, k4) << endl;

    string s5 = "tryhard";
    int k5 = 4;
    cout << solution.maxVowels(s5, k5) << endl;

    return 0;
}
