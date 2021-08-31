#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    static bool validPalindrome(string s) {
        int n = s.size();

        int left = 0;
        int right = n - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return isValid(s, left + 1, right) || isValid(s, left, right - 1);
            }
            left++;
            right--;
        }

        return true;
    }

    static bool isValid(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};

int test_validPalindrome() {

    string s = "aba";

    cout << Solution::validPalindrome(s) << endl;

    return 0;
}