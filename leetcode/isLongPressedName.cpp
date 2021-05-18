#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int m = name.length();
        int n = typed.length();

        int i = 0;
        int j = 0;

        while (j < n) {
            if (i < m && name[i] == typed[j]) {
                i++;
                j++;
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            } else {
                return false;
            }
        }
        return i == m;
    }
};

int test_isLongPressedName(){

    Solution solution;
    string name1 = "alex";
    string typed1 = "aaleex";
    cout << solution.isLongPressedName(name1, typed1) << endl;

    string name2 = "saeed";
    string typed2 = "ssaaedd";
    cout << solution.isLongPressedName(name2, typed2) << endl;

    string name3 = "leelee";
    string typed3 = "lleeelee";
    cout << solution.isLongPressedName(name3, typed3) << endl;

    string name4 = "laiden";
    string typed4 = "laiden";
    cout << solution.isLongPressedName(name4, typed4) << endl;

    return 0;
}