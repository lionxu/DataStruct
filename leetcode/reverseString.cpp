#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char> &s) {

        int n = s.size();

        for (int left = 0, right = n - 1; left < right; ++left, --right) {
            s[left] ^= s[right];
            s[right] ^= s[left];
            s[left] ^= s[right];
        }
    }
};

int test_reverseString() {

    vector<char> s;
    s.push_back('h');
    s.push_back('e');
    s.push_back('l');
    s.push_back('l');
    s.push_back('o');

    Solution solution;
    solution.reverseString(s);

    for (int i = 0; i < s.size(); ++i) {
        cout << s[i] << ",";
    }

    cout << endl;

    return 0;
}