#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        int skipS = 0;
        int skipT = 0;

        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') {
                    skipS++;
                    i--;
                } else if (skipS > 0) {
                    skipS--;
                    i--;
                } else {
                    break;
                }
            }

            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++;
                    j--;
                } else if (skipT > 0) {
                    skipT--;
                    j--;
                } else {
                    break;
                }
            }

            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) {
                    return false;
                }
            } else {
                if (i >= 0 || j >= 0) {
                    return false;
                }
            }

            i--;
            j--;
        }
        return true;
    }
};

int test_backspaceCompare() {
    Solution solution;

    string s1 = "ab#c";
    string t1 = "ad#c";
    bool result1 = solution.backspaceCompare(s1, t1);
    cout << result1 << endl;

    string s2 = "ab##";
    string t2 = "c#d#";
    bool result2 = solution.backspaceCompare(s2, t2);
    cout << result2 << endl;

    string s3 = "ac##";
    string t3 = "a#c#";
    bool result3 = solution.backspaceCompare(s3, t3);
    cout << result3 << endl;

    string s4 = "a#c";
    string t4 = "b";
    bool result4 = solution.backspaceCompare(s4, t4);
    cout << result4 << endl;

    return 0;
}