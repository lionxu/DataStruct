#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    static string removeKdigits(string num, int k) {

        vector<char> stack;

        for (auto n: num) {
            while (!stack.empty() && stack.back() > n && k) {
                stack.pop_back();
                k--;
            }

            stack.push_back(n);
        }

        for (; k > 0; k--) {
            stack.pop_back();
        }

        string result;

        bool frontZero = true;

        for (auto c: stack) {
            if (frontZero && c == '0') {
                continue;
            }

            frontZero = false;
            result += c;
        }

        if (result.empty()) return "0";
        else return result;
    }
};

int test_removeKdigits() {

    string num = "1432219";
    int k = 3;

    cout << Solution::removeKdigits(num, k) << endl;

    return 0;
}
