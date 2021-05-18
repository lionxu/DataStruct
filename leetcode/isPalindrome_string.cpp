#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 0) {
            return true;
        }

        int n = s.length();
        int left = 0;
        int right = n - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            while (left < right && !isalnum(s[right])) {
                right--;
            }

            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])){
                    return false;
                }
            }
            left++;
            right--;
        }

        return true;
    }
};

int test_isPalindrome_string() {

    Solution solution;

    string s1 = "A man, a plan, a canal: Panama";

    cout << solution.isPalindrome(s1) << endl;

    string s2 = "race a car";
    cout << solution.isPalindrome(s2) << endl;

    return 0;
}