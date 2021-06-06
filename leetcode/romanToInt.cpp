#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {

        int n = s.length();

        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return roman_char_to_int(s[0]);
        }

        int slow = 0;
        int fast = 1;
        int result = 0;

        while (slow < n) {
            if (fast == n) {
                result += roman_char_to_int(s[slow]);
            } else if (roman_char_to_int(s[slow]) >= roman_char_to_int(s[fast])) {
                result += roman_char_to_int(s[slow]);
            } else {
                result += -1 * roman_char_to_int(s[slow]);
            }
            slow = fast;
            fast++;
        }

        return result;
    }

    static int roman_char_to_int(char c) {
        int result = 0;
        switch (c) {
            case 'I':
                result = 1;
                break;
            case 'V':
                result = 5;
                break;
            case 'X':
                result = 10;
                break;
            case 'L':
                result = 50;
                break;
            case 'C':
                result = 100;
                break;
            case 'D':
                result = 500;
                break;
            case 'M':
                result = 1000;
                break;
            default:
                break;
        }
        return result;
    }
};

int test_romanToInt() {
    Solution solution;
    string s1 = "III";
    cout << solution.romanToInt(s1) << endl;

    string s2 = "IV";
    cout << solution.romanToInt(s2) << endl;

    string s3 = "IX";
    cout << solution.romanToInt(s3) << endl;

    string s4 = "LVIII";
    cout << solution.romanToInt(s4) << endl;

    string s5 = "MCMXCIV";
    cout << solution.romanToInt(s5) << endl;

    return 0;
}